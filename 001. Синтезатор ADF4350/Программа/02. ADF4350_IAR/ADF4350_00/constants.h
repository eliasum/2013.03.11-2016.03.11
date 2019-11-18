/*==========================================================================================================*/
/*                                     ���������� ��������� ���������                                       */
/*==========================================================================================================*/
#ifndef _constants_h_
#define _constants_h_

#define F_CPU 16000000
#define F_CPU_kHz (unsigned long)(F_CPU/1000)

#define delay_ns(x) __delay_cycles(x*F_CPU_kHz*0.000001)
#define delay_us(x) __delay_cycles(x*(F_CPU/1000000))
#define delay_ms(x) __delay_cycles(x*(F_CPU/1000))
#define delay_s(x)  __delay_cycles(x*F_CPU)

#define BR2K4          2400  // �������� ������ 2400
#define UBBR_2K4      (unsigned int)((F_CPU/(16L*BR2K4))-1)
#define UBBR_2K4L     (unsigned char)(UBBR_2K4&0x0FF)
#define UBBR_2K4H     (unsigned char)((UBBR_2K4>>8)&0x0FF)

#define BR9K6          9600  // �������� ������ 9600
#define UBBR_9K6      (unsigned int)((F_CPU/(16L*BR9K6))-1)
#define UBBR_9K6L     (unsigned char)(UBBR_9K6&0x0FF)
#define UBBR_9K6H     (unsigned char)((UBBR_9K6>>8)&0x0FF)

#define SYSTEM_TICK  600                   // ������� ������������ �������0 � ��
#define T_LED_ON     (SYSTEM_TICK/5)       // ����� ��������� ��������� � ����������
#define START_TIM0   0x04                  // ��������������� �������� F_CPU/256
#define RELOAD_TIM0  0x98                  // ��������� ������������ 'TIM0' 

#define ADF4350      5                     // ������� ����� ����������
/*
������� ������������ �������0, ������������ �������� ������� � �������� ��������� ����������, ���������� 600 ��. 
��� �������� �������� �����������, ������� �������� ������ 2400 ���/�. ��� �������� ������������ �����. ��������� 
����������� ������� ������������ ������� �������� ��������� �������. ����, ��� ������� ���������� (���) ��� ������
���������� �������� ���������� (�.�. ���� 2400 ��), �.�. ���� ������������ �������, ��� ������. ���� �� ������� 
����� ������, �� ����� ������ ��������. 
������� ������������ �������0 SYSTEM_TICK ������� ������ 600 ��.
����������� ������-�������0 ������������� ����� 256 (0xFF) ������ ����������.
����������� ���������������� �������� ������ ������ 256.
������� ��� ���������� F_CPU/256 = 62500 �� ������������ ��������� � �������� (62500 �� / 256) = 244,14 ��.
� ��� ������������ � �������� 600 �� ��������� 62500 �� / 600 = 104 ����� ����������.
������-������� ������ �������� ���� � 256 - 104 = 152 (0x98).
*/
#define CBOD         4                // ��������� ���
#define T_LED_ON     (SYSTEM_TICK/5)  // ����� ��������� ��������� � �������

#define LED_ON       PORTG &= ~(1<<LED)
#define LED_OFF      PORTG |=  (1<<LED)
#define LED_TOGGLE   cpl(PORTB, LED)

#define SetBit(reg, bit)    reg |= (1<<(bit))
#define ClearBit(reg, bit)  reg &= (~(1<<(bit)))

unsigned char const __flash Title[] = "ADF4350 - Wideband Synthesizer with Integrated VCO";

// �������������� ����:
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