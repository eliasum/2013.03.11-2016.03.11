// файл реализации формы Main_Form
//---------------------------------------------------------------------------
// директивы препроцессора #include подключают в данный файл тексты указанных в них файлов
#include <vcl.h>  // объявления, используемые в библиотеке визуальных компонентов С++Builder
#pragma hdrstop   // конец списка общих заголовочных файлов для всех модулей проекта

#include "BlazePoint_main.h"
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
  bool DirectoryExists(AnsiString DirectoryName);
  Функция DirectoryExists возвращает True, если данный DirectoryName файл существует.
  Каталог разыскивается в текущем каталоге. False может быть возвращена, если пользователю не
  разрешено видеть файл.

  bool CreateDir(AnsiString Dir);
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

  if(OpenDialog->Execute())
/*
virtual __fastcall bool Execute(HWND ParentWnd);
Отображает диалог выбора файлов.
Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/
  {
    BlpFName = OpenDialog->FileName; // имя выбранного файла сохраняется в переменной BlpFName
    LVScan->Items->Clear();          // очистка LVScan
    Update_Dump();                   // загрузка файла BlpFName в LVScan
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
  if (LVScan->Selected != NULL) // если выбранная строка LVScan не пустая
  {
    // запись введённых параметров из Edit'ов в выбранную строку LVScan
    LVScan->ItemFocused->Caption = E_BT->Text;
    LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[0] = E_X->Text;
    LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[1] = E_Y->Text;
    LVScan->Items->Item[LVScan->ItemIndex]->SubItems->Strings[2] = E_EPR->Text;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Update_Dump() // открыть дамп blp
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

void __fastcall TMain_Form::Save_Dump()  // сохранить дамп blp
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
  
  if (SaveDialog->Execute())
/*
virtual __fastcall bool Execute(HWND ParentWnd);
Отображает диалог выбора файлов.
Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/  
  {
    BlpFName = SaveDialog->FileName; // имя выбранного файла сохраняется в переменной BlpFName
    Save_Dump();                     // сохранить данные LVScan в файл
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddBTClick(TObject *Sender) // нажатие на кнопку "Добвить БТ"
{
  if((E_BT->Text!="")&&(E_X->Text!="")&&(E_Y->Text!="")&&(E_EPR->Text!="")) // если все Edit'ы не пусты
  {
    TListItem * Item = LVScan->Items->Add(); // добавить новую строку LVScan
    Item->Caption = E_BT->Text;              // заполнить колонки значениями из Edit'ов
    Item->SubItems->Add(E_X->Text);
    Item->SubItems->Add(E_Y->Text);
    Item->SubItems->Add(E_EPR->Text);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteBTClick(TObject *Sender) // нажатие на кнопку "Удалить БТ"
{
  if (LVScan->Selected != NULL)  // если выбранная строка LVScan не пуста
  {
    LVScan->Selected->Delete();   // удалить выбранную строку
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::ExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------


