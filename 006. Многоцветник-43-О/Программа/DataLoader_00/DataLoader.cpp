//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("DataLoader_Main.cpp", Main_Form);
USEFORM("Error.cpp", ErrorForm);
USEFORM("AboutBox.cpp", F_AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->Title = "DataLoader";
     Application->CreateForm(__classid(TMain_Form), &Main_Form);
     Application->CreateForm(__classid(TErrorForm), &ErrorForm);
     Application->CreateForm(__classid(TF_AboutBox), &F_AboutBox);
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
