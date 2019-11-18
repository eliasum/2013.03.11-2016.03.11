//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "About.h"
#include "Register1Settings.h"
#include "Register2Settings.h"
#include "Register3Settings.h"
#include "Register4Settings.h"
#include "Register5Settings.h"
#include "Registers.h"
#include "IFControl.h"

int Reg[7];

int REFin, R, T;         // Reference frequency input, Reference division factor, Reference divide-by-2 bit
int ChS, Fres;           // Channel Spacing, Channel resolution
double Fpfd, D, OD;      // PFD frequency, RF REFin doubler bit, Output Devider
double Fvco, Fout;       // Output frequency, VCO Frequency
double INTE, FRAC, MOD;  // Integer division factor,  Fractionality, Modulus
double N, Phase;         // INT+FRAC/MOD, Phase

int Prescaler;
int Counter_Reset;
int Three_State;
int Power_Down;
int Polarity;
int LDP;
int LDF;
int Current_setting;
int Double_Buff;
int MUXout;
int Noise_Mode;
int CLK_DIV;
int CLK_DIV_MODE;
int Cycle_Slip_Reduction;
int RF_Output;
int AUX_Output;
int AUX_Select;
int MTLD;
int VCO_Power_Down;
double BSCD;
double Divider_Select;
int Feedback_Select;
int LD_Pin_Mode;
unsigned char B;  // ������� 0...255

