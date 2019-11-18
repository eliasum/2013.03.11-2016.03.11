unit StendOdnocvetnik_main;
{
  В Delphi в исходных файлах pas (которые, как правило, и содержат основное тело
  программы) на уровне языковых средств введено строгое разделение на интерфейсный
  раздел и раздел реализации. В интерфейсной части содержатся лишь объявления
  типов и методов, тогда как код реализации в интерфейсной части не допускается
  на уровне компиляции.
}
interface // Определяет внешнюю видимость этого модуля

uses      // Частные модули
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ImgList, Menus, ExtCtrls, ComCtrls, ToolWin, StdCtrls;

type
  TMainForm = class(TForm)
    StatusBar1: TStatusBar;
    L_Danger: TLabel;
    GB_Channel1: TGroupBox;
    LE_U_IPO1: TLabeledEdit;
    StaticText1: TStaticText;
    LE_I_IPO1: TLabeledEdit;
    StaticText2: TStaticText;
    LE_U_IPP1: TLabeledEdit;
    StaticText3: TStaticText;
    LE_I_IPP1: TLabeledEdit;
    StaticText4: TStaticText;
    LE_U_IMP1: TLabeledEdit;
    StaticText5: TStaticText;
    LE_I_IMP1: TLabeledEdit;
    StaticText6: TStaticText;
    P_Mode1: TPanel;
    StaticText7: TStaticText;
    P_Protection1: TPanel;
    StaticText8: TStaticText;
    RB_Selected1: TRadioButton;
    P_Selected1: TPanel;
    StaticText40: TStaticText;
    P_Overheat1: TPanel;
    GB_Channel2: TGroupBox;
    LE_U_IPO2: TLabeledEdit;
    StaticText10: TStaticText;
    LE_I_IPO2: TLabeledEdit;
    StaticText11: TStaticText;
    LE_U_IPP2: TLabeledEdit;
    StaticText12: TStaticText;
    LE_I_IPP2: TLabeledEdit;
    StaticText13: TStaticText;
    LE_U_IMP2: TLabeledEdit;
    StaticText14: TStaticText;
    LE_I_IMP2: TLabeledEdit;
    StaticText15: TStaticText;
    P_Mode2: TPanel;
    StaticText16: TStaticText;
    P_Protection2: TPanel;
    StaticText17: TStaticText;
    RB_Selected2: TRadioButton;
    P_Selected2: TPanel;
    StaticText9: TStaticText;
    P_Overheat2: TPanel;
    GB_Channel3: TGroupBox;
    LE_U_IPO3: TLabeledEdit;
    StaticText19: TStaticText;
    LE_I_IPO3: TLabeledEdit;
    StaticText20: TStaticText;
    LE_U_IPP3: TLabeledEdit;
    StaticText21: TStaticText;
    LE_I_IPP3: TLabeledEdit;
    StaticText22: TStaticText;
    LE_U_IMP3: TLabeledEdit;
    StaticText23: TStaticText;
    LE_I_IMP3: TLabeledEdit;
    StaticText24: TStaticText;
    P_Mode3: TPanel;
    StaticText25: TStaticText;
    P_Protection3: TPanel;
    StaticText26: TStaticText;
    RB_Selected3: TRadioButton;
    P_Selected3: TPanel;
    StaticText18: TStaticText;
    P_Overheat3: TPanel;
    GB_Channel4: TGroupBox;
    LE_U_IPO4: TLabeledEdit;
    StaticText28: TStaticText;
    LE_I_IPO4: TLabeledEdit;
    StaticText29: TStaticText;
    LE_U_IPP4: TLabeledEdit;
    StaticText30: TStaticText;
    LE_I_IPP4: TLabeledEdit;
    StaticText31: TStaticText;
    LE_U_IMP4: TLabeledEdit;
    StaticText32: TStaticText;
    LE_I_IMP4: TLabeledEdit;
    StaticText33: TStaticText;
    P_Mode4: TPanel;
    StaticText34: TStaticText;
    P_Protection4: TPanel;
    StaticText35: TStaticText;
    RB_Selected4: TRadioButton;
    P_Selected4: TPanel;
    StaticText27: TStaticText;
    P_Overheat4: TPanel;
    StaticText38: TStaticText;
    B_Go: TButton;
    B_Stop: TButton;
    LE_Cycles: TLabeledEdit;
    StaticText39: TStaticText;
    M_Log: TMemo;
    Button2: TButton;
    Memo1: TMemo;
    ToolBar1: TToolBar;
    ToolButton1: TToolButton;
    ToolButton4: TToolButton;
    TB_LoadStend: TToolButton;
    ToolButton6: TToolButton;
    ToolButton7: TToolButton;
    TB_HelpAboutItem: TToolButton;
    T_Checkm6V: TTimer;
    T_Checkp6V: TTimer;
    T_Checkp20V: TTimer;
    T_Work: TTimer;
    T_Log: TTimer;
    T_Overheat: TTimer;
    T_Pause: TTimer;
    T_Danger: TTimer;
    MainMenu: TMainMenu;
    M_File: TMenuItem;
    LoadStend: TMenuItem;
    N1: TMenuItem;
    Exit: TMenuItem;
    Help: TMenuItem;
    HelpAboutItem: TMenuItem;
    ImageList1: TImageList;
    OpenDialog1: TOpenDialog;
    ST_Enterprise: TStaticText;
    Button1: TButton;
    procedure ExitClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure AddSaveLog(comment: string);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
  end;
{
  Устройство 1:
  P0.0, P0.1, P0.2 = 1 - тумблер вкл, = 0 - выкл.;
  P0.3, P0.4, P0.5 = 1 - источник питания блока ИПИ вкл, = 0 - выкл.;
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
}
var
{
  Объявление переменных в интерфейсной секции (interfase). Ко всем переменным, объявленным
  здесь, можно обращаться как в пределах этого модуля, так и в других модулях, к которым
  подключен данный.
  Компилятор автоматически инициализирует глобальные переменные как "пустые".
  Целочисленные значения устанавливаются равными О. строковые значения равными '',
  а булевские — равными False. Глобальные значения можно также инициализировать
  вручную при их объявлении:
}
  MainForm: TMainForm; // глобальные переменные
  My_Patch: string;
  logFname: string;
  FileStend: string = '';

  P0: array[0..7] of char;
  P1: array[0..3] of char;
{
  номинальные значения токов и напряжений источников питания блоков ИПИ,
  а так же время паузы и работы каналов
}
  Nominal1: array[0..7] of string = ('0', '0', '0', '0', '0', '0', '0', '0');
  Nominal2: array[0..7] of string = ('0', '0', '0', '0', '0', '0', '0', '0');
  Nominal3: array[0..7] of string = ('0', '0', '0', '0', '0', '0', '0', '0');
  Nominal4: array[0..7] of string = ('0', '0', '0', '0', '0', '0', '0', '0');

  FNominal1: array[0..7] of double = (0, 0, 0, 0, 0, 0, 0, 0);
  FNominal2: array[0..7] of double = (0, 0, 0, 0, 0, 0, 0, 0);
  FNominal3: array[0..7] of double = (0, 0, 0, 0, 0, 0, 0, 0);
  FNominal4: array[0..7] of double = (0, 0, 0, 0, 0, 0, 0, 0);

  ErrorADC: boolean;
  greenflag1: boolean = false;
  greenflag2: boolean = false;
  greenflag3: boolean = false;
  greenflag4: boolean = false;

  // отклонения U и I от номинального значения:
  Umin: double = 0.7;
  Umax: double = 1.3;
  Imin: double = 0.95;
  Imax: double = 1.05;

  value: double;

  k1: integer = 1;
  k2: integer = 2;

  // переменные управления таймерами:
  Checkm6VCounter: integer = -1;
  Checkp6VCounter: integer = -1;
  Checkp20VCounter: integer = -1;

  Tpause: integer = 0;
  Twork: integer = 0;
  Count: integer = 0;

