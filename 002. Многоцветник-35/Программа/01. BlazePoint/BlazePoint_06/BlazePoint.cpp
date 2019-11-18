// �������� ���� �������
//---------------------------------------------------------------------------
// ��������� ������������� #include ���������� � ������ ���� ������ ��������� � ��� ������
#include <vcl.h>  // ����������, ������������ � ���������� ���������� ����������� �++Builder
#pragma hdrstop   // ����� ������ ����� ������������ ������ ��� ���� ������� �������

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
/* �������, ������������ ����� �������� � ����. ������������ �������� ��� ������� � ��������������� ���.
������ �������� ������� �������� ��� ����� ������, ���������������� �����, � ������ �������� - ��� �����. */
//---------------------------------------------------------------------------
USEFORM("BlazePoint_main.cpp", Main_Form);
USEFORM("Sar1.cpp", F_Sar1);
USEFORM("Sar2.cpp", F_Sar2);
USEFORM("Sar3.cpp", F_Sar3);
USEFORM("Sar4.cpp", F_Sar4);
USEFORM("AboutBox.cpp", F_AboutBox);
USEFORM("Error.cpp", ErrorForm);
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
     Application->CreateForm(__classid(TMain_Form), &Main_Form);
     Application->CreateForm(__classid(TF_Sar1), &F_Sar1);
     Application->CreateForm(__classid(TF_Sar2), &F_Sar2);
     Application->CreateForm(__classid(TF_Sar3), &F_Sar3);
     Application->CreateForm(__classid(TF_Sar4), &F_Sar4);
     Application->CreateForm(__classid(TF_AboutBox), &F_AboutBox);
     Application->CreateForm(__classid(TErrorForm), &ErrorForm);
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
