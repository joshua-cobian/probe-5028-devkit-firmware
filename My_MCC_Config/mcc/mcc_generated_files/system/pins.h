/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  1.1.0
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set IO_PD5 aliases
#define IO_PD5_SetHigh() do { PORTD_OUTSET = 0x20; } while(0)
#define IO_PD5_SetLow() do { PORTD_OUTCLR = 0x20; } while(0)
#define IO_PD5_Toggle() do { PORTD_OUTTGL = 0x20; } while(0)
#define IO_PD5_GetValue() (VPORTD.IN & (0x1 << 5))
#define IO_PD5_SetDigitalInput() do { PORTD_DIRCLR = 0x20; } while(0)
#define IO_PD5_SetDigitalOutput() do { PORTD_DIRSET = 0x20; } while(0)
#define IO_PD5_SetPullUp() do { PORTD_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD5_ResetPullUp() do { PORTD_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD5_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD5_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD5_DisableInterruptOnChange() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD5_EnableInterruptForBothEdges() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD5_EnableInterruptForRisingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD5_EnableInterruptForFallingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD5_DisableDigitalInputBuffer() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD5_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD5_SetInterruptHandler IO_PD5_SetInterruptHandler

//get/set IO_PD4 aliases
#define IO_PD4_SetHigh() do { PORTD_OUTSET = 0x10; } while(0)
#define IO_PD4_SetLow() do { PORTD_OUTCLR = 0x10; } while(0)
#define IO_PD4_Toggle() do { PORTD_OUTTGL = 0x10; } while(0)
#define IO_PD4_GetValue() (VPORTD.IN & (0x1 << 4))
#define IO_PD4_SetDigitalInput() do { PORTD_DIRCLR = 0x10; } while(0)
#define IO_PD4_SetDigitalOutput() do { PORTD_DIRSET = 0x10; } while(0)
#define IO_PD4_SetPullUp() do { PORTD_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD4_ResetPullUp() do { PORTD_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD4_SetInverted() do { PORTD_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD4_ResetInverted() do { PORTD_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD4_DisableInterruptOnChange() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD4_EnableInterruptForBothEdges() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD4_EnableInterruptForRisingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD4_EnableInterruptForFallingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD4_DisableDigitalInputBuffer() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD4_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD4_SetInterruptHandler IO_PD4_SetInterruptHandler

//get/set IO_PA7 aliases
#define IO_PA7_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define IO_PA7_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define IO_PA7_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define IO_PA7_GetValue() (VPORTA.IN & (0x1 << 7))
#define IO_PA7_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define IO_PA7_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define IO_PA7_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PA7_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PA7_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PA7_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PA7_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PA7_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PA7_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PA7_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PA7_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PA7_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA7_SetInterruptHandler IO_PA7_SetInterruptHandler

//get/set IO_PD6 aliases
#define IO_PD6_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define IO_PD6_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define IO_PD6_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define IO_PD6_GetValue() (VPORTD.IN & (0x1 << 6))
#define IO_PD6_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define IO_PD6_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define IO_PD6_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD6_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD6_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD6_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD6_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD6_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD6_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD6_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD6_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD6_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD6_SetInterruptHandler IO_PD6_SetInterruptHandler

//get/set IO_PF4 aliases
#define IO_PF4_SetHigh() do { PORTF_OUTSET = 0x10; } while(0)
#define IO_PF4_SetLow() do { PORTF_OUTCLR = 0x10; } while(0)
#define IO_PF4_Toggle() do { PORTF_OUTTGL = 0x10; } while(0)
#define IO_PF4_GetValue() (VPORTF.IN & (0x1 << 4))
#define IO_PF4_SetDigitalInput() do { PORTF_DIRCLR = 0x10; } while(0)
#define IO_PF4_SetDigitalOutput() do { PORTF_DIRSET = 0x10; } while(0)
#define IO_PF4_SetPullUp() do { PORTF_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF4_ResetPullUp() do { PORTF_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF4_SetInverted() do { PORTF_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF4_ResetInverted() do { PORTF_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF4_DisableInterruptOnChange() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF4_EnableInterruptForBothEdges() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF4_EnableInterruptForRisingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF4_EnableInterruptForFallingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF4_DisableDigitalInputBuffer() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF4_EnableInterruptForLowLevelSensing() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF4_SetInterruptHandler IO_PF4_SetInterruptHandler

//get/set IO_PF6 aliases
#define IO_PF6_SetHigh() do { PORTF_OUTSET = 0x40; } while(0)
#define IO_PF6_SetLow() do { PORTF_OUTCLR = 0x40; } while(0)
#define IO_PF6_Toggle() do { PORTF_OUTTGL = 0x40; } while(0)
#define IO_PF6_GetValue() (VPORTF.IN & (0x1 << 6))
#define IO_PF6_SetDigitalInput() do { PORTF_DIRCLR = 0x40; } while(0)
#define IO_PF6_SetDigitalOutput() do { PORTF_DIRSET = 0x40; } while(0)
#define IO_PF6_SetPullUp() do { PORTF_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF6_ResetPullUp() do { PORTF_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF6_SetInverted() do { PORTF_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF6_ResetInverted() do { PORTF_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF6_DisableInterruptOnChange() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF6_EnableInterruptForBothEdges() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF6_EnableInterruptForRisingEdge() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF6_EnableInterruptForFallingEdge() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF6_DisableDigitalInputBuffer() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF6_EnableInterruptForLowLevelSensing() do { PORTF.PIN6CTRL = (PORTF.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF6_SetInterruptHandler IO_PF6_SetInterruptHandler

//get/set IO_PF5 aliases
#define IO_PF5_SetHigh() do { PORTF_OUTSET = 0x20; } while(0)
#define IO_PF5_SetLow() do { PORTF_OUTCLR = 0x20; } while(0)
#define IO_PF5_Toggle() do { PORTF_OUTTGL = 0x20; } while(0)
#define IO_PF5_GetValue() (VPORTF.IN & (0x1 << 5))
#define IO_PF5_SetDigitalInput() do { PORTF_DIRCLR = 0x20; } while(0)
#define IO_PF5_SetDigitalOutput() do { PORTF_DIRSET = 0x20; } while(0)
#define IO_PF5_SetPullUp() do { PORTF_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF5_ResetPullUp() do { PORTF_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF5_SetInverted() do { PORTF_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF5_ResetInverted() do { PORTF_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF5_DisableInterruptOnChange() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF5_EnableInterruptForBothEdges() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF5_EnableInterruptForRisingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF5_EnableInterruptForFallingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF5_DisableDigitalInputBuffer() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF5_EnableInterruptForLowLevelSensing() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF5_SetInterruptHandler IO_PF5_SetInterruptHandler

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD5 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD5_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD5 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD5_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD5 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD5 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD5_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD4 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD4_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD4 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD4_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD4 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD4 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD4_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PA7 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PA7_SetInterruptHandler() method.
 *        This handler is called every time the IO_PA7 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PA7_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PA7 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PA7 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PA7_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD6 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD6_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD6 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD6_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD6 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD6 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD6_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PF4 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PF4_SetInterruptHandler() method.
 *        This handler is called every time the IO_PF4 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PF4_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PF4 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PF4 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PF4_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PF6 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PF6_SetInterruptHandler() method.
 *        This handler is called every time the IO_PF6 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PF6_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PF6 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PF6 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PF6_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PF5 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PF5_SetInterruptHandler() method.
 *        This handler is called every time the IO_PF5 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PF5_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PF5 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PF5 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PF5_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */
