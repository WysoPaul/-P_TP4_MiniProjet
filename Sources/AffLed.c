//////////////////////////////////////////////////////////////////////////////////////
// ITI_2D_µp_TP4_ChenillardMinuteurCuisine
// Vinuesa Nicolas
// Wysocki Paul
// 2019_TD1_TP2
//////////////////////////////////////////////////////////////////////////////////////

#include "stm32f4xx.h"
#include "Affled.h"

void affiche2LEDs(unsigned int nTemp) 
{ 
	
GPIOG->ODR &=0xffff9fff;
GPIOG->ODR |=0x00002000;
tempo();
GPIOG->ODR &=0xffff9fff;
GPIOG->ODR |=0x00004000;
tempo();	
}

void ToggleLedRed(void){
	
		
	
}


void ToggleLedGreen(void){
	
}

