 /* ------------------------------------------------------------------- */
 /** @file main.c
  * @brief main file
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: main.c,v 1.2 2013/09/13 09:32:07 rpy Exp $
  *
  * @verbatim
  * -------------------------------------------------------------------
  * Date     B/F Who Comment
  * ------------------------------------------------------------------- 
  * 13/09/03 (F) RPY initial version
  * -------------------------------------------------------------------
  * @endverbatim
  * 
  *
  * @creator      RPY
  * @created      2013/06/15
  * 
  * @project      521.31
  * @requested    -
  * @inspector    - 
  * @verification -
  * @version      $Revision: 1.2 $
  * 
  * 
  * $State: Exp $   
  * $Author: rpy $
  * $Date: 2013/09/13 09:32:07 $

  * $Locker:  $
  * $Url:   $
  *
  * Additional markers:
  *
  *
  *
  */

#include "api.h"
#include "mod_sys.h"
#include "mod_sci.h"
#include "mod_gpio.h"
#include "mod_hvctrl.h"
#include "mod_adc.h"
#include "mod_pwm.h"
#include "mod_swt.h"
#include "version.h"

#include <stdio.h>
#include <stdlib.h>



//################################################################################
// main

#define MAIN_ENABLE_TERMINAL_OUTPUT

#define MAIN_SCREEN_UPDATE_INTERVAL   1000 // ms Refresh rate for terminal display
#define MAIN_SCREEN_REFRESH_TIMER     0 // count-down timer number for screen refresh timer 

#define MAIN_PWM_INCR_STEP            (PWM_PERIOD/250) // increment per step 
#define MAIN_PWM_INCR_PEROD           (PWM_PERIOD/2)  // limit max PWM (since in upper 1/2 no visible change).
#define MAIN_PWM_INCR_INTERVAL        100   // ms PWM incremet stepping
#define MAIN_PWM_INCR_TIMER           1     // timer number for auto-increment of PWM signals
// -------------------------------------------------------------------------------

typedef enum
{
  PWMMOD_MANUAL,
  PWMMOD_INCR,
  PWMMOD_DECR,
  PWMMOD_TOGGLE,
  
} main_PWMModeType;

// -------------------------------------------------------------------------------

bool main_InputMode;

main_PWMModeType main_PWMMode[PWM_CHANNELS];
bool main_PWMToggleDir[PWM_CHANNELS];

pwm_CounterType main_PWMPhases[PWM_CHANNELS];
bool main_UpdatePWMPhases;


// -------------------------------------------------------------------------------

// Initialize all HW components. 
bool main_Init()
{  
  return  (sys_Init()                             &&
           stdio_Init((sci_baud)(STDIO_SCI_BAUD)) &&   
           swt_Init()                             && // should be initilized quite early, since i.e. cctimer uses this module
           gpio_Init()                            && 
//           cctimer_Init()                         &&
           hvctrl_Init()                          && // take care to initialize hv_ctrl before adc, otherwise cyclic sampling starts, and disabling watch dog may fail.
           adc_Init()                             &&
           pwm_Init()
                                                  )? true:false;
}

// A terminal gotoxy method. 
void main_GotoXY(uint16_t x,uint16_t y)
{
  printf("\033\133%i\073%i\110",y,x);
}

void main_PrintPWMLine(pwm_ch_t plug,uint8_t lnum)
   main_GotoXY(13,6+lnum);    
{
   
   printf("%5u  %5u  ",pwm_GetOnPhase(plug),pwm_GetStartTick(plug));
   
   if (pwm_GetOnSampleTick(plug)!=PWM_NO_SAMPE) printf("%5u  ",pwm_GetOnSampleTick(plug));
   else printf("-----  ");

   if (pwm_GetOffSampleTick(plug)!=PWM_NO_SAMPE) printf("%5u   ",pwm_GetOffSampleTick(plug));
   else printf("-----   ");

   switch(main_PWMMode[lnum])
   {
     case PWMMOD_MANUAL:  printf("Manual "); break;
     case PWMMOD_INCR:    printf("Incr   "); break;
     case PWMMOD_DECR:    printf("Decr   "); break;
     case PWMMOD_TOGGLE:  printf("Toggle "); break;
   };
}

