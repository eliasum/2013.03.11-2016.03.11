unit TestOdnocvetnik_main;
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
  ���������� ���������� � ������������ ������ (interfase). �� ���� ����������, �����������
  �����, ����� ���������� ��� � �������� ����� ������, ��� � � ������ �������, � �������
  ��������� ������.
  ���������� ������������� �������������� ���������� ���������� ��� "������".
  ������������� �������� ��������������� ������� �. ��������� �������� ������� '',
  � ��������� � ������� False. ���������� �������� ����� ����� ����������������
  ������� ��� �� ����������:
}
  MainForm: TMainForm; // ���������� ����������

implementation // ������������ ��������� ����� ������ (����������)

{$R *.dfm} // ��������� {$R} - �������� ���������� �������� �������� �������� � �����

{
var

���������� ���������� � ���� ������ (������ implementation). �� ���� ����������, �����������
�����, ����� ���������� ������ � �������� ����� ������.
}
  My_Patch: string;
  FileStend: string = '';

end.
