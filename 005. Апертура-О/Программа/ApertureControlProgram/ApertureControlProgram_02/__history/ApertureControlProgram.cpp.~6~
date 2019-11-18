//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Help.cpp", F_Help);
USEFORM("SelfControl.cpp", F_SelfControl);
USEFORM("ApertureControlProgram_main.cpp", MainForm);
USEFORM("AboutBox.cpp", F_AboutBox);
USEFORM("Error.cpp", ErrorForm);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "ApertureControl";
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TF_SelfControl), &F_SelfControl);
		Application->CreateForm(__classid(TF_AboutBox), &F_AboutBox);
		Application->CreateForm(__classid(TF_Help), &F_Help);
		Application->CreateForm(__classid(TErrorForm), &ErrorForm);
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
