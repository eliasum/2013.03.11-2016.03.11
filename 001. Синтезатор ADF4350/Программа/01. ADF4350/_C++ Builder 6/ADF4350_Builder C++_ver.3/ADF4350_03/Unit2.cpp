//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"

extern int CLK_DIV;
extern double Fpfd;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
  : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender) // нажатие на Button1 OK
{
  cancel = false;
  Close();            // закрыть Form2
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender) // нажатие на Button2 Cancel
{
  Close();            // закрыть Form2
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1Change(TObject *Sender)  // редактирование Edit1 Clk Div Value
{
  if(Form2->Edit1->Text<=0) Form2->Edit1->Text=0;     // число не может быть меньше нуля

  CLK_DIV = StrToInt(Form2->Edit1->Text); // преобразовать текст из Edit1 в CLK DIV VALUE
  double E2 = CLK_DIV/Fpfd;
  Form2->Edit2->Text=FloatToStr(E2);      // преобразовать вещественное в текст Edit2 BW Time Interval [us]

  Form1->UpdateRegister3();               // обновление значения Register 3
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action) // закрытие Form2
{
  if(cancel)
  {
     Form2->Edit1->Text=InpStr; // если была нажата кнопка cancel, тогда восстановить
                                // предыдущее значение Edit1
     Form1->CheckBox6->Checked=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender) // открытие Form2
{
  cancel = true;             // инициализация флага cancel при открытии Form2
  InpStr=Form2->Edit1->Text; // при открытии Form2 сделать копию текущего значения в Edit1 
}
//---------------------------------------------------------------------------




