//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
  TStaticText *StaticText1;
  TEdit *Edit1;
  TEdit *Edit2;
  TEdit *Edit3;
  TStaticText *StaticText2;
  TStaticText *StaticText3;
  TStaticText *StaticText4;
  TButton *Button1;
  TButton *Button2;
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall Edit1Change(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
  Boolean cancel;    // флаг выхода без сохранения
  AnsiString InpStr; // строка для промежуточного сохранения значения Edit
  __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
