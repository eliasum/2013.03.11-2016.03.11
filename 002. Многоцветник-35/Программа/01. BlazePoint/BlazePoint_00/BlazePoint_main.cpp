// ���� ���������� ����� Main_Form
//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "BlazePoint_main.h"
#include <iostream>
#include <fstream>
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
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::SaveBlpClick(TObject *Sender)
{
  std::ofstream out("scan.txt",std::ios_base::out|std::ios_base::trunc);
  for(size_t i=0;i<(size_t)LVScan->Items->Count;++i){
    if(i) out<<std::endl;
    out<<"\""<<LVScan->Items->Item[i]->Caption.c_str()<<"\""<<std::endl;
    for(size_t j=0;j<(size_t)LVScan->Items->Item[i]->SubItems->Count;++j)
      out<<"\""<<LVScan->Items->Item[i]->SubItems->Strings[j].c_str()<<"\""<<std::endl;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LoadBlpClick(TObject *Sender)
{
  LVScan->Items->Clear();
  std::ifstream in("scan.txt");
  std::string x;
  TListItem * item=0;
  bool flag=false;
  while(!std::getline(in,x).fail()){
    if(!x.size()) {item=0;flag=false;continue;}
    if(x.size()&&'"'==x[x.size()-1]) x.resize(x.size()-1);
    if(x.size()&&'"'==x[0]) x.erase(0,1);
    if(!item) item=LVScan->Items->Add();
    if(!flag){ item->Caption=x.c_str(); flag=true; }
    else item->SubItems->Add(x.c_str());
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LVScanDblClick(TObject *Sender)
{   /*
  Edit1->Visible=true;
  Edit1->Enabled=true;
  Edit1->Text="";              */
/*
  if (LVScan->Selected != NULL)
  ShowMessage(LVScan->Selected->Caption) ;     */


  //LVScan->Selected->EditCaption();

LVScan->ItemFocused->Caption = Edit1->Text;
LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[0] = Edit2->Text;
LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[1] = Edit3->Text;
LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[2] = Edit4->Text;
}
//---------------------------------------------------------------------------


void __fastcall TMain_Form::Button1Click(TObject *Sender)
{                                 /*
  nomer=Edit1->Text;
  Edit1->Visible=false;
  LVScan->ItemFocused->SubItems->Add(nomer);            */

  //LVScan->Items->Add();
//TListItem * Item = LVScan->Items->Item[LVScan->Items->Count-1];
TListItem * Item = LVScan->Items->Add();
Item->Caption = Edit1->Text;
Item->SubItems->Add(Edit2->Text);
Item->SubItems->Add(Edit3->Text);
Item->SubItems->Add(Edit4->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Button5Click(TObject *Sender)
{
  LVScan->Selected->Delete();
}
//---------------------------------------------------------------------------

