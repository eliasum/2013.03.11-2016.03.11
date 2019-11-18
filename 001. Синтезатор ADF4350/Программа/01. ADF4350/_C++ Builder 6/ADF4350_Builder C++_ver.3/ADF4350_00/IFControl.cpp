//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IFControl.h"
#include "Unit1.h"
#include "Registers.h"

extern int Reg[7];
int Raf;
int Taf;
int Rfcf=0x3F;
int Tfcf=0x3F;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_IFControl *F_IFControl;
//---------------------------------------------------------------------------
__fastcall TF_IFControl::TF_IFControl(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::B_OKClick(TObject *Sender)      // нажатие на OK
{
  cancel = false;
  Close();            // закрыть форму IF Control
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::B_CancelClick(TObject *Sender)  // нажатие на Cancel
{
  Close();            // закрыть форму IF Control
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::FormShow(TObject *Sender)       // открытие F_IFControl
{
  cancel = true; // инициализация флага cancel при открытии IFControl
  // при открытии IFControl сделать копии текущих значений элементов
  InpStr1=F_IFControl->CB_Raf->ItemIndex;
  InpStr2=F_IFControl->CB_Taf->ItemIndex;
  InpStr3=F_IFControl->CB_Rfcf->ItemIndex;
  InpStr4=F_IFControl->CB_Tfcf->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::FormClose(TObject *Sender,
      TCloseAction &Action)                                   // закрытие F_IFControl
{
  if(cancel) // если была нажата кнопка cancel, тогда восстановить предыдущие значения элементов
  {
    F_IFControl->CB_Raf->ItemIndex=InpStr1;
    F_IFControl->CB_Taf->ItemIndex=InpStr2;
    F_IFControl->CB_Rfcf->ItemIndex=InpStr3;
    F_IFControl->CB_Tfcf->ItemIndex=InpStr4;

    F_IFControl->UpdateIFControl();  // обновление значения UpdateIFControl
  }
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::CB_RafChange(TObject *Sender)
{
  F_IFControl->UpdateIFControl();  // обновление значения UpdateIFControl
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::CB_TafChange(TObject *Sender)
{
  F_IFControl->UpdateIFControl();  // обновление значения UpdateIFControl
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::CB_RfcfChange(TObject *Sender)
{
  F_IFControl->UpdateIFControl();  // обновление значения UpdateIFControl
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::CB_TfcfChange(TObject *Sender)
{
  F_IFControl->UpdateIFControl();  // обновление значения UpdateIFControl
}
//---------------------------------------------------------------------------
void __fastcall TF_IFControl::UpdateIFControl(void)  // обновление значения IFControl
{
  int shift_Raf=0;
  int shift_Taf=0;
  int shift_Rfcf=0;
  int shift_Tfcf=0;

  // задание Raf
  for(int i=0; i<64; i++)
  {
    if(CB_Raf->ItemIndex==i) Raf=(0x3F-i);
  }

  // задание Taf
  for(int i=0; i<64; i++)
  {
    if(CB_Taf->ItemIndex==i) Taf=(0x3F-i);
  }

  // задание Rfcf
  for(int i=0; i<16; i++)
  {
    if(CB_Rfcf->ItemIndex==i) Rfcf=i;
  }

  // задание Tfcf
  for(int i=0; i<16; i++)
  {
    if(CB_Tfcf->ItemIndex==i) Tfcf=i;
  }

  Reg[6] &= ~0xFFFFFFFF;     // стереть предыдущее значение IFControl

  shift_Raf=(int)Raf&0x3F;   // Raf max = 63
  shift_Taf=(int)Taf&0x3F;   // Taf max = 63
  shift_Taf*=0x100;
  shift_Rfcf=(int)Rfcf&0xF;  // Rfcf max = 15
  shift_Rfcf*=0x10000;
  shift_Tfcf=(int)Tfcf&0xF;  // Tfcf max = 15
  shift_Tfcf*=0x1000000;

  Reg[6] |= shift_Raf|shift_Taf|shift_Rfcf|shift_Tfcf;  // занести новые значения

  Form9->UpdateCanvas(Reg[0], Reg[1], Reg[2],  Reg[3], Reg[4], Reg[5], Reg[6]);  // обновить канву
}
//---------------------------------------------------------------------------
