

#define g_mode_Reglage_sec 0
#define g_mode_Reglage_min 1
#define g_mode_Decomptage 2
#define g_mode_Alarme 3
#define g_mode_Pause 4



void  TIM4_IRQHandler(void);
void  TIM3_IRQHandler(void);
void  TIM2_IRQHandler(void);
void EXTI0_IRQHandler (void);  // bouton bleu
void EXTI2_IRQHandler (void);  // plus ou moins

void EXTI3_IRQHandler(void);     //select

void Go_to_plus(void);
void Go_to_moins(void);

void Go_to_select(void);





