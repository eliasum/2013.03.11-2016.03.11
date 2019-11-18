// �������� ���� �������
//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
/* �������, ������������ ����� �������� � ����. ������������ ��������� ��� ������� � ��������������� ���.
������ �������� ������� �������� ��� ����� ������, ���������������� �����, � ������ �������� - ��� �����. */
//---------------------------------------------------------------------------
USEFORM("Help.cpp", F_Help);
USEFORM("AboutBox.cpp", F_AboutBox);
USEFORM("Error.cpp", ErrorForm);
USEFORM("BlazePoint_main.cpp", Main_Form);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
/* ������ �������� ������� WinMain - ���������� ������� ���������� ����������.
���������� - ��� ����� ���������� ���������, ����������� Windows ����������� � ��������� ������������
�������� ���� ��������� ����������.
������ �������� - ���������� ����������� ���������� ���������� (���� ������������ ��������� ������������
��������� ����� ����������).
������ �������� - ��������� �� ������ � ������� �������� � �����, ���������� ���������, ������������ �
��������� ����� ��������� ������.
��������� �������� ���������� ���� ����������. */
{
  try
  {
     Application->Initialize();  // ������������� �������� ����������� ������� ����������
     Application->Title = "BlazePoint";
		Application->CreateForm(__classid(TMain_Form), &Main_Form);
		Application->CreateForm(__classid(TF_AboutBox), &F_AboutBox);
		Application->CreateForm(__classid(TErrorForm), &ErrorForm);
		Application->CreateForm(__classid(TF_Help), &F_Help);
		Application->Run();                                         // ������ ���������� ���������� ���������
  }
  catch (Exception &exception)   // ��������� ���������� - ��������� �������� ��� ������ ���������
  {
     Application->ShowException(&exception);  // ����������� ���������� ����������
  }
  catch (...)
  {
     try
     {
       throw Exception("");
     }
     catch (Exception &exception)
     {
       Application->ShowException(&exception);
     }
  }
  return 0;
}
//---------------------------------------------------------------------------
