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
	ptr_RCC_AHB1ENR = (int*)0x40023830;						// Adresse début régistre  CTRL 0x40023000 + offset=0x30
	*ptr_RCC_AHB1ENR |=(1<<6);		
	
	//  configuration of G13 (Rouge) et G14 (Verte)
 	int *ptr_GPIOG_MODER =  (int*)0x40021800;
	//int *ptr_GPIOG_OTYPER = (int*)0x40021804;
	int *ptr_GPIOG_OSPEEDR = (int*)0x40021808;
	int *ptr_GPIOG_PUPDR = (int*)0x4002180C;
	
	*ptr_GPIOG_MODER = (*ptr_GPIOG_MODER & 0xC3FFFFFF) | 0x14000000;				// Pin13 et Pin14 General Purpose output mode
	//*ptr_GPIOG_OTYPER = (*ptr_GPIOG_OTYPER & 0xFFFFFFFF) | 0x00000000;		// Inutile car déjà en mode push-Pull au reset
	*ptr_GPIOG_OSPEEDR = (*ptr_GPIOG_OSPEEDR & 0xC3FFFFFF) | 0x14000000;		// Pin13 & Pin14 medium speed
	*ptr_GPIOG_PUPDR = (*ptr_GPIOG_PUPDR & 0xC3FFFFFF) | 0x28000000;				// Pin13 & Pin14 Pull-Down pour placer à zero au reste	
	
}
/***********************************************************************/
//********* INITIALISATION DE TIMER4 *********************************/

/********************************************************/
void Init_Timer4(void)    // chennillard
{ 

	 // enable Timer4 clock
	 RCC->APB1ENR |=0x00000004;
	 
	//
	// Configuration  du Timer4
		
	//CEN=1, CKD=00, ARPE=1, CMS=00, DIR=0, OPM=0, URS=1, UDIS=0
	TIM4->CR1 = (TIM4->CR1 & 0xFFFFFC00) | 0x00000095;					//xxxxxxx xxxxxxxx ------00 10010101
	
	TIM4->PSC = (TIM4->PSC & 0xFFFF0000) | 0x00000007;				//Diviseur de fréquence par 7+1 = 8
	TIM4->ARR = (TIM4->ARR & 0xFFFF0000) | 0x000003E7;				//Compter de 0 à 9999 soit 1000 coup
	TIM4->DIER =  (TIM4->DIER & 0xFFFFFFFE) | 0x00000001;			//UIE=1 Update Interupt Enable

	//
	//Configuration du NVIC

	// priorité 64 (ou 128 fct du sujet de TP)
	//NVIC->IP[7] = (NVIC->IP[7] & 0xFF0FFFFF)| 0x00400000;			//IT=30, 30/4 = 7, 30%4 = 2(soit 3ème! position), Priorité 64 = 0x40, 128 = 0x80
	//NVIC->IP[7] |= 0x00400000;    <=== C'est pas 7 mais directement 30!!!, le calcul ci-dessus sert à rien :-[]  *#&t@*%
	NVIC->IP[30] = (NVIC->IP[30] & 0x0F)| 0x40;
	
	// Autorisation interruption #30 (cablé au TIMER4)
	NVIC->ISER[0] |= 0x40000000;						//IT=30, 30/32(!)=0, 30%32(!)=30
	
	TIM4->SR &= ~1;  // acquitement interruption
	// Acquitement de l'interruption au niv du NVIC
	//NVIC->ICPR[0] |= 0x40000000; ...Semble pas avoi d'effet ... (ou peut-être parce que trop rapide ...

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


	// priorité 16
	
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


