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
#include <iostream>
#include <cmath>
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
static int sec=0;       // глобальная переменная секунды
int itemNumber=0;       // количество БТ с ненулевыми значениями параметров
int X=0;                // значение координаты БТ по оси X
int Y=0;                // значение координаты БТ по оси Y
float Fi=0;             // значение направления полёта
int D=0;                // расстояние до цели [м]
int V=0;                // скорость полёта РСА [м/с]
int f=0;                // несущая частота [МГц]

int Command1[4]={1, 0, 0, 1};
int Command2[4]={2, 0, 1, 1};
int Command3[64][4];
int Command4[64][4];
int Command5[64][4];
int Command6[4]={6, 0, 0, 0};
int Command7[4]={7, 0, 0, 63};

int Com1[4]={225, 0, 0, 1};
int Com2[4]={226, 0, 1, 1};
int Com3[64][4];
int Com4[64][4];
int Com5[64][4];

int Com6[4]={230, 0, 0, 31};
int Com7[4]={231, 0, 0, 63};
int Com8[4]={232, 0, 7, 142};
int Com9[4]={233, 0, 7, 142};
int Com10[4]={234, 0, 0, 0};
int Com11[4]={235, 0, 0, 0};
int Com12[4]={236, 0, 0, 0};
/*
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;
*/
int Com13[4]={237, 0, 0, 200};   // 00, 00, c8
int Com14[4]={238, 0, 201, 128}; // 00, c9, 80
int Com15[4]={239, 0, 8, 194};   // 00, 08, c2
int Com16[4]={240, 78, 0, 0};    // 4e, 00, 00
int Com17[4]={241, 179, 4, 0};   // b3, 04, 00
int Com18[4]={242, 0, 36, 1};    // 00, 24, 01
int Com19[4]={243, 165, 0, 5};   // a5, 00, 05
int Com20[4]={244, 0, 88, 0};    // 00, 58, 00

//  Константные определения ошибок
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

// Переменные
int OldIndex=0;

