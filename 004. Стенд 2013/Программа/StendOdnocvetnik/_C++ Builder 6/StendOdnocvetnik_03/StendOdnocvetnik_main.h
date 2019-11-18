//---------------------------------------------------------------------------

#ifndef StendOdnocvetnik_mainH
#define StendOdnocvetnik_mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include "inifiles.hpp" // הכÿ פאיכמג ini
#include "Math.hpp"     // Log10(delta); RoundTo(temp,temp1);
#include <Math.h>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GB_Channel1;
  TLabeledEdit *LE_U_IPO1;
  TStaticText *StaticText1;
  TLabeledEdit *LE_I_IPO1;
  TStaticText *StaticText2;
  TLabeledEdit *LE_U_IPP1;
  TStaticText *StaticText3;
  TLabeledEdit *LE_I_IPP1;
  TStaticText *StaticText4;
  TLabeledEdit *LE_U_IMP1;
  TStaticText *StaticText5;
  TLabeledEdit *LE_I_IMP1;
  TStaticText *StaticText6;
  TPanel *P_Mode1;
  TStaticText *StaticText7;
  TPanel *P_Protection1;
  TStaticText *StaticText8;
  TGroupBox *GB_Channel2;
  TLabeledEdit *LE_U_IPO2;
  TStaticText *StaticText10;
  TLabeledEdit *LE_I_IPO2;
  TStaticText *StaticText11;
  TLabeledEdit *LE_U_IPP2;
  TStaticText *StaticText12;
  TLabeledEdit *LE_I_IPP2;
  TStaticText *StaticText13;
  TLabeledEdit *LE_U_IMP2;
  TStaticText *StaticText14;
  TLabeledEdit *LE_I_IMP2;
  TStaticText *StaticText15;
  TPanel *P_Mode2;
  TStaticText *StaticText16;
  TPanel *P_Protection2;
  TStaticText *StaticText17;
  TGroupBox *GB_Channel3;
  TLabeledEdit *LE_U_IPO3;
  TStaticText *StaticText19;
  TLabeledEdit *LE_I_IPO3;
  TStaticText *StaticText20;
  TLabeledEdit *LE_U_IPP3;
  TStaticText *StaticText21;
  TLabeledEdit *LE_I_IPP3;
  TStaticText *StaticText22;
  TLabeledEdit *LE_U_IMP3;
  TStaticText *StaticText23;
  TLabeledEdit *LE_I_IMP3;
  TStaticText *StaticText24;
  TPanel *P_Mode3;
  TStaticText *StaticText25;
  TPanel *P_Protection3;
  TStaticText *StaticText26;
  TGroupBox *GB_Channel4;
  TLabeledEdit *LE_U_IPO4;
  TStaticText *StaticText28;
  TLabeledEdit *LE_I_IPO4;
  TStaticText *StaticText29;
  TLabeledEdit *LE_U_IPP4;
  TStaticText *StaticText30;
  TLabeledEdit *LE_I_IPP4;
  TStaticText *StaticText31;
  TLabeledEdit *LE_U_IMP4;
  TStaticText *StaticText32;
  TLabeledEdit *LE_I_IMP4;
  TStaticText *StaticText33;
  TPanel *P_Mode4;
  TStaticText *StaticText34;
  TPanel *P_Protection4;
  TStaticText *StaticText35;
  TStaticText *ST_Enterprise;
  TStaticText *StaticText38;
  TButton *B_Go;
  TButton *B_Stop;
  TLabeledEdit *LE_Cycles;
  TStaticText *StaticText39;
  TMemo *M_Log;
  TButton *Button2;
  TMemo *Memo1;
  TTimer *T_Checkm6V;
  TRadioButton *RB_Selected1;
  TRadioButton *RB_Selected2;
  TRadioButton *RB_Selected3;
  TRadioButton *RB_Selected4;
  TMainMenu *MainMenu;
  TMenuItem *File;
  TMenuItem *LoadStend;
  TMenuItem *N3;
  TMenuItem *Exit;
  TMenuItem *Help;
  TMenuItem *HelpAboutItem;
  TToolBar *ToolBar1;
  TToolButton *ToolButton4;
  TToolButton *TB_LoadStend;
  TToolButton *ToolButton6;
  TToolButton *ToolButton7;
  TToolButton *TB_HelpAboutItem;
  TImageList *ImageList1;
  TStatusBar *StatusBar1;
  TOpenDialog *OpenDialog1;
  TPanel *P_Selected1;
  TPanel *P_Selected2;
  TPanel *P_Selected3;
  TPanel *P_Selected4;
  TTimer *T_Checkp6V;
  TTimer *T_Checkp20V;
  TTimer *T_Work;
  TLabel *L_Danger;
  TTimer *T_Log;
  TStaticText *StaticText40;
  TPanel *P_Overheat1;
  TStaticText *StaticText9;
  TPanel *P_Overheat2;
  TStaticText *StaticText18;
  TPanel *P_Overheat3;
  TStaticText *StaticText27;
  TPanel *P_Overheat4;
  TTimer *T_Overheat;
  TTimer *T_Pause;
  TTimer *T_Danger;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall B_GoClick(TObject *Sender);
  void __fastcall B_StopClick(TObject *Sender);
  void __fastcall RB_Selected1Click(TObject *Sender);
  void __fastcall RB_Selected2Click(TObject *Sender);
  void __fastcall RB_Selected3Click(TObject *Sender);
  void __fastcall RB_Selected4Click(TObject *Sender);
  void __fastcall TB_LoadStendClick(TObject *Sender);
  void __fastcall TB_HelpAboutItemClick(TObject *Sender);
  void __fastcall T_Checkm6VTimer(TObject *Sender);
  void __fastcall T_Checkp6VTimer(TObject *Sender);
  void __fastcall T_Checkp20VTimer(TObject *Sender);
  void __fastcall T_WorkTimer(TObject *Sender);
  void __fastcall T_LogTimer(TObject *Sender);
  void __fastcall T_OverheatTimer(TObject *Sender);
  void __fastcall T_PauseTimer(TObject *Sender);
  void __fastcall T_DangerTimer(TObject *Sender);
  void __fastcall ExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  AnsiString My_Patch;
  AnsiString logFname;
  void __fastcall TMainForm::AddSaveLog(AnsiString comment);
  void __fastcall TMainForm::Starting(void);
  void __fastcall TMainForm::Verification(void);
  void __fastcall TMainForm::Work(void);
  void __fastcall TMainForm::Pause(void);
  bool __fastcall TMainForm::ReadDigChan(const char *Config, char *DigPort);
  bool __fastcall TMainForm::WriteDigChan(const char *Config, char *DigPort);
  float __fastcall TMainForm::ReadAnalogChan(const char *Config);
  void __fastcall TMainForm::Delay(void);
  void __fastcall TMainForm::Checkm6V(void);
  void __fastcall TMainForm::Checkp6V(void);
  void __fastcall TMainForm::Checkp20V(void);
  String TMainForm::RoundValue(float delta, String value);
  void __fastcall TMainForm::PowerOff(void);
  void __fastcall TMainForm::PowerOffWithDelay(void);
  void __fastcall TMainForm::Powerm6VOff(void);  
  void __fastcall TMainForm::Powerp6VOff(void);
  void __fastcall TMainForm::Powerp20VOff(void);
  void __fastcall TMainForm::NominalNumber(AnsiString *Nominal);
  bool __fastcall TMainForm::CheckOfChannel(const char *Config, TLabeledEdit *Parameter,
                  double minAllow, double maxAllow, double Nom, const char *Message,
                  TPanel *Protection, void __fastcall (TMainForm::*pm)(void), int koef);
  void __fastcall TMainForm::Overheat(unsigned char line, TPanel *P_Overheat);
  bool __fastcall TMainForm::LoadChannel(AnsiString *Nominal, bool &greenflag, TPanel *Selected,
                  const char *NoMessage, double *FNominal, const char *YesMessage);
  __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
