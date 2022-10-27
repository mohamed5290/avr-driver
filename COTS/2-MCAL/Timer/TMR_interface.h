/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 21/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : Timer                 *****************/ 
/********************************************************************/

#ifndef TMR_INTERFACE_H
#definw TMR_INTERFACE_H

#define    TMR_NORMAL    0
#define    TMR_PWM       1
#define    TMR_CTC       2
#define    TMR_FAST_PWM  3


                                                  
#define   TMR_U8_NO_CLK_SOURCE                    0
#define   TMR_U8_CLK_NO_PRESCALLING               1
#define   TMR_U8_CLK_DIV_8_PRS                    2
#define   TMR_U8_CLK_DIV_64_PRS                   3
#define   TMR_U8_CLK_DIV_256_PRS                  4
#define   TMR_U8_CLK_DIV_1024_PRS	              5
#define   TMR_U8_EXT_CLK_SOURCE_FALLING_EDGE      6
#define   TMR_U8_EXT_CLK_SOURCE_RISING_EDGE       7
 
  

void TMR_voidtimer0init(void);

u8 TMR_u8tmr0overflowsetcallback(void(*copy_pfcallback(void)));
u8 TMR_u8tmr0_CTCsetcallback(void(*copy_pfcallback(void)));


#endif












