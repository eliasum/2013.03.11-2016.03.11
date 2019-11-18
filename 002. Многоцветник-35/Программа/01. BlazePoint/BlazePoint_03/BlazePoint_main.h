//---------------------------------------------------------------------------

#ifndef BlazePoint_mainH
#define BlazePoint_mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
// описание класса формы
class TMain_Form : public TForm  // класс TMain_Form наследует класс TForm как public
{
__published:	// IDE-managed Components
// размещённые на форме компоненты
  TMainMenu *MainMenu;
  TMenuItem *File;
  TMenuItem *Help;
  TMenuItem *HelpAboutItem;
  TMenuItem *LoadBlp;
  TMenuItem *LoadSar;
  TMenuItem *SaveBlp;
  TMenuItem *SaveSar;
  TMenuItem *Exit;
  TStatusBar *StatusBar;
  TOpenDialog *OpenDialog;
  TSaveDialog *SaveDialog;
  TOpenDialog *OpenDialog1;
  TSaveDialog *SaveDialog1;
  TImageList *ImageList1;
  TPageControl *PC_Main;
  TTabSheet *BT;
  TTabSheet *RLS1;
  TMenuItem *N1;
  TMenuItem *N2;
  TToolBar *ToolBar1;
  TToolButton *ToolButton1;
  TToolButton *TB_LoadBlp;
  TToolButton *ToolButton3;
  TToolButton *TB_LoadSar;
  TToolButton *ToolButton5;
  TToolButton *TB_SaveBlp;
  TToolButton *ToolButton7;
  TToolButton *ToolButton8;
  TToolButton *ToolButton9;
  TToolButton *TB_Exit;
  TToolButton *ToolButton11;
  TToolButton *ToolButton12;
  TListView *LVScan;
  TGroupBox *GroupBox1;
  TListView *LV_Sar1;
  TGroupBox *GroupBox2;
  TStaticText *StaticText1;
  TStaticText *StaticText2;
  TBitBtn *B_DeleteBT;
  TBitBtn *B_AddBT;
  TBitBtn *B_AddSar1;
  TBitBtn *B_DeleteSar1;
  TGroupBox *GroupBox3;
  TBitBtn *B_AddSar2;
  TBitBtn *B_DeleteSar2;
  TListView *LV_Sar2;
  TStaticText *StaticText3;
  TListView *LV_Sar3;
  TStaticText *StaticText4;
  TGroupBox *GroupBox4;
  TBitBtn *B_AddSar3;
  TBitBtn *B_DeleteSar3;
  TGroupBox *GroupBox5;
  TBitBtn *B_AddSar4;
  TBitBtn *B_DeleteSar4;
  TListView *LV_Sar4;
  void __fastcall LoadBlpClick(TObject *Sender);
  void __fastcall LVScanDblClick(TObject *Sender);
  void __fastcall SaveBlpClick(TObject *Sender);
  void __fastcall ExitClick(TObject *Sender);
  void __fastcall LV_Sar1DblClick(TObject *Sender);
  void __fastcall B_AddBTClick(TObject *Sender);
  void __fastcall B_DeleteBTClick(TObject *Sender);
  void __fastcall B_AddSar1Click(TObject *Sender);
  void __fastcall B_DeleteSar1Click(TObject *Sender);
  void __fastcall B_AddSar2Click(TObject *Sender);
  void __fastcall B_DeleteSar2Click(TObject *Sender);
  void __fastcall LV_Sar2DblClick(TObject *Sender);
  void __fastcall LoadSarClick(TObject *Sender);
  void __fastcall SaveSarClick(TObject *Sender);
  void __fastcall B_AddSar3Click(TObject *Sender);
  void __fastcall B_AddSar4Click(TObject *Sender);
  void __fastcall B_DeleteSar3Click(TObject *Sender);
  void __fastcall B_DeleteSar4Click(TObject *Sender);
  void __fastcall LV_Sar3DblClick(TObject *Sender);
  void __fastcall LV_Sar4DblClick(TObject *Sender);
  void __fastcall HelpAboutItemClick(TObject *Sender);
private:	// User declarations
  AnsiString BlpFName;
  AnsiString SarFName;
public:		// User declarations
  AnsiString My_Patch;
  void __fastcall TMain_Form::Update_Dump_blp();
  void __fastcall TMain_Form::Save_Dump_blp();
  void __fastcall TMain_Form::Update_Dump_sar();
  void __fastcall TMain_Form::Save_Dump_sar();
  __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
