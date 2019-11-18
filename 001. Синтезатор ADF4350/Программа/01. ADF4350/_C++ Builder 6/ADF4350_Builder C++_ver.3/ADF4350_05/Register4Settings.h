//---------------------------------------------------------------------------

#ifndef Register4SettingsH
#define Register4SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TStaticText *StaticText1;
  TStaticText *StaticText2;
  TComboBox *ComboBox1;
  TComboBox *ComboBox3;
  TComboBox *ComboBox4;
  TStaticText *StaticText4;
  TStaticText *StaticText5;
  TStaticText *StaticText6;
  TButton *Button1;
  TButton *Button2;
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall ComboBox4Change(TObject *Sender);
  void __fastcall ComboBox3Change(TObject *Sender);
  void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
  Boolean cancel;   // флаг выхода без сохранения
  int InpStr1;      // строка для промежуточного сохранения 1
  int InpStr2;      // строка для промежуточного сохранения 2
  int InpStr3;      // строка для промежуточного сохранения 3
  __fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif                       
