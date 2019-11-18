//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "ControlTesting_Main.h"
#include "BT.h"
#include "Sar1.h"
#include "Sar2.h"
#include "Sar3.h"
#include "Sar4.h"
#include "Error.h"
#include "About.h"
#include "Help.h"
#include <iostream>
#include <cmath>
#include <math.h>
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
const float pi=3.141592;
const float c=3*100000000;
Boolean c1=true;        // ���� ������� ���������� ����� � LV_Sar1
Boolean c2=true;        // ���� ������� ���������� ����� � LV_Sar2
Boolean c3=true;        // ���� ������� ���������� ����� � LV_Sar3
Boolean c4=true;        // ���� ������� ���������� ����� � LV_Sar4
float Fi=0;             // �������� ����������� �����
static int sec=0;       // ���������� ���������� �������
int itemNumber=0;       // ���������� �� � ���������� ���������� ����������
int X=0;                // �������� ���������� �� �� ��� X
int Y=0;                // �������� ���������� �� �� ��� Y
int D=0;                // ���������� �� ���� [�]
int V=0;                // �������� ����� ��� [�/�]
int f=0;                // ������� ������� [���]

int Command1[4]={1, 0, 0, 1};
int Command2[4]={2, 0, 1, 1};
int Command3[32][4];
int Command4[32][4];
int Command5[32][4];
int Command6[4]={6, 0, 0, 0};
int Command7[4]={7, 0, 0, 63};

int Com1[4]={225, 0, 0, 1};
int Com2[4]={226, 0, 1, 1};
int Com3[32][4];
int Com4[32][4];
int Com5[32][4];

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
float Fpfd, OD;         // PFD frequency, Output Devider
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

//  ����������� ����������� ������
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

// ����������
int OldIndex;                   // ��� ������ ����������
int OldIndex_;                  // ��� ������ ������������
int NIDAQmxCounter=-1;
int TempPowerCounter=-1;
const int NumReadValue=10;
bool ErrorADC;
TColor DefaultColor=clSilver;   // clBtnFace
TColor GoodColor=clLime;
TColor BadColor=clRed;
float value;

float Buff0[10];                // ������� �������
unsigned char N_zamera0=0;      // ����� ������
float sum0;                     // 0..0x0ffffffff

float Buff1[10];                // ������� �������
unsigned char N_zamera1=0;      // ����� ������
float sum1;                     // 0..0x0ffffffff

float Buff2[10];                // ������� �������
unsigned char N_zamera2=0;      // ����� ������
float sum2;                     // 0..0x0ffffffff

float Buff3[10];                // ������� �������
unsigned char N_zamera3=0;      // ����� ������
float sum3;                     // 0..0x0ffffffff

float Buff4[10];                // ������� �������
unsigned char N_zamera4=0;      // ����� ������
float sum4;                     // 0..0x0ffffffff

float Buff5[10];                // ������� �������
unsigned char N_zamera5=0;      // ����� ������
float sum5;                     // 0..0x0ffffffff

double k2=0.487, k3=0.529, k4=0.56, k5=1.42, k6=1.608;

String FileControl="";
String FileTesting="";

