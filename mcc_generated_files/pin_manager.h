/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15.3
        Device            :  PIC18F46K80
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define IO_RA0_TRIS               TRISAbits.TRISA0
#define IO_RA0_LAT                LATAbits.LATA0
#define IO_RA0_PORT               PORTAbits.RA0
#define IO_RA0_ANS                ANCON0bits.ANSEL0
#define IO_RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_RA0_GetValue()           PORTAbits.RA0
#define IO_RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_RA0_SetAnalogMode()  do { ANCON0bits.ANSEL0 = 1; } while(0)
#define IO_RA0_SetDigitalMode() do { ANCON0bits.ANSEL0 = 0; } while(0)

// get/set IO_RA1 aliases
#define IO_RA1_TRIS               TRISAbits.TRISA1
#define IO_RA1_LAT                LATAbits.LATA1
#define IO_RA1_PORT               PORTAbits.RA1
#define IO_RA1_ANS                ANCON0bits.ANSEL1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetAnalogMode()  do { ANCON0bits.ANSEL1 = 1; } while(0)
#define IO_RA1_SetDigitalMode() do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set IO_RA2 aliases
#define IO_RA2_TRIS               TRISAbits.TRISA2
#define IO_RA2_LAT                LATAbits.LATA2
#define IO_RA2_PORT               PORTAbits.RA2
#define IO_RA2_ANS                ANCON0bits.ANSEL2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetAnalogMode()  do { ANCON0bits.ANSEL2 = 1; } while(0)
#define IO_RA2_SetDigitalMode() do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set H6 aliases
#define H6_TRIS               TRISAbits.TRISA3
#define H6_LAT                LATAbits.LATA3
#define H6_PORT               PORTAbits.RA3
#define H6_ANS                ANCON0bits.ANSEL3
#define H6_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define H6_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define H6_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define H6_GetValue()           PORTAbits.RA3
#define H6_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define H6_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define H6_SetAnalogMode()  do { ANCON0bits.ANSEL3 = 1; } while(0)
#define H6_SetDigitalMode() do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set IO_RA5 aliases
#define IO_RA5_TRIS               TRISAbits.TRISA5
#define IO_RA5_LAT                LATAbits.LATA5
#define IO_RA5_PORT               PORTAbits.RA5
#define IO_RA5_ANS                ANCON0bits.ANSEL4
#define IO_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_RA5_GetValue()           PORTAbits.RA5
#define IO_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_RA5_SetAnalogMode()  do { ANCON0bits.ANSEL4 = 1; } while(0)
#define IO_RA5_SetDigitalMode() do { ANCON0bits.ANSEL4 = 0; } while(0)

// get/set H7 aliases
#define H7_TRIS               TRISBbits.TRISB0
#define H7_LAT                LATBbits.LATB0
#define H7_PORT               PORTBbits.RB0
#define H7_WPU                WPUBbits.WPUB0
#define H7_ANS                ANCON1bits.ANSEL10
#define H7_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define H7_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define H7_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define H7_GetValue()           PORTBbits.RB0
#define H7_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define H7_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define H7_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define H7_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define H7_SetAnalogMode()  do { ANCON1bits.ANSEL10 = 1; } while(0)
#define H7_SetDigitalMode() do { ANCON1bits.ANSEL10 = 0; } while(0)

// get/set H8 aliases
#define H8_TRIS               TRISBbits.TRISB1
#define H8_LAT                LATBbits.LATB1
#define H8_PORT               PORTBbits.RB1
#define H8_WPU                WPUBbits.WPUB1
#define H8_ANS                ANCON1bits.ANSEL8
#define H8_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define H8_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define H8_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define H8_GetValue()           PORTBbits.RB1
#define H8_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define H8_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define H8_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define H8_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define H8_SetAnalogMode()  do { ANCON1bits.ANSEL8 = 1; } while(0)
#define H8_SetDigitalMode() do { ANCON1bits.ANSEL8 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()    do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()   do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()   do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()         PORTBbits.RB2
#define RB2_SetDigitalInput()   do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()  do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()     do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()   do { WPUBbits.WPUB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()    do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()   do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()   do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()         PORTBbits.RB3
#define RB3_SetDigitalInput()   do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()  do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()     do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()   do { WPUBbits.WPUB3 = 0; } while(0)

// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISBbits.TRISB4
#define IO_RB4_LAT                LATBbits.LATB4
#define IO_RB4_PORT               PORTBbits.RB4
#define IO_RB4_WPU                WPUBbits.WPUB4
#define IO_RB4_ANS                ANCON1bits.ANSEL9
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()  do { ANCON1bits.ANSEL9 = 1; } while(0)
#define IO_RB4_SetDigitalMode() do { ANCON1bits.ANSEL9 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS               TRISBbits.TRISB5
#define IO_RB5_LAT                LATBbits.LATB5
#define IO_RB5_PORT               PORTBbits.RB5
#define IO_RB5_WPU                WPUBbits.WPUB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS               TRISBbits.TRISB6
#define IO_RB6_LAT                LATBbits.LATB6
#define IO_RB6_PORT               PORTBbits.RB6
#define IO_RB6_WPU                WPUBbits.WPUB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()      do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()    do { WPUBbits.WPUB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS               TRISBbits.TRISB7
#define IO_RB7_LAT                LATBbits.LATB7
#define IO_RB7_PORT               PORTBbits.RB7
#define IO_RB7_WPU                WPUBbits.WPUB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()      do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()    do { WPUBbits.WPUB7 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS               TRISCbits.TRISC0
#define IO_RC0_LAT                LATCbits.LATC0
#define IO_RC0_PORT               PORTCbits.RC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISCbits.TRISC1
#define IO_RC1_LAT                LATCbits.LATC1
#define IO_RC1_PORT               PORTCbits.RC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS               TRISCbits.TRISC2
#define IO_RC2_LAT                LATCbits.LATC2
#define IO_RC2_PORT               PORTCbits.RC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set STB aliases
#define STB_TRIS               TRISCbits.TRISC3
#define STB_LAT                LATCbits.LATC3
#define STB_PORT               PORTCbits.RC3
#define STB_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define STB_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define STB_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define STB_GetValue()           PORTCbits.RC3
#define STB_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define STB_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set N_LED aliases
#define N_LED_TRIS               TRISCbits.TRISC4
#define N_LED_LAT                LATCbits.LATC4
#define N_LED_PORT               PORTCbits.RC4
#define N_LED_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define N_LED_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define N_LED_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define N_LED_GetValue()           PORTCbits.RC4
#define N_LED_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define N_LED_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set R_LED aliases
#define R_LED_TRIS               TRISCbits.TRISC5
#define R_LED_LAT                LATCbits.LATC5
#define R_LED_PORT               PORTCbits.RC5
#define R_LED_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define R_LED_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define R_LED_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define R_LED_GetValue()           PORTCbits.RC5
#define R_LED_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define R_LED_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set P_LED aliases
#define P_LED_TRIS               TRISCbits.TRISC6
#define P_LED_LAT                LATCbits.LATC6
#define P_LED_PORT               PORTCbits.RC6
#define P_LED_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define P_LED_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define P_LED_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define P_LED_GetValue()           PORTCbits.RC6
#define P_LED_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define P_LED_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set H1 aliases
#define H1_TRIS               TRISCbits.TRISC7
#define H1_LAT                LATCbits.LATC7
#define H1_PORT               PORTCbits.RC7
#define H1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define H1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define H1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define H1_GetValue()           PORTCbits.RC7
#define H1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define H1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set Shift_Lock aliases
#define Shift_Lock_TRIS               TRISDbits.TRISD0
#define Shift_Lock_LAT                LATDbits.LATD0
#define Shift_Lock_PORT               PORTDbits.RD0
#define Shift_Lock_ANS                ANCON1bits.ANSEL11
#define Shift_Lock_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define Shift_Lock_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define Shift_Lock_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define Shift_Lock_GetValue()           PORTDbits.RD0
#define Shift_Lock_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define Shift_Lock_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define Shift_Lock_SetAnalogMode()  do { ANCON1bits.ANSEL11 = 1; } while(0)
#define Shift_Lock_SetDigitalMode() do { ANCON1bits.ANSEL11 = 0; } while(0)

// get/set P_Button aliases
#define P_Button_TRIS               TRISDbits.TRISD1
#define P_Button_LAT                LATDbits.LATD1
#define P_Button_PORT               PORTDbits.RD1
#define P_Button_ANS                ANCON1bits.ANSEL12
#define P_Button_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define P_Button_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define P_Button_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define P_Button_GetValue()           PORTDbits.RD1
#define P_Button_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define P_Button_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define P_Button_SetAnalogMode()  do { ANCON1bits.ANSEL12 = 1; } while(0)
#define P_Button_SetDigitalMode() do { ANCON1bits.ANSEL12 = 0; } while(0)

