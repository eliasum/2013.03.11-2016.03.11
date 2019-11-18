//---------------------------------------------------------------------------
// директивы препроцессора #include подключают в данный файл тексты указанных в них файлов
#include <vcl.h>  // объявления, используемые в библиотеке визуальных компонентов С++Builder
#pragma hdrstop   // конец списка общих заголовочных файлов для всех модулей проекта

#include "ControlTesting_Main.h"
#include "BT.h"
#include "Sar1.h"
#include "Sar2.h"
#include "Sar3.h"
#include "Sar4.h"
#include "Error.h"
#include "About.h"
#include "Help.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <Registry.hpp>

#define NUMBOFMODS 8
#define NUMBOFREQS 64
using namespace std;
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

using namespace std;
const float pi=3.141592;
const float c=3*100000000;
Boolean c1=true;        // флаг запрета добавления строк в LV_Sar1
Boolean c2=true;        // флаг запрета добавления строк в LV_Sar2
Boolean c3=true;        // флаг запрета добавления строк в LV_Sar3
Boolean c4=true;        // флаг запрета добавления строк в LV_Sar4
float Fi=0;             // значение направления полёта
static int sec=0;       // глобальная переменная секунды
int itemNumber=0;       // количество БТ с ненулевыми значениями параметров
int X=0;                // значение координаты БТ по оси X
int Y=0;                // значение координаты БТ по оси Y
int D=0;                // расстояние до цели [м]
int V=0;                // скорость полёта РСА [м/с]
int f=0;                // несущая частота [МГц]

int Command1[4]={1, 0, 0, 1};
int Command2[4]={2, 0, 1, 1};
int Command3[64][4];
int Shift[4]={3, 255, 0, 0};     // команда "Сдвиг разрядов"
int Command4[64][4];
int Command5[64][4];
int D_SignC[64];                 // знак доплеровского смещения БТ
int Command6[4]={6, 0, 0, 0};
int Command7[4]={7, 0, 0, 0};

int Com1[4]={225, 0, 0, 1};
int Com2[4]={226, 0, 1, 1};
int Com3[64][4];
int Shift_[4]={227, 255, 0, 0};  // команда "Сдвиг разрядов"
int Com4[64][4];
int Com5[64][4];
int D_SignT[64];                 // знак доплеровского смещения БТ
int Com6[4]={230, 0, 0, 31};
int Com7[4]={231, 0, 0, 63};
int Com8[4]={232, 0, 7, 142};
int Com9[4]={233, 0, 7, 142};
int Com10[4]={234, 0, 0, 0};
int Com11[4]={235, 0, 0, 0};
int Com12[4]={236, 0, 0, 0};

int Com13[4]={237, 0, 0, 200};   // 00, 00, c8
int Com14[4]={238, 0, 201, 128}; // 00, c9, 80
int Com15[4]={239, 0, 8, 194};   // 00, 08, c2
int Com16[4]={240, 78, 0, 0};    // 4e, 00, 00
int Com17[4]={241, 179, 4, 0};   // b3, 04, 00
int Com18[4]={242, 0, 36, 1};    // 00, 24, 01
int Com19[4]={243, 165, 0, 5};   // a5, 00, 05
int Com20[4]={244, 0, 88, 0};    // 00, 58, 00

int Mod[NUMBOFMODS][NUMBOFREQS][4];      // 8 модулей, в каждом модуле 64 параметра по 4 байта
int ModNumber[NUMBOFMODS];               // массив хранения индивидуального номера модуля
int FreqNumber[NUMBOFMODS][NUMBOFREQS];  // массив хранения номеров частот для каждого модуля
int NumberOfFreq;                        // количество частот для каждого модуля
int OldIndexF[NUMBOFMODS];               // массив хранения старых индексов номеров частот для каждого модуля
int OldIndexMod;                         // старый индекс модуля
/*
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;
*/
int Reg[6];

int REFin, R, T;         // Reference frequency input, Reference division factor, Reference divide-by-2 bit
int ChS, Fres;           // Channel Spacing, Channel resolution
float Fpfd;              // PFD frequency, Output Devider
double Fvco, Fout;       // Output frequency, VCO Frequency
double INTE, FRAC, MOD;  // Integer division factor,  Fractionality, Modulus
double N, Phase;         // INT+FRAC/MOD, Phase

int OD;
int Prescaler;
int Counter_Reset;
int Three_State;
int Power_Down;
int Polarity;
int LDP;
int LDF;
int Current_setting;
int Double_Buff;
int MUXout;
int Noise_Mode;
int CLK_DIV;
int CLK_DIV_MODE;
int Cycle_Slip_Reduction;
int RF_Output;
int AUX_Output;
int AUX_Select;
int MTLD;
int VCO_Power_Down;
double BSCD;
double Divider_Select;
int Feedback_Select;
int LD_Pin_Mode;

//  Константные определения ошибок
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

// Переменные
int OldIndex;                   // для режима Управление
int OldIndex_;                  // для режима Тестирование
int NIDAQmxCounter=-1;
int TempPowerCounter=-1;
const int NumReadValue=10;
bool ErrorADC;
TColor DefaultColor=clSilver;   // clBtnFace
TColor GoodColor=clLime;
TColor BadColor=clRed;
float value;

float Buff0[10];                // очередь замеров
unsigned char N_zamera0=0;      // номер замера
float sum0;                     // 0..0x0ffffffff

float Buff1[10];                // очередь замеров
unsigned char N_zamera1=0;      // номер замера
float sum1;                     // 0..0x0ffffffff

float Buff2[10];                // очередь замеров
unsigned char N_zamera2=0;      // номер замера
float sum2;                     // 0..0x0ffffffff

float Buff3[10];                // очередь замеров
unsigned char N_zamera3=0;      // номер замера
float sum3;                     // 0..0x0ffffffff

float Buff4[10];                // очередь замеров
unsigned char N_zamera4=0;      // номер замера
float sum4;                     // 0..0x0ffffffff

float Buff5[10];                // очередь замеров
unsigned char N_zamera5=0;      // номер замера
float sum5;                     // 0..0x0ffffffff

double k2=0.487, k3=0.529, k4=0.56, k5=1.42, k6=1.608;

String FileControl="";
String FileTesting="";

// Массивы для сохранения параметров Ложной Цели
int XString[64];
int YString[64];
int EPRString[64];

