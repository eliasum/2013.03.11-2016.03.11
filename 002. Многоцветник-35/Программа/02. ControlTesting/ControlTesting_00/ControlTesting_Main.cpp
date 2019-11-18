//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include "ControlTesting_Main.h"
#include "BT.h"
#include "Sar1.h"
#include "Sar2.h"
#include "Sar3.h"
#include "Sar4.h"
#include <iostream>
/*
iostream � ������������ ���� � ��������, ��������� � ����������� ��� ����������� �����-������
� ����� ���������������� C++. �� ������� � ����������� ���������� C++. �������� ���������� ��
Input/Output Stream (������ �����-������). � ����� C++ � ��� ���������������, �����
���������������� ��, ��� ���������� ��������� �����-������, ������ ����� ������������ ����������
�������. iostream ��������� ������-�������, ��� � stdio.h � ��. iostream ���������� ������� cin,
cout, cerr � clog ��� �������� ���������� � � �� ����������� ������� �����, ������, ������
(��� �����������) � ������ (� ������������) ��������������. ������� ������ �����������
���������� C++, ��� ������� ����� �������� ������ ������������ ������������ ��� � std.
*/
#include <fstream> // �������� �������� �����-������

using namespace std;
Boolean c1=true;    // ���� ������� ���������� ����� � LV_Sar1
Boolean c2=true;    // ���� ������� ���������� ����� � LV_Sar2
Boolean c3=true;    // ���� ������� ���������� ����� � LV_Sar3
Boolean c4=true;    // ���� ������� ���������� ����� � LV_Sar4
static int sec=0;   // ���������� ���������� �������
//---------------------------------------------------------------------------
#pragma package(smart_init)   /* ��������� ���������� ������������������ ������������� ������� �����, �����
��������������� ��������� �������� ������������ �� ������� */
#pragma resource "*.dfm"  // ��� ����� ���� ������������ ���� .dfm � ��� �� ������, ��� � ��� ������� �����
TMain_Form *Main_Form;    // ���������� ��������� �� ������ ����� Main_Form
//---------------------------------------------------------------------------
// ����� ������������ ����� Main_Form
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
  : TForm(Owner)
{
/*
  ExtractFilePath(Application->ExeName) - ���� � ����������� �����.
  GetCurrentDir() - ���� � ������� ����������.
  ��� �� ������� ���������, ������� ������� �������� �� ����������,
  �������  �� ������� ������� ����� � ����� �������� � ��������.
*/
  My_Patch = ExtractFilePath(Application->ExeName); // ���� � ����������� �����

  if(!DirectoryExists(My_Patch + "log �����"))
  {
    if(!CreateDir(My_Patch + "log �����"))
      ShowMessage("�� ������� ������� ���������� �������� log ������!");
    else
      ShowMessage("������� ���������� ��� �������� log ������!");
  }
/*
  Boolean DirectoryExists(AnsiString DirectoryName);
  ������� DirectoryExists ���������� True, ���� ������ DirectoryName ���� ����������.
  ������� ������������� � ������� ��������. False ����� ���� ����������, ���� ������������ ��
  ��������� ������ ����.

  Boolean CreateDir(AnsiString Dir);
  ������� CreateDir ������ ����� � ������� ����������.
  ���� ����� ���� �������, �� ������� ����� True, ���� ���, �� ������ ����� ���� ��������
  � ������� ������� GetLastError.
*/
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SB_OnOffClick(TObject *Sender)
{
  if(SB_OnOff->Down)         // ���� ������
  {
    SB_OnOff->Caption="���������";
    SB_OnOff->Font->Color=clRed;

    WorkTimer->Enabled=true; // �������� ������ WorkTimer
    AddSaveLog("��������");  // �������� ����������� � ��������� ���

  }
  else                       // ���� �� ������
  {
    SB_OnOff->Caption="��������";
    SB_OnOff->Font->Color=clGreen;

    AddSaveLog("���������. ����� ������ ��������� "+P_WorkTime->Caption);  // �������� ����������� � ��������� ���
    
    WorkTimer->Enabled=false;         // �������� ������ WorkTimer
    sec=0;                            // �������� �������� ������
    P_WorkTime->Caption = "00:00:00"; // �������� �������� ������� ������
/*
    ExtractFilePath(Application->ExeName) - ���� � ����������� �����.
    GetCurrentDir() - ���� � ������� ����������.
    ��� �� ������� ���������, ������� ������� �������� �� ����������,
    ������� �� ������� ������� ����� � ����� �������� � ��������.
*/
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::SystemTimerTimer(TObject *Sender)
// ������ ���������� � ������ ���������� ������� ������ 10 ��
{
/*
  FormatDateTime (s, dt) - ������ ��������, �������������� ����� ���� ��� �����. ������ �������������
  ������ ������ ������� s, ��������, ������ dd/mm/yyyy ������, ��� ��������� ������� �������� ����,
  � ������ hh:mm � �����
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+" "+FormatDateTime("HH:NN:SS",Time()); // ������� ���� � �����
  //P_SystemTime->Caption = Now();
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::WorkTimerTimer(TObject *Sender)
// ������ ���������� � ������ �������� ������� ������ 1 �
{
  static int min=0, hour=0; // ���������� ����� � �����
  sec++;                    // ������ 1000 �� ����������� �������� ���������� ������ �� 1

  if(sec>59)                // ������ 60 �
  {
    sec=0;                  // �������� �������� ������
    min++;                  // ����������� �������� ���������� ����� �� 1
  }

  if(min>59)                // ������ 60 �����
  {
    min=0;                  // �������� �������� �����
    hour++;                 // ����������� �������� ���������� ����� �� 1
  }

  // ����� ����� ������, ����� � ����� ������ ��� � �������������� 2-� ��������
  if(sec<10)  L_S->Caption="0"+IntToStr(sec);
  else        L_S->Caption=IntToStr(sec);

  if(min<10)  L_M->Caption="0"+IntToStr(min);
  else        L_M->Caption=IntToStr(min);
  
  if(hour<10) L_H->Caption="0"+IntToStr(hour);
  else        L_H->Caption=IntToStr(hour);

  P_WorkTime->Caption = L_H->Caption+":"+L_M->Caption+":"+L_S->Caption;
  P_WorkTime->Refresh(); // �������� ���������
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  AddSaveLog("��������� �������"); // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormCreate(TObject *Sender)
{
/*
  FormatDateTime (s, dt) - ������ ��������, �������������� ����� ���� ��� �����. ������ �������������
  ������ ������ ������� s, ��������, ������ dd/mm/yyyy ������, ��� ��������� ������� �������� ����,
  � ������ hh:mm � �����
*/
  P_SystemTime->Caption = FormatDateTime("YYYY.MM.DD",Date())+"_"+FormatDateTime("HH-NN-SS",Time()); // ������� ���� � �����
  logFname = P_SystemTime->Caption; // ������ ����� ��� ����� � ����� ��� �������� ���������
  AddSaveLog("��������� ��������"); // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::AddSaveLog(AnsiString comment) // �������� ����������� � ��������� ���
{
  My_Patch = ExtractFilePath(Application->ExeName); // ���� � ����������� �����

  if(!DirectoryExists(My_Patch + "log �����"))
  {
    if(!CreateDir(My_Patch + "log �����"))
      ShowMessage("�� ������� ������� ���������� �������� log ������!");
    else
      ShowMessage("������� ���������� ��� �������� log ������!");
  }
/*
  Now()- ��������� ���� � ����� � �������� ���� TDateTime;
  DateTimeToStr(Now()) - ������ ��������, ������������ ���� � ������� dd.mm.yyyy � ����� ������� hh:mm:ss
*/
  M_Log->Lines->Add(DateTimeToStr(Now())+" "+comment); // �������� ������ � ��� � ������� ��������
/*
  ExtractFilePath(Application->ExeName) - ���� � ����������� �����.
  GetCurrentDir() - ���� � ������� ����������.
  ��� �� ������� ���������, ������� ������� �������� �� ����������,
  ������� �� ������� ������� ����� � ����� �������� � ��������.
*/
  M_Log->Lines->SaveToFile(My_Patch+"\\log �����\\"+logFname+".log"); // ������ ��� �����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_EnterClick(TObject *Sender)
{
  if(E_EnterComment->Text!="") AddSaveLog(E_EnterComment->Text); // ������ ��� �����
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_LoadBlpClick(TObject *Sender) // ������� �� ������ "������� ���� .blp"
{
/*
  ������ ��� ������ � ������� ��������� ��� ������� ��������� �������:

  ofstream - ��� ������ (������) ������ � ����;
  ifstream - ��� ����� (������) ������ �� �����;
  fstream - ��� ������ � ��� ������ ������ (��������������� �����).

  ����� ������������ ��� ������, � ����� ��������� ���������� �������� �������������� ������������
  ���� fstream.h. ����� ����� � ��������� ����� ���������� ���������� �������� ������, ���������������
  ����� (������� ������� ofstream, ifstream, fstream), ��������, ����� �������:

  ofstream outFile; // �������� �������� �����.
  ifstream inFile; // ������� �������� �����.
  fstream ioFile; // �������� ����� ��� ����� � ������.

  �������� ��������� ������ (������� ���������������� ������) ��������� ��� ������ � ���������� ��� ����
  ������� � �������������� ���������� ��������� ������. ��� ��� ������������� ������ �������� �������
  ��������� �������� ������ ios, �� � ���������� ��������� ������� ��������� ������ ����������� �� �����
  �������� ������. ��� ��� �������� ������ �������� ������������ �� ������� ostream (����� ofstream),
  istream (����� ifstream), stream (����� fstream), �� ��� ������������ ��������� � ���������� �����
  ��������������� � ������������ ����� � �������. ������ ������ ��� ��������� �����, ���������� �������
  ��������������� ���� � ������� ��� � �������� �������.

  �������� ����� � ����� ����� ������ �������� ���������, ������������� ������� � ��� ���������, �������
  �������������� ��������� � ������. ���������� ������� ����������� ���������� ����� � ��� �������� ������
  fopen(), open(). �� ������� � ��������� �������� ���������� �����-������ ����� �++, ������� ������������
  ������������� ��������� ��������������� �������.

  ������ �������� �����, ����� "������������" ��� � ����������� ����� � ������� ������������ ������� open().
  ������� open() ������������ ������ �� �������� ������� ofstream, ifsream, fstream �� ������ fstreambase.
  � �� ������� ����� �� ������ ������� ����, �� � ������� ��� � ��� ������������ �������.
*/
  ifstream infile; // ������� �������� �����.

  if(OpenDialog->Execute())          // ���� ������ ������ OpenDialog
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  ���������� ������ ������ ������.
  ���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
  ���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/
  {
    BlpFName = OpenDialog->FileName; // ��� ���������� ����� ����������� � ���������� BlpFName
    LVScan->Items->Clear();          // ������� LVScan
    Update_Dump_blp();               // �������� ����� BlpFName � LVScan
  }
  if(!infile)                        // ���� �� ������� �������� �����
  {
    MessageBox(NULL,"���� �� ������� �������!","������!",MB_OK|MB_ICONERROR);
    return;
  }

  AddSaveLog("��������� ���� ������ ��");  // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_LoadSarClick(TObject *Sender) // ������� �� ������ "������� ���� .sar"
{
/*
  ������ ��� ������ � ������� ��������� ��� ������� ��������� �������:

  ofstream - ��� ������ (������) ������ � ����;
  ifstream - ��� ����� (������) ������ �� �����;
  fstream - ��� ������ � ��� ������ ������ (��������������� �����).

  ����� ������������ ��� ������, � ����� ��������� ���������� �������� �������������� ������������
  ���� fstream.h. ����� ����� � ��������� ����� ���������� ���������� �������� ������, ���������������
  ����� (������� ������� ofstream, ifstream, fstream), ��������, ����� �������:

  ofstream outFile; // �������� �������� �����.
  ifstream inFile; // ������� �������� �����.
  fstream ioFile; // �������� ����� ��� ����� � ������.

  �������� ��������� ������ (������� ���������������� ������) ��������� ��� ������ � ���������� ��� ����
  ������� � �������������� ���������� ��������� ������. ��� ��� ������������� ������ �������� �������
  ��������� �������� ������ ios, �� � ���������� ��������� ������� ��������� ������ ����������� �� �����
  �������� ������. ��� ��� �������� ������ �������� ������������ �� ������� ostream (����� ofstream),
  istream (����� ifstream), stream (����� fstream), �� ��� ������������ ��������� � ���������� �����
  ��������������� � ������������ ����� � �������. ������ ������ ��� ��������� �����, ���������� �������
  ��������������� ���� � ������� ��� � �������� �������.

  �������� ����� � ����� ����� ������ �������� ���������, ������������� ������� � ��� ���������, �������
  �������������� ��������� � ������. ���������� ������� ����������� ���������� ����� � ��� �������� ������
  fopen(), open(). �� ������� � ��������� �������� ���������� �����-������ ����� �++, ������� ������������
  ������������� ��������� ��������������� �������.

  ������ �������� �����, ����� "������������" ��� � ����������� ����� � ������� ������������ ������� open().
  ������� open() ������������ ������ �� �������� ������� ofstream, ifsream, fstream �� ������ fstreambase.
  � �� ������� ����� �� ������ ������� ����, �� � ������� ��� � ��� ������������ �������.
*/
  ifstream infile; // ������� �������� �����.

  if(OpenDialog1->Execute())          // ���� ������ ������ OpenDialog1 
/*
  virtual __fastcall bool Execute(HWND ParentWnd);
  ���������� ������ ������ ������.
  ���������� true, ���� ������������ ������ ���� � ����� ������ "�������" ("Open") � �������.
  ���� ������������ ����� ������ "������" ("Cancel"), �� Execute ���������� false.
*/
  {
    SarFName = OpenDialog1->FileName; // ��� ���������� ����� ����������� � ���������� BlpFName
    LV_Sar1->Items->Clear();          // ������� LV_Sar1
    LV_Sar2->Items->Clear();          // ������� LV_Sar2
    LV_Sar3->Items->Clear();          // ������� LV_Sar3
    LV_Sar4->Items->Clear();          // ������� LV_Sar4
    Update_Dump_sar();                // �������� ����� SarFName � LV_Sar1 � LV_Sar2
    c1=false;                         // ��������� ���������� ����� � LV_Sar1
    B_AddSar1->Enabled=false;         // ��������� ������ "������� ������ Sar1"
    c2=false;                         // ��������� ���������� ����� � LV_Sar2
    B_AddSar2->Enabled=false;         // ��������� ������ "������� ������ Sar2"
    c3=false;                         // ��������� ���������� ����� � LV_Sar3
    B_AddSar3->Enabled=false;         // ��������� ������ "������� ������ Sar3"
    c4=false;                         // ��������� ���������� ����� � LV_Sar4
    B_AddSar4->Enabled=false;         // ��������� ������ "������� ������ Sar4"
  }
  if(!infile)                         // ���� �� ������� �������� �����
  {
    MessageBox(NULL,"���� �� ������� �������!","������!",MB_OK|MB_ICONERROR);
    return;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Update_Dump_blp() // ������� ���� blp
{
  int itemNumber=0; // ���������� �� � ���������� ���������� ����������
/*
  ���� ������ ��������� ������������ ������� open() ��� �������� �����,
  � ����������� ������� ��� �������� ��-�������, ��������� ������ ifstream,
  ofstream � fstream �������� ������������, ������� ������������� �����-
  ���� �������� ����. ��������� � ���� ������������� � �� �������� (��������-
  ��� �� ���������) ��������� � ����������� � ���������������� ����������
  ������� open(). ������� ���� ����� ���� ����������� ���, ��� �������� � ���-
  ������ �������.
  ifstream mystream("myfile"); // ���� ����������� ��� ����� (������)
  ---------------------------------------------------------------------------
  std::string::c_str();
  ������� c_str �� ������ string ��������� ������ ����� � ����� ��. � ���������� ��������� �� ����.
  ��������, ��������� ������� � �������� ��������� ��������� ��������� �� ������ �����:
  void Foo(const char* content);
  �� ����, � �� ����� �������� ������ ������ � ���� c-ctyle ���������
  � � ���� ���� ������ ���������� � �������:
  std::string str="������ ���";
  � ���� ����� �������� ��� ������ � ���� �������:
  Foo(str); //������. ������� �� ����� �������� �� ���������
  �� ��� ��� ������� �� ����� �������� �� ���������, � ������ � �����������, �� ������������ ������
  ������� ��� - ������� c_str()
  Foo(str.c_str() ); //�����.
  ������� c_str() ������������ ������ ��� ������������� � �-style �����.
  � � ����������� c++ style ����, � ����� �������� ���������, ��������� ��� ��������, ���� ��
  ������� "������" (����� ���� ������ � ����� �������� ����)
*/
  std::ifstream infile(BlpFName.c_str()); // ������� �������� ����� (���� ����������� ��� ����� (������))
/*
  ������ � �� �������� �������� ��������, ������� ������������� ������� �������� ('\0'). ������ � ������
  �������������� ����� ���������, ����������� �� ������ ������ ������. ��������� ������ �������� �����
  � ������� �������. �.�., ������ - ��� ���������, ���������� ��������� �� ������ ������ ������.
  ������ ����� ���� ��������� � ���������� ���� ������� ��������, ���� ���������� ���� char *.
  ������������� �����:
  char color[] = "blue"; // ������ �� 5-� ���������, ���������� ������� 'b', 'l', 'u', 'e', '\0'
  const char colorPtr = "blue"; // ����������-��������� colorPtr, ������� ��������� �� ������ "blue"
  char color[] = {'b', 'l', 'u', 'e', '\0'};
  � ��++ ������� ����� ��������� ����� std::string. ���������� �� �-style ������ ���, ���
  �������� �� �����������, ��� std::string ������ ������ ������ ����, � � ������ �-style ��� ��������
  �������� � ������ ���������������; �������� ���� �� ��������� ���������� ����������� �������������,
  � � �-style ������ ����������� ������� ����� ������ ���������� �����������.
*/  
  std::string x;     // ������ x ������ string
  TListItem *item=0; // ��������� �� ������ ���� TListItem (������ ������� ������ ListView)  
  bool flag=false;   // ���� ���������� ���������� ������� item
/*
  ������� std::getline (string) ������ ��� ���������� ������ �� �������� ������.
  (1) istream& getline (istream& is, string& str, char delim);
  (2) istream& getline (istream& is, string& str);
  ��������� ������� �� is � ��������� �� � str ���� �� ���������� �������������� ������ delim
  (��� ������ ����� ������, '\n', ��� ������ (2)).
  ���������� ��� �� ������������, ���� ��������� ����� ����� � is ��� ���� �������� ��������� ������
  �� ����� �������� ����� (������).
  ���� ����������� ������, �� ����������� � �������������, �.� �� �� ����������� � ��������� ��������
  ���������� ���������.

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
  ������� std::basic_ios::fail ���������� ������, ���� ��������� ������ �� ��������������� ������.
*/
  while(!std::getline(infile,x).fail()) // ���� ��� ������ ��� ���������� ������ �� �������� ������
  {
/*
    ������� std::string::size ���������� ����� ������ (���������� ��������); 
	  ������������ �������� size_t �������������� ���� ��� �����.
	
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
    ������� std::string::resize �������� ����� ������ �� ���������� n ��������
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
    ������� std::string::erase ������� ����� ������, �������� � �����.
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
    ���� ����� ������ =0 (!x.size() ��� x.size()==0), �� ������ item �����������;
    ����������� ���������� ������� item; ���������� ��� ����������� ���������� ������� item.
*/
    if(x.size()&&'"'==x[x.size()-1]) x.resize(x.size()-1);
/*
    x.size() - ���������� �������� � ������;
    [x.size()-1] - ���������� ����� ���������� ������� ������ (�.�. ������ � ����);
    ���� ������ ������� ('"') �������� ��������� �������� ������ (x[x.size()-1]), ��
    �������� ����� ������ �� ���������� x.size()-1 �������� (�.�. �� 1 ������ ����� ������).
*/
    if(x.size()&&'"'==x[0]) x.erase(0,1);
/*
    ���� ������ ������� ('"') �������� ������� �������� ������ (x[0]), ��
    ������� �� ������ ���� ������, ������� � �������� ������ x.erase(0,1).
*/
    if(!item) {item=LVScan->Items->Add(); itemNumber++;}
/*
    ���� ������ item �����������, �� �������� ������ item; itemNumber++; ���������� ���������� ��
*/
    if(!flag){ item->Caption=x.c_str(); flag=true; }
/*
    ���� ����������� ���������� ������� item, �� �������� ������ item �� ������ �-style.
    ������� ���� ���������� ������� item.
*/
    else item->SubItems->Add(x.c_str()); // ����� ��������� ������ SubItems
  }
   
  for(int i=itemNumber+1;i<=64;i++) // ��� ���� �������������� �� � �������� ���������� ���������� �� 64-� ������������
  {
    item = LVScan->Items->Add();    // �������� ����� ������ LVScan
    item->Caption = i;              // �������� ����� ��
    item->SubItems->Add(0);         // ��������� ������� ���������� 0
    item->SubItems->Add(0);
    item->SubItems->Add(0);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::Update_Dump_sar() // ������� ���� sar
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

    if(line == "*****")
      if(std::getline(ifile,line))
      {
        pItem = LV_Sar3->Items->Add();
        pItem->Caption =AnsiString(line.c_str());
      }
    if(line == "******")
      if (std::getline(ifile,line))
        pItem->SubItems->Add(line.c_str());

    if(line == "*******")
      if(std::getline(ifile,line))
      {
        pItem = LV_Sar4->Items->Add();
        pItem->Caption =AnsiString(line.c_str());
      }
    if(line == "********")
      if (std::getline(ifile,line))
        pItem->SubItems->Add(line.c_str());
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddBTClick(TObject *Sender) // ������� ������ "�������� ��"
{
  //static int k = 1;                        // ������� ��
  TListItem *Item = LVScan->Items->Add();  // �������� ����� ������ LVScan
  Item->Caption = 0;                       // ��������� ������� ���������� 0
  Item->SubItems->Add(0);
  Item->SubItems->Add(0);
  Item->SubItems->Add(0);
  //k++;
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteBTClick(TObject *Sender) // ������� ������ "������� ��"
{
  if (LVScan->Selected != NULL)  // ���� ��������� ������ LVScan �� �����
  {
    LVScan->Selected->Delete();  // ������� ��������� ������
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar1Click(TObject *Sender) // ������� �� ������ "������� ������ Sar1"
{
  if(c1)                                      // ���� ��� ������� ���������� ����� � LV_Sar1
  {
    TListItem *Item = LV_Sar1->Items->Add();  // �������� ����� ������ LV_Sar1
    // ��������� ������� ���������� �� ���������
    Item->Caption = 0;                        // V ����� ��� [�/�]
    Item->SubItems->Add(0);                   // ������� ������� [���]
    Item->SubItems->Add(0);                   // ����������� ����� [����.]
    Item->SubItems->Add(0);                   // ��������� ������ ��� [����.]
    Item->SubItems->Add(0);                   // ���������� �� ���� [�]
    c1=false;
    B_AddSar1->Enabled=false;
  }  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteSar1Click(TObject *Sender) // ������� �� ������ "������� ������ Sar1"
{
  if (LV_Sar1->Selected != NULL)  // ���� ��������� ������ LV_Sar1 �� �����
  {
    LV_Sar1->Selected->Delete();  // ������� ��������� ������
    c1=true;                      // ��������� ���������� ����� � LV_Sar1
    B_AddSar1->Enabled=true;      // �������� ������ "������� ������ Sar1"
  }
}                                    
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar2Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if(c2)                                      // ���� ��� ������� ���������� ����� � LV_Sar2
  {
    TListItem *Item = LV_Sar2->Items->Add();  // �������� ����� ������ LV_Sar2
    // ��������� ������� ���������� �� ���������
    Item->Caption = 0;                        // �� ��������� 1 [��]
    Item->SubItems->Add(0);                   // �� ��������� 2 [��]
    Item->SubItems->Add(970);                 // f ����� ������� 1 [����.]
    Item->SubItems->Add(970);                 // f ����� ������� 2 [����.]
    Item->SubItems->Add(1);                   // W���. ��������
    Item->SubItems->Add(1);                   // W���. �����������
    c2=false;
    B_AddSar2->Enabled=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_DeleteSar2Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if (LV_Sar2->Selected != NULL)  // ���� ��������� ������ LV_Sar2 �� �����
  {
    LV_Sar2->Selected->Delete();  // ������� ��������� ������
    c2=true;                      // ���������� ���������� ����� � LV_Sar2
    B_AddSar2->Enabled=true;      // ��������� ������ "������� ������ Sar2"
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::B_AddSar3Click(TObject *Sender) // ������� �� ������ "������� ������ Sar2"
{
  if(c3)                                      // ���� ��� ������� ���������� ����� � LV_Sar3
  {
    TListItem *Item = LV_Sar3->Items->Add();  // �������� ����� ������ LV_Sar3
    // ��������� ������� ���������� �� ���������
    // Reg[0]=0x00C80000;
    Item->Caption = IntToHex(0, 2);           // ���� 1  (R0_1)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 2  (R0_2)
    Item->SubItems->Add(IntToHex(200, 2));    // ���� 3  (R0_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 4  (R0_4)
    // Reg[1]=0x080080C9;
    Item->SubItems->Add(IntToHex(201, 2));    // ���� 5  (R1_1)
    Item->SubItems->Add(IntToHex(128, 2));    // ���� 6  (R1_2)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 7  (R1_3)
    Item->SubItems->Add(IntToHex(8, 2));      // ���� 8  (R1_4)
    // Reg[2]=0x00004EC2;
    Item->SubItems->Add(IntToHex(194, 2));    // ���� 9  (R2_1)
    Item->SubItems->Add(IntToHex(78, 2));     // ���� 10 (R2_2)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 11 (R2_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 12 (R2_4)
    c3=false;                                 // ������ ���������� ����� � LV_Sar3
    B_AddSar3->Enabled=false;                 // ���������� ������ "������� ������ Sar3"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_AddSar4Click(TObject *Sender)
{
  if(c4)                                      // ���� ��� ������� ���������� ����� � LV_Sar4
  {
    TListItem *Item = LV_Sar4->Items->Add();  // �������� ����� ������ LV_Sar4
    // ��������� ������� ���������� �� ���������
    // Reg[3]=0x000004B3;
    Item->Caption = IntToHex(179, 2);         // ���� 13 (R3_1)
    Item->SubItems->Add(IntToHex(4, 2));      // ���� 14 (R3_2)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 15 (R3_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 16 (R3_4)
    // Reg[4]=0x00A5003C;
    Item->SubItems->Add(IntToHex(60, 2));     // ���� 17 (R4_1)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 18 (R4_2)
    Item->SubItems->Add(IntToHex(165, 2));    // ���� 19 (R4_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 20 (R4_4)
    // Reg[5]=0x00580005;
    Item->SubItems->Add(IntToHex(5, 2));      // ���� 21 (R5_1)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 22 (R5_2)
    Item->SubItems->Add(IntToHex(88, 2));     // ���� 23 (R5_3)
    Item->SubItems->Add(IntToHex(0, 2));      // ���� 24 (R5_4)
    c4=false;                                 // ������ ���������� ����� � LV_Sar4
    B_AddSar4->Enabled=false;                 // ���������� ������ "������� ������ Sar4"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DeleteSar3Click(TObject *Sender) // ������� �� ������ "������� ������ Sar3"
{
  if (LV_Sar3->Selected != NULL)  // ���� ��������� ������ LV_Sar3 �� �����
  {
    LV_Sar3->Selected->Delete();  // ������� ��������� ������
    c3=true;                      // ���������� ���������� ����� � LV_Sar3
    B_AddSar3->Enabled=true;      // ��������� ������ "������� ������ Sar3"
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::B_DeleteSar4Click(TObject *Sender)
{
  if (LV_Sar4->Selected != NULL)  // ���� ��������� ������ LV_Sar4 �� �����
  {
    LV_Sar4->Selected->Delete();  // ������� ��������� ������
    c4=true;                      // ���������� ���������� ����� � LV_Sar4
    B_AddSar4->Enabled=true;      // ��������� ������ "������� ������ Sar4"
  }
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::TB_ExitClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_ControlClick(TObject *Sender)
{
  AddSaveLog("������ ����� ����������");  // �������� ����������� � ��������� ���
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::RB_TestingClick(TObject *Sender)
{
  AddSaveLog("������ ����� ������������");  // �������� ����������� � ��������� ���    
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::FormShow(TObject *Sender)
{
  if (!DirectoryExists(My_Patch + "log �����"))
  {
    MessageBox(NULL,"���������� ���������� log �����!","������!",MB_OK|MB_ICONERROR);
    Application->Terminate();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LVScanDblClick(TObject *Sender)
{
  if (LVScan->Selected!= NULL) F_BT->ShowModal();  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar1DblClick(TObject *Sender)
{
  if (LV_Sar1->Selected!= NULL) F_Sar1->ShowModal(); // ���� ��������� ������ LV_Sar1 �� �����, ������� �����  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar2DblClick(TObject *Sender)
{
 if (LV_Sar2->Selected!= NULL) F_Sar2->ShowModal(); // ���� ��������� ������ LV_Sar2 �� �����, ������� �����  
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar3DblClick(TObject *Sender)
{
  if (LV_Sar3->Selected!= NULL) F_Sar3->ShowModal(); // ���� ��������� ������ LV_Sar3 �� �����, ������� �����
}
//---------------------------------------------------------------------------

void __fastcall TMain_Form::LV_Sar4DblClick(TObject *Sender)
{
  if (LV_Sar4->Selected!= NULL) F_Sar4->ShowModal(); // ���� ��������� ������ LV_Sar4 �� �����, ������� �����
}
//---------------------------------------------------------------------------

