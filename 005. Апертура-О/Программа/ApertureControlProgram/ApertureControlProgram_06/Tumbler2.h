//---------------------------------------------------------------------------

#ifndef Tumbler2H
#define Tumbler2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TF_Tumbler2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	__fastcall TF_Tumbler2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_Tumbler2 *F_Tumbler2;
//---------------------------------------------------------------------------
#endif
