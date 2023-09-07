#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f407xx.h"  /* her header file, registerlarına ve yapılarına ulaşmak için temel header kütüphanemizi içermelidir*/


/*
 *  Definitions of RCC AHB1 Enable Register Bits
 *
 */

#define RCC_AHB1ENR_GPIOAEN_POS			(0U) /* (2^0) Position of GPIOA enable pin in the AHB1 Enable Reg */
#define RCC_AHB1ENR_GPIOAEN_MASK 		(1<<RCC_AHB1ENR_GPIOAEN_POS )
#define RCC_AHB1ENR_GPIOAEN				RCC_AHB1ENR_GPIOAEN_MASK

#define RCC_AHB1ENR_GPIOBEN_POS			(1U)  /* (2^1) Position of GPIOB enable pin in the AHB1 Enable Reg */
#define RCC_AHB1ENR_GPIOBEN_MASK 		(1<<RCC_AHB1ENR_GPIOBEN_POS )
#define RCC_AHB1ENR_GPIOBEN				RCC_AHB1ENR_GPIOBEN_MASK

#define RCC_AHB1ENR_GPIOCEN_POS 		(2U)  /* (2^2) Position of GPIOC enable pin in the AHB1 Enable Reg */
#define RCC_AHB1ENR_GPIOCEN_MASK		(1<<RCC_AHB1ENR_GPIOCEN_POS )
#define RCC_AHB1ENR_GPIOCEN				RCC_AHB1ENR_GPIOCEN_MASK

#define RCC_AHB1ENR_GPIODEN_POS 		(3U)  /* (2^2) Position of GPIOD enable pin in the AHB1 Enable Reg */
#define RCC_AHB1ENR_GPIODEN_MASK		(1<<RCC_AHB1ENR_GPIODEN_POS )
#define RCC_AHB1ENR_GPIODEN				RCC_AHB1ENR_GPIODEN_MASK



/*
 *  RCC AHB1 Reset and Clock Control Peripherals Macro Definitions
 *
 */
#define RCC_CLK_SET_GPIOA()     	do{    SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOAEN);			 	     \
										   uint32_t tempValue=0;								 	     \
										   tempValue = READ_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOAEN);  	 \
										   UNUSED(tempValue);										  	 \
									  }while(0);


#define RCC_CLK_SET_GPIOB()			do{   SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOBEN);  		 	  	 \
										  uint32_t tempValue=0;	 								  	     \
										  tempValue = READ_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOBEN);	  	 \
										  UNUSED(tempValue);										  	 \
									  }while(0);

#define RCC_CLK_SET_GPIOC()			do{   SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOCEN);  		 	 	 \
										  uint32_t tempValue=0;	 								  	     \
										  tempValue = READ_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOCEN);	  	 \
										  UNUSED(tempValue);										  	 \
									  }while(0);

#define RCC_CLK_SET_GPIOD()         do{   SET_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIODEN); 					\
										  uint32_t tempValue=0;											\
										  tempValue = READ_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIODEN);     \
										  UNUSED(tempValue);											\
                                      }while(0);

#define RCC_CLK_RESET_GPIOA()		CLR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOAEN) /* noktalı virgül konulmaz!!!!! */
#define RCC_CLK_RESET_GPIOB()		CLR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOBEN)
#define RCC_CLK_RESET_GPIOC()		CLR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIOCEN)
#define RCC_CLK_RESET_GPIOD()		CLR_BIT(RCC->AHB1ENR , RCC_AHB1ENR_GPIODEN)











#endif /* INC_RCC_H_ */
