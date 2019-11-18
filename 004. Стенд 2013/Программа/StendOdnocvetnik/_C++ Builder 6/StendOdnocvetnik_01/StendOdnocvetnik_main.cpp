//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "StendOdnocvetnik_main.h"
#include "AboutBox.h"
#include "NIDAQmx.h"
#include <fstream>    // �������� �������� �����-������
#include <dstring.h>
using namespace std;
/*
  ���������� 1:
  P0.0, P0.1, P0.2 = 1 - ������� ���, = 0 - ����.
  P0.3, P0.4, P0.5 = 1 - �������� ������� ����� ��� ���, = 0 - ����.
  P0.0 - ������ �������� -6�;
  P0.1 - ������ �������� +6�;
  P0.2 - ������ �������� +20�;
  P0.3 - ������ ��������� ������� ����� ��� -6�;
  P0.4 - ������ ��������� ������� ����� ��� +6�;
  P0.5 - ������ ��������� ������� ����� ��� +20�;

  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �1
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �1
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �1
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �1
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �1
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �1

  ���������� 2:
  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �2
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �2
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �2
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �2
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �2
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �2

  ���������� 3:
  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �3
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �3
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �3
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �3
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �3
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �3

  ���������� 4:
  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �4
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �4
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �4
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �4
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �4
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �4
*/
unsigned char P0[8],P1[4]; // ����� ������ ��� �������� ������
const int NumReadValue=10;

bool ErrorADC;
bool greenflag1, greenflag2, greenflag3, greenflag4;

unsigned char Dev1P0[8],Dev1P1[4],Dev2P0[8],Dev2P1[4]; // �������� ��������� �����
unsigned char Dev3P0[8],Dev3P1[4],Dev4P0[8],Dev4P1[4];

//  ����������� ����������� ������
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;
const int TumblerOff=4;

const char *Dev1_port0_line0_2 = "Dev1/port0/line0:2";
const char *Dev1_port0_line3_5 = "Dev1/port0/line3:5";
const char *Dev1_port0_line3 = "Dev1/port0/line3";
const char *Dev1_port0_line4 = "Dev1/port0/line4";
const char *Dev1_port0_line5 = "Dev1/port0/line5";

const char *Dev1_ai0= "Dev1/ai0";
const char *Dev1_ai1= "Dev1/ai1";
const char *Dev1_ai2= "Dev1/ai2";
const char *Dev1_ai3= "Dev1/ai3";
const char *Dev1_ai4= "Dev1/ai4";
const char *Dev1_ai5= "Dev1/ai5";

const char *Dev2_ai0= "Dev2/ai0";
const char *Dev2_ai1= "Dev2/ai1";
const char *Dev2_ai2= "Dev2/ai2";
const char *Dev2_ai3= "Dev2/ai3";
const char *Dev2_ai4= "Dev2/ai4";
const char *Dev2_ai5= "Dev2/ai5";

const char *Dev3_ai0= "Dev3/ai0";
const char *Dev3_ai1= "Dev3/ai1";
const char *Dev3_ai2= "Dev3/ai2";
const char *Dev3_ai3= "Dev3/ai3";
const char *Dev3_ai4= "Dev3/ai4";
const char *Dev3_ai5= "Dev3/ai5";

const char *Dev4_ai0= "Dev4/ai0";
const char *Dev4_ai1= "Dev4/ai1";
const char *Dev4_ai2= "Dev4/ai2";
const char *Dev4_ai3= "Dev4/ai3";
const char *Dev4_ai4= "Dev4/ai4";
const char *Dev4_ai5= "Dev4/ai5";

const char *DangerI_IPO1 = "������������ ���������� ���� ���1 �� ������������ ��������!";
const char *DangerI_IPO2 = "������������ ���������� ���� ���2 �� ������������ ��������!";
const char *DangerI_IPO3 = "������������ ���������� ���� ���3 �� ������������ ��������!";
const char *DangerI_IPO4 = "������������ ���������� ���� ���4 �� ������������ ��������!";

