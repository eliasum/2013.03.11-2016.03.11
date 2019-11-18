// файл реализации формы Main_Form
//---------------------------------------------------------------------------
// директивы препроцессора #include подключают в данный файл тексты указанных в них файлов
#include <vcl.h>  // объявления, используемые в библиотеке визуальных компонентов С++Builder
#pragma hdrstop   // конец списка общих заголовочных файлов для всех модулей проекта

#include "BlazePoint_main.h"
#include "BT.h"
#include "Sar1.h"
#include "Sar2.h"
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

using namespace std;
Boolean c1=true;    // флаг запрета добавления строк в LV_Sar1
Boolean c2=true;    // флаг запрета добавления строк в LV_Sar2
Boolean c3=true;    // флаг запрета добавления строк в LV_Sar3
Boolean c4=true;    // флаг запрета добавления строк в LV_Sar4
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* директива определяет последовательность инициализации пакетов такой, какая
устанавливается взаимными ссылками использующих их модулей */
#pragma resource "*.dfm"  // для формы надо использовать файл .dfm с тем же именем, что и имя данного файла
TMain_Form *Main_Form;  // объявление указателя на объект формы Main_Form
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
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LoadBlpClick(TObject *Sender) // нажатие на кнопку "Открыть файл .blp"
{
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

void __fastcall TMain_Form::LVScanDblClick(TObject *Sender)  // двойной щелчок по LVScan
{
  if (LVScan->Selected!= NULL) F_BT->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Update_Dump_blp() // открыть дамп blp
{
  std::ifstream infile(BlpFName.c_str());
  std::string x;
  TListItem * item=0;
  bool flag=false;
  while(!std::getline(infile,x).fail())
  {
    if(!x.size()) {item=0;flag=false;continue;}
    if(x.size()&&'"'==x[x.size()-1]) x.resize(x.size()-1);
    if(x.size()&&'"'==x[0]) x.erase(0,1);
    if(!item) item=LVScan->Items->Add();
    if(!flag){ item->Caption=x.c_str(); flag=true; }
    else item->SubItems->Add(x.c_str());
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Save_Dump_blp()  // сохранить дамп blp
{
  std::ofstream out(BlpFName.c_str(),std::ios_base::out|std::ios_base::trunc);
  for(size_t i=0;i<(size_t)LVScan->Items->Count;++i)
  {
    if(i) out<<std::endl;
    out<<"\""<<LVScan->Items->Item[i]->Caption.c_str()<<"\""<<std::endl;
    for(size_t j=0;j<(size_t)LVScan->Items->Item[i]->SubItems->Count;++j)
    out<<"\""<<LVScan->Items->Item[i]->SubItems->Strings[j].c_str()<<"\""<<std::endl;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SaveBlpClick(TObject *Sender) // нажатие на кнопку "Сохранить файл .blp"
{
  SaveDialog->InitialDir=My_Patch + "Данные_БТ";
  SaveDialog->FileName="*.blp";
  SaveDialog->Title=" Сохранение файла данных БТ";
  SaveDialog->Filter="данные БТ (*.blp)|*.blp";
  
  if (SaveDialog->Execute())         // если выбран диалог SaveDialog
/*
virtual __fastcall bool Execute(HWND ParentWnd);
Отображает диалог выбора файлов.
Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/  
  {
    BlpFName = SaveDialog->FileName; // имя выбранного файла сохраняется в переменной BlpFName
    Save_Dump_blp();                 // сохранить данные LVScan в файл
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar1DblClick(TObject *Sender)
{
  if (LV_Sar1->Selected!= NULL) F_Sar1->ShowModal();
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
  if(c1)
  {
    TListItem *Item = LV_Sar1->Items->Add();  // добавить новую строку LV_Sar1
    Item->Caption = 0;                        // заполнить колонки значениями 0
    Item->SubItems->Add(0);
    Item->SubItems->Add(0);
    Item->SubItems->Add(0);
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
    c1=true;
    B_AddSar1->Enabled=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar2Click(TObject *Sender) // нажатие на кнопку "Добвить данные Sar2"
{
  if(c2)
  {
    TListItem *Item = LV_Sar2->Items->Add();  // добавить новую строку LV_Sar2
    Item->Caption = 0;                        // заполнить колонки значениями 0
    Item->SubItems->Add(0);
    Item->SubItems->Add(970);
    Item->SubItems->Add(970);
    Item->SubItems->Add(1);
    Item->SubItems->Add(1);
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
    c2=true;
    B_AddSar2->Enabled=true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar2DblClick(TObject *Sender)
{
  if (LV_Sar2->Selected!= NULL) F_Sar2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LoadSarClick(TObject *Sender)
{
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
    Update_Dump_sar();                // загрузка файла SarFName в LV_Sar1 и LV_Sar2
    c1=false;                         // запретить добавление строк в LV_Sar1
    B_AddSar1->Enabled=false;         // отключить кнопку "Добвить данные Sar1"
    c2=false;                         // запретить добавление строк в LV_Sar2
    B_AddSar2->Enabled=false;         // отключить кнопку "Добвить данные Sar2"
  }
  if(!infile)                         // если не входной файловый поток
  {
    MessageBox(NULL,"Файл не удается открыть!","Ошибка!",MB_OK|MB_ICONERROR);
    return;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::SaveSarClick(TObject *Sender)
{
  SaveDialog1->InitialDir=My_Patch + "Данные_РЛС_и_модуля";
  SaveDialog1->FileName="*.sar";
  SaveDialog1->Title=" Сохранение файла данных РЛС и модуля";
  SaveDialog1->Filter="данные РЛС и модуля (*.sar)|*.sar";
  
  if (SaveDialog1->Execute())         // если выбран диалог SaveDialog1
/*
virtual __fastcall bool Execute(HWND ParentWnd);
Отображает диалог выбора файлов.
Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/  
  {
    SarFName = SaveDialog1->FileName; // имя выбранного файла сохраняется в переменной SarFName
    Save_Dump_sar();                  // сохранить данные LV_Sar1 и LV_Sar2 в файл
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Update_Dump_sar() // открыть дамп sar
{
  TListItem *pItem;
  std::ifstream ifile(SarFName.c_str());
  std::string line;
  while(std::getline(ifile,line))
  {
    if(line == "*")
      if(std::getline(ifile,line))
      {
        pItem = LV_Sar1->Items->Add();
        pItem->Caption =AnsiString(line.c_str());
      }
    if(line == "**")
      if(std::getline(ifile,line))
        pItem->SubItems->Add(line.c_str());

    if(line == "***")
      if(std::getline(ifile,line))
      {
        pItem = LV_Sar2->Items->Add();
        pItem->Caption =AnsiString(line.c_str());
      }
    if(line == "****")
      if (std::getline(ifile,line))
        pItem->SubItems->Add(line.c_str());
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Save_Dump_sar()  // сохранить дамп sar
{
  ofstream SaveFile;
  SaveFile.open(SarFName.c_str(), ios::out);
  for (int i=0; i<LV_Sar1->Items->Count; i++)
  {
    SaveFile<<"*"<<endl;
    SaveFile<<LV_Sar1->Items->Item[i]->Caption.c_str()<<endl;
    for (int j=0; j<LV_Sar1->Items->Item[i]->SubItems->Count; j++)
    {
      SaveFile<<"**"<<endl;
      SaveFile<<LV_Sar1->Items->Item[i]->SubItems->Strings[j].c_str()<<endl;
    }
    SaveFile<<endl;
  }

  for (int i=0; i<LV_Sar2->Items->Count; i++)
  {
    SaveFile<<"***"<<endl;
    SaveFile<<LV_Sar2->Items->Item[i]->Caption.c_str()<<endl;
    for (int j=0; j<LV_Sar2->Items->Item[i]->SubItems->Count; j++)
    {
      SaveFile<<"****"<<endl;
      SaveFile<<LV_Sar2->Items->Item[i]->SubItems->Strings[j].c_str()<<endl;
    }
    SaveFile<<endl;
  }
  SaveFile.close();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormCreate(TObject *Sender)
{
//эта структура будет содержать разрешение экрана на системе
struct res{float x,y;}res;
/*здесь будет хранится коэфицент, показывающий во сколько раз
текущее разрешение больше исходного*/
struct factor{float x,y;}factor;
//считать текущее разрешение
res.x=Screen->Width;
res.y=Screen->Height;
//вычислить коэфицент. Если программа пишется при другом разрешении,
//то нужно только подставить его вместо 1366 и 768
factor.x=1366/res.x;
factor.y=768/res.y;
int cc=ControlCount-1; //количество объектов на форме
while(cc!=-1) //для каждого объекта выполняем следующие операции
{
Controls[cc]->Left/=factor.x; //правильно располагаем по горизонтали
Controls[cc]->Top/=factor.y; //…по вертикали
Controls[cc]->Width/=factor.x; //растягиваем до нужной ширины
Controls[cc]->Height/=factor.y; //…высоты
cc--;
}
//теперь растягиваем саму форму
Main_Form->Width/=factor.x;
Main_Form->Height/=factor.y;
//изменяем размер шрифтов; не забудьте поставить свойство формы Scaled=true
Main_Form->PixelsPerInch=Screen->PixelsPerInch;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar3Click(TObject *Sender)
{
  if(c3)
  {
    TListItem *Item = LV_Sar3->Items->Add();  // добавить новую строку LV_Sar2
    Item->Caption = 0;                        // заполнить колонки значениями 0
    Item->SubItems->Add(0);
    Item->SubItems->Add(970);
    Item->SubItems->Add(970);
    Item->SubItems->Add(1);
    Item->SubItems->Add(1);
    c2=false;
    B_AddSar2->Enabled=false;
  }
}
//---------------------------------------------------------------------------

