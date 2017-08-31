/**
  TMR1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.h

  @Summary
    This is the generated header file for the TMR1 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for TMR1.
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

#ifndef _ESTTargetGear_H
#define _ESTTargetGear_H

#include <stdbool.h>
#include <stdint.h>

/**
  Section: Included Files
*/


void TargerGearDetector(void);
void TCUGearPosition(void);
void TargetGearJudge(void);
void APAMode(void);
void TCUGearLED(void);
void CAN_BUSRecovery(void);

unsigned int GearCount = 0, GearFailCount = 0,GearLatchCount = 0, EstAliveCount = 0, PLockCount = 0;
unsigned char NewGear = 0, OldGear = 0;

#define             TIME_60S                                        6000
#define             GearThreshold                                   20          // 200ms
#define             GearThreshold_11                                300          // 1000ms
#define             GearLatchThreshold                              1200        //1miniute
#define             PButtonLatchThreshold                            6000        //1miniute
#define             ESTTXCOUNT                                      4

// TCU_TrsmStGearLvr
#define             TCU_GEAR_P                          0x0
#define             TCU_GEAR_D                          0x5
#define             TCU_GEAR_N                          0x6
#define             TCU_GEAR_R                          0x7
#define             VCU_GEAR_M                          0x8
#define             TCU_GEAR_Invalid                     0xF


// EST_PButton
#define             PButton_NoRequest                   0x0
#define             PButton_RequestPark                 0x1
#define             PButton_ParkFault                   0x2

// ShiftLock
#define             ShiftLock_UnLock                    0x0
#define             ShiftLock_Lock                      0x1

// EST_FAULT
#define             EST_GEAR_Normal                     0x0
#define             EST_GEAR_Fail                       0x1

// EST_TargetGear
#define             EST_GEAR_P                          0x1
#define             EST_GEAR_R                          0x2
#define             EST_GEAR_N                          0x3
#define             EST_GEAR_D                          0x4
#define             EST_GEAR_M                          0x5
#define             EST_GEAR_Invalid                     0x7


// EST_APA InhibitCode
#define             EST_APA_InhibitCode_NormalOperation                 0x0
#define             EST_APA_InhibitCode_DriverInterference              0x2
#define             EST_APA_InhibitCode_AbnormalCANInput                0x3
#define             EST_APA_InhibitCode_ESTFailure                      0x5

// EST_APA Responce
#define             EST_APA_Responce_Inhibit                            0x0
#define             EST_APA_Responce_Available                          0x1
#define             EST_APA_Responce_Active                             0x2
#define             EST_APA_Responce_Abort                              0x3
#define             EST_APA_Responce_ReplyForControl                     0x4
#define             EST_APA_Responce_ADASActive                         0x5
#define             EST_APA_Responce_Failure                            0x7



#define                     APA_EST_REQUEST_NoRequest                        0x0
#define                     APA_EST_REQUEST_ControlESTRequest                 0x1
#define                     APA_EST_REQUEST_ESTControl                       0x2


typedef union flaggear {    
    unsigned int frame;
    struct{        
        unsigned char Gear_0:1;
        unsigned char Gear_1:1;
        unsigned char Gear_2:1;
        unsigned char Gear__1:1;
        unsigned char Gear__2:1;
        unsigned char Gear_Fail:1;
        unsigned char GearLatch:1;
        unsigned char re:2;
    };    
};
volatile union flaggear Flaggear;


typedef enum Status{
    Nochange_Status,
    Release_Status,
    GetNew_Status,
    Latch_Status,
    Failure_Status,
    Finish_Status
};
volatile enum Status GearStatus;

typedef enum gearposition{
    TCU_Position_P,
    TCU_Position_R,
    TCU_Position_N,
    TCU_Position_D,
    TCU_Position_M,
    TCU_Position_F
};
volatile enum gearposition GearPosition;

