//---------------------------------------------------------------------------
// директивы препроцессора #include подключают в данный файл тексты указанных в них файлов
#include <vcl.h>  // объявления, используемые в библиотеке визуальных компонентов С++Builder
#pragma hdrstop   // конец списка общих заголовочных файлов для всех модулей проекта

#include "ApertureControlProgram_main.h"
#include "SelfControl.h"
#include "AboutBox.h"
#include "Help.h"
#include "Error.h"
#include "Tumbler.h"
#include "Tumbler2.h"
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
#include <iostream>
#include <fstream>               // Файловые операции ввода-вывода
#include <cmath>
#include <math.h>
#include "NIDAQmx.h"
#include <Registry.hpp>
#include <stdio.h>               // Include file for printf
#include <stdlib.h>              // Include file for strtol
#include <string.h>
#include <windows.h>             // Include file for Win32 time functions
#include "ni845x.h"              // Include file for NI-485x functions and constants
#include <wchar.h>

using namespace std;

/* Номера NI USB-6008:
01. Блок ПРД  - 1A32668
02. Блок ПРМ  - 19526E6
03. Блок ВИП  - 1A325A7
04. Блок ФРЛП - 1A46FA0
05. Блок УУ   - 1A32670
06. Блок БС   - 1A46FD2

Номер NI USB-8451:
01. Блок БС   - 01A5912A
*/

#define NUMBEROFPOINTS 64
#define PRD  dv6
#define PRM  dv4
#define VIP  dv2
#define FRLP dv3
#define UU   dv1
#define BS   dv5

/* the NI 845x handles */
NiHandle DeviceHandle;
NiHandle ScriptHandle;

uInt8  LineDirectionMap  = 0;    // direction configuration in hex
long   DigValue;                 // value to read

/*  error Function for NI 845x */
#ifndef errChk
#define errChk(fCall) if (Error = (fCall), Error < 0) {goto Error;} else
#endif

int    Error           = 0;
uInt32 ChipSelect      = 0;      // chip select pin (0)
uInt32 ChipSelectR     = 1;      // chip select pin (1)
uInt32 WriteSize       = 0;
uInt8  SendData1[4];             // array for data bytes to write
uInt32 ScriptReadIndex = 0;

//  Константные определения ошибок
const int NotInBorders=0;
const int NotFloat=1;
const int NotInt=2;
const int FileNotExist=3;

// Глобальные переменные таймеров
static int sec=0;
int NIDAQmxCounter=-1;
int TempPowerCounter=-1;

// Переменные обмена по DAQmx
const int NumReadValue=10;
bool ErrorADC;

float Ip27BDmin;
float Ip27BDmax;

float Ip27BDminD12=-10;
float Ip27BDmaxD12=10;
float Ip27BDminD34=-10;
float Ip27BDmaxD34=10;

float ValuePo;
float ValuePr;
float ValuePRD;
bool FPRD=false;
bool FPRDON=false;

// Описание портов NI USB-6008
unsigned char P0[8],P1[4];        // буфер

unsigned char DevP0[8],DevP1[4];  // буфер

unsigned char Dev1P0[8],Dev1P1[4],Dev2P0[8],Dev2P1[4];
unsigned char Dev3P0[8],Dev3P1[4],Dev4P0[8],Dev4P1[4];
unsigned char Dev5P0[8],Dev5P1[4],Dev6P0[8],Dev6P1[4];

// Описание конфигурации NI USB-6008
const char *Dev_port0;            // буфер
const char *Dev_port1;

const char *Dev1_port0 = "Dev1/port0/line0:7";
const char *Dev1_port1 = "Dev1/port1/line0:3";

const char *Dev2_port0 = "Dev2/port0/line0:7";
const char *Dev2_port1 = "Dev2/port1/line0:3";

const char *Dev3_port0 = "Dev3/port0/line0:7";
const char *Dev3_port1 = "Dev3/port1/line0:3";

const char *Dev4_port0 = "Dev4/port0/line0:7";
const char *Dev4_port1 = "Dev4/port1/line0:3";

const char *Dev5_port0 = "Dev5/port0/line0:7";
const char *Dev5_port1 = "Dev5/port1/line0:3";

const char *Dev6_port0 = "Dev6/port0/line0:7";
const char *Dev6_port1 = "Dev6/port1/line0:3";

const char *Dev_ai0;
const char *Dev_ai1;
const char *Dev_ai2;
const char *Dev_ai3;
const char *Dev_ai4;
const char *Dev_ai5;
const char *Dev_ai6;

const char *Dev1_ai0= "Dev1/ai0";
const char *Dev1_ai1= "Dev1/ai1";
const char *Dev1_ai2= "Dev1/ai2";
const char *Dev1_ai3= "Dev1/ai3";
const char *Dev1_ai4= "Dev1/ai4";
const char *Dev1_ai5= "Dev1/ai5";
const char *Dev1_ai6= "Dev1/ai6";

const char *Dev2_ai0= "Dev2/ai0";
const char *Dev2_ai1= "Dev2/ai1";
const char *Dev2_ai2= "Dev2/ai2";
const char *Dev2_ai3= "Dev2/ai3";
const char *Dev2_ai4= "Dev2/ai4";
const char *Dev2_ai5= "Dev2/ai5";
const char *Dev2_ai6= "Dev2/ai6";

const char *Dev3_ai0= "Dev3/ai0";
const char *Dev3_ai1= "Dev3/ai1";
const char *Dev3_ai2= "Dev3/ai2";
const char *Dev3_ai3= "Dev3/ai3";
const char *Dev3_ai4= "Dev3/ai4";
const char *Dev3_ai5= "Dev3/ai5";
const char *Dev3_ai6= "Dev3/ai6";

const char *Dev4_ai0= "Dev4/ai0";
const char *Dev4_ai1= "Dev4/ai1";
const char *Dev4_ai2= "Dev4/ai2";
const char *Dev4_ai3= "Dev4/ai3";
const char *Dev4_ai4= "Dev4/ai4";
const char *Dev4_ai5= "Dev4/ai5";
const char *Dev4_ai6= "Dev4/ai6";

const char *Dev5_ai0= "Dev5/ai0";
const char *Dev5_ai1= "Dev5/ai1";
const char *Dev5_ai2= "Dev5/ai2";
const char *Dev5_ai3= "Dev5/ai3";
const char *Dev5_ai4= "Dev5/ai4";
const char *Dev5_ai5= "Dev5/ai5";
const char *Dev5_ai6= "Dev5/ai6";

const char *Dev6_ai0= "Dev6/ai0";
const char *Dev6_ai1= "Dev6/ai1";
const char *Dev6_ai2= "Dev6/ai2";
const char *Dev6_ai3= "Dev6/ai3";
const char *Dev6_ai4= "Dev6/ai4";
const char *Dev6_ai5= "Dev6/ai5";
const char *Dev6_ai6= "Dev6/ai6";

// Переменные цветовой индикации
TColor DefaultColor=clBtnFace;
TColor GoodColor=clLime;
TColor BadColor=clRed;

// Переменные для расчета времени задержки и доплеровского смещения
const float pi=3.141592;
const float c=3*100000000;
int Fi=0;                        // значение направления полёта
int X=0;                         // значение координаты БТ по оси X
int Y=0;                         // значение координаты БТ по оси Y
int D=0;                         // расстояние до цели [м]
int V=0;                         // скорость полёта РСА [м/с]
int f=900;                       // несущая частота [МГц]

// Переменные индексов
int OldIndex;                    // для режима Управление
int OldIndex_;                   // для режима Тестирование

// Переменные усреднения
float Buff0[10];                 // очередь замеров
unsigned char N_zamera0=0;       // номер замера
float sum0;                      // 0..0x0ffffffff

float Buff1[10];                 // очередь замеров
unsigned char N_zamera1=0;       // номер замера
float sum1;                      // 0..0x0ffffffff

float Buff2[10];                 // очередь замеров
unsigned char N_zamera2=0;       // номер замера
float sum2;                      // 0..0x0ffffffff

float Buff3[10];                 // очередь замеров
unsigned char N_zamera3=0;       // номер замера
float sum3;                      // 0..0x0ffffffff

float Buff4[10];                 // очередь замеров
unsigned char N_zamera4=0;       // номер замера
float sum4;                      // 0..0x0ffffffff

float Buff5[10];                 // очередь замеров
unsigned char N_zamera5=0;       // номер замера
float sum5;                      // 0..0x0ffffffff

double k2=0.487, k3=0.529, k4=0.56, k5=1.42, k6=1.608;

String FileControl="";
String FileTesting="";

// Массивы для сохранения параметров Ложной Цели
int XString[NUMBEROFPOINTS];
int YString[NUMBEROFPOINTS];
int EPRString[NUMBEROFPOINTS];

int delay_ms;
enum diapason {D1=1, D2, D3, D4} range;           // диапазоны
enum dev {dv1=1, dv2, dv3, dv4, dv5, dv6} device; // номера NI USB-6008
enum freq {ht1=1, ht2, ht3} heterodyne;           // номера гетеродинов
/*
 Протокол обмена информацией между устройством управления (УУ)
 и платой ЦПС блока ФРЛП по интерфейсу RS-232 от 28.02.14.
*/
// Режим "Управление"
int Command3[NUMBEROFPOINTS][4]; // команда "Амплитуда БТ"
int Shift[4]={3, 255, 0, 0};     // команда "Сдвиг разрядов"
int Command4[NUMBEROFPOINTS][4]; // команда "Время задержки БТ"
int Command5[NUMBEROFPOINTS][4]; // команда "Доплеровский сдвиг БТ"
int D_SignC[NUMBEROFPOINTS];     // знак доплеровского сдвига БТ
int Command6[4]={6, 0, 0, 0};    // команда "Центральная частота рабочей полосы"
int Command7[4]={7, 0, 0, 63};   // команда "Коэффициент ослабления передатчика ППРМ-2"

// Режим "Тестирование"
int Com3[NUMBEROFPOINTS][4];     // команда "Амплитуда БТ"
int Shift_[4]={227, 255, 0, 0};  // команда "Сдвиг разрядов"
int Com4[NUMBEROFPOINTS][4];     // команда "Время задержки БТ"
int Com5[NUMBEROFPOINTS][4];     // команда "Доплеровский сдвиг БТ"
int D_SignT[NUMBEROFPOINTS];     // знак доплеровского смещения БТ
int Com6[4]={230, 0, 0, 31};     // команда "Коэффициент ослабления приёмника ППРМ-2"
int Com7[4]={231, 0, 0, 63};     // команда "Коэффициент ослабления передатчика ППРМ-2"
int Com8[4]={232, 0, 7, 142};    // команда "Частота среза фильтра гетеродина приёмника ППРМ-2"
int Com9[4]={233, 0, 7, 142};    // команда "Частота среза фильтра гетеродина передатчика ППРМ-2"
int Com10[4]={234, 0, 0, 0};     // команда "Код управления входным преселектором"
int Com11[4]={235, 0, 0, 0};     // команда "Код управления выходным преселектором"

// Рабочие регистры синтезатора платы ППРМ-2
int Com13[4]={237, 0, 0, 200};   // 00, 00, c8
int Com14[4]={238, 0, 201, 128}; // 00, c9, 80
int Com15[4]={239, 0, 8, 194};   // 00, 08, c2
int Com16[4]={240, 78, 0, 0};    // 4e, 00, 00
int Com17[4]={241, 179, 4, 0};   // b3, 04, 00
int Com18[4]={242, 0, 36, 1};    // 00, 24, 01
int Com19[4]={243, 165, 0, 5};   // a5, 00, 05
int Com20[4]={244, 0, 88, 0};    // 00, 58, 00

int Com21[4]={246, 0, 0, 0};     // команда "Смещение I-ой составляющей сигнала"
int Com22[4]={247, 0, 0, 0};     // команда "Смещение Q-ой составляющей сигнала"
int Com23[4]={248, 0, 0, 0};     // команда "Работа АЦП"
int Com24[4]={249, 0, 0, 0};     // команда "Работа ЦАП"
int Com25[4]={250, 0, 0, 0};     // команда "Работа ППРМ-2"
int Com26[4]={251, 0, 0, 0};     // команда "Работа ПЛИС"

int Reg[6];
/*
  Reg[0]=0x00C80000;
  Reg[1]=0x080080C9;
  Reg[2]=0x00004EC2;
  Reg[3]=0x000004B3;
  Reg[4]=0x00A50124;
  Reg[5]=0x00580005;

  Параметры синтезатора частоты ADF4350 блока ФРЛП, входящего в состав изделия.
*/
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
/*
  Цоколёвка аналоговых и цифровых выводов NI USB-6008 и NI USB-8451:

  Устройство 1 (Приёмник ПРМ):
  NI USB-6008:
  P0.0, P0.1, P0.2, P0.3, P0.4 - запись команды "Затухание аттенюатора приемника" [дБ]
  P0.5 - запись команды "Выбор частотного диапазона 2-й ступени"
  P0.6, P0.7 - запись команды "Выбор частотного диапазона №1"
  P1.0, P1.1 - запись команды "Выбор частотного диапазона №2"

  AI0 - чтение напряжения питания источника +5 В приёмника [В]
  AI1 - чтение напряжения питания источника +12 В приёмника [В]
  AI2 - чтение мощности сигнала приёмника [дБм]
  AI4 - чтение напряжения питания источника -5 В приёмника [В]
  AI5 - чтение тока питания источника +27 В приёмника [А]

  Устройство 2 (Передатчик ПРД):
  NI USB-6008:
  P0.0, P0.1, P0.2, P0.3, P0.4 - запись команды "Затухание аттенюатора передатчика" [дБ]
  P0.5 - запись команды "Выбор частотного диапазона 2-й ступени"
  P0.6, P0.7 - запись команды "Выбор частотного диапазона №1"
  P1.0, P1.1 - запись команды "Выбор частотного диапазона №2"

  AI0 - чтение напряжения питания источника +5 В передатчика [В]
  AI1 - чтение напряжения питания источника +12 В передатчика [В]
  AI2 - чтение мощности сигнала передатчика [дБм]
  AI4 - чтение напряжения питания источника -5 В передатчика [В]
  AI5 - чтение тока питания источника +27 В передатчика [А]

  Устройство 3 (Вторичный источник питания ВИП):
  NI USB-6008:
  P0.0 - запись команды "Запомнить для ВК-ПРД"
  P0.1 - запись команды "Включить -9 В на ВК-ПРД"
  P0.2 - запись команды "Включить +24 В на ВК-ПРД"

  AI0 - чтение напряжения питания источника +12 В [В]
  AI1 - чтение напряжения питания источника +27 В [В]
  AI2 - чтение тока выносного передатчика [А]
  AI3 - чтение напряжения питания ВК-ПРД [В]
  AI4 - чтение напряжения питания источника +5 В [В]
  AI5 - чтение тока выносного приёмника [А]

  Устройство 4 (Устройство управления УУ):
  NI USB-6008:
  AI0 - чтение напряжения питания источника +5 В [В]
  AI1 - чтение выходного напряжения датчика тока [А]
  AI4 - чтение напряжения питания источника +12 В [В]

  Устройство 5 (Блок синтезатора БС)
  NI USB-6008:
  P0.0, P0.1, P0.2, P0.3, P0.4, P0.5 - запись команды "Установка затухания аттенюатора основного канала" [дБ]
  P0.6, P0.7, P1.0, P1.1, P1.2, P1.3 - запись команды "Установка затухания аттенюатора резервного канала" [дБ]

  AI0 - чтение значения датчика температуры основного канала [град.]
  AI1 - чтение значения датчика температуры резервного канала [град.]
  AI2 - чтение значения напряжения питания +5В [В]
  AI3 - чтение значения тока потребления по +27В [А]
  AI4 - чтение значения мощности сигнала контрольного выхода основного канала [Вт]
  AI5 - чтение значения мощности сигнала контрольного выхода резервного канала [Вт]
  AI6 - чтение значения напряжения питания -5В [В]

  NI USB-8451:
  P0.0 - чтение команды "Захват фазы ФАПЧ основного канала", 0 – фаза не захвачена, 1 – фаза захвачена
  P0.1 - запись команды "Включить питание синтезатора основного канала", 0 – выключено, 1 – включено
  P0.2 - чтение команды "Захват фазы ФАПЧ резервного канала", 0 – фаза не захвачена, 1 – фаза захвачена
  P0.3 - запись команды "Включить питание синтезатора резервного канала", 0 – выключено, 1 – включено

  P0.4, P0.5 - запись команды "Выбор гетеродина основного канала для контроля"
  P0.6, P0.7 - запись команды "Выбор гетеродина резервного канала для контроля"

  Устройство 6 (Блок ФРЛП)
  NI USB-6008:

  AI0 - чтение значения напряжения питания УЦПС [В], при вкл. блока - 5 В (+4,85…+5,15 В)
  AI1 - чтение значения датчика температуры [град.]
  AI4 - чтение значения датчика тока потребления +27 В блока ФРЛП [А]
  AI5 - чтение значения напряжения аналогового выхода детектора [дБм]
*/
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CommPort"
#pragma resource "*.dfm"
TMainForm *MainForm;
TIniFile *Ini;
//---------------------------------------------------------------------------
// вызов конструктора формы MainForm
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

  if(!DirectoryExists(My_Patch + "Файлы результатов в режиме Работа"))
  {
	if(!CreateDir(My_Patch + "Файлы результатов в режиме Работа"))
	  ShowMessage("Не удается создать директорию хранения файлов результатов в режиме Работа!");
    else
      ShowMessage("Создана директория для хранения файлов результатов в режиме Работа!");
  }
