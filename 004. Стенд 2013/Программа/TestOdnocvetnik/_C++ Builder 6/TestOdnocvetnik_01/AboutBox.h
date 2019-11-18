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
#include "sPanel.hpp"
#include "sLabel.hpp"

const int NumPoints = 30;
//---------------------------------------------------------------------------
class TF_AboutBox : public TForm
{
__published:	// IDE-managed Components
  TsPanel *sPanel1;
  TButton *B_Exit;
  TLabel *Comments;
  TLabel *Copyright;
  TLabel *Version_view;
  TLabel *Device;
  TLabel *Label1;
  TLabel *ProductName;
  TsWebLabel *ST_Email;
  void __fastcall B_ExitClick(TObject *Sender);
  void __fastcall sWebLabel1Click(TObject *Sender);
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
