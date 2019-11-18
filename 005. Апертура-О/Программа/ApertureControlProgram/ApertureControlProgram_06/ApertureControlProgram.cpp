//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Help.cpp", F_Help);
USEFORM("Tumbler.cpp", F_Tumbler);
USEFORM("SelfControl.cpp", F_SelfControl);
USEFORM("AboutBox.cpp", F_AboutBox);
USEFORM("Error.cpp", ErrorForm);
USEFORM("ApertureControlProgram_main.cpp", MainForm);
USEFORM("Tumbler2.cpp", F_Tumbler2);
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
		Application->CreateForm(__classid(TF_Tumbler), &F_Tumbler);
		Application->CreateForm(__classid(TF_Tumbler2), &F_Tumbler2);
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
