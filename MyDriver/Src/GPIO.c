#include "GPIO.h"



/**
 * @brief	 Makes ready to Pin configuration of GPIOx
 * @param 	 GPIOx x can be (A..I) for STM32F407xx
 * 			 You can see when you search "GPIO_REG_Typedef" in the "stm32f407xx.h"
 * @param 	 GPIO_CONFIG_Init_Typedef is a structure which it has propert of pin that will configure
 * 			 User configure to that structure.
 * @retval	 none
 */

void GPIO_Init(GPIO_REG_Typedef* GPIOx , GPIO_CONFIG_Init_Typedef* Pin_Config_Sel)
{

	 uint8_t position;
	 uint16_t fakePosition=0x00;

	 for(position=0 ; position < Max_Pin_Number ; position++)
	 {

		 fakePosition = (0x01 << position);

		 if( (fakePosition & Pin_Config_Sel->Pin_Number) == fakePosition )
		 {

			 /* Configuraiton start */

			 /* MODER Config */

			 uint32_t tempValue = GPIOx->MODER;            // Direkt registerlar üzerinden işlem yapılmaz
			 tempValue &= ~( (0x3U) << ( 2 * position ) ); //önceki işlemlerden arıttı.
			 tempValue |= ( ((uint32_t)(Pin_Config_Sel->Pin_Mode)) << ( 2 * position ) );
			 GPIOx->MODER = tempValue;
			 // SET_BIT( (GPIOx->MODER) , ( (Pin_Config_Sel->Pin_Mode) << ( 2*position ) ) );


			 /* Output Configuraitons */

			 if( (Pin_Config_Sel->Pin_Mode) == GPIO_MODE_OUTPUT || (Pin_Config_Sel->Pin_Mode) == GPIO_MODE_AF )

			 {
				 /* OTYPER Config */

				 tempValue = GPIOx->OTYPER;
				 tempValue |= ( (uint32_t)(Pin_Config_Sel->Pin_OType) << position );
				 GPIOx->OTYPER = tempValue;


				 /*OSPEEDR Config */

				 tempValue = GPIOx->OSPEEDR;
				 tempValue &= ~( (0x03U) << ( 2 * position ) );
				 tempValue |= ( (Pin_Config_Sel->Pin_OType) << ( 2 * position ) );
				 GPIOx->OSPEEDR = tempValue ;

			 }

			 /* PUPDR Config */

			 tempValue = GPIOx->PUPDR;
			 tempValue &= ~( (0x03U) << ( 2 * position ) );
			 tempValue |= ( (Pin_Config_Sel->Pin_PuPd) << ( 2 * position ) );
			 GPIOx->PUPDR = tempValue;

		 }

	 }

}



/**
 * @brief	 Makes High or Low Output for bits of GPIOx Port
 * @param 	 GPIOx x can be (A..I) for STM32F407xx
 * 			 You can see when you search "GPIO_REG_Typedef" in the "stm32f407xx.h"
 * @param 	 GPIO_Pins represents pins of GPIOx Port. it can be 0-15.
 * 			 You can search "GPIO_Pins" for #define in the "GPIO.h" (it is at the top)
 * @param 	 Pin Mode means that you want to set or reset bits. you can type GPIO_Pin_Set or GPIO_Pin_Reset
 * @retval	 none
 */


void GPIO_Write(GPIO_REG_Typedef*  GPIOx , uint16_t GPIO_Pin ,Pin_Mode_Typedef Pin_Mode)
{
	 if(Pin_Mode == GPIO_Pin_Set)
	 {
		 SET_BIT( (GPIOx->BSRR) , (GPIO_Pin) );
		 // GPIOx->BSRR = GPIO_Pin ; Burada GPIO_Pin | orlanmış şekilde geleceği için | kullanmadan da yazılabilir.
	 }
	 else
	 {
		 SET_BIT( (GPIOx->BSRR) , ( (GPIO_Pin) << 16U ) );
		 CLR_BIT( (GPIOx->BSRR) , (GPIO_Pin) );
		 /* GPIOx->BSRR = (GPIO_Pin<<16);  Bu şekilde olduğunda 0110 0000 0000 0001 gibi üç pin reset edilmek istenirse
		 *altta SET bitleri zaten 0 olacaktır. Ancak böyle bir kullanımda  RESET ya da SET için son fonksiyon geçerli olur.
		 * işlem yapılacak tüm Pinler son fonksiyona yazılmalıdır.*/
	 }
}





/**
 * @brief	 Read data value of GPIOx register which is Input Mode
 * @param 	 GPIOx x can be (A..I) for STM32F407xx
 * 			 You can see when you search "GPIO_REG_Typedef" in the "stm32f407xx.h"
 * @param 	 GPIO_Pins represents pins of GPIOx Port. It can be 0-15.
 * 			 You can search "GPIO_Pins" for #define in the "GPIO.h"
 * @retval	 uint16_t and it have datas of selected pins of port
 */


uint16_t GPIO_Read(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin )
{
	uint16_t result = 0x00;
	result = READ_BIT( (GPIOx->IDR) , (GPIO_Pin) );
	//result = READ_BIT( (GPIOx->IDR) , (GPIO_Pin) );

	return result;

}


