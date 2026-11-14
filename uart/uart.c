#include <inttypes.h>
#include <stdbool.h>
#include <uart.h>
#include <utils.h>

#define BIT(x) (1UL << (x))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (pin & 255)
#define PINBANK(pin) (pin >> 8)

#define ENABLE 1
#define DISABLE 0


void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi){ 

    

    //activate all the others later on
    if (EnorDi){
        if (pUSARTx == "USART1")  RCC-> APB2ENR |= BIT(4); //activate USART1
        if (pUSARTx == "USART6")  RCC-> APB2ENR |= BIT(5);

    }



    if (!EnorDi){
        if (pUSARTx == "USART1")  RCC-> APB2ENR |= ~BIT(4); //activate USART1
        if (pUSARTx == "USART6")  RCC-> APB2ENR |= ~BIT(5);

    }


}




void USART_Init(USART_Handle_t *pUSARTHandle){

    //Temporary variable
	uint32_t tempreg=0;// we use this to make a simpler configuration



    /*Configuarion of CR1*/

    //Implement the code to enable the Clock for given USART peripheral
    USART_PeriClockControl(&(pUSARTHandle->pUSARTx),1);


    //Enable the usart by using the control register
    pUSARTHandle->pUSARTx->CR1 |= BIT(13); 


    //Enable USART Tx and Rx engines according to the USART_Mode configuration item
   if ( pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX){

        tempreg |= BIT(3);
   }


    //Enable USART Tx and Rx engines according to the USART_Mode configuration item
   if ( pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX){

        tempreg |= BIT(2);
   }


     //Enable USART Tx and Rx engines according to the USART_Mode configuration item
   if ( pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX){

    tempreg |= BIT(2) & BIT(3);

   }



    

    //Define the word lenght
    tempreg |= pUSARTHandle->USART_Config.USART_WordLength << 12;



     /*Configuarion of CR2*/






     /*BAUD RATE*/


}