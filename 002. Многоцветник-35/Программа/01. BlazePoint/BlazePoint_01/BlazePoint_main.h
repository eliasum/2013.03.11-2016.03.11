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
  TTabSheet *RLS;
  TMenuItem *N1;
  TMenuItem *N2;
  TToolBar *ToolBar1;
  TToolButton *ToolButton1;
  TToolButton *TB_LoadBlp;
  TToolButton *ToolButton3;
  TToolButton *ToolButton4;
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
  TButton *B_AddBT;
  TButton *B_DeleteBT;
  TEdit *E_BT;
  TEdit *E_X;
  TEdit *E_Y;
  TEdit *E_EPR;
  TStaticText *StaticText1;
  TStaticText *StaticText2;
  TStaticText *StaticText3;
  TStaticText *StaticText4;
  TTabSheet *TabSheet1;
  TTabSheet *TabSheet2;
  TTabSheet *TabSheet3;
  void __fastcall LoadBlpClick(TObject *Sender);
  void __fastcall LVScanDblClick(TObject *Sender);
  void __fastcall SaveBlpClick(TObject *Sender);
  void __fastcall B_AddBTClick(TObject *Sender);
  void __fastcall B_DeleteBTClick(TObject *Sender);
  void __fastcall ExitClick(TObject *Sender);
private:	// User declarations
  AnsiString BlpFName;
  AnsiString SarFName;
public:		// User declarations
  AnsiString My_Patch;
  void __fastcall TMain_Form::Update_Dump();
  void __fastcall TMain_Form::Save_Dump();
  __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
