#include <inttypes.h>
#include <stdbool.h>
#include <uart.h>
#include <utils.h>

#define BIT(x) (1UL << (x))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (pin & 255)
#define PINBANK(pin) (pin >> 8)

#define ENABLE 1
#define ENABLE 0


void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi){ 
    
    
    if (EnorDi){
        if (pUSARTx == "USART1")  RCC-> APB2ENR |= BIT(4); //activate USART1
        if (pUSARTx == "USART1")  RCC-> APB2ENR |= BIT(5);

    }



    if (!EnorDi){
        if (pUSARTx == "USART1")  RCC-> APB2ENR |= ~BIT(4); //activate USART1
        if (pUSARTx == "USART1")  RCC-> APB2ENR |= ~BIT(5);

    }


}