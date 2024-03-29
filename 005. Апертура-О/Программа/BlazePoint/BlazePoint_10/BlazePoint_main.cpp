﻿// файл реализации формы Main_Form
//---------------------------------------------------------------------------
// директивы препроцессора #include подключают в данный файл тексты указанных в них файлов
#include <vcl.h>  // объявления, используемые в библиотеке визуальных компонентов С++Builder
#pragma hdrstop   // конец списка общих заголовочных файлов для всех модулей проекта

#include "BlazePoint_main.h"
#include "BT.h"
#include "Sar1.h"
#include "Sar2.h"
#include "Sar3.h"
#include "Sar4.h"
#include "AboutBox.h"
#include "Error.h"
#include "Help.h"
#include <iostream>
/*
iostream — заголовочный файл с классами, функциями и переменными для организации ввода-вывода
в языке программирования C++. Он включён в стандартную библиотеку C++. Название образовано от
Input/Output Stream («поток ввода-вывода»). В языке C++ и его предшественнике, языке
программирования Си, нет встроенной поддержки ввода-вывода, вместо этого используется библиотека
функций. iostream управляет вводом-выводом, как и stdio.h в Си. iostream использует объекты cin,
cout, cerr и clog для передачи информации в и из стандартных потоков ввода, вывода, ошибок
(без буферизации) и ошибок (с буферизацией) соответственно. Являясь частью стандартной
библиотеки C++, эти объекты также являются частью стандартного пространства имён — std.
*/
#include <fstream> // Файловые операции ввода-вывода
#include <string>
/*
string — заголовочный файл с классами, функциями и переменными для организации работы со строками
в языке программирования C++. Он включён в стандартную библиотеку C++. Название образовано от имени
строчного типа данных (англ. string). В языке C++ и его предшественнике, языке программирования Си,
нет встроенной поддержки строкового типа данных, вместо этого используется массив символов. string
управляет строками, как и string.h в Си. string использует единственный объект string для организации
работы со строками. Являясь частью стандартной библиотеки C++, эти объекты также являются частью
стандартного пространства имён — std.
*/

using namespace std;
Boolean c1=true;    // флаг запрета добавления строк в LV_Sar1
Boolean c2=true;    // флаг запрета добавления строк в LV_Sar2
Boolean c3=true;    // флаг запрета добавления строк в LV_Sar3
Boolean c4=true;    // флаг запрета добавления строк в LV_Sar4
Boolean fRect=true;
Boolean fTrans=true;

String FileControl="";
String FileTesting="";

// Массивы для сохранения параметров Ложной Цели
int XString[64];
int YString[64];
int EPRString[64];
int PointColor[64];

int LYmin=0;
int BXmin=0;
int LYmax=4000;
int BXmax=4000;

int XMin, XMax, YMin, YMax;

#define EPRmin   0
#define EPRmax   0xFFFF
#define EPRmax0  EPRmax/11
#define EPRmax1  2*EPRmax/11
#define EPRmax2  3*EPRmax/11
#define EPRmax3  4*EPRmax/11
#define EPRmax4  5*EPRmax/11
#define EPRmax5  6*EPRmax/11
#define EPRmax6  7*EPRmax/11
#define EPRmax7  8*EPRmax/11
#define EPRmax8  9*EPRmax/11
#define EPRmax9  10*EPRmax/11

#define CMagenta 0xFF00FF  // маджента (фиолетовый)
#define CFiolet  0x7F00FF  // фиолетовый
#define CBlue    0xFF0000  // синий
#define CLiBlue  0xFF7F00  // синий
#define CAqua    0xFFFF00  // цвет морской фолны (бирюзовый)
#define CSprGre  0x7FFF00  // весенне-зеленый
#define CLime    0x00FF00  // лайм (зеленый)
#define CShart   0x00FF7F  // шартрёз (зелено-желтый)
#define CYellow  0x00FFFF  // желтый
#define COrange  0x007FFF  // оранжевый
#define CRed     0x0000FF  // красный

#define PColor   0xFF0000

#define STEP     50

// Переменные
int OldIndex=0;

//  Константные определения ошибок
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

double LeftMin;
double LeftMax;
double BottomMin;
double BottomMax;

double tmpX,tmpY;
double Xa, Ya;
double alpha, b2, b3;

int X0;
int Y0;
int X1;
int Y1;
TRect R;

