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
void __fastcall TForm4::Button1Click(TObject *Sender) // ������� �� Button1 OK
{
  cancel = false;
  Close();            // ������� Form4
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender) // ������� �� Button2 Cancel
{
  Close();            // ������� Form4
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender) // �������� Form4
{
  cancel = true;             // ������������� ����� cancel ��� �������� Form4
  InpStr=Form4->Edit1->Text; // ��� �������� Form4 ������� ����� �������� �������� � Edit1 � Phase
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action) // �������� Form4
{
  if(cancel)  // ���� ���� ������ ������ cancel
  {
    Form4->Edit1->Text=InpStr; // ����� ������������ ���������� �������� Edit1 � Phase
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

  Form1->UpdateRegister1();  // ���������� �������� Register 1
}
//---------------------------------------------------------------------------