/*
  extern PACKAGE bool __fastcall DirectoryExists(const System::UnicodeString Directory, bool FollowLink = true);
  Функция DirectoryExists возвращает True, если данный DirectoryName файл существует.
  Каталог разыскивается в текущем каталоге. False может быть возвращена, если пользователю не
  разрешено видеть файл.

  extern PACKAGE bool __fastcall CreateDir(const System::UnicodeString Dir);
  Функция CreateDir создаёт папку в текущей директории.
  Если папка была создана, то функция вернёт True.
*/

  InitBPControl();
  InitBPTesting();

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

  // очистка портов NI USB-6008
  ClearDevs();

  DevToP0P1(dv1);
  SetDev_port(dv1);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv2);
  SetDev_port(dv2);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv3);
  SetDev_port(dv3);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv4);
  SetDev_port(dv4);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv5);
  SetDev_port(dv5);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  DevToP0P1(dv6);
  SetDev_port(dv6);
  SetDevP0P1Data(Dev_port0, Dev_port1);

  range=D1;
  heterodyne=0;
  DefaultPanel();

  Ip27BDmin=Ip27BDminD12;
  Ip27BDmax=Ip27BDmaxD12;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
  F_SelfControl->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_AvailableComClick(TObject *Sender)
{
  SearchCOMPorts();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SearchCOMPorts(void)
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
void __fastcall TMainForm::TB_AboutClick(TObject *Sender)
{
  AddSaveLog("Информация о программе, номере версии и правах");  // добавить комментарий и сохранить лог
  F_AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HelpAboutProgClick(TObject *Sender)
{
  F_Help->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddSaveLog(String comment) // добавить комментарий и сохранить лог
{
  My_Patch = ExtractFilePath(Application->ExeName);   // путь к исполнимому файлу

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
3.	Алгоритмическая реализация управления А-О

3.1	 Предпусковые операции.
Для работы с программой управления все тумблеры управления электропитанием блоков
перевести в положение «ВКЛ.».
В блоке ВИП (на NI6008) сигнал управления «ВКЛ. Минус 9В» выставить
в лог. 1, через секунду сигнал управления «ВКЛ.+24В» выставить
в лог. 1 и через секунду передать сигнал «Запомнить» длительностью не менее 20мс
(длительность 200 мс, лог. 1).

  P0.0 - запись команды "Запомнить для ВК-ПРД"
  P0.1 - запись команды "Включить -9 В на ВК-ПРД"
  P0.2 - запись команды "Включить +24 В на ВК-ПРД"
*/
  //Prestart();                       // предпусковые операции
/*
  FormatDateTime (s, dt) - Строка символов, представляющая собой дату или время. Способ представления
  задает строка формата s, например, строка dd/mm/yyyy задает, что значением функции является дата,
  а строка hh:mm – время
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+"_"+FormatDateTime("HH-NN-SS",Time()); // текущая дата и время
  logFname = P_SystemTime->Caption; // запись имени лог файла в буфер при открытии программы
  AddSaveLog("Программа запущена"); // добавить комментарий и сохранить лог
/*
  M_Debug->Lines->Add(PRD);
  M_Debug->Lines->Add(PRM);
  M_Debug->Lines->Add(VIP);
  M_Debug->Lines->Add(FRLP);
  M_Debug->Lines->Add(UU);
  M_Debug->Lines->Add(BS);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  AddSaveLog("Программа закрыта"); // добавить комментарий и сохранить лог
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_EnterClick(TObject *Sender)
{
  if(E_EnterComment->Text!="")
  {
    AddSaveLog(E_EnterComment->Text); // запись лог файла
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ChB_LogClick(TObject *Sender)
{
  if(ChB_Log->Checked==true) M_Log->Visible=false;
  else                       M_Log->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WorkTimerTimer(TObject *Sender)
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
void __fastcall TMainForm::SB_OnOffClick(TObject *Sender)
{
  try
  {
    if(SB_OnOff->Down)         // если нажата
	{
      SB_OnOff->Caption="Выключить";
      SB_OnOff->Font->Color=clRed;

      WorkTimer->Enabled=true; // включить таймер WorkTimer

	  StartControl();
    }
    else                       // если не нажата
    {
      SB_OnOff->Caption="Включить";
	  SB_OnOff->Font->Color=clGreen;

	  StopControl();
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
void __fastcall TMainForm::ButtonsOn(void)
{
  B_Ready->Enabled=true;
  CB_ComNum->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SystemTimerTimer(TObject *Sender)
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
void __fastcall TMainForm::ExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
  if (!DirectoryExists(My_Patch + "log файлы"))
  {
	MessageBox(NULL,L"Отсутсвует директория log файлы!",L"Ошибка!",MB_OK|MB_ICONERROR);
    Application->Terminate();
  }
}
//---------------------------------------------------------------------------
bool TMainForm::IsValidInt(int min, int max, String value, String EdIzm)
// проверка правильности диапазона значений целых чисел
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
void TMainForm::ShowError(int ErrorNum, float Par1, float Par2, String Par3)
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
bool __fastcall TMainForm::SetDevP0P1Data(const char *Config0, const char *Config1)
// запись цифровых портов
{
	TaskHandle  taskHandle=0;
	char        errBuff[2048]={'\0'};

/////////////////////////////////////////////////////////////////////////////
  // Записываем P0
/////////////////////////////////////////////////////////////////////////////

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // Определяем параметры задачи
  if (DAQmxFailed((DAQmxCreateDOChan(taskHandle,Config0,"",DAQmx_Val_ChanForAllLines))))
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

/////////////////////////////////////////////////////////////////////////////
  // Записываем P1
/////////////////////////////////////////////////////////////////////////////

  // Создаем задачу
  if (DAQmxFailed((DAQmxCreateTask("",&taskHandle))))
  {
    DAQmxGetExtendedErrorInfo(errBuff,2048);
    return false;
  }

  // Определяем параметры задачи
  if (DAQmxFailed((DAQmxCreateDOChan(taskHandle,Config1,"",DAQmx_Val_ChanForAllLines))))
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
  if (DAQmxFailed((DAQmxWriteDigitalLines(taskHandle,1,1,1.0,DAQmx_Val_GroupByChannel,P1,NULL,NULL))))
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
float __fastcall TMainForm::GetDevACDData(const char *Config)
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
void __fastcall TMainForm::E_Command3Change(TObject *Sender)
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
void __fastcall TMainForm::E_Command3Exit(TObject *Sender)
{
  bool b;
  int min=0;                                           // минимальное значение
  int max=255;                                         // максимальное значение
  int delta=1;
  String EdIzm="";                                     // единица измерения
  int ivalue;                                          // строка значения

  ivalue=StrToInt(E_Command3->Text);                   // значение

  b=IsValidInt(min,max,ivalue,EdIzm);                  // проверка правильности диапазона значений
  if(b)                                                // если правильно
  {
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
String TMainForm::RoundValue(float delta, float fvalue)
{
  float temp;
  float temp1;

  temp=fvalue;
  temp1=Log10(delta);          // количество знаков после запятой
  // округлить до значения с 2-мя десятичными знаками после запятой:
  fvalue=RoundTo(temp,temp1);  // в BCB6 было String (преобразование типов автоматом)

  return fvalue;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command3KeyPress(TObject *Sender, wchar_t &Key)
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
void __fastcall TMainForm::E_Command3_0Change(TObject *Sender)
{
  ResetBPControl();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ResetBPControl(void)  // сброс команд Command 3...5
{
  InitBPControl();                 // очистить предыдущие параметры БТ
  CB_Command3_1->ItemIndex=0;
  CB_SignC->ItemIndex=0;
  E_Command3->Text=IntToStr(255);
  E_Command4->Text=IntToStr(0);
  E_Command5->Text=IntToStr(0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::InitBPControl(void)  // инициализация команд Command 3...5
{
  // инициализация массива Command3
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Command3[i][0]=3;   // байт кода команды
    Command3[i][1]=i+1; // 1-й байт пакета данных
    Command3[i][2]=0;   // 2-й байт пакета данных
  }
  Command3[0][3]=255;   // 3-й байт пакета данных (БТ №1)

  for(int i=1; i<NUMBEROFPOINTS; i++)
  {
    Command3[i][3]=0;   // 3-й байт пакета данных (остальные БТ)
  }

  // инициализация массива Command4
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Command4[i][0]=4;   // байт кода команды
    Command4[i][1]=i+1; // 1-й байт пакета данных
    Command4[i][2]=0;   // 2-й байт пакета данных
    Command4[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива Command5
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Command5[i][0]=5;   // байт кода команды
    Command5[i][1]=i+1; // 1-й байт пакета данных
    Command5[i][2]=0;   // 2-й байт пакета данных
    Command5[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива SignC
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    D_SignC[i]=0;
  }

  OldIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command3_0Exit(TObject *Sender)
// когда поле "Количество блестящих точек" неактивно
{
  bool b;
  int min=1;                             // минимальное значение
  int max=NUMBEROFPOINTS;                // максимальное значение
  int delta=1;
  String EdIzm="";                       // единица измерения
  int ivalue;                            // строка значения

  ivalue=StrToInt(E_Command3_0->Text);   // значение

  b=IsValidInt(min,max,ivalue,EdIzm);    // проверка правильности диапазона значений
  if(b)                                  // если правильно
  {
	CB_Command3_1->Clear();              // очистить предыдущее количество БТ

    for(int i=0;i<StrToInt(E_Command3_0->Text);i++)
    {
      CB_Command3_1->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
    }

	CB_Command3_1->ItemIndex=0;          // номер БТ по умолчанию при изменении числа БТ
  }
  else                                   // если не правильно
  {
	E_Command3_0->SetFocus();            // фокус на поле "Количество блестящих точек"
    ErrorForm->SetFocus();               // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Command3_1Change(TObject *Sender)  // по изменении номера БТ
{
  int i, Comm3, Comm4, Comm5;
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
void __fastcall TMainForm::CB_SignCKeyPress(TObject *Sender, wchar_t &Key)  // запрет введения любых символов
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
void __fastcall TMainForm::CB_ShiftChange(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
	if(CB_Shift->ItemIndex==i) Shift[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command4Change(TObject *Sender)
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
void __fastcall TMainForm::E_Command4Exit(TObject *Sender)
// по изменении фокуса с данного поля редактирования
{
  bool b;
  int min=0;
  int max=63;
  int delta=1;
  String EdIzm="нс";
  int ivalue;

  ivalue=StrToInt(E_Command4->Text);

  b=IsValidInt(min,max,ivalue,EdIzm);
  if(b)
  {
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
void __fastcall TMainForm::CB_SignCChange(TObject *Sender)
{
  if(CB_SignC->ItemIndex==0) D_SignC[OldIndex]=0;
  else                       D_SignC[OldIndex]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_SignCExit(TObject *Sender)
{
  if(CB_SignC->ItemIndex==0) D_SignC[OldIndex]=0;
  else                       D_SignC[OldIndex]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command5Change(TObject *Sender)
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
void __fastcall TMainForm::E_Command5Exit(TObject *Sender)
// по изменении фокуса с данного поля редактирования
{
  bool b;
  float min=-16384;   // -32768*0.5
  float max=16383.5;  // 32767*0.5
  float delta=0.5;    // цена младшего разряда 0.5 Гц
  String EdIzm="гц";
  float fvalue;

  fvalue=StrToFloat(E_Command5->Text);

  b=IsValid(min,max,fvalue,EdIzm);
  if(b)
  {
	E_Command5->Text=RoundValue(delta,fvalue);
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
bool TMainForm::IsValid(float min, float max, String value, String EdIzm)
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
void __fastcall TMainForm::CB_Command7Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Command7->ItemIndex==i) Command7[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Command7Exit(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Command7->ItemIndex==i) Command7[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com3Change(TObject *Sender)
{
  int Comm3;
  if(E_Com3->Text=="") E_Com3->Text=0;
  Comm3=StrToInt(E_Com3->Text);                  // записать значение в переменную
  Com3[OldIndex_][3]=Comm3&0xFF;                 // мл. байт
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com3Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=255;
  int delta=1;
  String EdIzm="";
  int ivalue;

  ivalue=StrToInt(E_Com3->Text);

  b=IsValidInt(min,max,ivalue,EdIzm);
  if(b)
  {
    Com3[OldIndex_][3]=StrToInt(E_Com3->Text);
  }
  else
  {
    E_Com3->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com3_1Change(TObject *Sender)  // по изменении номера БТ
{
  int i, Comm3, Comm4, Comm5;
  i=CB_Com3_1->ItemIndex;                            // записать новый индекс поля выбора CB_Com3_1
  // записать старые значения полей редактирования в переменную:
  Comm3=StrToInt(E_Com3->Text);                      // записать старое значение поля E_Com3 в переменную
  Comm4=StrToInt(E_Com4->Text);                      // записать старое значение поля E_Com4 в переменную
  Comm5=StrToInt(E_Com5->Text);                      // записать старое значение поля E_Com5 в переменную
  // записать старые значения по индексу OldIndex в массив:
  Com3[OldIndex_][3]=Comm3&0xFF;
  Com4[OldIndex_][3]=Comm4&0xFF;                     // мл. байт
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;               // ст. байт
  Com5[OldIndex_][3]=Comm5&0xFF;                     // мл. байт
  Com5[OldIndex_][2]=(Comm5/256)&0xFF;               // ст. байт
  D_SignT[OldIndex_]=CB_SignT->ItemIndex;

  OldIndex_=i;  // сохранить текущий индекс как старый для следующего вхождения в метод

  // извлечь значения из массива по текущему индексу в поля редактирования:
  E_Com3->Text=IntToStr(Com3[i][3]);                 // показать текущее значение
  E_Com4->Text=IntToStr(Com4[i][2]*256+Com4[i][3]);  // показать текущее значение
  E_Com5->Text=IntToStr(Com5[i][2]*256+Com5[i][3]);  // показать текущее значение
  // извлечь значения из массива по текущему индексу в поле выбора:
  if(D_SignT[i]==0) CB_SignT->ItemIndex=0;
  else              CB_SignT->ItemIndex=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ResetBPTesting(void)  // сброс команд Com 3...5
{
  InitBPTesting();                                // очистить предыдущие параметры БТ
  CB_Com3_1->ItemIndex=0;
  CB_SignT->ItemIndex=0;
  E_Com3->Text=IntToStr(255);
  E_Com4->Text=IntToStr(0);
  E_Com5->Text=IntToStr(0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::InitBPTesting(void)  // инициализация команд Com 3...5
{
  // инициализация массива Com3
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Com3[i][0]=227; // байт кода команды
    Com3[i][1]=i+1; // 1-й байт пакета данных
    Com3[i][2]=0;   // 2-й байт пакета данных
  }
  Com3[0][3]=255;   // 3-й байт пакета данных (БТ №1)

  for(int i=1; i<NUMBEROFPOINTS; i++)
  {
    Com3[i][3]=0;   // 3-й байт пакета данных (остальные БТ)
  }

  // инициализация массива Com4
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Com4[i][0]=228; // байт кода команды
    Com4[i][1]=i+1; // 1-й байт пакета данных
    Com4[i][2]=0;   // 2-й байт пакета данных
    Com4[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива Com5
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    Com5[i][0]=229; // байт кода команды
    Com5[i][1]=i+1; // 1-й байт пакета данных
    Com5[i][2]=0;   // 2-й байт пакета данных
    Com5[i][3]=0;   // 3-й байт пакета данных
  }

  // инициализация массива SignT
  for(int i=0; i<NUMBEROFPOINTS; i++)
  {
    D_SignT[i]=0;
  }

  OldIndex_=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com3_0Change(TObject *Sender)
{
  ResetBPTesting();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com3_0Exit(TObject *Sender)
// когда поле "Количество блестящих точек" неактивно
{
  bool b;
  int min=1;                           // минимальное значение
  int max=NUMBEROFPOINTS;              // максимальное значение
  String EdIzm="";                     // единица измерения
  int ivalue;                          // строка значения

  ivalue=StrToInt(E_Com3_0->Text);     // значение

  b=IsValidInt(min,max,ivalue,EdIzm);  // проверка правильности диапазона значений
  if(b)                                // если правильно
  {
	CB_Com3_1->Clear();                // очистить предыдущее количество БТ

    for(int i=0;i<StrToInt(E_Com3_0->Text);i++)
    {
      CB_Com3_1->Items->Add(IntToStr(i+1)); // увеличить количество БТ в полях "Номер блестящей точки"
    }

	CB_Com3_1->ItemIndex=0;            // номер БТ по умолчанию при изменении числа БТ
  }
  else                                 // если не правильно
  {
	E_Com3_0->SetFocus();              // фокус на поле "Количество блестящих точек"
    ErrorForm->SetFocus();             // вывод сообщения об ошибке
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Shift_Change(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
    if(CB_Shift_->ItemIndex==i) Shift_[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_ShiftExit(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
	if(CB_Shift->ItemIndex==i) Shift[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Shift_Exit(TObject *Sender)
{
  for(int i=0; i<7; i++)
  {
    if(CB_Shift_->ItemIndex==i) Shift_[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com4Change(TObject *Sender)
{
  int Comm4;
  if(E_Com4->Text=="") E_Com4->Text=0;
  Comm4=StrToInt(E_Com4->Text);                   // записать значение в переменную
  Com4[OldIndex_][3]=Comm4&0xFF;                  // мл. байт
  Com4[OldIndex_][2]=(Comm4/256)&0xFF;            // ст. байт
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com4Exit(TObject *Sender)
{
  bool b;
  int min=0;
  int max=65535;
  int delta=1;
  String EdIzm="нс";
  int ivalue;

  ivalue=StrToInt(E_Com4->Text);

  b=IsValidInt(min,max,ivalue,EdIzm);
  if(b)
  {
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
//--------------------------------------------------------------------------
void __fastcall TMainForm::E_Com5Change(TObject *Sender)
// по изменении параметра в поле редактирования
{
  float Comm5;
  if(E_Com5->Text=="") E_Com5->Text=0;
  Comm5=StrToFloat(E_Com5->Text);                  // записать текущее значение в переменную
  // записать текущее значение по индексу OldIndex в массив:
  Com5[OldIndex_][3]=(int)Comm5&0xFF;              // мл. байт
  Com5[OldIndex_][2]=((int)Comm5/256)&0xFF;        // ст. байт
/*
  Значение записывается по индексу OldIndex, т.к. этот индекс старый относительно
  метода "по изменении номера БТ" CB_Command3_1Change(TObject *Sender).
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Com5Exit(TObject *Sender)
{
  bool b;
  float min=0;
  float max=16383.75;  // 65535*0.5/2
  float delta=0.5;
  String EdIzm="гц";
  float fvalue;

  fvalue=StrToFloat(E_Com5->Text);

  b=IsValid(min,max,fvalue,EdIzm);
  if(b)
  {
	E_Com5->Text=RoundValue(delta,fvalue);
	float Comm5=StrToInt(E_Com5->Text);             // записать текущее значение в переменную
	// записать текущее значение по индексу OldIndex в массив:
	Com5[OldIndex_][3]=(int)Comm5&0xFF;             // мл. байт
	Com5[OldIndex_][2]=((int)Comm5/256)&0xFF;       // ст. байт
/*
    Значение записывается по индексу OldIndex, т.к. этот индекс старый относительно
    метода "по изменении номера БТ" CB_Command3_1Change(TObject *Sender).
*/
  }
  else
  {
    E_Com5->SetFocus();
    ErrorForm->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_SignTChange(TObject *Sender)
{
  if(CB_SignT->ItemIndex==0) D_SignT[OldIndex_]=0;
  else                       D_SignT[OldIndex_]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_SignTExit(TObject *Sender)
{
  if(CB_SignT->ItemIndex==0) D_SignT[OldIndex_]=0;
  else                       D_SignT[OldIndex_]=1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com6Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
	if(CB_Com6->ItemIndex==i) Com6[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com7Change(TObject *Sender)
{
  for(int i=0; i<64; i++)
  {
    if(CB_Com7->ItemIndex==i) Com7[3]=63-i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com8Change(TObject *Sender)
{
  for(int i=0; i<16; i++)
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
void __fastcall TMainForm::CB_Com9Change(TObject *Sender)
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
void __fastcall TMainForm::CB_Com10Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Com10->ItemIndex==i) Com10[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com11Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Com11->ItemIndex==i) Com11[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_OutputChange(TObject *Sender)
{
  UpdateRegister4();  // обновление значения Register 4
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_AuxOutChange(TObject *Sender)
{
  UpdateRegister4();  // обновление значения Register 4
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_OutFreqChange(TObject *Sender)
{
  if(E_OutFreq->Text<=1) E_OutFreq->Text=1;  // число не может быть меньше 1
  Fout=StrToFloat(E_OutFreq->Text);          // записать значение в переменную
  //M_Debug->Lines->Add(Fout);

  Fvco_OD();          // вычисление Fvco и OD
  Ndevider();         // вычисление INT, FRAC и MOD
  UpdateRegister0();  // обновление значения Register 0
  UpdateRegister1();  // обновление значения Register 1
  UpdateRegister4();  // обновление значения Register 4
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Fvco_OD(void)
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
void __fastcall TMainForm::Ndevider(void)  // вычисление INT, FRAC и MOD:
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
void __fastcall TMainForm::UpdateRegister0(void)  // обновление значения Register 0
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
/*
  E_Com13_1->Text=IntToStr(Com13[1]);
  E_Com13_2->Text=IntToStr(Com13[2]);
  E_Com13_3->Text=IntToStr(Com13[3]);
  E_Com14_1->Text=IntToStr(Com14[1]);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateRegister1(void)  // обновление значения Register 1
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
/*
  E_Com14_2->Text=IntToStr(Com14[2]);
  E_Com14_3->Text=IntToStr(Com14[3]);
  E_Com15_1->Text=IntToStr(Com15[1]);
  E_Com15_2->Text=IntToStr(Com15[2]);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateRegister4(void)  // обновление значения Register 4
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
/*
  E_Com18_2->Text=IntToStr(Com18[2]);
  E_Com18_3->Text=IntToStr(Com18[3]);
  E_Com19_1->Text=IntToStr(Com19[1]);
  E_Com19_2->Text=IntToStr(Com19[2]);
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadBlpClick(TObject *Sender)  // нажатие на кнопку "Открыть файл .blp"
{
  AddSaveLog("Загрузить файл данных БТ");  // добавить комментарий и сохранить лог

  OpenDialog1->DefaultExt=".blp";
  OpenDialog1->FileName="*.blp";
  OpenDialog1->Filter="Файл данных БТ (*.blp)|*.blp";
  OpenDialog1->Title=" Загрузка файла данных БТ";

  String File;

  if(OpenDialog1->Execute())
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  Отображает диалог выбора файлов.
  Возвращает true, если пользователь выбрал файл и нажал кнопку "Открыть" ("Open") в диалоге.
  Если пользователь нажал кнопку "Отмена" ("Cancel"), то Execute возвращает false.
*/
  {
	File=OpenDialog1->FileName;
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

  StatusBar1->SimpleText=File; // вывод в строку состояния
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadSarClick(TObject *Sender)  // нажатие на кнопку "Открыть файл .sar"
{
  AddSaveLog("Загрузить файл данных РЛС и модуля");          // добавить комментарий и сохранить лог

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
	  // Скорость полёта РСА V
	  LE_V->Text=Ini->ReadString("Данные РЛС и модуля","Скорость полёта РСА","1");   // считать из файла в массив

	  if(LE_V->Text!="")
	  {
		V=StrToInt(LE_V->Text);    // подготовить значение
	    //M_Debug->Lines->Add(V);
	  }
	  // Несущая частота f
	  LE_f->Text=Ini->ReadString("Данные РЛС и модуля","Несущая частота","1");       // считать из файла в массив

	  if(LE_f->Text!="")
	  {
		f=StrToInt(LE_f->Text);    // подготовить значение
		//M_Debug->Lines->Add(f);
	  }
	  // Направления полёта Fi относительно направления на север
	  LE_Fi->Text=Ini->ReadString("Данные РЛС и модуля","Направление полёта","1");   // считать из файла в массив

	  if(LE_Fi->Text!="")
	  {
		Fi=StrToInt(LE_Fi->Text);  // подготовить значение
		//M_Debug->Lines->Add(Fi);
	  }
	  // Расстояние до цели D
	  LE_D->Text=Ini->ReadString("Данные РЛС и модуля","Расстояние до цели","1");    // считать из файла в массив

	  if(LE_D->Text!="")
	  {
		D=StrToInt(LE_D->Text);    // подготовить значение
		//M_Debug->Lines->Add(D);
	  }
      AddSaveLog("Загружен файл "+SarFName);           // добавить комментарий и сохранить лог

	  delete Ini;
	}
	else
	{
	  ShowError(FileNotExist, 0, 0, "");
	}
  }

  StatusBar1->SimpleText=File; // вывод в строку состояния
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_SaveControlClick(TObject *Sender)
{
  AddSaveLog("Сохранить файл результатов в режиме Управление");  // добавить комментарий и сохранить лог

  SaveDialog1->DefaultExt=".ctr";
  SaveDialog1->FileName="*.ctr";
  SaveDialog1->Filter="Файл режима Управление (*.ctr)|*.ctr";
  SaveDialog1->Title=" Сохранение файла режима Управление";

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

  if(SaveDialog1->Execute())
  {
	File=SaveDialog1->FileName;
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
	Ini->WriteString("Данные в режиме Управление","Количество БТ",E_Command3_0->Text);

	// Command3
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
	  Ini->WriteString("Данные в режиме Управление","Команда \"Амплитуда блестящей точки (БТ)\""+IntToStr(i+1)+"\"",Command3[i][3]);  // запись из массива в файл
    }
    // Command4
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
      int Command=Command4[i][3]+Command4[i][2]*256;
	  Ini->WriteString("Данные в режиме Управление","Команда \"Время задержки (БТ)"+IntToStr(i+1)+"\"",Command);   // запись из массива в файл
    }
    // Command5, цена младшего разряда 0.5 Гц
    for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
    {
	  Ini->WriteString("Данные в режиме Управление","Команда \"Знак доплеровского сдвига частоты (БТ)\""+IntToStr(i+1)+"\"",D_SignC[i]);  // запись из массива в файл
      int Command=(Command5[i][3]+Command5[i][2]*256);
	  Ini->WriteString("Данные в режиме Управление","Команда \"Доплеровский сдвиг частоты (БТ)\""+IntToStr(i+1)+"\"",Command);  // запись из массива в файл
    }
    // Команда "Сдвиг разрядов"
	Ini->WriteString("Данные в режиме Управление","Команда \"Сдвиг разрядов\"",IntToStr(Shift[3])); // запись из массива в файл
    // Command6
    int Comm6=Command6[3]+Command6[2]*256;
	Ini->WriteString("Данные в режиме Управление","Команда \"Центральная частота рабочей полосы\"",Comm6);   // запись из массива в файл
    // Command7
    Ini->WriteString("Данные в режиме Управление","Команда \"Коэффициент ослабления передатчика ППРМ-2\"",IntToStr(Command7[3])); // запись из массива в файл

    delete Ini;
  }

  StatusBar1->SimpleText=File; // вывод в строку состояния
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_SaveTestingClick(TObject *Sender)
{
  AddSaveLog("Сохранить файл результатов в режиме Тестирование");  // добавить комментарий и сохранить лог

  SaveDialog1->DefaultExt=".tst";
  SaveDialog1->FileName="*.tst";
  SaveDialog1->Filter="Файл режима Тестирование(*.tst)|*.tst";
  SaveDialog1->Title=" Сохранение файла режима Тестирование";

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

  if(SaveDialog1->Execute())
  {
    File=SaveDialog1->FileName;
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

  StatusBar1->SimpleText=File; // вывод в строку состояния
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadControlClick(TObject *Sender)
{
  AddSaveLog("Загрузить файл результатов в режиме Управление");  // добавить комментарий и сохранить лог

  ResetBPControl();

  OpenDialog1->DefaultExt=".ctr";
  OpenDialog1->FileName="*.ctr";
  OpenDialog1->Filter="Файл режима Управление (*.ctr)|*.ctr";
  OpenDialog1->Title=" Загрузка файла режима Управление";

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
      // Количество БТ
	   E_Command3_0->Text=Ini->ReadString("Данные в режиме Управление","Количество БТ","1");                // считать из файла в массив
      // Command3, Command4, Command5
      for(int i=0; i<StrToInt(E_Command3_0->Text); i++)
      {
        // Command3
		Command3[i][3]=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Амплитуда блестящей точки (БТ)\""+IntToStr(i+1)+"\"","0"));  // считать из файла в массив
        // Command4
		int Comm4=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Время задержки (БТ)"+IntToStr(i+1)+"\"","0"));                    // считать из файла в массив
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
      // Команда "Сдвиг разрядов"
	  Shift[3]=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Сдвиг разрядов\"","0")); // считать из файла в массив
      for(int i=0; i<7; i++)
      {
        if(Shift[3]==i) CB_Shift->ItemIndex=i; // запись в форму
      }
      // Command6
	  int Comm6=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Центральная частота рабочей полосы\"","0"));      // считать из файла в массив
      Command6[3]=Comm6&0xFF;                     // мл. байт
      Command6[2]=(Comm6/256)&0xFF;               // ст. байт
      // Command7
      Command7[3]=StrToInt(Ini->ReadString("Данные в режиме Управление","Команда \"Коэффициент ослабления передатчика ППРМ-2\"","0")); // считать из файла в массив
      for(int i=0; i<64; i++)
      {
        if(Command7[3]==63-i) CB_Command7->ItemIndex=i; // запись в форму
      }

      AddSaveLog("Загружен файл "+FileControl);  // добавить комментарий и сохранить лог

      delete Ini;
    }
    else
    {
      ShowError(FileNotExist, 0, 0, "");
    }
  }

  StatusBar1->SimpleText=File; // вывод в строку состояния
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_LoadTestingClick(TObject *Sender)
{
  AddSaveLog("Загрузить файл результатов в режиме Тестирование");  // добавить комментарий и сохранить лог

  ResetBPTesting();

  OpenDialog1->DefaultExt=".tst";
  OpenDialog1->FileName="*.tst";
  OpenDialog1->Filter="Файл режима Тестирование (*.tst)|*.tst";
  OpenDialog1->Title=" Загрузка файла режима Тестирование";

  String File;

  if(OpenDialog1->Execute())
  {
    File=OpenDialog1->FileName;
    FileTesting=File;

    if(FileExists(File))
    {
      Ini= new TIniFile(File);
/*
      Ini->ReadString("Название секции","Имя переменной", "значение");
*/
      // Количество БТ
	  E_Com3_0->Text=Ini->ReadString("Данные в режиме Тестирование","Количество БТ","1");
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
      // Com13
	  unsigned long int Comm13=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 1\"","0"));      // считать из файла в массив
      Com13[3]=Comm13&0xFF;                    // мл. байт
      Com13[2]=(Comm13/256)&0xFF;              // ср. байт
	  Com13[1]=(Comm13/65536)&0xFF;            // ст. байт

      // Com14
	  unsigned long int Comm14=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 2\"","0"));      // считать из файла в массив
      Com14[3]=Comm14&0xFF;                    // мл. байт
      Com14[2]=(Comm14/256)&0xFF;              // ср. байт
	  Com14[1]=(Comm14/65536)&0xFF;            // ст. байт

      // Com15
	  unsigned long int Comm15=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 3\"","0"));      // считать из файла в массив
      Com15[3]=Comm15&0xFF;                    // мл. байт
      Com15[2]=(Comm15/256)&0xFF;              // ср. байт
	  Com15[1]=(Comm15/65536)&0xFF;            // ст. байт

      // Com16
	  unsigned long int Comm16=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 4\"","0"));      // считать из файла в массив
	  Com16[3]=Comm16&0xFF;                    // мл. байт
      Com16[2]=(Comm16/256)&0xFF;              // ср. байт
	  Com16[1]=(Comm16/65536)&0xFF;            // ст. байт

      // Com17
	  unsigned long int Comm17=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 5\"","0"));      // считать из файла в массив
      Com17[3]=Comm17&0xFF;                    // мл. байт
      Com17[2]=(Comm17/256)&0xFF;              // ср. байт
	  Com17[1]=(Comm17/65536)&0xFF;            // ст. байт

      // Com18
	  unsigned long int Comm18=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 6\"","0"));      // считать из файла в массив
      Com18[3]=Comm18&0xFF;                    // мл. байт
      Com18[2]=(Comm18/256)&0xFF;              // ср. байт
	  Com18[1]=(Comm18/65536)&0xFF;            // ст. байт

      // Com19
	  unsigned long int Comm19=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 7\"","0"));      // считать из файла в массив
      Com19[3]=Comm19&0xFF;                    // мл. байт
      Com19[2]=(Comm19/256)&0xFF;              // ср. байт
	  Com19[1]=(Comm19/65536)&0xFF;            // ст. байт

      // Com20
      unsigned long int Comm20=StrToInt(Ini->ReadString("Данные в режиме Тестирование","Команда \"Рабочие регистры синтезатора платы ППРМ-2. Пакет 8\"","0"));      // считать из файла в массив
      Com20[3]=Comm20&0xFF;                    // мл. байт
      Com20[2]=(Comm20/256)&0xFF;              // ср. байт
	  Com20[1]=(Comm20/65536)&0xFF;            // ст. байт

      UpdateAllRegisters();

      AddSaveLog("Загружен файл "+FileTesting);  // добавить комментарий и сохранить лог

      delete Ini;
	}
	else
	{
	  ShowError(FileNotExist, 0, 0, "");
	}
  }

  StatusBar1->SimpleText=File; // вывод в строку состояния
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateAllRegisters(void)  // обновление значения Register 0...5
{
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
void __fastcall TMainForm::B_ReadyClick(TObject *Sender)
{
  AddSaveLog("Подготовить команды");  // добавить комментарий и сохранить лог

  if(f>=900&&f<=10000)         // если диапазон правильный
  {
	if(f>=900&&f<=1700)
	{
	  CB_FreqRange->ItemIndex=0;
	  Command6[3]=0;           // записать значение младшего байта центральной частоты рабочей полосы
	  range=D1;
	  heterodyne=ht1;
	  Ip27BDmin=Ip27BDminD12;
	  Ip27BDmax=Ip27BDmaxD12;
	}
	else
	if(f>=4900&&f<=5700)
	{
	  CB_FreqRange->ItemIndex=1;
	  Command6[3]=1;           // записать значение младшего байта центральной частоты рабочей полосы
	  range=D2;
	  heterodyne=ht1;
	  Ip27BDmin=Ip27BDminD12;
	  Ip27BDmax=Ip27BDmaxD12;
	}
	else
	if(f>=7100&&f<=8500)
	{
	  CB_FreqRange->ItemIndex=2;
	  Command6[3]=2;           // записать значение младшего байта центральной частоты рабочей полосы
	  range=D3;
	  heterodyne=ht2;
	  Ip27BDmin=Ip27BDminD34;
	  Ip27BDmax=Ip27BDmaxD34;
	}
	else
	if(f>=9200&&f<=10000)
	{
	  CB_FreqRange->ItemIndex=3;
	  Command6[3]=3;           // записать значение младшего байта центральной частоты рабочей полосы
	  range=D4;
	  heterodyne=ht3;
	  Ip27BDmin=Ip27BDminD34;
	  Ip27BDmax=Ip27BDmaxD34;
	}
	else
	  Application->MessageBox(L"Введено неправильное значение центральной частоты!",L"Внимание",MB_ICONWARNING);
  }
  else
	Application->MessageBox(L"Значение центральной частоты вне допустимого диапазона!",L"Внимание",MB_ICONWARNING);

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
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::E_Command5KeyPress(TObject *Sender, wchar_t &Key)
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
bool __fastcall TMainForm::DigitalLineWrite(int LineNumber, int DValue)
// LineNumber - line number for DO, DValue - value to write
{
   int    Error             = 0;
   char   FirstDevice[260];       // 260 characters for 845x resource name
   uInt8  DioPort           = 0;  // port for the line
   int    ch;
   char   CharBuff[10];
   char   ErrorMsg[1024];

   LineDirectionMap |= (0x1 << LineNumber);

   /* find first device */
   errChk (ni845xFindDevice (FirstDevice, NULL , NULL));

   /* open device handle */
   errChk (ni845xOpen (FirstDevice, &DeviceHandle));

   /* Set the I/O Voltage Level */
   errChk (ni845xSetIoVoltageLevel (DeviceHandle, kNi845x33Volts));

   /* Set the DIO Driver Type */
   errChk (ni845xDioSetDriverType (DeviceHandle, DioPort, kNi845xPushPull));

   /* Set the Line Direction Map */
   errChk (ni845xDioSetPortLineDirectionMap (DeviceHandle, DioPort, LineDirectionMap));

   /* Write the Digital Line */
   errChk (ni845xDioWriteLine(DeviceHandle, DioPort, LineNumber, DValue));

   // Close the device handle
   errChk (ni845xClose (DeviceHandle));

   DeviceHandle = 0;

   return 1;

Error:
   if (Error < 0)
   {
	 try
	 {
	   /*
	   ni845xStatusToString(Error, 1024, ErrorMsg);

	   wchar_t* WErrorMsg;
	   swprintf(WErrorMsg, L"%S", ErrorMsg); // char* -> wchar_t*
	   Application->MessageBox(WErrorMsg,L"Ошибка работы устройства сбора данных блока БС!",MB_ICONWARNING);
	   */
	   ni845xClose (DeviceHandle);
	 }

	 catch(...)
	 {
	   Application->MessageBox(L"Ошибка доступа к блоку БС!",L"Внимание",MB_ICONWARNING);
	   MainForm->SetFocus();
	   //exit(1);
	 }
   }

   return 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClearDevs(void) // очистка портов NI USB-6008
{
  int i;

  for(i=0;i<8;i++)
  {
	Dev1P0[i]=0;
	Dev2P0[i]=0;
	Dev3P0[i]=0;
	Dev4P0[i]=0;
	Dev5P0[i]=0;
	Dev6P0[i]=0;
  }

  for(i=0;i<4;i++)
  {
	Dev1P1[i]=0;
	Dev2P1[i]=0;
	Dev3P1[i]=0;
	Dev4P1[i]=0;
	Dev5P1[i]=0;
	Dev6P1[i]=0;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DevToP0P1(int dv)
// запись значений портов NI USB-6008 в буфер обмена
{
  int i;

  if(dv==dv1)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev1P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev1P1[i];
	}
  }
  else
  if(dv==dv2)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev2P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev2P1[i];
	}
  }
  else
  if(dv==dv3)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev3P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev3P1[i];
	}
  }
  else
  if(dv==dv4)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev4P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev4P1[i];
	}
  }
  else
  if(dv==dv5)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev5P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev5P1[i];
	}
  }
  else
  if(dv==dv6)
  {
	for(i=0;i<8;i++)
	{
	  P0[i]=Dev6P0[i];
	}

	for(i=0;i<4;i++)
	{
	  P1[i]=Dev6P1[i];
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetDev_port(int dv)
// установка буферов Dev_portN из портов DevX_portN устройства device
{
  if(dv==dv1)
  {
	Dev_port0 = Dev1_port0;
	Dev_port1 = Dev1_port1;
  }
  else
  if(dv==dv2)
  {
	Dev_port0 = Dev2_port0;
	Dev_port1 = Dev2_port1;
  }
  else
  if(dv==dv3)
  {
	Dev_port0 = Dev3_port0;
	Dev_port1 = Dev3_port1;
  }
  else
  if(dv==dv4)
  {
	Dev_port0 = Dev4_port0;
	Dev_port1 = Dev4_port1;
  }
  else
  if(dv==dv5)
  {
	Dev_port0 = Dev5_port0;
	Dev_port1 = Dev5_port1;
  }
  else
  if(dv==dv6)
  {
	Dev_port0 = Dev6_port0;
	Dev_port1 = Dev6_port1;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetDev_ai(int dv)
// установка буферов Dev_aiN из портов DevX_aiN устройства device
{
  if(dv==dv1)
  {
	Dev_ai0 = Dev1_ai0;
	Dev_ai1 = Dev1_ai1;
	Dev_ai2 = Dev1_ai2;
	Dev_ai3 = Dev1_ai3;
	Dev_ai4 = Dev1_ai4;
	Dev_ai5 = Dev1_ai5;
	Dev_ai6 = Dev1_ai6;
  }
  else
  if(dv==dv2)
  {
	Dev_ai0 = Dev2_ai0;
	Dev_ai1 = Dev2_ai1;
	Dev_ai2 = Dev2_ai2;
	Dev_ai3 = Dev2_ai3;
	Dev_ai4 = Dev2_ai4;
	Dev_ai5 = Dev2_ai5;
	Dev_ai6 = Dev2_ai6;
  }
  else
  if(dv==dv3)
  {
	Dev_ai0 = Dev3_ai0;
	Dev_ai1 = Dev3_ai1;
	Dev_ai2 = Dev3_ai2;
	Dev_ai3 = Dev3_ai3;
	Dev_ai4 = Dev3_ai4;
	Dev_ai5 = Dev3_ai5;
	Dev_ai6 = Dev3_ai6;
  }
  else
  if(dv==dv4)
  {
	Dev_ai0 = Dev4_ai0;
	Dev_ai1 = Dev4_ai1;
	Dev_ai2 = Dev4_ai2;
	Dev_ai3 = Dev4_ai3;
	Dev_ai4 = Dev4_ai4;
	Dev_ai5 = Dev4_ai5;
	Dev_ai6 = Dev4_ai6;
  }
  else
  if(dv==dv5)
  {
	Dev_ai0 = Dev5_ai0;
	Dev_ai1 = Dev5_ai1;
	Dev_ai2 = Dev5_ai2;
	Dev_ai3 = Dev5_ai3;
	Dev_ai4 = Dev5_ai4;
	Dev_ai5 = Dev5_ai5;
	Dev_ai6 = Dev5_ai6;
  }
  else
  if(dv==dv6)
  {
	Dev_ai0 = Dev6_ai0;
	Dev_ai1 = Dev6_ai1;
	Dev_ai2 = Dev6_ai2;
	Dev_ai3 = Dev6_ai3;
	Dev_ai4 = Dev6_ai4;
	Dev_ai5 = Dev6_ai5;
	Dev_ai6 = Dev6_ai6;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetDevPN(int dv, unsigned char* Dev, int i)
// установка портов DevXPN устройства device из буферов DevPN
{
  if(dv==dv1)
  {
	if(Dev==DevP0) Dev1P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev1P1[i]=DevP1[i];
  }
  else
  if(dv==dv2)
  {
	if(Dev==DevP0) Dev2P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev2P1[i]=DevP1[i];
  }
  else
  if(dv==dv3)
  {
	if(Dev==DevP0) Dev3P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev3P1[i]=DevP1[i];
  }
  else
  if(dv==dv4)
  {
	if(Dev==DevP0) Dev4P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev4P1[i]=DevP1[i];
  }
  else
  if(dv==dv5)
  {
	if(Dev==DevP0) Dev5P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev5P1[i]=DevP1[i];
  }
  else
  if(dv==dv6)
  {
	if(Dev==DevP0) Dev6P0[i]=DevP0[i];
	else
	if(Dev==DevP1) Dev6P1[i]=DevP1[i];
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AlgorithmBS(void)  // Тестирование блока БС
{
/*
  1) Перед началом измерения напряжений питания необходимо включить питание
  синтезаторов частоты основного и резервного каналов. Для этого на выводах P0.1
  и P0.3 NI8451 установить логическую «1» («1» должна быть установлена перед
  началом процесса самотестирования или в режиме управления вплоть до момента
  окончания работы всего изделия).

  P0.1 - запись команды "Включить питание синтезатора основного канала", 0 – выключено, 1 – включено
  P0.3 - запись команды "Включить питание синтезатора резервного канала", 0 – выключено, 1 – включено
*/
  try
  {
	if(!DigitalLineWrite(0, 1)) throw 1;
	if(!DigitalLineWrite(3, 1)) throw 2;
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок БС!",L"Внимание",MB_ICONWARNING);
	 MainForm->SetFocus();
	 //exit(1);
  }
/*
  2) Измерить напряжение питания Uпит.+5В, считав аналоговое напряжение на выводе AI6 NI6008.

  AI6 - чтение значения напряжения питания +5В [В]
*/



}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec1Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec1->Enabled=false;

  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[2]=1;                            // 1->DevP0[2]

  SetDevPN(VIP, DevP0, 2);               // if VIP DevP0[2]->Dev1P0[2]
  DevToP0P1(VIP);                        // if VIP Dev1PX[2]->Px[2]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP
	 T_Sec2->Enabled=true;                               // задержка 1 с
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec2Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec2->Enabled=false;

  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[0]=1;                            // 1->DevP0[0]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                        // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP
	 T_mSec1->Enabled=true;                              // задержка 200 мс
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_mSec1Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_mSec1->Enabled=false;

  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[0]=0;                            // 0->DevP0[0]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                        // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP
	 SB_OnOff->Enabled=true;
	 //P_OneSec->Visible=false;
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_FreqRangeChange(TObject *Sender)
{
/*
В блоке ВК-ПРД в зависимости от выбранного частотного диапазона ток
потребления будет изменяться (т. к. включаются разные усилители СВЧ). Если
выбран частотный диапазон Д1 или Д2 то ток потребления имеет значение 500 мА,
если выбран частотный диапазон Д3 или Д4 то ток потребления имеет значение 3 А.
*/
  if(CB_FreqRange->ItemIndex==0)
  {
	Command6[3]=0;           // записать значение младшего байта центральной частоты рабочей полосы
	range=D1;
	heterodyne=0;
	Ip27BDmin=Ip27BDminD12;
	Ip27BDmax=Ip27BDmaxD12;
  }
  else
  if(CB_FreqRange->ItemIndex==1)
  {
	Command6[3]=1;           // записать значение младшего байта центральной частоты рабочей полосы
	range=D2;
	heterodyne=ht1;
	Ip27BDmin=Ip27BDminD12;
	Ip27BDmax=Ip27BDmaxD12;
  }
  else
  if(CB_FreqRange->ItemIndex==2)
  {
	Command6[3]=2;           // записать значение младшего байта центральной частоты рабочей полосы
	range=D3;
	heterodyne=ht2;
	Ip27BDmin=Ip27BDminD34;
	Ip27BDmax=Ip27BDmaxD34;
  }
  else
  if(CB_FreqRange->ItemIndex==3)
  {
	Command6[3]=3;           // записать значение младшего байта центральной частоты рабочей полосы
	range=D4;
	heterodyne=ht3;
	Ip27BDmin=Ip27BDminD34;
	Ip27BDmax=Ip27BDmaxD34;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_FreqRangeExit(TObject *Sender)
{
  if(CB_FreqRange->ItemIndex==0)
  {
	range=D1;
	heterodyne=ht1;
  }
  else
  if(CB_FreqRange->ItemIndex==1)
  {
	range=D2;
	heterodyne=ht1;
  }
  else
  if(CB_FreqRange->ItemIndex==2)
  {
	range=D3;
	heterodyne=ht2;
  }
  else
  if(CB_FreqRange->ItemIndex==3)
  {
	range=D4;
	heterodyne=ht3;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StartControl(void)
{
/*
В интерфейсе программы выбрать частотный диапазон, режим работы и затухание
аттенюаторов блоков ПРМ и ПРД. По умолчанию выставить частотный диапазон Д1,
режим работы «Когерентная помеха», затухание аттенюаторов 0дБ.
*/
  //int PRM=dv1;
  //M_Debug->Lines->Add(PRM);

  try
  {
	if(!PRMatt())   throw 3;

	if(!PRDatt())   throw 3;

	if(Range()==0)  throw 3;
	else
	if(Range()==-1) throw 4;
  }

  catch(int i)
  {
	if(i==3)
	  Application->MessageBox(L"Ошибка записи в блок ПРМ!",L"Внимание",MB_ICONWARNING);
	else
	if(i==4)
	  Application->MessageBox(L"Ошибка записи в блок ПРД!",L"Внимание",MB_ICONWARNING);
    //exit(1);
  }
/*
3.2	Основной алгоритм.

При нажатии кнопки ВКЛЮЧИТЬ в интерфейсе программы, в зависимости от выбранного
частотного диапазона выставить соответствующие значения частоты гетеродина в
блоке синтезатора (блок БС).
*/
  SetFreqSPI();  // Режим «Работа» блока БС
  SetFRLP();     // Режим «Работа» блока ФРЛП
/*
Далее производится проверка токов потребления и напряжений всех восьми блоков
устройства А-О. Если токи потребления имеют отклонение от номинального значения,
выдается информационное сообщение «Блок [название блока] не включен или неисправен».
*/
  NIDAQmxTimer->Enabled=true;
  VIPWorkON();   // Режим «Работа Вкл» блока ВИП
/*
После проверки токов потребления (если токи в норме) включить единичные
индикаторы Включения блоков. Для блока ВК-ПРД включение индикаторов в
зависимости от выбранного частотного диапазона. Если выбран частотный диапазон
Д1 или Д2 включить индикатор «Д1 Д2 ВК-ПРД». Если выбран частотный диапазон Д3
или Д4 включить индикатор «Д3 Д4 ВК-ПРД».
Далее если выбран частотный диапазон Д3 или Д4 необходимо включить
дополнительный усилитель в блоке ВК-ПРД для чего:
 - Установить сигнал «Вкл. Минус 9В» в лог. 1 *(на NI6008 в блоке ВИП);
 - Через время около 1с передать сигнал «запомнить» длительностью 20мс *(на
NI6008 в блоке ВИП) (200 мс);
 - Установить сигнал «Вкл. +24В» в лог. 1 *(на NI6008 в блоке ВИП);
 - Через время около 1с передать сигнал «запомнить» длительностью 20мс *(на
NI6008 в блоке ВИП) (200 мс).
*/
  //if(range==D3||range==D4) Prestart(); // Предпусковые операции
/*
Дополнительный усилитель включен и готов к работе. Включение дополнительного
усилителя приведет к увеличению тока потребления блоком ВК-ПРД. Если ток
потребления номинальный, то включить единичный индикатор «Д3 Д4 ВК-ПРД».
*/
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetPRMchan(unsigned char* Dev, int i)
// установить канал ПРМ
{
  //int PRM=dv1;

  SetDevPN(PRM, Dev, i);                               // if PRM DevP0[]->Dev1P0[]
  DevToP0P1(PRM);                                      // if PRM Dev1PX[]->Px[]

  SetDev_port(PRM);                                    // if PRM Dev1_portX->Dev_portX
  if(!SetDevP0P1Data(Dev_port0, Dev_port1)) return 0;  // запись цифровых портов PRM
  else                                      return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetPRMatt(int a, int b, int c, int d, int e)
// установить порт ПРМ
{
  DevP0[0]=a;                            // 1->DevP0[0]
  if(!SetPRMchan(DevP0, 0)) return 0;    // установить канал ПРМ

  DevP0[1]=b;                            // 1->DevP0[1]
  if(!SetPRMchan(DevP0, 1)) return 0;    // установить канал ПРМ

  DevP0[2]=c;                            // 1->DevP0[2]
  if(!SetPRMchan(DevP0, 2)) return 0;    // установить канал ПРМ

  DevP0[3]=d;                            // 1->DevP0[3]
  if(!SetPRMchan(DevP0, 3)) return 0;    // установить канал ПРМ

  DevP0[4]=e;                            // 1->DevP0[4]
  if(!SetPRMchan(DevP0, 4)) return 0;    // установить канал ПРМ

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetPRDatt(int a, int b, int c, int d, int e)
// установить порт ПРД
{
  DevP0[0]=a;                            // 1->DevP0[0]
  if(!SetPRDchan(DevP0, 0)) return 0;    // установить канал ПРД

  DevP0[1]=b;                            // 1->DevP0[1]
  if(!SetPRDchan(DevP0, 1)) return 0;    // установить канал ПРД

  DevP0[2]=c;                            // 1->DevP0[2]
  if(!SetPRDchan(DevP0, 2)) return 0;    // установить канал ПРД

  DevP0[3]=d;                            // 1->DevP0[3]
  if(!SetPRDchan(DevP0, 3)) return 0;    // установить канал ПРД

  DevP0[4]=e;                            // 1->DevP0[4]
  if(!SetPRDchan(DevP0, 4)) return 0;    // установить канал ПРД

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetPRDchan(unsigned char* Dev, int i)
// установить канал ПРД
{
  SetDevPN(PRD, Dev, i);                               // if PRM DevP0[]->Dev1P0[]
  DevToP0P1(PRD);                                      // if PRM Dev1PX[]->Px[]

  SetDev_port(PRD);                                    // if PRM Dev1_portX->Dev_portX
  if(!SetDevP0P1Data(Dev_port0, Dev_port1)) return 0;  // запись цифровых портов PRM
  else                                      return 1;
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::SetRange(int a, int b, int c, int d, int e)
// установить порт ПРМ и ПРД
{
  DevP0[5]=a;                            // 1->DevP0[5]
  if(!SetPRMchan(DevP0, 5)) return 0;    // установить канал ПРМ
  if(!SetPRDchan(DevP0, 5)) return -1;   // установить канал ПРД

  DevP0[6]=b;                            // 1->DevP0[6]
  if(!SetPRMchan(DevP0, 6)) return 0;    // установить канал ПРМ
  if(!SetPRDchan(DevP0, 6)) return -1;   // установить канал ПРД

  DevP0[7]=c;                            // 1->DevP0[7]
  if(!SetPRMchan(DevP0, 7)) return 0;    // установить канал ПРМ
  if(!SetPRDchan(DevP0, 7)) return -1;   // установить канал ПРД

  DevP1[0]=d;                            // 1->DevP1[0]
  if(!SetPRMchan(DevP1, 0)) return 0;    // установить канал ПРМ
  if(!SetPRDchan(DevP1, 0)) return -1;   // установить канал ПРД

  DevP1[1]=e;                            // 1->DevP1[1]
  if(!SetPRMchan(DevP1, 1)) return 0;    // установить канал ПРМ
  if(!SetPRDchan(DevP1, 1)) return -1;   // установить канал ПРД

  return 1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NIDAQmxTimerTimer(TObject *Sender)
{
  GoNIDAQmx();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GoNIDAQmx()
{
  float value;
  float min,max;
  NIDAQmxCounter++;
  //int PRM=dv1;
  //int VIP=dv1;
  //int UU=dv1;
  //int BS=dv1;
  //int FRLP=dv1;

  switch(NIDAQmxCounter)
  {

	// ПРМ
	case 0:                                    // Напряжение питания источника +5 В приёмника [В]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai0);            // Считываем AI0 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up5B->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_1->Color=BadColor;
		 P_Up5B->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
         P_1->Color=GoodColor;
		 P_Up5B->Color=GoodColor;
      }

      break;

	case 1:                                    // Напряжение питания источника +12 В приёмника [В]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai1);            // Считываем AI1 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up12B->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_2->Color=BadColor;
		 P_Up12B->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
      {
         P_2->Color=GoodColor;
         P_Up12B->Color=GoodColor;
      }

      break;

    case 2:                                    // Мощность сигнала приёмника [дБм]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai2);            // Считываем AI2 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Pprm->Caption=FloatToStrF(value,ffFixed,5,2)+" дБм"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_3->Color=BadColor;
		 P_Pprm->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
      {
         P_3->Color=GoodColor;
		 P_Pprm->Color=GoodColor;
      }

	  break;

	case 3:                                    // Напряжение питания источника -5 В приёмника [В]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai4);            // Считываем AI4 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Um5B->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_4->Color=BadColor;
		 P_Um5B->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
      {
         P_4->Color=GoodColor;
         P_Um5B->Color=GoodColor;
      }

      break;

	case 4:                                    // Ток питания источника +27 В приёмника [А]
	  value=0;
	  SetDev_ai(PRM);
	  value=GetDevACDData(Dev_ai5);            // Считываем AI5 от NI USB-6008

      if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Ip27B->Caption=FloatToStrF(value,ffFixed,5,2)+" А"; // 2 десятичных знака после запятой

      if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
         P_5->Color=BadColor;
		 P_Ip27B->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
      {
         P_5->Color=GoodColor;
         P_Ip27B->Color=GoodColor;
	  }

	  break;

	// ПРД
	case 5:                                    // Напряжение питания источника +5 В приёмника [В]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai0);            // Считываем AI0 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up5BD->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_1D->Color=BadColor;
		 P_Up5BD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_1D->Color=GoodColor;
		 P_Up5BD->Color=GoodColor;
      }

      break;

	case 6:                                    // Напряжение питания источника +12 В приёмника [В]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai1);            // Считываем AI1 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up12BD->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
		 P_2D->Color=BadColor;
		 P_Up12BD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
	  {
		 P_2D->Color=GoodColor;
		 P_Up12BD->Color=GoodColor;
	  }

      break;

	case 7:                                    // Мощность сигнала приёмника [дБм]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai2);            // Считываем AI2 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_PprmD->Caption=FloatToStrF(value,ffFixed,5,2)+" дБм"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
		 P_3D->Color=BadColor;
		 P_PprmD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
	  {
		 P_3D->Color=GoodColor;
		 P_PprmD->Color=GoodColor;
	  }

	  break;

	case 8:                                    // Напряжение питания источника -5 В приёмника [В]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai4);            // Считываем AI4 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Um5BD->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
		 P_4D->Color=BadColor;
		 P_Um5BD->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
	  {
		 P_4D->Color=GoodColor;
		 P_Um5BD->Color=GoodColor;
	  }

	  break;

	case 9:                                    // Ток питания источника +27 В приёмника [А]
	  value=0;
	  SetDev_ai(PRD);
	  value=GetDevACDData(Dev_ai5);            // Считываем AI5 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=Ip27BDmin;                           // граничные значения напряжения
	  max=Ip27BDmax;

	  P_Ip27BD->Caption=FloatToStrF(value,ffFixed,5,2)+" А"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		P_5D->Color=BadColor;
		P_Ip27BD->Color=BadColor;
		NIDAQmxTimer->Enabled=false;
/*
		if(Ip27BDmin==Ip27BDminD34&&Ip27BDmax==Ip27BDminD34)
		{
/*
Если ток потребления отличается от номинального значения   необходимо выключить
дополнительный усилитель в блоке ВК- ПРД для чего:
 - Установить сигнал «Вкл. Минус 9В» в лог. 0 *(на NI6008 в блоке ВИП);
 - Установить сигнал «Вкл. +24В» в лог. 0 *(на NI6008 в блоке ВИП);
 - Через время около 1с передать сигнал «запомнить» длительностью 20мс *(на
NI6008 в блоке ВИП) (200 мс);
- Выдать информационное сообщение «Усилитель МИП в блоке ВК-ПРД неисправен»;
Единичный индикатор «Д3 Д4 ВК- ПРД» не включать.
Дополнительный усилитель выключен.

  P0.0 - запись команды "Запомнить для ВК-ПРД"
  P0.1 - запись команды "Включить -9 В на ВК-ПРД"
  P0.2 - запись команды "Включить +24 В на ВК-ПРД"
*/
		  //int VIP=dv1;
		  //M_Debug->Lines->Add(VIP);
/*
		  DevP0[1]=0;                                           // 0->DevP0[1]

		  SetDevPN(VIP, DevP0, 1);                              // if VIP DevP0[1]->Dev1P0[1]
		  DevToP0P1(VIP);                                       // if VIP Dev1PX[1]->Px[1]

		  SetDev_port(VIP);                                     // if VIP Dev1_portX->Dev_portX
		  try
		  {
			if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP

			DevP0[2]=0;                                         // 0->DevP0[2]

			SetDevPN(VIP, DevP0, 2);                            // if VIP DevP0[2]->Dev1P0[2]
			DevToP0P1(VIP);                                     // if VIP Dev1PX[2]->Px[2]

			SetDev_port(VIP);                                   // if VIP Dev1_portX->Dev_portX
            if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 4;  // запись цифровых портов VIP

		   	T_Sec3->Enabled=true;                               // задержка 1 с
		  }

		  catch(...)
		  {
			Application->MessageBox(L"Усилитель МИП в блоке ВК-ПРД неисправен!",L"Внимание",MB_ICONWARNING);
			SB_OnOff->Enabled=false;
		  }
		}
*/
	  }
	  else                                     // значение в нужных пределах
	  {
		P_5D->Color=GoodColor;
		P_Ip27BD->Color=GoodColor;
	  }

	  break;

	// ВИП
	case 10:                                   // Напряжение питания источника +12 В [В]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai0);            // Считываем AI0 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up12BV->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_1V->Color=BadColor;
		 P_Up12BV->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_1V->Color=GoodColor;
		 P_Up12BV->Color=GoodColor;
	  }

	  break;

	case 11:                                   // Напряжение питания источника +27 В [В]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai1);            // Считываем AI1 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up27BV->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_2V->Color=BadColor;
		 P_Up27BV->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // значение в нужных пределах
	  {
		 P_2V->Color=GoodColor;
		 P_Up27BV->Color=GoodColor;
	  }

	  break;

	case 12:                                   // Ток выносного передатчика [А]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai2);            // Считываем AI2 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Ivprd->Caption=FloatToStrF(value,ffFixed,5,2)+" А"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_3V->Color=BadColor;
		 P_Ivprd->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // значение в нужных пределах
	  {
		 P_3V->Color=GoodColor;
		 P_Ivprd->Color=GoodColor;
	  }

	  break;

	case 13:                                   // Напряжение питания ВК-ПРД [В]
	  SetDev_ai(VIP);
	  ValuePRD=GetDevACDData(Dev_ai3);         // Считываем AI3 от NI USB-6008

	  if((ValuePRD>1e10)||(ValuePRD<-1e10)) ValuePRD=0;        // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                 // граничные значения напряжения
	  max=10;

	  P_Uvkprd->Caption=FloatToStrF(ValuePRD,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((ValuePRD>max)||(ValuePRD<min)||(ErrorADC))           // выход значения за границы
	  {
		 P_6V->Color=BadColor;
		 P_Uvkprd->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_6V->Color=GoodColor;
		 P_Uvkprd->Color=GoodColor;

		 if(FPRD)
		 {
/*
		   4)	Считать с аналогового вывода AI3 напряжение. Если считанное значение
		   попадает в диапазон «5±0,5В» то убираем информационное сообщение из п.2
		   и переходим к п.4. Иначе программа должна перейти в режим опроса
		   сигнала включения тумблера ВК ПРД.
*/
		   if((ValuePRD<4.5)||(ValuePRD>5.5));
		   else
		   if((ValuePRD>4.5)||(ValuePRD<5.5))
		   {
			 F_Tumbler->Close();
			 FPRDON=true;
		   }
		   //M_Debug->Lines->Add(ValuePRD);
		 }
		 else
		 if(!FPRD)
		 {
/*
		   6)	Считать с аналогового вывода AI3 напряжение. Если считанное значение
		   попадает в диапазон «0±0,5В» то убираем информационное сообщение из п.
		   Иначе программа встать в режим ожидания выключения тумблера.
*/
		   if((ValuePRD>0.5)||(ValuePRD<-0.5));
		   else
		   if((ValuePRD<0.5)||(ValuePRD>-0.5))
		   {
			 F_Tumbler2->Close();
		   }
		   //M_Debug->Lines->Add(int(FPRD));
         }
	  }

	  break;

	case 14:                                   // Напряжение питания источника +5 В [В]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai4);            // Считываем AI4 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up5BV->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_4V->Color=BadColor;
		 P_Up5BV->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_4V->Color=GoodColor;
		 P_Up5BV->Color=GoodColor;
	  }

	  break;

	case 15:                                   // Ток выносного приёмника [А]
	  value=0;
	  SetDev_ai(VIP);
	  value=GetDevACDData(Dev_ai5);            // Считываем AI5 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Ivprm->Caption=FloatToStrF(value,ffFixed,5,2)+" А"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_5V->Color=BadColor;
		 P_Ivprm->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_5V->Color=GoodColor;
		 P_Ivprm->Color=GoodColor;
	  }

	  break;

	// УУ
	case 16:                                   // Напряжение питания источника +5 В [В]
	  value=0;
	  SetDev_ai(UU);
	  value=GetDevACDData(Dev_ai0);            // Считываем AI0 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up5BU->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_1U->Color=BadColor;
		 P_Up5BU->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_1U->Color=GoodColor;
		 P_Up5BU->Color=GoodColor;
      }

      break;

	case 17:                                   // Выходное напряжение датчика тока [А]
	  value=0;
	  SetDev_ai(UU);
	  value=GetDevACDData(Dev_ai1);            // Считываем AI1 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_I->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
		 P_2U->Color=BadColor;
		 P_I->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
	  {
		 P_2U->Color=GoodColor;
		 P_I->Color=GoodColor;
	  }

      break;

	case 18:                                   // Напряжение питания источника +12 В [В]
	  value=0;
	  SetDev_ai(UU);
	  value=GetDevACDData(Dev_ai4);            // Считываем AI4 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up12BU->Caption=FloatToStrF(value,ffFixed,5,2)+" А"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
      {
		 P_3U->Color=BadColor;
		 P_Up12BU->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
      else                                     // значение в нужных пределах
	  {
		 P_3U->Color=GoodColor;
		 P_Up12BU->Color=GoodColor;
	  }

	  break;

	// БС
	case 19:                                   // Датчик температуры основного канала [град.]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai0);            // Считываем AI0 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_To->Caption=FloatToStrF(value,ffFixed,5,2)+" град."; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_1B->Color=BadColor;
		 P_To->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_1B->Color=GoodColor;
		 P_To->Color=GoodColor;
	  }

	  break;

	case 20:                                   // Датчик температуры резервного канала [град.]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai1);            // Считываем AI1 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Tr->Caption=FloatToStrF(value,ffFixed,5,2)+" град."; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_2B->Color=BadColor;
		 P_Tr->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // значение в нужных пределах
	  {
		 P_2B->Color=GoodColor;
		 P_Tr->Color=GoodColor;
	  }

	  break;

	case 21:                                   // Напряжение питания +5В [В]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai2);            // Считываем AI2 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Up5BB->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_3B->Color=BadColor;
		 P_Up5BB->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
      }
	  else                                     // значение в нужных пределах
	  {
		 P_3B->Color=GoodColor;
		 P_Up5BB->Color=GoodColor;
	  }

	  break;

	case 22:                                   // Ток потребления по +27В [А]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai3);            // Считываем AI3 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Ip27BB->Caption=FloatToStrF(value,ffFixed,5,2)+" А"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_4B->Color=BadColor;
		 P_Ip27BB->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_4B->Color=GoodColor;
		 P_Ip27BB->Color=GoodColor;
	  }

	  break;

	case 23:                                   // Мощность сигнала контрольного выхода основного канала [Вт]
	  SetDev_ai(BS);
	  ValuePo=GetDevACDData(Dev_ai4);          // Считываем AI4 от NI USB-6008

	  if((ValuePo>1e10)||(ValuePo<-1e10)) ValuePo=0;        // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                 // граничные значения напряжения
	  max=10;

	  P_Po->Caption=FloatToStrF(ValuePo,ffFixed,5,2)+" Вт"; // 2 десятичных знака после запятой

	  if((ValuePo>max)||(ValuePo<min)||(ErrorADC))          // выход значения за границы
	  {
		 P_5B->Color=BadColor;
		 P_Po->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_5B->Color=GoodColor;
		 P_Po->Color=GoodColor;
	  }

	  break;

	case 24:                                   // Мощность сигнала контрольного выхода резервного канала [Вт]
	  SetDev_ai(BS);
	  ValuePr=GetDevACDData(Dev_ai5);          // Считываем AI5 от NI USB-6008

	  if((ValuePr>1e10)||(ValuePr<-1e10)) ValuePr=0;        // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                 // граничные значения напряжения
	  max=10;

	  P_Pr->Caption=FloatToStrF(ValuePr,ffFixed,5,2)+" Вт"; // 2 десятичных знака после запятой

	  if((ValuePr>max)||(ValuePr<min)||(ErrorADC))          // выход значения за границы
	  {
		 P_6B->Color=BadColor;
		 P_Pr->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_6B->Color=GoodColor;
		 P_Pr->Color=GoodColor;
	  }

	  break;

	case 25:                                   // Напряжение питания -5В [В]
	  value=0;
	  SetDev_ai(BS);
	  value=GetDevACDData(Dev_ai6);            // Считываем AI6 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Um5BB->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_7B->Color=BadColor;
		 P_Um5BB->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_7B->Color=GoodColor;
		 P_Um5BB->Color=GoodColor;
	  }

	  break;

	// ФРЛП
	case 26:                                   // Напряжение питания УЦПС [В], при вкл. блока - 5 В (+4,85…+5,15 В)
	  value=0;
	  SetDev_ai(FRLP);
	  value=GetDevACDData(Dev_ai0);            // Считываем AI0 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Uucps->Caption=FloatToStrF(value,ffFixed,5,2)+" В"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_1F->Color=BadColor;
		 P_Uucps->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_1F->Color=GoodColor;
		 P_Uucps->Color=GoodColor;
	  }

	  break;

	case 27:                                   // Датчик температуры [град.]
	  value=0;
	  SetDev_ai(FRLP);
	  value=GetDevACDData(Dev_ai1);            // Считываем AI1 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_T->Caption=FloatToStrF(value,ffFixed,5,2)+" град."; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_2F->Color=BadColor;
		 P_T->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_2F->Color=GoodColor;
		 P_T->Color=GoodColor;
	  }

	  break;

	case 28:                                   // Ток потребления +27 В блока ФРЛП [А]
	  value=0;
	  SetDev_ai(FRLP);
	  value=GetDevACDData(Dev_ai4);            // Считываем AI4 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Ip27BF->Caption=FloatToStrF(value,ffFixed,5,2)+" А"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_3F->Color=BadColor;
		 P_Ip27BF->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_3F->Color=GoodColor;
		 P_Ip27BF->Color=GoodColor;
	  }

	  break;

	case 29:                                   // Напряжение аналогового выхода детектора [дБм]
	  value=0;
	  SetDev_ai(FRLP);
	  value=GetDevACDData(Dev_ai5);            // Считываем AI5 от NI USB-6008

	  if((value>1e10)||(value<-1e10)) value=0; // при отключениии NI USB-6008 от компьютера ошибки не будет
	  min=-10;                                // граничные значения напряжения
	  max=10;

	  P_Udet->Caption=FloatToStrF(value,ffFixed,5,2)+" дБм"; // 2 десятичных знака после запятой

	  if((value>max)||(value<min)||(ErrorADC)) // выход значения за границы
	  {
		 P_4F->Color=BadColor;
		 P_Udet->Color=BadColor;
		 NIDAQmxTimer->Enabled=false;
	  }
	  else                                     // значение в нужных пределах
	  {
		 P_4F->Color=GoodColor;
		 P_Udet->Color=GoodColor;
	  }

	  NIDAQmxCounter=-1;                       // начать отсчёт заново
	  break;

  }

  PanelColor();                                // цветовая индикация и вывод сообщений
/*
Если токи потребления блоков в норме и все данные переданы, то устройство А-О
включено и готово к работе. Во время работы устройства  А-О необходимо
контролировать токи потребления блоков входящих в состав устройства.
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DefaultPanel()
{
  // ПРМ
  P_PRM->Color=DefaultColor;
  P_1->Color=DefaultColor;
  P_2->Color=DefaultColor;
  P_3->Color=DefaultColor;
  P_4->Color=DefaultColor;
  P_5->Color=DefaultColor;

  P_Up5B->Color=DefaultColor;
  P_Up12B->Color=DefaultColor;
  P_Pprm->Color=DefaultColor;
  P_Um5B->Color=DefaultColor;
  P_Ip27B->Color=DefaultColor;

  P_Up5B->Caption="0 В";
  P_Up12B->Caption="0 В";
  P_Pprm->Caption="0 дБм";
  P_Um5B->Caption="0 В";
  P_Ip27B->Caption="0 А";

  // ПРД
  P_PRD->Color=DefaultColor;
  P_1D->Color=DefaultColor;
  P_2D->Color=DefaultColor;
  P_3D->Color=DefaultColor;
  P_4D->Color=DefaultColor;
  P_5D->Color=DefaultColor;

  P_Up5BD->Color=DefaultColor;
  P_Up12BD->Color=DefaultColor;
  P_PprmD->Color=DefaultColor;
  P_Um5BD->Color=DefaultColor;
  P_Ip27BD->Color=DefaultColor;

  P_Up5BD->Caption="0 В";
  P_Up12BD->Caption="0 В";
  P_PprmD->Caption="0 дБм";
  P_Um5BD->Caption="0 В";
  P_Ip27BD->Caption="0 А";

  // ВИП
  P_VK_PRD1->Color=DefaultColor;
  P_VK_PRD2->Color=DefaultColor;
  P_VK_PRM->Color=DefaultColor;
  P_1V->Color=DefaultColor;
  P_2V->Color=DefaultColor;
  P_3V->Color=DefaultColor;
  P_4V->Color=DefaultColor;
  P_5V->Color=DefaultColor;
  P_6V->Color=DefaultColor;

  P_Up12BV->Color=DefaultColor;
  P_Up27BV->Color=DefaultColor;
  P_Ivprd->Color=DefaultColor;
  P_Up5BV->Color=DefaultColor;
  P_Ivprm->Color=DefaultColor;
  P_Uvkprd->Color=DefaultColor;

  P_Up12BV->Caption="0 В";
  P_Up27BV->Caption="0 В";
  P_Ivprd->Caption="0 А";
  P_Up5BV->Caption="0 В";
  P_Ivprm->Caption="0 А";
  P_Uvkprd->Caption="0 В";

  // УУ
  P_UU->Color=DefaultColor;
  P_1U->Color=DefaultColor;
  P_2U->Color=DefaultColor;
  P_3U->Color=DefaultColor;

  P_Up5BU->Color=DefaultColor;
  P_I->Color=DefaultColor;
  P_Up12BU->Color=DefaultColor;

  P_Up5BU->Caption="0 В";
  P_I->Caption="0 В";
  P_Up12BU->Caption="0 А";

  // БС
  P_BS->Color=DefaultColor;
  P_Lock1->Color=DefaultColor;
  P_Lock2->Color=DefaultColor;
  P_1B->Color=DefaultColor;
  P_2B->Color=DefaultColor;
  P_3B->Color=DefaultColor;
  P_4B->Color=DefaultColor;
  P_5B->Color=DefaultColor;
  P_6B->Color=DefaultColor;
  P_7B->Color=DefaultColor;

  P_To->Color=DefaultColor;
  P_Tr->Color=DefaultColor;
  P_Um5BB->Color=DefaultColor;
  P_Ip27BB->Color=DefaultColor;
  P_Po->Color=DefaultColor;
  P_Pr->Color=DefaultColor;
  P_Up5BB->Color=DefaultColor;

  P_To->Caption="0 град.";
  P_Tr->Caption="0 град.";
  P_Um5BB->Caption="0 В";
  P_Ip27BB->Caption="0 А";
  P_Po->Caption="0 Вт";
  P_Pr->Caption="0 Вт";
  P_Up5BB->Caption="0 В";

  // ФРЛП
  P_FRLP->Color=DefaultColor;
  P_1F->Color=DefaultColor;
  P_2F->Color=DefaultColor;
  P_3F->Color=DefaultColor;
  P_4F->Color=DefaultColor;

  P_Uucps->Color=DefaultColor;
  P_T->Color=DefaultColor;
  P_Ip27BF->Color=DefaultColor;
  P_Udet->Color=DefaultColor;

  P_Uucps->Caption="0 В";
  P_T->Caption="0 град.";
  P_Ip27BF->Caption="0 А";
  P_Udet->Caption="0 дБм";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PanelColor()
{
  // ПРМ
  if(P_1->Color==GoodColor&&P_2->Color==GoodColor&&P_3->Color==GoodColor&&P_4->Color==GoodColor&&P_5->Color==GoodColor)
  {
	P_PRM->Color=GoodColor;
  }
  else
  {
	P_PRM->Color=BadColor;
  }

  if(P_1->Color==BadColor||P_2->Color==BadColor||P_3->Color==BadColor||P_4->Color==BadColor||P_5->Color==BadColor)
  {
	Application->MessageBox(L"Блок ПРМ не включен или неисправен!",L"Внимание",MB_ICONWARNING);
  }

  // ПРД
  if(P_1D->Color==GoodColor&&P_2D->Color==GoodColor&&P_3D->Color==GoodColor&&P_4D->Color==GoodColor&&P_5D->Color==GoodColor)
  {
	P_PRD->Color=GoodColor;
  }
  else
  {
	P_PRD->Color=BadColor;
  }

  if(P_1D->Color==BadColor||P_2D->Color==BadColor||P_3D->Color==BadColor||P_4D->Color==BadColor||P_5D->Color==BadColor)
  {
	Application->MessageBox(L"Блок ПРД не включен или неисправен!",L"Внимание",MB_ICONWARNING);
  }

  // ВИП
  // ВК-ПРД
  if(range==D1||range==D2)
  {
	if(P_3V->Color==GoodColor)
	{
	  P_VK_PRD1->Color=GoodColor;
	}
	else
	{
	  P_VK_PRD1->Color=BadColor;
	}
  }
  else
  if(range==D3||range==D4)
  {
	if(P_3V->Color==GoodColor)
	{
	  P_VK_PRD2->Color=GoodColor;
	}
	else
	{
	  P_VK_PRD2->Color=BadColor;
	}
  }

  if(P_3V->Color==BadColor)
  {
	Application->MessageBox(L"Блок ВК-ПРД не включен или неисправен!",L"Внимание",MB_ICONWARNING);
  }


  // ВК-ПРМ
  if(P_5V->Color==GoodColor)
  {
	P_VK_PRM->Color=GoodColor;
  }
  else
  if(P_5V->Color==BadColor)
  {
	P_VK_PRM->Color=BadColor;
	Application->MessageBox(L"Блок ВК-ПРМ не включен или неисправен!",L"Внимание",MB_ICONWARNING);
  }

  // остальное
  if(P_1V->Color==BadColor||P_2V->Color==BadColor||P_3V->Color==BadColor)
  {
	Application->MessageBox(L"Блок ВИП не включен или неисправен!",L"Внимание",MB_ICONWARNING);
  }

  // УУ
  if(P_1U->Color==GoodColor&&P_2U->Color==GoodColor&&P_3U->Color==GoodColor)
  {
	P_UU->Color=GoodColor;
  }
  else
  {
	P_UU->Color=BadColor;
  }

  if(P_1U->Color==BadColor||P_2U->Color==BadColor||P_3U->Color==BadColor)
  {
	Application->MessageBox(L"Блок УУ не включен или неисправен!",L"Внимание",MB_ICONWARNING);
  }

  // БС
  if(P_1B->Color==GoodColor&&P_2B->Color==GoodColor&&P_3B->Color==GoodColor&&P_4B->Color==GoodColor&&P_5B->Color==GoodColor&&P_6B->Color==GoodColor&&P_7B->Color==GoodColor)
  {
	P_BS->Color=GoodColor;
  }
  else
  {
	P_BS->Color=BadColor;
  }

  if(P_1B->Color==BadColor||P_2B->Color==BadColor||P_3B->Color==BadColor||P_4B->Color==BadColor||P_5B->Color==BadColor||P_6B->Color==BadColor||P_7B->Color==BadColor)
  {
	Application->MessageBox(L"Блок БС не включен или неисправен!",L"Внимание",MB_ICONWARNING);
  }

  // ФРЛП
  if(P_1F->Color==GoodColor&&P_2F->Color==GoodColor&&P_3F->Color==GoodColor&&P_4F->Color==GoodColor)
  {
	P_FRLP->Color=GoodColor;
  }
  else
  {
	P_FRLP->Color=BadColor;
  }

  if(P_1F->Color==BadColor||P_2F->Color==BadColor||P_3F->Color==BadColor||P_4F->Color==BadColor)
  {
	Application->MessageBox(L"Блок ФРЛП не включен или неисправен!",L"Внимание",MB_ICONWARNING);
  }

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Command6Change(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
	if(CB_Command6->ItemIndex==i) Command6[3]=i;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CB_Command6Exit(TObject *Sender)
{
  for(int i=0; i<4; i++)
  {
    if(CB_Command6->ItemIndex==i) Command6[3]=i;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::B_SendClick(TObject *Sender)
{
  ComPortTransmitter();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_ComNumChange(TObject *Sender)
{
  CommPort1->ComNumber = CB_ComNum->ItemIndex+1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_BaudRateChange(TObject *Sender)
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
//---------------------------------------------------------------------------
void __fastcall TMainForm::ComPortTransmitter()
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
//---------------------------------------------------------------------------
void __fastcall TMainForm::SendTerminal()
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
  }
  CommPort1->PutChar(0x0d);                    // возврат каретки
  CommPort1->PutChar(0x0a);                    // перевод на следующую строку

  if(ChB_Command7->Checked==false)
  {
    CommPort1->PutString("Command7 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Command7[i]);
    }
  }
  CommPort1->PutChar(0x0d);                    // возврат каретки
  CommPort1->PutChar(0x0a);                    // перевод на следующую строку

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

  if(ChB_Com21->Checked==false)
  {
	CommPort1->PutString("Com21 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com21[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
  }

  if(ChB_Com22->Checked==false)
  {
	CommPort1->PutString("Com22 = ");

    for(int i=0; i<4; i++)
    {
      uart_puthex_byte((char)Com22[i]);
    }

    CommPort1->PutChar(0x0d);                  // возврат каретки
    CommPort1->PutChar(0x0a);                  // перевод на следующую строку
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
void __fastcall TMainForm::uart_puti( signed int val )
 { unsigned char buffer[8];

   itoa(val, buffer);
   uart_puts( buffer );
 }/* uart_puti */
 /*************************************************************************
 itoa:  конвертируем n в символы в s
**************************************************************************/
void __fastcall TMainForm::itoa(signed int n, unsigned char s[])
{
   Bin_to_dec (s, n);
}
/*----------------------------------------------------------------------------*/
/* Функция:    Преобразование BIN->DEC 's[]'                                  */
/* Принимает:  двоичное число                                                 */
/* Возвращает: ничего (изменяет глобальные переменные)                        */
/*----------------------------------------------------------------------------*/
void __fastcall TMainForm::Bin_to_dec (unsigned char s[],     // буфер
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
void __fastcall TMainForm::uart_puts(unsigned char *s )
 { while (*s)
	  CommPort1->PutChar(*s++);  // строчка преобразована для проекта
 } /* uart_puts */
/*************************************************************************
Function: uart_puthex_byte()
Purpose:  transmit upper and lower nibble as ASCII-hex to UART
Input:    byte value
Returns:  none
This functions has been added by Martin Thomas <eversmith@heizung-thomas.de>
Don't blame P. Fleury if it doesn't work ;-)
**************************************************************************/
void __fastcall TMainForm::uart_puthex_byte(unsigned char  b)
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
void __fastcall TMainForm::uart_puthex_nibble(unsigned char b)
 { unsigned char  c = b & 0x0f;
   if (c>9) c += 'A'-10;
   else c += '0';
   CommPort1->PutChar(c);  // строчка преобразована для проекта
 } /* uart_puthex_nibble */
//---------------------------------------------------------------------------
void __fastcall TMainForm::SendControl()
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
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Shift[i]);
    }
    Delay();                                     // задержка
  }

  if(ChB_Command6->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command6[i]);
    }
    Delay();                                     // задержка
  }

  if(ChB_Command7->Checked==false)
  {
    for(int i=0; i<4; i++)
    {
      CommPort1->PutChar((char)Command7[i]);
    }
    Delay();                                     // задержка
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SendTesting()
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

  if(ChB_Com21->Checked==false)
  {
	for(int i=0; i<4; i++)
	{
	  CommPort1->PutChar((char)Com21[i]);
	}
	Delay();                                 // задержка
  }

  if(ChB_Com22->Checked==false)
  {
	for(int i=0; i<4; i++)
	{
	  CommPort1->PutChar((char)Com22[i]);
	}
	Delay();                                 // задержка
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Delay(void)       // функция задержки
{
  Sleep(delay_ms);                           // задержка в мс
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com21Change(TObject *Sender)
{
  if(CB_Com21->ItemIndex<257)
  {
	for(int i=0; i<257; i++)
	{
	  int code;
	  if(CB_Com21->ItemIndex==i) code=256-i;      // получение кода параметра
	  int code_LSB=code&0xFF;                     // младший байт параметра
	  int code_MSB=(code/256)&0xFF;               // старший байт параметра
	  Com21[2]=code_MSB;                          // записать значение старшего байта параметра
	  Com21[3]=code_LSB;                          // записать значение младшего байта параметра
	}
  }

  if(CB_Com21->ItemIndex>=257)
  {
	for(int i=257; i<514; i++)
	{
	  long int code;
	  if(CB_Com21->ItemIndex==i) code=65535+257-i;  // получение кода параметра
	  int code_LSB=code&0xFF;                       // младший байт параметра
	  int code_MSB=(code/256)&0xFF;                 // старший байт параметра
	  Com21[2]=code_MSB;                            // записать значение старшего байта параметра
	  Com21[3]=code_LSB;                            // записать значение младшего байта параметра
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_Com22Change(TObject *Sender)
{
  if(CB_Com22->ItemIndex<257)
  {
	for(int i=0; i<257; i++)
    {
	  int code;
	  if(CB_Com22->ItemIndex==i) code=256-i;      // получение кода параметра
      int code_LSB=code&0xFF;                     // младший байт параметра
      int code_MSB=(code/256)&0xFF;               // старший байт параметра
	  Com22[2]=code_MSB;                          // записать значение старшего байта параметра
	  Com22[3]=code_LSB;                          // записать значение младшего байта параметра
    }
  }

  if(CB_Com22->ItemIndex>=257)
  {
    for(int i=257; i<514; i++)
    {
      long int code;
	  if(CB_Com22->ItemIndex==i) code=65535+257-i;  // получение кода параметра
	  int code_LSB=code&0xFF;                       // младший байт параметра
	  int code_MSB=(code/256)&0xFF;                 // старший байт параметра
	  Com22[2]=code_MSB;                            // записать значение старшего байта параметра
	  Com22[3]=code_LSB;                            // записать значение младшего байта параметра
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StopControl(void)
{
  //NIDAQmxTimer->Enabled=false;
  DefaultPanel();
  VIPWorkOFF();                              // Режим «Работа Выкл» блока ВИП
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetFreqSPI(void)  // Режим «Работа» блока БС
{
/*
  Нажатие на кнопку «Включить» должно инициировать следующие действия для блока БС:
  1)	Измерить ток потребления по +27 В, считав аналоговое напряжение на выводе AI3 NI6008.
  Если ток не попадает в диапазон 900…1000 мА, то необходимо выдать информационное сообщение
  «Блок БС не включен или не исправен».
*/
  try
  {
	if(range!=D1)
	{
/*
	2)	Установить необходимую частоту синтезатора основного канала блока БС. В
	зависимости от выбранного пользователем частотного диапазона, устанавливается
	частота синтезатора путем посылки рабочих данных по шине SPI. Для диапазона
	Д1 не требуется посылать данные (т.е. этот шаг нужно пропустить). Для диапазона
	Д2 устанавливается частота 7200 МГц (данные SPI смотри в протоколе на синтезатор
	частоты). Для диапазона Д3 устанавливается частота 5850 МГц. И для диапазона
	Д4 необходимо установить частоту 7700 МГц
*/
	if(!SPIWrite())              throw 3;  // запись значения частоты гетеродина основного канала в блок БС по SPI
/*
	3)	Считать состояние P0.2 NI8451 командой «Захват фазы ФАПЧ основного канала».
	Если фаза захвачена, то окрасить единичный индикатор «Захват фазы БС1» в зеленый
	цвет, иначе окрасить его в красный цвет и выдать информационное сообщение
	«Синтезатор основного канала не работоспособен. Переключитесь на резервный канал».
*/
	if(!LockDetect1())           throw 3;
//  4)	Повторить действия по п.2 для синтезатора резервного канала.
	if(!SPIWriteR())             throw 3;  // запись значения частоты гетеродина резервного канала в блок БС по SPI
/*
	5)	Считать состояние P0.0 NI8451 командой «Захват фазы ФАПЧ резервного канала».
	Если фаза захвачена, то окрасить единичный индикатор «Захват фазы БС2» в зеленый
	цвет, иначе окрасить его в красный цвет и выдать информационное сообщение «Синтезатор
	резервного канала не работоспособен. Переключитесь на основной канал».
*/
	if(!LockDetect2())           throw 3;
/*
6)	Установить требуемый уровень мощности гетеродина приемника и передатчика для
	основного канала. Для частотного диапазона Д1 этот пункт можно пропустить.
	Для диапазона Д2 (частота синтезатора 7200 МГц) необходимо с помощью команды
	«Установка затухания аттенюатора основного канала» установить затухание 0 дБ.
	Для диапазона Д3 (частота синтезатора 5850 МГц) необходимо установить затухание
	 -3 дБ. И для диапазона Д4 (частота синтезатора 7700 МГц) необходимо с помощью
	команды «Установка затухания аттенюатора основного канала» установить затухание -3 дБ.
*/
	if(range==D2)
	{
	  CB_Att_BS->ItemIndex=0;
	  if(!BSatt())                 throw 3;
	}
	else
	if(range==D3||range==D4)
	{
	  CB_Att_BS->ItemIndex=6;
	  if(!BSatt())                 throw 3;
    }
/*
7)	С помощью команды «Выбор гетеродина основного канала для контроля» выбрать
	«гетеродин приемника». Командой «Мощность сигнала контрольного выхода основного
	канала» считать аналоговое напряжение. Если считанное значение не лежит в
	диапазоне «1,33…1,39» (частота 5850 МГц), «1,25…1,33» (частота 7200 МГц) или
	«1,39…1,48» (частота 7700 МГц), то необходимо выдать информационное сообщение
	«Малый уровень сигнала на выходе гетеродина приемника. Переключитесь на
	резервный канал».
*/

	if(RB_ReceiverHet->Checked==true)
	  if(!DigitalLineWrite(7, 1))  throw 3;

	if(range==D3)
	  if((ValuePo>1.05)||(ValuePo<=1.09))
		goto Lab1;

	if(range==D2)
	  if((ValuePo>1.33)||(ValuePo<=1.36))
		goto Lab1;

	if(range==D4)
	  if((ValuePo>1.2)||(ValuePo<=1.28))
		goto Lab1;

	Lab1:
	Application->MessageBox(L"Малый уровень сигнала на выходе гетеродина приемника. Переключитесь на резервный канал!",L"Внимание",MB_ICONWARNING);

/*
8)	С помощью команды «Выбор гетеродина основного канала для контроля» выбрать
	«гетеродин передатчика». Командой «Мощность сигнала контрольного выхода основного
	канала» считать аналоговое напряжение. Если считанное значение не лежит в
	диапазоне «1,33…1,39» (частота 5850 МГц), «1,25…1,33» (частота 7200 МГц) или
	«1,39…1,48» (частота 7700 МГц), то необходимо выдать информационное сообщение
	«Малый уровень сигнала на выходе гетеродина передатчика. Переключитесь на
	основной канал».
*/

    RB_TransmitHet->Checked=true;
	if(RB_TransmitHet->Checked==true)
	  if(!DigitalLineWrite(7, 0))  throw 3;

	if(range==D3)
	  if((ValuePo>1.05)||(ValuePo<=1.09))
		goto Lab2;

	if(range==D2)
	  if((ValuePo>1.33)||(ValuePo<=1.36))
		goto Lab2;

	if(range==D4)
	  if((ValuePo>1.2)||(ValuePo<=1.28))
		goto Lab2;

	Lab2:
    Application->MessageBox(L"Малый уровень сигнала на выходе гетеродина передатчика. Переключитесь на резервный канал!",L"Внимание",MB_ICONWARNING);

/*
9)	Повторить действия по п.6-8 для резервного канала (используемые команды «Установка
	затухания аттенюатора резервного канала», «Выбор гетеродина резервного канала
	для контроля» и «Мощность сигнала контрольного выхода резервного канала» смотри
    в протоколе на синтезатор частоты).
*/

    // 6
	if(range==D2)
	{
	  CB_Att_BSR->ItemIndex=0;
	  if(!BSattR())                 throw 3;
	}
	else
	if(range==D3||range==D4)
	{
	  CB_Att_BSR->ItemIndex=6;
	  if(!BSattR())                 throw 3;
	}

	// 7
	if(RB_ReceiverHetR->Checked==true)
	  if(!DigitalLineWrite(5, 1)) throw 3;

	if(range==D3)
	  if((ValuePr>0.98)||(ValuePr<=1.02))
		goto Lab3;

	if(range==D2)
	  if((ValuePr>1.19)||(ValuePr<=1.22))
		goto Lab3;

	if(range==D4)
	  if((ValuePr>1.38)||(ValuePr<=1.45))
		goto Lab3;

	Lab3:
    Application->MessageBox(L"Малый уровень сигнала на выходе гетеродина приемника. Переключитесь на основной канал!",L"Внимание",MB_ICONWARNING);

	// 8
	RB_TransmitHetR->Checked=true;
	if(RB_TransmitHetR->Checked==true)
	  if(!DigitalLineWrite(5, 0)) throw 3;

	if(range==D3)
	  if((ValuePr>0.98)||(ValuePr<=1.02))
		goto Lab4;

	if(range==D2)
	  if((ValuePr>1.19)||(ValuePr<=1.22))
		goto Lab4;

	if(range==D4)
	  if((ValuePr>1.38)||(ValuePr<=1.45))
		goto Lab4;

	Lab4:
    Application->MessageBox(L"Малый уровень сигнала на выходе гетеродина передатчика. Переключитесь на основной канал!",L"Внимание",MB_ICONWARNING);
	}
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок БС!",L"Внимание",MB_ICONWARNING);
	 MainForm->SetFocus();
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SPIWrite(void)
// запись значения частоты гетеродина в блок БС по SPI
{
  char   FirstDevice[260];         // 260 characters for 845x resource name
  uInt16 ClockRate       = 1000;   // clock rate in KHz (1000)
  uInt8  PortNumber      = 0;
  char   CharBuff[10];
  char   ErrorMsg[1024];
  uInt8  Delay           = 5;

   /* find first device */
   errChk (ni845xFindDevice (FirstDevice, NULL , NULL));

   /* open device handle */
   errChk (ni845xOpen (FirstDevice, &DeviceHandle));

   /* Set the I/O Voltage Level */
   errChk (ni845xSetIoVoltageLevel (DeviceHandle, kNi845x33Volts));

   /* create script */
   errChk (ni845xSpiScriptOpen (&ScriptHandle));

   /* issue stop condition */
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelect));
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelect));

   /* issue stop condition */
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelectR));

   /* enable script logging */
   errChk (ni845xSpiScriptEnableSPI (ScriptHandle));

   /* configure Polarity and Phase */
   errChk (ni845xSpiScriptClockPolarityPhase (ScriptHandle,
            kNi845xSpiClockPolarityIdleLow, kNi845xSpiClockPhaseFirstEdge));

   /* configure clock rate */
   errChk (ni845xSpiScriptClockRate (ScriptHandle, ClockRate));

   WriteSize = 4;

   if(heterodyne==ht1) F7200MHz();
   else
   if(heterodyne==ht2) F5850MHz();
   else
   if(heterodyne==ht3) F7700MHz();

   /* issue delay */
   errChk (ni845xSpiScriptDelay (ScriptHandle, Delay));

   /* disable script logging */
   errChk (ni845xSpiScriptDisableSPI (ScriptHandle));

   /* run the script */
   errChk (ni845xSpiScriptRun (ScriptHandle, DeviceHandle, PortNumber));

   /* close the script and device handles */
   errChk (ni845xSpiScriptClose (ScriptHandle));
   errChk (ni845xClose (DeviceHandle));

   return 1;

Error:
   if (Error < 0)
   {
	 try
	 {
	   /*
	   ni845xStatusToString(Error, 1024, ErrorMsg);

	   wchar_t* WErrorMsg;
	   swprintf(WErrorMsg, L"%S", ErrorMsg); // char* -> wchar_t*
	   Application->MessageBox(WErrorMsg,L"Ошибка работы устройства сбора данных блока БС!",MB_ICONWARNING);
       */
	   ni845xClose (DeviceHandle);
	 }

	 catch(...)
	 {
	   Application->MessageBox(L"Ошибка доступа к блоку БС!",L"Внимание",MB_ICONWARNING);
	   MainForm->SetFocus();
	   //exit(1);
	 }
   }

   return 0;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SendD(char* SendData, char a, char b, char c, char d)
{
   /* issue start condition */
   errChk (ni845xSpiScriptCSHigh (ScriptHandle, ChipSelect));

   /* issue stop condition */
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelectR));

   // РЕГИСТР
   SendData[0] = a;
   SendData[1] = b;
   SendData[2] = c;
   SendData[3] = d;

   /* write data array */
   errChk (ni845xSpiScriptWriteRead (ScriptHandle, WriteSize, SendData,
   &ScriptReadIndex));

   /* issue stop condition */
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelect));
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelect));
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelect));
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelect));

   return 1;

Error:
   if (Error < 0)
   {
	 try
	 {
	   /*
	   ni845xStatusToString(Error, 1024, ErrorMsg);

	   wchar_t* WErrorMsg;
	   swprintf(WErrorMsg, L"%S", ErrorMsg); // char* -> wchar_t*
	   Application->MessageBox(WErrorMsg,L"Ошибка работы устройства сбора данных блока БС!",MB_ICONWARNING);
       */
	   ni845xClose (DeviceHandle);
	 }

	 catch(...)
	 {
	   Application->MessageBox(L"Ошибка доступа к блоку БС!",L"Внимание",MB_ICONWARNING);
	   MainForm->SetFocus();
	   //exit(1);
	 }
   }

   return 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SPISend(char* SendData, char addr, long int data)
{
  int byte1, byte2, byte3, byte4;

  long int Send;
  Send &= ~0xFFFFFFFF;

  long int shift_data = data & 0xFFFFFF;
  shift_data *=0x02;
  //M_Debug->Lines->Add(IntToHexStr(data));

  int shift_addr = addr & 0x3F;
  shift_addr *=0x2000000;

  Send |= shift_data|shift_addr;
  //M_Debug->Lines->Add(IntToHexStr(Send));

  byte1=(int) Send     &0xFF; // 1-й байт
  byte2=(int)(Send>>8) &0xFF; // 2-й байт
  byte3=(int)(Send>>16)&0xFF; // 3-й байт
  byte4=(int)(Send>>24)&0xFF; // 4-й байт
/*
  //M_Debug->Lines->Clear();
  M_Debug->Lines->Add(IntToHexStr(byte4));
  M_Debug->Lines->Add(IntToHexStr(byte3));
  M_Debug->Lines->Add(IntToHexStr(byte2));
  M_Debug->Lines->Add(IntToHexStr(byte1));
*/
  SendD(SendData1, byte4, byte3, byte2, byte1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::F5850MHz(void)
{
   SPISend(SendData1, 0x0, 0xA7975);
   SPISend(SendData1, 0xF, 0xC1);
   SPISend(SendData1, 0x1, 0x2);
   SPISend(SendData1, 0x2, 0x1);
   SPISend(SendData1, 0x3, 0x3A);
   SPISend(SendData1, 0x5, 0x0);
   SPISend(SendData1, 0x6, 0x30F4A);
   SPISend(SendData1, 0x7, 0x14D);
   SPISend(SendData1, 0x8, 0xC1BEFF);
   SPISend(SendData1, 0x9, 0x547FFF);
   SPISend(SendData1, 0xA, 0x2046);
   SPISend(SendData1, 0xB, 0x7C021);
   SPISend(SendData1, 0xC, 0x0);
   SPISend(SendData1, 0xD, 0x0);
   SPISend(SendData1, 0xE, 0x0);
   SPISend(SendData1, 0xF, 0xC1);
   SPISend(SendData1, 0x4, 0x800000);
   SPISend(SendData1, 0xC, 0x0);
   SPISend(SendData1, 0x5, 0x6090);
   SPISend(SendData1, 0x5, 0xEE00);
   SPISend(SendData1, 0xC, 0x0);
   SPISend(SendData1, 0x6, 0x30F4A);
   SPISend(SendData1, 0x6, 0x30F4A);
   SPISend(SendData1, 0x2, 0x1);
   SPISend(SendData1, 0x5, 0x2018);
   SPISend(SendData1, 0x5, 0x0);
   SPISend(SendData1, 0x3, 0x3A);
   SPISend(SendData1, 0x5, 0x0);
   SPISend(SendData1, 0x4, 0x800000);
   SPISend(SendData1, 0xC, 0x0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::F7200MHz(void)
{
   SPISend(SendData1, 0x0, 0xA7975);
   SPISend(SendData1, 0xF, 0xC1);
   SPISend(SendData1, 0x1, 0x2);
   SPISend(SendData1, 0x2, 0x1);
   SPISend(SendData1, 0x3, 0x48);
   SPISend(SendData1, 0x5, 0x6090);
   SPISend(SendData1, 0x6, 0x2003CA);
   SPISend(SendData1, 0x7, 0x14D);
   SPISend(SendData1, 0x8, 0xC1BEFF);
   SPISend(SendData1, 0x9, 0x147FFF);
   SPISend(SendData1, 0xA, 0x2046);
   SPISend(SendData1, 0xB, 0x7C061);
   SPISend(SendData1, 0xC, 0x0);
   SPISend(SendData1, 0xD, 0x0);
   SPISend(SendData1, 0xE, 0x0);
   SPISend(SendData1, 0xF, 0xC1);
   SPISend(SendData1, 0x4, 0x0);
   SPISend(SendData1, 0x5, 0x6090);
   SPISend(SendData1, 0xC, 0x0);
   SPISend(SendData1, 0x6, 0x2003CA);
   SPISend(SendData1, 0x6, 0x2003CA);
   SPISend(SendData1, 0x2, 0x1);
   SPISend(SendData1, 0x5, 0x2018);
   SPISend(SendData1, 0x5, 0x0);
   SPISend(SendData1, 0x5, 0x0);
   SPISend(SendData1, 0x4, 0x0);
   SPISend(SendData1, 0x3, 0x48);
   SPISend(SendData1, 0x5, 0x6090);
   SPISend(SendData1, 0x9, 0x147FFF);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::F7700MHz(void)
{
   SPISend(SendData1, 0x0, 0xA7975);
   SPISend(SendData1, 0xF, 0xC1);
   SPISend(SendData1, 0x1, 0x2);
   SPISend(SendData1, 0x2, 0x1);
   SPISend(SendData1, 0x3, 0x4D);
   SPISend(SendData1, 0x5, 0x6090);
   SPISend(SendData1, 0x6, 0x2003CA);
   SPISend(SendData1, 0x7, 0x14D);
   SPISend(SendData1, 0x8, 0xC1BEFF);
   SPISend(SendData1, 0x9, 0x147FFF);
   SPISend(SendData1, 0xA, 0x2046);
   SPISend(SendData1, 0xB, 0x7C061);
   SPISend(SendData1, 0xC, 0x0);
   SPISend(SendData1, 0xD, 0x0);
   SPISend(SendData1, 0xE, 0x0);
   SPISend(SendData1, 0xF, 0xC1);
   SPISend(SendData1, 0x4, 0x0);
   SPISend(SendData1, 0x5, 0x6090);
   SPISend(SendData1, 0xC, 0x0);
   SPISend(SendData1, 0x6, 0x2003CA);
   SPISend(SendData1, 0x6, 0x2003CA);
   SPISend(SendData1, 0x2, 0x1);
   SPISend(SendData1, 0x5, 0x2018);
   SPISend(SendData1, 0x5, 0x0);
   SPISend(SendData1, 0x5, 0x0);
   SPISend(SendData1, 0x4, 0x0);
   SPISend(SendData1, 0x3, 0x4D);
   SPISend(SendData1, 0x5, 0x6090);
   SPISend(SendData1, 0x9, 0x147FFF);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Prestart(void)  // предпусковые операции
{
  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[1]=1;                              // 1->DevP0[1]

  SetDevPN(VIP, DevP0, 1);                 // if VIP DevP0[1]->Dev1P0[1]
  DevToP0P1(VIP);                          // if VIP Dev1PX[1]->Px[1]

  SetDev_port(VIP);                        // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP
	 T_Sec1->Enabled=true;                               // задержка 1 с
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec3Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec3->Enabled=false;

  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[0]=1;                            // 1->DevP0[0]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                        // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP
	 T_mSec2->Enabled=true;                              // задержка 200 мс
  }

  catch(...)
  {
	 Application->MessageBox(L"Усилитель МИП в блоке ВК-ПРД неисправен!",L"Внимание",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_mSec2Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_mSec2->Enabled=false;

  //int VIP=dv1;
  //M_Debug->Lines->Add(VIP);

  DevP0[0]=0;                            // 0->DevP0[0]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                        // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP
	 SB_OnOff->Enabled=true;
	 P_OneSec->Visible=false;
  }

  catch(...)
  {
	 Application->MessageBox(L"Усилитель МИП в блоке ВК-ПРД неисправен!",L"Внимание",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::PRMatt(void)
{
  switch(CB_Att_PRM->ItemIndex)
  {
	case 0:
	  if(!SetPRMatt(0, 1, 0, 0, 0)) return 0;
	  break;

	case 1:
	  if(!SetPRMatt(0, 0, 0, 0, 0)) return 0;
	  break;

	case 2:
	  if(!SetPRMatt(1, 1, 0, 0, 0)) return 0;
	  break;

	case 3:
	  if(!SetPRMatt(1, 0, 0, 0, 0)) return 0;
	  break;

	case 4:
	  if(!SetPRMatt(0, 1, 0, 1, 0)) return 0;
	  break;

	case 5:
	  if(!SetPRMatt(0, 0, 0, 1, 0)) return 0;
	  break;

	case 6:
	  if(!SetPRMatt(1, 1, 0, 1, 0)) return 0;
	  break;

	case 7:
	  if(!SetPRMatt(1, 0, 0, 1, 0)) return 0;
	  break;

	case 8:
	  if(!SetPRMatt(0, 1, 1, 0, 0)) return 0;
	  break;

	case 9:
	  if(!SetPRMatt(0, 0, 1, 0, 0)) return 0;
	  break;

	case 10:
	  if(!SetPRMatt(1, 1, 1, 0, 0)) return 0;
	  break;

	case 11:
	  if(!SetPRMatt(1, 0, 1, 0, 0)) return 0;
	  break;

	case 12:
	  if(!SetPRMatt(0, 1, 1, 1, 0)) return 0;
	  break;

	case 13:
	  if(!SetPRMatt(0, 0, 1, 1, 0)) return 0;
	  break;

	case 14:
	  if(!SetPRMatt(1, 1, 1, 1, 0)) return 0;
	  break;

	case 15:
	  if(!SetPRMatt(1, 0, 1, 1, 0)) return 0;
	  break;

	case 16:
	  if(!SetPRMatt(0, 1, 0, 0, 1)) return 0;
	  break;

	case 17:
	  if(!SetPRMatt(0, 0, 0, 0, 1)) return 0;
	  break;

	case 18:
	  if(!SetPRMatt(1, 1, 0, 0, 1)) return 0;
	  break;

	case 19:
	  if(!SetPRMatt(1, 0, 0, 0, 1)) return 0;
	  break;

	case 20:
	  if(!SetPRMatt(0, 1, 0, 1, 1)) return 0;
	  break;

	case 21:
	  if(!SetPRMatt(0, 0, 0, 1, 1)) return 0;
	  break;

	case 22:
	  if(!SetPRMatt(1, 1, 0, 1, 1)) return 0;
	  break;

	case 23:
	  if(!SetPRMatt(1, 0, 0, 1, 1)) return 0;
	  break;

	case 24:
	  if(!SetPRMatt(0, 1, 1, 0, 1)) return 0;
	  break;

	case 25:
	  if(!SetPRMatt(0, 0, 1, 0, 1)) return 0;
	  break;

	case 26:
	  if(!SetPRMatt(1, 1, 1, 0, 1)) return 0;
	  break;

	case 27:
	  if(!SetPRMatt(1, 0, 1, 0, 1)) return 0;
	  break;

	case 28:
	  if(!SetPRMatt(0, 1, 1, 1, 1)) return 0;
	  break;

	case 29:
	  if(!SetPRMatt(0, 0, 1, 1, 1)) return 0;
	  break;

	case 30:
	  if(!SetPRMatt(1, 1, 1, 1, 1)) return 0;
	  break;

	case 31:
	  if(!SetPRMatt(1, 0, 1, 1, 1)) return 0;
	  break;
  }

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::PRDatt(void)
{
  switch(CB_Att_PRD->ItemIndex)
  {
	case 0:
	  if(!SetPRDatt(0, 1, 0, 0, 0)) return 0;
	  break;

	case 1:
	  if(!SetPRDatt(0, 0, 0, 0, 0)) return 0;
	  break;

	case 2:
	  if(!SetPRDatt(1, 1, 0, 0, 0)) return 0;
	  break;

	case 3:
	  if(!SetPRDatt(1, 0, 0, 0, 0)) return 0;
	  break;

	case 4:
	  if(!SetPRDatt(0, 1, 0, 1, 0)) return 0;
	  break;

	case 5:
	  if(!SetPRDatt(0, 0, 0, 1, 0)) return 0;
	  break;

	case 6:
	  if(!SetPRDatt(1, 1, 0, 1, 0)) return 0;
	  break;

	case 7:
	  if(!SetPRDatt(1, 0, 0, 1, 0)) return 0;
	  break;

	case 8:
	  if(!SetPRDatt(0, 1, 1, 0, 0)) return 0;
	  break;

	case 9:
	  if(!SetPRDatt(0, 0, 1, 0, 0)) return 0;
	  break;

	case 10:
	  if(!SetPRDatt(1, 1, 1, 0, 0)) return 0;
	  break;

	case 11:
	  if(!SetPRDatt(1, 0, 1, 0, 0)) return 0;
	  break;

	case 12:
	  if(!SetPRDatt(0, 1, 1, 1, 0)) return 0;
	  break;

	case 13:
	  if(!SetPRDatt(0, 0, 1, 1, 0)) return 0;
	  break;

	case 14:
	  if(!SetPRDatt(1, 1, 1, 1, 0)) return 0;
	  break;

	case 15:
	  if(!SetPRDatt(1, 0, 1, 1, 0)) return 0;
	  break;

	case 16:
	  if(!SetPRDatt(0, 1, 0, 0, 1)) return 0;
	  break;

	case 17:
	  if(!SetPRDatt(0, 0, 0, 0, 1)) return 0;
	  break;

	case 18:
	  if(!SetPRDatt(1, 1, 0, 0, 1)) return 0;
	  break;

	case 19:
	  if(!SetPRDatt(1, 0, 0, 0, 1)) return 0;
	  break;

	case 20:
	  if(!SetPRDatt(0, 1, 0, 1, 1)) return 0;
	  break;

	case 21:
	  if(!SetPRDatt(0, 0, 0, 1, 1)) return 0;
	  break;

	case 22:
	  if(!SetPRDatt(1, 1, 0, 1, 1)) return 0;
	  break;

	case 23:
	  if(!SetPRDatt(1, 0, 0, 1, 1)) return 0;
	  break;

	case 24:
	  if(!SetPRDatt(0, 1, 1, 0, 1)) return 0;
	  break;

	case 25:
	  if(!SetPRDatt(0, 0, 1, 0, 1)) return 0;
	  break;

	case 26:
	  if(!SetPRDatt(1, 1, 1, 0, 1)) return 0;
	  break;

	case 27:
	  if(!SetPRDatt(1, 0, 1, 0, 1)) return 0;
	  break;

	case 28:
	  if(!SetPRDatt(0, 1, 1, 1, 1)) return 0;
	  break;

	case 29:
	  if(!SetPRDatt(0, 0, 1, 1, 1)) return 0;
	  break;

	case 30:
	  if(!SetPRDatt(1, 1, 1, 1, 1)) return 0;
	  break;

	case 31:
	  if(!SetPRDatt(1, 0, 1, 1, 1)) return 0;
	  break;
  }

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::Range(void)
{
  switch(range)
  {
	case D1:                                  // Д1 (0,9-1,7)	0	1	1	0	0
	  if(SetRange(0, 1, 1, 0, 0)==0)  return 0;
	  else
	  if(SetRange(0, 1, 1, 0, 0)==-1) return -1;
	  break;

	case D2:                                  // Д2 (4,9-5,7)	1	1	0	1	0
	  if(SetRange(1, 1, 0, 1, 0)==0)  return 0;
	  else
	  if(SetRange(1, 1, 0, 1, 0)==-1) return -1;
	  break;

	case D3:                                  // Д3 (7,1-8,5)	1	0	1	0	1
	  if(SetRange(1, 0, 1, 0, 1)==0)  return 0;
	  else
	  if(SetRange(1, 0, 1, 0, 1)==-1) return -1;
	  break;

	case D4:                                  // Д4 (9,2-10)	1	0	0	1	1
	  if(SetRange(1, 0, 0, 1, 1)==0)  return 0;
	  else
	  if(SetRange(1, 0, 0, 1, 1)==-1) return -1;
	  break;
  }

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::DigitalLineRead(int LineNumber)
// LineNumber - line number for DI
{
   int    Error             = 0;
   char   FirstDevice[260];         // 260 characters for 845x resource name
   uInt8  DioPort           = 0;    // port for the line
   int    ch;
   char   CharBuff[10];
   char   ErrorMsg[1024];

   LineDirectionMap = ~(0x1 << LineNumber);

   /* find first device */
   errChk (ni845xFindDevice (FirstDevice, NULL , NULL));

   /* open device handle */
   errChk (ni845xOpen (FirstDevice, &DeviceHandle));

   /* Set the I/O Voltage Level */
   errChk (ni845xSetIoVoltageLevel (DeviceHandle, kNi845x33Volts));

   /* Set the Line Direction Map */
   errChk (ni845xDioSetPortLineDirectionMap (DeviceHandle, DioPort,
      LineDirectionMap));

   /* read the Digital Line */
   errChk (ni845xDioReadLine(DeviceHandle, DioPort, LineNumber, &DigValue));

   //Edit1->Text=DigValue;

   // Close the device handle
   errChk (ni845xClose (DeviceHandle));

   DeviceHandle = 0;

   return 1;

Error:
   if (Error < 0)
   {
	 try
	 {
	   /*
	   ni845xStatusToString(Error, 1024, ErrorMsg);

	   wchar_t* WErrorMsg;
	   swprintf(WErrorMsg, L"%S", ErrorMsg); // char* -> wchar_t*
	   Application->MessageBox(WErrorMsg,L"Ошибка работы устройства сбора данных блока БС!",MB_ICONWARNING);
	   */
	   ni845xClose (DeviceHandle);
	 }

	 catch(...)
	 {
	   Application->MessageBox(L"Ошибка доступа к блоку БС!",L"Внимание",MB_ICONWARNING);
	   MainForm->SetFocus();
	   //exit(1);
	 }
   }

   return 0;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::LockDetect1(void)
{
  if(!DigitalLineRead(2)) return 0;

  if(DigValue) P_Lock1->Color=GoodColor;
  else
  if(!DigValue)
  {
	P_Lock1->Color=BadColor;
	Application->MessageBox(L"Синтезатор основного канала не работоспособен. Переключитесь на резервный канал!",L"Внимание",MB_ICONWARNING);
  }

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SPIWriteR(void)
// запись значения частоты гетеродина в блок БС по SPI
{
  char   FirstDevice[260];         // 260 characters for 845x resource name
  uInt16 ClockRate       = 1000;   // clock rate in KHz (1000)
  uInt8  PortNumber      = 0;
  char   CharBuff[10];
  char   ErrorMsg[1024];
  uInt8  Delay           = 5;

   /* find first device */
   errChk (ni845xFindDevice (FirstDevice, NULL , NULL));

   /* open device handle */
   errChk (ni845xOpen (FirstDevice, &DeviceHandle));

   /* Set the I/O Voltage Level */
   errChk (ni845xSetIoVoltageLevel (DeviceHandle, kNi845x33Volts));

   /* create script */
   errChk (ni845xSpiScriptOpen (&ScriptHandle));

   /* issue stop condition */
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelectR));
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelectR));

   /* issue stop condition */
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelect));

   /* enable script logging */
   errChk (ni845xSpiScriptEnableSPI (ScriptHandle));

   /* configure Polarity and Phase */
   errChk (ni845xSpiScriptClockPolarityPhase (ScriptHandle,
            kNi845xSpiClockPolarityIdleLow, kNi845xSpiClockPhaseFirstEdge));

   /* configure clock rate */
   errChk (ni845xSpiScriptClockRate (ScriptHandle, ClockRate));

   WriteSize = 4;

   if(heterodyne==ht1) F7200MHzR();
   else
   if(heterodyne==ht2) F5850MHzR();
   else
   if(heterodyne==ht3) F7700MHzR();

   /* issue delay */
   errChk (ni845xSpiScriptDelay (ScriptHandle, Delay));

   /* disable script logging */
   errChk (ni845xSpiScriptDisableSPI (ScriptHandle));

   /* run the script */
   errChk (ni845xSpiScriptRun (ScriptHandle, DeviceHandle, PortNumber));

   /* close the script and device handles */
   errChk (ni845xSpiScriptClose (ScriptHandle));
   errChk (ni845xClose (DeviceHandle));

   return 1;

Error:
   if (Error < 0)
   {
	 try
	 {
	   /*
	   ni845xStatusToString(Error, 1024, ErrorMsg);

	   wchar_t* WErrorMsg;
	   swprintf(WErrorMsg, L"%S", ErrorMsg); // char* -> wchar_t*
	   Application->MessageBox(WErrorMsg,L"Ошибка работы устройства сбора данных блока БС!",MB_ICONWARNING);
       */
	   ni845xClose (DeviceHandle);
	 }

	 catch(...)
	 {
	   Application->MessageBox(L"Ошибка доступа к блоку БС!",L"Внимание",MB_ICONWARNING);
	   MainForm->SetFocus();
	   //exit(1);
	 }
   }

   return 0;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SendDR(char* SendData, char a, char b, char c, char d)
{
   /* issue start condition */
   errChk (ni845xSpiScriptCSHigh (ScriptHandle, ChipSelectR));

   /* issue stop condition */
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelect));

   // РЕГИСТР
   SendData[0] = a;
   SendData[1] = b;
   SendData[2] = c;
   SendData[3] = d;

   /* write data array */
   errChk (ni845xSpiScriptWriteRead (ScriptHandle, WriteSize, SendData,
   &ScriptReadIndex));

   /* issue stop condition */
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelectR));
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelectR));
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelectR));
   errChk (ni845xSpiScriptCSLow (ScriptHandle, ChipSelectR));

   return 1;

Error:
   if (Error < 0)
   {
	 try
	 {
	   /*
	   ni845xStatusToString(Error, 1024, ErrorMsg);

	   wchar_t* WErrorMsg;
	   swprintf(WErrorMsg, L"%S", ErrorMsg); // char* -> wchar_t*
	   Application->MessageBox(WErrorMsg,L"Ошибка работы устройства сбора данных блока БС!",MB_ICONWARNING);
       */
	   ni845xClose (DeviceHandle);
	 }

	 catch(...)
	 {
	   Application->MessageBox(L"Ошибка доступа к блоку БС!",L"Внимание",MB_ICONWARNING);
	   MainForm->SetFocus();
	   //exit(1);
	 }
   }

   return 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SPISendR(char* SendData, char addr, long int data)
{
  int byte1, byte2, byte3, byte4;

  long int Send;
  Send &= ~0xFFFFFFFF;

  long int shift_data = data & 0xFFFFFF;
  shift_data *=0x02;
  //M_Debug->Lines->Add(IntToHexStr(data));

  int shift_addr = addr & 0x3F;
  shift_addr *=0x2000000;

  Send |= shift_data|shift_addr;
  //M_Debug->Lines->Add(IntToHexStr(Send));

  byte1=(int) Send     &0xFF; // 1-й байт
  byte2=(int)(Send>>8) &0xFF; // 2-й байт
  byte3=(int)(Send>>16)&0xFF; // 3-й байт
  byte4=(int)(Send>>24)&0xFF; // 4-й байт
/*
  //M_Debug->Lines->Clear();
  M_Debug->Lines->Add(IntToHexStr(byte4));
  M_Debug->Lines->Add(IntToHexStr(byte3));
  M_Debug->Lines->Add(IntToHexStr(byte2));
  M_Debug->Lines->Add(IntToHexStr(byte1));
*/
  SendDR(SendData1, byte4, byte3, byte2, byte1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::F5850MHzR(void)
{
   SPISendR(SendData1, 0x0, 0xA7975);
   SPISendR(SendData1, 0xF, 0xC1);
   SPISendR(SendData1, 0x1, 0x2);
   SPISendR(SendData1, 0x2, 0x1);
   SPISendR(SendData1, 0x3, 0x3A);
   SPISendR(SendData1, 0x5, 0x0);
   SPISendR(SendData1, 0x6, 0x30F4A);
   SPISendR(SendData1, 0x7, 0x14D);
   SPISendR(SendData1, 0x8, 0xC1BEFF);
   SPISendR(SendData1, 0x9, 0x547FFF);
   SPISendR(SendData1, 0xA, 0x2046);
   SPISendR(SendData1, 0xB, 0x7C021);
   SPISendR(SendData1, 0xC, 0x0);
   SPISendR(SendData1, 0xD, 0x0);
   SPISendR(SendData1, 0xE, 0x0);
   SPISendR(SendData1, 0xF, 0xC1);
   SPISendR(SendData1, 0x4, 0x800000);
   SPISendR(SendData1, 0xC, 0x0);
   SPISendR(SendData1, 0x5, 0x6090);
   SPISendR(SendData1, 0x5, 0xEE00);
   SPISendR(SendData1, 0xC, 0x0);
   SPISendR(SendData1, 0x6, 0x30F4A);
   SPISendR(SendData1, 0x6, 0x30F4A);
   SPISendR(SendData1, 0x2, 0x1);
   SPISendR(SendData1, 0x5, 0x2018);
   SPISendR(SendData1, 0x5, 0x0);
   SPISendR(SendData1, 0x3, 0x3A);
   SPISendR(SendData1, 0x5, 0x0);
   SPISendR(SendData1, 0x4, 0x800000);
   SPISendR(SendData1, 0xC, 0x0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::F7200MHzR(void)
{
   SPISendR(SendData1, 0x0, 0xA7975);
   SPISendR(SendData1, 0xF, 0xC1);
   SPISendR(SendData1, 0x1, 0x2);
   SPISendR(SendData1, 0x2, 0x1);
   SPISendR(SendData1, 0x3, 0x48);
   SPISendR(SendData1, 0x5, 0x6090);
   SPISendR(SendData1, 0x6, 0x2003CA);
   SPISendR(SendData1, 0x7, 0x14D);
   SPISendR(SendData1, 0x8, 0xC1BEFF);
   SPISendR(SendData1, 0x9, 0x147FFF);
   SPISendR(SendData1, 0xA, 0x2046);
   SPISendR(SendData1, 0xB, 0x7C061);
   SPISendR(SendData1, 0xC, 0x0);
   SPISendR(SendData1, 0xD, 0x0);
   SPISendR(SendData1, 0xE, 0x0);
   SPISendR(SendData1, 0xF, 0xC1);
   SPISendR(SendData1, 0x4, 0x0);
   SPISendR(SendData1, 0x5, 0x6090);
   SPISendR(SendData1, 0xC, 0x0);
   SPISendR(SendData1, 0x6, 0x2003CA);
   SPISendR(SendData1, 0x6, 0x2003CA);
   SPISendR(SendData1, 0x2, 0x1);
   SPISendR(SendData1, 0x5, 0x2018);
   SPISendR(SendData1, 0x5, 0x0);
   SPISendR(SendData1, 0x5, 0x0);
   SPISendR(SendData1, 0x4, 0x0);
   SPISendR(SendData1, 0x3, 0x48);
   SPISendR(SendData1, 0x5, 0x6090);
   SPISendR(SendData1, 0x9, 0x147FFF);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::F7700MHzR(void)
{
   SPISendR(SendData1, 0x0, 0xA7975);
   SPISendR(SendData1, 0xF, 0xC1);
   SPISendR(SendData1, 0x1, 0x2);
   SPISendR(SendData1, 0x2, 0x1);
   SPISendR(SendData1, 0x3, 0x4D);
   SPISendR(SendData1, 0x5, 0x6090);
   SPISendR(SendData1, 0x6, 0x2003CA);
   SPISendR(SendData1, 0x7, 0x14D);
   SPISendR(SendData1, 0x8, 0xC1BEFF);
   SPISendR(SendData1, 0x9, 0x147FFF);
   SPISendR(SendData1, 0xA, 0x2046);
   SPISendR(SendData1, 0xB, 0x7C061);
   SPISendR(SendData1, 0xC, 0x0);
   SPISendR(SendData1, 0xD, 0x0);
   SPISendR(SendData1, 0xE, 0x0);
   SPISendR(SendData1, 0xF, 0xC1);
   SPISendR(SendData1, 0x4, 0x0);
   SPISendR(SendData1, 0x5, 0x6090);
   SPISendR(SendData1, 0xC, 0x0);
   SPISendR(SendData1, 0x6, 0x2003CA);
   SPISendR(SendData1, 0x6, 0x2003CA);
   SPISendR(SendData1, 0x2, 0x1);
   SPISendR(SendData1, 0x5, 0x2018);
   SPISendR(SendData1, 0x5, 0x0);
   SPISendR(SendData1, 0x5, 0x0);
   SPISendR(SendData1, 0x4, 0x0);
   SPISendR(SendData1, 0x3, 0x4D);
   SPISendR(SendData1, 0x5, 0x6090);
   SPISendR(SendData1, 0x9, 0x147FFF);
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::LockDetect2(void)
{
  if(!DigitalLineRead(0)) return 0;

  if(DigValue) P_Lock2->Color=GoodColor;
  else
  if(!DigValue)
  {
	P_Lock2->Color=BadColor;
	Application->MessageBox(L"Синтезатор резервного канала не работоспособен. Переключитесь на основной канал!",L"Внимание",MB_ICONWARNING);
  }

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetBSatt(int a, int b, int c, int d, int e, int f)
// установить порт БС основного канала
{
  DevP0[6]=a;                            // 1->DevP0[6]
  if(!SetBSchan(DevP0, 6)) return 0;     // установить канал

  DevP0[7]=b;                            // 1->DevP0[7]
  if(!SetBSchan(DevP0, 7)) return 0;     // установить канал

  DevP1[0]=c;                            // 1->DevP1[0]
  if(!SetBSchan(DevP1, 0)) return 0;     // установить канал

  DevP1[1]=d;                            // 1->DevP1[1]
  if(!SetBSchan(DevP1, 1)) return 0;     // установить канал

  DevP1[2]=e;                            // 1->DevP1[2]
  if(!SetBSchan(DevP1, 2)) return 0;     // установить канал

  DevP1[3]=f;                            // 1->DevP1[3]
  if(!SetBSchan(DevP1, 3)) return 0;     // установить канал

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetBSchan(unsigned char* Dev, int i)
// установить канал БС основного канала
{
  //int BS=dv1;

  SetDevPN(BS, Dev, i);                                // if BS DevP[]->Dev5P[]
  DevToP0P1(BS);                                       // if BS Dev5PX[]->Px[]

  SetDev_port(BS);                                     // if BS Dev5_portX->Dev_portX
  if(!SetDevP0P1Data(Dev_port0, Dev_port1)) return 0;  // запись цифровых портов BS
  else                                      return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::BSatt(void)
{
  int digmass[64][8];
  int mass[64];

  for (int i = 0; i < 64; i++)
	mass[i]=63-i;

  for (int i = 0; i < 64; i++)
  {
    for(int j=128, k=7; j>0, k>=0; j=j/2, k--)
	  if(mass[i]&j)
		digmass[i][k]=1;
	  else
		digmass[i][k]=0;
  }

  for (int i = 0; i < 64; i++)
  {
	if(CB_Att_BS->ItemIndex==i)
	{
	  if(!SetBSatt(digmass[i][5], digmass[i][4], digmass[i][3], digmass[i][2], digmass[i][1], digmass[i][0])) return 0;
	  /*
	  M_Debug->Lines->Clear();
	  M_Debug->Lines->Add(digmass[i][5]);
	  M_Debug->Lines->Add(digmass[i][4]);
	  M_Debug->Lines->Add(digmass[i][3]);
	  M_Debug->Lines->Add(digmass[i][2]);
	  M_Debug->Lines->Add(digmass[i][1]);
	  M_Debug->Lines->Add(digmass[i][0]);
      */
	}
  }

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::BSattR(void)
{
  int digmass[64][8];
  int mass[64];

  for (int i = 0; i < 64; i++)
	mass[i]=63-i;

  for (int i = 0; i < 64; i++)
  {
    for(int j=128, k=7; j>0, k>=0; j=j/2, k--)
	  if(mass[i]&j)
		digmass[i][k]=1;
	  else
		digmass[i][k]=0;
  }

  for (int i = 0; i < 64; i++)
  {
	if(CB_Att_BSR->ItemIndex==i)
	{
	  if(!SetBSattR(digmass[i][5], digmass[i][4], digmass[i][3], digmass[i][2], digmass[i][1], digmass[i][0])) return 0;
	  /*
	  M_Debug->Lines->Clear();
	  M_Debug->Lines->Add(digmass[i][5]);
	  M_Debug->Lines->Add(digmass[i][4]);
	  M_Debug->Lines->Add(digmass[i][3]);
	  M_Debug->Lines->Add(digmass[i][2]);
	  M_Debug->Lines->Add(digmass[i][1]);
	  M_Debug->Lines->Add(digmass[i][0]);
	  */
	}
  }

  return 1;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetBSattR(int a, int b, int c, int d, int e, int f)
// установить порт БС резервного канала
{
  DevP0[0]=a;                            // 1->DevP0[0]
  if(!SetBSchan(DevP0, 0)) return 0;     // установить канал

  DevP0[1]=b;                            // 1->DevP0[1]
  if(!SetBSchan(DevP0, 1)) return 0;     // установить канал

  DevP0[2]=c;                            // 1->DevP0[2]
  if(!SetBSchan(DevP0, 2)) return 0;     // установить канал

  DevP0[3]=d;                            // 1->DevP0[3]
  if(!SetBSchan(DevP0, 3)) return 0;     // установить канал

  DevP0[4]=e;                            // 1->DevP0[4]
  if(!SetBSchan(DevP0, 4)) return 0;     // установить канал

  DevP0[5]=f;                            // 1->DevP0[5]
  if(!SetBSchan(DevP0, 5)) return 0;     // установить канал

  return 1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetFRLP(void)  // Режим «Работа» блока ФРЛП
{
  CommPort1->Open=true;
/*
  Нажатие на кнопку «Включить» должно инициировать следующие действия для блока ФРЛП:
  1)	Измерить ток потребления по +27 В, считав аналоговое напряжение на выводе
  NI6008. Если ток не попадает в диапазон 900…1000 мА, то необходимо выдать
  информационное сообщение «Блок ФРЛП не включен или не исправен».

  2)	Если выбран диапазон Д1, то блок ФРЛП необходимо инициализировать следующими
  командами по СOM-порту:
  а) Передать команду «Коэффициент ослабления приемника ППРМ-2» (см. режим тестирование
  программы Controltesting). Значение затухания -27 дБ.
*/
  if(range==D1)
  {
	CB_Com6->ItemIndex=54;

	for(int i=0; i<64; i++)
	{
	  if(CB_Com6->ItemIndex==i) Com6[3]=63-i;
	}

	if(ChB_Com6->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com6[i]);
	  }
	  Delay();                                 // задержка
    }
/*
	б) Передать команду «Коэффициент ослабления передатчика ППРМ-2» (см. режим
	тестирование программы Controltesting). Значение затухания -31,5 дБ.
*/
	CB_Com7->ItemIndex=63;

	for(int i=0; i<64; i++)
	{
	  if(CB_Com7->ItemIndex==i) Com7[3]=63-i;
	}

	if(ChB_Com7->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com7[i]);
	  }
	  Delay();                                 // задержка
    }
/*
	в) Передать команду «Сдвиг разрядов» (см. режим тестирование программы Controltesting).
    Значение сдвига – 3.
*/
	CB_Shift_->ItemIndex=3;

	for(int i=0; i<7; i++)
	{
	  if(CB_Shift_->ItemIndex==i) Shift_[3]=i;
	}

	if(ChB_Com3->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Shift_[i]);
	  }
      Delay();                                 // задержка
	}
/*
	г) Установить частоту синтезатора платы ППРМ-2 равной 1300 МГц. Мощность на
	выходе 1 и 2 равна -4. Это относится к команде «Рабочие регистры синтезатора
	платы ППРМ-2. Пакет 1…8».
*/
	E_OutFreq->Text=1300;
	/*
	M_Debug->Lines->Clear();
	M_Debug->Lines->Add(Reg[0]);
	M_Debug->Lines->Add(Reg[1]);
	M_Debug->Lines->Add(Reg[4]);
	*/
/*
	д) Передать команду «Частота среза фильтра гетеродина приемника ППРМ-2»
	(см. режим тестирование программы Controltesting). Значение команды 1195 МГц.
*/
	CB_Com8->ItemIndex=7;

	for(int i=0; i<16; i++)
	{
	  int code;
	  if(CB_Com8->ItemIndex==i) code=14+128*i;    // получение кода параметра
	  int code_LSB=code&0xFF;                     // младший байт параметра
	  int code_MSB=(code/256)&0xFF;               // старший байт параметра
	  Com8[2]=code_MSB;                           // записать значение старшего байта параметра
	  Com8[3]=code_LSB;                           // записать значение младшего байта параметра
    }

	if(ChB_Com8->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com8[i]);
	  }
	  Delay();                                    // задержка
	}
/*
	е) Передать команду «Частота среза фильтра гетеродина передатчика ППРМ-2»
    (см. режим тестирование программы Controltesting). Значение команды 1195 МГц.
*/
	CB_Com9->ItemIndex=7;

	for(int i=0; i<16; i++)
	{
	  int code;
	  if(CB_Com9->ItemIndex==i) code=14+128*i;    // получение кода параметра
	  int code_LSB=code&0xFF;                     // младший байт параметра
	  int code_MSB=(code/256)&0xFF;               // старший байт параметра
	  Com9[2]=code_MSB;                           // записать значение старшего байта параметра
	  Com9[3]=code_LSB;                           // записать значение младшего байта параметра
    }

	if(ChB_Com9->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com9[i]);
	  }
	  Delay();                                    // задержка
	}

//  ж) Передать команду «Смещение I-ой составляющей». Команда F600FFDB.

	CB_Com21->ItemIndex=293;

	if(CB_Com21->ItemIndex<257)
	{
	  for(int i=0; i<257; i++)
	  {
		int code;
		if(CB_Com21->ItemIndex==i) code=256-i;      // получение кода параметра
		int code_LSB=code&0xFF;                     // младший байт параметра
		int code_MSB=(code/256)&0xFF;               // старший байт параметра
		Com21[2]=code_MSB;                          // записать значение старшего байта параметра
		Com21[3]=code_LSB;                          // записать значение младшего байта параметра
	  }
	}

	if(CB_Com21->ItemIndex>=257)
	{
	  for(int i=257; i<514; i++)
	  {
		long int code;
		if(CB_Com21->ItemIndex==i) code=65535+257-i;  // получение кода параметра
		int code_LSB=code&0xFF;                       // младший байт параметра
		int code_MSB=(code/256)&0xFF;                 // старший байт параметра
		Com21[2]=code_MSB;                            // записать значение старшего байта параметра
		Com21[3]=code_LSB;                            // записать значение младшего байта параметра
	  }
	}

	if(ChB_Com21->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com21[i]);
	  }
	  Delay();                                 // задержка
	}

//  З) Передать команду «Смещение Q-ой составляющей». Команда F7000034.

	CB_Com22->ItemIndex=204;

	if(CB_Com22->ItemIndex<257)
	{
	  for(int i=0; i<257; i++)
	  {
		int code;
		if(CB_Com22->ItemIndex==i) code=256-i;      // получение кода параметра
		int code_LSB=code&0xFF;                     // младший байт параметра
		int code_MSB=(code/256)&0xFF;               // старший байт параметра
		Com22[2]=code_MSB;                          // записать значение старшего байта параметра
		Com22[3]=code_LSB;                          // записать значение младшего байта параметра
	  }
	}

	if(CB_Com22->ItemIndex>=257)
	{
	  for(int i=257; i<514; i++)
	  {
		long int code;
		if(CB_Com22->ItemIndex==i) code=65535+257-i;  // получение кода параметра
		int code_LSB=code&0xFF;                       // младший байт параметра
		int code_MSB=(code/256)&0xFF;                 // старший байт параметра
		Com22[2]=code_MSB;                            // записать значение старшего байта параметра
		Com22[3]=code_LSB;                            // записать значение младшего байта параметра
	  }
	}

	if(ChB_Com22->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com22[i]);
	  }
	  Delay();                                 // задержка
	}
  }
  else
/*
  3) Если выбран диапазон Д2, Д3 или Д4, то блок ФРЛП необходимо инициализировать
  следующими командами по СOM-порту:
  а) Передать команду «Коэффициент ослабления приемника ППРМ-2» (см. режим тестирование
  программы Controltesting). Значение затухания -25 дБ.
*/
  if(range==D2||range==D3||range==D4)
  {
	CB_Com6->ItemIndex=50;

	for(int i=0; i<64; i++)
	{
	  if(CB_Com6->ItemIndex==i) Com6[3]=63-i;
	}

	if(ChB_Com6->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com6[i]);
	  }
	  Delay();                                 // задержка
    }
/*
	б) Передать команду «Коэффициент ослабления передатчика ППРМ-2» (см. режим
	тестирование программы Controltesting). Значение затухания -31,5 дБ.
*/
	CB_Com7->ItemIndex=63;

	for(int i=0; i<64; i++)
	{
	  if(CB_Com7->ItemIndex==i) Com7[3]=63-i;
	}

	if(ChB_Com7->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com7[i]);
	  }
	  Delay();                                 // задержка
    }
