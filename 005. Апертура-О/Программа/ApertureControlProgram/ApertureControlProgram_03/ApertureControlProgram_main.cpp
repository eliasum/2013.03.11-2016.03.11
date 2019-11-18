//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "ApertureControlProgram_main.h"
#include "SelfControl.h"
#include "AboutBox.h"
#include "Help.h"
#include "Error.h"
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
#include <iostream>
#include <fstream>               // �������� �������� �����-������
#include <cmath>
#include <math.h>
#include "NIDAQmx.h"
#include <Registry.hpp>
#include <stdio.h>               // Include file for printf
#include <stdlib.h>              // Include file for strtol
#include <string.h>
#include <windows.h>             // Include file for Win32 time functions
#include "ni845x.h"              // Include file for NI-485x functions and constants
#include <wchar.h>

using namespace std;

/* ������ NI USB-6008:
01. ���� ���  - 1A32668
02. ���� ���  - 19526E6
03. ���� ���  - 1A325A7
04. ���� ���� - 1A46FA0
05. ���� ��   - 1A32670
06. ���� ��   - 1A46FD2

����� NI USB-8451:
01. ���� ��   - 01A5912A
*/

#define NUMBEROFPOINTS 64
#define PRD  dv6
#define PRM  dv4
#define VIP  dv2
#define FRLP dv3
#define UU   dv1
#define BS   dv5

/* the NI 845x handles */
NiHandle DeviceHandle;

uInt8  LineDirectionMap  = 0;    // direction configuration in hex

/*  error Function for NI 845x */
#ifndef errChk
#define errChk(fCall) if (Error = (fCall), Error < 0) {goto Error;} else
#endif

//  ����������� ����������� ������
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

// ���������� ���������� ��������
static int sec=0;
int NIDAQmxCounter=-1;
int TempPowerCounter=-1;

// ���������� ������ �� DAQmx
const int NumReadValue=10;
bool ErrorADC;

// �������� ������ NI USB-6008
unsigned char P0[8],P1[4];        // �����

unsigned char DevP0[8],DevP1[4];  // �����

unsigned char Dev1P0[8],Dev1P1[4],Dev2P0[8],Dev2P1[4];
unsigned char Dev3P0[8],Dev3P1[4],Dev4P0[8],Dev4P1[4];
unsigned char Dev5P0[8],Dev5P1[4],Dev6P0[8],Dev6P1[4];

// �������� ������������ NI USB-6008
const char *Dev_port0;            // �����
const char *Dev_port1;

const char *Dev1_port0 = "Dev1/port0/line0:7";
const char *Dev1_port1 = "Dev1/port1/line0:3";

const char *Dev2_port0 = "Dev2/port0/line0:7";
const char *Dev2_port1 = "Dev2/port1/line0:3";

const char *Dev3_port0 = "Dev3/port0/line0:7";
const char *Dev3_port1 = "Dev3/port1/line0:3";

const char *Dev4_port0 = "Dev4/port0/line0:7";
const char *Dev4_port1 = "Dev4/port1/line0:3";

const char *Dev5_port0 = "Dev5/port0/line0:7";
const char *Dev5_port1 = "Dev5/port1/line0:3";

const char *Dev6_port0 = "Dev6/port0/line0:7";
const char *Dev6_port1 = "Dev6/port1/line0:3";

const char *Dev_ai0;
const char *Dev_ai1;
const char *Dev_ai2;
const char *Dev_ai3;
const char *Dev_ai4;
const char *Dev_ai5;
const char *Dev_ai6;

const char *Dev1_ai0= "Dev1/ai0";
const char *Dev1_ai1= "Dev1/ai1";
const char *Dev1_ai2= "Dev1/ai2";
const char *Dev1_ai3= "Dev1/ai3";
const char *Dev1_ai4= "Dev1/ai4";
const char *Dev1_ai5= "Dev1/ai5";
const char *Dev1_ai6= "Dev1/ai6";

const char *Dev2_ai0= "Dev2/ai0";
const char *Dev2_ai1= "Dev2/ai1";
const char *Dev2_ai2= "Dev2/ai2";
const char *Dev2_ai3= "Dev2/ai3";
const char *Dev2_ai4= "Dev2/ai4";
const char *Dev2_ai5= "Dev2/ai5";
const char *Dev2_ai6= "Dev2/ai6";

const char *Dev3_ai0= "Dev3/ai0";
const char *Dev3_ai1= "Dev3/ai1";
const char *Dev3_ai2= "Dev3/ai2";
const char *Dev3_ai3= "Dev3/ai3";
const char *Dev3_ai4= "Dev3/ai4";
const char *Dev3_ai5= "Dev3/ai5";
const char *Dev3_ai6= "Dev3/ai6";

const char *Dev4_ai0= "Dev4/ai0";
const char *Dev4_ai1= "Dev4/ai1";
const char *Dev4_ai2= "Dev4/ai2";
const char *Dev4_ai3= "Dev4/ai3";
const char *Dev4_ai4= "Dev4/ai4";
const char *Dev4_ai5= "Dev4/ai5";
const char *Dev4_ai6= "Dev4/ai6";

const char *Dev5_ai0= "Dev5/ai0";
const char *Dev5_ai1= "Dev5/ai1";
const char *Dev5_ai2= "Dev5/ai2";
const char *Dev5_ai3= "Dev5/ai3";
const char *Dev5_ai4= "Dev5/ai4";
const char *Dev5_ai5= "Dev5/ai5";
const char *Dev5_ai6= "Dev5/ai6";

const char *Dev6_ai0= "Dev6/ai0";
const char *Dev6_ai1= "Dev6/ai1";
const char *Dev6_ai2= "Dev6/ai2";
const char *Dev6_ai3= "Dev6/ai3";
const char *Dev6_ai4= "Dev6/ai4";
const char *Dev6_ai5= "Dev6/ai5";
const char *Dev6_ai6= "Dev6/ai6";

// ���������� �������� ���������
TColor DefaultColor=clBtnFace;
TColor GoodColor=clLime;
TColor BadColor=clRed;

// ���������� ��� ������� ������� �������� � ������������� ��������
const float pi=3.141592;
const float c=3*100000000;
int Fi=0;                        // �������� ����������� �����
int X=0;                         // �������� ���������� �� �� ��� X
int Y=0;                         // �������� ���������� �� �� ��� Y
int D=0;                         // ���������� �� ���� [�]
int V=0;                         // �������� ����� ��� [�/�]
int f=0;                         // ������� ������� [���]

// ���������� ��������
int OldIndex;                    // ��� ������ ����������
int OldIndex_;                   // ��� ������ ������������

// ���������� ����������
float Buff0[10];                 // ������� �������
unsigned char N_zamera0=0;       // ����� ������
float sum0;                      // 0..0x0ffffffff

float Buff1[10];                 // ������� �������
unsigned char N_zamera1=0;       // ����� ������
float sum1;                      // 0..0x0ffffffff

float Buff2[10];                 // ������� �������
unsigned char N_zamera2=0;       // ����� ������
float sum2;                      // 0..0x0ffffffff

float Buff3[10];                 // ������� �������
unsigned char N_zamera3=0;       // ����� ������
float sum3;                      // 0..0x0ffffffff

float Buff4[10];                 // ������� �������
unsigned char N_zamera4=0;       // ����� ������
float sum4;                      // 0..0x0ffffffff

float Buff5[10];                 // ������� �������
unsigned char N_zamera5=0;       // ����� ������
float sum5;                      // 0..0x0ffffffff

double k2=0.487, k3=0.529, k4=0.56, k5=1.42, k6=1.608;

String FileControl="";
String FileTesting="";

// ������� ��� ���������� ���������� ������ ����
int XString[NUMBEROFPOINTS];
int YString[NUMBEROFPOINTS];
int EPRString[NUMBEROFPOINTS];

int delay_ms;
enum diapason {D1=1, D2, D31, D32, D4} range;     // ���������
enum dev {dv1=1, dv2, dv3, dv4, dv5, dv6} device; // ������ NI USB-6008
/*
 �������� ������ ����������� ����� ����������� ���������� (��)
 � ������ ��� ����� ���� �� ���������� RS-232 �� 28.02.14.
*/
// ����� "����������"
int Command3[NUMBEROFPOINTS][4]; // ������� "��������� ��"
int Shift[4]={3, 255, 0, 0};     // ������� "����� ��������"
int Command4[NUMBEROFPOINTS][4]; // ������� "����� �������� ��"
int Command5[NUMBEROFPOINTS][4]; // ������� "������������ ����� ��"
int D_SignC[NUMBEROFPOINTS];     // ���� ������������� ������ ��
int Command6[4]={6, 0, 0, 0};    // ������� "����������� ������� ������� ������"
int Command7[4]={7, 0, 0, 63};   // ������� "����������� ���������� ����������� ����-2"

// ����� "������������"
int Com3[NUMBEROFPOINTS][4];     // ������� "��������� ��"
int Shift_[4]={227, 255, 0, 0};  // ������� "����� ��������"
int Com4[NUMBEROFPOINTS][4];     // ������� "����� �������� ��"
int Com5[NUMBEROFPOINTS][4];     // ������� "������������ ����� ��"
int D_SignT[NUMBEROFPOINTS];     // ���� ������������� �������� ��
int Com6[4]={230, 0, 0, 31};     // ������� "����������� ���������� �������� ����-2"
int Com7[4]={231, 0, 0, 63};     // ������� "����������� ���������� ����������� ����-2"
int Com8[4]={232, 0, 7, 142};    // ������� "������� ����� ������� ���������� �������� ����-2"
int Com9[4]={233, 0, 7, 142};    // ������� "������� ����� ������� ���������� ����������� ����-2"
int Com10[4]={234, 0, 0, 0};     // ������� "��� ���������� ������� �������������"
int Com11[4]={235, 0, 0, 0};     // ������� "��� ���������� �������� �������������"

// ������� �������� ����������� ����� ����-2
int Com13[4]={237, 0, 0, 200};   // 00, 00, c8
int Com14[4]={238, 0, 201, 128}; // 00, c9, 80
int Com15[4]={239, 0, 8, 194};   // 00, 08, c2
int Com16[4]={240, 78, 0, 0};    // 4e, 00, 00
int Com17[4]={241, 179, 4, 0};   // b3, 04, 00
int Com18[4]={242, 0, 36, 1};    // 00, 24, 01
int Com19[4]={243, 165, 0, 5};   // a5, 00, 05
int Com20[4]={244, 0, 88, 0};    // 00, 58, 00

int Com21[4]={246, 0, 0, 0};     // ������� "�������� I-�� ������������ �������"
int Com22[4]={247, 0, 0, 0};     // ������� "�������� Q-�� ������������ �������"
int Com23[4]={248, 0, 0, 0};     // ������� "������ ���"
int Com24[4]={249, 0, 0, 0};     // ������� "������ ���"
int Com25[4]={250, 0, 0, 0};     // ������� "������ ����-2"
int Com26[4]={251, 0, 0, 0};     // ������� "������ ����"

int Reg[6];
/*
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;

  ��������� ����������� ������� ADF4350 ����� ����, ��������� � ������ �������.
*/
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
/*
  �������� ���������� � �������� ������� NI USB-6008 � NI USB-8451:

  ���������� 1 (������� ���):
  NI USB-6008:
  P0.0, P0.1, P0.2, P0.3, P0.4 - ������ ������� "��������� ����������� ���������" [��]
  P0.5 - ������ ������� "����� ���������� ��������� 2-� �������"
  P0.6, P0.7 - ������ ������� "����� ���������� ��������� �1"
  P1.0, P1.1 - ������ ������� "����� ���������� ��������� �2"

  AI0 - ������ ���������� ������� ��������� +5 � �������� [�]
  AI1 - ������ ���������� ������� ��������� +12 � �������� [�]
  AI2 - ������ �������� ������� �������� [���]
  AI4 - ������ ���������� ������� ��������� -5 � �������� [�]
  AI5 - ������ ���� ������� ��������� +27 � �������� [�]

  ���������� 2 (���������� ���):
  NI USB-6008:
  P0.0, P0.1, P0.2, P0.3, P0.4 - ������ ������� "��������� ����������� �����������" [��]
  P0.5 - ������ ������� "����� ���������� ��������� 2-� �������"
  P0.6, P0.7 - ������ ������� "����� ���������� ��������� �1"
  P1.0, P1.1 - ������ ������� "����� ���������� ��������� �2"

  AI0 - ������ ���������� ������� ��������� +5 � ����������� [�]
  AI1 - ������ ���������� ������� ��������� +12 � ����������� [�]
  AI2 - ������ �������� ������� ����������� [���]
  AI4 - ������ ���������� ������� ��������� -5 � ����������� [�]
  AI5 - ������ ���� ������� ��������� +27 � ����������� [�]

  ���������� 3 (��������� �������� ������� ���):
  NI USB-6008:
  P0.0 - ������ ������� "��������� ��� ��-���"
  P0.1 - ������ ������� "�������� -9 � �� ��-���"
  P0.2 - ������ ������� "�������� +24 � �� ��-���"

  AI0 - ������ ���������� ������� ��������� +12 � [�]
  AI1 - ������ ���������� ������� ��������� +27 � [�]
  AI2 - ������ ���� ��������� ����������� [�]
  AI4 - ������ ���������� ������� ��������� +5 � [�]
  AI5 - ������ ���� ��������� �������� [�]

  ���������� 4 (���������� ���������� ��):
  NI USB-6008:
  AI0 - ������ ���������� ������� ��������� +5 � [�]
  AI1 - ������ ��������� ���������� ������� ���� [�]
  AI4 - ������ ���������� ������� ��������� +12 � [�]

  ���������� 5 (���� ����������� ��)
  NI USB-6008:
  P0.0, P0.1, P0.2, P0.3, P0.4, P0.5 - ������ ������� "��������� ��������� ����������� ��������� ������" [��]
  P0.6, P0.7, P1.0, P1.1, P1.2, P1.3 - ������ ������� "��������� ��������� ����������� ���������� ������" [��]

  AI0 - ������ �������� ������� ����������� ��������� ������ [����.]
  AI1 - ������ �������� ������� ����������� ���������� ������ [����.]
  AI2 - ������ �������� ���������� ������� -5� [�]
  AI3 - ������ �������� ���� ����������� �� +27� [�]
  AI4 - ������ �������� �������� ������� ������������ ������ ��������� ������ [��]
  AI5 - ������ �������� �������� ������� ������������ ������ ���������� ������ [��]
  AI6 - ������ �������� ���������� ������� +5� [�]

  NI USB-8451:
  P0.0 - ������ ������� "������ ���� ���� ��������� ������", 0 � ���� �� ���������, 1 � ���� ���������
  P0.1 - ������ ������� "�������� ������� ����������� ��������� ������", 0 � ���������, 1 � ��������
  P0.2 - ������ ������� "������ ���� ���� ���������� ������", 0 � ���� �� ���������, 1 � ���� ���������
  P0.3 - ������ ������� "�������� ������� ����������� ���������� ������", 0 � ���������, 1 � ��������

  P0.4, P0.5 - ������ ������� "����� ���������� ��������� ������ ��� ��������"
  P0.6, P0.7 - ������ ������� "����� ���������� ���������� ������ ��� ��������"

  ���������� 6 (���� ����)
  NI USB-6008:

  AI0 - ������ �������� ���������� ������� ���� [�], ��� ���. ����� - 5 � (+4,85�+5,15 �)
  AI1 - ������ �������� ������� ����������� [����.]
  AI4 - ������ �������� ������� ���� ����������� +27 � ����� ���� [�]
  AI5 - ������ �������� ���������� ����������� ������ ��������� [���]
*/
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CommPort"
#pragma resource "*.dfm"
TMainForm *MainForm;
TIniFile *Ini;
//---------------------------------------------------------------------------
// ����� ������������ ����� MainForm
__fastcall TMainForm::TMainForm(TComponent* Owner)
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

  if(!DirectoryExists(My_Patch + "����� ����������� � ������ ������"))
  {
	if(!CreateDir(My_Patch + "����� ����������� � ������ ������"))
	  ShowMessage("�� ������� ������� ���������� �������� ������ ����������� � ������ ������!");
    else
      ShowMessage("������� ���������� ��� �������� ������ ����������� � ������ ������!");
  }
