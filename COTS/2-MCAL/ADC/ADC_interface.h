/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 19/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : ADC                   *****************/ 
/********************************************************************/

#ifndef   ADC_INTERFACE_H
#define   ADC_INTERFACE_H


#define       ADC_U8_CHANNEL_0      0
#define       ADC_U8_CHANNEL_1      1
#define       ADC_U8_CHANNEL_2      2
#define       ADC_U8_CHANNEL_3      3
#define       ADC_U8_CHANNEL_4      4
#define       ADC_U8_CHANNEL_5      5
#define       ADC_U8_CHANNEL_6      6
#define       ADC_U8_CHANNEL_7      7
#define       ADC_U8_CHANNEL_8      8
#define       ADC_U8_CHANNEL_9      9
#define       ADC_U8_CHANNEL_10     10
#define       ADC_U8_CHANNEL_11     11
#define       ADC_U8_CHANNEL_12     12
#define       ADC_U8_CHANNEL_13     13
#define       ADC_U8_CHANNEL_14     14
#define       ADC_U8_CHANNEL_15     15
#define       ADC_U8_CHANNEL_16     16
#define       ADC_U8_CHANNEL_17     17
#define       ADC_U8_CHANNEL_18     18
#define       ADC_U8_CHANNEL_19     19
#define       ADC_U8_CHANNEL_20     20
#define       ADC_U8_CHANNEL_21     21
#define       ADC_U8_CHANNEL_22     22
#define       ADC_U8_CHANNEL_23     23
#define       ADC_U8_CHANNEL_24     24
#define       ADC_U8_CHANNEL_25     25
#define       ADC_U8_CHANNEL_26     26
#define       ADC_U8_CHANNEL_27     27
#define       ADC_U8_CHANNEL_28     28
#define       ADC_U8_CHANNEL_29     29
#define       ADC_U8_CHANNEL_30     30
#define       ADC_U8_CHANNEL_31     31
 
#define       ADC_U8_PRESCALER_2    1
#define       ADC_U8_PRESCALER_4    2 
#define       ADC_U8_PRESCALER_8    3 
#define       ADC_U8_PRESCALER_16   4 
#define       ADC_U8_PRESCALER_32   5
#define       ADC_U8_PRESCALER_64   6
#define       ADC_U8_PRESCALER_128  7

#define  ADC_U8_LEFT_ADJ      1 
#define  ADC_U8_RIGHT_ADJ     0

#define       ADC_U8_FREE_RUNNING_MODE  0
#define       ADC_U8_ANALOG_COMPARATOR  1

#define ADC_U8_EXTERNAL_AREF                       0
#define ADC_U8_EXTERNAL_AVCC                       1
#define ADC_U8_INTERNAL_2.5_VOLTAGE_REF            3 
void ADC_voidinit(void);
u8 ADC_u8getdigitalvaluesynchronous(u8 copy_u8channelnum,u16 *copy_pu16digitalvalue);

u8 ADC_u8getdigitalvalueAsynvhronous(u8 copy_u8channelnum,void(*copy_pfnotification)(u16));


#endif
