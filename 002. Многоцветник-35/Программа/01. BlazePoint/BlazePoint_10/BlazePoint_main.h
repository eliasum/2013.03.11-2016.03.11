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
  TListView *LV_Sar1;
  TGroupBox *GroupBox2;
  TStaticText *StaticText1;
  TStaticText *StaticText2;
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
  TGroupBox *GroupBox79;
  TEdit *edLCBT;
  TGroupBox *GroupBox85;
  TComboBox *cbLCnBT;
  TGroupBox *GroupBox86;
  TLabeledEdit *edLCx;
  TLabeledEdit *edLCy;
  TButton *btnReDrawLC;
  TChart *ChartLC;
  TPointSeries *Series1;
  TButton *B_Sbros;
  TLabel *Label1;
  TBitBtn *BitBtn1;
  TButton *Button1;
  TOpenDialog *OpenDialog2;
  TLabeledEdit *LE_EPR;
  TMenuItem *HelpAboutItem;
  TLabel *Label2;
  TButton *Button2;
  TMemo *M_PointIndex;
  TMemo *M_ValueIndex;
  TLabel *Label3;
  TLabel *Label4;
  void __fastcall LoadBlpClick(TObject *Sender);
  void __fastcall SaveBlpClick(TObject *Sender);
  void __fastcall ExitClick(TObject *Sender);
  void __fastcall LV_Sar1DblClick(TObject *Sender);
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
  void __fastcall B_AddSar1Click(TObject *Sender);
  void __fastcall B_DeleteSar1Click(TObject *Sender);
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
  void __fastcall ChartLCClickSeries(TCustomChart *Sender,
          TChartSeries *Series, int ValueIndex, TMouseButton Button,
          TShiftState Shift, int X, int Y);
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
  void __fastcall TMain_Form::Update_Dump_sar();
  void __fastcall TMain_Form::Save_Dump_sar();
  bool TMain_Form::IsValidInt(int min, int max, String value, String EdIzm);
  String TMain_Form::RoundValue(float delta, String value);
  void TMain_Form::DrawLC(void);
  void TMain_Form::ShowError(int ErrorNum, float Par1, float Par2, String Par3);
  void __fastcall TMain_Form::LineSeries1AfterDrawValues(TObject *Sender);
  void __fastcall TMain_Form::LineSeries1BeforeDrawValues(TObject *Sender);
  void __fastcall TMain_Form::ResetBP(void);
  __fastcall TMain_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
