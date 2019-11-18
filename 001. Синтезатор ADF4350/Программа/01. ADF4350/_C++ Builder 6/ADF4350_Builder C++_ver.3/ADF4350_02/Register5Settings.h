//---------------------------------------------------------------------------

#ifndef Register5SettingsH
#define Register5SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
  TComboBox *ComboBox1;
  TStaticText *StaticText1;
  TButton *Button1;
  TButton *Button2;
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
  Boolean cancel;     // флаг выхода без сохранения
  AnsiString InpStr;  // строка для промежуточного сохранения
  __fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
