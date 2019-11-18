//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sar2.h"
#include "ControlTesting_Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_Sar2 *F_Sar2;
//---------------------------------------------------------------------------
__fastcall TF_Sar2::TF_Sar2(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TF_Sar2::CB_1Change(TObject *Sender)
{
  UpdateSar2();               // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::CB_2Change(TObject *Sender)
{
  UpdateSar2();               // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::CB_3Change(TObject *Sender)
{
  UpdateSar2();               // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::CB_4Change(TObject *Sender)
{
  UpdateSar2();               // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::CB_5Change(TObject *Sender)
{
  UpdateSar2();               // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::CB_6Change(TObject *Sender)
{
  UpdateSar2();               // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::B_OKClick(TObject *Sender)
{
  cancel = false;
  Close();               // закрыть форму    
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::B_CancelClick(TObject *Sender)
{
  Close();               // закрыть форму
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::FormShow(TObject *Sender)
{
  cancel = true;         // инициализация флага cancel при открытии формы

  if((CB_1->Text!="")&&(CB_2->Text!="")&&(CB_3->Text!="")&&(CB_4->Text!="")&&(CB_5->Text!="")&&(CB_6->Text!=""))  // если все ComboBox'ы не пусты
  {
    InpStr1=CB_1->ItemIndex;  // при открытии формы сделать копию текущего значения
    InpStr2=CB_2->ItemIndex;
    InpStr3=CB_3->ItemIndex;
    InpStr4=CB_4->ItemIndex;
    InpStr5=CB_5->ItemIndex;
    InpStr6=CB_6->ItemIndex;
  }
  else
  {
    InpStr1=0;           // при открытии формы сделать копию текущего значения
    InpStr2=0;
    InpStr3=0;
    InpStr4=0;
    InpStr5=0;
    InpStr6=0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::FormClose(TObject *Sender, TCloseAction &Action)
{
  if(cancel)                  // если была нажата кнопка cancel
  {
    CB_1->ItemIndex=InpStr1;  // восстановить предыдущие значения элементов
    CB_2->ItemIndex=InpStr2;
    CB_3->ItemIndex=InpStr3;
    CB_4->ItemIndex=InpStr4;
    CB_5->ItemIndex=InpStr5;
    CB_6->ItemIndex=InpStr6;
  }
  UpdateSar2();               // обновление значений данных
}
//---------------------------------------------------------------------------
void __fastcall TF_Sar2::UpdateSar2(void)  // обновление значений данных
{
  Main_Form->LV_Sar2->ItemFocused->Caption = CB_1->Text;
  Main_Form->LV_Sar2->Items->Item[Main_Form->LV_Sar2->ItemIndex]->SubItems->Strings[0] = CB_2->Text;
  Main_Form->LV_Sar2->Items->Item[Main_Form->LV_Sar2->ItemIndex]->SubItems->Strings[1] = CB_3->Text;
  Main_Form->LV_Sar2->Items->Item[Main_Form->LV_Sar2->ItemIndex]->SubItems->Strings[2] = CB_4->Text;
  Main_Form->LV_Sar2->Items->Item[Main_Form->LV_Sar2->ItemIndex]->SubItems->Strings[3] = CB_5->Text;
  Main_Form->LV_Sar2->Items->Item[Main_Form->LV_Sar2->ItemIndex]->SubItems->Strings[4] = CB_6->Text;
}
//---------------------------------------------------------------------------
