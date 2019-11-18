//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Register4Settings.h"
#include "Unit1.h"
extern int REFin;              // Reference frequency input
extern int ChS, Fres;          // Channel Spacing, Channel resolution
extern double Fpfd, D, OD;     // PFD frequency, RF REFin doubler bit, Output Devider
extern double Fout, Fvco;      // Output frequency, VCO Frequency
extern double INTE, FRAC, MOD; // Integer division factor,  Fractionality, Modulus
extern double N;               // INT+FRAC/MOD
extern int Feedback_Select;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender) // нажатие на Button1 OK
{
  cancel = false;
  Close();            // закрыть Form7
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Button2Click(TObject *Sender) // нажатие на Button2 Cancel
{
  Close();            // закрыть Form7
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormShow(TObject *Sender) // открытие Form7
{
  cancel = true; // инициализация флага cancel при открытии Form7
  // при открытии Form7 сделать копии текущих значений элементов
  InpStr1=Form7->ComboBox1->ItemIndex;
  InpStr2=Form7->ComboBox3->ItemIndex;
  InpStr3=Form7->ComboBox4->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormClose(TObject *Sender, TCloseAction &Action) //закрытие Form7
{
  if(cancel) // если была нажата кнопка cancel, тогда восстановить предыдущие значения элементов
  {
    Form7->ComboBox1->ItemIndex=InpStr1;
    Form7->ComboBox3->ItemIndex=InpStr2;
    Form7->ComboBox4->ItemIndex=InpStr3;

    Form1->UpdateRegister4();  // обновление значения Register 4
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ComboBox4Change(TObject *Sender)
{
  Form1->UpdateRegister4();  // обновление значения Register 4
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ComboBox3Change(TObject *Sender)
{
  Form1->UpdateRegister4();  // обновление значения Register 4
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ComboBox1Change(TObject *Sender)
{
  if(ComboBox1->ItemIndex==0) Feedback_Select=0;
  else                        Feedback_Select=1;

  Form1->UpdateRegister4();  // обновление значения Register 4
}
//---------------------------------------------------------------------------

