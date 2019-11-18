//---------------------------------------------------------------------------

#ifndef Sar3H
#define Sar3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TF_Sar3 : public TForm
{
__published:	// IDE-managed Components
  TButton *B_OK;
  TButton *B_Cancel;
  TEdit *E_1;
  TEdit *E_2;
  TEdit *E_3;
  TEdit *E_4;
  TEdit *E_5;
  TEdit *E_6;
  TEdit *E_7;
  TEdit *E_8;
  TEdit *E_9;
  TEdit *E_10;
  TEdit *E_11;
  TEdit *E_12;
  TStaticText *StaticText1;
  TStaticText *StaticText2;
  TStaticText *StaticText3;
  TStaticText *StaticText4;
  TStaticText *StaticText5;
  TStaticText *StaticText6;
  TStaticText *StaticText7;
  TStaticText *StaticText8;
  TStaticText *StaticText9;
  TStaticText *StaticText10;
  TStaticText *StaticText11;
  TStaticText *StaticText12;
  void __fastcall E_1Change(TObject *Sender);
  void __fastcall E_2Change(TObject *Sender);
  void __fastcall E_3Change(TObject *Sender);
  void __fastcall E_4Change(TObject *Sender);
  void __fastcall E_5Change(TObject *Sender);
  void __fastcall E_6Change(TObject *Sender);
  void __fastcall E_7Change(TObject *Sender);
  void __fastcall E_8Change(TObject *Sender);
  void __fastcall E_9Change(TObject *Sender);
  void __fastcall E_10Change(TObject *Sender);
  void __fastcall E_11Change(TObject *Sender);
  void __fastcall E_12Change(TObject *Sender);
  void __fastcall B_OKClick(TObject *Sender);
  void __fastcall B_CancelClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
  Boolean cancel;     // ���� ������ ��� ����������
  AnsiString InpStr1; // ������ ��� �������������� ���������� �������� Edit'��
  AnsiString InpStr2;
  AnsiString InpStr3;
  AnsiString InpStr4;
  AnsiString InpStr5;
  AnsiString InpStr6;
  AnsiString InpStr7;
  AnsiString InpStr8;
  AnsiString InpStr9;
  AnsiString InpStr10;
  AnsiString InpStr11;
  AnsiString InpStr12;
  __fastcall TF_Sar3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_Sar3 *F_Sar3;
//---------------------------------------------------------------------------
#endif
