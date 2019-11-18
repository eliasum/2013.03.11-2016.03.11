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
#include <iostream>
#include <cmath>
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
static int sec=0;       // ���������� ���������� �������
int itemNumber=0;       // ���������� �� � ���������� ���������� ����������
int X=0;                // �������� ���������� �� �� ��� X
int Y=0;                // �������� ���������� �� �� ��� Y
float Fi=0;             // �������� ����������� �����
int D=0;                // ���������� �� ���� [�]
int V=0;                // �������� ����� ��� [�/�]
int f=0;                // ������� ������� [���]

int Command1[4]={1, 0, 0, 1};
int Command2[4]={2, 0, 1, 1};
int Command3[64][4];
int Command4[64][4];
int Command5[64][4];
int Command6[4]={6, 0, 0, 0};
int Command7[4]={7, 0, 0, 63};

int Com1[4]={225, 0, 0, 1};
int Com2[4]={226, 0, 1, 1};
int Com3[64][4];
int Com4[64][4];
int Com5[64][4];

int Com6[4]={230, 0, 0, 31};
int Com7[4]={231, 0, 0, 63};
int Com8[4]={232, 0, 7, 142};
int Com9[4]={233, 0, 7, 142};
int Com10[4]={234, 0, 0, 0};
int Com11[4]={235, 0, 0, 0};
int Com12[4]={236, 0, 0, 0};
/*
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;
*/
int Com13[4]={237, 0, 0, 200};   // 00, 00, c8
int Com14[4]={238, 0, 201, 128}; // 00, c9, 80
int Com15[4]={239, 0, 8, 194};   // 00, 08, c2
int Com16[4]={240, 78, 0, 0};    // 4e, 00, 00
int Com17[4]={241, 179, 4, 0};   // b3, 04, 00
int Com18[4]={242, 0, 36, 1};    // 00, 24, 01
int Com19[4]={243, 165, 0, 5};   // a5, 00, 05
int Com20[4]={244, 0, 88, 0};    // 00, 58, 00

//  ����������� ����������� ������
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

// ����������
int OldIndex=0;

