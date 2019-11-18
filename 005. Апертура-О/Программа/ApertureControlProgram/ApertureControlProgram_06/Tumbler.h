//---------------------------------------------------------------------------

#ifndef TumblerH
#define TumblerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TF_Tumbler : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	__fastcall TF_Tumbler(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_Tumbler *F_Tumbler;
//---------------------------------------------------------------------------
#endif
