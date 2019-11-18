//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Error.h"
#include "ControlTesting_Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TErrorForm *ErrorForm;
//---------------------------------------------------------------------------
__fastcall TErrorForm::TErrorForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TErrorForm::btnOKClick(TObject *Sender)
{
        ErrorForm->Visible=false;
}
//---------------------------------------------------------------------------
