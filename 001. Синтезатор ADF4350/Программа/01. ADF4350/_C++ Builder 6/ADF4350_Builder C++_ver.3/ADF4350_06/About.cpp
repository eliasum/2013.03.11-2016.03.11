//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::StaticText3Click(TObject *Sender)  // �� �������
{
  // ��������� ����������� �� ����� eliasum@yandex.ru:
  AnsiString      EmailValueStr;
  EmailValueStr = "mailto:" + StaticText3->Caption + "?subject=Theme";
  ShellExecute(Handle,NULL, EmailValueStr.c_str(), NULL,NULL,SW_SHOWNORMAL);

  StaticText3->Font->Color=clPurple;                   // �������� ���� �� ���������
  StaticText3->Font->Style=TFontStyles()<<fsUnderline; // ������� �������������
}
//---------------------------------------------------------------------------

void __fastcall TForm3::StaticText3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)  // ��� �������
{
  StaticText3->Font->Color=clRed;                      // �������� ���� �� �������
  StaticText3->Font->Style=TFontStyles()>>fsUnderline; // ������ �������������
}
//---------------------------------------------------------------------------
void __fastcall TForm3::StaticText3MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) // ���������� �������
{
  StaticText3->Font->Color=clPurple;                   // �������� ���� �� ���������
  StaticText3->Font->Style=TFontStyles()<<fsUnderline; // ������� �������������
}
//---------------------------------------------------------------------------


