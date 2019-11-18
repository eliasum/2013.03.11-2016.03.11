//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sar1.h"
#include "BlazePoint_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_Sar1 *F_Sar1;
//---------------------------------------------------------------------------
__fastcall TF_Sar1::TF_Sar1(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar1::E_1Change(TObject *Sender)
{
  Main_Form->LV_Sar1->ItemFocused->Caption = E_1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar1::E_2Change(TObject *Sender)
{
  Main_Form->LV_Sar1->Items->Item[Main_Form->LV_Sar1->ItemIndex]->SubItems->Strings[0] = E_2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar1::E_3Change(TObject *Sender)
{
  Main_Form->LV_Sar1->Items->Item[Main_Form->LV_Sar1->ItemIndex]->SubItems->Strings[1] = E_3->Text;
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar1::E_4Change(TObject *Sender)
{
  Main_Form->LV_Sar1->Items->Item[Main_Form->LV_Sar1->ItemIndex]->SubItems->Strings[2] = E_4->Text;
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar1::FormShow(TObject *Sender)
{
  cancel = true;        // инициализация флага cancel при открытии формы

  if((E_1->Text!="")&&(E_2->Text!="")&&(E_3->Text!="")&&(E_4->Text!=""))  // если все Edit'ы не пусты
  {
    InpStr1=E_1->Text;  // при открытии формы сделать копию текущего значения
    InpStr2=E_2->Text;
    InpStr3=E_3->Text;
    InpStr4=E_4->Text;
  }
  else
  {
    InpStr1=0;          // при открытии формы сделать копию текущего значения
    InpStr2=0;
    InpStr3=0;
    InpStr4=0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar1::B_OKClick(TObject *Sender)
{
  cancel = false;
  Close();              // закрыть форму  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar1::B_CancelClick(TObject *Sender)
{
  Close();              // закрыть форму  
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar1::FormClose(TObject *Sender, TCloseAction &Action)
{
  if(cancel)            // если была нажата кнопка cancel
  {
    E_1->Text=InpStr1;  // тогда восстановить предыдущее значение элементов
    E_2->Text=InpStr2;
    E_3->Text=InpStr3;
    E_4->Text=InpStr4;
  }  
}
//---------------------------------------------------------------------------

