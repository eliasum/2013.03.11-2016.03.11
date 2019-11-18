// файл реализации формы Main_Form
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
*/
  ifstream infile; // Входной файловый поток.
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  Отображает диалог выбора файлов.
  Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
  Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/
  if(OpenDialog->Execute())          // если выбран диалог OpenDialog
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
    if(!item) item=LVScan->Items->Add(); // если объект item отсутствует, то добавить объект item
    if(!flag){ item->Caption=x.c_str(); flag=true; }
/*
    Если отсутствует заполнение объекта item, то аполнить объект item из строки с-style.
    Поднять флаг заполнения объекта item.
*/
    else item->SubItems->Add(x.c_str()); // иначе добавить и заполнить объект SubItems
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Save_Dump_blp()  // сохранить дамп blp
{
/*
  std::ofstream - класс выходного потока для работы с файлами.
  std::ofstream out - выходной файловый поток (файл открывается для вывода (записи)).
  std::ios_base::out - способ открытия файла для вывода данных.
  std::ios_base::trunc - способ открытия файла приводит к разрушению содержимого
  файла, имя которого совпадает с возвращаемым параметром BlpFName.c_str(), а сам этот файл усекается
  до нулевой длины.
  Функция std::endl кроме переноса строки, производит сброс буферов потока вывода (записи) данных в файл;
*/
  std::ofstream out(BlpFName.c_str(),std::ios_base::out|std::ios_base::trunc);
  for(size_t i=0;i<(size_t)LVScan->Items->Count;++i) // перебор Items
  {
    if(i) out<<std::endl;  // если новый Item, добавить пустую строку разделитель
    out<<"\""<<LVScan->Items->Item[i]->Caption.c_str()<<"\""<<std::endl;  // вывести значение Item в кавычках
    for(size_t j=0;j<(size_t)LVScan->Items->Item[i]->SubItems->Count;++j) // перебор SubItems
    out<<"\""<<LVScan->Items->Item[i]->SubItems->Strings[j].c_str()<<"\""<<std::endl; // вывести значение SubItem в кавычках
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
  if (LV_Sar1->Selected!= NULL) F_Sar1->ShowModal(); // если выбранная строка LV_Sar1 не пуста, открыть форму
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
    c1=true;                      // разрешение добавления строк в LV_Sar1
    B_AddSar1->Enabled=true;      // включение кнопки "Добвить данные Sar1"
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

void __fastcall TMain_Form::LV_Sar2DblClick(TObject *Sender)
{
  if (LV_Sar2->Selected!= NULL) F_Sar2->ShowModal(); // если выбранная строка LV_Sar2 не пуста, открыть форму
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
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::Save_Dump_sar()  // сохранить дамп sar
{
/*
  std::ofstream - класс выходного потока для работы с файлами.
  std::ofstream SaveFile - выходной файловый поток (файл открывается для вывода (записи)).
  std::ios_base::out - способ открытия файла для вывода данных.
  Функция std::endl кроме переноса строки, производит сброс буферов потока вывода (записи) данных в файл;
*/
  ofstream SaveFile;
  SaveFile.open(SarFName.c_str(), ios::out);
  
  for (int i=0; i<LV_Sar1->Items->Count; i++) // перебор Items
  {
    SaveFile<<"*"<<endl;                      // записать символ в файл, закончить строку
    SaveFile<<LV_Sar1->Items->Item[i]->Caption.c_str()<<endl; // записать значение i-го Item, закончить строку
    for (int j=0; j<LV_Sar1->Items->Item[i]->SubItems->Count; j++) // перебор SubItems
    {
      SaveFile<<"**"<<endl;                   // записать символ в файл, закончить строку
      SaveFile<<LV_Sar1->Items->Item[i]->SubItems->Strings[j].c_str()<<endl; // записать значение j-го SubItem, закончить строку
    }
    SaveFile<<endl;                           // записать пустую строку в файл
  }

  for (int i=0; i<LV_Sar2->Items->Count; i++) // перебор Items
  {
    SaveFile<<"***"<<endl;                    // записать символ в файл, закончить строку
    SaveFile<<LV_Sar2->Items->Item[i]->Caption.c_str()<<endl; // записать значение i-го Item, закончить строку
    for (int j=0; j<LV_Sar2->Items->Item[i]->SubItems->Count; j++) // перебор SubItems
    {
      SaveFile<<"****"<<endl;                 // записать символ в файл, закончить строку
      SaveFile<<LV_Sar2->Items->Item[i]->SubItems->Strings[j].c_str()<<endl; // записать значение j-го SubItem, закончить строку
    }
    SaveFile<<endl;                           // записать пустую строку в файл
  }

  for (int i=0; i<LV_Sar3->Items->Count; i++) // перебор Items
  {
    SaveFile<<"*****"<<endl;                  // записать символ в файл, закончить строку
    SaveFile<<LV_Sar3->Items->Item[i]->Caption.c_str()<<endl; // записать значение i-го Item, закончить строку
    for (int j=0; j<LV_Sar3->Items->Item[i]->SubItems->Count; j++) // перебор SubItems
    {
      SaveFile<<"******"<<endl;               // записать символ в файл, закончить строку
      SaveFile<<LV_Sar3->Items->Item[i]->SubItems->Strings[j].c_str()<<endl; // записать значение j-го SubItem, закончить строку
    }
    SaveFile<<endl;                           // записать пустую строку в файл
  }

  for (int i=0; i<LV_Sar4->Items->Count; i++) // перебор Items
  {
    SaveFile<<"*******"<<endl;                // записать символ в файл, закончить строку
    SaveFile<<LV_Sar4->Items->Item[i]->Caption.c_str()<<endl; // записать значение i-го Item, закончить строку
    for (int j=0; j<LV_Sar4->Items->Item[i]->SubItems->Count; j++) // перебор SubItems
    {
      SaveFile<<"********"<<endl;             // записать символ в файл, закончить строку
      SaveFile<<LV_Sar4->Items->Item[i]->SubItems->Strings[j].c_str()<<endl; // записать значение j-го SubItem, закончить строку
    }
    SaveFile<<endl;                           // записать пустую строку в файл
  }
  
  SaveFile.close();                           // закрыть записанный файл
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

void __fastcall TMain_Form::HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();  
}
//---------------------------------------------------------------------------


