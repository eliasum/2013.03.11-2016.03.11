// ���� ���������� ����� Main_Form
//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "BlazePoint_main.h"
#include "BT.h"
#include "Sar1.h"
#include "Sar2.h"
#include "Sar3.h"
#include "Sar4.h"
#include "AboutBox.h"
#include "Error.h"
#include "Help.h"
#include <iostream>
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
#include <string>
/*
string � ������������ ���� � ��������, ��������� � ����������� ��� ����������� ������ �� ��������
� ����� ���������������� C++. �� ������� � ����������� ���������� C++. �������� ���������� �� �����
��������� ���� ������ (����. string). � ����� C++ � ��� ���������������, ����� ���������������� ��,
��� ���������� ��������� ���������� ���� ������, ������ ����� ������������ ������ ��������. string
��������� ��������, ��� � string.h � ��. string ���������� ������������ ������ string ��� �����������
������ �� ��������. ������� ������ ����������� ���������� C++, ��� ������� ����� �������� ������
������������ ������������ ��� � std.
*/

using namespace std;
Boolean c1=true;    // ���� ������� ���������� ����� � LV_Sar1
Boolean c2=true;    // ���� ������� ���������� ����� � LV_Sar2
Boolean c3=true;    // ���� ������� ���������� ����� � LV_Sar3
Boolean c4=true;    // ���� ������� ���������� ����� � LV_Sar4
Boolean fRect=true;

// ������� ��� ���������� ���������� ������ ����
int XString[64];
int YString[64];
int EPRString[64];
int PointColor[64];

#define EPRmin   0
#define EPRmax   0xFFFF
#define EPRmax0  EPRmax/11
#define EPRmax1  2*EPRmax/11
#define EPRmax2  3*EPRmax/11
#define EPRmax3  4*EPRmax/11
#define EPRmax4  5*EPRmax/11
#define EPRmax5  6*EPRmax/11
#define EPRmax6  7*EPRmax/11
#define EPRmax7  8*EPRmax/11
#define EPRmax8  9*EPRmax/11
#define EPRmax9  10*EPRmax/11

#define CMagenta 0xFF00FF  // �������� (����������)
#define CFiolet  0x7F00FF  // ����������
#define CBlue    0xFF0000  // �����
#define CLiBlue  0xFF7F00  // �����
#define CAqua    0xFFFF00  // ���� ������� ����� (���������)
#define CSprGre  0x7FFF00  // �������-�������
#define CLime    0x00FF00  // ���� (�������)
#define CShart   0x00FF7F  // ������ (������-������)
#define CYellow  0x00FFFF  // ������
#define COrange  0x007FFF  // ���������
#define CRed     0x0000FF  // �������

#define PColor   0xFF0000

// ����������
int OldIndex=0;

//  ����������� ����������� ������
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

