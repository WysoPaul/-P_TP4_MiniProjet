//////////////////////////////////////////////////////////////////////////////////////
// ITI_2D_µp_TP4_ChenillardMinuteurCuisine
// Vinuesa Nicolas
// Wysocki Paul
// 2019_TD1_TP2
//////////////////////////////////////////////////////////////////////////////////////

#include "stm32f4xx.h"
#include "Affled.h"
extern void tempo(int);

void affiche2LEDs(unsigned int nTemp) 
{
	GPIOG->ODR = (GPIOG->ODR & 0xFFFF9FFF)| 0x00002000;	// LED VERTE ON && LED RED OFF
	tempo(nTemp);
	GPIOG->ODR = (GPIOG->ODR & 0xFFFF9FFF)| 0x00004000;	// LED VERTE OFF && LED RED ON
	tempo(nTemp);
}


void ToggleLedRed(void){
	if(0 == (GPIOG->ODR & 0x00004000)){		// Si la LED RED est éteinte
		GPIOG->BSRR |= 0x00004000;				// Allumer LED RED (sans toucher à LED VERT)
	}else{
		GPIOG->BSRR |= 0x40000000;				// Sinon éteindre LED RED
	}
}


void ToggleLedGreen(void){
	if(0 == (GPIOG->ODR & 0x00002000)){		// Si la LED VERTE est éteinte
		GPIOG->BSRR |= 0x00002000;				// Allumer LED RED (sans toucher à LED VERT)
	}else{
		GPIOG->BSRR |= 0x20000000;				// Sinon éteindre LED RED
	}
}