const char *DangerU_IPO1 = "������������ ���������� ���������� ���1 �� ������������ ��������!";
const char *DangerU_IPO2 = "������������ ���������� ���������� ���2 �� ������������ ��������!";
const char *DangerU_IPO3 = "������������ ���������� ���������� ���3 �� ������������ ��������!";
const char *DangerU_IPO4 = "������������ ���������� ���������� ���4 �� ������������ ��������!";

const char *DangerI_IPP1 = "������������ ���������� ���� ���1 �� ������������ ��������!";
const char *DangerI_IPP2 = "������������ ���������� ���� ���2 �� ������������ ��������!";
const char *DangerI_IPP3 = "������������ ���������� ���� ���3 �� ������������ ��������!";
const char *DangerI_IPP4 = "������������ ���������� ���� ���4 �� ������������ ��������!";

const char *DangerU_IPP1 = "������������ ���������� ���������� ���1 �� ������������ ��������!";
const char *DangerU_IPP2 = "������������ ���������� ���������� ���2 �� ������������ ��������!";
const char *DangerU_IPP3 = "������������ ���������� ���������� ���3 �� ������������ ��������!";
const char *DangerU_IPP4 = "������������ ���������� ���������� ���4 �� ������������ ��������!";

const char *DangerI_IMP1 = "������������ ���������� ���� ���1 �� ������������ ��������!";
const char *DangerI_IMP2 = "������������ ���������� ���� ���2 �� ������������ ��������!";
const char *DangerI_IMP3 = "������������ ���������� ���� ���3 �� ������������ ��������!";
const char *DangerI_IMP4 = "������������ ���������� ���� ���4 �� ������������ ��������!";

const char *DangerU_IMP1 = "������������ ���������� ���������� ���1 �� ������������ ��������!";
const char *DangerU_IMP2 = "������������ ���������� ���������� ���2 �� ������������ ��������!";
const char *DangerU_IMP3 = "������������ ���������� ���������� ���3 �� ������������ ��������!";
const char *DangerU_IMP4 = "������������ ���������� ���������� ���4 �� ������������ ��������!";

String FileStend="";
AnsiString Nominal1[8]; // ����������� �������� ����� �
AnsiString Nominal2[8]; // ���������� ���������� ������� ������ ���,
AnsiString Nominal3[8]; // � ��� �� ����� ����� � ������ �������
AnsiString Nominal4[8];

double FNominal1[8];    // ����������� �������� ����� �
double FNominal2[8];    // ���������� ���������� ������� ������ ���,
double FNominal3[8];    // � ��� �� ����� ����� � ������ �������
double FNominal4[8];

double Umin=0.7, Umax=1.3, Imin=0.95, Imax=1.05; // ���������� U � I �� ������������ ��������

float Source[24];       // ���������� �������� ����� � ���������� ���������� ������� ������ ���
float value;
int k1=1, k2=2;         // ������������, ����������� �������� �� 2

// ���������� ���������� ��������� 
int Checkm6VCounter=-1;
int Checkp6VCounter=-1;
int Checkp20VCounter=-1;

