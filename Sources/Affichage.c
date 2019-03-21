//////////////////////////////////////////////////////////////////////////////////////
// ITI_2D_µp_TP4_ChenillardMinuteurCuisine
// Vinuesa Nicolas
// Wysocki Paul
// 2019_TD1_TP2
//////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include "SCREEN_fonts.h"
#include "SCREEN.h"
#include <string.h>
#include "Fonctions_interruption.h"
#include "stm32f4xx.h"


extern unsigned short int SCREEN_Font11x18 [] ;
extern SCREEN_FontDef_t SCREEN_FormatFont_11x18;


/****************  Importation Variables Globales Externes *********************/

 extern int g_sec_left_time;
 extern int g_min_left_time;
 extern int g_reglage_sec;
 extern int g_reglage_min;
 
 extern int g_mode;

 extern  int g_freq ;
	
/*************************************************************************/
void Affiche_Menu(void)
{
	// /*********************  Chaines de caracteres pour le menu ********************************************/
	SCREEN_Rotate(SCREEN_Orientation_Landscape_1);
	SCREEN_Fill(SCREEN_COLOR_BLUE);
  SCREEN_Puts(5,0,"Nom1 -  Nom2",&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLUE);
	
		
	SCREEN_Puts(5,60,"Bouton Encodeur:",&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLACK);
				
	SCREEN_Puts(5,80,"Sel Min/Start/Pause/stop",&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLUE);
	
 
}

/*************************************************************************/

void Affiche_temps_reglage(void)
	{ 
		char  t[2];
						SCREEN_Puts(5,100,"Reglage :",&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLACK);
		
		SCREEN_Puts(5,120,"Min :",&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLUE);
		sprintf(  t,"%d", g_reglage_min);
		SCREEN_Puts(70,120,"  ",&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLUE);
	  SCREEN_Puts(70,120,t,&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLUE);
		
		
		SCREEN_Puts(5,140,"Sec :",&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLUE);
		sprintf(  t,"%d", g_reglage_sec);
		SCREEN_Puts(70,140,"  ",&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLUE);
		SCREEN_Puts(70,140,t,&SCREEN_FormatFont_11x18,
	  	  		SCREEN_COLOR_WHITE,SCREEN_COLOR_BLUE);
		
	}
	
/*************************************************************************/

void	Affiche_Mode(void )
{
	
	
}

/*************************************************************************/
void Affiche_Temps_restant(void)
{
	
}
// *******   Affichage de la frequence du chenillard  *********
	void Affichage_frequence (void)
	{
		unsigned	  char  t[2];
		 
		
			
		
		
		
	
	}
/*************************************************************************/
