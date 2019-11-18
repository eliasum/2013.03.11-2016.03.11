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
    InpStr1=179;  // при открытии формы сделать копию текущего значения
    InpStr2=4;
    InpStr3=0;
    InpStr4=0;
    InpStr5=36;
    InpStr6=1;
    InpStr7=165;
    InpStr8=0;
    InpStr9=5;
    InpStr10=0;
    InpStr11=88;
    InpStr12=0;
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

