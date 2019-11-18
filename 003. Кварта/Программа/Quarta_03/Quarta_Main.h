//---------------------------------------------------------------------------

#ifndef Quarta_MainH
#define Quarta_MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include "CommPort.h"
#include "NIDAQmx.h"
#include "Math.hpp"       // Log10(delta); RoundTo(temp,temp1);
#include <Math.h>
#include "inifiles.hpp"
#include "windows.h"      // Sleep(ms);
//---------------------------------------------------------------------------
struct DataControl
{
  int NumIP;              // max 12
  int NumCurrent;         // max 10
  int NumDetSig;          // max 8
  int NumDetWSig;         // max 8
  int NumTemp;            // max 5
  bool KG;
  bool TUt;
};
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
  TStaticText *StaticText1;
  TPanel *P_U5V;
  TPanel *P_U12V;
  TPanel *P_I12V;
  TPanel *P_I5V;
  TGroupBox *GB_Commands;
  TButton *B_Ready;
  TButton *B_Send;
  TPanel *P_SystemTime;
  TPanel *P_WorkTime;
  TTimer *SystemTimer;
  TTimer *WorkTimer;
  TLabel *L_S;
  TLabel *L_M;
  TLabel *L_H;
  TStaticText *StaticText3;
  TStaticText *StaticText4;
  TSaveDialog *SaveDialog;
  TGroupBox *GB_Message;
  TEdit *E_EnterComment;
  TMemo *M_Log;
  TStaticText *StaticText6;
  TStaticText *StaticText7;
  TButton *B_Enter;
  TPageControl *PC_Main;
  TTabSheet *Tsh_Testing;
  TToolBar *ToolBar1;
  TToolButton *TB_LoadBlp;
  TToolButton *ToolButton3;
  TToolButton *TB_LoadSar;
  TToolButton *ToolButton5;
  TToolButton *TB_SaveTesting;
  TOpenDialog *OpenDialog;
  TOpenDialog *OpenDialog1;
  TImageList *ImageList1;
  TStatusBar *StatusBar1;
  TScrollBox *SB_Data2;
  TGroupBox *GB_Com3;
  TStaticText *StaticText16;
  TStaticText *StaticText17;
  TEdit *E_Com3_0;
  TEdit *E_Com3;
  TGroupBox *GB_Com6;
  TCheckBox *ChB_Com6;
  TComboBox *CB_Com6;
  TGroupBox *GB_Com7;
  TCheckBox *ChB_Com7;
  TComboBox *CB_Com7;
  TCheckBox *ChB_Com3;
  TGroupBox *GB_Com8;
  TCheckBox *ChB_Com8;
  TComboBox *CB_Com8;
  TGroupBox *GB_Com9;
  TCheckBox *ChB_Com9;
  TComboBox *CB_Com9;
  TGroupBox *GB_Com13;
  TCheckBox *ChB_Com13;
  TEdit *E_Com13_1;
  TStaticText *StaticText25;
  TEdit *E_Com13_2;
  TStaticText *StaticText26;
  TEdit *E_Com13_3;
  TStaticText *StaticText27;
  TStaticText *StaticText51;
  TComboBox *CB_Com3_1;
  TCommPort *CommPort1;
  TPanel *P_Temp;
  TPanel *P_Power;
  TTimer *NIDAQmxTimer;
  TPanel *P_1;
  TPanel *P_2;
  TPanel *P_3;
  TPanel *P_4;
  TPanel *P_5;
  TPanel *P_6;
  TTabSheet *Tsh_Kalibr;
  TToolButton *ToolButton2;
  TToolButton *TB_LoadTesting;
  TCheckBox *ChB_Log;
  TButton *B_DataOn;
  TButton *B_DataOff;
  TToolButton *ToolButton6;
  TToolButton *TB_About;
  TTabSheet *Sar_invisible;
  TListView *LV_Sar1;
  TListView *LV_Sar2;
  TListView *LV_Sar3;
  TListView *LV_Sar4;
  TStaticText *StaticText2;
  TStaticText *StaticText5;
  TStaticText *StaticText8;
  TStaticText *StaticText9;
  TToolButton *ToolButton1;
  TComboBox *CB_ComNum;
  TComboBox *CB_BaudRate;
  TLabel *Label2;
  TLabel *Label16;
  TLabel *L_SendDirect;
  TStaticText *StaticText19;
  TEdit *E_Com4;
  TStaticText *StaticText21;
  TEdit *E_Com5;
  TStaticText *StaticText28;
  TEdit *E_Com14_1;
  TStaticText *StaticText29;
  TEdit *E_Com14_2;
  TStaticText *StaticText30;
  TEdit *E_Com14_3;
  TStaticText *StaticText31;
  TEdit *E_Com15_1;
  TStaticText *StaticText32;
  TEdit *E_Com15_2;
  TStaticText *StaticText33;
  TEdit *E_Com15_3;
  TStaticText *StaticText34;
  TStaticText *StaticText35;
  TStaticText *StaticText36;
  TEdit *E_Com16_1;
  TEdit *E_Com16_2;
  TEdit *E_Com16_3;
  TStaticText *StaticText37;
  TStaticText *StaticText38;
  TStaticText *StaticText39;
  TEdit *E_Com17_1;
  TEdit *E_Com17_2;
  TEdit *E_Com17_3;
  TStaticText *StaticText40;
  TEdit *E_Com18_1;
  TStaticText *StaticText41;
  TEdit *E_Com18_2;
  TStaticText *StaticText42;
  TEdit *E_Com18_3;
  TStaticText *StaticText43;
  TEdit *E_Com19_1;
  TStaticText *StaticText44;
  TEdit *E_Com19_2;
  TStaticText *StaticText45;
  TEdit *E_Com19_3;
  TStaticText *StaticText46;
  TEdit *E_Com20_1;
  TStaticText *StaticText47;
  TEdit *E_Com20_2;
  TStaticText *StaticText48;
  TEdit *E_Com20_3;
  TRadioGroup *RG_P;
  TRadioButton *RB_5GHz;
  TRadioButton *RB_8GHz;
  TMainMenu *MainMenu;
  TMenuItem *File;
  TMenuItem *LoadBlp;
  TMenuItem *LoadSar;
  TMenuItem *N1;
  TMenuItem *SaveTst;
  TMenuItem *N2;
  TMenuItem *LoadTst;
  TMenuItem *N3;
  TMenuItem *Exit;
  TMenuItem *Help;
  TMenuItem *HelpAboutProg;
  TMenuItem *HelpAboutItem;
  TGroupBox *GB_Parameters;
  TLabel *Label1;
  TComboBox *CB_Output;
  TLabel *Label3;
  TComboBox *CB_AuxOut;
  TLabel *Label4;
  TEdit *E_OutFreq;
  TLabel *Label5;
  TRadioGroup *RG_param_reg;
  TRadioButton *RB_parameters;
  TRadioButton *RB_registers;
  TComboBox *CB_Sign;
  void __fastcall SystemTimerTimer(TObject *Sender);
  void __fastcall WorkTimerTimer(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall B_EnterClick(TObject *Sender);
  void __fastcall TB_LoadBlpClick(TObject *Sender);
  void __fastcall TB_LoadSarClick(TObject *Sender);
  void __fastcall TB_ExitClick(TObject *Sender);
  void __fastcall RB_ControlClick(TObject *Sender);
  void __fastcall RB_TestingClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall LV_Sar1DblClick(TObject *Sender);
  void __fastcall LV_Sar2DblClick(TObject *Sender);
  void __fastcall LV_Sar3DblClick(TObject *Sender);
  void __fastcall LV_Sar4DblClick(TObject *Sender);
  void __fastcall B_ReadyClick(TObject *Sender);
  void __fastcall CB_Com1Change(TObject *Sender);
  void __fastcall E_Command3_0KeyPress(TObject *Sender, char &Key);
  void __fastcall E_Com3_0Exit(TObject *Sender);
  void __fastcall CB_Com3_1Change(TObject *Sender);
  void __fastcall CB_Com7Change(TObject *Sender);
  void __fastcall CB_Com6Change(TObject *Sender);
  void __fastcall CB_Com8Change(TObject *Sender);
  void __fastcall CB_Com9Change(TObject *Sender);
  void __fastcall NIDAQmxTimerTimer(TObject *Sender);
  void __fastcall B_SendClick(TObject *Sender);
  void __fastcall ChB_LogClick(TObject *Sender);
  void __fastcall E_Com3Exit(TObject *Sender);
  void __fastcall E_Com3Change(TObject *Sender);
  void __fastcall E_Com4Exit(TObject *Sender);
  void __fastcall E_Com4Change(TObject *Sender);
  void __fastcall E_Com5Exit(TObject *Sender);
  void __fastcall E_Com5Change(TObject *Sender);
  void __fastcall TB_SaveTestingClick(TObject *Sender);
  void __fastcall TB_LoadTestingClick(TObject *Sender);
  void __fastcall TempPowerTimerTimer(TObject *Sender);
  void __fastcall B_DataOnClick(TObject *Sender);
  void __fastcall B_DataOffClick(TObject *Sender);
  void __fastcall TB_AboutClick(TObject *Sender);
  void __fastcall CB_ComNumChange(TObject *Sender);
  void __fastcall CB_BaudRateChange(TObject *Sender);
  void __fastcall ExitClick(TObject *Sender);
  void __fastcall HelpAboutProgClick(TObject *Sender);
  void __fastcall CB_OutputChange(TObject *Sender);
  void __fastcall CB_AuxOutChange(TObject *Sender);
  void __fastcall E_OutFreqChange(TObject *Sender);
  void __fastcall RB_parametersClick(TObject *Sender);
  void __fastcall RB_registersClick(TObject *Sender);
  void __fastcall E_OutFreqExit(TObject *Sender);
  void __fastcall E_Com13_1Exit(TObject *Sender);
  void __fastcall E_Com3_0Change(TObject *Sender);
  void __fastcall CB_SignChange(TObject *Sender);
  void __fastcall CB_SignExit(TObject *Sender);
  void __fastcall CB_SignKeyPress(TObject *Sender, char &Key);
  void __fastcall E_Com4KeyPress(TObject *Sender, char &Key);
private:	// User declarations
  AnsiString BlpFName;
  AnsiString SarFName;
public:		// User declarations
  void __fastcall TMain_Form::AddSaveLog(AnsiString comment);
  void __fastcall TMain_Form::Update_Dump_blp();
  void __fastcall TMain_Form::Update_Dump_sar();
  bool TMain_Form::IsValidInt(int min, int max, String value, String EdIzm);
  void TMain_Form::ShowError(int ErrorNum, float Par1, float Par2, String Par3);
  void __fastcall TMain_Form::StartControl();
  void __fastcall TMain_Form::StartTesting();
  void __fastcall TMain_Form::StopControl();
  void __fastcall TMain_Form::StopTesting();
  float __fastcall TMain_Form::GetACD0Data();
  float __fastcall TMain_Form::GetACD4Data();
  float __fastcall TMain_Form::GetACD1Data();
  float __fastcall TMain_Form::GetACD5Data();
  float __fastcall TMain_Form::GetACD2Data();
  float __fastcall TMain_Form::GetACD6Data();
  void __fastcall TMain_Form::GoNIDAQmx();
  String TMain_Form::RoundValue(float delta, String value);
  void __fastcall TMain_Form::ComPortTransmitter();
  void __fastcall TMain_Form::uart_puthex_byte(unsigned char  b);
  void __fastcall TMain_Form::uart_puthex_nibble(unsigned char b);
  float __fastcall TMain_Form::average_U5V(float znachenie);
  float __fastcall TMain_Form::average_U12V(float znachenie);
  float __fastcall TMain_Form::average_I5V(float znachenie);
  float __fastcall TMain_Form::average_I12V(float znachenie);
  float __fastcall TMain_Form::average_Temp(float znachenie);
  float __fastcall TMain_Form::average_Power(float znachenie);
  void __fastcall TMain_Form::OnlySaveLog(AnsiString comment);
  void __fastcall TMain_Form::uart_puti( signed int val );
  void __fastcall TMain_Form::itoa(signed int n, unsigned char s[]);
  void __fastcall TMain_Form::Bin_to_dec (unsigned char s[], signed int dnum);
  void __fastcall TMain_Form::uart_puts(unsigned char *s );
  void __fastcall TMain_Form::SendTerminal();
  void __fastcall TMain_Form::SendControl();
  void __fastcall TMain_Form::SendTesting();
  void __fastcall TMain_Form::Fvco_OD(void);
  void __fastcall TMain_Form::Ndevider(void);
  void __fastcall TMain_Form::UpdateRegister0(void);
  void __fastcall TMain_Form::UpdateRegister1(void);
  void __fastcall TMain_Form::UpdateRegister4(void);
  void __fastcall TMain_Form::ResetSynthesizer();
  bool TMain_Form::IsValid(float min, float max, String value, String EdIzm);
  void __fastcall TMain_Form::UpdateAllRegisters(void);
  void __fastcall TMain_Form::InitBPTesting(void);
  void __fastcall TMain_Form::Delay(void);
  void __fastcall TMain_Form::ResetBPTesting(void);
  AnsiString My_Patch;
  AnsiString logFname;
  __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
