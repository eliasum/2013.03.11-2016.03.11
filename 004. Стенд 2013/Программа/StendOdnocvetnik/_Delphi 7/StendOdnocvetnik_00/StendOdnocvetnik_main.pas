unit StendOdnocvetnik_main;
{
  � Delphi � �������� ������ pas (�������, ��� �������, � �������� �������� ����
  ���������) �� ������ �������� ������� ������� ������� ���������� �� ������������
  ������ � ������ ����������. � ������������ ����� ���������� ���� ����������
  ����� � �������, ����� ��� ��� ���������� � ������������ ����� �� �����������
  �� ������ ����������.
}
interface // ���������� ������� ��������� ����� ������

uses      // ������� ������
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
  ���������� 1:
  P0.0, P0.1, P0.2 = 1 - ������� ���, = 0 - ����.;
  P0.3, P0.4, P0.5 = 1 - �������� ������� ����� ��� ���, = 0 - ����.;
  P0.0 - ������ �������� -6�;
  P0.1 - ������ �������� +6�;
  P0.2 - ������ �������� +20�;
  P0.3 - ������ ��������� ������� ����� ��� -6�;
  P0.4 - ������ ��������� ������� ����� ��� +6�;
  P0.5 - ������ ��������� ������� ����� ��� +20�;
  P0.6 - ������ ������� ��������� ����������� �������� ��������;
  P1.0 - ������ ������� � ��������� ���������� 1, = 0 - ��������;

  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �1
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �1
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �1
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �1
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �1
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �1

  ���������� 2:
  P1.0 - ������ ������� � ��������� ���������� 2, = 0 - ��������;

  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �2
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �2
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �2
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �2
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �2
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �2

  ���������� 3:
  P1.0 - ������ ������� � ��������� ���������� 3, = 0 - ��������;

  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �3
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �3
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �3
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �3
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �3
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �3

  ���������� 4:
  P1.0 - ������ ������� � ��������� ���������� 4, = 0 - ��������;

  AI0 - ������ �������������� ���� �������� ��������� ������� -6� ������ �4
  AI1 - ������ �������������� ���������� ������� ��������� ������� -6� ������ �4
  AI2 - ������ �������������� ���� �������� ��������� ������� +6� ������ �4
  AI3 - ������ �������������� ���������� ������� ��������� ������� +6� ������ �4
  AI4 - ������ �������������� ���� �������� ��������� ������� +20� ������ �4
  AI5 - ������ �������������� ���������� ������� ��������� ������� +20� ������ �4
}
var
{
  ���������� ���������� � ������������ ������ (interfase). �� ���� ����������, �����������
  �����, ����� ���������� ��� � �������� ����� ������, ��� � � ������ �������, � �������
  ��������� ������.
  ���������� ������������� �������������� ���������� ���������� ��� "������".
  ������������� �������� ��������������� ������� �. ��������� �������� ������� '',
  � ��������� � ������� False. ���������� �������� ����� ����� ����������������
  ������� ��� �� ����������:
}
  MainForm: TMainForm; // ���������� ����������
  My_Patch: string;
  logFname: string;
  FileStend: string = '';

  P0: array[0..7] of char;
  P1: array[0..3] of char;
{
  ����������� �������� ����� � ���������� ���������� ������� ������ ���,
  � ��� �� ����� ����� � ������ �������
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

  // ���������� U � I �� ������������ ��������:
  Umin: double = 0.7;
  Umax: double = 1.3;
  Imin: double = 0.95;
  Imax: double = 1.05;

  value: double;

  k1: integer = 1;
  k2: integer = 2;

  // ���������� ���������� ���������:
  Checkm6VCounter: integer = -1;
  Checkp6VCounter: integer = -1;
  Checkp20VCounter: integer = -1;

  Tpause: integer = 0;
  Twork: integer = 0;
  Count: integer = 0;

const

  NumReadValue: integer = 10;



implementation // ������������ ��������� ����� ������ (����������)

{$R *.dfm} // ��������� {$R} - �������� ���������� �������� �������� �������� � �����

{
var

���������� ���������� � ���� ������ (������ implementation). �� ���� ����������, �����������
�����, ����� ���������� ������ � �������� ����� ������.
}

procedure TMainForm.ExitClick(Sender: TObject);
begin
  Close;
end;

procedure TMainForm.FormCreate(Sender: TObject);
var DateTime: string;
begin
{
  function ExtractFilePath(const FileName: string): string; - ���� � ����������� �����.
  function GetCurrentDir: string; - ���� � ������� ����������.
  ��� �� ������� ���������, ������� ������� �������� �� ����������,
  �������  �� ������� ������� ����� � ����� �������� � ��������.
}
  My_Patch := ExtractFilePath(Application.ExeName);  // ���� � ����������� �����

  if(DirectoryExists(My_Patch + 'log �����') = false) then
  begin
    if(CreateDir(My_Patch + 'log �����') = false) then
      ShowMessage('�� ������� ������� ���������� �������� log ������!')
    else
      ShowMessage('������� ���������� ��� �������� log ������!')
  end;
{
  function DirectoryExists(const Directory: string): Boolean;
  ������� DirectoryExists ���������� True, ���� ������ Directory ���� ����������.
  ������� ������������� � ������� ��������. False ����� ���� ����������, ���� ������������ ��
  ��������� ������ ����.

  function CreateDir(const Dir: string): Boolean;
  ������� CreateDir ������ ����� � ������� ����������.
  ���� ����� ���� �������, �� ������� ����� True, ���� ���, �� ������ ����� ���� ��������
  � ������� ������� function GetLastError: Integer; stdcall;.

  function FormatDateTime(const Format: string; DateTime: TDateTime): string; overload;
 - ������ ��������, �������������� ����� ���� ��� �����. ������ �������������
  ������ ������ ������� string, ��������, ������ dd/mm/yyyy ������, ��� ��������� ������� �������� ����,
  � ������ hh:mm � �����
}
  DateTime:= FormatDateTime('YYYY.MM.DD',Date())+'_'+FormatDateTime('HH-NN-SS',Time()); // ������� ���� � �����
  logFname := DateTime;              // ������ ����� ��� ����� � ����� ��� �������� ���������
  AddSaveLog('��������� ��������');  // �������� ����������� � ��������� ���

end;

procedure TMainForm.AddSaveLog(comment: string);
begin
  My_Patch := ExtractFilePath(Application.ExeName);  // ���� � ����������� �����

  if(DirectoryExists(My_Patch + 'log �����') = false) then
  begin
    if(CreateDir(My_Patch + 'log �����') = false) then
      ShowMessage('�� ������� ������� ���������� �������� log ������!')
    else
      ShowMessage('������� ���������� ��� �������� log ������!');
  end;
{
  function Now: TDateTime; - ��������� ���� � ����� � �������� ���� TDateTime;
  function DateTimeToStr(DateTime: TDateTime): string; overload;
 - ������ ��������, ������������ ���� � ������� dd.mm.yyyy � ����� ������� hh:mm:ss
}

  M_Log.Lines.Add(DateTimeToStr(Now())+' '+comment); // �������� ������ � ��� � ������� ��������
{
  function ExtractFilePath(const FileName: string): string; - ���� � ����������� �����.
  function GetCurrentDir: string; - ���� � ������� ����������.
  ��� �� ������� ���������, ������� ������� �������� �� ����������,
  �������  �� ������� ������� ����� � ����� �������� � ��������.
}
  M_Log.Lines.SaveToFile(My_Patch+'\log �����\'+logFname+'.log'); // ������ ��� �����
end;

procedure TMainForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  AddSaveLog('��������� �������'); // �������� ����������� � ��������� ���  
end;

end.
