/*==========================================================================================================*/
/*                                     Глобальные переменные программы                                      */
/*==========================================================================================================*/
#ifndef _variables_h_
#define _variables_h_

unsigned char count;               
volatile unsigned char count_bod;  // счетчик БОД
volatile unsigned char t_led_on;   // 0.2 сек
unsigned char R[68];               // массив 17-и 4-х байтовых команд
unsigned char StartControl[3];
unsigned char StartTesting[3];
unsigned char StopControl[3];
unsigned char StopTesting[3];

#endif