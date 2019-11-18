//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Register3Settings.h"
#include "Unit1.h"

extern int CLK_DIV;
extern int CLK_DIV_MODE;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormShow(TObject *Sender) // открытие Form6
{
  cancel = true; // инициализация флага cancel при открытии Form6
  // при открытии Form6 сделать копии текущих значений элементов
  InpStr1=Form6->CheckBox1->Checked;
  InpStr2=Form6->Edit1->Text;
  InpStr3=Form6->Edit2->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormClose(TObject *Sender, TCloseAction &Action) // закрытие Form6
{
  if(cancel) // если была нажата кнопка cancel, тогда восстановить предыдущие значения элементов
  {
    Form6->CheckBox1->Checked=InpStr1;
    Form6->Edit1->Text=InpStr2;
    Form6->Edit2->Text=InpStr3;
    CLK_DIV = StrToInt(InpStr2); // преобразовать текст из Edit1 в CLK DIV VALUE
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender) // нажатие на Button1 OK
{
  cancel = false;
  Close();            // закрыть Form6
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender) // нажатие на Button2 Cancel
{
  Close();            // закрыть Form6
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit1Change(TObject *Sender) // редактирование CLK DIV VALUE
{
  double tsync;

  CLK_DIV = StrToInt(Form6->Edit1->Text); // преобразовать текст из Edit1 в CLK DIV VALUE
  tsync = CLK_DIV*2.5;
  Form6->Edit2->Text=FloatToStr(tsync);   // преобразовать tsync [us] в текст Edit2

  Form1->UpdateRegister3();               // обновление значения Register 2
}
//---------------------------------------------------------------------------
void __fastcall TForm6::CheckBox1Click(TObject *Sender)
{
  if(CheckBox1->Checked==true)
  {
    Form1->CheckBox6->Checked=false;      // отключить режим Fast Lock enable
    Form1->CheckBox6->Enabled=false;      // запретить режим Fast Lock enable

    CLK_DIV_MODE=2;                       // режим Resync enable
    Form1->UpdateRegister3();             // обновление значения Register 3
  }
  else
  {
    Form1->CheckBox6->Enabled=true;       // разрешить режим Fast Lock enable

    CLK_DIV_MODE=0;                       // режим Clock Divider off
    Form1->UpdateRegister3();             // обновление значения Register 3
  }
}
//---------------------------------------------------------------------------

