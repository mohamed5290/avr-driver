/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 11/1/2021              *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : LED                   *****************/    
/********************************************************************/

#ifndef  LED_INTERFACE_H
#define  LED_INTERFACE_H
typedef struct
{
	 u8 PortId;
	 u8 PinID;
	 u8 Conn_Type; 
} LED_T ;

u8 LED_u8ON  (LED_T LED);
u8 LED_u8OFF (LED_T LED);
u8 LED_u8TOG (LED_T LED);


#endif