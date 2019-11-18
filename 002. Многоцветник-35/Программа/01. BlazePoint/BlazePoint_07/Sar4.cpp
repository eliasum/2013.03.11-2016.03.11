//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sar4.h"
#include "BlazePoint_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_Sar4 *F_Sar4;
//---------------------------------------------------------------------------
__fastcall TF_Sar4::TF_Sar4(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar4::B_OKClick(TObject *Sender)
{
  cancel = false;
  Close();               // закрыть форму   
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar4::B_CancelClick(TObject *Sender)
{
  Close();               // закрыть форму   
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar4::FormShow(TObject *Sender)
{
  cancel = true;         // инициализация флага cancel при открытии формы                      // если все ComboBox'ы не пусты

  if((E_1->Text!="")&&(E_2->Text!="")&&(E_3->Text!="")&&(E_4->Text!="") &&(E_5->Text!="") &&(E_6->Text!="")
   &&(E_7->Text!="")&&(E_8->Text!="")&&(E_9->Text!="")&&(E_10->Text!="")&&(E_11->Text!="")&&(E_12->Text!=""))
  {
    InpStr1=E_1->Text;  // при открытии формы сделать копию текущего значения
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
    InpStr1=IntToHex(179, 2);  // при открытии формы сделать копию текущего значения
    InpStr2=IntToHex(4, 2);
    InpStr3=IntToHex(0, 2);
    InpStr4=IntToHex(0, 2);
    InpStr5=IntToHex(60, 2);
    InpStr6=IntToHex(0, 2);
    InpStr7=IntToHex(165, 2);
    InpStr8=IntToHex(0, 2);
    InpStr9=IntToHex(5, 2);
    InpStr10=IntToHex(0, 2);
    InpStr11=IntToHex(88, 2);
    InpStr12=IntToHex(0, 2);
  }
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar4::FormClose(TObject *Sender, TCloseAction &Action)
{
  if(cancel)             // если была нажата кнопка cancel
  {
    E_1->Text=InpStr1;   // при открытии формы сделать копию текущего значения
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
  UpdateSar4();          // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar4::UpdateSar4(void)  // обновление значений данных
{
  Main_Form->LV_Sar4->ItemFocused->Caption = E_1->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[0]  = E_2->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[1]  = E_3->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[2]  = E_4->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[3]  = E_5->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[4]  = E_6->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[5]  = E_7->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[6]  = E_8->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[7]  = E_9->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[8]  = E_10->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[9]  = E_11->Text;
  Main_Form->LV_Sar4->Items->Item[Main_Form->LV_Sar4->ItemIndex]->SubItems->Strings[10] = E_12->Text;
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_1Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_2Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_3Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_4Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_5Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_6Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_7Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_8Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_9Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_10Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_11Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar4::E_12Change(TObject *Sender)
{
  UpdateSar4();          // обновление значений данных  
}
//---------------------------------------------------------------------------

