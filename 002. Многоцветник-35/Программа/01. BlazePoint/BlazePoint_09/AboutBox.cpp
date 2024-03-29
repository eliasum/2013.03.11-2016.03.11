//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutBox.h"
#include "BlazePoint_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_AboutBox *F_AboutBox;
//---------------------------------------------------------------------------
__fastcall TF_AboutBox::TF_AboutBox(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::ST_EmailClick(TObject *Sender) // �� �������
{
  // ��������� ����������� �� ����� eliasum@yandex.ru:
  AnsiString EmailValueStr;
  EmailValueStr = "mailto:" + ST_Email->Caption + "?subject=Theme";
  ShellExecute(Handle,NULL, EmailValueStr.c_str(), NULL,NULL,SW_SHOWNORMAL);

  ST_Email->Font->Color=clPurple;                   // �������� ���� �� ���������
  ST_Email->Font->Style=TFontStyles()<<fsUnderline; // ������� �������������
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::ST_EmailMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) // ��� �������
{
  ST_Email->Font->Color=clRed;                      // �������� ���� �� �������
  ST_Email->Font->Style=TFontStyles()>>fsUnderline; // ������ �������������
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::ST_EmailMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) // ���������� �������
{
  ST_Email->Font->Color=clPurple;                   // �������� ���� �� ���������
  ST_Email->Font->Style=TFontStyles()<<fsUnderline; // ������� �������������
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::B_ExitClick(TObject *Sender)
{
  Close();               // ������� �����
}
//---------------------------------------------------------------------------
void __fastcall TF_AboutBox::FormCreate(TObject *Sender)
{
  PosChart1 = -1; // starting position of vertical divider
  PosChart4 = NumPoints / 2;

  // Generate some random points
  dynamic_cast<TCircledSeries*>(PieSeries1)->FillSampleValues(8);
}
//---------------------------------------------------------------------------

void __fastcall TF_AboutBox::FormResize(TObject *Sender)
{
  // Equally resize the panels to center charts
  Chart3->Height = ClientHeight / 2;
}
//---------------------------------------------------------------------------

void __fastcall TF_AboutBox::Timer1Timer(TObject *Sender)
{
  PieSeries1->RotationAngle = (PieSeries1->RotationAngle+1) % 359;  // rotate pie
}
//---------------------------------------------------------------------------
// This procedure changes the Series values every second
void TF_AboutBox::RefreshMonitorChart(TChart* Chart, int &PosChart)
{
  double LastValueWas;
  PosChart++;
  if (PosChart >= NumPoints)
    PosChart = 0;
  for (int t = 0;t<Chart->SeriesCount()-1;t++) {
    if (PosChart == 0)      {
      Chart->LeftAxis->Automatic = true;
      Chart->LeftAxis->SetMinMax(
        Chart->MinYValue(Chart->LeftAxis),Chart->MaxYValue(Chart->LeftAxis));
      LastValueWas = Chart->Series[t]->YValues->Last();
    }
    else
      LastValueWas = Chart->Series[t]->YValue[PosChart-1];

    // change the value for a new random one
    Chart->Series[t]->YValue[PosChart] =
      LastValueWas+random(ChartSamplesMax)- (ChartSamplesMax / 2);
  }
}
//---------------------------------------------------------------------------
