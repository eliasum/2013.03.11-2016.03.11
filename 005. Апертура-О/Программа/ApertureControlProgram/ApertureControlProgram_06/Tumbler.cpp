//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tumbler.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_Tumbler *F_Tumbler;
//---------------------------------------------------------------------------
__fastcall TF_Tumbler::TF_Tumbler(TComponent* Owner)
	: TForm(Owner)
{
  BorderIcons = TBorderIcons() >> biSystemMenu;
}
//---------------------------------------------------------------------------
void __fastcall TF_Tumbler::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
  if(Shift.Contains(ssAlt)&&Key==VK_F4) Tag=1;
}
//---------------------------------------------------------------------------
void __fastcall TF_Tumbler::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  if(Tag)
  {
	CanClose=false;
	Tag=0;
  }
}
//---------------------------------------------------------------------------
