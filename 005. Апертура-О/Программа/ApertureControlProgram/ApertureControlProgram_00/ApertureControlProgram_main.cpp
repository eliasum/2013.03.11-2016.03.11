//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ApertureControlProgram_main.h"
#include "SelfControl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CommPort"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------





void __fastcall TMainForm::Button1Click(TObject *Sender)
{
  F_SelfControl->ShowModal();
}
//---------------------------------------------------------------------------