float Buffer0[10];              // ������� �������
unsigned char SampleCount0=0;   // ����� ������
float Sum0=0;                   // 0..0x0ffffffff
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* ��������� ���������� ������������������ ������������� ������� �����, �����
��������������� ��������� �������� ������������ �� ������� */
#pragma resource "*.dfm"  // ��� ����� ���� ������������ ���� .dfm � ��� �� ������, ��� � ��� ������� �����
TMainForm *MainForm;      // ���������� ��������� �� ������ ����� MainForm ������ TMainForm 
TIniFile *Ini;
void __fastcall (TMainForm::*Method)(void); // ��������� �� ����� ������ TMainForm  
//---------------------------------------------------------------------------
// ����� ������������ ����� Main_Form
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
  ClearDevs();  // ������� �������� �������� ������ ��������� 1...4
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddSaveLog(AnsiString comment) // �������� ����������� � ��������� ���
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
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
/*
  FormatDateTime (s, dt) - ������ ��������, �������������� ����� ���� ��� �����. ������ �������������
  ������ ������ ������� s, ��������, ������ dd/mm/yyyy ������, ��� ��������� ������� �������� ����,
  � ������ hh:mm � �����
*/
  AnsiString DateTime = FormatDateTime("YYYY.MM.DD",Date())+"_"+FormatDateTime("HH-NN-SS",Time()); // ������� ���� � �����
  logFname = DateTime;              // ������ ����� ��� ����� � ����� ��� �������� ���������
  AddSaveLog("��������� ��������"); // �������� ����������� � ��������� ���

  // ������������� ������ ��� �������� �����:
  PowerOff();                       // ��������� ��� ��������� ������� ������ ���

  for(int i=0; i<8; i++)
  {
    Nominal1[i]="0";
    Nominal2[i]="0";
    Nominal3[i]="0";
    Nominal4[i]="0";
  }

  for(int i=0; i<8; i++)
  {
    FNominal1[i]=0.0;
    FNominal2[i]=0.0;
    FNominal3[i]=0.0;
    FNominal4[i]=0.0;
  }

  greenflag1=greenflag2=greenflag3=greenflag4=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  AddSaveLog("��������� �������"); // �������� ����������� � ��������� ���  
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Starting(void)
// ������������ ��������
{
  // �������� �������� ��������� ��������� -6� ,+6�, +20�
  ReadDigChan(Dev1_port0_line0_2, P0);  // ������ � ����� ������ ��������� ����� P0 ���������� 1
/*
  for(int i=0; i<8; i++)
  {
    Memo1->Lines->Add(P0[i]);
  }
*/
  PowerOff();                 // ��������� ��� ��������� ������� ������ ���

  if(!P0[0]||!P0[1]||!P0[2])  // �������� ��������� ��������� -6� ,+6�, +20�
  {
    Application->MessageBox("�������� -6� ,+6�, +20� � ��������� ����. ��������� �������� � ��������� ���.","��������",MB_ICONWARNING);
    B_Go->Enabled=true;
    B_Stop->Enabled=false;
  }
  else
  {
    B_Go->Enabled=false;
    B_Stop->Enabled=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
  Memo1->Clear();
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::ReadDigChan(const char *Config, char *DigPort)
// ������ � ����� ������ ��������� ����� Px ���������� y
{
	TaskHandle	taskHandle=0;
	char		errBuff[2048]={'\0'};

  // ������� ������
	if(DAQmxCreateTask("",&taskHandle))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ���������� ��������� ������
	if(DAQmxCreateDIChan(taskHandle,Config,"",DAQmx_Val_ChanForAllLines))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // ��������� ������
	if(DAQmxStartTask(taskHandle))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

	// ���������� ������
	if(DAQmxReadDigitalLines(taskHandle,1,10.0,DAQmx_Val_GroupByChannel,DigPort,100,NULL,NULL,NULL))
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
void __fastcall TMainForm::B_GoClick(TObject *Sender)
{
  Starting();
  Verification();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_StopClick(TObject *Sender)
{
  B_Go->Enabled=true;
  B_Stop->Enabled=false;
  PowerOffWithDelay(); // ��������� ��� ��������� ������� ������ ��� � ����������
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Dev1ToP0P1(void)
// ������ �������� �������� ������ ���������� 1 � ����� ������ P0 � P1
{
  int i;

  for(i=0;i<8;i++)
  {
    P0[i]=Dev1P0[i];
  }

  for(i=0;i<4;i++)
  {
    P1[i]=Dev1P1[i];
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Dev2ToP0P1(void)
// ������ �������� �������� ������ ���������� 2 � ����� ������ P0 � P1
{
  int i;

  for(i=0;i<8;i++)
  {
    P0[i]=Dev2P0[i];
  }

  for(i=0;i<4;i++)
  {
    P1[i]=Dev2P1[i];
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Dev3ToP0P1(void)
// ������ �������� �������� ������ ���������� 3 � ����� ������  P0 � P1
{
  int i;

  for(i=0;i<8;i++)
  {
    P0[i]=Dev3P0[i];
  }

  for(i=0;i<4;i++)
  {
    P1[i]=Dev3P1[i];
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Dev4ToP0P1(void)
// ������ �������� �������� ������ ���������� 4 � ����� ������  P0 � P1
{
  int i;

  for(i=0;i<8;i++)
  {
    P0[i]=Dev4P0[i];
  }

  for(i=0;i<4;i++)
  {
    P1[i]=Dev4P1[i];
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClearDevs(void)
// ������� �������� �������� ������ ��������� 1...4
{            
  int i;

  for(i=0;i<8;i++)
  {
    Dev1P0[i]=1;
    Dev2P0[i]=1;
    Dev3P0[i]=1;
    Dev4P0[i]=1;
  }

  for(i=0;i<4;i++)
  {
    Dev1P1[i]=1;
    Dev2P1[i]=1;
    Dev3P1[i]=1;
    Dev4P1[i]=1;
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
void __fastcall TMainForm::RB_Selected1Click(TObject *Sender)
{
  if(RB_Selected1->Checked==true)
  {
    RB_Selected2->Checked=false;
    RB_Selected3->Checked=false;
    RB_Selected4->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RB_Selected2Click(TObject *Sender)
{
  if(RB_Selected2->Checked==true)
  {
    RB_Selected1->Checked=false;
    RB_Selected3->Checked=false;
    RB_Selected4->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RB_Selected3Click(TObject *Sender)
{
  if(RB_Selected3->Checked==true)
  {
    RB_Selected1->Checked=false;
    RB_Selected2->Checked=false;
    RB_Selected4->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RB_Selected4Click(TObject *Sender)
{
  if(RB_Selected4->Checked==true)
  {
    RB_Selected1->Checked=false;
    RB_Selected2->Checked=false;
    RB_Selected3->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadStendClick(TObject *Sender)
{
  OpenDialog1->DefaultExt=".stend";
  OpenDialog1->FileName="*.stend";
  OpenDialog1->Filter="���� ��������� (*.stend)|*.stend";
  OpenDialog1->Title=" �������� ����� ���������";

  String File;

  if(OpenDialog1->Execute())
  {
    File=OpenDialog1->FileName;
    FileStend=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("�������� ������","��� ����������", "��������");
*/
      if(RB_Selected1->Checked==true)
      {
        NominalNumber(Nominal1); // ����� ������, ��� �������� ����������� ����������� ��������

        // �������� �������� ����� ��������� ������ ������������� � ����� 1
        for(int i=0; i<8; i++)
        {
          if(Nominal1[i].IsEmpty()) // ���� ������ ������
          {
            greenflag1=false;
            B_Go->Enabled=false;
            B_Stop->Enabled=false;
            P_Selected1->Color=clRed;
            Application->MessageBox("���� ��������� ������ ������������� � ����� 1 �� ��������!","��������",MB_ICONWARNING);
            break;
          }
          else
          {
            greenflag1=true;
            P_Selected1->Color=clGreen;
            FNominal1[i]=Nominal1[i].ToDouble(); // FNominal1[i]=StrToFloat(Nominal1[i]);
          }
        }

        if(greenflag1) Application->MessageBox("���� ��������� ������ ������������� � ����� 1 ��������!","��������",MB_ICONWARNING);
        /*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(Nominal1[i]);
        }
        */
      }
      if(RB_Selected2->Checked==true)
      {
        NominalNumber(Nominal2); // ����� ������, ��� �������� ����������� ����������� ��������

        // �������� �������� ����� ��������� ������ ������������� � ����� 2
        for(int i=0; i<8; i++)
        {
          if(Nominal2[i].IsEmpty()) // ���� ������ ������
          {
            B_Go->Enabled=false;
            B_Stop->Enabled=false;
            P_Selected2->Color=clRed;
            Application->MessageBox("���� ��������� ������ ������������� � ����� 2 �� ��������!","��������",MB_ICONWARNING);
            break;
          }
          else
          {
            greenflag2=true;
            P_Selected2->Color=clGreen;
            FNominal2[i]=Nominal2[i].ToDouble(); // FNominal2[i]=StrToFloat(Nominal2[i]);
          }
        }

        if(greenflag2) Application->MessageBox("���� ��������� ������ ������������� � ����� 2 ��������!","��������",MB_ICONWARNING);       
        /*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(Nominal2[i]);
        }
        */
      }
      if(RB_Selected3->Checked==true)
      {
        NominalNumber(Nominal3); // ����� ������, ��� �������� ����������� ����������� ��������

        // �������� �������� ����� ��������� ������ ������������� � ����� 3
        for(int i=0; i<8; i++)
        {
          if(Nominal3[i].IsEmpty()) // ���� ������ ������
          {
            B_Go->Enabled=false;
            B_Stop->Enabled=false;
            P_Selected3->Color=clRed;
            Application->MessageBox("���� ��������� ������ ������������� � ����� 3 �� ��������!","��������",MB_ICONWARNING);
            break;
          }
          else
          {
            greenflag3=true;
            P_Selected3->Color=clGreen;
            FNominal3[i]=Nominal3[i].ToDouble(); // FNominal3[i]=StrToFloat(Nominal3[i]);
          }
        }

        if(greenflag3) Application->MessageBox("���� ��������� ������ ������������� � ����� 3 ��������!","��������",MB_ICONWARNING);
        /*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(Nominal3[i]);
        }
        */
      }
      if(RB_Selected4->Checked==true)
      {
        NominalNumber(Nominal4); // ����� ������, ��� �������� ����������� ����������� ��������

        // �������� �������� ����� ��������� ������ ������������� � ����� 4
        for(int i=0; i<8; i++)
        {
          if(Nominal4[i].IsEmpty()) // ���� ������ ������
          {
            B_Go->Enabled=false;
            B_Stop->Enabled=false;
            P_Selected4->Color=clRed;          
            Application->MessageBox("���� ��������� ������ ������������� � ����� 4 �� ��������!","��������",MB_ICONWARNING);
            break;
          }
          else
          {
            greenflag4=true;
            P_Selected4->Color=clGreen;
            FNominal4[i]=Nominal4[i].ToDouble(); // FNominal4[i]=StrToFloat(Nominal4[i]);
          }
        }

        if(greenflag4) Application->MessageBox("���� ��������� ������ ������������� � ����� 4 ��������!","��������",MB_ICONWARNING);
        /*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(Nominal4[i]);
        }
        */
      }
      if(greenflag1&&greenflag2&&greenflag3&&greenflag4) B_Go->Enabled=true;

      delete Ini;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Verification(void)
// �������� ����������� �������� ���������� ���������� ������� ������ ���
{
  B_Go->Enabled=false;
  B_Stop->Enabled=true;

  // �������� ������������� ��������� ������� -6� ���� ���������
  P0[3]=1;                               // �������� -6�
  WriteDigChan(Dev1_port0_line3, P0);    // ������ � �������� ���� P0 ���������� 1
  Delay();                               // �������� 1 ���
  Checkm6V();                            // �������� ������������� ���������� ������� ������ ��� -6�

  // �������� ������������� ��������� ������� +6� ���� ���������
  P0[4]=1;                               // �������� +6�
  WriteDigChan(Dev1_port0_line4, P0);    // ������ � �������� ���� P0 ���������� 1
  Delay();                               // �������� 1 ���
  Checkp6V();                            // �������� ������������� ���������� ������� ������ ��� +6�

  // �������� ������������� ��������� ������� +20� ���� ���������
  P0[5]=1;                               // �������� +20�
  WriteDigChan(Dev1_port0_line5, P0);    // ������ � �������� ���� P0 ���������� 1
  Delay();                               // �������� 1 ���
  Checkp20V();                           // �������� ������������� ���������� ������� ������ ��� +20�
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Delay(void)
// ������� ��������
{
  Sleep(1000);                           // 1000 ��
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();      
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
void __fastcall TMainForm::Checkm6V(void)
// �������� ������������� ���������� ������� ������ ��� -6�
{
  T_Checkm6V->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Checkp6V(void)
// �������� ������������� ���������� ������� ������ ��� +6�
{
  T_Checkp6V->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Checkp20V(void)
// �������� ������������� ���������� ������� ������ ��� +20�
{
  T_Checkp20V->Enabled=true;
}
//---------------------------------------------------------------------------
float __fastcall TMainForm::MovingAverage0(float value)
// ������������ ������� "����������� ��������"
{
  Buffer0[SampleCount0]=value;                 // ������� ����� ����� � "�������"
  unsigned char i;                             // 0..0x0ff

  // ������� ������� �� "�������":
  for (Sum0=0, i=0; i<10; i++)
  {
    Sum0 += Buffer0[i];
  }

  Sum0=Sum0/10;
  value = Sum0;
  SampleCount0++;

  if (SampleCount0 == 10)
  {
    SampleCount0 = 0;
  }

  return value;
}
//---------------------------------------------------------------------------
String TMainForm::RoundValue(float delta, String value)
{
  float temp;
  float temp1;

  temp=StrToFloat(value);
  temp1=Log10(delta);         // ���������� ������ ����� �������
  value=RoundTo(temp,temp1);  // ��������� �� �������� � 2-�� ����������� ������� ����� �������

  return value;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PowerOff(void)
// ��������� ��� ��������� ������� ������ ���
{
  P0[3]=0;                               // �������� -6�
  P0[4]=0;                               // �������� +6�
  P0[5]=0;                               // �������� +20�
  WriteDigChan(Dev1_port0_line3_5, P0);  // ������ � �������� ���� P0 ���������� 1
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PowerOffWithDelay(void)
// ��������� ��� ��������� ������� ������ ��� � ����������
{
  T_Checkp20V->Enabled=false;
  Powerp20VOff(); // ��������� ��������� ������� +20� ������ ���
  Delay();        // �������� 1 ���

  T_Checkp6V->Enabled=false;
  Powerp6VOff();  // ��������� ��������� ������� +6� ������ ���
  Delay();        // �������� 1 ���

  T_Checkm6V->Enabled=false;
  Powerm6VOff();  // ��������� ��������� ������� -6� ������ ���
  Delay();        // �������� 1 ���
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Powerm6VOff(void)
// ��������� ��������� ������� -6� ������ ���
{
  P0[3]=0;                             // �������� -6�
  WriteDigChan(Dev1_port0_line3, P0);  // ������ � �������� ���� P0 ���������� 1
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Powerp6VOff(void)
// ��������� ��������� ������� +6� ������ ���
{
  P0[4]=0;                             // �������� +6�
  WriteDigChan(Dev1_port0_line4, P0);  // ������ � �������� ���� P0 ���������� 1
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Powerp20VOff(void)
// ��������� ��������� ������� +20� ������ ���
{
  P0[5]=0;                             // �������� +20�
  WriteDigChan(Dev1_port0_line5, P0);  // ������ � �������� ���� P0 ���������� 1
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NominalNumber(AnsiString *Nominal)
// ����� ������, ��� �������� ����������� ����������� ��������
{
  Nominal[0]=Ini->ReadString("�����","I���-6�","1");
  Nominal[1]=Ini->ReadString("�����","U���-6�","1");
  Nominal[2]=Ini->ReadString("�����","I���+6�","1");
  Nominal[3]=Ini->ReadString("�����","U���+6�","1");
  Nominal[4]=Ini->ReadString("�����","I���+20�","1");
  Nominal[5]=Ini->ReadString("�����","U���+20�","1");
  Nominal[6]=Ini->ReadString("�����","T�����","1");
  Nominal[7]=Ini->ReadString("�����","T������","1");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CheckOfChannel(const char *Config, TLabeledEdit *Parameter,
                double minAllow, double maxAllow, double Nom, const char *Message,
                TPanel *Protection, void __fastcall (TMainForm::*pm)(void), int koef)
// �������� ����������� ������
{
  double min, max;
  
  value = ReadAnalogChan(Config)*koef;                 // ������ ����������� ������ x ����� AI ���������� y
  Parameter->Text=RoundValue(0.01, FloatToStr(value)); // 2 ���������� ����� ����� �������

  min=Nom*minAllow;
  max=Nom*maxAllow;

  //Memo1->Lines->Add(Nom);
  //Memo1->Lines->Add(min);
  //Memo1->Lines->Add(maxAllow);

  if((value>max)||(value<min)||(ErrorADC))  // �������� ��������� ����������� �������� ���������
  {                                             
    T_Checkm6V->Enabled=false;
    T_Checkp6V->Enabled=false;
    T_Checkp20V->Enabled=false;
    Application->MessageBox(Message,"��������",MB_ICONWARNING);
    B_Go->Enabled=true;
    B_Stop->Enabled=false;
    // ��������� ��������� �������:
    (MainForm->*pm)();   // ����� � ������� ��������� �� ������������ ������, � ������ � ��������� �� ����� ����� �������
    Delay();             // �������� 1 ���
    PowerOffWithDelay(); // ��������� ��� ��������� ������� ������ ��� � ����������
    Protection->Color=clRed;
  }
  else
  {
    B_Go->Enabled=false;
    B_Stop->Enabled=true;
    T_Checkm6V->Enabled=true;
    T_Checkp6V->Enabled=true;
    T_Checkp20V->Enabled=true;
    Protection->Color=clBtnFace;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Checkm6VTimer(TObject *Sender)
{
  Checkm6VCounter++;
  Method = &TMainForm::Powerm6VOff; // ��������� ��������� �� ����� ������ TMainForm ����� ������ Powerm6VOff

  switch(Checkm6VCounter)
  {
    case 0:
      // ��� ���1:
      CheckOfChannel(Dev1_ai0, LE_I_IPO1, Imin, Imax, FNominal1[0], DangerI_IPO1, P_Protection1, Method, k2);
      break;

    case 1:
      // ��� ���2:
      CheckOfChannel(Dev2_ai0, LE_I_IPO2, Imin, Imax, FNominal2[0], DangerI_IPO2, P_Protection2, Method, k2);
      break;
/*
    case 2:
      // ��� ���3:
      CheckOfChannel(Dev3_ai0, LE_I_IPO3, Imin, Imax, FNominal3[0], DangerI_IPO3, P_Protection3, Method, k2);
      break;

    case 3:
      // ��� ���4:
      CheckOfChannel(Dev4_ai0, LE_I_IPO4, Imin, Imax, FNominal4[0], DangerI_IPO4, P_Protection4, Method, k2);
      break;
*/
    case 4:
      // ���������� ���1:
      CheckOfChannel(Dev1_ai1, LE_U_IPO1, Umin, Umax, FNominal1[1], DangerU_IPO1, P_Protection1, Method, k1);
      break;

    case 5:
      // ���������� ���2:
      CheckOfChannel(Dev2_ai1, LE_U_IPO2, Umin, Umax, FNominal2[1], DangerU_IPO2, P_Protection2, Method, k1);
      Checkm6VCounter=-1;  // ������ ������ ������
      break;
/*
    case 6:
      // ���������� ���3:
      CheckOfChannel(Dev3_ai1, LE_U_IPO3, Umin, Umax, FNominal3[1], DangerU_IPO3, P_Protection3, Method, k1);
      break;

    case 7:
      // ���������� ���4:
      CheckOfChannel(Dev4_ai1, LE_U_IPO4, Umin, Umax, FNominal4[1], DangerU_IPO4, P_Protection4, Method, k1);
      break;
*/      
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Checkp6VTimer(TObject *Sender)
{
  Checkp6VCounter++;
  Method = &TMainForm::Powerp6VOff; // ��������� ��������� �� ����� ������ TMainForm ����� ������ Powerp6VOff

  switch(Checkp6VCounter)
  {
    case 0:
      // ��� ���1:
      CheckOfChannel(Dev1_ai2, LE_I_IPP1, Imin, Imax, FNominal1[2], DangerI_IPP1, P_Protection1, Method, k2);
      break;

    case 1:
      // ��� ���2:
      CheckOfChannel(Dev2_ai2, LE_I_IPP2, Imin, Imax, FNominal2[2], DangerI_IPP2, P_Protection2, Method, k2);
      break;
/*
    case 2:
      // ��� ���3:
      CheckOfChannel(Dev3_ai2, LE_I_IPP3, Imin, Imax, FNominal3[2], DangerI_IPP3, P_Protection3, Method, k2);
      break;

    case 3:
      // ��� ���4:
      CheckOfChannel(Dev4_ai2, LE_I_IPP4, Imin, Imax, FNominal4[2], DangerI_IPP4, P_Protection4, Method, k2);
      break;
*/
    case 4:
      // ���������� ���1:
      CheckOfChannel(Dev1_ai3, LE_U_IPP1, Umin, Umax, FNominal1[3], DangerU_IPP1, P_Protection1, Method, k1);
      break;

    case 5:
      // ���������� ���2:
      CheckOfChannel(Dev2_ai3, LE_U_IPP2, Umin, Umax, FNominal2[3], DangerU_IPP2, P_Protection2, Method, k1);
      Checkp6VCounter=-1;  // ������ ������ ������
      break;
/*
    case 6:
      // ���������� ���3:
      CheckOfChannel(Dev3_ai3, LE_U_IPP3, Umin, Umax, FNominal3[3], DangerU_IPP3, P_Protection3, Method, k1);
      break;

    case 7:
      // ���������� ���4:
      CheckOfChannel(Dev4_ai3, LE_U_IPP4, Umin, Umax, FNominal4[3], DangerU_IPP4, P_Protection4, Method, k1);
      break;
*/      
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Checkp20VTimer(TObject *Sender)
{
  Checkp20VCounter++;
  Method = &TMainForm::Powerp20VOff; // ��������� ��������� �� ����� ������ TMainForm ����� ������ Powerp20VOff

  switch(Checkp20VCounter)
  {
    case 0:
      // ��� ���1:
      CheckOfChannel(Dev1_ai4, LE_I_IMP1, Imin, Imax, FNominal1[4], DangerI_IMP1, P_Protection1, Method, k2);
      break;

    case 1:
      // ��� ���2:
      CheckOfChannel(Dev2_ai4, LE_I_IMP2, Imin, Imax, FNominal2[4], DangerI_IMP2, P_Protection2, Method, k2);
      break;
/*
    case 2:
      // ��� ���3:
      CheckOfChannel(Dev3_ai4, LE_I_IMP3, Imin, Imax, FNominal3[4], DangerI_IMP3, P_Protection3, Method, k2);
      break;

    case 3:
      // ��� ���4:
      CheckOfChannel(Dev4_ai4, LE_I_IMP4, Imin, Imax, FNominal4[4], DangerI_IMP4, P_Protection4, Method, k2);
      break;
*/
    case 4:
      // ���������� ���1:
      CheckOfChannel(Dev1_ai5, LE_U_IMP1, Umin, Umax, FNominal1[5], DangerU_IMP1, P_Protection1, Method, k2);
      break;

    case 5:
      // ���������� ���2:
      CheckOfChannel(Dev2_ai5, LE_U_IMP2, Umin, Umax, FNominal2[5], DangerU_IMP2, P_Protection2, Method, k2);
      Checkp20VCounter=-1;  // ������ ������ ������
      break;
/*
    case 6:
      // ���������� ���3:
      CheckOfChannel(Dev3_ai5, LE_U_IMP3, Umin, Umax, FNominal3[5], DangerU_IMP3, P_Protection3, Method, k2);
      break;

    case 7:
      // ���������� ���4:
      CheckOfChannel(Dev4_ai5, LE_U_IMP4, Umin, Umax, FNominal4[5], DangerU_IMP4, P_Protection4, Method, k2);
      break;
*/      
  }
}
//---------------------------------------------------------------------------

