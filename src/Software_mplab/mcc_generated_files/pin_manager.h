/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F26K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_VERDE aliases
#define LED_VERDE_TRIS                 TRISAbits.TRISA2
#define LED_VERDE_LAT                  LATAbits.LATA2
#define LED_VERDE_PORT                 PORTAbits.RA2
#define LED_VERDE_WPU                  WPUAbits.WPUA2
#define LED_VERDE_OD                   ODCONAbits.ODCA2
#define LED_VERDE_ANS                  ANSELAbits.ANSELA2
#define LED_VERDE_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_VERDE_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_VERDE_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_VERDE_GetValue()           PORTAbits.RA2
#define LED_VERDE_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_VERDE_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_VERDE_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_VERDE_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_VERDE_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_VERDE_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_VERDE_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LED_VERDE_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LED_ROJO aliases
#define LED_ROJO_TRIS                 TRISAbits.TRISA3
#define LED_ROJO_LAT                  LATAbits.LATA3
#define LED_ROJO_PORT                 PORTAbits.RA3
#define LED_ROJO_WPU                  WPUAbits.WPUA3
#define LED_ROJO_OD                   ODCONAbits.ODCA3
#define LED_ROJO_ANS                  ANSELAbits.ANSELA3
#define LED_ROJO_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED_ROJO_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED_ROJO_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED_ROJO_GetValue()           PORTAbits.RA3
#define LED_ROJO_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED_ROJO_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED_ROJO_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LED_ROJO_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LED_ROJO_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LED_ROJO_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LED_ROJO_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LED_ROJO_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set AZ_R aliases
#define AZ_R_TRIS                 TRISAbits.TRISA6
#define AZ_R_LAT                  LATAbits.LATA6
#define AZ_R_PORT                 PORTAbits.RA6
#define AZ_R_WPU                  WPUAbits.WPUA6
#define AZ_R_OD                   ODCONAbits.ODCA6
#define AZ_R_ANS                  ANSELAbits.ANSELA6
#define AZ_R_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define AZ_R_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define AZ_R_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define AZ_R_GetValue()           PORTAbits.RA6
#define AZ_R_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define AZ_R_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define AZ_R_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define AZ_R_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define AZ_R_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define AZ_R_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define AZ_R_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define AZ_R_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set EMERGENCY aliases
#define EMERGENCY_TRIS                 TRISAbits.TRISA7
#define EMERGENCY_LAT                  LATAbits.LATA7
#define EMERGENCY_PORT                 PORTAbits.RA7
#define EMERGENCY_WPU                  WPUAbits.WPUA7
#define EMERGENCY_OD                   ODCONAbits.ODCA7
#define EMERGENCY_ANS                  ANSELAbits.ANSELA7
#define EMERGENCY_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define EMERGENCY_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define EMERGENCY_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define EMERGENCY_GetValue()           PORTAbits.RA7
#define EMERGENCY_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define EMERGENCY_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define EMERGENCY_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define EMERGENCY_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define EMERGENCY_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define EMERGENCY_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define EMERGENCY_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define EMERGENCY_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set DIR1 aliases
#define DIR1_TRIS                 TRISBbits.TRISB0
#define DIR1_LAT                  LATBbits.LATB0
#define DIR1_PORT                 PORTBbits.RB0
#define DIR1_WPU                  WPUBbits.WPUB0
#define DIR1_OD                   ODCONBbits.ODCB0
#define DIR1_ANS                  ANSELBbits.ANSELB0
#define DIR1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define DIR1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define DIR1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define DIR1_GetValue()           PORTBbits.RB0
#define DIR1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define DIR1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define DIR1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define DIR1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define DIR1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define DIR1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define DIR1_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define DIR1_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set STEP1 aliases
#define STEP1_TRIS                 TRISBbits.TRISB1
#define STEP1_LAT                  LATBbits.LATB1
#define STEP1_PORT                 PORTBbits.RB1
#define STEP1_WPU                  WPUBbits.WPUB1
#define STEP1_OD                   ODCONBbits.ODCB1
#define STEP1_ANS                  ANSELBbits.ANSELB1
#define STEP1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define STEP1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define STEP1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define STEP1_GetValue()           PORTBbits.RB1
#define STEP1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define STEP1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define STEP1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define STEP1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define STEP1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define STEP1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define STEP1_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define STEP1_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set MS2 aliases
#define MS2_TRIS                 TRISBbits.TRISB2
#define MS2_LAT                  LATBbits.LATB2
#define MS2_PORT                 PORTBbits.RB2
#define MS2_WPU                  WPUBbits.WPUB2
#define MS2_OD                   ODCONBbits.ODCB2
#define MS2_ANS                  ANSELBbits.ANSELB2
#define MS2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define MS2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define MS2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define MS2_GetValue()           PORTBbits.RB2
#define MS2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define MS2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define MS2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define MS2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define MS2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define MS2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define MS2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define MS2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set MS1 aliases
#define MS1_TRIS                 TRISBbits.TRISB3
#define MS1_LAT                  LATBbits.LATB3
#define MS1_PORT                 PORTBbits.RB3
#define MS1_WPU                  WPUBbits.WPUB3
#define MS1_OD                   ODCONBbits.ODCB3
#define MS1_ANS                  ANSELBbits.ANSELB3
#define MS1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define MS1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define MS1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define MS1_GetValue()           PORTBbits.RB3
#define MS1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define MS1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define MS1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define MS1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define MS1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define MS1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define MS1_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define MS1_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set MS0 aliases
#define MS0_TRIS                 TRISBbits.TRISB4
#define MS0_LAT                  LATBbits.LATB4
#define MS0_PORT                 PORTBbits.RB4
#define MS0_WPU                  WPUBbits.WPUB4
#define MS0_OD                   ODCONBbits.ODCB4
#define MS0_ANS                  ANSELBbits.ANSELB4
#define MS0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define MS0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define MS0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define MS0_GetValue()           PORTBbits.RB4
#define MS0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define MS0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define MS0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define MS0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define MS0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define MS0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define MS0_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define MS0_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set ENABLE aliases
#define ENABLE_TRIS                 TRISBbits.TRISB5
#define ENABLE_LAT                  LATBbits.LATB5
#define ENABLE_PORT                 PORTBbits.RB5
#define ENABLE_WPU                  WPUBbits.WPUB5
#define ENABLE_OD                   ODCONBbits.ODCB5
#define ENABLE_ANS                  ANSELBbits.ANSELB5
#define ENABLE_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define ENABLE_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define ENABLE_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define ENABLE_GetValue()           PORTBbits.RB5
#define ENABLE_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define ENABLE_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define ENABLE_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define ENABLE_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define ENABLE_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define ENABLE_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define ENABLE_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define ENABLE_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set AZ_L aliases
#define AZ_L_TRIS                 TRISCbits.TRISC0
#define AZ_L_LAT                  LATCbits.LATC0
#define AZ_L_PORT                 PORTCbits.RC0
#define AZ_L_WPU                  WPUCbits.WPUC0
#define AZ_L_OD                   ODCONCbits.ODCC0
#define AZ_L_ANS                  ANSELCbits.ANSELC0
#define AZ_L_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define AZ_L_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define AZ_L_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define AZ_L_GetValue()           PORTCbits.RC0
#define AZ_L_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define AZ_L_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define AZ_L_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define AZ_L_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define AZ_L_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define AZ_L_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define AZ_L_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define AZ_L_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set EL_R aliases
#define EL_R_TRIS                 TRISCbits.TRISC1
#define EL_R_LAT                  LATCbits.LATC1
#define EL_R_PORT                 PORTCbits.RC1
#define EL_R_WPU                  WPUCbits.WPUC1
#define EL_R_OD                   ODCONCbits.ODCC1
#define EL_R_ANS                  ANSELCbits.ANSELC1
#define EL_R_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define EL_R_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define EL_R_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define EL_R_GetValue()           PORTCbits.RC1
#define EL_R_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define EL_R_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define EL_R_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define EL_R_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define EL_R_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define EL_R_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define EL_R_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define EL_R_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set EL_L aliases
#define EL_L_TRIS                 TRISCbits.TRISC2
#define EL_L_LAT                  LATCbits.LATC2
#define EL_L_PORT                 PORTCbits.RC2
#define EL_L_WPU                  WPUCbits.WPUC2
#define EL_L_OD                   ODCONCbits.ODCC2
#define EL_L_ANS                  ANSELCbits.ANSELC2
#define EL_L_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define EL_L_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define EL_L_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define EL_L_GetValue()           PORTCbits.RC2
#define EL_L_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define EL_L_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define EL_L_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define EL_L_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define EL_L_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define EL_L_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define EL_L_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define EL_L_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set DIR2 aliases
#define DIR2_TRIS                 TRISCbits.TRISC6
#define DIR2_LAT                  LATCbits.LATC6
#define DIR2_PORT                 PORTCbits.RC6
#define DIR2_WPU                  WPUCbits.WPUC6
#define DIR2_OD                   ODCONCbits.ODCC6
#define DIR2_ANS                  ANSELCbits.ANSELC6
#define DIR2_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define DIR2_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define DIR2_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define DIR2_GetValue()           PORTCbits.RC6
#define DIR2_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define DIR2_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define DIR2_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define DIR2_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define DIR2_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define DIR2_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define DIR2_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define DIR2_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set STEP2 aliases
#define STEP2_TRIS                 TRISCbits.TRISC7
#define STEP2_LAT                  LATCbits.LATC7
#define STEP2_PORT                 PORTCbits.RC7
#define STEP2_WPU                  WPUCbits.WPUC7
#define STEP2_OD                   ODCONCbits.ODCC7
#define STEP2_ANS                  ANSELCbits.ANSELC7
#define STEP2_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define STEP2_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define STEP2_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define STEP2_GetValue()           PORTCbits.RC7
#define STEP2_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define STEP2_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define STEP2_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define STEP2_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define STEP2_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define STEP2_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define STEP2_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define STEP2_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/