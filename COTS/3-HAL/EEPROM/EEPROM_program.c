/*
 *  Author   : Samar Sobhy
 *  Date     : January 28, 2021
 *  Version  : 1.0 v
 *  SWC      : EEPROM
 */
#define F_CPU 8000000UL
#include <util/delay.h>
// LIB Layer
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// MCAL
#include "TWI_interface.h"
// HAL
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

void EEPROM_voidInit (void)
{
	TWI_voidMasterInit();
}
u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress,u8 Copy_u8Data)//11bit
{
	u8 			 	Local_u8ErrorState = STD_TYPES_NOK ;
	TWIError_t 		Local_EnuTWIErrorState = TWI_OK ;
	u8 			 	Local_u8SlaveAdd =(EEEPROM_u8_FIXED_ADD|(Copy_u16ByteAddress>>8));//(((address & 0x700)>>7)|0xA0)
	// Send Start Condition
	Local_EnuTWIErrorState = TWI_EnuSendREStartCondition();
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send SLave Address + W
	Local_EnuTWIErrorState = TWI_EnuSendSlaveAddWithWrite(Local_u8SlaveAdd);
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send Byte Address
	Local_EnuTWIErrorState = TWI_EnuMasterSendDataByte((u8)Copy_u16ByteAddress);
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send Data Byte
	Local_EnuTWIErrorState = TWI_EnuMasterSendDataByte(Copy_u8Data);
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send stop Condition
	TWI_EnuSendStopCondition();
	_delay_ms(5);

return Local_u8ErrorState;
}
u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress,u8 * Copy_pu8RXData)//11bit
{
	u8 			 	Local_u8ErrorState = STD_TYPES_NOK ;
	TWIError_t 		Local_EnuTWIErrorState = TWI_OK ;
	u8 			 	Local_u8SlaveAdd =(EEEPROM_u8_FIXED_ADD|(Copy_u16ByteAddress>>8));//(((address & 0x700)>>8)|0x50)
	// Send Start Condition
	Local_EnuTWIErrorState = TWI_EnuSendREStartCondition();
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send SLave Address + W
	Local_EnuTWIErrorState = TWI_EnuSendSlaveAddWithWrite(Local_u8SlaveAdd);
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send Byte Address
	Local_EnuTWIErrorState = TWI_EnuMasterSendDataByte((u8)Copy_u16ByteAddress);
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send Repeated Start Condition
	Local_EnuTWIErrorState = TWI_EnuSendREStartCondition();
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send SLave Address + R
	Local_EnuTWIErrorState = TWI_EnuSendSlaveAddWithRead(Local_u8SlaveAdd);
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Read Data Byte
	Local_EnuTWIErrorState = TWI_EnuMasterReadDataByte(Copy_pu8RXData);
	if (Local_EnuTWIErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	// Send stop Condition
	TWI_EnuSendStopCondition();
	_delay_ms(5);
return Local_u8ErrorState;
}
