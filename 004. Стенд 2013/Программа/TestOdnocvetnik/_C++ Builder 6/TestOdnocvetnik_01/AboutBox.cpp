//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutBox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sPanel"
#pragma link "sLabel"
#pragma resource "*.dfm"
TF_AboutBox *F_AboutBox;
//---------------------------------------------------------------------------
__fastcall TF_AboutBox::TF_AboutBox(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TF_AboutBox::B_ExitClick(TObject *Sender)
{
  Close();               // закрыть форму  
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::sWebLabel1Click(TObject *Sender)
{
  // обработка гиперссылки на почту eliasum@yandex.ru:
  AnsiString EmailValueStr;
  EmailValueStr = "mailto:" + ST_Email->Caption + "?subject=Theme";
  ShellExecute(Handle,NULL, EmailValueStr.c_str(), NULL,NULL,SW_SHOWNORMAL);  
}
//---------------------------------------------------------------------------