int delay_ms;
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* директива определяет последовательность инициализации пакетов такой, какая
устанавливается взаимными ссылками использующих их модулей */
#pragma link "CommPort"
#pragma resource "*.dfm"  // для формы надо использовать файл .dfm с тем же именем, что и имя данного файла
TMain_Form *Main_Form;    // объявление указателя на объект формы Main_Form
TIniFile *Ini;
//---------------------------------------------------------------------------
// вызов конструктора формы Main_Form
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
  : TForm(Owner)
{
/*
  ExtractFilePath(Application->ExeName) - путь к исполнимому файлу.
  GetCurrentDir() - путь к текущей директории.
  Они не обязаны совпадать, текущий каталог величина не постоянная,
  зависит  от способа запуска проги и может меняться в процессе.
*/
  My_Patch = ExtractFilePath(Application->ExeName); // путь к исполнимому файлу

  if(!DirectoryExists(My_Patch + "log файлы"))
  {
    if(!CreateDir(My_Patch + "log файлы"))
      ShowMessage("Не удается создать директорию хранения log файлов!");
    else
      ShowMessage("Создана директория для хранения log файлов!");
  }

  if(!DirectoryExists(My_Patch + "Файлы результатов в режиме Управление"))
  {
    if(!CreateDir(My_Patch + "Файлы результатов в режиме Управление"))
      ShowMessage("Не удается создать директорию хранения файлов результатов в режиме Управление!");
    else
      ShowMessage("Создана директория для хранения файлов результатов в режиме Управление!");
  }

  if(!DirectoryExists(My_Patch + "Файлы результатов в режиме Тестирование"))
  {
    if(!CreateDir(My_Patch + "Файлы результатов в режиме Тестирование"))
      ShowMessage("Не удается создать директорию хранения файлов результатов в режиме Тестирование!");
    else
      ShowMessage("Создана директория для хранения файлов результатов в режиме Тестирование!");
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

  InitBPControl();  // инициализация команд Command 3...5
  InitBPTesting();  // инициализация команд Com 3...5
  InitModulus();    // инициализация модулей 1...8

  REFin=10;  // Reference frequency input
  D=0;       // RF REFin doubler bit
  T=0;       // Reference divide-by-2 bit
  R=1;       // Reference division factor
  OD=4;      // Output Devider
  ChS=100;   // Channel Spacing
  Fres=400;  // Channel resolution
  Fout=1000; // Output frequency
  Phase=1;   // Phase
  Fvco=4000; // VCO Frequency
  Fpfd=10;   // PFD frequency
  INTE=400;  // Integer division factor
  FRAC=0;    // Fractionality
  MOD=25;    // Modulus
  N=400;     // INT+FRAC/MOD

  Prescaler=0;
  Counter_Reset=0;
  Three_State=0;
  Power_Down=0;
  Polarity=1;
  LDP=1;
  LDF=0;
  Current_setting=7;
  CLK_DIV=150;
  CLK_DIV_MODE=0;
  Cycle_Slip_Reduction=0;
  RF_Output=4;
  AUX_Output=0;
  AUX_Select=0;
  MTLD=0;
  VCO_Power_Down=0;
  BSCD=80;
  Divider_Select=2;
  Feedback_Select=1;
  LD_Pin_Mode=1;  

  // начальная инициализация:
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;

  delay_ms=1;

  NumberOfFreq=1;
  ResetModulus();
  E_Command6->Text=IntToStr(10*(Mod[0][0][0]*256+Mod[0][0][1])+8500);
  for(int i=0; i<8; i++) ModNumber[i]=1;

  for(int z=0; z<NUMBOFREQS; z++)
  {
    if(Mod[0][0][2]==63-z)
    {
      CB_Command7->ItemIndex=z;
    }
  }

  for(int z=0; z<7; z++)
  {
    if(Mod[0][0][3]==z)
    {
      CB_Shift->ItemIndex=z;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SB_OnOffClick(TObject *Sender)
{
  try
  {
    if(SB_OnOff->Down)         // если нажата
    {
      SB_OnOff->Caption="Выключить";
      SB_OnOff->Font->Color=clRed;
    
      WorkTimer->Enabled=true; // включить таймер WorkTimer

      if(RG_Mode->ItemIndex==0)
      {
        StartControl();
      }
      else
      {
        StartTesting();
      }
    }
    else                       // если не нажата
    {
      SB_OnOff->Caption="Включить";
      SB_OnOff->Font->Color=clGreen;
    
      if(RG_Mode->ItemIndex==0)
      {
        StopControl();
      }
      else
      {
        StopTesting();
      }
/*
      ExtractFilePath(Application->ExeName) - путь к исполнимому файлу.
      GetCurrentDir() - путь к текущей директории.
      Они не обязаны совпадать, текущий каталог величина не постоянная,
      зависит от способа запуска проги и может меняться в процессе.
*/
    }
  }

  catch(...)
  {
    SB_OnOff->Down=false;
    SB_OnOff->Caption="Включить";
    SB_OnOff->Font->Color=clGreen;
    ButtonsOn();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SystemTimerTimer(TObject *Sender)
// таймер обновления и вывода системного времени каждые 10 мс
{
/*
  FormatDateTime (s, dt) - Строка символов, представляющая собой дату или время. Способ представления
  задает строка формата s, например, строка dd/mm/yyyy задает, что значением функции является дата,
  а строка hh:mm – время
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+" "+FormatDateTime("HH:NN:SS",Time()); // текущая дата и время
  //P_SystemTime->Caption = Now();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::WorkTimerTimer(TObject *Sender)
// таймер обновления и вывода рабочего времени каждую 1 с
{
  static int min=0, hour=0; // переменные минут и часов
  sec++;                    // каждые 1000 мс увеличивать значение переменной секунд на 1

  if(sec>59)                // каждые 60 с
  {
    sec=0;                  // обнулять значение секунд
    min++;                  // увеличивать значение переменной минут на 1
  }

  if(min>59)                // каждые 60 минут
  {
    min=0;                  // обнулять значение минут
    hour++;                 // увеличивать значение переменной часов на 1
  }

  // чтобы вывод секунд, минут и часов всегда был с использованием 2-х символов
  if(sec<10)  L_S->Caption="0"+IntToStr(sec);
  else        L_S->Caption=IntToStr(sec);

  if(min<10)  L_M->Caption="0"+IntToStr(min);
  else        L_M->Caption=IntToStr(min);
  
  if(hour<10) L_H->Caption="0"+IntToStr(hour);
  else        L_H->Caption=IntToStr(hour);

  P_WorkTime->Caption = L_H->Caption+":"+L_M->Caption+":"+L_S->Caption;
  P_WorkTime->Refresh(); // обновить заголовок
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  AddSaveLog("Программа закрыта"); // добавить комментарий и сохранить лог
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormCreate(TObject *Sender)
{
/*
  FormatDateTime (s, dt) - Строка символов, представляющая собой дату или время. Способ представления
  задает строка формата s, например, строка dd/mm/yyyy задает, что значением функции является дата,
  а строка hh:mm – время
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+"_"+FormatDateTime("HH-NN-SS",Time()); // текущая дата и время
  logFname = P_SystemTime->Caption; // запись имени лог файла в буфер при открытии программы
  AddSaveLog("Программа запущена"); // добавить комментарий и сохранить лог
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::AddSaveLog(AnsiString comment) // добавить комментарий и сохранить лог
{
  My_Patch = ExtractFilePath(Application->ExeName); // путь к исполнимому файлу

  if(!DirectoryExists(My_Patch + "log файлы"))
  {
    if(!CreateDir(My_Patch + "log файлы"))
      ShowMessage("Не удается создать директорию хранения log файлов!");
    else
      ShowMessage("Создана директория для хранения log файлов!");
  }
/*
  Now()- Системная дата и время – значение типа TDateTime;
  DateTimeToStr(Now()) - Строка символов, изображающая дату в формате dd.mm.yyyy и время формате hh:mm:ss
*/
  M_Log->Lines->Add(DateTimeToStr(Now())+" "+comment); // добавить запись в лог с текущим временем
/*
  ExtractFilePath(Application->ExeName) - путь к исполнимому файлу.
  GetCurrentDir() - путь к текущей директории.
  Они не обязаны совпадать, текущий каталог величина не постоянная,
  зависит от способа запуска проги и может меняться в процессе.
*/
  M_Log->Lines->SaveToFile(My_Patch+"\\log файлы\\"+logFname+".log"); // запись лог файла
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_EnterClick(TObject *Sender)
{
  if(E_EnterComment->Text!="")
  {
    AddSaveLog(E_EnterComment->Text); // запись лог файла
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_LoadBlpClick(TObject *Sender) // нажатие на кнопку "Открыть файл .blp"
{
  AddSaveLog("Загрузить файл данных БТ");  // добавить комментарий и сохранить лог

  OpenDialog->DefaultExt=".blp";
  OpenDialog->FileName="*.blp";
  OpenDialog->Filter="Файл данных БТ (*.blp)|*.blp";
  OpenDialog->Title=" Загрузка файла данных БТ";

  String File;

  if(OpenDialog->Execute())
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  Отображает диалог выбора файлов.
  Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
  Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/
  {
    File=OpenDialog->FileName;
    BlpFName=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("Название секции","Имя переменной", "значение");
*/
      // Количество БТ
      E_Command3_0->Text=Ini->ReadString("Файл данных БТ","Количество БТ","1");  // считать из файла в массив
      E_Com3_0->Text=Ini->ReadString("Файл данных БТ","Количество БТ","1");      // считать из файла в массив
      // Координата X БТ, Координата Y БТ, ЭПР БТ
      for(int i=0; i<StrToInt(E_Command3_0->Text); i++)                          
      {
        // Координата X БТ
        XString[i]=StrToInt(Ini->ReadString("Файл данных БТ","Координата X блестящей точки (БТ)"+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
        // Координата Y БТ
        YString[i]=StrToInt(Ini->ReadString("Файл данных БТ","Координата Y блестящей точки (БТ)"+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
        // ЭПР БТ
        EPRString[i]=StrToInt(Ini->ReadString("Файл данных БТ","ЭПР блестящей точки (БТ)"+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
      }

      AddSaveLog("Загружен файл "+BlpFName);  // добавить комментарий и сохранить лог

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
void __fastcall TMain_Form::TB_LoadSarClick(TObject *Sender) // нажатие на кнопку "Открыть файл .sar"
{
  AddSaveLog("Загрузить файл данных РЛС и модуля");  // добавить комментарий и сохранить лог
/*
  Потоки для работы с файлами создаются как объекты следующих классов:

  ofstream - для вывода (записи) данных в файл;
  ifstream - для ввода (чтения) данных из файла;
  fstream - для чтения и для записи данных (двунаправленный обмен).

  Чтобы использовать эти классы, в текст программы необходимо включить дополнительный заголовочный
  файл fstream.h. После этого в программе можно определять конкретные файловые потоки, соответствующих
  типов (объекты классов ofstream, ifstream, fstream), например, таким образом:

  ofstream outFile; // Выходной файловый поток.
  ifstream inFile; // Входной файловый поток.
  fstream ioFile; // Файловый поток для ввода и вывода.

  Создание файлового потока (объекта соответствующего класса) связывает имя потока с выделяемым для него
  буфером и инициализирует переменные состояния потока. Так как перечисленные классы файловых потоков
  наследуют свойства класса ios, то и переменные состояния каждого файлового потока наследуются из этого
  базового класса. Так как файловые классы являются производными от классов ostream (класс ofstream),
  istream (класс ifstream), stream (класс fstream), то они поддерживают описанный в предыдущих шагах
  форматированный и бесформатный обмен с файлами. Однако прежде чем выполнить обмен, необходимо открыть
  соответствующий файл и связать его с файловым потоком.

  Открытие файла в самом общем смысле означает процедуру, информирующую систему о тех действиях, которые
  предполагается выполнять с файлом. Существуют функции стандартной библиотеки языка С для открытия файлов
  fopen(), open(). Но работая с файловыми потоками библиотеки ввода-вывода языка С++, удобнее пользоваться
  компонентными функциями соответствующих классов.

  Создав файловый поток, можно "присоединить" его к конкретному файлу с помощью компонентной функции open().
  Функция open() унаследована каждым из файловых классов ofstream, ifsream, fstream от класса fstreambase.
  С ее помощью можно не только открыть файл, но и связать его с уже определенным потоком.
*/
  ifstream infile; // Входной файловый поток.

  if(OpenDialog1->Execute())          // если выбран диалог OpenDialog1 
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  Отображает диалог выбора файлов.
  Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
  Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/
  {
    SarFName = OpenDialog1->FileName; // имя выбранного файла сохраняется в переменной BlpFName
    LV_Sar1->Items->Clear();          // очистка LV_Sar1
    LV_Sar2->Items->Clear();          // очистка LV_Sar2
    LV_Sar3->Items->Clear();          // очистка LV_Sar3
    LV_Sar4->Items->Clear();          // очистка LV_Sar4
    Update_Dump_sar();                // загрузка файла SarFName в LV_Sar1 и LV_Sar2
  }
  if(!infile)                         // если не входной файловый поток
  {
    MessageBox(NULL,"Файл не удается открыть!","Ошибка!",MB_OK|MB_ICONERROR);
    return;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Update_Dump_sar() // открыть дамп sar
{
  TListItem *pItem;               // указатель на объект типа TListItem (первый столбец строки ListView)
  std::ifstream ifile(SarFName.c_str()); // Входной файловый поток (файл открывается для ввода (чтения))
  std::string line;               // строка line класса string
/*
  Функция std::getline (string) служит для заполнения строки из входного потока.
  (1) istream& getline (istream& is, string& str, char delim);
  (2) istream& getline (istream& is, string& str);
  Извлекает символы из is и сохраняет их в str пока не встретится разделительный символ delim
  (или символ новой строки, '\n', для пункта (2)).
  Извлечение так же прекращается, если достигнут конец файла в is или если возникли некоторые ошибки
  во время операции ввода (чтения).
  Если разделитель найден, он извлекается и отбрасывается, т.е он не сохраняется и следующая операция
  начинается посленего.
*/
  while(std::getline(ifile,line))                  // пока заполняется строка из входного потока
  {
    if(line == "*")                                // если встретился этот символ
      if(std::getline(ifile,line))                 // если заполняется строка из входного потока
      {
        pItem = LV_Sar1->Items->Add();             // добавить объект pItem
        pItem->Caption =AnsiString(line.c_str());  // заполнить объект pItem
      }
    if(line == "**")                               // если встретился этот символ
      if(std::getline(ifile,line))                 // если заполняется строка из входного потока
        pItem->SubItems->Add(line.c_str());        // добавить объект SubItem

    if(line == "***")                              // если встретился этот символ
      if(std::getline(ifile,line))                 // если заполняется строка из входного потока
      {
        pItem = LV_Sar2->Items->Add();             // добавить объект pItem
        pItem->Caption =AnsiString(line.c_str());  // заполнить объект pItem
      }
    if(line == "****")                             // если встретился этот символ
      if (std::getline(ifile,line))                // если заполняется строка из входного потока
        pItem->SubItems->Add(line.c_str());        // добавить объект SubItem

    if(line == "*****")                            // если встретился этот символ
      if(std::getline(ifile,line))                 // если заполняется строка из входного потока
      {
        pItem = LV_Sar3->Items->Add();             // добавить объект pItem
        pItem->Caption =AnsiString(line.c_str());  // заполнить объект pItem
      }
    if(line == "******")                           // если встретился этот символ
      if (std::getline(ifile,line))                // если заполняется строка из входного потока
        pItem->SubItems->Add(line.c_str());        // добавить объект SubItem

    if(line == "*******")                          // если встретился этот символ
      if(std::getline(ifile,line))                 // если заполняется строка из входного потока
      {
        pItem = LV_Sar4->Items->Add();             // добавить объект pItem
        pItem->Caption =AnsiString(line.c_str());  // заполнить объект pItem
      }
    if(line == "********")                         // если встретился этот символ
      if (std::getline(ifile,line))                // если заполняется строка из входного потока
        pItem->SubItems->Add(line.c_str());        // добавить объект SubItem
  }

  AddSaveLog("Загружен файл "+SarFName);           // добавить комментарий и сохранить лог
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_ControlClick(TObject *Sender)
{
  AddSaveLog("Выбран режим Управление");  // добавить комментарий и сохранить лог
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_TestingClick(TObject *Sender)
{
  AddSaveLog("Выбран режим Тестирование");  // добавить комментарий и сохранить лог    
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::FormShow(TObject *Sender)
{
  if (!DirectoryExists(My_Patch + "log файлы"))
  {
    MessageBox(NULL,"Отсутсвует директория log файлы!","Ошибка!",MB_OK|MB_ICONERROR);
    Application->Terminate();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar1DblClick(TObject *Sender)
{
  if (LV_Sar1->Selected!= NULL) F_Sar1->ShowModal(); // если выбранная строка LV_Sar1 не пуста, открыть форму  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar2DblClick(TObject *Sender)
{
 if (LV_Sar2->Selected!= NULL) F_Sar2->ShowModal(); // если выбранная строка LV_Sar2 не пуста, открыть форму  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar3DblClick(TObject *Sender)
{
  if (LV_Sar3->Selected!= NULL) F_Sar3->ShowModal(); // если выбранная строка LV_Sar3 не пуста, открыть форму
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar4DblClick(TObject *Sender)
{
  if (LV_Sar4->Selected!= NULL) F_Sar4->ShowModal(); // если выбранная строка LV_Sar4 не пуста, открыть форму
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_ReadyClick(TObject *Sender)
{
  AddSaveLog("Подготовить команды");  // добавить комментарий и сохранить лог
/*
  Направления полёта Fi относительно направления на север
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/      
  if((size_t)LV_Sar1->Items->Count!=0) // если количество строк LV_Sar1 не нулевое
  {
    Fi=StrToFloat(LV_Sar1->Items->Item[0]->SubItems->Strings[1].c_str());  // подготовить значение направления полёта
    //M_Debug->Lines->Add(Fi);
  }
/*
  Скорость полёта РСА V, несущая частота f, расстояние до цели D
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar1->Items->Count!=0) // если количество строк LV_Sar1 не нулевое
  {
    V=StrToInt(LV_Sar1->Items->Item[0]->Caption.c_str());              // подготовить значение скорости полёта РСА
    f=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[0].c_str()); // подготовить значение несущей частоты
    D=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[3].c_str()); // подготовить значение расстояния до цели

    if(f>=8500&&f<=17500)                       // если диапазон правильный
    {
      int rounding=f/10;                        // округление до числа, кратного 10
      f=rounding*10;
      int code=(f-8500)/10;                     // получение кода центральной частоты
      int code_LSB=code&0xFF;                   // младший байт центральной частоты рабочей полосы
      int code_MSB=(code/256)&0xFF;             // старший байт центральной частоты рабочей полосы
      Command6[2]=code_MSB;                     // записать значение старшего байта центральной частоты рабочей полосы
      Command6[3]=code_LSB;                     // записать значение младшего байта центральной частоты рабочей полосы
    }

    E_Command6->Text=IntToStr(f);
    
    //M_Debug->Lines->Add(V);
    //M_Debug->Lines->Add(f);
    //M_Debug->Lines->Add(D);
  }

  CB_Command3_1->Clear();                          // очистить предыдущее количество БТ
  CB_Com3_1->Clear();                              // очистить предыдущее количество БТ

  for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
  {
    CB_Command3_1->Items->Add(IntToStr(i+1));      // увеличить количество БТ в полях "Номер блестящей точки"
  }

  for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
  {
    CB_Com3_1->Items->Add(IntToStr(i+1));          // увеличить количество БТ в полях "Номер блестящей точки"
  }
  // Command3, Command4, Command5, Com3, Com4, Com5
  for(int i=0;i<StrToInt(E_Command3_0->Text);++i)  // перебор БТ
  {
    // ЭПР
    float EPR=StrToFloat(EPRString[i]);            // подготовить значение ЭПР

    // Координаты
    X=XString[i];                                  // подготовить значение координаты БТ по оси X
    Y=YString[i];                                  // подготовить значение координаты БТ по оси Y
    //float arg=Fi*pi/180;                         // перевод градусов в радианы
    //float Xi=X*cos(arg)+Y*sin(arg);              // координата X с учётом направления полёта Fi
    //float Yi=Y*cos(arg)-X*sin(arg);              // координата Y с учётом направления полёта Fi
    //M_Debug->Lines->Add(Xi);
    //M_Debug->Lines->Add(Yi);

    // Время задержки
    //Tau=((2*Xi)/c-1мкс)*10^9 [нс]                // формула времени задержки БТ [нс] (Калинин)
    //float Tau=2*Xi*3.33-1000;                    // время задержки БТ [нс](Калинин)
    //float Tau=2*Yi*3.33-1000;                    // время задержки БТ [нс](учёт направления полёта Fi)
    float Tau=2*Y*3.33-1000;                       // время задержки БТ [нс](без учёта направления полёта Fi)
    int Tau_LSB=((int)Tau)&0xFF;                   // младший байт времени задержки БТ
    int Tau_MSB=((int)Tau/256)&0xFF;               // старший байт времени задержки БТ

    // Доплеровское смещение    
    //fdi=2*f[МГц=1000000Гц]*V*Yi/c*D;             // формула доплеровского смещения БТ [Гц]
    //double K1=2*((double)f/1000)*V*Yi/D;         // (Калинин)
    //double K1=2*((double)f/1000)*V*Xi/D;         // (учёт направления полёта Fi)
    double K1=2*((double)f/1000)*V*X/D;            // (без учёта направления полёта Fi)
    double K2=1000000*1000/c;
    double fdi=K1*K2;                              // доплеровское смещение БТ [Гц] для вывода в программе

    //M_Debug->Lines->Add(fdi);
    if(fdi<0)
    {
      fdi=-fdi;
      CB_SignC->ItemIndex=1;
      CB_SignT->ItemIndex=1;
    }
    else
    {
      CB_SignC->ItemIndex=0;
      CB_SignT->ItemIndex=0;
    }
    //M_Debug->Lines->Add(CB_SignC->ItemIndex);
    //M_Debug->Lines->Add(CB_SignT->ItemIndex);

    int fdi_LSB=((int)fdi)&0xFF;                   // младший байт доплеровского смещения БТ
    int fdi_MSB=((int)fdi/256)&0xFF;               // старший байт доплеровского смещения БТ
    Command5[i][2]=fdi_MSB;                        // записать значение старшего байта, цена младшего разряда 0.5 Гц
    Command5[i][3]=fdi_LSB;                        // записать значение младшего байта, цена младшего разряда 0.5 Гц

    // Command3 "Амплитуда блестящей точки (БТ)" режима Управление
    Command3[i][1]=i+1;                            // записать значение номера БТ
    Command3[i][3]=int(sqrt(EPR));                 // записать значение амплитуды БТ
    // Command4 "Время задержки (БТ)" режима Управление
    Command4[i][1]=i+1;                            // записать значение номера БТ
    Command4[i][2]=Tau_MSB;                        // записать значение старшего байта времени задержки БТ
    Command4[i][3]=Tau_LSB;                        // записать значение младшего байта времени задержки БТ
    // Command5 "Доплеровский сдвиг частоты (БТ)" режима Управление
    Command5[i][1]=i+1;                            // записать значение номера БТ
    D_SignC[i]=CB_SignC->ItemIndex;

    // Com3 "Амплитуда блестящей точки (БТ)" режима Тестирование
    Com3[i][1]=i+1;                                // записать значение номера БТ
    Com3[i][3]=int(sqrt(EPR));                     // записать значение амплитуды БТ
    // Com4 "Время задержки (БТ)" режима Тестирование
    Com4[i][1]=i+1;                                // записать значение номера БТ
    Com4[i][2]=Tau_MSB;                            // записать значение старшего байта времени задержки БТ
    Com4[i][3]=Tau_LSB;                            // записать значение младшего байта времени задержки БТ
    // Com5 "Доплеровский сдвиг частоты (БТ)" режима Тестирование
    Com5[i][1]=i+1;                                // записать значение номера БТ
    Com5[i][2]=fdi_MSB;                            // записать значение старшего байта, цена младшего разряда 0.5 Гц
    Com5[i][3]=fdi_LSB;                            // записать значение младшего байта, цена младшего разряда 0.5 Гц
    D_SignT[i]=CB_SignT->ItemIndex;
  }

  CB_Command3_1->ItemIndex=OldIndex;               // номер БТ по умолчанию при изменении числа БТ
  E_Command3->Text=IntToStr(Command3[OldIndex][3]);                            // показать текущее значение
  E_Command4->Text=IntToStr(Command4[OldIndex][3]+Command4[OldIndex][2]*256);  // показать текущее значение
  E_Command5->Text=IntToStr(Command5[OldIndex][3]+Command5[OldIndex][2]*256);  // показать текущее значение
  if(D_SignC[OldIndex]==0) CB_SignC->ItemIndex=0;
  else                     CB_SignC->ItemIndex=1;


  CB_Com3_1->ItemIndex=OldIndex_;                   // номер БТ по умолчанию при изменении числа БТ
  E_Com3->Text=IntToStr(Com3[OldIndex_][3]);                         // показать текущее значение
  E_Com4->Text=IntToStr(Com4[OldIndex_][3]+Com4[OldIndex_][2]*256);  // показать текущее значение
  E_Com5->Text=IntToStr(Com5[OldIndex_][3]+Com5[OldIndex_][2]*256);  // показать текущее значение
  if(D_SignT[OldIndex_]==0) CB_SignT->ItemIndex=0;
  else                      CB_SignT->ItemIndex=1;
/*
  Коэффициент ослабления передатчика ППРМ-2 режима Управление
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // если количество строк LV_Sar2 не нулевое
  {
    int K2=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[0].c_str()); // подготовить значение
    CB_Command7->Text=IntToStr(K2);
    Command7[3]=K2;
  }
/*
  Коэффициент ослабления приёмника ППРМ-2 режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // если количество строк LV_Sar2 не нулевое
  {
    int K1=StrToInt(LV_Sar2->Items->Item[0]->Caption.c_str()); // подготовить значение
    CB_Com6->Text=IntToStr(K1);
    Com6[3]=K1;
  }
/*
  Коэффициент ослабления передатчика ППРМ-2 режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // если количество строк LV_Sar2 не нулевое
  {
    int K2=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[0].c_str()); // подготовить значение
    CB_Com7->Text=IntToStr(K2);
    Com7[3]=K2;
  }
/*
  Частота среза фильтра гетеродина приемника ППРМ-2 режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // если количество строк LV_Sar2 не нулевое
  {
    int F1=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[1].c_str()); // подготовить значение
    CB_Com8->Text=IntToStr(F1);

    if(F1==970)  CB_Com8->ItemIndex=0;
    else
    if(F1==1000) CB_Com8->ItemIndex=1;
    else
    if(F1==1030) CB_Com8->ItemIndex=2;
    else
    if(F1==1055) CB_Com8->ItemIndex=3;
    else
    if(F1==1085) CB_Com8->ItemIndex=4;
    else
    if(F1==1120) CB_Com8->ItemIndex=5;
    else
    if(F1==1155) CB_Com8->ItemIndex=6;
    else
    if(F1==1195) CB_Com8->ItemIndex=7;
    else
    if(F1==2335) CB_Com8->ItemIndex=8;
    else
    if(F1==2430) CB_Com8->ItemIndex=9;
    else
    if(F1==2530) CB_Com8->ItemIndex=10;
    else
    if(F1==2655) CB_Com8->ItemIndex=11;
    else
    if(F1==2770) CB_Com8->ItemIndex=12;
    else
    if(F1==2940) CB_Com8->ItemIndex=13;
    else
    if(F1==3145) CB_Com8->ItemIndex=14;
    else
    if(F1==3400) CB_Com8->ItemIndex=15;

    for(int i=0; i<16; i++)
    {
      int code;
      if(CB_Com8->ItemIndex==i) code=14+128*i;    // получение кода параметра
      int code_LSB=code&0xFF;                     // младший байт параметра
      int code_MSB=(code/256)&0xFF;               // старший байт параметра
      Com8[2]=code_MSB;                           // записать значение старшего байта параметра
      Com8[3]=code_LSB;                           // записать значение младшего байта параметра
    }
    //M_Debug->Lines->Add(CB_Com8->ItemIndex);
  }
/*
  Частота среза фильтра гетеродина передатчика ППРМ-2 режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // если количество строк LV_Sar2 не нулевое
  {
    int F2=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[2].c_str()); // подготовить значение
    CB_Com9->Text=IntToStr(F2);

    if(F2==970)  CB_Com9->ItemIndex=0;
    else
    if(F2==1000) CB_Com9->ItemIndex=1;
    else
    if(F2==1030) CB_Com9->ItemIndex=2;
    else
    if(F2==1055) CB_Com9->ItemIndex=3;
    else
    if(F2==1085) CB_Com9->ItemIndex=4;
    else
    if(F2==1120) CB_Com9->ItemIndex=5;
    else
    if(F2==1155) CB_Com9->ItemIndex=6;
    else
    if(F2==1195) CB_Com9->ItemIndex=7;
    else
    if(F2==2335) CB_Com9->ItemIndex=8;
    else
    if(F2==2430) CB_Com9->ItemIndex=9;
    else
    if(F2==2530) CB_Com9->ItemIndex=10;
    else
    if(F2==2655) CB_Com9->ItemIndex=11;
    else
    if(F2==2770) CB_Com9->ItemIndex=12;
    else
    if(F2==2940) CB_Com9->ItemIndex=13;
    else
    if(F2==3145) CB_Com9->ItemIndex=14;
    else
    if(F2==3400) CB_Com9->ItemIndex=15;

    for(int i=0; i<16; i++)
    {
      int code;
      if(CB_Com9->ItemIndex==i) code=14+128*i;    // получение кода параметра
      int code_LSB=code&0xFF;                     // младший байт параметра
      int code_MSB=(code/256)&0xFF;               // старший байт параметра
      Com9[2]=code_MSB;                           // записать значение старшего байта параметра
      Com9[3]=code_LSB;                           // записать значение младшего байта параметра
    }
    //M_Debug->Lines->Add(IntToStr(Com9[2]));
    //M_Debug->Lines->Add(IntToStr(Com9[3]));
  }
/*
  Код управления входным преселектором режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // если количество строк LV_Sar2 не нулевое
  {
    int K=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[3].c_str()); // подготовить значение
    CB_Com10->Text=IntToStr(K);
    Com10[3]=K;
    //M_Debug->Lines->Add(IntToStr(Com10[3]));
  }
/*
  Код управления выходным преселектором режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar2->Items->Count!=0) // если количество строк LV_Sar2 не нулевое
  {
    int K=StrToInt(LV_Sar2->Items->Item[0]->SubItems->Strings[4].c_str()); // подготовить значение
    CB_Com11->Text=IntToStr(K);
    Com11[3]=K;
    //M_Debug->Lines->Add(IntToStr(Com11[3]));
  }
/*
  Команда "Рабочие регистры синтезатора платы ППРМ-2. Пакет 1"
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar3->Items->Count!=0) // если количество строк LV_Sar3 не нулевое
  {
    Com13[1]=StrToInt(LV_Sar3->Items->Item[0]->Caption.c_str());              // подготовить значение команды
    Com13[2]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[0].c_str()); // подготовить значение команды
    Com13[3]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[1].c_str()); // подготовить значение команды

    E_Com13_1->Text=LV_Sar3->Items->Item[0]->Caption.c_str();
    E_Com13_2->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[0].c_str();
    E_Com13_3->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[1].c_str();

    //M_Debug->Lines->Add(IntToStr(Com13[1]));
    //M_Debug->Lines->Add(IntToStr(Com13[2]));
    //M_Debug->Lines->Add(IntToStr(Com13[3]));
  }
/*
  Команда "Рабочие регистры синтезатора платы ППРМ-2. Пакет 2"
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar3->Items->Count!=0) // если количество строк LV_Sar3 не нулевое
  {
    Com14[1]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[2].c_str()); // подготовить значение команды
    Com14[2]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[3].c_str()); // подготовить значение команды
    Com14[3]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[4].c_str()); // подготовить значение команды

    E_Com14_1->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[2].c_str();
    E_Com14_2->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[3].c_str();
    E_Com14_3->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[4].c_str();
  }
/*
  Команда "Рабочие регистры синтезатора платы ППРМ-2. Пакет 3"
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar3->Items->Count!=0) // если количество строк LV_Sar3 не нулевое
  {
    Com15[1]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[5].c_str()); // подготовить значение команды
    Com15[2]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[6].c_str()); // подготовить значение команды
    Com15[3]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[7].c_str()); // подготовить значение команды

    E_Com15_1->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[5].c_str();
    E_Com15_2->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[6].c_str();
    E_Com15_3->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[7].c_str();
  }
/*
  Команда "Рабочие регистры синтезатора платы ППРМ-2. Пакет 4"
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar3->Items->Count!=0) // если количество строк LV_Sar3 не нулевое
  {
    Com16[1]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[8].c_str());  // подготовить значение команды
    Com16[2]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[9].c_str());  // подготовить значение команды
    Com16[3]=StrToInt(LV_Sar3->Items->Item[0]->SubItems->Strings[10].c_str()); // подготовить значение команды

    E_Com16_1->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[8].c_str();
    E_Com16_2->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[9].c_str();
    E_Com16_3->Text=LV_Sar3->Items->Item[0]->SubItems->Strings[10].c_str();
  }
/*
  Команда "Рабочие регистры синтезатора платы ППРМ-2. Пакет 5"
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar4->Items->Count!=0) // если количество строк LV_Sar4 не нулевое
  {
    Com17[1]=StrToInt(LV_Sar4->Items->Item[0]->Caption.c_str());              // подготовить значение команды
    Com17[2]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[0].c_str()); // подготовить значение команды
    Com17[3]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[1].c_str()); // подготовить значение команды

    E_Com17_1->Text=LV_Sar4->Items->Item[0]->Caption.c_str();
    E_Com17_2->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[0].c_str();
    E_Com17_3->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[1].c_str();

    //M_Debug->Lines->Add(IntToStr(Com17[1]));
    //M_Debug->Lines->Add(IntToStr(Com17[2]));
    //M_Debug->Lines->Add(IntToStr(Com17[3]));
  }
/*  
  Команда "Рабочие регистры синтезатора платы ППРМ-2. Пакет 6"
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar4->Items->Count!=0) // если количество строк LV_Sar4 не нулевое
  {
    Com18[1]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[2].c_str()); // подготовить значение команды
    Com18[2]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[3].c_str()); // подготовить значение команды
    Com18[3]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[4].c_str()); // подготовить значение команды

    E_Com18_1->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[2].c_str();
    E_Com18_2->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[3].c_str();
    E_Com18_3->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[4].c_str();
  }
/*  
  Команда "Рабочие регистры синтезатора платы ППРМ-2. Пакет 7"
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar4->Items->Count!=0) // если количество строк LV_Sar4 не нулевое
  {
    Com19[1]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[5].c_str()); // подготовить значение команды
    Com19[2]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[6].c_str()); // подготовить значение команды
    Com19[3]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[7].c_str()); // подготовить значение команды

    E_Com19_1->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[5].c_str();
    E_Com19_2->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[6].c_str();
    E_Com19_3->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[7].c_str();
  }
/*  
  Команда "Рабочие регистры синтезатора платы ППРМ-2. Пакет 8"
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size
*/
  if((size_t)LV_Sar4->Items->Count!=0) // если количество строк LV_Sar4 не нулевое
  {
    Com20[1]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[8].c_str()); // подготовить значение команды
    Com20[2]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[9].c_str()); // подготовить значение команды
    Com20[3]=StrToInt(LV_Sar4->Items->Item[0]->SubItems->Strings[10].c_str()); // подготовить значение команды

    E_Com20_1->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[8].c_str();
    E_Com20_2->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[9].c_str();
    E_Com20_3->Text=LV_Sar4->Items->Item[0]->SubItems->Strings[10].c_str();
  }
/*/
  M_Debug->Lines->Clear();
  M_Debug->Lines->Add(IntToStr(Com13[1]));
  M_Debug->Lines->Add(IntToStr(Com13[2]));
  M_Debug->Lines->Add(IntToStr(Com13[3]));

  M_Debug->Lines->Add(IntToStr(Com14[1]));
  M_Debug->Lines->Add(IntToStr(Com14[2]));
  M_Debug->Lines->Add(IntToStr(Com14[3]));

  M_Debug->Lines->Add(IntToStr(Com15[1]));
  M_Debug->Lines->Add(IntToStr(Com15[2]));
  M_Debug->Lines->Add(IntToStr(Com15[3]));

  M_Debug->Lines->Add(IntToStr(Com16[1]));
  M_Debug->Lines->Add(IntToStr(Com16[2]));
  M_Debug->Lines->Add(IntToStr(Com16[3]));

  M_Debug->Lines->Add(IntToStr(Com17[1]));
  M_Debug->Lines->Add(IntToStr(Com17[2]));
  M_Debug->Lines->Add(IntToStr(Com17[3]));

  M_Debug->Lines->Add(IntToStr(Com18[1]));
  M_Debug->Lines->Add(IntToStr(Com18[2]));
  M_Debug->Lines->Add(IntToStr(Com18[3]));

  M_Debug->Lines->Add(IntToStr(Com19[1]));
  M_Debug->Lines->Add(IntToStr(Com19[2]));
  M_Debug->Lines->Add(IntToStr(Com19[3]));

  M_Debug->Lines->Add(IntToStr(Com20[1]));
  M_Debug->Lines->Add(IntToStr(Com20[2]));
  M_Debug->Lines->Add(IntToStr(Com20[3]));
*/  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command1Change(TObject *Sender)
{
  for(int i=0; i<3; i++)
  {
    if(CB_Command1->ItemIndex==i) Command1[2]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command3_0Exit(TObject *Sender)
// когда поле "Количество блестящих точек" неактивно
{
  bool b;
  int min=1;                         // минимальное значение
  int max=64;                        // максимальное значение
  int delta=1;
  String EdIzm="";                   // единица измерения
  String value;                      // строка значения

  value=E_Command3_0->Text;          // значение

  b=IsValidInt(min,max,value,EdIzm); // проверка правильности диапазона значений
  if(b)                              // если правильно
  {
    CB_Command3_1->Text=RoundValue(delta,value);
    CB_Command3_1->Clear();          // очистить предыдущее количество БТ

    for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
    {
      CB_Command3_1->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
    }

    CB_Command3_1->ItemIndex=0;      // номер БТ по умолчанию при изменении числа БТ
  }
  else                               // если не правильно
  {
    E_Command3_0->SetFocus();        // фокус на поле "Количество блестящих точек"
    ErrorForm->SetFocus();           // вывод сообщения об ошибке
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
void TMain_Form::ShowError(int ErrorNum, float Par1, float Par2, String Par3)
// вывод формы сообщения об ошибке
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
void __fastcall TMain_Form::CB_Command3_1Change(TObject *Sender)
// по изменении номера БТ
{
  int i, Comm3, Comm4, Comm5, D_Signe;
  i=CB_Command3_1->ItemIndex;                        // записать новый индекс поля выбора CB_Command3_1
  // записать старые значения полей редактирования в переменную:
  Comm3=StrToInt(E_Command3->Text);                  // записать старое значение поля E_Command3 в переменную
  Comm4=StrToInt(E_Command4->Text);                  // записать старое значение поля E_Command4 в переменную
  Comm5=StrToInt(E_Command5->Text);                  // записать старое значение поля E_Command5 в переменную
  // записать старые значения по индексу OldIndex в массив:
  Command3[OldIndex][3]=Comm3&0xFF;
  Command4[OldIndex][3]=Comm4&0xFF;                  // мл. байт
  Command4[OldIndex][2]=(Comm4/256)&0xFF;            // ст. байт
  Command5[OldIndex][3]=Comm5&0xFF;                  // мл. байт
  Command5[OldIndex][2]=(Comm5/256)&0xFF;            // ст. байт
  D_SignC[OldIndex]=CB_SignC->ItemIndex;

  OldIndex=i;  // сохранить текущий индекс как старый для следующего вхождения в метод

  // извлечь значения из массива по текущему индексу в поля редактирования:
  E_Command3->Text=IntToStr(Command3[i][3]);                    
  E_Command4->Text=IntToStr(Command4[i][2]*256+Command4[i][3]);
  E_Command5->Text=IntToStr(Command5[i][2]*256+Command5[i][3]);
  // извлечь значения из массива по текущему индексу в поле выбора:
  if(D_SignC[i]==0) CB_SignC->ItemIndex=0;
  else              CB_SignC->ItemIndex=1;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command6Change(TObject *Sender)
{
  int Freq;
  if(E_Command6->Text=="") E_Command6->Text=0;
  Freq=StrToInt(E_Command6->Text);            // центральная частота рабочей полосы

  int Old = OldIndexF[OldIndexMod];           // старый индекс номера частоты

  if(Freq>=8500&&Freq<=17500)                 // если диапазон правильный
  {
    int rounding=Freq/10;                     // округление до числа, кратного 10
    Freq=rounding*10;
    int code=(Freq-8500)/10;                  // получение кода центральной частоты
    int code_LSB=code&0xFF;                   // младший байт центральной частоты рабочей полосы
    int code_MSB=(code/256)&0xFF;             // старший байт центральной частоты рабочей полосы
    // записать старое значение по индексам OldIndexMod и Old в массив:
    Mod[OldIndexMod][Old][0]=code_MSB;        // записать значение старшего байта центральной частоты рабочей полосы
    Mod[OldIndexMod][Old][1]=code_LSB;        // записать значение младшего байта центральной частоты рабочей полосы

    Command6[2]=code_MSB;                     // записать значение старшего байта центральной частоты рабочей полосы
    Command6[3]=code_LSB;                     // записать значение младшего байта центральной частоты рабочей полосы
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command7Change(TObject *Sender)
{
  int i, j;
  i=CB_Frequency->ItemIndex;                   // записать текущий индекс поля выбора CB_Frequency
  j=CB_Modulus->ItemIndex;                     // записать текущий индекс поля выбора CB_Modulus

  for(int z=0; z<NUMBOFREQS; z++)
  {
    if(CB_Command7->ItemIndex==z) Mod[j][i][2]=63-z;
  }

  for(int y=0; y<NUMBOFREQS; y++)
  {
    if(CB_Command7->ItemIndex==y) Command7[3]=63-y;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com1Change(TObject *Sender)
{
  for(int i=0; i<3; i++)
  {
    if(CB_Com1->ItemIndex==i) Com1[2]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command3_0KeyPress(TObject *Sender,
      char &Key)
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
void __fastcall TMain_Form::E_Com3_0Exit(TObject *Sender)
// когда поле "Количество блестящих точек" неактивно
{
  bool b;
  int min=1;                         // минимальное значение
  int max=64;                        // максимальное значение
  String EdIzm="";                   // единица измерения
  String value;                      // строка значения

  value=E_Com3_0->Text;              // значение

  b=IsValidInt(min,max,value,EdIzm); // проверка правильности диапазона значений
  if(b)                              // если правильно
  {
    CB_Com3_1->Clear();              // очистить предыдущее количество БТ
    
    for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
    {
      CB_Com3_1->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
    }

    CB_Com3_1->ItemIndex=0;          // номер БТ по умолчанию при изменении числа БТ
  }
  else                               // если не правильно
  {
    E_Com3_0->SetFocus();            // фокус на поле "Количество блестящих точек"
    ErrorForm->SetFocus();           // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com3_1Change(TObject *Sender)
// по изменении номера БТ
{
  int i, Comm3, Comm4, Comm5;
  i=CB_Com3_1->ItemIndex;                            // записать новый порядковый номер БТ
  Comm3=StrToInt(E_Com3->Text);                      // записать значение в переменную
  Comm4=StrToInt(E_Com4->Text);                      // записать значение в переменную
  Comm5=StrToInt(E_Com5->Text);                      // записать значение в переменную
  // записать значения в массив:
  Com3[OldIndex_][3]=Comm3&0xFF;
  Com4[OldIndex_][3]=Comm4&0xFF;                     // мл. байт
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;               // ст. байт
  Com5[OldIndex_][3]=Comm5&0xFF;                     // мл. байт
  Com5[OldIndex_][2]=(Comm5/256)&0xFF;               // ст. байт
  D_SignT[OldIndex_]=CB_SignT->ItemIndex;

  OldIndex_=i;                                       // сохранить текущий порядковый номер
  E_Com3->Text=IntToStr(Com3[i][3]);                 // показать текущее значение
  E_Com4->Text=IntToStr(Com4[i][2]*256+Com4[i][3]);  // показать текущее значение
  E_Com5->Text=IntToStr(Com5[i][2]*256+Com5[i][3]);  // показать текущее значение
  if(D_SignT[i]==0) CB_SignT->ItemIndex=0;
  else              CB_SignT->ItemIndex=1;
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::CB_Com7Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Com7->ItemIndex==i) Com7[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com6Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Com6->ItemIndex==i) Com6[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com8Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    int code;
    if(CB_Com8->ItemIndex==i) code=14+128*i;    // получение кода параметра
    int code_LSB=code&0xFF;                     // младший байт параметра
    int code_MSB=(code/256)&0xFF;               // старший байт параметра
    Com8[2]=code_MSB;                           // записать значение старшего байта параметра
    Com8[3]=code_LSB;                           // записать значение младшего байта параметра
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com9Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    int code;
    if(CB_Com9->ItemIndex==i) code=14+128*i;    // получение кода параметра
    int code_LSB=code&0xFF;                     // младший байт параметра
    int code_MSB=(code/256)&0xFF;               // старший байт параметра
    Com9[2]=code_MSB;                           // записать значение старшего байта параметра
    Com9[3]=code_LSB;                           // записать значение младшего байта параметра
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com10Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Com10->ItemIndex==i) Com10[3]=i;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::CB_Com11Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Com11->ItemIndex==i) Com11[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com12Change(TObject *Sender)
{
  for(int i=0; i<2; i++)
  {
    if(CB_Com12->ItemIndex==i) Com12[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StartControl()
{
  AddSaveLog("Включен режим Управление");  // добавить комментарий и сохранить лог
  ButtonsOff();
  CommPort1->Open=true;
  ComPortException();

  if(CommPort1->BaudRate==cbr9600)         // передача на Serial Input/Output Monitor
  {
    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command1[i]);
    }
    CommPort1->PutChar(0x0d);              // возврат каретки
    CommPort1->PutChar(0x0a);              // перевод на следующую строку
  }
  else                                     // передача на ППРМ-2, BaudRate=57600
  {
    //CommPort1->PutChar(0xBB);            // маркер передачи на контроллер (отладка)

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command1[i]);
    }
  }
  CommPort1->Open=false;  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StopControl()
{
  WorkTimer->Enabled=false;         // выключить таймер WorkTimer
  sec=0;                            // обнулить значение секунд

  AddSaveLog("Выключен режим Управление. Время работы составило "+P_WorkTime->Caption);  // добавить комментарий и сохранить лог
  
  P_WorkTime->Caption = "00:00:00"; // обнулить значение времени работы

  ButtonsOn();
  CommPort1->Open=true;
  ComPortException();

  if(CommPort1->BaudRate==cbr9600)         // передача на Serial Input/Output Monitor
  {
    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command2[i]);
    }
    CommPort1->PutChar(0x0d);              // возврат каретки
    CommPort1->PutChar(0x0a);              // перевод на следующую строку
  }
  else                                     // передача на ППРМ-2, BaudRate=57600
  {
    //CommPort1->PutChar(0xDD);            // маркер передачи на контроллер (отладка)

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command2[i]);
    }
  }
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StartTesting()
{
  AddSaveLog("Включен режим Тестирование");  // добавить комментарий и сохранить лог
  ButtonsOff();
  CommPort1->Open=true;
  ComPortException();

  if(CommPort1->BaudRate==cbr9600)         // передача на Serial Input/Output Monitor
  {
    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com1[i]);
    }
    CommPort1->PutChar(0x0d);              // возврат каретки
    CommPort1->PutChar(0x0a);              // перевод на следующую строку
  }
  else                                     // передача на ППРМ-2, BaudRate=57600
  {
    //CommPort1->PutChar(0xCC);            // маркер передачи на контроллер (отладка)

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com1[i]);
    }
  }
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StopTesting()
{
  WorkTimer->Enabled=false;         // выключить таймер WorkTimer
  sec=0;                            // обнулить значение секунд

  AddSaveLog("Выключен режим Тестирование. Время работы составило "+P_WorkTime->Caption);  // добавить комментарий и сохранить лог
  
  P_WorkTime->Caption = "00:00:00"; // обнулить значение времени работы
  
  ButtonsOn();
  CommPort1->Open=true;
  ComPortException();

  if(CommPort1->BaudRate==cbr9600)         // передача на Serial Input/Output Monitor
  {
    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com2[i]);
    }
    CommPort1->PutChar(0x0d);              // возврат каретки
    CommPort1->PutChar(0x0a);              // перевод на следующую строку
  }
  else                                     // передача на ППРМ-2, BaudRate=57600
  {
    //CommPort1->PutChar(0xEE);            // маркер передачи на контроллер (отладка)

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com2[i]);
    }
  }
  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::NIDAQmxTimerTimer(TObject *Sender)
{
  GoNIDAQmx();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::GoNIDAQmx()
{
  float min,max;
  NIDAQmxCounter++;

  switch(NIDAQmxCounter)
  {
    case 0:                                    // Значение напряжения источника +5 В
      value=0;
      value=GetACD0Data();                     // Считываем AI0 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
      min=0;                                   // граничные значения напряжения
      max=5.5;

	    value = average_U5V(value);              // расчет "скользящего среднего"

      P_U5V->Caption=RoundValue(0.01, FloatToStr(value))+" В"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_1->Color=BadColor;
         P_U5V->Color=BadColor;
      }
      else                                     // значение в нужных пределах
      {
         P_1->Color=GoodColor;
         P_U5V->Color=GoodColor;
      }

      break;

    case 1:                                    // Значение напряжения источника +12 В
      value=0;
      value=GetACD4Data();                     // Считываем AI4 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
      value=value*2;                           // коэффициент пропорциональности
      min=0;                                   // граничные значения напряжения
      max=6.15*2;

      value = average_U12V(value);             // расчет "скользящего среднего"

      P_U12V->Caption=RoundValue(0.01, FloatToStr(value))+" В"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_2->Color=BadColor;
         P_U12V->Color=BadColor;
      }
      else                                     // значение в нужных пределах
      {
         P_2->Color=GoodColor;
         P_U12V->Color=GoodColor;
      }

      break;

    case 2:                                    // Ток потребления источника +5V
      value=0;
      value=GetACD1Data();                     // Считываем AI1 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
      value=(value-k2)/0.185;                  // коэффициент пропорциональности
      min=(0.5-k2)/0.185;                      // граничные значения тока
      max=(4.5-k2)/0.185;

      value = average_I5V(value);              // расчет "скользящего среднего"

      P_I5V->Caption=RoundValue(0.01, FloatToStr(value))+" А"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_3->Color=BadColor;
         P_I5V->Color=BadColor;
      }
      else                                     // значение в нужных пределах
      {
         P_3->Color=GoodColor;
         P_I5V->Color=GoodColor;
      }

      break;

    case 3:                                    // Ток потребления источника +12V
      value=0;
      value=GetACD5Data();                     // Считываем AI5 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
      value=(value-k3)/0.185;                  // коэффициент пропорциональности
      min=(0.5-k3)/0.185;                      // граничные значения тока
      max=(4.5-k3)/0.185;

      value = average_I12V(value);             // расчет "скользящего среднего"

      P_I12V->Caption=RoundValue(0.01, FloatToStr(value))+" А"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_4->Color=BadColor;
         P_I12V->Color=BadColor;
      }
      else                                     // значение в нужных пределах
      {
         P_4->Color=GoodColor;
         P_I12V->Color=GoodColor;
      }

      break;

    case 4:                                    // Температура окружающей среды
      value=0;
      value=GetACD2Data();                     // Считываем AI2 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
      value=(value-k4)*500;                    // коэффициент пропорциональности
      min=(0.45-k4)*500;                       // граничные значения температуры
      max=(0.75-k4)*500;

      value = average_Temp(value);             // расчет "скользящего среднего"

      P_Temp->Caption=RoundValue(1, FloatToStr(value))+" град. С"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_5->Color=BadColor;
         P_Temp->Color=BadColor;
      }
      else                                     // значение в нужных пределах
      {
         P_5->Color=GoodColor;
         P_Temp->Color=GoodColor;
      }

      break;

    case 5:                                    // СВЧ мощность в точке ВСК2
      value=0;
      value=GetACD6Data();                     // Считываем AI6 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
      if(RB_5GHz->Checked==true)               // частотная коррекция: 5 ГГЦ
      {
        value=-(value-k5)*37.5;                // коэффициент пропорциональности
        min=-(1.75-k5)*37.5;                   // граничные значения мощности
        max=-(0.5-k5)*37.5;
      }
      else                                     // частотная коррекция: 8 ГГЦ
      {
        value=-(value-k6)*46.1538;             // коэффициент пропорциональности
        min=-(1.75-k6)*46.1538;                // граничные значения мощности
        max=-(0.5-k6)*46.1538;
      }
      
      value = average_Power(value);            // расчет "скользящего среднего"

      P_Power->Caption=RoundValue(1, FloatToStr(value))+" dBm"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_6->Color=BadColor;
         P_Power->Color=BadColor;
      }
      else                                     // значение в нужных пределах
      {
         P_6->Color=GoodColor;
         P_Power->Color=GoodColor;
      }

      NIDAQmxCounter=-1;                       // начать отсчёт заново
      break;
  }
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::GetACD0Data() //  Считываем AI0
{
	TaskHandle  taskHandle=0;
	char errBuff[2048]={'\0'};
  int32 read;
	float64 data[NumReadValue];
  double value;
  ErrorADC=false;

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем параметры задачи
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai0","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем тактирование
  if (DAQmxFailed(DAQmxCfgSampClkTiming(taskHandle,"",10000,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,NumReadValue)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Запускаем задачу
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Считываем данные
  if (DAQmxFailed(DAQmxReadAnalogF64(taskHandle,NumReadValue,1.0,DAQmx_Val_GroupByChannel,data,NumReadValue,&read,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Останавливаем и очищаем задачу
  if( taskHandle!=0 )
  {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
  }

  try
  {
    value=0;
    for(int i=0;i<read;i++)
    {
      value+=data[i];
    }

    value/=read;
    return value;
  }

  catch(...)
  {
    ErrorADC=true;
    return 0;
  }
}
//---------------------------------------------------------------------------
String TMain_Form::RoundValue(float delta, String value)
{
  float temp;
  float temp1;

  temp=StrToFloat(value);
  temp1=Log10(delta);         // количество знаков после запятой
  value=RoundTo(temp,temp1);  // округлить до значения с 2-мя десятичными знаками после запятой

  return value;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::GetACD4Data() //  Считываем AI4
{
	TaskHandle  taskHandle=0;
	char errBuff[2048]={'\0'};
  int32 read;
	float64 data[NumReadValue];
  double value;
  ErrorADC=false;

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем параметры задачи
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai4","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем тактирование
  if (DAQmxFailed(DAQmxCfgSampClkTiming(taskHandle,"",10000,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,NumReadValue)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Запускаем задачу
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Считываем данные
  if (DAQmxFailed(DAQmxReadAnalogF64(taskHandle,NumReadValue,1.0,DAQmx_Val_GroupByChannel,data,NumReadValue,&read,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Останавливаем и очищаем задачу
  if( taskHandle!=0 )
  {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
  }

  try
  {
    value=0;
    for(int i=0;i<read;i++)
    {
      value+=data[i];
    }

    value/=read;
    return value;
  }

  catch(...)
  {
    ErrorADC=true;
    return 0;
  }
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::GetACD1Data() //  Считываем AI1
{
	TaskHandle  taskHandle=0;
	char errBuff[2048]={'\0'};
  int32 read;
	float64 data[NumReadValue];
  double value;
  ErrorADC=false;

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем параметры задачи
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai1","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем тактирование
  if (DAQmxFailed(DAQmxCfgSampClkTiming(taskHandle,"",10000,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,NumReadValue)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Запускаем задачу
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Считываем данные
  if (DAQmxFailed(DAQmxReadAnalogF64(taskHandle,NumReadValue,1.0,DAQmx_Val_GroupByChannel,data,NumReadValue,&read,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Останавливаем и очищаем задачу
  if( taskHandle!=0 )
  {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
  }

  try
  {
    value=0;
    for(int i=0;i<read;i++)
    {
      value+=data[i];
    }

    value/=read;
    return value;
  }

  catch(...)
  {
    ErrorADC=true;
    return 0;
  }
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::GetACD5Data() //  Считываем AI5
{
	TaskHandle  taskHandle=0;
	char errBuff[2048]={'\0'};
  int32 read;
	float64 data[NumReadValue];
  double value;
  ErrorADC=false;

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем параметры задачи
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai5","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем тактирование
  if (DAQmxFailed(DAQmxCfgSampClkTiming(taskHandle,"",10000,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,NumReadValue)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Запускаем задачу
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Считываем данные
  if (DAQmxFailed(DAQmxReadAnalogF64(taskHandle,NumReadValue,1.0,DAQmx_Val_GroupByChannel,data,NumReadValue,&read,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Останавливаем и очищаем задачу
  if( taskHandle!=0 )
  {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
  }

  try
  {
    value=0;
    for(int i=0;i<read;i++)
    {
      value+=data[i];
    }

    value/=read;
    return value;
  }

  catch(...)
  {
    ErrorADC=true;
    return 0;
  }
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::GetACD2Data() //  Считываем AI2
{
	TaskHandle  taskHandle=0;
	char errBuff[2048]={'\0'};
  int32 read;
	float64 data[NumReadValue];
  double value;
  ErrorADC=false;

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем параметры задачи
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai2","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем тактирование
  if (DAQmxFailed(DAQmxCfgSampClkTiming(taskHandle,"",10000,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,NumReadValue)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Запускаем задачу
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Считываем данные
  if (DAQmxFailed(DAQmxReadAnalogF64(taskHandle,NumReadValue,1.0,DAQmx_Val_GroupByChannel,data,NumReadValue,&read,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Останавливаем и очищаем задачу
  if( taskHandle!=0 )
  {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
  }

  try
  {
    value=0;
    for(int i=0;i<read;i++)
    {
      value+=data[i];
    }

    value/=read;
    return value;
  }

  catch(...)
  {
    ErrorADC=true;
    return 0;
  }
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::GetACD6Data() //  Считываем AI6
{
	TaskHandle  taskHandle=0;
	char errBuff[2048]={'\0'};
  int32 read;
	float64 data[NumReadValue];
  double value;
  ErrorADC=false;

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем параметры задачи
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,"Dev1/ai6","",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Определяем тактирование
  if (DAQmxFailed(DAQmxCfgSampClkTiming(taskHandle,"",10000,DAQmx_Val_Rising,DAQmx_Val_FiniteSamps,NumReadValue)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Запускаем задачу
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Считываем данные
  if (DAQmxFailed(DAQmxReadAnalogF64(taskHandle,NumReadValue,1.0,DAQmx_Val_GroupByChannel,data,NumReadValue,&read,NULL)))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    ErrorADC=true;
  }

  // Останавливаем и очищаем задачу
  if( taskHandle!=0 )
  {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
  }

  try
  {
    value=0;
    for(int i=0;i<read;i++)
    {
      value+=data[i];
    }

    value/=read;
    return value;
  }

  catch(...)
  {
    ErrorADC=true;
    return 0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_SendClick(TObject *Sender)
{
  ComPortTransmitter();
/*
    Время на передачу одного блока информации о 27 регистрах Tпер = Vпер*Nбит*Nбайт =
    = (1/57600 бит/с)*(11 бит = 1старт+8+1чётн+1стоп)*(6 регистров*256байт+17 регистров*4байт)
    = 30,6 мс.

    start|1|2|3|4|5|6|7|8|parity|stop1 карта сигнала, передаваемого по интерфейсу RS-232
*/  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ComPortTransmitter(void)
{
  CommPort1->Open=true;

  if(CommPort1->BaudRate==cbr9600)               // передача на Serial Input/Output Monitor
  {
    SendTerminal();
  }
  else                                           // передача на ППРМ-2, BaudRate=57600
  {
    //CommPort1->PutChar(0xAA);                  // маркер передачи на контроллер (отладка)

    if(RG_Mode->ItemIndex==0)                    // если режим "Управление"
    {
      SendControl();
    }
    else                                         // если режим "Тестирование"
    {
      SendTesting();
    }
  }
  CommPort1->Open=false;
}
/*************************************************************************
Function: uart_puthex_byte()
Purpose:  transmit upper and lower nibble as ASCII-hex to UART
Input:    byte value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TMain_Form::uart_puthex_byte(unsigned char  b)
 { uart_puthex_nibble(b>>4);
   uart_puthex_nibble(b);
 } /* uart_puthex_byte */
/*************************************************************************
Function: uart_puthex_nibble()
Purpose:  transmit lower nibble as ASCII-hex to UART
Input:    byte value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TMain_Form::uart_puthex_nibble(unsigned char b)
 { unsigned char  c = b & 0x0f;
   if (c>9) c += 'A'-10;
   else c += '0';
   CommPort1->PutChar(c);  // строчка преобразована для проекта
 } /* uart_puthex_nibble */
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_U5V(float znachenie)
// Подпрограмма расчета "скользящего среднего"
{
  Buff0[N_zamera0]=znachenie;                   // заносим новый замер в "очередь"
  unsigned char i;                              // 0..0x0ff

  // считаем среднее из "очереди":
  for (sum0=0,i=0; i<10; i++)
  {
    sum0 += Buff0[i];
  }

  sum0=sum0/10;
  znachenie = sum0;
  N_zamera0++;

  if (N_zamera0 == 10)
  {
    N_zamera0 = 0;
    AddSaveLog("Значение напряжения источника +5 В составило "+P_U5V->Caption);  // добавить комментарий и сохранить лог
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_U12V(float znachenie)
// Подпрограмма расчета "скользящего среднего"
{
  Buff1[N_zamera1]=znachenie;                   // заносим новый замер в "очередь"
  unsigned char i;                              // 0..0x0ff

  // считаем среднее из "очереди":
  for (sum1=0,i=0; i<10; i++)
  {
    sum1 += Buff1[i];
  }

  sum1=sum1/10;
  znachenie = sum1;
  N_zamera1++;

  if (N_zamera1 == 10)
  {
    N_zamera1 = 0;
    AddSaveLog("Значение напряжения источника +12 В составило "+P_U12V->Caption);  // добавить комментарий и сохранить лог
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_I5V(float znachenie)
// Подпрограмма расчета "скользящего среднего"
{
  Buff2[N_zamera2]=znachenie;                   // заносим новый замер в "очередь"
  unsigned char i;                              // 0..0x0ff

  // считаем среднее из "очереди":
  for (sum2=0,i=0; i<10; i++)
  {
    sum2 += Buff2[i];
  }

  sum2=sum2/10;
  znachenie = sum2;
  N_zamera2++;

  if (N_zamera2 == 10)
  {
    N_zamera2 = 0;
    AddSaveLog("Значение тока источника +5 В составило "+P_I5V->Caption);  // добавить комментарий и сохранить лог
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_I12V(float znachenie)
// Подпрограмма расчета "скользящего среднего"
{
  Buff3[N_zamera3]=znachenie;                   // заносим новый замер в "очередь"
  unsigned char i;                              // 0..0x0ff

  // считаем среднее из "очереди":
  for (sum3=0,i=0; i<10; i++)
  {
    sum3 += Buff3[i];
  }

  sum3=sum3/10;
  znachenie = sum3;
  N_zamera3++;

  if (N_zamera3 == 10)
  {
    N_zamera3 = 0;
    AddSaveLog("Значение тока источника +12 В составило "+P_I12V->Caption);  // добавить комментарий и сохранить лог
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_Temp(float znachenie)
// Подпрограмма расчета "скользящего среднего"
{
  Buff4[N_zamera4]=znachenie;                   // заносим новый замер в "очередь"
  unsigned char i;                              // 0..0x0ff

  // считаем среднее из "очереди":
  for (sum4=0,i=0; i<10; i++)
  {
    sum4 += Buff4[i];
  }

  sum4=sum4/10;
  znachenie = sum4;
  N_zamera4++;

  if (N_zamera4 == 10)
  {
    N_zamera4 = 0;
    AddSaveLog("Температура окружающей среды составила "+P_Temp->Caption);  // добавить комментарий и сохранить лог
  }

  return znachenie;
}
//---------------------------------------------------------------------------
float __fastcall TMain_Form::average_Power(float znachenie)
// Подпрограмма расчета "скользящего среднего"
{
  Buff5[N_zamera5]=znachenie;                   // заносим новый замер в "очередь"
  unsigned char i;                              // 0..0x0ff

  // считаем среднее из "очереди":
  for (sum5=0,i=0; i<10; i++)
  {
    sum5 += Buff5[i];
  }

  sum5=sum5/10;
  znachenie = sum5;
  N_zamera5++;

  if (N_zamera5 == 10)
  {
    N_zamera5 = 0;
    AddSaveLog("СВЧ мощность в точке ВСК2 составила "+P_Power->Caption);  // добавить комментарий и сохранить лог
  }

  return znachenie;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_SaveControlClick(TObject *Sender)
{
  AddSaveLog("Сохранить файл результатов в режиме Управление");  // добавить комментарий и сохранить лог

  SaveDialog->DefaultExt=".ctr";
  SaveDialog->FileName="*.ctr";
  SaveDialog->Filter="Файл режима Управление (*.ctr)|*.ctr";
  SaveDialog->Title=" Сохранение файла режима Управление";

  String File;
  FILE *F;

  if(SaveDialog->Execute())
  {
    File=SaveDialog->FileName;
    FileControl=File;
    if(F!=NULL)
    {
      F=fopen(File.c_str(),"w+"); // открыть файл с перезаписью
      fclose(F);                  // закрыть файл
    }
    Ini= new TIniFile(File); // создание нового файла .ini
/*
    Ini->WriteString("Название секции","Имя переменной", "значение");
*/
    // Время и дата
    Ini->WriteString("Время и дата","Время и дата",P_SystemTime->Caption);
    // Задержка между командами
    Ini->WriteString("Данные в режиме Управление","Задержка между командами",E_Delay->Text);
    // Количество БТ
    Ini->WriteString("Данные в режиме Управление","Количество БТ",E_Command3_0->Text);
    // Command1
    Ini->WriteString("Данные в режиме Управление","Команда \"Начать работу\"",IntToStr(Command1[2])); // запись из массива в файл
    // Command3
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
      Ini->WriteString("Данные в режиме Управление","Команда \"Амплитуда блестящей точки (БТ)\""+IntToStr(i+1)+"\"",Command3[i][3]);  // запись из массива в файл
    }
    // Command4
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
      int Command=Command4[i][3]+Command4[i][2]*256;
      Ini->WriteString("Данные в режиме Управление","Команда \"Время задержки (БТ)\""+IntToStr(i+1)+"\"",Command);   // запись из массива в файл
    }
    // Command5, цена младшего разряда 0.5 Гц
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
      Ini->WriteString("Данные в режиме Управление","Команда \"Знак доплеровского сдвига частоты (БТ)\""+IntToStr(i+1)+"\"",D_SignC[i]);  // запись из массива в файл
      int Command=(Command5[i][3]+Command5[i][2]*256);
      Ini->WriteString("Данные в режиме Управление","Команда \"Доплеровский сдвиг частоты (БТ)\""+IntToStr(i+1)+"\"",Command);  // запись из массива в файл
    }
    // Количество модулей
    Ini->WriteString("Данные в режиме Управление","Количество модулей",E_NumbOfMods->Text);
    // Количество частот
    Ini->WriteString("Данные в режиме Управление","Количество частот",E_NumbOfFreq->Text);
    // Индивид-ый # модуля
    for(int i=0; i<StrToInt(E_NumbOfMods->Text); i++)
    {
      Ini->WriteString("Данные в режиме Управление","Индивид-ый # модуля"+IntToStr(i+1)+"\"",ModNumber[i]);  // запись из массива в файл
    }
    // Команда "Центральная частота"
    for(int i=0; i<StrToInt(E_NumbOfMods->Text); i++)
    {
      for(int j=0; j<StrToInt(E_NumbOfFreq->Text); j++)
      {
        int Freq=Mod[i][j][0]*256+Mod[i][j][1];
        Ini->WriteString("Данные в режиме Управление","Команда \"Центральная частота рабочей полосы\", Модуль"+IntToStr(i+1)+", частота"+IntToStr(j+1)+"\"",Freq);  // запись из массива в файл
      }
    }
    // Команда "Коэф-т ослабления"
    for(int i=0; i<StrToInt(E_NumbOfMods->Text); i++)
    {
      for(int j=0; j<StrToInt(E_NumbOfFreq->Text); j++)
      {
        Ini->WriteString("Данные в режиме Управление","Команда \"Коэф-т ослабления\", Модуль"+IntToStr(i+1)+", частота"+IntToStr(j+1)+"\"",IntToStr(Mod[i][j][2]));  // запись из массива в файл
      }
    }
    // Команда "Сдвиг разрядов"
    for(int i=0; i<StrToInt(E_NumbOfMods->Text); i++)
    {
      for(int j=0; j<StrToInt(E_NumbOfFreq->Text); j++)
      {
        Ini->WriteString("Данные в режиме Управление","Команда \"Сдвиг разрядов\", Модуль"+IntToStr(i+1)+", частота"+IntToStr(j+1)+"\"",IntToStr(Mod[i][j][3]));  // запись из массива в файл
      }
    }
    delete Ini;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ChB_LogClick(TObject *Sender)
{
  if(ChB_Log->Checked==true) M_Log->Visible=false;
  else                       M_Log->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_LoadControlClick(TObject *Sender)
{
  AddSaveLog("Загрузить файл результатов в режиме Управление");  // добавить комментарий и сохранить лог

  ResetBPControl();

  OpenDialog->DefaultExt=".ctr";
  OpenDialog->FileName="*.ctr";
  OpenDialog->Filter="Файл режима Управление (*.ctr)|*.ctr";
  OpenDialog->Title=" Загрузка файла режима Управление";

  String File;

  if(OpenDialog->Execute())
  {
    File=OpenDialog->FileName;
    FileControl=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("Название секции","Имя переменной", "значение");
*/
      // Задержка между командами
      E_Delay->Text=Ini->ReadString("Данные в режиме Управление","Задержка между командами","1");                // считать из файла в массив
      // Количество БТ
      E_Command3_0->Text=Ini->ReadString("Данные в режиме Управление","Количество БТ","1");                // считать из файла в массив
      // Command1
      Command1[2]=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Начать работу\"","0")); // считать из файла в массив
      for(int i=0; i<3; i++)
      {
        if(Command1[2]==i) CB_Command1->ItemIndex=i; // запись в форму
      }
      // Command3, Command4, Command5 
      for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
      {
        // Command3
        Command3[i][3]=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Амплитуда блестящей точки (БТ)\""+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
        // Command4
        int Comm4=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Время задержки (БТ)\""+IntToStr(i+1)+"\"","0"));                    // считать из файла в массив
        Command4[i][3]=Comm4&0xFF;                // мл. байт
        Command4[i][2]=(Comm4/256)&0xFF;          // ст. байт
        // Command5, цена младшего разряда 0.5 Гц
        D_SignC[i]=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Знак доплеровского сдвига частоты (БТ)\""+IntToStr(i+1)+"\"","0")); // считать из файла
        if(D_SignC[i]==0) CB_SignC->ItemIndex=0;
        else              CB_SignC->ItemIndex=1;

        int Comm5=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Доплеровский сдвиг частоты (БТ)\""+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
        Command5[i][3]=Comm5&0xFF;                // мл. байт
        Command5[i][2]=(Comm5/256)&0xFF;          // ст. байт
      }
      CB_Command3_1->Clear();                     // очистить предыдущее количество БТ

      for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
      {
        CB_Command3_1->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
      }

      CB_Command3_1->ItemIndex=OldIndex;          // номер БТ по умолчанию при изменении числа БТ
      E_Command3->Text=Command3[OldIndex][3];                           // показать текущее значение
      E_Command4->Text=Command4[OldIndex][3]+Command4[OldIndex][2]*256; // показать текущее значение
      E_Command5->Text=Command5[OldIndex][3]+Command5[OldIndex][2]*256; // показать текущее значение

      // Команды "Центральная частота" и "Коэф-т ослабления"
      // Количество модулей
      E_NumbOfMods->Text=Ini->ReadString("Данные в режиме Управление","Количество модулей","1");
      // Количество частот
      E_NumbOfFreq->Text=Ini->ReadString("Данные в режиме Управление","Количество частот","1");
      // Индивид-ый # модуля
      for(int i=0; i<StrToInt(E_NumbOfMods->Text); i++)
      {
        ModNumber[i] = StrToInt(Ini->ReadString("Данные в режиме Управление","Индивид-ый # модуля"+IntToStr(i+1)+"\"","0"));  // считать из файла
      }
      CB_Modulus->Clear();                        // очистить предыдущее количество модулей

      for(int i=0;i<StrToInt(E_NumbOfMods->Text);i++)
      {
        CB_Modulus->Items->Add(IntToStr(i+1));    // увеличить количество модулей в поле "Модуль №"
      }

      CB_Modulus->ItemIndex=OldIndexMod;          // номер модуля по умолчанию при изменении числа модулей
      E_Mod->Text=ModNumber[OldIndexMod];         // показать текущее значение
      // Команда "Центральная частота" и "Коэф-т ослабления"
      for(int i=0; i<StrToInt(E_NumbOfMods->Text); i++)
      {
        for(int j=0; j<StrToInt(E_NumbOfFreq->Text); j++)   
        {
          // Команда "Центральная частота"
          int Freq=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Центральная частота рабочей полосы\", Модуль"+IntToStr(i+1)+", частота"+IntToStr(j+1)+"\"","0"));  // считать из файла
          Mod[i][j][1]=Freq&0xFF;                 // мл. байт
          Mod[i][j][0]=(Freq/256)&0xFF;           // ст. байт

          Command6[3]=Mod[i][j][1];               // мл. байт
          Command6[2]=Mod[i][j][0];               // ст. байт

          // Команда "Коэф-т ослабления"
          Mod[i][j][2]=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Коэф-т ослабления\", Модуль"+IntToStr(i+1)+", частота"+IntToStr(j+1)+"\"","0")); // считать из файла

          Command7[3]=Mod[i][j][2];             

          // Команда "Сдвиг разрядов"
          Mod[i][j][3]=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Сдвиг разрядов\", Модуль"+IntToStr(i+1)+", частота"+IntToStr(j+1)+"\"","0")); // считать из файла

          Shift[3]=Mod[i][j][3];
        }
      }
      CB_Modulus->Clear();                        // очистить предыдущее количество модулей
      CB_Frequency->Clear();                      // очистить предыдущее количество частот

      for(int i=0;i<StrToInt(E_NumbOfMods->Text);i++)
      {
        CB_Modulus->Items->Add(IntToStr(i+1));    // увеличить количество модулей в полях "Модуль №"
      }

      for(int i=0;i<StrToInt(E_NumbOfFreq->Text);i++)
      {
        CB_Frequency->Items->Add(IntToStr(i+1));  // увеличить количество частот в полях "Номер частоты"
      }

      CB_Modulus->ItemIndex=OldIndexMod;          // номер модуля по умолчанию при изменении числа модулей
      int Old = OldIndexF[OldIndexMod];
      CB_Frequency->ItemIndex=Old;                // номер частоты по умолчанию при изменении числа частот

      // показать текущее значение:
      E_Command6->Text=IntToStr(10*(Mod[OldIndexMod][Old][0]*256+Mod[OldIndexMod][Old][1])+8500);
      // показать текущее значение:
      for(int z=0; z<NUMBOFREQS; z++)
      {
        if(Mod[OldIndexMod][Old][2]==63-z)
        {
          CB_Command7->ItemIndex=z;
        }
      }
      // показать текущее значение:
      for(int z=0; z<7; z++)
      {
        if(Mod[OldIndexMod][Old][3]==z)
        {
          CB_Shift->ItemIndex=z;
        }
      }

      AddSaveLog("Загружен файл "+FileControl);  // добавить комментарий и сохранить лог

      delete Ini;
    }
    else
    {
      ShowError(FileNotExist, 0, 0, "");
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command3Change(TObject *Sender)
// по изменении параметра в поле редактирования
{
  int Comm3;
  if(E_Command3->Text=="") E_Command3->Text=0;
  Comm3=StrToInt(E_Command3->Text);                   // записать текущее значение в переменную
  Command3[OldIndex][3]=Comm3&0xFF;                   // записать байт по индексу OldIndex в массив
/*
  Значение записывается по индексу OldIndex, т.к. этот индекс старый относительно
  метода "по изменении номера БТ" CB_Command3_1Change(TObject *Sender).
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command4Change(TObject *Sender)
// по изменении параметра в поле редактирования
{
  int Comm4;
  if(E_Command4->Text=="") E_Command4->Text=0;
  Comm4=StrToInt(E_Command4->Text);                   // записать текущее значение в переменную
  // записать текущее значение по индексу OldIndex в массив:
  Command4[OldIndex][3]=Comm4&0xFF;                   // мл. байт
  Command4[OldIndex][2]=(Comm4/256)&0xFF;             // ст. байт
/*
  Значение записывается по индексу OldIndex, т.к. этот индекс старый относительно
  метода "по изменении номера БТ" CB_Command3_1Change(TObject *Sender).
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command3Exit(TObject *Sender)
// по изменении фокуса с данного поля редактирования
{
  bool b;
  int min=0;
  int max=255;
  int delta=1;
  String EdIzm="";
  String value;

  value=E_Command3->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Command3->Text=RoundValue(delta,value);           // записать текущее значение в переменную
    // записать текущее значение по индексу OldIndex в массив:
    Command3[OldIndex][3]=StrToInt(E_Command3->Text);
/*
    Значение записывается по индексу OldIndex, т.к. этот индекс старый относительно
    метода "по изменении номера БТ" CB_Command3_1Change(TObject *Sender).
*/    
  }
  else
  {
    E_Command3->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command4Exit(TObject *Sender)
// по изменении фокуса с данного поля редактирования
{
  bool b;
  int min=0;
  int max=63;
  int delta=1;
  String EdIzm="нс";
  String value;

  value=E_Command4->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Command4->Text=RoundValue(delta,value);
    int Comm4=StrToInt(E_Command4->Text);               // записать текущее значение в переменную
    // записать текущее значение по индексу OldIndex в массив:
    Command4[OldIndex][3]=Comm4&0xFF;                   // мл. байт
    Command4[OldIndex][2]=(Comm4/256)&0xFF;             // ст. байт
/*
    Значение записывается по индексу OldIndex, т.к. этот индекс старый относительно
    метода "по изменении номера БТ" CB_Command3_1Change(TObject *Sender).
*/
  }
  else
  {
    E_Command4->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command5Change(TObject *Sender)
// по изменении параметра в поле редактирования
{
  float Comm5;
  if(E_Command5->Text=="") E_Command5->Text=0;
  Comm5=StrToFloat(E_Command5->Text);            // записать текущее значение в переменную
  // записать текущее значение по индексу OldIndex в массив:
  Command5[OldIndex][3]=(int)Comm5&0xFF;         // мл. байт
  Command5[OldIndex][2]=((int)Comm5/256)&0xFF;   // ст. байт
/*
  Значение записывается по индексу OldIndex, т.к. этот индекс старый относительно
  метода "по изменении номера БТ" CB_Command3_1Change(TObject *Sender).
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command5Exit(TObject *Sender)
// по изменении фокуса с данного поля редактирования
{
  bool b;
  float min=-16384;   // -32768*0.5
  float max=16383.5;  // 32767*0.5
  float delta=0.5;    // цена младшего разряда 0.5 Гц
  String EdIzm="гц";
  String value;

  value=E_Command5->Text;

  b=IsValid(min,max,value,EdIzm);
  if(b)
  {
    E_Command5->Text=RoundValue(delta,value);
    float Comm5=StrToFloat(E_Command5->Text);               // записать текущее значение в переменную
    // записать текущее значение по индексу OldIndex в массив:    
    Command5[OldIndex][3]=(int)Comm5&0xFF;                  // мл. байт
    Command5[OldIndex][2]=((int)Comm5/256)&0xFF;            // ст. байт
/*
    Значение записывается по индексу OldIndex, т.к. этот индекс старый относительно
    метода "по изменении номера БТ" CB_Command3_1Change(TObject *Sender).
*/
  }
  else
  {
    E_Command5->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com3Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=255;
  int delta=1;
  String EdIzm="";
  String value;

  value=E_Com3->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Com3->Text=RoundValue(delta,value);
    Com3[OldIndex_][3]=StrToInt(E_Com3->Text);
  }
  else
  {
    E_Com3->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com3Change(TObject *Sender)
{
  int Comm3;
  if(E_Com3->Text=="") E_Com3->Text=0;
  Comm3=StrToInt(E_Com3->Text);                  // записать значение в переменную
  Com3[OldIndex_][3]=Comm3&0xFF;                 // мл. байт
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com4Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=65535;
  int delta=1;
  String EdIzm="нс";
  String value;

  value=E_Com4->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Com4->Text=RoundValue(delta,value);
    int Comm4=StrToInt(E_Com4->Text);               // записать значение в переменную
    Com4[OldIndex_][3]=Comm4&0xFF;                   // мл. байт
    Com4[OldIndex_][2]=(Comm4/256)&0xFF;             // ст. байт
  }
  else
  {
    E_Com4->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com4Change(TObject *Sender)
{
  int Comm4;
  if(E_Com4->Text=="") E_Com4->Text=0;
  Comm4=StrToInt(E_Com4->Text);                   // записать значение в переменную
  Com4[OldIndex_][3]=Comm4&0xFF;                  // мл. байт
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;            // ст. байт
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com5Exit(TObject *Sender)
{
  bool b;
  float min=0;
  float max=16383.75;  // 65535*0.5/2
  float delta=0.5;
  String EdIzm="гц";
  String value;

  value=E_Com5->Text;

  b=IsValid(min,max,value,EdIzm);
  if(b)
  {
    E_Com5->Text=RoundValue(delta,value);
    float Comm5=StrToInt(E_Com5->Text);             // записать значение в [гц] в переменную, цена младшего разряда 0.5 Гц
    Com5[OldIndex_][3]=(int)Comm5&0xFF;             // мл. байт
    Com5[OldIndex_][2]=((int)Comm5/256)&0xFF;       // ст. байт
  }
  else
  {
    E_Com5->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com5Change(TObject *Sender)
{
  float Comm5;
  if(E_Com5->Text=="") E_Com5->Text=0;
  Comm5=StrToFloat(E_Com5->Text);                  // записать значение в [гц] в переменную, цена младшего разряда 0.5 Гц
  Com5[OldIndex_][3]=(int)Comm5&0xFF;              // мл. байт
  Com5[OldIndex_][2]=((int)Comm5/256)&0xFF;        // ст. байт
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_SaveTestingClick(TObject *Sender)
{
  AddSaveLog("Сохранить файл результатов в режиме Тестирование");  // добавить комментарий и сохранить лог

  SaveDialog->DefaultExt=".tst";
  SaveDialog->FileName="*.tst";
  SaveDialog->Filter="Файл режима Управление (*.tst)|*.tst";
  SaveDialog->Title=" Сохранение файла режима Тестирование";

  String File;
  FILE *F;

  if(SaveDialog->Execute())
  {
    File=SaveDialog->FileName;
    FileControl=File;
    if(F!=NULL)
    {
      F=fopen(File.c_str(),"w+"); // открыть файл с перезаписью
      fclose(F);                  // закрыть файл
    }
    Ini= new TIniFile(File); // создание нового файла .ini
/*
    Ini->WriteString("Название секции","Имя переменной", "значение");
*/
    Ini->WriteString("Время и дата","Время и дата",P_SystemTime->Caption);
    Ini->WriteString("Данные в режиме Тестирование","Количество БТ",E_Com3_0->Text);
    // Com1
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Начать работу\"",IntToStr(Com1[2])); // запись из массива в файл
    // Com3
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
    {
      Ini->WriteString("Данные в режиме Тестирование","Команда \"Амплитуда блестящей точки (БТ)\""+IntToStr(i+1)+"\"",Com3[i][3]);  // запись из массива в файл
    }
    // Com4
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
    {
      int Command=Com4[i][3]+Com4[i][2]*256;
      Ini->WriteString("Данные в режиме Тестирование","Команда \"Время задержки (БТ)"+IntToStr(i+1)+"\"",Command);   // запись из массива в файл
    }
    // Com5, цена младшего разряда 0.5 Гц
    for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
    {
      Ini->WriteString("Данные в режиме Тестирование","Команда \"Знак доплеровского сдвига частоты (БТ)\""+IntToStr(i+1)+"\"",D_SignT[i]);  // запись из массива в файл
      int Command=(Com5[i][3]+Com5[i][2]*256);
      Ini->WriteString("Данные в режиме Тестирование","Команда \"Доплеровский сдвиг частоты (БТ)\""+IntToStr(i+1)+"\"",Command);  // запись из массива в файл
    }
    // Команда "Сдвиг разрядов"
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Сдвиг разрядов\"",IntToStr(Shift_[3])); // запись из массива в файл
    // Com6
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Коэффициент ослабления приёмника ППРМ-2\"",IntToStr(Com6[3]));   // запись из массива в файл
    // Com7
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Коэффициент ослабления передатчика ППРМ-2\"",IntToStr(Com7[3])); // запись из массива в файл
    // Com8
    int Comm8=Com8[3]+Com8[2]*256;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Частота среза фильтра гетеродина приёмника ППРМ-2\"",Comm8);  // запись из массива в файл
    // Com9
    int Comm9=Com9[3]+Com9[2]*256;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Частота среза фильтра гетеродина передатчика ППРМ-2\"",Comm9);  // запись из массива в файл
    // Com10
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Код управления входным преселектором\"",IntToStr(Com10[3])); // запись из массива в файл
    // Com11
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Код управления выходным преселектором\"",IntToStr(Com11[3])); // запись из массива в файл
    // Com12
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Код управления блоком гетеродинов\"",IntToStr(Com12[3])); // запись из массива в файл
    // Com13
    unsigned long int Comm13=Com13[3]+Com13[2]*256+Com13[1]*65536;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 1\"",Comm13); // запись из массива в файл
    // Com14
    unsigned long int Comm14=Com14[3]+Com14[2]*256+Com14[1]*65536;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 2\"",Comm14); // запись из массива в файл
    // Com15
    unsigned long int Comm15=Com15[3]+Com15[2]*256+Com15[1]*65536;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 3\"",Comm15); // запись из массива в файл
    // Com16
    unsigned long int Comm16=Com16[3]+Com16[2]*256+Com16[1]*65536;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 4\"",Comm16); // запись из массива в файл
    // Com17
    unsigned long int Comm17=Com17[3]+Com17[2]*256+Com17[1]*65536;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 5\"",Comm17); // запись из массива в файл
    // Com18
    unsigned long int Comm18=Com18[3]+Com18[2]*256+Com18[1]*65536;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 6\"",Comm18); // запись из массива в файл
    // Com19
    unsigned long int Comm19=Com19[3]+Com19[2]*256+Com19[1]*65536;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 7\"",Comm19); // запись из массива в файл
    // Com20
    unsigned long int Comm20=Com20[3]+Com20[2]*256+Com20[1]*65536;
    Ini->WriteString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 8\"",Comm20); // запись из массива в файл

    delete Ini;
  }  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::TB_LoadTestingClick(TObject *Sender)
{
  AddSaveLog("Загрузить файл результатов в режиме Тестирование");  // добавить комментарий и сохранить лог

  ResetBPTesting();

  OpenDialog->DefaultExt=".tst";
  OpenDialog->FileName="*.tst";
  OpenDialog->Filter="Файл режима Тестирование (*.tst)|*.tst";
  OpenDialog->Title=" Загрузка файла режима Тестирование";

  String File;

  if(OpenDialog->Execute())
  {
    File=OpenDialog->FileName;
    FileTesting=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("Название секции","Имя переменной", "значение");
*/
      // Количество БТ
      E_Com3_0->Text=Ini->ReadString("Данные в режиме Тестирование","Количество БТ","1");
      // Com1
      Com1[2]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Начать работу\"","0")); // считать из файла в массив
      for(int i=0; i<3; i++)
      {
        if(Com1[2]==i) CB_Com1->ItemIndex=i; // запись в форму
      }
      // Com3, Com4, Com5 
      for(int i=0; i<StrToInt(E_Com3_0->Text); i++)
      {
        // Com3
        Com3[i][3]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Амплитуда блестящей точки (БТ)\""+IntToStr(i+1)+"\"","0")); // считать из файла в массив
        // Com4
        int Comm4=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Время задержки (БТ)"+IntToStr(i+1)+"\"","0"));             // считать из файла в массив
        Com4[i][3]=Comm4&0xFF;                // мл. байт
        Com4[i][2]=(Comm4/256)&0xFF;          // ст. байт
        // Com5, цена младшего разряда 0.5 Гц
        D_SignT[i]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Знак доплеровского сдвига частоты (БТ)\""+IntToStr(i+1)+"\"","0")); // считать из файла
        if(D_SignT[i]==0) CB_SignT->ItemIndex=0;
        else              CB_SignT->ItemIndex=1;
        
        int Comm5=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Доплеровский сдвиг частоты (БТ)\""+IntToStr(i+1)+"\"","0")); // считать из файла в массив
        Com5[i][3]=Comm5&0xFF;                // мл. байт
        Com5[i][2]=(Comm5/256)&0xFF;          // ст. байт
      }
      CB_Com3_1->Clear();                     // очистить предыдущее количество БТ

      for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
      {
        CB_Com3_1->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
      }

      CB_Com3_1->ItemIndex=OldIndex_;         // номер БТ по умолчанию при изменении числа БТ
      E_Com3->Text=Com3[OldIndex_][3];                        // показать текущее значение
      E_Com4->Text=Com4[OldIndex_][3]+Com4[OldIndex_][2]*256; // показать текущее значение
      E_Com5->Text=Com5[OldIndex_][3]+Com5[OldIndex_][2]*256; // показать текущее значение
      // Команда "Сдвиг разрядов"
      Shift_[3]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Сдвиг разрядов\"","0")); // считать из файла в массив
      for(int i=0; i<7; i++)
      {
        if(Shift_[3]==i) CB_Shift_->ItemIndex=i; // запись в форму
      }
      // Com6
      Com6[3]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Коэффициент ослабления приёмника ППРМ-2\"","0")); // считать из файла в массив
      for(int i=0; i<64; i++)
      {
        if(Com6[3]==63-i) CB_Com6->ItemIndex=i; // запись в форму
      }
      // Com7
      Com7[3]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Коэффициент ослабления передатчика ППРМ-2\"","0")); // считать из файла в массив
      for(int i=0; i<64; i++)
      {
        if(Com7[3]==63-i) CB_Com7->ItemIndex=i; // запись в форму
      }
      // Com8
      int Comm8=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Частота среза фильтра гетеродина приёмника ППРМ-2\"","0"));      // считать из файла в массив
      Com8[3]=Comm8&0xFF;                       // мл. байт
      Com8[2]=(Comm8/256)&0xFF;                 // ст. байт
      for(int i=0; i<=15; i++)
      {
        if(Comm8==14+i*128) CB_Com8->ItemIndex=i;      // запись в форму
      }
      // Com9
      int Comm9=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Частота среза фильтра гетеродина приёмника ППРМ-2\"","0"));      // считать из файла в массив
      Com9[3]=Comm9&0xFF;                       // мл. байт
      Com9[2]=(Comm9/256)&0xFF;                 // ст. байт
      for(int i=0; i<=15; i++)
      {
        if(Comm9==14+i*128) CB_Com9->ItemIndex=i;      // запись в форму
      }
      // Com10
      Com10[3]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Код управления входным преселектором\"","0")); // считать из файла в массив
      for(int i=0; i<=3; i++)
      {
        if(Com10[3]==i) CB_Com10->ItemIndex=i; // запись в форму
      }
      // Com11
      Com11[3]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Код управления выходным преселектором\"","0")); // считать из файла в массив
      for(int i=0; i<=3; i++)
      {
        if(Com11[3]==i) CB_Com11->ItemIndex=i; // запись в форму
      }
      // Com12
      Com12[3]=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Код управления блоком гетеродинов\"","0")); // считать из файла в массив
      for(int i=0; i<2; i++)
      {
        if(Com12[3]==i) CB_Com12->ItemIndex=i; // запись в форму
      }
      // Com13
      unsigned long int Comm13=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 1\"","0"));      // считать из файла в массив
      Com13[3]=Comm13&0xFF;                    // мл. байт
      Com13[2]=(Comm13/256)&0xFF;              // ср. байт
      Com13[1]=(Comm13/65536)&0xFF;            // ст. байт
      E_Com13_1->Text=IntToStr(Com13[1]);
      E_Com13_2->Text=IntToStr(Com13[2]);
      E_Com13_3->Text=IntToStr(Com13[3]);
      // Com14
      unsigned long int Comm14=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 2\"","0"));      // считать из файла в массив
      Com14[3]=Comm14&0xFF;                    // мл. байт
      Com14[2]=(Comm14/256)&0xFF;              // ср. байт
      Com14[1]=(Comm14/65536)&0xFF;            // ст. байт
      E_Com14_1->Text=IntToStr(Com14[1]);
      E_Com14_2->Text=IntToStr(Com14[2]);
      E_Com14_3->Text=IntToStr(Com14[3]);
      // Com15
      unsigned long int Comm15=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 3\"","0"));      // считать из файла в массив
      Com15[3]=Comm15&0xFF;                    // мл. байт
      Com15[2]=(Comm15/256)&0xFF;              // ср. байт
      Com15[1]=(Comm15/65536)&0xFF;            // ст. байт
      E_Com15_1->Text=IntToStr(Com15[1]);
      E_Com15_2->Text=IntToStr(Com15[2]);
      E_Com15_3->Text=IntToStr(Com15[3]);
      // Com16
      unsigned long int Comm16=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 4\"","0"));      // считать из файла в массив
      Com16[3]=Comm16&0xFF;                    // мл. байт
      Com16[2]=(Comm16/256)&0xFF;              // ср. байт
      Com16[1]=(Comm16/65536)&0xFF;            // ст. байт
      E_Com16_1->Text=IntToStr(Com16[1]);
      E_Com16_2->Text=IntToStr(Com16[2]);
      E_Com16_3->Text=IntToStr(Com16[3]);
      // Com17
      unsigned long int Comm17=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 5\"","0"));      // считать из файла в массив
      Com17[3]=Comm17&0xFF;                    // мл. байт
      Com17[2]=(Comm17/256)&0xFF;              // ср. байт
      Com17[1]=(Comm17/65536)&0xFF;            // ст. байт
      E_Com17_1->Text=IntToStr(Com17[1]);
      E_Com17_2->Text=IntToStr(Com17[2]);
      E_Com17_3->Text=IntToStr(Com17[3]);
      // Com18
      unsigned long int Comm18=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 6\"","0"));      // считать из файла в массив
      Com18[3]=Comm18&0xFF;                    // мл. байт
      Com18[2]=(Comm18/256)&0xFF;              // ср. байт
      Com18[1]=(Comm18/65536)&0xFF;            // ст. байт
      E_Com18_1->Text=IntToStr(Com18[1]);
      E_Com18_2->Text=IntToStr(Com18[2]);
      E_Com18_3->Text=IntToStr(Com18[3]);
      // Com19
      unsigned long int Comm19=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 7\"","0"));      // считать из файла в массив
      Com19[3]=Comm19&0xFF;                    // мл. байт
      Com19[2]=(Comm19/256)&0xFF;              // ср. байт
      Com19[1]=(Comm19/65536)&0xFF;            // ст. байт
      E_Com19_1->Text=IntToStr(Com19[1]);
      E_Com19_2->Text=IntToStr(Com19[2]);
      E_Com19_3->Text=IntToStr(Com19[3]);
      // Com20
      unsigned long int Comm20=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 8\"","0"));      // считать из файла в массив
      Com20[3]=Comm20&0xFF;                    // мл. байт
      Com20[2]=(Comm20/256)&0xFF;              // ср. байт
      Com20[1]=(Comm20/65536)&0xFF;            // ст. байт
      E_Com20_1->Text=IntToStr(Com20[1]);
      E_Com20_2->Text=IntToStr(Com20[2]);
      E_Com20_3->Text=IntToStr(Com20[3]);

      UpdateAllRegisters();    

      AddSaveLog("Загружен файл "+FileTesting);  // добавить комментарий и сохранить лог

      delete Ini;
    }
    else
    {
      ShowError(FileNotExist, 0, 0, "");
    }
  }  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DataOnClick(TObject *Sender)
{
  AddSaveLog("Включить измерение данных");  // добавить комментарий и сохранить лог
  B_DataOff->Enabled=true;
  B_DataOn->Enabled=false;
  NIDAQmxTimer->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DataOffClick(TObject *Sender)
{
  AddSaveLog("Выключить измерение данных");  // добавить комментарий и сохранить лог

  B_DataOff->Enabled=false;
  B_DataOn->Enabled=true;

  NIDAQmxTimer->Enabled=false;

  P_1->Color=clBtnFace;
  P_2->Color=clBtnFace;
  P_3->Color=clBtnFace;
  P_4->Color=clBtnFace;
  P_5->Color=clBtnFace;
  P_6->Color=clBtnFace;

  P_U5V->Color=clBtnFace;
  P_U12V->Color=clBtnFace;
  P_I5V->Color=clBtnFace;
  P_I12V->Color=clBtnFace;
  P_Temp->Color=clBtnFace;
  P_Power->Color=clBtnFace;

  P_U5V->Caption="0 В";
  P_U12V->Caption="0 В";
  P_I5V->Caption="0 А";
  P_I12V->Caption="0 А";
  P_Temp->Caption="град. С";
  P_Power->Caption="dBm";
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_AboutClick(TObject *Sender)
{
  AddSaveLog("Информация о программе, номере версии и правах");  // добавить комментарий и сохранить лог
  F_AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_ComNumChange(TObject *Sender) // изменение номера com порта
{
  CommPort1->ComNumber = CB_ComNum->ItemIndex+1;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_BaudRateChange(TObject *Sender)
{
  switch(CB_BaudRate->ItemIndex)
  {
    case 0:
    CommPort1->BaudRate=cbr9600;
    L_SendDirect->Caption="Напр-е передачи: терминал";
    break;

    case 1:
    CommPort1->BaudRate=cbr57600;
    L_SendDirect->Caption="Напр-е передачи: ФРЛП";
    break;
  }
}
/*************************************************************************
Function: uart_puti()
Purpose:  transmit integer as ASCII to UART
Input:    integer value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TMain_Form::uart_puti( signed int val )
 { unsigned char buffer[8];
  
   itoa(val, buffer);
   uart_puts( buffer );
 }/* uart_puti */
 /*************************************************************************
 itoa:  конвертируем n в символы в s
**************************************************************************/
void __fastcall TMain_Form::itoa(signed int n, unsigned char s[])
{
   Bin_to_dec (s, n);
}
/*----------------------------------------------------------------------------*/
/* Функция:    Преобразование BIN->DEC 's[]'                                  */
/* Принимает:  двоичное число                                                 */
/* Возвращает: ничего (изменяет глобальные переменные)                        */
/*----------------------------------------------------------------------------*/
void __fastcall TMain_Form::Bin_to_dec (unsigned char s[],     // буфер
                 signed int dnum)       // преобразуемое
{
   s[0] = ((dnum%1000)%100)/10 + '0';   // после знака выводится старший разряд двухзначного числа
   s[1] = dnum%10 + '0';                // младший разряд
   s[2] = 0;                            // символ конца строки
} 
/*************************************************************************
Function: uart_puts()
Purpose:  transmit string to UART
Input:    string to be transmitted
Returns:  none          
**************************************************************************/
void __fastcall TMain_Form::uart_puts(unsigned char *s )
 { while (*s)
      CommPort1->PutChar(*s++);  // строчка преобразована для проекта
 } /* uart_puts */
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::HelpAboutProgClick(TObject *Sender)
{
  F_Help->ShowModal();  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SendControl(void)
{
  AddSaveLog("Передать команды в режиме Управление");  // добавить комментарий и сохранить лог

  if(ChB_Command3->Checked==false)
  {
    for(int i=0; i<64; i++)
    {
      CommPort1->PutChar((char)Command3[i][0]);  // байт кода команды
      CommPort1->PutChar((char)Command3[i][1]);  // 1-й байт пакета данных
      CommPort1->PutChar((char)Command3[i][2]);  // 2-й байт пакета данных
      CommPort1->PutChar((char)Command3[i][3]);  // 3-й байт пакета данных

      Delay();                                   // задержка

      CommPort1->PutChar((char)Command4[i][0]);  // байт кода команды
      CommPort1->PutChar((char)Command4[i][1]);  // 1-й байт пакета данных
      CommPort1->PutChar((char)Command4[i][2]);  // 2-й байт пакета данных
      CommPort1->PutChar((char)Command4[i][3]);  // 3-й байт пакета данных

      Delay();                                   // задержка

      //int Comm5=(Command5[i][3]+Command5[i][2]*256)/0.5; // цена младшего разряда 0.5 гц
      int Comm5=(Command5[i][3]+Command5[i][2]*256);
      int Comm5_LSB[64], Comm5_MSB[64];
      
      if(D_SignC[i]==1)
      {
        Comm5=~Comm5+1;
      }

      Comm5_LSB[i]=Comm5&0xFF;                   // мл. байт
      Comm5_MSB[i]=(Comm5>>8)&0xFF;              // ст. байт (было /256, принципиально для знакового целого)

      CommPort1->PutChar((char)Command5[i][0]);  // байт кода команды
      CommPort1->PutChar((char)Command5[i][1]);  // 1-й байт пакета данных
      CommPort1->PutChar((char)Comm5_MSB[i]);    // 2-й байт пакета данных
      CommPort1->PutChar((char)Comm5_LSB[i]);    // 3-й байт пакета данных       

      Delay();                                   // задержка      
    }
  }

  if(ChB_Command6->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Shift[i]);
    }
    Delay();                                     // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command6[i]);     
    }
    Delay();                                     // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command7[i]);
    }
    Delay();                                     // задержка
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SendTesting(void)
{
  AddSaveLog("Передать команды в режиме Тестирование");  // добавить комментарий и сохранить лог

  if(ChB_Com3->Checked==false)
  {
    for(int i=0; i<64; i++)
    {
      CommPort1->PutChar((char)Com3[i][0]);  // байт кода команды
      CommPort1->PutChar((char)Com3[i][1]);  // 1-й байт пакета данных
      CommPort1->PutChar((char)Com3[i][2]);  // 2-й байт пакета данных
      CommPort1->PutChar((char)Com3[i][3]);  // 3-й байт пакета данных

      Delay();                               // задержка

      CommPort1->PutChar((char)Com4[i][0]);  // байт кода команды
      CommPort1->PutChar((char)Com4[i][1]);  // 1-й байт пакета данных
      CommPort1->PutChar((char)Com4[i][2]);  // 2-й байт пакета данных
      CommPort1->PutChar((char)Com4[i][3]);  // 3-й байт пакета данных

      Delay();                               // задержка        

      //int Comm5=(Com5[i][3]+Com5[i][2]*256)/0.5; // цена младшего разряда 0.5 гц
      int Comm5=(Com5[i][3]+Com5[i][2]*256);
      int Comm5_LSB[64], Comm5_MSB[64];
      
      if(D_SignT[i]==1)
      {
        Comm5=~Comm5+1;
      }

      Comm5_LSB[i]=Comm5&0xFF;               // мл. байт
      Comm5_MSB[i]=(Comm5>>8)&0xFF;          // ст. байт (было /256, принципиально для знакового целого)

      CommPort1->PutChar((char)Com5[i][0]);  // байт кода команды
      CommPort1->PutChar((char)Com5[i][1]);  // 1-й байт пакета данных
      CommPort1->PutChar((char)Comm5_MSB[i]);// 2-й байт пакета данных
      CommPort1->PutChar((char)Comm5_LSB[i]);// 3-й байт пакета данных      

      Delay();                               // задержка        
    }
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Shift_[i]);
    }
    Delay();                                 // задержка
  }

  if(ChB_Com6->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com6[i]);
    }
    Delay();                                 // задержка
  }

  if(ChB_Com7->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com7[i]);
    }
    Delay();                                 // задержка    
  }

  if(ChB_Com8->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com8[i]);
    }
    Delay();                                 // задержка    
  }

  if(ChB_Com9->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com9[i]);
    }
    Delay();                                 // задержка    
  }

  if(ChB_Com10->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com10[i]);
    }
    Delay();                                 // задержка
  }

  if(ChB_Com11->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com11[i]);
    }
    Delay();                                 // задержка
  }

  if(ChB_Com12->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com12[i]);
    }
    Delay();                                 // задержка    
  }

  if(ChB_Com13->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com20[i]);
    }
    Delay();                                 // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com19[i]);
    }
    Delay();                                 // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com18[i]);
    }
    Delay();                                 // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com17[i]);
    }
    Delay();                                 // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com16[i]);
    }
    Delay();                                 // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com15[i]);
    }
    Delay();                                 // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com14[i]);
    }
    Delay();                                 // задержка

    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Com13[i]);
    }
    Delay();                                 // задержка    
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SendTerminal()
{
  AddSaveLog("Передать команды на Терминал");  // добавить комментарий и сохранить лог

  if(ChB_Command3->Checked==false)
  {
    CommPort1->PutString("Command3 = ");
    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
    
    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // передача номера БТ
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Command3[i][0]);  // байт кода команды
      uart_puthex_byte((char)Command3[i][1]);  // 1-й байт пакета данных
      uart_puthex_byte((char)Command3[i][2]);  // 2-й байт пакета данных
      uart_puthex_byte((char)Command3[i][3]);  // 3-й байт пакета данных

      CommPort1->PutChar(0x0d);                // возврат каретки
      CommPort1->PutChar(0x0a);                // перевод на следующую строку
    }

    CommPort1->PutString("Command4 = ");
    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // передача номера БТ
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Command4[i][0]);  // байт кода команды
      uart_puthex_byte((char)Command4[i][1]);  // 1-й байт пакета данных
      uart_puthex_byte((char)Command4[i][2]);  // 2-й байт пакета данных
      uart_puthex_byte((char)Command4[i][3]);  // 3-й байт пакета данных

      CommPort1->PutChar(0x0d);                // возврат каретки
      CommPort1->PutChar(0x0a);                // перевод на следующую строку
    }

    CommPort1->PutString("Command5 = ");
    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // передача номера БТ
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Command5[i][0]);  // байт кода команды
      uart_puthex_byte((char)Command5[i][1]);  // 1-й байт пакета данных
      uart_puthex_byte((char)Command5[i][2]);  // 2-й байт пакета данных
      uart_puthex_byte((char)Command5[i][3]);  // 3-й байт пакета данных

      CommPort1->PutChar(0x0d);                // возврат каретки
      CommPort1->PutChar(0x0a);                // перевод на следующую строку
    }
  }

  if(ChB_Command6->Checked==false)
  {
    CommPort1->PutString("Command6 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command6[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    CommPort1->PutString("Command7 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command7[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }

  if(ChB_Com3->Checked==false)
  {
    CommPort1->PutString("Com3 = ");
    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // передача номера БТ
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Com3[i][0]);      // байт кода команды
      uart_puthex_byte((char)Com3[i][1]);      // 1-й байт пакета данных
      uart_puthex_byte((char)Com3[i][2]);      // 2-й байт пакета данных
      uart_puthex_byte((char)Com3[i][3]);      // 3-й байт пакета данных

      CommPort1->PutChar(0x0d);                // возврат каретки
      CommPort1->PutChar(0x0a);                // перевод на следующую строку
    }

    CommPort1->PutString("Com4 = ");
    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку      

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // передача номера БТ
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Com4[i][0]);      // байт кода команды
      uart_puthex_byte((char)Com4[i][1]);      // 1-й байт пакета данных
      uart_puthex_byte((char)Com4[i][2]);      // 2-й байт пакета данных
      uart_puthex_byte((char)Com4[i][3]);      // 3-й байт пакета данных

      CommPort1->PutChar(0x0d);                // возврат каретки
      CommPort1->PutChar(0x0a);                // перевод на следующую строку
    }

    CommPort1->PutString("Com5 = ");
    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    for(int i=0; i<64; i++)
    {
      CommPort1->PutString("BP");
      uart_puti(i+1);                          // передача номера БТ
      CommPort1->PutString(" = ");

      uart_puthex_byte((char)Com5[i][0]);      // байт кода команды
      uart_puthex_byte((char)Com5[i][1]);      // 1-й байт пакета данных
      uart_puthex_byte((char)Com5[i][2]);      // 2-й байт пакета данных
      uart_puthex_byte((char)Com5[i][3]);      // 3-й байт пакета данных

      CommPort1->PutChar(0x0d);                // возврат каретки
      CommPort1->PutChar(0x0a);                // перевод на следующую строку
    }
  }

  if(ChB_Com6->Checked==false)
  {
    CommPort1->PutString("Com6 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com6[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }

  if(ChB_Com7->Checked==false)
  {
    CommPort1->PutString("Com7 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com7[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }

  if(ChB_Com8->Checked==false)
  {
    CommPort1->PutString("Com8 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com8[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }

  if(ChB_Com9->Checked==false)
  {
    CommPort1->PutString("Com9 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com9[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }

  if(ChB_Com10->Checked==false)
  {
    CommPort1->PutString("Com10 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com10[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку      
  }

  if(ChB_Com11->Checked==false)
  {
    CommPort1->PutString("Com11 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com11[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }

  if(ChB_Com12->Checked==false)
  {
    CommPort1->PutString("Com12 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com12[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }

  if(ChB_Com13->Checked==false)
  {
    CommPort1->PutString("Com13 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com13[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    CommPort1->PutString("Com14 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com14[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    CommPort1->PutString("Com15 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com15[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    CommPort1->PutString("Com16 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com16[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    CommPort1->PutString("Com17 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com17[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    CommPort1->PutString("Com18 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com18[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    CommPort1->PutString("Com19 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com19[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку

    CommPort1->PutString("Com20 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com20[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_OutputChange(TObject *Sender)
{
  UpdateRegister4();  // обновление значения Register 4
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::CB_AuxOutChange(TObject *Sender)
{
  UpdateRegister4();  // обновление значения Register 4  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_OutFreqChange(TObject *Sender)
{
  if(E_OutFreq->Text<=1) E_OutFreq->Text=1;  // число не может быть меньше 1
  Fout=StrToFloat(E_OutFreq->Text);          // записать значение в переменную

  Fvco_OD();          // вычисление Fvco и OD
  Ndevider();         // вычисление INT, FRAC и MOD
  UpdateRegister0();  // обновление значения Register 0
  UpdateRegister1();  // обновление значения Register 1
  UpdateRegister4();  // обновление значения Register 4
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Fvco_OD(void)
{
  OD=1;
  while(Fout*OD<2200) OD*=2;
  Fvco=Fout*OD;

  Fres=ChS*OD;               // запись channel resolution

  // задание Divider_Select:
  //Divider_Select=log(OD)/log(2);
  
  if(OD==1) Divider_Select=0;
  else
  if(OD==2) Divider_Select=1;
  else
  if(OD==4) Divider_Select=2;
  else
  if(OD==8) Divider_Select=3;
  else
  if(OD==16) Divider_Select=4;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Ndevider(void)  // вычисление INT, FRAC и MOD:
{
  double Inv, n;
  Inv=1/Fpfd;            // величина, обратная Fpfd для учёта дробной части N
  N=Fvco*Inv;

  MOD=(REFin*1000)/Fres; //*1000, т.к. REFin [kHz]
  /*
  Функция modf(N, &n) вычисляет целую (INTE) и дробную (FRAC/MOD) части значения аргумента N со знаком.
  Целая часть 'n' со знаком запоминается в ptr. Дробная часть со знаком - возвращаемое значение.
  */
  FRAC=modf(N, &n)*MOD;  // или FRAC=(N-INTE)*MOD
  FRAC=floor(FRAC+0.5);  // округление до ближайшего целого положительного(для отрицательного ceil(x-0.5))
  INTE=n;                // или INTE=(int)N

  int i;
  for(i=1; i<1000; i++)  // упрощение дроби
  {
    if(((int)FRAC%i==0)&&((int)MOD%i==0)&&((int)FRAC!=0)) // если числитель и знаменатель одновременно делятся на число i без остатка
    {
      FRAC/=i;
      MOD/=i;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::UpdateRegister0(void)  // обновление значения Register 0
{
  int shift_FRAC=0;
  int shift_INT=0;

  Reg[0] &= ~0x7FFFFFF8;           // стереть предыдущее значение Register 0

  shift_FRAC=(int)FRAC&0xFFE;      // FRAC max = 4094
  shift_FRAC*=0x8;
  shift_INT=(int)INTE&0xFFFF;      // INT max = 65535
  shift_INT*=0x8000;

  Reg[0] |= shift_FRAC|shift_INT;  // занести новое значение INT и FRAC

  // обновить значения команд:
  Com13[1]=(int) Reg[0]     &0xFF; // 1-й байт Register 0
  Com13[2]=(int)(Reg[0]>>8) &0xFF; // 2-й байт Register 0
  Com13[3]=(int)(Reg[0]>>16)&0xFF; // 3-й байт Register 0
  Com14[1]=(int)(Reg[0]>>24)&0xFF; // 4-й байт Register 0

  E_Com13_1->Text=IntToStr(Com13[1]);
  E_Com13_2->Text=IntToStr(Com13[2]);
  E_Com13_3->Text=IntToStr(Com13[3]);
  E_Com14_1->Text=IntToStr(Com14[1]);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::UpdateRegister1(void)  // обновление значения Register 1
{
  int shift_MOD=0;
  int shift_Phase=0;
  int shift_Prescaler=0;

  if(INTE<75)
  {
    Prescaler=0;
  }
  else
  if(INTE>=75)
  {
    Prescaler=1;
  }

  Reg[1] &= ~0xFFFFFFF8;  // стереть предыдущее значение Register 1

  shift_MOD=(int)MOD&0xFFF;                         // MOD max = 4095
  shift_MOD*=0x08;
  shift_Phase=(int)Phase&0xFFF;                     // Phase max = 4095
  shift_Phase*=0x8000;
  shift_Prescaler=Prescaler&0x01;                   // Prescaler max = 1
  shift_Prescaler*=0x8000000;

  Reg[1] |= shift_MOD|shift_Phase|shift_Prescaler;  // занести новые значения

  // обновить значения команд:
  Com14[2]=(int) Reg[1]     &0xFF;                  // 1-й байт Register 1
  Com14[3]=(int)(Reg[1]>>8) &0xFF;                  // 2-й байт Register 1
  Com15[1]=(int)(Reg[1]>>16)&0xFF;                  // 3-й байт Register 1
  Com15[2]=(int)(Reg[1]>>24)&0xFF;                  // 4-й байт Register 1

  E_Com14_2->Text=IntToStr(Com14[2]);
  E_Com14_3->Text=IntToStr(Com14[3]);
  E_Com15_1->Text=IntToStr(Com15[1]);
  E_Com15_2->Text=IntToStr(Com15[2]);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::UpdateRegister4(void)  // обновление значения Register 4
{
  int shift_RF_Output=0;
  int shift_AUX_Output=0;
  int shift_AUX_Select=0;
  int shift_MTLD=0;
  int shift_VCO_Power_Down=0;
  int shift_BSCD=0;
  int shift_Divider_Select=0;
  int shift_Feedback_Select=0;

  // задание Output:
  if(CB_Output->ItemIndex==0)   RF_Output=0;
  for(int i=1; i<5; i++)
  {
    if(CB_Output->ItemIndex==i) RF_Output=(i+3);
  }

  // задание AUX Output:
  if(CB_AuxOut->ItemIndex==0)   AUX_Output=0;
  for(int i=1; i<5; i++)
  {
    if(CB_AuxOut->ItemIndex==i) AUX_Output=(i+3);
  }

  Reg[4] &= ~0xFFFFFFF8;  // стереть предыдущее значение Register 4

  shift_RF_Output=RF_Output&0x07;                   // Output max = 7
  shift_RF_Output*=0x08;
  shift_AUX_Output=AUX_Output&0x07;                 // AUX Output max = 7
  shift_AUX_Output*=0x40;
  shift_AUX_Select=AUX_Select&0x01;                 // AUX Select max = 1
  shift_AUX_Select*=0x200;
  shift_MTLD=MTLD&0x01;                             // MTLD max = 1
  shift_MTLD*=0x400;
  shift_VCO_Power_Down=VCO_Power_Down&0x01;         // VCO Power Down max = 1
  shift_VCO_Power_Down*=0x800;
  shift_BSCD=(int)BSCD&0xFF;                        // BSCD max = 255
  shift_BSCD*=0x1000;
  shift_Divider_Select=(int)Divider_Select&0x07;    // Divider Select max = 7
  shift_Divider_Select*=0x100000;
  shift_Feedback_Select=Feedback_Select&0x01;       // Feedback Select max = 1
  shift_Feedback_Select*=0x800000;

  Reg[4] |= shift_RF_Output|shift_AUX_Output|shift_AUX_Select|shift_MTLD|shift_VCO_Power_Down
  |shift_BSCD|shift_Divider_Select|shift_Feedback_Select;  // занести новые значения

  // обновить значения команд:
  Com18[2]=(int) Reg[4]     &0xFF;                  // 1-й байт Register 4
  Com18[3]=(int)(Reg[4]>>8) &0xFF;                  // 2-й байт Register 4
  Com19[1]=(int)(Reg[4]>>16)&0xFF;                  // 3-й байт Register 4
  Com19[2]=(int)(Reg[4]>>24)&0xFF;                  // 4-й байт Register 4

  E_Com18_2->Text=IntToStr(Com18[2]);
  E_Com18_3->Text=IntToStr(Com18[3]);
  E_Com19_1->Text=IntToStr(Com19[1]);
  E_Com19_2->Text=IntToStr(Com19[2]);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ResetSynthesizer()
{
  Com13[4]=(237, 0, 0, 200);   // 00, 00, c8
  Com14[4]=(238, 0, 201, 128); // 00, c9, 80
  Com15[4]=(239, 0, 8, 194);   // 00, 08, c2
  Com16[4]=(240, 78, 0, 0);    // 4e, 00, 00
  Com17[4]=(241, 179, 4, 0);   // b3, 04, 00
  Com18[4]=(242, 0, 36, 1);    // 00, 24, 01
  Com19[4]=(243, 165, 0, 5);   // a5, 00, 05
  Com20[4]=(244, 0, 88, 0);    // 00, 58, 00
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_parametersClick(TObject *Sender)
{
  //ResetSynthesizer();
/*
  E_Com13_1->Text=0;
  E_Com13_2->Text=0;
  E_Com13_3->Text=200;
  E_Com14_1->Text=0;
  E_Com14_2->Text=201;
  E_Com14_3->Text=128;
  E_Com15_1->Text=0;
  E_Com15_2->Text=8;
  E_Com15_3->Text=194;
  E_Com16_1->Text=78;
  E_Com16_2->Text=0;
  E_Com16_3->Text=0;
  E_Com17_1->Text=179;
  E_Com17_2->Text=4;
  E_Com17_3->Text=0;
  E_Com18_1->Text=0;
  E_Com18_2->Text=36;
  E_Com18_3->Text=1;
  E_Com19_1->Text=165;
  E_Com19_2->Text=0;
  E_Com19_3->Text=5;
  E_Com20_1->Text=0;
  E_Com20_2->Text=88;
  E_Com20_3->Text=0;
*/
  E_Com13_1->Enabled=false;
  E_Com13_2->Enabled=false;
  E_Com13_3->Enabled=false;
  E_Com14_1->Enabled=false;
  E_Com14_2->Enabled=false;
  E_Com14_3->Enabled=false;
  E_Com15_1->Enabled=false;
  E_Com15_2->Enabled=false;
  E_Com15_3->Enabled=false;
  E_Com16_1->Enabled=false;
  E_Com16_2->Enabled=false;
  E_Com16_3->Enabled=false;
  E_Com17_1->Enabled=false;
  E_Com17_2->Enabled=false;
  E_Com17_3->Enabled=false;
  E_Com18_1->Enabled=false;
  E_Com18_2->Enabled=false;
  E_Com18_3->Enabled=false;
  E_Com19_1->Enabled=false;
  E_Com19_2->Enabled=false;
  E_Com19_3->Enabled=false;
  E_Com20_1->Enabled=false;
  E_Com20_2->Enabled=false;
  E_Com20_3->Enabled=false;

  E_Com13_1->Color=clSilver;
  E_Com13_2->Color=clSilver;
  E_Com13_3->Color=clSilver;
  E_Com14_1->Color=clSilver;
  E_Com14_2->Color=clSilver;
  E_Com14_3->Color=clSilver;
  E_Com15_1->Color=clSilver;
  E_Com15_2->Color=clSilver;
  E_Com15_3->Color=clSilver;
  E_Com16_1->Color=clSilver;
  E_Com16_2->Color=clSilver;
  E_Com16_3->Color=clSilver;
  E_Com17_1->Color=clSilver;
  E_Com17_2->Color=clSilver;
  E_Com17_3->Color=clSilver;
  E_Com18_1->Color=clSilver;
  E_Com18_2->Color=clSilver;
  E_Com18_3->Color=clSilver;
  E_Com19_1->Color=clSilver;
  E_Com19_2->Color=clSilver;
  E_Com19_3->Color=clSilver;
  E_Com20_1->Color=clSilver;
  E_Com20_2->Color=clSilver;
  E_Com20_3->Color=clSilver;

  GB_Parameters->Enabled=true;
  CB_Output->Color=clWindow;
  CB_AuxOut->Color=clWindow;
  E_OutFreq->Color=clWindow;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_registersClick(TObject *Sender)
{
  //ResetSynthesizer();

  E_Com13_1->Enabled=true;
  E_Com13_2->Enabled=true;
  E_Com13_3->Enabled=true;
  E_Com14_1->Enabled=true;
  E_Com14_2->Enabled=true;
  E_Com14_3->Enabled=true;
  E_Com15_1->Enabled=true;
  E_Com15_2->Enabled=true;
  E_Com15_3->Enabled=true;
  E_Com16_1->Enabled=true;
  E_Com16_2->Enabled=true;
  E_Com16_3->Enabled=true;
  E_Com17_1->Enabled=true;
  E_Com17_2->Enabled=true;
  E_Com17_3->Enabled=true;
  E_Com18_1->Enabled=true;
  E_Com18_2->Enabled=true;
  E_Com18_3->Enabled=true;
  E_Com19_1->Enabled=true;
  E_Com19_2->Enabled=true;
  E_Com19_3->Enabled=true;
  E_Com20_1->Enabled=true;
  E_Com20_2->Enabled=true;
  E_Com20_3->Enabled=true;

  E_Com13_1->Color=clWindow;
  E_Com13_2->Color=clWindow;
  E_Com13_3->Color=clWindow;
  E_Com14_1->Color=clWindow;
  E_Com14_2->Color=clWindow;
  E_Com14_3->Color=clWindow;
  E_Com15_1->Color=clWindow;
  E_Com15_2->Color=clWindow;
  E_Com15_3->Color=clWindow;
  E_Com16_1->Color=clWindow;
  E_Com16_2->Color=clWindow;
  E_Com16_3->Color=clWindow;
  E_Com17_1->Color=clWindow;
  E_Com17_2->Color=clWindow;
  E_Com17_3->Color=clWindow;
  E_Com18_1->Color=clWindow;
  E_Com18_2->Color=clWindow;
  E_Com18_3->Color=clWindow;
  E_Com19_1->Color=clWindow;
  E_Com19_2->Color=clWindow;
  E_Com19_3->Color=clWindow;
  E_Com20_1->Color=clWindow;
  E_Com20_2->Color=clWindow;
  E_Com20_3->Color=clWindow;
/*
  CB_Output->ItemIndex=1;
  CB_AuxOut->ItemIndex=1;
  E_OutFreq->Text=1000;
*/
  GB_Parameters->Enabled=false;
  CB_Output->Color=clSilver;
  CB_AuxOut->Color=clSilver;
  E_OutFreq->Color=clSilver;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_OutFreqExit(TObject *Sender)
{
  bool b;
  float min=137.5;
  float max=4400;
  float delta=0.1;
  String EdIzm="МГц";
  String value;

  value=E_OutFreq->Text;

  b=IsValid(min,max,value,EdIzm);
  if(b)
  {
    E_OutFreq->Text=RoundValue(delta,value);
    Fout=StrToFloat(E_OutFreq->Text);          // записать значение в переменную
  }
  else
  {
    E_OutFreq->SetFocus();
    ErrorForm->SetFocus();
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
void __fastcall TMain_Form::E_Command6Exit(TObject *Sender)
{
  bool b;
  int min=8500;
  int max=17500;
  int delta=10;
  String EdIzm="МГц";
  String value;

  value=E_Command6->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    int Freq;
    E_Command6->Text=RoundValue(delta,value);

    Freq=StrToInt(E_Command6->Text);            // центральная частота рабочей полосы

    int Old = OldIndexF[OldIndexMod];           // старый индекс номера частоты

    if(Freq>=8500&&Freq<=17500)                 // если диапазон правильный
    {
      int rounding=Freq/10;                     // округление до числа, кратного 10
      Freq=rounding*10;
      int code=(Freq-8500)/10;                  // получение кода центральной частоты
      int code_LSB=code&0xFF;                   // младший байт центральной частоты рабочей полосы
      int code_MSB=(code/256)&0xFF;             // старший байт центральной частоты рабочей полосы
      // записать старое значение по индексам OldIndexMod и Old в массив:
      Mod[OldIndexMod][Old][0]=code_MSB;        // записать значение старшего байта центральной частоты рабочей полосы
      Mod[OldIndexMod][Old][1]=code_LSB;        // записать значение младшего байта центральной частоты рабочей полосы

      Command6[2]=code_MSB;                     // записать значение старшего байта центральной частоты рабочей полосы
      Command6[3]=code_LSB;                     // записать значение младшего байта центральной частоты рабочей полосы
    }
  }
  else
  {
    E_Command6->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::UpdateAllRegisters(void)  // обновление значения Register 0...5
{
  if(E_Com13_1->Text=="") E_Com13_1->Text=0;
  if(E_Com13_2->Text=="") E_Com13_2->Text=0;
  if(E_Com13_3->Text=="") E_Com13_3->Text=0;

  if(E_Com14_1->Text=="") E_Com14_1->Text=0;
  if(E_Com14_2->Text=="") E_Com14_2->Text=0;
  if(E_Com14_3->Text=="") E_Com14_3->Text=0;

  if(E_Com15_1->Text=="") E_Com15_1->Text=0;
  if(E_Com15_2->Text=="") E_Com15_2->Text=0;
  if(E_Com15_3->Text=="") E_Com15_3->Text=0;

  if(E_Com16_1->Text=="") E_Com16_1->Text=0;
  if(E_Com16_2->Text=="") E_Com16_2->Text=0;
  if(E_Com16_3->Text=="") E_Com16_3->Text=0;

  if(E_Com17_1->Text=="") E_Com17_1->Text=0;
  if(E_Com17_2->Text=="") E_Com17_2->Text=0;
  if(E_Com17_3->Text=="") E_Com17_3->Text=0;

  if(E_Com18_1->Text=="") E_Com18_1->Text=0;
  if(E_Com18_2->Text=="") E_Com18_2->Text=0;
  if(E_Com18_3->Text=="") E_Com18_3->Text=0;

  if(E_Com19_1->Text=="") E_Com19_1->Text=0;
  if(E_Com19_2->Text=="") E_Com19_2->Text=0;
  if(E_Com19_3->Text=="") E_Com19_3->Text=0;

  if(E_Com20_1->Text=="") E_Com20_1->Text=0;
  if(E_Com20_2->Text=="") E_Com20_2->Text=0;
  if(E_Com20_3->Text=="") E_Com20_3->Text=0;

  int shift_Com13_1=0;
  int shift_Com13_2=0;
  int shift_Com13_3=0;

  int shift_Com14_1=0;
  int shift_Com14_2=0;
  int shift_Com14_3=0;

  int shift_Com15_1=0;
  int shift_Com15_2=0;

  int shift_Com18_2=0;
  int shift_Com18_3=0;

  int shift_Com19_1=0;
  int shift_Com19_2=0;

  Com13[1]=StrToInt(E_Com13_1->Text);
  Com13[2]=StrToInt(E_Com13_2->Text);
  Com13[3]=StrToInt(E_Com13_3->Text);

  Com14[1]=StrToInt(E_Com14_1->Text);
  Com14[2]=StrToInt(E_Com14_2->Text);
  Com14[3]=StrToInt(E_Com14_3->Text);

  Com15[1]=StrToInt(E_Com15_1->Text);
  Com15[2]=StrToInt(E_Com15_2->Text);
  Com15[3]=StrToInt(E_Com15_3->Text);

  Com16[1]=StrToInt(E_Com16_1->Text);
  Com16[2]=StrToInt(E_Com16_2->Text);
  Com16[3]=StrToInt(E_Com16_3->Text);

  Com17[1]=StrToInt(E_Com17_1->Text);
  Com17[2]=StrToInt(E_Com17_2->Text);
  Com17[3]=StrToInt(E_Com17_3->Text);

  Com18[1]=StrToInt(E_Com18_1->Text);
  Com18[2]=StrToInt(E_Com18_2->Text);
  Com18[3]=StrToInt(E_Com18_3->Text);

  Com19[1]=StrToInt(E_Com19_1->Text);
  Com19[2]=StrToInt(E_Com19_2->Text);
  Com19[3]=StrToInt(E_Com19_3->Text);

  Com20[1]=StrToInt(E_Com20_1->Text);
  Com20[2]=StrToInt(E_Com20_2->Text);
  Com20[3]=StrToInt(E_Com20_3->Text);

  Reg[0] &= ~0xFFFFFFFF;  // стереть предыдущее значение Register 0
  Reg[1] &= ~0xFFFFFFFF;  // стереть предыдущее значение Register 1
  Reg[4] &= ~0xFFFFFFFF;  // стереть предыдущее значение Register 4

  shift_Com13_1=Com13[1];
  shift_Com13_2=Com13[2]*0x100;
  shift_Com13_3=Com13[3]*0x10000;
  shift_Com14_1=Com14[1]*0x1000000;

  Reg[0] |= shift_Com13_1|shift_Com13_2|shift_Com13_3|shift_Com14_1;  // занести новые значения

  // обновить значения параметров:
  FRAC=(int)(Reg[0]>>3) &0xFFF;
  INTE=(int)(Reg[0]>>15)&0xFFFF;

  shift_Com14_2=Com14[2];
  shift_Com14_3=Com14[3]*0x100;
  shift_Com15_1=Com15[1]*0x10000;
  shift_Com15_2=Com15[2]*0x1000000;

  Reg[1] |= shift_Com14_2|shift_Com14_3|shift_Com15_1|shift_Com15_2;  // занести новые значения

  // обновить значения параметров:
  MOD=(int)(Reg[1]>>3) &0xFFF;

  shift_Com18_2=Com18[2];
  shift_Com18_3=Com18[3]*0x100;
  shift_Com19_1=Com19[1]*0x10000;
  shift_Com19_2=Com19[2]*0x1000000;

  Reg[4] |= shift_Com18_2|shift_Com18_3|shift_Com19_1|shift_Com19_2;  // занести новые значения

  // обновить значения параметров:
  RF_Output=(int)(Reg[4]>>3)&0x07;
  AUX_Output=(int)(Reg[4]>>6)&0x07;
  Divider_Select=(int)(Reg[4]>>20)&0x07;

  // задание Output:
  if(RF_Output==0)   CB_Output->ItemIndex=0;
  for(int i=1; i<5; i++)
  {
    if(RF_Output==(i+3)) CB_Output->ItemIndex=i;
  }

  // задание AUX Output:
  if(AUX_Output==0)   CB_AuxOut->ItemIndex=0;
  for(int i=1; i<5; i++)
  {
    if(AUX_Output==(i+3)) CB_AuxOut->ItemIndex=i;
  }

  // задание OD:
  //OD=pow(10, Divider_Select*log(2));
  
  if(Divider_Select==0) OD=1;
  else
  if(Divider_Select==1) OD=2;
  else
  if(Divider_Select==2) OD=4;
  else
  if(Divider_Select==3) OD=8;
  else
  if(Divider_Select==4) OD=16;

  // задание AUX Fout:
  Fout=(INTE+FRAC/MOD)*(Fpfd/OD);
  E_OutFreq->Text=FloatToStr(Fout);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com13_1Change(TObject *Sender)
{
  UpdateAllRegisters();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com13_1Exit(TObject *Sender)
{
  UpdateAllRegisters();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command3_0Change(TObject *Sender)
{
  ResetBPControl();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::InitBPControl(void)  // инициализация команд Command 3...5
{
  // инициализация массива Command3
  for(int i=0; i<64; i++)
  {
    Command3[i][0]=3;   // байт кода команды
    Command3[i][1]=i+1; // 1-й байт пакета данных
    Command3[i][2]=0;   // 2-й байт пакета данных
  }
  Command3[0][3]=255;   // 3-й байт пакета данных (БТ №1)

  for(int i=1; i<64; i++)
  {
    Command3[i][3]=0;   // 3-й байт пакета данных (остальные БТ)
  }

  // инициализация массива Command4
  for(int i=0; i<64; i++)
  {
    Command4[i][0]=4;   // байт кода команды
    Command4[i][1]=i+1; // 1-й байт пакета данных
    Command4[i][2]=0;   // 2-й байт пакета данных
    Command4[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива Command5
  for(int i=0; i<64; i++)
  {
    Command5[i][0]=5;   // байт кода команды
    Command5[i][1]=i+1; // 1-й байт пакета данных
    Command5[i][2]=0;   // 2-й байт пакета данных
    Command5[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива SignC
  for(int i=0; i<64; i++)
  {
    D_SignC[i]=0;
  }

  OldIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Com3_0Change(TObject *Sender)
{
  ResetBPTesting();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::InitBPTesting(void)  // инициализация команд Com 3...5
{
  // инициализация массива Com3
  for(int i=0; i<64; i++)
  {
    Com3[i][0]=227; // байт кода команды
    Com3[i][1]=i+1; // 1-й байт пакета данных
    Com3[i][2]=0;   // 2-й байт пакета данных
  }
  Com3[0][3]=255;   // 3-й байт пакета данных (БТ №1)

  for(int i=1; i<64; i++)
  {
    Com3[i][3]=0;   // 3-й байт пакета данных (остальные БТ)
  }

  // инициализация массива Com4
  for(int i=0; i<64; i++)
  {
    Com4[i][0]=228; // байт кода команды
    Com4[i][1]=i+1; // 1-й байт пакета данных
    Com4[i][2]=0;   // 2-й байт пакета данных
    Com4[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива Com5
  for(int i=0; i<64; i++)
  {
    Com5[i][0]=229; // байт кода команды
    Com5[i][1]=i+1; // 1-й байт пакета данных
    Com5[i][2]=0;   // 2-й байт пакета данных
    Com5[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива SignT
  for(int i=0; i<64; i++)
  {
    D_SignT[i]=0;
  }

  OldIndex_=0;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_SignCChange(TObject *Sender)
{
  if(CB_SignC->ItemIndex==0) D_SignC[OldIndex]=0;
  else                       D_SignC[OldIndex]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_SignCExit(TObject *Sender)
{
  if(CB_SignC->ItemIndex==0) D_SignC[OldIndex]=0;
  else                       D_SignC[OldIndex]=1;  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_SignTChange(TObject *Sender)
{
  if(CB_SignT->ItemIndex==0) D_SignT[OldIndex_]=0;
  else                       D_SignT[OldIndex_]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_SignTExit(TObject *Sender)
{
  if(CB_SignT->ItemIndex==0) D_SignT[OldIndex_]=0;
  else                       D_SignT[OldIndex_]=1;  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_SignCKeyPress(TObject *Sender, char &Key)
// запрет введения любых символов
{
  Set<char,0,255>Dig;
	Dig<<8;
	if(!Dig.Contains(Key))
	{
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ResetBPControl(void)  // сброс команд Command 3...5
{
  InitBPControl();                 // очистить предыдущие параметры БТ
  CB_Command3_1->ItemIndex=0;
  CB_SignC->ItemIndex=0;
  E_Command3->Text=IntToStr(255);
  E_Command4->Text=IntToStr(0);
  E_Command5->Text=IntToStr(0);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ResetBPTesting(void)  // сброс команд Com 3...5
{
  InitBPTesting();                 // очистить предыдущие параметры БТ
  CB_Com3_1->ItemIndex=0;
  CB_SignT->ItemIndex=0;
  E_Com3->Text=IntToStr(255);
  E_Com4->Text=IntToStr(0);
  E_Com5->Text=IntToStr(0);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command5KeyPress(TObject *Sender, char &Key)
// запрет введения любых символов, кроме чисел 0...9 и десятичной запятой
{
  Set<char,0,255>Dig;
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<','<<8;
	if(!Dig.Contains(Key))
	{
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Delay(void)  // функция задержки
{
  Sleep(delay_ms);                       // задержка в мс
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_DelayChange(TObject *Sender)
{
  if(E_Delay->Text=="") E_Delay->Text=0;
  delay_ms = StrToInt(E_Delay->Text);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_5GHzClick(TObject *Sender)
{
  AddSaveLog("Введена частотная калибровка 5 ГГц");  // добавить комментарий и сохранить лог
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_8GHzClick(TObject *Sender)
{
  AddSaveLog("Введена частотная калибровка 8 ГГц");  // добавить комментарий и сохранить лог  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_EnterDelayClick(TObject *Sender)
{
  bool b;
  int min=0;
  int max=1000;
  int delta=1;
  String EdIzm="мс";
  String value;

  value=E_Delay->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    E_Delay->Text=RoundValue(delta,value);           
    delay_ms = StrToInt(E_Delay->Text);
    AddSaveLog("Введено новое значение задержки между командами "+E_Delay->Text);  // добавить комментарий и сохранить лог
  }
  else
  {
    E_Delay->SetFocus();
    ErrorForm->SetFocus();
  }  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_ShiftChange(TObject *Sender)
{
  int i, j;
  i=CB_Frequency->ItemIndex;                   // записать текущий индекс поля выбора CB_Frequency
  j=CB_Modulus->ItemIndex;                     // записать текущий индекс поля выбора CB_Modulus

  for(int z=0; z<7; z++)
  {
    if(CB_Shift->ItemIndex==z) Mod[j][i][3]=z;
  }

  for(int y=0; y<7; y++)
  {
    if(CB_Shift->ItemIndex==y) Shift[3]=y;
  }    
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Shift_Change(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
    if(CB_Shift_->ItemIndex==i) Shift_[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::InitModulus(void)  // инициализация модулей 1...8
{
  for(int i=0; i<NUMBOFMODS; i++)
  {
    for(int j=0; j<NUMBOFREQS; j++)
    {
      for(int k=0; k<3; k++)
      {
        Mod[i][j][k]=0;
      }
    }
  }

  for(int i=0; i<8; i++) ModNumber[i]=1;

  OldIndexMod=0;

  for(int z=0; z<NUMBOFMODS; z++)
  {
    OldIndexF[z]=0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ResetModulus(void)  // сброс модулей 1...8
{
  InitModulus();                     // инициализация модулей 1...8
  NumberOfFreq=1;
  E_NumbOfFreq->Text=IntToStr(NumberOfFreq);
  CB_Modulus->ItemIndex=0;           // очистить предыдущие параметры
  E_Mod->Text=1;
  ResetFrequency();                  // сброс модулей 1...8
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_NumbOfModsChange(TObject *Sender)
{
  ResetModulus();                    // сброс модулей 1...8
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_NumbOfModsExit(TObject *Sender)
// когда поле "Количество модулей" неактивно
{
  bool b;
  int min=1;                         // минимальное значение
  int max=NUMBOFMODS;                // максимальное значение
  int delta=1;
  String EdIzm="";                   // единица измерения
  String value;                      // строка значения

  value=E_NumbOfMods->Text;          // значение

  b=IsValidInt(min,max,value,EdIzm); // проверка правильности диапазона значений
  if(b)                              // если правильно
  {
    CB_Modulus->Text=RoundValue(delta,value);
    CB_Modulus->Clear();             // очистить предыдущее количество модулей
    CB_Frequency->Clear();           // очистить предыдущее количество частот

    for(int i=0;i<StrToInt(E_NumbOfMods->Text);i++)
    {
      CB_Modulus->Items->Add(IntToStr(i+1)); // увеличить количество модулей в полях "Модуль №"
    }

    for(int i=0;i<StrToInt(E_NumbOfFreq->Text);i++)
    {
      CB_Frequency->Items->Add(IntToStr(i+1)); // увеличить количество частот в полях "Номер частоты"
    }    

    CB_Modulus->ItemIndex=0;         // номер модуля по умолчанию при изменении числа модулей
    CB_Frequency->ItemIndex=0;       // номер частоты по умолчанию при изменении числа частот
  }
  else                               // если не правильно
  {
    E_NumbOfMods->SetFocus();        // фокус на поле "Количество модулей"
    ErrorForm->SetFocus();           // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_ModulusChange(TObject *Sender)
// по изменении номера модуля
{
  int i, j, Freq;
  i=CB_Frequency->ItemIndex;                         // записать текущий индекс поля выбора CB_Frequency
  j=CB_Modulus->ItemIndex;                           // записать текущий индекс поля выбора CB_Modulus

  // записать старое значение поля E_Mod в массив хранения индивидуального номера модуля:
  ModNumber[OldIndexMod]=StrToInt(E_Mod->Text);
  
  int Old = OldIndexF[OldIndexMod];                  // старый индекс номера частоты  OldIndexMod
  
  FreqNumber[OldIndexMod][Old]=i;                    // запись в массив хранения номеров частот
  Freq=StrToInt(E_Command6->Text);                   // записать старое значение поля E_Command6 в переменную

  int rounding=Freq/10;                              // округление до числа, кратного 10
  Freq=rounding*10;
  int code=(Freq-8500)/10;                           // получение кода центральной частоты
  int code_LSB=code&0xFF;                            // младший байт центральной частоты рабочей полосы
  int code_MSB=(code/256)&0xFF;                      // старший байт центральной частоты рабочей полосы
  // записать старое значение по индексам OldIndexMod и Old в массив:
  Mod[OldIndexMod][Old][0]=code_MSB;                 // записать значение старшего байта центральной частоты рабочей полосы
  Mod[OldIndexMod][Old][1]=code_LSB;                 // записать значение младшего байта центральной частоты рабочей полосы

  // записать значение коэффициента ослабления по индексам OldIndexMod и Old:
  for(int z=0; z<NUMBOFREQS; z++)
  {
    if(CB_Command7->ItemIndex==z) Mod[OldIndexMod][Old][2]=63-z;
  }

  // записать значение сдвига разрядов по индексам OldIndexMod и Old:
  for(int z=0; z<7; z++)
  {
    if(CB_Shift->ItemIndex==z) Mod[OldIndexMod][Old][3]=z;
  }

  // сохранить текущий индекс как старый для следующего вхождения в метод:
  OldIndexMod=j;                                     // индекс модуля
  Old = OldIndexF[j];                                // индекс частоты

  // извлечь значение из массива по текущему индексу в поле редактирования:
  E_Mod->Text=IntToStr(ModNumber[j]);

  // извлечь новые значения частот в поле выбора:
  CB_Frequency->Clear();                             // очистить предыдущее количество частот
  for(int i=0;i<StrToInt(E_NumbOfFreq->Text);i++)
  {
    CB_Frequency->Items->Add(IntToStr(i+1));         // увеличить количество частот в полях "Номер частоты"
  }
  for(int z=0; z<NUMBOFREQS; z++)
  {
    if(FreqNumber[j][Old]==z)
    {
      CB_Frequency->ItemIndex=z;
    }
  }
  
  // извлечь значение из массива по текущему индексу в поле E_Command6:
  E_Command6->Text=IntToStr(10*(Mod[j][Old][0]*256+Mod[j][Old][1])+8500);

  Command6[2]=Mod[j][Old][0];  // при загрузке из файла
  Command6[3]=Mod[j][Old][1];
  
  // извлечь значение из массива по текущему индексу в поле CB_Command7:
  for(int z=0; z<NUMBOFREQS; z++)
  {
    if(Mod[j][Old][2]==63-z)
    {
      CB_Command7->ItemIndex=z;
    }
  }

  Command7[3]=Mod[j][Old][2];  // при загрузке из файла

  // извлечь значение из массива по текущему индексу в поле CB_Shift:
  for(int z=0; z<7; z++)
  {
    if(Mod[j][Old][3]==z)
    {
      CB_Shift->ItemIndex=z;
    }
  }

  Shift[3]=Mod[j][Old][3];  // при загрузке из файла  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::InitFrequency(void)  // инициализация частот 1...64
{
  for(int j=0; j<NUMBOFREQS; j++)
  {
    for(int k=0; k<3; k++)
    {
      Mod[OldIndexMod][j][k]=0;      
    }
  }

  for(int z=0; z<NUMBOFMODS; z++)
  {
    OldIndexF[z]=0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ResetFrequency(void)  // сброс частот 1...64
{
  InitFrequency();                   // очистить предыдущие параметры БТ
  CB_Frequency->ItemIndex=0;
  E_Command6->Text=8500;
  CB_Command7->ItemIndex=63;
  CB_Shift->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_NumbOfFreqChange(TObject *Sender)
{
  ResetFrequency();                  // сброс частот 1...64
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_NumbOfFreqExit(TObject *Sender)
// когда поле "Количество частот" неактивно
{
  bool b;
  int min=1;                         // минимальное значение
  int max=NUMBOFREQS;                // максимальное значение
  int delta=1;
  String EdIzm="";                   // единица измерения
  String value;                      // строка значения

  value=E_NumbOfFreq->Text;          // значение

  b=IsValidInt(min,max,value,EdIzm); // проверка правильности диапазона значений
  if(b)                              // если правильно
  {
    CB_Frequency->Text=RoundValue(delta,value);
    CB_Frequency->Clear();           // очистить предыдущее количество частот

    for(int i=0;i<StrToInt(E_NumbOfFreq->Text);i++)
    {
      CB_Frequency->Items->Add(IntToStr(i+1)); // увеличить количество частот в полях "Номер частоты"
    }

    CB_Frequency->ItemIndex=0;       // номер частоты по умолчанию при изменении числа частот
  }
  else                               // если не правильно
  {
    E_NumbOfFreq->SetFocus();        // фокус на поле "Количество частот"
    ErrorForm->SetFocus();           // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_FrequencyChange(TObject *Sender)
// по изменении номера частоты
{
  int i, j, Freq;
  i=CB_Frequency->ItemIndex;                   // записать текущий индекс поля выбора CB_Frequency
  j=CB_Modulus->ItemIndex;                     // записать текущий индекс поля выбора CB_Modulus

  Freq=StrToInt(E_Command6->Text);             // записать старое значение поля E_Command6 в переменную

  int Old = OldIndexF[j];                      // старый индекс номера частоты

  int rounding=Freq/10;                        // округление до числа, кратного 10
  Freq=rounding*10;
  int code=(Freq-8500)/10;                     // получение кода центральной частоты
  int code_LSB=code&0xFF;                      // младший байт центральной частоты рабочей полосы
  int code_MSB=(code/256)&0xFF;                // старший байт центральной частоты рабочей полосы
  // записать старое значение по индексу Old в массив:
  Mod[j][Old][0]=code_MSB;                     // записать значение старшего байта центральной частоты рабочей полосы
  Mod[j][Old][1]=code_LSB;                     // записать значение младшего байта центральной частоты рабочей полосы

  // записать значение коэффициента ослабления по индексу Old:
  for(int z=0; z<NUMBOFREQS; z++)
  {
    if(CB_Command7->ItemIndex==z) Mod[j][Old][2]=63-z;
  }

  // записать значение сдвига разрядов по индексу Old:
  for(int z=0; z<7; z++)
  {
    if(CB_Shift->ItemIndex==z) Mod[j][Old][3]=z;
  }

  // сохранить текущий индекс как старый для следующего вхождения в метод:
  Old=i;                                       
  OldIndexF[j]=Old;
  OldIndexMod=j;

  // извлечь значение из массива по текущему индексу в поле редактирования:
  E_Command6->Text=IntToStr(10*(Mod[j][i][0]*256+Mod[j][i][1])+8500);  // извлечь значение из массива по текущему индексу в поле E_Command3

  Command6[2]=Mod[j][i][0];  // при загрузке из файла
  Command6[3]=Mod[j][i][1];

  // извлечь значение из массива по текущему индексу в поле выбора:
  for(int z=0; z<NUMBOFREQS; z++)
  {
    if(Mod[j][i][2]==63-z)
    {
      CB_Command7->ItemIndex=z;
    }
  }

  Command7[3]=Mod[j][i][2];  // при загрузке из файла

  // извлечь значение из массива по текущему индексу в поле выбора:
  for(int z=0; z<7; z++)
  {
    if(Mod[j][i][3]==z)
    {
      CB_Shift->ItemIndex=z;
    }
  }

  Shift[3]=Mod[j][i][3];  // при загрузке из файла  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_ModChange(TObject *Sender)
{
  int ModN;
  if(E_Mod->Text=="") E_Mod->Text=0;
  ModN=StrToInt(E_Mod->Text);

  // записать старое значение по индексу OldIndexMod в массив:
  ModNumber[OldIndexMod]=ModN;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_ModExit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=999;
  int delta=1;
  String EdIzm="";
  String value;

  value=E_Mod->Text;

  b=IsValidInt(min,max,value,EdIzm);
  if(b)
  {
    int ModN;
    E_Mod->Text=RoundValue(delta,value);
    ModN=StrToInt(E_Mod->Text);

    // записать старое значение по индексу OldIndexMod в массив:
    ModNumber[OldIndexMod]=ModN;
  }
  else
  {
    E_Mod->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SearchCOMPorts(void)
{
  TRegistry *reg = new TRegistry;
  TStringList *list = new TStringList;
  reg->RootKey = HKEY_LOCAL_MACHINE;
  reg->OpenKey("HARDWARE\\DEVICEMAP\\SERIALCOMM", false);
  reg->GetValueNames(list);
  for(int i = 0; i < list->Count; i++)
  list->Strings[i] = reg->ReadString( list->Strings[i]);
  list->Sort();
  LB_AvailableCom->Clear();
  LB_AvailableCom->Items->AddStrings(list);
  delete list;
  delete reg;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AvailableComClick(TObject *Sender)
{
  SearchCOMPorts();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ButtonsOff(void)
{
  RG_Mode->Enabled=false;
  B_Ready->Enabled=false;
  B_Send->Enabled=false;
  CB_ComNum->Enabled=false;
  GB_TCommand->Enabled=false;
  RB_5GHz->Enabled=false;
  RB_8GHz->Enabled=false;  
  //PC_Main->Enabled=false;
  //Tsh_Control->Enabled=false;
  //Tsh_Testing->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ButtonsOn(void)
{
  RG_Mode->Enabled=true;
  B_Ready->Enabled=true;
  B_Send->Enabled=true;
  CB_ComNum->Enabled=true;
  GB_TCommand->Enabled=true;
  RB_5GHz->Enabled=true;
  RB_8GHz->Enabled=true;
  //PC_Main->Enabled=true;
  //Tsh_Control->Enabled=true;
  //Tsh_Testing->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ComPortException(void)
{
  if(CommPort1->Open!=true)
  {
    throw "";
  }
}
//---------------------------------------------------------------------------

