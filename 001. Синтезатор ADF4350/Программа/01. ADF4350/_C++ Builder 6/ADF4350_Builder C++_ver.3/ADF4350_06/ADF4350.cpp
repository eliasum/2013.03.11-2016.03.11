//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Form2);
USEFORM("About.cpp", Form3);
USEFORM("Register1Settings.cpp", Form4);
USEFORM("Register2Settings.cpp", Form5);
USEFORM("Register3Settings.cpp", Form6);
USEFORM("Register4Settings.cpp", Form7);
USEFORM("Register5Settings.cpp", Form8);
USEFORM("Registers.cpp", Form9);
USEFORM("IFControl.cpp", F_IFControl);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->CreateForm(__classid(TForm1), &Form1);
     Application->CreateForm(__classid(TForm2), &Form2);
     Application->CreateForm(__classid(TForm3), &Form3);
     Application->CreateForm(__classid(TForm4), &Form4);
     Application->CreateForm(__classid(TForm5), &Form5);
     Application->CreateForm(__classid(TForm6), &Form6);
     Application->CreateForm(__classid(TForm7), &Form7);
     Application->CreateForm(__classid(TForm8), &Form8);
     Application->CreateForm(__classid(TForm9), &Form9);
     Application->CreateForm(__classid(TF_IFControl), &F_IFControl);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
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
