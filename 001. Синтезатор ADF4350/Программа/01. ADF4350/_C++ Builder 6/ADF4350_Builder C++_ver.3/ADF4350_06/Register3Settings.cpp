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
void __fastcall TForm6::FormShow(TObject *Sender) // �������� Form6
{
  cancel = true; // ������������� ����� cancel ��� �������� Form6
  // ��� �������� Form6 ������� ����� ������� �������� ���������
  InpStr1=Form6->CheckBox1->Checked;
  InpStr2=Form6->Edit1->Text;
  InpStr3=Form6->Edit2->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormClose(TObject *Sender, TCloseAction &Action) // �������� Form6
{
  if(cancel) // ���� ���� ������ ������ cancel, ����� ������������ ���������� �������� ���������
  {
    Form6->CheckBox1->Checked=InpStr1;
    Form6->Edit1->Text=InpStr2;
    Form6->Edit2->Text=InpStr3;
    CLK_DIV = StrToInt(InpStr2); // ������������� ����� �� Edit1 � CLK DIV VALUE
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender) // ������� �� Button1 OK
{
  cancel = false;
  Close();            // ������� Form6
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender) // ������� �� Button2 Cancel
{
  Close();            // ������� Form6
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit1Change(TObject *Sender) // �������������� CLK DIV VALUE
{
  double tsync;

  CLK_DIV = StrToInt(Form6->Edit1->Text); // ������������� ����� �� Edit1 � CLK DIV VALUE
  tsync = CLK_DIV*2.5;
  Form6->Edit2->Text=FloatToStr(tsync);   // ������������� tsync [us] � ����� Edit2

  Form1->UpdateRegister3();               // ���������� �������� Register 2
}
//---------------------------------------------------------------------------
void __fastcall TForm6::CheckBox1Click(TObject *Sender)
{
  if(CheckBox1->Checked==true)
  {
    Form1->CheckBox6->Checked=false;      // ��������� ����� Fast Lock enable
    Form1->CheckBox6->Enabled=false;      // ��������� ����� Fast Lock enable

    CLK_DIV_MODE=2;                       // ����� Resync enable
    Form1->UpdateRegister3();             // ���������� �������� Register 3
  }
  else
  {
    Form1->CheckBox6->Enabled=true;       // ��������� ����� Fast Lock enable

    CLK_DIV_MODE=0;                       // ����� Clock Divider off
    Form1->UpdateRegister3();             // ���������� �������� Register 3
  }
}
//---------------------------------------------------------------------------