const

  NumReadValue: integer = 10;



implementation // Осуществляет Интерфейс этого модуля (реализация)

{$R *.dfm} // Директива {$R} - проверка допустимых значений индексов массивов и строк

{
var

Объявление переменных в теле модуля (секция implementation). Ко всем переменным, объявленным
здесь, можно обращаться только в пределах этого модуля.
}

procedure TMainForm.ExitClick(Sender: TObject);
begin
  Close;
end;

procedure TMainForm.FormCreate(Sender: TObject);
var DateTime: string;
begin
{
  function ExtractFilePath(const FileName: string): string; - путь к исполнимому файлу.
  function GetCurrentDir: string; - путь к текущей директории.
  Они не обязаны совпадать, текущий каталог величина не постоянная,
  зависит  от способа запуска проги и может меняться в процессе.
}
  My_Patch := ExtractFilePath(Application.ExeName);  // путь к исполнимому файлу

  if(DirectoryExists(My_Patch + 'log файлы') = false) then
  begin
    if(CreateDir(My_Patch + 'log файлы') = false) then
      ShowMessage('Не удается создать директорию хранения log файлов!')
    else
      ShowMessage('Создана директория для хранения log файлов!')
  end;
{
  function DirectoryExists(const Directory: string): Boolean;
  Функция DirectoryExists возвращает True, если данный Directory файл существует.
  Каталог разыскивается в текущем каталоге. False может быть возвращена, если пользователю не
  разрешено видеть файл.

  function CreateDir(const Dir: string): Boolean;
  Функция CreateDir создаёт папку в текущей директории.
  Если папка была создана, то функция вернёт True, если нет, то ошибка может быть получена
  с помощью функции function GetLastError: Integer; stdcall;.

  function FormatDateTime(const Format: string; DateTime: TDateTime): string; overload;
 - Строка символов, представляющая собой дату или время. Способ представления
  задает строка формата string, например, строка dd/mm/yyyy задает, что значением функции является дата,
  а строка hh:mm – время
}
  DateTime:= FormatDateTime('YYYY.MM.DD',Date())+'_'+FormatDateTime('HH-NN-SS',Time()); // текущая дата и время
  logFname := DateTime;              // запись имени лог файла в буфер при открытии программы
  AddSaveLog('Программа запущена');  // добавить комментарий и сохранить лог

