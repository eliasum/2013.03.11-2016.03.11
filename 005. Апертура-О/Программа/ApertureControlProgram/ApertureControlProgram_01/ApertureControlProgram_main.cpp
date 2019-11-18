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
using namespace std;

#define NUMBEROFPOINTS 64

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
unsigned char P0[8],P1[4];       // ����� ������ ��� �������� ������
const int NumReadValue=10;
bool ErrorADC;

// ���������� �������� ���������
TColor DefaultColor=clSilver;    // clBtnFace
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

float value;

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

/*
 �������� ������ ����������� ����� ����������� ���������� (��)
 � ������ ��� ����� ���� �� ���������� RS-232 �� 28.02.14.
*/
int Command3[NUMBEROFPOINTS][4];
int Shift[4]={3, 255, 0, 0};     // ������� "����� ��������"
int Command4[NUMBEROFPOINTS][4];
int Command5[NUMBEROFPOINTS][4];
int D_SignC[NUMBEROFPOINTS];     // ���� ������������� �������� ��
int Command6[4]={6, 0, 0, 0};
int Command7[4]={7, 0, 0, 63};

int Com3[NUMBEROFPOINTS][4];
int Shift_[4]={227, 255, 0, 0};  // ������� "����� ��������"
int Com4[NUMBEROFPOINTS][4];
int Com5[NUMBEROFPOINTS][4];
int D_SignT[NUMBEROFPOINTS];     // ���� ������������� �������� ��
int Com6[4]={230, 0, 0, 31};
int Com7[4]={231, 0, 0, 63};
int Com8[4]={232, 0, 7, 142};
int Com9[4]={233, 0, 7, 142};
int Com10[4]={234, 0, 0, 0};
int Com11[4]={235, 0, 0, 0};