/**
 * @brief	 Read data value JUST ONE PİN which is selected of GPIOx register that is Input Mode
 * @param 	 GPIOx x can be (A..I) for STM32F407xx
 * 			 You can see when you search "GPIO_REG_Typedef" in the "stm32f407xx.h"
 * @param 	 GPIO_Pins represents pins of GPIOx Port. it can be 0-15.
 * 			 You can search "GPIO_Pins" for #define in the "GPIO.h"
 * @retval	 Pin_Mode_Typedef and it have data of selected pin that high or low
 */


Pin_Mode_Typedef GPIO_ReadPin(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin  )
{
	Pin_Mode_Typedef result = GPIO_Pin_Reset;

	if(((GPIO->IDR) & GPIO_Pin) != GPIO_Pin_Reset )
	{
		result = GPIO_Pin_Set ;

	}
	return result;
}

Pin_Mode_Typedef GPIO_ReaddPin(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin  )
{
	Pin_Mode_Typedef result = GPIO_Pin_Reset;

	if(((GPIO->IDR) & GPIO_Pin) == GPIO_Pin )
	{
		result = GPIO_Pin_Set ;

	}

	return result;
}



/**
 * @brief	 It lock configuration of bits
 * @param 	 GPIOx x can be (A..I) for STM32F407xx
 * 			 You can see when you search "GPIO_REG_Typedef" in the "stm32f407xx.h"
 * @param 	 GPIO_Pins represents pins of GPIOx Port. it can be 0-15.
 * 			 You can search "GPIO_Pins" for #define in the "GPIO.h"
 * @retval	 none
 */



void GPIO_ConfigLock(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin)  /* the Pin variable should be exact Word(32-bit) */
{
		GPIO_Pin = ( ((uint32_t)GPIO_Pin) | (0x00001111) );     /* 0000 0000 0000 0000 xxxx xxxx xxxx xxxx */
		uint32_t PIN_16 = 0x0100;   							/* 0000 0000 0000 0001 0000 0000 0000 0000 */
		SET_BIT( (GPIOx->LCKR) , (PIN_16 | GPIO_Pin) ) ;
		SET_BIT( (GPIOx->LCKR) , (GPIO_Pin) ) ;
		SET_BIT( (GPIOx->LCKR) , (PIN_16 |GPIO_Pin) ) ;
		uint32_t Read_LCKR = GPIOx->LCKR ;

}


Pin_Mode_Typedef GPIO_ConfigLockAndControl(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin)  /* the Pin variable should be exact Word(32-bit) */
{
		Pin_Mode_Typedef result= GPIO_Pin_Reset;
		GPIO_Pin = ( ((uint32_t)GPIO_Pin) | (0x00001111) );     /* 0000 0000 0000 0000 xxxx xxxx xxxx xxxx */
		uint32_t PIN_16 = 0x0100;   							/* 0000 0000 0000 0001 0000 0000 0000 0000 */
		SET_BIT( (GPIOx->LCKR) , (PIN_16 | GPIO_Pin) ) ;
		SET_BIT( (GPIOx->LCKR) , (GPIO_Pin) ) ;
		SET_BIT( (GPIOx->LCKR) , (PIN_16 |GPIO_Pin) ) ;
		uint32_t Read_LCKR = GPIOx->LCKR ;
		uint32_t BIT_16 = READ_BIT( (GPIOx->LCKR) , (PIN_16) ) ;

		if(BIT_16 != GPIO_Pin_Reset)
		{
			result = GPIO_Pin_Set ;
		}
		return result;
}





/**
 * @brief	 It will be toggle  to bits
 * @param 	 GPIOx x can be (A..I) for STM32F407xx
 * 			 You can see when you search "GPIO_REG_Typedef" in the "stm32f407xx.h"
 * @param 	 GPIO_Pins represents pins of GPIOx Port. it can be 0-15.
 * 			 You can search "GPIO_Pins" for #define in the "GPIO.h"
 * @retval	 none
 */



void GPIO_Toggle(GPIO_REG_Typedef* GPIOx , uint16_t GPIO_Pin )
{

	 uint32_t tempValue=0;
	 tempValue = GPIOx->ODR;

	 (tempValue & GPIO_Pin); //toggle etmek istediğin ve 1 olan değerler

	 GPIOx->BSRR |= ( (tempValue & GPIO_Pin) << 16U ); // toggle etmek istediğin ve 1 olan değerleri resetledik.
	 GPIOx->BSRR &= ~(tempValue & GPIO_Pin) ;		   // SET BİLGİLERİ TEMİZLENDİ.

	 ( (~tempValue) & GPIO_Pin ); //toggle etmek istediğin ve 0 olan değerler.
	 GPIOx->BSRR |= ( (~tempValue) & GPIO_Pin );
	 GPIOx->BSRR &= ~(((~tempValue) & GPIO_Pin ) << 16U );


	//  GPIOx->BSRR |= ( ( (tempValue & GPIO_Pin) << 16U )  |  ( (~tempValue) & GPIO_Pin ) ); //TEK SATIR
	// GPIOx->BSRR &= (  ~(tempValue & GPIO_Pin)   |  ~(((~tempValue) & GPIO_Pin ) << 16U ) );
}













