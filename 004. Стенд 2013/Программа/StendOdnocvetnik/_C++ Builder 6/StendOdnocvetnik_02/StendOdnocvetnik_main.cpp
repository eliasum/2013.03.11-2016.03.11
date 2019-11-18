//---------------------------------------------------------------------------
// директивы препроцессора #include подключают в данный файл тексты указанных в них файлов
#include <vcl.h>  // объявления, используемые в библиотеке визуальных компонентов С++Builder
#pragma hdrstop   // конец списка общих заголовочных файлов для всех модулей проекта

#include "StendOdnocvetnik_main.h"
#include "AboutBox.h"
#include "NIDAQmx.h"
#include <fstream>    // Файловые операции ввода-вывода
#include <dstring.h>
using namespace std;
/*
  Устройство 1:
  P0.0, P0.1, P0.2 = 1 - тумблер вкл, = 0 - выкл.;
  P0.3, P0.4, P0.5 = 1 - источник питания блока ИПИ вкл, = 0 - выкл.;
  P0.6 = 1 - вкл, = 0 - выкл.;
  P0.0 - чтение тумблера -6В;
  P0.1 - чтение тумблера +6В;
  P0.2 - чтение тумблера +20В;
  P0.3 - запись источника питания блока ИПИ -6В;
  P0.4 - запись источника питания блока ИПИ +6В;
  P0.5 - запись источника питания блока ИПИ +20В;
  P0.6 - запись сигнала включения эквивалента тепловой нагрузки;
  P1.0 - чтение сигнала о перегреве устройства 1, = 0 - перегрев;

  AI0 - чтение отрицательного тока нагрузки источника питания -6В канала №1
  AI1 - чтение отрицательного напряжения питания источника питания -6В канала №1
  AI2 - чтение положительного тока нагрузки источника питания +6В канала №1
  AI3 - чтение положительного напряжения питания источника питания +6В канала №1
  AI4 - чтение положительного тока нагрузки источника питания +20В канала №1
  AI5 - чтение положительного напряжения питания источника питания +20В канала №1

  Устройство 2:
  P1.0 - чтение сигнала о перегреве устройства 2, = 0 - перегрев;

  AI0 - чтение отрицательного тока нагрузки источника питания -6В канала №2
  AI1 - чтение отрицательного напряжения питания источника питания -6В канала №2
  AI2 - чтение положительного тока нагрузки источника питания +6В канала №2
  AI3 - чтение положительного напряжения питания источника питания +6В канала №2
  AI4 - чтение положительного тока нагрузки источника питания +20В канала №2
  AI5 - чтение положительного напряжения питания источника питания +20В канала №2

  Устройство 3:
  P1.0 - чтение сигнала о перегреве устройства 3, = 0 - перегрев;

  AI0 - чтение отрицательного тока нагрузки источника питания -6В канала №3
  AI1 - чтение отрицательного напряжения питания источника питания -6В канала №3
  AI2 - чтение положительного тока нагрузки источника питания +6В канала №3
  AI3 - чтение положительного напряжения питания источника питания +6В канала №3
  AI4 - чтение положительного тока нагрузки источника питания +20В канала №3
  AI5 - чтение положительного напряжения питания источника питания +20В канала №3

  Устройство 4:
  P1.0 - чтение сигнала о перегреве устройства 4, = 0 - перегрев;

  AI0 - чтение отрицательного тока нагрузки источника питания -6В канала №4
  AI1 - чтение отрицательного напряжения питания источника питания -6В канала №4
  AI2 - чтение положительного тока нагрузки источника питания +6В канала №4
  AI3 - чтение положительного напряжения питания источника питания +6В канала №4
  AI4 - чтение положительного тока нагрузки источника питания +20В канала №4
  AI5 - чтение положительного напряжения питания источника питания +20В канала №4
*/
unsigned char P0[8],P1[4]; // буфер обмена для цифровых портов
const int NumReadValue=10;

bool ErrorADC;
bool greenflag1, greenflag2, greenflag3, greenflag4;

const char *Dev1_port0_line0_2 = "Dev1/port0/line0:2";
const char *Dev1_port0_line3_5 = "Dev1/port0/line3:5";
const char *Dev1_port0_line3 = "Dev1/port0/line3";
const char *Dev1_port0_line4 = "Dev1/port0/line4";
const char *Dev1_port0_line5 = "Dev1/port0/line5";
const char *Dev1_port0_line6 = "Dev1/port0/line6";

const char *Dev1_port1_line0_3 = "Dev1/port1/line0:3";

const char *Dev1_ai0= "Dev1/ai0";
const char *Dev1_ai1= "Dev1/ai1";
const char *Dev1_ai2= "Dev1/ai2";
const char *Dev1_ai3= "Dev1/ai3";
const char *Dev1_ai4= "Dev1/ai4";
const char *Dev1_ai5= "Dev1/ai5";

const char *Dev2_port1_line0 = "Dev2/port1/line0";

