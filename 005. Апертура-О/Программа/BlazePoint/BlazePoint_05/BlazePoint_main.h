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
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "Math.hpp" // Log10 � RoundTo
#include <jpeg.hpp>
#include "inifiles.hpp"
#include <Graphics.hpp>
//---------------------------------------------------------------------------
// �������� ������ �����
class TMain_Form : public TForm  // ����� TMain_Form ��������� ����� TForm ��� public
{
__published:	// IDE-managed Components
// ����������� �� ����� ����������
  TMainMenu *MainMenu;
  TMenuItem *File;
  TMenuItem *Help;
  TMenuItem *HelpAboutProg;
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
  TToolButton *TB_SaveSar;
  TToolButton *ToolButton9;
  TToolButton *TB_Exit;
  TToolButton *ToolButton11;
  TToolButton *TB_About;
  TGroupBox *GroupBox79;
  TEdit *edLCBT;
  TGroupBox *GroupBox85;
  TComboBox *cbLCnBT;
  TGroupBox *GroupBox86;
  TLabeledEdit *edLCx;
  TLabeledEdit *edLCy;
  TChart *ChartLC;
  TPointSeries *Series1;
  TButton *B_Sbros;
  TLabel *Label1;
  TBitBtn *BitBtn1;
  TButton *Button1;
  TOpenDialog *OpenDialog2;
  TLabeledEdit *LE_EPR;
  TMenuItem *HelpAboutItem;
  TPointSeries *Series2;
  TBitBtn *BitBtn2;
  TSaveDialog *SaveDialog2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TImage *Image;
	TLabeledEdit *LE_V;
	TLabeledEdit *LE_f;
	TLabeledEdit *LE_Fi;
	TLabeledEdit *LE_D;
	TPopupMenu *PopupMenu1;
	TMemo *Memo1;
	TButton *B_dat;
	TImage *Image2;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label15;
	TLabel *Label16;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
  void __fastcall LoadBlpClick(TObject *Sender);
  void __fastcall SaveBlpClick(TObject *Sender);
  void __fastcall ExitClick(TObject *Sender);
  void __fastcall LoadSarClick(TObject *Sender);
  void __fastcall SaveSarClick(TObject *Sender);
  void __fastcall edLCBTExit(TObject *Sender);
  void __fastcall PIntKeyPress(TObject *Sender, char &Key);
  void __fastcall cbLCnBTChange(TObject *Sender);
  void __fastcall edLCxChange(TObject *Sender);
  void __fastcall edLCxExit(TObject *Sender);
  void __fastcall edLCyChange(TObject *Sender);
  void __fastcall edLCyExit(TObject *Sender);
  void __fastcall btnReDrawLCClick(TObject *Sender);
  void __fastcall B_SbrosClick(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall ChartLCMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
  void __fastcall ChartLCDblClick(TObject *Sender);
  void __fastcall edLCBTChange(TObject *Sender);
  void __fastcall edLCBTClick(TObject *Sender);
  void __fastcall BitBtn1Click(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall ChartLCAfterDraw(TObject *Sender);
  void __fastcall LE_EPRChange(TObject *Sender);
  void __fastcall LE_EPRExit(TObject *Sender);
  void __fastcall HelpAboutProgClick(TObject *Sender);
  void __fastcall HelpAboutItemClick(TObject *Sender);
  void __fastcall ChartLCZoom(TObject *Sender);
  void __fastcall ChartLCUndoZoom(TObject *Sender);
  void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall LE_VKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall LE_fExit(TObject *Sender);
	void __fastcall B_datClick(TObject *Sender);
	void __fastcall ChartLCMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ChartLCMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
  AnsiString BlpFName;
  AnsiString SarFName;
  int OldX;
  int OldY;
  TColor CrossHairColor;
  TPenStyle CrossHairStyle;
  void DrawCross(int AX, int AY);
  double Percent;
public:		// User declarations
  AnsiString My_Patch;
  bool TMain_Form::IsValidInt(int min, int max, String value, String EdIzm);
  String TMain_Form::RoundValue(float delta, float fvalue);
  void TMain_Form::DrawLC(void);
  void TMain_Form::ShowError(int ErrorNum, float Par1, float Par2, String Par3);
  void __fastcall TMain_Form::LineSeries1AfterDrawValues(TObject *Sender);
  void __fastcall TMain_Form::LineSeries1BeforeDrawValues(TObject *Sender);
  void __fastcall TMain_Form::ResetBP(void);
  void TMain_Form::DrawHighlight(void);
  void __fastcall TMain_Form::Palette(int index);
  __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
