//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainScreen.h"
#include "AddNewPokeScreen.h"
#include "UpdatePokeRecordScreen.h"
#include "OptionsScreen.h"
#include <pngimage.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddPokeForm *AddPokeForm;

int c=0, e=0;
//---------------------------------------------------------------------------
__fastcall TAddPokeForm::TAddPokeForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//Called when relevant info has been inputed, data is added to DB
void __fastcall TAddPokeForm::FinishAddClick(TObject *Sender){
    //e is used to prevent errors if scrolling in main screen happenes during data entry into DB
	e=1;

	Main->ListOfPoke->Append();

	Main->ListOfPoke->FieldByName("ID")->AsInteger = StrToInt(DBEditDexEntry->Text);
	Main->ListOfPoke->FieldByName("DexEntry")->AsString = DBEditDexEntry->Text;
	Main->ListOfPoke->FieldByName("Name")->AsString = DBEditName->Text;
	Main->ListOfPoke->FieldByName("Gen")->AsString = DBEditGen->Text;
	Main->ListOfPoke->FieldByName("PrimaryType")->AsString = DBEditPT->Text;
	Main->ListOfPoke->FieldByName("SecondaryType")->AsString = DBEditST->Text;
	Main->ListOfPoke->FieldByName("HP")->AsInteger = StrToInt(DBEditHP->Text);
	Main->ListOfPoke->FieldByName("ATK")->AsInteger = StrToInt(DBEditATK->Text);
	Main->ListOfPoke->FieldByName("DEF")->AsInteger = StrToInt(DBEditDEF->Text);
	Main->ListOfPoke->FieldByName("SPATK")->AsInteger = StrToInt(DBEditSPATK->Text);
	Main->ListOfPoke->FieldByName("SPDEF")->AsInteger = StrToInt(DBEditSPDEF->Text);
	Main->ListOfPoke->FieldByName("SPD")->AsInteger = StrToInt(DBEditSPD->Text);

	static_cast<TBlobField*> (Main->ListOfPoke->FieldByName("PokeIcon"))->LoadFromFile(OpenPokePic->FileName);

	Main->ListOfPoke->Post();

    //c is used to determine if there was a learnset added to the DB
    if(c != 0){
        Main->PokeL->Insert();

		Main->PokeL->FieldByName("ID")->AsInteger = StrToInt(DBEditDexEntry->Text);
		Main->PokeL->FieldByName("LearnsetLKP")->AsString = OpenLearnset->FileName;

		Main->PokeL->Post();
		c=0;
    }

	ShowMessage("New pokemon added successfully!");
	e=0;
	AddPokeForm->Close();
}
//---------------------------------------------------------------------------

//Calls picture dialog for selectiong a pokemon picture to add
void __fastcall TAddPokeForm::AddImgBtnClick(TObject *Sender){
    OpenPokePic->Execute();
}
//---------------------------------------------------------------------------

//Calls picture dialog for selectiong a pokemon learnset picture to add
void __fastcall TAddPokeForm::AddPokeLearnsetClick(TObject *Sender){
	OpenLearnset->Execute();
	c++;
	UnicodeString link = OpenLearnset->FileName;
	link = StringReplace(link, _D("C:\\Users\\M\\Desktop\\NTP\\Project\\Win32\\Debug\\"), _D(""), TReplaceFlags() << rfReplaceAll);
	//OpenLearnset->FileName = link;
	//ShowMessage(link);
}
//---------------------------------------------------------------------------

//Loading program config from generalSettings.ini file
void __fastcall TAddPokeForm::FormShow(TObject *Sender){
    TIniFile *Ini = new TIniFile(GetCurrentDir() + "\\generalSettings.ini");
    if(Ini->ReadString("Options", "Language", "") == "ENG"){
		TranslateToENG();
	}
	if(Ini->ReadString("Options", "Language", "") == "HR"){
		TranslateToHR();
	}

    AddPokeForm->Color = StringToColor(Ini->ReadString("Options", "Color", ""));
	AddPokeForm->Font->Name = Ini->ReadString("Options", "Font", OptionsS->ComboBox2->Text);

	delete Ini;
}
//---------------------------------------------------------------------------

