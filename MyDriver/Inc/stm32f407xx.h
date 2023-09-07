/*
 * stm32f407xx.h
 *
 *  Created on: Aug 31 , 2023
 *      Author: yusuf
 */



#ifndef INC_STM32F407XX_H_          //header guard
#define INC_STM32F407XX_H_

/* MİKROİŞLEMCİ İÇİN TEMEL HEADER DOSYASI */

#include <stdint.h>


#define __IO  volatile

#define SET_BIT(REG , BIT)  ((REG) |=  (BIT))
#define CLR_BIT(REG , BIT)  ((REG) &= ~(BIT))
#define READ_BIT(REG , BIT) ((REG) &=  (BIT))
#define UNUSED(x)  (void)x



/*
 *  Addresses definition of memories
 *
 */

#define FLASH_MEMORY_BASE_ADDR		(0x08000000UL)		/*Flash Memory up to 1MB	*/  //#define olarak yapılan işlemler pre-processer işlemlerdir
#define SRAM1_BASE_ADDR				(0x20000000UL)		/*112KB SRAM 				*/
#define SRAM2_BASE_ADDR				(0x2001C000UL)		/*16KB SRAM					*/
/* the addresses that won't be use didn't define */



/*
 * Addresses definition of peripheral base (BUS DOMAİN)
 *
 */

#define PERIPH_BASE_ADDR		(0x40000000UL)							/*Base of Peripherals				*/
#define APB1_BASE_ADDR			(PERIPH_BASE_ADDR)						/*Base of Advanced Peripheral Bus 1 */
#define APB2_BASE_ADDR			(PERIPH_BASE_ADDR + 0x00010000UL)		/*Base of Advanced Peripheral Bus 2 */
#define AHB1_BASE_ADDR			(PERIPH_BASE_ADDR + 0x00020000UL)		/*Base of Advanced High-Perf. Bus 1 */
#define AHB2_BASE_ADDR			(PERIPH_BASE_ADDR + 0x10000000UL)		/*Base of Advanced High-Perf. Bus 2 */


/*
 * Addresses definiton of APB1
 *
 */

#define TIM2_BASE_ADDR			(APB1_BASE_ADDR + 0x0000UL)		/*Base of Timer 2 */
#define TIM3_BASE_ADDR			(APB1_BASE_ADDR + 0x0400UL)		/*Base of Timer 3 */
#define TIM4_BASE_ADDR			(APB1_BASE_ADDR + 0x0800UL)		/*Base of Timer 4 */
#define TIM5_BASE_ADDR			(APB1_BASE_ADDR + 0x0C00UL)		/*Base of Timer 5 */
#define TIM6_BASE_ADDR			(APB1_BASE_ADDR + 0x1000UL)		/*Base of Timer 6 */
#define TIM7_BASE_ADDR			(APB1_BASE_ADDR + 0x1400UL)		/*Base of Timer 7 */

#define SPI2_BASE_ADDR			(APB1_BASE_ADDR + 0x3800UL)		/*Base of SPI 2   */
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR + 0x3C00UL)		/*Base of SPI 3   */

#define USART2_BASE_ADDR		(APB1_BASE_ADDR + 0x4400UL)		/*Base of USART	2 */
#define USART3_BASE_ADDR		(APB1_BASE_ADDR + 0x4800UL)		/*Base of USART	3 */
#define UART4_BASE_ADDR			(APB1_BASE_ADDR + 0x4C00UL)		/*Base of UART 4  */
#define UART5_BASE_ADDR			(APB1_BASE_ADDR + 0x5000UL)		/*Base of UART 5  */

#define I2C1_BASE_ADDR			(APB1_BASE_ADDR + 0x5400UL)		/*Base of I2C 1   */
#define I2C2_BASE_ADDR			(APB1_BASE_ADDR + 0x5800UL)		/*Base of I2C 2   */
#define I2C3_BASE_ADDR			(APB1_BASE_ADDR + 0x5C00UL)		/*Base of I2C 3   */
/* The addresses that won't be use didn't define */


/*
 * Addresses definition of APB2
 *
 */

