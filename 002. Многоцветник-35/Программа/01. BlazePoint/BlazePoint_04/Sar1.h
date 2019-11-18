//---------------------------------------------------------------------------

#ifndef Sar1H
#define Sar1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TF_Sar1 : public TForm
{
__published:	// IDE-managed Components
  TStaticText *StaticText1;
  TStaticText *StaticText2;
  TStaticText *StaticText3;
  TStaticText *StaticText4;
  TButton *B_OK;
  TButton *B_Cancel;
  TStaticText *StaticText5;
  TStaticText *StaticText6;
  TStaticText *StaticText7;
  TStaticText *StaticText8;
  TEdit *E_1;
  TEdit *E_2;
  TEdit *E_3;
  TEdit *E_4;
  void __fastcall E_1Change(TObject *Sender);
  void __fastcall E_2Change(TObject *Sender);
  void __fastcall E_3Change(TObject *Sender);
  void __fastcall E_4Change(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall B_OKClick(TObject *Sender);
  void __fastcall B_CancelClick(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
  Boolean cancel;    // флаг выхода без сохранения
  AnsiString InpStr1; // строки для промежуточного сохранения значения Edit'ов
  AnsiString InpStr2;
  AnsiString InpStr3;
  AnsiString InpStr4;
  __fastcall TF_Sar1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_Sar1 *F_Sar1;
//---------------------------------------------------------------------------
#endif
