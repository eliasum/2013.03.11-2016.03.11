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
  P0.0, P0.1, P0.2 = 1 - ������� ���, = 0 - ����.;
  P0.3, P0.4, P0.5 = 1 - �������� ������� ����� ��� ���, = 0 - ����.;
  P0.6 = 1 - ���, = 0 - ����.;
  P0.0 - ������ �������� -6�;
  P0.1 - ������ �������� +6�;
  P0.2 - ������ �������� +20�;
  P0.3 - ������ ��������� ������� ����� ��� -6�;
  P0.4 - ������ ��������� ������� ����� ��� +6�;
  P0.5 - ������ ��������� ������� ����� ��� +20�;
  P0.6 - ������ ������� ��������� ����������� �������� ��������;
  P1.0 - ������ ������� � ��������� ���������� 1, = 0 - ��������;

  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �1
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �1
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �1
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �1
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �1
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �1

  ���������� 2:
  P1.0 - ������ ������� � ��������� ���������� 2, = 0 - ��������;

  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �2
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �2
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �2
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �2
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �2
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �2

  ���������� 3:
  P1.0 - ������ ������� � ��������� ���������� 3, = 0 - ��������;

  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �3
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �3
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �3
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �3
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �3
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �3

  ���������� 4:
  P1.0 - ������ ������� � ��������� ���������� 4, = 0 - ��������;

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

const char *Dev1_port0_line0_2 = "Dev1/port0/line0:2";
const char *Dev1_port0_line3_5 = "Dev1/port0/line3:5";
const char *Dev1_port0_line3 = "Dev1/port0/line3";
const char *Dev1_port0_line4 = "Dev1/port0/line4";
const char *Dev1_port0_line5 = "Dev1/port0/line5";
const char *Dev1_port0_line6 = "Dev1/port0/line6";

const char *Dev1_port1_line0_3 = "Dev1/port1/line0:3";

const char *Dev1_ai0= "Dev1/ai0";
const char *Dev1_ai1= "Dev1/ai1";
const char *Dev1_ai2= "Dev1/ai2";
const char *Dev1_ai3= "Dev1/ai3";
const char *Dev1_ai4= "Dev1/ai4";
const char *Dev1_ai5= "Dev1/ai5";

const char *Dev2_port1_line0 = "Dev2/port1/line0";

const char *Dev2_ai0= "Dev2/ai0";
const char *Dev2_ai1= "Dev2/ai1";
const char *Dev2_ai2= "Dev2/ai2";
const char *Dev2_ai3= "Dev2/ai3";
const char *Dev2_ai4= "Dev2/ai4";
const char *Dev2_ai5= "Dev2/ai5";

const char *Dev3_port1_line0 = "Dev3/port1/line0";

const char *Dev3_ai0= "Dev3/ai0";
const char *Dev3_ai1= "Dev3/ai1";
const char *Dev3_ai2= "Dev3/ai2";
const char *Dev3_ai3= "Dev3/ai3";
const char *Dev3_ai4= "Dev3/ai4";
const char *Dev3_ai5= "Dev3/ai5";

const char *Dev4_port1_line0 = "Dev4/port1/line0";

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

const char *OverheatMessage = "�������� ����������! ������������� ���������!";

const char *UnloadedChannel1 = "���� ��������� ������ ������������� � ����� 1 �� ��������!";
const char *UnloadedChannel2 = "���� ��������� ������ ������������� � ����� 2 �� ��������!";
const char *UnloadedChannel3 = "���� ��������� ������ ������������� � ����� 3 �� ��������!";
const char *UnloadedChannel4 = "���� ��������� ������ ������������� � ����� 4 �� ��������!";

const char *LoadedChannel1 = "���� ��������� ������ ������������� � ����� 1 ��������!";
const char *LoadedChannel2 = "���� ��������� ������ ������������� � ����� 2 ��������!";
const char *LoadedChannel3 = "���� ��������� ������ ������������� � ����� 3 ��������!";
const char *LoadedChannel4 = "���� ��������� ������ ������������� � ����� 4 ��������!";

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