const char *Dev2_ai0= "Dev2/ai0";
const char *Dev2_ai1= "Dev2/ai1";
const char *Dev2_ai2= "Dev2/ai2";
const char *Dev2_ai3= "Dev2/ai3";
const char *Dev2_ai4= "Dev2/ai4";
const char *Dev2_ai5= "Dev2/ai5";

const char *Dev3_port1_line0 = "Dev3/port1/line0";

const char *Dev3_ai0= "Dev3/ai0";
const char *Dev3_ai1= "Dev3/ai1";
const char *Dev3_ai2= "Dev3/ai2";
const char *Dev3_ai3= "Dev3/ai3";
const char *Dev3_ai4= "Dev3/ai4";
const char *Dev3_ai5= "Dev3/ai5";

const char *Dev4_port1_line0 = "Dev4/port1/line0";

const char *Dev4_ai0= "Dev4/ai0";
const char *Dev4_ai1= "Dev4/ai1";
const char *Dev4_ai2= "Dev4/ai2";
const char *Dev4_ai3= "Dev4/ai3";
const char *Dev4_ai4= "Dev4/ai4";
const char *Dev4_ai5= "Dev4/ai5";

const char *DangerI_IPO1 = "Недопустимое отклонение тока ИПО1 от номинального значения!";
const char *DangerI_IPO2 = "Недопустимое отклонение тока ИПО2 от номинального значения!";
const char *DangerI_IPO3 = "Недопустимое отклонение тока ИПО3 от номинального значения!";
const char *DangerI_IPO4 = "Недопустимое отклонение тока ИПО4 от номинального значения!";

const char *DangerU_IPO1 = "Недопустимое отклонение напряжения ИПО1 от номинального значения!";
const char *DangerU_IPO2 = "Недопустимое отклонение напряжения ИПО2 от номинального значения!";
const char *DangerU_IPO3 = "Недопустимое отклонение напряжения ИПО3 от номинального значения!";
const char *DangerU_IPO4 = "Недопустимое отклонение напряжения ИПО4 от номинального значения!";

const char *DangerI_IPP1 = "Недопустимое отклонение тока ИПП1 от номинального значения!";
const char *DangerI_IPP2 = "Недопустимое отклонение тока ИПП2 от номинального значения!";
const char *DangerI_IPP3 = "Недопустимое отклонение тока ИПП3 от номинального значения!";
const char *DangerI_IPP4 = "Недопустимое отклонение тока ИПП4 от номинального значения!";

const char *DangerU_IPP1 = "Недопустимое отклонение напряжения ИПП1 от номинального значения!";
const char *DangerU_IPP2 = "Недопустимое отклонение напряжения ИПП2 от номинального значения!";
const char *DangerU_IPP3 = "Недопустимое отклонение напряжения ИПП3 от номинального значения!";
const char *DangerU_IPP4 = "Недопустимое отклонение напряжения ИПП4 от номинального значения!";

const char *DangerI_IMP1 = "Недопустимое отклонение тока ИМП1 от номинального значения!";
const char *DangerI_IMP2 = "Недопустимое отклонение тока ИМП2 от номинального значения!";
const char *DangerI_IMP3 = "Недопустимое отклонение тока ИМП3 от номинального значения!";
const char *DangerI_IMP4 = "Недопустимое отклонение тока ИМП4 от номинального значения!";

const char *DangerU_IMP1 = "Недопустимое отклонение напряжения ИМП1 от номинального значения!";
const char *DangerU_IMP2 = "Недопустимое отклонение напряжения ИМП2 от номинального значения!";
const char *DangerU_IMP3 = "Недопустимое отклонение напряжения ИМП3 от номинального значения!";
const char *DangerU_IMP4 = "Недопустимое отклонение напряжения ИМП4 от номинального значения!";

const char *OverheatMessage = "Перегрев устройства! Перезапустить программу!";

const char *UnloadedChannel1 = "Файл испытаний стенда Одноцветников в канал 1 не загружен!";
const char *UnloadedChannel2 = "Файл испытаний стенда Одноцветников в канал 2 не загружен!";
const char *UnloadedChannel3 = "Файл испытаний стенда Одноцветников в канал 3 не загружен!";
const char *UnloadedChannel4 = "Файл испытаний стенда Одноцветников в канал 4 не загружен!";

const char *LoadedChannel1 = "Файл испытаний стенда Одноцветников в канал 1 загружен!";
const char *LoadedChannel2 = "Файл испытаний стенда Одноцветников в канал 2 загружен!";
const char *LoadedChannel3 = "Файл испытаний стенда Одноцветников в канал 3 загружен!";
const char *LoadedChannel4 = "Файл испытаний стенда Одноцветников в канал 4 загружен!";

String FileStend="";
AnsiString Nominal1[8]; // номинальные значения токов и
AnsiString Nominal2[8]; // напряжений источников питания блоков ИПИ,
AnsiString Nominal3[8]; // а так же время паузы и работы каналов
AnsiString Nominal4[8];

