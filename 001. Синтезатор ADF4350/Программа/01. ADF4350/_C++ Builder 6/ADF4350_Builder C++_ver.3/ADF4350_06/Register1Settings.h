//---------------------------------------------------------------------------

#ifndef Register1SettingsH
#define Register1SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TStaticText *StaticText1;
  TEdit *Edit1;
  TButton *Button1;
  TButton *Button2;
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall Edit1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
  int Phase; // Phase
  Boolean cancel;    // флаг выхода без сохранения
  AnsiString InpStr; // строка для промежуточного сохранения значения Edit
  double InpPhase;   // строка для промежуточного сохранения значения Phase
  __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