float value;
int k1=1, k2=2;         // ������������, ����������� �������� �� 2

// ���������� ���������� ��������� 
int Checkm6VCounter=-1;
int Checkp6VCounter=-1;
int Checkp20VCounter=-1;

long int Tpause=0, Twork=0;
int ::count=0;
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

  L_Danger->Caption="";
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
    Application->MessageBox("�������� -6�, +6�, +20� � ��������� ����. ��������� �������� � ��������� ���.","��������",MB_ICONWARNING);
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
  T_Work->Enabled=true;
  T_Pause->Enabled=true;
  Starting();
  Work();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_StopClick(TObject *Sender)
{
  PowerOffWithDelay(); // ��������� ��� ��������� ������� ������ ��� � ����������
  T_Work->Enabled=false;
  T_Pause->Enabled=false;
  B_Go->Enabled=true;
  B_Stop->Enabled=false;
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
        LoadChannel(Nominal1, greenflag1, P_Selected1, UnloadedChannel1, FNominal1, LoadedChannel1);

        Tpause = (long int)FNominal1[6]*1000; // [�]
        Twork = (long int)FNominal1[7]*1000;  // [�]
/*
        Memo1->Lines->Add(Tpause);
        Memo1->Lines->Add(Twork);

        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(FNominal1[i]);
        }
*/
      }
      if(RB_Selected2->Checked==true)
      {
        LoadChannel(Nominal2, greenflag2, P_Selected2, UnloadedChannel2, FNominal2, LoadedChannel2);
/*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(FNominal2[i]);
        }
*/
      }
      if(RB_Selected3->Checked==true)
      {
        LoadChannel(Nominal3, greenflag3, P_Selected3, UnloadedChannel3, FNominal3, LoadedChannel3);
/*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(FNominal3[i]);
        }
*/
      }
      if(RB_Selected4->Checked==true)
      {
        LoadChannel(Nominal4, greenflag4, P_Selected4, UnloadedChannel4, FNominal4, LoadedChannel4);
/*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(FNominal4[i]);
        }
*/
      }
      
      B_Go->Enabled=true;
      //if(greenflag1&greenflag2) B_Go->Enabled=true;  // greenflag1&greenflag2&greenflag3&greenflag4

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
  P_Mode1->Color=clBtnFace;
  P_Mode2->Color=clBtnFace;
  //P_Mode3->Color=clBtnFace;
  //P_Mode3->Color=clBtnFace;

  // ��������� ��������� ������� +20� ������ ���
  T_Checkp20V->Enabled=false;
  Powerp20VOff(); // ��������� ��������� ������� +20� ������ ���

  LE_I_IMP1->Text="0";
  LE_I_IMP2->Text="0";
  LE_I_IMP3->Text="0";
  LE_I_IMP4->Text="0";

  LE_U_IMP1->Text="0";
  LE_U_IMP2->Text="0";
  LE_U_IMP3->Text="0";
  LE_U_IMP4->Text="0";

  Delay();        // �������� 1 ���

  // ��������� ��������� ������� +6� ������ ���
  T_Checkp6V->Enabled=false;
  Powerp6VOff();  // ��������� ��������� ������� +6� ������ ���

  LE_I_IPP1->Text="0";
  LE_I_IPP2->Text="0";
  LE_I_IPP3->Text="0";
  LE_I_IPP4->Text="0";

  LE_U_IPP1->Text="0";
  LE_U_IPP2->Text="0";
  LE_U_IPP3->Text="0";
  LE_U_IPP4->Text="0";

  Delay();        // �������� 1 ���

  // ��������� ��������� ������� -6� ������ ���
  T_Checkm6V->Enabled=false;
  Powerm6VOff();  // ��������� ��������� ������� -6� ������ ���

  LE_I_IPO1->Text="0";
  LE_I_IPO2->Text="0";
  LE_I_IPO3->Text="0";
  LE_I_IPO4->Text="0";

  LE_U_IPO1->Text="0";
  LE_U_IPO2->Text="0";
  LE_U_IPO3->Text="0";
  LE_U_IPO4->Text="0";
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
    L_Danger->Caption=Message;
    // ��������� ��������� �������:
    (MainForm->*pm)();   // ����� � ������� ��������� �� ������������ ������, � ������ � ��������� �� ����� ����� �������
    PowerOffWithDelay(); // ��������� ��� ��������� ������� ������ ��� � ����������
    Protection->Color=clRed;
    B_Go->Enabled=true;
    B_Stop->Enabled=false;    
  }
  else
  {
    L_Danger->Caption="";
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
void __fastcall TMainForm::Work(void)
// ���� ������
{
  Verification();          // �������� ����������� �������� ���������� ���������� ������� ������ ���

  T_Work->Interval=Twork;  // ������ ����� ������ �� ����� Twork [c]
  T_Log->Enabled=true;     // ������ ������ � log ���� ������ 10 ���

  // ������ ���������� ����������� �������� ��������
  P0[6]=0;
  WriteDigChan(Dev1_port0_line6, P0); // ������ � �������� ���� P0 ���������� 1

  P_Mode1->Color=clGreen;
  P_Mode2->Color=clGreen;
  //P_Mode3->Color=clGreen;
  //P_Mode3->Color=clGreen;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_WorkTimer(TObject *Sender)
// �� ��������� ������� Twork [c]
{
  T_Work->Interval=0;    // ���������� ���� ������
  T_Log->Enabled=false;  // ���������� ����� � log ���� ������ 10 ���
  PowerOffWithDelay();   // ��������� ��� ��������� ������� ������ ��� � ����������

  Pause();               // ���� �����
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_LogTimer(TObject *Sender)
// ����� � log ���� ������ 10 ���
{
  T_Log->Enabled=true;

  AddSaveLog("�������� ���� ���1 ��������� "+LE_I_IPO1->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���� ���1 ��������� "+LE_I_IPP1->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���� ���1 ��������� "+LE_I_IMP1->Text+" �");  // �������� ����������� � ��������� ���

  AddSaveLog("�������� ���������� ���1 ��������� "+LE_U_IPO1->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���������� ���1 ��������� "+LE_U_IPP1->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���������� ���1 ��������� "+LE_U_IMP1->Text+" �");  // �������� ����������� � ��������� ���

  AddSaveLog("�������� ���� ���2 ��������� "+LE_I_IPO2->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���� ���2 ��������� "+LE_I_IPP2->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���� ���2 ��������� "+LE_I_IMP2->Text+" �");  // �������� ����������� � ��������� ���

  AddSaveLog("�������� ���������� ���2 ��������� "+LE_U_IPO2->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���������� ���2 ��������� "+LE_U_IPP2->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���������� ���2 ��������� "+LE_U_IMP2->Text+" �");  // �������� ����������� � ��������� ���
/*
  AddSaveLog("�������� ���� ���3 ��������� "+LE_I_IPO3->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���� ���3 ��������� "+LE_I_IPP3->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���� ���3 ��������� "+LE_I_IMP3->Text+" �");  // �������� ����������� � ��������� ���

  AddSaveLog("�������� ���������� ���3 ��������� "+LE_U_IPO3->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���������� ���3 ��������� "+LE_U_IPP3->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���������� ���3 ��������� "+LE_U_IMP3->Text+" �");  // �������� ����������� � ��������� ���

  AddSaveLog("�������� ���� ���4 ��������� "+LE_I_IPO4->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���� ���4 ��������� "+LE_I_IPP4->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���� ���4 ��������� "+LE_I_IMP4->Text+" �");  // �������� ����������� � ��������� ���

  AddSaveLog("�������� ���������� ���4 ��������� "+LE_U_IPO4->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���������� ���4 ��������� "+LE_U_IPP4->Text+" �");  // �������� ����������� � ��������� ���
  AddSaveLog("�������� ���������� ���4 ��������� "+LE_U_IMP4->Text+" �");  // �������� ����������� � ��������� ���
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_OverheatTimer(TObject *Sender)
{
  T_Overheat->Enabled=true;

  ReadDigChan(Dev1_port1_line0_3, P1);  // ������ � ����� ������ ��������� ����� P1 ���������� 1

  Overheat(P1[0], P_Overheat1);  // �������� ��������� ���������� 1
  Overheat(P1[1], P_Overheat2);  // �������� ��������� ���������� 2
  Overheat(P1[2], P_Overheat3);  // �������� ��������� ���������� 3
  Overheat(P1[3], P_Overheat4);  // �������� ��������� ���������� 4      
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Overheat(unsigned char line, TPanel *P_Overheat)
// �������� ��������� ����������
{
  if(!line)
  {
    T_Overheat->Enabled=false;
    T_Danger->Enabled=true;
    L_Danger->Caption=OverheatMessage;
    P_Overheat->Color=clRed;
    PowerOffWithDelay();         // ��������� ��� ��������� ������� ������ ��� � ����������
    B_Go->Enabled=false;
    B_Stop->Enabled=false;
    GB_Channel1->Enabled=false;
    GB_Channel2->Enabled=false;
    GB_Channel3->Enabled=false;
    GB_Channel4->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Delay(void)
// ������� ��������
{
  Sleep(1000);                           // 1000 ��
/*
  ������:
  int time=GetTickCount();          // ����� �� �� ������� ��������� ����������
  while((GetTickCount()-time)<1000) // 1000 - ����� ���������� ��������
  { }

  ���������� �������� ��� ��������:
  for(DWORD tt=GetTickCount();GetTickCount()-tt<1000;Sleep(10)) Application->ProcessMessages();
  ���
  int time=GetTickCount();
  do{Application->ProcessMessages();} while((GetTickCount()-time)<1000);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Pause(void)
// ���� �����
{
  T_Pause->Interval=Tpause;           // ������ ����� ����� �� ����� Tpause [c]

  // ������ ��������� ����������� �������� ��������
  P0[6]=1;
  WriteDigChan(Dev1_port0_line6, P0); // ������ � �������� ���� P0 ���������� 1
/*
  Memo1->Lines->Add(P0[6]);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_PauseTimer(TObject *Sender)
// �� ��������� ������� Tpause [c]
{
  T_Pause->Interval=0;      // ���������� ���� �����

  ::count++;
  LE_Cycles->Text=::count;

  if(::count<5000)
  {
    T_Work->Interval=Twork; // ������ ����� ������ �� ����� Twork [c] (������������)
    Verification();         // �������� ����������� �������� ���������� ���������� ������� ������ ���
  }
  else
  {
    PowerOffWithDelay();    // ��������� ��� ��������� ������� ������ ��� � ����������
    B_Go->Enabled=false;
    B_Stop->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LoadChannel(AnsiString *Nominal, bool &greenflag, TPanel *Selected,
                const char *NoMessage, double *FNominal, const char *YesMessage)
{
  NominalNumber(Nominal); // ����� ������, ��� �������� ����������� ����������� ��������

  // �������� �������� ����� ��������� ������ ������������� � �����
  for(int i=0; i<8; i++)
  {
    if(Nominal[i].IsEmpty()) // ���� ������ ������
    {
      greenflag=false;
      B_Go->Enabled=false;
      B_Stop->Enabled=false;
      Selected->Color=clRed;
      Application->MessageBox(NoMessage,"��������",MB_ICONWARNING);
      break;
    }
    else
    {
      greenflag=true;
      Selected->Color=clGreen;
      FNominal[i]=Nominal[i].ToDouble(); // FNominal[i]=StrToFloat(Nominal[i]);
    }
  }
  if(greenflag) Application->MessageBox(YesMessage,"��������",MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_DangerTimer(TObject *Sender)
{
  T_Danger->Enabled=true;
  MessageBeep(MB_ICONHAND);
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

