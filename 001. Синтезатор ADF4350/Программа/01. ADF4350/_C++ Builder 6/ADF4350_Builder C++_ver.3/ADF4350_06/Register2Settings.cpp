//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Register2Settings.h"
#include "Unit1.h"

extern int Counter_Reset;
extern int Three_State;
extern int Power_Down;
extern int Polarity;
extern int Double_Buff;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormShow(TObject *Sender) // открытие Form5
{
  cancel = true; // инициализация флага cancel при открытии Form5
  // при открытии Form5 сделать копии текущих значений элементов
  InpStr1=Form5->ComboBox1->ItemIndex;
  InpStr2=Form5->ComboBox2->ItemIndex;
  InpStr3=Form5->ComboBox3->ItemIndex;
  InpStr4=Form5->ComboBox4->ItemIndex;
  InpStr5=Form5->CheckBox1->Checked;
  InpStr6=Form5->CheckBox2->Checked;
  InpStr7=Form5->CheckBox3->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action) // закрытие Form5
{
  if(cancel) // если была нажата кнопка cancel, тогда восстановить предыдущие значения элементов
  {
    Form5->ComboBox1->ItemIndex=InpStr1;
    Form5->ComboBox2->ItemIndex=InpStr2;
    Form5->ComboBox3->ItemIndex=InpStr3;
    Form5->ComboBox4->ItemIndex=InpStr4;
    Form5->CheckBox1->Checked=InpStr5;
    Form5->CheckBox2->Checked=InpStr6;
    Form5->CheckBox3->Checked=InpStr7;

    Form1->UpdateRegister2();  // обновление значения Register 2
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender) // нажатие на Button1 OK
{
  cancel = false;
  Close();            // закрыть Form5
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button2Click(TObject *Sender) // нажатие на Button2 Cancel
{
  Close();            // закрыть Form5
}
//---------------------------------------------------------------------------

void __fastcall TForm5::CheckBox3Click(TObject *Sender)
{
  // задание Counter Reset:
  if(Form5->CheckBox3->Checked) Counter_Reset=1;
  else                          Counter_Reset=0;

  Form1->UpdateRegister2();  // обновление значения Register 2
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ComboBox4Change(TObject *Sender) // CP Three-State
{
  Form1->UpdateRegister2();  // обновление значения Register 2
}
//---------------------------------------------------------------------------

void __fastcall TForm5::CheckBox1Click(TObject *Sender)
{
  // задание Power Down:
  if(Form5->CheckBox1->Checked) Power_Down=1;
  else                          Power_Down=0;

  Form1->UpdateRegister2();  // обновление значения Register 2
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ComboBox3Change(TObject *Sender) // CP Polarity
{
  Form1->UpdateRegister2();  // обновление значения Register 2
}
//---------------------------------------------------------------------------
void __fastcall TForm5::ComboBox2Change(TObject *Sender) // LDP
{
  Form1->UpdateRegister2();  // обновление значения Register 2
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ComboBox1Change(TObject *Sender) // LDF
{
  Form1->UpdateRegister2();  // обновление значения Register 2
}
//---------------------------------------------------------------------------

void __fastcall TForm5::CheckBox2Click(TObject *Sender)
{
  // задание Double Buff:
  if(Form5->CheckBox2->Checked) Double_Buff=1;
  else                          Double_Buff=0;

  Form1->UpdateRegister2();  // обновление значения Register 2
}
//---------------------------------------------------------------------------

