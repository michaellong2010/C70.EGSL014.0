/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include "mcc.h"

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation



unsigned int TimeCount = 0, ErrCount = 0, DutyCount = 0, i = 0, RecoveryCount = 0, ReleaseCount = 0, EstResult, ESTTxCount = 0, PButtonCount = 0;
uCAN_MSG rxMessage, txMessage;

#define             EST_ID                              0x131
#define             TCU_ID                              0x151
#define             APA_ID                              0x310
#define             Tester_DiagPhysRegToEST_ID             0x76E
#define             EST_DiagResp_ID                      0x7AE
#define             Tester_DiagFuncReg_ID                 0x7DF

#define             ERRCount                                4
#define             BusRecovery_190ms                       19
#define             BusRecovery40msTimes                     4


#define             LED_SMALL                 60
#define             LED_BIG                   10


typedef union Flag {    
    unsigned char all;
    struct{
        unsigned char TX:1;
        unsigned char RX:1;
        unsigned char SLEEP:1;
        unsigned char LED_R:1;
        unsigned char LED_N:1;
        unsigned char LED_D:1;
        unsigned char LED_P:1;
        unsigned char ERR:1;
    };    
};
volatile union Flag flag;
typedef union flag2 {    
    unsigned char all;
    struct{        
        unsigned char _10ms:1;
        unsigned char LED_SMA:1; 
        unsigned char Release:1; 
        unsigned char PButton:1;
        unsigned char LED_M:1;
        unsigned char re:3;
    };    
};
volatile union flag2 Flag2;



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

