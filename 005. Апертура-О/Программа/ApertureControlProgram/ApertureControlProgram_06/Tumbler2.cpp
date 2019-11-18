//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tumbler2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_Tumbler2 *F_Tumbler2;
//---------------------------------------------------------------------------
__fastcall TF_Tumbler2::TF_Tumbler2(TComponent* Owner)
	: TForm(Owner)
{
  BorderIcons = TBorderIcons() >> biSystemMenu;
}
//---------------------------------------------------------------------------
void __fastcall TF_Tumbler2::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
  if(Shift.Contains(ssAlt)&&Key==VK_F4) Tag=1;
}
//---------------------------------------------------------------------------
void __fastcall TF_Tumbler2::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  if(Tag)
  {
	CanClose=false;
	Tag=0;
  }
}
//---------------------------------------------------------------------------
