//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainScreen.h"
#include "AddNewPokeScreen.h"
#include "UpdatePokeRecordScreen.h"
#include "OptionsScreen.h"
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOptionsS *OptionsS;
int f=0;
//---------------------------------------------------------------------------
__fastcall TOptionsS::TOptionsS(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//Color picking and flagging that a color has been picked
void __fastcall TOptionsS::ColorPickClick(TObject *Sender){
	f++;
	ColorPicking->Execute();
    ShowMessage(ColorPicking->Color);
}
//---------------------------------------------------------------------------

//Close the OptionsScrees.cpp form
void __fastcall TOptionsS::CancelButtonClick(TObject *Sender){
    OptionsS->Close();
}
//---------------------------------------------------------------------------

//Applying the settings currently chosen and saving them
void __fastcall TOptionsS::ApplySettingsClick(TObject *Sender){
	TIniFile *Ini = new TIniFile(GetCurrentDir() + "\\generalSettings.ini");
	Ini->WriteString("Options", "Language", ComboBox1->Text);
    Ini->WriteInteger("Options", "LanguageIndex", ComboBox1->ItemIndex);

	if(Ini->ReadString("Options", "Language", "") == "ENG"){
		TranslateToENG();
	}
	if(Ini->ReadString("Options", "Language", "") == "HR"){
		TranslateToHR();
	}

	//f determines if there is a new color code to be stored
	if(f != 0){
		Ini->WriteString("Options", "Color", ColorPicking->Color);
		Main->Color = ColorPicking->Color;
		AddPokeForm->Color = ColorPicking->Color;
		UPPokeEntry->Color = ColorPicking->Color;
		OptionsS->Color = ColorPicking->Color;
        f=0;
	}
	Ini->WriteString("Options", "Font", ComboBox2->Text);

	//Main->Change
	Main->Color = StringToColor(Ini->ReadString("Options", "Color", ""));
	Main->Font->Name = Ini->ReadString("Options", "Font", ComboBox2->Text);

	//AddPokeForm->Change
	AddPokeForm->Color = StringToColor(Ini->ReadString("Options", "Color", ""));
	AddPokeForm->Font->Name = Ini->ReadString("Options", "Font", ComboBox2->Text);

	//UPPokeEntry->Change
	UPPokeEntry->Color = StringToColor(Ini->ReadString("Options", "Color", ""));
	UPPokeEntry->Font->Name = Ini->ReadString("Options", "Font", ComboBox2->Text);


	//OptionsS->Change
	OptionsS->Font->Name = StringToColor(Ini->ReadString("Options", "Color", ""));
	OptionsS->Font->Name = Ini->ReadString("Options", "Font", ComboBox2->Text);

	//End
    delete Ini;
	OptionsS->Close();
}
//---------------------------------------------------------------------------

//Loading program config from generalSettings.ini file
void __fastcall TOptionsS::FormShow(TObject *Sender){
    TIniFile *Ini = new TIniFile(GetCurrentDir() + "\\generalSettings.ini");

    if(Ini->ReadString("Options", "Language", "") == "ENG"){
		TranslateToENG();
	}
	if(Ini->ReadString("Options", "Language", "") == "HR"){
		TranslateToHR();
	}

	OptionsS->Font->Name = StringToColor(Ini->ReadString("Options", "Color", ""));
	OptionsS->Font->Name = Ini->ReadString("Options", "Font", ComboBox2->Text);
}
//---------------------------------------------------------------------------

