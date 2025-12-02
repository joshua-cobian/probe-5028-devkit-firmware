/*
 * MAIN Generated Driver File
 *
 * @file main.c
 *
 * @defgroup main MAIN
 *
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
 */

/*
� [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip
    software and any derivatives exclusively with Microchip products.
    You are responsible for complying with 3rd party license terms
    applicable to your use of 3rd party software (including open source
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.?
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.
*/
#include "mcc_generated_files/adc/adc0.h"
#include "mcc_generated_files/adc/adc_types.h"
#include "mcc_generated_files/dac/dac0.h"
#include "mcc_generated_files/nvm/nvm.h"
#include "mcc_generated_files/system/ccp.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/tca0.h"
#include "mcc_generated_files/timer/tcb0.h"
#include <avr/io.h>
#include "eeprom_wrapper.h"

/*
    Main application
*/

#define SCALING_FACTOR                                                         \
  1000L // If changing scaling factor make sure to change VDD to match
#define FAST_SCALING_FACTOR 1024L
#define VDD (33 * (SCALING_FACTOR / 10))
#define DAC_RESOLUTION 1023L
#define ADC_RESOLUTION 4095L
#define NUM_READINGS 2
#define EEPROM_START_ADDR 0x1400
//GAIN_Q16 is an estimation of the fraction VDD/DAC_RESOLUTION fraction using x/2^16
#define GAIN_Q16 52813L

struct sensor_reading_t {
  adc_result_t counts;
  int16_t voltage;
  bool update_adc;
  bool update_dac;
};

volatile struct sensor_reading_t readings[NUM_READINGS];
static eeprom_data_t lfsr8 = 0xA5; // Not zero

void my_IO_PF6_SetInterruptHandler(void) { RSTCTRL_SoftwareReset(); }

// Interrupt Handler for result ready...
static void myADC0_ConversionDoneCallback(void) {
  uint8_t channel =
      ADC0.MUXPOS - 0x14; // 0x14 is current selected port number (AIN20)
  readings[channel].counts = ADC0_ConversionResultGet();
  readings[channel].update_adc = true;
}

void myTCA0_OVFCallback(void) {
  ADC0_ConversionStart();
  IO_PF5_Toggle();
}

void print_voltage(uint16_t voltage) {
  int8_t voltage_broken[4] = {0};
  uint16_t temp = voltage;
  for (int j = 0; j < 4; j++) {
    voltage_broken[3 - j] = temp % 10;
    temp /= 10;
  }
  printf("Result is %d, and Voltage is %d.%d%d%d\n\r", readings[0].counts,
         voltage_broken[0], voltage_broken[1], voltage_broken[2],
         voltage_broken[3]);
}

void floatCountsToVoltage(adc_result_t counts) {
  TCB0_CounterSet(0);
  TCB0_Start();
  double voltage = ((3.3f * counts)  / 4095.0f);
  readings[0].voltage = (int16_t)voltage;
  readings[0].update_dac = true;
  TCB0_Stop();
  uint16_t time = TCB0_CounterGet();
  printf("Float time %d and voltage is %f \n\r", time, voltage);
}

void intCountsToVoltage(adc_result_t counts, uint8_t currReading) {
  TCB0_CounterSet(0);
  TCB0_Start();
  int32_t Voltage = (VDD * counts) / ADC_RESOLUTION;
  // printf("%d:%ld:%ld:%ld\n\r", readings[currReading].counts, scaled_counts,
  // counts_fraction, scaled_voltage);
  readings[currReading].voltage = (int16_t)Voltage;
  readings[currReading].update_dac = true;
  TCB0_Stop();
  uint16_t time = TCB0_CounterGet();
  printf("Int time is %d\n\r", time);
  print_voltage(readings[currReading].voltage);
  // printf("%ld\n\r", readings[currReading].voltage);
}

void fastintCountsToVoltage(adc_result_t counts, uint8_t currReading) {
  TCB0_CounterSet(0);
  TCB0_Start();
  int32_t Voltage = (VDD * ((counts * FAST_SCALING_FACTOR) / ADC_RESOLUTION)) / FAST_SCALING_FACTOR;
  // printf("%d:%ld:%ld:%ld\n\r", readings[currReading].counts, scaled_counts,
  // counts_fraction, scaled_voltage);
  readings[currReading].voltage = (int16_t)Voltage;
  readings[currReading].update_dac = true;
  TCB0_Stop();
  uint16_t time = TCB0_CounterGet();
  printf("Fast int time is %d\n\r", time);
  print_voltage(readings[currReading].voltage);
}

