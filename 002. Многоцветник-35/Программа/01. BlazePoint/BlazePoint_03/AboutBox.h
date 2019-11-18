//---------------------------------------------------------------------------

#ifndef AboutBoxH
#define AboutBoxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TF_AboutBox : public TForm
{
__published:	// IDE-managed Components
  TPanel *Panel2;
  TLabel *ProductName;
  TLabel *Version_view;
  TLabel *Copyright;
  TLabel *Comments;
  TLabel *Device;
  TButton *B_Exit;
  TStaticText *ST_Email;
  void __fastcall ST_EmailClick(TObject *Sender);
  void __fastcall ST_EmailMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ST_EmailMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall B_ExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TF_AboutBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_AboutBox *F_AboutBox;
//---------------------------------------------------------------------------
#endif
