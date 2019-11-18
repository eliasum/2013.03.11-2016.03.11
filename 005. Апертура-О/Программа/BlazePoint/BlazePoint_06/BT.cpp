//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BT.h"
#include "BlazePoint_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_BT *F_BT;
//---------------------------------------------------------------------------
__fastcall TF_BT::TF_BT(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::E_1Change(TObject *Sender)
{
  UpdateBT();           // ���������� �������� ������
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::E_2Change(TObject *Sender)
{
  UpdateBT();           // ���������� �������� ������
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::E_3Change(TObject *Sender)
{
  UpdateBT();           // ���������� �������� ������
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::E_4Change(TObject *Sender)
{
  UpdateBT();           // ���������� �������� ������
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::B_OKClick(TObject *Sender)
{
  cancel = false;
  Close();              // ������� �����
}
//---------------------------------------------------------------------------

void __fastcall TF_BT::B_CancelClick(TObject *Sender)
{
  Close();              // ������� �����
}
//---------------------------------------------------------------------------

void __fastcall TF_BT::FormShow(TObject *Sender)
{
  cancel = true;        // ������������� ����� cancel ��� �������� �����

  if((E_1->Text!="")&&(E_2->Text!="")&&(E_3->Text!="")&&(E_4->Text!=""))  // ���� ��� Edit'� �� �����
  {
    InpStr1=E_1->Text;  // ��� �������� ����� ������� ����� �������� �������� E_1
    InpStr2=E_2->Text;  // ��� �������� ����� ������� ����� �������� �������� E_2
    InpStr3=E_3->Text;  // ��� �������� ����� ������� ����� �������� �������� E_3
    InpStr4=E_4->Text;  // ��� �������� ����� ������� ����� �������� �������� E_4
  }
  else
  {
    InpStr1=0;          // ��� �������� ����� ������� ����� �������� �������� E_1
    InpStr2=0;          // ��� �������� ����� ������� ����� �������� �������� E_2
    InpStr3=0;          // ��� �������� ����� ������� ����� �������� �������� E_3
    InpStr4=0;          // ��� �������� ����� ������� ����� �������� �������� E_4
  }
}
//---------------------------------------------------------------------------

void __fastcall TF_BT::FormClose(TObject *Sender, TCloseAction &Action)
{
  if(cancel)            // ���� ���� ������ ������ cancel
  {
    E_1->Text=InpStr1;  // ����� ������������ ���������� �������� E_1
    E_2->Text=InpStr2;  // ����� ������������ ���������� �������� E_2
    E_3->Text=InpStr3;  // ����� ������������ ���������� �������� E_3
    E_4->Text=InpStr4;  // ����� ������������ ���������� �������� E_4
  }
  UpdateBT();           // ���������� �������� ������
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::UpdateBT(void)  // ���������� �������� ������
{
  Main_Form->LVScan->ItemFocused->Caption = E_1->Text;
  Main_Form->LVScan->Items->Item[Main_Form->LVScan->ItemIndex]->SubItems->Strings[0] = E_2->Text;
  Main_Form->LVScan->Items->Item[Main_Form->LVScan->ItemIndex]->SubItems->Strings[1] = E_3->Text;
  Main_Form->LVScan->Items->Item[Main_Form->LVScan->ItemIndex]->SubItems->Strings[2] = E_4->Text;
}
//---------------------------------------------------------------------------

