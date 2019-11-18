//---------------------------------------------------------------------------

#ifndef AboutBoxH
#define AboutBoxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>

const int NumPoints = 30;
//---------------------------------------------------------------------------
class TF_AboutBox : public TForm
{
__published:	// IDE-managed Components
  TPanel *Panel2;
  TLabel *ProductName;
  TLabel *Version_view;
  TLabel *Copyright;
  TLabel *Comments;
  TLabel *Device;
  TStaticText *ST_Email;
  TChart *Chart3;
  TPieSeries *PieSeries1;
  TButton *B_Exit;
  TTimer *Timer1;
  TLabel *Label1;
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall B_ExitClick(TObject *Sender);
  void __fastcall ST_EmailClick(TObject *Sender);
  void __fastcall ST_EmailMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ST_EmailMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
  int PosChart1;
  int PosChart4; // used to draw vertical lines over charts
  void RefreshMonitorChart(TChart* Chart, int &PosChart);
public:		// User declarations
  __fastcall TF_AboutBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_AboutBox *F_AboutBox;
//---------------------------------------------------------------------------
#endif
