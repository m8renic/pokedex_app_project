//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#pragma hdrstop

#include "MainScreen.h"
#include "OptionsScreen.h"
#include "DownloadScreen.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IdBaseComponent"
#pragma link "IdComponent"
#pragma link "IdHTTP"
#pragma link "IdTCPClient"
#pragma link "IdTCPConnection"
#pragma resource "*.dfm"
TDownDB *DownDB;
int count=0;
//---------------------------------------------------------------------------
__fastcall TDownDB::TDownDB(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//Connection throttle
void __fastcall TDownDB::CLimitsChange(TObject *Sender){
    int choice = CLimits->ItemIndex;
	if(choice == 0)	IdInterceptThrottler1->BitsPerSec = 0; /* no limit */
	if(choice == 1)	IdInterceptThrottler1->BitsPerSec = 409600; /* 50 kb/s = 50 * 1024 * 8 */
	if(choice == 2) IdInterceptThrottler1->BitsPerSec = 819200; /* 100 kb/s */
	if(choice == 3)	IdInterceptThrottler1->BitsPerSec = 2048000; /* 250 kb/s */
	if(choice == 4)	IdInterceptThrottler1->BitsPerSec = 4096000; /* 500 kb/s */
}
//---------------------------------------------------------------------------

//Download part
void __fastcall TDownDB::BDownloadClick(TObject *Sender){
    Progress->Position = 0;
	Application->ProcessMessages(); //Lazy mans way for not doing threads, basically tell main thread to take a break and check queued messages

	TFileStream* x = new TFileStream("Pokemon_OldAccessDB_new.txt", fmCreate);
	BCancel->Enabled = true;
	CLimits->Enabled = true;
	//Start downloading .txt file
	HTTP->Get(E->Text, x);

    delete x;

    count = 1;

	fstream f("Pokemon_OldAccessDB_new.txt");
	std::stringstream iss;
	iss << f.rdbuf();
	std::string entireFile = iss.str();

	std::string link = entireFile.substr(entireFile.find("https://download", 0), 87);

	TFileStream* y = new TFileStream("Pokemon_OldAccessDB_new.mdb", fmCreate);
	//Start downloading .mdb file from link obtained from previouse .txt file
	HTTP->Get(link.c_str(), y);

    f.close();
	delete y;

	remove("Pokemon_OldAccessDB_new.txt");
    count = 0;
}
//---------------------------------------------------------------------------

//Close the form
void __fastcall TDownDB::BCancelClick(TObject *Sender){
	ShowMessage("Canceled!");
    DownDB->Close();
}
//---------------------------------------------------------------------------

//Setting up the progress bar when download starts
void __fastcall TDownDB::HTTPWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax){
    Progress->Max = AWorkCountMax;
}
//---------------------------------------------------------------------------

//Progress the progress bar
void __fastcall TDownDB::HTTPWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount){
	Progress->Position = AWorkCount;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------

//Inform the user the file has been downloaded
void __fastcall TDownDB::HTTPWorkEnd(TObject *ASender, TWorkMode AWorkMode){
    //Since 2 downloads take place, only the second one it relevant to the end user
	if(count != 0){
		ShowMessage("Saved in app folder!");
    }
}
//---------------------------------------------------------------------------

//Loading program config from generalSettings.ini file
void __fastcall TDownDB::FormShow(TObject *Sender){
    TIniFile *Ini = new TIniFile(GetCurrentDir() + "\\generalSettings.ini");
	if(Ini->ReadString("Options", "Language", "") == "ENG"){
		TranslateToENG();
	}
	if(Ini->ReadString("Options", "Language", "") == "HR"){
		TranslateToHR();
	}

	DownDB->Color = StringToColor(Ini->ReadString("Options", "Color", ""));
	DownDB->Font->Name = Ini->ReadString("Options", "Font", OptionsS->ComboBox2->Text);

	delete Ini;
}
//---------------------------------------------------------------------------

