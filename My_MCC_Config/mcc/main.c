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
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/tca0.h"

/*
    Main application
*/

#define SCALING_FACTOR 1000L
#define VDD 3300L
#define RESOLUTION 4095L
#define NUM_READINGS 2


struct sensor_reading_t{
    adc_result_t counts;
    int32_t voltage;
    bool update;
};


volatile struct sensor_reading_t readings[NUM_READINGS];

//Interrupt Handler for result ready...
static void myADC0_ConversionDoneCallback(void)
{
    uint8_t channel = ADC0.MUXPOS - 0x14;
    readings[channel].counts = ADC0_ConversionResultGet();
    readings[channel].update = true;
}

void myTCA0_OVFCallback(void)
{
    ADC0_ConversionStart();
    IO_PF5_Toggle();
}


void floatMath(int16_t counts) 
{
    //int32_t voltage 
    //printf("Result is %d, and Voltage is %d", )
}


void intMath() 
{

}


int main(void)
{
    SYSTEM_Initialize();
    TCA0_OverflowCallbackRegister(myTCA0_OVFCallback);
    ADC0_ConversionDoneCallbackRegister(myADC0_ConversionDoneCallback);
    ADC0_Enable();
    TCA0_Start();
    sei();

    for(int i = 0; i < NUM_READINGS; i++)
    {
        readings[i].counts = 0;
        readings[i].voltage = 0;
        readings[i].update = false;
    }
    printf("\r\nProgram Starting \r\n");
    
    int32_t curr_counts = 0;
    int32_t scaled_counts = 0;
    int32_t counts_factor = 0;
    int32_t scaled_voltage = 0; 
    int32_t temp = 0;
    int32_t voltage_broken[4] = {0,0,0,0};
    while(1)
    {
        //printf("Running...\n\r");
        for(int i = 0; i < NUM_READINGS; i++)
        {
            if(readings[i].update)
            {
                readings[i].update = false;
                curr_counts = (int32_t)readings[i].counts;
                scaled_counts = curr_counts * SCALING_FACTOR;
                counts_factor = scaled_counts / RESOLUTION;
                scaled_voltage = VDD * counts_factor;
                //printf("%d:%ld:%ld:%ld\n\r", readings[i].counts, scaled_counts, counts_factor, scaled_voltage);
                readings[i].voltage = scaled_voltage / (SCALING_FACTOR);
                printf("%ld\n\r", readings[i].voltage);
                temp = readings[i].voltage;
                for(int j = 0; j < 4; j++) 
                {
                    voltage_broken[3-j] = temp % 10;
                    temp /= 10;
                }
                printf("Result is %d, and Voltage is %ld.%ld%ld%ld\n\r", readings[i].counts, voltage_broken[0], voltage_broken[1], voltage_broken[2], voltage_broken[3]); 
            }
            
        }
            
        //DO NOTHING
    }    
}