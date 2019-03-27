//////////////////////////////////////////////////////////////////////////////////////
// ITI_2D_µp_TP4_ChenillardMinuteurCuisine
// Vinuesa Nicolas
// Wysocki Paul
// 2019_TD1_TP2
//////////////////////////////////////////////////////////////////////////////////////

#include "stm32F4xx.h"
#include "Fonctions_interruption.h"
#include "Affichage.h"
#include "Affled.h"


// Importation des variables globales
extern int g_current_time_10ms;
extern int g_var_chennillard;
extern int  g_reglage_sec;
extern int  g_nbTimes;
extern int g_reglage_min;
extern int  g_mode;
extern int g_sec_left_time;
extern int g_min_left_time;
extern int g_indice;
extern  int g_freq ;
extern int g_bidon;


/********************************************************************/
// Fonctions qu'on ne doit jamais appeler, 
// c'est le  NVIC qui s'en charge (contrôleur d'interruptions)

void TIM4_IRQHandler(void) 
	{ 
		g_nbTimes++;
		if(2000 == g_nbTimes){
			ToggleLedRed();
			ToggleLedGreen();
			g_nbTimes = 0;
		}

	// Acquitement de l'interruption
		TIM4->SR &= ~1; 

	}
	/***********************************************/
	void EXTI0_IRQHandler (void) //Bouton bleu
	{
		
		
		EXTI->PR |= 0x0001;  // effacement de la demande d'interruption 
	}
	/***********************************************/
		void EXTI2_IRQHandler (void) // Plus ou moins
	{
		
	
			
		EXTI->PR |= 0x0004;  // effacement de la demande d'interruption 
	}
/***********************************************/
		void EXTI3_IRQHandler (void)  // bouton encodeur (select)
	{
		
		
		EXTI->PR |= 0x0008;  // effacement de la demande d'interruption 
	}
/***********************************************/
void TIM3_IRQHandler(void) //Base de temps
	{ 
		
		TIM3->SR &= ~1; // effacement de la demande d'interruption
		
	
	}


/********************************************************************/


void Go_to_plus(void) // 
{
	
	
	
}
/********************************************************************/

void Go_to_moins(void)
{

}

/********************************************************************/

void TIM2_IRQHandler(void)
{
	

	TIM2->SR &= ~1;   // effacement de la demande d'interruption
	
}




