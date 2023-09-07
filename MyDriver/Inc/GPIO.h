//function decleration
#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f407xx.h"



#define Max_Pin_Number  16  /* Pin number of a port that is available */

/*
 *  Definition of GPIO Pins (@def_group GPIO_Pins)
 *
 */

#define PIN_0   ((uint16_t)(0x0001))      /*0000 0000 0000 0001 b */	/*!<GPIO Pin 0 selected    */  /*direkt pin numaralarına tekabül etmiyor*/
#define PIN_1   ((uint16_t)(0x0002))      /*0000 0000 0000 0010 b */	/*!<GPIO Pin 1 selected    */
#define PIN_2   ((uint16_t)(0x0004))	  /*0000 0000 0000 0100 b */	/*!<GPIO Pin 2 selected    */
#define PIN_3   ((uint16_t)(0x0008))	  /*0000 0000 0000 1000 b */	/*!<GPIO Pin 3 selected    */
#define PIN_4   ((uint16_t)(0x0010))	  /*0000 0000 0001 0000 b */	/*!<GPIO Pin 4 selected    */
#define PIN_5   ((uint16_t)(0x0020))  	  /*0000 0000 0010 0000 b */	/*!<GPIO Pin 5 selected    */
#define PIN_6   ((uint16_t)(0x0040))	  /*0000 0000 0100 0000 b */	/*!<GPIO Pin 6 selected    */
#define PIN_7   ((uint16_t)(0x0080))	  /*0000 0000 1000 0000 b */	/*!<GPIO Pin 7 selected    */
#define PIN_8   ((uint16_t)(0x0100))	  /*0000 0001 0000 0000 b */	/*!<GPIO Pin 8 selected    */
#define PIN_9   ((uint16_t)(0x0200))	  /*0000 0010 0000 0000 b */	/*!<GPIO Pin 9 selected    */
#define PIN_10  ((uint16_t)(0x0400))	  /*0000 0100 0000 0000 b */	/*!<GPIO Pin 10 selected   */
#define PIN_11  ((uint16_t)(0x0800))	  /*0000 1000 0000 0000 b */	/*!<GPIO Pin 11 selected   */
#define PIN_12  ((uint16_t)(0x1000))      /*0001 0000 0000 0000 b */	/*!<GPIO Pin 12 selected   */
#define PIN_13  ((uint16_t)(0x2000))	  /*0010 0000 0000 0000 b */	/*!<GPIO Pin 13 selected   */
#define PIN_14  ((uint16_t)(0x4000))	  /*0100 0000 0000 0000 b */	/*!<GPIO Pin 14 selected   */
#define PIN_15  ((uint16_t)(0x8000))	  /*1000 0000 0000 0000 b */	/*!<GPIO Pin 15 selected   */
#define PIN_All ((uint16_t)(0xFFFF))	  /*1111 1111 1111 1111 b */	/*!<GPIO All Pins selected */

/*
 *  Definition of GPIO Modes (@def_group GPIO_Modes)
 *
 */

#define GPIO_MODE_INPUT  (0x00U)
#define GPIO_MODE_OUTPUT (0x01U)
#define GPIO_MODE_AF     (0x02U)
#define GPIO_MODE_ANALOG (0x03U)


/*
 *  Definition of GPIO Output Types (@def_group GPIO_Otypes)
 *
 */
#define GPIO_OTYPE_PUPD	 (0x00U)
#define GPIO_OTYPE_OD	 (0x01U)


/*
 *  Definitions of GPIO Output Speeds(@def_group GPIO_Ospeeds)
 *
 */

#define GPIO_OSPEED_LOW  	  (0x00U)
#define GPIO_OSPEED_MID 	  (0x01U)
#define GPIO_OSPEED_HIGH	  (0x02U)
#define GPIO_OSPEED_VERY_HIGH (0x03U)


/*
 *  Definitions of GPIO Pull-Up / Pull-Down Adjusting (@def_group GPIO_PuPd)
 *
 */

#define GPIO_PuPd_NONE	(0x00U)
#define GPIO_PuPd_UP	(0x01U)
#define GPIO_PuPd_DOWN  (0x02U)


/*
 *  Definitions of GPIO Alternate function (@def_group GPIO_AFSel)
 *
 */

#define GPIO_AF0  (0X00U)
#define GPIO_AF1  (0X01U)
#define GPIO_AF2  (0X02U)
#define GPIO_AF3  (0X03U)
#define GPIO_AF4  (0X04U)
#define GPIO_AF5  (0X05U)  /*  0101*/
#define GPIO_AF6  (0X06U)
#define GPIO_AF7  (0X07U)
#define GPIO_AF8  (0X08U)
#define GPIO_AF9  (0X09U)
#define GPIO_AF10 (0X0AU)
#define GPIO_AF11 (0X0BU)
#define GPIO_AF12 (0X0CU)
#define GPIO_AF13 (0X0DU)
#define GPIO_AF14 (0X0EU)
#define GPIO_AF15 (0X0FU)



typedef struct{

	uint16_t Pin_Number;   /*!< GPIO Pin Number (@def_group GPIO_Pins)              */
	uint8_t  Pin_Mode; 	   /*!< GPIO Pin Modes  (@def_group GPIO_Modes) 	        */
	uint8_t  Pin_OType;	   /*!< GPIO Pin Output Types (@def_group GPIO_Otypes)      */
	uint8_t	 Pin_OSpeed;   /*!< GPIO Pin Output Speeds (@def_group GPIO_Ospeeds)    */
	uint8_t  Pin_PuPd;	   /*!< GPIO Pin Pull-UP / Pull-DOWN (@def_group GPIO_PuPd) */
	uint8_t  Pin_AF;	   /*!< GPIO Pin Alternate function (@def_group GPIO_AFSel) */

}GPIO_CONFIG_Init_Typedef;





typedef enum{
	GPIO_Pin_Reset = 0x00,
	GPIO_Pin_Set = !(GPIO_Pin_Reset),	//Bu yapı ile Pin_Mode için seçilebilir alternatifler bir yapıda toplanmış oldu.
}Pin_Mode_Typedef;




/*
 * Functions
 *
 */

void GPIO_Init(GPIO_REG_Typedef* GPIOx , GPIO_CONFIG_Init_Typedef* Pin_Config_Sel);

void GPIO_Write(GPIO_REG_Typedef*  GPIOx , uint16_t GPIO_Pin , Pin_Mode_Typedef Pin_Mode);
// (@def_group GPIO_Pins)


uint16_t GPIO_Read(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin );
Pin_Mode_Typedef GPIO_ReadPin(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin );
Pin_Mode_Typedef GPIO_ReaddPin(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin );

void GPIO_ConfigLock(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin);
Pin_Mode_Typedef GPIO_ConfigLockAndControl(GPIO_REG_Typedef* GPIOx, uint16_t GPIO_Pin);

void GPIO_Toggle(GPIO_REG_Typedef* GPIOx , uint16_t GPIO_Pin );






#endif /* INC_GPIO_H_ */
