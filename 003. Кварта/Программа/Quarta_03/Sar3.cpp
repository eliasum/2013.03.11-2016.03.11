//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sar3.h"
#include "Quarta_Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_Sar3 *F_Sar3;
//---------------------------------------------------------------------------
__fastcall TF_Sar3::TF_Sar3(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_1Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_2Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_3Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_4Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_5Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_6Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_7Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_8Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_9Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_10Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_11Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::E_12Change(TObject *Sender)
{
  UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::B_OKClick(TObject *Sender)
{
  cancel = false;
  Close();               // ������� �����    
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::B_CancelClick(TObject *Sender)
{
  Close();               // ������� �����  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::FormShow(TObject *Sender)
{
  cancel = true;         // ������������� ����� cancel ��� �������� �����                      // ���� ��� ComboBox'� �� �����

  if((E_1->Text!="")&&(E_2->Text!="")&&(E_3->Text!="")&&(E_4->Text!="") &&(E_5->Text!="") &&(E_6->Text!="")
   &&(E_7->Text!="")&&(E_8->Text!="")&&(E_9->Text!="")&&(E_10->Text!="")&&(E_11->Text!="")&&(E_12->Text!=""))
  {
    InpStr1=E_1->Text;  // ��� �������� ����� ������� ����� �������� ��������
    InpStr2=E_2->Text;
    InpStr3=E_3->Text;
    InpStr4=E_4->Text;
    InpStr5=E_5->Text;
    InpStr6=E_6->Text;
    InpStr7=E_7->Text;
    InpStr8=E_8->Text;
    InpStr9=E_9->Text;
    InpStr10=E_10->Text;
    InpStr11=E_11->Text;
    InpStr12=E_12->Text;
  }
  else
  {
    InpStr1=IntToHex(0, 2);  // ��� �������� ����� ������� ����� �������� ��������
    InpStr2=IntToHex(0, 2);
    InpStr3=IntToHex(200, 2);
    InpStr4=IntToHex(0, 2);
    InpStr5=IntToHex(201, 2);
    InpStr6=IntToHex(128, 2);
    InpStr7=IntToHex(0, 2);
    InpStr8=IntToHex(8, 2);
    InpStr9=IntToHex(194, 2);
    InpStr10=IntToHex(78, 2);
    InpStr11=IntToHex(0, 2);
    InpStr12=IntToHex(0, 2);
  }  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::FormClose(TObject *Sender, TCloseAction &Action)
{
  if(cancel)             // ���� ���� ������ ������ cancel
  {
    E_1->Text=InpStr1;   // ��� �������� ����� ������� ����� �������� ��������
    E_2->Text=InpStr2;
    E_3->Text=InpStr3;
    E_4->Text=InpStr4;
    E_5->Text=InpStr5;
    E_6->Text=InpStr6;
    E_7->Text=InpStr7;
    E_8->Text=InpStr8;
    E_9->Text=InpStr9;
    E_10->Text=InpStr10;
    E_11->Text=InpStr11;
    E_12->Text=InpStr12;
  }
    UpdateSar3();        // ���������� �������� ������  
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar3::UpdateSar3(void)  // ���������� �������� ������
{
  Main_Form->LV_Sar3->ItemFocused->Caption = E_1->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[0]  = E_2->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[1]  = E_3->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[2]  = E_4->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[3]  = E_5->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[4]  = E_6->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[5]  = E_7->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[6]  = E_8->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[7]  = E_9->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[8]  = E_10->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[9]  = E_11->Text;
  Main_Form->LV_Sar3->Items->Item[Main_Form->LV_Sar3->ItemIndex]->SubItems->Strings[10] = E_12->Text;
}
//---------------------------------------------------------------------------
