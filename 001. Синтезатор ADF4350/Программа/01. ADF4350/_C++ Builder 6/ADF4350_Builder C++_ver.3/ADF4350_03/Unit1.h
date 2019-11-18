//---------------------------------------------------------------------------
  
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include "CommPort.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *Reference;
  TGroupBox *OtherOptions;
  TButton *Button7;
  TButton *Button9;
  TButton *Button5;
  TButton *Button10;
  TButton *Button11;
  TGroupBox *GroupBox1;
  TGroupBox *GroupBox2;
  TEdit *Edit2;
  TStaticText *StaticText1;
  TStaticText *StaticText2;
  TComboBox *ComboBox1;
  TStaticText *StaticText3;
  TEdit *Edit1;
  TStaticText *StaticText4;
  TComboBox *ComboBox2;
  TStaticText *StaticText5;
  TStaticText *StaticText6;
  TComboBox *ComboBox3;
  TStaticText *StaticText7;
  TStaticText *StaticText8;
  TComboBox *ComboBox4;
  TStaticText *StaticText9;
  TComboBox *ComboBox5;
  TRadioButton *RadioButton3;
  TRadioButton *RadioButton4;
  TCheckBox *CheckBox3;
  TCheckBox *CheckBox6;
  TGroupBox *GroupBox3;
  TRadioButton *RadioButton1;
  TRadioButton *RadioButton2;
  TEdit *Edit3;
  TEdit *Edit4;
  TStaticText *StaticText11;
  TEdit *Edit5;
  TStaticText *StaticText12;
  TStaticText *StaticText13;
  TStaticText *StaticText14;
  TButton *Button1;
  TButton *Button2;
  TGroupBox *GroupBox4;
  TStaticText *StaticText15;
  TEdit *Edit6;
  TStaticText *StaticText16;
  TRadioButton *RadioButton5;
  TRadioButton *RadioButton6;
  TRadioButton *RadioButton7;
  TGroupBox *GroupBox5;
  TLabel *Label2;
  TLabel *Label3;
  TLabel *Label4;
  TLabel *Label5;
  TLabel *Label6;
  TLabel *Label7;
  TLabel *Label8;
  TLabel *Label9;
  TLabel *Label10;
  TLabel *Label11;
  TButton *Button3;
  TLabel *Label12;
  TStaticText *StaticText17;
  TLabel *Label13;
  TLabel *Label14;
  TLabel *Label1;
  TTimer *Timer1;
  TLabel *Label15;
  TTimer *Timer2;
  TGroupBox *GroupBox6;
  TProgressBar *PB_proc;
  TCommPort *CommPort1;
  TLabel *Label16;
  TComboBox *CB_ComNum;
  TLabel *Label17;
  TComboBox *CB_BaudRate;
  TPanel *B_Open;
  TLabel *SendDirect;
  TButton *Button4;
  TTimer *Timer3;
  TRadioButton *RB_ADF_filters;
  TRadioButton *RB_Parallel_lines;
  void __fastcall CheckBox6Click(TObject *Sender);
  void __fastcall Edit2Change(TObject *Sender);
  void __fastcall StaticText17DblClick(TObject *Sender);
  void __fastcall Button9Click(TObject *Sender);
  void __fastcall Button7Click(TObject *Sender);
  void __fastcall Button10Click(TObject *Sender);
  void __fastcall Button5Click(TObject *Sender);
  void __fastcall Button11Click(TObject *Sender);
  void __fastcall RadioButton1Click(TObject *Sender);
  void __fastcall RadioButton2Click(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall RadioButton6Click(TObject *Sender);
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall Edit6Change(TObject *Sender);
  void __fastcall RadioButton7Click(TObject *Sender);
  void __fastcall Edit3Change(TObject *Sender);
  void __fastcall Edit4Change(TObject *Sender);
  void __fastcall ComboBox1Change(TObject *Sender);
  void __fastcall Edit1Change(TObject *Sender);
  void __fastcall Edit5Change(TObject *Sender);
  void __fastcall Button3Click(TObject *Sender);
  void __fastcall ComboBox2Change(TObject *Sender);
  void __fastcall ComboBox5Change(TObject *Sender);
  void __fastcall RadioButton3Click(TObject *Sender);
  void __fastcall RadioButton4Click(TObject *Sender);
  void __fastcall CheckBox3Click(TObject *Sender);
  void __fastcall ComboBox3Change(TObject *Sender);
  void __fastcall ComboBox4Change(TObject *Sender);
  void __fastcall Timer2Timer(TObject *Sender);
  void __fastcall CB_ComNumChange(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall CB_BaudRateChange(TObject *Sender);
  void __fastcall CommPort1Open(TObject *Sender, int Error);
  void __fastcall CommPort1Close(TObject *Sender);
  void __fastcall B_OpenMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall B_OpenMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall Button4Click(TObject *Sender);
  void __fastcall Timer3Timer(TObject *Sender);
  void __fastcall RadioButton5Click(TObject *Sender);
  void __fastcall RB_ADF_filtersClick(TObject *Sender);
  void __fastcall RB_Parallel_linesClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
  int InpCLKDIV;                  // строка для промежуточного сохранения
  unsigned int Err_TimeOut;

  __fastcall TForm1(TComponent* Owner);
  void __fastcall TForm1::Ndevider(void);  // вычисление INT, FRAC и MOD
  void __fastcall TForm1::UpdateRegister0(void);
  void __fastcall TForm1::UpdateRegister1(void);
  void __fastcall TForm1::UpdateRegister2(void);
  void __fastcall TForm1::UpdateRegister3(void);
  void __fastcall TForm1::UpdateRegister4(void);
  void __fastcall TForm1::UpdateRegister5(void);
  void __fastcall TForm1::Activatef(AnsiString metka);
  void __fastcall TForm1::uart_puthex_nibble(unsigned char b);
  void __fastcall TForm1::uart_puthex_byte(unsigned char  b);
  void __fastcall TForm1::uart_puthex_4bytes(int n);
  void __fastcall TForm1::uart_4bytes(int n);
  void __fastcall TForm1::ComPortTransmitter(void);
  void __fastcall TForm1::Fvco_OD(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