extern AnsiString Int_To_StrBin (int A); // ���������� ��������� �������
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CommPort"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
void __fastcall TForm1::Ndevider(void)  // ���������� INT, FRAC � MOD:
{
  Fvco_OD();

  double Inv, n;
  Inv=1/Fpfd;            // ��������, �������� Fpfd ��� ����� ������� ����� N
  N=Fvco*Inv;

  MOD=(REFin*1000)/Fres; //*1000, �.�. REFin [kHz]
  /*
  ������� modf(N, &n) ��������� ����� (INTE) � ������� (FRAC/MOD) ����� �������� ��������� N �� ������.
  ����� ����� 'n' �� ������ ������������ � ptr. ������� ����� �� ������ - ������������ ��������.
  */
  FRAC=modf(N, &n)*MOD;  // ��� FRAC=(N-INTE)*MOD
  FRAC=floor(FRAC+0.5);  // ���������� �� ���������� ������ ��������������(��� �������������� ceil(x-0.5))
  INTE=n;                // ��� INTE=(int)N

  int i;
  for(i=1; i<1000; i++)  // ��������� �����
  {
    if(((int)FRAC%i==0)&&((int)MOD%i==0)&&((int)FRAC!=0)) // ���� ��������� � ����������� ������������ ������� �� ����� i ��� �������
    {
      FRAC/=i;
      MOD/=i;
    }
  }
  Label7->Caption="INT = "+FloatToStr(INTE);
  Label8->Caption="FRAC = "+FloatToStr(FRAC);
  Label9->Caption="MOD = "+FloatToStr(MOD);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateRegister0(void)  // ���������� �������� Register 0
{
  int shift_FRAC=0;
  int shift_INT=0;

  Reg[0] &= ~0x7FFFFFF8;           // ������� ���������� �������� Register 0

  shift_FRAC=(int)FRAC&0xFFE;      // FRAC max = 4094
  shift_FRAC*=0x8;
  shift_INT=(int)INTE&0xFFFF;      // INT max = 65535
  shift_INT*=0x8000;

  Reg[0] |= shift_FRAC|shift_INT;  // ������� ����� �������� INT � FRAC

  Form9->UpdateCanvas(Reg[0], Reg[1], Reg[2],  Reg[3], Reg[4], Reg[5], Reg[6]);  // �������� �����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateRegister1(void)  // ���������� �������� Register 1
{
  int shift_MOD=0;
  int shift_Phase=0;
  int shift_Prescaler=0;

  Phase=StrToFloat(Form4->Edit1->Text);

  if(OD!=1)  // ������� Prescaler
  {
    Label3->Caption="Prescaler = 8/9";
    Prescaler=1;
  }
  else
  {
    Label3->Caption="Prescaler = 4/5";
    Prescaler=0;
  }

  Reg[1] &= ~0xFFFFFFF8;  // ������� ���������� �������� Register 1

  shift_MOD=(int)MOD&0xFFF;                         // MOD max = 4095
  shift_MOD*=0x08;
  shift_Phase=(int)Phase&0xFFF;                     // Phase max = 4095
  shift_Phase*=0x8000;
  shift_Prescaler=Prescaler&0x01;                   // Prescaler max = 1
  shift_Prescaler*=0x8000000;

  Reg[1] |= shift_MOD|shift_Phase|shift_Prescaler;  // ������� ����� ��������

  Form9->UpdateCanvas(Reg[0], Reg[1], Reg[2],  Reg[3], Reg[4], Reg[5], Reg[6]);  // �������� �����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateRegister2(void)  // ���������� �������� Register 2
{
  int shift_Counter_Reset=0;
  int shift_Three_State=0;
  int shift_Power_Down=0;
  int shift_Polarity=0;
  int shift_LDP=0;
  int shift_LDF=0;
  int shift_Current_setting=0;
  int shift_Double_Buff=0;
  int shift_R=0;
  int shift_T=0;
  int shift_D=0;
  int shift_MUXout=0;
  int shift_Noise_Mode=0;

  // ������� CP Three-State:
  if(Form5->ComboBox4->ItemIndex==0) Three_State=0;
  else                               Three_State=1;

  // ������� CP Polarity:
  if(Form5->ComboBox3->ItemIndex==0) Polarity=0;
  else                               Polarity=1;

  // ������� LDP:
  if(Form5->ComboBox2->ItemIndex==0) LDP=0;
  else                               LDP=1;

  // ������� LDF:
  if(Form5->ComboBox1->ItemIndex==0) LDF=0;
  else                               LDF=1;

  // ������� Current setting:
  for(int i=0; i<16; i++)
  {
    if(ComboBox2->ItemIndex==i) Current_setting=i;
  }

  // ������� MUXout:
  for(int i=0; i<8; i++)
  {
    if(ComboBox5->ItemIndex==i) MUXout=i;
  }

  Reg[2] &= ~0xFFFFFFF8;  // ������� ���������� �������� Register 2

  shift_Counter_Reset=Counter_Reset&0x01;      // Prescaler max = 1
  shift_Counter_Reset*=0x08;
  shift_Three_State=Three_State&0x01;          // Three State max = 1
  shift_Three_State*=0x10;
  shift_Power_Down=Power_Down&0x01;            // Power Down max = 1
  shift_Power_Down*=0x20;
  shift_Polarity=Polarity&0x01;                // Polarity max = 1
  shift_Polarity*=0x40;
  shift_LDP=LDP&0x01;                          // LDP max = 1
  shift_LDP*=0x80;
  shift_LDF=LDF&0x01;                          // LDF max = 1
  shift_LDF*=0x100;
  shift_Current_setting=Current_setting&0x0F;  // Current setting max = 15
  shift_Current_setting*=0x200;
  shift_Double_Buff=Double_Buff&0x01;          // Double Buff max = 1
  shift_Double_Buff*=0x2000;
  shift_R=R&0x3FF;                             // R max = 1023
  shift_R*=0x4000;
  shift_T=T&0x01;                              // T max = 1
  shift_T*=0x1000000;
  shift_D=(int)D&0x01;                         // D max = 1
  shift_D*=0x2000000;
  shift_MUXout=MUXout&0x07;                    // MUX out max = 7
  shift_MUXout*=0x4000000;
  shift_Noise_Mode=Noise_Mode&0x03;            // Noise Mode max = 3
  shift_Noise_Mode*=0x20000000;

  Reg[2] |= shift_Counter_Reset|shift_Three_State|shift_Power_Down|shift_Polarity
  |shift_LDP|shift_LDF|shift_Current_setting|shift_Double_Buff|shift_R|shift_T
  |shift_D|shift_MUXout|shift_Noise_Mode;      // ������� ����� ��������

  Form9->UpdateCanvas(Reg[0], Reg[1], Reg[2],  Reg[3], Reg[4], Reg[5], Reg[6]);  // �������� �����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateRegister3(void)  // ���������� �������� Register 3
{
  int shift_CLK_DIV=0;
  int shift_CLK_DIV_MODE=0;
  int shift_Cycle_Slip_Reduction=0;

  Reg[3] &= ~0xFFFFFFF8;  // ������� ���������� �������� Register 3

  shift_CLK_DIV=CLK_DIV&0xFFF;                           // CLK DIV max = 4095
  shift_CLK_DIV*=0x08;
  shift_CLK_DIV_MODE=CLK_DIV_MODE&0x03;                  // CLK DIV MODE max = 3
  shift_CLK_DIV_MODE*=0x8000;
  shift_Cycle_Slip_Reduction=Cycle_Slip_Reduction&0x01;  // Cycle Slip Reduction max = 1
  shift_Cycle_Slip_Reduction*=0x40000;

  Reg[3] |= shift_CLK_DIV|shift_CLK_DIV_MODE|shift_Cycle_Slip_Reduction;  // ������� ����� ��������

  Form9->UpdateCanvas(Reg[0], Reg[1], Reg[2],  Reg[3], Reg[4], Reg[5], Reg[6]);  // �������� �����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateRegister4(void)  // ���������� �������� Register 4
{
  int shift_RF_Output=0;
  int shift_AUX_Output=0;
  int shift_AUX_Select=0;
  int shift_MTLD=0;
  int shift_VCO_Power_Down=0;
  int shift_BSCD=0;
  int shift_Divider_Select=0;
  int shift_Feedback_Select=0;

  // ������� Output:
  if(ComboBox3->ItemIndex==0)   RF_Output=0;
  for(int i=1; i<5; i++)
  {
    if(ComboBox3->ItemIndex==i) RF_Output=(i+3);
  }

  // ������� AUX Output:
  if(ComboBox4->ItemIndex==0)   AUX_Output=0;
  for(int i=1; i<5; i++)
  {
    if(ComboBox4->ItemIndex==i) AUX_Output=(i+3);
  }

  // ������� AUX Select:
  if(Form7-> ComboBox4->ItemIndex==0) AUX_Select=0;
  else                                AUX_Select=1;

  // ������� MTLD:
  if(Form7-> ComboBox3->ItemIndex==0) MTLD=0;
  else                                MTLD=1;

  // ���������� BSCD:
  BSCD=Fpfd*8;
  BSCD=floor(BSCD+0.5);  // ���������� �� ���������� ������ ��������������
  Label11->Caption="Clk Div = "+FloatToStr(BSCD);

  Reg[4] &= ~0xFFFFFFF8;  // ������� ���������� �������� Register 4

  shift_RF_Output=RF_Output&0x07;                   // Output max = 7
  shift_RF_Output*=0x08;
  shift_AUX_Output=AUX_Output&0x07;                 // AUX Output max = 7
  shift_AUX_Output*=0x40;
  shift_AUX_Select=AUX_Select&0x01;                 // AUX Select max = 1
  shift_AUX_Select*=0x200;
  shift_MTLD=MTLD&0x01;                             // MTLD max = 1
  shift_MTLD*=0x400;
  shift_VCO_Power_Down=VCO_Power_Down&0x01;         // VCO Power Down max = 1
  shift_VCO_Power_Down*=0x800;
  shift_BSCD=(int)BSCD&0xFF;                        // BSCD max = 255
  shift_BSCD*=0x1000;
  shift_Divider_Select=(int)Divider_Select&0x07;    // Divider Select max = 7
  shift_Divider_Select*=0x100000;
  shift_Feedback_Select=Feedback_Select&0x01;       // Feedback Select max = 1
  shift_Feedback_Select*=0x800000;

  Reg[4] |= shift_RF_Output|shift_AUX_Output|shift_AUX_Select|shift_MTLD|shift_VCO_Power_Down
  |shift_BSCD|shift_Divider_Select|shift_Feedback_Select;  // ������� ����� ��������

  Form9->UpdateCanvas(Reg[0], Reg[1], Reg[2],  Reg[3], Reg[4], Reg[5], Reg[6]);  // �������� �����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateRegister5(void)  // ���������� �������� Register 5
{
  int shift_LD_Pin_Mode=0;

  Reg[5] &= ~0xFFE7FFF8;  // ������� ���������� �������� Register 5

  shift_LD_Pin_Mode=LD_Pin_Mode&0x03;                        // LD Pin Mode max = 3
  shift_LD_Pin_Mode*=0x400000;

  Reg[5] |= shift_LD_Pin_Mode;                               // ������� ����� ��������

  Form9->UpdateCanvas(Reg[0], Reg[1], Reg[2],  Reg[3], Reg[4], Reg[5], Reg[6]);  // �������� �����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Activatef(AnsiString metka) // �������-���������� 'Activate fx'
{
  Label1->Caption="Output Frequency = "+metka+" MHz";

  if(StrToFloat(metka)>=137.5&&StrToFloat(metka)<=4400) // �������� ���������
  {
    Label15->Caption="";
    Label1->Caption="Output Frequency = "+metka+" MHz";
    Fout=StrToFloat(metka);
  }
  else
  if(StrToFloat(metka)<137.5)
  {
    Label15->Caption="Output frequency range: 137,5 MHz to 4,4 GHz";
    Label1->Caption="Output Frequency = 137,5 MHz";
    Fout=137.5;
  }
  else
  if(StrToFloat(metka)>4400)
  {
    Label15->Caption="Output frequency range: 137,5 MHz to 4,4 GHz";
    Label1->Caption="Output Frequency = 4400 MHz";
    Fout=4400;
  }

  Fvco_OD();          // ���������� Fvco � OD
  Ndevider();         // ���������� INT, FRAC � MOD
  UpdateRegister0();  // ���������� �������� Register 0
  UpdateRegister1();  // ���������� �������� Register 1
  UpdateRegister4();  // ���������� �������� Register 4
}

/*************************************************************************
Function: uart_puthex_nibble()
Purpose:  transmit lower nibble as ASCII-hex to UART
Input:    byte value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TForm1::uart_puthex_nibble(unsigned char b)
 { unsigned char  c = b & 0x0f;
   if (c>9) c += 'A'-10;
   else c += '0';
   CommPort1->PutChar(c);  // ������� ������������� ��� �������
 } /* uart_puthex_nibble */

/*************************************************************************
Function: uart_puthex_byte()
Purpose:  transmit upper and lower nibble as ASCII-hex to UART
Input:    byte value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TForm1::uart_puthex_byte(unsigned char  b)
 { uart_puthex_nibble(b>>4);
   uart_puthex_nibble(b);
 } /* uart_puthex_byte */
//---------------------------------------------------------------------------
void __fastcall TForm1::uart_puthex_4bytes(int n)  // ������� �������� 4-� ��������� ����� �� Serial Input/Output Monitor
{
  uart_puthex_byte((char)(n>>24)&0xFF);  // 3-� ����
  uart_puthex_byte((char)(n>>16)&0xFF);  // 2-� ����
  uart_puthex_byte((char)(n>>8) &0xFF);  // 1-� ����
  uart_puthex_byte((char) n     &0xFF);  // 0-� ����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::uart_4bytes(int n)  // ������� �������� 4-� ��������� ����� �� ����������
{
  CommPort1->PutChar((char)(n>>24)&0xFF);  // 3-� ����
  CommPort1->PutChar((char)(n>>16)&0xFF);  // 2-� ����
  CommPort1->PutChar((char)(n>>8) &0xFF);  // 1-� ����
  CommPort1->PutChar((char) n     &0xFF);  // 0-� ����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComPortTransmitter(void)
{
  if(CommPort1->BaudRate==cbr9600)       // �������� �� Serial Input/Output Monitor
  {
    if(RB_ADF_filters->Checked==true)     // ���� ������� �������� �� ���������� ��� �������
    {
      for(int i=0; i<6; i++)
      {
        CommPort1->PutString("Register");  // �������� ������ "Register"
        uart_puthex_nibble(i);             // �������� ������� ��������
        CommPort1->PutString(" = 0x");     // �������� ������ " = 0x"
        uart_puthex_4bytes(Reg[i]);        // �������� �������� ��������
        CommPort1->PutChar(0x0d);          // ������� �������
        CommPort1->PutChar(0x0a);          // ������� �� ��������� ������
      }
      CommPort1->PutString("IFControl = 0x");  // �������� ������ "IFControl"
      uart_puthex_4bytes(Reg[6]);              // �������� �������� ��������
      CommPort1->PutChar(0x0d);                // ������� �������
      CommPort1->PutChar(0x0a);                // ������� �� ��������� ������
    }
    else                                       // ���� ������� �������� �� || �����
    {
      CommPort1->PutString("IFControl = 0x");  // �������� ������ "IFControl"
      uart_puthex_4bytes(Reg[6]);              // �������� �������� ��������
      CommPort1->PutChar(0x0d);                // ������� �������
      CommPort1->PutChar(0x0a);                // ������� �� ��������� ������
    }
  }
  else                                         // �������� �� ����������, BaudRate=2400
  {
    if(RB_ADF_filters->Checked==true)               // ���� ������� �������� �� ���������� � �������
    {
      CommPort1->PutChar(0xAA);                     // ������ �������� �� ���������� � �������
      for(int i=6; i>=0; i--) uart_4bytes(Reg[i]);  // R6_4, R6_3,...,R6_1,...R0_1
    }
    else                                            // ���� ������� �������� �� || �����
    {
      CommPort1->PutChar(0x55);                     // ������ �������� �� || �����
      for(int i=6; i>=0; i--) uart_4bytes(Reg[i]);  // R6_4, R6_3,...,R6_1,...R0_1
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Fvco_OD(void)
{
  OD=1;
  while(Fout*OD<2200) OD*=2;
  Fvco=Fout*OD;

  Label4->Caption="Output Devider = "+FloatToStr(OD);         // ������ 'Output Devider'
  Label2->Caption="VCO Frequency = "+FloatToStr(Fvco)+" MHz"; // ����� 'VCO Frequency'

  ChS=StrToInt(Edit5->Text); // ������ Channel Spacing
  Fres=ChS*OD;               // ������ channel resolution
  Label5->Caption="VCO Channel Spacing = "+IntToStr(Fres)+" kHz"; // ����� 'VCO Channel Spacing'

  // ������� Divider_Select:
  Divider_Select=log(OD)/log(2);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
  // ��������� �������������:
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A5003C;
  Reg[5]=0x00580005;

  REFin=10;  // Reference frequency input
  D=0;       // RF REFin doubler bit
  T=0;       // Reference divide-by-2 bit
  R=1;       // Reference division factor
  OD=4;      // Output Devider
  ChS=100;   // Channel Spacing
  Fres=400;  // Channel resolution
  Fout=1000; // Output frequency
  Phase=1;   // Phase
  Fvco=4000; // VCO Frequency
  Fpfd=10;   // PFD frequency
  INTE=400;  // Integer division factor
  FRAC=0;    // Fractionality
  MOD=25;    // Modulus
  N=400;     // INT+FRAC/MOD

  Prescaler=0;
  Counter_Reset=0;
  Three_State=0;
  Power_Down=0;
  Polarity=1;
  LDP=1;
  LDF=0;
  Current_setting=7;
  CLK_DIV=150;
  CLK_DIV_MODE=0;
  Cycle_Slip_Reduction=0;
  RF_Output=4;
  AUX_Output=0;
  AUX_Select=0;
  MTLD=0;
  VCO_Power_Down=0;
  BSCD=80;
  Divider_Select=2;
  Feedback_Select=1;
  LD_Pin_Mode=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox6Click(TObject *Sender) // ������� CheckBox6 Fast Lock
{
  if(CheckBox6->Checked==true)              // ���� �������
  {
    Form6->CheckBox1->Checked=false;        // ��������� ����� Resync enable
    Form6->CheckBox1->Enabled=false;        // ��������� ����� Resync enable

    InpCLKDIV=CLK_DIV;                      // ���������� ����������� ��������
    Form2->Edit3->Text=FloatToStr(Fpfd);    // ����������� �������� Fpfd � Edit3 PFD[MHz]
    CLK_DIV=StrToInt(Form2->Edit1->Text);   // ������������� ����� �� Edit1 � CLK DIV VALUE
    CLK_DIV_MODE=1;                         // ����� Fast Lock enable
    Form2->ShowModal();                     // ����� Form2 FastLock � ��������� ����
  }
  else
  {
    Form6->CheckBox1->Enabled=true;         // ��������� ����� Resync enable

    CLK_DIV=InpCLKDIV;                      // �������������� ����������� ��������
    CLK_DIV_MODE=0;                         // ����� Clock Divider off
  }

  UpdateRegister3();                        // ���������� �������� Register 3
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender) // �������������� Edit2 Frequency
{
  if(Form1->Edit2->Text<=1) Form1->Edit2->Text=1;    // ����� �� ����� ���� ������ 1

  if(StrToInt(Edit2->Text)>=10&&StrToFloat(Edit2->Text)<=250) // �������� ���������
  {
    Label15->Caption="";
    Form2->Edit3->Text=Form1->Edit2->Text; // ����������� �������� Edit2 Frequency �� Form1 � Edit3 PFD[MHz] �� Form2
  }
  else
  if(StrToInt(Edit2->Text)<10)
  {
    Label15->Caption="Reference frequency input range: 10 to 250 MHz";
    Form2->Edit3->Text=Form1->Edit2->Text; // ����������� �������� Edit2 Frequency �� Form1 � Edit3 PFD[MHz] �� Form2
  }
  else
  if(StrToInt(Edit2->Text)>250)
  {
    Edit2->Text=250;
    Label15->Caption="Reference frequency input range: 10 to 250 MHz";
    Form2->Edit3->Text=Form1->Edit2->Text; // ����������� �������� Edit2 Frequency �� Form1 � Edit3 PFD[MHz] �� Form2
  }
  double E1, E2, E3;

  E1 = StrToFloat(Form2->Edit1->Text);   // ������������� ����� �� Edit1 Clk Div Value � ������������
  E3 = StrToFloat(Form2->Edit3->Text);   // ������������� ����� �� Edit3 PFD[MHz] � ������������
  E2 = E1/E3;

  Form2->Edit2->Text=FloatToStr(E2);     // ������������� ������������ � ����� Edit2 BW Time Interval [us]

  REFin=StrToInt(Form1->Edit2->Text);    // ������ �������� REFin

  Fpfd=REFin*((1+D)/(R*(1+T)));          // ���������� Fpfd
  Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)+" MHz"; // ������ Fpfd � 'PFD Frequency'

  if(Fpfd>32.0)
  {
    Label15->Caption="PFD frequency must be less than 32 MHz";
    Fpfd=32.0;
    Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)+" MHz"; // ������ Fpfd � 'PFD Frequency'
  }

  if(Fpfd<1) Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)*1000+" kHz"; // 'PFD Frequency' [kHz]

  Ndevider();         // ���������� INT, FRAC � MOD
  UpdateRegister0();  // ���������� �������� Register 0
  UpdateRegister1();  // ���������� �������� Register 1
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StaticText17DblClick(TObject *Sender)
{
  Form3->ShowModal();                    // ����� Form3 About � ��������� ����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
  Form4->ShowModal();                    // ����� Form4 Register 1 Settings � ��������� ����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  Form5->ShowModal();                    // ����� Form5 Register 2 Settings � ��������� ����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
  Form6->ShowModal();                    // ����� Form6 Register 3 Settings � ��������� ����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Form7->ShowModal();                    // ����� Form7 Register 4 Settings � ��������� ����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
  Form8->ShowModal();                    // ����� Form8 Register 5 Settings � ��������� ����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Form9->Show();                         // ����� Form9 Registers
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  F_IFControl->ShowModal();              // ����� ����� IF Control � ��������� ����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender) // ������� �� RadioButton1 'Activate f1'
{
  Activatef(Edit3->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender) // ������� �� RadioButton2 'Activate f2'
{
  Activatef(Edit4->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) // ������� �� Button1 '+'
{
  double E;

  if(RadioButton1->Checked==true)
  {
    E = StrToFloat(Edit3->Text)+0.1;
    Edit3->Text=FloatToStr(E);
  }
  else
  if(RadioButton2->Checked==true)
  {
    E = StrToFloat(Edit4->Text)+0.1;
    Edit4->Text=FloatToStr(E);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) // ������� �� Button2 '-'
{
  double E;

  if(RadioButton1->Checked==true)
  {
    E = StrToFloat(Edit3->Text)-0.1;
    Edit3->Text=FloatToStr(E);
  }
  else
  if(RadioButton2->Checked==true)
  {
    E = StrToFloat(Edit4->Text)-0.1;
    Edit4->Text=FloatToStr(E);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton6Click(TObject *Sender) // ������� �� RadioButton6 'Alternate'
{
  double E = StrToFloat(Edit6->Text);
  Timer1->Interval=E; // ��������� ������� (���� Interval=0) � ������� ��������� �������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender) // �� ��������� ������� 1
{
  if(RadioButton6->Checked==true) // ���� ������ RadioButton6 'Alternate'
  {
    /*
    ��� static ������������ ��� �������� ����������, ������� ���� � �������, ����������
    ��� ��������. �.�. �� ������� ���������, � ������� �� ���������� ����������, ����������
    ����� ���������, �.�. ��������� ��� � ��������� ����������. �� � ������� �� ���������
    ����������, ������� ������������ ��� ������ �� �������, ���������� static ���������
    ���� ��������, � ��� �������� ����� ������������ ��� ����� ����� � �������, �.�.
    � ���� ������ ���������� static ����� ���� ��� ����������.
    */
    static char A=0; // ���� ������������ �������� ������
    Timer1->Enabled; // ������������ �������

    // ������������ ����� ������������ �������� ������
    A++;
    if(A > 1) A = 0;

    // ������������ �������� ������:
    if(A == 0)
    {
      Label1->Caption="Output Frequency = "+Edit3->Text+" MHz";
      Fout=StrToFloat(Edit3->Text);
    }
    if(A == 1)
    {
      Label1->Caption="Output Frequency = "+Edit4->Text+" MHz";
      Fout=StrToFloat(Edit4->Text);
    }
  }
  else
  if(RadioButton7->Checked==true) // ���� ������ RadioButton7 'Sweep'
  {
    double E3, E4, CS;
    E3 = StrToFloat(Edit3->Text);
    E4 = StrToFloat(Edit4->Text);
    CS = StrToFloat(Edit5->Text)*0.001; // Channel Spacing [MHz]
    static double f=E3;                 // ��������� �������� Output Frequency

    Timer1->Enabled;                    // ������������ �������

    // ���������� �������� ������:
    Label1->Caption="Output Frequency = "+FloatToStr(f+=CS)+" MHz";
    Fout=f;

    if(f >= E4) f = E3;
  }

  Fvco_OD();          // ���������� Fvco � OD
  Ndevider();         // ���������� INT, FRAC � MOD
  UpdateRegister0();  // ���������� �������� Register 0
  UpdateRegister1();  // ���������� �������� Register 1
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Change(TObject *Sender) // ��������� Edit6
{
  double E = StrToFloat(Edit6->Text);
  Timer1->Interval=E; // ������� ��������� �������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton7Click(TObject *Sender) // ������� �� RadioButton7 'Sweep'
{
  double E = StrToFloat(Edit6->Text);
  Timer1->Interval=E; // ��������� ������� (���� Interval=0) � ������� ��������� �������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)       // ��������� Edit3 'Activate f1'
{
  if(Edit3->Text<=1)              Edit3->Text=1;           // ����� �� ����� ���� ������ 1
  if(RadioButton1->Checked==true) Activatef(Edit3->Text);  // ���� �������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject *Sender)       // ��������� Edit4 'Activate f2'
{
  if(Edit4->Text<=1)              Edit4->Text=1;           // ����� �� ����� ���� ������ 1
  if(RadioButton2->Checked==true) Activatef(Edit4->Text);  // ���� �������
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox1Change(TObject *Sender) // ��������� ComboBox1
{
  if(ComboBox1->Text=="/2")
  {
    T=1;
    D=0;
  }
  else
  if(ComboBox1->Text=="x2")
  {
    T=0;
    D=1;
  }
  else
  if(ComboBox1->Text=="1")
  {
    T=0;
    D=0;
  }

  Fpfd=REFin*((1+D)/(R*(1+T))); // ���������� Fpfd
  Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)+" MHz"; // ������ Fpfd � 'PFD Frequency'

  if(Fpfd>32.0)
  {
    Label15->Caption="PFD frequency must be less than 32 MHz";
    Fpfd=32.0;
    Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)+" MHz"; // ������ Fpfd � 'PFD Frequency'
  }

  if(Fpfd<1) Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)*1000+" kHz"; // 'PFD Frequency' [kHz]

  Ndevider();         // ���������� INT, FRAC � MOD
  UpdateRegister0();  // ���������� �������� Register 0
  UpdateRegister1();  // ���������� �������� Register 1
  UpdateRegister2();  // ���������� �������� Register 2
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender) // ��������� Edit1
{
  if(Form1->Edit1->Text<=1) Form1->Edit1->Text=1;    // ����� �� ����� ���� ������ 1

  if(StrToInt(Edit1->Text)>=1&&StrToFloat(Edit1->Text)<=1023)   // �������� ���������
  {
    Label15->Caption="";
    Label10->Caption="R = "+Edit1->Text;
    R=StrToInt(Edit1->Text);
  }
  else
  if(StrToInt(Edit1->Text)>1023)
  {
    Label15->Caption="Reference division factor range: 1 to 1023";
    Label10->Caption="R = 1023";
    R=1023;
  }

  Fpfd=REFin*((1+D)/(R*(1+T))); // ���������� Fpfd
  Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)+" MHz"; // ������ Fpfd � 'PFD Frequency'

  if(Fpfd>32.0)
  {
    Label15->Caption="PFD frequency must be less than 32 MHz";
    Fpfd=32.0;
    Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)+" MHz"; // ������ Fpfd � 'PFD Frequency'
  }

  if(Fpfd<1) Label6->Caption="PFD Frequency = "+FloatToStr(Fpfd)*1000+" kHz"; // 'PFD Frequency' [kHz]

  Ndevider();         // ���������� INT, FRAC � MOD
  UpdateRegister0();  // ���������� �������� Register 0
  UpdateRegister1();  // ���������� �������� Register 1
  UpdateRegister2();  // ���������� �������� Register 2
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit5Change(TObject *Sender) // ��������� Edit5 'Channel Spacing'
{
  if(Form1->Edit5->Text<=1) Form1->Edit5->Text=1;    // ����� �� ����� ���� ������ 1

  Fvco_OD();          // ���������� Fvco � OD
  Ndevider();         // ���������� INT, FRAC � MOD
  UpdateRegister0();  // ���������� �������� Register 0
  UpdateRegister1();  // ���������� �������� Register 1
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
  UpdateRegister2();  // ���������� �������� Register 2
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox5Change(TObject *Sender)
{
  UpdateRegister2();  // ���������� �������� Register 2  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)  // Low Spur Mode
{
  Noise_Mode=3;
  UpdateRegister2();  // ���������� �������� Register 2
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)  // Low Noise Mode
{
  Noise_Mode=0;
  UpdateRegister2();  // ���������� �������� Register 2
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
  if(CheckBox3->Checked==true) Cycle_Slip_Reduction=1;
  else                         Cycle_Slip_Reduction=0;

  UpdateRegister3();  // ���������� �������� Register 3
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox3Change(TObject *Sender)
{
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox4Change(TObject *Sender)
{
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)  // �� ��������� ������� 2
{
  B++;
  PB_proc->Position = 0x7F&B;  // 127 - max

  ComPortTransmitter();        // �������� ������ �� com �����
/*
    ����� �� �������� ������ ����� ���������� � 7 ��������� T��� = V���*N���*N���� =
    = (1/2400 ���/�)*(11 ��� = 1�����+8+1����+1����)*(7 ���������*4����) = 128,3 ��.
    ������������� ������� �������� ������� 2 = 150 ��, ����� ����� ����� �������
    ������������ ���������� ���� 150 - 128,3 = 21,7 ��.

    start|1|2|3|4|5|6|7|8|parity|stop1 ����� �������, ������������� �� ���������� RS-232
*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CB_ComNumChange(TObject *Sender)  // ��������� ������ com �����
{
  CommPort1->ComNumber = CB_ComNum->ItemIndex+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) // �������� �����
{
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CB_BaudRateChange(TObject *Sender)
{
  switch(CB_BaudRate->ItemIndex)
  {
    case 0:
    CommPort1->BaudRate=cbr2400;
    SendDirect->Caption="Send direction: to Synthesizer";
    break;

    case 1:
    CommPort1->BaudRate=cbr9600;
    SendDirect->Caption="Send direction: to Terminal";
    break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CommPort1Open(TObject *Sender, int Error)  // com ���� �������
{
  B_Open->Caption="STOP";              // ������������ ��������� ������ �� 'STOP'
  B=0;                                 // �������� �������
  PB_proc->Position=B;                 // ������� ������������ = 0
  if(RadioButton5->Checked==false)     // ���� ������� Alternate ��� Sweep
  {
    Timer2->Enabled=true;              // ��������� Timer2
  }
  else                                 // ���� ������� Stop
  {
    if(RB_ADF_filters->Checked==true)  // ���� ������� �������� �� ���������� ��� �������
    {
      ComPortTransmitter();            // �������� ������ �� com �����
      Timer3->Enabled=true;            // ��������� Timer3
    }
    else                               // ���� ������� �������� �� || �����
    {
      Timer2->Enabled=true;            // ��������� Timer2
    }
  }
  B_Open->Color=clBtnFace;             // �������� ���� ������
  CB_ComNum->Enabled=false;            // ��������� ��������� ������ com �����
  CB_BaudRate->Enabled=false;          // ��������� ��������� �������� ������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CommPort1Close(TObject *Sender)  // com ���� �������
{
  B_Open->Caption="START";           // ������������ ��������� ������ �� 'START'
  B=0;                               // �������� �������
  PB_proc->Position=B;               // ������� ������������ = 0
  Timer2->Enabled=false;             // ��������� Timer2
  Timer3->Enabled=false;             // ��������� Timer3
  B_Open->Color=(TColor)0x00817DFF;  // �������� ���� ������
  CB_ComNum->Enabled=true;           // �������� ��������� ������ com �����
  CB_BaudRate->Enabled=true;         // �������� ��������� �������� ������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_OpenMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)  // ������ ������ START/STOP
{
  B_Open->BevelInner=bvLowered;  // ���������� ���������� ����� ������
  B_Open->BevelOuter=bvLowered;  // ���������� ������� ����� ������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_OpenMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)  // �������� ������ START/STOP
{
  B_Open->BevelInner=bvRaised;   // ��������� ���������� ����� ������
  B_Open->BevelOuter=bvRaised;   // ��������� ������� ����� ������

  if(B_Open->Caption == "START") CommPort1->Open=true;   // ���� ���� 'START', ����� ������� com ����
  else                           CommPort1->Open=false;  // ���� ���� 'STOP', ����� ������� com ����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
  if(RB_ADF_filters->Checked==true)  // ���� ������� �������� �� ���������� ��� �������
    {
      ComPortTransmitter();          // �������� ������ �� com �����
      Timer3->Enabled=true;          // ��������� Timer3
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RB_ADF_filtersClick(TObject *Sender)
{ 
  CommPort1->Open=false;
  Timer2->Enabled=false;             // ��������� Timer2
  RadioButton6->Enabled=true;
  RadioButton7->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RB_Parallel_linesClick(TObject *Sender)
{
  CommPort1->Open=false;
  Timer2->Enabled=false;             // ��������� Timer2
  RadioButton5->Checked=true;
  RadioButton6->Enabled=false;
  RadioButton7->Enabled=false;
}
//---------------------------------------------------------------------------


