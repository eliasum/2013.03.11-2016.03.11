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
  UpdateBT();           // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::E_2Change(TObject *Sender)
{
  UpdateBT();           // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::E_3Change(TObject *Sender)
{
  UpdateBT();           // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::E_4Change(TObject *Sender)
{
  UpdateBT();           // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::B_OKClick(TObject *Sender)
{
  cancel = false;
  Close();              // закрыть форму
}
//---------------------------------------------------------------------------

void __fastcall TF_BT::B_CancelClick(TObject *Sender)
{
  Close();              // закрыть форму
}
//---------------------------------------------------------------------------

void __fastcall TF_BT::FormShow(TObject *Sender)
{
  cancel = true;        // инициализация флага cancel при открытии формы

  if((E_1->Text!="")&&(E_2->Text!="")&&(E_3->Text!="")&&(E_4->Text!=""))  // если все Edit'ы не пусты
  {
    InpStr1=E_1->Text;  // при открытии формы сделать копию текущего значения E_1
    InpStr2=E_2->Text;  // при открытии формы сделать копию текущего значения E_2
    InpStr3=E_3->Text;  // при открытии формы сделать копию текущего значения E_3
    InpStr4=E_4->Text;  // при открытии формы сделать копию текущего значения E_4
  }
  else
  {
    InpStr1=0;          // при открытии формы сделать копию текущего значения E_1
    InpStr2=0;          // при открытии формы сделать копию текущего значения E_2
    InpStr3=0;          // при открытии формы сделать копию текущего значения E_3
    InpStr4=0;          // при открытии формы сделать копию текущего значения E_4
  }
}
//---------------------------------------------------------------------------

void __fastcall TF_BT::FormClose(TObject *Sender, TCloseAction &Action)
{
  if(cancel)            // если была нажата кнопка cancel
  {
    E_1->Text=InpStr1;  // тогда восстановить предыдущее значение E_1
    E_2->Text=InpStr2;  // тогда восстановить предыдущее значение E_2
    E_3->Text=InpStr3;  // тогда восстановить предыдущее значение E_3
    E_4->Text=InpStr4;  // тогда восстановить предыдущее значение E_4
  }
  UpdateBT();           // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_BT::UpdateBT(void)  // обновление значений данных
{
  Main_Form->LVScan->ItemFocused->Caption = E_1->Text;
  Main_Form->LVScan->Items->Item[Main_Form->LVScan->ItemIndex]->SubItems->Strings[0] = E_2->Text;
  Main_Form->LVScan->Items->Item[Main_Form->LVScan->ItemIndex]->SubItems->Strings[1] = E_3->Text;
  Main_Form->LVScan->Items->Item[Main_Form->LVScan->ItemIndex]->SubItems->Strings[2] = E_4->Text;
}
//---------------------------------------------------------------------------

