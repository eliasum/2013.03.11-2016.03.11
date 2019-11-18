//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "TestOdnocvetnik_main.h"
#include "AboutBox.h"
#include <fstream>    // �������� �������� �����-������
using namespace std;

String FileStend="";
TLabeledEdit *Parameter;
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* ��������� ���������� ������������������ ������������� ������� �����, �����
��������������� ��������� �������� ������������ �� ������� */
#pragma resource "*.dfm"  // ��� ����� ���� ������������ ���� .dfm � ��� �� ������, ��� � ��� ������� �����
TMainForm *MainForm;      // ���������� ��������� �� ������ ����� Main_Form
TIniFile *Ini;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
  : TForm(Owner)
{
  if(!DirectoryExists(My_Patch + "����� ���������"))
  {
    if(!CreateDir(My_Patch + "����� ���������"))
      ShowMessage("�� ������� ������� ���������� �������� ������ ���������!");
    else
      ShowMessage("������� ���������� ��� �������� ������ ���������!");
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
void __fastcall TMainForm::ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TB_HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_SaveStendClick(TObject *Sender)
{
  SaveDialog1->DefaultExt=".stend";
  SaveDialog1->FileName="*.stend";
  SaveDialog1->Filter="���� ��������� (*.stend)|*.stend";
  SaveDialog1->Title=" ���������� ����� ���������";

  String File;
  FILE *F;

  if(SaveDialog1->Execute())
  {
    File=SaveDialog1->FileName;
    FileStend=File;
    if(F!=NULL)
    {
      F=fopen(File.c_str(),"w+"); // ������� ���� � �����������
      fclose(F);                  // ������� ����
    }
    Ini= new TIniFile(File); // �������� ������ ����� .ini
/*
    Ini->WriteString("�������� ������","��� ����������", "��������");
*/
    Ini->WriteString("�����","I���-6�",LE_Inomm6V->Text);
    Ini->WriteString("�����","U���-6�",LE_Unomm6V->Text);
    Ini->WriteString("�����","I���+6�",LE_Inomp6V->Text);
    Ini->WriteString("�����","U���+6�",LE_Unomp6V->Text);
    Ini->WriteString("�����","I���+20�",LE_Inomp20V->Text);
    Ini->WriteString("�����","U���+20�",LE_Unomp20V->Text);
    Ini->WriteString("�����","T�����",LE_Tpause->Text);
    Ini->WriteString("�����","T������",LE_Twork->Text);

    delete Ini;
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
      LE_Inomm6V->Text=Ini->ReadString("�����","I���-6�","1");
      LE_Unomm6V->Text=Ini->ReadString("�����","U���-6�","1");
      LE_Inomp6V->Text=Ini->ReadString("�����","I���+6�","1");
      LE_Unomp6V->Text=Ini->ReadString("�����","U���+6�","1");
      LE_Inomp20V->Text=Ini->ReadString("�����","I���+20�","1");
      LE_Unomp20V->Text=Ini->ReadString("�����","U���+20�","1");
      LE_Tpause->Text=Ini->ReadString("�����","T�����","1");
      LE_Twork->Text=Ini->ReadString("�����","T������","1");

      delete Ini;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LE_Inomm6VKeyPress(TObject *Sender, char &Key)
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
void __fastcall TMainForm::LE_TpauseKeyPress(TObject *Sender, char &Key)
// ������ �������� ����� ��������, ����� ����� 0...9
{
  Set<char,0,255>Dig;
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<8;
	if(!Dig.Contains(Key))
	{
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LE_Inomm6VChange(TObject *Sender)
{
  DefaultValue(LE_Inomm6V);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DefaultValue(TLabeledEdit *Parameter)
{
  if(Parameter->Text=="") Parameter->Text=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LE_Unomm6VChange(TObject *Sender)
{
  DefaultValue(LE_Unomm6V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_Inomp6VChange(TObject *Sender)
{
  DefaultValue(LE_Inomp6V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_Unomp6VChange(TObject *Sender)
{
  DefaultValue(LE_Unomp6V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_Inomp20VChange(TObject *Sender)
{
  DefaultValue(LE_Inomp20V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_Unomp20VChange(TObject *Sender)
{
  DefaultValue(LE_Unomp20V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_TpauseChange(TObject *Sender)
{
  DefaultValue(LE_Tpause);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_TworkChange(TObject *Sender)
{
  DefaultValue(LE_Twork);
}
//---------------------------------------------------------------------------

