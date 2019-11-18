//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "DataLoader_Main.h"
#include "Error.h"
#include "Aboutbox.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <Registry.hpp>

using namespace std;
/*
iostream � ������������ ���� � ��������, ��������� � ����������� ��� ����������� �����-������
� ����� ���������������� C++. �� ������� � ����������� ���������� C++. �������� ���������� ��
Input/Output Stream (������ �����-������). � ����� C++ � ��� ���������������, �����
���������������� ��, ��� ���������� ��������� �����-������, ������ ����� ������������ ����������
�������. iostream ��������� ������-�������, ��� � stdio.h � ��. iostream ���������� ������� cin,
cout, cerr � clog ��� �������� ���������� � � �� ����������� ������� �����, ������, ������
(��� �����������) � ������ (� ������������) ��������������. ������� ������ �����������
���������� C++, ��� ������� ����� �������� ������ ������������ ������������ ��� � std.
*/
#include <fstream> // �������� �������� �����-������

using namespace std;

static int sec=0;       // ���������� ���������� �������

int Com1[4]={225, 0, 0, 1};
int Com2[4]={226, 0, 1, 1};
int Com6[4]={230, 0, 0, 31};
int Com7[4]={231, 0, 0, 63};
int Com8[4]={232, 0, 7, 142};
int Com9[4]={233, 0, 7, 142};
int Com10[4]={234, 0, 0, 0};
int Com11[4]={235, 0, 0, 0};
int Com12[4]={236, 0, 0, 0};

int Com13[4]={237, 0, 0, 200};   // 00, 00, c8
int Com14[4]={238, 0, 201, 128}; // 00, c9, 80
int Com15[4]={239, 0, 8, 194};   // 00, 08, c2
int Com16[4]={240, 78, 0, 0};    // 4e, 00, 00
int Com17[4]={241, 179, 4, 0};   // b3, 04, 00
int Com18[4]={242, 0, 36, 1};    // 00, 24, 01
int Com19[4]={243, 165, 0, 5};   // a5, 00, 05
int Com20[4]={244, 0, 88, 0};    // 00, 58, 00
/*
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;
*/
int Reg[6];

int REFin, R, T;         // Reference frequency input, Reference division factor, Reference divide-by-2 bit
int ChS, Fres;           // Channel Spacing, Channel resolution
float Fpfd;              // PFD frequency, Output Devider
double Fvco, Fout;       // Output frequency, VCO Frequency
double INTE, FRAC, MOD;  // Integer division factor,  Fractionality, Modulus
double N, Phase;         // INT+FRAC/MOD, Phase

int OD;
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

//  ����������� ����������� ������
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

String FileControl="";
String FileTesting="";

