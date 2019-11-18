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
  TTabSheet *TabSheet1;
  TTabSheet *TabSheet2;
  TMenuItem *N1;
  TMenuItem *N2;
  TToolBar *ToolBar1;
  TToolButton *ToolButton1;
  TToolButton *ToolButton2;
  TToolButton *ToolButton3;
  TToolButton *ToolButton4;
  TToolButton *ToolButton5;
  TToolButton *ToolButton6;
  TToolButton *ToolButton7;
  TToolButton *ToolButton8;
  TToolButton *ToolButton9;
  TToolButton *ToolButton10;
  TToolButton *ToolButton11;
  TToolButton *ToolButton12;
  TListView *LVScan;
  TEdit *Edit1;
  TButton *Button1;
  TButton *Button2;
  TButton *Button3;
  TButton *Button4;
  TEdit *Edit2;
  TEdit *Edit3;
  TEdit *Edit4;
  TButton *Button5;
  void __fastcall SaveBlpClick(TObject *Sender);
  void __fastcall LoadBlpClick(TObject *Sender);
  void __fastcall LVScanDblClick(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  AnsiString My_Patch;
  AnsiString nomer;
  __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