int ZX0;
int ZX1;
int ZY0;
int ZY1;
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* директива определяет последовательность инициализации пакетов такой, какая
устанавливается взаимными ссылками использующих их модулей */
#pragma resource "*.dfm"  // для формы надо использовать файл .dfm с тем же именем, что и имя данного файла
TMain_Form *Main_Form;  // объявление указателя на объект формы Main_Form
TIniFile *Ini;
Graphics::TBitmap *TmpBitmap;
//---------------------------------------------------------------------------
// вызов конструктора формы Main_Form
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
  : TForm(Owner)
{
  if(!DirectoryExists(My_Patch + "Данные_БТ"))
  {
    if(!CreateDir(My_Patch + "Данные_БТ"))
      ShowMessage("Не удается создать директорию хранения данных БТ!");
    else
      ShowMessage("Создана директория для хранения данных БТ!");
  }

  if(!DirectoryExists(My_Patch + "Данные_РЛС_и_модуля"))
  {
    if(!CreateDir(My_Patch + "Данные_РЛС_и_модуля"))
      ShowMessage("Не удается создать директорию хранения данных РЛС и модуля!");
    else
      ShowMessage("Создана директория для хранения данных РЛС и модуля!");
  }
/*
  Boolean DirectoryExists(AnsiString DirectoryName);
  Функция DirectoryExists возвращает True, если данный DirectoryName файл существует.
  Каталог разыскивается в текущем каталоге. False может быть возвращена, если пользователю не
  разрешено видеть файл.

  Boolean CreateDir(AnsiString Dir);
  Функция CreateDir создаёт папку в текущей директории.
  Если папка была создана, то функция вернёт True, если нет, то ошибка может быть получена
  с помощью функции GetLastError.
*/
  Main_Form->DoubleBuffered=true;

  ZX0=ChartLC->Zoom->X0;
  ZX1=ChartLC->Zoom->X1;
  ZY0=ChartLC->Zoom->Y0;
  ZY1=ChartLC->Zoom->Y1;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LoadBlpClick(TObject *Sender) // нажатие на кнопку "Открыть файл .blp"
{
  OpenDialog->DefaultExt=".blp";
  OpenDialog->FileName="*.blp";
  OpenDialog->Filter="Файл данных БТ (*.blp)|*.blp";
  OpenDialog->Title=" Загрузка файла данных БТ";

  String File;

  if(OpenDialog->Execute())
  {
    File=OpenDialog->FileName;
    BlpFName=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("Название секции","Имя переменной", "значение");
*/
       edLCBT->Text=Ini->ReadString("Файл данных БТ","Количество БТ","1");  // считать из файла в массив

      for(int i=0; i<StrToInt(edLCBT->Text); i++)
      {
        // Координата X БТ
        XString[i]=StrToInt(Ini->ReadString("Файл данных БТ","Координата X блестящей точки (БТ)"+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
        // Координата Y БТ
        YString[i]=StrToInt(Ini->ReadString("Файл данных БТ","Координата Y блестящей точки (БТ)"+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
        // ЭПР БТ
        EPRString[i]=StrToInt(Ini->ReadString("Файл данных БТ","ЭПР блестящей точки (БТ)"+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
		//PointColor[i]=EPRString[i]*PColor/EPRmax;

		Palette(i);                   // Алгоритм выбора цвета БТ из цветовой палитры
	  }
	  cbLCnBT->Clear();               // очистить предыдущее количество БТ

      for(int i=0;i<StrToInt(edLCBT->Text);i++)
      {
        cbLCnBT->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
      }

      cbLCnBT->ItemIndex=OldIndex;    // номер БТ по умолчанию при изменении числа БТ
      edLCx->Text=XString[OldIndex];  // показать текущие значения
      edLCy->Text=YString[OldIndex];
	  LE_EPR->Text=EPRString[OldIndex];
	  //PointColor[OldIndex]=EPRString[OldIndex]*PColor/EPRmax;

	  Palette(OldIndex);              // Алгоритм выбора цвета БТ из цветовой палитры

	  edLCBT->Enabled=false;          // запретить поле "Количество блестящих точек"
      edLCx->Enabled=true;            // разрешить поле "Координата X"
      edLCy->Enabled=true;            // разрешить поле "Координата Y"
      LE_EPR->Enabled=true;           // разрешить поле "ЭПР"
      B_Sbros->Enabled=true;          // разрешить кнопку "Сбросить БТ"
      DrawLC();                       // обновить график
      edLCBT->Color=clWindow;

      delete Ini;
    }
    else
    {
      ShowError(FileNotExist, 0, 0, "");
      return;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SaveBlpClick(TObject *Sender) // нажатие на кнопку "Сохранить файл .blp"
{
  SaveDialog->InitialDir=My_Patch + "Данные_БТ";
  SaveDialog->FileName="*.blp";
  SaveDialog->Title=" Сохранение файла данных БТ";
  SaveDialog->Filter="данные БТ (*.blp)|*.blp";

  AnsiString File; // в BCB6 было String
/*
  В заголовочном файле sysmac.h указано:

  #if defined(_DELPHI_STRING_UNICODE)
	typedef UnicodeString        String;           //
  #else
	typedef AnsiString           String;           //
  #endif

  Т.е. по умолчанию тип String есть UnicodeString.
  В BCB6 по умолчанию тип String есть AnsiString.
*/

  FILE *F;

  if(SaveDialog->Execute())
  {
    File=SaveDialog->FileName;
	BlpFName=File;
    if(F!=NULL)
	{
	  F=fopen(File.c_str(),"w+"); // открыть файл с перезаписью
	  fclose(F);                  // закрыть файл
    }
    Ini= new TIniFile(File); // создание нового файла .ini
/*
    Ini->WriteString("Название секции","Имя переменной", "значение");
*/
    Ini->WriteString("Файл данных БТ","Количество БТ",edLCBT->Text);
    // Координата X БТ
    for(int i=0; i<StrToInt(edLCBT->Text); i++)
    {
      Ini->WriteString("Файл данных БТ","Координата X блестящей точки (БТ)"+IntToStr(i+1)+"\"",XString[i]);  // запись из массива в файл
    }
    // Координата Y БТ
    for(int i=0; i<StrToInt(edLCBT->Text); i++)
    {
      Ini->WriteString("Файл данных БТ","Координата Y блестящей точки (БТ)"+IntToStr(i+1)+"\"",YString[i]);  // запись из массива в файл
    }
    // ЭПР БТ
    for(int i=0; i<StrToInt(edLCBT->Text); i++)
    {
      Ini->WriteString("Файл данных БТ","ЭПР блестящей точки (БТ)"+IntToStr(i+1)+"\"",EPRString[i]);  // запись из массива в файл
    }

    delete Ini;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LoadSarClick(TObject *Sender)
{
  OpenDialog1->DefaultExt=".sar";
  OpenDialog1->FileName="*.sar";
  OpenDialog1->Title=" Загрузка файла данных РЛС и модуля";
  OpenDialog1->Filter="данные РЛС и модуля (*.sar)|*.sar";

  String File;

  if(OpenDialog1->Execute())
  {
	File=OpenDialog1->FileName;
    FileControl=File;

	if(FileExists(File))
	{
	  Ini= new TIniFile(File);
/*
	  Ini->ReadString("Название секции","Имя переменной", "значение");
*/
	  // Скорость полёта РСА
	  LE_V->Text=Ini->ReadString("Данные РЛС и модуля","Скорость полёта РСА","1");   // считать из файла в массив
	  // Несущая частота
	  LE_f->Text=Ini->ReadString("Данные РЛС и модуля","Несущая частота","1");       // считать из файла в массив
	  // Направление полёта
	  LE_Fi->Text=Ini->ReadString("Данные РЛС и модуля","Направление полёта","1");  // считать из файла в массив
	  // Расстояние до цели
	  LE_D->Text=Ini->ReadString("Данные РЛС и модуля","Расстояние до цели","1");    // считать из файла в массив

	  delete Ini;
	}
	else
	{
	  ShowError(FileNotExist, 0, 0, "");
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SaveSarClick(TObject *Sender)
{
  SaveDialog1->InitialDir=My_Patch + "Данные_РЛС_и_модуля";
  SaveDialog1->FileName="*.sar";
  SaveDialog1->Title=" Сохранение файла данных РЛС и модуля";
  SaveDialog1->Filter="данные РЛС и модуля (*.sar)|*.sar";

  AnsiString File; // в BCB6 было String
/*
  В заголовочном файле sysmac.h указано:

  #if defined(_DELPHI_STRING_UNICODE)
	typedef UnicodeString        String;           //
  #else
	typedef AnsiString           String;           //
  #endif

  Т.е. по умолчанию тип String есть UnicodeString.
  В BCB6 по умолчанию тип String есть AnsiString.
*/
  FILE *F;

  if (SaveDialog1->Execute())         // если выбран диалог SaveDialog1
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  Отображает диалог выбора файлов.
  Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
  Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/  
  {
	File=SaveDialog1->FileName;
    FileControl=File;
	if(F!=NULL)
    {
	  F=fopen(File.c_str(),"w+"); // открыть файл с перезаписью
      fclose(F);                  // закрыть файл
    }
    Ini= new TIniFile(File);      // создание нового файла .ini
/*
	Ini->WriteString("Название секции","Имя переменной", "значение");
*/
	// Скорость полёта РСА
	Ini->WriteString("Данные РЛС и модуля","Скорость полёта РСА",LE_V->Text);
	// Несущая частота
	Ini->WriteString("Данные РЛС и модуля","Несущая частота",LE_f->Text);
	// Направление полёта
	Ini->WriteString("Данные РЛС и модуля","Направление полёта",LE_Fi->Text);
	// Расстояние до цели
	Ini->WriteString("Данные РЛС и модуля","Расстояние до цели",LE_D->Text);

	delete Ini;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCBTExit(TObject *Sender)
// когда поле "Количество блестящих точек" неактивно
{
  bool b;
  int min=1;                                   // минимальное значение
  int max=64;                                  // максимальное значение
  int delta=1;
  String EdIzm="";                             // единица измерения
  float fvalue;                                // строка значения

  fvalue=StrToFloat(edLCBT->Text);             // значение

  b=IsValidInt(min,max,fvalue,EdIzm);          // проверка правильности диапазона значений
  if(b)                                        // если правильно
  {
	edLCBT->Text=RoundValue(delta,fvalue);
    cbLCnBT->Clear();                          // очистить предыдущее количество БТ

	for(int i=0;i<StrToInt(edLCBT->Text);i++)
    {
      cbLCnBT->Items->Add(IntToStr(i+1));      // увеличить количество БТ в полях "Номер блестящей точки"

      XString[i]=StrToInt(edLCx->Text);        // заполнение массива данных!!!
      YString[i]=StrToInt(edLCy->Text);
	  EPRString[i]=EPRmax;                     // StrToInt(LE_EPR->Text)
	  PointColor[i]=CRed;                      // PColor
    }
    cbLCnBT->ItemIndex=0;                      // номер БТ по умолчанию при изменении числа БТ

    edLCBT->Enabled=false;                     // запретить поле "Количество блестящих точек"
    edLCx->Enabled=true;                       // разрешить поле "Координата X"
    edLCy->Enabled=true;                       // разрешить поле "Координата Y"
    LE_EPR->Enabled=true;                      // разрешить поле "ЭПР"
    B_Sbros->Enabled=true;                     // разрешить кнопку "Сбросить БТ"
  }
  else                                         // если не правильно
  {
    edLCBT->SetFocus();                        // фокус на поле "Количество блестящих точек"
    ErrorForm->SetFocus();                     // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::PIntKeyPress(TObject *Sender, char &Key)
// запрет введения любых символов, кроме чисел 0...9
{
/*
  Класс set поддерживает множество, в котором не уникальным(в общем случае)
  ключам соответствуют определенные значения. Спецификация его шаблона имеет следующий вид

  template <class Key, class Comp = less<Key>, class Allocator = allocator<Key>> class set

  Здесь Key - тип данных ключей, a Comp - функция, которая сравнивает два ключа.
  Класс set имеет следующие конструкторы.

  explicit set(const Comp &cmpfn = Comp(), const Allocator &a = Allocator));
  set(const set<Key, Comp, Allocator> &ob);
  template  <class InIter> set(InIter start, InIter end,
	const Comp &cmpfn = Comp(), const Allocator &a = Allocator());

  Первая форма конструктора создает пустое множество, Вторая создает множество,
  которое содержит те же элементы, что и множество ob. Третья создает множество, которое
  содержит элементы в диапазоне, заданном параметрами start и end. Функция, заданная
  параметром cmpfn(если она задана), определяет упорядочение множества.

  Для класса set определены следующие операторы сравнения: ==, <, <=, !=, > и >=.

  Строго говоря, set обеспечивает следующую функциональность:
  - добавить элемент в рассматриваемое множество, при этом исключая возможность появления дублей;
  - удалить элемент из множества;
  - узнать количество (различных) элементов в контейнере;
  - проверить, присутствует ли в контейнере некоторый элемент.
*/
  Set<char,0,255>Dig;
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<8<<'-';
	if(!Dig.Contains(Key))
	{
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::cbLCnBTChange(TObject *Sender)
// по изменении номера БТ
{
  int i;
  i=cbLCnBT->ItemIndex;                       // записать новый порядковый номер БТ

  XString[OldIndex]=StrToInt(edLCx->Text);    // записать значения в массивы
  YString[OldIndex]=StrToInt(edLCy->Text);
  EPRString[OldIndex]=StrToInt(LE_EPR->Text);
  //PointColor[OldIndex]=EPRString[OldIndex]*PColor/EPRmax;

  Palette(OldIndex);                          // Алгоритм выбора цвета БТ из цветовой палитры

  DrawLC();                                   // обновить график

  OldIndex=i;                                 // сохранить текущий порядковый номер

  edLCx->Text=XString[i];                     // показать текущие значения
  edLCy->Text=YString[i];
  LE_EPR->Text=EPRString[i];
  //PointColor[i]=EPRString[i]*PColor/EPRmax;

  Palette(i);                                 // Алгоритм выбора цвета БТ из цветовой палитры

  DrawLC();                                   // обновить график

  DrawHighlight();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCxChange(TObject *Sender)
{
  int Comm;
  if(edLCx->Text=="") edLCx->Text=0;
  Comm=StrToInt(edLCx->Text);
  XString[OldIndex]=Comm;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCxExit(TObject *Sender)
{
  bool b;
  int min=XMin;                                 // минимальное значение
  int max=XMax;                                 // максимальное значение
  int delta=1;
  String EdIzm="м";                             // единица измерения
  int ivalue;                                   // строка значения

  ivalue=StrToInt(edLCx->Text);                 // значение

  b=IsValidInt(min,max,ivalue,EdIzm);           // проверка правильности диапазона значений
  if(b)                                         // если правильно
  {
	edLCx->Text=RoundValue(delta,ivalue);
    XString[OldIndex]=StrToInt(edLCx->Text);    // записать значение в массив
    DrawLC();                                   // обновить график
  }
  else
  {
    edLCx->SetFocus();                          // фокус на поле "Количество блестящих точек"
    ErrorForm->SetFocus();                      // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::edLCyChange(TObject *Sender)
{
  int Comm;
  if(edLCy->Text=="") edLCy->Text=0;
  Comm=StrToInt(edLCy->Text);
  YString[OldIndex]=Comm;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCyExit(TObject *Sender)
{
  bool b;
  int min=YMin;                                 // минимальное значение
  int max=YMax;                                 // максимальное значение
  int delta=1;
  String EdIzm="м";                             // единица измерения
  int ivalue;                                   // строка значения

  ivalue=StrToFloat(edLCy->Text);               // значение

  b=IsValidInt(min,max,ivalue,EdIzm);           // проверка правильности диапазона значений
  if(b)                                         // если правильно
  {
	if(StrToInt(edLCy->Text)>0)                 // если вне запрещённой зоны 150 м
    {
	  edLCy->Text=RoundValue(delta,ivalue);
      YString[OldIndex]=StrToInt(edLCy->Text);  // записать значение в массив
      DrawLC();                                 // обновить график
    }
  }
  else
  {
	edLCy->SetFocus();                          // фокус на поле "Количество блестящих точек"
	ErrorForm->SetFocus();                      // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::btnReDrawLCClick(TObject *Sender)
{
  if(StrToInt(edLCx->Text)>0)               // если вне запрещённой зоны 150 м
  {
    DrawLC();                               // обновить график
  }
}
//---------------------------------------------------------------------------
bool TMain_Form::IsValidInt(int min, int max, String value, String EdIzm)
// проверка правильности диапазона значений
{
  int temp;

  try
  {
    temp=StrToInt(value);

    if((temp>max)||(temp<min))
    {
      ShowError(NotInBorders,min,max,EdIzm);
      return false;
    }

  }

  catch(...)
  {
    ShowError(NotInt,0,0,"");
    return false;
  }
  
  return true;
}
//---------------------------------------------------------------------------
String TMain_Form::RoundValue(float delta, float fvalue)
{
  float temp;
  float temp1;

  temp=fvalue;
  temp1=Log10(delta);
  fvalue=RoundTo(temp,temp1);  // в BCB6 было String (преобразование типов автоматом)

  return fvalue;
}
//---------------------------------------------------------------------------
void TMain_Form::DrawLC(void)
// обновить график
{
  int I,X,Y,xmax,xmin,ymax,ymin;

  Series1->Clear();

  if(edLCBT->Text=="") return;

  I=StrToInt(edLCBT->Text);

  xmax=0;
  xmin=0;
  ymax=0;
  ymin=0;

  for(int i=0;i<I;i++)
  {
    X=XString[i];
    Y=YString[i];

	//Series1->AddXY(X,Y);
	Series1->AddXY(X,Y,"",PointColor[i]);

	if(X>xmax) xmax=X;
    if(Y>ymax) ymax=Y;
	if(X<xmin) xmin=X;
    if(Y<ymin) ymin=Y;         
  }
}
//---------------------------------------------------------------------------
void TMain_Form::ShowError(int ErrorNum, float Par1, float Par2, String Par3)
{
  switch(ErrorNum)
  {
    case NotInBorders:
      ErrorForm->Visible=true;
      ErrorForm->Caption="Ошибка";
      ErrorForm->Panel1->Caption="Ошибка ввода данных. Введенное значение вне допустимого диапазона.";
      ErrorForm->Panel2->Caption="Значение должно лежать в диапазоне от "+ FloatToStrF(Par1,ffGeneral,5,2)+" до "+FloatToStrF(Par2,ffGeneral,5,2)+" "+Par3+".";
    break;

    case NotFloat:
      ErrorForm->Visible=true;
      ErrorForm->Caption="Ошибка";
      ErrorForm->Panel1->Caption="Ошибка ввода данных. Введенное значение не является вещественным.";
      ErrorForm->Panel2->Caption="Необходимо вводить вещественные значения. Например, \"-2,2e+3\".";
    break;

    case NotInt:
      ErrorForm->Visible=true;
      ErrorForm->Caption="Ошибка";
      ErrorForm->Panel1->Caption="Ошибка ввода данных. Введенное значение не является целым.";
      ErrorForm->Panel2->Caption="Необходимо вводить целые значения. Например, \"-25\".";
    break;

    case FileNotExist:
      ErrorForm->Visible=true;
      ErrorForm->Caption="Ошибка";
      ErrorForm->Panel1->Caption="Невозможно загрузить не существующий файл. Для создания нового файла";
      ErrorForm->Panel2->Caption="воспользуйтесь командами \"Сохранить\" и \"Сохранить как...\".";
    break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_SbrosClick(TObject *Sender)
{
  ResetBP();
  if(B_DeleteTrans->Enabled==false)
  {
    edLCBT->Color=clScrollBar;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormCreate(TObject *Sender)
{
  ResetBP();
  edLCBT->Color=clScrollBar;

  // алгоритм создания курсора перекрестия
  Series1->FillSampleValues(30);  // <-- some random values
  OldX = -1;                      // initialize variables
  CrossHairColor = clRed;
  CrossHairStyle = psSolid;
  ChartLC->Cursor = crCross;

  Series1->Clear();               // очистить график

  LeftMin=LYmin;
  LeftMax=LYmax;
  BottomMin=BXmin;
  BottomMax=BXmax;

  YMin=LYmin;
  YMax=LYmax;
  XMin=BXmin;
  XMax=BXmax;
}
//---------------------------------------------------------------------------
// This procedure draws the crosshair lines }
void TMain_Form::DrawCross(int ax, int ay)
{
  TColor tmp;
  tmp = ChartLC->BackColor;
  if (tmp == clTeeColor)
    tmp = clBtnFace;
  ChartLC->Canvas->Pen->Color = (TColor)(CrossHairColor ^ ColorToRGB(tmp));

  ChartLC->Canvas->Pen->Style = CrossHairStyle;
  ChartLC->Canvas->Pen->Mode = pmXor;
  ChartLC->Canvas->Pen->Width = 1;
  ChartLC->Canvas->MoveTo(ax,ChartLC->ChartRect.Top-ChartLC->Height3D);
  ChartLC->Canvas->LineTo(ax,ChartLC->ChartRect.Bottom-ChartLC->Height3D);
  ChartLC->Canvas->MoveTo(ChartLC->ChartRect.Left+ChartLC->Width3D,ay);
  ChartLC->Canvas->LineTo(ChartLC->ChartRect.Right+ChartLC->Width3D,ay);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  if (OldX != 1) {
    DrawCross(OldX,OldY);  // draw old crosshair
    OldX = -1;
  }

  // check if (mouse is inside Chart rectangle
  if (PtInRect((RECT*)&ChartLC->ChartRect, Point(X-ChartLC->Width3D,Y+ChartLC->Height3D))) {
    DrawCross(X,Y);  // draw crosshair at current position
    // store old position
    OldX = X;
    OldY = Y;
    // set label text
    Series1->GetCursorValues(tmpX,tmpY);  // <-- get values under mouse cursor
	Label1->Caption = "X: " + Series1->GetHorizAxis->LabelValue((int)tmpX)
      + ",  Y: " + Series1->GetVertAxis->LabelValue((int)tmpY);
  }

  if (Shift.Contains(ssLeft)) {
	//ChartLC->BackImage->Bitmap->Canvas->DrawFocusRect(R);
	if (X0 < X) {
	  R.Left = X0;
	  R.Right = X-24;
    }
	else {
	  R.Left = X-21;
	  R.Right = X0;
    }
    if (Y0 < Y) {
	  R.Top = Y0;
	  R.Bottom = Y+8;
	}
    else {
	  R.Top = Y+7;
	  R.Bottom = Y0;
	}
	//ChartLC->BackImage->Bitmap->Canvas->DrawFocusRect(R);
  }
/*
  Edit1->Text=X;
  Edit2->Text=Y;

  Edit3->Text=R.Top;
  Edit4->Text=R.Bottom;
  Edit5->Text=R.Left;
  Edit6->Text=R.Right;

  Edit9->Text=ChartLC->Zoom->X0;
  Edit10->Text=ChartLC->Zoom->X1;
  Edit11->Text=ChartLC->Zoom->Y0;
  Edit12->Text=ChartLC->Zoom->Y1;
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LineSeries1AfterDrawValues(TObject *Sender)
{
  OldX = -1;  // Reset old mouse position
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCDblClick(TObject *Sender)
// двойной щелчок по графику компонента Chart
{
  if(B_Trans->Enabled==false && B_DeleteTrans->Enabled==false)
  {
	Series3->AddXY(tmpX,tmpY);
	Xa = tmpX;
	Ya = tmpY;
	B_DeleteTrans->Enabled=true;
	E_Trans->Enabled=true;
	GB_NumberBT->Enabled=true;
	edLCBT->Color=clYellow;
  }
  else
  {
	if((edLCBT->Text!="")&&(cbLCnBT->Text!=""))
	{
	  Memo2->Lines->Strings[0]=Series1->GetHorizAxis->LabelValue((int)tmpX);
	  Memo2->Lines->Strings[1]=Series1->GetVertAxis->LabelValue((int)tmpY);

	  // строки
	  AnsiString S[2];
	  for(int i=0;i<2;i++)
	  {
		S[i] = Memo2->Lines->Strings[i];
	  }

	  // длины строк
	  int L[2];
	  for(int i=0;i<2;i++)
	  {
		L[i] = S[i].Length();
	  }

	  int Count = Memo2->Lines->Count;
	  int Axis;

	  // убрать лишнее
	  for(int i = 0; i < Count; i++)
	  {
		for (int j = 1; j < L[i]; j++)
		{
		  AnsiString valueStr = Memo2->Lines->Strings[i];
		  if((valueStr[j]!='1')&&(valueStr[j]!='2')
		   &&(valueStr[j]!='3')&&(valueStr[j]!='4')
		   &&(valueStr[j]!='5')&&(valueStr[j]!='6')
		   &&(valueStr[j]!='7')&&(valueStr[j]!='8')
		   &&(valueStr[j]!='9')&&(valueStr[j]!='0'))
		   {
			 valueStr[j] = DecimalSeparator;
			 Axis = (int)((StrToFloat(valueStr))*1000);
			 valueStr = Axis;
		   }
		  Memo2->Lines->Strings[i] = valueStr;
		}
	  }

	  double x, y;
	  x = StrToFloat(Memo2->Lines->Strings[0]);
	  y = StrToFloat(Memo2->Lines->Strings[1]);

	  if(-M_PI_2<alpha && alpha<M_PI_2)
	  {
		if((y>(tan(alpha)*x + b2))&&(y<(tan(alpha)*x + b3)))
		{
		  DrawAndEnter();                              // обновить график
		}
	  }
	  else
	  if(-3*M_PI_2<=alpha && alpha<-M_PI_2)
	  {
		if((y<(tan(alpha)*x + b2))&&(y>(tan(alpha)*x + b3)))
		{
		  DrawAndEnter();                              // обновить график
		}
	  }
	  else
	  {
		if((y>(tan(alpha)*x + b2))&&(y<(tan(alpha)*x + b3)))
		{
		  DrawAndEnter();                              // обновить график
		}
	  }
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCBTChange(TObject *Sender)
{
  cbLCnBT->Enabled=true;                   // разрешить поле "Номер БТ"
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::edLCBTClick(TObject *Sender)
{
  if(GB_NumberBT->Enabled==true)
  {
    edLCBT->Color=clWindow;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::BitBtn1Click(TObject *Sender) // открыть карту
{
  Image2->Width=500;
  Image2->Height=500;

  if (OpenDialog2->Execute())
  {
	Image2->Picture->LoadFromFile(OpenDialog2->FileName);
  }
  else
  {
	ShowError(FileNotExist, 0, 0, "");
	return;
  }

  TmpBitmap = new Graphics::TBitmap();
  TmpBitmap->Width=500;
  TmpBitmap->Height=500;
  TmpBitmap->Canvas->StretchDraw(TRect(0,0,TmpBitmap->Width,TmpBitmap->Height),Image2->Picture->Graphic);
  //Canvas->Draw(10, 10, TmpBitmap);

  ChartLC->BackImageMode = TTeeBackImageMode(0);  // 0 - Stretch (растянуть)
  ChartLC->BackImageInside = true;                // внутри осей X и Y
  ChartLC->BackImage->Graphic=TmpBitmap;
  ChartLC->BackImage->Repaint();

  Button1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Button1Click(TObject *Sender)
{
  ChartLC->BackImage = 0; // очистить карту
  delete TmpBitmap;
  Button1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCAfterDraw(TObject *Sender)
{
/*
  // отрисовка запрещённой зоны 150 м
  if(fRect)
  {
    ChartLC->Canvas->Pen->Style = psClear;
    ChartLC->Canvas->Brush->Color=clWhite;
    ChartLC->Canvas->Brush->Style=bsDiagCross;
    ChartLC->Canvas->Rectangle(40,360,465,435);         
  }
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LE_EPRChange(TObject *Sender)
{
  int Comm;
  if(LE_EPR->Text=="") LE_EPR->Text=0;
  Comm=StrToInt(LE_EPR->Text);
  EPRString[OldIndex]=Comm;
  //PointColor[OldIndex]=EPRString[OldIndex]*PColor/EPRmax;

  Palette(OldIndex);                             // Алгоритм выбора цвета БТ из цветовой палитры

  DrawLC();                                      // обновить график

  //Series1->Transparency=100-EPRString[OldIndex]*100/EPRmax; // яркость БТ x%
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LE_EPRExit(TObject *Sender)
{
  bool b;
  int min=0;                                     // минимальное значение
  int max=EPRmax;                                // максимальное значение
  int delta=1;
  String EdIzm="м^2";                            // единица измерения
  int ivalue;                                    // строка значения

  ivalue=StrToInt(LE_EPR->Text);                 // значение

  b=IsValidInt(min,max,ivalue,EdIzm);            // проверка правильности диапазона значений
  if(b)                                          // если правильно
  {
    LE_EPR->Text=RoundValue(delta,ivalue);
	EPRString[OldIndex]=StrToInt(LE_EPR->Text);  // записать значение в массив
	//PointColor[OldIndex]=EPRString[OldIndex]*PColor/EPRmax;

	Palette(OldIndex);                           // Алгоритм выбора цвета БТ из цветовой палитры

	DrawLC();                                    // обновить график

	//Series1->Transparency=100-EPRString[OldIndex]*100/EPRmax; // яркость БТ x%
  }
  else
  {
    LE_EPR->SetFocus();                          // фокус на поле
    ErrorForm->SetFocus();                       // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::HelpAboutProgClick(TObject *Sender)
{
  F_Help->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::ChartLCZoom(TObject *Sender)
{
  fRect=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCUndoZoom(TObject *Sender)
{
  fRect=true;

  if(TmpBitmap!=NULL)
  {
  ChartLC->BackImage->Graphic=TmpBitmap;
  ChartLC->BackImage->Repaint();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ResetBP(void)
{
  edLCBT->Text="";
  cbLCnBT->Clear();
  OldIndex=0;
  edLCx->Text="0";
  edLCy->Text="0";
  LE_EPR->Text="65535";            // EPRmax

  for(int i=0;i<64;i++)
  {
    XString[i]=0;                  // заполнение массива данных!!!
    YString[i]=0;
	EPRString[i]=EPRmax;
    PointColor[i]=CRed;
  }

  edLCBT->Enabled=true;            // разрешить поле "Количество блестящих точек"
  edLCBT->Color=clYellow;
  cbLCnBT->Enabled=false;          // запретить поле "Номер БТ"
  edLCx->Enabled=false;            // запретить поле "Координата X"
  edLCy->Enabled=false;            // запретить поле "Координата Y"
  LE_EPR->Enabled=false;           // запретить поле "ЭПР"
  Series1->Clear();                // очистить график
  Series2->Clear();                // очистить график

  B_Sbros->Enabled=false;          // запретить кнопку "Сбросить БТ"
}
//---------------------------------------------------------------------------
void TMain_Form::DrawHighlight(void)
// обновить текущую точку на графике
{
  int X,Y;

  Series2->Clear();

  if(edLCBT->Text=="") return;

  X=XString[OldIndex];
  Y=YString[OldIndex];

  Series2->AddXY(X,Y);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::BitBtn2Click(TObject *Sender)
{
  SaveDialog2->FileName="*.WMF";
  SaveDialog2->Title=" Сохранить как";
  SaveDialog2->Filter="Metafile Format (*.WMF)|*.WMF";

  if (SaveDialog2->Execute()) {  // <-- ask for a filename first
	// SAVE IT !!

	// CLIPPING WORKS FINE BUT DO NOT ALLOW MOVEABLE OR RESIZEABLE METAFILES
	// TO FORCE CLIPPING WITH METAFILES UNCOMMENT THIS LINE:
	// TeeClipWhenMetafiling = true;

	ChartLC->SaveToMetafile(SaveDialog2->FileName);

	// THIS METHOD CAN BE USED TOO:
	/*
	  Chart1->SaveToMetafileRect( SaveDialog1->FileName,
	  Rect( 0,0, round(21//cm*37->8), round(10//cm*37->8)));
	*/
	//   ( this equals to 96 * 21 / 2->54 , 96 * 10 /2->54 )
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Palette(int index)
{
  // Алгоритм выбора цвета БТ из цветовой палитры:
  if((EPRString[index]>=EPRmin) &&(EPRString[index]<EPRmax0)) PointColor[index]=CMagenta;
  else
  if((EPRString[index]>=EPRmax0)&&(EPRString[index]<EPRmax1)) PointColor[index]=CFiolet;
  else
  if((EPRString[index]>=EPRmax1)&&(EPRString[index]<EPRmax2)) PointColor[index]=CBlue;
  else
  if((EPRString[index]>=EPRmax2)&&(EPRString[index]<EPRmax3)) PointColor[index]=CLiBlue;
  else
  if((EPRString[index]>=EPRmax3)&&(EPRString[index]<EPRmax4)) PointColor[index]=CAqua;
  else
  if((EPRString[index]>=EPRmax4)&&(EPRString[index]<EPRmax5)) PointColor[index]=CSprGre;
  else
  if((EPRString[index]>=EPRmax5)&&(EPRString[index]<EPRmax6)) PointColor[index]=CLime;
  else
  if((EPRString[index]>=EPRmax6)&&(EPRString[index]<EPRmax7)) PointColor[index]=CShart;
  else
  if((EPRString[index]>=EPRmax7)&&(EPRString[index]<EPRmax8)) PointColor[index]=CYellow;
  else
  if((EPRString[index]>=EPRmax8)&&(EPRString[index]<EPRmax9)) PointColor[index]=COrange;
  else
  if((EPRString[index]>=EPRmax9)&&(EPRString[index]<=EPRmax)) PointColor[index]=CRed;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LE_VKeyPress(TObject *Sender, wchar_t &Key)
// запрет введения любых символов, кроме чисел 0...9
{
/*
  Класс set поддерживает множество, в котором не уникальным(в общем случае)
  ключам соответствуют определенные значения. Спецификация его шаблона имеет следующий вид

  template <class Key, class Comp = less<Key>, class Allocator = allocator<Key>> class set

  Здесь Key - тип данных ключей, a Comp - функция, которая сравнивает два ключа.
  Класс set имеет следующие конструкторы.

  explicit set(const Comp &cmpfn = Comp(), const Allocator &a = Allocator));
  set(const set<Key, Comp, Allocator> &ob);
  template  <class InIter> set(InIter start, InIter end,
	const Comp &cmpfn = Comp(), const Allocator &a = Allocator());

  Первая форма конструктора создает пустое множество, Вторая создает множество,
  которое содержит те же элементы, что и множество ob. Третья создает множество, которое
  содержит элементы в диапазоне, заданном параметрами start и end. Функция, заданная
  параметром cmpfn(если она задана), определяет упорядочение множества.

  Для класса set определены следующие операторы сравнения: ==, <, <=, !=, > и >=.

  Строго говоря, set обеспечивает следующую функциональность:
  - добавить элемент в рассматриваемое множество, при этом исключая возможность появления дублей;
  - удалить элемент из множества;
  - узнать количество (различных) элементов в контейнере;
  - проверить, присутствует ли в контейнере некоторый элемент.
*/
  Set<char,0,255>Dig;
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<8;
	if(!Dig.Contains(Key))
	{
	//Application->MessageBox("В поле необходимо вводить только цифры!","Внимание",MB_ICONWARNING);
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::LE_fExit(TObject *Sender)
{
  int f = StrToInt(LE_f->Text);
  if(!(f>=900&&f<=10000))
  {
	ShowMessage("Необходимо ввести значение от 900 до 10000 МГц.");
	LE_f->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_datClick(TObject *Sender)
{
  OpenDialog1->DefaultExt=".dat";
  OpenDialog1->FileName="*.dat";
  OpenDialog1->Title=" Загрузка файла данных SAS.Planet";
  OpenDialog1->Filter="данные SAS.Planet (*.dat)|*.dat";

  String File;

  if(OpenDialog1->Execute())
  {
	File=OpenDialog1->FileName;

	if(FileExists(File))
	{
	  Memo1->Lines->LoadFromFile(File);

	  // лишнее
	  Memo1->Lines->Delete(5);
	  Memo1->Lines->Delete(0);

	  // строки
	  AnsiString S[4];
	  for(int i=0;i<4;i++)
	  {
		S[i] = Memo1->Lines->Strings[i];
	  }

	  // длины строк
	  int L[4];
	  for(int i=0;i<4;i++)
	  {
		L[i] = S[i].Length();
	  }

	  int Count = Memo1->Lines->Count;

	  // убрать запятые
	  for(int i = 0; i < Count; i++)
	  {
		for (int j = 1; j < L[i]; j++)
		{
		  AnsiString valueStr = Memo1->Lines->Strings[i];
		  if(valueStr[j]== ',') valueStr[j] = ' ';
		  Memo1->Lines->Strings[i] = valueStr;
		}
	  }

	  // установить системный разделитель
	  for(int i = 0; i < Count; i++)
	  {
		for (int j = 1; j < L[i]; j++)
		{
		  AnsiString valueStr = Memo1->Lines->Strings[i];
		  if(valueStr[j]== '.') valueStr[j] = DecimalSeparator;
		  Memo1->Lines->Strings[i] = valueStr;
		}
	  }

	  // строки
	  AnsiString S0 = Memo1->Lines->Strings[0];
	  AnsiString S1 = Memo1->Lines->Strings[1];
	  AnsiString S2 = Memo1->Lines->Strings[2];
	  AnsiString S3 = Memo1->Lines->Strings[3];

      // координаты
	  long double E1,N1,E2,N2,E3,N3,E4,N4;

	  int subL1=1;
	  while(S0[subL1]!=' ')
	  {
		subL1++;
	  }

	  E1 = StrToFloat(S0.SubString(1,subL1-1));
	  N1 = StrToFloat(S0.SubString(subL1+1,L[0]));

	  int subL2=1;
	  while(S1[subL2]!=' ')
	  {
		subL2++;
	  }

	  E2 = StrToFloat(S1.SubString(1,subL2-1));
	  N2 = StrToFloat(S1.SubString(subL2+1,L[1]));

	  int subL3=1;
	  while(S2[subL3]!=' ')
	  {
		subL3++;
	  }

	  E3 = StrToFloat(S2.SubString(1,subL3-1));
	  N3 = StrToFloat(S2.SubString(subL3+1,L[2]));

	  int subL4=1;
	  while(S3[subL4]!=' ')
	  {
		subL4++;
	  }

	  E4 = StrToFloat(S3.SubString(1,subL4-1));
	  N4 = StrToFloat(S3.SubString(subL4+2,L[3]));

	  long double pi=3.14;
	  long double pid=pi/180;
	  int R=6372795;

	  long double L1 = acosl(sin(N1*pid)*sin(N2*pid)+cos(N1*pid)*cos(N2*pid)*cos((E1-E2)*pid))*R;
	  long double L2 = acosl(sin(N2*pid)*sin(N3*pid)+cos(N2*pid)*cos(N3*pid)*cos((E2-E3)*pid))*R;
	  long double L3 = acosl(sin(N3*pid)*sin(N4*pid)+cos(N3*pid)*cos(N4*pid)*cos((E3-E4)*pid))*R;
	  long double L4 = acosl(sin(N4*pid)*sin(N1*pid)+cos(N4*pid)*cos(N1*pid)*cos((E4-E1)*pid))*R;

	  LeftMin=0.0;
	  LeftMax=L2;
	  BottomMin=0.0;
	  BottomMax=L1;

	  ChartLC->LeftAxis->SetMinMax(LeftMin,LeftMax);
	  ChartLC->BottomAxis->SetMinMax(BottomMin,BottomMax);
	}
	else
	{
	  ShowError(FileNotExist, 0, 0, "");
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  if (Shift.Contains(ssLeft)) {
	X0=X-26;
	Y0=Y+5;
	R.Top=Y;     // TRect(const TPoint& TL, const TPoint& BR) { left=TL.x; top=TL.y; right=BR.x; bottom=BR.y; }
	R.Bottom=Y;
	R.Left=X;
	R.Right=X;
  }
/*
  Edit3->Text=R.Top;
  Edit4->Text=R.Bottom;
  Edit5->Text=R.Left;
  Edit6->Text=R.Right;

  Edit9->Text=ChartLC->Zoom->X0;
  Edit10->Text=ChartLC->Zoom->X1;
  Edit11->Text=ChartLC->Zoom->Y0;
  Edit12->Text=ChartLC->Zoom->Y1;
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChartLCMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  X1=X;
  Y1=Y;

  Image2->Picture->Bitmap->Width=abs(X1-X0);
  Image2->Picture->Bitmap->Height=abs(Y1-Y0);
  Image2->Canvas->CopyRect(Rect(0,0,Image2->Picture->Width,Image2->Picture->Height),ChartLC->BackImage->Bitmap->Canvas,R);
  ChartLC->BackImage->Bitmap->Canvas->CopyRect(Rect(0,0,ChartLC->BackImage->Width,ChartLC->BackImage->Height),ChartLC->BackImage->Bitmap->Canvas,R);
/*
  Edit3->Text=R.Top;
  Edit4->Text=R.Bottom;
  Edit5->Text=R.Left;
  Edit6->Text=R.Right;

  Edit7->Text=Image2->Picture->Bitmap->Width;
  Edit8->Text=Image2->Picture->Bitmap->Height;

  Edit9->Text=ChartLC->Zoom->X0;
  Edit10->Text=ChartLC->Zoom->X1;
  Edit11->Text=ChartLC->Zoom->Y0;
  Edit12->Text=ChartLC->Zoom->Y1;
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormClose(TObject *Sender, TCloseAction &Action)
{
  delete TmpBitmap;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteTransClick(TObject *Sender)
{
  B_Trans->Enabled=true;
  B_DeleteTrans->Enabled=false;
  E_Trans->Enabled=false;
  E_Trans->Text="0";
  Series3->Clear();
  Series5->Clear();
  Series6->Clear();
  ChartLC->Refresh();     // обновление графика
  ResetBP();
  edLCBT->Color=clScrollBar;
  GB_NumberBT->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_TransChange(TObject *Sender)
{
  if(E_Trans->Text=="") E_Trans->Text="0";

  double x,y;
  //double alpha, b2, b3, n, m, n3, m3, Xc, Yc, Xd, Yd;
  double n, m, n3, m3, Xc, Yc, Xd, Yd;

  double L=100;
  double L3=1450;

  alpha = (90 - StrToFloat(E_Trans->Text))*M_PI/180;

  n = L*sin(alpha);
  m = L*cos(alpha);
  Xc = Xa - n;
  Yc = Ya + m;
  b2 = Yc - tan(alpha)*Xc;

  n3 = L3*sin(alpha);
  m3 = L3*cos(alpha);
  Xd = Xa - n3;
  Yd = Ya + m3;
  b3 = Yd - tan(alpha)*Xd;

  Series5->Clear();         // очистка серии
  Series6->Clear();         // очистка серии

  if(-M_PI_2<alpha && alpha<M_PI_2)
  {
	for(x=BottomMin; x<BottomMax; x+=(BottomMax/STEP))
	{
	  y = tan(alpha)*x + b2;
	  Series5->AddXY(x,y,"",clAqua);

	  y = tan(alpha)*x + b2 - pow(BottomMax,2);
	  Series5->AddXY(x,y,"",clAqua);

	  y = tan(alpha)*x + b3;
	  Series6->AddXY(x,y,"",clAqua);

	  y = tan(alpha)*x + b3 + pow(BottomMax,2);
	  Series6->AddXY(x,y,"",clAqua);
	}
  }
  else
  if(-3*M_PI_2<=alpha && alpha<-M_PI_2)
  {
	for(x=BottomMin; x<BottomMax; x+=(BottomMax/STEP))
	{
	  y = tan(alpha)*x + b2;
	  Series5->AddXY(x,y,"",clAqua);

	  y = pow(BottomMax,2);
	  Series5->AddXY(x,y,"",clAqua);

	  y = tan(alpha)*x + b3;
	  Series6->AddXY(x,y,"",clAqua);

	  y = -pow(BottomMax,2);
	  Series6->AddXY(x,y,"",clAqua);
	}
  }
  else
  {
	for(x=BottomMin; x<BottomMax; x+=(BottomMax/STEP))
	{
	  y = tan(alpha)*x + b2;
	  Series5->AddXY(x,y,"",clAqua);

	  y = -pow(BottomMax,2);
	  Series5->AddXY(x,y,"",clAqua);

	  y = tan(alpha)*x + b3;
	  Series6->AddXY(x,y,"",clAqua);

	  y = pow(BottomMax,2);
	  Series6->AddXY(x,y,"",clAqua);
	}
  }

  for(x=BottomMin; x<BottomMax; x+=(BottomMax/STEP))
  {
	y = tan(alpha)*x + b2;
	Series5->AddXY(x,y,"",clAqua);
  }

  for(x=BottomMin; x<BottomMax; x+=(BottomMax/STEP))
  {
	y = tan(alpha)*x + b3;
	Series6->AddXY(x,y,"",clAqua);
  }

  ChartLC->Refresh();       // обновление графика
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_TransClick(TObject *Sender)
{
  B_Trans->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_TransExit(TObject *Sender)
// когда поле "Угол" неактивно
{
  bool b;
  double min=0;                                // минимальное значение
  double max=359;                              // максимальное значение
  double delta=1;
  String EdIzm="";                             // единица измерения
  float fvalue;                                // строка значения

  fvalue=StrToFloat(E_Trans->Text);            // значение

  b=IsValid(min,max,fvalue,EdIzm);             // проверка правильности диапазона значений
  if(b)                                        // если правильно
  {

  }
  else                                         // если не правильно
  {
	E_Trans->SetFocus();                       // фокус на поле "Угол"
	E_Trans->Text="0";
    ErrorForm->SetFocus();                     // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
bool TMain_Form::IsValid(float min, float max, String value, String EdIzm)
{
  float temp;

  try
  {
    temp=StrToFloat(value);

    if((temp>max)||(temp<min))
    {
      ShowError(NotInBorders,min,max,EdIzm);
      return false;
    }
  }

  catch(...)
  {
    ShowError(NotFloat,0,0,"");
    return false;
  }

  return true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_TransKeyPress(TObject *Sender, wchar_t &Key)
{
  Set<char,0,255>Dig;
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<8;
	if(!Dig.Contains(Key))
	{
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void TMain_Form::DrawAndEnter(void)
{
  int Commx, Commy;

  edLCx->Text=Memo2->Lines->Strings[0];
  Commx=StrToInt(edLCx->Text);
  XString[OldIndex]=Commx;

  edLCy->Text=Memo2->Lines->Strings[1];
  Commy=StrToInt(edLCy->Text);
  YString[OldIndex]=Commy;

  DrawLC();                              // обновить график
}
//---------------------------------------------------------------------------