/*
	в) Передать команду «Сдвиг разрядов» (см. режим тестирование программы Controltesting).
    Значение сдвига – 3.
*/
	CB_Shift_->ItemIndex=3;

	for(int i=0; i<7; i++)
	{
	  if(CB_Shift_->ItemIndex==i) Shift_[3]=i;
	}

	if(ChB_Com3->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Shift_[i]);
	  }
      Delay();                                 // задержка
	}
/*
	г) Установить частоту синтезатора платы ППРМ-2 равной 1900 МГц. Мощность на
	выходе 1 и 2 равна -4. Это относится к команде «Рабочие регистры синтезатора
	платы ППРМ-2. Пакет 1…8».
*/
	E_OutFreq->Text=1900;
	/*
	M_Debug->Lines->Clear();
	M_Debug->Lines->Add(Reg[0]);
	M_Debug->Lines->Add(Reg[1]);
	M_Debug->Lines->Add(Reg[4]);
	*/
/*
	д) Передать команду «Частота среза фильтра гетеродина приемника ППРМ-2»
	(см. режим тестирование программы Controltesting). Значение команды 3145 МГц.
*/
	CB_Com8->ItemIndex=14;

	for(int i=0; i<16; i++)
	{
	  int code;
	  if(CB_Com8->ItemIndex==i) code=14+128*i;    // получение кода параметра
	  int code_LSB=code&0xFF;                     // младший байт параметра
	  int code_MSB=(code/256)&0xFF;               // старший байт параметра
	  Com8[2]=code_MSB;                           // записать значение старшего байта параметра
	  Com8[3]=code_LSB;                           // записать значение младшего байта параметра
    }

	if(ChB_Com8->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com8[i]);
	  }
	  Delay();                                    // задержка
	}
