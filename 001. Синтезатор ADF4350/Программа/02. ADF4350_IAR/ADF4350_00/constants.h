/*==========================================================================================================*/
/*                                     Глобальные константы программы                                       */
/*==========================================================================================================*/
#ifndef _constants_h_
#define _constants_h_

#define F_CPU 16000000
#define F_CPU_kHz (unsigned long)(F_CPU/1000)

#define delay_ns(x) __delay_cycles(x*F_CPU_kHz*0.000001)
#define delay_us(x) __delay_cycles(x*(F_CPU/1000000))
#define delay_ms(x) __delay_cycles(x*(F_CPU/1000))
#define delay_s(x)  __delay_cycles(x*F_CPU)

#define BR2K4          2400  // скорость обмена 2400
#define UBBR_2K4      (unsigned int)((F_CPU/(16L*BR2K4))-1)
#define UBBR_2K4L     (unsigned char)(UBBR_2K4&0x0FF)
#define UBBR_2K4H     (unsigned char)((UBBR_2K4>>8)&0x0FF)

#define BR9K6          9600  // скорость обмена 9600
#define UBBR_9K6      (unsigned int)((F_CPU/(16L*BR9K6))-1)
#define UBBR_9K6L     (unsigned char)(UBBR_9K6&0x0FF)
#define UBBR_9K6H     (unsigned char)((UBBR_9K6>>8)&0x0FF)

#define SYSTEM_TICK  600                   // частота переполнения таймера0 в Гц
#define T_LED_ON     (SYSTEM_TICK/5)       // время индикации обращения к устройству
#define START_TIM0   0x04                  // предварительный делитель F_CPU/256
#define RELOAD_TIM0  0x98                  // константа перезагрузки 'TIM0' 

#define ADF4350      5                     // базовый адрес устройства
/*
Частота переполнения таймера0, определяющая точность задания и контроля временных интервалов, составляет 600 Гц. 
Эта величина является оптимальной, кратной скорости обмена 2400 бит/с. Она получена эмпирическим путем. Границами 
определения частоты переполнения таймера являются следующие условия. Чаще, чем единица информации (бит) нет смысла
опрашивать источник информации (т.е. выше 2400 Гц), т.к. выше потребляемая энергия, КПД падает. Если же частота 
будет низкой, то будет низкая точность. 
Частота переполнения таймера0 SYSTEM_TICK выбрана равной 600 Гц.
Однобайтный таймер-счеткик0 переполняется через 256 (0xFF) тактов генератора.
Коэффициент предварительного делителя выбран равным 256.
Поэтому для генератора F_CPU/256 = 62500 Гц переполнение возникает с частотой (62500 Гц / 256) = 244,14 Гц.
А для переполнения с частотой 600 Гц небходимо 62500 Гц / 600 = 104 такта генератора.
Таймер-счетчик толжен начинать счет с 256 - 104 = 152 (0x98).
*/
#define CBOD         4                // константа БОД
#define T_LED_ON     (SYSTEM_TICK/5)  // время индикации обращения к датчику

#define LED_ON       PORTG &= ~(1<<LED)
#define LED_OFF      PORTG |=  (1<<LED)
#define LED_TOGGLE   cpl(PORTB, LED)

#define SetBit(reg, bit)    reg |= (1<<(bit))
#define ClearBit(reg, bit)  reg &= (~(1<<(bit)))

unsigned char const __flash Title[] = "ADF4350 - Wideband Synthesizer with Integrated VCO";

// Инвертирование бита:
#ifndef cpl
#define cpl(sfr, bit) \
  if(sfr & (1<<bit))  \
  {                   \
   sfr &= ~(1<<bit);  \
  }                   \
  else                \
  {                   \
    sfr |= (1<<bit);  \
  }
#endif // cpl

#endif