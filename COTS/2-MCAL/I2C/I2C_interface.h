/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 27/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : I2C                   *****************/ 
/********************************************************************/
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

typdef enum 
{
	TWI_OK;
	TWI_SC_ERROR;
	TWI_RS_ERROR;
	TWI_SLAVE_W_ERROR;
	TWI_SLAVE_R_ERROR
	TWI_DATA_W_ERROR
	TWI_DATA_R_ERROR,
	NULL_ERROR;
	
}TWIERROR_t;

void         TWI_voidMasterInit             (void);
            
void         TWI_voidSlaveInit              (u8 Copy_u8Address);

TWIERROR_t   TWI_EnuSendStartCondition      (void);

TWIERROR_t   TWI_EnuSendRestartCondition    (void);

TWIERROR_t   TWI_EnuSendSlaveaddWithwriteop (u8 Copy_u8SlaveAddress);        

TWIERROR_t   TWI_EnuSendSlaveaddWithreedop  (u8 Copy_u8SlaveAddress);        

TWIERROR_t   TWI_EnuMasterSendDatabyte      (u8 Copy_u8Data);        

TWIERROR_t   TWI_EnuMasterReedDatabyte      (u8 *Copy_pu8Data);        

TWIERROR_t   TWI_EnuSendStopCondition       (void);

#endif