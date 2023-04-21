//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainScreen.h"
#include "AddNewPokeScreen.h"
#include "UpdatePokeRecordScreen.h"
#include "OptionsScreen.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUPPokeEntry *UPPokeEntry;

int x=0, c=0;
//---------------------------------------------------------------------------
__fastcall TUPPokeEntry::TUPPokeEntry(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//Updating currently selected pokemon entry
void __fastcall TUPPokeEntry::FinishUpdateClick(TObject *Sender){
	//x determines if the pokemon picture was updated
	if(x != 0){
		Main->ListOfPoke->Edit();
		static_cast<TBlobField*> (Main->ListOfPoke->FieldByName("PokeIcon"))->LoadFromFile(UpdatePokePic->FileName);
		Main->ListOfPoke->Post();
        x=0;
	}

    //c determines if the pokemon learnset picture was updated
    if(c != 0){
        Main->PokeL->Edit();

		Main->PokeL->FieldByName("Learnset")->AsString = UpdateLearnset->FileName;

		Main->PokeL->Post();
        c=0;
	}

	ShowMessage("Pokemon updated successfully!");

	UPPokeEntry->Close();
}
//---------------------------------------------------------------------------

//Pokemon picture update
void __fastcall TUPPokeEntry::UpdatePokePicButtonClick(TObject *Sender){
	UpdatePokePic->Execute();
    x++;
}
//---------------------------------------------------------------------------

//Pokemon learnset picture update
void __fastcall TUPPokeEntry::UpdatePLearnsetClick(TObject *Sender){
	UpdateLearnset->Execute();
	c++;
	UnicodeString link = UpdateLearnset->FileName;
	link = StringReplace(link, _D("C:\\Users\\M\\Desktop\\NTP\\Project\\Win32\\Debug\\"), _D(""), TReplaceFlags() << rfReplaceAll);
	UpdateLearnset->FileName = link;
}
//---------------------------------------------------------------------------

//Loading program config from generalSettings.ini file
void __fastcall TUPPokeEntry::FormShow(TObject *Sender){
    TIniFile *Ini = new TIniFile(GetCurrentDir() + "\\generalSettings.ini");
    if(Ini->ReadString("Options", "Language", "") == "ENG"){
		TranslateToENG();
	}
	if(Ini->ReadString("Options", "Language", "") == "HR"){
		TranslateToHR();
	}

    UPPokeEntry->Color = StringToColor(Ini->ReadString("Options", "Color", ""));
	UPPokeEntry->Font->Name = Ini->ReadString("Options", "Font", OptionsS->ComboBox2->Text);

	delete Ini;
}
//---------------------------------------------------------------------------

