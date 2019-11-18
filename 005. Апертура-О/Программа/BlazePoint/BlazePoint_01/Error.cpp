//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Error.h"
#include "BlazePoint_main.h"
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
  Close();  
}
//---------------------------------------------------------------------------


