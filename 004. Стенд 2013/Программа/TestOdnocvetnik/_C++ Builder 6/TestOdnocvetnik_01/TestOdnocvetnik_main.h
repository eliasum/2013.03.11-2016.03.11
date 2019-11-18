//---------------------------------------------------------------------------

#ifndef TestOdnocvetnik_mainH
#define TestOdnocvetnik_mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sSkinManager.hpp"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include "sColorSelect.hpp"
#include "sComboEdit.hpp"
#include "sCurrEdit.hpp"
#include "sCurrencyEdit.hpp"
#include "sCustomComboEdit.hpp"
#include "sEdit.hpp"
#include "sMaskEdit.hpp"
#include "sSpeedButton.hpp"
#include "sSpinEdit.hpp"
#include <Buttons.hpp>
#include <Mask.hpp>
#include "sLabel.hpp"
#include "sToolBar.hpp"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
  TsSkinManager *sSkinManager1;
  TMainMenu *MainMenu;
  TMenuItem *File;
  TMenuItem *SaveStend;
  TMenuItem *N2;
  TMenuItem *LoadStend;
  TMenuItem *N3;
  TMenuItem *Exit;
  TMenuItem *Help;
  TMenuItem *HelpAboutItem;
  TImageList *ImageList1;
  TOpenDialog *OpenDialog1;
  TSaveDialog *SaveDialog1;
  TsEdit *LE_Inomm6V;
  TsToolBar *sToolBar1;
  TToolButton *ToolButton2;
  TToolButton *TB_SaveStend;
  TToolButton *ToolButton8;
  TToolButton *ToolButton9;
  TToolButton *TB_LoadStend;
  TToolButton *ToolButton11;
  TToolButton *ToolButton12;
  TToolButton *TB_HelpAboutItem;
  TLabel *Label1;
  TLabel *Label2;
  TsEdit *LE_Unomm6V;
  TsEdit *LE_Inomp6V;
  TLabel *Label3;
  TsEdit *LE_Unomp6V;
  TLabel *Label4;
  TsEdit *LE_Inomp20V;
  TLabel *Label5;
  TsEdit *LE_Unomp20V;
  TLabel *Label6;
  TsEdit *LE_Tpause;
  TLabel *Label7;
  TsEdit *LE_Twork;
  TLabel *Label8;
  void __fastcall TB_HelpAboutItemClick(TObject *Sender);
  void __fastcall ExitClick(TObject *Sender);
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
  void __fastcall TMainForm::DefaultValue(TsEdit *Parameter);
  __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
