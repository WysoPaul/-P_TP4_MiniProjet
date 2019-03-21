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
void tempo (int);
void verifHorloges(void);

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
	
	// Initialisations des périphéries
	Init_port_leds();
	Init_Timer4();
	verifHorloges();
	while(1)
	{
				test0();
	}	
	return 0;
}

void test0(void){
	//affiche2LEDs(5);			//Q8
	
	//Q9
	/*
	int nTemp =0;
	while(nTemp < 5){
			affiche2LEDs(nTemp);
			nTemp += 1;
		}
	*/
}

void tempo (int nTemp){
	//SYSCLOCK tourne à 16MHz, il faut 3 instructions et on pert un (ou deux?!) coup(s) d'horloge du au PipeLine
	unsigned long ui32Temp = (unsigned long)nTemp*16000000/4;
	while(ui32Temp >0){
			ui32Temp--;
	}
	
}

//
void verifHorloges(void){
	int maSysclk = HAL_RCC_GetSysClockFreq();		//0xXXXXXXX => 16MHz => OK
	int maAHB = HAL_RCC_GetHCLKFreq();					//Valeur abérante 0x8004770 => 134.236.016
	int monAPB1 = HAL_RCC_GetPCLK1Freq();				//Valeur abérante 0x8004770 => 134.236.016
	int monAPB2 = HAL_RCC_GetPCLK2Freq();				//Inacessible ?!
	
}