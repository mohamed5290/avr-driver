/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 21/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : Timer                 *****************/ 
/********************************************************************/
  
  
#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

#include "TMR_interface.h"  
#include "TMR_private.h"  
#include "TMR_config.h"  

//
static void (*TMR_pftimer0overflowcallback)(void) =NULL; 
static void (*TMR_pftimer0_CTCcallback)(void) =NULL;

void TMR_voidtimer0init(void)
{
	/*select mode*/
	if(TMR_MODE==TMR_NORMAL)
	{
	  CLE_BIT(TMR_U8_TMR0_TCCR0_REG,6);
      CLE_BIT(TMR_U8_TMR0_TCCR0_REG,3);

	  	/*init tmr rigester with the load value*/
	  TMR_U8_TMR0_TCNT0_REG =  TMR_U8_TMR0_PRELOAD_VALUE;
	
		/*Enable ovf intrreupt */
        SET_BIT(TMR_U8_TMR_TIMSK_REG,TMR_U8_TIMSK_TOIE0);
	}
	else if(TMR_MODE == TMR_PWM)
	{
		SET_BIT(TMR_U8_TMR0_TCCR0_REG,6);
        CLE_BIT(TMR_U8_TMR0_TCCR0_REG,3);

	}
	else if(TMR_MODE == TMR_CTC)
	{
		SET_BIT(TMR_U8_TMR0_TCCR0_REG,3);
        CLE_BIT(TMR_U8_TMR0_TCCR0_REG,6);

        TMR_U8_TMR0_OCR0_REG = 100;
		/*Enable ovf intrreupt */
		SET_BIT(TMR_U8_TMR_TIMSK_REG,TMR_U8_TIMSK_OCIE0);

/*
		SET_BIT(TMR_U8_TMR0_TCCR0_REG,TMR_U8_TCCR0_COM00);
        SET_BIT(TMR_U8_TMR0_TCCR0_REG,TMR_U8_TCCR0_COM01);
*/
	}
	else if(TMR_MODE == TMR_FAST_PWM)
	{
		SET_BIT(TMR_U8_TMR0_TCCR0_REG,6);
        SET_BIT(TMR_U8_TMR0_TCCR0_REG,3);
	}


	
	//select prescaler 
	/*
		CLE_BIT(TMR_U8_TMR0_TCCR0_REG,0);
        SET_BIT(TMR_U8_TMR0_TCCR0_REG,1);
		CLE_BIT(TMR_U8_TMR0_TCCR0_REG,2);
	*/
	TMR_U8_TMR0_TCCR0_REG &=~(7<<0);
	TMR_U8_TMR0_TCCR0_REG |=(TMR_U8_PRESCALLER<<0);
	
}


u8 TMR_u8tmr0overflowsetcallback(void(*copy_pfcallback(void)))
{ 
   u8 local_u8staterror =STD_TYPES_OK;
   if(copy_pfcallback !=NULL)
   {
	TMR_pftimer0overflowcallback = copy_pfcallback;
   }
	else
	{
		local_u8staterror =STD_TYPES_NOK;
	}
	return local_u8staterror;
}


u8 TMR_u8tmr0_CTCsetcallback(void(*copy_pfcallback(void)))
{
	u8 local_u8staterror =STD_TYPES_OK;
   if(copy_pfcallback !=NULL)
   {
	TMR_pftimer0_CTCcallback = copy_pfcallback;
   }
	else
	{
		local_u8staterror =STD_TYPES_NOK;
	}
	return local_u8staterror;

}


/*  ISR fo */
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16counter;
	local_u16counter++;
	if(local_u16counter == TMR_U16_TMR0_OVERFLOW_COUNTER)
	{
		/*set preload value*/
	   TMR_U8_TMR0_TCNT0_REG =  TMR_U8_TMR0_PRELOAD_VALUE;
	   /*clear vounter*/
	   local_u16counter =0;
         if(TMR_pftimer0overflowcallback !=NULL) 
          {
            TMR_pftimer0overflowcallback();
           }

	  }
	
	
}

void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
	static u16 local_u16counter;
	local_u16counter++;
	if(local_u16counter == 10000)
	{
		local_u16counter =0;
		if(TMR_pftimer0_CTCcallback !=NULL)
		{
		TMR_pftimer0_CTCcallback();
	    }
	}
}