//misc peripheral data
typedef union meta_data_t {
  struct EGSL_status_t {
  	unsigned char gear_function_status: 1;  //0: normal; 1: malfunction
  	unsigned char park_indicator: 1;  //0: off; 1: on
  	unsigned char gear_decision: 4;  //xxxx: DNRP
  	unsigned char reserve1: 2;
	unsigned char gear_recognition: 3;  //0: none; 1: P; 2: R; 3: N; 4: D
  	unsigned char reserve2: 3;
	unsigned char gear_shift_alarm: 1;  //0: normal; 1: alarm
	unsigned char gear_malfunction: 2;  //1: R&D low level; 2: R low & N high; 3: D low & N high
	unsigned char gear_malfunction:
  	unsigned char reserve2: 35;
  	unsigned char checksum: 8;
  } egsl_status;
};

// EST Bit Function Specification Byte0
// Bit 0 Fault
//      0x0: normal
//      0x1: fault(Double fault shifter sensor)
//      ????????(?????????????)
// Bit 1,2,3 TargetGear ??????????
//      0x0: Reserve
//      0x1: P
//      0x2: R
//      0x3: N
//      0x4: D
//      0x5: M
//      0x6: Reserve
//      0x7: invalid
// Bit 4 UnlockStatus ???
//      0x0: unlock
//      0x1: lock
// Bit 5,6 PButton
//      0x0: no request
//      0x1: driver request park button
//      0x2: Park button fault
//      0x3: reserve
// Bit 7 Reserve


typedef union est_byte0 {    
    unsigned char frame;
    struct{
        unsigned char Fault:1;       
        unsigned char TargetGear:3;
        unsigned char UnlockStatus:1;
        unsigned char PButton:2;
        unsigned char Reserve:1;                       
    };    
};
volatile union est_byte0 EST_Byte0;

// EST Bit Function Specification Byte1
// Bit 8 Reserve
// Bit 9,10,11 APA InhibitCode
//      0x0: Normal Operation
//      0x1: Reserve
//      0x2: Driver Interference
//      0x3: Abnormal CAN input
//      0x4: Reserve
//      0x5: EST failure
//      0x6~7: Reserve
// Bit 12,13,14,15 APA_Responce
//      0x0: Inhibit
//      0x1: Available
//      0x2: Active
//      0x3: Abort(??)
//      0x4: Reply for Control
//      0x5: Reserve
//      0x6: ADAS active
//      0x7: failure
//      0x8~F: Reserve

typedef union est_byte1 {    
    unsigned char frame;
    struct{
        unsigned char Reserve:1;       
        unsigned char APA_InhbitCode:3;
        unsigned char APA_Responce:4;                
    };    
};
volatile union est_byte1 EST_Byte1;

// EST Bit Function Specification Byte7
// Bit 56,57,58,59 Checksum
//      result = [Byte0] XOR [Byte1] XOR [Byte2] XOR [Byte3] XOR [Byte4] XOR [Byte5] XOR [Byte6]
//      Checksum = [result(Low 4 bit)] XOR [result(High 4 bit)] XOR [Byte7(High 4 bit)]
// Bit 60,61,62,63 For Message Counter
//      A properly operating transmitter shall update the value
//      of the Message Counter signal every time a frme is transmitted, even if no other data
//      in the frame has changed value.
//      The counter value shall be updated in the sequence 0,1,2...15, etc. Upon start-up, 
//      the initial value of the Message Counter signal shall be 0(zero). 0-15??

typedef union est_byte7 {    
    unsigned char frame;
    struct{
        unsigned char ESTChecksum:4;       
        unsigned char ESTAliveCounter:4;                      
    };    
};
volatile union est_byte7 EST_Byte7;

