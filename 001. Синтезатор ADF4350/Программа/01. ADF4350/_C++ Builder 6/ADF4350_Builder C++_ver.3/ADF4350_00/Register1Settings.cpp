//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Register1Settings.h"
#include "Unit1.h"
extern double MOD, Phase; // Modulus, Phase
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender) // нажатие на Button1 OK
{
  cancel = false;
  Close();            // закрыть Form4
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender) // нажатие на Button2 Cancel
{
  Close();            // закрыть Form4
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender) // открытие Form4
{
  cancel = true;             // инициализация флага cancel при открытии Form4
  InpStr=Form4->Edit1->Text; // при открытии Form4 сделать копию текущего значения в Edit1 и Phase
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action) // закрытие Form4
{
  if(cancel)  // если была нажата кнопка cancel
  {
    Form4->Edit1->Text=InpStr; // тогда восстановить предыдущее значение Edit1 и Phase
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit1Change(TObject *Sender)
{
  Phase=StrToFloat(Form4->Edit1->Text);

  if(Phase>MOD)
  {
    Phase=MOD;
    ShowMessage("Phase value must be less than modulus");
  }
  
  Form1->Label12->Caption="Phase = "+FloatToStr(Phase);
  Edit1->Text=FloatToStr(Phase);

  Form1->UpdateRegister1();  // обновление значения Register 1
}
//---------------------------------------------------------------------------