/*
  extern PACKAGE bool __fastcall DirectoryExists(const System::UnicodeString Directory, bool FollowLink = true);
  ������� DirectoryExists ���������� True, ���� ������ DirectoryName ���� ����������.
  ������� ������������� � ������� ��������. False ����� ���� ����������, ���� ������������ ��
  ��������� ������ ����.

  extern PACKAGE bool __fastcall CreateDir(const System::UnicodeString Dir);
  ������� CreateDir ������ ����� � ������� ����������.
  ���� ����� ���� �������, �� ������� ������ True.
*/

  InitBPControl();
  InitBPTesting();

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

  // ��������� �������������:
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;

  delay_ms=1;

  // ������� ������ NI USB-6008
  ClearDevs();

  DevToP0P1(dv1);
  SetDev_port(dv1);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv2);
  SetDev_port(dv2);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv3);
  SetDev_port(dv3);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv4);
  SetDev_port(dv4);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv5);
  SetDev_port(dv5);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv6);
  SetDev_port(dv6);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  range=D1;
  DefaultPanel();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
  F_SelfControl->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_AvailableComClick(TObject *Sender)
{
  SearchCOMPorts();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SearchCOMPorts(void)
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
void __fastcall TMainForm::TB_AboutClick(TObject *Sender)
{
  AddSaveLog("���������� � ���������, ������ ������ � ������");  // �������� ����������� � ��������� ���
  F_AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HelpAboutProgClick(TObject *Sender)
{
  F_Help->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddSaveLog(String comment) // �������� ����������� � ��������� ���
{
  My_Patch = ExtractFilePath(Application->ExeName);   // ���� � ����������� �����

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
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
/*
3.	��������������� ���������� ���������� �-�

3.1	 ������������ ��������.
��� ������ � ���������� ���������� ��� �������� ���������� ��������������� ������
��������� � ��������� ����.�.
� ����� ��� (�� NI6008) ������ ���������� ����. ����� 9» ���������
� ���. 1, ����� ������� ������ ���������� ����.+24» ���������
� ���. 1 � ����� ������� �������� ������ ����������� ������������� �� ����� 20��
(������������ 200 ��, ���. 1).

  P0.0 - ������ ������� "��������� ��� ��-���"
  P0.1 - ������ ������� "�������� -9 � �� ��-���"
  P0.2 - ������ ������� "�������� +24 � �� ��-���"
*/
  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[1]=1;                            // 1->DevP0[1]

  SetDevPN(VIP, DevP0, 1);               // if VIP DevP0[1]->Dev1P0[1]
  DevToP0P1(VIP);                        // if VIP Dev1PX[1]->Px[1]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // ������ �������� ������ VIP
     T_Sec1->Enabled=true;                               // �������� 1 �
  }

  catch(...)
  {
	 Application->MessageBox(L"������ ������ � ���� ���!",L"��������",MB_ICONWARNING);
     SB_OnOff->Enabled=false;
  }
/*
  FormatDateTime (s, dt) - ������ ��������, �������������� ����� ���� ��� �����. ������ �������������
  ������ ������ ������� s, ��������, ������ dd/mm/yyyy ������, ��� ��������� ������� �������� ����,
  � ������ hh:mm � �����
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+"_"+FormatDateTime("HH-NN-SS",Time()); // ������� ���� � �����
  logFname = P_SystemTime->Caption; // ������ ����� ��� ����� � ����� ��� �������� ���������
  AddSaveLog("��������� ��������"); // �������� ����������� � ��������� ���
/*
  M_Debug->Lines->Add(PRD);
  M_Debug->Lines->Add(PRM);
  M_Debug->Lines->Add(VIP);
  M_Debug->Lines->Add(FRLP);
  M_Debug->Lines->Add(UU);
  M_Debug->Lines->Add(BS);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  AddSaveLog("��������� �������"); // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_EnterClick(TObject *Sender)
{
  if(E_EnterComment->Text!="")
  {
    AddSaveLog(E_EnterComment->Text); // ������ ��� �����
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ChB_LogClick(TObject *Sender)
{
  if(ChB_Log->Checked==true) M_Log->Visible=false;
  else                       M_Log->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WorkTimerTimer(TObject *Sender)
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
void __fastcall TMainForm::SB_OnOffClick(TObject *Sender)
{
  try
  {
    if(SB_OnOff->Down)         // ���� ������
    {
      SB_OnOff->Caption="���������";
      SB_OnOff->Font->Color=clRed;

      WorkTimer->Enabled=true; // �������� ������ WorkTimer

	  StartControl();
    }
    else                       // ���� �� ������
    {
      SB_OnOff->Caption="��������";
	  SB_OnOff->Font->Color=clGreen;

	  StopControl();
/*
      ExtractFilePath(Application->ExeName) - ���� � ����������� �����.
      GetCurrentDir() - ���� � ������� ����������.
      ��� �� ������� ���������, ������� ������� �������� �� ����������,
      ������� �� ������� ������� ����� � ����� �������� � ��������.
*/
    }
  }

  catch(...)
  {
    SB_OnOff->Down=false;
    SB_OnOff->Caption="��������";
	SB_OnOff->Font->Color=clGreen;
	ButtonsOn();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonsOn(void)
{
  B_Ready->Enabled=true;
  CB_ComNum->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SystemTimerTimer(TObject *Sender)
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
void __fastcall TMainForm::ExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
  if (!DirectoryExists(My_Patch + "log �����"))
  {
	MessageBox(NULL,L"���������� ���������� log �����!",L"������!",MB_OK|MB_ICONERROR);
    Application->Terminate();
  }
}
//---------------------------------------------------------------------------
bool TMainForm::IsValidInt(int min, int max, String value, String EdIzm)
// �������� ������������ ��������� �������� ����� �����
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
void TMainForm::ShowError(int ErrorNum, float Par1, float Par2, String Par3)
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
bool __fastcall TMainForm::SetDevP0P1Data(const char *Config0, const char *Config1)
// ������ �������� ������
{
	TaskHandle  taskHandle=0;
	char        errBuff[2048]={'\0'};

/////////////////////////////////////////////////////////////////////////////
  // ���������� P0
/////////////////////////////////////////////////////////////////////////////

  // ������� ������
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ���������� ��������� ������
  if (DAQmxFailed((DAQmxCreateDOChan(taskHandle,Config0,"",DAQmx_Val_ChanForAllLines))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ��������� ������
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ���������� ������
  if (DAQmxFailed((DAQmxWriteDigitalLines(taskHandle,1,1,1.0,DAQmx_Val_GroupByChannel,P0,NULL,NULL))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ������������� � ������� ������
  if( taskHandle!=0 )
  {
	/*********************************************/
	// DAQmx Stop Code
	/*********************************************/
	DAQmxStopTask(taskHandle);
	DAQmxClearTask(taskHandle);
  }

/////////////////////////////////////////////////////////////////////////////
  // ���������� P1
/////////////////////////////////////////////////////////////////////////////

  // ������� ������
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ���������� ��������� ������
  if (DAQmxFailed((DAQmxCreateDOChan(taskHandle,Config1,"",DAQmx_Val_ChanForAllLines))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ��������� ������
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ���������� ������
  if (DAQmxFailed((DAQmxWriteDigitalLines(taskHandle,1,1,1.0,DAQmx_Val_GroupByChannel,P1,NULL,NULL))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ������������� � ������� ������
  if( taskHandle!=0 )
  {
	/*********************************************/
	// DAQmx Stop Code
	/*********************************************/
	DAQmxStopTask(taskHandle);
	DAQmxClearTask(taskHandle);
  }

  return true;
}
//---------------------------------------------------------------------------
float __fastcall TMainForm::GetDevACDData(const char *Config)
{
  TaskHandle  taskHandle=0;
  char errBuff[2048]={'\0'};
  int32 read;
  float64 data[NumReadValue];
  double value;
  ErrorADC=false;

  // ������� ������
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // ���������� ��������� ������
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,Config,"",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // ���������� ������������
  if (DAQmxFailed(DAQmxCfgSampClkTiming(taskHandle,"",10000,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,NumReadValue)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // ��������� ������
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // ��������� ������
  if (DAQmxFailed(DAQmxReadAnalogF64(taskHandle,NumReadValue,1.0,DAQmx_Val_GroupByChannel,data,NumReadValue,&read,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // ������������� � ������� ������
  if( taskHandle!=0 )
  {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
  }

  try
  {
    value=0;
    for(int i=0;i<read;i++)
    {
      value+=data[i];
    }

    value/=read;
    return value;
  }

  catch(...)
  {
    ErrorADC=true;
    return 0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command3Change(TObject *Sender)
{
  int Comm3;
  if(E_Command3->Text=="") E_Command3->Text=0;
  Comm3=StrToInt(E_Command3->Text);                   // �������� ������� �������� � ����������
  Command3[OldIndex][3]=Comm3&0xFF;                   // �������� ���� �� ������� OldIndex � ������
/*
  �������� ������������ �� ������� OldIndex, �.�. ���� ������ ������ ������������
  ������ "�� ��������� ������ ��" CB_Command3_1Change(TObject *Sender).
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command3Exit(TObject *Sender)
{
  bool b;
  int min=0;                                           // ����������� ��������
  int max=255;                                         // ������������ ��������
  int delta=1;
  String EdIzm="";                                     // ������� ���������
  int ivalue;                                          // ������ ��������

  ivalue=StrToInt(E_Command3->Text);                   // ��������

  b=IsValidInt(min,max,ivalue,EdIzm);                  // �������� ������������ ��������� ��������
  if(b)                                                // ���� ���������
  {
	// �������� ������� �������� �� ������� OldIndex � ������:
	Command3[OldIndex][3]=StrToInt(E_Command3->Text);
/*
    �������� ������������ �� ������� OldIndex, �.�. ���� ������ ������ ������������
    ������ "�� ��������� ������ ��" CB_Command3_1Change(TObject *Sender).
*/
  }
  else
  {
	E_Command3->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
String TMainForm::RoundValue(float delta, float fvalue)
{
  float temp;
  float temp1;

  temp=fvalue;
  temp1=Log10(delta);          // ���������� ������ ����� �������
  // ��������� �� �������� � 2-�� ����������� ������� ����� �������:
  fvalue=RoundTo(temp,temp1);  // � BCB6 ���� String (�������������� ����� ���������)

  return fvalue;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command3KeyPress(TObject *Sender, wchar_t &Key)
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
void __fastcall TMainForm::E_Command3_0Change(TObject *Sender)
{
  ResetBPControl();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ResetBPControl(void)  // ����� ������ Command 3...5
{
  InitBPControl();                 // �������� ���������� ��������� ��
  CB_Command3_1->ItemIndex=0;
  CB_SignC->ItemIndex=0;
  E_Command3->Text=IntToStr(255);
  E_Command4->Text=IntToStr(0);
  E_Command5->Text=IntToStr(0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::InitBPControl(void)  // ������������� ������ Command 3...5
{
  // ������������� ������� Command3
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Command3[i][0]=3;   // ���� ���� �������
    Command3[i][1]=i+1; // 1-� ���� ������ ������
    Command3[i][2]=0;   // 2-� ���� ������ ������
  }
  Command3[0][3]=255;   // 3-� ���� ������ ������ (�� �1)

  for(int i=1; i<NUMBEROFPOINTS; i++)
  {
    Command3[i][3]=0;   // 3-� ���� ������ ������ (��������� ��)
  }

  // ������������� ������� Command4
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Command4[i][0]=4;   // ���� ���� �������
    Command4[i][1]=i+1; // 1-� ���� ������ ������
    Command4[i][2]=0;   // 2-� ���� ������ ������
    Command4[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� Command5
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Command5[i][0]=5;   // ���� ���� �������
    Command5[i][1]=i+1; // 1-� ���� ������ ������
    Command5[i][2]=0;   // 2-� ���� ������ ������
    Command5[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� SignC
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    D_SignC[i]=0;
  }

  OldIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command3_0Exit(TObject *Sender)
// ����� ���� "���������� ��������� �����" ���������
{
  bool b;
  int min=1;                             // ����������� ��������
  int max=NUMBEROFPOINTS;                // ������������ ��������
  int delta=1;
  String EdIzm="";                       // ������� ���������
  int ivalue;                            // ������ ��������

  ivalue=StrToInt(E_Command3_0->Text);   // ��������

  b=IsValidInt(min,max,ivalue,EdIzm);    // �������� ������������ ��������� ��������
  if(b)                                  // ���� ���������
  {
	CB_Command3_1->Clear();              // �������� ���������� ���������� ��

    for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
    {
      CB_Command3_1->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
    }

	CB_Command3_1->ItemIndex=0;          // ����� �� �� ��������� ��� ��������� ����� ��
  }
  else                                   // ���� �� ���������
  {
	E_Command3_0->SetFocus();            // ����� �� ���� "���������� ��������� �����"
    ErrorForm->SetFocus();               // ����� ��������� �� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Command3_1Change(TObject *Sender)  // �� ��������� ������ ��
{
  int i, Comm3, Comm4, Comm5;
  i=CB_Command3_1->ItemIndex;                        // �������� ����� ������ ���� ������ CB_Command3_1
  // �������� ������ �������� ����� �������������� � ����������:
  Comm3=StrToInt(E_Command3->Text);                  // �������� ������ �������� ���� E_Command3 � ����������
  Comm4=StrToInt(E_Command4->Text);                  // �������� ������ �������� ���� E_Command4 � ����������
  Comm5=StrToInt(E_Command5->Text);                  // �������� ������ �������� ���� E_Command5 � ����������
  // �������� ������ �������� �� ������� OldIndex � ������:
  Command3[OldIndex][3]=Comm3&0xFF;
  Command4[OldIndex][3]=Comm4&0xFF;                  // ��. ����
  Command4[OldIndex][2]=(Comm4/256)&0xFF;            // ��. ����
  Command5[OldIndex][3]=Comm5&0xFF;                  // ��. ����
  Command5[OldIndex][2]=(Comm5/256)&0xFF;            // ��. ����
  D_SignC[OldIndex]=CB_SignC->ItemIndex;

  OldIndex=i;  // ��������� ������� ������ ��� ������ ��� ���������� ��������� � �����

  // ������� �������� �� ������� �� �������� ������� � ���� ��������������:
  E_Command3->Text=IntToStr(Command3[i][3]);
  E_Command4->Text=IntToStr(Command4[i][2]*256+Command4[i][3]);
  E_Command5->Text=IntToStr(Command5[i][2]*256+Command5[i][3]);
  // ������� �������� �� ������� �� �������� ������� � ���� ������:
  if(D_SignC[i]==0) CB_SignC->ItemIndex=0;
  else              CB_SignC->ItemIndex=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_SignCKeyPress(TObject *Sender, wchar_t &Key)  // ������ �������� ����� ��������
{
  Set<char,0,255>Dig;
  Dig<<8;
  if(!Dig.Contains(Key))
  {
	Key=0;
	return;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_ShiftChange(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
	if(CB_Shift->ItemIndex==i) Shift[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command4Change(TObject *Sender)
// �� ��������� ��������� � ���� ��������������
{
  int Comm4;
  if(E_Command4->Text=="") E_Command4->Text=0;
  Comm4=StrToInt(E_Command4->Text);                   // �������� ������� �������� � ����������
  // �������� ������� �������� �� ������� OldIndex � ������:
  Command4[OldIndex][3]=Comm4&0xFF;                   // ��. ����
  Command4[OldIndex][2]=(Comm4/256)&0xFF;             // ��. ����
/*
  �������� ������������ �� ������� OldIndex, �.�. ���� ������ ������ ������������
  ������ "�� ��������� ������ ��" CB_Command3_1Change(TObject *Sender).
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command4Exit(TObject *Sender)
// �� ��������� ������ � ������� ���� ��������������
{
  bool b;
  int min=0;
  int max=63;
  int delta=1;
  String EdIzm="��";
  int ivalue;

  ivalue=StrToInt(E_Command4->Text);

  b=IsValidInt(min,max,ivalue,EdIzm);
  if(b)
  {
    int Comm4=StrToInt(E_Command4->Text);               // �������� ������� �������� � ����������
    // �������� ������� �������� �� ������� OldIndex � ������:
    Command4[OldIndex][3]=Comm4&0xFF;                   // ��. ����
    Command4[OldIndex][2]=(Comm4/256)&0xFF;             // ��. ����
/*
    �������� ������������ �� ������� OldIndex, �.�. ���� ������ ������ ������������
    ������ "�� ��������� ������ ��" CB_Command3_1Change(TObject *Sender).
*/
  }
  else
  {
    E_Command4->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_SignCChange(TObject *Sender)
{
  if(CB_SignC->ItemIndex==0) D_SignC[OldIndex]=0;
  else                       D_SignC[OldIndex]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_SignCExit(TObject *Sender)
{
  if(CB_SignC->ItemIndex==0) D_SignC[OldIndex]=0;
  else                       D_SignC[OldIndex]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command5Change(TObject *Sender)
// �� ��������� ��������� � ���� ��������������
{
  float Comm5;
  if(E_Command5->Text=="") E_Command5->Text=0;
  Comm5=StrToFloat(E_Command5->Text);            // �������� ������� �������� � ����������
  // �������� ������� �������� �� ������� OldIndex � ������:
  Command5[OldIndex][3]=(int)Comm5&0xFF;         // ��. ����
  Command5[OldIndex][2]=((int)Comm5/256)&0xFF;   // ��. ����
/*
  �������� ������������ �� ������� OldIndex, �.�. ���� ������ ������ ������������
  ������ "�� ��������� ������ ��" CB_Command3_1Change(TObject *Sender).
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command5Exit(TObject *Sender)
// �� ��������� ������ � ������� ���� ��������������
{
  bool b;
  float min=-16384;   // -32768*0.5
  float max=16383.5;  // 32767*0.5
  float delta=0.5;    // ���� �������� ������� 0.5 ��
  String EdIzm="��";
  float fvalue;

  fvalue=StrToFloat(E_Command5->Text);

  b=IsValid(min,max,fvalue,EdIzm);
  if(b)
  {
	E_Command5->Text=RoundValue(delta,fvalue);
    float Comm5=StrToFloat(E_Command5->Text);               // �������� ������� �������� � ����������
    // �������� ������� �������� �� ������� OldIndex � ������:
    Command5[OldIndex][3]=(int)Comm5&0xFF;                  // ��. ����
    Command5[OldIndex][2]=((int)Comm5/256)&0xFF;            // ��. ����
/*
    �������� ������������ �� ������� OldIndex, �.�. ���� ������ ������ ������������
    ������ "�� ��������� ������ ��" CB_Command3_1Change(TObject *Sender).
*/
  }
  else
  {
    E_Command5->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
bool TMainForm::IsValid(float min, float max, String value, String EdIzm)
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
void __fastcall TMainForm::CB_Command7Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Command7->ItemIndex==i) Command7[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Command7Exit(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Command7->ItemIndex==i) Command7[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com3Change(TObject *Sender)
{
  int Comm3;
  if(E_Com3->Text=="") E_Com3->Text=0;
  Comm3=StrToInt(E_Com3->Text);                  // �������� �������� � ����������
  Com3[OldIndex_][3]=Comm3&0xFF;                 // ��. ����
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com3Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=255;
  int delta=1;
  String EdIzm="";
  int ivalue;

  ivalue=StrToInt(E_Com3->Text);

  b=IsValidInt(min,max,ivalue,EdIzm);
  if(b)
  {
    Com3[OldIndex_][3]=StrToInt(E_Com3->Text);
  }
  else
  {
    E_Com3->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com3_1Change(TObject *Sender)  // �� ��������� ������ ��
{
  int i, Comm3, Comm4, Comm5;
  i=CB_Com3_1->ItemIndex;                            // �������� ����� ������ ���� ������ CB_Com3_1
  // �������� ������ �������� ����� �������������� � ����������:
  Comm3=StrToInt(E_Com3->Text);                      // �������� ������ �������� ���� E_Com3 � ����������
  Comm4=StrToInt(E_Com4->Text);                      // �������� ������ �������� ���� E_Com4 � ����������
  Comm5=StrToInt(E_Com5->Text);                      // �������� ������ �������� ���� E_Com5 � ����������
  // �������� ������ �������� �� ������� OldIndex � ������:
  Com3[OldIndex_][3]=Comm3&0xFF;
  Com4[OldIndex_][3]=Comm4&0xFF;                     // ��. ����
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;               // ��. ����
  Com5[OldIndex_][3]=Comm5&0xFF;                     // ��. ����
  Com5[OldIndex_][2]=(Comm5/256)&0xFF;               // ��. ����
  D_SignT[OldIndex_]=CB_SignT->ItemIndex;

  OldIndex_=i;  // ��������� ������� ������ ��� ������ ��� ���������� ��������� � �����

  // ������� �������� �� ������� �� �������� ������� � ���� ��������������:
  E_Com3->Text=IntToStr(Com3[i][3]);                 // �������� ������� ��������
  E_Com4->Text=IntToStr(Com4[i][2]*256+Com4[i][3]);  // �������� ������� ��������
  E_Com5->Text=IntToStr(Com5[i][2]*256+Com5[i][3]);  // �������� ������� ��������
  // ������� �������� �� ������� �� �������� ������� � ���� ������:
  if(D_SignT[i]==0) CB_SignT->ItemIndex=0;
  else              CB_SignT->ItemIndex=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ResetBPTesting(void)  // ����� ������ Com 3...5
{
  InitBPTesting();                                // �������� ���������� ��������� ��
  CB_Com3_1->ItemIndex=0;
  CB_SignT->ItemIndex=0;
  E_Com3->Text=IntToStr(255);
  E_Com4->Text=IntToStr(0);
  E_Com5->Text=IntToStr(0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::InitBPTesting(void)  // ������������� ������ Com 3...5
{
  // ������������� ������� Com3
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Com3[i][0]=227; // ���� ���� �������
    Com3[i][1]=i+1; // 1-� ���� ������ ������
    Com3[i][2]=0;   // 2-� ���� ������ ������
  }
  Com3[0][3]=255;   // 3-� ���� ������ ������ (�� �1)

  for(int i=1; i<NUMBEROFPOINTS; i++)
  {
    Com3[i][3]=0;   // 3-� ���� ������ ������ (��������� ��)
  }

  // ������������� ������� Com4
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Com4[i][0]=228; // ���� ���� �������
    Com4[i][1]=i+1; // 1-� ���� ������ ������
    Com4[i][2]=0;   // 2-� ���� ������ ������
    Com4[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� Com5
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Com5[i][0]=229; // ���� ���� �������
    Com5[i][1]=i+1; // 1-� ���� ������ ������
    Com5[i][2]=0;   // 2-� ���� ������ ������
    Com5[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� SignT
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    D_SignT[i]=0;
  }

  OldIndex_=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com3_0Change(TObject *Sender)
{
  ResetBPTesting();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com3_0Exit(TObject *Sender)
// ����� ���� "���������� ��������� �����" ���������
{
  bool b;
  int min=1;                           // ����������� ��������
  int max=NUMBEROFPOINTS;              // ������������ ��������
  String EdIzm="";                     // ������� ���������
  int ivalue;                          // ������ ��������

  ivalue=StrToInt(E_Com3_0->Text);     // ��������

  b=IsValidInt(min,max,ivalue,EdIzm);  // �������� ������������ ��������� ��������
  if(b)                                // ���� ���������
  {
	CB_Com3_1->Clear();                // �������� ���������� ���������� ��

    for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
    {
      CB_Com3_1->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
    }

	CB_Com3_1->ItemIndex=0;            // ����� �� �� ��������� ��� ��������� ����� ��
  }
  else                                 // ���� �� ���������
  {
	E_Com3_0->SetFocus();              // ����� �� ���� "���������� ��������� �����"
    ErrorForm->SetFocus();             // ����� ��������� �� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Shift_Change(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
    if(CB_Shift_->ItemIndex==i) Shift_[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_ShiftExit(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
	if(CB_Shift->ItemIndex==i) Shift[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Shift_Exit(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
    if(CB_Shift_->ItemIndex==i) Shift_[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com4Change(TObject *Sender)
{
  int Comm4;
  if(E_Com4->Text=="") E_Com4->Text=0;
  Comm4=StrToInt(E_Com4->Text);                   // �������� �������� � ����������
  Com4[OldIndex_][3]=Comm4&0xFF;                  // ��. ����
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;            // ��. ����
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com4Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=65535;
  int delta=1;
  String EdIzm="��";
  int ivalue;

  ivalue=StrToInt(E_Com4->Text);

  b=IsValidInt(min,max,ivalue,EdIzm);
  if(b)
  {
    int Comm4=StrToInt(E_Com4->Text);               // �������� �������� � ����������
    Com4[OldIndex_][3]=Comm4&0xFF;                   // ��. ����
    Com4[OldIndex_][2]=(Comm4/256)&0xFF;             // ��. ����
  }
  else
  {
    E_Com4->SetFocus();
    ErrorForm->SetFocus();
  }
}
//--------------------------------------------------------------------------
void __fastcall TMainForm::E_Com5Change(TObject *Sender)
// �� ��������� ��������� � ���� ��������������
{
  float Comm5;
  if(E_Com5->Text=="") E_Com5->Text=0;
  Comm5=StrToFloat(E_Com5->Text);                  // �������� ������� �������� � ����������
  // �������� ������� �������� �� ������� OldIndex � ������:
  Com5[OldIndex_][3]=(int)Comm5&0xFF;              // ��. ����
  Com5[OldIndex_][2]=((int)Comm5/256)&0xFF;        // ��. ����
/*
  �������� ������������ �� ������� OldIndex, �.�. ���� ������ ������ ������������
  ������ "�� ��������� ������ ��" CB_Command3_1Change(TObject *Sender).
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com5Exit(TObject *Sender)
{
  bool b;
  float min=0;
  float max=16383.75;  // 65535*0.5/2
  float delta=0.5;
  String EdIzm="��";
  float fvalue;

  fvalue=StrToFloat(E_Com5->Text);

  b=IsValid(min,max,fvalue,EdIzm);
  if(b)
  {
	E_Com5->Text=RoundValue(delta,fvalue);
	float Comm5=StrToInt(E_Com5->Text);             // �������� ������� �������� � ����������
	// �������� ������� �������� �� ������� OldIndex � ������:
	Com5[OldIndex_][3]=(int)Comm5&0xFF;             // ��. ����
	Com5[OldIndex_][2]=((int)Comm5/256)&0xFF;       // ��. ����
/*
    �������� ������������ �� ������� OldIndex, �.�. ���� ������ ������ ������������
    ������ "�� ��������� ������ ��" CB_Command3_1Change(TObject *Sender).
*/
  }
  else
  {
    E_Com5->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_SignTChange(TObject *Sender)
{
  if(CB_SignT->ItemIndex==0) D_SignT[OldIndex_]=0;
  else                       D_SignT[OldIndex_]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_SignTExit(TObject *Sender)
{
  if(CB_SignT->ItemIndex==0) D_SignT[OldIndex_]=0;
  else                       D_SignT[OldIndex_]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com6Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Com6->ItemIndex==i) Com6[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com7Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Com7->ItemIndex==i) Com7[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com8Change(TObject *Sender)
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
void __fastcall TMainForm::CB_Com9Change(TObject *Sender)
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
void __fastcall TMainForm::CB_Com10Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Com10->ItemIndex==i) Com10[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com11Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Com11->ItemIndex==i) Com11[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_OutputChange(TObject *Sender)
{
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_AuxOutChange(TObject *Sender)
{
  UpdateRegister4();  // ���������� �������� Register 4
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_OutFreqChange(TObject *Sender)
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
void __fastcall TMainForm::Fvco_OD(void)
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
void __fastcall TMainForm::Ndevider(void)  // ���������� INT, FRAC � MOD:
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
void __fastcall TMainForm::UpdateRegister0(void)  // ���������� �������� Register 0
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
/*
  E_Com13_1->Text=IntToStr(Com13[1]);
  E_Com13_2->Text=IntToStr(Com13[2]);
  E_Com13_3->Text=IntToStr(Com13[3]);
  E_Com14_1->Text=IntToStr(Com14[1]);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateRegister1(void)  // ���������� �������� Register 1
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
/*
  E_Com14_2->Text=IntToStr(Com14[2]);
  E_Com14_3->Text=IntToStr(Com14[3]);
  E_Com15_1->Text=IntToStr(Com15[1]);
  E_Com15_2->Text=IntToStr(Com15[2]);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateRegister4(void)  // ���������� �������� Register 4
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
/*
  E_Com18_2->Text=IntToStr(Com18[2]);
  E_Com18_3->Text=IntToStr(Com18[3]);
  E_Com19_1->Text=IntToStr(Com19[1]);
  E_Com19_2->Text=IntToStr(Com19[2]);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadBlpClick(TObject *Sender)  // ������� �� ������ "������� ���� .blp"
{
  AddSaveLog("��������� ���� ������ ��");  // �������� ����������� � ��������� ���

  OpenDialog1->DefaultExt=".blp";
  OpenDialog1->FileName="*.blp";
  OpenDialog1->Filter="���� ������ �� (*.blp)|*.blp";
  OpenDialog1->Title=" �������� ����� ������ ��";

  String File;

  if(OpenDialog1->Execute())
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  ���������� ������ ������ ������.
  ���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
  ���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/
  {
	File=OpenDialog1->FileName;
	BlpFName=File;

    if(FileExists(File))
    {
	  Ini= new TIniFile(File);
/*
      Ini->ReadString("�������� ������","��� ����������", "��������");
*/
      // ���������� ��
      E_Command3_0->Text=Ini->ReadString("���� ������ ��","���������� ��","1");  // ������� �� ����� � ������
      E_Com3_0->Text=Ini->ReadString("���� ������ ��","���������� ��","1");      // ������� �� ����� � ������
      // ���������� X ��, ���������� Y ��, ��� ��
      for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
      {
        // ���������� X ��
        XString[i]=StrToInt(Ini->ReadString("���� ������ ��","���������� X ��������� ����� (��)"+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
        // ���������� Y ��
        YString[i]=StrToInt(Ini->ReadString("���� ������ ��","���������� Y ��������� ����� (��)"+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
        // ��� ��
        EPRString[i]=StrToInt(Ini->ReadString("���� ������ ��","��� ��������� ����� (��)"+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
      }

      AddSaveLog("�������� ���� "+BlpFName);  // �������� ����������� � ��������� ���

      delete Ini;
    }
    else
    {
      ShowError(FileNotExist, 0, 0, "");
      return;
    }
  }

  StatusBar1->SimpleText=File; // ����� � ������ ���������
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadSarClick(TObject *Sender)  // ������� �� ������ "������� ���� .sar"
{
  AddSaveLog("��������� ���� ������ ��� � ������");          // �������� ����������� � ��������� ���

  OpenDialog1->DefaultExt=".sar";
  OpenDialog1->FileName="*.sar";
  OpenDialog1->Title=" �������� ����� ������ ��� � ������";
  OpenDialog1->Filter="������ ��� � ������ (*.sar)|*.sar";

  String File;

  if(OpenDialog1->Execute())
  {
    File=OpenDialog1->FileName;
    FileControl=File;

    if(FileExists(File))
	{
      Ini= new TIniFile(File);
/*
      Ini->ReadString("�������� ������","��� ����������", "��������");
*/
	  // �������� ����� ���
	  LE_V->Text=Ini->ReadString("������ ��� � ������","�������� ����� ���","1");   // ������� �� ����� � ������
	  // ������� �������
	  LE_f->Text=Ini->ReadString("������ ��� � ������","������� �������","1");       // ������� �� ����� � ������
	  // ����������� �����
	  LE_Fi->Text=Ini->ReadString("������ ��� � ������","����������� �����","1");   // ������� �� ����� � ������
	  // ���������� �� ����
	  LE_D->Text=Ini->ReadString("������ ��� � ������","���������� �� ����","1");    // ������� �� ����� � ������

      AddSaveLog("�������� ���� "+SarFName);           // �������� ����������� � ��������� ���

	  delete Ini;
	}
	else
	{
	  ShowError(FileNotExist, 0, 0, "");
	}
  }

  StatusBar1->SimpleText=File; // ����� � ������ ���������
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_SaveControlClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ����������");  // �������� ����������� � ��������� ���

  SaveDialog1->DefaultExt=".ctr";
  SaveDialog1->FileName="*.ctr";
  SaveDialog1->Filter="���� ������ ���������� (*.ctr)|*.ctr";
  SaveDialog1->Title=" ���������� ����� ������ ����������";

  AnsiString File; // � BCB6 ���� String
/*
  � ������������ ����� sysmac.h �������:

  #if defined(_DELPHI_STRING_UNICODE)
	typedef UnicodeString        String;           //
  #else
	typedef AnsiString           String;           //
  #endif

  �.�. �� ��������� ��� String ���� UnicodeString.
  � BCB6 �� ��������� ��� String ���� AnsiString.
*/
  FILE *F;

  if(SaveDialog1->Execute())
  {
	File=SaveDialog1->FileName;
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
	Ini->WriteString("������ � ������ ����������","���������� ��",E_Command3_0->Text);

	// Command3
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
	  Ini->WriteString("������ � ������ ����������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"",Command3[i][3]);  // ������ �� ������� � ����
    }
    // Command4
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
      int Command=Command4[i][3]+Command4[i][2]*256;
	  Ini->WriteString("������ � ������ ����������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"",Command);   // ������ �� ������� � ����
    }
    // Command5, ���� �������� ������� 0.5 ��
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
	  Ini->WriteString("������ � ������ ����������","������� \"���� ������������� ������ ������� (��)\""+IntToStr(i+1)+"\"",D_SignC[i]);  // ������ �� ������� � ����
      int Command=(Command5[i][3]+Command5[i][2]*256);
	  Ini->WriteString("������ � ������ ����������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"",Command);  // ������ �� ������� � ����
    }
    // ������� "����� ��������"
	Ini->WriteString("������ � ������ ����������","������� \"����� ��������\"",IntToStr(Shift[3])); // ������ �� ������� � ����
    // Command6
    int Comm6=Command6[3]+Command6[2]*256;
	Ini->WriteString("������ � ������ ����������","������� \"����������� ������� ������� ������\"",Comm6);   // ������ �� ������� � ����
    // Command7
    Ini->WriteString("������ � ������ ����������","������� \"����������� ���������� ����������� ����-2\"",IntToStr(Command7[3])); // ������ �� ������� � ����

    delete Ini;
  }

  StatusBar1->SimpleText=File; // ����� � ������ ���������
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_SaveTestingClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ������������");  // �������� ����������� � ��������� ���

  SaveDialog1->DefaultExt=".tst";
  SaveDialog1->FileName="*.tst";
  SaveDialog1->Filter="���� ������ ������������(*.tst)|*.tst";
  SaveDialog1->Title=" ���������� ����� ������ ������������";

  AnsiString File; // � BCB6 ���� String
/*
  � ������������ ����� sysmac.h �������:

  #if defined(_DELPHI_STRING_UNICODE)
	typedef UnicodeString        String;           //
  #else
	typedef AnsiString           String;           //
  #endif

  �.�. �� ��������� ��� String ���� UnicodeString.
  � BCB6 �� ��������� ��� String ���� AnsiString.
*/
  FILE *F;

  if(SaveDialog1->Execute())
  {
    File=SaveDialog1->FileName;
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
	Ini->WriteString("������ � ������ ������������","���������� ��",E_Com3_0->Text);

    // Com3
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
    {
	  Ini->WriteString("������ � ������ ������������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"",Com3[i][3]);  // ������ �� ������� � ����
    }
    // Com4
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
    {
      int Command=Com4[i][3]+Com4[i][2]*256;
	  Ini->WriteString("������ � ������ ������������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"",Command);   // ������ �� ������� � ����
	}
	// Com5, ���� �������� ������� 0.5 ��
	for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
	{
	  Ini->WriteString("������ � ������ ������������","������� \"���� ������������� ������ ������� (��)\""+IntToStr(i+1)+"\"",D_SignT[i]);  // ������ �� ������� � ����
	  int Command=(Com5[i][3]+Com5[i][2]*256);
	  Ini->WriteString("������ � ������ ������������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"",Command);  // ������ �� ������� � ����
	}
    // ������� "����� ��������"
	Ini->WriteString("������ � ������ ������������","������� \"����� ��������\"",IntToStr(Shift_[3])); // ������ �� ������� � ����
	// Com6
	Ini->WriteString("������ � ������ ������������","������� \"����������� ���������� �������� ����-2\"",IntToStr(Com6[3]));   // ������ �� ������� � ����
    // Com7
	Ini->WriteString("������ � ������ ������������","������� \"����������� ���������� ����������� ����-2\"",IntToStr(Com7[3])); // ������ �� ������� � ����
    // Com8
    int Comm8=Com8[3]+Com8[2]*256;
	Ini->WriteString("������ � ������ ������������","������� \"������� ����� ������� ���������� �������� ����-2\"",Comm8);  // ������ �� ������� � ����
    // Com9
    int Comm9=Com9[3]+Com9[2]*256;
	Ini->WriteString("������ � ������ ������������","������� \"������� ����� ������� ���������� ����������� ����-2\"",Comm9);  // ������ �� ������� � ����
    // Com10
	Ini->WriteString("������ � ������ ������������","������� \"��� ���������� ������� �������������\"",IntToStr(Com10[3])); // ������ �� ������� � ����
	// Com11
	Ini->WriteString("������ � ������ ������������","������� \"��� ���������� �������� �������������\"",IntToStr(Com11[3])); // ������ �� ������� � ����
	// Com13
    unsigned long int Comm13=Com13[3]+Com13[2]*256+Com13[1]*65536;
	Ini->WriteString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 1\"",Comm13); // ������ �� ������� � ����
    // Com14
    unsigned long int Comm14=Com14[3]+Com14[2]*256+Com14[1]*65536;
	Ini->WriteString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 2\"",Comm14); // ������ �� ������� � ����
	// Com15
    unsigned long int Comm15=Com15[3]+Com15[2]*256+Com15[1]*65536;
	Ini->WriteString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 3\"",Comm15); // ������ �� ������� � ����
	// Com16
    unsigned long int Comm16=Com16[3]+Com16[2]*256+Com16[1]*65536;
	Ini->WriteString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 4\"",Comm16); // ������ �� ������� � ����
    // Com17
	unsigned long int Comm17=Com17[3]+Com17[2]*256+Com17[1]*65536;
	Ini->WriteString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 5\"",Comm17); // ������ �� ������� � ����
	// Com18
    unsigned long int Comm18=Com18[3]+Com18[2]*256+Com18[1]*65536;
	Ini->WriteString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 6\"",Comm18); // ������ �� ������� � ����
    // Com19
    unsigned long int Comm19=Com19[3]+Com19[2]*256+Com19[1]*65536;
	Ini->WriteString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 7\"",Comm19); // ������ �� ������� � ����
    // Com20
	unsigned long int Comm20=Com20[3]+Com20[2]*256+Com20[1]*65536;
	Ini->WriteString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 8\"",Comm20); // ������ �� ������� � ����

    delete Ini;
  }

  StatusBar1->SimpleText=File; // ����� � ������ ���������
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadControlClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ����������");  // �������� ����������� � ��������� ���

  ResetBPControl();

  OpenDialog1->DefaultExt=".ctr";
  OpenDialog1->FileName="*.ctr";
  OpenDialog1->Filter="���� ������ ���������� (*.ctr)|*.ctr";
  OpenDialog1->Title=" �������� ����� ������ ����������";

  String File;

  if(OpenDialog1->Execute())
  {
    File=OpenDialog1->FileName;
    FileControl=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("�������� ������","��� ����������", "��������");
*/
      // ���������� ��
	   E_Command3_0->Text=Ini->ReadString("������ � ������ ����������","���������� ��","1");                // ������� �� ����� � ������
      // Command3, Command4, Command5
      for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
      {
        // Command3
		Command3[i][3]=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
        // Command4
		int Comm4=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"","0"));                    // ������� �� ����� � ������
        Command4[i][3]=Comm4&0xFF;                // ��. ����
        Command4[i][2]=(Comm4/256)&0xFF;          // ��. ����
        // Command5, ���� �������� ������� 0.5 ��
		D_SignC[i]=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"���� ������������� ������ ������� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� �����
        if(D_SignC[i]==0) CB_SignC->ItemIndex=0;
        else              CB_SignC->ItemIndex=1;

		int Comm5=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
        Command5[i][3]=Comm5&0xFF;                // ��. ����
        Command5[i][2]=(Comm5/256)&0xFF;          // ��. ����
      }
      CB_Command3_1->Clear();                     // �������� ���������� ���������� ��

      for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
      {
        CB_Command3_1->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
      }

      CB_Command3_1->ItemIndex=OldIndex;          // ����� �� �� ��������� ��� ��������� ����� ��
      E_Command3->Text=Command3[OldIndex][3];                           // �������� ������� ��������
      E_Command4->Text=Command4[OldIndex][3]+Command4[OldIndex][2]*256; // �������� ������� ��������
      E_Command5->Text=Command5[OldIndex][3]+Command5[OldIndex][2]*256; // �������� ������� ��������
      // ������� "����� ��������"
	  Shift[3]=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"����� ��������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<7; i++)
      {
        if(Shift[3]==i) CB_Shift->ItemIndex=i; // ������ � �����
      }
      // Command6
	  int Comm6=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"����������� ������� ������� ������\"","0"));      // ������� �� ����� � ������
      Command6[3]=Comm6&0xFF;                     // ��. ����
      Command6[2]=(Comm6/256)&0xFF;               // ��. ����
      // Command7
      Command7[3]=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"����������� ���������� ����������� ����-2\"","0")); // ������� �� ����� � ������
      for(int i=0; i<64; i++)
      {
        if(Command7[3]==63-i) CB_Command7->ItemIndex=i; // ������ � �����
      }

      AddSaveLog("�������� ���� "+FileControl);  // �������� ����������� � ��������� ���

      delete Ini;
    }
    else
    {
      ShowError(FileNotExist, 0, 0, "");
    }
  }

  StatusBar1->SimpleText=File; // ����� � ������ ���������
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadTestingClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ������������");  // �������� ����������� � ��������� ���

  ResetBPTesting();

  OpenDialog1->DefaultExt=".tst";
  OpenDialog1->FileName="*.tst";
  OpenDialog1->Filter="���� ������ ������������ (*.tst)|*.tst";
  OpenDialog1->Title=" �������� ����� ������ ������������";

  String File;

  if(OpenDialog1->Execute())
  {
    File=OpenDialog1->FileName;
    FileTesting=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("�������� ������","��� ����������", "��������");
*/
      // ���������� ��
	  E_Com3_0->Text=Ini->ReadString("������ � ������ ������������","���������� ��","1");
	  // Com3, Com4, Com5
      for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
      {
        // Com3
		Com3[i][3]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� ����� � ������
        // Com4
		int Comm4=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"","0"));             // ������� �� ����� � ������
        Com4[i][3]=Comm4&0xFF;                // ��. ����
        Com4[i][2]=(Comm4/256)&0xFF;          // ��. ����
        // Com5, ���� �������� ������� 0.5 ��
		D_SignT[i]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"���� ������������� ������ ������� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� �����
        if(D_SignT[i]==0) CB_SignT->ItemIndex=0;
        else              CB_SignT->ItemIndex=1;

		int Comm5=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� ����� � ������
        Com5[i][3]=Comm5&0xFF;                // ��. ����
        Com5[i][2]=(Comm5/256)&0xFF;          // ��. ����
      }
      CB_Com3_1->Clear();                     // �������� ���������� ���������� ��

      for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
      {
        CB_Com3_1->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
      }

      CB_Com3_1->ItemIndex=OldIndex_;         // ����� �� �� ��������� ��� ��������� ����� ��
      E_Com3->Text=Com3[OldIndex_][3];                        // �������� ������� ��������
      E_Com4->Text=Com4[OldIndex_][3]+Com4[OldIndex_][2]*256; // �������� ������� ��������
      E_Com5->Text=Com5[OldIndex_][3]+Com5[OldIndex_][2]*256; // �������� ������� ��������
	  // ������� "����� ��������"
	  Shift_[3]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"����� ��������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<7; i++)
      {
        if(Shift_[3]==i) CB_Shift_->ItemIndex=i; // ������ � �����
      }
      // Com6
	  Com6[3]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"����������� ���������� �������� ����-2\"","0")); // ������� �� ����� � ������
      for(int i=0; i<64; i++)
      {
        if(Com6[3]==63-i) CB_Com6->ItemIndex=i; // ������ � �����
      }
      // Com7
	  Com7[3]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"����������� ���������� ����������� ����-2\"","0")); // ������� �� ����� � ������
	  for(int i=0; i<64; i++)
      {
        if(Com7[3]==63-i) CB_Com7->ItemIndex=i; // ������ � �����
      }
      // Com8
	  int Comm8=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� ����� ������� ���������� �������� ����-2\"","0"));      // ������� �� ����� � ������
      Com8[3]=Comm8&0xFF;                       // ��. ����
      Com8[2]=(Comm8/256)&0xFF;                 // ��. ����
      for(int i=0; i<=15; i++)
      {
        if(Comm8==14+i*128) CB_Com8->ItemIndex=i;      // ������ � �����
      }
      // Com9
	  int Comm9=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� ����� ������� ���������� �������� ����-2\"","0"));      // ������� �� ����� � ������
	  Com9[3]=Comm9&0xFF;                       // ��. ����
	  Com9[2]=(Comm9/256)&0xFF;                 // ��. ����
      for(int i=0; i<=15; i++)
      {
        if(Comm9==14+i*128) CB_Com9->ItemIndex=i;      // ������ � �����
      }
      // Com10
	  Com10[3]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"��� ���������� ������� �������������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<=3; i++)
      {
        if(Com10[3]==i) CB_Com10->ItemIndex=i; // ������ � �����
      }
      // Com11
	  Com11[3]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"��� ���������� �������� �������������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<=3; i++)
      {
        if(Com11[3]==i) CB_Com11->ItemIndex=i; // ������ � �����
      }
      // Com13
	  unsigned long int Comm13=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 1\"","0"));      // ������� �� ����� � ������
      Com13[3]=Comm13&0xFF;                    // ��. ����
      Com13[2]=(Comm13/256)&0xFF;              // ��. ����
	  Com13[1]=(Comm13/65536)&0xFF;            // ��. ����

      // Com14
	  unsigned long int Comm14=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 2\"","0"));      // ������� �� ����� � ������
      Com14[3]=Comm14&0xFF;                    // ��. ����
      Com14[2]=(Comm14/256)&0xFF;              // ��. ����
	  Com14[1]=(Comm14/65536)&0xFF;            // ��. ����

      // Com15
	  unsigned long int Comm15=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 3\"","0"));      // ������� �� ����� � ������
      Com15[3]=Comm15&0xFF;                    // ��. ����
      Com15[2]=(Comm15/256)&0xFF;              // ��. ����
	  Com15[1]=(Comm15/65536)&0xFF;            // ��. ����

      // Com16
	  unsigned long int Comm16=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 4\"","0"));      // ������� �� ����� � ������
	  Com16[3]=Comm16&0xFF;                    // ��. ����
      Com16[2]=(Comm16/256)&0xFF;              // ��. ����
	  Com16[1]=(Comm16/65536)&0xFF;            // ��. ����

      // Com17
	  unsigned long int Comm17=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 5\"","0"));      // ������� �� ����� � ������
      Com17[3]=Comm17&0xFF;                    // ��. ����
      Com17[2]=(Comm17/256)&0xFF;              // ��. ����
	  Com17[1]=(Comm17/65536)&0xFF;            // ��. ����

      // Com18
	  unsigned long int Comm18=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 6\"","0"));      // ������� �� ����� � ������
      Com18[3]=Comm18&0xFF;                    // ��. ����
      Com18[2]=(Comm18/256)&0xFF;              // ��. ����
	  Com18[1]=(Comm18/65536)&0xFF;            // ��. ����

      // Com19
	  unsigned long int Comm19=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 7\"","0"));      // ������� �� ����� � ������
      Com19[3]=Comm19&0xFF;                    // ��. ����
      Com19[2]=(Comm19/256)&0xFF;              // ��. ����
	  Com19[1]=(Comm19/65536)&0xFF;            // ��. ����

      // Com20
      unsigned long int Comm20=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 8\"","0"));      // ������� �� ����� � ������
      Com20[3]=Comm20&0xFF;                    // ��. ����
      Com20[2]=(Comm20/256)&0xFF;              // ��. ����
	  Com20[1]=(Comm20/65536)&0xFF;            // ��. ����

      UpdateAllRegisters();

      AddSaveLog("�������� ���� "+FileTesting);  // �������� ����������� � ��������� ���

      delete Ini;
	}
	else
	{
	  ShowError(FileNotExist, 0, 0, "");
	}
  }

  StatusBar1->SimpleText=File; // ����� � ������ ���������
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateAllRegisters(void)  // ���������� �������� Register 0...5
{
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
void __fastcall TMainForm::B_ReadyClick(TObject *Sender)
{
  AddSaveLog("����������� �������");  // �������� ����������� � ��������� ���

  // �������� ����� ��� V
  if(LE_V->Text!="")
  {
	V=StrToInt(LE_V->Text);  // ����������� ��������
	//M_Debug->Lines->Add(V);
  }

  // ������� ������� f
  if(LE_f->Text!="")
  {
	f=StrToInt(LE_f->Text);  // ����������� ��������
	//M_Debug->Lines->Add(f);
  }

  // ����������� ����� Fi ������������ ����������� �� �����
  if(LE_Fi->Text!="")
  {
	Fi=StrToInt(LE_Fi->Text);  // ����������� ��������
	//M_Debug->Lines->Add(Fi);
  }

  // ���������� �� ���� D
  if(LE_D->Text!="")
  {
	D=StrToInt(LE_D->Text);  // ����������� ��������
	//M_Debug->Lines->Add(D);
  }
/*
  if(f>=900&&f<=10000)                        // ���� �������� ����������
  {
	if(f>=900&&f<=1700) range = D1;
	else
	if(f>=4900&&f<=5700) range = D2;
	else
	if(f>=7100&&f<=7900) range = D31;
	else
	if(f>=7700&&f<=8500) range = D32;
	else
	if(f>=9200&&f<=10000) range = D4;

	if(range == D1)
	{
	  Command6[2]=0;                     // �������� �������� �������� ����� ����������� ������� ������� ������
	  Command6[3]=0;                     // �������� �������� �������� ����� ����������� ������� ������� ������
	}
	else
	{
	  Command6[2]=0;                     // �������� �������� �������� ����� ����������� ������� ������� ������
	  Command6[3]=1;                     // �������� �������� �������� ����� ����������� ������� ������� ������
	}
  }
*/
  CB_Command3_1->Clear();                          // �������� ���������� ���������� ��
  CB_Com3_1->Clear();                              // �������� ���������� ���������� ��

  for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
  {
    CB_Command3_1->Items->Add(IntToStr(i+1));      // ��������� ���������� �� � ����� "����� ��������� �����"
  }

  for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
  {
    CB_Com3_1->Items->Add(IntToStr(i+1));          // ��������� ���������� �� � ����� "����� ��������� �����"
  }
  // Command3, Command4, Command5, Com3, Com4, Com5
  for(int i=0;i<StrToInt(E_Command3_0->Text);++i)  // ������� ��
  {
    // ���
    float EPR=StrToFloat(EPRString[i]);            // ����������� �������� ���

    // ����������
    X=XString[i];                                  // ����������� �������� ���������� �� �� ��� X
    Y=YString[i];                                  // ����������� �������� ���������� �� �� ��� Y
    //float arg=Fi*pi/180;                         // ������� �������� � �������
    //float Xi=X*cos(arg)+Y*sin(arg);              // ���������� X � ������ ����������� ����� Fi
    //float Yi=Y*cos(arg)-X*sin(arg);              // ���������� Y � ������ ����������� ����� Fi
    //M_Debug->Lines->Add(Xi);
    //M_Debug->Lines->Add(Yi);

    // ����� ��������
    //Tau=((2*Xi)/c-1���)*10^9 [��]                // ������� ������� �������� �� [��] (�������)
    //float Tau=2*Xi*3.33-1000;                    // ����� �������� �� [��](�������)
    //float Tau=2*Yi*3.33-1000;                    // ����� �������� �� [��](���� ����������� ����� Fi)
    float Tau=2*Y*3.33-1000;                       // ����� �������� �� [��](��� ����� ����������� ����� Fi)
    int Tau_LSB=((int)Tau)&0xFF;                   // ������� ���� ������� �������� ��
    int Tau_MSB=((int)Tau/256)&0xFF;               // ������� ���� ������� �������� ��

    // ������������ ��������
    //fdi=2*f[���=1000000��]*V*Yi/c*D;             // ������� ������������� �������� �� [��]
    //double K1=2*((double)f/1000)*V*Yi/D;         // (�������)
    //double K1=2*((double)f/1000)*V*Xi/D;         // (���� ����������� ����� Fi)
    double K1=2*((double)f/1000)*V*X/D;            // (��� ����� ����������� ����� Fi)
    double K2=1000000*1000/c;
    double fdi=K1*K2;                              // ������������ �������� �� [��] ��� ������ � ���������

    //M_Debug->Lines->Add(fdi);
    if(fdi<0)
    {
      fdi=-fdi;
      CB_SignC->ItemIndex=1;
      CB_SignT->ItemIndex=1;
    }
    else
    {
      CB_SignC->ItemIndex=0;
      CB_SignT->ItemIndex=0;
    }
    //M_Debug->Lines->Add(CB_SignC->ItemIndex);
    //M_Debug->Lines->Add(CB_SignT->ItemIndex);

    int fdi_LSB=((int)fdi)&0xFF;                   // ������� ���� ������������� �������� ��
    int fdi_MSB=((int)fdi/256)&0xFF;               // ������� ���� ������������� �������� ��
    Command5[i][2]=fdi_MSB;                        // �������� �������� �������� �����, ���� �������� ������� 0.5 ��
    Command5[i][3]=fdi_LSB;                        // �������� �������� �������� �����, ���� �������� ������� 0.5 ��

    // Command3 "��������� ��������� ����� (��)" ������ ����������
    Command3[i][1]=i+1;                            // �������� �������� ������ ��
    Command3[i][3]=int(sqrt(EPR));                 // �������� �������� ��������� ��
    // Command4 "����� �������� (��)" ������ ����������
    Command4[i][1]=i+1;                            // �������� �������� ������ ��
    Command4[i][2]=Tau_MSB;                        // �������� �������� �������� ����� ������� �������� ��
    Command4[i][3]=Tau_LSB;                        // �������� �������� �������� ����� ������� �������� ��
    // Command5 "������������ ����� ������� (��)" ������ ����������
    Command5[i][1]=i+1;                            // �������� �������� ������ ��
    D_SignC[i]=CB_SignC->ItemIndex;

    // Com3 "��������� ��������� ����� (��)" ������ ������������
    Com3[i][1]=i+1;                                // �������� �������� ������ ��
    Com3[i][3]=int(sqrt(EPR));                     // �������� �������� ��������� ��
    // Com4 "����� �������� (��)" ������ ������������
    Com4[i][1]=i+1;                                // �������� �������� ������ ��
    Com4[i][2]=Tau_MSB;                            // �������� �������� �������� ����� ������� �������� ��
    Com4[i][3]=Tau_LSB;                            // �������� �������� �������� ����� ������� �������� ��
    // Com5 "������������ ����� ������� (��)" ������ ������������
    Com5[i][1]=i+1;                                // �������� �������� ������ ��
    Com5[i][2]=fdi_MSB;                            // �������� �������� �������� �����, ���� �������� ������� 0.5 ��
    Com5[i][3]=fdi_LSB;                            // �������� �������� �������� �����, ���� �������� ������� 0.5 ��
    D_SignT[i]=CB_SignT->ItemIndex;
  }

  CB_Command3_1->ItemIndex=OldIndex;               // ����� �� �� ��������� ��� ��������� ����� ��
  E_Command3->Text=IntToStr(Command3[OldIndex][3]);                            // �������� ������� ��������
  E_Command4->Text=IntToStr(Command4[OldIndex][3]+Command4[OldIndex][2]*256);  // �������� ������� ��������
  E_Command5->Text=IntToStr(Command5[OldIndex][3]+Command5[OldIndex][2]*256);  // �������� ������� ��������
  if(D_SignC[OldIndex]==0) CB_SignC->ItemIndex=0;
  else                     CB_SignC->ItemIndex=1;


  CB_Com3_1->ItemIndex=OldIndex_;                   // ����� �� �� ��������� ��� ��������� ����� ��
  E_Com3->Text=IntToStr(Com3[OldIndex_][3]);                         // �������� ������� ��������
  E_Com4->Text=IntToStr(Com4[OldIndex_][3]+Com4[OldIndex_][2]*256);  // �������� ������� ��������
  E_Com5->Text=IntToStr(Com5[OldIndex_][3]+Com5[OldIndex_][2]*256);  // �������� ������� ��������
  if(D_SignT[OldIndex_]==0) CB_SignT->ItemIndex=0;
  else                      CB_SignT->ItemIndex=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command5KeyPress(TObject *Sender, wchar_t &Key)
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
bool __fastcall TMainForm::DigitalLineWrite(int LineNumber, int DValue)
// LineNumber - line number for DO, DValue - value to write
{
   int    Error             = 0;
   char   FirstDevice[260];       // 260 characters for 845x resource name
   uInt8  DioPort           = 0;  // port for the line
   int    ch;
   char   CharBuff[10];
   char   ErrorMsg[1024];

   LineDirectionMap |= (0x1 << LineNumber);

   /* find first device */
   errChk (ni845xFindDevice (FirstDevice, NULL , NULL));

   /* open device handle */
   errChk (ni845xOpen (FirstDevice, &DeviceHandle));

   /* Set the I/O Voltage Level */
   errChk (ni845xSetIoVoltageLevel (DeviceHandle, kNi845x33Volts));

   /* Set the DIO Driver Type */
   errChk (ni845xDioSetDriverType (DeviceHandle, DioPort, kNi845xPushPull));

   /* Set the Line Direction Map */
   errChk (ni845xDioSetPortLineDirectionMap (DeviceHandle, DioPort, LineDirectionMap));

   /* Write the Digital Line */
   errChk (ni845xDioWriteLine(DeviceHandle, DioPort, LineNumber, DValue));

   // Close the device handle
   errChk (ni845xClose (DeviceHandle));

   DeviceHandle = 0;

   return 1;

Error:
   if (Error < 0)
   {
	 try
	 {
	   /*
	   ni845xStatusToString(Error, 1024, ErrorMsg);

	   wchar_t* WErrorMsg;
	   swprintf(WErrorMsg, L"%S", ErrorMsg); // char* -> wchar_t*
	   Application->MessageBox(WErrorMsg,L"������ ������ ���������� ����� ������ ����� ��!",MB_ICONWARNING);
       */
	   ni845xClose (DeviceHandle);
	 }

	 catch(...)
	 {
	   Application->MessageBox(L"������ ������� � ����� ��!",L"��������",MB_ICONWARNING);
	   MainForm->SetFocus();
	   //exit(1);
	 }

   }

   return 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClearDevs(void) // ������� ������ NI USB-6008
{
  int i;

  for(i=0;i<8;i++)
  {
	Dev1P0[i]=0;
	Dev2P0[i]=0;
	Dev3P0[i]=0;
	Dev4P0[i]=0;
	Dev5P0[i]=0;
	Dev6P0[i]=0;
  }

  for(i=0;i<4;i++)
  {
	Dev1P1[i]=0;
	Dev2P1[i]=0;
	Dev3P1[i]=0;
	Dev4P1[i]=0;
	Dev5P1[i]=0;
	Dev6P1[i]=0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DevToP0P1(int dv)
// ������ �������� ������ NI USB-6008 � ����� ������
{
  int i;

  if(dv==dv1)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev1P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev1P1[i];
	}
  }
  else
  if(dv==dv2)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev2P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev2P1[i];
	}
  }
  else
  if(dv==dv3)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev3P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev3P1[i];
	}
  }
  else
  if(dv==dv4)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev4P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev4P1[i];
	}
  }
  else
  if(dv==dv5)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev5P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev5P1[i];
	}
  }
  else
  if(dv==dv6)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev6P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev6P1[i];
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetDev_port(int dv)
// ��������� ������� Dev_portN �� ������ DevX_portN ���������� device
{
  if(dv==dv1)
  {
	Dev_port0 = Dev1_port0;
	Dev_port1 = Dev1_port1;
  }
  else
  if(dv==dv2)
  {
	Dev_port0 = Dev2_port0;
	Dev_port1 = Dev2_port1;
  }
  else
  if(dv==dv3)
  {
	Dev_port0 = Dev3_port0;
	Dev_port1 = Dev3_port1;
  }
  else
  if(dv==dv4)
  {
	Dev_port0 = Dev4_port0;
	Dev_port1 = Dev4_port1;
  }
  else
  if(dv==dv5)
  {
	Dev_port0 = Dev5_port0;
	Dev_port1 = Dev5_port1;
  }
  else
  if(dv==dv6)
  {
	Dev_port0 = Dev6_port0;
	Dev_port1 = Dev6_port1;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetDev_ai(int dv)
// ��������� ������� Dev_aiN �� ������ DevX_aiN ���������� device
{
  if(dv==dv1)
  {
	Dev_ai0 = Dev1_ai0;
	Dev_ai1 = Dev1_ai1;
	Dev_ai2 = Dev1_ai2;
	Dev_ai3 = Dev1_ai3;
	Dev_ai4 = Dev1_ai4;
	Dev_ai5 = Dev1_ai5;
	Dev_ai6 = Dev1_ai6;
  }
  else
  if(dv==dv2)
  {
	Dev_ai0 = Dev2_ai0;
	Dev_ai1 = Dev2_ai1;
	Dev_ai2 = Dev2_ai2;
	Dev_ai3 = Dev2_ai3;
	Dev_ai4 = Dev2_ai4;
	Dev_ai5 = Dev2_ai5;
	Dev_ai6 = Dev2_ai6;
  }
  else
  if(dv==dv3)
  {
	Dev_ai0 = Dev3_ai0;
	Dev_ai1 = Dev3_ai1;
	Dev_ai2 = Dev3_ai2;
	Dev_ai3 = Dev3_ai3;
	Dev_ai4 = Dev3_ai4;
	Dev_ai5 = Dev3_ai5;
	Dev_ai6 = Dev3_ai6;
  }
  else
  if(dv==dv4)
  {
	Dev_ai0 = Dev4_ai0;
	Dev_ai1 = Dev4_ai1;
	Dev_ai2 = Dev4_ai2;
	Dev_ai3 = Dev4_ai3;
	Dev_ai4 = Dev4_ai4;
	Dev_ai5 = Dev4_ai5;
	Dev_ai6 = Dev4_ai6;
  }
  else
  if(dv==dv5)
  {
	Dev_ai0 = Dev5_ai0;
	Dev_ai1 = Dev5_ai1;
	Dev_ai2 = Dev5_ai2;
	Dev_ai3 = Dev5_ai3;
	Dev_ai4 = Dev5_ai4;
	Dev_ai5 = Dev5_ai5;
	Dev_ai6 = Dev5_ai6;
  }
  else
  if(dv==dv6)
  {
	Dev_ai0 = Dev6_ai0;
	Dev_ai1 = Dev6_ai1;
	Dev_ai2 = Dev6_ai2;
	Dev_ai3 = Dev6_ai3;
	Dev_ai4 = Dev6_ai4;
	Dev_ai5 = Dev6_ai5;
	Dev_ai6 = Dev6_ai6;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetDevPN(int dv, unsigned char* Dev, int i)
// ��������� ������ DevXPN ���������� device �� ������� DevPN
{
  if(dv==dv1)
  {
	if(Dev==DevP0) Dev1P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev1P1[i]=DevP1[i];
  }
  else
  if(dv==dv2)
  {
	if(Dev==DevP0) Dev2P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev2P1[i]=DevP1[i];
  }
  else
  if(dv==dv3)
  {
	if(Dev==DevP0) Dev3P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev3P1[i]=DevP1[i];
  }
  else
  if(dv==dv4)
  {
	if(Dev==DevP0) Dev4P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev4P1[i]=DevP1[i];
  }
  else
  if(dv==dv5)
  {
	if(Dev==DevP0) Dev5P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev5P1[i]=DevP1[i];
  }
  else
  if(dv==dv6)
  {
	if(Dev==DevP0) Dev6P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev6P1[i]=DevP1[i];
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AlgorithmBS(void)  // ������������ ����� ��
{
/*
  1) ����� ������� ��������� ���������� ������� ���������� �������� �������
  ������������ ������� ��������� � ���������� �������. ��� ����� �� ������� P0.1
  � P0.3 NI8451 ���������� ���������� �1� (�1� ������ ���� ����������� �����
  ������� �������� ���������������� ��� � ������ ���������� ������ �� �������
  ��������� ������ ����� �������).

  P0.1 - ������ ������� "�������� ������� ����������� ��������� ������", 0 � ���������, 1 � ��������
  P0.3 - ������ ������� "�������� ������� ����������� ���������� ������", 0 � ���������, 1 � ��������
*/
  try
  {
	if(!DigitalLineWrite(0, 1)) throw 1;
	if(!DigitalLineWrite(3, 1)) throw 2;
  }

  catch(...)
  {
	 Application->MessageBox(L"������ ������ � ���� ��!",L"��������",MB_ICONWARNING);
	 MainForm->SetFocus();
	 //exit(1);
  }
/*
  2) �������� ���������� ������� U���.+5�, ������ ���������� ���������� �� ������ AI6 NI6008.

  AI6 - ������ �������� ���������� ������� +5� [�]
*/



}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec1Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec1->Enabled=false;

  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[2]=1;                            // 1->DevP0[2]

  SetDevPN(VIP, DevP0, 2);               // if VIP DevP0[2]->Dev1P0[2]
  DevToP0P1(VIP);                        // if VIP Dev1PX[2]->Px[2]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // ������ �������� ������ VIP
	 T_Sec2->Enabled=true;                               // �������� 1 �
  }

  catch(...)
  {
	 Application->MessageBox(L"������ ������ � ���� ���!",L"��������",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec2Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec2->Enabled=false;

  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[0]=1;                            // 1->DevP0[2]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[2]->Dev1P0[2]
  DevToP0P1(VIP);                        // if VIP Dev1PX[2]->Px[2]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // ������ �������� ������ VIP
	 T_mSec1->Enabled=true;                              // �������� 200 ��
  }

  catch(...)
  {
	 Application->MessageBox(L"������ ������ � ���� ���!",L"��������",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_mSec1Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_mSec1->Enabled=false;

  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[0]=0;                            // 1->DevP0[2]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[2]->Dev1P0[2]
  DevToP0P1(VIP);                        // if VIP Dev1PX[2]->Px[2]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // ������ �������� ������ VIP
	 SB_OnOff->Enabled=true;
	 P_OneSec->Visible=false;
  }

  catch(...)
  {
	 Application->MessageBox(L"������ ������ � ���� ���!",L"��������",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_FreqRangeChange(TObject *Sender)
{
  if(CB_FreqRange->ItemIndex==0) range=D1;
  else
  if(CB_FreqRange->ItemIndex==1) range=D2;
  else
  if(CB_FreqRange->ItemIndex==2) range=D31;
  else
  if(CB_FreqRange->ItemIndex==3) range=D32;
  else
  if(CB_FreqRange->ItemIndex==4) range=D4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_FreqRangeExit(TObject *Sender)
{
  if(CB_FreqRange->ItemIndex==0) range=D1;
  else
  if(CB_FreqRange->ItemIndex==1) range=D2;
  else
  if(CB_FreqRange->ItemIndex==2) range=D31;
  else
  if(CB_FreqRange->ItemIndex==3) range=D32;
  else
  if(CB_FreqRange->ItemIndex==4) range=D4;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StartControl(void)
{
  //int PRM=dv1;
  //M_Debug->Lines->Add(PRM);

  switch(CB_Att_PRM->ItemIndex)
  {
	case 0:                                  // 0	1	0	0	0	0
	  SetPRMatt(1, 0, 0, 0, 0);
	  break;

	case 1:                                  // -1	0	0	0	0	0
	  SetPRMatt(0, 0, 0, 0, 0);
	  break;

	case 2:                                  // -2	0	1	0	0	0
	  SetPRMatt(0, 1, 0, 0, 0);
	  break;

	case 3:                                  // -3	1	1	0	0	0
	  SetPRMatt(1, 1, 0, 0, 0);
	  break;

	case 4:                                  // -4	0	0	1	0	0
	  SetPRMatt(0, 0, 1, 0, 0);
	  break;

	case 5:                                  // -5	1	0	1	0	0
	  SetPRMatt(1, 0, 1, 0, 0);
	  break;

	case 6:                                  // -6	0	1	1	0	0
	  SetPRMatt(0, 1, 1, 0, 0);
	  break;

	case 7:                                  // -7	1	1	1	0	0
	  SetPRMatt(1, 1, 1, 0, 0);
	  break;

	case 8:                                  // -8	0	0	0	1	0
	  SetPRMatt(0, 0, 0, 1, 0);
	  break;

	case 9:                                  // -9	1	0	0	1	0
	  SetPRMatt(1, 0, 0, 1, 0);
	  break;

	case 10:                                 // -10	0	1	0	1	0
	  SetPRMatt(0, 1, 0, 1, 0);
	  break;

	case 11:                                 // -11	1	1	0	1	0
	  SetPRMatt(1, 1, 0, 1, 0);
	  break;

	case 12:                                 // -12	0	0	1	1	0
	  SetPRMatt(0, 0, 1, 1, 0);
	  break;

	case 13:                                 // -13	1	0	1	1	0
	  SetPRMatt(1, 0, 1, 1, 0);
	  break;

	case 14:                                 // -14	0	1	1	1	0
	  SetPRMatt(0, 1, 1, 1, 0);
	  break;

	case 15:                                 // -15	1	1	1	1	0
	  SetPRMatt(1, 1, 1, 1, 0);
	  break;

	case 16:                                 // -16	0	0	0	0	1
	  SetPRMatt(0, 0, 0, 0, 1);
	  break;

	case 17:                                 // -17	1	0	0	0	1
	  SetPRMatt(1, 0, 0, 0, 1);
	  break;

	case 18:                                 // -18	0	1	0	0	1
	  SetPRMatt(0, 1, 0, 0, 1);
	  break;

	case 19:                                 // -19	1	1	0	0	1
	  SetPRMatt(1, 1, 0, 0, 1);
	  break;

	case 20:                                 // -20	0	0	1	0	1
	  SetPRMatt(0, 0, 1, 0, 1);
	  break;

	case 21:                                 // -21	1	0	1	0	1
	  SetPRMatt(1, 0, 1, 0, 1);
	  break;

	case 22:                                 // -22	0	1	1	0	1
	  SetPRMatt(0, 1, 1, 0, 1);
	  break;

	case 23:                                 // -23	1	1	1	0	1
	  SetPRMatt(1, 1, 1, 0, 1);
	  break;

	case 24:                                 // -24	0	0	0	1	1
	  SetPRMatt(0, 0, 0, 1, 1);
	  break;

	case 25:                                 // -25	1	0	0	1	1
	  SetPRMatt(1, 0, 0, 1, 1);
	  break;

	case 26:                                 // -26	0	1	0	1	1
	  SetPRMatt(0, 1, 0, 1, 1);
	  break;

	case 27:                                 // -27	1	1	0	1	1
	  SetPRMatt(1, 1, 0, 1, 1);
	  break;

	case 28:                                 // -28	0	0	1	1	1
	  SetPRMatt(0, 0, 1, 1, 1);
	  break;

	case 29:                                 // -29	1	0	1	1	1
	  SetPRMatt(1, 0, 1, 1, 1);
	  break;

	case 30:                                 // -30	0	1	1	1	1
	  SetPRMatt(0, 1, 1, 1, 1);
	  break;

	case 31:                                 // -31	1	1	1	1	1
	  SetPRMatt(1, 1, 1, 1, 1);
	  break;
  }

  switch(CB_Att_PRD->ItemIndex)
  {
	case 0:                                  // 0	1	0	0	0	0
	  SetPRDatt(1, 0, 0, 0, 0);
	  break;

	case 1:                                  // -1	0	0	0	0	0
	  SetPRDatt(0, 0, 0, 0, 0);
	  break;

	case 2:                                  // -2	0	1	0	0	0
	  SetPRDatt(0, 1, 0, 0, 0);
	  break;

	case 3:                                  // -3	1	1	0	0	0
	  SetPRDatt(1, 1, 0, 0, 0);
	  break;

	case 4:                                  // -4	0	0	1	0	0
	  SetPRDatt(0, 0, 1, 0, 0);
	  break;

	case 5:                                  // -5	1	0	1	0	0
	  SetPRDatt(1, 0, 1, 0, 0);
	  break;

	case 6:                                  // -6	0	1	1	0	0
	  SetPRDatt(0, 1, 1, 0, 0);
	  break;

	case 7:                                  // -7	1	1	1	0	0
	  SetPRDatt(1, 1, 1, 0, 0);
	  break;

	case 8:                                  // -8	0	0	0	1	0
	  SetPRDatt(0, 0, 0, 1, 0);
	  break;

	case 9:                                  // -9	1	0	0	1	0
	  SetPRDatt(1, 0, 0, 1, 0);
	  break;

	case 10:                                 // -10	0	1	0	1	0
	  SetPRDatt(0, 1, 0, 1, 0);
	  break;

	case 11:                                 // -11	1	1	0	1	0
	  SetPRDatt(1, 1, 0, 1, 0);
	  break;

	case 12:                                 // -12	0	0	1	1	0
	  SetPRDatt(0, 0, 1, 1, 0);
	  break;

	case 13:                                 // -13	1	0	1	1	0
	  SetPRDatt(1, 0, 1, 1, 0);
	  break;

	case 14:                                 // -14	0	1	1	1	0
	  SetPRDatt(0, 1, 1, 1, 0);
	  break;

	case 15:                                 // -15	1	1	1	1	0
	  SetPRDatt(1, 1, 1, 1, 0);
	  break;

	case 16:                                 // -16	0	0	0	0	1
	  SetPRDatt(0, 0, 0, 0, 1);
	  break;

	case 17:                                 // -17	1	0	0	0	1
	  SetPRDatt(1, 0, 0, 0, 1);
	  break;

	case 18:                                 // -18	0	1	0	0	1
	  SetPRDatt(0, 1, 0, 0, 1);
	  break;

	case 19:                                 // -19	1	1	0	0	1
	  SetPRDatt(1, 1, 0, 0, 1);
	  break;

	case 20:                                 // -20	0	0	1	0	1
	  SetPRDatt(0, 0, 1, 0, 1);
	  break;

	case 21:                                 // -21	1	0	1	0	1
	  SetPRDatt(1, 0, 1, 0, 1);
	  break;

	case 22:                                 // -22	0	1	1	0	1
	  SetPRDatt(0, 1, 1, 0, 1);
	  break;

	case 23:                                 // -23	1	1	1	0	1
	  SetPRDatt(1, 1, 1, 0, 1);
	  break;

	case 24:                                 // -24	0	0	0	1	1
	  SetPRDatt(0, 0, 0, 1, 1);
	  break;

	case 25:                                 // -25	1	0	0	1	1
	  SetPRDatt(1, 0, 0, 1, 1);
	  break;

	case 26:                                 // -26	0	1	0	1	1
	  SetPRDatt(0, 1, 0, 1, 1);
	  break;

	case 27:                                 // -27	1	1	0	1	1
	  SetPRDatt(1, 1, 0, 1, 1);
	  break;

	case 28:                                 // -28	0	0	1	1	1
	  SetPRDatt(0, 0, 1, 1, 1);
	  break;

	case 29:                                 // -29	1	0	1	1	1
	  SetPRDatt(1, 0, 1, 1, 1);
	  break;

	case 30:                                 // -30	0	1	1	1	1
	  SetPRDatt(0, 1, 1, 1, 1);
	  break;

	case 31:                                 // -31	1	1	1	1	1
	  SetPRDatt(1, 1, 1, 1, 1);
	  break;
  }

  switch(range)
  {
	case D1:                                  // �1 (0,9-1,7)	0	1	1	0	0
	  SetRange(0, 1, 1, 0, 0);
	  break;

	case D2:                                  // �2 (4,9-5,7)	1	1	0	1	0
	  SetRange(1, 1, 0, 1, 0);
	  break;

	case D31:                                 // �3.1 (7,1-7,9)	1	0	1	0	1
	  SetRange(1, 0, 1, 0, 1);
	  break;

	case D32:                                 // �3.2 (7,7-8,5) 1	0	1	0	1
	  SetRange(1, 0, 1, 0, 1);
	  break;

	case D4:                                  // �4 (9,2-10)	1	0	0	1	1
	  SetRange(1, 0, 0, 1, 1);
	  break;
  }

  NIDAQmxTimer->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetPRMchan(unsigned char* Dev, int i)
// ���������� ����� ���
{
  //int PRM=dv1;

  SetDevPN(PRM, Dev, i);                 // if PRM DevP0[]->Dev1P0[]
  DevToP0P1(PRM);                        // if PRM Dev1PX[]->Px[]

  SetDev_port(PRM);                      // if PRM Dev1_portX->Dev_portX
  try
  {
	if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // ������ �������� ������ PRM
  }

  catch(...)
  {
	Application->MessageBox(L"������ ������ � ���� ���!",L"��������",MB_ICONWARNING);
	//exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetPRMatt(int a, int b, int c, int d, int e)
// ���������� ���� ���
{
  DevP0[0]=a;                            // 1->DevP0[0]
  SetPRMchan(DevP0, 0);                  // ���������� ����� ���

  DevP0[1]=b;                            // 1->DevP0[1]
  SetPRMchan(DevP0, 1);                  // ���������� ����� ���

  DevP0[2]=c;                            // 1->DevP0[2]
  SetPRMchan(DevP0, 2);                  // ���������� ����� ���

  DevP0[3]=d;                            // 1->DevP0[3]
  SetPRMchan(DevP0, 3);                  // ���������� ����� ���

  DevP0[4]=e;                            // 1->DevP0[4]
  SetPRMchan(DevP0, 4);                  // ���������� ����� ���
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetPRDatt(int a, int b, int c, int d, int e)
// ���������� ���� ���
{
  DevP0[0]=a;                            // 1->DevP0[0]
  SetPRDchan(DevP0, 0);                  // ���������� ����� ���

  DevP0[1]=b;                            // 1->DevP0[1]
  SetPRDchan(DevP0, 1);                  // ���������� ����� ���

  DevP0[2]=c;                            // 1->DevP0[2]
  SetPRDchan(DevP0, 2);                  // ���������� ����� ���

  DevP0[3]=d;                            // 1->DevP0[3]
  SetPRDchan(DevP0, 3);                  // ���������� ����� ���

  DevP0[4]=e;                            // 1->DevP0[4]
  SetPRDchan(DevP0, 4);                  // ���������� ����� ���
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetPRDchan(unsigned char* Dev, int i)
// ���������� ����� ���
{
  SetDevPN(PRD, Dev, i);                 // if PRM DevP0[]->Dev1P0[]
  DevToP0P1(PRD);                        // if PRM Dev1PX[]->Px[]

  SetDev_port(PRD);                      // if PRM Dev1_portX->Dev_portX
  try
  {
	if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // ������ �������� ������ PRD
  }

  catch(...)
  {
	Application->MessageBox(L"������ ������ � ���� ���!",L"��������",MB_ICONWARNING);
	//exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetRange(int a, int b, int c, int d, int e)
// ���������� ���� ��� � ���
{
  DevP0[5]=a;                            // 1->DevP0[5]
  SetPRMchan(DevP0, 5);                  // ���������� ����� ���
  SetPRDchan(DevP0, 5);                  // ���������� ����� ���

  DevP0[6]=b;                            // 1->DevP0[6]
  SetPRMchan(DevP0, 6);                  // ���������� ����� ���
  SetPRDchan(DevP0, 6);                  // ���������� ����� ���

  DevP0[7]=c;                            // 1->DevP0[7]
  SetPRMchan(DevP0, 7);                  // ���������� ����� ���
  SetPRDchan(DevP0, 7);                  // ���������� ����� ���

  DevP1[0]=d;                            // 1->DevP1[0]
  SetPRMchan(DevP1, 0);                  // ���������� ����� ���
  SetPRDchan(DevP1, 0);                  // ���������� ����� ���

  DevP1[1]=e;                            // 1->DevP1[1]
  SetPRMchan(DevP1, 1);                  // ���������� ����� ���
  SetPRDchan(DevP1, 1);                  // ���������� ����� ���
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NIDAQmxTimerTimer(TObject *Sender)
{
  GoNIDAQmx();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GoNIDAQmx()
{
  float value;
  float min,max;
  NIDAQmxCounter++;
  //int PRM=dv1;
  //int VIP=dv1;
  //int UU=dv1;
  //int BS=dv1;
  //int FRLP=dv1;

  switch(NIDAQmxCounter)
  {

	// ���
	case 0:                                    // ���������� ������� ��������� +5 � �������� [�]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai0);            // ��������� AI0 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up5B->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_1->Color=BadColor;
		 P_Up5B->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
	  {
         P_1->Color=GoodColor;
		 P_Up5B->Color=GoodColor;
      }

      break;

	case 1:                                    // ���������� ������� ��������� +12 � �������� [�]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai1);            // ��������� AI1 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up12B->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_2->Color=BadColor;
		 P_Up12B->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
      {
         P_2->Color=GoodColor;
         P_Up12B->Color=GoodColor;
      }

      break;

    case 2:                                    // �������� ������� �������� [���]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai2);            // ��������� AI2 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Pprm->Caption=FloatToStrF(value,ffFixed,5,2)+" ���"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_3->Color=BadColor;
		 P_Pprm->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
      {
         P_3->Color=GoodColor;
		 P_Pprm->Color=GoodColor;
      }

	  break;

	case 3:                                    // ���������� ������� ��������� -5 � �������� [�]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai4);            // ��������� AI4 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Um5B->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_4->Color=BadColor;
		 P_Um5B->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
      {
         P_4->Color=GoodColor;
         P_Um5B->Color=GoodColor;
      }

      break;

	case 4:                                    // ��� ������� ��������� +27 � �������� [�]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai5);            // ��������� AI5 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Ip27B->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_5->Color=BadColor;
		 P_Ip27B->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
      {
         P_5->Color=GoodColor;
         P_Ip27B->Color=GoodColor;
	  }

	  break;

	// ���
	case 5:                                    // ���������� ������� ��������� +5 � �������� [�]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai0);            // ��������� AI0 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up5BD->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_1D->Color=BadColor;
		 P_Up5BD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_1D->Color=GoodColor;
		 P_Up5BD->Color=GoodColor;
      }

      break;

	case 6:                                    // ���������� ������� ��������� +12 � �������� [�]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai1);            // ��������� AI1 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up12BD->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
		 P_2D->Color=BadColor;
		 P_Up12BD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
	  {
		 P_2D->Color=GoodColor;
		 P_Up12BD->Color=GoodColor;
	  }

      break;

	case 7:                                    // �������� ������� �������� [���]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai2);            // ��������� AI2 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_PprmD->Caption=FloatToStrF(value,ffFixed,5,2)+" ���"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
		 P_3D->Color=BadColor;
		 P_PprmD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
	  {
		 P_3D->Color=GoodColor;
		 P_PprmD->Color=GoodColor;
	  }

	  break;

	case 8:                                    // ���������� ������� ��������� -5 � �������� [�]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai4);            // ��������� AI4 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Um5BD->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
		 P_4D->Color=BadColor;
		 P_Um5BD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
	  {
		 P_4D->Color=GoodColor;
		 P_Um5BD->Color=GoodColor;
	  }

      break;

	case 9:                                    // ��� ������� ��������� +27 � �������� [�]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai5);            // ��������� AI5 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Ip27BD->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
		 P_5D->Color=BadColor;
		 P_Ip27BD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // �������� � ������ ��������
	  {
		 P_5D->Color=GoodColor;
		 P_Ip27BD->Color=GoodColor;
	  }

	  break;

	// ���
	case 10:                                   // ���������� ������� ��������� +12 � [�]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai0);            // ��������� AI0 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up12BV->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_1V->Color=BadColor;
		 P_Up12BV->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_1V->Color=GoodColor;
		 P_Up12BV->Color=GoodColor;
	  }

	  break;

	case 11:                                   // ���������� ������� ��������� +27 � [�]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai1);            // ��������� AI1 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up27BV->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_2V->Color=BadColor;
		 P_Up27BV->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // �������� � ������ ��������
	  {
		 P_2V->Color=GoodColor;
		 P_Up27BV->Color=GoodColor;
	  }

	  break;

	case 12:                                   // ��� ��������� ����������� [�]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai2);            // ��������� AI2 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Ivprd->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_3V->Color=BadColor;
		 P_Ivprd->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // �������� � ������ ��������
	  {
		 P_3V->Color=GoodColor;
		 P_Ivprd->Color=GoodColor;
	  }

	  break;

	case 13:                                   // ���������� ������� ��������� +5 � [�]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai4);            // ��������� AI4 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up5BV->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_4V->Color=BadColor;
		 P_Up5BV->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // �������� � ������ ��������
	  {
		 P_4V->Color=GoodColor;
		 P_Up5BV->Color=GoodColor;
	  }

	  break;

	case 14:                                   // ��� ��������� �������� [�]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai5);            // ��������� AI5 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Ivprm->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_5V->Color=BadColor;
		 P_Ivprm->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_5V->Color=GoodColor;
		 P_Ivprm->Color=GoodColor;
	  }

	  break;

	// ��
	case 15:                                   // ���������� ������� ��������� +5 � [�]
	  value=0;
	  SetDev_ai(UU);
	  value=GetDevACDData(Dev_ai0);            // ��������� AI0 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up5BU->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_1U->Color=BadColor;
		 P_Up5BU->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_1U->Color=GoodColor;
		 P_Up5BU->Color=GoodColor;
      }

      break;

	case 16:                                   // �������� ���������� ������� ���� [�]
	  value=0;
	  SetDev_ai(UU);
	  value=GetDevACDData(Dev_ai1);            // ��������� AI1 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_I->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
		 P_2U->Color=BadColor;
		 P_I->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
	  {
		 P_2U->Color=GoodColor;
		 P_I->Color=GoodColor;
	  }

      break;

	case 17:                                   // ���������� ������� ��������� +12 � [�]
	  value=0;
	  SetDev_ai(UU);
	  value=GetDevACDData(Dev_ai4);            // ��������� AI4 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up12BU->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
		 P_3U->Color=BadColor;
		 P_Up12BU->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // �������� � ������ ��������
	  {
		 P_3U->Color=GoodColor;
		 P_Up12BU->Color=GoodColor;
	  }

	  break;

	// ��
	case 18:                                   // ������ ����������� ��������� ������ [����.]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai0);            // ��������� AI0 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_To->Caption=FloatToStrF(value,ffFixed,5,2)+" ����."; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_1B->Color=BadColor;
		 P_To->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_1B->Color=GoodColor;
		 P_To->Color=GoodColor;
	  }

	  break;

	case 19:                                   // ������ ����������� ���������� ������ [����.]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai1);            // ��������� AI1 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Tr->Caption=FloatToStrF(value,ffFixed,5,2)+" ����."; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_2B->Color=BadColor;
		 P_Tr->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // �������� � ������ ��������
	  {
		 P_2B->Color=GoodColor;
		 P_Tr->Color=GoodColor;
	  }

	  break;

	case 20:                                   // ���������� ������� -5� [�]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai2);            // ��������� AI2 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Um5BB->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_3B->Color=BadColor;
		 P_Um5BB->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // �������� � ������ ��������
	  {
		 P_3B->Color=GoodColor;
		 P_Um5BB->Color=GoodColor;
	  }

	  break;

	case 21:                                   // ��� ����������� �� +27� [�]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai3);            // ��������� AI3 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Ip27BB->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_4B->Color=BadColor;
		 P_Ip27BB->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_4B->Color=GoodColor;
		 P_Ip27BB->Color=GoodColor;
	  }

	  break;

	case 22:                                   // �������� ������� ������������ ������ ��������� ������ [��]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai4);            // ��������� AI4 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Po->Caption=FloatToStrF(value,ffFixed,5,2)+" ��"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_5B->Color=BadColor;
		 P_Po->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_5B->Color=GoodColor;
		 P_Po->Color=GoodColor;
	  }

	  break;

	case 23:                                   // �������� ������� ������������ ������ ���������� ������ [��]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai5);            // ��������� AI5 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Pr->Caption=FloatToStrF(value,ffFixed,5,2)+" ��"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_6B->Color=BadColor;
		 P_Pr->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_6B->Color=GoodColor;
		 P_Pr->Color=GoodColor;
	  }

	  break;

	case 24:                                   // ���������� ������� +5� [�]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai6);            // ��������� AI6 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Up5BB->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_7B->Color=BadColor;
		 P_Up5BB->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_7B->Color=GoodColor;
		 P_Up5BB->Color=GoodColor;
	  }

	  break;

	// ����
	case 25:                                   // ���������� ������� ���� [�], ��� ���. ����� - 5 � (+4,85�+5,15 �)
	  value=0;
	  SetDev_ai(FRLP);
	  value=GetDevACDData(Dev_ai0);            // ��������� AI0 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Uucps->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_1F->Color=BadColor;
		 P_Uucps->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_1F->Color=GoodColor;
		 P_Uucps->Color=GoodColor;
	  }

	  break;

	case 26:                                   // ������ ����������� [����.]
	  value=0;
	  SetDev_ai(FRLP);
	  value=GetDevACDData(Dev_ai1);            // ��������� AI1 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_T->Caption=FloatToStrF(value,ffFixed,5,2)+" ����."; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_2F->Color=BadColor;
		 P_T->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_2F->Color=GoodColor;
		 P_T->Color=GoodColor;
	  }

	  break;

	case 27:                                   // ��� ����������� +27 � ����� ���� [�]
	  value=0;
	  SetDev_ai(FRLP);
	  value=GetDevACDData(Dev_ai4);            // ��������� AI4 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Ip27BF->Caption=FloatToStrF(value,ffFixed,5,2)+" �"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_3F->Color=BadColor;
		 P_Ip27BF->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_3F->Color=GoodColor;
		 P_Ip27BF->Color=GoodColor;
	  }

	  break;

	case 28:                                   // ���������� ����������� ������ ��������� [���]
	  value=0;
	  SetDev_ai(FRLP);
	  value=GetDevACDData(Dev_ai5);            // ��������� AI5 �� NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
	  min=-10;                                // ��������� �������� ����������
	  max=10;

	  P_Udet->Caption=FloatToStrF(value,ffFixed,5,2)+" ���"; // 2 ���������� ����� ����� �������

	  if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
	  {
		 P_4F->Color=BadColor;
		 P_Udet->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // �������� � ������ ��������
	  {
		 P_4F->Color=GoodColor;
		 P_Udet->Color=GoodColor;
	  }

	  NIDAQmxCounter=-1;                       // ������ ������ ������
	  break;

  }
  PanelColor();
  //NIDAQmxTimer->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DefaultPanel()
{
  // ���
  P_PRM->Color=DefaultColor;
  P_1->Color=DefaultColor;
  P_2->Color=DefaultColor;
  P_3->Color=DefaultColor;
  P_4->Color=DefaultColor;
  P_5->Color=DefaultColor;

  P_Up5B->Color=DefaultColor;
  P_Up12B->Color=DefaultColor;
  P_Pprm->Color=DefaultColor;
  P_Um5B->Color=DefaultColor;
  P_Ip27B->Color=DefaultColor;

  P_Up5B->Caption="0 �";
  P_Up12B->Caption="0 �";
  P_Pprm->Caption="0 ���";
  P_Um5B->Caption="0 �";
  P_Ip27B->Caption="0 �";

  // ���
  P_PRD->Color=DefaultColor;
  P_1D->Color=DefaultColor;
  P_2D->Color=DefaultColor;
  P_3D->Color=DefaultColor;
  P_4D->Color=DefaultColor;
  P_5D->Color=DefaultColor;

  P_Up5BD->Color=DefaultColor;
  P_Up12BD->Color=DefaultColor;
  P_PprmD->Color=DefaultColor;
  P_Um5BD->Color=DefaultColor;
  P_Ip27BD->Color=DefaultColor;

  P_Up5BD->Caption="0 �";
  P_Up12BD->Caption="0 �";
  P_PprmD->Caption="0 ���";
  P_Um5BD->Caption="0 �";
  P_Ip27BD->Caption="0 �";

  // ���
  P_VK_PRD1->Color=DefaultColor;
  P_VK_PRD2->Color=DefaultColor;
  P_VK_PRM->Color=DefaultColor;
  P_1V->Color=DefaultColor;
  P_2V->Color=DefaultColor;
  P_3V->Color=DefaultColor;
  P_4V->Color=DefaultColor;
  P_5V->Color=DefaultColor;

  P_Up12BV->Color=DefaultColor;
  P_Up27BV->Color=DefaultColor;
  P_Ivprd->Color=DefaultColor;
  P_Up5BV->Color=DefaultColor;
  P_Ivprm->Color=DefaultColor;

  P_Up12BV->Caption="0 �";
  P_Up27BV->Caption="0 �";
  P_Ivprd->Caption="0 �";
  P_Up5BV->Caption="0 �";
  P_Ivprm->Caption="0 �";

  // ��
  P_UU->Color=DefaultColor;
  P_1U->Color=DefaultColor;
  P_2U->Color=DefaultColor;
  P_3U->Color=DefaultColor;

  P_Up5BU->Color=DefaultColor;
  P_I->Color=DefaultColor;
  P_Up12BU->Color=DefaultColor;

  P_Up5BU->Caption="0 �";
  P_I->Caption="0 �";
  P_Up12BU->Caption="0 �";

  // ��
  P_BS->Color=DefaultColor;
  P_1B->Color=DefaultColor;
  P_2B->Color=DefaultColor;
  P_3B->Color=DefaultColor;
  P_4B->Color=DefaultColor;
  P_5B->Color=DefaultColor;
  P_6B->Color=DefaultColor;
  P_7B->Color=DefaultColor;

  P_To->Color=DefaultColor;
  P_Tr->Color=DefaultColor;
  P_Um5BB->Color=DefaultColor;
  P_Ip27BB->Color=DefaultColor;
  P_Po->Color=DefaultColor;
  P_Pr->Color=DefaultColor;
  P_Up5BB->Color=DefaultColor;

  P_To->Caption="0 ����.";
  P_Tr->Caption="0 ����.";
  P_Um5BB->Caption="0 �";
  P_Ip27BB->Caption="0 �";
  P_Po->Caption="0 ��";
  P_Pr->Caption="0 ��";
  P_Up5BB->Caption="0 �";

  // ����
  P_FRLP->Color=DefaultColor;
  P_1F->Color=DefaultColor;
  P_2F->Color=DefaultColor;
  P_3F->Color=DefaultColor;
  P_4F->Color=DefaultColor;

  P_Uucps->Color=DefaultColor;
  P_T->Color=DefaultColor;
  P_Ip27BF->Color=DefaultColor;
  P_Udet->Color=DefaultColor;

  P_Uucps->Caption="0 �";
  P_T->Caption="0 ����.";
  P_Ip27BF->Caption="0 �";
  P_Udet->Caption="0 ���";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PanelColor()
{
  // ���
  if(P_1->Color==GoodColor&&P_2->Color==GoodColor&&P_3->Color==GoodColor&&P_4->Color==GoodColor&&P_5->Color==GoodColor)
  {
	P_PRM->Color=GoodColor;
  }
  else
  {
	P_PRM->Color=BadColor;
  }

  if(P_1->Color==BadColor||P_2->Color==BadColor||P_3->Color==BadColor||P_4->Color==BadColor||P_5->Color==BadColor)
  {
	Application->MessageBox(L"���� ��� �� ������� ��� ����������!",L"��������",MB_ICONWARNING);
  }

  // ���
  if(P_1D->Color==GoodColor&&P_2D->Color==GoodColor&&P_3D->Color==GoodColor&&P_4D->Color==GoodColor&&P_5D->Color==GoodColor)
  {
	P_PRD->Color=GoodColor;
  }
  else
  {
	P_PRD->Color=BadColor;
  }

  if(P_1D->Color==BadColor||P_2D->Color==BadColor||P_3D->Color==BadColor||P_4D->Color==BadColor||P_5D->Color==BadColor)
  {
	Application->MessageBox(L"���� ��� �� ������� ��� ����������!",L"��������",MB_ICONWARNING);
  }

  // ���
  // ��-���
  if(range==D1||range==D2)
  {
	if(P_3V->Color==GoodColor)
	{
	  P_VK_PRD1->Color=GoodColor;
	}
	else
	{
	  P_VK_PRD1->Color=BadColor;
	}
  }
  else
  if(range==D31||range==D32||range==D4)
  {
	if(P_3V->Color==GoodColor)
	{
	  P_VK_PRD2->Color=GoodColor;
	}
	else
	{
	  P_VK_PRD2->Color=BadColor;
	}
  }
  if(P_3V->Color==BadColor)
  {
	Application->MessageBox(L"���� ��-��� �� ������� ��� ����������!",L"��������",MB_ICONWARNING);
  }

  // ��-���
  if(P_5V->Color==GoodColor)
  {
	P_VK_PRM->Color=GoodColor;
  }
  else
  if(P_5V->Color==BadColor)
  {
	P_VK_PRM->Color=BadColor;
	Application->MessageBox(L"���� ��-��� �� ������� ��� ����������!",L"��������",MB_ICONWARNING);
  }

  // ���������
  if(P_1V->Color==BadColor||P_2V->Color==BadColor||P_3V->Color==BadColor)
  {
	Application->MessageBox(L"���� ��� �� ������� ��� ����������!",L"��������",MB_ICONWARNING);
  }

  // ��
  if(P_1U->Color==GoodColor&&P_2U->Color==GoodColor&&P_3U->Color==GoodColor)
  {
	P_UU->Color=GoodColor;
  }
  else
  {
	P_UU->Color=BadColor;
  }

  if(P_1U->Color==BadColor||P_2U->Color==BadColor||P_3U->Color==BadColor)
  {
	Application->MessageBox(L"���� �� �� ������� ��� ����������!",L"��������",MB_ICONWARNING);
  }

  // ��
  if(P_1B->Color==GoodColor&&P_2B->Color==GoodColor&&P_3B->Color==GoodColor&&P_4B->Color==GoodColor&&P_5B->Color==GoodColor&&P_6B->Color==GoodColor&&P_7B->Color==GoodColor)
  {
	P_BS->Color=GoodColor;
  }
  else
  {
	P_BS->Color=BadColor;
  }

  if(P_1B->Color==BadColor||P_2B->Color==BadColor||P_3B->Color==BadColor||P_4B->Color==BadColor||P_5B->Color==BadColor||P_6B->Color==BadColor||P_7B->Color==BadColor)
  {
	Application->MessageBox(L"���� �� �� ������� ��� ����������!",L"��������",MB_ICONWARNING);
  }

  // ����
  if(P_1F->Color==GoodColor&&P_2F->Color==GoodColor&&P_3F->Color==GoodColor&&P_4F->Color==GoodColor)
  {
	P_FRLP->Color=GoodColor;
  }
  else
  {
	P_FRLP->Color=BadColor;
  }

  if(P_1F->Color==BadColor||P_2F->Color==BadColor||P_3F->Color==BadColor||P_4F->Color==BadColor)
  {
	Application->MessageBox(L"���� ���� �� ������� ��� ����������!",L"��������",MB_ICONWARNING);
  }

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Command6Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Command6->ItemIndex==i) Command6[3]=i;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CB_Command6Exit(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Command6->ItemIndex==i) Command6[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_SendClick(TObject *Sender)
{
  ComPortTransmitter();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_ComNumChange(TObject *Sender)
{
  CommPort1->ComNumber = CB_ComNum->ItemIndex+1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_BaudRateChange(TObject *Sender)
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
//---------------------------------------------------------------------------
void __fastcall TMainForm::ComPortTransmitter()
{
  CommPort1->Open=true;

  if(CommPort1->BaudRate==cbr9600)               // �������� �� Serial Input/Output Monitor
  {
    SendTerminal();
  }
  else                                           // �������� �� ����-2, BaudRate=57600
  {
    //CommPort1->PutChar(0xAA);                  // ������ �������� �� ���������� (�������)

	if(RG_Mode->ItemIndex==0)                    // ���� ����� "����������"
    {
      SendControl();
    }
	else                                         // ���� ����� "������������"
    {
	  SendTesting();
    }
  }
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SendTerminal()
{
  AddSaveLog("�������� ������� �� ��������");  // �������� ����������� � ��������� ���

  if(ChB_Command3->Checked==false)
  {
    CommPort1->PutString("Command3 = ");
    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // �������� ������ ��
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Command3[i][0]);  // ���� ���� �������
      uart_puthex_byte((char)Command3[i][1]);  // 1-� ���� ������ ������
      uart_puthex_byte((char)Command3[i][2]);  // 2-� ���� ������ ������
      uart_puthex_byte((char)Command3[i][3]);  // 3-� ���� ������ ������

      CommPort1->PutChar(0x0d);                // ������� �������
      CommPort1->PutChar(0x0a);                // ������� �� ��������� ������
    }

    CommPort1->PutString("Command4 = ");
    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // �������� ������ ��
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Command4[i][0]);  // ���� ���� �������
      uart_puthex_byte((char)Command4[i][1]);  // 1-� ���� ������ ������
      uart_puthex_byte((char)Command4[i][2]);  // 2-� ���� ������ ������
      uart_puthex_byte((char)Command4[i][3]);  // 3-� ���� ������ ������

      CommPort1->PutChar(0x0d);                // ������� �������
      CommPort1->PutChar(0x0a);                // ������� �� ��������� ������
    }

    CommPort1->PutString("Command5 = ");
    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // �������� ������ ��
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Command5[i][0]);  // ���� ���� �������
      uart_puthex_byte((char)Command5[i][1]);  // 1-� ���� ������ ������
      uart_puthex_byte((char)Command5[i][2]);  // 2-� ���� ������ ������
      uart_puthex_byte((char)Command5[i][3]);  // 3-� ���� ������ ������

      CommPort1->PutChar(0x0d);                // ������� �������
      CommPort1->PutChar(0x0a);                // ������� �� ��������� ������
    }
  }

  if(ChB_Command6->Checked==false)
  {
    CommPort1->PutString("Command6 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command6[i]);
    }
  }
  CommPort1->PutChar(0x0d);                    // ������� �������
  CommPort1->PutChar(0x0a);                    // ������� �� ��������� ������

  if(ChB_Command7->Checked==false)
  {
    CommPort1->PutString("Command7 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command7[i]);
    }
  }
  CommPort1->PutChar(0x0d);                    // ������� �������
  CommPort1->PutChar(0x0a);                    // ������� �� ��������� ������

  if(ChB_Com3->Checked==false)
  {
    CommPort1->PutString("Com3 = ");
    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // �������� ������ ��
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Com3[i][0]);      // ���� ���� �������
      uart_puthex_byte((char)Com3[i][1]);      // 1-� ���� ������ ������
      uart_puthex_byte((char)Com3[i][2]);      // 2-� ���� ������ ������
      uart_puthex_byte((char)Com3[i][3]);      // 3-� ���� ������ ������

      CommPort1->PutChar(0x0d);                // ������� �������
      CommPort1->PutChar(0x0a);                // ������� �� ��������� ������
    }

    CommPort1->PutString("Com4 = ");
    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // �������� ������ ��
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Com4[i][0]);      // ���� ���� �������
      uart_puthex_byte((char)Com4[i][1]);      // 1-� ���� ������ ������
      uart_puthex_byte((char)Com4[i][2]);      // 2-� ���� ������ ������
      uart_puthex_byte((char)Com4[i][3]);      // 3-� ���� ������ ������

      CommPort1->PutChar(0x0d);                // ������� �������
      CommPort1->PutChar(0x0a);                // ������� �� ��������� ������
    }

    CommPort1->PutString("Com5 = ");
    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // �������� ������ ��
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Com5[i][0]);      // ���� ���� �������
      uart_puthex_byte((char)Com5[i][1]);      // 1-� ���� ������ ������
      uart_puthex_byte((char)Com5[i][2]);      // 2-� ���� ������ ������
      uart_puthex_byte((char)Com5[i][3]);      // 3-� ���� ������ ������

      CommPort1->PutChar(0x0d);                // ������� �������
      CommPort1->PutChar(0x0a);                // ������� �� ��������� ������
    }
  }

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

  if(ChB_Com21->Checked==false)
  {
	CommPort1->PutString("Com21 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com21[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
  }

  if(ChB_Com22->Checked==false)
  {
	CommPort1->PutString("Com22 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com22[i]);
    }

    CommPort1->PutChar(0x0d);                  // ������� �������
    CommPort1->PutChar(0x0a);                  // ������� �� ��������� ������
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
void __fastcall TMainForm::uart_puti( signed int val )
 { unsigned char buffer[8];

   itoa(val, buffer);
   uart_puts( buffer );
 }/* uart_puti */
 /*************************************************************************
 itoa:  ������������ n � ������� � s
**************************************************************************/
void __fastcall TMainForm::itoa(signed int n, unsigned char s[])
{
   Bin_to_dec (s, n);
}
/*----------------------------------------------------------------------------*/
/* �������:    �������������� BIN->DEC 's[]'                                  */
/* ���������:  �������� �����                                                 */
/* ����������: ������ (�������� ���������� ����������)                        */
/*----------------------------------------------------------------------------*/
void __fastcall TMainForm::Bin_to_dec (unsigned char s[],     // �����
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
void __fastcall TMainForm::uart_puts(unsigned char *s )
 { while (*s)
	  CommPort1->PutChar(*s++);  // ������� ������������� ��� �������
 } /* uart_puts */
/*************************************************************************
Function: uart_puthex_byte()
Purpose:  transmit upper and lower nibble as ASCII-hex to UART
Input:    byte value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TMainForm::uart_puthex_byte(unsigned char  b)
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
void __fastcall TMainForm::uart_puthex_nibble(unsigned char b)
 { unsigned char  c = b & 0x0f;
   if (c>9) c += 'A'-10;
   else c += '0';
   CommPort1->PutChar(c);  // ������� ������������� ��� �������
 } /* uart_puthex_nibble */
//---------------------------------------------------------------------------
void __fastcall TMainForm::SendControl()
{
  AddSaveLog("�������� ������� � ������ ����������");  // �������� ����������� � ��������� ���

  if(ChB_Command3->Checked==false)
  {
    for(int i=0; i<64; i++)
    {
      CommPort1->PutChar((char)Command3[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Command3[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Command3[i][2]);  // 2-� ���� ������ ������
      CommPort1->PutChar((char)Command3[i][3]);  // 3-� ���� ������ ������

      Delay();                                   // ��������

      CommPort1->PutChar((char)Command4[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Command4[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Command4[i][2]);  // 2-� ���� ������ ������
      CommPort1->PutChar((char)Command4[i][3]);  // 3-� ���� ������ ������

      Delay();                                   // ��������

      //int Comm5=(Command5[i][3]+Command5[i][2]*256)/0.5; // ���� �������� ������� 0.5 ��
      int Comm5=(Command5[i][3]+Command5[i][2]*256);
      int Comm5_LSB[64], Comm5_MSB[64];

      if(D_SignC[i]==1)
      {
        Comm5=~Comm5+1;
      }

      Comm5_LSB[i]=Comm5&0xFF;                   // ��. ����
      Comm5_MSB[i]=(Comm5>>8)&0xFF;              // ��. ���� (���� /256, ������������� ��� ��������� ������)

      CommPort1->PutChar((char)Command5[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Command5[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Comm5_MSB[i]);    // 2-� ���� ������ ������
      CommPort1->PutChar((char)Comm5_LSB[i]);    // 3-� ���� ������ ������

      Delay();                                   // ��������
    }
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Shift[i]);
    }
    Delay();                                     // ��������
  }

  if(ChB_Command6->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command6[i]);
    }
    Delay();                                     // ��������
  }

  if(ChB_Command7->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command7[i]);
    }
    Delay();                                     // ��������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SendTesting()
{
  AddSaveLog("�������� ������� � ������ ������������");  // �������� ����������� � ��������� ���

  if(ChB_Com3->Checked==false)
  {
    for(int i=0; i<64; i++)
    {
      CommPort1->PutChar((char)Com3[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Com3[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Com3[i][2]);  // 2-� ���� ������ ������
      CommPort1->PutChar((char)Com3[i][3]);  // 3-� ���� ������ ������

      Delay();                               // ��������

      CommPort1->PutChar((char)Com4[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Com4[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Com4[i][2]);  // 2-� ���� ������ ������
      CommPort1->PutChar((char)Com4[i][3]);  // 3-� ���� ������ ������

      Delay();                               // ��������

      //int Comm5=(Com5[i][3]+Com5[i][2]*256)/0.5; // ���� �������� ������� 0.5 ��
      int Comm5=(Com5[i][3]+Com5[i][2]*256);
      int Comm5_LSB[64], Comm5_MSB[64];

      if(D_SignT[i]==1)
      {
        Comm5=~Comm5+1;
      }

      Comm5_LSB[i]=Comm5&0xFF;               // ��. ����
      Comm5_MSB[i]=(Comm5>>8)&0xFF;          // ��. ���� (���� /256, ������������� ��� ��������� ������)

      CommPort1->PutChar((char)Com5[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Com5[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Comm5_MSB[i]);// 2-� ���� ������ ������
      CommPort1->PutChar((char)Comm5_LSB[i]);// 3-� ���� ������ ������

      Delay();                               // ��������
    }
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Shift_[i]);
    }
    Delay();                                 // ��������
  }

  if(ChB_Com6->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com6[i]);
    }
    Delay();                                 // ��������
  }

  if(ChB_Com7->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com7[i]);
    }
    Delay();                                 // ��������
  }

  if(ChB_Com8->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com8[i]);
    }
    Delay();                                 // ��������
  }

  if(ChB_Com9->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com9[i]);
    }
    Delay();                                 // ��������
  }

  if(ChB_Com10->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com10[i]);
    }
    Delay();                                 // ��������
  }

  if(ChB_Com11->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com11[i]);
    }
    Delay();                                 // ��������
  }

  if(ChB_Com13->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com20[i]);
    }
    Delay();                                 // ��������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com19[i]);
    }
    Delay();                                 // ��������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com18[i]);
    }
    Delay();                                 // ��������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com17[i]);
    }
    Delay();                                 // ��������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com16[i]);
    }
    Delay();                                 // ��������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com15[i]);
    }
    Delay();                                 // ��������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com14[i]);
    }
    Delay();                                 // ��������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com13[i]);
    }
    Delay();                                 // ��������
  }

  if(ChB_Com21->Checked==false)
  {
	for(int i=0; i<4; i++)
	{
	  CommPort1->PutChar((char)Com21[i]);
	}
	Delay();                                 // ��������
  }

  if(ChB_Com22->Checked==false)
  {
	for(int i=0; i<4; i++)
	{
	  CommPort1->PutChar((char)Com22[i]);
	}
	Delay();                                 // ��������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Delay(void)       // ������� ��������
{
  Sleep(delay_ms);                           // �������� � ��
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com21Change(TObject *Sender)
{
  if(CB_Com21->ItemIndex<257)
  {
	for(int i=0; i<257; i++)
    {
	  int code;
	  if(CB_Com21->ItemIndex==i) code=256-i;      // ��������� ���� ���������
      int code_LSB=code&0xFF;                     // ������� ���� ���������
      int code_MSB=(code/256)&0xFF;               // ������� ���� ���������
	  Com21[2]=code_MSB;                          // �������� �������� �������� ����� ���������
	  Com21[3]=code_LSB;                          // �������� �������� �������� ����� ���������
    }
  }

  if(CB_Com21->ItemIndex>=257)
  {
    for(int i=257; i<514; i++)
    {
      long int code;
	  if(CB_Com21->ItemIndex==i) code=65535+257-i;  // ��������� ���� ���������
	  int code_LSB=code&0xFF;                       // ������� ���� ���������
	  int code_MSB=(code/256)&0xFF;                 // ������� ���� ���������
	  Com21[2]=code_MSB;                            // �������� �������� �������� ����� ���������
	  Com21[3]=code_LSB;                            // �������� �������� �������� ����� ���������
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com22Change(TObject *Sender)
{
  if(CB_Com22->ItemIndex<257)
  {
	for(int i=0; i<257; i++)
    {
	  int code;
	  if(CB_Com22->ItemIndex==i) code=256-i;      // ��������� ���� ���������
      int code_LSB=code&0xFF;                     // ������� ���� ���������
      int code_MSB=(code/256)&0xFF;               // ������� ���� ���������
	  Com22[2]=code_MSB;                          // �������� �������� �������� ����� ���������
	  Com22[3]=code_LSB;                          // �������� �������� �������� ����� ���������
    }
  }

  if(CB_Com22->ItemIndex>=257)
  {
    for(int i=257; i<514; i++)
    {
      long int code;
	  if(CB_Com22->ItemIndex==i) code=65535+257-i;  // ��������� ���� ���������
	  int code_LSB=code&0xFF;                       // ������� ���� ���������
	  int code_MSB=(code/256)&0xFF;                 // ������� ���� ���������
	  Com22[2]=code_MSB;                            // �������� �������� �������� ����� ���������
	  Com22[3]=code_LSB;                            // �������� �������� �������� ����� ���������
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StopControl(void)
{
  NIDAQmxTimer->Enabled=false;
  DefaultPanel();
}
//---------------------------------------------------------------------------

