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
#include "ESTTargetGear.h"



/**
  Section: Global Variables Definitions
*/


/**
  Section: ESTGearDetector APIs
*/

void TargerGearDetector(void)
{    
    // Gear 0 Detetector
    // H3,H4,H6
    // H4,H6
    // H3,H6
    // H3,H4
    /* 20170829 C70 BYD
     * H1?H2: shift lock enable
     * H3?H4: shift lock disable
     * (H7 or H8) and H5: shift back
     * (H7 or H8) and H6: shift forward
     */
#if 0
   if ( ( H1_GetValue() == 0 || H2_GetValue() == 0 ) && ( H3_GetValue() == 1 || H4_GetValue() == 1 ) ) {
     shift_lock = 1;
   }
   else {
      //shift_lock = 0;
      if ( H3_GetValue() == 0 || H4_GetValue() == 0 ) {
        //shift_lock = 0;
          if ( ( H7_GetValue() == 0 || H8_GetValue() == 0 ) && H5_GetValue() == 0 ) {
            shift_lock = 0;
          }
          else
              if ( ( H7_GetValue() == 0 || H8_GetValue() == 0 ) && H6_GetValue() == 0 ) {
                  shift_lock = 0;
              }
      }
   }
#endif  //test hall sensor only   
    
#if 1
    if ( ( H1_GetValue() == 0 || H2_GetValue() == 0 ) && ( H3_GetValue() == 1 || H4_GetValue() == 1 ) ) {
      Flaggear.shift_lock = 1;
    }
	else
    if ( H3_GetValue() == 0 || H4_GetValue() == 0 ) {
        if ( ( H7_GetValue() == 0 || H8_GetValue() == 0 ) && H5_GetValue() == 0 ) {
			GearCount++;
			if ( GearCount > GearThreshold ) {
                if ( GearStatus == Release_Status ) {
                  GearStatus = GetNew_Status;
  				  Flaggear.Gear_0 = 0;
				  Flaggear.Gear_1 = 0;
				  Flaggear.Gear__1 = 1;
                }
                Flaggear.shift_lock = 0;
			}

			/*if(GearStatus != Finish_Status){
				OldGear = GearPosition;
				
				GearStatus = GetNew_Status;

				GearLatchCount = 0;
				GearCount = 0;

				Flaggear.Gear_0 = 0;            
				Flaggear.Gear_1 = 0; 
				Flaggear.Gear__1 = 1;				
				Flaggear.Gear_Fail = 0;
				Flaggear.shift_lock = 0;
			}*/
        }
        else
            if ( ( H7_GetValue() == 0 || H8_GetValue() == 0 ) && H6_GetValue() == 0 ) {
				GearCount++;
				if ( GearCount > GearThreshold ) {
                  if ( GearStatus == Release_Status ) {
                    GearStatus = GetNew_Status;
  				    Flaggear.Gear_0 = 0;
				    Flaggear.Gear_1 = 1;
				    Flaggear.Gear__1 = 0;
                  }
                  Flaggear.shift_lock = 0;
				}
                

				/*if(GearStatus != Finish_Status){
					OldGear = GearPosition;

					GearStatus = GetNew_Status;

					GearLatchCount = 0;
					GearCount = 0;

					Flaggear.Gear_0 = 0;            
					Flaggear.Gear_1 = 1; 
					Flaggear.Gear__1 = 0;				
					Flaggear.Gear_Fail = 0;
					Flaggear.shift_lock = 0;
				}*/
            }
			else {
				GearCount = 0;
				GearStatus = Release_Status;
			    Flaggear.Gear_0 = 1;
				Flaggear.Gear_1 = 0;
				Flaggear.Gear__1 = 0;
                //P_lamp_ctrl_SetLow();
				/*Flaggear.Gear_1 = 0; 
				Flaggear.Gear__1 = 0;				
				Flaggear.shift_lock = 1;
				GearCount = 0;*/
                Flaggear.shift_lock = 1;
			}
    }
#endif

#if 0    
    if(H1_GetValue() == 1 && H2_GetValue() == 1 && H3_GetValue() == 0 && H4_GetValue() == 0 && H5_GetValue() == 1 && H6_GetValue() == 0){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear_0 == 1){                
                GearStatus = Nochange_Status;                
            } 
            else{
                OldGear = GearPosition;
                Flaggear.Gear_0 = 1; 
                GearStatus = Release_Status;
                GearLatchCount = 0;                
            }
            Flaggear.Gear_1 = 0;
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0; 
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else if(H1_GetValue() == 1 && H2_GetValue() == 1 && H3_GetValue() == 1 && H4_GetValue() == 0 && H5_GetValue() == 1 && H6_GetValue() == 0){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear_0 == 1){                
                GearStatus = Nochange_Status;                
            } 
            else{
                OldGear = GearPosition;
                Flaggear.Gear_0 = 1; 
                GearStatus = Release_Status;
                GearLatchCount = 0;                
            }            
            Flaggear.Gear_1 = 0;
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0; 
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else if(H1_GetValue() == 1 && H2_GetValue() == 1 && H3_GetValue() == 0 && H4_GetValue() == 1 && H5_GetValue() == 1 && H6_GetValue() == 0){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear_0 == 1){                
                GearStatus = Nochange_Status;                
            } 
            else{
                OldGear = GearPosition;
                Flaggear.Gear_0 = 1; 
                GearStatus = Release_Status;
                GearLatchCount = 0;                
            }            
            Flaggear.Gear_1 = 0;
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0; 
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else if(H1_GetValue() == 1 && H2_GetValue() == 1 && H3_GetValue() == 0 && H4_GetValue() == 0 && H5_GetValue() == 1 && H6_GetValue() == 1){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear_0 == 1){                
                GearStatus = Nochange_Status;                 
            } 
            else{
                OldGear = GearPosition;
                Flaggear.Gear_0 = 1; 
                GearStatus = Release_Status;
                GearLatchCount = 0;                
            }                 
            Flaggear.Gear_1 = 0;
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0; 
            GearCount = 0;
        }
        GearFailCount = 0;
    }

    // Gear 1 Detector
    // H1,H3        
     else if(H1_GetValue() == 0 && H2_GetValue() == 1 && H3_GetValue() == 0 && H4_GetValue() == 1 && H5_GetValue() == 1 && H6_GetValue() == 1){         
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear_1 == 1){ 
                GearLatchCount++;
           //     GearStatus = Latch_Status; 
            } 
        }
        if(GearStatus != Finish_Status){
            OldGear = GearPosition;
            Flaggear.Gear_1 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0;
            GearCount = 0;
            Flaggear.Gear_0 = 0;            
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0;            
       }        
       GearFailCount = 0;
    }

    // Gear 2 Detector
    // H1,H6
    // H1,H5
    // H5,H6
    // H1,H5,H6
    else if(H1_GetValue() == 0 && H2_GetValue() == 1 && H3_GetValue() == 1 && H4_GetValue() == 1 && H5_GetValue() == 0 && H6_GetValue() == 0){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear_2 == 1){ 
                GearLatchCount++;
             //   GearStatus = Latch_Status;                
            } 
        }
        if(GearStatus != Finish_Status || Flaggear.Gear_1 == 1){
            Flaggear.Gear_2 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0; 
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;            
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0;             
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else if(H1_GetValue() == 0 && H2_GetValue() == 1 && H3_GetValue() == 1 && H4_GetValue() == 1 && H5_GetValue() == 0 && H6_GetValue() == 1){
       GearCount++;
       if(GearCount > GearThreshold){
            if(Flaggear.Gear_2 == 1){ 
                GearLatchCount++;
             //   GearStatus = Latch_Status;                
            } 
        }
        if(GearStatus != Finish_Status  || Flaggear.Gear_1 == 1){
            Flaggear.Gear_2 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0; 
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;            
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0;             
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else if(H1_GetValue() == 1 && H2_GetValue() == 1 && H3_GetValue() == 1 && H4_GetValue() == 1 && H5_GetValue() == 0 && H6_GetValue() == 0){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear_2 == 1){ 
                GearLatchCount++;
             //   GearStatus = Latch_Status;                
            } 
        }
        if(GearStatus != Finish_Status || Flaggear.Gear_1 == 1){
            Flaggear.Gear_2 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0; 
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;            
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0;             
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else if(H1_GetValue() == 0 && H2_GetValue() == 1 && H3_GetValue() == 1 && H4_GetValue() == 1 && H5_GetValue() == 1 && H6_GetValue() == 0){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear_2 == 1){ 
                GearLatchCount++;
             //   GearStatus = Latch_Status;                
            } 
        }
        if(GearStatus != Finish_Status  || Flaggear.Gear_1 == 1){
            Flaggear.Gear_2 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0; 
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;            
            Flaggear.Gear__1 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0;             
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    
    // Gear -1 Detector
    // H2,H6    
    else if(H1_GetValue() == 1 && H2_GetValue() == 0 && H3_GetValue() == 1 && H4_GetValue() == 1 && H5_GetValue() == 1 && H6_GetValue() == 0){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear__1 == 1){ 
                GearLatchCount++;
            //    GearStatus = Latch_Status;                
            } 
        }
        if(GearStatus != Finish_Status){
            OldGear = GearPosition;
            Flaggear.Gear__1 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0;  
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;            
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__2 = 0;
            Flaggear.Gear_Fail = 0;             
            GearCount = 0;
        }   
        GearFailCount = 0;
    }
    
    // Gear -2 Detector
    // H1,H2,H4
    // H1,H2
    // H1,H4
    // H2,H4
    else if(H1_GetValue() == 0 && H2_GetValue() == 0 && H3_GetValue() == 1 && H4_GetValue() == 0 && H5_GetValue() == 1 && H6_GetValue() == 1){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear__2 == 1){ 
                GearLatchCount++;
          //      GearStatus = Latch_Status;                  
            } 
        }
        if(GearStatus != Finish_Status || Flaggear.Gear__1 == 1){
            Flaggear.Gear__2 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0; 
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;            
            Flaggear.Gear_Fail = 0; 
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else if(H1_GetValue() == 0 && H2_GetValue() == 0 && H3_GetValue() == 1 && H4_GetValue() == 1 && H5_GetValue() == 1 && H6_GetValue() == 1){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear__2 == 1){ 
                GearLatchCount++;
           //     GearStatus = Latch_Status;                
            } 
        }
        if(GearStatus != Finish_Status || Flaggear.Gear__1 == 1){
            Flaggear.Gear__2 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0; 
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;            
            Flaggear.Gear_Fail = 0; 
            GearCount = 0;
        }
        GearFailCount = 0;
    } 
    else if(H1_GetValue() == 1 && H2_GetValue() == 0 && H3_GetValue() == 1 && H4_GetValue() == 0 && H5_GetValue() == 1 && H6_GetValue() == 1){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear__2 == 1){ 
                GearLatchCount++;
           //     GearStatus = Latch_Status;                
            } 
        }
        if(GearStatus != Finish_Status || Flaggear.Gear__1 == 1){
            Flaggear.Gear__2 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0; 
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;            
            Flaggear.Gear_Fail = 0; 
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else if(H1_GetValue() == 0 && H2_GetValue() == 1 && H3_GetValue() == 1 && H4_GetValue() == 0 && H5_GetValue() == 1 && H6_GetValue() == 1){
        GearCount++;
        if(GearCount > GearThreshold){
            if(Flaggear.Gear__2 == 1){ 
                GearLatchCount++;
           //     GearStatus = Latch_Status;                  
            }
        }
        if(GearStatus != Finish_Status || Flaggear.Gear__1 == 1){
            Flaggear.Gear__2 = 1; 
            GearStatus = GetNew_Status;
            GearLatchCount = 0; 
            Flaggear.Gear_0 = 0;
            Flaggear.Gear_1 = 0;
            Flaggear.Gear_2 = 0;
            Flaggear.Gear__1 = 0;            
            Flaggear.Gear_Fail = 0; 
            GearCount = 0;
        }
        GearFailCount = 0;
    }
    else{
        GearFailCount++;
        if(GearFailCount > TIME_60S){
            Flaggear.Gear_Fail = 1;  
            EST_Byte0.TargetGear = EST_GEAR_Invalid;
            EST_Byte0.Fault = EST_GEAR_Fail;
        }        
    }
    
    
 //   if(GearStatus == Latch_Status){
        if(GearLatchCount > GearLatchThreshold){ 
            Flaggear.GearLatch = 1;
            Flaggear.Gear_Fail = 1;  
        }
        else
            Flaggear.GearLatch = 0;
  //  }
#endif    
}

