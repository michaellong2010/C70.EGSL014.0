/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
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

#include "mcc_generated_files/mcc.h"


/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    //P_lamp_ctrl_SetLow();
    //Flaggear.shift_lock = 1;
    while (1) {
        TargerGearDetector();
        if ( shift_lock == 1 )
            P_lamp_ctrl_SetLow();
        else
            P_lamp_ctrl_SetHigh();
        __delay_ms(100);
    }
    
    rxMessage.frame.idType = 0;
    rxMessage.frame.id = 0;
    rxMessage.frame.dlc = 0;
    rxMessage.frame.data0 = 0;
    rxMessage.frame.data1 = 0;
    rxMessage.frame.data2 = 0;
    rxMessage.frame.data3 = 0;
    rxMessage.frame.data4 = 0;
    rxMessage.frame.data5 = 0;
    rxMessage.frame.data6 = 0;
    rxMessage.frame.data7 = 0;
    
    txMessage.frame.idType = 0;
    txMessage.frame.id = 0;
    txMessage.frame.dlc = 0;
    txMessage.frame.data0 = 0;
    txMessage.frame.data1 = 0;
    txMessage.frame.data2 = 0;
    txMessage.frame.data3 = 0;
    txMessage.frame.data4 = 0;
    txMessage.frame.data5 = 0;
    txMessage.frame.data6 = 0;
    txMessage.frame.data7 = 0;
    flag.all = 0;
    Flag2.all = 0;
    Flag2.Release = 1;
    EST_Byte0.TargetGear = EST_GEAR_P; 
    __delay_ms(10);
    while (1)
    {
        // Add your application code
        ClrWdt();        
        CAN_BUSRecovery();
    //    __delay_ms(1);
        if(Flag2._10ms){
            Flag2._10ms = 0;
            if(Flag2.PButton == 0){
                TargerGearDetector();
                TCUGearPosition();
                TargetGearJudge(); 
            }            
            if(Shift_Lock_GetValue() == 0){
                EST_Byte0.UnlockStatus = ShiftLock_UnLock;   // unlock             
            }
            else{
                EST_Byte0.UnlockStatus = ShiftLock_Lock;     // lock                 
            }
            
            if(Flag2.Release == 0 && Flag2.PButton == 0){ 
                if(P_Button_GetValue() == 1){
                    Flag2.Release = 1;                        
                    PLockCount = 0;                    
                }
                else{
                    PLockCount++;
                    if(PLockCount > PButtonLatchThreshold)
                        EST_Byte0.PButton = PButton_ParkFault;          // button latch                        
                    ReleaseCount = 0;                    
                }
            } 
            if(Flag2.Release){
                if(P_Button_GetValue() == 0){                    
                    Flag2.PButton = 1;
                    Flag2.Release = 0;
                    PLockCount = 0;
                }            
            }            
            APAMode();
        }
            
        if(flag.TX && COMSTATbits.TXBO == 0){
            flag.TX = 0; 
            // Check P button status
            if(Flag2.PButton){
                PButtonCount++;
                if(PButtonCount > 2){
                    Flag2.PButton = 0;
                    EST_Byte0.PButton = PButton_NoRequest;
                    PButtonCount = 0;
                }
                else{
                    EST_Byte0.PButton = PButton_RequestPark; 
                    EST_Byte0.TargetGear = EST_GEAR_P;
                }
            }          
            
            txMessage.frame.id = EST_ID;
            txMessage.frame.dlc = 8;             
            txMessage.frame.data0 = EST_Byte0.frame;
            txMessage.frame.data1 = EST_Byte1.frame;
            EstResult = EST_Byte0.frame ^ EST_Byte1.frame;
            EstAliveCount++;
            if(EstAliveCount > 0xF)
                EstAliveCount = 0;
            EST_Byte7.ESTAliveCounter = EstAliveCount; 
            EST_Byte7.ESTChecksum = (EstResult & 0x0F) ^ ((EstResult >> 4) & 0x0F) ^ EstAliveCount;            
            txMessage.frame.data7 = EST_Byte7.frame;
            CAN_transmit(&txMessage);             
        }
        if(flag.RX){
            flag.RX = 0;
            CAN_receive(&rxMessage);
            if(rxMessage.frame.id == TCU_ID){
                TCU_Byte0.frame = rxMessage.frame.data0;
                TCU_Byte1.frame = rxMessage.frame.data1;
                TCU_Byte2.frame = rxMessage.frame.data2;                
            }
            if(rxMessage.frame.id == APA_ID){
                APA_Byte0.frame = rxMessage.frame.data0;
                APA_Byte6.frame = rxMessage.frame.data6; 
       //        APAMode();
            }
        }
    }
}