void evenfasterintCountsToVoltage(adc_result_t counts, uint8_t currReading) {
  TCB0_CounterSet(0);
  TCB0_Start();
  int32_t Voltage = (counts * GAIN_Q16) >> 16;
  // printf("%d:%ld:%ld:%ld\n\r", readings[currReading].counts, scaled_counts,
  // counts_fraction, scaled_voltage);
  readings[currReading].voltage = (int16_t)Voltage;
  readings[currReading].update_dac = true;
  TCB0_Stop();
  uint16_t time = TCB0_CounterGet();
  printf("Faster int time is %d\n\r", time);
  print_voltage(readings[currReading].voltage);
}

// Converts 16bit voltage to 10-bit counts value for DAC
dac_resolution_t intVoltageToCounts(int16_t voltage) {
  int32_t scaled_voltage = (int32_t)voltage * SCALING_FACTOR;
  int32_t voltage_fraction = scaled_voltage / VDD;
  int32_t Scaled_DAC_Counts = voltage_fraction * DAC_RESOLUTION;
  dac_resolution_t DAC_Counts = Scaled_DAC_Counts / SCALING_FACTOR;
  return DAC_Counts;
}

void EEPROM_Erase() {
  // Erase entire EEPROM
  ccp_write_spm((void *)&NVMCTRL.CTRLA, NVMCTRL_CMD_EECHER_gc);

  // Clear the current command
  ccp_write_spm((void *)&NVMCTRL.CTRLA, NVMCTRL_CMD_NONE_gc);
}

// Writes bytes to EEPROM in sequential order starting at a given address
void EEPROM_Write_Bytes(eeprom_address_t starting_address, eeprom_data_t *bytes,
                        uint8_t num_bytes) {
  for (eeprom_address_t i = 0; i < num_bytes; i++) {
    EEPROM_Write(EEPROM_START_ADDR + starting_address + i, bytes[i]);
    while (EEPROM_IsBusy())
      ;
    if (NVM_StatusGet() != NVM_OK) {
      NVM_StatusClear();
      printf("EEPROM Write FAILED\n\r");
    }
  }
}

// Reads bytes from the EEPROM starting at a specfic address
void EEPROM_Read_bytes(eeprom_address_t starting_address,
                       eeprom_address_t ending_address, eeprom_data_t *bytes,
                       int *num_bytes) {
  *num_bytes = 0;
  for (eeprom_address_t i = starting_address; i < ending_address; i++) {
    eeprom_data_t read_data = EEPROM_Read(EEPROM_START_ADDR + i);
    bytes[i - starting_address] = read_data;
    (*num_bytes)++;
  }
}









/**
 * @brief
 *
 * @return eeprom_data_t
 */
eeprom_data_t randData() {
  uint8_t lsb = lfsr8 & 1;
  lfsr8 >>= 1;
  if (lsb) {
    lfsr8 ^= 0xB8;
  }

  return lfsr8;
}
int main(void) {
  SYSTEM_Initialize();
  IO_PF6_SetInterruptHandler(my_IO_PF6_SetInterruptHandler);
  TCA0_OverflowCallbackRegister(myTCA0_OVFCallback);
  ADC0_ConversionDoneCallbackRegister(myADC0_ConversionDoneCallback);

  eeprom_data_t write_data[4] = {0xDE, 0xAD, 0xBE, 0xEF};
  testing_eeprom_write_bytes(200, write_data, 4);

  eeprom_data_t buff[256];
  testing_eeprom_read_bytes(200, 56, buff);

  for (int i = 0; i < 56; i++) {
    printf("eeprom data at %d is %x\n\r", i + 200, buff[i]);
  }

  for (int i = 0; i < NUM_READINGS; i++) {
    readings[i].counts = 0;
    readings[i].voltage = 0;
    readings[i].update_adc = false;
    readings[i].update_dac = false;
  }
  printf("Program Starting \r\n");

  ADC0_Enable();
  TCA0_Start();
  TCB0_CounterSet(0);
  TCB0_Start();
  TCB0_Stop();
  uint16_t time = TCB0_CounterGet();
  printf("Tick Overhead is %d\n\r", time);
  adc_result_t curr_counts = 0;
  int16_t curr_voltage = 0;
  dac_resolution_t dac_counts = 0;
  int32_t temp = 0;

  while (1) {
    // printf("Running...\n\r");
    for (int i = 0; i < NUM_READINGS; i++) {
      if (readings[i].update_adc) {
        // ADC Voltage Conversion
        readings[i].update_adc = false;
        curr_counts = readings[i].counts;
        floatCountsToVoltage(curr_counts);
        intCountsToVoltage(curr_counts, i);
        fastintCountsToVoltage(curr_counts, i);
        evenfasterintCountsToVoltage(curr_counts, i);
      }
      if (readings[i].update_dac) {
        // DAC Count Conversion
        readings[i].update_dac = false;
        curr_voltage = readings[i].voltage;
        dac_counts = intVoltageToCounts(curr_voltage);
        printf("DAC_counts: %d\n\r", dac_counts);
        printf("--------------------------\n\r");
        DAC0_SetOutput(dac_counts);
      }
    }

    // DO NOTHING
  }
}