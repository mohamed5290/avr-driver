/*
 *  Author   : Samar Sobhy
 *  Date     : January 28, 2021
 *  Version  : 1.0 v
 *  SWC      : EEPROM
 */
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidInit (void);

u8 EEPROM_u8WriteDataByte(u16 Copy_u16ByteAddress,u8 Copy_u8Data);//11bit

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress,u8 * Copy_pu8RXData);//11bit

#endif /* EEPROM_INTERFACE_H */