/*
	е) Передать команду «Частота среза фильтра гетеродина передатчика ППРМ-2»
    (см. режим тестирование программы Controltesting). Значение команды 3145 МГц.
*/
	CB_Com9->ItemIndex=14;

	for(int i=0; i<16; i++)
	{
	  int code;
	  if(CB_Com9->ItemIndex==i) code=14+128*i;    // получение кода параметра
	  int code_LSB=code&0xFF;                     // младший байт параметра
	  int code_MSB=(code/256)&0xFF;               // старший байт параметра
	  Com9[2]=code_MSB;                           // записать значение старшего байта параметра
	  Com9[3]=code_LSB;                           // записать значение младшего байта параметра
    }

	if(ChB_Com9->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com9[i]);
	  }
	  Delay();                                    // задержка
	}

//  ж) Передать команду «Смещение I-ой составляющей». Команда F600FFDЕ.

	CB_Com21->ItemIndex=290;

	if(CB_Com21->ItemIndex<257)
	{
	  for(int i=0; i<257; i++)
	  {
		int code;
		if(CB_Com21->ItemIndex==i) code=256-i;      // получение кода параметра
		int code_LSB=code&0xFF;                     // младший байт параметра
		int code_MSB=(code/256)&0xFF;               // старший байт параметра
		Com21[2]=code_MSB;                          // записать значение старшего байта параметра
		Com21[3]=code_LSB;                          // записать значение младшего байта параметра
	  }
	}

	if(CB_Com21->ItemIndex>=257)
	{
	  for(int i=257; i<514; i++)
	  {
		long int code;
		if(CB_Com21->ItemIndex==i) code=65535+257-i;  // получение кода параметра
		int code_LSB=code&0xFF;                       // младший байт параметра
		int code_MSB=(code/256)&0xFF;                 // старший байт параметра
		Com21[2]=code_MSB;                            // записать значение старшего байта параметра
		Com21[3]=code_LSB;                            // записать значение младшего байта параметра
	  }
	}

	if(ChB_Com21->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com21[i]);
	  }
	  Delay();                                 // задержка
	}

