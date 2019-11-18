//---------------------------------------------------------------------------

#ifndef TestOdnocvetnik_mainH
#define TestOdnocvetnik_mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include "inifiles.hpp"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
  TMainMenu *MainMenu;
  TMenuItem *File;
  TMenuItem *SaveStend;
  TMenuItem *N2;
  TMenuItem *LoadStend;
  TMenuItem *N3;
  TMenuItem *Exit;
  TMenuItem *Help;
  TMenuItem *HelpAboutItem;
  TLabeledEdit *LE_Inomm6V;
  TLabeledEdit *LE_Unomm6V;
  TLabeledEdit *LE_Inomp6V;
  TLabeledEdit *LE_Unomp6V;
  TLabeledEdit *LE_Inomp20V;
  TLabeledEdit *LE_Unomp20V;
  TLabeledEdit *LE_Tpause;
  TLabeledEdit *LE_Twork;
  TToolBar *ToolBar1;
  TToolButton *ToolButton1;
  TToolButton *TB_SaveStend;
  TToolButton *ToolButton3;
  TToolButton *ToolButton4;
  TToolButton *TB_LoadStend;
  TToolButton *ToolButton6;
  TToolButton *ToolButton7;
  TToolButton *TB_HelpAboutItem;
  TImageList *ImageList1;
  TOpenDialog *OpenDialog1;
  TSaveDialog *SaveDialog1;
  void __fastcall ExitClick(TObject *Sender);
  void __fastcall HelpAboutItemClick(TObject *Sender);
  void __fastcall TB_HelpAboutItemClick(TObject *Sender);
  void __fastcall TB_SaveStendClick(TObject *Sender);
  void __fastcall TB_LoadStendClick(TObject *Sender);
  void __fastcall LE_Inomm6VKeyPress(TObject *Sender, char &Key);
  void __fastcall LE_TpauseKeyPress(TObject *Sender, char &Key);
  void __fastcall LE_Inomm6VChange(TObject *Sender);
  void __fastcall LE_Unomm6VChange(TObject *Sender);
  void __fastcall LE_Inomp6VChange(TObject *Sender);
  void __fastcall LE_Unomp6VChange(TObject *Sender);
  void __fastcall LE_Inomp20VChange(TObject *Sender);
  void __fastcall LE_Unomp20VChange(TObject *Sender);
  void __fastcall LE_TpauseChange(TObject *Sender);
  void __fastcall LE_TworkChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
  AnsiString My_Patch;
  void __fastcall TMainForm::DefaultValue(TLabeledEdit *Parameter);
  __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
