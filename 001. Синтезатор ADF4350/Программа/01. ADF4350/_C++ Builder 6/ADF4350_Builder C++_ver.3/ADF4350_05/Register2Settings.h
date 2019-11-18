//---------------------------------------------------------------------------

#ifndef Register2SettingsH
#define Register2SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TComboBox *ComboBox1;
  TStaticText *StaticText1;
  TStaticText *StaticText2;
  TComboBox *ComboBox2;
  TGroupBox *GroupBox2;
  TComboBox *ComboBox3;
  TStaticText *StaticText3;
  TStaticText *StaticText4;
  TComboBox *ComboBox4;
  TStaticText *StaticText5;
  TStaticText *StaticText6;
  TGroupBox *GroupBox3;
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TCheckBox *CheckBox3;
  TButton *Button1;
  TButton *Button2;
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall CheckBox3Click(TObject *Sender);
  void __fastcall ComboBox4Change(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
  void __fastcall ComboBox3Change(TObject *Sender);
  void __fastcall ComboBox2Change(TObject *Sender);
  void __fastcall ComboBox1Change(TObject *Sender);
  void __fastcall CheckBox2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  Boolean cancel;   // флаг выхода без сохранения
  int InpStr1;      // строка для промежуточного сохранения 1
  int InpStr2;      // строка для промежуточного сохранения 2
  int InpStr3;      // строка для промежуточного сохранения 3
  int InpStr4;      // строка для промежуточного сохранения 4
  Boolean InpStr5;  // строка для промежуточного сохранения 5
  Boolean InpStr6;  // строка для промежуточного сохранения 6
  Boolean InpStr7;  // строка для промежуточного сохранения 7
  __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
