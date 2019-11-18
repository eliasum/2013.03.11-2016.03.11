// ���� ���������� ����� Main_Form
//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "BlazePoint_main.h"
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
  bool DirectoryExists(AnsiString DirectoryName);
  ������� DirectoryExists ���������� True, ���� ������ DirectoryName ���� ����������.
  ������� ������������� � ������� ��������. False ����� ���� ����������, ���� ������������ ��
  ��������� ������ ����.

  bool CreateDir(AnsiString Dir);
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

  if(OpenDialog->Execute())
/*
virtual __fastcall bool Execute(HWND ParentWnd);
���������� ������ ������ ������.
���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/
  {
    BlpFName = OpenDialog->FileName; // ��� ���������� ����� ����������� � ���������� BlpFName
    LVScan->Items->Clear();          // ������� LVScan
    Update_Dump();                   // �������� ����� BlpFName � LVScan
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
  if (LVScan->Selected != NULL) // ���� ��������� ������ LVScan �� ������
  {
    // ������ �������� ���������� �� Edit'�� � ��������� ������ LVScan
    LVScan->ItemFocused->Caption = E_BT->Text;
    LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[0] = E_X->Text;
    LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[1] = E_Y->Text;
    LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[2] = E_EPR->Text;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Update_Dump() // ������� ���� blp
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

void __fastcall TMain_Form::Save_Dump()  // ��������� ���� blp
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
  
  if (SaveDialog->Execute())
/*
virtual __fastcall bool Execute(HWND ParentWnd);
���������� ������ ������ ������.
���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/  
  {
    BlpFName = SaveDialog->FileName; // ��� ���������� ����� ����������� � ���������� BlpFName
    Save_Dump();                     // ��������� ������ LVScan � ����
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddBTClick(TObject *Sender) // ������� �� ������ "������� ��"
{
  if((E_BT->Text!="")&&(E_X->Text!="")&&(E_Y->Text!="")&&(E_EPR->Text!="")) // ���� ��� Edit'� �� �����
  {
    TListItem * Item = LVScan->Items->Add(); // �������� ����� ������ LVScan
    Item->Caption = E_BT->Text;              // ��������� ������� ���������� �� Edit'��
    Item->SubItems->Add(E_X->Text);
    Item->SubItems->Add(E_Y->Text);
    Item->SubItems->Add(E_EPR->Text);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteBTClick(TObject *Sender) // ������� �� ������ "������� ��"
{
  if (LVScan->Selected != NULL)  // ���� ��������� ������ LVScan �� �����
  {
    LVScan->Selected->Delete();   // ������� ��������� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------