// ������� ��� ���������� ���������� ������ ����
int XString[32];
int YString[32];
int EPRString[32];
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

  if(!DirectoryExists(My_Patch + "����� ����������� � ������ ����������"))
  {
    if(!CreateDir(My_Patch + "����� ����������� � ������ ����������"))
      ShowMessage("�� ������� ������� ���������� �������� ������ ����������� � ������ ����������!");
    else
      ShowMessage("������� ���������� ��� �������� ������ ����������� � ������ ����������!");
  }

  if(!DirectoryExists(My_Patch + "����� ����������� � ������ ������������"))
  {
    if(!CreateDir(My_Patch + "����� ����������� � ������ ������������"))
      ShowMessage("�� ������� ������� ���������� �������� ������ ����������� � ������ ������������!");
    else
      ShowMessage("������� ���������� ��� �������� ������ ����������� � ������ ������������!");
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

  // ������������� ������� Command3
  for(int i=0; i<32; i++)
  {
    Command3[i][0]=3;   // ���� ���� �������
    Command3[i][1]=i+1; // 1-� ���� ������ ������
    Command3[i][2]=0;   // 2-� ���� ������ ������
  }
  Command3[0][3]=255;   // 3-� ���� ������ ������ (�� �1)

  for(int i=1; i<32; i++)
  {
    Command3[i][3]=0;   // 3-� ���� ������ ������ (��������� ��)
  }

  // ������������� ������� Command4
  for(int i=0; i<32; i++)
  {
    Command4[i][0]=4;   // ���� ���� �������
    Command4[i][1]=i+1; // 1-� ���� ������ ������
    Command4[i][2]=0;   // 2-� ���� ������ ������
    Command4[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� Command5
  for(int i=0; i<32; i++)
  {
    Command5[i][0]=5;   // ���� ���� �������
    Command5[i][1]=i+1; // 1-� ���� ������ ������
    Command5[i][2]=0;   // 2-� ���� ������ ������
    Command5[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� Com3
  for(int i=0; i<32; i++)
  {
    Com3[i][0]=227;     // ���� ���� �������
    Com3[i][1]=i+1;     // 1-� ���� ������ ������
    Com3[i][2]=0;       // 2-� ���� ������ ������
  }
  Com3[0][3]=255;       // 3-� ���� ������ ������ (�� �1)

  for(int i=1; i<32; i++)
  {
    Com3[i][3]=0;       // 3-� ���� ������ ������ (��������� ��)
  }

  // ������������� ������� Com4
  for(int i=0; i<32; i++)
  {
    Command4[i][0]=228; // ���� ���� �������
    Command4[i][1]=i+1; // 1-� ���� ������ ������
    Command4[i][2]=0;   // 2-� ���� ������ ������
    Command4[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� Command5
  for(int i=0; i<32; i++)
  {
    Command5[i][0]=229; // ���� ���� �������
    Command5[i][1]=i+1; // 1-� ���� ������ ������
    Command5[i][2]=0;   // 2-� ���� ������ ������
    Command5[i][3]=0;   // 3-� ���� ������ ������
  }

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
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SB_OnOffClick(TObject *Sender)
{
  if(SB_OnOff->Down)         // ���� ������
  {
    SB_OnOff->Caption="���������";
    SB_OnOff->Font->Color=clRed;

    if(RG_Mode->ItemIndex==0)
    {
      StartControl();
    }
    else
    {
      StartTesting();
    }

    WorkTimer->Enabled=true; // �������� ������ WorkTimer
  }
  else                       // ���� �� ������
  {
    SB_OnOff->Caption="��������";
    SB_OnOff->Font->Color=clGreen;

    if(RG_Mode->ItemIndex==0)
    {
      StopControl();
    }
    else
    {
      StopTesting();
    }

    WorkTimer->Enabled=false;         // �������� ������ WorkTimer
    sec=0;                            // �������� �������� ������
    P_WorkTime->Caption = "00:00:00"; // �������� �������� ������� ������
/*
    ExtractFilePath(Application->ExeName) - ���� � ����������� �����.
    GetCurrentDir() - ���� � ������� ����������.
    ��� �� ������� ���������, ������� ������� �������� �� ����������,
    ������� �� ������� ������� ����� � ����� �������� � ��������.
*/
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
void __fastcall TMain_Form::TB_LoadBlpClick(TObject *Sender) // ������� �� ������ "������� ���� .blp"
{
  AddSaveLog("��������� ���� ������ ��");  // �������� ����������� � ��������� ���

  OpenDialog->DefaultExt=".blp";
  OpenDialog->FileName="*.blp";
  OpenDialog->Filter="���� ������ �� (*.blp)|*.blp";
  OpenDialog->Title=" �������� ����� ������ ��";

  String File;

  if(OpenDialog->Execute())
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  ���������� ������ ������ ������.
  ���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
  ���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/
  {
    File=OpenDialog->FileName;
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
void __fastcall TMain_Form::TB_LoadSarClick(TObject *Sender) // ������� �� ������ "������� ���� .sar"
{
  AddSaveLog("��������� ���� ������ ��� � ������");  // �������� ����������� � ��������� ���
/*
  ������ ��� ������ � ������� ��������� ��� ������� ��������� �������:

  ofstream - ��� ������ (������) ������ � ����;
  ifstream - ��� ����� (������) ������ �� �����;
  fstream - ��� ������ � ��� ������ ������ (��������������� �����).

  ����� ������������ ��� ������, � ����� ��������� ���������� �������� �������������� ������������
  ���� fstream.h. ����� ����� � ��������� ����� ���������� ���������� �������� ������, ���������������
  ����� (������� ������� ofstream, ifstream, fstream), ��������, ����� �������:

  ofstream outFile; // �������� �������� �����.
  ifstream inFile; // ������� �������� �����.
  fstream ioFile; // �������� ����� ��� ����� � ������.

  �������� ��������� ������ (������� ���������������� ������) ��������� ��� ������ � ���������� ��� ����
  ������� � �������������� ���������� ��������� ������. ��� ��� ������������� ������ �������� �������
  ��������� �������� ������ ios, �� � ���������� ��������� ������� ��������� ������ ����������� �� �����
  �������� ������. ��� ��� �������� ������ �������� ������������ �� ������� ostream (����� ofstream),
  istream (����� ifstream), stream (����� fstream), �� ��� ������������ ��������� � ���������� �����
  ��������������� � ������������ ����� � �������. ������ ������ ��� ��������� �����, ���������� �������
  ��������������� ���� � ������� ��� � �������� �������.

  �������� ����� � ����� ����� ������ �������� ���������, ������������� ������� � ��� ���������, �������
  �������������� ��������� � ������. ���������� ������� ����������� ���������� ����� � ��� �������� ������
  fopen(), open(). �� ������� � ��������� �������� ���������� �����-������ ����� �++, ������� ������������
  ������������� ��������� ��������������� �������.

  ������ �������� �����, ����� "������������" ��� � ����������� ����� � ������� ������������ ������� open().
  ������� open() ������������ ������ �� �������� ������� ofstream, ifsream, fstream �� ������ fstreambase.
  � �� ������� ����� �� ������ ������� ����, �� � ������� ��� � ��� ������������ �������.
*/
  ifstream infile; // ������� �������� �����.

  if(OpenDialog1->Execute())          // ���� ������ ������ OpenDialog1 
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  ���������� ������ ������ ������.
  ���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
  ���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/
  {
    SarFName = OpenDialog1->FileName; // ��� ���������� ����� ����������� � ���������� BlpFName
    LV_Sar1->Items->Clear();          // ������� LV_Sar1
    LV_Sar2->Items->Clear();          // ������� LV_Sar2
    LV_Sar3->Items->Clear();          // ������� LV_Sar3
    LV_Sar4->Items->Clear();          // ������� LV_Sar4
    Update_Dump_sar();                // �������� ����� SarFName � LV_Sar1 � LV_Sar2
  }
  if(!infile)                         // ���� �� ������� �������� �����
  {
    MessageBox(NULL,"���� �� ������� �������!","������!",MB_OK|MB_ICONERROR);
    return;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Update_Dump_sar() // ������� ���� sar
{
  TListItem *pItem;               // ��������� �� ������ ���� TListItem (������ ������� ������ ListView)
  std::ifstream ifile(SarFName.c_str()); // ������� �������� ����� (���� ����������� ��� ����� (������))
  std::string line;               // ������ line ������ string
/*
  ������� std::getline (string) ������ ��� ���������� ������ �� �������� ������.
  (1) istream& getline (istream& is, string& str, char delim);
  (2) istream& getline (istream& is, string& str);
  ��������� ������� �� is � ��������� �� � str ���� �� ���������� �������������� ������ delim
  (��� ������ ����� ������, '\n', ��� ������ (2)).
  ���������� ��� �� ������������, ���� ��������� ����� ����� � is ��� ���� �������� ��������� ������
  �� ����� �������� ����� (������).
  ���� ����������� ������, �� ����������� � �������������, �.� �� �� ����������� � ��������� ��������
  ���������� ���������.
*/
  while(std::getline(ifile,line))                  // ���� ����������� ������ �� �������� ������
  {
    if(line == "*")                                // ���� ���������� ���� ������
      if(std::getline(ifile,line))                 // ���� ����������� ������ �� �������� ������
      {
        pItem = LV_Sar1->Items->Add();             // �������� ������ pItem
        pItem->Caption =AnsiString(line.c_str());  // ��������� ������ pItem
      }
    if(line == "**")                               // ���� ���������� ���� ������
      if(std::getline(ifile,line))                 // ���� ����������� ������ �� �������� ������
        pItem->SubItems->Add(line.c_str());        // �������� ������ SubItem

    if(line == "***")                              // ���� ���������� ���� ������
      if(std::getline(ifile,line))                 // ���� ����������� ������ �� �������� ������
      {
        pItem = LV_Sar2->Items->Add();             // �������� ������ pItem
        pItem->Caption =AnsiString(line.c_str());  // ��������� ������ pItem
      }
    if(line == "****")                             // ���� ���������� ���� ������
      if (std::getline(ifile,line))                // ���� ����������� ������ �� �������� ������
        pItem->SubItems->Add(line.c_str());        // �������� ������ SubItem

    if(line == "*****")                            // ���� ���������� ���� ������
      if(std::getline(ifile,line))                 // ���� ����������� ������ �� �������� ������
      {
        pItem = LV_Sar3->Items->Add();             // �������� ������ pItem
        pItem->Caption =AnsiString(line.c_str());  // ��������� ������ pItem
      }
    if(line == "******")                           // ���� ���������� ���� ������
      if (std::getline(ifile,line))                // ���� ����������� ������ �� �������� ������
        pItem->SubItems->Add(line.c_str());        // �������� ������ SubItem

    if(line == "*******")                          // ���� ���������� ���� ������
      if(std::getline(ifile,line))                 // ���� ����������� ������ �� �������� ������
      {
        pItem = LV_Sar4->Items->Add();             // �������� ������ pItem
        pItem->Caption =AnsiString(line.c_str());  // ��������� ������ pItem
      }
    if(line == "********")                         // ���� ���������� ���� ������
      if (std::getline(ifile,line))                // ���� ����������� ������ �� �������� ������
        pItem->SubItems->Add(line.c_str());        // �������� ������ SubItem
  }

  AddSaveLog("�������� ���� "+SarFName);           // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_ControlClick(TObject *Sender)
{
  AddSaveLog("������ ����� ����������");  // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_TestingClick(TObject *Sender)
{
  AddSaveLog("������ ����� ������������");  // �������� ����������� � ��������� ���    
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

void __fastcall TMain_Form::LV_Sar1DblClick(TObject *Sender)
{
  if (LV_Sar1->Selected!= NULL) F_Sar1->ShowModal(); // ���� ��������� ������ LV_Sar1 �� �����, ������� �����  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar2DblClick(TObject *Sender)
{
 if (LV_Sar2->Selected!= NULL) F_Sar2->ShowModal(); // ���� ��������� ������ LV_Sar2 �� �����, ������� �����  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar3DblClick(TObject *Sender)
{
  if (LV_Sar3->Selected!= NULL) F_Sar3->ShowModal(); // ���� ��������� ������ LV_Sar3 �� �����, ������� �����
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar4DblClick(TObject *Sender)
{
  if (LV_Sar4->Selected!= NULL) F_Sar4->ShowModal(); // ���� ��������� ������ LV_Sar4 �� �����, ������� �����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_ReadyClick(TObject *Sender)
{
  AddSaveLog("����������� �������");  // �������� ����������� � ��������� ���
/*
  ����������� ����� Fi ������������ ����������� �� �����
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/      
  if((size_t)LV_Sar1->Items->Count!=0) // ���� ���������� ����� LV_Sar1 �� �������
  {
    Fi=StrToFloat(LV_Sar1->Items->Item[0]->SubItems->Strings[1].c_str());  // ����������� �������� ����������� �����
    //M_Debug->Lines->Add(Fi);
  }
/*
  �������� ����� ��� V, ������� ������� f, ���������� �� ���� D
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size
*/
  if((size_t)LV_Sar1->Items->Count!=0) // ���� ���������� ����� LV_Sar1 �� �������
  {
    V=StrToInt(LV_Sar1->Items->Item[0]->Caption.c_str());              // ����������� �������� �������� ����� ���
    f=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[0].c_str()); // ����������� �������� ������� �������
    D=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[3].c_str()); // ����������� �������� ���������� �� ����

    E_Command6->Text=IntToStr(f);
    if(f>=8500&&f<=17500)                       // ���� �������� ����������
    {
      int rounding=f/10;                        // ���������� �� �����, �������� 10
      f=rounding*10;
      int code=(f-8500)/10;                     // ��������� ���� ����������� �������
      int code_LSB=code&0xFF;                   // ������� ���� ����������� ������� ������� ������
      int code_MSB=(code/256)&0xFF;             // ������� ���� ����������� ������� ������� ������
      Command6[2]=code_MSB;                     // �������� �������� �������� ����� ����������� ������� ������� ������
      Command6[3]=code_LSB;                     // �������� �������� �������� ����� ����������� ������� ������� ������
    }
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
    // Command3 "��������� ��������� ����� (��)" ������ ����������
    Command3[i][1]=i+1;                            // �������� �������� ������ ��
    float EPR=StrToFloat(EPRString[i]);            // ����������� �������� ���
    Command3[i][3]=int(sqrt(EPR));                 // �������� �������� ��������� ��
    // Command4 "����� �������� (��)" ������ ����������
    Command4[i][1]=i+1;                            // �������� �������� ������ ��
    X=XString[i];                                  // ����������� �������� ���������� �� �� ��� X
    Y=YString[i];                                  // ����������� �������� ���������� �� �� ��� Y
    float arg=Fi*pi/180;                           // ������� �������� � �������
    float Xi=X*cos(arg)+Y*sin(arg);                // ���������� X � ������ ����������� ����� Fi
    float Tau=((2*Xi)/c-0.000001)*1000000000;      // ����� �������� �� [��], ���� �������� ������� 1 ��
    int Tau_LSB=((int)Tau)&0xFF;                   // ������� ���� ������� �������� ��
    int Tau_MSB=((int)Tau/256)&0xFF;               // ������� ���� ������� �������� ��
    Command4[i][2]=Tau_MSB;                        // �������� �������� �������� ����� ������� �������� ��
    Command4[i][3]=Tau_LSB;                        // �������� �������� �������� ����� ������� �������� ��
    // Command5 "������������ ����� ������� (��)" ������ ����������
    Command5[i][1]=i+1;                            // �������� �������� ������ ��
    float Yi=Y*cos(arg)-X*sin(arg);                // ���������� Y � ������ ����������� ����� Fi
    float fdi=f*V*Yi/c*D;                          // ������������ �������� �� [��], ���� �������� ������� 0.5 ��
    int fdi_LSB=((int)fdi)&0xFF;                   // ������� ���� ������������� �������� ��
    int fdi_MSB=((int)fdi/256)&0xFF;               // ������� ���� ������������� �������� ��
    Command5[i][2]=fdi_MSB;                        // �������� �������� �������� ����� ������������� �������� ��
    Command5[i][3]=fdi_LSB;                        // �������� �������� �������� ����� ������������� �������� ��
    // Com3 "��������� ��������� ����� (��)" ������ ������������
    Com3[i][1]=i+1;                                // �������� �������� ������ ��
    Com3[i][3]=int(sqrt(EPR));                     // �������� �������� ��������� ��
    // Com4 "����� �������� (��)" ������ ������������
    Com4[i][1]=i+1;                                // �������� �������� ������ ��
    Com4[i][2]=Tau_MSB;                            // �������� �������� �������� ����� ������� �������� ��
    Com4[i][3]=Tau_LSB;                            // �������� �������� �������� ����� ������� �������� ��
    // Com5 "������������ ����� ������� (��)" ������ ������������
    Com5[i][1]=i+1;                                // �������� �������� ������ ��
    Com5[i][2]=fdi_MSB;                            // �������� �������� �������� ����� ������������� �������� ��
    Com5[i][3]=fdi_LSB;                            // �������� �������� �������� ����� ������������� �������� ��

    //M_Debug->Lines->Add(Command5[i][3]);          
  }

  CB_Command3_1->ItemIndex=OldIndex;               // ����� �� �� ��������� ��� ��������� ����� ��
  E_Command3->Text=Command3[OldIndex][3];                           // �������� ������� ��������
  E_Command4->Text=Command4[OldIndex][3]+Command4[OldIndex][2]*256; // �������� ������� ��������
  E_Command5->Text=Command5[OldIndex][3]+Command5[OldIndex][2]*256; // �������� ������� ��������

  CB_Com3_1->ItemIndex=OldIndex;                   // ����� �� �� ��������� ��� ��������� ����� ��
  E_Com3->Text=Com3[OldIndex][3];                       // �������� ������� ��������
  E_Com4->Text=Com4[OldIndex][3]+Com4[OldIndex][2]*256; // �������� ������� ��������
  E_Com5->Text=Com5[OldIndex][3]+Com5[OldIndex][2]*256; // �������� ������� ��������

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
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command1Change(TObject *Sender)
{
  for(int i=0; i<3; i++)
  {
    if(CB_Command1->ItemIndex==i) Command1[2]=i;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Command3_0Exit(TObject *Sender)
// ����� ���� "���������� ��������� �����" ���������
{
  bool b;
  int min=1;                         // ����������� ��������
  int max=32;                        // ������������ ��������
  int delta=1;
  String EdIzm="";                   // ������� ���������
  String value;                      // ������ ��������

  value=E_Command3_0->Text;          // ��������

  b=IsValidInt(min,max,value,EdIzm); // �������� ������������ ��������� ��������
  if(b)                              // ���� ���������
  {
    CB_Command3_1->Text=RoundValue(delta,value);
    CB_Command3_1->Clear();          // �������� ���������� ���������� ��

    for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
    {
      CB_Command3_1->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
    }

    CB_Command3_1->ItemIndex=0;      // ����� �� �� ��������� ��� ��������� ����� ��
  }
  else                               // ���� �� ���������
  {
    E_Command3_0->SetFocus();        // ����� �� ���� "���������� ��������� �����"
    ErrorForm->SetFocus();           // ����� ��������� �� ������
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
void __fastcall TMain_Form::CB_Command3_1Change(TObject *Sender)
// �� ��������� ������ ��
{
  int i, Comm3, Comm4, Comm5;
  i=CB_Command3_1->ItemIndex;                        // �������� ����� ���������� ����� ��
  Comm3=StrToInt(E_Command3->Text);                  // �������� �������� � ����������
  Comm4=StrToInt(E_Command4->Text);                  // �������� �������� � ����������
  Comm5=StrToInt(E_Command5->Text);                  // �������� �������� � ����������
  // �������� �������� � ������:
  Command3[OldIndex][3]=Comm3&0xFF;
  Command4[OldIndex][3]=Comm4&0xFF;                  // ��. ����
  Command4[OldIndex][2]=(Comm4/256)&0xFF;            // ��. ����
  Command5[OldIndex][3]=Comm5&0xFF;                  // ��. ����
  Command5[OldIndex][2]=(Comm5/256)&0xFF;            // ��. ����

  OldIndex=i;                                        // ��������� ������� ���������� �����
  E_Command3->Text=IntToStr(Command3[i][3]);                    // �������� ������� ��������
  E_Command4->Text=IntToStr(Command4[i][2]*256+Command4[i][3]); // �������� ������� ��������
  E_Command5->Text=IntToStr(Command5[i][2]*256+Command5[i][3]); // �������� ������� ��������
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command6Change(TObject *Sender)
{
  f=StrToInt(E_Command6->Text);               // ����������� ������� ������� ������
  if(f>=8500&&f<=17500)                       // ���� �������� ����������
  {
    int rounding=f/10;                        // ���������� �� �����, �������� 10
    f=rounding*10;
    int code=(f-8500)/10;                     // ��������� ���� ����������� �������
    int code_LSB=code&0xFF;                   // ������� ���� ����������� ������� ������� ������
    int code_MSB=(code/256)&0xFF;             // ������� ���� ����������� ������� ������� ������
    Command6[2]=code_MSB;                     // �������� �������� �������� ����� ����������� ������� ������� ������
    Command6[3]=code_LSB;                     // �������� �������� �������� ����� ����������� ������� ������� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command7Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Command7->ItemIndex==i) Command7[3]=63-i;
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
void __fastcall TMain_Form::E_Com3_0Exit(TObject *Sender)
// ����� ���� "���������� ��������� �����" ���������
{
  bool b;
  int min=1;                         // ����������� ��������
  int max=32;                        // ������������ ��������
  String EdIzm="";                   // ������� ���������
  String value;                      // ������ ��������

  value=E_Com3_0->Text;              // ��������

  b=IsValidInt(min,max,value,EdIzm); // �������� ������������ ��������� ��������
  if(b)                              // ���� ���������
  {
    CB_Com3_1->Clear();              // �������� ���������� ���������� ��
    
    for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
    {
      CB_Com3_1->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
    }

    CB_Com3_1->ItemIndex=0;          // ����� �� �� ��������� ��� ��������� ����� ��
  }
  else                               // ���� �� ���������
  {
    E_Com3_0->SetFocus();            // ����� �� ���� "���������� ��������� �����"
    ErrorForm->SetFocus();           // ����� ��������� �� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com3_1Change(TObject *Sender)
// �� ��������� ������ ��
{
  int i, Comm3, Comm4, Comm5;
  i=CB_Com3_1->ItemIndex;                           // �������� ����� ���������� ����� ��
  Comm3=StrToInt(E_Com3->Text);                     // �������� �������� � ����������
  Comm4=StrToInt(E_Com4->Text);                     // �������� �������� � ����������
  Comm5=StrToInt(E_Com5->Text);                     // �������� �������� � ����������
  // �������� �������� � ������:
  Com3[OldIndex_][3]=Comm3&0xFF;
  Com4[OldIndex_][3]=Comm4&0xFF;                     // ��. ����
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;               // ��. ����
  Com5[OldIndex_][3]=Comm5&0xFF;                     // ��. ����
  Com5[OldIndex_][2]=(Comm5/256)&0xFF;               // ��. ����

  OldIndex_=i;                                       // ��������� ������� ���������� �����
  E_Com3->Text=IntToStr(Com3[i][3]);                 // �������� ������� ��������
  E_Com4->Text=IntToStr(Com4[i][2]*256+Com4[i][3]);  // �������� ������� ��������
  E_Com5->Text=IntToStr(Com5[i][2]*256+Com5[i][3]);  // �������� ������� ��������
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
void __fastcall TMain_Form::E_Com13_1Change(TObject *Sender)
{
  Com13[1]=StrToInt(E_Com13_1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com13_2Change(TObject *Sender)
{
  Com13[2]=StrToInt(E_Com13_2->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com13_3Change(TObject *Sender)
{
  Com13[3]=StrToInt(E_Com13_3->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com14_1Change(TObject *Sender)
{
  Com14[1]=StrToInt(E_Com14_1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com14_2Change(TObject *Sender)
{
  Com14[2]=StrToInt(E_Com14_2->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com14_3Change(TObject *Sender)
{
  Com14[3]=StrToInt(E_Com14_3->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com15_1Change(TObject *Sender)
{
  Com15[1]=StrToInt(E_Com15_1->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com15_2Change(TObject *Sender)
{
  Com15[2]=StrToInt(E_Com15_2->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com15_3Change(TObject *Sender)
{
  Com15[3]=StrToInt(E_Com15_3->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com16_1Change(TObject *Sender)
{
  Com16[1]=StrToInt(E_Com16_1->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com16_2Change(TObject *Sender)
{
  Com16[2]=StrToInt(E_Com16_2->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com16_3Change(TObject *Sender)
{
  Com16[3]=StrToInt(E_Com16_3->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com17_1Change(TObject *Sender)
{
  Com17[1]=StrToInt(E_Com17_1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com17_2Change(TObject *Sender)
{
  Com17[2]=StrToInt(E_Com17_2->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com17_3Change(TObject *Sender)
{
  Com17[3]=StrToInt(E_Com17_3->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com18_1Change(TObject *Sender)
{
  Com18[1]=StrToInt(E_Com18_1->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com18_2Change(TObject *Sender)
{
  Com18[2]=StrToInt(E_Com18_2->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com18_3Change(TObject *Sender)
{
  Com18[3]=StrToInt(E_Com18_3->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com19_1Change(TObject *Sender)
{
  Com19[1]=StrToInt(E_Com19_1->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com19_2Change(TObject *Sender)
{
  Com19[2]=StrToInt(E_Com19_2->Text);    
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com19_3Change(TObject *Sender)
{
  Com19[3]=StrToInt(E_Com19_3->Text);    
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com20_1Change(TObject *Sender)
{
  Com20[1]=StrToInt(E_Com20_1->Text);    
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com20_2Change(TObject *Sender)
{
  Com20[2]=StrToInt(E_Com20_2->Text);     
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com20_3Change(TObject *Sender)
{
  Com20[3]=StrToInt(E_Com20_3->Text);     
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StartControl()
{
  AddSaveLog("������� ����� ����������");  // �������� ����������� � ��������� ���

  RG_Mode->Enabled=false;
  B_Ready->Enabled=false;
  B_Send->Enabled=false;
  //PC_Main->Enabled=false;
  Tsh_Control->Enabled=false;
  Tsh_Testing->Enabled=false;

  CommPort1->Open=true;

  if(CommPort1->BaudRate==cbr9600)         // �������� �� Serial Input/Output Monitor
  {
    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command1[i]);
    }
    CommPort1->PutChar(0x0d);              // ������� �������
    CommPort1->PutChar(0x0a);              // ������� �� ��������� ������
  }
  else                                     // �������� �� ����-2, BaudRate=57600
  {
    CommPort1->PutChar(0xBB);              // ������ �������� �� ����������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command1[i]);
    }
  }
  CommPort1->Open=false;  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StopControl()
{
  AddSaveLog("�������� ����� ����������. ����� ������ ��������� "+P_WorkTime->Caption);  // �������� ����������� � ��������� ���

  RG_Mode->Enabled=true;
  B_Ready->Enabled=true;
  B_Send->Enabled=true;
  //PC_Main->Enabled=true;
  Tsh_Control->Enabled=true;
  Tsh_Testing->Enabled=true;

  CommPort1->Open=true;

  if(CommPort1->BaudRate==cbr9600)         // �������� �� Serial Input/Output Monitor
  {
    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command2[i]);
    }
    CommPort1->PutChar(0x0d);              // ������� �������
    CommPort1->PutChar(0x0a);              // ������� �� ��������� ������
  }
  else                                     // �������� �� ����-2, BaudRate=57600
  {
    CommPort1->PutChar(0xDD);              // ������ �������� �� ����������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command2[i]);
    }
  }
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StartTesting()
{
  AddSaveLog("������� ����� ������������");  // �������� ����������� � ��������� ���
  TempPowerTimer->Enabled=true;

  RG_Mode->Enabled=false;
  B_Ready->Enabled=false;
  B_Send->Enabled=false;
  //PC_Main->Enabled=false;
  Tsh_Control->Enabled=false;
  Tsh_Testing->Enabled=false;

  CommPort1->Open=true;

  if(CommPort1->BaudRate==cbr9600)         // �������� �� Serial Input/Output Monitor
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
  AddSaveLog("�������� ����� ������������. ����� ������ ��������� "+P_WorkTime->Caption);  // �������� ����������� � ��������� ���

  TempPowerTimer->Enabled=false;

  P_5->Color=clBtnFace;
  P_6->Color=clBtnFace;

  P_Temp->Color=clBtnFace;
  P_Power->Color=clBtnFace;

  P_Temp->Caption="����. �";
  P_Power->Caption="dBm";

  RG_Mode->Enabled=true;
  B_Ready->Enabled=true;
  B_Send->Enabled=true;
  //PC_Main->Enabled=true;
  Tsh_Control->Enabled=true;
  Tsh_Testing->Enabled=true;

  CommPort1->Open=true;

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
    CommPort1->PutChar(0xEE);              // ������ �������� �� ����������

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com2[i]);
    }
  }
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::NIDAQmxTimerTimer(TObject *Sender)
{
  GoNIDAQmx();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::GoNIDAQmx()
{
  float min,max;
  NIDAQmxCounter++;

  switch(NIDAQmxCounter)
  {
    case 0:                                    // �������� ���������� ��������� +5 �
      value=0;
      value=GetACD0Data();                     // ��������� AI0 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
      min=0;                                   // ��������� �������� ����������
      max=5.5;

	    value = average_U5V(value);              // ������ "����������� ��������"

      P_U5V->Caption=RoundValue(0.01, FloatToStr(value))+" �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_1->Color=BadColor;
         P_U5V->Color=BadColor;
      }
      else                                     // �������� � ������ ��������
      {
         P_1->Color=GoodColor;
         P_U5V->Color=GoodColor;
      }

      break;

    case 1:                                    // �������� ���������� ��������� +12 �
      value=0;
      value=GetACD4Data();                     // ��������� AI4 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
      value=value*2;                           // ����������� ������������������
      min=0;                                   // ��������� �������� ����������
      max=6.15*2;

      value = average_U12V(value);             // ������ "����������� ��������"

      P_U12V->Caption=RoundValue(0.01, FloatToStr(value))+" �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_2->Color=BadColor;
         P_U12V->Color=BadColor;
      }
      else                                     // �������� � ������ ��������
      {
         P_2->Color=GoodColor;
         P_U12V->Color=GoodColor;
      }

      break;

    case 2:                                    // ��� ����������� ��������� +5V
      value=0;
      value=GetACD1Data();                     // ��������� AI1 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
      value=(value-k2)/0.185;                  // ����������� ������������������
      min=(0.5-k2)/0.185;                      // ��������� �������� ����
      max=(4.5-k2)/0.185;

      value = average_I5V(value);              // ������ "����������� ��������"

      P_I5V->Caption=RoundValue(0.01, FloatToStr(value))+" �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_3->Color=BadColor;
         P_I5V->Color=BadColor;
      }
      else                                     // �������� � ������ ��������
      {
         P_3->Color=GoodColor;
         P_I5V->Color=GoodColor;
      }

      break;

    case 3:                                    // ��� ����������� ��������� +12V
      value=0;
      value=GetACD5Data();                     // ��������� AI5 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
      value=(value-k3)/0.185;                  // ����������� ������������������
      min=(0.5-k3)/0.185;                      // ��������� �������� ����
      max=(4.5-k3)/0.185;

      value = average_I12V(value);             // ������ "����������� ��������"

      P_I12V->Caption=RoundValue(0.01, FloatToStr(value))+" �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_4->Color=BadColor;
         P_I12V->Color=BadColor;
      }
      else                                     // �������� � ������ ��������
      {
         P_4->Color=GoodColor;
         P_I12V->Color=GoodColor;
      }

      NIDAQmxCounter=-1;                       // ������ ������ ������
      break;
  }
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::GetACD0Data() //  ��������� AI0
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
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai0","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
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
float __fastcall TMain_Form::GetACD4Data() //  ��������� AI4
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
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai4","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
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
float __fastcall TMain_Form::GetACD1Data() //  ��������� AI1
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
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai1","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
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
float __fastcall TMain_Form::GetACD5Data() //  ��������� AI5
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
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai5","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
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
float __fastcall TMain_Form::GetACD2Data() //  ��������� AI2
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
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai2","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
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
float __fastcall TMain_Form::GetACD6Data() //  ��������� AI6
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
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai6","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
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
void __fastcall TMain_Form::ComPortTransmitter()
{
  CommPort1->Open=true;

  if(CommPort1->BaudRate==cbr9600)               // �������� �� Serial Input/Output Monitor
  {
    SendTerminal();
  }
  else                                           // �������� �� ����-2, BaudRate=57600
  {
    CommPort1->PutChar(0xAA);                    // ������ �������� �� ����������

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
float __fastcall TMain_Form::average_U5V(float znachenie)
// ������������ ������� "����������� ��������"
{
  Buff0[N_zamera0]=znachenie;                   // ������� ����� ����� � "�������"
  unsigned char i;                              // 0..0x0ff

  // ������� ������� �� "�������":
  for (sum0=0,i=0; i<10; i++)
  {
    sum0 += Buff0[i];
  }

  sum0=sum0/10;
  znachenie = sum0;
  N_zamera0++;

  if (N_zamera0 == 10)
  {
    N_zamera0 = 0;
    AddSaveLog("�������� ���������� ��������� +5 � ��������� "+P_U5V->Caption);  // �������� ����������� � ��������� ���
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_U12V(float znachenie)
// ������������ ������� "����������� ��������"
{
  Buff1[N_zamera1]=znachenie;                   // ������� ����� ����� � "�������"
  unsigned char i;                              // 0..0x0ff

  // ������� ������� �� "�������":
  for (sum1=0,i=0; i<10; i++)
  {
    sum1 += Buff1[i];
  }

  sum1=sum1/10;
  znachenie = sum1;
  N_zamera1++;

  if (N_zamera1 == 10)
  {
    N_zamera1 = 0;
    AddSaveLog("�������� ���������� ��������� +12 � ��������� "+P_U12V->Caption);  // �������� ����������� � ��������� ���
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_I5V(float znachenie)
// ������������ ������� "����������� ��������"
{
  Buff2[N_zamera2]=znachenie;                   // ������� ����� ����� � "�������"
  unsigned char i;                              // 0..0x0ff

  // ������� ������� �� "�������":
  for (sum2=0,i=0; i<10; i++)
  {
    sum2 += Buff2[i];
  }

  sum2=sum2/10;
  znachenie = sum2;
  N_zamera2++;

  if (N_zamera2 == 10)
  {
    N_zamera2 = 0;
    AddSaveLog("�������� ���� ��������� +5 � ��������� "+P_I5V->Caption);  // �������� ����������� � ��������� ���
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_I12V(float znachenie)
// ������������ ������� "����������� ��������"
{
  Buff3[N_zamera3]=znachenie;                   // ������� ����� ����� � "�������"
  unsigned char i;                              // 0..0x0ff

  // ������� ������� �� "�������":
  for (sum3=0,i=0; i<10; i++)
  {
    sum3 += Buff3[i];
  }

  sum3=sum3/10;
  znachenie = sum3;
  N_zamera3++;

  if (N_zamera3 == 10)
  {
    N_zamera3 = 0;
    AddSaveLog("�������� ���� ��������� +12 � ��������� "+P_I12V->Caption);  // �������� ����������� � ��������� ���
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_Temp(float znachenie)
// ������������ ������� "����������� ��������"
{
  Buff4[N_zamera4]=znachenie;                   // ������� ����� ����� � "�������"
  unsigned char i;                              // 0..0x0ff

  // ������� ������� �� "�������":
  for (sum4=0,i=0; i<10; i++)
  {
    sum4 += Buff4[i];
  }

  sum4=sum4/10;
  znachenie = sum4;
  N_zamera4++;

  if (N_zamera4 == 10)
  {
    N_zamera4 = 0;
    AddSaveLog("����������� ���������� ����� ��������� "+P_Temp->Caption);  // �������� ����������� � ��������� ���
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_Power(float znachenie)
// ������������ ������� "����������� ��������"
{
  Buff5[N_zamera5]=znachenie;                   // ������� ����� ����� � "�������"
  unsigned char i;                              // 0..0x0ff

  // ������� ������� �� "�������":
  for (sum5=0,i=0; i<10; i++)
  {
    sum5 += Buff5[i];
  }

  sum5=sum5/10;
  znachenie = sum5;
  N_zamera5++;

  if (N_zamera5 == 10)
  {
    N_zamera5 = 0;
    AddSaveLog("��� �������� � ����� ���2 ��������� "+P_Power->Caption);  // �������� ����������� � ��������� ���
  }

  return znachenie;
}
//---------------------------------------------------------------------------


void __fastcall TMain_Form::TB_SaveControlClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ����������");  // �������� ����������� � ��������� ���

  SaveDialog->DefaultExt=".ctr";
  SaveDialog->FileName="*.ctr";
  SaveDialog->Filter="���� ������ ���������� (*.ctr)|*.ctr";
  SaveDialog->Title=" ���������� ����� ������ ����������";

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
    Ini->WriteString("������ � ������ ����������","���������� ��",E_Command3_0->Text);
    // Command1
    Ini->WriteString("������ � ������ ����������","������� \"������ ������\"",IntToStr(Command1[2])); // ������ �� ������� � ����
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
    // Command5
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
      int Command=Command5[i][3]+Command5[i][2]*256;
      Ini->WriteString("������ � ������ ����������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"",Command);  // ������ �� ������� � ����
    }
    // Command6
    int Comm6=Command6[3]+Command6[2]*256;
    Ini->WriteString("������ � ������ ����������","������� \"����������� ������� ������� ������\"",Comm6);   // ������ �� ������� � ����
    // Command7
    Ini->WriteString("������ � ������ ����������","������� \"����������� ���������� ����������� ����-2\"",IntToStr(Command7[3])); // ������ �� ������� � ����

    delete Ini;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChB_LogClick(TObject *Sender)
{
  if(ChB_Log->Checked==true) M_Log->Visible=false;
  else                       M_Log->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_LoadControlClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ����������");  // �������� ����������� � ��������� ���

  OpenDialog->DefaultExt=".ctr";
  OpenDialog->FileName="*.ctr";
  OpenDialog->Filter="���� ������ ���������� (*.ctr)|*.ctr";
  OpenDialog->Title=" �������� ����� ������ ����������";

  String File;

  if(OpenDialog->Execute())
  {
    File=OpenDialog->FileName;
    FileControl=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("�������� ������","��� ����������", "��������");
*/
      // ���������� ��
       E_Command3_0->Text=Ini->ReadString("������ � ������ ����������","���������� ��","1");                // ������� �� ����� � ������
      // Command1
      Command1[2]=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"������ ������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<3; i++)
      {
        if(Command1[2]==i) CB_Command1->ItemIndex=i; // ������ � �����
      }
      // Command3, Command4, Command5 
      for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
      {
        // Command3
        Command3[i][3]=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
        // Command4
        int Comm4=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"","0"));                  // ������� �� ����� � ������
        Command4[i][3]=Comm4&0xFF;                // ��. ����
        Command4[i][2]=(Comm4/256)&0xFF;          // ��. ����
        // Command5
        int Comm5=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"","0"));      // ������� �� ����� � ������
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
      // Command6
      int Comm6=StrToInt(Ini->ReadString("������ � ������ ����������","������� \"����������� ������� ������� ������\"","0"));      // ������� �� ����� � ������
      Command6[3]=Comm6&0xFF;                     // ��. ����
      Command6[2]=(Comm6/256)&0xFF;               // ��. ����
      for(int i=0; i<=900; i++)
      {
        if(Comm6==i) E_Command6->Text=i*10+8500;  // ������ � �����
      }
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
}
//---------------------------------------------------------------------------


void __fastcall TMain_Form::E_Command3Change(TObject *Sender)
{
  int Comm3;
  if(E_Command3->Text=="") E_Command3->Text=0;
  Comm3=StrToInt(E_Command3->Text);                   // �������� �������� � ����������
  Command3[OldIndex][3]=Comm3&0xFF;                   // ��. ����
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Command4Change(TObject *Sender)
{
  int Comm4;
  if(E_Command4->Text=="") E_Command4->Text=0;
  Comm4=StrToInt(E_Command4->Text);                   // �������� �������� � ����������
  Command4[OldIndex][3]=Comm4&0xFF;                   // ��. ����
  Command4[OldIndex][2]=(Comm4/256)&0xFF;             // ��. ����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command3Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=255;
  int delta=1;
  String EdIzm="";
  String value;

  value=E_Command3->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Command3->Text=RoundValue(delta,value);
    int Comm3=StrToInt(E_Command3->Text);             // �������� �������� � ����������
    Command3[OldIndex][3]=Comm3&0xFF;                 // ��. ����
    Command3[OldIndex][2]=(Comm3/256)&0xFF;           // ��. ����
  }
  else
  {
    E_Command3->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command4Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=65535;
  int delta=1;
  String EdIzm="��";
  String value;

  value=E_Command4->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Command4->Text=RoundValue(delta,value);
    int Comm4=StrToInt(E_Command4->Text);               // �������� �������� � ����������
    Command4[OldIndex][3]=Comm4&0xFF;                   // ��. ����
    Command4[OldIndex][2]=(Comm4/256)&0xFF;             // ��. ����
  }
  else
  {
    E_Command4->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Command5Change(TObject *Sender)
{
  int Comm5;
  if(E_Command5->Text=="") E_Command5->Text=0;
  Comm5=StrToInt(E_Command5->Text);                   // �������� �������� � [��] � ����������
  Command5[OldIndex][3]=Comm5&0xFF;                   // ��. ����
  Command5[OldIndex][2]=(Comm5/256)&0xFF;             // ��. ����
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Command5Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=32767;
  int delta=1;
  String EdIzm="��";
  String value;

  value=E_Command5->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Command5->Text=RoundValue(delta,value);
    int Comm5=StrToInt(E_Command5->Text);               // �������� �������� � [��] � ����������
    Command5[OldIndex][3]=Comm5&0xFF;                   // ��. ����
    Command5[OldIndex][2]=(Comm5/256)&0xFF;             // ��. ����
  }
  else
  {
    E_Command5->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com3Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=255;
  int delta=1;
  String EdIzm="";
  String value;

  value=E_Com3->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Com3->Text=RoundValue(delta,value);
    Com3[OldIndex_][3]=StrToInt(E_Com3->Text);
  }
  else
  {
    E_Com3->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com3Change(TObject *Sender)
{
  int Comm3;
  if(E_Com3->Text=="") E_Com3->Text=0;
  Comm3=StrToInt(E_Com3->Text);                  // �������� �������� � ����������
  Com3[OldIndex_][3]=Comm3&0xFF;                 // ��. ����
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com4Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=65535;
  int delta=1;
  String EdIzm="��";
  String value;

  value=E_Com4->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Com4->Text=RoundValue(delta,value);
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
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com4Change(TObject *Sender)
{
  int Comm4;
  if(E_Com4->Text=="") E_Com4->Text=0;
  Comm4=StrToInt(E_Com4->Text);                   // �������� �������� � ����������
  Com4[OldIndex_][3]=Comm4&0xFF;                  // ��. ����
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;            // ��. ����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com5Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=32767;
  int delta=1;
  String EdIzm="��";
  String value;

  value=E_Com5->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Com5->Text=RoundValue(delta,value);
    int Comm5=StrToInt(E_Com5->Text);               // �������� �������� � [��] � ����������
    Com5[OldIndex_][3]=Comm5&0xFF;                  // ��. ����
    Com5[OldIndex_][2]=(Comm5/256)&0xFF;            // ��. ����
  }
  else
  {
    E_Com5->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com5Change(TObject *Sender)
{
  int Comm5;
  if(E_Com5->Text=="") E_Com5->Text=0;
  Comm5=StrToInt(E_Com5->Text);                   // �������� �������� � [��] � ����������
  Com5[OldIndex_][3]=Comm5&0xFF;                   // ��. ����
  Com5[OldIndex_][2]=(Comm5/256)&0xFF;             // ��. ����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_SaveTestingClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ������������");  // �������� ����������� � ��������� ���

  SaveDialog->DefaultExt=".tst";
  SaveDialog->FileName="*.tst";
  SaveDialog->Filter="���� ������ ���������� (*.tst)|*.tst";
  SaveDialog->Title=" ���������� ����� ������ ������������";

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
    Ini->WriteString("������ � ������ ������������","���������� ��",E_Com3_0->Text);
    // Com1
    Ini->WriteString("������ � ������ ������������","������� \"������ ������\"",IntToStr(Com1[2])); // ������ �� ������� � ����
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
    // Com5
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
    {
      int Command=Com5[i][3]+Com5[i][2]*256;
      Ini->WriteString("������ � ������ ������������","������� \"������������ ����� ������� (��)\""+IntToStr(i+1)+"\"",Command);  // ������ �� ������� � ����
    }
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
    // Com12
    Ini->WriteString("������ � ������ ������������","������� \"��� ���������� ������ �����������\"",IntToStr(Com12[3])); // ������ �� ������� � ����
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
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::TB_LoadTestingClick(TObject *Sender)
{
  AddSaveLog("��������� ���� ����������� � ������ ������������");  // �������� ����������� � ��������� ���

  OpenDialog->DefaultExt=".tst";
  OpenDialog->FileName="*.tst";
  OpenDialog->Filter="���� ������ ������������ (*.tst)|*.tst";
  OpenDialog->Title=" �������� ����� ������ ������������";

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
      // ���������� ��
      E_Com3_0->Text=Ini->ReadString("������ � ������ ������������","���������� ��","1");
      // Com1
      Com1[2]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������ ������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<3; i++)
      {
        if(Com1[2]==i) CB_Com1->ItemIndex=i; // ������ � �����
      }
      // Com3, Com4, Com5 
      for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
      {
        // Com3
        Com3[i][3]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"��������� ��������� ����� (��)\""+IntToStr(i+1)+"\"","0")); // ������� �� ����� � ������
        // Com4
        int Comm4=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"����� �������� (��)"+IntToStr(i+1)+"\"","0"));             // ������� �� ����� � ������
        Com4[i][3]=Comm4&0xFF;                // ��. ����
        Com4[i][2]=(Comm4/256)&0xFF;          // ��. ����
        // Com5
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
      // Com12
      Com12[3]=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"��� ���������� ������ �����������\"","0")); // ������� �� ����� � ������
      for(int i=0; i<2; i++)
      {
        if(Com12[3]==i) CB_Com12->ItemIndex=i; // ������ � �����
      }
      // Com13
      unsigned long int Comm13=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 1\"","0"));      // ������� �� ����� � ������
      Com13[3]=Comm13&0xFF;                    // ��. ����
      Com13[2]=(Comm13/256)&0xFF;              // ��. ����
      Com13[1]=(Comm13/65536)&0xFF;            // ��. ����
      E_Com13_1->Text=IntToStr(Com13[1]);
      E_Com13_2->Text=IntToStr(Com13[2]);
      E_Com13_3->Text=IntToStr(Com13[3]);
      // Com14
      unsigned long int Comm14=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 2\"","0"));      // ������� �� ����� � ������
      Com14[3]=Comm14&0xFF;                    // ��. ����
      Com14[2]=(Comm14/256)&0xFF;              // ��. ����
      Com14[1]=(Comm14/65536)&0xFF;            // ��. ����
      E_Com14_1->Text=IntToStr(Com14[1]);
      E_Com14_2->Text=IntToStr(Com14[2]);
      E_Com14_3->Text=IntToStr(Com14[3]);
      // Com15
      unsigned long int Comm15=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 3\"","0"));      // ������� �� ����� � ������
      Com15[3]=Comm15&0xFF;                    // ��. ����
      Com15[2]=(Comm15/256)&0xFF;              // ��. ����
      Com15[1]=(Comm15/65536)&0xFF;            // ��. ����
      E_Com15_1->Text=IntToStr(Com15[1]);
      E_Com15_2->Text=IntToStr(Com15[2]);
      E_Com15_3->Text=IntToStr(Com15[3]);
      // Com16
      unsigned long int Comm16=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 4\"","0"));      // ������� �� ����� � ������
      Com16[3]=Comm16&0xFF;                    // ��. ����
      Com16[2]=(Comm16/256)&0xFF;              // ��. ����
      Com16[1]=(Comm16/65536)&0xFF;            // ��. ����
      E_Com16_1->Text=IntToStr(Com16[1]);
      E_Com16_2->Text=IntToStr(Com16[2]);
      E_Com16_3->Text=IntToStr(Com16[3]);
      // Com17
      unsigned long int Comm17=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 5\"","0"));      // ������� �� ����� � ������
      Com17[3]=Comm17&0xFF;                    // ��. ����
      Com17[2]=(Comm17/256)&0xFF;              // ��. ����
      Com17[1]=(Comm17/65536)&0xFF;            // ��. ����
      E_Com17_1->Text=IntToStr(Com17[1]);
      E_Com17_2->Text=IntToStr(Com17[2]);
      E_Com17_3->Text=IntToStr(Com17[3]);
      // Com18
      unsigned long int Comm18=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 6\"","0"));      // ������� �� ����� � ������
      Com18[3]=Comm18&0xFF;                    // ��. ����
      Com18[2]=(Comm18/256)&0xFF;              // ��. ����
      Com18[1]=(Comm18/65536)&0xFF;            // ��. ����
      E_Com18_1->Text=IntToStr(Com18[1]);
      E_Com18_2->Text=IntToStr(Com18[2]);
      E_Com18_3->Text=IntToStr(Com18[3]);
      // Com19
      unsigned long int Comm19=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 7\"","0"));      // ������� �� ����� � ������
      Com19[3]=Comm19&0xFF;                    // ��. ����
      Com19[2]=(Comm19/256)&0xFF;              // ��. ����
      Com19[1]=(Comm19/65536)&0xFF;            // ��. ����
      E_Com19_1->Text=IntToStr(Com19[1]);
      E_Com19_2->Text=IntToStr(Com19[2]);
      E_Com19_3->Text=IntToStr(Com19[3]);
      // Com20
      unsigned long int Comm20=StrToInt(Ini->ReadString("������ � ������ ������������","������� \"������� �������� ����������� ����� ����-2. ����� 8\"","0"));      // ������� �� ����� � ������
      Com20[3]=Comm20&0xFF;                    // ��. ����
      Com20[2]=(Comm20/256)&0xFF;              // ��. ����
      Com20[1]=(Comm20/65536)&0xFF;            // ��. ����
      E_Com20_1->Text=IntToStr(Com20[1]);
      E_Com20_2->Text=IntToStr(Com20[2]);
      E_Com20_3->Text=IntToStr(Com20[3]);

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
void __fastcall TMain_Form::TempPowerTimerTimer(TObject *Sender)
{
  float min,max;
  TempPowerCounter++;

  switch(TempPowerCounter)
  {
    case 0:                                    // ����������� ���������� �����
      value=0;
      value=GetACD2Data();                     // ��������� AI2 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
      value=(value-k4)*500;                    // ����������� ������������������
      min=(0.45-k4)*500;                       // ��������� �������� �����������
      max=(0.75-k4)*500;

      value = average_Temp(value);             // ������ "����������� ��������"

      P_Temp->Caption=RoundValue(1, FloatToStr(value))+" ����. �"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_5->Color=BadColor;
         P_Temp->Color=BadColor;
      }
      else                                     // �������� � ������ ��������
      {
         P_5->Color=GoodColor;
         P_Temp->Color=GoodColor;
      }

      break;

    case 1:                                    // ��� �������� � ����� ���2
      value=0;
      value=GetACD6Data();                     // ��������� AI6 �� NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // ��� ����������� NI USB-6008 �� ���������� ������ �� �����
      if(RB_5GHz->Checked==true)               // ��������� ���������: 5 ���
      {
        value=-(value-k5)*37.5;                // ����������� ������������������
        min=-(1.75-k5)*37.5;                   // ��������� �������� ��������
        max=-(0.5-k5)*37.5;
      }
      else                                     // ��������� ���������: 8 ���
      {
        value=-(value-k6)*46.1538;             // ����������� ������������������
        min=-(1.75-k6)*46.1538;                // ��������� �������� ��������
        max=-(0.5-k6)*46.1538;
      }
      
      value = average_Power(value);            // ������ "����������� ��������"

      P_Power->Caption=RoundValue(1, FloatToStr(value))+" dBm"; // 2 ���������� ����� ����� �������

      if((value>max)||(value<min)||(ErrorADC)) // ����� �������� �� �������
      {
         P_6->Color=BadColor;
         P_Power->Color=BadColor;
      }
      else                                     // �������� � ������ ��������
      {
         P_6->Color=GoodColor;
         P_Power->Color=GoodColor;
      }

      TempPowerCounter=-1;                       // ������ ������ ������
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DataOnClick(TObject *Sender)
{
  AddSaveLog("�������� ��������� ������");  // �������� ����������� � ��������� ���
  B_DataOff->Enabled=true;
  B_DataOn->Enabled=false;
  NIDAQmxTimer->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DataOffClick(TObject *Sender)
{
  AddSaveLog("��������� ��������� ������");  // �������� ����������� � ��������� ���

  B_DataOff->Enabled=false;
  B_DataOn->Enabled=true;

  NIDAQmxTimer->Enabled=false;

  P_1->Color=clBtnFace;
  P_2->Color=clBtnFace;
  P_3->Color=clBtnFace;
  P_4->Color=clBtnFace;

  P_U5V->Color=clBtnFace;
  P_U12V->Color=clBtnFace;
  P_I5V->Color=clBtnFace;
  P_I12V->Color=clBtnFace;

  P_U5V->Caption="0 �";
  P_U12V->Caption="0 �";
  P_I5V->Caption="0 �";
  P_I12V->Caption="0 �";
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
    L_SendDirect->Caption="����-� ��������: ����-2";
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
void __fastcall TMain_Form::HelpAboutProgClick(TObject *Sender)
{
  F_Help->ShowModal();  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SendControl()
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
    }

    for(int i=0; i<64; i++)
    {
      CommPort1->PutChar((char)Command4[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Command4[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Command4[i][2]);  // 2-� ���� ������ ������
      CommPort1->PutChar((char)Command4[i][3]);  // 3-� ���� ������ ������
    }

    for(int i=0; i<64; i++)
    {
      CommPort1->PutChar((char)Command5[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Command5[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Command5[i][2]);  // 2-� ���� ������ ������
      CommPort1->PutChar((char)Command5[i][3]);  // 3-� ���� ������ ������
    }
  }

  if(ChB_Command6->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command6[i]);
    }
  }

  if(ChB_Command7->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command7[i]);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SendTesting()
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
    }

    for(int i=0; i<64; i++)
    {
      CommPort1->PutChar((char)Com4[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Com4[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Com4[i][2]);  // 2-� ���� ������ ������
      CommPort1->PutChar((char)Com4[i][3]);  // 3-� ���� ������ ������
    }

    for(int i=0; i<64; i++)
    {
      CommPort1->PutChar((char)Com5[i][0]);  // ���� ���� �������
      CommPort1->PutChar((char)Com5[i][1]);  // 1-� ���� ������ ������
      CommPort1->PutChar((char)Com5[i][2]);  // 2-� ���� ������ ������
      CommPort1->PutChar((char)Com5[i][3]);  // 3-� ���� ������ ������
    }
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
  Divider_Select=log(OD)/log(2);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Ndevider(void)  // ���������� INT, FRAC � MOD:
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
  ResetSynthesizer();

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
  ResetSynthesizer();

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

  CB_Output->ItemIndex=1;
  CB_AuxOut->ItemIndex=1;
  E_OutFreq->Text=1000;

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
void __fastcall TMain_Form::E_Command6Exit(TObject *Sender)
{
  bool b;
  int min=8500;
  int max=17500;
  int delta=10;
  String EdIzm="���";
  String value;

  value=E_Command6->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Command6->Text=RoundValue(delta,value);

    f=StrToInt(E_Command6->Text);               // ����������� ������� ������� ������
    if(f>=8500&&f<=17500)                       // ���� �������� ����������
    {
      int rounding=f/10;                        // ���������� �� �����, �������� 10
      f=rounding*10;
      int code=(f-8500)/10;                     // ��������� ���� ����������� �������
      int code_LSB=code&0xFF;                   // ������� ���� ����������� ������� ������� ������
      int code_MSB=(code/256)&0xFF;             // ������� ���� ����������� ������� ������� ������
      Command6[2]=code_MSB;                     // �������� �������� �������� ����� ����������� ������� ������� ������
      Command6[3]=code_LSB;                     // �������� �������� �������� ����� ����������� ������� ������� ������
    }
  }
  else
  {
    E_Command6->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------


