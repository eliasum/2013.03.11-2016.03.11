//---------------------------------------------------------------------------

#ifndef RegistersH
#define RegistersH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
  TButton *Button1;
  TImage *Image1;
  void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm9(TComponent* Owner);
  void __fastcall TForm9::UpdateCanvas(int Reg0, int Reg1, int Reg2, int Reg3, int Reg4, int Reg5, int Reg6);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