#define TIM1_BASE_ADDR			(APB2_BASE_ADDR + 0x0000UL)		/*Base of Timer 1 */
#define TIM8_BASE_ADDR			(APB2_BASE_ADDR + 0x0400UL)		/*Base of Timer 8 */

#define USART1_BASE_ADDR		(APB2_BASE_ADDR + 0x1000UL)		/*Base of USART 1 */
#define USART6_BASE_ADDR		(APB2_BASE_ADDR + 0x1400UL)		/*Base of USART 6 */

#define SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0x3000UL)		/*Base of SPI 1   */
#define SPI4_BASE_ADDR			(APB2_BASE_ADDR + 0x3400UL)		/*Base of SPI 4   */

#define SYSCFG_BASE_ADDR 		(APB2_BASE_ADDR + 0x3800UL) 	/*Base of System Configure Address*/
#define EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0x3C00UL)		/*Base of External Interrupt	  */
/* The addresses that won't be use didn't define */



/*
 * Addresses definiton of AHB1
 *
 */

#define GPIOA_BASE_ADDR 	(AHB1_BASE_ADDR + 0x0000UL)			/*Base of General Purpose I/O A */
#define GPIOB_BASE_ADDR 	(AHB1_BASE_ADDR + 0x0400UL)			/*Base of General Purpose I/O B */
#define GPIOC_BASE_ADDR 	(AHB1_BASE_ADDR + 0x0800UL)			/*Base of General Purpose I/O C */
#define GPIOD_BASE_ADDR 	(AHB1_BASE_ADDR + 0x0C00UL)			/*Base of General Purpose I/O D */
#define GPIOE_BASE_ADDR 	(AHB1_BASE_ADDR + 0x1000UL)			/*Base of General Purpose I/O E */
#define GPIOF_BASE_ADDR 	(AHB1_BASE_ADDR + 0x1400UL)			/*Base of General Purpose I/O F */
#define GPIOG_BASE_ADDR 	(AHB1_BASE_ADDR + 0x1800UL)			/*Base of General Purpose I/O G */
#define GPIOH_BASE_ADDR 	(AHB1_BASE_ADDR + 0x1C00UL)			/*Base of General Purpose I/O H */
#define GPIOI_BASE_ADDR 	(AHB1_BASE_ADDR + 0x2000UL)			/*Base of General Purpose I/O I */
#define GPIOJ_BASE_ADDR 	(AHB1_BASE_ADDR + 0x2400UL)			/*Base of General Purpose I/O J */
#define GPIOK_BASE_ADDR 	(AHB1_BASE_ADDR + 0x2800UL)			/*Base of General Purpose I/O K */

#define RCC_BASE_ADDR 		(AHB1_BASE_ADDR + 0x3800UL)			/*Base of RCC    				*/






/*
 *  Definiton of structure peripheral
 *
 */


typedef struct for_GPIO
{
	__IO uint32_t MODER;			/*!< GPIO port mode register         			Address offset: 0x00 */
	__IO uint32_t OTYPER;			/*!< GPIO port output type register	  			Address offset: 0x04 */
	__IO uint32_t OSPEEDR;			/*!< GPIO port output speed register  			Address offset: 0x08 */
	__IO uint32_t PUPDR;			/*!< GPIO port pull-up/pull-down register		Address offset: 0x0C */
	__IO uint32_t IDR;		 		/*!< GPIO port input data register				Address offset: 0x10 */
	__IO uint32_t ODR;				/*!< GPIO port output data register				Address offset: 0x14 */
	__IO uint32_t BSRR;				/*!< GPIO port bit set/reset register			Address offset: 0x18 */
	__IO uint32_t LCKR;				/*!< GPIO port configuration lock register  	Address offset: 0x1C */
	__IO uint32_t AFR[2];     		/*!< GPIO alternate function low/high register  Address offset: 0x20 */
//	__IO uint32_t AFRH;			/* AFR={ AFRL , AFRH } */

}GPIO_REG_Typedef;