//---------------------------------------------------------------------------
#pragma package(smart_init)   /* директива определяет последовательность инициализации пакетов такой, какая
устанавливается взаимными ссылками использующих их модулей */
#pragma link "CommPort"
#pragma resource "*.dfm"  // для формы надо использовать файл .dfm с тем же именем, что и имя данного файла
TMain_Form *Main_Form;    // объявление указателя на объект формы Main_Form
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

  // инициализация массива Com3
  for(int i=0; i<64; i++)
  {
    Com3[i][0]=227;     // байт кода команды
    Com3[i][1]=i+1;     // 1-й байт пакета данных
    Com3[i][2]=0;       // 2-й байт пакета данных
  }
  Com3[0][3]=255;       // 3-й байт пакета данных (БТ №1)

  for(int i=1; i<64; i++)
  {
    Com3[i][3]=0;       // 3-й байт пакета данных (остальные БТ)
  }

  // инициализация массива Com4
  for(int i=0; i<64; i++)
  {
    Command4[i][0]=228; // байт кода команды
    Command4[i][1]=i+1; // 1-й байт пакета данных
    Command4[i][2]=0;   // 2-й байт пакета данных
    Command4[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива Command5
  for(int i=0; i<64; i++)
  {
    Command5[i][0]=229; // байт кода команды
    Command5[i][1]=i+1; // 1-й байт пакета данных
    Command5[i][2]=0;   // 2-й байт пакета данных
    Command5[i][3]=0;   // 3-й байт пакета данных
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SB_OnOffClick(TObject *Sender)
{
  if(SB_OnOff->Down)         // если нажата
  {
    SB_OnOff->Caption="Выключить";
    SB_OnOff->Font->Color=clRed;

    if(RG_Mode->ItemIndex==0)
    {
      StartControl();
      AddSaveLog("Включен режим Управление");  // добавить комментарий и сохранить лог
    }
    else
    {
      StartTesting();
      AddSaveLog("Включен режим Тестирование");  // добавить комментарий и сохранить лог
    }
    
    WorkTimer->Enabled=true; // включить таймер WorkTimer
  }
  else                       // если не нажата
  {
    SB_OnOff->Caption="Включить";
    SB_OnOff->Font->Color=clGreen;

    if(RG_Mode->ItemIndex==0)
    {
      StopControl();
      AddSaveLog("Выключен режим Управление. Время работы составило "+P_WorkTime->Caption);  // добавить комментарий и сохранить лог
    }
    else
    {
      StopTesting();
      AddSaveLog("Выключен режим Тестирование. Время работы составило "+P_WorkTime->Caption);  // добавить комментарий и сохранить лог
    }

    WorkTimer->Enabled=false;         // включить таймер WorkTimer
    sec=0;                            // обнулить значение секунд
    P_WorkTime->Caption = "00:00:00"; // обнулить значение времени работы
/*
    ExtractFilePath(Application->ExeName) - путь к исполнимому файлу.
    GetCurrentDir() - путь к текущей директории.
    Они не обязаны совпадать, текущий каталог величина не постоянная,
    зависит от способа запуска проги и может меняться в процессе.
*/
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
  if(E_EnterComment->Text!="") AddSaveLog(E_EnterComment->Text); // запись лог файла
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_LoadBlpClick(TObject *Sender) // нажатие на кнопку "Открыть файл .blp"
{
  AddSaveLog("Загрузить файл данных БТ");  // добавить комментарий и сохранить лог
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

  if(OpenDialog->Execute())          // если выбран диалог OpenDialog
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  Отображает диалог выбора файлов.
  Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
  Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/
  {
    BlpFName = OpenDialog->FileName; // имя выбранного файла сохраняется в переменной BlpFName
    LVScan->Items->Clear();          // очистка LVScan
    Update_Dump_blp();               // загрузка файла BlpFName в LVScan
  }
  if(!infile)                        // если не входной файловый поток
  {
    MessageBox(NULL,"Файл не удается открыть!","Ошибка!",MB_OK|MB_ICONERROR);
    return;
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
    SarFName = OpenDialog1->FileName; // имя выбранного файла сохраняется в переменной SarFName
    LV_Sar1->Items->Clear();          // очистка LV_Sar1
    LV_Sar2->Items->Clear();          // очистка LV_Sar2
    LV_Sar3->Items->Clear();          // очистка LV_Sar3
    LV_Sar4->Items->Clear();          // очистка LV_Sar4
    Update_Dump_sar();                // загрузка файла SarFName в LV_Sar1 и LV_Sar2
    c1=false;                         // запретить добавление строк в LV_Sar1
    B_AddSar1->Enabled=false;         // отключить кнопку "Добвить данные Sar1"
    c2=false;                         // запретить добавление строк в LV_Sar2
    B_AddSar2->Enabled=false;         // отключить кнопку "Добвить данные Sar2"
    c3=false;                         // запретить добавление строк в LV_Sar3
    B_AddSar3->Enabled=false;         // отключить кнопку "Добвить данные Sar3"
    c4=false;                         // запретить добавление строк в LV_Sar4
    B_AddSar4->Enabled=false;         // отключить кнопку "Добвить данные Sar4"
  }
  if(!infile)                         // если не входной файловый поток
  {
    MessageBox(NULL,"Файл не удается открыть!","Ошибка!",MB_OK|MB_ICONERROR);
    return;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Update_Dump_blp() // открыть дамп blp
{
/*
  Хотя вполне корректно использовать функцию open() для открытия файла,
  в большинстве случаев это делается по-другому, поскольку классы ifstream,
  ofstream и fstream включают конструкторы, которые автоматически откры-
  вают заданный файл. Параметры у этих конструкторов и их значения (действую-
  щие по умолчанию) совпадают с параметрами и соответствующими значениями
  функции open(). Поэтому чаще всего файл открывается так, как показано в сле-
  дующем примере.
  ifstream mystream("myfile"); // файл открывается для ввода (чтения)
  ---------------------------------------------------------------------------
  std::string::c_str();
  Функция c_str из класса string формирует массив строк в стиле си. И возвращает указатель на него.
  Допустим, некоторая функция в качестве параметра принимает указатель на массив чаров:
  void Foo(const char* content);
  То есть, в неё можно передать строку только в виде c-ctyle указателя
  А у тебя есть строка записанная в стринге:
  std::string str="привет мир";
  И тебе нужно передать эту строку в твою функцию:
  Foo(str); //нельзя. функция не умеет работать со стрингами
  но так как функция не умеет работать со стрингами, а только с указателями, то единственный способ
  сделать это - функция c_str()
  Foo(str.c_str() ); //можно.
  Функция c_str() присутствует только для совместимости с с-style кодом.
  И в собственном c++ style коде, её лучше избегать настолько, насколько это возможно, дабы не
  плодить "суржик" (смесь двух стилей в одном исходном коде)
*/
  std::ifstream infile(BlpFName.c_str()); // Входной файловый поток (файл открывается для ввода (чтения))
/*
  Строка в Си является массивом символов, который заканчивается нулевым символом ('\0'). Доступ к строке
  осуществляется через указатель, ссылающийся на первый символ строки. Значением строки является адрес
  её первого символа. Т.о., строка - это указатель, фактически указатель на первый символ строки.
  Строка может быть присвоена в объявлении либо массиву символов, либо переменной типа char *.
  Инициализация строк:
  char color[] = "blue"; // массив из 5-и элементов, содержащих символы 'b', 'l', 'u', 'e', '\0'
  const char colorPtr = "blue"; // переменная-указатель colorPtr, которая указывает на строку "blue"
  char color[] = {'b', 'l', 'u', 'e', '\0'};
  В Си++ функцию строк выполняет класс std::string. Отличается от с-style строки тем, что
  стандарт не оговаривает, как std::string хранит данные внутри себя, а в строке с-style все элементы
  хранятся в памяти последовательно; концевой ноль за пределами контейнера добавляется автоматически,
  а в с-style строке добавлением символа конца строки занимается программист.
*/  
  std::string x;     // строка x класса string
  TListItem *item=0; // указатель на объект типа TListItem (первый столбец строки ListView)  
  bool flag=false;   // флаг отсутствия заполнения объекта item
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

  // extract to string
  #include <iostream>
  #include <string>

  main ()
  {
    std::string name;

    std::cout << "Please, enter your full name: ";
    std::getline (std::cin,name);
    std::cout << "Hello, " << name << "!\n";

    return 0;
 }
 ---------------------------------------------------------------------------
  Функция std::basic_ios::fail возвращает истину, если произошла ошибка на соответствующем потоке.
*/
  while(!std::getline(infile,x).fail()) // пока нет ошибки при заполнении строки из входного потока
  {
/*
    Функция std::string::size возвращает длину строки (количество символов); 
	  возвращаемое значение size_t целочисленного типа без знака.
	
	  // string::size
    #include <iostream>
    #include <string>

    int main ()
    {
      std::string str ("Test string");
      std::cout << "The size of str is " << str.size() << " characters.\n";
      return 0;
    }

    Output:
    The size of str is 11 characters.
    ---------------------------------------------------------------------------
    Функция std::string::resize изменяет длину строки на количество n символов
    void resize (size_t n);
    void resize (size_t n, char c);

    // resizing string
    #include <iostream>
    #include <string>

    int main ()
    {
      std::string str ("I like to code in C");
      std::cout << str << '\n';

      unsigned sz = str.size();

      str.resize (sz+2,'+');
      std::cout << str << '\n';

      str.resize (14);
      std::cout << str << '\n';
      return 0;
    }

    Output:

    I like to code in C
    I like to code in C++
    I like to code
    ---------------------------------------------------------------------------
    Функция std::string::erase стирает часть строки, уменьшая её длину.
    sequence  (1) string& erase (size_t pos = 0, size_t len = npos);
    character (2) iterator erase (iterator p);
    range     (3) iterator erase (iterator first, iterator last);

    (1) sequence
    Erases the portion of the string value that begins at the character position pos and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.
    Notice that the default argument erases all characters in the string (like member function clear).
    (2) character
    Erases the character pointed by p.
    (3) range
    Erases the sequence of characters in the range [first,last).

    // string::erase
    #include <iostream>
    #include <string>

    int main ()
    {
      std::string str ("This is an example sentence.");
      std::cout << str << '\n';
                                               // "This is an example sentence."
      str.erase (10,8);                        //            ^^^^^^^^
      std::cout << str << '\n';
                                               // "This is an sentence."
      str.erase (str.begin()+9);               //           ^
      std::cout << str << '\n';
                                               // "This is a sentence."
      str.erase (str.begin()+5, str.end()-9);  //       ^^^^^
      std::cout << str << '\n';
                                               // "This sentence."
      return 0;
    }

    Output:

    This is an example sentence.
    This is an sentence.
    This is a sentence.
    This sentence.
*/
    if(!x.size()) {item=0;flag=false;continue;}
/*
    Если длина строки =0 (!x.size() или x.size()==0), то объект item отсутствует;
    отсутствует заполнение объекта item; продолжить для возможности заполнения объекта item.
*/
    if(x.size()&&'"'==x[x.size()-1]) x.resize(x.size()-1);
/*
    x.size() - количество символов в строке;
    [x.size()-1] - порядковый номер последнего символа строки (т.к. отсчёт с нуля);
    Если символ кавычки ('"') является последним символом строки (x[x.size()-1]), то
    изменить длину строки на количество x.size()-1 символов (т.е. на 1 меньше длины строки).
*/
    if(x.size()&&'"'==x[0]) x.erase(0,1);
/*
    Если символ кавычки ('"') является нулевым символом строки (x[0]), то
    удалить из строки один символ, начиная с нулевого сивола x.erase(0,1).
*/
    if(!item) {item=LVScan->Items->Add(); itemNumber++;}
/*
    Если объект item отсутствует, то добавить объект item; itemNumber++; подсчитать количество БТ
*/
    if(!flag){ item->Caption=x.c_str(); flag=true; }
/*
    Если отсутствует заполнение объекта item, то аполнить объект item из строки с-style.
    Поднять флаг заполнения объекта item.
*/
    else item->SubItems->Add(x.c_str()); // иначе заполнить объект SubItems
  }

  for(int i=itemNumber+1;i<=64;i++) // для всех дополнительных БТ с нулевыми значениями параметров до 64-х включительно
  {
    item = LVScan->Items->Add();    // добавить новую строку LVScan
    item->Caption = i;              // добавить номер БТ
    item->SubItems->Add(0);         // заполнить колонки значениями 0
    item->SubItems->Add(0);
    item->SubItems->Add(0);
  }

  AddSaveLog("Загружен файл "+BlpFName);  // добавить комментарий и сохранить лог
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
void __fastcall TMain_Form::B_AddBTClick(TObject *Sender) // нажатие кнопку "Добавить БТ"
{
  //static int k = 1;                        // счётчик БТ
  TListItem *Item = LVScan->Items->Add();  // добавить новую строку LVScan
  Item->Caption = 0;                       // заполнить колонки значениями 0
  Item->SubItems->Add(0);
  Item->SubItems->Add(0);
  Item->SubItems->Add(0);
  //k++;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteBTClick(TObject *Sender) // нажатие кнопку "Удалить БТ"
{
  if (LVScan->Selected != NULL)  // если выбранная строка LVScan не пуста
  {
    LVScan->Selected->Delete();  // удалить выбранную строку
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar1Click(TObject *Sender) // нажатие на кнопку "Добвить данные Sar1"
{
  if(c1)                                      // если нет запрета добавления строк в LV_Sar1
  {
    TListItem *Item = LV_Sar1->Items->Add();  // добавить новую строку LV_Sar1
    // заполнить колонки значениями по умолчанию
    Item->Caption = 0;                        // V полёта РСА [м/с]
    Item->SubItems->Add(0);                   // Несущая частота [Мгц]
    Item->SubItems->Add(0);                   // Направление полёта [град.]
    Item->SubItems->Add(0);                   // Положение антенн РСА [град.]
    Item->SubItems->Add(0);                   // Расстояние до цели [м]
    c1=false;
    B_AddSar1->Enabled=false;
  }  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteSar1Click(TObject *Sender) // нажатие на кнопку "Удалить данные Sar1"
{
  if (LV_Sar1->Selected != NULL)  // если выбранная строка LV_Sar1 не пуста
  {
    LV_Sar1->Selected->Delete();  // удалить выбранную строку
    c1=true;                      // разрешить добавления строк в LV_Sar1
    B_AddSar1->Enabled=true;      // включить кнопку "Добвить данные Sar1"
  }
}                                    
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar2Click(TObject *Sender) // нажатие на кнопку "Добвить данные Sar2"
{
  if(c2)                                      // если нет запрета добавления строк в LV_Sar2
  {
    TListItem *Item = LV_Sar2->Items->Add();  // добавить новую строку LV_Sar2
    // заполнить колонки значениями по умолчанию
    Item->Caption = 0;                        // Ку усилителя 1 [дБ]
    Item->SubItems->Add(0);                   // Ку усилителя 2 [дБ]
    Item->SubItems->Add(970);                 // f среза фильтра 1 [град.]
    Item->SubItems->Add(970);                 // f среза фильтра 2 [град.]
    Item->SubItems->Add(1);                   // Wраб. приёмника
    Item->SubItems->Add(1);                   // Wраб. передатчика
    c2=false;
    B_AddSar2->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteSar2Click(TObject *Sender) // нажатие на кнопку "Удалить данные Sar2"
{
  if (LV_Sar2->Selected != NULL)  // если выбранная строка LV_Sar2 не пуста
  {
    LV_Sar2->Selected->Delete();  // удалить выбранную строку
    c2=true;                      // разрешение добавления строк в LV_Sar2
    B_AddSar2->Enabled=true;      // включение кнопки "Добвить данные Sar2"
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar3Click(TObject *Sender) // нажатие на кнопку "Добвить данные Sar2"
{
  if(c3)                                      // если нет запрета добавления строк в LV_Sar3
  {
    TListItem *Item = LV_Sar3->Items->Add();  // добавить новую строку LV_Sar3
    // заполнить колонки значениями по умолчанию
    // Reg[0]=0x00C80000;
    Item->Caption = IntToHex(0, 2);           // Байт 1  (R0_1)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 2  (R0_2)
    Item->SubItems->Add(IntToHex(200, 2));    // Байт 3  (R0_3)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 4  (R0_4)
    // Reg[1]=0x080080C9;
    Item->SubItems->Add(IntToHex(201, 2));    // Байт 5  (R1_1)
    Item->SubItems->Add(IntToHex(128, 2));    // Байт 6  (R1_2)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 7  (R1_3)
    Item->SubItems->Add(IntToHex(8, 2));      // Байт 8  (R1_4)
    // Reg[2]=0x00004EC2;
    Item->SubItems->Add(IntToHex(194, 2));    // Байт 9  (R2_1)
    Item->SubItems->Add(IntToHex(78, 2));     // Байт 10 (R2_2)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 11 (R2_3)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 12 (R2_4)
    c3=false;                                 // запрет добавления строк в LV_Sar3
    B_AddSar3->Enabled=false;                 // отключение кнопки "Добвить данные Sar3"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_AddSar4Click(TObject *Sender)
{
  if(c4)                                      // если нет запрета добавления строк в LV_Sar4
  {
    TListItem *Item = LV_Sar4->Items->Add();  // добавить новую строку LV_Sar4
    // заполнить колонки значениями по умолчанию
    // Reg[3]=0x000004B3;
    Item->Caption = IntToHex(179, 2);         // Байт 13 (R3_1)
    Item->SubItems->Add(IntToHex(4, 2));      // Байт 14 (R3_2)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 15 (R3_3)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 16 (R3_4)
    // Reg[4]=0x00A5003C;
    Item->SubItems->Add(IntToHex(60, 2));     // Байт 17 (R4_1)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 18 (R4_2)
    Item->SubItems->Add(IntToHex(165, 2));    // Байт 19 (R4_3)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 20 (R4_4)
    // Reg[5]=0x00580005;
    Item->SubItems->Add(IntToHex(5, 2));      // Байт 21 (R5_1)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 22 (R5_2)
    Item->SubItems->Add(IntToHex(88, 2));     // Байт 23 (R5_3)
    Item->SubItems->Add(IntToHex(0, 2));      // Байт 24 (R5_4)
    c4=false;                                 // запрет добавления строк в LV_Sar4
    B_AddSar4->Enabled=false;                 // отключение кнопки "Добвить данные Sar4"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DeleteSar3Click(TObject *Sender) // нажатие на кнопку "Удалить данные Sar3"
{
  if (LV_Sar3->Selected != NULL)  // если выбранная строка LV_Sar3 не пуста
  {
    LV_Sar3->Selected->Delete();  // удалить выбранную строку
    c3=true;                      // разрешение добавления строк в LV_Sar3
    B_AddSar3->Enabled=true;      // включение кнопки "Добвить данные Sar3"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DeleteSar4Click(TObject *Sender)
{
  if (LV_Sar4->Selected != NULL)  // если выбранная строка LV_Sar4 не пуста
  {
    LV_Sar4->Selected->Delete();  // удалить выбранную строку
    c4=true;                      // разрешение добавления строк в LV_Sar4
    B_AddSar4->Enabled=true;      // включение кнопки "Добвить данные Sar4"
  }
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

void __fastcall TMain_Form::LVScanDblClick(TObject *Sender)  // двойной щелчок по LVScan
{
  if (LVScan->Selected!= NULL) F_BT->ShowModal();  
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
/*
  Подготовка команды "Амплитуда блестящей точки (БТ)" режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size.
*/

  if((size_t)LVScan->Items->Count!=0) // если количество строк LVScan не нулевое
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i)  // перебор БТ по количеству строк LVScan
    {
      Command3[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());            // записать значение номера БТ
      float EPR=StrToFloat(LVScan->Items->Item[i]->SubItems->Strings[2].c_str());  // подготовить значение ЭПР
      Command3[i][3]=int(sqrt(EPR));                                               // записать значение амплитуды БТ

      //M_Debug->Lines->Add(Command3[i][1]);
      //M_Debug->Lines->Add(Command3[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i) // перебор БТ от последней строки
    {                                                   // LVScan до 64
      //M_Debug->Lines->Add(Command3[i][1]);
      //M_Debug->Lines->Add(Command3[i][3]);
    }
  }
  else                                // если в LVScan строки отсутствуют
  {
    for(int i=0;i<64;++i)             // перебор БТ от 1 до 64
    {
      //M_Debug->Lines->Add(Command3[i][1]);
      //M_Debug->Lines->Add(Command3[i][3]);
    }
  }
/*
  Подготовка команды "Время задержки (БТ)" режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size.
*/
  if((size_t)LV_Sar1->Items->Count!=0) // если количество строк LV_Sar1 не нулевое
  {
    Fi=StrToFloat(LV_Sar1->Items->Item[0]->SubItems->Strings[1].c_str());  // подготовить значение направления полёта
    //M_Debug->Lines->Add(Fi);
  }

  if((size_t)LVScan->Items->Count!=0) // если количество строк LVScan не нулевое
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // перебор по количеству строк LVScan
    {
      Command4[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());  // записать значение номера БТ
      X=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[0].c_str());  // подготовить значение координаты БТ по оси X
      Y=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[1].c_str());  // подготовить значение координаты БТ по оси Y
      float arg=Fi*pi/180;                                  // перевод градусов в радианы
      float Xi=X*cos(arg)+Y*sin(arg);                       // координата X с учётом направления полёта Fi
      float Tau=((2*Xi)/c-0.000001)*1000000000;             // время задержки БТ [нс], цена младшего разряда 1 нс
      int Tau_LSB=((int)Tau)&0xFF;                          // младший байт времени задержки БТ
      int Tau_MSB=((int)Tau/256)&0xFF;                      // старший байт времени задержки БТ
      Command4[i][2]=Tau_MSB;                               // записать значение старшего байта времени задержки БТ
      Command4[i][3]=Tau_LSB;                               // записать значение младшего байта времени задержки БТ

      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i)     // перебор БТ от последней строки
    {                                                       // LVScan до 64
      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
  }
  else                                // если в LVScan строки отсутствуют
  {
    for(int i=0;i<64;++i)             // перебор БТ от 1 до 64
    {
      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
  }
/*
  Подготовка команды "Доплеровский сдвиг частоты (БТ)" режима Тестирование
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size.
*/
  if((size_t)LV_Sar1->Items->Count!=0) // если количество строк LV_Sar1 не нулевое
  {
    V=StrToInt(LV_Sar1->Items->Item[0]->Caption.c_str());              // подготовить значение скорости полёта РСА
    f=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[0].c_str()); // подготовить значение несущей частоты
    D=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[3].c_str()); // подготовить значение расстояния до цели

    //M_Debug->Lines->Add(D);
  }

  if((size_t)LVScan->Items->Count!=0) // если количество строк LVScan не нулевое
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // перебор по количеству строк LVScan
    {
      Command4[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());  // записать значение номера БТ
      X=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[0].c_str());  // подготовить значение координаты БТ по оси X
      Y=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[1].c_str());  // подготовить значение координаты БТ по оси Y
      float arg=Fi*pi/180;                                  // перевод градусов в радианы
      float Yi=Y*cos(arg)-X*sin(arg);                       // координата Y с учётом направления полёта Fi
      float fdi=f*V*Yi/c*D;                                 // доплеровское смещение БТ [Гц], цена младшего разряда 0.5 Гц
      int fdi_LSB=((int)fdi)&0xFF;                          // младший байт доплеровского смещения БТ
      int fdi_MSB=((int)fdi/256)&0xFF;                      // старший байт доплеровского смещения БТ
      Command5[i][2]=fdi_MSB;                               // записать значение старшего байта доплеровского смещения БТ
      Command5[i][3]=fdi_LSB;                               // записать значение младшего байта доплеровского смещения БТ

      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i)     // перебор БТ от последней строки
    {                                                       // LVScan до 64
      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
  }
  else                                // если в LVScan строки отсутствуют
  {
    for(int i=0;i<64;++i)             // перебор БТ от 1 до 64
    {
      //M_Debug->Lines->Add(Command4[i][2]);
      //M_Debug->Lines->Add(Command4[i][3]);
    }
  }
/*
  Подготовка команды "Амплитуда блестящей точки (БТ)" режима Контроль
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size.
*/

  if((size_t)LVScan->Items->Count!=0) // если количество строк LVScan не нулевое
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i)  // перебор БТ по количеству строк LVScan
    {
      Com3[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());                // записать значение номера БТ
      float EPR=StrToFloat(LVScan->Items->Item[i]->SubItems->Strings[2].c_str());  // подготовить значение ЭПР
      Com3[i][3]=int(sqrt(EPR));                                                   // записать значение амплитуды БТ

      //M_Debug->Lines->Add(Com3[i][1]);
      //M_Debug->Lines->Add(Com3[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i) // перебор БТ от последней строки
    {                                                   // LVScan до 64
      //M_Debug->Lines->Add(Com3[i][1]);
      //M_Debug->Lines->Add(Com3[i][3]);
    }
  }
  else                                // если в LVScan строки отсутствуют
  {
    for(int i=0;i<64;++i)             // перебор БТ от 1 до 64
    {
      //M_Debug->Lines->Add(Com3[i][1]);
      //M_Debug->Lines->Add(Com3[i][3]);
    }
  }
/*
  Подготовка команды "Время задержки (БТ)" режима Контроль
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size.
*/
  if((size_t)LV_Sar1->Items->Count!=0) // если количество строк LV_Sar1 не нулевое
  {
    Fi=StrToFloat(LV_Sar1->Items->Item[0]->SubItems->Strings[1].c_str());  // подготовить значение направления полёта
    //M_Debug->Lines->Add(Fi);
  }

  if((size_t)LVScan->Items->Count!=0) // если количество строк LVScan не нулевое
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // перебор по количеству строк LVScan
    {
      Com4[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());      // записать значение номера БТ
      X=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[0].c_str());  // подготовить значение координаты БТ по оси X
      Y=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[1].c_str());  // подготовить значение координаты БТ по оси Y
      float arg=Fi*pi/180;                                  // перевод градусов в радианы
      float Xi=X*cos(arg)+Y*sin(arg);                       // координата X с учётом направления полёта Fi
      float Tau=((2*Xi)/c-0.000001)*1000000000;             // время задержки БТ [нс], цена младшего разряда 1 нс
      int Tau_LSB=((int)Tau)&0xFF;                          // младший байт времени задержки БТ
      int Tau_MSB=((int)Tau/256)&0xFF;                      // старший байт времени задержки БТ
      Com4[i][2]=Tau_MSB;                                   // записать значение старшего байта времени задержки БТ
      Com4[i][3]=Tau_LSB;                                   // записать значение младшего байта времени задержки БТ

      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i)     // перебор БТ от последней строки
    {                                                       // LVScan до 64
      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
  }
  else                                // если в LVScan строки отсутствуют
  {
    for(int i=0;i<64;++i)             // перебор БТ от 1 до 64
    {
      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
  }
/*
  Подготовка команды "Доплеровский сдвиг частоты (БТ)" режима Контроль
  size_t - возвращаемое значение длины строки целочисленного типа без знака функции std::string::size.
*/
  if((size_t)LV_Sar1->Items->Count!=0) // если количество строк LV_Sar1 не нулевое
  {
    V=StrToInt(LV_Sar1->Items->Item[0]->Caption.c_str());              // подготовить значение скорости полёта РСА
    f=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[0].c_str()); // подготовить значение несущей частоты
    D=StrToInt(LV_Sar1->Items->Item[0]->SubItems->Strings[3].c_str()); // подготовить значение расстояния до цели

    //M_Debug->Lines->Add(D);
  }

  if((size_t)LVScan->Items->Count!=0) // если количество строк LVScan не нулевое
  {
    for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // перебор по количеству строк LVScan
    {
      Com4[i][1]=StrToInt(LVScan->Items->Item[i]->Caption.c_str());      // записать значение номера БТ
      X=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[0].c_str());  // подготовить значение координаты БТ по оси X
      Y=StrToInt(LVScan->Items->Item[i]->SubItems->Strings[1].c_str());  // подготовить значение координаты БТ по оси Y
      float arg=Fi*pi/180;                                  // перевод градусов в радианы
      float Yi=Y*cos(arg)-X*sin(arg);                       // координата Y с учётом направления полёта Fi
      float fdi=f*V*Yi/c*D;                                 // доплеровское смещение БТ [Гц], цена младшего разряда 0.5 Гц
      int fdi_LSB=((int)fdi)&0xFF;                          // младший байт доплеровского смещения БТ
      int fdi_MSB=((int)fdi/256)&0xFF;                      // старший байт доплеровского смещения БТ
      Com5[i][2]=fdi_MSB;                                   // записать значение старшего байта доплеровского смещения БТ
      Com5[i][3]=fdi_LSB;                                   // записать значение младшего байта доплеровского смещения БТ

      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
    for(size_t i=(size_t)LVScan->Items->Count;i<64;++i)     // перебор БТ от последней строки
    {                                                       // LVScan до 64
      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
  }
  else                                // если в LVScan строки отсутствуют
  {
    for(int i=0;i<64;++i)             // перебор БТ от 1 до 64
    {
      //M_Debug->Lines->Add(Com4[i][2]);
      //M_Debug->Lines->Add(Com4[i][3]);
    }
  }
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
  String EdIzm="";                   // единица измерения
  String value;                      // строка значения

  value=E_Command3_0->Text;          // значение

  b=IsValidInt(min,max,value,EdIzm); // проверка правильности диапазона значений
  if(b)                              // если правильно
  {
    CB_Command3_1->Clear();          // очистить предыдущее количество БТ
    CB_Command4_1->Clear();
    CB_Command5_1->Clear();
 
    for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
    {
      CB_Command3_1->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
      CB_Command4_1->Items->Add(IntToStr(i+1));
      CB_Command5_1->Items->Add(IntToStr(i+1));
    }

    CB_Command3_1->ItemIndex=0;      // номер БТ по умолчанию при изменении числа БТ
    CB_Command4_1->ItemIndex=0;
    CB_Command5_1->ItemIndex=0;
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
  int i, Command;
  i=CB_Command3_1->ItemIndex;                           // записать порядковый номер БТ
  Command=StrToInt(E_Command3_2->Text);                 // записать значение в переменную
  Command3[OldIndex][3]=Command&0xFF;                   // мл. байт
  Command3[OldIndex][2]=(Command/256)&0xFF;             // ст. байт
  OldIndex=i;                                           // сохранить текущий порядковый номер
  E_Command3_2->Text=IntToStr(Command3[i][2]*256+Command3[i][3]); // показать текущее значение
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command4_1Change(TObject *Sender)
// по изменении номера БТ
{
  int i, Command;
  i=CB_Command4_1->ItemIndex;                           // записать порядковый номер БТ
  Command=StrToInt(E_Command4_2->Text);                 // записать значение в переменную
  Command4[OldIndex][3]=Command&0xFF;                   // мл. байт
  Command4[OldIndex][2]=(Command/256)&0xFF;             // ст. байт
  OldIndex=i;                                           // сохранить текущий порядковый номер
  E_Command4_2->Text=IntToStr(Command4[i][2]*256+Command4[i][3]); // показать текущее значение
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command5_1Change(TObject *Sender)
// по изменении номера БТ
{
  int i, Command;
  i=CB_Command5_1->ItemIndex;                           // записать порядковый номер БТ
  Command=StrToInt(E_Command5_2->Text);                 // записать значение в переменную
  Command5[OldIndex][3]=Command&0xFF;                   // мл. байт
  Command5[OldIndex][2]=(Command/256)&0xFF;             // ст. байт
  OldIndex=i;                                           // сохранить текущий порядковый номер
  E_Command5_2->Text=IntToStr(Command5[i][2]*256+Command5[i][3]); // показать текущее значение
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::E_Command6Change(TObject *Sender)
{
  int Fc=StrToInt(E_Command6->Text);            // центральная частота рабочей полосы
  if(Fc>=8500&&Fc<=17500)                       // если диапазон правильный
  {
    int rounding=Fc/10;                         // округление до числа, кратного 10
    Fc=rounding*10;
    int code=(Fc-8500)/10;                      // получение кода центральной частоты
    int code_LSB=code&0xFF;                     // младший байт центральной частоты рабочей полосы
    int code_MSB=(code/256)&0xFF;               // старший байт центральной частоты рабочей полосы
    Command6[2]=code_MSB;                       // записать значение старшего байта центральной частоты рабочей полосы
    Command6[3]=code_LSB;                       // записать значение младшего байта центральной частоты рабочей полосы
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Command7Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Command7->ItemIndex==i) Command7[3]=63-i;
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
    CB_Com4_1->Clear();
    CB_Com5_1->Clear();
    
    for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
    {
      CB_Com3_1->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
      CB_Com4_1->Items->Add(IntToStr(i+1));
      CB_Com5_1->Items->Add(IntToStr(i+1));
    }

    CB_Com3_1->ItemIndex=0;          // номер БТ по умолчанию при изменении числа БТ
    CB_Com4_1->ItemIndex=0;
    CB_Com5_1->ItemIndex=0;
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
  int i, Command;
  i=CB_Com3_1->ItemIndex;                    // записать порядковый номер БТ
  Command=StrToInt(E_Com3_2->Text);          // записать значение в переменную
  Com3[OldIndex][3]=Command&0xFF;            // мл. байт
  Com3[OldIndex][2]=(Command/256)&0xFF;      // ст. байт
  OldIndex=i;                                // сохранить текущий порядковый номер
  E_Com3_2->Text=IntToStr(Com3[i][2]*256+Com3[i][3]);  // показать текущее значение
}

//---------------------------------------------------------------------------
void __fastcall TMain_Form::CB_Com4_1Change(TObject *Sender)
// по изменении номера БТ
{
  int i, Command;
  i=CB_Com4_1->ItemIndex;                    // записать порядковый номер БТ
  Command=StrToInt(E_Com4_2->Text);          // записать значение в переменную
  Com4[OldIndex][3]=Command&0xFF;            // мл. байт
  Com4[OldIndex][2]=(Command/256)&0xFF;      // ст. байт
  OldIndex=i;                                // сохранить текущий порядковый номер
  E_Com4_2->Text=IntToStr(Com4[i][2]*256+Com4[i][3]);  // показать текущее значение
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::CB_Com5_1Change(TObject *Sender)
// по изменении номера БТ
{
  int i, Command;
  i=CB_Com5_1->ItemIndex;                    // записать порядковый номер БТ
  Command=StrToInt(E_Com5_2->Text);          // записать значение в переменную
  Com5[OldIndex][3]=Command&0xFF;            // мл. байт
  Com5[OldIndex][2]=(Command/256)&0xFF;      // ст. байт
  OldIndex=i;                                // сохранить текущий порядковый номер
  E_Com5_2->Text=IntToStr(Com5[i][2]*256+Com5[i][3]);  // показать текущее значение
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
void __fastcall TMain_Form::E_Com13_1Change(TObject *Sender)
{
  Com13[1]=StrToInt(E_Com13_1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com13_2Change(TObject *Sender)
{
  Com13[2]=StrToInt(E_Com13_2->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com13_3Change(TObject *Sender)
{
  Com13[3]=StrToInt(E_Com13_3->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com14_1Change(TObject *Sender)
{
  Com14[1]=StrToInt(E_Com14_1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com14_2Change(TObject *Sender)
{
  Com14[2]=StrToInt(E_Com14_2->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com14_3Change(TObject *Sender)
{
  Com14[3]=StrToInt(E_Com14_3->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com15_1Change(TObject *Sender)
{
  Com15[1]=StrToInt(E_Com15_1->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com15_2Change(TObject *Sender)
{
  Com15[2]=StrToInt(E_Com15_2->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com15_3Change(TObject *Sender)
{
  Com15[3]=StrToInt(E_Com15_3->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com16_1Change(TObject *Sender)
{
  Com16[1]=StrToInt(E_Com16_1->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com16_2Change(TObject *Sender)
{
  Com16[2]=StrToInt(E_Com16_2->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com16_3Change(TObject *Sender)
{
  Com16[3]=StrToInt(E_Com16_3->Text);   
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com17_1Change(TObject *Sender)
{
  Com17[1]=StrToInt(E_Com17_1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com17_2Change(TObject *Sender)
{
  Com17[2]=StrToInt(E_Com17_2->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com17_3Change(TObject *Sender)
{
  Com17[3]=StrToInt(E_Com17_3->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com18_1Change(TObject *Sender)
{
  Com18[1]=StrToInt(E_Com18_1->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com18_2Change(TObject *Sender)
{
  Com18[2]=StrToInt(E_Com18_2->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com18_3Change(TObject *Sender)
{
  Com18[3]=StrToInt(E_Com18_3->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com19_1Change(TObject *Sender)
{
  Com19[1]=StrToInt(E_Com19_1->Text);  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com19_2Change(TObject *Sender)
{
  Com19[2]=StrToInt(E_Com19_2->Text);    
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com19_3Change(TObject *Sender)
{
  Com19[3]=StrToInt(E_Com19_3->Text);    
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com20_1Change(TObject *Sender)
{
  Com20[1]=StrToInt(E_Com20_1->Text);    
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com20_2Change(TObject *Sender)
{
  Com20[2]=StrToInt(E_Com20_2->Text);     
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::E_Com20_3Change(TObject *Sender)
{
  Com20[3]=StrToInt(E_Com20_3->Text);     
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StartControl()
{
  RG_Mode->Enabled=false;
  GB_File->Enabled=false;
  GB_Commands->Enabled=false;
  PC_Main->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StopControl()
{
  RG_Mode->Enabled=true;
  GB_File->Enabled=true;
  GB_Commands->Enabled=true;
  PC_Main->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StartTesting()
{
  RG_Mode->Enabled=false;
  GB_File->Enabled=false;
  GB_Commands->Enabled=false;
  PC_Main->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::StopTesting()
{
  RG_Mode->Enabled=true;
  GB_File->Enabled=true;
  GB_Commands->Enabled=true;
  PC_Main->Enabled=true;
}
//---------------------------------------------------------------------------






