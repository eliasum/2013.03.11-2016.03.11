unit TestOdnocvetnik_main;
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
  Dialogs, Menus, sSkinManager, ComCtrls, ToolWin, sToolBar, StdCtrls,
  sEdit, ImgList;

type
  TMainForm = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    LE_Inomm6V: TsEdit;
    sToolBar1: TsToolBar;
    ToolButton2: TToolButton;
    TB_SaveStend: TToolButton;
    ToolButton8: TToolButton;
    ToolButton9: TToolButton;
    TB_LoadStend: TToolButton;
    ToolButton11: TToolButton;
    ToolButton12: TToolButton;
    TB_HelpAboutItem: TToolButton;
    LE_Unomm6V: TsEdit;
    LE_Inomp6V: TsEdit;
    LE_Unomp6V: TsEdit;
    LE_Inomp20V: TsEdit;
    LE_Unomp20V: TsEdit;
    LE_Tpause: TsEdit;
    LE_Twork: TsEdit;
    sSkinManager1: TsSkinManager;
    MainMenu1: TMainMenu;
    M_File: TMenuItem;
    SaveStend: TMenuItem;
    N1: TMenuItem;
    LoadStend: TMenuItem;
    N2: TMenuItem;
    Exit: TMenuItem;
    Help: TMenuItem;
    HelpAboutItem: TMenuItem;
    ImageList1: TImageList;
    OpenDialog1: TOpenDialog;
    SaveDialog1: TSaveDialog;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

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

implementation // Осуществляет Интерфейс этого модуля (реализация)

{$R *.dfm} // Директива {$R} - проверка допустимых значений индексов массивов и строк

{
var

Объявление переменных в теле модуля (секция implementation). Ко всем переменным, объявленным
здесь, можно обращаться только в пределах этого модуля.
}
  My_Patch: string;
  FileStend: string = '';

end.
