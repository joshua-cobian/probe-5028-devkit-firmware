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
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/tca0.h"

/*
    Main application
*/

#define SCALING_FACTOR 1000L //If changing scaling factor make sure to change VDD to match
#define VDD 3300L
#define DAC_RESOLUTION 1023L
#define ADC_RESOLUTION 4095L
#define NUM_READINGS 2


struct sensor_reading_t{
    adc_result_t counts;
    int16_t voltage;
    bool update_adc;
    bool update_dac;
};


volatile struct sensor_reading_t readings[NUM_READINGS];

//Interrupt Handler for result ready...
static void myADC0_ConversionDoneCallback(void)
{
    uint8_t channel = ADC0.MUXPOS - 0x14; //0x14 is current selected port number (AIN20)
    readings[channel].counts = ADC0_ConversionResultGet();
    readings[channel].update_adc = true;
}

void myTCA0_OVFCallback(void)
{
    ADC0_ConversionStart();
    IO_PF5_Toggle();
}


void floatCountsToVoltage(adc_result_t counts) 
{
    int32_t voltage = 3.3 * (counts / 4095.0f);
    printf("Result is %d, and Voltage is %f", counts, voltage);
}


void intCountsToVoltage(adc_result_t counts, uint8_t currReading) 
{
    int32_t scaled_counts = counts * SCALING_FACTOR;
    int32_t counts_fraction = scaled_counts / ADC_RESOLUTION;
    int32_t scaled_voltage = VDD * counts_fraction;
    int32_t Voltage = scaled_voltage / (SCALING_FACTOR);    //printf("%d:%ld:%ld:%ld\n\r", readings[i].counts, scaled_counts, counts_factor, scaled_voltage);
    readings[currReading].voltage = (int16_t) Voltage;
    readings[currReading].update_dac = true;
    //printf("%ld\n\r", readings[currReading].voltage);
}

//Converts 16bit voltage to 10-bit counts value for DAC
dac_resolution_t intVoltageToCounts(int16_t voltage)
{
    int32_t scaled_voltage = (int32_t)voltage * SCALING_FACTOR;
    int32_t voltage_fraction = scaled_voltage / VDD;
    int32_t Scaled_DAC_Counts = voltage_fraction * DAC_RESOLUTION;
    dac_resolution_t DAC_Counts = Scaled_DAC_Counts / SCALING_FACTOR;
    return DAC_Counts;
}

int main(void)
{
    SYSTEM_Initialize();
    TCA0_OverflowCallbackRegister(myTCA0_OVFCallback);
    ADC0_ConversionDoneCallbackRegister(myADC0_ConversionDoneCallback);
    ADC0_Enable();
    TCA0_Start();
    sei();


    DAC0_SetOutput(512);
    for(int i = 0; i < NUM_READINGS; i++)
    {
        readings[i].counts = 0;
        readings[i].voltage = 0;
        readings[i].update_adc = false;
        readings[i].update_dac = false;
    }
    printf("\r\nProgram Starting \r\n");
    
    adc_result_t curr_counts = 0;
    int16_t curr_voltage = 0;
    dac_resolution_t dac_counts = 0;
    int32_t temp = 0;
    int32_t voltage_broken[4] = {0,0,0,0};
    while(1)
    {
        //printf("Running...\n\r");
        for(int i = 0; i < NUM_READINGS; i++)
        {
            if(readings[i].update_adc)
            {
                readings[i].update_adc = false;
                curr_counts = readings[i].counts;
                intCountsToVoltage(curr_counts, i);
                temp = readings[i].voltage;
                for(int j = 0; j < 4; j++) 
                {
                    voltage_broken[3-j] = temp % 10;
                    temp /= 10;
                }
                printf("Result is %d, and Voltage is %ld.%ld%ld%ld\n\r", readings[i].counts, voltage_broken[0], voltage_broken[1], voltage_broken[2], voltage_broken[3]); 
            }
            if(readings[i].update_dac)
            {
                readings[i].update_dac = false;
                curr_voltage = readings[i].voltage;
                dac_counts = intVoltageToCounts(curr_voltage);
                printf("DAC_counts: %d\n\r", dac_counts);
                DAC0_SetOutput(dac_counts);
            }
        }
            
        //DO NOTHING
    }    
}