//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("MainScreen.cpp", Main);
USEFORM("AddNewPokeScreen.cpp", AddPokeForm);
USEFORM("DownloadScreen.cpp", DownDB);
USEFORM("EncryptedTCPChatBox.cpp", Chat);
USEFORM("OptionsScreen.cpp", OptionsS);
USEFORM("UpdatePokeRecordScreen.cpp", UPPokeEntry);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMain), &Main);
		Application->CreateForm(__classid(TAddPokeForm), &AddPokeForm);
		Application->CreateForm(__classid(TDownDB), &DownDB);
		Application->CreateForm(__classid(TChat), &Chat);
		Application->CreateForm(__classid(TOptionsS), &OptionsS);
		Application->CreateForm(__classid(TUPPokeEntry), &UPPokeEntry);
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
