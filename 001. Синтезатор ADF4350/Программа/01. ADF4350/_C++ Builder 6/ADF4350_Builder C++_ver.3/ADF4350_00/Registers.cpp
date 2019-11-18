//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Registers.h"
#include "Unit1.h"
#include "IFControl.h"

extern int Reg[7];
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;

//перевод Int - StrBin
AnsiString Int_To_StrBin (int A)
{
  AnsiString S, S1, S2;

  if(A == 0) S = "0";

  // алгоритм записи в строку S двоичного значения A МЗР справа:
  while(A > 0)
  {
    S = S + IntToStr(A % 2); // запись значения разряда
    A = A/2;                 // переход на следующий разряд
  }

 // алгоритм записи в строку S1 двоичного значения из строки S МЗР слева:
  for (int i = 0; i < S.Length(); i++)
  {
    S1 = S1 + S[S.Length() - i];
  }

  // алгоритм добавления нулей перед СЗР до количества разрядов 32:
  for (int i = 0; i < (32 - S.Length()); i++)
  {
    S2 = S2 + 0; // запись в строку S2 '32 - S.Length()' нулей
  }
  S2 = S2 + S1;  // запись в строку S2 '32 - S.Length()' нулей и строки S1

  return S2;
}

// функция работы со свойством Canvas компонента Image1
void __fastcall TForm9::UpdateCanvas(int Reg0, int Reg1, int Reg2, int Reg3, int Reg4, int Reg5, int Reg6)
{
  Image1->Canvas->Brush->Color=clBtnFace;  // цвет кисти
  Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
  /*
  FillRect - заливка указанного прямоугольника цветом и текстурой текущей кисти.
  ClipRect - подогнать размеры выводимого изображения под размеры главной формы.
  */
  // вывод чёрного разделителя hex/bin на канву:
  Image1->Canvas->Pen->Color=clBlack;  // цвет пера
  Image1->Canvas->Pen->Width=3;        // ширина прямоугольника
  Image1->Canvas->MoveTo(232,0);       // текущая позиция пера: в верхнем крае, 232 pix от левого края
  Image1->Canvas->LineTo(232,289);     // рисует перпендикулярно прямую вниз до нижнего края

  // вывод 1-й тени на канву:
  Image1->Canvas->Pen->Color=clMoneyGreen;  // цвет пера
  Image1->Canvas->Pen->Width=31;            // ширина прямоугольника
  Image1->Canvas->MoveTo(156,0);            // текущая позиция пера: в верхнем крае, 156 pix от левого края
  Image1->Canvas->LineTo(156,289);          // рисует перпендикулярно прямую вниз до нижнего края

  // вывод 2-й тени на канву:
  Image1->Canvas->Pen->Color=clMoneyGreen;  // цвет пера
  Image1->Canvas->Pen->Width=31;            // ширина прямоугольника
  Image1->Canvas->MoveTo(276,0);            // текущая позиция пера: в верхнем крае, 276 pix от левого края
  Image1->Canvas->LineTo(276,289);          // рисует перпендикулярно прямую вниз до нижнего края

  // вывод 3-й тени на канву:
  Image1->Canvas->Pen->Color=clMoneyGreen;  // цвет пера
  Image1->Canvas->Pen->Width=31;            // ширина прямоугольника
  Image1->Canvas->MoveTo(340,0);            // текущая позиция пера: в верхнем крае, 340 pix от левого края
  Image1->Canvas->LineTo(340,289);          // рисует перпендикулярно прямую вниз до нижнего края

  // вывод 4-й тени на канву:
  Image1->Canvas->Pen->Color=clMoneyGreen;  // цвет пера
  Image1->Canvas->Pen->Width=31;            // ширина прямоугольника
  Image1->Canvas->MoveTo(404,0);            // текущая позиция пера: в верхнем крае, 404 pix от левого края
  Image1->Canvas->LineTo(404,289);          // рисует перпендикулярно прямую вниз до нижнего края

  // вывод 5-й тени на канву:
  Image1->Canvas->Pen->Color=clMoneyGreen;  // цвет пера
  Image1->Canvas->Pen->Width=31;            // ширина прямоугольника
  Image1->Canvas->MoveTo(468,0);            // текущая позиция пера: в верхнем крае, 468 pix от левого края
  Image1->Canvas->LineTo(468,289);          // рисует перпендикулярно прямую вниз до нижнего края

  // вывод текста на канву:
  Image1->Canvas->Font->Name="Lucida Console";  // название шрифта
  Image1->Canvas->Font->Size=8;                 // размер шрифта
  Image1->Canvas->Brush->Style=bsClear;         // стиль кисти - очистить около текста

  Image1->Canvas->TextOut(20,20 ,"Register 0");            // вывод названий регистров
  Image1->Canvas->TextOut(20,60 ,"Register 1");
  Image1->Canvas->TextOut(20,100,"Register 2");
  Image1->Canvas->TextOut(20,140,"Register 3");
  Image1->Canvas->TextOut(20,180,"Register 4");
  Image1->Canvas->TextOut(20,220,"Register 5");
  Image1->Canvas->TextOut(20,260,"IF Control");

  Image1->Canvas->TextOut(140,20 ,IntToHex(Reg[0], 8));    // вывод hex-значений регистров
  Image1->Canvas->TextOut(140,60 ,IntToHex(Reg[1], 8));
  Image1->Canvas->TextOut(140,100,IntToHex(Reg[2], 8));
  Image1->Canvas->TextOut(140,140,IntToHex(Reg[3], 8));
  Image1->Canvas->TextOut(140,180,IntToHex(Reg[4], 8));
  Image1->Canvas->TextOut(140,220,IntToHex(Reg[5], 8));
  Image1->Canvas->TextOut(140,260,IntToHex(Reg[6], 8));

  Image1->Canvas->TextOut(260,20 ,Int_To_StrBin(Reg[0]));  // вывод bin-значений регистров
  Image1->Canvas->TextOut(260,60 ,Int_To_StrBin(Reg[1]));
  Image1->Canvas->TextOut(260,100,Int_To_StrBin(Reg[2]));
  Image1->Canvas->TextOut(260,140,Int_To_StrBin(Reg[3]));
  Image1->Canvas->TextOut(260,180,Int_To_StrBin(Reg[4]));
  Image1->Canvas->TextOut(260,220,Int_To_StrBin(Reg[5]));
  Image1->Canvas->TextOut(260,260,Int_To_StrBin(Reg[6]));
}
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
  : TForm(Owner)
{
  // начальная инициализация:
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A5003C;
  Reg[5]=0x00580005;
  Reg[6]=0x00003F3F;

  UpdateCanvas(Reg[0], Reg[1], Reg[2],  Reg[3], Reg[4], Reg[5], Reg[6]);
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------