#define GPIOA ((GPIO_REG_Typedef *)(GPIOA_BASE_ADDR))
#define GPIOB ((GPIO_REG_Typedef *)(GPIOB_BASE_ADDR))
#define GPIOC ((GPIO_REG_Typedef *)(GPIOC_BASE_ADDR))
#define GPIOD ((GPIO_REG_Typedef *)(GPIOD_BASE_ADDR))
#define GPIOE ((GPIO_REG_Typedef *)(GPIOE_BASE_ADDR))
#define GPIOF ((GPIO_REG_Typedef *)(GPIOF_BASE_ADDR))
#define GPIOG ((GPIO_REG_Typedef *)(GPIOG_BASE_ADDR))



/*
 *   Definiton of structure Reset and Clock Control
 *
 */


typedef struct
{
	__IO uint32_t CR;			 	/*!<RCC clock control register										Address offset: 0x00 */
	__IO uint32_t PLLCFGR;      	/*!<PLL(Phase-locked loop) configuration register 					Address offset: 0x04 */
	__IO uint32_t CFGR; 		    /*!<RCC clock configuration register				 				Address offset: 0x08 */
	__IO uint32_t CIR;				/*!<RCC clock interrupt register									Address offset: 0x0C */
	__IO uint32_t AHB1RSTR;	    	/*!<AHB1 peripheral reset register									Address offset: 0x10 */
	__IO uint32_t AHB2RSTR;	     	/*!<AHB2 peripheral reset register									Address offset: 0x14 */
	__IO uint32_t AHB3RSTR;	     	/*!<AHB3 peripheral reset register									Address offset: 0x18 */
	__IO uint32_t RESERVED_0x1C;
	__IO uint32_t APB1RSTR;	    	/*!<APB1 peripheral reset register									Address offset: 0x20 */
	__IO uint32_t APB2RSTR;	    	/*!<APB2 peripheral reset register									Address offset: 0x24 */
	__IO uint32_t RESERVED_0x28; 	/* __IO uint32_t RESERVED[2];                                                */
	__IO uint32_t RESERVED_0x2C;
	__IO uint32_t AHB1ENR;			/*!<RCC AHB1 peripheral clock enable register						Address offset: 0x30 */
	__IO uint32_t AHB2ENR;		 	/*!<RCC AHB2 peripheral clock enable register 						Address offset: 0x34 */
	__IO uint32_t AHB3ENR;			/*!<RCC AHB3 peripheral clock enable register						Address offset: 0x38 */
	__IO uint32_t RESERVED_0x3C;
	__IO uint32_t APB1ENR;			/*!<RCC APB1 peripheral clock enable register						Address offset: 0x40 */
	__IO uint32_t APB2ENR;			/*!<RCC APB2 peripheral clock enable register						Address offset: 0x44 */
	__IO uint32_t RESERVED_0x48;
	__IO uint32_t RESERVED_0x4C;
	__IO uint32_t AHB1LPENR;		/*!<RCC AHB1 peripheral clock enable in low power mode register		Address offset: 0x50 */
	__IO uint32_t AHB2LPENR;		/*!<RCC AHB2 peripheral clock enable in low power mode register		Address offset: 0x54 */
	__IO uint32_t AHB3LPENR;		/*!<RCC AHB3 peripheral clock enable in low power mode register		Address offset: 0x58 */
	__IO uint32_t RESERVED_0x5C;
	__IO uint32_t APB1LPENR;		/*!<RCC APB1 peripheral clock enable in low power mode register		Address offset: 0x60 */
	__IO uint32_t APB2LPENR;		/*!<RCC APB1 peripheral clock enable in low power mode register		Address offset: 0x64 */
	__IO uint32_t RESERVED_0x68;
	__IO uint32_t RESERVED_0x6C;
	__IO uint32_t BDCR;				/*!<RCC Backup domain control register								Address offset: 0x70 */
	__IO uint32_t CSR;				/*!<RCC clock control & status register								Address offset: 0x74 */
	__IO uint32_t RESERVED_0x78;
	__IO uint32_t RESERVED_0x7C;
	__IO uint32_t SSCGR;			/*!<RCC spread spectrum clock generation register					Address offset: 0x80 */
	__IO uint32_t PLLI2SCFGR;		/*!<RCC PLLI2S configuration register 								Address offset: 0x84 */

}RCC_REG_Typedef;

#define RCC ((RCC_REG_Typedef *)(RCC_BASE_ADDR))










#include "RCC.h"
#include "GPIO.h"

#endif /* INC_STM32F407XX_H_ */
