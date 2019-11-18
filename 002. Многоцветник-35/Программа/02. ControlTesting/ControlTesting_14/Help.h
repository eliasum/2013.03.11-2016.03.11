//---------------------------------------------------------------------------

#ifndef HelpH
#define HelpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TF_Help : public TForm
{
__published:	// IDE-managed Components
  TScrollBox *ScrollBox1;
  TLabel *Label1;
  TMemo *Memo1;
private:	// User declarations
public:		// User declarations
  __fastcall TF_Help(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_Help *F_Help;
//---------------------------------------------------------------------------
#endif
