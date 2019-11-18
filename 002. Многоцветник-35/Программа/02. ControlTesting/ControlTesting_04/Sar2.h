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
  TLabel *Label1;
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
  void __fastcall CB_1Change(TObject *Sender);
  void __fastcall CB_2Change(TObject *Sender);
  void __fastcall CB_3Change(TObject *Sender);
  void __fastcall CB_4Change(TObject *Sender);
  void __fastcall CB_5Change(TObject *Sender);
  void __fastcall CB_6Change(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall B_OKClick(TObject *Sender);
  void __fastcall B_CancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  Boolean cancel;     // флаг выхода без сохранения
  int InpStr1; // строки для промежуточного сохранения значения ComboBox'ов
  int InpStr2;
  int InpStr3;
  int InpStr4;
  int InpStr5;
  int InpStr6;
  __fastcall TF_Sar2::TF_Sar2(TComponent* Owner);
  void __fastcall TF_Sar2::UpdateSar2(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_Sar2 *F_Sar2;
//---------------------------------------------------------------------------
#endif
