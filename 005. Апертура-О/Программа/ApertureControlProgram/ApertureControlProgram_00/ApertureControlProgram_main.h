//---------------------------------------------------------------------------

#ifndef ApertureControlProgram_mainH
#define ApertureControlProgram_mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CommPort.h"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *File;
	TMenuItem *Help;
	TMenuItem *HelpAboutProg;
	TMenuItem *HelpAboutItem;
	TToolBar *ToolBar1;
	TToolButton *ToolButton3;
	TToolButton *TB_LoadBlp;
	TToolButton *ToolButton1;
	TToolButton *TB_LoadSar;
	TToolButton *ToolButton5;
	TToolButton *TB_SaveControl;
	TToolButton *ToolButton7;
	TToolButton *TB_SaveTesting;
	TToolButton *ToolButton2;
	TToolButton *TB_LoadControl;
	TToolButton *ToolButton4;
	TToolButton *TB_LoadTesting;
	TToolButton *ToolButton6;
	TToolButton *TB_About;
	TTimer *NIDAQmxTimer;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TImageList *ImageList1;
	TCommPort *CommPort1;
	TSpeedButton *SB_OnOff;
	TGroupBox *GB_Commands;
	TLabel *Label16;
	TComboBox *CB_ComNum;
	TGroupBox *GB_AvailableCom;
	TListBox *LB_AvailableCom;
	TButton *B_AvailableCom;
	TButton *B_Send;
	TPageControl *PC_Main;
	TTabSheet *Tsh_Testing;
	TScrollBox *SB_Data2;
	TTabSheet *Tsh_Kalibr;
	TTabSheet *Sar_invisible;
	TListView *LV_Sar1;
	TListView *LV_Sar2;
	TListView *LV_Sar3;
	TListView *LV_Sar4;
	TStaticText *StaticText2;
	TStaticText *StaticText5;
	TStaticText *StaticText8;
	TStaticText *StaticText9;
	TTabSheet *DataSensors;
	TButton *B_DataOn;
	TButton *B_DataOff;
	TStaticText *StaticText1;
	TPanel *P_U5V;
	TPanel *P_U12V;
	TPanel *P_I12V;
	TPanel *P_I5V;
	TPanel *P_Temp;
	TPanel *P_Power;
	TPanel *P_1;
	TPanel *P_2;
	TPanel *P_3;
	TPanel *P_4;
	TPanel *P_5;
	TPanel *P_6;
	TLabel *L_H;
	TLabel *L_M;
	TLabel *L_S;
	TStaticText *StaticText4;
	TPanel *P_SystemTime;
	TStaticText *StaticText3;
	TPanel *P_WorkTime;
	TTimer *SystemTimer;
	TTimer *WorkTimer;
	TStatusBar *StatusBar1;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TComboBox *ComboBox1;
	TGroupBox *GroupBox2;
	TCheckBox *CheckBox2;
	TComboBox *ComboBox2;
	TGroupBox *GroupBox3;
	TCheckBox *CheckBox3;
	TComboBox *ComboBox3;
	TCheckBox *CheckBox9;
	TGroupBox *GroupBox9;
	TCheckBox *CheckBox10;
	TComboBox *ComboBox5;
	TGroupBox *GroupBox10;
	TCheckBox *CheckBox11;
	TComboBox *ComboBox6;
	TGroupBox *GroupBox13;
	TCheckBox *CheckBox14;
	TRadioButton *RadioButton9;
	TRadioButton *RadioButton10;
	TGroupBox *GroupBox14;
	TCheckBox *CheckBox15;
	TRadioButton *RadioButton11;
	TRadioButton *RadioButton12;
	TGroupBox *GB_Message;
	TEdit *E_EnterComment;
	TMemo *M_Log;
	TStaticText *StaticText6;
	TStaticText *StaticText7;
	TButton *B_Enter;
	TCheckBox *ChB_Log;
	TButton *Button1;
	TTabSheet *TabSheet1;
	TScrollBox *ScrollBox1;
	TGroupBox *GroupBox30;
	TCheckBox *CheckBox29;
	TRadioButton *RadioButton15;
	TRadioButton *RadioButton16;
	TGroupBox *GroupBox31;
	TCheckBox *CheckBox30;
	TRadioButton *RadioButton17;
	TRadioButton *RadioButton18;
	TGroupBox *GroupBox32;
	TCheckBox *CheckBox31;
	TRadioButton *RadioButton19;
	TRadioButton *RadioButton20;
	TGroupBox *GroupBox33;
	TCheckBox *CheckBox32;
	TRadioButton *RadioButton21;
	TRadioButton *RadioButton22;
	TCheckBox *CheckBox33;
	TGroupBox *GroupBox36;
	TCheckBox *CheckBox36;
	TEdit *Edit32;
	TGroupBox *GroupBox37;
	TCheckBox *CheckBox37;
	TEdit *Edit33;
	void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
