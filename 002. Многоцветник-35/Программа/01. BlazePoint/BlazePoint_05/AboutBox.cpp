//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutBox.h"
#include "BlazePoint_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_AboutBox *F_AboutBox;
//---------------------------------------------------------------------------
__fastcall TF_AboutBox::TF_AboutBox(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::ST_EmailClick(TObject *Sender) // по нажатии
{
  // обработка гиперссылки на почту eliasum@yandex.ru:
  AnsiString EmailValueStr;
  EmailValueStr = "mailto:" + ST_Email->Caption + "?subject=Theme";
  ShellExecute(Handle,NULL, EmailValueStr.c_str(), NULL,NULL,SW_SHOWNORMAL);

  ST_Email->Font->Color=clPurple;                   // изменить цвет на пурпурный
  ST_Email->Font->Style=TFontStyles()<<fsUnderline; // вернуть подчёркивание
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::ST_EmailMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) // при нажатии
{
  ST_Email->Font->Color=clRed;                      // изменить цвет на красный
  ST_Email->Font->Style=TFontStyles()>>fsUnderline; // убрать подчёркивание
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::ST_EmailMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) // отпускание нажатой
{
  ST_Email->Font->Color=clPurple;                   // изменить цвет на пурпурный
  ST_Email->Font->Style=TFontStyles()<<fsUnderline; // вернуть подчёркивание
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::B_ExitClick(TObject *Sender)
{
  Close();               // закрыть форму
}
//---------------------------------------------------------------------------
