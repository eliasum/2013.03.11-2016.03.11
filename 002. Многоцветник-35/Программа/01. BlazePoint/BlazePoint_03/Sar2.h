//---------------------------------------------------------------------------

#ifndef Sar2H
#define Sar2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TF_Sar2 : public TForm
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
  TStaticText *StaticText9;
  TStaticText *StaticText10;
  TStaticText *StaticText11;
  TStaticText *StaticText12;
  TComboBox *CB_1;
  TComboBox *CB_2;
  TComboBox *CB_3;
  TComboBox *CB_4;
  TComboBox *CB_5;
  TComboBox *CB_6;
  TLabel *Label1;
  void __fastcall CB_1Change(TObject *Sender);
  void __fastcall CB_2Change(TObject *Sender);
  void __fastcall CB_3Change(TObject *Sender);
  void __fastcall CB_4Change(TObject *Sender);
  void __fastcall CB_5Change(TObject *Sender);
  void __fastcall CB_6Change(TObject *Sender);
  void __fastcall B_OKClick(TObject *Sender);
  void __fastcall B_CancelClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
  Boolean cancel;     // флаг выхода без сохранения
  AnsiString InpStr1; // строки для промежуточного сохранения значения ComboBox'ов
  AnsiString InpStr2;
  AnsiString InpStr3;
  AnsiString InpStr4;
  AnsiString InpStr5;
  AnsiString InpStr6;
  __fastcall TF_Sar2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_Sar2 *F_Sar2;
//---------------------------------------------------------------------------
#endif
