/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 28/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : I2C                   *****************/ 
/********************************************************************/


#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h" 


void         TWI_voidMasterInit             (void)
{
      /*set prescaler value */
	  CLE_BIT(TWI_u8_TWSR_REG,0);
	  CLE_BIT(TWI_u8_TWSR_REG,1);
	  
      /*set freq 200KHz*/
	  TWI_u8_TWBR_REG = 12;
       /*Enable ACK*/
      SET_BIT(TWI_u8_TWCR_REG,6);
	 /*Enable TWI priphral*/
      SET_BIT(TWI_u8_TWCR_REG,2);
	 
}
            
void         TWI_voidSlaveInit              (u8 Copy_u8Address)
{
	/*set its own slave address */
	TWI_u8_TWAR_REG |= (Copy_u8Address<<1);
	/* enable general call*/
	/*Enable ACK*/
	 SET_BIT(TWI_u8_TWCR_REG,6);
    /*Enable TWI priphral*/
	  SET_BIT(TWI_u8_TWCR_REG,2);
} 

TWIERROR_t   TWI_EnuSendStartCondition      (void)
{
	TWIERROR_t local_enuERRORstat = TWI_OK;
	/*send start condition */
	SET_BIT(TWI_u8_TWCR_REG,5);
	/*clear flag to start next job*/
	SET_BIT(TWI_u8_TWCR_REG,7);
	
	/*wait for the flag */
	while(!GIT_BIT(TWI_u8_TWCR_REG,7));

	/*Chack Ack = SC_ASK */
	
	if((TWI_u8_TWSR_REG & 0xf8) != 0x08)
	{
		local_enuERRORstat = TWI_SC_ERROR;
	}
   return local_enuERRORstat ;
}

TWIERROR_t   TWI_EnuSendRestartCondition    (void)
{
	TWIERROR_t local_enuERRORstat = TWI_OK;
	
		/*send start condition */
		SET_BIT(TWI_u8_TWCR_REG,5);
	    /*clear flag to start next job*/
		CLE_BIT(TWI_u8_TWCR_REG,7);
	    /*wait for the flag */
		while(!GIT_BIT(TWI_u8_TWCR_REG,7));
	    /*Chack Ack =RSC_ACK */
			if((TWI_u8_TWSR_REG & 0xF8) != 0x10)
	        {
		     local_enuERRORstat = TWI_RS_ERROR;
	        }

           return local_enuERRORstat ;
}
TWIERROR_t   TWI_EnuSendSlaveaddWithwriteop (u8 Copy_u8SlaveAddress)
{
		TWIERROR_t local_enuERRORstat = TWI_OK;
     /*  clear Start condition  bit*/
    CLE_BIT(TWI_u8_TWCR_REG,5);

    /*set TwDR_REG with input slave add +0*/
    TWI_u8_TWDR_REG = Copy_u8SlaveAddress<<1;
	CLE_BIT(TWI_u8_TWDR_REG,0);
    /*clear flag to start next job*/
	    SET_BIT(TWI_u8_TWCR_REG,7);
    /*Chack Ack =SLA+W ACK */
	    if((TWI_u8_TWSR_REG & 0xF8) != 0x18)
	     {
	     local_enuERRORstat = TWI_SLAVE_W_ERROR;
	     }

         return local_enuERRORstat ;
}       

TWIERROR_t   TWI_EnuSendSlaveaddWithreedop  (u8 Copy_u8SlaveAddress)
{
		TWIERROR_t local_enuERRORstat = TWI_OK;	
	    /*clear Start condition  bit*/
		   CLE_BIT(TWI_u8_TWCR_REG,5);

        /*set TwDR_REG with input slave add +0*/
		 TWI_u8_TWDR_REG = Copy_u8SlaveAddress<<1 ;
		 SET_BIT(TWI_u8_TWDR_REG,0);        
        /*clear flag to start next job*/
	    SET_BIT(TWI_u8_TWCR_REG,7);
		
	    /*Chack Ack =SLA+R ACK */
	    if((TWI_u8_TWSR_REG & 0xF8) != 0x40)
	     {
	     local_enuERRORstat = TWI_SLAVE_R_ERROR;
	     }

         return local_enuERRORstat ;
}        

TWIERROR_t   TWI_EnuMasterSendDatabyte      (u8 Copy_u8Data)
{
		TWIERROR_t local_enuERRORstat = TWI_OK;		
        /*write data into twdr reg */
		TWI_u8_TWDR_REG = Copy_u8Data;
        /*  clear Start condition  bit*/
		 CLE_BIT(TWI_u8_TWCR_REG,5);


        /*clear flag to start next job*/
	    SET_BIT(TWI_u8_TWCR_REG,7);
		while(!GIT_BIT(TWI_u8_TWCR_REG,7));
		/*Chack Ack =Send _data ACK */ 
	    if((TWI_u8_TWSR_REG & 0xF8) != 0x28)
	     {
	     local_enuERRORstat = TWI_DATA_W_ERROR;
	     }

         return local_enuERRORstat ;				
}       

TWIERROR_t   TWI_EnuMasterReedDatabyte      (u8 *Copy_pu8Data)
{
	TWIERROR_t local_enuERRORstat = TWI_OK;	
	if(Copy_pu8Data !=NULL)
	{

      CLE_BIT(TWI_u8_TWCR_REG,5);
	/*clear flag to start next job*/
	SET_BIT(TWI_u8_TWCR_REG,7);
	
	/*wait for the flag */
	while(!GIT_BIT(TWI_u8_TWCR_REG,7));

	/*Chack Ack = SC_ASK */
	
	if((TWI_u8_TWSR_REG & 0xf8) != 0x50)
	{
		local_enuERRORstat = TWI_SC_ERROR;
	}
	else 
	{
	*Copy_pu8Data = TWI_u8_TWDR_REG	;
	}
	}
	else
	{
	  	local_enuERRORstat =NULL_ERROR;
	}
   return local_enuERRORstat ;	
}

TWIERROR_t   TWI_EnuSendStopCondition       (void)
{
    /*send stop condition*/	
	SET_BIT(TWI_u8_TWCR_REG,4);
  	/*  clear Start condition  bit*/
	SET_BIT(TWI_u8_TWCR_REG,7);

}