int delay_ms;
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* ��������� ���������� ������������������ ������������� ������� �����, �����
��������������� ��������� �������� ������������ �� ������� */
#pragma link "CommPort"
#pragma resource "*.dfm"  // ��� ����� ���� ������������ ���� .dfm � ��� �� ������, ��� � ��� ������� �����
TMain_Form *Main_Form;    // ���������� ��������� �� ������ ����� Main_Form
TIniFile *Ini;
//---------------------------------------------------------------------------
// ����� ������������ ����� Main_Form
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
  : TForm(Owner)
{
/*
  ExtractFilePath(Application->ExeName) - ���� � ����������� �����.
  GetCurrentDir() - ���� � ������� ����������.
  ��� �� ������� ���������, ������� ������� �������� �� ����������,
  �������  �� ������� ������� ����� � ����� �������� � ��������.
*/
  My_Patch = ExtractFilePath(Application->ExeName); // ���� � ����������� �����

  if(!DirectoryExists(My_Patch + "log �����"))
  {
    if(!CreateDir(My_Patch + "log �����"))
      ShowMessage("�� ������� ������� ���������� �������� log ������!");
    else
      ShowMessage("������� ���������� ��� �������� log ������!");
  }

  if(!DirectoryExists(My_Patch + "����� ������"))
  {
    if(!CreateDir(My_Patch + "����� ������"))
      ShowMessage("�� ������� ������� ���������� �������� ������ ������!");
    else
      ShowMessage("������� ���������� ��� �������� ������ ������!");
  }
/*
  Boolean DirectoryExists(AnsiString DirectoryName);
  ������� DirectoryExists ���������� True, ���� ������ DirectoryName ���� ����������.
  ������� ������������� � ������� ��������. False ����� ���� ����������, ���� ������������ ��
  ��������� ������ ����.

  Boolean CreateDir(AnsiString Dir);
  ������� CreateDir ������ ����� � ������� ����������.
  ���� ����� ���� �������, �� ������� ����� True, ���� ���, �� ������ ����� ���� ��������
  � ������� ������� GetLastError.
*/

  REFin=10;  // Reference frequency input
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

  // ��������� �������������:
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;

  delay_ms=1;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SB_OnOffClick(TObject *Sender)
{
  try
  {
    if(SB_OnOff->Down)         // ���� ������
    {
      SB_OnOff->Caption="���������";
      SB_OnOff->Font->Color=clRed;

      StartTesting();
    }
    else                       // ���� �� ������
    {
      SB_OnOff->Caption="��������";
      SB_OnOff->Font->Color=clGreen;

      StopTesting();
    }
  }

  catch(...)
  {
    SB_OnOff->Down=false;
    SB_OnOff->Caption="��������";
    SB_OnOff->Font->Color=clGreen;
    ButtonsOn();

    WorkTimer->Enabled=false;         // ��������� ������ WorkTimer
    sec=0;                            // �������� �������� ������
    P_WorkTime->Caption = "00:00:00"; // �������� �������� ������� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SystemTimerTimer(TObject *Sender)
// ������ ���������� � ������ ���������� ������� ������ 10 ��
{
/*
  FormatDateTime (s, dt) - ������ ��������, �������������� ����� ���� ��� �����. ������ �������������
  ������ ������ ������� s, ��������, ������ dd/mm/yyyy ������, ��� ��������� ������� �������� ����,
  � ������ hh:mm � �����
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+" "+FormatDateTime("HH:NN:SS",Time()); // ������� ���� � �����
  //P_SystemTime->Caption = Now();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::WorkTimerTimer(TObject *Sender)
// ������ ���������� � ������ �������� ������� ������ 1 �
{
  static int min=0, hour=0; // ���������� ����� � �����
  sec++;                    // ������ 1000 �� ����������� �������� ���������� ������ �� 1

  if(sec>59)                // ������ 60 �
  {
    sec=0;                  // �������� �������� ������
    min++;                  // ����������� �������� ���������� ����� �� 1
  }

  if(min>59)                // ������ 60 �����
  {
    min=0;                  // �������� �������� �����
    hour++;                 // ����������� �������� ���������� ����� �� 1
  }

  // ����� ����� ������, ����� � ����� ������ ��� � �������������� 2-� ��������
  if(sec<10)  L_S->Caption="0"+IntToStr(sec);
  else        L_S->Caption=IntToStr(sec);

  if(min<10)  L_M->Caption="0"+IntToStr(min);
  else        L_M->Caption=IntToStr(min);
  
  if(hour<10) L_H->Caption="0"+IntToStr(hour);
  else        L_H->Caption=IntToStr(hour);

  P_WorkTime->Caption = L_H->Caption+":"+L_M->Caption+":"+L_S->Caption;
  P_WorkTime->Refresh(); // �������� ���������
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  AddSaveLog("��������� �������"); // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormCreate(TObject *Sender)
{
/*
  FormatDateTime (s, dt) - ������ ��������, �������������� ����� ���� ��� �����. ������ �������������
  ������ ������ ������� s, ��������, ������ dd/mm/yyyy ������, ��� ��������� ������� �������� ����,
  � ������ hh:mm � �����
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+"_"+FormatDateTime("HH-NN-SS",Time()); // ������� ���� � �����
  logFname = P_SystemTime->Caption; // ������ ����� ��� ����� � ����� ��� �������� ���������
  AddSaveLog("��������� ��������"); // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::AddSaveLog(AnsiString comment) // �������� ����������� � ��������� ���
{
  My_Patch = ExtractFilePath(Application->ExeName); // ���� � ����������� �����

  if(!DirectoryExists(My_Patch + "log �����"))
  {
    if(!CreateDir(My_Patch + "log �����"))
      ShowMessage("�� ������� ������� ���������� �������� log ������!");
    else
      ShowMessage("������� ���������� ��� �������� log ������!");
  }
/*
  Now()- ��������� ���� � ����� � �������� ���� TDateTime;
  DateTimeToStr(Now()) - ������ ��������, ������������ ���� � ������� dd.mm.yyyy � ����� ������� hh:mm:ss
*/
  M_Log->Lines->Add(DateTimeToStr(Now())+" "+comment); // �������� ������ � ��� � ������� ��������
/*
  ExtractFilePath(Application->ExeName) - ���� � ����������� �����.
  GetCurrentDir() - ���� � ������� ����������.
  ��� �� ������� ���������, ������� ������� �������� �� ����������,
  ������� �� ������� ������� ����� � ����� �������� � ��������.
*/
  M_Log->Lines->SaveToFile(My_Patch+"\\log �����\\"+logFname+".log"); // ������ ��� �����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_EnterClick(TObject *Sender)
{
  if(E_EnterComment->Text!="")
  {
    AddSaveLog(E_EnterComment->Text); // ������ ��� �����
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormShow(TObject *Sender)
{
  if (!DirectoryExists(My_Patch + "log �����"))
  {
    MessageBox(NULL,"���������� ���������� log �����!","������!",MB_OK|MB_ICONERROR);
    Application->Terminate();
  }
}
//---------------------------------------------------------------------------
bool TMain_Form::IsValidInt(int min, int max, String value, String EdIzm)
// �������� ������������ ��������� ��������
{
  int temp;

  try
  {
    temp=StrToInt(value);

    if((temp>max)||(temp<min))
    {
      ShowError(NotInBorders,min,max,EdIzm);
      return false;
    }
  }

  catch(...)
  {
    ShowError(NotInt,0,0,"");
    return false;
  }

  return true;
}
//---------------------------------------------------------------------------
void TMain_Form::ShowError(int ErrorNum, float Par1, float Par2, String Par3)
// ����� ����� ��������� �� ������
{
  switch(ErrorNum)
  {
    case NotInBorders:
      ErrorForm->Visible=true;
      ErrorForm->Caption="������";
      ErrorForm->Panel1->Caption="������ ����� ������. ��������� �������� ��� ����������� ���������.";
      ErrorForm->Panel2->Caption="�������� ������ ������ � ��������� �� "+ FloatToStrF(Par1,ffGeneral,5,2)+" �� "+FloatToStrF(Par2,ffGeneral,5,2)+" "+Par3+".";
      break;

    case NotFloat:
      ErrorForm->Visible=true;
      ErrorForm->Caption="������";
      ErrorForm->Panel1->Caption="������ ����� ������. ��������� �������� �� �������� ������������.";
      ErrorForm->Panel2->Caption="���������� ������� ������������ ��������. ��������, \"-2,2e+3\".";
      break;

    case NotInt:
      ErrorForm->Visible=true;
      ErrorForm->Caption="������";
      ErrorForm->Panel1->Caption="������ ����� ������. ��������� �������� �� �������� �����.";
      ErrorForm->Panel2->Caption="���������� ������� ����� ��������. ��������, \"-25\".";
      break;

    case FileNotExist:
      ErrorForm->Visible=true;
      ErrorForm->Caption="������";
      ErrorForm->Panel1->Caption="���������� ��������� �� ������������ ����. ��� �������� ������ �����";
      ErrorForm->Panel2->Caption="�������������� ��������� \"���������\" � \"��������� ���...\".";
      break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com1Change(TObject *Sender)
{
  for(int i=0; i<3; i++)
  {
    if(CB_Com1->ItemIndex==i) Com1[2]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command3_0KeyPress(TObject *Sender,
      char &Key)
// ������ �������� ����� ��������, ����� ����� 0...9
{
/*
  ����� set ������������ ���������, � ������� �� ����������(� ����� ������)
  ������ ������������� ������������ ��������. ������������ ��� ������� ����� ��������� ���

  template <class Key, class Comp = less<Key>, class Allocator = allocator<Key>> class set

  ����� Key - ��� ������ ������, a Comp - �������, ������� ���������� ��� �����.
  ����� set ����� ��������� ������������.

  explicit set(const Comp &cmpfn = Comp(), const Allocator &a = Allocator));
  set(const set<Key, Comp, Allocator> &ob);
  template  <class InIter> set(InIter start, InIter end,
	const Comp &cmpfn = Comp(), const Allocator &a = Allocator());

  ������ ����� ������������ ������� ������ ���������, ������ ������� ���������,
  ������� �������� �� �� ��������, ��� � ��������� ob. ������ ������� ���������, �������
  �������� �������� � ���������, �������� ����������� start � end. �������, ��������
  ���������� cmpfn(���� ��� ������), ���������� ������������ ���������.

  ��� ������ set ���������� ��������� ��������� ���������: ==, <, <=, !=, > � >=.

  ������ ������, set ������������ ��������� ����������������:
  - �������� ������� � ��������������� ���������, ��� ���� �������� ����������� ��������� ������;
  - ������� ������� �� ���������;
  - ������ ���������� (���������) ��������� � ����������;
  - ���������, ������������ �� � ���������� ��������� �������.
*/
  Set<char,0,255>Dig;
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<8;
	if(!Dig.Contains(Key))
	{
    //Application->MessageBox("� ���� ���������� ������� ������ �����!","��������",MB_ICONWARNING);
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::CB_Com7Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Com7->ItemIndex==i) Com7[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com6Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Com6->ItemIndex==i) Com6[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com8Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    int code;
    if(CB_Com8->ItemIndex==i) code=14+128*i;    // ��������� ���� ���������
    int code_LSB=code&0xFF;                     // ������� ���� ���������
    int code_MSB=(code/256)&0xFF;               // ������� ���� ���������
    Com8[2]=code_MSB;                           // �������� �������� �������� ����� ���������
    Com8[3]=code_LSB;                           // �������� �������� �������� ����� ���������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com9Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    int code;
    if(CB_Com9->ItemIndex==i) code=14+128*i;    // ��������� ���� ���������
    int code_LSB=code&0xFF;                     // ������� ���� ���������
    int code_MSB=(code/256)&0xFF;               // ������� ���� ���������
    Com9[2]=code_MSB;                           // �������� �������� �������� ����� ���������
    Com9[3]=code_LSB;                           // �������� �������� �������� ����� ���������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com10Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Com10->ItemIndex==i) Com10[3]=i;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::CB_Com11Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Com11->ItemIndex==i) Com11[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com12Change(TObject *Sender)
{
  for(int i=0; i<2; i++)
  {
    if(CB_Com12->ItemIndex==i) Com12[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StartTesting()
{
  AddSaveLog("������� ����� ������������");  // �������� ����������� � ��������� ���
  ButtonsOff();
  CommPort1->Open=true;
  ComPortException();

  WorkTimer->Enabled=true;                   // �������� ������ WorkTimer

  if(CommPort1->BaudRate==cbr9600)           // �������� �� Serial Input/Output Monitor
  {
    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com1[i]);
    }
    CommPort1->PutChar(0x0d);              // ������� �������
    CommPort1->PutChar(0x0a);              // ������� �� ��������� ������
  }
  else                                     // �������� �� ����-2, BaudRate=57600
  {
    CommPort1->PutChar(0xCC);              // ������ �������� �� ����������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com1[i]);
    }
  }
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StopTesting()
{
  WorkTimer->Enabled=false;         // ��������� ������ WorkTimer
  sec=0;                            // �������� �������� ������

  AddSaveLog("�������� ����� ������������. ����� ������ ��������� "+P_WorkTime->Caption);  // �������� ����������� � ��������� ���
  
  P_WorkTime->Caption = "00:00:00"; // �������� �������� ������� ������
  
  ButtonsOn();
  CommPort1->Open=true;
  ComPortException();

  if(CommPort1->BaudRate==cbr9600)         // �������� �� Serial Input/Output Monitor
  {
    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com2[i]);
    }
    CommPort1->PutChar(0x0d);              // ������� �������
    CommPort1->PutChar(0x0a);              // ������� �� ��������� ������
  }
  else                                     // �������� �� ����-2, BaudRate=57600
  {
    CommPort1->PutChar(0xEE);            // ������ �������� �� ����������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com2[i]);
    }
  }
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
String TMain_Form::RoundValue(float delta, String value)
{
  float temp;
  float temp1;

  temp=StrToFloat(value);
  temp1=Log10(delta);         // ���������� ������ ����� �������
  value=RoundTo(temp,temp1);  // ��������� �� �������� � 2-�� ����������� ������� ����� �������

  return value;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_SendClick(TObject *Sender)
{
  ComPortTransmitter();
/*
    ����� �� �������� ������ ����� ���������� � 27 ��������� T��� = V���*N���*N���� =
    = (1/57600 ���/�)*(11 ��� = 1�����+8+1����+1����)*(6 ���������*256����+17 ���������*4����)
    = 30,6 ��.

    start|1|2|3|4|5|6|7|8|parity|stop1 ����� �������, ������������� �� ���������� RS-232
*/  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ComPortTransmitter(void)
{
  CommPort1->Open=true;

  if(CommPort1->BaudRate==cbr9600)               // �������� �� Serial Input/Output Monitor
  {
    SendTerminal();
  }
  else                                           // �������� �� ����-2, BaudRate=57600
  {
    CommPort1->PutChar(0xAA);                    // ������ �������� �� ����������

    SendTesting();
  }
  CommPort1->Open=false;
}
/*************************************************************************
Function: uart_puthex_byte()
Purpose:  transmit upper and lower nibble as ASCII-hex to UART
Input:    byte value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TMain_Form::uart_puthex_byte(unsigned char  b)
 { uart_puthex_nibble(b>>4);
   uart_puthex_nibble(b);
 } /* uart_puthex_byte */
/*************************************************************************
Function: uart_puthex_nibble()
Purpose:  transmit lower nibble as ASCII-hex to UART
Input:    byte value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TMain_Form::uart_puthex_nibble(unsigned char b)
 { unsigned char  c = b & 0x0f;
   if (c>9) c += 'A'-10;
   else c += '0';
   CommPort1->PutChar(c);  // ������� ������������� ��� �������
 } /* uart_puthex_nibble */
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChB_LogClick(TObject *Sender)
{
  if(ChB_Log->Checked==true) M_Log->Visible=false;
  else                       M_Log->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_SaveTestingClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ������");  // �������� ����������� � ��������� ���

  SaveDialog->DefaultExt=".load";
  SaveDialog->FileName="*.load";
  SaveDialog->Filter="���� ������ (*.load)|*.load";
  SaveDialog->Title=" ���������� ����� ������";

  String File;
  FILE *F;

  if(SaveDialog->Execute())
  {
    File=SaveDialog->FileName;
    FileControl=File;
    if(F!=NULL)
    {
      F=fopen(File.c_str(),"w+"); // ������� ���� � �����������
      fclose(F);                  // ������� ����
    }
    Ini= new TIniFile(File); // �������� ������ ����� .ini
/*
    Ini->WriteString("�������� ������","��� ����������", "��������");
*/
    Ini->WriteString("����� � ����","����� � ����",P_SystemTime->Caption);
    // Com1
    Ini->WriteString("������","������� \"������ ������\"",IntToStr(Com1[2])); // ������ �� ������� � ����
    // Com6
    Ini->WriteString("������","������� \"����������� ���������� �������� ����-2\"",IntToStr(Com6[3]));   // ������ �� ������� � ����
    // Com7
    Ini->WriteString("������","������� \"����������� ���������� ����������� ����-2\"",IntToStr(Com7[3])); // ������ �� ������� � ����
    // Com8
    int Comm8=Com8[3]+Com8[2]*256;
    Ini->WriteString("������","������� \"������� ����� ������� ���������� �������� ����-2\"",Comm8);  // ������ �� ������� � ����
    // Com9
    int Comm9=Com9[3]+Com9[2]*256;
    Ini->WriteString("������","������� \"������� ����� ������� ���������� ����������� ����-2\"",Comm9);  // ������ �� ������� � ����
    // Com10
    Ini->WriteString("������","������� \"��� ���������� ������� �������������\"",IntToStr(Com10[3])); // ������ �� ������� � ����
    // Com11
    Ini->WriteString("������","������� \"��� ���������� �������� �������������\"",IntToStr(Com11[3])); // ������ �� ������� � ����
    // Com12
    Ini->WriteString("������","������� \"��� ���������� ������ �����������\"",IntToStr(Com12[3])); // ������ �� ������� � ����
    // Com13
    unsigned long int Comm13=Com13[3]+Com13[2]*256+Com13[1]*65536;
    Ini->WriteString("������","������� \"������� �������� ����������� ����� ����-2. ����� 1\"",Comm13); // ������ �� ������� � ����
    // Com14
    unsigned long int Comm14=Com14[3]+Com14[2]*256+Com14[1]*65536;
    Ini->WriteString("������","������� \"������� �������� ����������� ����� ����-2. ����� 2\"",Comm14); // ������ �� ������� � ����
    // Com15
    unsigned long int Comm15=Com15[3]+Com15[2]*256+Com15[1]*65536;
    Ini->WriteString("������","������� \"������� �������� ����������� ����� ����-2. ����� 3\"",Comm15); // ������ �� ������� � ����
    // Com16
    unsigned long int Comm16=Com16[3]+Com16[2]*256+Com16[1]*65536;
    Ini->WriteString("������","������� \"������� �������� ����������� ����� ����-2. ����� 4\"",Comm16); // ������ �� ������� � ����
    // Com17
    unsigned long int Comm17=Com17[3]+Com17[2]*256+Com17[1]*65536;
    Ini->WriteString("������","������� \"������� �������� ����������� ����� ����-2. ����� 5\"",Comm17); // ������ �� ������� � ����
    // Com18
    unsigned long int Comm18=Com18[3]+Com18[2]*256+Com18[1]*65536;
    Ini->WriteString("������","������� \"������� �������� ����������� ����� ����-2. ����� 6\"",Comm18); // ������ �� ������� � ����
    // Com19
    unsigned long int Comm19=Com19[3]+Com19[2]*256+Com19[1]*65536;
    Ini->WriteString("������","������� \"������� �������� ����������� ����� ����-2. ����� 7\"",Comm19); // ������ �� ������� � ����
    // Com20
    unsigned long int Comm20=Com20[3]+Com20[2]*256+Com20[1]*65536;
    Ini->WriteString("������","������� \"������� �������� ����������� ����� ����-2. ����� 8\"",Comm20); // ������ �� ������� � ����

    delete Ini;
  }  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_LoadTestingClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ������");  // �������� ����������� � ��������� ���

  OpenDialog->DefaultExt=".load";
  OpenDialog->FileName="*.load";
  OpenDialog->Filter="���� ������ (*.load)|*.load";
  OpenDialog->Title=" �������� ����� ������";

  String File;

  if(OpenDialog->Execute())
  {
    File=OpenDialog->FileName;
    FileTesting=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("�������� ������","��� ����������", "��������");
*/
      // Com1
      Com1[2]=StrToInt(Ini->ReadString("������","������� \"������ ������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<3; i++)
      {
        if(Com1[2]==i) CB_Com1->ItemIndex=i; // ������ � �����
      }
      // Com6
      Com6[3]=StrToInt(Ini->ReadString("������","������� \"����������� ���������� �������� ����-2\"","0")); // ������� �� ����� � ������
      for(int i=0; i<64; i++)
      {
        if(Com6[3]==63-i) CB_Com6->ItemIndex=i; // ������ � �����
      }
      // Com7
      Com7[3]=StrToInt(Ini->ReadString("������","������� \"����������� ���������� ����������� ����-2\"","0")); // ������� �� ����� � ������
      for(int i=0; i<64; i++)
      {
        if(Com7[3]==63-i) CB_Com7->ItemIndex=i; // ������ � �����
      }
      // Com8
      int Comm8=StrToInt(Ini->ReadString("������","������� \"������� ����� ������� ���������� �������� ����-2\"","0"));      // ������� �� ����� � ������
      Com8[3]=Comm8&0xFF;                       // ��. ����
      Com8[2]=(Comm8/256)&0xFF;                 // ��. ����
      for(int i=0; i<=15; i++)
      {
        if(Comm8==14+i*128) CB_Com8->ItemIndex=i;      // ������ � �����
      }
      // Com9
      int Comm9=StrToInt(Ini->ReadString("������","������� \"������� ����� ������� ���������� �������� ����-2\"","0"));      // ������� �� ����� � ������
      Com9[3]=Comm9&0xFF;                       // ��. ����
      Com9[2]=(Comm9/256)&0xFF;                 // ��. ����
      for(int i=0; i<=15; i++)
      {
        if(Comm9==14+i*128) CB_Com9->ItemIndex=i;      // ������ � �����
      }
      // Com10
      Com10[3]=StrToInt(Ini->ReadString("������","������� \"��� ���������� ������� �������������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<=3; i++)
      {
        if(Com10[3]==i) CB_Com10->ItemIndex=i; // ������ � �����
      }
      // Com11
      Com11[3]=StrToInt(Ini->ReadString("������","������� \"��� ���������� �������� �������������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<=3; i++)
      {
        if(Com11[3]==i) CB_Com11->ItemIndex=i; // ������ � �����
      }
      // Com12
      Com12[3]=StrToInt(Ini->ReadString("������","������� \"��� ���������� ������ �����������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<2; i++)
      {
        if(Com12[3]==i) CB_Com12->ItemIndex=i; // ������ � �����
      }
      // Com13
      unsigned long int Comm13=StrToInt(Ini->ReadString("������","������� \"������� �������� ����������� ����� ����-2. ����� 1\"","0"));      // ������� �� ����� � ������
      Com13[3]=Comm13&0xFF;                    // ��. ����
      Com13[2]=(Comm13/256)&0xFF;              // ��. ����
      Com13[1]=(Comm13/65536)&0xFF;            // ��. ����
      E_Com13_1->Text=IntToStr(Com13[1]);
      E_Com13_2->Text=IntToStr(Com13[2]);
      E_Com13_3->Text=IntToStr(Com13[3]);
      // Com14
      unsigned long int Comm14=StrToInt(Ini->ReadString("������","������� \"������� �������� ����������� ����� ����-2. ����� 2\"","0"));      // ������� �� ����� � ������
      Com14[3]=Comm14&0xFF;                    // ��. ����
      Com14[2]=(Comm14/256)&0xFF;              // ��. ����
      Com14[1]=(Comm14/65536)&0xFF;            // ��. ����
      E_Com14_1->Text=IntToStr(Com14[1]);
      E_Com14_2->Text=IntToStr(Com14[2]);
      E_Com14_3->Text=IntToStr(Com14[3]);
      // Com15
      unsigned long int Comm15=StrToInt(Ini->ReadString("������","������� \"������� �������� ����������� ����� ����-2. ����� 3\"","0"));      // ������� �� ����� � ������
      Com15[3]=Comm15&0xFF;                    // ��. ����
      Com15[2]=(Comm15/256)&0xFF;              // ��. ����
      Com15[1]=(Comm15/65536)&0xFF;            // ��. ����
      E_Com15_1->Text=IntToStr(Com15[1]);
      E_Com15_2->Text=IntToStr(Com15[2]);
      E_Com15_3->Text=IntToStr(Com15[3]);
      // Com16
      unsigned long int Comm16=StrToInt(Ini->ReadString("������","������� \"������� �������� ����������� ����� ����-2. ����� 4\"","0"));      // ������� �� ����� � ������
      Com16[3]=Comm16&0xFF;                    // ��. ����
      Com16[2]=(Comm16/256)&0xFF;              // ��. ����
      Com16[1]=(Comm16/65536)&0xFF;            // ��. ����
      E_Com16_1->Text=IntToStr(Com16[1]);
      E_Com16_2->Text=IntToStr(Com16[2]);
      E_Com16_3->Text=IntToStr(Com16[3]);
      // Com17
      unsigned long int Comm17=StrToInt(Ini->ReadString("������","������� \"������� �������� ����������� ����� ����-2. ����� 5\"","0"));      // ������� �� ����� � ������
      Com17[3]=Comm17&0xFF;                    // ��. ����
      Com17[2]=(Comm17/256)&0xFF;              // ��. ����
      Com17[1]=(Comm17/65536)&0xFF;            // ��. ����
      E_Com17_1->Text=IntToStr(Com17[1]);
      E_Com17_2->Text=IntToStr(Com17[2]);
      E_Com17_3->Text=IntToStr(Com17[3]);
      // Com18
      unsigned long int Comm18=StrToInt(Ini->ReadString("������","������� \"������� �������� ����������� ����� ����-2. ����� 6\"","0"));      // ������� �� ����� � ������
      Com18[3]=Comm18&0xFF;                    // ��. ����
      Com18[2]=(Comm18/256)&0xFF;              // ��. ����
      Com18[1]=(Comm18/65536)&0xFF;            // ��. ����
      E_Com18_1->Text=IntToStr(Com18[1]);
      E_Com18_2->Text=IntToStr(Com18[2]);
      E_Com18_3->Text=IntToStr(Com18[3]);
      // Com19
      unsigned long int Comm19=StrToInt(Ini->ReadString("������","������� \"������� �������� ����������� ����� ����-2. ����� 7\"","0"));      // ������� �� ����� � ������
      Com19[3]=Comm19&0xFF;                    // ��. ����
      Com19[2]=(Comm19/256)&0xFF;              // ��. ����
      Com19[1]=(Comm19/65536)&0xFF;            // ��. ����
      E_Com19_1->Text=IntToStr(Com19[1]);
      E_Com19_2->Text=IntToStr(Com19[2]);
      E_Com19_3->Text=IntToStr(Com19[3]);
      // Com20
      unsigned long int Comm20=StrToInt(Ini->ReadString("������","������� \"������� �������� ����������� ����� ����-2. ����� 8\"","0"));      // ������� �� ����� � ������
      Com20[3]=Comm20&0xFF;                    // ��. ����
      Com20[2]=(Comm20/256)&0xFF;              // ��. ����
      Com20[1]=(Comm20/65536)&0xFF;            // ��. ����
      E_Com20_1->Text=IntToStr(Com20[1]);
      E_Com20_2->Text=IntToStr(Com20[2]);
      E_Com20_3->Text=IntToStr(Com20[3]);

      UpdateAllRegisters();    

      AddSaveLog("�������� ���� "+FileTesting);  // �������� ����������� � ��������� ���

      delete Ini;
    }
    else
    {
      ShowError(FileNotExist, 0, 0, "");
    }
  }  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_AboutClick(TObject *Sender)
{
  AddSaveLog("���������� � ���������, ������ ������ � ������");  // �������� ����������� � ��������� ���
  F_AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_ComNumChange(TObject *Sender) // ��������� ������ com �����
{
  CommPort1->ComNumber = CB_ComNum->ItemIndex+1;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_BaudRateChange(TObject *Sender)
{
  switch(CB_BaudRate->ItemIndex)
  {
    case 0:
    CommPort1->BaudRate=cbr9600;
    L_SendDirect->Caption="����-� ��������: ��������";
    break;

    case 1:
    CommPort1->BaudRate=cbr57600;
    L_SendDirect->Caption="����-� ��������: ����";
    break;
  }
}
/*************************************************************************
Function: uart_puti()
Purpose:  transmit integer as ASCII to UART
Input:    integer value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TMain_Form::uart_puti( signed int val )
 { unsigned char buffer[8];
  
   itoa(val, buffer);
   uart_puts( buffer );
 }/* uart_puti */
 /*************************************************************************
 itoa:  ������������ n � ������� � s
**************************************************************************/
void __fastcall TMain_Form::itoa(signed int n, unsigned char s[])
{
   Bin_to_dec (s, n);
}
/*----------------------------------------------------------------------------*/
/* �������:    �������������� BIN->DEC 's[]'                                  */
/* ���������:  �������� �����                                                 */
/* ����������: ������ (�������� ���������� ����������)                        */
/*----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Bin_to_dec (unsigned char s[],     // �����
                 signed int dnum)       // �������������
{
   s[0] = ((dnum%1000)%100)/10 + '0';   // ����� ����� ��������� ������� ������ ������������ �����
   s[1] = dnum%10 + '0';                // ������� ������
   s[2] = 0;                            // ������ ����� ������
} 
/*************************************************************************
Function: uart_puts()
Purpose:  transmit string to UART
Input:    string to be transmitted
Returns:  none          
**************************************************************************/
void __fastcall TMain_Form::uart_puts(unsigned char *s )
 { while (*s)
      CommPort1->PutChar(*s++);  // ������� ������������� ��� �������
 } /* uart_puts */
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SendTesting(void)
{
  AddSaveLog("�������� ������� � ������ ������������");  // �������� ����������� � ��������� ���

  for(int i=0; i<4; i++)
  {
    CommPort1->PutChar(0x06000000); // Command6 = 06000000h
  }

  for(int i=0; i<4; i++)
  {
    CommPort1->PutChar(0x0700003F); // Command7 = 0700003Fh
  }

  if(ChB_Com6->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com6[i]);
    }
  }

  if(ChB_Com7->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com7[i]);
    }
  }

  if(ChB_Com8->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com8[i]);
    }
  }

  if(ChB_Com9->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com9[i]);
    }
  }

  if(ChB_Com10->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com10[i]);
    }
  }

  if(ChB_Com11->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com11[i]);
    }
  }

  if(ChB_Com12->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com12[i]);
    }
  }

  if(ChB_Com13->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com13[i]);
    }

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com14[i]);
    }

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com15[i]);
    }

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com16[i]);
    }

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com17[i]);
    }

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com18[i]);
    }

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com19[i]);
    }

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com20[i]);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SendTerminal()
{
  AddSaveLog("�������� ������� �� ��������");  // �������� ����������� � ��������� ���

  if(ChB_Com6->Checked==false)
  {
    CommPort1->PutString("Com6 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com6[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
  }

  if(ChB_Com7->Checked==false)
  {
    CommPort1->PutString("Com7 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com7[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
  }

  if(ChB_Com8->Checked==false)
  {
    CommPort1->PutString("Com8 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com8[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
  }

  if(ChB_Com9->Checked==false)
  {
    CommPort1->PutString("Com9 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com9[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
  }

  if(ChB_Com10->Checked==false)
  {
    CommPort1->PutString("Com10 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com10[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������      
  }

  if(ChB_Com11->Checked==false)
  {
    CommPort1->PutString("Com11 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com11[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
  }

  if(ChB_Com12->Checked==false)
  {
    CommPort1->PutString("Com12 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com12[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
  }

  if(ChB_Com13->Checked==false)
  {
    CommPort1->PutString("Com13 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com13[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    CommPort1->PutString("Com14 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com14[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    CommPort1->PutString("Com15 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com15[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    CommPort1->PutString("Com16 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com16[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    CommPort1->PutString("Com17 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com17[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    CommPort1->PutString("Com18 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com18[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    CommPort1->PutString("Com19 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com19[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    CommPort1->PutString("Com20 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com20[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_OutputChange(TObject *Sender)
{
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::CB_AuxOutChange(TObject *Sender)
{
  UpdateRegister4();  // ���������� �������� Register 4  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_OutFreqChange(TObject *Sender)
{
  if(E_OutFreq->Text<=1) E_OutFreq->Text=1;  // ����� �� ����� ���� ������ 1
  Fout=StrToFloat(E_OutFreq->Text);          // �������� �������� � ����������

  Fvco_OD();          // ���������� Fvco � OD
  Ndevider();         // ���������� INT, FRAC � MOD
  UpdateRegister0();  // ���������� �������� Register 0
  UpdateRegister1();  // ���������� �������� Register 1
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Fvco_OD(void)
{
  OD=1;
  while(Fout*OD<2200) OD*=2;
  Fvco=Fout*OD;

  Fres=ChS*OD;               // ������ channel resolution

  // ������� Divider_Select:
  //Divider_Select=log(OD)/log(2);
  
  if(OD==1) Divider_Select=0;
  else
  if(OD==2) Divider_Select=1;
  else
  if(OD==4) Divider_Select=2;
  else
  if(OD==8) Divider_Select=3;
  else
  if(OD==16) Divider_Select=4;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Ndevider(void)  // ���������� INT, FRAC � MOD:
{
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
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::UpdateRegister0(void)  // ���������� �������� Register 0
{
  int shift_FRAC=0;
  int shift_INT=0;

  Reg[0] &= ~0x7FFFFFF8;           // ������� ���������� �������� Register 0

  shift_FRAC=(int)FRAC&0xFFE;      // FRAC max = 4094
  shift_FRAC*=0x8;
  shift_INT=(int)INTE&0xFFFF;      // INT max = 65535
  shift_INT*=0x8000;

  Reg[0] |= shift_FRAC|shift_INT;  // ������� ����� �������� INT � FRAC

  // �������� �������� ������:
  Com13[1]=(int) Reg[0]     &0xFF; // 1-� ���� Register 0
  Com13[2]=(int)(Reg[0]>>8) &0xFF; // 2-� ���� Register 0
  Com13[3]=(int)(Reg[0]>>16)&0xFF; // 3-� ���� Register 0
  Com14[1]=(int)(Reg[0]>>24)&0xFF; // 4-� ���� Register 0

  E_Com13_1->Text=IntToStr(Com13[1]);
  E_Com13_2->Text=IntToStr(Com13[2]);
  E_Com13_3->Text=IntToStr(Com13[3]);
  E_Com14_1->Text=IntToStr(Com14[1]);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::UpdateRegister1(void)  // ���������� �������� Register 1
{
  int shift_MOD=0;
  int shift_Phase=0;
  int shift_Prescaler=0;

  if(INTE<75)
  {
    Prescaler=0;
  }
  else
  if(INTE>=75)
  {
    Prescaler=1;
  }

  Reg[1] &= ~0xFFFFFFF8;  // ������� ���������� �������� Register 1

  shift_MOD=(int)MOD&0xFFF;                         // MOD max = 4095
  shift_MOD*=0x08;
  shift_Phase=(int)Phase&0xFFF;                     // Phase max = 4095
  shift_Phase*=0x8000;
  shift_Prescaler=Prescaler&0x01;                   // Prescaler max = 1
  shift_Prescaler*=0x8000000;

  Reg[1] |= shift_MOD|shift_Phase|shift_Prescaler;  // ������� ����� ��������

  // �������� �������� ������:
  Com14[2]=(int) Reg[1]     &0xFF;                  // 1-� ���� Register 1
  Com14[3]=(int)(Reg[1]>>8) &0xFF;                  // 2-� ���� Register 1
  Com15[1]=(int)(Reg[1]>>16)&0xFF;                  // 3-� ���� Register 1
  Com15[2]=(int)(Reg[1]>>24)&0xFF;                  // 4-� ���� Register 1

  E_Com14_2->Text=IntToStr(Com14[2]);
  E_Com14_3->Text=IntToStr(Com14[3]);
  E_Com15_1->Text=IntToStr(Com15[1]);
  E_Com15_2->Text=IntToStr(Com15[2]);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::UpdateRegister4(void)  // ���������� �������� Register 4
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
  if(CB_Output->ItemIndex==0)   RF_Output=0;
  for(int i=1; i<5; i++)
  {
    if(CB_Output->ItemIndex==i) RF_Output=(i+3);
  }

  // ������� AUX Output:
  if(CB_AuxOut->ItemIndex==0)   AUX_Output=0;
  for(int i=1; i<5; i++)
  {
    if(CB_AuxOut->ItemIndex==i) AUX_Output=(i+3);
  }

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

  // �������� �������� ������:
  Com18[2]=(int) Reg[4]     &0xFF;                  // 1-� ���� Register 4
  Com18[3]=(int)(Reg[4]>>8) &0xFF;                  // 2-� ���� Register 4
  Com19[1]=(int)(Reg[4]>>16)&0xFF;                  // 3-� ���� Register 4
  Com19[2]=(int)(Reg[4]>>24)&0xFF;                  // 4-� ���� Register 4

  E_Com18_2->Text=IntToStr(Com18[2]);
  E_Com18_3->Text=IntToStr(Com18[3]);
  E_Com19_1->Text=IntToStr(Com19[1]);
  E_Com19_2->Text=IntToStr(Com19[2]);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ResetSynthesizer()
{
  Com13[4]=(237, 0, 0, 200);   // 00, 00, c8
  Com14[4]=(238, 0, 201, 128); // 00, c9, 80
  Com15[4]=(239, 0, 8, 194);   // 00, 08, c2
  Com16[4]=(240, 78, 0, 0);    // 4e, 00, 00
  Com17[4]=(241, 179, 4, 0);   // b3, 04, 00
  Com18[4]=(242, 0, 36, 1);    // 00, 24, 01
  Com19[4]=(243, 165, 0, 5);   // a5, 00, 05
  Com20[4]=(244, 0, 88, 0);    // 00, 58, 00
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_parametersClick(TObject *Sender)
{
  //ResetSynthesizer();
/*
  E_Com13_1->Text=0;
  E_Com13_2->Text=0;
  E_Com13_3->Text=200;
  E_Com14_1->Text=0;
  E_Com14_2->Text=201;
  E_Com14_3->Text=128;
  E_Com15_1->Text=0;
  E_Com15_2->Text=8;
  E_Com15_3->Text=194;
  E_Com16_1->Text=78;
  E_Com16_2->Text=0;
  E_Com16_3->Text=0;
  E_Com17_1->Text=179;
  E_Com17_2->Text=4;
  E_Com17_3->Text=0;
  E_Com18_1->Text=0;
  E_Com18_2->Text=36;
  E_Com18_3->Text=1;
  E_Com19_1->Text=165;
  E_Com19_2->Text=0;
  E_Com19_3->Text=5;
  E_Com20_1->Text=0;
  E_Com20_2->Text=88;
  E_Com20_3->Text=0;
*/
  E_Com13_1->Enabled=false;
  E_Com13_2->Enabled=false;
  E_Com13_3->Enabled=false;
  E_Com14_1->Enabled=false;
  E_Com14_2->Enabled=false;
  E_Com14_3->Enabled=false;
  E_Com15_1->Enabled=false;
  E_Com15_2->Enabled=false;
  E_Com15_3->Enabled=false;
  E_Com16_1->Enabled=false;
  E_Com16_2->Enabled=false;
  E_Com16_3->Enabled=false;
  E_Com17_1->Enabled=false;
  E_Com17_2->Enabled=false;
  E_Com17_3->Enabled=false;
  E_Com18_1->Enabled=false;
  E_Com18_2->Enabled=false;
  E_Com18_3->Enabled=false;
  E_Com19_1->Enabled=false;
  E_Com19_2->Enabled=false;
  E_Com19_3->Enabled=false;
  E_Com20_1->Enabled=false;
  E_Com20_2->Enabled=false;
  E_Com20_3->Enabled=false;

  E_Com13_1->Color=clSilver;
  E_Com13_2->Color=clSilver;
  E_Com13_3->Color=clSilver;
  E_Com14_1->Color=clSilver;
  E_Com14_2->Color=clSilver;
  E_Com14_3->Color=clSilver;
  E_Com15_1->Color=clSilver;
  E_Com15_2->Color=clSilver;
  E_Com15_3->Color=clSilver;
  E_Com16_1->Color=clSilver;
  E_Com16_2->Color=clSilver;
  E_Com16_3->Color=clSilver;
  E_Com17_1->Color=clSilver;
  E_Com17_2->Color=clSilver;
  E_Com17_3->Color=clSilver;
  E_Com18_1->Color=clSilver;
  E_Com18_2->Color=clSilver;
  E_Com18_3->Color=clSilver;
  E_Com19_1->Color=clSilver;
  E_Com19_2->Color=clSilver;
  E_Com19_3->Color=clSilver;
  E_Com20_1->Color=clSilver;
  E_Com20_2->Color=clSilver;
  E_Com20_3->Color=clSilver;

  GB_Parameters->Enabled=true;
  CB_Output->Color=clWindow;
  CB_AuxOut->Color=clWindow;
  E_OutFreq->Color=clWindow;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_registersClick(TObject *Sender)
{
  //ResetSynthesizer();

  E_Com13_1->Enabled=true;
  E_Com13_2->Enabled=true;
  E_Com13_3->Enabled=true;
  E_Com14_1->Enabled=true;
  E_Com14_2->Enabled=true;
  E_Com14_3->Enabled=true;
  E_Com15_1->Enabled=true;
  E_Com15_2->Enabled=true;
  E_Com15_3->Enabled=true;
  E_Com16_1->Enabled=true;
  E_Com16_2->Enabled=true;
  E_Com16_3->Enabled=true;
  E_Com17_1->Enabled=true;
  E_Com17_2->Enabled=true;
  E_Com17_3->Enabled=true;
  E_Com18_1->Enabled=true;
  E_Com18_2->Enabled=true;
  E_Com18_3->Enabled=true;
  E_Com19_1->Enabled=true;
  E_Com19_2->Enabled=true;
  E_Com19_3->Enabled=true;
  E_Com20_1->Enabled=true;
  E_Com20_2->Enabled=true;
  E_Com20_3->Enabled=true;

  E_Com13_1->Color=clWindow;
  E_Com13_2->Color=clWindow;
  E_Com13_3->Color=clWindow;
  E_Com14_1->Color=clWindow;
  E_Com14_2->Color=clWindow;
  E_Com14_3->Color=clWindow;
  E_Com15_1->Color=clWindow;
  E_Com15_2->Color=clWindow;
  E_Com15_3->Color=clWindow;
  E_Com16_1->Color=clWindow;
  E_Com16_2->Color=clWindow;
  E_Com16_3->Color=clWindow;
  E_Com17_1->Color=clWindow;
  E_Com17_2->Color=clWindow;
  E_Com17_3->Color=clWindow;
  E_Com18_1->Color=clWindow;
  E_Com18_2->Color=clWindow;
  E_Com18_3->Color=clWindow;
  E_Com19_1->Color=clWindow;
  E_Com19_2->Color=clWindow;
  E_Com19_3->Color=clWindow;
  E_Com20_1->Color=clWindow;
  E_Com20_2->Color=clWindow;
  E_Com20_3->Color=clWindow;
/*
  CB_Output->ItemIndex=1;
  CB_AuxOut->ItemIndex=1;
  E_OutFreq->Text=1000;
*/
  GB_Parameters->Enabled=false;
  CB_Output->Color=clSilver;
  CB_AuxOut->Color=clSilver;
  E_OutFreq->Color=clSilver;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_OutFreqExit(TObject *Sender)
{
  bool b;
  float min=137.5;
  float max=4400;
  float delta=0.1;
  String EdIzm="���";
  String value;

  value=E_OutFreq->Text;

  b=IsValid(min,max,value,EdIzm);
  if(b)
  {
    E_OutFreq->Text=RoundValue(delta,value);
    Fout=StrToFloat(E_OutFreq->Text);          // �������� �������� � ����������
  }
  else
  {
    E_OutFreq->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
bool TMain_Form::IsValid(float min, float max, String value, String EdIzm)
{
  float temp;

  try
  {
    temp=StrToFloat(value);

    if((temp>max)||(temp<min))
    {
      ShowError(NotInBorders,min,max,EdIzm);
      return false;
    }
  }

  catch(...)
  {
    ShowError(NotFloat,0,0,"");
    return false;
  }

  return true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::UpdateAllRegisters(void)  // ���������� �������� Register 0...5
{
  if(E_Com13_1->Text=="") E_Com13_1->Text=0;
  if(E_Com13_2->Text=="") E_Com13_2->Text=0;
  if(E_Com13_3->Text=="") E_Com13_3->Text=0;

  if(E_Com14_1->Text=="") E_Com14_1->Text=0;
  if(E_Com14_2->Text=="") E_Com14_2->Text=0;
  if(E_Com14_3->Text=="") E_Com14_3->Text=0;

  if(E_Com15_1->Text=="") E_Com15_1->Text=0;
  if(E_Com15_2->Text=="") E_Com15_2->Text=0;
  if(E_Com15_3->Text=="") E_Com15_3->Text=0;

  if(E_Com16_1->Text=="") E_Com16_1->Text=0;
  if(E_Com16_2->Text=="") E_Com16_2->Text=0;
  if(E_Com16_3->Text=="") E_Com16_3->Text=0;

  if(E_Com17_1->Text=="") E_Com17_1->Text=0;
  if(E_Com17_2->Text=="") E_Com17_2->Text=0;
  if(E_Com17_3->Text=="") E_Com17_3->Text=0;

  if(E_Com18_1->Text=="") E_Com18_1->Text=0;
  if(E_Com18_2->Text=="") E_Com18_2->Text=0;
  if(E_Com18_3->Text=="") E_Com18_3->Text=0;

  if(E_Com19_1->Text=="") E_Com19_1->Text=0;
  if(E_Com19_2->Text=="") E_Com19_2->Text=0;
  if(E_Com19_3->Text=="") E_Com19_3->Text=0;

  if(E_Com20_1->Text=="") E_Com20_1->Text=0;
  if(E_Com20_2->Text=="") E_Com20_2->Text=0;
  if(E_Com20_3->Text=="") E_Com20_3->Text=0;

  int shift_Com13_1=0;
  int shift_Com13_2=0;
  int shift_Com13_3=0;

  int shift_Com14_1=0;
  int shift_Com14_2=0;
  int shift_Com14_3=0;

  int shift_Com15_1=0;
  int shift_Com15_2=0;

  int shift_Com18_2=0;
  int shift_Com18_3=0;

  int shift_Com19_1=0;
  int shift_Com19_2=0;

  Com13[1]=StrToInt(E_Com13_1->Text);
  Com13[2]=StrToInt(E_Com13_2->Text);
  Com13[3]=StrToInt(E_Com13_3->Text);

  Com14[1]=StrToInt(E_Com14_1->Text);
  Com14[2]=StrToInt(E_Com14_2->Text);
  Com14[3]=StrToInt(E_Com14_3->Text);

  Com15[1]=StrToInt(E_Com15_1->Text);
  Com15[2]=StrToInt(E_Com15_2->Text);
  Com15[3]=StrToInt(E_Com15_3->Text);

  Com16[1]=StrToInt(E_Com16_1->Text);
  Com16[2]=StrToInt(E_Com16_2->Text);
  Com16[3]=StrToInt(E_Com16_3->Text);

  Com17[1]=StrToInt(E_Com17_1->Text);
  Com17[2]=StrToInt(E_Com17_2->Text);
  Com17[3]=StrToInt(E_Com17_3->Text);

  Com18[1]=StrToInt(E_Com18_1->Text);
  Com18[2]=StrToInt(E_Com18_2->Text);
  Com18[3]=StrToInt(E_Com18_3->Text);

  Com19[1]=StrToInt(E_Com19_1->Text);
  Com19[2]=StrToInt(E_Com19_2->Text);
  Com19[3]=StrToInt(E_Com19_3->Text);

  Com20[1]=StrToInt(E_Com20_1->Text);
  Com20[2]=StrToInt(E_Com20_2->Text);
  Com20[3]=StrToInt(E_Com20_3->Text);

  Reg[0] &= ~0xFFFFFFFF;  // ������� ���������� �������� Register 0
  Reg[1] &= ~0xFFFFFFFF;  // ������� ���������� �������� Register 1
  Reg[4] &= ~0xFFFFFFFF;  // ������� ���������� �������� Register 4

  shift_Com13_1=Com13[1];
  shift_Com13_2=Com13[2]*0x100;
  shift_Com13_3=Com13[3]*0x10000;
  shift_Com14_1=Com14[1]*0x1000000;

  Reg[0] |= shift_Com13_1|shift_Com13_2|shift_Com13_3|shift_Com14_1;  // ������� ����� ��������

  // �������� �������� ����������:
  FRAC=(int)(Reg[0]>>3) &0xFFF;
  INTE=(int)(Reg[0]>>15)&0xFFFF;

  shift_Com14_2=Com14[2];
  shift_Com14_3=Com14[3]*0x100;
  shift_Com15_1=Com15[1]*0x10000;
  shift_Com15_2=Com15[2]*0x1000000;

  Reg[1] |= shift_Com14_2|shift_Com14_3|shift_Com15_1|shift_Com15_2;  // ������� ����� ��������

  // �������� �������� ����������:
  MOD=(int)(Reg[1]>>3) &0xFFF;

  shift_Com18_2=Com18[2];
  shift_Com18_3=Com18[3]*0x100;
  shift_Com19_1=Com19[1]*0x10000;
  shift_Com19_2=Com19[2]*0x1000000;

  Reg[4] |= shift_Com18_2|shift_Com18_3|shift_Com19_1|shift_Com19_2;  // ������� ����� ��������

  // �������� �������� ����������:
  RF_Output=(int)(Reg[4]>>3)&0x07;
  AUX_Output=(int)(Reg[4]>>6)&0x07;
  Divider_Select=(int)(Reg[4]>>20)&0x07;

  // ������� Output:
  if(RF_Output==0)   CB_Output->ItemIndex=0;
  for(int i=1; i<5; i++)
  {
    if(RF_Output==(i+3)) CB_Output->ItemIndex=i;
  }

  // ������� AUX Output:
  if(AUX_Output==0)   CB_AuxOut->ItemIndex=0;
  for(int i=1; i<5; i++)
  {
    if(AUX_Output==(i+3)) CB_AuxOut->ItemIndex=i;
  }

  // ������� OD:
  //OD=pow(10, Divider_Select*log(2));
  
  if(Divider_Select==0) OD=1;
  else
  if(Divider_Select==1) OD=2;
  else
  if(Divider_Select==2) OD=4;
  else
  if(Divider_Select==3) OD=8;
  else
  if(Divider_Select==4) OD=16;

  // ������� AUX Fout:
  Fout=(INTE+FRAC/MOD)*(Fpfd/OD);
  E_OutFreq->Text=FloatToStr(Fout);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com13_1Change(TObject *Sender)
{
  UpdateAllRegisters();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com13_1Exit(TObject *Sender)
{
  UpdateAllRegisters();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command5KeyPress(TObject *Sender, char &Key)
// ������ �������� ����� ��������, ����� ����� 0...9 � ���������� �������
{
  Set<char,0,255>Dig;
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<','<<8;
	if(!Dig.Contains(Key))
	{
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Delay(void)  // ������� ��������
{
  Sleep(delay_ms);                       // �������� � ��
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SearchCOMPorts(void)
{
  TRegistry *reg = new TRegistry;
  TStringList *list = new TStringList;
  reg->RootKey = HKEY_LOCAL_MACHINE;
  reg->OpenKey("HARDWARE\\DEVICEMAP\\SERIALCOMM", false);
  reg->GetValueNames(list);
  for(int i = 0; i < list->Count; i++)
  list->Strings[i] = reg->ReadString( list->Strings[i]);
  list->Sort();
  LB_AvailableCom->Clear();
  LB_AvailableCom->Items->AddStrings(list);
  delete list;
  delete reg;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AvailableComClick(TObject *Sender)
{
  SearchCOMPorts();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ButtonsOff(void)
{
  CB_ComNum->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ButtonsOn(void)
{
  CB_ComNum->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ComPortException(void)
{
  if(CommPort1->Open!=true)
  {
    throw "";
  }
}
//---------------------------------------------------------------------------





