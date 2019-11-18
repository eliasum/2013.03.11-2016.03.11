//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Register5Settings.h"
#include "Unit1.h"

extern int LD_Pin_Mode;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)// нажатие на Button1 OK
{
  cancel = false;
  Close();            // закрыть Form8
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)// нажатие на Button2 Cancel
{
  Close();            // закрыть Form8
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormShow(TObject *Sender)// открытие Form8
{
  cancel = true; // инициализация флага cancel при открытии Form8
  InpStr=Form8->ComboBox1->Text; // при открытии Form8 сделать копию текущего значения элемента
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormClose(TObject *Sender, TCloseAction &Action) //закрытие Form8
{
  if(cancel) // если была нажата кнопка cancel, тогда восстановить предыдущее значение элемента
  {
    Form8->ComboBox1->Text=InpStr;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ComboBox1Change(TObject *Sender)
{
  if(ComboBox1->ItemIndex==0) LD_Pin_Mode=1;
  else
  if(ComboBox1->ItemIndex==1) LD_Pin_Mode=0;
  else
  if(ComboBox1->ItemIndex==2) LD_Pin_Mode=3;

  Form1->UpdateRegister5();  // обновление значения Register 5
}
//---------------------------------------------------------------------------

