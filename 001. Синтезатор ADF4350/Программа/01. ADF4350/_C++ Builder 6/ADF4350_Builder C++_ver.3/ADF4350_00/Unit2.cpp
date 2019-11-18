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

void __fastcall TForm2::Button1Click(TObject *Sender) // ������� �� Button1 OK
{
  cancel = false;
  Close();            // ������� Form2
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender) // ������� �� Button2 Cancel
{
  Close();            // ������� Form2
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1Change(TObject *Sender)  // �������������� Edit1 Clk Div Value
{
  if(Form2->Edit1->Text<=0) Form2->Edit1->Text=0;     // ����� �� ����� ���� ������ ����

  CLK_DIV = StrToInt(Form2->Edit1->Text); // ������������� ����� �� Edit1 � CLK DIV VALUE
  double E2 = CLK_DIV/Fpfd;
  Form2->Edit2->Text=FloatToStr(E2);      // ������������� ������������ � ����� Edit2 BW Time Interval [us]

  Form1->UpdateRegister3();               // ���������� �������� Register 3
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action) // �������� Form2
{
  if(cancel)
  {
     Form2->Edit1->Text=InpStr; // ���� ���� ������ ������ cancel, ����� ������������
                                // ���������� �������� Edit1
     Form1->CheckBox6->Checked=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender) // �������� Form2
{
  cancel = true;             // ������������� ����� cancel ��� �������� Form2
  InpStr=Form2->Edit1->Text; // ��� �������� Form2 ������� ����� �������� �������� � Edit1 
}
//---------------------------------------------------------------------------