double FNominal1[8];    // номинальные значения токов и
double FNominal2[8];    // напряжений источников питания блоков ИПИ,
double FNominal3[8];    // а так же время паузы и работы каналов
double FNominal4[8];

double Umin=0.7, Umax=1.3, Imin=0.95, Imax=1.05; // отклонения U и I от номинального значения

float value;
int k1=1, k2=2;         // коэффициенты, учитывающие делитель на 2

// переменные управления таймерами 
int Checkm6VCounter=-1;
int Checkp6VCounter=-1;
int Checkp20VCounter=-1;

long int Tpause=0, Twork=0;
int ::count=0;
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* директива определяет последовательность инициализации пакетов такой, какая
устанавливается взаимными ссылками использующих их модулей */
#pragma resource "*.dfm"  // для формы надо использовать файл .dfm с тем же именем, что и имя данного файла
TMainForm *MainForm;      // объявление указателя на объект формы MainForm класса TMainForm 
TIniFile *Ini;
void __fastcall (TMainForm::*Method)(void); // указатель на метод класса TMainForm  
//---------------------------------------------------------------------------
// вызов конструктора формы Main_Form
__fastcall TMainForm::TMainForm(TComponent* Owner)
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
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddSaveLog(AnsiString comment) // добавить комментарий и сохранить лог
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
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
/*
  FormatDateTime (s, dt) - Строка символов, представляющая собой дату или время. Способ представления
  задает строка формата s, например, строка dd/mm/yyyy задает, что значением функции является дата,
  а строка hh:mm – время
*/
  AnsiString DateTime = FormatDateTime("YYYY.MM.DD",Date())+"_"+FormatDateTime("HH-NN-SS",Time()); // текущая дата и время
  logFname = DateTime;              // запись имени лог файла в буфер при открытии программы
  AddSaveLog("Программа запущена"); // добавить комментарий и сохранить лог

  // инициализация данных при создании формы:
  PowerOff();                       // выключить все источники питания блоков ИПИ

  for(int i=0; i<8; i++)
  {
    Nominal1[i]="0";
    Nominal2[i]="0";
    Nominal3[i]="0";
    Nominal4[i]="0";
  }

  for(int i=0; i<8; i++)
  {
    FNominal1[i]=0.0;
    FNominal2[i]=0.0;
    FNominal3[i]=0.0;
    FNominal4[i]=0.0;
  }

  greenflag1=greenflag2=greenflag3=greenflag4=false;

  L_Danger->Caption="";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  AddSaveLog("Программа закрыта"); // добавить комментарий и сохранить лог  
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Starting(void)
// Предпусковые операции
{
  // алгоритм проверки состояния тумблеров -6В ,+6В, +20В
  ReadDigChan(Dev1_port0_line0_2, P0);  // чтение в буфер обмена цифрового порта P0 устройства 1
/*
  for(int i=0; i<8; i++)
  {
    Memo1->Lines->Add(P0[i]);
  }
*/
  PowerOff();                 // выключить все источники питания блоков ИПИ

  if(!P0[0]||!P0[1]||!P0[2])  // проверка включения тумблеров -6В ,+6В, +20В
  {
    Application->MessageBox("Тумблеры -6В, +6В, +20В в положении ВЫКЛ. Перевести тумблеры в положение ВКЛ.","Внимание",MB_ICONWARNING);
    B_Go->Enabled=true;
    B_Stop->Enabled=false;
  }
  else
  {
    B_Go->Enabled=false;
    B_Stop->Enabled=true;
  }         
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
  Memo1->Clear();
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::ReadDigChan(const char *Config, char *DigPort)
// чтение в буфер обмена цифрового порта Px устройства y
{
	TaskHandle	taskHandle=0;
	char		errBuff[2048]={'\0'};

  // Создаем задачу
	if(DAQmxCreateTask("",&taskHandle))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // Определяем параметры задачи
	if(DAQmxCreateDIChan(taskHandle,Config,"",DAQmx_Val_ChanForAllLines))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // Запускаем задачу
	if(DAQmxStartTask(taskHandle))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

	// Записываем данные
	if(DAQmxReadDigitalLines(taskHandle,1,10.0,DAQmx_Val_GroupByChannel,DigPort,100,NULL,NULL,NULL))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
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
  
  return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_GoClick(TObject *Sender)
{
  T_Work->Enabled=true;
  T_Pause->Enabled=true;
  Starting();
  Work();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_StopClick(TObject *Sender)
{
  PowerOffWithDelay(); // выключить все источники питания блоков ИПИ с задержками
  T_Work->Enabled=false;
  T_Pause->Enabled=false;
  B_Go->Enabled=true;
  B_Stop->Enabled=false;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::WriteDigChan(const char *Config, char *DigPort)
// запись из буфера обмена цифрового порта P0 устройства 1
{
	TaskHandle  taskHandle=0;
	char        errBuff[2048]={'\0'};

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // Определяем параметры задачи
  if (DAQmxFailed((DAQmxCreateDOChan(taskHandle,"Dev1/port0/line0:7","",DAQmx_Val_ChanForAllLines))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // Запускаем задачу
  if (DAQmxFailed((DAQmxStartTask(taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // Записываем данные
  if (DAQmxFailed((DAQmxWriteDigitalLines(taskHandle,1,1,1.0,DAQmx_Val_GroupByChannel,P0,NULL,NULL))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
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

  return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RB_Selected1Click(TObject *Sender)
{
  if(RB_Selected1->Checked==true)
  {
    RB_Selected2->Checked=false;
    RB_Selected3->Checked=false;
    RB_Selected4->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RB_Selected2Click(TObject *Sender)
{
  if(RB_Selected2->Checked==true)
  {
    RB_Selected1->Checked=false;
    RB_Selected3->Checked=false;
    RB_Selected4->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RB_Selected3Click(TObject *Sender)
{
  if(RB_Selected3->Checked==true)
  {
    RB_Selected1->Checked=false;
    RB_Selected2->Checked=false;
    RB_Selected4->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RB_Selected4Click(TObject *Sender)
{
  if(RB_Selected4->Checked==true)
  {
    RB_Selected1->Checked=false;
    RB_Selected2->Checked=false;
    RB_Selected3->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadStendClick(TObject *Sender)
{
  OpenDialog1->DefaultExt=".stend";
  OpenDialog1->FileName="*.stend";
  OpenDialog1->Filter="Файл испытаний (*.stend)|*.stend";
  OpenDialog1->Title=" Загрузка файла испытаний";

  String File;

  if(OpenDialog1->Execute())
  {
    File=OpenDialog1->FileName;
    FileStend=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("Название секции","Имя переменной", "значение");
*/
      if(RB_Selected1->Checked==true)
      {
        LoadChannel(Nominal1, greenflag1, P_Selected1, UnloadedChannel1, FNominal1, LoadedChannel1);

        Tpause = (long int)FNominal1[6]*1000; // [с]
        Twork = (long int)FNominal1[7]*1000;  // [с]
/*
        Memo1->Lines->Add(Tpause);
        Memo1->Lines->Add(Twork);

        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(FNominal1[i]);
        }
*/
      }
      if(RB_Selected2->Checked==true)
      {
        LoadChannel(Nominal2, greenflag2, P_Selected2, UnloadedChannel2, FNominal2, LoadedChannel2);
/*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(FNominal2[i]);
        }
*/
      }
      if(RB_Selected3->Checked==true)
      {
        LoadChannel(Nominal3, greenflag3, P_Selected3, UnloadedChannel3, FNominal3, LoadedChannel3);
/*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(FNominal3[i]);
        }
*/
      }
      if(RB_Selected4->Checked==true)
      {
        LoadChannel(Nominal4, greenflag4, P_Selected4, UnloadedChannel4, FNominal4, LoadedChannel4);
/*
        for(int i=0; i<8; i++)
        {
          Memo1->Lines->Add(FNominal4[i]);
        }
*/
      }
      
      B_Go->Enabled=true;
      //if(greenflag1&greenflag2) B_Go->Enabled=true;  // greenflag1&greenflag2&greenflag3&greenflag4

      delete Ini;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Verification(void)
// проверка номинальных значений параметров источников питания блоков ИПИ
{
  B_Go->Enabled=false;
  B_Stop->Enabled=true;

  // включить отрицательные источники питания -6В всех устройств
  P0[3]=1;                               // источник -6В
  WriteDigChan(Dev1_port0_line3, P0);    // запись в цифровой порт P0 устройства 1
  Delay();                               // задержка 1 сек
  Checkm6V();                            // проверка отрицательных источников питания блоков ИПИ -6В

  // включить положительные источники питания +6В всех устройств
  P0[4]=1;                               // источник +6В
  WriteDigChan(Dev1_port0_line4, P0);    // запись в цифровой порт P0 устройства 1
  Delay();                               // задержка 1 сек
  Checkp6V();                            // проверка положительных источников питания блоков ИПИ +6В

  // включить положительные источники питания +20В всех устройств
  P0[5]=1;                               // источник +20В
  WriteDigChan(Dev1_port0_line5, P0);    // запись в цифровой порт P0 устройства 1
  Delay();                               // задержка 1 сек
  Checkp20V();                           // проверка положительных источников питания блоков ИПИ +20В
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();      
}
//---------------------------------------------------------------------------
float __fastcall TMainForm::ReadAnalogChan(const char *Config)
// чтение аналогового канала x порта AIx устройства y
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
  if (DAQmxFailed(DAQmxCreateAIVoltageChan(taskHandle,Config,"",DAQmx_Val_RSE,-10.0,10.0,DAQmx_Val_Volts,NULL)))
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
void __fastcall TMainForm::Checkm6V(void)
// проверка отрицательных источников питания блоков ИПИ -6В
{
  T_Checkm6V->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Checkp6V(void)
// проверка положительных источников питания блоков ИПИ +6В
{
  T_Checkp6V->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Checkp20V(void)
// проверка положительных источников питания блоков ИПИ +20В
{
  T_Checkp20V->Enabled=true;
}
//---------------------------------------------------------------------------
String TMainForm::RoundValue(float delta, String value)
{
  float temp;
  float temp1;

  temp=StrToFloat(value);
  temp1=Log10(delta);         // количество знаков после запятой
  value=RoundTo(temp,temp1);  // округлить до значения с 2-мя десятичными знаками после запятой

  return value;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PowerOff(void)
// выключить все источники питания блоков ИПИ
{
  P0[3]=0;                               // источник -6В
  P0[4]=0;                               // источник +6В
  P0[5]=0;                               // источник +20В
  WriteDigChan(Dev1_port0_line3_5, P0);  // запись в цифровой порт P0 устройства 1
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PowerOffWithDelay(void)
// выключить все источники питания блоков ИПИ с задержками
{
  P_Mode1->Color=clBtnFace;
  P_Mode2->Color=clBtnFace;
  //P_Mode3->Color=clBtnFace;
  //P_Mode3->Color=clBtnFace;

  // выключить источники питания +20В блоков ИПИ
  T_Checkp20V->Enabled=false;
  Powerp20VOff(); // выключить источники питания +20В блоков ИПИ

  LE_I_IMP1->Text="0";
  LE_I_IMP2->Text="0";
  LE_I_IMP3->Text="0";
  LE_I_IMP4->Text="0";

  LE_U_IMP1->Text="0";
  LE_U_IMP2->Text="0";
  LE_U_IMP3->Text="0";
  LE_U_IMP4->Text="0";

  Delay();        // задержка 1 сек

  // выключить источники питания +6В блоков ИПИ
  T_Checkp6V->Enabled=false;
  Powerp6VOff();  // выключить источники питания +6В блоков ИПИ

  LE_I_IPP1->Text="0";
  LE_I_IPP2->Text="0";
  LE_I_IPP3->Text="0";
  LE_I_IPP4->Text="0";

  LE_U_IPP1->Text="0";
  LE_U_IPP2->Text="0";
  LE_U_IPP3->Text="0";
  LE_U_IPP4->Text="0";

  Delay();        // задержка 1 сек

  // выключить источники питания -6В блоков ИПИ
  T_Checkm6V->Enabled=false;
  Powerm6VOff();  // выключить источники питания -6В блоков ИПИ

  LE_I_IPO1->Text="0";
  LE_I_IPO2->Text="0";
  LE_I_IPO3->Text="0";
  LE_I_IPO4->Text="0";

  LE_U_IPO1->Text="0";
  LE_U_IPO2->Text="0";
  LE_U_IPO3->Text="0";
  LE_U_IPO4->Text="0";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Powerm6VOff(void)
// выключить источники питания -6В блоков ИПИ
{
  P0[3]=0;                             // источник -6В
  WriteDigChan(Dev1_port0_line3, P0);  // запись в цифровой порт P0 устройства 1
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Powerp6VOff(void)
// выключить источники питания +6В блоков ИПИ
{
  P0[4]=0;                             // источник +6В
  WriteDigChan(Dev1_port0_line4, P0);  // запись в цифровой порт P0 устройства 1
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Powerp20VOff(void)
// выключить источники питания +20В блоков ИПИ
{
  P0[5]=0;                             // источник +20В
  WriteDigChan(Dev1_port0_line5, P0);  // запись в цифровой порт P0 устройства 1
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NominalNumber(AnsiString *Nominal)
// номер канала, для которого считываются номинальные значения
{
  Nominal[0]=Ini->ReadString("Стенд","Iном-6В","1");
  Nominal[1]=Ini->ReadString("Стенд","Uном-6В","1");
  Nominal[2]=Ini->ReadString("Стенд","Iном+6В","1");
  Nominal[3]=Ini->ReadString("Стенд","Uном+6В","1");
  Nominal[4]=Ini->ReadString("Стенд","Iном+20В","1");
  Nominal[5]=Ini->ReadString("Стенд","Uном+20В","1");
  Nominal[6]=Ini->ReadString("Стенд","Tпаузы","1");
  Nominal[7]=Ini->ReadString("Стенд","Tработы","1");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CheckOfChannel(const char *Config, TLabeledEdit *Parameter,
                double minAllow, double maxAllow, double Nom, const char *Message,
                TPanel *Protection, void __fastcall (TMainForm::*pm)(void), int koef)
// проверка аналогового канала
{
  double min, max;
  
  value = ReadAnalogChan(Config)*koef;                 // чтение аналогового канала x порта AI устройства y
  Parameter->Text=RoundValue(0.01, FloatToStr(value)); // 2 десятичных знака после запятой

  min=Nom*minAllow;
  max=Nom*maxAllow;

  //Memo1->Lines->Add(Nom);
  //Memo1->Lines->Add(min);
  //Memo1->Lines->Add(maxAllow);

  if((value>max)||(value<min)||(ErrorADC))  // проверка диапазона номинальных значений параметра
  {                                             
    T_Checkm6V->Enabled=false;
    T_Checkp6V->Enabled=false;
    T_Checkp20V->Enabled=false;
    L_Danger->Caption=Message;
    // выключить источники питания:
    (MainForm->*pm)();   // слева — обычный указатель на динамический объект, а справа — указатель на метод этого объекта
    PowerOffWithDelay(); // выключить все источники питания блоков ИПИ с задержками
    Protection->Color=clRed;
    B_Go->Enabled=true;
    B_Stop->Enabled=false;    
  }
  else
  {
    L_Danger->Caption="";
    B_Go->Enabled=false;
    B_Stop->Enabled=true;
    T_Checkm6V->Enabled=true;
    T_Checkp6V->Enabled=true;
    T_Checkp20V->Enabled=true;
    Protection->Color=clBtnFace;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Checkm6VTimer(TObject *Sender)
{
  Checkm6VCounter++;
  Method = &TMainForm::Powerm6VOff; // присвоить указателю на метод класса TMainForm адрес метода Powerm6VOff

  switch(Checkm6VCounter)
  {
    case 0:
      // Ток ИПО1:
      CheckOfChannel(Dev1_ai0, LE_I_IPO1, Imin, Imax, FNominal1[0], DangerI_IPO1, P_Protection1, Method, k2);
      break;

    case 1:
      // Ток ИПО2:
      CheckOfChannel(Dev2_ai0, LE_I_IPO2, Imin, Imax, FNominal2[0], DangerI_IPO2, P_Protection2, Method, k2);
      break;
/*
    case 2:
      // Ток ИПО3:
      CheckOfChannel(Dev3_ai0, LE_I_IPO3, Imin, Imax, FNominal3[0], DangerI_IPO3, P_Protection3, Method, k2);
      break;

    case 3:
      // Ток ИПО4:
      CheckOfChannel(Dev4_ai0, LE_I_IPO4, Imin, Imax, FNominal4[0], DangerI_IPO4, P_Protection4, Method, k2);
      break;
*/
    case 4:
      // Напряжение ИПО1:
      CheckOfChannel(Dev1_ai1, LE_U_IPO1, Umin, Umax, FNominal1[1], DangerU_IPO1, P_Protection1, Method, k1);
      break;

    case 5:
      // Напряжение ИПО2:
      CheckOfChannel(Dev2_ai1, LE_U_IPO2, Umin, Umax, FNominal2[1], DangerU_IPO2, P_Protection2, Method, k1);
      Checkm6VCounter=-1;  // начать отсчёт заново
      break;
/*
    case 6:
      // Напряжение ИПО3:
      CheckOfChannel(Dev3_ai1, LE_U_IPO3, Umin, Umax, FNominal3[1], DangerU_IPO3, P_Protection3, Method, k1);
      break;

    case 7:
      // Напряжение ИПО4:
      CheckOfChannel(Dev4_ai1, LE_U_IPO4, Umin, Umax, FNominal4[1], DangerU_IPO4, P_Protection4, Method, k1);
      break;
*/      
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Checkp6VTimer(TObject *Sender)
{
  Checkp6VCounter++;
  Method = &TMainForm::Powerp6VOff; // присвоить указателю на метод класса TMainForm адрес метода Powerp6VOff

  switch(Checkp6VCounter)
  {
    case 0:
      // Ток ИПП1:
      CheckOfChannel(Dev1_ai2, LE_I_IPP1, Imin, Imax, FNominal1[2], DangerI_IPP1, P_Protection1, Method, k2);
      break;

    case 1:
      // Ток ИПП2:
      CheckOfChannel(Dev2_ai2, LE_I_IPP2, Imin, Imax, FNominal2[2], DangerI_IPP2, P_Protection2, Method, k2);
      break;
/*
    case 2:
      // Ток ИПП3:
      CheckOfChannel(Dev3_ai2, LE_I_IPP3, Imin, Imax, FNominal3[2], DangerI_IPP3, P_Protection3, Method, k2);
      break;

    case 3:
      // Ток ИПП4:
      CheckOfChannel(Dev4_ai2, LE_I_IPP4, Imin, Imax, FNominal4[2], DangerI_IPP4, P_Protection4, Method, k2);
      break;
*/
    case 4:
      // Напряжение ИПП1:
      CheckOfChannel(Dev1_ai3, LE_U_IPP1, Umin, Umax, FNominal1[3], DangerU_IPP1, P_Protection1, Method, k1);
      break;

    case 5:
      // Напряжение ИПП2:
      CheckOfChannel(Dev2_ai3, LE_U_IPP2, Umin, Umax, FNominal2[3], DangerU_IPP2, P_Protection2, Method, k1);
      Checkp6VCounter=-1;  // начать отсчёт заново
      break;
/*
    case 6:
      // Напряжение ИПП3:
      CheckOfChannel(Dev3_ai3, LE_U_IPP3, Umin, Umax, FNominal3[3], DangerU_IPP3, P_Protection3, Method, k1);
      break;

    case 7:
      // Напряжение ИПП4:
      CheckOfChannel(Dev4_ai3, LE_U_IPP4, Umin, Umax, FNominal4[3], DangerU_IPP4, P_Protection4, Method, k1);
      break;
*/      
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Checkp20VTimer(TObject *Sender)
{
  Checkp20VCounter++;
  Method = &TMainForm::Powerp20VOff; // присвоить указателю на метод класса TMainForm адрес метода Powerp20VOff

  switch(Checkp20VCounter)
  {
    case 0:
      // Ток ИМП1:
      CheckOfChannel(Dev1_ai4, LE_I_IMP1, Imin, Imax, FNominal1[4], DangerI_IMP1, P_Protection1, Method, k2);
      break;

    case 1:
      // Ток ИМП2:
      CheckOfChannel(Dev2_ai4, LE_I_IMP2, Imin, Imax, FNominal2[4], DangerI_IMP2, P_Protection2, Method, k2);
      break;
/*
    case 2:
      // Ток ИМП3:
      CheckOfChannel(Dev3_ai4, LE_I_IMP3, Imin, Imax, FNominal3[4], DangerI_IMP3, P_Protection3, Method, k2);
      break;

    case 3:
      // Ток ИМП4:
      CheckOfChannel(Dev4_ai4, LE_I_IMP4, Imin, Imax, FNominal4[4], DangerI_IMP4, P_Protection4, Method, k2);
      break;
*/
    case 4:
      // Напряжение ИМП1:
      CheckOfChannel(Dev1_ai5, LE_U_IMP1, Umin, Umax, FNominal1[5], DangerU_IMP1, P_Protection1, Method, k2);
      break;

    case 5:
      // Напряжение ИМП2:
      CheckOfChannel(Dev2_ai5, LE_U_IMP2, Umin, Umax, FNominal2[5], DangerU_IMP2, P_Protection2, Method, k2);
      Checkp20VCounter=-1;  // начать отсчёт заново
      break;
/*
    case 6:
      // Напряжение ИМП3:
      CheckOfChannel(Dev3_ai5, LE_U_IMP3, Umin, Umax, FNominal3[5], DangerU_IMP3, P_Protection3, Method, k2);
      break;

    case 7:
      // Напряжение ИМП4:
      CheckOfChannel(Dev4_ai5, LE_U_IMP4, Umin, Umax, FNominal4[5], DangerU_IMP4, P_Protection4, Method, k2);
      break;
*/      
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Work(void)
// цикл Работа
{
  Verification();          // проверка номинальных значений параметров источников питания блоков ИПИ

  T_Work->Interval=Twork;  // запуск цикла Работа на время Twork [c]
  T_Log->Enabled=true;     // запуск вывода в log файл каждые 10 сек

  // сигнал выключения эквивалента тепловой нагрузки
  P0[6]=0;
  WriteDigChan(Dev1_port0_line6, P0); // запись в цифровой порт P0 устройства 1

  P_Mode1->Color=clGreen;
  P_Mode2->Color=clGreen;
  //P_Mode3->Color=clGreen;
  //P_Mode3->Color=clGreen;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_WorkTimer(TObject *Sender)
// по окончании времени Twork [c]
{
  T_Work->Interval=0;    // остановить цикл Работа
  T_Log->Enabled=false;  // остановить вывод в log файл каждые 10 сек
  PowerOffWithDelay();   // выключить все источники питания блоков ИПИ с задержками

  Pause();               // цикл Пауза
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_LogTimer(TObject *Sender)
// вывод в log файл каждые 10 сек
{
  T_Log->Enabled=true;

  AddSaveLog("Значение тока ИПО1 составило "+LE_I_IPO1->Text+" А");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение тока ИПП1 составило "+LE_I_IPP1->Text+" А");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение тока ИМП1 составило "+LE_I_IMP1->Text+" А");  // добавить комментарий и сохранить лог

  AddSaveLog("Значение напряжения ИПО1 составило "+LE_U_IPO1->Text+" В");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение напряжения ИПП1 составило "+LE_U_IPP1->Text+" В");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение напряжения ИМП1 составило "+LE_U_IMP1->Text+" В");  // добавить комментарий и сохранить лог

  AddSaveLog("Значение тока ИПО2 составило "+LE_I_IPO2->Text+" А");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение тока ИПП2 составило "+LE_I_IPP2->Text+" А");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение тока ИМП2 составило "+LE_I_IMP2->Text+" А");  // добавить комментарий и сохранить лог

  AddSaveLog("Значение напряжения ИПО2 составило "+LE_U_IPO2->Text+" В");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение напряжения ИПП2 составило "+LE_U_IPP2->Text+" В");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение напряжения ИМП2 составило "+LE_U_IMP2->Text+" В");  // добавить комментарий и сохранить лог
/*
  AddSaveLog("Значение тока ИПО3 составило "+LE_I_IPO3->Text+" А");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение тока ИПП3 составило "+LE_I_IPP3->Text+" А");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение тока ИМП3 составило "+LE_I_IMP3->Text+" А");  // добавить комментарий и сохранить лог

  AddSaveLog("Значение напряжения ИПО3 составило "+LE_U_IPO3->Text+" В");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение напряжения ИПП3 составило "+LE_U_IPP3->Text+" В");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение напряжения ИМП3 составило "+LE_U_IMP3->Text+" В");  // добавить комментарий и сохранить лог

  AddSaveLog("Значение тока ИПО4 составило "+LE_I_IPO4->Text+" А");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение тока ИПП4 составило "+LE_I_IPP4->Text+" А");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение тока ИМП4 составило "+LE_I_IMP4->Text+" А");  // добавить комментарий и сохранить лог

  AddSaveLog("Значение напряжения ИПО4 составило "+LE_U_IPO4->Text+" В");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение напряжения ИПП4 составило "+LE_U_IPP4->Text+" В");  // добавить комментарий и сохранить лог
  AddSaveLog("Значение напряжения ИМП4 составило "+LE_U_IMP4->Text+" В");  // добавить комментарий и сохранить лог
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_OverheatTimer(TObject *Sender)
{
  T_Overheat->Enabled=true;

  ReadDigChan(Dev1_port1_line0_3, P1);  // чтение в буфер обмена цифрового порта P1 устройства 1

  Overheat(P1[0], P_Overheat1);  // проверка перегрева устройства 1
  Overheat(P1[1], P_Overheat2);  // проверка перегрева устройства 2
  Overheat(P1[2], P_Overheat3);  // проверка перегрева устройства 3
  Overheat(P1[3], P_Overheat4);  // проверка перегрева устройства 4      
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Overheat(unsigned char line, TPanel *P_Overheat)
// проверка перегрева устройства
{
  if(!line)
  {
    T_Overheat->Enabled=false;
    T_Danger->Enabled=true;
    L_Danger->Caption=OverheatMessage;
    P_Overheat->Color=clRed;
    PowerOffWithDelay();         // выключить все источники питания блоков ИПИ с задержками
    B_Go->Enabled=false;
    B_Stop->Enabled=false;
    GB_Channel1->Enabled=false;
    GB_Channel2->Enabled=false;
    GB_Channel3->Enabled=false;
    GB_Channel4->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Delay(void)
// функция задержки
{
  Sleep(1000);                           // 1000 мс
/*
  Аналог:
  int time=GetTickCount();          // число мс со времени включения компьютера
  while((GetTickCount()-time)<1000) // 1000 - число милисекунд задержки
  { }

  Приложение работает при задержке:
  for(DWORD tt=GetTickCount();GetTickCount()-tt<1000;Sleep(10)) Application->ProcessMessages();
  или
  int time=GetTickCount();
  do{Application->ProcessMessages();} while((GetTickCount()-time)<1000);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Pause(void)
// цикл Пауза
{
  T_Pause->Interval=Tpause;           // запуск цикла Пауза на время Tpause [c]

  // сигнал включения эквивалента тепловой нагрузки
  P0[6]=1;
  WriteDigChan(Dev1_port0_line6, P0); // запись в цифровой порт P0 устройства 1
/*
  Memo1->Lines->Add(P0[6]);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_PauseTimer(TObject *Sender)
// по окончании времени Tpause [c]
{
  T_Pause->Interval=0;      // остановить цикл Пауза

  ::count++;
  LE_Cycles->Text=::count;

  if(::count<5000)
  {
    T_Work->Interval=Twork; // запуск цикла Работа на время Twork [c] (зацикливание)
    Verification();         // проверка номинальных значений параметров источников питания блоков ИПИ
  }
  else
  {
    PowerOffWithDelay();    // выключить все источники питания блоков ИПИ с задержками
    B_Go->Enabled=false;
    B_Stop->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LoadChannel(AnsiString *Nominal, bool &greenflag, TPanel *Selected,
                const char *NoMessage, double *FNominal, const char *YesMessage)
{
  NominalNumber(Nominal); // номер канала, для которого считываются номинальные значения

  // проверка загрузки файла испытаний стенда Одноцветников в канал
  for(int i=0; i<8; i++)
  {
    if(Nominal[i].IsEmpty()) // если строка пустая
    {
      greenflag=false;
      B_Go->Enabled=false;
      B_Stop->Enabled=false;
      Selected->Color=clRed;
      Application->MessageBox(NoMessage,"Внимание",MB_ICONWARNING);
      break;
    }
    else
    {
      greenflag=true;
      Selected->Color=clGreen;
      FNominal[i]=Nominal[i].ToDouble(); // FNominal[i]=StrToFloat(Nominal[i]);
    }
  }
  if(greenflag) Application->MessageBox(YesMessage,"Внимание",MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_DangerTimer(TObject *Sender)
{
  T_Danger->Enabled=true;
  MessageBeep(MB_ICONHAND);
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