void TCUGearPosition(void)
{
    if(TCU_Byte1.TrsmStGearLvr == TCU_GEAR_P){         // 0x0 Gear P
        GearPosition = TCU_Position_P;
        flag.LED_P = 1;
        flag.LED_R = 0;
        flag.LED_N = 0;
        flag.LED_D = 0;
        Flag2.LED_M = 0;
    }
    else if(TCU_Byte1.TrsmStGearLvr == TCU_GEAR_D){        // 0x5 Gear D
        GearPosition = TCU_Position_D;
        flag.LED_P = 0;
        flag.LED_R = 0;
        flag.LED_N = 0;
        flag.LED_D = 1;
        Flag2.LED_M = 0;
    }
    else if(TCU_Byte1.TrsmStGearLvr == TCU_GEAR_N){        // 0x6 Gear N
        GearPosition = TCU_Position_N;
        flag.LED_P = 0;
        flag.LED_R = 0;
        flag.LED_N = 1;
        flag.LED_D = 0;
        Flag2.LED_M = 0;
    }
    else if(TCU_Byte1.TrsmStGearLvr == TCU_GEAR_R){        // 0x7 Gear R
        GearPosition = TCU_Position_R;
        flag.LED_P = 0;
        flag.LED_R = 1;
        flag.LED_N = 0;
        flag.LED_D = 0;
        Flag2.LED_M = 0;
    }
    else if(TCU_Byte1.TrsmStGearLvr == VCU_GEAR_M){        // 0x8 Gear_M
        GearPosition = TCU_Position_M;
        flag.LED_P = 0;
        flag.LED_R = 0;
        flag.LED_N = 0;
        flag.LED_D = 0;
        Flag2.LED_M = 1;
    }
    else if(TCU_Byte1.TrsmStGearLvr == TCU_GEAR_Invalid){        // 0xF Gear Invalid
        GearPosition = TCU_Position_F;
        flag.LED_P = 1;
        flag.LED_R = 1;
        flag.LED_N = 1;
        flag.LED_D = 1;
        Flag2.LED_M = 1;            
    }
} 

void APAMode(void)
{
    if(GearStatus == Nochange_Status){
        EST_Byte1.APA_InhbitCode = EST_APA_InhibitCode_NormalOperation;
        EST_Byte1.APA_Responce = EST_APA_Responce_Available;        
    }
    else{
        if(GearStatus == Failure_Status){
            EST_Byte1.APA_InhbitCode = EST_APA_InhibitCode_ESTFailure;                        
        }
        else{
            EST_Byte1.APA_InhbitCode = EST_APA_InhibitCode_DriverInterference;
        }
        EST_Byte1.APA_Responce = EST_APA_Responce_Inhibit;
    }
    
    if(EST_Byte1.APA_InhbitCode == EST_APA_InhibitCode_NormalOperation){
        if(APA_Byte0.EST_Request == APA_EST_REQUEST_NoRequest){        
           EST_Byte1.APA_Responce = EST_APA_Responce_Available;
        }
        else if(APA_Byte0.EST_Request == APA_EST_REQUEST_ControlESTRequest){        
           EST_Byte1.APA_Responce = EST_APA_Responce_ReplyForControl;
        }
        else if(APA_Byte0.EST_Request == APA_EST_REQUEST_ESTControl){
            EST_Byte1.APA_Responce = EST_APA_Responce_Active;
            EST_Byte0.TargetGear = APA_Byte6.TargetGear;
        }
    }
    else{
        EST_Byte1.APA_Responce = EST_APA_Responce_Inhibit;          
    }
}

void CAN_BUSRecovery(void)
{
    if (flag.SLEEP == 0 && COMSTATbits.TXBO == 1){          // error detected then disable bus
        flag.ERR = 1;
        flag.SLEEP = 1;
        TRISBbits.TRISB2 = 1;           
    //    PIR5bits.WAKIF = 0; // clear CAN bus wakeup interrupt
    //    PIE5bits.WAKIE = 0; // Enable CAN bus activity wakeup
        CANCON = 0x20; // request disable mode
   //     WDTCONbits.SWDTEN = 0;
        while ((CANSTAT & 0xE0) != 0x20); // wait until ECAN is in disable mode
        //Wake up from sleep should set the CAN module straight into Normal mode
   //     WDTCONbits.SWDTEN = 1;
    }
        
    if(TimeCount > 4 && ErrCount < 5){         // 50ms recovery, 5times  
        TimeCount = 0;
        CANCON = 0x00;
   //     WDTCONbits.SWDTEN = 0;
        while (0x00 != (CANSTAT & 0xE0)); // wait until ECAN is in Normal mode 
     //   WDTCONbits.SWDTEN = 1;
        TRISBbits.TRISB2 = 0;  
        flag.SLEEP = 0;            
        ErrCount++;
    }
    if(TimeCount > 19 && ErrCount == 5){        // 200ms
        CANCON = 0x00;
        TimeCount = 0;
    //    WDTCONbits.SWDTEN = 0;
        while (0x00 != (CANSTAT & 0xE0)); // wait until ECAN is in Normal mode 
    //    WDTCONbits.SWDTEN = 1;
        TRISBbits.TRISB2 = 0; 
        flag.SLEEP = 0;
        flag.ERR = 0;             
    }
}
/**
 End of File
*/