double tmpX,tmpY;
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* ��������� ���������� ������������������ ������������� ������� �����, �����
��������������� ��������� �������� ������������ �� ������� */
#pragma resource "*.dfm"  // ��� ����� ���� ������������ ���� .dfm � ��� �� ������, ��� � ��� ������� �����
TMain_Form *Main_Form;  // ���������� ��������� �� ������ ����� Main_Form
TIniFile *Ini;
//---------------------------------------------------------------------------
// ����� ������������ ����� Main_Form
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
  : TForm(Owner)
{
  if(!DirectoryExists(My_Patch + "������_��"))
  {
    if(!CreateDir(My_Patch + "������_��"))
      ShowMessage("�� ������� ������� ���������� �������� ������ ��!");
    else
      ShowMessage("������� ���������� ��� �������� ������ ��!");
  }

  if(!DirectoryExists(My_Patch + "������_���_�_������"))
  {
    if(!CreateDir(My_Patch + "������_���_�_������"))
      ShowMessage("�� ������� ������� ���������� �������� ������ ��� � ������!");
    else
      ShowMessage("������� ���������� ��� �������� ������ ��� � ������!");
  }
/*
  Boolean DirectoryExists(AnsiString DirectoryName);
  ������� DirectoryExists ���������� True, ���� ������ DirectoryName ���� ����������.
  ������� ������������� � ������� ��������. False ����� ���� ����������, ���� ������������ ��
  ��������� ������ ����.

  Boolean CreateDir(AnsiString Dir);
  ������� CreateDir ������ ����� � ������� ����������.
  ���� ����� ���� �������, �� ������� ������ True, ���� ���, �� ������ ����� ���� ��������
  � ������� ������� GetLastError.
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LoadBlpClick(TObject *Sender) // ������� �� ������ "������� ���� .blp"
{
  OpenDialog->DefaultExt=".blp";
  OpenDialog->FileName="*.blp";
  OpenDialog->Filter="���� ������ �� (*.blp)|*.blp";
  OpenDialog->Title=" �������� ����� ������ ��";

  String File;

  if(OpenDialog->Execute())
  {
    File=OpenDialog->FileName;
    BlpFName=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("�������� ������","��� ����������", "��������");
*/
       edLCBT->Text=Ini->ReadString("���� ������ ��","���������� ��","1");  // ������� �� ����� � ������

      for(int i=0; i<StrToInt(edLCBT->Text); i++)
      {
        // ���������� X ��
        XString[i]=StrToInt(Ini->ReadString("���� ������ ��","���������� X ��������� ����� (��)"+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
        // ���������� Y ��
        YString[i]=StrToInt(Ini->ReadString("���� ������ ��","���������� Y ��������� ����� (��)"+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
        // ��� ��
        EPRString[i]=StrToInt(Ini->ReadString("���� ������ ��","��� ��������� ����� (��)"+IntToStr(i+1)+"\"","0"));  // ������� �� ����� � ������
		//PointColor[i]=EPRString[i]*PColor/EPRmax;

		Palette(i);                   // �������� ������ ����� �� �� �������� �������
	  }
	  cbLCnBT->Clear();               // �������� ���������� ���������� ��

      for(int i=0;i<StrToInt(edLCBT->Text);i++)
      {
        cbLCnBT->Items->Add(IntToStr(i+1)); // ��������� ���������� �� � ����� "����� ��������� �����"
      }

      cbLCnBT->ItemIndex=OldIndex;    // ����� �� �� ��������� ��� ��������� ����� ��
      edLCx->Text=XString[OldIndex];  // �������� ������� ��������
      edLCy->Text=YString[OldIndex];
	  LE_EPR->Text=EPRString[OldIndex];
	  //PointColor[OldIndex]=EPRString[OldIndex]*PColor/EPRmax;

	  Palette(OldIndex);              // �������� ������ ����� �� �� �������� �������

	  edLCBT->Enabled=false;          // ��������� ���� "���������� ��������� �����"
      edLCx->Enabled=true;            // ��������� ���� "���������� X"
      edLCy->Enabled=true;            // ��������� ���� "���������� Y"
      LE_EPR->Enabled=true;           // ��������� ���� "���"
      B_Sbros->Enabled=true;          // ��������� ������ "�������� ��"
      DrawLC();                       // �������� ������
      edLCBT->Color=clWindow;

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
void __fastcall TMain_Form::SaveBlpClick(TObject *Sender) // ������� �� ������ "��������� ���� .blp"
{
  SaveDialog->InitialDir=My_Patch + "������_��";
  SaveDialog->FileName="*.blp";
  SaveDialog->Title=" ���������� ����� ������ ��";
  SaveDialog->Filter="������ �� (*.blp)|*.blp";

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

  if(SaveDialog->Execute())
  {
    File=SaveDialog->FileName;
	BlpFName=File;
    if(F!=NULL)
	{
	  F=fopen(File.c_str(),"w+"); // ������� ���� � �����������
	  fclose(F);                  // ������� ����
    }
    Ini= new TIniFile(File); // �������� ������ ����� .ini
/*
    Ini->WriteString("�������� ������","��� ����������", "��������");
*/
    Ini->WriteString("���� ������ ��","���������� ��",edLCBT->Text);
    // ���������� X ��
    for(int i=0; i<StrToInt(edLCBT->Text); i++)
    {
      Ini->WriteString("���� ������ ��","���������� X ��������� ����� (��)"+IntToStr(i+1)+"\"",XString[i]);  // ������ �� ������� � ����
    }
    // ���������� Y ��
    for(int i=0; i<StrToInt(edLCBT->Text); i++)
    {
      Ini->WriteString("���� ������ ��","���������� Y ��������� ����� (��)"+IntToStr(i+1)+"\"",YString[i]);  // ������ �� ������� � ����
    }
    // ��� ��
    for(int i=0; i<StrToInt(edLCBT->Text); i++)
    {
      Ini->WriteString("���� ������ ��","��� ��������� ����� (��)"+IntToStr(i+1)+"\"",EPRString[i]);  // ������ �� ������� � ����
    }

    delete Ini;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar1DblClick(TObject *Sender)
{
  if (LV_Sar1->Selected!= NULL) F_Sar1->ShowModal(); // ���� ��������� ������ LV_Sar1 �� �����, ������� �����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar2Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if(c2)                                      // ���� ��� ������� ���������� ����� � LV_Sar2
  {
    TListItem *Item = LV_Sar2->Items->Add();  // �������� ����� ������ LV_Sar2
    // ��������� ������� ���������� �� ���������
    Item->Caption = -16;                      // �� ��������� 1 [��]
    Item->SubItems->Add(0);                   // �� ��������� 2 [��]
    Item->SubItems->Add(3400);                // f ����� ������� 1 [����.]
    Item->SubItems->Add(3400);                // f ����� ������� 2 [����.]
    Item->SubItems->Add(1);                   // W���. ��������
    Item->SubItems->Add(1);                   // W���. �����������
    c2=false;                                 // ��������� ���������� ����� � LV_Sar2
    B_AddSar2->Enabled=false;                 // ��������� ������ "������� ������ Sar2"
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteSar2Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if (LV_Sar2->Selected != NULL)  // ���� ��������� ������ LV_Sar2 �� �����
  {
    LV_Sar2->Selected->Delete();  // ������� ��������� ������
    c2=true;                      // ��������� ���������� ����� � LV_Sar2
    B_AddSar2->Enabled=true;      // �������� ������ "������� ������ Sar2"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar2DblClick(TObject *Sender)
{
  if (LV_Sar2->Selected!= NULL) F_Sar2->ShowModal(); // ���� ��������� ������ LV_Sar2 �� �����, ������� �����
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LoadSarClick(TObject *Sender)
{
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

void __fastcall TMain_Form::SaveSarClick(TObject *Sender)
{
  SaveDialog1->InitialDir=My_Patch + "������_���_�_������";
  SaveDialog1->FileName="*.sar";
  SaveDialog1->Title=" ���������� ����� ������ ��� � ������";
  SaveDialog1->Filter="������ ��� � ������ (*.sar)|*.sar";
  
  if (SaveDialog1->Execute())         // ���� ������ ������ SaveDialog1
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  ���������� ������ ������ ������.
  ���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
  ���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/  
  {
    SarFName = SaveDialog1->FileName; // ��� ���������� ����� ����������� � ���������� SarFName
    Save_Dump_sar();                  // ��������� ������ Sar � ����
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
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Save_Dump_sar()  // ��������� ���� sar
{
/*
  std::ofstream - ����� ��������� ������ ��� ������ � �������.
  std::ofstream SaveFile - �������� �������� ����� (���� ����������� ��� ������ (������)).
  std::ios_base::out - ������ �������� ����� ��� ������ ������.
  ������� std::endl ����� �������� ������, ���������� ����� ������� ������ ������ (������) ������ � ����;
*/
  ofstream SaveFile;
  SaveFile.open(SarFName.c_str(), ios::out);
  
  for (int i=0; i<LV_Sar1->Items->Count; i++) // ������� Items
  {
    SaveFile<<"*"<<endl;                      // �������� ������ � ����, ��������� ������
    SaveFile<<LV_Sar1->Items->Item[i]->Caption.c_str()<<endl; // �������� �������� i-�� Item, ��������� ������
    for (int j=0; j<LV_Sar1->Items->Item[i]->SubItems->Count; j++) // ������� SubItems
    {
      SaveFile<<"**"<<endl;                   // �������� ������ � ����, ��������� ������
      SaveFile<<LV_Sar1->Items->Item[i]->SubItems->Strings[j].c_str()<<endl; // �������� �������� j-�� SubItem, ��������� ������
    }
    SaveFile<<endl;                           // �������� ������ ������ � ����
  }

  for (int i=0; i<LV_Sar2->Items->Count; i++) // ������� Items
  {
    SaveFile<<"***"<<endl;                    // �������� ������ � ����, ��������� ������
    SaveFile<<LV_Sar2->Items->Item[i]->Caption.c_str()<<endl; // �������� �������� i-�� Item, ��������� ������
    for (int j=0; j<LV_Sar2->Items->Item[i]->SubItems->Count; j++) // ������� SubItems
    {
      SaveFile<<"****"<<endl;                 // �������� ������ � ����, ��������� ������
      SaveFile<<LV_Sar2->Items->Item[i]->SubItems->Strings[j].c_str()<<endl; // �������� �������� j-�� SubItem, ��������� ������
    }
    SaveFile<<endl;                           // �������� ������ ������ � ����
  }

  for (int i=0; i<LV_Sar3->Items->Count; i++) // ������� Items
  {
    SaveFile<<"*****"<<endl;                  // �������� ������ � ����, ��������� ������
    SaveFile<<LV_Sar3->Items->Item[i]->Caption.c_str()<<endl; // �������� �������� i-�� Item, ��������� ������
    for (int j=0; j<LV_Sar3->Items->Item[i]->SubItems->Count; j++) // ������� SubItems
    {
      SaveFile<<"******"<<endl;               // �������� ������ � ����, ��������� ������
      SaveFile<<LV_Sar3->Items->Item[i]->SubItems->Strings[j].c_str()<<endl; // �������� �������� j-�� SubItem, ��������� ������
    }
    SaveFile<<endl;                           // �������� ������ ������ � ����
  }

  for (int i=0; i<LV_Sar4->Items->Count; i++) // ������� Items
  {
    SaveFile<<"*******"<<endl;                // �������� ������ � ����, ��������� ������
    SaveFile<<LV_Sar4->Items->Item[i]->Caption.c_str()<<endl; // �������� �������� i-�� Item, ��������� ������
    for (int j=0; j<LV_Sar4->Items->Item[i]->SubItems->Count; j++) // ������� SubItems
    {
      SaveFile<<"********"<<endl;             // �������� ������ � ����, ��������� ������
      SaveFile<<LV_Sar4->Items->Item[i]->SubItems->Strings[j].c_str()<<endl; // �������� �������� j-�� SubItem, ��������� ������
    }
    SaveFile<<endl;                           // �������� ������ ������ � ����
  }
  
  SaveFile.close();                           // ������� ���������� ����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar3Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if(c3)                                      // ���� ��� ������� ���������� ����� � LV_Sar3
  {
    TListItem *Item = LV_Sar3->Items->Add();  // �������� ����� ������ LV_Sar3
    // ��������� ������� ���������� �� ���������
    // Reg[0]=0x00C80000;
    Item->Caption = 0;           // ���� 1  (R0_1)
    Item->SubItems->Add(0);      // ���� 2  (R0_2)
    Item->SubItems->Add(200);    // ���� 3  (R0_3)      IntToHex(200, 2)
    Item->SubItems->Add(0);      // ���� 4  (R0_4)
    // Reg[1]=0x080080C9;
    Item->SubItems->Add(201);    // ���� 5  (R1_1)
    Item->SubItems->Add(128);    // ���� 6  (R1_2)
    Item->SubItems->Add(0);      // ���� 7  (R1_3)
    Item->SubItems->Add(8);      // ���� 8  (R1_4)
    // Reg[2]=0x00004EC2;
    Item->SubItems->Add(194);    // ���� 9  (R2_1)
    Item->SubItems->Add(78);     // ���� 10 (R2_2)
    Item->SubItems->Add(0);      // ���� 11 (R2_3)
    Item->SubItems->Add(0);      // ���� 12 (R2_4)
    c3=false;                    // ������ ���������� ����� � LV_Sar3
    B_AddSar3->Enabled=false;    // ���������� ������ "������� ������ Sar3"
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
    Item->Caption = 179;         // ���� 13 (R3_1)
    Item->SubItems->Add(4);      // ���� 14 (R3_2)
    Item->SubItems->Add(0);      // ���� 15 (R3_3)
    Item->SubItems->Add(0);      // ���� 16 (R3_4)
    // Reg[4]=0x00A5003C;
    Item->SubItems->Add(36);     // ���� 17 (R4_1)
    Item->SubItems->Add(1);      // ���� 18 (R4_2)
    Item->SubItems->Add(165);    // ���� 19 (R4_3)
    Item->SubItems->Add(0);      // ���� 20 (R4_4)
    // Reg[5]=0x00580005;
    Item->SubItems->Add(5);      // ���� 21 (R5_1)
    Item->SubItems->Add(0);      // ���� 22 (R5_2)
    Item->SubItems->Add(88);     // ���� 23 (R5_3)
    Item->SubItems->Add(0);      // ���� 24 (R5_4)
    c4=false;                    // ������ ���������� ����� � LV_Sar4
    B_AddSar4->Enabled=false;    // ���������� ������ "������� ������ Sar4"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DeleteSar3Click(TObject *Sender) // ������� �� ������ "������� ������ Sar3"
{
  if (LV_Sar3->Selected != NULL)  // ���� ��������� ������ LV_Sar3 �� �����
  {
    LV_Sar3->Selected->Delete();  // ������� ��������� ������
    c3=true;                      // ��������� ���������� ����� � LV_Sar3
    B_AddSar3->Enabled=true;      // �������� ������ "������� ������ Sar3"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DeleteSar4Click(TObject *Sender)
{
  if (LV_Sar4->Selected != NULL)  // ���� ��������� ������ LV_Sar4 �� �����
  {
    LV_Sar4->Selected->Delete();  // ������� ��������� ������
    c4=true;                      // ��������� ���������� ����� � LV_Sar4
    B_AddSar4->Enabled=true;      // �������� ������ "������� ������ Sar4"
  }
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
void __fastcall TMain_Form::edLCBTExit(TObject *Sender)
// ����� ���� "���������� ��������� �����" ���������
{
  bool b;
  int min=1;                                   // ����������� ��������
  int max=64;                                  // ������������ ��������
  int delta=1;
  String EdIzm="";                             // ������� ���������
  float fvalue;                                // ������ ��������

  fvalue=StrToFloat(edLCBT->Text);             // ��������

  b=IsValidInt(min,max,fvalue,EdIzm);          // �������� ������������ ��������� ��������
  if(b)                                        // ���� ���������
  {
	edLCBT->Text=RoundValue(delta,fvalue);
    cbLCnBT->Clear();                          // �������� ���������� ���������� ��

	for(int i=0;i<StrToInt(edLCBT->Text);i++)
    {
      cbLCnBT->Items->Add(IntToStr(i+1));      // ��������� ���������� �� � ����� "����� ��������� �����"

      XString[i]=StrToInt(edLCx->Text);        // ���������� ������� ������!!!
      YString[i]=StrToInt(edLCy->Text);
	  EPRString[i]=EPRmax;                     // StrToInt(LE_EPR->Text)
	  PointColor[i]=CRed;                      // PColor
    }
    cbLCnBT->ItemIndex=0;                      // ����� �� �� ��������� ��� ��������� ����� ��

    edLCBT->Enabled=false;                     // ��������� ���� "���������� ��������� �����"
    edLCx->Enabled=true;                       // ��������� ���� "���������� X"
    edLCy->Enabled=true;                       // ��������� ���� "���������� Y"
    LE_EPR->Enabled=true;                      // ��������� ���� "���"
    B_Sbros->Enabled=true;                     // ��������� ������ "�������� ��"
  }
  else                                         // ���� �� ���������
  {
    edLCBT->SetFocus();                        // ����� �� ���� "���������� ��������� �����"
    ErrorForm->SetFocus();                     // ����� ��������� �� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::PIntKeyPress(TObject *Sender, char &Key)
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
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<8<<'-';
	if(!Dig.Contains(Key))
	{
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::cbLCnBTChange(TObject *Sender)
// �� ��������� ������ ��
{
  int i;
  i=cbLCnBT->ItemIndex;                       // �������� ����� ���������� ����� ��

  XString[OldIndex]=StrToInt(edLCx->Text);    // �������� �������� � �������
  YString[OldIndex]=StrToInt(edLCy->Text);
  EPRString[OldIndex]=StrToInt(LE_EPR->Text);
  //PointColor[OldIndex]=EPRString[OldIndex]*PColor/EPRmax;

  Palette(OldIndex);                          // �������� ������ ����� �� �� �������� �������

  DrawLC();                                   // �������� ������

  OldIndex=i;                                 // ��������� ������� ���������� �����

  edLCx->Text=XString[i];                     // �������� ������� ��������
  edLCy->Text=YString[i];
  LE_EPR->Text=EPRString[i];
  //PointColor[i]=EPRString[i]*PColor/EPRmax;

  Palette(i);                                 // �������� ������ ����� �� �� �������� �������

  DrawLC();                                   // �������� ������

  DrawHighlight();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCxChange(TObject *Sender)
{
  int Comm;
  if(edLCx->Text=="") edLCx->Text=0;
  Comm=StrToInt(edLCx->Text);
  XString[OldIndex]=Comm;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCxExit(TObject *Sender)
{
  bool b;
  int min=-425;                                 // ����������� ��������
  int max=425;                                  // ������������ ��������
  int delta=1;
  String EdIzm="�";                             // ������� ���������
  int ivalue;                                   // ������ ��������

  ivalue=StrToInt(edLCx->Text);                 // ��������

  b=IsValidInt(min,max,ivalue,EdIzm);           // �������� ������������ ��������� ��������
  if(b)                                         // ���� ���������
  {
	edLCx->Text=RoundValue(delta,ivalue);
    XString[OldIndex]=StrToInt(edLCx->Text);    // �������� �������� � ������
    DrawLC();                                   // �������� ������
  }
  else
  {
    edLCx->SetFocus();                          // ����� �� ���� "���������� ��������� �����"
    ErrorForm->SetFocus();                      // ����� ��������� �� ������
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::edLCyChange(TObject *Sender)
{
  int Comm;
  if(edLCy->Text=="") edLCy->Text=0;
  Comm=StrToInt(edLCy->Text);
  YString[OldIndex]=Comm;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCyExit(TObject *Sender)
{
  bool b;
  int min=151;                                // ����������� ��������
  int max=850;                                // ������������ ��������
  int delta=1;
  String EdIzm="�";                           // ������� ���������
  int ivalue;                                 // ������ ��������

  ivalue=StrToFloat(edLCy->Text);             // ��������

  b=IsValidInt(min,max,ivalue,EdIzm);         // �������� ������������ ��������� ��������
  if(b)                                       // ���� ���������
  {
    if(StrToInt(edLCy->Text)>150)               // ���� ��� ����������� ����
    {
	  edLCy->Text=RoundValue(delta,ivalue);
      YString[OldIndex]=StrToInt(edLCy->Text);  // �������� �������� � ������
      DrawLC();                                 // �������� ������
    }
  }
  else
  {
    edLCy->SetFocus();                        // ����� �� ���� "���������� ��������� �����"
    ErrorForm->SetFocus();                    // ����� ��������� �� ������
  }  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::btnReDrawLCClick(TObject *Sender)
{
  if(StrToInt(edLCx->Text)>150)
  {
    DrawLC();                               // �������� ������
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
String TMain_Form::RoundValue(float delta, float fvalue)
{
  float temp;
  float temp1;

  temp=fvalue;
  temp1=Log10(delta);
  fvalue=RoundTo(temp,temp1);  // � BCB6 ���� String (�������������� ����� ���������)

  return fvalue;
}
//---------------------------------------------------------------------------
void TMain_Form::DrawLC(void)
// �������� ������
{
  int I,X,Y,xmax,xmin,ymax,ymin;

  Series1->Clear();

  if(edLCBT->Text=="") return;

  I=StrToInt(edLCBT->Text);

  xmax=0;
  xmin=0;
  ymax=0;
  ymin=0;

  for(int i=0;i<I;i++)
  {
    X=XString[i];
    Y=YString[i];

	//Series1->AddXY(X,Y);
	Series1->AddXY(X,Y,"",PointColor[i]);

	if(X>xmax) xmax=X;
    if(Y>ymax) ymax=Y;
    if(X<xmin) xmin=X;
    if(Y<ymin) ymin=Y;         
  }
}
//---------------------------------------------------------------------------
void TMain_Form::ShowError(int ErrorNum, float Par1, float Par2, String Par3)
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
void __fastcall TMain_Form::B_SbrosClick(TObject *Sender)
{
  ResetBP();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormCreate(TObject *Sender)
{
  ResetBP();

  // �������� �������� ������� �����������
  Series1->FillSampleValues(30);  // <-- some random values
  OldX = -1;                      // initialize variables
  CrossHairColor = clRed;
  CrossHairStyle = psSolid;
  ChartLC->Cursor = crCross;

  Series1->Clear();               // �������� ������
}
//---------------------------------------------------------------------------
// This procedure draws the crosshair lines }
void TMain_Form::DrawCross(int ax, int ay)
{
  TColor tmp;
  tmp = ChartLC->BackColor;
  if (tmp == clTeeColor)
    tmp = clBtnFace;
  ChartLC->Canvas->Pen->Color = (TColor)(CrossHairColor ^ ColorToRGB(tmp));

  ChartLC->Canvas->Pen->Style = CrossHairStyle;
  ChartLC->Canvas->Pen->Mode = pmXor;
  ChartLC->Canvas->Pen->Width = 1;
  ChartLC->Canvas->MoveTo(ax,ChartLC->ChartRect.Top-ChartLC->Height3D);
  ChartLC->Canvas->LineTo(ax,ChartLC->ChartRect.Bottom-ChartLC->Height3D);
  ChartLC->Canvas->MoveTo(ChartLC->ChartRect.Left+ChartLC->Width3D,ay);
  ChartLC->Canvas->LineTo(ChartLC->ChartRect.Right+ChartLC->Width3D,ay);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  if (OldX != 1) {
    DrawCross(OldX,OldY);  // draw old crosshair
    OldX = -1;
  }

  // check if (mouse is inside Chart rectangle
  if (PtInRect((RECT*)&ChartLC->ChartRect, Point(X-ChartLC->Width3D,Y+ChartLC->Height3D))) {
    DrawCross(X,Y);  // draw crosshair at current position
    // store old position
    OldX = X;
    OldY = Y;
    // set label text
    Series1->GetCursorValues(tmpX,tmpY);  // <-- get values under mouse cursor
    Label1->Caption = Series1->GetHorizAxis->LabelValue((int)tmpX)
      + " " + Series1->GetVertAxis->LabelValue((int)tmpY);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LineSeries1AfterDrawValues(TObject *Sender)
{
  OldX = -1;  // Reset old mouse position
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
    c1=false;                                 // ��������� ���������� ����� � LV_Sar1
    B_AddSar1->Enabled=false;                 // ��������� ������ "������� ������ Sar1"
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
void __fastcall TMain_Form::ChartLCDblClick(TObject *Sender)
// ������� ������ �� ������� ���������� Chart
{
  int VertAxis;
  VertAxis=StrToInt(Series1->GetVertAxis->LabelValue((int)tmpY));
  
  if((edLCBT->Text!="")&&(cbLCnBT->Text!="")&&(VertAxis>150))
  {
    int Commx, Commy;

    edLCx->Text=Series1->GetHorizAxis->LabelValue((int)tmpX);
    Commx=StrToInt(edLCx->Text);
    XString[OldIndex]=Commx;

    edLCy->Text=Series1->GetVertAxis->LabelValue((int)tmpY);
    Commy=StrToInt(edLCy->Text);
	YString[OldIndex]=Commy;

    //Series1->Transparency=0;             // ������� �� 100%

    DrawLC();                              // �������� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCBTChange(TObject *Sender)
{
  cbLCnBT->Enabled=true;                   // ��������� ���� "����� ��"
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCBTClick(TObject *Sender)
{
  edLCBT->Color=clWindow;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::BitBtn1Click(TObject *Sender) // ������� �����
{
  if (OpenDialog2->Execute())
  {
    ChartLC->BackImage->LoadFromFile(OpenDialog2->FileName);
    ChartLC->BackImageMode = TTeeBackImageMode(0);  // 0 - Stretch (���������)
    ChartLC->BackImageInside = true;                // ������ ���� X � Y
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Button1Click(TObject *Sender)
{
  ChartLC->BackImage = 0; // �������� �����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCAfterDraw(TObject *Sender)
{
  // ��������� ����������� ���� 150�
  if(fRect)
  {
    ChartLC->Canvas->Pen->Style = psClear;
    ChartLC->Canvas->Brush->Color=clWhite;
    ChartLC->Canvas->Brush->Style=bsDiagCross;
    ChartLC->Canvas->Rectangle(40,360,465,435);         
  }                
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LE_EPRChange(TObject *Sender)
{
  int Comm;
  if(LE_EPR->Text=="") LE_EPR->Text=0;
  Comm=StrToInt(LE_EPR->Text);
  EPRString[OldIndex]=Comm;
  //PointColor[OldIndex]=EPRString[OldIndex]*PColor/EPRmax;

  Palette(OldIndex);                             // �������� ������ ����� �� �� �������� �������

  DrawLC();                                      // �������� ������

  //Series1->Transparency=100-EPRString[OldIndex]*100/EPRmax; // ������� �� x%
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LE_EPRExit(TObject *Sender)
{
  bool b;
  int min=0;                                     // ����������� ��������
  int max=EPRmax;                                // ������������ ��������
  int delta=1;
  String EdIzm="�^2";                            // ������� ���������
  int ivalue;                                    // ������ ��������

  ivalue=StrToInt(LE_EPR->Text);                 // ��������

  b=IsValidInt(min,max,ivalue,EdIzm);            // �������� ������������ ��������� ��������
  if(b)                                          // ���� ���������
  {
    LE_EPR->Text=RoundValue(delta,ivalue);
	EPRString[OldIndex]=StrToInt(LE_EPR->Text);  // �������� �������� � ������
	//PointColor[OldIndex]=EPRString[OldIndex]*PColor/EPRmax;

	Palette(OldIndex);                           // �������� ������ ����� �� �� �������� �������

	DrawLC();                                    // �������� ������

	//Series1->Transparency=100-EPRString[OldIndex]*100/EPRmax; // ������� �� x%
  }
  else
  {
    LE_EPR->SetFocus();                          // ����� �� ����
    ErrorForm->SetFocus();                       // ����� ��������� �� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::HelpAboutProgClick(TObject *Sender)
{
  F_Help->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::ChartLCZoom(TObject *Sender)
{
  fRect=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCUndoZoom(TObject *Sender)
{
  fRect=true;  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ResetBP(void)
{
  edLCBT->Text="";
  cbLCnBT->Clear();
  edLCx->Text="0";
  edLCy->Text="0";
  LE_EPR->Text="65535";            // EPRmax

  for(int i=0;i<64;i++)
  {
    XString[i]=0;                  // ���������� ������� ������!!!
    YString[i]=0;
	EPRString[i]=EPRmax;
    PointColor[i]=CRed;
  }

  edLCBT->Enabled=true;            // ��������� ���� "���������� ��������� �����"
  edLCBT->Color=clYellow;
  cbLCnBT->Enabled=false;          // ��������� ���� "����� ��"
  edLCx->Enabled=false;            // ��������� ���� "���������� X"
  edLCy->Enabled=false;            // ��������� ���� "���������� Y"
  LE_EPR->Enabled=false;           // ��������� ���� "���"
  Series1->Clear();                // �������� ������
  B_Sbros->Enabled=false;          // ��������� ������ "�������� ��"
}
//---------------------------------------------------------------------------
void TMain_Form::DrawHighlight(void)
// �������� ������� ����� �� �������
{
  int X,Y;

  Series2->Clear();

  if(edLCBT->Text=="") return;

  X=XString[OldIndex];
  Y=YString[OldIndex];

  Series2->AddXY(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::BitBtn2Click(TObject *Sender)
{
  SaveDialog2->FileName="*.WMF";
  SaveDialog2->Title=" ��������� ���";
  SaveDialog2->Filter="Metafile Format (*.WMF)|*.WMF";
  
  if (SaveDialog2->Execute()) {  // <-- ask for a filename first
    // SAVE IT !!

    // CLIPPING WORKS FINE BUT DO NOT ALLOW MOVEABLE OR RESIZEABLE METAFILES
    // TO FORCE CLIPPING WITH METAFILES UNCOMMENT THIS LINE:
    // TeeClipWhenMetafiling = true;

    ChartLC->SaveToMetafile(SaveDialog2->FileName);

    // THIS METHOD CAN BE USED TOO:
    /*
      Chart1->SaveToMetafileRect( SaveDialog1->FileName,
      Rect( 0,0, round(21//cm*37->8), round(10//cm*37->8)));
    */
    //   ( this equals to 96 * 21 / 2->54 , 96 * 10 /2->54 )
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Palette(int index)
{
  // �������� ������ ����� �� �� �������� �������:
  if((EPRString[index]>=EPRmin) &&(EPRString[index]<EPRmax0)) PointColor[index]=CMagenta;
  else
  if((EPRString[index]>=EPRmax0)&&(EPRString[index]<EPRmax1)) PointColor[index]=CFiolet;
  else
  if((EPRString[index]>=EPRmax1)&&(EPRString[index]<EPRmax2)) PointColor[index]=CBlue;
  else
  if((EPRString[index]>=EPRmax2)&&(EPRString[index]<EPRmax3)) PointColor[index]=CLiBlue;
  else
  if((EPRString[index]>=EPRmax3)&&(EPRString[index]<EPRmax4)) PointColor[index]=CAqua;
  else
  if((EPRString[index]>=EPRmax4)&&(EPRString[index]<EPRmax5)) PointColor[index]=CSprGre;
  else
  if((EPRString[index]>=EPRmax5)&&(EPRString[index]<EPRmax6)) PointColor[index]=CLime;
  else
  if((EPRString[index]>=EPRmax6)&&(EPRString[index]<EPRmax7)) PointColor[index]=CShart;
  else
  if((EPRString[index]>=EPRmax7)&&(EPRString[index]<EPRmax8)) PointColor[index]=CYellow;
  else
  if((EPRString[index]>=EPRmax8)&&(EPRString[index]<EPRmax9)) PointColor[index]=COrange;
  else
  if((EPRString[index]>=EPRmax9)&&(EPRString[index]<=EPRmax)) PointColor[index]=CRed;
}
//---------------------------------------------------------------------------





