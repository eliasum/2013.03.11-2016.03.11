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

using namespace std;
Boolean c1=true;    // ���� ������� ���������� ����� � LV_Sar1
Boolean c2=true;    // ���� ������� ���������� ����� � LV_Sar2
Boolean c3=true;    // ���� ������� ���������� ����� � LV_Sar3
Boolean c4=true;    // ���� ������� ���������� ����� � LV_Sar4
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* ��������� ���������� ������������������ ������������� ������� �����, �����
��������������� ��������� �������� ������������ �� ������� */
#pragma resource "*.dfm"  // ��� ����� ���� ������������ ���� .dfm � ��� �� ������, ��� � ��� ������� �����
TMain_Form *Main_Form;  // ���������� ��������� �� ������ ����� Main_Form
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
  ���� ����� ���� �������, �� ������� ����� True, ���� ���, �� ������ ����� ���� ��������
  � ������� ������� GetLastError.
*/
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LoadBlpClick(TObject *Sender) // ������� �� ������ "������� ���� .blp"
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

void __fastcall TMain_Form::LVScanDblClick(TObject *Sender)  // ������� ������ �� LVScan
{
  if (LVScan->Selected!= NULL) F_BT->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Update_Dump_blp() // ������� ���� blp
{
  std::ifstream infile(BlpFName.c_str());
  std::string x;
  TListItem * item=0;
  bool flag=false;
  while(!std::getline(infile,x).fail())
  {
    if(!x.size()) {item=0;flag=false;continue;}
    if(x.size()&&'"'==x[x.size()-1]) x.resize(x.size()-1);
    if(x.size()&&'"'==x[0]) x.erase(0,1);
    if(!item) item=LVScan->Items->Add();
    if(!flag){ item->Caption=x.c_str(); flag=true; }
    else item->SubItems->Add(x.c_str());
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Save_Dump_blp()  // ��������� ���� blp
{
  std::ofstream out(BlpFName.c_str(),std::ios_base::out|std::ios_base::trunc);
  for(size_t i=0;i<(size_t)LVScan->Items->Count;++i)
  {
    if(i) out<<std::endl;
    out<<"\""<<LVScan->Items->Item[i]->Caption.c_str()<<"\""<<std::endl;
    for(size_t j=0;j<(size_t)LVScan->Items->Item[i]->SubItems->Count;++j)
    out<<"\""<<LVScan->Items->Item[i]->SubItems->Strings[j].c_str()<<"\""<<std::endl;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SaveBlpClick(TObject *Sender) // ������� �� ������ "��������� ���� .blp"
{
  SaveDialog->InitialDir=My_Patch + "������_��";
  SaveDialog->FileName="*.blp";
  SaveDialog->Title=" ���������� ����� ������ ��";
  SaveDialog->Filter="������ �� (*.blp)|*.blp";
  
  if (SaveDialog->Execute())         // ���� ������ ������ SaveDialog
/*
virtual __fastcall bool Execute(HWND ParentWnd);
���������� ������ ������ ������.
���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/  
  {
    BlpFName = SaveDialog->FileName; // ��� ���������� ����� ����������� � ���������� BlpFName
    Save_Dump_blp();                 // ��������� ������ LVScan � ����
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
  if (LV_Sar1->Selected!= NULL) F_Sar1->ShowModal();
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
    c1=true;                      // ���������� ���������� ����� � LV_Sar1
    B_AddSar1->Enabled=true;      // ��������� ������ "������� ������ Sar1"
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

void __fastcall TMain_Form::LV_Sar2DblClick(TObject *Sender)
{
  if (LV_Sar2->Selected!= NULL) F_Sar2->ShowModal();
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
    Save_Dump_sar();                  // ��������� ������ LV_Sar1 � LV_Sar2 � ����
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Update_Dump_sar() // ������� ���� sar
{
  TListItem *pItem;
  std::ifstream ifile(SarFName.c_str());
  std::string line;
  while(std::getline(ifile,line))
  {
    if(line == "*")
      if(std::getline(ifile,line))
      {
        pItem = LV_Sar1->Items->Add();
        pItem->Caption =AnsiString(line.c_str());
      }
    if(line == "**")
      if(std::getline(ifile,line))
        pItem->SubItems->Add(line.c_str());

    if(line == "***")
      if(std::getline(ifile,line))
      {
        pItem = LV_Sar2->Items->Add();
        pItem->Caption =AnsiString(line.c_str());
      }
    if(line == "****")
      if (std::getline(ifile,line))
        pItem->SubItems->Add(line.c_str());

    if(line == "*****")
      if(std::getline(ifile,line))
      {
        pItem = LV_Sar3->Items->Add();
        pItem->Caption =AnsiString(line.c_str());
      }
    if(line == "******")
      if (std::getline(ifile,line))
        pItem->SubItems->Add(line.c_str());

    if(line == "*******")
      if(std::getline(ifile,line))
      {
        pItem = LV_Sar4->Items->Add();
        pItem->Caption =AnsiString(line.c_str());
      }
    if(line == "********")
      if (std::getline(ifile,line))
        pItem->SubItems->Add(line.c_str());
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Save_Dump_sar()  // ��������� ���� sar
{
  ofstream SaveFile;
  SaveFile.open(SarFName.c_str(), ios::out);
  
  for (int i=0; i<LV_Sar1->Items->Count; i++)
  {
    SaveFile<<"*"<<endl;
    SaveFile<<LV_Sar1->Items->Item[i]->Caption.c_str()<<endl;
    for (int j=0; j<LV_Sar1->Items->Item[i]->SubItems->Count; j++)
    {
      SaveFile<<"**"<<endl;
      SaveFile<<LV_Sar1->Items->Item[i]->SubItems->Strings[j].c_str()<<endl;
    }
    SaveFile<<endl;
  }

  for (int i=0; i<LV_Sar2->Items->Count; i++)
  {
    SaveFile<<"***"<<endl;
    SaveFile<<LV_Sar2->Items->Item[i]->Caption.c_str()<<endl;
    for (int j=0; j<LV_Sar2->Items->Item[i]->SubItems->Count; j++)
    {
      SaveFile<<"****"<<endl;
      SaveFile<<LV_Sar2->Items->Item[i]->SubItems->Strings[j].c_str()<<endl;
    }
    SaveFile<<endl;
  }

  for (int i=0; i<LV_Sar3->Items->Count; i++)
  {
    SaveFile<<"*****"<<endl;
    SaveFile<<LV_Sar3->Items->Item[i]->Caption.c_str()<<endl;
    for (int j=0; j<LV_Sar3->Items->Item[i]->SubItems->Count; j++)
    {
      SaveFile<<"******"<<endl;
      SaveFile<<LV_Sar3->Items->Item[i]->SubItems->Strings[j].c_str()<<endl;
    }
    SaveFile<<endl;
  }

  for (int i=0; i<LV_Sar4->Items->Count; i++)
  {
    SaveFile<<"*******"<<endl;
    SaveFile<<LV_Sar4->Items->Item[i]->Caption.c_str()<<endl;
    for (int j=0; j<LV_Sar4->Items->Item[i]->SubItems->Count; j++)
    {
      SaveFile<<"********"<<endl;
      SaveFile<<LV_Sar4->Items->Item[i]->SubItems->Strings[j].c_str()<<endl;
    }
    SaveFile<<endl;
  }
  
  SaveFile.close();
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

void __fastcall TMain_Form::LV_Sar3DblClick(TObject *Sender)
{
  if (LV_Sar3->Selected!= NULL) F_Sar3->ShowModal();  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar4DblClick(TObject *Sender)
{
  if (LV_Sar4->Selected!= NULL) F_Sar4->ShowModal();   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();  
}
//---------------------------------------------------------------------------


