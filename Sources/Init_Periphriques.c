//////////////////////////////////////////////////////////////////////////////////////
// ITI_2D_?p_TP4_ChenillardMinuteurCuisine
// Vinuesa Nicolas
// Wysocki Paul
// 2019_TD1_TP2
//////////////////////////////////////////////////////////////////////////////////////
#include "stm32f4xx.h"


/****************************** Initialisation G13 et G14 pour le chenillard ********************/
void Init_port_leds(void)
{
	// Q4 Activation horloge Port G en utilisant un pointeur
	//RCC->AHB1ENR |= 0x00000040
	int *ptr_RCC_AHB1ENR;
	ptr_RCC_AHB1ENR = (int*)0x40023830;						// Adresse d�but r�gistre  CTRL 0x40023000 + offset=0x30
	*ptr_RCC_AHB1ENR |=(1<<6);		
	
	//  configuration of G13 (Rouge) et G14 (Verte)
 	int *ptr_GPIOG_MODER =  (int*)0x40021800;
	//int *ptr_GPIOG_OTYPER = (int*)0x40021804;
	int *ptr_GPIOG_OSPEEDR = (int*)0x40021808;
	int *ptr_GPIOG_PUPDR = (int*)0x4002180C;
	
	*ptr_GPIOG_MODER = (*ptr_GPIOG_MODER & 0xC3FFFFFF) | 0x14000000;				// Pin13 et Pin14 General Purpose output mode
	//*ptr_GPIOG_OTYPER = (*ptr_GPIOG_OTYPER & 0xFFFFFFFF) | 0x00000000;		// Inutile car d�j� en mode push-Pull au reset
	*ptr_GPIOG_OSPEEDR = (*ptr_GPIOG_OSPEEDR & 0xC3FFFFFF) | 0x14000000;		// Pin13 & Pin14 medium speed
	*ptr_GPIOG_PUPDR = (*ptr_GPIOG_PUPDR & 0xC3FFFFFF) | 0x28000000;				// Pin13 & Pin14 Pull-Down pour placer � zero au reste	
	
}
/***********************************************************************/
//********* INITIALISATION DE TIMER2 *********************************/

/********************************************************/
void Init_Timer4(void)    // chennillard
{ 

	 // enable Timer4 clock
	 RCC->APB1ENR |=0x00000004;
	 
	 // Configuration  du Timer4
	
	



	// priorit� 64
	
	// Autorisation interruption
	
		TIM4->SR &= ~1;  // acqutement interruption

}
	



/***************************************************************************/

void Init_Encodeur(void)
{
	 //Activation du Port G
	  
	// Configuration EXTI2 G2 front montant (PG2) (entree A de l'encodeur)
	
    // Activation de l'horloge du System_config EXTI
	
	// Configuration PG2 (Signal A fron descendant)
	
	
	
    // ExTI2 from PG2 
	
	
		
     // Fronts Descendant 

	 // Autorisation des interruptions des EXTI
	
   

	// Configuration  de PG3 sans interruption (entree B de l'encodeur)



	// Configuration  de PE3 EXTI3  (Bouton de l'encodeur)

    //Activation du Port E
	
	// ExTI3 from PE3
	
	
		
   	// Autorisation des interruptions des EXTI3
	
   

}


/**********************ININTIALISATION TIMER 3 *************************/
void Init_Timer3(void)  // base de temps
{ 

	//  enable Timer3 clock
	
	// Configuration Timer3


	// priorit� 16
	
}
/****************** Initialisation bouton Bleu *******************************************************/

void Init_Bouton(void)  // bouton Bleu
{
	// Activation Port A
	
	// Configuration PA0 
	
	// Configuration EXTI0 PA0 
	
	 // Activation de l'horloge du System_config EXTI
	 
	 // ExTI0 fron PA0
		
   	// Autorisation des interruptions des EXTI
	
  
}
/*************************************************************************/


void Init_buzzer(void)
{
// Activation horloge Port C  

// Configuration (PC13)

	
}
/**********************INITIALISATION TIMER 2 *************************/
// configuration of Timer2
void Init_timer2(void)
{

		// enable timer2 clock
	

	// Configuration TIM2
  
	 

	
}