//  З) Передать команду «Смещение Q-ой составляющей». Команда F7000038.

	CB_Com22->ItemIndex=200;

	if(CB_Com22->ItemIndex<257)
	{
	  for(int i=0; i<257; i++)
	  {
		int code;
		if(CB_Com22->ItemIndex==i) code=256-i;      // получение кода параметра
		int code_LSB=code&0xFF;                     // младший байт параметра
		int code_MSB=(code/256)&0xFF;               // старший байт параметра
		Com22[2]=code_MSB;                          // записать значение старшего байта параметра
		Com22[3]=code_LSB;                          // записать значение младшего байта параметра
	  }
	}

	if(CB_Com22->ItemIndex>=257)
	{
	  for(int i=257; i<514; i++)
	  {
		long int code;
		if(CB_Com22->ItemIndex==i) code=65535+257-i;  // получение кода параметра
		int code_LSB=code&0xFF;                       // младший байт параметра
		int code_MSB=(code/256)&0xFF;                 // старший байт параметра
		Com22[2]=code_MSB;                            // записать значение старшего байта параметра
		Com22[3]=code_LSB;                            // записать значение младшего байта параметра
	  }
	}

	if(ChB_Com22->Checked==false)
	{
	  for(int i=0; i<4; i++)
	  {
		CommPort1->PutChar((char)Com22[i]);
	  }
	  Delay();                                 // задержка
	}
  }

  CommPort1->Open=false;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::IntToHexStr(unsigned int v)
{
   AnsiString S;
   S.sprintf("%X", v);
   return S;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CB_AllCom_Click(TObject *Sender)
{
  if(CB_AllCom_->Checked==true)
  {
	ChB_Com3->Checked=true;
	ChB_Com6->Checked=true;
	ChB_Com7->Checked=true;
	ChB_Com8->Checked=true;
	ChB_Com9->Checked=true;
	ChB_Com10->Checked=true;
	ChB_Com11->Checked=true;
	ChB_Com13->Checked=true;
	ChB_Com21->Checked=true;
	ChB_Com22->Checked=true;
  }
  else
  {
	ChB_Com3->Checked=false;
	ChB_Com6->Checked=false;
	ChB_Com7->Checked=false;
	ChB_Com8->Checked=false;
	ChB_Com9->Checked=false;
	ChB_Com10->Checked=false;
	ChB_Com11->Checked=false;
	ChB_Com13->Checked=false;
	ChB_Com21->Checked=false;
	ChB_Com22->Checked=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::VIPWorkON(void)  // Режим «Работа Вкл» блока ВИП
{
  FPRD=true;
/*
  Нажатие на кнопку «Включить» должно инициировать следующие действия для блока ВИП:
  1)	Установить на выводах порта P0 NI6008 все нули.
  2)	Установить на выводе P0.0 – логическую «1» на 200 мс;
*/
  DevP0[0]=1;                              // 1->DevP0[0]

  SetDevPN(VIP, DevP0, 0);                 // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                          // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                        // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP
	 T_mSec3->Enabled=true;                              // задержка 200 мс
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 SB_OnOff->Enabled=false;
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
  F_Tumbler->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_mSec3Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_mSec3->Enabled=false;

  DevP0[0]=0;                              // 1->DevP0[0]

  SetDevPN(VIP, DevP0, 0);                 // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                          // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                        // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP

	 //3)	Вывести на экран информационное сообщение «Включите тумблер питания ВК-ПРД».
	 F_Tumbler->ShowModal();
	 while(!FPRDON) {};
	 //M_Debug->Lines->Add(123);

	 //5)	Выдержать паузу 1 с.
	 T_Sec35->Enabled=true;                              // задержка 1 с
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec4Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec4->Enabled=false;

//8)	Выдержать паузу 1 с. Установить на выводе P0.2 – логическую «1»;
  DevP0[2]=1;                            // 0->DevP0[2]

  SetDevPN(VIP, DevP0, 2);               // if VIP DevP0[2]->Dev1P0[2]
  DevToP0P1(VIP);                        // if VIP Dev1PX[2]->Px[2]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;   // запись цифровых портов VIP

//   9)	Выдержать паузу 1 с.
     T_Sec45->Enabled=true;
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::VIPWorkOFF(void)  // Режим «Работа Выкл» блока ВИП
{
  FPRD=false;
/*
  Нажатие на кнопку «Выключить» должно инициировать следующие действия для блока ВИП:
  1)	Установить на выводе P0.0 – логический «1»;
*/
  DevP0[0]=1;                            // 0->DevP0[0]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                        // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;   // запись цифровых портов VIP
//   2)	Установить на выводе P0.2 – логический «0»;
	 DevP0[2]=0;                        // 0->DevP0[2]

	 SetDevPN(VIP, DevP0, 2);           // if VIP DevP0[2]->Dev1P0[2]
	 DevToP0P1(VIP);                    // if VIP Dev1PX[2]->Px[2]

	 SetDev_port(VIP);                  // if VIP Dev1_portX->Dev_portX
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP

	 T_Sec5->Enabled=true;                               // задержка 1 с
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec5Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec5->Enabled=false;

//3)	Выдержать паузу 1 с. Установить на выводе P0.1 – логический «0»;
  DevP0[1]=0;                            // 0->DevP0[2]

  SetDevPN(VIP, DevP0, 1);               // if VIP DevP0[1]->Dev1P0[1]
  DevToP0P1(VIP);                        // if VIP Dev1PX[1]->Px[1]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;   // запись цифровых портов VIP
//   4)	Установить на выводе P0.0 – логический «0»;
	 DevP0[0]=0;                         // 0->DevP0[0]

	 SetDevPN(VIP, DevP0, 0);            // if VIP DevP0[0]->Dev1P0[0]
	 DevToP0P1(VIP);                     // if VIP Dev1PX[0]->Px[0]

	 SetDev_port(VIP);                   // if VIP Dev1_portX->Dev_portX
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP

//	 5)	Вывести на экран информационное сообщение «Выключите тумблер питания ВК-ПРД».
	 //F_Tumbler2->ShowModal();
	 //M_Debug->Lines->Add(1);
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec35Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec35->Enabled=false;

//6)	Установить на выводе P0.0 – логическую «1»;
  DevP0[0]=1;                            // 0->DevP0[0]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                        // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;   // запись цифровых портов VIP

//   7)	Установить на выводе P0.1 – логическую «1»;
	 DevP0[1]=1;                         // 0->DevP0[1]

	 SetDevPN(VIP, DevP0, 1);            // if VIP DevP0[1]->Dev1P0[1]
	 DevToP0P1(VIP);                     // if VIP Dev1PX[1]->Px[1]

	 SetDev_port(VIP);                   // if VIP Dev1_portX->Dev_portX
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;  // запись цифровых портов VIP

	 T_Sec4->Enabled=true;                               // задержка 1 с

  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 //exit(1);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::T_Sec45Timer(TObject *Sender)
{
  if(P_OneSec->Color==clBlue) P_OneSec->Color=clYellow;
  else
  if(P_OneSec->Color==clYellow) P_OneSec->Color=clBlue;

  T_Sec45->Enabled=false;

//10)	Установить на выводе P0.0 – логический «0»;
  DevP0[0]=0;                            // 0->DevP0[0]

  SetDevPN(VIP, DevP0, 0);               // if VIP DevP0[0]->Dev1P0[0]
  DevToP0P1(VIP);                        // if VIP Dev1PX[0]->Px[0]

  SetDev_port(VIP);                      // if VIP Dev1_portX->Dev_portX
  try
  {
	 if(!SetDevP0P1Data(Dev_port0, Dev_port1)) throw 3;   // запись цифровых портов VIP
  }

  catch(...)
  {
	 Application->MessageBox(L"Ошибка записи в блок ВИП!",L"Внимание",MB_ICONWARNING);
	 //exit(1);
  }
}
//---------------------------------------------------------------------------