// get/set M_LED aliases
#define M_LED_TRIS               TRISDbits.TRISD2
#define M_LED_LAT                LATDbits.LATD2
#define M_LED_PORT               PORTDbits.RD2
#define M_LED_ANS                ANCON1bits.ANSEL13
#define M_LED_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define M_LED_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define M_LED_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define M_LED_GetValue()           PORTDbits.RD2
#define M_LED_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define M_LED_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define M_LED_SetAnalogMode()  do { ANCON1bits.ANSEL13 = 1; } while(0)
#define M_LED_SetDigitalMode() do { ANCON1bits.ANSEL13 = 0; } while(0)

// get/set D_LED aliases
#define D_LED_TRIS               TRISDbits.TRISD3
#define D_LED_LAT                LATDbits.LATD3
#define D_LED_PORT               PORTDbits.RD3
#define D_LED_ANS                ANCON1bits.ANSEL14
#define D_LED_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define D_LED_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define D_LED_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define D_LED_GetValue()           PORTDbits.RD3
#define D_LED_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define D_LED_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define D_LED_SetAnalogMode()  do { ANCON1bits.ANSEL14 = 1; } while(0)
#define D_LED_SetDigitalMode() do { ANCON1bits.ANSEL14 = 0; } while(0)

// get/set H2 aliases
#define H2_TRIS               TRISDbits.TRISD4
#define H2_LAT                LATDbits.LATD4
#define H2_PORT               PORTDbits.RD4
#define H2_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define H2_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define H2_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define H2_GetValue()           PORTDbits.RD4
#define H2_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define H2_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set H3 aliases
#define H3_TRIS               TRISDbits.TRISD5
#define H3_LAT                LATDbits.LATD5
#define H3_PORT               PORTDbits.RD5
#define H3_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define H3_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define H3_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define H3_GetValue()           PORTDbits.RD5
#define H3_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define H3_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

// get/set H4 aliases
#define H4_TRIS               TRISDbits.TRISD6
#define H4_LAT                LATDbits.LATD6
#define H4_PORT               PORTDbits.RD6
#define H4_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define H4_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define H4_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define H4_GetValue()           PORTDbits.RD6
#define H4_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define H4_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

// get/set H5 aliases
#define H5_TRIS               TRISDbits.TRISD7
#define H5_LAT                LATDbits.LATD7
#define H5_PORT               PORTDbits.RD7
#define H5_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define H5_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define H5_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define H5_GetValue()           PORTDbits.RD7
#define H5_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define H5_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

// get/set IO_RE0 aliases
#define IO_RE0_TRIS               TRISEbits.TRISE0
#define IO_RE0_LAT                LATEbits.LATE0
#define IO_RE0_PORT               PORTEbits.RE0
#define IO_RE0_ANS                ANCON0bits.ANSEL5
#define IO_RE0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define IO_RE0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define IO_RE0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define IO_RE0_GetValue()           PORTEbits.RE0
#define IO_RE0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define IO_RE0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define IO_RE0_SetAnalogMode()  do { ANCON0bits.ANSEL5 = 1; } while(0)
#define IO_RE0_SetDigitalMode() do { ANCON0bits.ANSEL5 = 0; } while(0)

// get/set IO_RE1 aliases
#define IO_RE1_TRIS               TRISEbits.TRISE1
#define IO_RE1_LAT                LATEbits.LATE1
#define IO_RE1_PORT               PORTEbits.RE1
#define IO_RE1_ANS                ANCON0bits.ANSEL6
#define IO_RE1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define IO_RE1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define IO_RE1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define IO_RE1_GetValue()           PORTEbits.RE1
#define IO_RE1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define IO_RE1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define IO_RE1_SetAnalogMode()  do { ANCON0bits.ANSEL6 = 1; } while(0)
#define IO_RE1_SetDigitalMode() do { ANCON0bits.ANSEL6 = 0; } while(0)

// get/set IO_RE2 aliases
#define IO_RE2_TRIS               TRISEbits.TRISE2
#define IO_RE2_LAT                LATEbits.LATE2
#define IO_RE2_PORT               PORTEbits.RE2
#define IO_RE2_ANS                ANCON0bits.ANSEL7
#define IO_RE2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define IO_RE2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define IO_RE2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define IO_RE2_GetValue()           PORTEbits.RE2
#define IO_RE2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define IO_RE2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define IO_RE2_SetAnalogMode()  do { ANCON0bits.ANSEL7 = 1; } while(0)
#define IO_RE2_SetDigitalMode() do { ANCON0bits.ANSEL7 = 0; } while(0)

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