void TargetGearJudge(void)
{
	if(GearStatus == GetNew_Status){ 
		GearStatus = Finish_Status;
		switch(GearPosition){
		case TCU_Position_P:
			if( Flaggear.shift_lock == 0){
				if( Flaggear.Gear_1 ){ 
					EST_Byte0.TargetGear = EST_GEAR_N;
					EST_Byte0.Fault = EST_GEAR_Normal;
				}
				else
					if( Flaggear.Gear__1 ){ 
						EST_Byte0.TargetGear = EST_GEAR_N;
						EST_Byte0.Fault = EST_GEAR_Normal;
					}
			}				
			break;

		case TCU_Position_R:
			if( Flaggear.shift_lock == 0){
				if( Flaggear.Gear_1 ){ 
					EST_Byte0.TargetGear = EST_GEAR_N;
					EST_Byte0.Fault = EST_GEAR_Normal;
				}
				else
					if( Flaggear.Gear__1 ){ 
						EST_Byte0.TargetGear = EST_GEAR_D;
						EST_Byte0.Fault = EST_GEAR_Normal;
					}
			}				
			break;

		case TCU_Position_N:
			if( Flaggear.shift_lock == 0){
				if( Flaggear.Gear_1 ){ 
					EST_Byte0.TargetGear = EST_GEAR_R;
					EST_Byte0.Fault = EST_GEAR_Normal;
				}
				else
					if( Flaggear.Gear__1 ){ 
						EST_Byte0.TargetGear = EST_GEAR_D;
						EST_Byte0.Fault = EST_GEAR_Normal;
					}
			}				
			break;

		case TCU_Position_D:
			if( Flaggear.shift_lock == 0){
				if( Flaggear.Gear_1 ){ 
					EST_Byte0.TargetGear = EST_GEAR_R;
					EST_Byte0.Fault = EST_GEAR_Normal;
				}
				else
					if( Flaggear.Gear__1 ){ 
						EST_Byte0.TargetGear = EST_GEAR_N;
						EST_Byte0.Fault = EST_GEAR_Normal;
					}
			}				
			break;
		}
    }
        
#if 0    
    if(Flaggear.Gear_2 == 1 && GearStatus == GetNew_Status){
        NewGear = GearPosition;
        if(OldGear != NewGear){
            GearPosition = OldGear;         
        }            
    }
    if(GearStatus == GetNew_Status){ 
        GearStatus = Finish_Status;
        switch(GearPosition){
            case TCU_Position_P:
                if(Flaggear.Gear_2){
                    if(Shift_Lock_GetValue() == 0){
                        EST_Byte0.TargetGear = EST_GEAR_D;
                        EST_Byte0.Fault = EST_GEAR_Normal;  
                    }
                }
                else if(Flaggear.Gear_1){ 
                    if(Shift_Lock_GetValue() == 0){
                        EST_Byte0.TargetGear = EST_GEAR_N;
                        EST_Byte0.Fault = EST_GEAR_Normal;
                    }
                }
                else if(Flaggear.Gear__2){ 
                    if(Shift_Lock_GetValue() == 0){
                        EST_Byte0.TargetGear = EST_GEAR_R;
                        EST_Byte0.Fault = EST_GEAR_Normal;
                    }                    
                }
                else if(Flaggear.Gear__1){
                    if(Shift_Lock_GetValue() == 0){
                        EST_Byte0.TargetGear = EST_GEAR_N; 
                        EST_Byte0.Fault = EST_GEAR_Normal;
                    }
                }
                else if(Flaggear.Gear_Fail){
                    EST_Byte0.TargetGear = EST_GEAR_Invalid;
                    EST_Byte0.Fault = EST_GEAR_Fail;
                }
                break;
            case TCU_Position_R:                
                if(Flaggear.Gear_2){                    
                    EST_Byte0.TargetGear = EST_GEAR_D;
                    EST_Byte0.Fault = EST_GEAR_Normal;                           
                }
                else if(Flaggear.Gear_1){
                    EST_Byte0.TargetGear = EST_GEAR_N;
                    EST_Byte0.Fault = EST_GEAR_Normal;
                }
                else if(Flaggear.Gear__2){                                            
                    EST_Byte0.TargetGear = EST_GEAR_R;
                    EST_Byte0.Fault = EST_GEAR_Normal;                    
                } 
                else if(Flaggear.Gear__1){                                            
                    EST_Byte0.TargetGear = EST_GEAR_R;
                    EST_Byte0.Fault = EST_GEAR_Normal;                    
                } 
                else if(Flaggear.Gear_Fail){
                    EST_Byte0.TargetGear = EST_GEAR_Invalid;
                    EST_Byte0.Fault = EST_GEAR_Fail;
                }
                break;
            case TCU_Position_N:
                if(Flaggear.Gear_2){
                    EST_Byte0.TargetGear = EST_GEAR_D;
                    EST_Byte0.Fault = EST_GEAR_Normal;                             
                } 
                else if(Flaggear.Gear_1){
                    EST_Byte0.TargetGear = EST_GEAR_D;
                    EST_Byte0.Fault = EST_GEAR_Normal;                             
                } 
                else if(Flaggear.Gear__2){
                    if(Shift_Lock_GetValue() == 0){
                        EST_Byte0.TargetGear = EST_GEAR_R; 
                        EST_Byte0.Fault = EST_GEAR_Normal;
                    }
                }
                else if(Flaggear.Gear__1){
                    if(Shift_Lock_GetValue() == 0){
                        EST_Byte0.TargetGear = EST_GEAR_R; 
                        EST_Byte0.Fault = EST_GEAR_Normal;
                    }
                }
                else if(Flaggear.Gear_Fail){
                    EST_Byte0.TargetGear = EST_GEAR_Invalid;
                    EST_Byte0.Fault = EST_GEAR_Fail;
                }
                break;
            case TCU_Position_D:
                if(Flaggear.Gear_2){
                    EST_Byte0.TargetGear = EST_GEAR_M;
                    EST_Byte0.Fault = EST_GEAR_Normal;                             
                }
                else if(Flaggear.Gear_1){
                    EST_Byte0.TargetGear = EST_GEAR_M;
                    EST_Byte0.Fault = EST_GEAR_Normal;                             
                }
                else if(Flaggear.Gear__2){
                    if(Shift_Lock_GetValue() == 0){
                        EST_Byte0.TargetGear = EST_GEAR_R; 
                        EST_Byte0.Fault = EST_GEAR_Normal;
                    }
                }
                else if(Flaggear.Gear__1){                    
                    EST_Byte0.TargetGear = EST_GEAR_N;
                    EST_Byte0.Fault = EST_GEAR_Normal;                    
                }
                else if(Flaggear.Gear_Fail){
                    EST_Byte0.TargetGear = EST_GEAR_Invalid;
                    EST_Byte0.Fault = EST_GEAR_Fail;
                }
                break;
            case TCU_Position_M:
                if(Flaggear.Gear_2){
                    EST_Byte0.TargetGear = EST_GEAR_D;
                    EST_Byte0.Fault = EST_GEAR_Normal;                             
                }
                else if(Flaggear.Gear_1){
                    EST_Byte0.TargetGear = EST_GEAR_D;
                    EST_Byte0.Fault = EST_GEAR_Normal;                             
                }
                else if(Flaggear.Gear__2){
                    if(Shift_Lock_GetValue() == 0){
                        EST_Byte0.TargetGear = EST_GEAR_R; 
                        EST_Byte0.Fault = EST_GEAR_Normal;
                    }
                }
                else if(Flaggear.Gear__1){
                    EST_Byte0.TargetGear = EST_GEAR_N;
                    EST_Byte0.Fault = EST_GEAR_Normal;                    
                }
                else if(Flaggear.Gear_Fail){
                    EST_Byte0.TargetGear = EST_GEAR_Invalid;
                    EST_Byte0.Fault = EST_GEAR_Fail;
                }
                break;
            case TCU_Position_F:
                break;
            default:
                break;
            
        }
    }    
#endif
}




/**
  End of File
*/
