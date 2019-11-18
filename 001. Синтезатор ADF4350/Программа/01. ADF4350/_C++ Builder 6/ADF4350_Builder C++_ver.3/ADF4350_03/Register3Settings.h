//---------------------------------------------------------------------------

#ifndef Register3SettingsH
#define Register3SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
  TCheckBox *CheckBox1;
  TGroupBox *GroupBox1;
  TStaticText *StaticText1;
  TEdit *Edit1;
  TGroupBox *GroupBox2;
  TEdit *Edit2;
  TStaticText *StaticText2;
  TLabel *Label1;
  TButton *Button1;
  TButton *Button2;
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall Edit1Change(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  Boolean cancel;     // флаг выхода без сохранения
  Boolean InpStr1;    // строка для промежуточного сохранения 1
  AnsiString InpStr2; // строка для промежуточного сохранения 2
  AnsiString InpStr3; // строка для промежуточного сохранения 3
  __fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