int Com13[4]={237, 0, 0, 200};   // 00, 00, c8
int Com14[4]={238, 0, 201, 128}; // 00, c9, 80
int Com15[4]={239, 0, 8, 194};   // 00, 08, c2
int Com16[4]={240, 78, 0, 0};    // 4e, 00, 00
int Com17[4]={241, 179, 4, 0};   // b3, 04, 00
int Com18[4]={242, 0, 36, 1};    // 00, 24, 01
int Com19[4]={243, 165, 0, 5};   // a5, 00, 05
int Com20[4]={244, 0, 88, 0};    // 00, 58, 00
/*
  �������� � ��������� ����������� ������� ADF4350 ����� ����,
  ��������� � ������ �������.

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
/*
  ���������� 1 (������� ���):
  NI USB-6008:
  P0.0, P0.1, P0.2, P0.3, P0.4 - ������ ������� "��������� ����������� ���������" [��]
  P0.5 - ������ ������� "����� ���������� ��������� 2-� �������"
  P0.6, P0.7 - ������ ������� "����� ���������� ���������"

  AI0 - ������ ���������� ������� ��������� +5 � �������� [�]
  AI1 - ������ ���������� ������� ��������� +12 � �������� [�]
  AI2 - ������ �������� ������� �������� [���]
  AI4 - ������ ���������� ������� ��������� -5 � �������� [�]
  AI5 - ������ ���� ������� ��������� +27 � �������� [�]

  ���������� 2 (���������� ���):
  NI USB-6008:
  P0.0, P0.1, P0.2, P0.3, P0.4 - ������ ������� "��������� ����������� �����������" [��]
  P0.5 - ������ ������� "����� ���������� ��������� 2-� �������"
  P0.6, P0.7 - ������ ������� "����� ���������� ���������"

  AI0 - ������ ���������� ������� ��������� +5 � ����������� [�]
  AI1 - ������ ���������� ������� ��������� +12 � ����������� [�]
  AI2 - ������ �������� ������� ����������� [���]
  AI4 - ������ ���������� ������� ��������� -5 � ����������� [�]
  AI5 - ������ ���� ������� ��������� +27 � ����������� [�]

  ���������� 3 (��������� �������� ������� ���):
  NI USB-6008:
  P0.0 - ������ ������� "�������� +20 � �� �������� �����������"
  P0.1 - ������ ������� "�������� -8 � �� �������� �����������"
  P0.2 - ������ ������� "�������� +12 � �� �������� �����������"
  P0.0 - ������ ������� "�������� +12 � �� �������� ��������"

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
  FormatDateTime (s, dt) - ������ ��������, �������������� ����� ���� ��� �����. ������ �������������
  ������ ������ ������� s, ��������, ������ dd/mm/yyyy ������, ��� ��������� ������� �������� ����,
  � ������ hh:mm � �����
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+"_"+FormatDateTime("HH-NN-SS",Time()); // ������� ���� � �����
  logFname = P_SystemTime->Caption; // ������ ����� ��� ����� � ����� ��� �������� ���������
  AddSaveLog("��������� ��������"); // �������� ����������� � ��������� ���
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
	  /*
      if(RG_Mode->ItemIndex==0)
      {
        StartControl();
      }
      else
      {
        StartTesting();
	  } */
    }
    else                       // ���� �� ������
    {
      SB_OnOff->Caption="��������";
      SB_OnOff->Font->Color=clGreen;
	  /*
      if(RG_Mode->ItemIndex==0)
      {
        StopControl();
      }
      else
      {
        StopTesting();
	  }   */
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
bool __fastcall TMainForm::WriteDigChan(const char *Config, char *DigPort)
// ������ �� ������ ������ ��������� ����� P0 ���������� 1
{
	TaskHandle  taskHandle=0;
	char        errBuff[2048]={'\0'};

  // ������� ������
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ���������� ��������� ������
  if (DAQmxFailed((DAQmxCreateDOChan(taskHandle,"Dev1/port0/line0:7","",DAQmx_Val_ChanForAllLines))))
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

  return true;
}
//---------------------------------------------------------------------------
float __fastcall TMainForm::ReadAnalogChan(const char *Config)
// ������ ����������� ������ x ����� AIx ���������� y
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
  int i, Comm3, Comm4, Comm5, D_Signe;
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
  i=CB_Com3_1->ItemIndex;                            // �������� ����� ���������� ����� ��
  Comm3=StrToInt(E_Com3->Text);                      // �������� �������� � ����������
  Comm4=StrToInt(E_Com4->Text);                      // �������� �������� � ����������
  Comm5=StrToInt(E_Com5->Text);                      // �������� �������� � ����������
  // �������� �������� � ������:
  Com3[OldIndex_][3]=Comm3&0xFF;
  Com4[OldIndex_][3]=Comm4&0xFF;                     // ��. ����
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;               // ��. ����
  Com5[OldIndex_][3]=Comm5&0xFF;                     // ��. ����
  Com5[OldIndex_][2]=(Comm5/256)&0xFF;               // ��. ����
  D_SignT[OldIndex_]=CB_SignT->ItemIndex;

  OldIndex_=i;                                       // ��������� ������� ���������� �����
  E_Com3->Text=IntToStr(Com3[i][3]);                 // �������� ������� ��������
  E_Com4->Text=IntToStr(Com4[i][2]*256+Com4[i][3]);  // �������� ������� ��������
  E_Com5->Text=IntToStr(Com5[i][2]*256+Com5[i][3]);  // �������� ������� ��������
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
void __fastcall TMainForm::CB_Com3_1Exit(TObject *Sender)
// ����� ���� "���������� ��������� �����" ���������
{
  bool b;
  int min=1;                           // ����������� ��������
  int max=64;                          // ������������ ��������
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
  int max=64;                          // ������������ ��������
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
{
  float Comm5;
  if(E_Com5->Text=="") E_Com5->Text=0;
  Comm5=StrToFloat(E_Com5->Text);                  // �������� �������� � [��] � ����������, ���� �������� ������� 0.5 ��
  Com5[OldIndex_][3]=(int)Comm5&0xFF;              // ��. ����
  Com5[OldIndex_][2]=((int)Comm5/256)&0xFF;        // ��. ����
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
    E_Com5->Text=RoundValue(delta,value);
    float Comm5=StrToInt(E_Com5->Text);             // �������� �������� � [��] � ����������, ���� �������� ������� 0.5 ��
    Com5[OldIndex_][3]=(int)Comm5&0xFF;             // ��. ����
    Com5[OldIndex_][2]=((int)Comm5/256)&0xFF;       // ��. ����
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
	  LE_Dir->Text=Ini->ReadString("������ ��� � ������","����������� �����","1");  // ������� �� ����� � ������
	  // ��������� ������ ���
	  LE_A->Text=Ini->ReadString("������ ��� � ������","��������� ������ ���","1");  // ������� �� ����� � ������
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
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_SaveControlClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ������");  // �������� ����������� � ��������� ���

  SaveDialog1->DefaultExt=".ctr";
  SaveDialog1->FileName="*.ctr";
  SaveDialog1->Filter="���� ������ ������ (*.ctr)|*.ctr";
  SaveDialog1->Title=" ���������� ����� ������ ������";

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
	Ini->WriteString("������ � ������ ������","���������� ��",E_Command3_0->Text);

	// Command3
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
	  Ini->WriteString("������ � ������ ������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"",Command3[i][3]);  // ������ �� ������� � ����
    }
    // Command4
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
      int Command=Command4[i][3]+Command4[i][2]*256;
	  Ini->WriteString("������ � ������ ������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"",Command);   // ������ �� ������� � ����
    }
    // Command5, ���� �������� ������� 0.5 ��
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
	  Ini->WriteString("������ � ������ ������","������� \"���� ������������� ������ ������� (��)\""+IntToStr(i+1)+"\"",D_SignC[i]);  // ������ �� ������� � ����
      int Command=(Command5[i][3]+Command5[i][2]*256);
	  Ini->WriteString("������ � ������ ������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"",Command);  // ������ �� ������� � ����
    }
    // ������� "����� ��������"
	Ini->WriteString("������ � ������ ������","������� \"����� ��������\"",IntToStr(Shift[3])); // ������ �� ������� � ����
    // Command6
    int Comm6=Command6[3]+Command6[2]*256;
	Ini->WriteString("������ � ������ ������","������� \"����������� ������� ������� ������\"",Comm6);   // ������ �� ������� � ����
    // Command7
    Ini->WriteString("������ � ������ ������","������� \"����������� ���������� ����������� ����-2\"",IntToStr(Command7[3])); // ������ �� ������� � ����

    delete Ini;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_SaveTestingClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� ���������� ������");  // �������� ����������� � ��������� ���

  SaveDialog1->DefaultExt=".tst";
  SaveDialog1->FileName="*.tst";
  SaveDialog1->Filter="���� ���������� ������ (*.tst)|*.tst";
  SaveDialog1->Title=" ���������� ����� ���������� ������";

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
	Ini->WriteString("������ � ��������� ������","���������� ��",E_Com3_0->Text);

    // Com3
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
    {
	  Ini->WriteString("������ � ��������� ������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"",Com3[i][3]);  // ������ �� ������� � ����
    }
    // Com4
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
    {
      int Command=Com4[i][3]+Com4[i][2]*256;
	  Ini->WriteString("������ � ��������� ������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"",Command);   // ������ �� ������� � ����
    }
    // Com5, ���� �������� ������� 0.5 ��
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
	{
	  Ini->WriteString("������ � ��������� ������","������� \"���� ������������� ������ ������� (��)\""+IntToStr(i+1)+"\"",D_SignT[i]);  // ������ �� ������� � ����
      int Command=(Com5[i][3]+Com5[i][2]*256);
	  Ini->WriteString("������ � ��������� ������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"",Command);  // ������ �� ������� � ����
	}
    // ������� "����� ��������"
	Ini->WriteString("������ � ��������� ������","������� \"����� ��������\"",IntToStr(Shift_[3])); // ������ �� ������� � ����
	// Com6
	Ini->WriteString("������ � ��������� ������","������� \"����������� ���������� �������� ����-2\"",IntToStr(Com6[3]));   // ������ �� ������� � ����
    // Com7
	Ini->WriteString("������ � ��������� ������","������� \"����������� ���������� ����������� ����-2\"",IntToStr(Com7[3])); // ������ �� ������� � ����
    // Com8
    int Comm8=Com8[3]+Com8[2]*256;
	Ini->WriteString("������ � ��������� ������","������� \"������� ����� ������� ���������� �������� ����-2\"",Comm8);  // ������ �� ������� � ����
    // Com9
    int Comm9=Com9[3]+Com9[2]*256;
	Ini->WriteString("������ � ��������� ������","������� \"������� ����� ������� ���������� ����������� ����-2\"",Comm9);  // ������ �� ������� � ����
    // Com10
	Ini->WriteString("������ � ��������� ������","������� \"��� ���������� ������� �������������\"",IntToStr(Com10[3])); // ������ �� ������� � ����
	// Com11
	Ini->WriteString("������ � ��������� ������","������� \"��� ���������� �������� �������������\"",IntToStr(Com11[3])); // ������ �� ������� � ����
	// Com13
    unsigned long int Comm13=Com13[3]+Com13[2]*256+Com13[1]*65536;
	Ini->WriteString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 1\"",Comm13); // ������ �� ������� � ����
    // Com14
    unsigned long int Comm14=Com14[3]+Com14[2]*256+Com14[1]*65536;
	Ini->WriteString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 2\"",Comm14); // ������ �� ������� � ����
	// Com15
    unsigned long int Comm15=Com15[3]+Com15[2]*256+Com15[1]*65536;
	Ini->WriteString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 3\"",Comm15); // ������ �� ������� � ����
	// Com16
    unsigned long int Comm16=Com16[3]+Com16[2]*256+Com16[1]*65536;
	Ini->WriteString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 4\"",Comm16); // ������ �� ������� � ����
    // Com17
	unsigned long int Comm17=Com17[3]+Com17[2]*256+Com17[1]*65536;
	Ini->WriteString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 5\"",Comm17); // ������ �� ������� � ����
    // Com18
    unsigned long int Comm18=Com18[3]+Com18[2]*256+Com18[1]*65536;
	Ini->WriteString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 6\"",Comm18); // ������ �� ������� � ����
    // Com19
    unsigned long int Comm19=Com19[3]+Com19[2]*256+Com19[1]*65536;
	Ini->WriteString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 7\"",Comm19); // ������ �� ������� � ����
    // Com20
	unsigned long int Comm20=Com20[3]+Com20[2]*256+Com20[1]*65536;
	Ini->WriteString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 8\"",Comm20); // ������ �� ������� � ����

    delete Ini;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadControlClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ������");  // �������� ����������� � ��������� ���

  ResetBPControl();

  OpenDialog1->DefaultExt=".ctr";
  OpenDialog1->FileName="*.ctr";
  OpenDialog1->Filter="���� ������ ������ (*.ctr)|*.ctr";
  OpenDialog1->Title=" �������� ����� ������ ������";

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
	   E_Command3_0->Text=Ini->ReadString("������ � ������ ������","���������� ��","1");                // ������� �� ����� � ������
      // Command3, Command4, Command5
      for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
      {
        // Command3
		Command3[i][3]=StrToInt(Ini->ReadString("������ � ������ ������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
        // Command4
		int Comm4=StrToInt(Ini->ReadString("������ � ������ ������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"","0"));                    // ������� �� ����� � ������
        Command4[i][3]=Comm4&0xFF;                // ��. ����
        Command4[i][2]=(Comm4/256)&0xFF;          // ��. ����
        // Command5, ���� �������� ������� 0.5 ��
		D_SignC[i]=StrToInt(Ini->ReadString("������ � ������ ������","������� \"���� ������������� ������ ������� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� �����
        if(D_SignC[i]==0) CB_SignC->ItemIndex=0;
        else              CB_SignC->ItemIndex=1;

		int Comm5=StrToInt(Ini->ReadString("������ � ������ ������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
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
	  Shift[3]=StrToInt(Ini->ReadString("������ � ������ ������","������� \"����� ��������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<7; i++)
      {
        if(Shift[3]==i) CB_Shift->ItemIndex=i; // ������ � �����
      }
      // Command6
	  int Comm6=StrToInt(Ini->ReadString("������ � ������ ������","������� \"����������� ������� ������� ������\"","0"));      // ������� �� ����� � ������
      Command6[3]=Comm6&0xFF;                     // ��. ����
      Command6[2]=(Comm6/256)&0xFF;               // ��. ����
      // Command7
      Command7[3]=StrToInt(Ini->ReadString("������ � ������ ������","������� \"����������� ���������� ����������� ����-2\"","0")); // ������� �� ����� � ������
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
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadTestingClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ��������� ������");  // �������� ����������� � ��������� ���

  ResetBPTesting();

  OpenDialog1->DefaultExt=".tst";
  OpenDialog1->FileName="*.tst";
  OpenDialog1->Filter="���� ���������� (*.tst)|*.tst";
  OpenDialog1->Title=" �������� ����� ���������� ������";

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
      E_Com3_0->Text=Ini->ReadString("������ � ��������� ������","���������� ��","1");
	  // Com3, Com4, Com5
      for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
      {
        // Com3
		Com3[i][3]=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� ����� � ������
        // Com4
		int Comm4=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"","0"));             // ������� �� ����� � ������
        Com4[i][3]=Comm4&0xFF;                // ��. ����
        Com4[i][2]=(Comm4/256)&0xFF;          // ��. ����
        // Com5, ���� �������� ������� 0.5 ��
		D_SignT[i]=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"���� ������������� ������ ������� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� �����
        if(D_SignT[i]==0) CB_SignT->ItemIndex=0;
        else              CB_SignT->ItemIndex=1;

		int Comm5=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� ����� � ������
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
	  Shift_[3]=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"����� ��������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<7; i++)
      {
        if(Shift_[3]==i) CB_Shift_->ItemIndex=i; // ������ � �����
      }
      // Com6
	  Com6[3]=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"����������� ���������� �������� ����-2\"","0")); // ������� �� ����� � ������
      for(int i=0; i<64; i++)
      {
        if(Com6[3]==63-i) CB_Com6->ItemIndex=i; // ������ � �����
      }
      // Com7
	  Com7[3]=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"����������� ���������� ����������� ����-2\"","0")); // ������� �� ����� � ������
      for(int i=0; i<64; i++)
      {
        if(Com7[3]==63-i) CB_Com7->ItemIndex=i; // ������ � �����
      }
      // Com8
	  int Comm8=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� ����� ������� ���������� �������� ����-2\"","0"));      // ������� �� ����� � ������
      Com8[3]=Comm8&0xFF;                       // ��. ����
      Com8[2]=(Comm8/256)&0xFF;                 // ��. ����
      for(int i=0; i<=15; i++)
      {
        if(Comm8==14+i*128) CB_Com8->ItemIndex=i;      // ������ � �����
      }
      // Com9
	  int Comm9=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� ����� ������� ���������� �������� ����-2\"","0"));      // ������� �� ����� � ������
      Com9[3]=Comm9&0xFF;                       // ��. ����
      Com9[2]=(Comm9/256)&0xFF;                 // ��. ����
      for(int i=0; i<=15; i++)
      {
        if(Comm9==14+i*128) CB_Com9->ItemIndex=i;      // ������ � �����
      }
      // Com10
	  Com10[3]=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"��� ���������� ������� �������������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<=3; i++)
      {
        if(Com10[3]==i) CB_Com10->ItemIndex=i; // ������ � �����
      }
      // Com11
	  Com11[3]=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"��� ���������� �������� �������������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<=3; i++)
      {
        if(Com11[3]==i) CB_Com11->ItemIndex=i; // ������ � �����
      }
      // Com13
	  unsigned long int Comm13=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 1\"","0"));      // ������� �� ����� � ������
      Com13[3]=Comm13&0xFF;                    // ��. ����
      Com13[2]=(Comm13/256)&0xFF;              // ��. ����
	  Com13[1]=(Comm13/65536)&0xFF;            // ��. ����

      // Com14
	  unsigned long int Comm14=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 2\"","0"));      // ������� �� ����� � ������
      Com14[3]=Comm14&0xFF;                    // ��. ����
      Com14[2]=(Comm14/256)&0xFF;              // ��. ����
	  Com14[1]=(Comm14/65536)&0xFF;            // ��. ����

      // Com15
	  unsigned long int Comm15=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 3\"","0"));      // ������� �� ����� � ������
      Com15[3]=Comm15&0xFF;                    // ��. ����
      Com15[2]=(Comm15/256)&0xFF;              // ��. ����
	  Com15[1]=(Comm15/65536)&0xFF;            // ��. ����

      // Com16
	  unsigned long int Comm16=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 4\"","0"));      // ������� �� ����� � ������
      Com16[3]=Comm16&0xFF;                    // ��. ����
      Com16[2]=(Comm16/256)&0xFF;              // ��. ����
	  Com16[1]=(Comm16/65536)&0xFF;            // ��. ����

      // Com17
	  unsigned long int Comm17=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 5\"","0"));      // ������� �� ����� � ������
      Com17[3]=Comm17&0xFF;                    // ��. ����
      Com17[2]=(Comm17/256)&0xFF;              // ��. ����
	  Com17[1]=(Comm17/65536)&0xFF;            // ��. ����

      // Com18
	  unsigned long int Comm18=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 6\"","0"));      // ������� �� ����� � ������
      Com18[3]=Comm18&0xFF;                    // ��. ����
      Com18[2]=(Comm18/256)&0xFF;              // ��. ����
	  Com18[1]=(Comm18/65536)&0xFF;            // ��. ����

      // Com19
	  unsigned long int Comm19=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 7\"","0"));      // ������� �� ����� � ������
      Com19[3]=Comm19&0xFF;                    // ��. ����
      Com19[2]=(Comm19/256)&0xFF;              // ��. ����
	  Com19[1]=(Comm19/65536)&0xFF;            // ��. ����

      // Com20
      unsigned long int Comm20=StrToInt(Ini->ReadString("������ � ��������� ������","������� \"������� �������� ����������� ����� ����-2. ����� 8\"","0"));      // ������� �� ����� � ������
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
	//M_Debug->Lines->Add(Fi);
  }

  // ������� �������
  if(LE_f->Text!="")
  {
	f=StrToInt(LE_f->Text);  // ����������� ��������
	//M_Debug->Lines->Add(Fi);
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
	//M_Debug->Lines->Add(Fi);
  }

  if(f>=900&&f<=10000)                        // ���� �������� ����������
  {




	Command6[2]=code_MSB;                     // �������� �������� �������� ����� ����������� ������� ������� ������
	Command6[3]=code_LSB;                     // �������� �������� �������� ����� ����������� ������� ������� ������
  }

    E_Command6->Text=IntToStr(f);

	//M_Debug->Lines->Add(V);
    //M_Debug->Lines->Add(f);
    //M_Debug->Lines->Add(D);
  }

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
/*
  ����������� ���������� ����������� ����-2 ������ ����������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // ���� ���������� ����� LV_Sar2 �� �������
  {
    int K2=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[0].c_str()); // ����������� ��������
    CB_Command7->Text=IntToStr(K2);
    Command7[3]=K2;
  }
/*
  ����������� ���������� �������� ����-2 ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // ���� ���������� ����� LV_Sar2 �� �������
  {
    int K1=StrToInt(LV_Sar2->Items->Item[0]->Caption.c_str()); // ����������� ��������
    CB_Com6->Text=IntToStr(K1);
    Com6[3]=K1;
  }
/*
  ����������� ���������� ����������� ����-2 ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // ���� ���������� ����� LV_Sar2 �� �������
  {
    int K2=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[0].c_str()); // ����������� ��������
    CB_Com7->Text=IntToStr(K2);
    Com7[3]=K2;
  }
/*
  ������� ����� ������� ���������� ��������� ����-2 ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // ���� ���������� ����� LV_Sar2 �� �������
  {
    int F1=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[1].c_str()); // ����������� ��������
    CB_Com8->Text=IntToStr(F1);

    if(F1==970)  CB_Com8->ItemIndex=0;
    else
    if(F1==1000) CB_Com8->ItemIndex=1;
    else
    if(F1==1030) CB_Com8->ItemIndex=2;
    else
    if(F1==1055) CB_Com8->ItemIndex=3;
    else
    if(F1==1085) CB_Com8->ItemIndex=4;
    else
    if(F1==1120) CB_Com8->ItemIndex=5;
    else
    if(F1==1155) CB_Com8->ItemIndex=6;
    else
    if(F1==1195) CB_Com8->ItemIndex=7;
    else
    if(F1==2335) CB_Com8->ItemIndex=8;
    else
    if(F1==2430) CB_Com8->ItemIndex=9;
    else
    if(F1==2530) CB_Com8->ItemIndex=10;
    else
    if(F1==2655) CB_Com8->ItemIndex=11;
    else
    if(F1==2770) CB_Com8->ItemIndex=12;
    else
    if(F1==2940) CB_Com8->ItemIndex=13;
    else
    if(F1==3145) CB_Com8->ItemIndex=14;
    else
    if(F1==3400) CB_Com8->ItemIndex=15;

    for(int i=0; i<16; i++)
    {
      int code;
      if(CB_Com8->ItemIndex==i) code=14+128*i;    // ��������� ���� ���������
      int code_LSB=code&0xFF;                     // ������� ���� ���������
      int code_MSB=(code/256)&0xFF;               // ������� ���� ���������
      Com8[2]=code_MSB;                           // �������� �������� �������� ����� ���������
      Com8[3]=code_LSB;                           // �������� �������� �������� ����� ���������
    }
    //M_Debug->Lines->Add(CB_Com8->ItemIndex);
  }
/*
  ������� ����� ������� ���������� ����������� ����-2 ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // ���� ���������� ����� LV_Sar2 �� �������
  {
    int F2=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[2].c_str()); // ����������� ��������
    CB_Com9->Text=IntToStr(F2);

    if(F2==970)  CB_Com9->ItemIndex=0;
    else
    if(F2==1000) CB_Com9->ItemIndex=1;
    else
    if(F2==1030) CB_Com9->ItemIndex=2;
    else
    if(F2==1055) CB_Com9->ItemIndex=3;
    else
    if(F2==1085) CB_Com9->ItemIndex=4;
    else
    if(F2==1120) CB_Com9->ItemIndex=5;
    else
    if(F2==1155) CB_Com9->ItemIndex=6;
    else
    if(F2==1195) CB_Com9->ItemIndex=7;
    else
    if(F2==2335) CB_Com9->ItemIndex=8;
    else
    if(F2==2430) CB_Com9->ItemIndex=9;
    else
    if(F2==2530) CB_Com9->ItemIndex=10;
    else
    if(F2==2655) CB_Com9->ItemIndex=11;
    else
    if(F2==2770) CB_Com9->ItemIndex=12;
    else
    if(F2==2940) CB_Com9->ItemIndex=13;
    else
    if(F2==3145) CB_Com9->ItemIndex=14;
    else
    if(F2==3400) CB_Com9->ItemIndex=15;

    for(int i=0; i<16; i++)
    {
      int code;
      if(CB_Com9->ItemIndex==i) code=14+128*i;    // ��������� ���� ���������
      int code_LSB=code&0xFF;                     // ������� ���� ���������
      int code_MSB=(code/256)&0xFF;               // ������� ���� ���������
      Com9[2]=code_MSB;                           // �������� �������� �������� ����� ���������
      Com9[3]=code_LSB;                           // �������� �������� �������� ����� ���������
    }
    //M_Debug->Lines->Add(IntToStr(Com9[2]));
    //M_Debug->Lines->Add(IntToStr(Com9[3]));
  }
/*
  ��� ���������� ������� ������������� ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // ���� ���������� ����� LV_Sar2 �� �������
  {
    int K=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[3].c_str()); // ����������� ��������
    CB_Com10->Text=IntToStr(K);
    Com10[3]=K;
    //M_Debug->Lines->Add(IntToStr(Com10[3]));
  }
/*
  ��� ���������� �������� ������������� ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // ���� ���������� ����� LV_Sar2 �� �������
  {
    int K=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[4].c_str()); // ����������� ��������
    CB_Com11->Text=IntToStr(K);
    Com11[3]=K;
    //M_Debug->Lines->Add(IntToStr(Com11[3]));
  }
/*
  ������� "������� �������� ����������� ����� ����-2. ����� 1"
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar3->Items->Count!=0) // ���� ���������� ����� LV_Sar3 �� �������
  {
    Com13[1]=StrToInt(LV_Sar3->Items->Item[0]->Caption.c_str());              // ����������� �������� �������
    Com13[2]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[0].c_str()); // ����������� �������� �������
    Com13[3]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[1].c_str()); // ����������� �������� �������

    E_Com13_1->Text=LV_Sar3->Items->Item[0]->Caption.c_str();
    E_Com13_2->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[0].c_str();
    E_Com13_3->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[1].c_str();

    //M_Debug->Lines->Add(IntToStr(Com13[1]));
    //M_Debug->Lines->Add(IntToStr(Com13[2]));
    //M_Debug->Lines->Add(IntToStr(Com13[3]));
  }
/*
  ������� "������� �������� ����������� ����� ����-2. ����� 2"
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar3->Items->Count!=0) // ���� ���������� ����� LV_Sar3 �� �������
  {
    Com14[1]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[2].c_str()); // ����������� �������� �������
    Com14[2]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[3].c_str()); // ����������� �������� �������
    Com14[3]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[4].c_str()); // ����������� �������� �������

    E_Com14_1->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[2].c_str();
    E_Com14_2->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[3].c_str();
    E_Com14_3->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[4].c_str();
  }
/*
  ������� "������� �������� ����������� ����� ����-2. ����� 3"
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar3->Items->Count!=0) // ���� ���������� ����� LV_Sar3 �� �������
  {
    Com15[1]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[5].c_str()); // ����������� �������� �������
    Com15[2]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[6].c_str()); // ����������� �������� �������
    Com15[3]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[7].c_str()); // ����������� �������� �������

    E_Com15_1->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[5].c_str();
    E_Com15_2->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[6].c_str();
    E_Com15_3->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[7].c_str();
  }
/*
  ������� "������� �������� ����������� ����� ����-2. ����� 4"
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar3->Items->Count!=0) // ���� ���������� ����� LV_Sar3 �� �������
  {
    Com16[1]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[8].c_str());  // ����������� �������� �������
    Com16[2]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[9].c_str());  // ����������� �������� �������
    Com16[3]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[10].c_str()); // ����������� �������� �������

    E_Com16_1->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[8].c_str();
    E_Com16_2->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[9].c_str();
    E_Com16_3->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[10].c_str();
  }
/*
  ������� "������� �������� ����������� ����� ����-2. ����� 5"
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar4->Items->Count!=0) // ���� ���������� ����� LV_Sar4 �� �������
  {
    Com17[1]=StrToInt(LV_Sar4->Items->Item[0]->Caption.c_str());              // ����������� �������� �������
    Com17[2]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[0].c_str()); // ����������� �������� �������
    Com17[3]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[1].c_str()); // ����������� �������� �������

    E_Com17_1->Text=LV_Sar4->Items->Item[0]->Caption.c_str();
    E_Com17_2->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[0].c_str();
    E_Com17_3->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[1].c_str();

    //M_Debug->Lines->Add(IntToStr(Com17[1]));
    //M_Debug->Lines->Add(IntToStr(Com17[2]));
    //M_Debug->Lines->Add(IntToStr(Com17[3]));
  }
/*
  ������� "������� �������� ����������� ����� ����-2. ����� 6"
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar4->Items->Count!=0) // ���� ���������� ����� LV_Sar4 �� �������
  {
    Com18[1]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[2].c_str()); // ����������� �������� �������
    Com18[2]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[3].c_str()); // ����������� �������� �������
    Com18[3]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[4].c_str()); // ����������� �������� �������

    E_Com18_1->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[2].c_str();
    E_Com18_2->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[3].c_str();
    E_Com18_3->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[4].c_str();
  }
/*
  ������� "������� �������� ����������� ����� ����-2. ����� 7"
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar4->Items->Count!=0) // ���� ���������� ����� LV_Sar4 �� �������
  {
    Com19[1]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[5].c_str()); // ����������� �������� �������
    Com19[2]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[6].c_str()); // ����������� �������� �������
    Com19[3]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[7].c_str()); // ����������� �������� �������

    E_Com19_1->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[5].c_str();
    E_Com19_2->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[6].c_str();
    E_Com19_3->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[7].c_str();
  }
/*
  ������� "������� �������� ����������� ����� ����-2. ����� 8"
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar4->Items->Count!=0) // ���� ���������� ����� LV_Sar4 �� �������
  {
    Com20[1]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[8].c_str()); // ����������� �������� �������
    Com20[2]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[9].c_str()); // ����������� �������� �������
    Com20[3]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[10].c_str()); // ����������� �������� �������

    E_Com20_1->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[8].c_str();
    E_Com20_2->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[9].c_str();
    E_Com20_3->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[10].c_str();
  }
/*/
  M_Debug->Lines->Clear();
  M_Debug->Lines->Add(IntToStr(Com13[1]));
  M_Debug->Lines->Add(IntToStr(Com13[2]));
  M_Debug->Lines->Add(IntToStr(Com13[3]));

  M_Debug->Lines->Add(IntToStr(Com14[1]));
  M_Debug->Lines->Add(IntToStr(Com14[2]));
  M_Debug->Lines->Add(IntToStr(Com14[3]));

  M_Debug->Lines->Add(IntToStr(Com15[1]));
  M_Debug->Lines->Add(IntToStr(Com15[2]));
  M_Debug->Lines->Add(IntToStr(Com15[3]));

  M_Debug->Lines->Add(IntToStr(Com16[1]));
  M_Debug->Lines->Add(IntToStr(Com16[2]));
  M_Debug->Lines->Add(IntToStr(Com16[3]));

  M_Debug->Lines->Add(IntToStr(Com17[1]));
  M_Debug->Lines->Add(IntToStr(Com17[2]));
  M_Debug->Lines->Add(IntToStr(Com17[3]));

  M_Debug->Lines->Add(IntToStr(Com18[1]));
  M_Debug->Lines->Add(IntToStr(Com18[2]));
  M_Debug->Lines->Add(IntToStr(Com18[3]));

  M_Debug->Lines->Add(IntToStr(Com19[1]));
  M_Debug->Lines->Add(IntToStr(Com19[2]));
  M_Debug->Lines->Add(IntToStr(Com19[3]));

  M_Debug->Lines->Add(IntToStr(Com20[1]));
  M_Debug->Lines->Add(IntToStr(Com20[2]));
  M_Debug->Lines->Add(IntToStr(Com20[3]));
*/
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