//---------------------------------------------------------------------------
#pragma package(smart_init)   /* ��������� ���������� ������������������ ������������� ������� �����, �����
��������������� ��������� �������� ������������ �� ������� */
#pragma link "CommPort"
#pragma resource "*.dfm"  // ��� ����� ���� ������������ ���� .dfm � ��� �� ������, ��� � ��� ������� �����
TMain_Form *Main_Form;    // ���������� ��������� �� ������ ����� Main_Form
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
  for(int i=0; i<64; i++)
  {
    Command3[i][0]=3;   // ���� ���� �������
    Command3[i][1]=i+1; // 1-� ���� ������ ������
    Command3[i][2]=0;   // 2-� ���� ������ ������
  }
  Command3[0][3]=255;   // 3-� ���� ������ ������ (�� �1)

  for(int i=1; i<64; i++)
  {
    Command3[i][3]=0;   // 3-� ���� ������ ������ (��������� ��)
  }

  // ������������� ������� Command4
  for(int i=0; i<64; i++)
  {
    Command4[i][0]=4;   // ���� ���� �������
    Command4[i][1]=i+1; // 1-� ���� ������ ������
    Command4[i][2]=0;   // 2-� ���� ������ ������
    Command4[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� Command5
  for(int i=0; i<64; i++)
  {
    Command5[i][0]=5;   // ���� ���� �������
    Command5[i][1]=i+1; // 1-� ���� ������ ������
    Command5[i][2]=0;   // 2-� ���� ������ ������
    Command5[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� Com3
  for(int i=0; i<64; i++)
  {
    Com3[i][0]=227;     // ���� ���� �������
    Com3[i][1]=i+1;     // 1-� ���� ������ ������
    Com3[i][2]=0;       // 2-� ���� ������ ������
  }
  Com3[0][3]=255;       // 3-� ���� ������ ������ (�� �1)

  for(int i=1; i<64; i++)
  {
    Com3[i][3]=0;       // 3-� ���� ������ ������ (��������� ��)
  }

  // ������������� ������� Com4
  for(int i=0; i<64; i++)
  {
    Command4[i][0]=228; // ���� ���� �������
    Command4[i][1]=i+1; // 1-� ���� ������ ������
    Command4[i][2]=0;   // 2-� ���� ������ ������
    Command4[i][3]=0;   // 3-� ���� ������ ������
  }

  // ������������� ������� Command5
  for(int i=0; i<64; i++)
  {
    Command5[i][0]=229; // ���� ���� �������
    Command5[i][1]=i+1; // 1-� ���� ������ ������
    Command5[i][2]=0;   // 2-� ���� ������ ������
    Command5[i][3]=0;   // 3-� ���� ������ ������
  }
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
      AddSaveLog("������� ����� ����������");  // �������� ����������� � ��������� ���
    }
    else
    {
      StartTesting();
      AddSaveLog("������� ����� ������������");  // �������� ����������� � ��������� ���
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
      AddSaveLog("�������� ����� ����������. ����� ������ ��������� "+P_WorkTime->Caption);  // �������� ����������� � ��������� ���
    }
    else
    {
      StopTesting();
      AddSaveLog("�������� ����� ������������. ����� ������ ��������� "+P_WorkTime->Caption);  // �������� ����������� � ��������� ���
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
  if(E_EnterComment->Text!="") AddSaveLog(E_EnterComment->Text); // ������ ��� �����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_LoadBlpClick(TObject *Sender) // ������� �� ������ "������� ���� .blp"
{
  AddSaveLog("��������� ���� ������ ��");  // �������� ����������� � ��������� ���
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

  if(OpenDialog->Execute())          // ���� ������ ������ OpenDialog
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  ���������� ������ ������ ������.
  ���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
  ���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/
  {
    BlpFName = OpenDialog->FileName; // ��� ���������� ����� ����������� � ���������� BlpFName
    LVScan->Items->Clear();          // ������� LVScan
    Update_Dump_blp();               // �������� ����� BlpFName � LVScan
  }
  if(!infile)                        // ���� �� ������� �������� �����
  {
    MessageBox(NULL,"���� �� ������� �������!","������!",MB_OK|MB_ICONERROR);
    return;
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
    SarFName = OpenDialog1->FileName; // ��� ���������� ����� ����������� � ���������� SarFName
    LV_Sar1->Items->Clear();          // ������� LV_Sar1
    LV_Sar2->Items->Clear();          // ������� LV_Sar2
    LV_Sar3->Items->Clear();          // ������� LV_Sar3
    LV_Sar4->Items->Clear();          // ������� LV_Sar4
    Update_Dump_sar();                // �������� ����� SarFName � LV_Sar1 � LV_Sar2
    c1=false;                         // ��������� ���������� ����� � LV_Sar1
    B_AddSar1->Enabled=false;         // ��������� ������ "������� ������ Sar1"
    c2=false;                         // ��������� ���������� ����� � LV_Sar2
    B_AddSar2->Enabled=false;         // ��������� ������ "������� ������ Sar2"
    c3=false;                         // ��������� ���������� ����� � LV_Sar3
    B_AddSar3->Enabled=false;         // ��������� ������ "������� ������ Sar3"
    c4=false;                         // ��������� ���������� ����� � LV_Sar4
    B_AddSar4->Enabled=false;         // ��������� ������ "������� ������ Sar4"
  }
  if(!infile)                         // ���� �� ������� �������� �����
  {
    MessageBox(NULL,"���� �� ������� �������!","������!",MB_OK|MB_ICONERROR);
    return;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Update_Dump_blp() // ������� ���� blp
{
/*
  ���� ������ ��������� ������������ ������� open() ��� �������� �����,
  � ����������� ������� ��� �������� ��-�������, ��������� ������ ifstream,
  ofstream � fstream �������� ������������, ������� ������������� �����-
  ���� �������� ����. ��������� � ���� ������������� � �� �������� (��������-
  ��� �� ���������) ��������� � ����������� � ���������������� ����������
  ������� open(). ������� ���� ����� ���� ����������� ���, ��� �������� � ���-
  ������ �������.
  ifstream mystream("myfile"); // ���� ����������� ��� ����� (������)
  ---------------------------------------------------------------------------
  std::string::c_str();
  ������� c_str �� ������ string ��������� ������ ����� � ����� ��. � ���������� ��������� �� ����.
  ��������, ��������� ������� � �������� ��������� ��������� ��������� �� ������ �����:
  void Foo(const char* content);
  �� ����, � �� ����� �������� ������ ������ � ���� c-ctyle ���������
  � � ���� ���� ������ ���������� � �������:
  std::string str="������ ���";
  � ���� ����� �������� ��� ������ � ���� �������:
  Foo(str); //������. ������� �� ����� �������� �� ���������
  �� ��� ��� ������� �� ����� �������� �� ���������, � ������ � �����������, �� ������������ ������
  ������� ��� - ������� c_str()
  Foo(str.c_str() ); //�����.
  ������� c_str() ������������ ������ ��� ������������� � �-style �����.
  � � ����������� c++ style ����, � ����� �������� ���������, ��������� ��� ��������, ���� ��
  ������� "������" (����� ���� ������ � ����� �������� ����)
*/
  std::ifstream infile(BlpFName.c_str()); // ������� �������� ����� (���� ����������� ��� ����� (������))
/*
  ������ � �� �������� �������� ��������, ������� ������������� ������� �������� ('\0'). ������ � ������
  �������������� ����� ���������, ����������� �� ������ ������ ������. ��������� ������ �������� �����
  � ������� �������. �.�., ������ - ��� ���������, ���������� ��������� �� ������ ������ ������.
  ������ ����� ���� ��������� � ���������� ���� ������� ��������, ���� ���������� ���� char *.
  ������������� �����:
  char color[] = "blue"; // ������ �� 5-� ���������, ���������� ������� 'b', 'l', 'u', 'e', '\0'
  const char colorPtr = "blue"; // ����������-��������� colorPtr, ������� ��������� �� ������ "blue"
  char color[] = {'b', 'l', 'u', 'e', '\0'};
  � ��++ ������� ����� ��������� ����� std::string. ���������� �� �-style ������ ���, ���
  �������� �� �����������, ��� std::string ������ ������ ������ ����, � � ������ �-style ��� ��������
  �������� � ������ ���������������; �������� ���� �� ��������� ���������� ����������� �������������,
  � � �-style ������ ����������� ������� ����� ������ ���������� �����������.
*/  
  std::string x;     // ������ x ������ string
  TListItem *item=0; // ��������� �� ������ ���� TListItem (������ ������� ������ ListView)  
  bool flag=false;   // ���� ���������� ���������� ������� item
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

  // extract to string
  #include <iostream>
  #include <string>

  main ()
  {
    std::string name;

    std::cout << "Please, enter your full name: ";
    std::getline (std::cin,name);
    std::cout << "Hello, " << name << "!\n";

    return 0;
 }
 ---------------------------------------------------------------------------
  ������� std::basic_ios::fail ���������� ������, ���� ��������� ������ �� ��������������� ������.
*/
  while(!std::getline(infile,x).fail()) // ���� ��� ������ ��� ���������� ������ �� �������� ������
  {
/*
    ������� std::string::size ���������� ����� ������ (���������� ��������); 
	  ������������ �������� size_t �������������� ���� ��� �����.
	
	  // string::size
    #include <iostream>
    #include <string>

    int main ()
    {
      std::string str ("Test string");
      std::cout << "The size of str is " << str.size() << " characters.\n";
      return 0;
    }

    Output:
    The size of str is 11 characters.
    ---------------------------------------------------------------------------
    ������� std::string::resize �������� ����� ������ �� ���������� n ��������
    void resize (size_t n);
    void resize (size_t n, char c);

    // resizing string
    #include <iostream>
    #include <string>

    int main ()
    {
      std::string str ("I like to code in C");
      std::cout << str << '\n';

      unsigned sz = str.size();

      str.resize (sz+2,'+');
      std::cout << str << '\n';

      str.resize (14);
      std::cout << str << '\n';
      return 0;
    }

    Output:

    I like to code in C
    I like to code in C++
    I like to code
    ---------------------------------------------------------------------------
    ������� std::string::erase ������� ����� ������, �������� � �����.
    sequence  (1) string& erase (size_t pos = 0, size_t len = npos);
    character (2) iterator erase (iterator p);
    range     (3) iterator erase (iterator first, iterator last);

    (1) sequence
    Erases the portion of the string value that begins at the character position pos and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.
    Notice that the default argument erases all characters in the string (like member function clear).
    (2) character
    Erases the character pointed by p.
    (3) range
    Erases the sequence of characters in the range [first,last).

    // string::erase
    #include <iostream>
    #include <string>

    int main ()
    {
      std::string str ("This is an example sentence.");
      std::cout << str << '\n';
                                               // "This is an example sentence."
      str.erase (10,8);                        //            ^^^^^^^^
      std::cout << str << '\n';
                                               // "This is an sentence."
      str.erase (str.begin()+9);               //           ^
      std::cout << str << '\n';
                                               // "This is a sentence."
      str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
      std::cout << str << '\n';
                                               // "This sentence."
      return 0;
    }

    Output:

    This is an example sentence.
    This is an sentence.
    This is a sentence.
    This sentence.
*/
    if(!x.size()) {item=0;flag=false;continue;}
/*
    ���� ����� ������ =0 (!x.size() ��� x.size()==0), �� ������ item �����������;
    ����������� ���������� ������� item; ���������� ��� ����������� ���������� ������� item.
*/
    if(x.size()&&'"'==x[x.size()-1]) x.resize(x.size()-1);
/*
    x.size() - ���������� �������� � ������;
    [x.size()-1] - ���������� ����� ���������� ������� ������ (�.�. ������ � ����);
    ���� ������ ������� ('"') �������� ��������� �������� ������ (x[x.size()-1]), ��
    �������� ����� ������ �� ���������� x.size()-1 �������� (�.�. �� 1 ������ ����� ������).
*/
    if(x.size()&&'"'==x[0]) x.erase(0,1);
/*
    ���� ������ ������� ('"') �������� ������� �������� ������ (x[0]), ��
    ������� �� ������ ���� ������, ������� � �������� ������ x.erase(0,1).
*/
    if(!item) {item=LVScan->Items->Add(); itemNumber++;}
/*
    ���� ������ item �����������, �� �������� ������ item; itemNumber++; ���������� ���������� ��
*/
    if(!flag){ item->Caption=x.c_str(); flag=true; }
/*
    ���� ����������� ���������� ������� item, �� �������� ������ item �� ������ �-style.
    ������� ���� ���������� ������� item.
*/
    else item->SubItems->Add(x.c_str()); // ����� ��������� ������ SubItems
  }

  for(int i=itemNumber+1;i<=64;i++) // ��� ���� �������������� �� � �������� ���������� ���������� �� 64-� ������������
  {
    item = LVScan->Items->Add();    // �������� ����� ������ LVScan
    item->Caption = i;              // �������� ����� ��
    item->SubItems->Add(0);         // ��������� ������� ���������� 0
    item->SubItems->Add(0);
    item->SubItems->Add(0);
  }

  AddSaveLog("�������� ���� "+BlpFName);  // �������� ����������� � ��������� ���
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
void __fastcall TMain_Form::B_AddBTClick(TObject *Sender) // ������� ������ "�������� ��"
{
  //static int k = 1;                        // ������� ��
  TListItem *Item = LVScan->Items->Add();  // �������� ����� ������ LVScan
  Item->Caption = 0;                       // ��������� ������� ���������� 0
  Item->SubItems->Add(0);
  Item->SubItems->Add(0);
  Item->SubItems->Add(0);
  //k++;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteBTClick(TObject *Sender) // ������� ������ "������� ��"
{
  if (LVScan->Selected != NULL)  // ���� ��������� ������ LVScan �� �����
  {
    LVScan->Selected->Delete();  // ������� ��������� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar1Click(TObject *Sender) // ������� �� ������ "������� ������ Sar1"
{
  if(c1)                                      // ���� ��� ������� ���������� ����� � LV_Sar1
  {
    TListItem *Item = LV_Sar1->Items->Add();  // �������� ����� ������ LV_Sar1
    // ��������� ������� ���������� �� ���������
    Item->Caption = 0;                        // V ����� ��� [�/�]
    Item->SubItems->Add(0);                   // ������� ������� [���]
    Item->SubItems->Add(0);                   // ����������� ����� [����.]
    Item->SubItems->Add(0);                   // ��������� ������ ��� [����.]
    Item->SubItems->Add(0);                   // ���������� �� ���� [�]
    c1=false;
    B_AddSar1->Enabled=false;
  }  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteSar1Click(TObject *Sender) // ������� �� ������ "������� ������ Sar1"
{
  if (LV_Sar1->Selected != NULL)  // ���� ��������� ������ LV_Sar1 �� �����
  {
    LV_Sar1->Selected->Delete();  // ������� ��������� ������
    c1=true;                      // ��������� ���������� ����� � LV_Sar1
    B_AddSar1->Enabled=true;      // �������� ������ "������� ������ Sar1"
  }
}                                    
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar2Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if(c2)                                      // ���� ��� ������� ���������� ����� � LV_Sar2
  {
    TListItem *Item = LV_Sar2->Items->Add();  // �������� ����� ������ LV_Sar2
    // ��������� ������� ���������� �� ���������
    Item->Caption = 0;                        // �� ��������� 1 [��]
    Item->SubItems->Add(0);                   // �� ��������� 2 [��]
    Item->SubItems->Add(970);                 // f ����� ������� 1 [����.]
    Item->SubItems->Add(970);                 // f ����� ������� 2 [����.]
    Item->SubItems->Add(1);                   // W���. ��������
    Item->SubItems->Add(1);                   // W���. �����������
    c2=false;
    B_AddSar2->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteSar2Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if (LV_Sar2->Selected != NULL)  // ���� ��������� ������ LV_Sar2 �� �����
  {
    LV_Sar2->Selected->Delete();  // ������� ��������� ������
    c2=true;                      // ���������� ���������� ����� � LV_Sar2
    B_AddSar2->Enabled=true;      // ��������� ������ "������� ������ Sar2"
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar3Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if(c3)                                      // ���� ��� ������� ���������� ����� � LV_Sar3
  {
    TListItem *Item = LV_Sar3->Items->Add();  // �������� ����� ������ LV_Sar3
    // ��������� ������� ���������� �� ���������
    // Reg[0]=0x00C80000;
    Item->Caption = IntToHex(0, 2);           // ���� 1  (R0_1)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 2  (R0_2)
    Item->SubItems->Add(IntToHex(200, 2));    // ���� 3  (R0_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 4  (R0_4)
    // Reg[1]=0x080080C9;
    Item->SubItems->Add(IntToHex(201, 2));    // ���� 5  (R1_1)
    Item->SubItems->Add(IntToHex(128, 2));    // ���� 6  (R1_2)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 7  (R1_3)
    Item->SubItems->Add(IntToHex(8, 2));      // ���� 8  (R1_4)
    // Reg[2]=0x00004EC2;
    Item->SubItems->Add(IntToHex(194, 2));    // ���� 9  (R2_1)
    Item->SubItems->Add(IntToHex(78, 2));     // ���� 10 (R2_2)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 11 (R2_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 12 (R2_4)
    c3=false;                                 // ������ ���������� ����� � LV_Sar3
    B_AddSar3->Enabled=false;                 // ���������� ������ "������� ������ Sar3"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_AddSar4Click(TObject *Sender)
{
  if(c4)                                      // ���� ��� ������� ���������� ����� � LV_Sar4
  {
    TListItem *Item = LV_Sar4->Items->Add();  // �������� ����� ������ LV_Sar4
    // ��������� ������� ���������� �� ���������
    // Reg[3]=0x000004B3;
    Item->Caption = IntToHex(179, 2);         // ���� 13 (R3_1)
    Item->SubItems->Add(IntToHex(4, 2));      // ���� 14 (R3_2)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 15 (R3_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 16 (R3_4)
    // Reg[4]=0x00A5003C;
    Item->SubItems->Add(IntToHex(60, 2));     // ���� 17 (R4_1)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 18 (R4_2)
    Item->SubItems->Add(IntToHex(165, 2));    // ���� 19 (R4_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 20 (R4_4)
    // Reg[5]=0x00580005;
    Item->SubItems->Add(IntToHex(5, 2));      // ���� 21 (R5_1)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 22 (R5_2)
    Item->SubItems->Add(IntToHex(88, 2));     // ���� 23 (R5_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 24 (R5_4)
    c4=false;                                 // ������ ���������� ����� � LV_Sar4
    B_AddSar4->Enabled=false;                 // ���������� ������ "������� ������ Sar4"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DeleteSar3Click(TObject *Sender) // ������� �� ������ "������� ������ Sar3"
{
  if (LV_Sar3->Selected != NULL)  // ���� ��������� ������ LV_Sar3 �� �����
  {
    LV_Sar3->Selected->Delete();  // ������� ��������� ������
    c3=true;                      // ���������� ���������� ����� � LV_Sar3
    B_AddSar3->Enabled=true;      // ��������� ������ "������� ������ Sar3"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DeleteSar4Click(TObject *Sender)
{
  if (LV_Sar4->Selected != NULL)  // ���� ��������� ������ LV_Sar4 �� �����
  {
    LV_Sar4->Selected->Delete();  // ������� ��������� ������
    c4=true;                      // ���������� ���������� ����� � LV_Sar4
    B_AddSar4->Enabled=true;      // ��������� ������ "������� ������ Sar4"
  }
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

void __fastcall TMain_Form::LVScanDblClick(TObject *Sender)  // ������� ������ �� LVScan
{
  if (LVScan->Selected!= NULL) F_BT->ShowModal();  
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
/*
  ���������� ������� "��������� ��������� ����� (��)" ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size.
*/

  if((size_t)LVScan->Items->Count!=0) // ���� ���������� ����� LVScan �� �������
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i)  // ������� �� �� ���������� ����� LVScan
    {
      Command3[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());            // �������� �������� ������ ��
      float EPR=StrToFloat(LVScan->Items->Item[i]->SubItems->Strings[2].c_str());  // ����������� �������� ���
      Command3[i][3]=int(sqrt(EPR));                                               // �������� �������� ��������� ��

      //M_Debug->Lines->Add(Command3[i][1]);
      //M_Debug->Lines->Add(Command3[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i) // ������� �� �� ��������� ������
    {                                                   // LVScan �� 64
      //M_Debug->Lines->Add(Command3[i][1]);
      //M_Debug->Lines->Add(Command3[i][3]);
    }
  }
  else                                // ���� � LVScan ������ �����������
  {
    for(int i=0;i<64;++i)             // ������� �� �� 1 �� 64
    {
      //M_Debug->Lines->Add(Command3[i][1]);
      //M_Debug->Lines->Add(Command3[i][3]);
    }
  }
/*
  ���������� ������� "����� �������� (��)" ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size.
*/
  if((size_t)LV_Sar1->Items->Count!=0) // ���� ���������� ����� LV_Sar1 �� �������
  {
    Fi=StrToFloat(LV_Sar1->Items->Item[0]->SubItems->Strings[1].c_str());  // ����������� �������� ����������� �����
    //M_Debug->Lines->Add(Fi);
  }

  if((size_t)LVScan->Items->Count!=0) // ���� ���������� ����� LVScan �� �������
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // ������� �� ���������� ����� LVScan
    {
      Command4[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());  // �������� �������� ������ ��
      X=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[0].c_str());  // ����������� �������� ���������� �� �� ��� X
      Y=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[1].c_str());  // ����������� �������� ���������� �� �� ��� Y
      float arg=Fi*pi/180;                                  // ������� �������� � �������
      float Xi=X*cos(arg)+Y*sin(arg);                       // ���������� X � ������ ����������� ����� Fi
      float Tau=((2*Xi)/c-0.000001)*1000000000;             // ����� �������� �� [��], ���� �������� ������� 1 ��
      int Tau_LSB=((int)Tau)&0xFF;                          // ������� ���� ������� �������� ��
      int Tau_MSB=((int)Tau/256)&0xFF;                      // ������� ���� ������� �������� ��
      Command4[i][2]=Tau_MSB;                               // �������� �������� �������� ����� ������� �������� ��
      Command4[i][3]=Tau_LSB;                               // �������� �������� �������� ����� ������� �������� ��

      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i)     // ������� �� �� ��������� ������
    {                                                       // LVScan �� 64
      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
  }
  else                                // ���� � LVScan ������ �����������
  {
    for(int i=0;i<64;++i)             // ������� �� �� 1 �� 64
    {
      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
  }
/*
  ���������� ������� "������������ ����� ������� (��)" ������ ������������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size.
*/
  if((size_t)LV_Sar1->Items->Count!=0) // ���� ���������� ����� LV_Sar1 �� �������
  {
    V=StrToInt(LV_Sar1->Items->Item[0]->Caption.c_str());              // ����������� �������� �������� ����� ���
    f=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[0].c_str()); // ����������� �������� ������� �������
    D=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[3].c_str()); // ����������� �������� ���������� �� ����

    //M_Debug->Lines->Add(D);
  }

  if((size_t)LVScan->Items->Count!=0) // ���� ���������� ����� LVScan �� �������
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // ������� �� ���������� ����� LVScan
    {
      Command4[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());  // �������� �������� ������ ��
      X=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[0].c_str());  // ����������� �������� ���������� �� �� ��� X
      Y=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[1].c_str());  // ����������� �������� ���������� �� �� ��� Y
      float arg=Fi*pi/180;                                  // ������� �������� � �������
      float Yi=Y*cos(arg)-X*sin(arg);                       // ���������� Y � ������ ����������� ����� Fi
      float fdi=f*V*Yi/c*D;                                 // ������������ �������� �� [��], ���� �������� ������� 0.5 ��
      int fdi_LSB=((int)fdi)&0xFF;                          // ������� ���� ������������� �������� ��
      int fdi_MSB=((int)fdi/256)&0xFF;                      // ������� ���� ������������� �������� ��
      Command5[i][2]=fdi_MSB;                               // �������� �������� �������� ����� ������������� �������� ��
      Command5[i][3]=fdi_LSB;                               // �������� �������� �������� ����� ������������� �������� ��

      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i)     // ������� �� �� ��������� ������
    {                                                       // LVScan �� 64
      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
  }
  else                                // ���� � LVScan ������ �����������
  {
    for(int i=0;i<64;++i)             // ������� �� �� 1 �� 64
    {
      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
  }
/*
  ���������� ������� "��������� ��������� ����� (��)" ������ ��������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size.
*/

  if((size_t)LVScan->Items->Count!=0) // ���� ���������� ����� LVScan �� �������
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i)  // ������� �� �� ���������� ����� LVScan
    {
      Com3[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());                // �������� �������� ������ ��
      float EPR=StrToFloat(LVScan->Items->Item[i]->SubItems->Strings[2].c_str());  // ����������� �������� ���
      Com3[i][3]=int(sqrt(EPR));                                                   // �������� �������� ��������� ��

      //M_Debug->Lines->Add(Com3[i][1]);
      //M_Debug->Lines->Add(Com3[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i) // ������� �� �� ��������� ������
    {                                                   // LVScan �� 64
      //M_Debug->Lines->Add(Com3[i][1]);
      //M_Debug->Lines->Add(Com3[i][3]);
    }
  }
  else                                // ���� � LVScan ������ �����������
  {
    for(int i=0;i<64;++i)             // ������� �� �� 1 �� 64
    {
      //M_Debug->Lines->Add(Com3[i][1]);
      //M_Debug->Lines->Add(Com3[i][3]);
    }
  }
/*
  ���������� ������� "����� �������� (��)" ������ ��������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size.
*/
  if((size_t)LV_Sar1->Items->Count!=0) // ���� ���������� ����� LV_Sar1 �� �������
  {
    Fi=StrToFloat(LV_Sar1->Items->Item[0]->SubItems->Strings[1].c_str());  // ����������� �������� ����������� �����
    //M_Debug->Lines->Add(Fi);
  }

  if((size_t)LVScan->Items->Count!=0) // ���� ���������� ����� LVScan �� �������
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // ������� �� ���������� ����� LVScan
    {
      Com4[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());      // �������� �������� ������ ��
      X=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[0].c_str());  // ����������� �������� ���������� �� �� ��� X
      Y=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[1].c_str());  // ����������� �������� ���������� �� �� ��� Y
      float arg=Fi*pi/180;                                  // ������� �������� � �������
      float Xi=X*cos(arg)+Y*sin(arg);                       // ���������� X � ������ ����������� ����� Fi
      float Tau=((2*Xi)/c-0.000001)*1000000000;             // ����� �������� �� [��], ���� �������� ������� 1 ��
      int Tau_LSB=((int)Tau)&0xFF;                          // ������� ���� ������� �������� ��
      int Tau_MSB=((int)Tau/256)&0xFF;                      // ������� ���� ������� �������� ��
      Com4[i][2]=Tau_MSB;                                   // �������� �������� �������� ����� ������� �������� ��
      Com4[i][3]=Tau_LSB;                                   // �������� �������� �������� ����� ������� �������� ��

      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i)     // ������� �� �� ��������� ������
    {                                                       // LVScan �� 64
      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
  }
  else                                // ���� � LVScan ������ �����������
  {
    for(int i=0;i<64;++i)             // ������� �� �� 1 �� 64
    {
      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
  }
/*
  ���������� ������� "������������ ����� ������� (��)" ������ ��������
  size_t - ������������ �������� ����� ������ �������������� ���� ��� ����� ������� std::string::size.
*/
  if((size_t)LV_Sar1->Items->Count!=0) // ���� ���������� ����� LV_Sar1 �� �������
  {
    V=StrToInt(LV_Sar1->Items->Item[0]->Caption.c_str());              // ����������� �������� �������� ����� ���
    f=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[0].c_str()); // ����������� �������� ������� �������
    D=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[3].c_str()); // ����������� �������� ���������� �� ����

    //M_Debug->Lines->Add(D);
  }

  if((size_t)LVScan->Items->Count!=0) // ���� ���������� ����� LVScan �� �������
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // ������� �� ���������� ����� LVScan
    {
      Com4[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());      // �������� �������� ������ ��
      X=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[0].c_str());  // ����������� �������� ���������� �� �� ��� X
      Y=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[1].c_str());  // ����������� �������� ���������� �� �� ��� Y
      float arg=Fi*pi/180;                                  // ������� �������� � �������
      float Yi=Y*cos(arg)-X*sin(arg);                       // ���������� Y � ������ ����������� ����� Fi
      float fdi=f*V*Yi/c*D;                                 // ������������ �������� �� [��], ���� �������� ������� 0.5 ��
      int fdi_LSB=((int)fdi)&0xFF;                          // ������� ���� ������������� �������� ��
      int fdi_MSB=((int)fdi/256)&0xFF;                      // ������� ���� ������������� �������� ��
      Com5[i][2]=fdi_MSB;                                   // �������� �������� �������� ����� ������������� �������� ��
      Com5[i][3]=fdi_LSB;                                   // �������� �������� �������� ����� ������������� �������� ��

      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i)     // ������� �� �� ��������� ������
    {                                                       // LVScan �� 64
      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
  }
  else                                // ���� � LVScan ������ �����������
  {
    for(int i=0;i<64;++i)             // ������� �� �� 1 �� 64
    {
      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
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
  int max=64;                        // ������������ ��������
  String EdIzm="";                   // ������� ���������
  String value;                      // ������ ��������

  value=E_Command3_0->Text;          // ��������

  b=IsValidInt(min,max,value,EdIzm); // �������� ������������ ��������� ��������
  if(b)                              // ���� ���������
  {
    CB_Command3_1->Clear();          // �������� ���������� ���������� ��
    CB_Command4_1->Clear();
    CB_Command5_1->Clear();
 
    for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
    {
      CB_Command3_1->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
      CB_Command4_1->Items->Add(IntToStr(i+1));
      CB_Command5_1->Items->Add(IntToStr(i+1));
    }

    CB_Command3_1->ItemIndex=0;      // ����� �� �� ��������� ��� ��������� ����� ��
    CB_Command4_1->ItemIndex=0;
    CB_Command5_1->ItemIndex=0;
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
  int i, Command;
  i=CB_Command3_1->ItemIndex;                           // �������� ���������� ����� ��
  Command=StrToInt(E_Command3_2->Text);                 // �������� �������� � ����������
  Command3[OldIndex][3]=Command&0xFF;                   // ��. ����
  Command3[OldIndex][2]=(Command/256)&0xFF;             // ��. ����
  OldIndex=i;                                           // ��������� ������� ���������� �����
  E_Command3_2->Text=IntToStr(Command3[i][2]*256+Command3[i][3]); // �������� ������� ��������
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command4_1Change(TObject *Sender)
// �� ��������� ������ ��
{
  int i, Command;
  i=CB_Command4_1->ItemIndex;                           // �������� ���������� ����� ��
  Command=StrToInt(E_Command4_2->Text);                 // �������� �������� � ����������
  Command4[OldIndex][3]=Command&0xFF;                   // ��. ����
  Command4[OldIndex][2]=(Command/256)&0xFF;             // ��. ����
  OldIndex=i;                                           // ��������� ������� ���������� �����
  E_Command4_2->Text=IntToStr(Command4[i][2]*256+Command4[i][3]); // �������� ������� ��������
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command5_1Change(TObject *Sender)
// �� ��������� ������ ��
{
  int i, Command;
  i=CB_Command5_1->ItemIndex;                           // �������� ���������� ����� ��
  Command=StrToInt(E_Command5_2->Text);                 // �������� �������� � ����������
  Command5[OldIndex][3]=Command&0xFF;                   // ��. ����
  Command5[OldIndex][2]=(Command/256)&0xFF;             // ��. ����
  OldIndex=i;                                           // ��������� ������� ���������� �����
  E_Command5_2->Text=IntToStr(Command5[i][2]*256+Command5[i][3]); // �������� ������� ��������
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command6Change(TObject *Sender)
{
  int Fc=StrToInt(E_Command6->Text);            // ����������� ������� ������� ������
  if(Fc>=8500&&Fc<=17500)                       // ���� �������� ����������
  {
    int rounding=Fc/10;                         // ���������� �� �����, �������� 10
    Fc=rounding*10;
    int code=(Fc-8500)/10;                      // ��������� ���� ����������� �������
    int code_LSB=code&0xFF;                     // ������� ���� ����������� ������� ������� ������
    int code_MSB=(code/256)&0xFF;               // ������� ���� ����������� ������� ������� ������
    Command6[2]=code_MSB;                       // �������� �������� �������� ����� ����������� ������� ������� ������
    Command6[3]=code_LSB;                       // �������� �������� �������� ����� ����������� ������� ������� ������
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
  int max=64;                        // ������������ ��������
  String EdIzm="";                   // ������� ���������
  String value;                      // ������ ��������

  value=E_Com3_0->Text;              // ��������

  b=IsValidInt(min,max,value,EdIzm); // �������� ������������ ��������� ��������
  if(b)                              // ���� ���������
  {
    CB_Com3_1->Clear();              // �������� ���������� ���������� ��
    CB_Com4_1->Clear();
    CB_Com5_1->Clear();
    
    for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
    {
      CB_Com3_1->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
      CB_Com4_1->Items->Add(IntToStr(i+1));
      CB_Com5_1->Items->Add(IntToStr(i+1));
    }

    CB_Com3_1->ItemIndex=0;          // ����� �� �� ��������� ��� ��������� ����� ��
    CB_Com4_1->ItemIndex=0;
    CB_Com5_1->ItemIndex=0;
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
  int i, Command;
  i=CB_Com3_1->ItemIndex;                    // �������� ���������� ����� ��
  Command=StrToInt(E_Com3_2->Text);          // �������� �������� � ����������
  Com3[OldIndex][3]=Command&0xFF;            // ��. ����
  Com3[OldIndex][2]=(Command/256)&0xFF;      // ��. ����
  OldIndex=i;                                // ��������� ������� ���������� �����
  E_Com3_2->Text=IntToStr(Com3[i][2]*256+Com3[i][3]);  // �������� ������� ��������
}

//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com4_1Change(TObject *Sender)
// �� ��������� ������ ��
{
  int i, Command;
  i=CB_Com4_1->ItemIndex;                    // �������� ���������� ����� ��
  Command=StrToInt(E_Com4_2->Text);          // �������� �������� � ����������
  Com4[OldIndex][3]=Command&0xFF;            // ��. ����
  Com4[OldIndex][2]=(Command/256)&0xFF;      // ��. ����
  OldIndex=i;                                // ��������� ������� ���������� �����
  E_Com4_2->Text=IntToStr(Com4[i][2]*256+Com4[i][3]);  // �������� ������� ��������
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::CB_Com5_1Change(TObject *Sender)
// �� ��������� ������ ��
{
  int i, Command;
  i=CB_Com5_1->ItemIndex;                    // �������� ���������� ����� ��
  Command=StrToInt(E_Com5_2->Text);          // �������� �������� � ����������
  Com5[OldIndex][3]=Command&0xFF;            // ��. ����
  Com5[OldIndex][2]=(Command/256)&0xFF;      // ��. ����
  OldIndex=i;                                // ��������� ������� ���������� �����
  E_Com5_2->Text=IntToStr(Com5[i][2]*256+Com5[i][3]);  // �������� ������� ��������
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
  RG_Mode->Enabled=false;
  GB_File->Enabled=false;
  GB_Commands->Enabled=false;
  PC_Main->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StopControl()
{
  RG_Mode->Enabled=true;
  GB_File->Enabled=true;
  GB_Commands->Enabled=true;
  PC_Main->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StartTesting()
{
  RG_Mode->Enabled=false;
  GB_File->Enabled=false;
  GB_Commands->Enabled=false;
  PC_Main->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StopTesting()
{
  RG_Mode->Enabled=true;
  GB_File->Enabled=true;
  GB_Commands->Enabled=true;
  PC_Main->Enabled=true;
}
//---------------------------------------------------------------------------