end;

procedure TMainForm.AddSaveLog(comment: string);
begin
  My_Patch := ExtractFilePath(Application.ExeName);  // путь к исполнимому файлу

  if(DirectoryExists(My_Patch + 'log файлы') = false) then
  begin
    if(CreateDir(My_Patch + 'log файлы') = false) then
      ShowMessage('Не удается создать директорию хранения log файлов!')
    else
      ShowMessage('Создана директория для хранения log файлов!');
  end;
{
  function Now: TDateTime; - Системная дата и время – значение типа TDateTime;
  function DateTimeToStr(DateTime: TDateTime): string; overload;
 - Строка символов, изображающая дату в формате dd.mm.yyyy и время формате hh:mm:ss
}

  M_Log.Lines.Add(DateTimeToStr(Now())+' '+comment); // добавить запись в лог с текущим временем
{
  function ExtractFilePath(const FileName: string): string; - путь к исполнимому файлу.
  function GetCurrentDir: string; - путь к текущей директории.
  Они не обязаны совпадать, текущий каталог величина не постоянная,
  зависит  от способа запуска проги и может меняться в процессе.
}
  M_Log.Lines.SaveToFile(My_Patch+'\log файлы\'+logFname+'.log'); // запись лог файла
end;

procedure TMainForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  AddSaveLog('Программа закрыта'); // добавить комментарий и сохранить лог  
end;

end.
