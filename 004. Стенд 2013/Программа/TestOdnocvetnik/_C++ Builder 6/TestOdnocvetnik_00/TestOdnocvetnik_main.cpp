//---------------------------------------------------------------------------
// директивы препроцессора #include подключают в данный файл тексты указанных в них файлов
#include <vcl.h>  // объявления, используемые в библиотеке визуальных компонентов С++Builder
#pragma hdrstop   // конец списка общих заголовочных файлов для всех модулей проекта

#include "TestOdnocvetnik_main.h"
#include "AboutBox.h"
#include <fstream>    // Файловые операции ввода-вывода
using namespace std;

String FileStend="";
TLabeledEdit *Parameter;
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* директива определяет последовательность инициализации пакетов такой, какая
устанавливается взаимными ссылками использующих их модулей */
#pragma resource "*.dfm"  // для формы надо использовать файл .dfm с тем же именем, что и имя данного файла
TMainForm *MainForm;      // объявление указателя на объект формы Main_Form
TIniFile *Ini;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
  : TForm(Owner)
{
  if(!DirectoryExists(My_Patch + "Файлы испытаний"))
  {
    if(!CreateDir(My_Patch + "Файлы испытаний"))
      ShowMessage("Не удается создать директорию хранения файлов испытаний!");
    else
      ShowMessage("Создана директория для хранения файлов испытаний!");
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
void __fastcall TMainForm::ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TB_HelpAboutItemClick(TObject *Sender)
{
  F_AboutBox->ShowModal();    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TB_SaveStendClick(TObject *Sender)
{
  SaveDialog1->DefaultExt=".stend";
  SaveDialog1->FileName="*.stend";
  SaveDialog1->Filter="Файл испытаний (*.stend)|*.stend";
  SaveDialog1->Title=" Сохранение файла испытаний";

  String File;
  FILE *F;

  if(SaveDialog1->Execute())
  {
    File=SaveDialog1->FileName;
    FileStend=File;
    if(F!=NULL)
    {
      F=fopen(File.c_str(),"w+"); // открыть файл с перезаписью
      fclose(F);                  // закрыть файл
    }
    Ini= new TIniFile(File); // создание нового файла .ini
/*
    Ini->WriteString("Название секции","Имя переменной", "значение");
*/
    Ini->WriteString("Стенд","Iном-6В",LE_Inomm6V->Text);
    Ini->WriteString("Стенд","Uном-6В",LE_Unomm6V->Text);
    Ini->WriteString("Стенд","Iном+6В",LE_Inomp6V->Text);
    Ini->WriteString("Стенд","Uном+6В",LE_Unomp6V->Text);
    Ini->WriteString("Стенд","Iном+20В",LE_Inomp20V->Text);
    Ini->WriteString("Стенд","Uном+20В",LE_Unomp20V->Text);
    Ini->WriteString("Стенд","Tпаузы",LE_Tpause->Text);
    Ini->WriteString("Стенд","Tработы",LE_Twork->Text);

    delete Ini;
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
      LE_Inomm6V->Text=Ini->ReadString("Стенд","Iном-6В","1");
      LE_Unomm6V->Text=Ini->ReadString("Стенд","Uном-6В","1");
      LE_Inomp6V->Text=Ini->ReadString("Стенд","Iном+6В","1");
      LE_Unomp6V->Text=Ini->ReadString("Стенд","Uном+6В","1");
      LE_Inomp20V->Text=Ini->ReadString("Стенд","Iном+20В","1");
      LE_Unomp20V->Text=Ini->ReadString("Стенд","Uном+20В","1");
      LE_Tpause->Text=Ini->ReadString("Стенд","Tпаузы","1");
      LE_Twork->Text=Ini->ReadString("Стенд","Tработы","1");

      delete Ini;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LE_Inomm6VKeyPress(TObject *Sender, char &Key)
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
void __fastcall TMainForm::LE_TpauseKeyPress(TObject *Sender, char &Key)
// запрет введения любых символов, кроме чисел 0...9
{
  Set<char,0,255>Dig;
	Dig<<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9'<<8;
	if(!Dig.Contains(Key))
	{
	  Key=0;
	  return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LE_Inomm6VChange(TObject *Sender)
{
  DefaultValue(LE_Inomm6V);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DefaultValue(TLabeledEdit *Parameter)
{
  if(Parameter->Text=="") Parameter->Text=0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LE_Unomm6VChange(TObject *Sender)
{
  DefaultValue(LE_Unomm6V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_Inomp6VChange(TObject *Sender)
{
  DefaultValue(LE_Inomp6V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_Unomp6VChange(TObject *Sender)
{
  DefaultValue(LE_Unomp6V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_Inomp20VChange(TObject *Sender)
{
  DefaultValue(LE_Inomp20V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_Unomp20VChange(TObject *Sender)
{
  DefaultValue(LE_Unomp20V);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_TpauseChange(TObject *Sender)
{
  DefaultValue(LE_Tpause);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LE_TworkChange(TObject *Sender)
{
  DefaultValue(LE_Twork);
}
//---------------------------------------------------------------------------