void main_PrintADCLine(uint8_t ch,uint8_t lnum)
{
  main_GotoXY(13,15+lnum);    
  
  uint16_t val;
  
  val=adc_GetCurrentValue(ch);    
  if (val!=ADC_INVALID_VALUE) printf("%4u  ",val);
  else printf("----  ");
  
  for (uint8_t p=0;p<ADC_PWM_CHANNELS;++p)
  {
      
    uint16_t val_on;
    uint16_t val_off;
  
    val_on=adc_GetOnPhaseValue(p,ch);
    val_off=adc_GetOffPhaseValue(p,ch);
    
    if (val_on!=ADC_INVALID_VALUE) printf("%4u ",val_on);
    else printf("---- ");
 
    if (val_off!=ADC_INVALID_VALUE) printf("%4u  ",val_off);
    else printf("----  ");    
  } 
}

// Clears screen, and prints header line
void main_NewScreen()
{
  main_GotoXY(1,1);
    
  printf("\033\133\062\112\n\r        *** 521.31 LED Demo ***   "MAIN_VERSION_STRING"\n\n\r");
}

// Initializes text mode demo screen
void main_SetupScreen()
{
  main_NewScreen();
     
  printf("+- PWM Values ------------------( Period: %5u )-+ \n\r",(uint16_t)PWM_PERIOD);
  printf("! Channel   Dur    Start  On-T   Off-T   Mode     !\n\r");
  printf("! PWM1:     00000  00000  00000  00000   Incr     !\n\r");
  printf("! PWM2:     00000  00000  00000  00000   Incr     !\n\r");
  printf("! PWM3:     00000  00000  00000  00000   Incr     !\n\r");
  printf("! PWM4:     00000  00000  00000  00000            !\n\r");
  printf("+-------------------------------------------------+\n\r");
  printf("\n\r");  
  printf("+- ADC Values ------------------------------------------------+\n\r");  
  printf("! Channel   Cur     Ch1        Ch2        Ch3        Ch4      !\n\r");
  printf("!                 On   Off   On   Off   On   Off   On   Off   !\n\r");
  printf("! None:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! VDIFF:    0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! OUT1:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! OUT2:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! OUT3:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! OUT4:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! AIN1:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! AIN2:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! AIN3:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! AIN4:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! VTEMP:    0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! VDD3:     0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! VDD5VDA:  0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! VS:       0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! VDD3I_VH: 0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("! VBG:      0000  0000 0000  0000 0000  0000 0000  0000 0000  !\n\r");
  printf("+-------------------------------------------------------------+\n\r"); 
  printf("\n\r");  
  printf(" Press Ctrl-A for input. ( + 'h' for Help )\n\r");  
}

// Initializes text mode demo screen
void main_ShowHelpScreen()
{
  main_NewScreen();
  
  printf("Info: %s\n\r",MAIN_VERSION_STRING_LONG);
  printf("\n\r");
  printf("+- Help / Keys --------------------------------------+\n\r");
  printf("!                                                    !\n\r");
  printf("! SPC     - Repaint screen                           !\n\r");
  printf("!                                                    !\n\r");
  printf("! 1 2 3 4 - Enter PWM Value + Switch to manual mode  !\n\r");
  printf("! q w e r - Change PWM channel mode                  !\n\r");
  printf("! o       - Switch PWM channel drivers OFF           !\n\r");
  printf("! i       - Change PWM channel drivers ON            !\n\r"); 
  printf("!                                                    !\n\r");
  printf("! h       - Show this help                           !\n\r"); 
  printf("!                                                    !\n\r");
  printf("+----------------------------------------------------+\n\r");
  
  printf("\n\r");
  printf("Press ESC to return to the status screen.\n\r");

  main_GotoXY(1,1);  
}

void main_UpdateScreen()
{
  // update PWM values
  main_PrintPWMLine(PWM_GP1,0);
  main_PrintPWMLine(PWM_GP2,1);
  main_PrintPWMLine(PWM_GP3,2);
  main_PrintPWMLine(PWM_GP4,3);
   
  // update ADC values
  
  main_PrintADCLine(ADC_CH_NONE,0);
  main_PrintADCLine(ADC_CH_VDIFF,1);
  main_PrintADCLine(ADC_CH_OUT1,2);
  main_PrintADCLine(ADC_CH_OUT2,3);
  main_PrintADCLine(ADC_CH_OUT3,4);
  main_PrintADCLine(ADC_CH_OUT4,5);
  main_PrintADCLine(ADC_CH_AIN1,6);
  main_PrintADCLine(ADC_CH_AIN2,7);
  main_PrintADCLine(ADC_CH_AIN3,8);
  main_PrintADCLine(ADC_CH_AIN4,9);
  main_PrintADCLine(ADC_CH_VTEMP,10);
  main_PrintADCLine(ADC_CH_VDD3,11);
  main_PrintADCLine(ADC_CH_VDD5VDDA,12);
  main_PrintADCLine(ADC_CH_VS,13);
  main_PrintADCLine(ADC_CH_VDD3I_HV,14);
  main_PrintADCLine(ADC_CH_VBG,15);
   
  main_GotoXY(1,1); 
}

// ask user to enter new PWM on-phase value
void main_EnterPWMValue(uint8_t lnum)
{
  main_GotoXY(13,6+lnum); 
  printf("     ");
  main_GotoXY(13,6+lnum); 

  char entry_buffer[6] = { 0 }; 
  
  for (unsigned int i=0;i<10000;++i)
    while (stdio_GetCharNonBlk()!=-1) { i=0; };
  
  stdio_GetLine(entry_buffer,sizeof(entry_buffer),false);
   
  if (strlen(entry_buffer)>0)
  {
    unsigned int val=atoi(entry_buffer);
   
    if (val>PWM_PERIOD) val=PWM_PERIOD;
   
    main_PWMPhases[lnum]=val;
    main_PWMMode[lnum]=PWMMOD_MANUAL;
    main_UpdatePWMPhases=true;
  }
}
// iterate over available PWM handling modes
void main_NextPWMMode(uint8_t ch)
{
  if (ch<PWM_CHANNELS)
  {
    switch(main_PWMMode[ch])
    {
      case PWMMOD_MANUAL: main_PWMMode[ch]=PWMMOD_INCR; break;
      case PWMMOD_INCR:  main_PWMMode[ch]=PWMMOD_DECR; break;
      case PWMMOD_DECR:  main_PWMMode[ch]=PWMMOD_TOGGLE; break;
      case PWMMOD_TOGGLE:  main_PWMMode[ch]=PWMMOD_MANUAL; break;
    }
  }
}

// Set initial variable values
void main_SetDefaults()
{  
  for(uint8_t i=0;i<PWM_CHANNELS;++i)
  {
    main_PWMMode[i]=PWMMOD_TOGGLE;
    if (i<3) main_PWMPhases[i]=i*(MAIN_PWM_INCR_PEROD/3);
    else main_PWMPhases[i]=0;
    
    main_PWMToggleDir[i]=true;
  }
  
  main_UpdatePWMPhases=true;  
  main_InputMode=false;
}

// initialie terminal screen
void main_TerminalSetup()
{
  main_SetupScreen();
  main_UpdateScreen();  
  
  swt_SetCountDownTimer(MAIN_SCREEN_REFRESH_TIMER,MAIN_SCREEN_UPDATE_INTERVAL);
}

void main_TerminalHandler()
{
  if (main_InputMode==true)
  {
    
    int key=stdio_GetChar();
    if (key!=-1) 
    {    
      switch(key)
      {
        case 32:  // SPC (update screen)
        {
          main_SetupScreen();
          main_UpdateScreen();
          break;
        }
    
        case 'h': // (print help)
        {
          main_ShowHelpScreen();
          while (stdio_GetCharNonBlk()!=-1) ;
          while(stdio_GetChar()!=27); 
          main_SetupScreen();
          main_UpdateScreen();   
          break;
        }
    
        // manualy enter PWM phase value
        case '1': main_EnterPWMValue(0); break;
        case '2': main_EnterPWMValue(1); break;
        case '3': main_EnterPWMValue(2); break;
        case '4': main_EnterPWMValue(3); break;
  
        // switch GPx on        
        case 'i': hvctrl_SetLEDDrv(true,true,false); break;

        // switch GPx off
        case 'o':  hvctrl_SetLEDDrv(false,true,false); break;
  
        // iterate PWM modes
        case 'q': main_NextPWMMode(0); break;
        case 'w': main_NextPWMMode(1); break;
        case 'e': main_NextPWMMode(2); break;
        case 'r': main_NextPWMMode(3); break;
    
        case 27: // ESC ( return to update mode)
        {
          main_InputMode=false;
        } 
      }
    }
    main_InputMode=false;      
  }
  else
  {
    int key=stdio_GetCharNonBlk();
  
    if (key!=-1)
    {
      if (key==1) 
      {
        main_InputMode=true;
        while (stdio_GetCharNonBlk()!=-1) ;
      }
    }        
  }
    
  if (swt_IsCountDownTimerZero(MAIN_SCREEN_REFRESH_TIMER))
  {
    if (!main_InputMode) main_UpdateScreen();
    swt_SetCountDownTimer(MAIN_SCREEN_REFRESH_TIMER,MAIN_SCREEN_UPDATE_INTERVAL);    
  }
}


int main(void)
{
  // Initialization
  
  if (!main_Init()) 
  {
    dint();

    // TODO: eventually add some blinking LED code here, to indicate 
    // initialization failure to the user.    
    while(1); 
  }

  sei();
  eint();  
   
  main_SetDefaults();

#ifdef MAIN_ENABLE_TERMINAL_OUTPUT
  main_TerminalSetup();
#endif  
  
  swt_SetCountDownTimer(MAIN_PWM_INCR_TIMER,MAIN_PWM_INCR_INTERVAL);
          
  while(1)
  {
    
#ifdef MAIN_ENABLE_TERMINAL_OUTPUT    
    main_TerminalHandler();
#endif    
    
    // takeover values computet/enterd in main to the actual hardware
    if (main_UpdatePWMPhases)
    {
      pwm_SetAllOnPhases(main_PWMPhases[0],main_PWMPhases[1],main_PWMPhases[2],main_PWMPhases[3]);
      main_UpdatePWMPhases=false;
    }
        
    // update auto-increment phases
    if (swt_IsCountDownTimerZero(MAIN_PWM_INCR_TIMER))
    {
      for (uint8_t p=0;p<PWM_CHANNELS;++p)
      {
        unsigned short step=(MAIN_PWM_INCR_STEP*(p+1));
        switch(main_PWMMode[p])
        {
          case PWMMOD_INCR:
          {
            main_PWMPhases[p]+=step;
            if (main_PWMPhases[p]>MAIN_PWM_INCR_PEROD) main_PWMPhases[p]-=MAIN_PWM_INCR_PEROD; 
            main_UpdatePWMPhases=true;     
            break;
          }          
          case PWMMOD_DECR:
          {
            if (main_PWMPhases[p]<step) main_PWMPhases[p]+=MAIN_PWM_INCR_PEROD;
            main_PWMPhases[p]-=step;
            
            main_UpdatePWMPhases=true;     
            break;
          }          
          case PWMMOD_TOGGLE:
          {
            if  (main_PWMToggleDir[p]) 
            {
              if (main_PWMPhases[p]>MAIN_PWM_INCR_PEROD) 
              {
                main_PWMPhases[p]=MAIN_PWM_INCR_PEROD; 
                main_PWMToggleDir[p]=main_PWMToggleDir[p]?false:true;
              }
              else main_PWMPhases[p]+=step;
            }          
            else
            {
              if (main_PWMPhases[p]<step) 
              {
                main_PWMPhases[p]=0;
                main_PWMToggleDir[p]=main_PWMToggleDir[p]?false:true;
              }
              else main_PWMPhases[p]-=step;              
            }                                       
            
            main_UpdatePWMPhases=true;     
            break;
          }          
        }
      }
      
      swt_SetCountDownTimer(MAIN_PWM_INCR_TIMER,MAIN_PWM_INCR_INTERVAL);
    }         
  }
  
  // return 0;  // unreachable
}


