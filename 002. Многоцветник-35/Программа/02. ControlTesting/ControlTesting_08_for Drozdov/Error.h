//---------------------------------------------------------------------------

#ifndef ErrorH
#define ErrorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TErrorForm : public TForm
{
__published:	// IDE-managed Components
  TButton *btnOK;
  TPanel *Panel1;
  TPanel *Panel2;
  void __fastcall btnOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TErrorForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TErrorForm *ErrorForm;
//---------------------------------------------------------------------------
#endif
