/**
  TMR1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.c

  @Summary
    This is the generated driver implementation file for the TMR1 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for TMR1.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC18F46K80
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "mcc.h"
#include "tmr1.h"


/**
  Section: Global Variables Definitions
*/
volatile uint16_t timer1ReloadVal;
void (*TMR1_InterruptHandler)(void);

/**
  Section: TMR1 APIs
*/

void TMR1_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T1CKPS 1:8; RD16 disabled; SOSCEN disabled; nT1SYNC synchronize; TMR1CS FOSC/4; TMR1ON off; 
    T1CON = 0x30;

    //T1GSS T1G; TMR1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; T1GVAL disabled; 
    T1GCON = 0x00;

    //TMR1H 177; 
    TMR1H = 0xB1;

    //TMR1L 224; 
    TMR1L = 0xE0;

    // Load the TMR value to reload variable
    timer1ReloadVal=(TMR1H << 8) | TMR1L;

    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR1IF = 0;

    // Enabling TMR1 interrupt.
    PIE1bits.TMR1IE = 1;

    // Set Default Interrupt Handler
    TMR1_SetInterruptHandler(TMR1_DefaultInterruptHandler);

    // Start TMR1
    TMR1_StartTimer();
}

void TMR1_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void TMR1_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}

uint16_t TMR1_ReadTimer(void)
{
    uint16_t readVal;

    readVal = (TMR1H << 8) | TMR1L;

    return readVal;
}

void TMR1_WriteTimer(uint16_t timerVal)
{
    if (T1CONbits.nT1SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON = 0;

        // Write to the Timer1 register
        TMR1H = (timerVal >> 8);
        TMR1L = timerVal;

        // Start the Timer after writing to the register
        T1CONbits.TMR1ON =1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H = (timerVal >> 8);
        TMR1L = timerVal;
    }
}

void TMR1_Reload(void)
{
    //Write to the Timer1 register
    TMR1H = (timer1ReloadVal >> 8);
    TMR1L = timer1ReloadVal;
}

void TMR1_StartSinglePulseAcquisition(void)
{
    T1GCONbits.T1GGO = 1;
}

uint8_t TMR1_CheckGateValueStatus(void)
{
    return (T1GCONbits.T1GVAL);
}

void TMR1_ISR(void)
{

    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF = 0;

    TMR1H = (timer1ReloadVal >> 8);
    TMR1L = timer1ReloadVal;

    // ticker function call;
    // ticker is 1 -> Callback function gets called everytime this ISR executes
    TMR1_CallBack();
}

void TMR1_CallBack(void)
{
    // Add your custom callback code here
    if(TMR1_InterruptHandler)
    {
        TMR1_InterruptHandler();
    }
}

void TMR1_SetInterruptHandler(void* InterruptHandler){
    TMR1_InterruptHandler = InterruptHandler;
}

void TMR1_DefaultInterruptHandler(void){
    // add your TMR1 interrupt custom code
    // or set custom function using TMR1_SetInterruptHandler()
    // 10ms per cycle
    int remainder = 0;
	
    ESTTxCount++;
    if(ESTTxCount > ESTTXCOUNT){        // 50ms per cycle
        ESTTxCount = 0;
        flag.TX = 1;
    }
    Flag2._10ms = 1;
    if(RXB0CONbits.RXFUL != 0){
        flag.RX = 1;
    }
    
    if(flag.ERR == 0){
        if(COMSTATbits.TXBO == 0){
            RecoveryCount++;
        }
        else
            RecoveryCount = 0;
        if(RecoveryCount > 2){
            ErrCount = 0;
            RecoveryCount = 0;
        }
    }
    else
        RecoveryCount = 0;
        
    if(flag.SLEEP == 1){
        TimeCount++;         
    } 
#if 1
	switch ( GearPosition ) {
	  case TCU_Position_P:
	     P_lamp_ctrl_SetHigh ();
	     break;
	  case TCU_Position_R:
	  	 remainder = BlinkCount % 50;
 		 if ( remainder == 0 )
		 	ToggleCount++;
		 if ( ToggleCount < 1 ) {
		 if ( remainder == 1 )
		   P_lamp_ctrl_SetHigh ();
		 else
			if ( remainder == 25 )
		 	  P_lamp_ctrl_SetLow ();
		 }
		 else
		 	if ( ToggleCount == 4 )
 			  ToggleCount = 0;
	     break;

	  case TCU_Position_N:
	  	 remainder = BlinkCount % 50;
 		 if ( remainder == 0 )
		 	ToggleCount++;
		 if ( ToggleCount < 2 ) {
		 if ( remainder == 1 )
		   P_lamp_ctrl_SetHigh ();
		 else
			if ( remainder == 25 )
		 	  P_lamp_ctrl_SetLow ();
		 }
		 else
		 	if ( ToggleCount == 5 )
 			  ToggleCount = 0;
	     break;

  	  case TCU_Position_D:
	  	 remainder = BlinkCount % 50;
 		 if ( remainder == 0 )
		 	ToggleCount++;
		 if ( ToggleCount < 3 ) {
		 if ( remainder == 1 )
		   P_lamp_ctrl_SetHigh ();
		 else
			if ( remainder == 25 )
		 	  P_lamp_ctrl_SetLow ();
		 }
		 else
		 	if ( ToggleCount == 6 )
 			  ToggleCount = 0;
	     break;
	}
	BlinkCount++;
#endif
}

/**
  End of File
*/
