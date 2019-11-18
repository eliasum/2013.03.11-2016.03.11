//---------------------------------------------------------------------------

#ifndef BTH
#define BTH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TF_BT : public TForm
{
__published:	// IDE-managed Components
  TEdit *E_1;
  TEdit *E_2;
  TEdit *E_3;
  TEdit *E_4;
  TStaticText *StaticText1;
  TStaticText *StaticText2;
  TStaticText *StaticText3;
  TStaticText *StaticText4;
  TButton *B_OK;
  TButton *B_Cancel;
  void __fastcall E_1Change(TObject *Sender);
  void __fastcall E_2Change(TObject *Sender);
  void __fastcall E_3Change(TObject *Sender);
  void __fastcall E_4Change(TObject *Sender);
  void __fastcall B_OKClick(TObject *Sender);
  void __fastcall B_CancelClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
  Boolean cancel;    // ���� ������ ��� ����������
  AnsiString InpStr1; // ������ ��� �������������� ���������� �������� Edit
  AnsiString InpStr2; // ������ ��� �������������� ���������� �������� Edit
  AnsiString InpStr3; // ������ ��� �������������� ���������� �������� Edit
  AnsiString InpStr4; // ������ ��� �������������� ���������� �������� Edit
  __fastcall TF_BT(TComponent* Owner);
  void __fastcall TF_BT::UpdateBT(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_BT *F_BT;
//---------------------------------------------------------------------------
#endif
