//---------------------------------------------------------------------------

#ifndef IFControlH
#define IFControlH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TF_IFControl : public TForm
{
__published:	// IDE-managed Components
  TComboBox *CB_Raf;
  TLabel *Label1;
  TComboBox *CB_Taf;
  TLabel *Label2;
  TComboBox *CB_Rfcf;
  TLabel *Label3;
  TLabel *Label4;
  TComboBox *CB_Tfcf;
  TButton *B_OK;
  TButton *B_Cancel;
  void __fastcall B_OKClick(TObject *Sender);
  void __fastcall B_CancelClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall CB_RafChange(TObject *Sender);
  void __fastcall CB_TafChange(TObject *Sender);
  void __fastcall CB_RfcfChange(TObject *Sender);
  void __fastcall CB_TfcfChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
  Boolean cancel;   // флаг выхода без сохранения
  int InpStr1;      // строка для промежуточного сохранения 1
  int InpStr2;      // строка для промежуточного сохранения 2
  int InpStr3;      // строка для промежуточного сохранения 3
  int InpStr4;      // строка для промежуточного сохранения 4
  __fastcall TF_IFControl(TComponent* Owner);

  void __fastcall TF_IFControl::UpdateIFControl(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_IFControl *F_IFControl;
//---------------------------------------------------------------------------
#endif
