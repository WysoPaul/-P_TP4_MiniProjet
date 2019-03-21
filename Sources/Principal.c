//////////////////////////////////////////////////////////////////////////////////////
// ITI_2D_µp_TP4_ChenillardMinuteurCuisine
// Vinuesa Nicolas
// Wysocki Paul
// 2019_TD1_TP2
//////////////////////////////////////////////////////////////////////////////////////


#include "stm32f4xx.h"
#include "stm32f4xx_hal_conf.h"


#include <stdio.h>
#include "SCREEN.h"
#include <string.h>
#include "Init_Peripheriques.h"
#include "Affichage.h"
#include "Affled.h"

void HAL_IncTick(void);
void test0(void);
void tempo (void);



/* declaration des variables globales **************/

  int g_current_time_10ms;
  int  g_reglage_sec;
  int  g_nbTimes;
  int g_reglage_min;
  int  g_mode;
  int g_sec_left_time;
  int g_min_left_time;
  int g_indice;
  int g_freq;
  int i=0;
 //int nTemp=0;
 //  Call of "IncTick" Handler (ne pas avoir l'exeption due à Systick)
void SysTick_Handler(){
	HAL_IncTick();
}
int main(void){
	// initialisation des variables globales
		g_reglage_sec=5;
		g_nbTimes=0;
		g_reglage_min=0;
		g_mode=0;
		g_sec_left_time=0;
		g_min_left_time=0;	
		g_indice=0;
		g_freq=2;
	int nTemp=2;

	
	
	test0();
	
	
	while(1)
	{
		affiche2LEDs(nTemp);
	
	}	
	return 0;
}

void test0(){
	
		// Initialisations des périphéries
	Init_port_leds();
	Init_Timer4();
	int mySysClock=HAL_RCC_GetSysClockFreq();
	int monApb2=HAL_RCC_GetPCLK2Freq();
	
	
}

void tempo(){
	int i;
	int j=8000000;
	int nTemp=2;

	
	for (i=0;i<(nTemp*j);i++)
		i=i+1;
	
	}
	
