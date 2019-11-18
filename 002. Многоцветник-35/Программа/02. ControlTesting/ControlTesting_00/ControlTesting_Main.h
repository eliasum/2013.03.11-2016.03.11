//---------------------------------------------------------------------------

#ifndef ControlTesting_MainH
#define ControlTesting_MainH
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
//---------------------------------------------------------------------------
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GB_Mode;
  TRadioButton *RB_Control;
  TRadioButton *RB_Testing;
  TStaticText *StaticText1;
  TPanel *Panel1;
  TPanel *Panel2;
  TPanel *Panel3;
  TPanel *Panel4;
  TGroupBox *GroupBox2;
  TButton *btnNew;
  TButton *btnSave;
  TButton *btnLoad;
  TButton *btnSaveAs;
  TGroupBox *GroupBox3;
  TButton *Button1;
  TButton *Button3;
  TPanel *P_SystemTime;
  TPanel *P_WorkTime;
  TSpeedButton *SB_OnOff;
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
  TTabSheet *BT;
  TListView *LVScan;
  TGroupBox *GroupBox1;
  TBitBtn *B_AddBT;
  TBitBtn *B_DeleteBT;
  TTabSheet *RLS1;
  TListView *LV_Sar1;
  TGroupBox *GroupBox4;
  TBitBtn *B_AddSar1;
  TBitBtn *B_DeleteSar1;
  TStaticText *StaticText2;
  TStaticText *StaticText5;
  TGroupBox *GroupBox5;
  TBitBtn *B_AddSar2;
  TBitBtn *B_DeleteSar2;
  TListView *LV_Sar2;
  TStaticText *StaticText8;
  TListView *LV_Sar3;
  TStaticText *StaticText9;
  TGroupBox *GroupBox6;
  TBitBtn *B_AddSar3;
  TBitBtn *B_DeleteSar3;
  TGroupBox *GroupBox7;
  TBitBtn *B_AddSar4;
  TBitBtn *B_DeleteSar4;
  TListView *LV_Sar4;
  TTabSheet *TabSheet1;
  TTabSheet *TabSheet2;
  TScrollBox *ScrollBox1;
  TButton *Button2;
  TButton *Button4;
  TButton *Button5;
  TButton *Button6;
  TButton *Button7;
  TButton *Button8;
  TToolBar *ToolBar1;
  TToolButton *ToolButton1;
  TToolButton *TB_LoadBlp;
  TToolButton *ToolButton3;
  TToolButton *TB_LoadSar;
  TToolButton *ToolButton5;
  TToolButton *TB_SaveControl;
  TToolButton *ToolButton7;
  TToolButton *TB_SaveTesting;
  TToolButton *ToolButton9;
  TToolButton *TB_Exit;
  TToolButton *ToolButton11;
  TToolButton *BT_About;
  TOpenDialog *OpenDialog;
  TOpenDialog *OpenDialog1;
  TImageList *ImageList1;
  TToolButton *ToolButton2;
  TMainMenu *MainMenu1;
  TMenuItem *File;
  TStatusBar *StatusBar1;
  void __fastcall SB_OnOffClick(TObject *Sender);
  void __fastcall SystemTimerTimer(TObject *Sender);
  void __fastcall WorkTimerTimer(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall B_EnterClick(TObject *Sender);
  void __fastcall TB_LoadBlpClick(TObject *Sender);
  void __fastcall TB_LoadSarClick(TObject *Sender);
  void __fastcall B_AddBTClick(TObject *Sender);
  void __fastcall B_DeleteBTClick(TObject *Sender);
  void __fastcall B_AddSar1Click(TObject *Sender);  
  void __fastcall B_DeleteSar1Click(TObject *Sender);
  void __fastcall B_AddSar2Click(TObject *Sender);
  void __fastcall B_DeleteSar2Click(TObject *Sender);
  void __fastcall B_AddSar3Click(TObject *Sender);
  void __fastcall B_AddSar4Click(TObject *Sender);
  void __fastcall B_DeleteSar3Click(TObject *Sender);
  void __fastcall B_DeleteSar4Click(TObject *Sender);
  void __fastcall TB_ExitClick(TObject *Sender);
  void __fastcall RB_ControlClick(TObject *Sender);
  void __fastcall RB_TestingClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall LVScanDblClick(TObject *Sender);
  void __fastcall LV_Sar1DblClick(TObject *Sender);
  void __fastcall LV_Sar2DblClick(TObject *Sender);
  void __fastcall LV_Sar3DblClick(TObject *Sender);
  void __fastcall LV_Sar4DblClick(TObject *Sender);
private:	// User declarations
  AnsiString BlpFName;
  AnsiString SarFName;
public:		// User declarations
  void __fastcall TMain_Form::AddSaveLog(AnsiString comment);
  void __fastcall TMain_Form::Update_Dump_blp();
  void __fastcall TMain_Form::Update_Dump_sar();
  AnsiString My_Patch;
  AnsiString logFname;
  __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