// TCU Byte0
// During the shifting process this value informs about the
// gear which is expected to be engaged in the gear box 
// after the shifting process.
// ????, N??0
// 0xE: R?
// Bit0,1,2,3 reserved
// Bit4,5,6,7 TCU TrsmGearTar
//      0x0: P/N Gear
//      0x1: 1st gear
//      0x2: 2nd gear
//      0x3: 3rd gear
//      0x4: 4th gear
//      0x5: 5th gear
//      0x6: 6th gear
//      0x7: 7th gear
//      0x8: 8th gear(reserved)
//      0x9: drive gear(CVT)
//      0xA,B,C,D reserved
//      0xE: reverse gear
//      0xF: invalid      

typedef union tcu_byte0 {    
    unsigned char frame;
    struct{
        unsigned char Reserve:4;
        unsigned char TrsmGearTar:4;        
    };    
};
volatile union tcu_byte0 TCU_Byte0;


// TCU Byte1
// Bit 8 reserved
// Bit 9,10 TrsmFlgFlt
// Transmission system fault flag.
// This signal can be used to turn on transmission non-OBD fault lamp on the cluster.
// ??????
//      0x0: no failure
//      0x1: failure
//      0x2: failure(limp home activated)??????????2
//      0x3: not used
// Bit 11 TrsmFlgShiftProgs
//      0x0: no gear shift in process
//      0x1: gear shift in progress
// Indicates that a gear shift is in progress, i.e. transient torque transfer
// The TCU will always send 0x1 for this signal for VT5 project.
// ????????
// Bit 12,13,14,15 Acutal transmission Gear lever position based on the Transmission range selected by driver.
// ?????
// TrsmStGearLvr
//      0x0: P
//      0x1~0x4: not used
//      0x5: D
//      0x6: N
//      0x7: R
//      0x8: M
//      0x9~E: Reserved
//      0xF: invalid

typedef union tcu_byte1 {    
    unsigned char frame;
    struct{
        unsigned char Reserve:1;
        unsigned char TrsmFlgFlt:2;
        unsigned char TrsmFlgShiftProgs:1;
        unsigned char TrsmStGearLvr:4;        
    };    
};
volatile union tcu_byte1 TCU_Byte1;


// TCU Byte2
// Bit 16,17,18,19,20 Reserve
// Bit 21,22,23 TrsmStGearMode
// ?????
//      0x0: standard
//      0x1: winter(CVT / DCT???????)
//      0x2: sport
//      0x3: ECO
//      0x4: Manual
//      0x5: not used
//      0x6: not used
//      0x7: invalid(?????????????)


typedef union tcu_byte2 {    
    unsigned char frame;
    struct{
        unsigned char Reserve:5;
        unsigned char TrsmStGearMode:3;              
    };    
};
volatile union tcu_byte2 TCU_Byte2;

// APA Byte0
// Bit 0,1 EST_Request
// ?EST????
//      0x0: no request
//      0x1: Control EST request
//      0x2: EST Control
//      0x3: Reserve
// Bit 2,3,4,5 Reserve
// Bit 6 Active
// APA??
//      0x0: no active
//      0x1: 
// Bit 7 APA??
//      0x0: no failed
//      0x1: failed

typedef union apa_byte0 {    
    unsigned char frame;
    struct{
        unsigned char EST_Request:2;
        unsigned char Reserve:4;
        unsigned char Active:1;
        unsigned char Failed:1;        
    };    
};
volatile union apa_byte0 APA_Byte0;

// APA Byte6
// TargetGear ??????
// Bit 48,49,50 reserved
// Bit 51,52,53 Target Gear
//      0x0: Reserve
//      0x1: P
//      0x2: R
//      0x3: N
//      0x4: D
//      0x5: Reserve
//      0x6: Reserve
//      0x7: invalid

typedef union apa_byte6 {    
    unsigned char frame;
    struct{
        unsigned char Reserve:3;
        unsigned char TargetGear:3;
        unsigned char Reserve2:2;         
    };    
};
volatile union apa_byte6 APA_Byte6;


#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif



#endif // _TMR1_H
/**
 End of File
*/
