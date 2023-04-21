//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainScreen.h"
#include "AddNewPokeScreen.h"
#include "UpdatePokeRecordScreen.h"
#include "OptionsScreen.h"
#include "EncryptedTCPChatBox.h"
#include "DownloadScreen.h"
#include <pngimage.hpp>
#include <jpeg.hpp>
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportHTML"
#pragma link "frxExportImage"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma resource "*.dfm"
TMain *Main;

int y=0;
int calc=0;
extern int e;

//Functions for translating the program

void TranslateToENG(){
	//Main translate to ENG
	Main->L1->Caption = "Pokemon name:";
	Main->L2->Caption = "Generation:";
	Main->L3->Caption = "Primary type:";
	Main->L4->Caption = "Secondary type:";
	Main->SearchPoke->Caption = "Search for pokemon";
	Main->L5->Caption = "Pokemon entry:";
	Main->L6->Caption = "Name:";
	Main->L7->Caption = "Generation:";
	Main->L8->Caption = "Primary type:";
	Main->L9->Caption = "Secondary type:";
	Main->L10->Caption = "HP:";
	Main->L11->Caption = "ATK:";
	Main->L12->Caption = "DEF:";
	Main->L13->Caption = "SP. ATK:";
	Main->L14->Caption = "SP. DEF:";
	Main->L15->Caption = "SPD:";
    Main->L16->Caption = "Learnset:";
	Main->AddNewPoke->Caption = "Add new pokemon";
	Main->UpdatePokeEntry->Caption = "Update pokemon entry";
	Main->DeletePokeEntry->Caption = "Delete pokemon entry";
	Main->N1->Caption = "Export";
    Main->N2->Caption = "Options";
	Main->S1->Caption = "As PDF";
	Main->S2->Caption = "As RTF";
	Main->S3->Caption = "As PNG";

	//AddNewPoke translate to ENG
	AddPokeForm->Caption = "Add new pokemon";
	AddPokeForm->L1->Caption = "Pokemon entry:";
	AddPokeForm->L2->Caption = "Name:";
	AddPokeForm->L3->Caption = "Generation:";
	AddPokeForm->L4->Caption = "Primary type:";
	AddPokeForm->L5->Caption = "Secondary type:";
	AddPokeForm->L6->Caption = "HP:";
	AddPokeForm->L7->Caption = "ATK:";
	AddPokeForm->L8->Caption = "DEF:";
	AddPokeForm->L9->Caption = "SP. ATK:";
	AddPokeForm->L10->Caption = "SP. DEF:";
	AddPokeForm->L11->Caption = "SPD:";
	AddPokeForm->AddImgBtn->Caption = "Add pokemon image";
    AddPokeForm->AddPokeLearnset->Caption = "Add poke learnset";
	AddPokeForm->FinishAdd->Caption = "Add pokemon entry";

	//UPPokeEntry translate to ENG
	UPPokeEntry->Caption = "Update new pokemon";
	UPPokeEntry->L1->Caption = "Pokemon entry:";
	UPPokeEntry->L2->Caption = "Name:";
	UPPokeEntry->L3->Caption = "Generation:";
	UPPokeEntry->L4->Caption = "Primary type:";
	UPPokeEntry->L5->Caption = "Secondary type:";
	UPPokeEntry->L6->Caption = "HP:";
	UPPokeEntry->L7->Caption = "ATK:";
	UPPokeEntry->L8->Caption = "DEF:";
	UPPokeEntry->L9->Caption = "SP. ATK:";
	UPPokeEntry->L10->Caption = "SP. DEF:";
	UPPokeEntry->L11->Caption = "SPD:";
	UPPokeEntry->UpdatePokePicButton->Caption = "Update pokemon image";
    UPPokeEntry->UpdatePLearnset->Caption = "Update poke learnset";
	UPPokeEntry->FinishUpdate->Caption = "Update pokemon entry";

	//OptionsS translate to ENG
	OptionsS->ComboBox1->ItemIndex = 0;
	OptionsS->Caption = "Options";
	OptionsS->L1->Caption = "Language:";
	OptionsS->L2->Caption = "Background color:";
	OptionsS->L3->Caption = "Font:";
	OptionsS->Button1->Caption = "Apply";
	OptionsS->Button2->Caption = "Cancel";
	OptionsS->Button3->Caption = "Pick a color";

	//Chat translate to ENG
	Chat->IPEdit->TextHint = "Public IP";
	Chat->L2->Caption = "Username:";
	Chat->B1->Caption = "Connect";
	Chat->B2->Caption = "Disconnect";
	Chat->Message->TextHint = "Start typing here to message other online users";

	//DownDB translate to ENG
	DownDB->L1->Caption = "Download Pokemon DB";
	DownDB->BDownload->Caption = "Download";
	DownDB->BCancel->Caption = "Cancel";
}

void TranslateToHR(){
	//Main translate to HR
	Main->L1->Caption = "Ime pokemona:";
	Main->L2->Caption = "Generacija:";
	Main->L3->Caption = "Primarni tip:";
	Main->L4->Caption = "Sekundarni tip:";
	Main->SearchPoke->Caption = "Traži pokemona";
	Main->L5->Caption = "Pokemon ID:";
	Main->L6->Caption = "Ime:";
	Main->L7->Caption = "Generacija:";
	Main->L8->Caption = "Primarni tip:";
	Main->L9->Caption = "Sekundarni tip:";
	Main->L10->Caption = "HP:";
	Main->L11->Caption = "ATK:";
	Main->L12->Caption = "DEF:";
	Main->L13->Caption = "SP. ATK:";
	Main->L14->Caption = "SP. DEF:";
	Main->L15->Caption = "SPD:";
	Main->L16->Caption = "Potezi koji se nauèe:";
	Main->AddNewPoke->Caption = "Dodaj novog pokemona";
	Main->UpdatePokeEntry->Caption = "Ažuriraj info pokemona";
	Main->DeletePokeEntry->Caption = "Izbriši zapis pokemona";
	Main->N1->Caption = "Izvezi";
	Main->N2->Caption = "Opcije";
	Main->S1->Caption = "Kao PDF";
	Main->S2->Caption = "Kao RTF";
	Main->S3->Caption = "Kao PNG";

	//AddNewPoke translate to HR
	AddPokeForm->Caption = "Dodaj novog pokemona";
	AddPokeForm->L1->Caption = "Pokemon ID:";
	AddPokeForm->L2->Caption = "Ime:";
	AddPokeForm->L3->Caption = "Generacija:";
	AddPokeForm->L4->Caption = "Primarni tip:";
	AddPokeForm->L5->Caption = "Sekundarni tip:";
	AddPokeForm->L6->Caption = "HP:";
	AddPokeForm->L7->Caption = "ATK:";
	AddPokeForm->L8->Caption = "DEF:";
	AddPokeForm->L9->Caption = "SP. ATK:";
	AddPokeForm->L10->Caption = "SP. DEF:";
	AddPokeForm->L11->Caption = "SPD:";
	AddPokeForm->AddImgBtn->Caption = "Dodaj sliku";
    AddPokeForm->AddPokeLearnset->Caption = "Dodaj learnset";
	AddPokeForm->FinishAdd->Caption = "Dodaj zapis pokemona";

	//UPPokeEntry translate to HR
	UPPokeEntry->Caption = "Ažuriraj info pokemona";
	UPPokeEntry->L1->Caption = "Pokemon ID:";
	UPPokeEntry->L2->Caption = "Ime:";
	UPPokeEntry->L3->Caption = "Generacija:";
	UPPokeEntry->L4->Caption = "Primarni tip:";
	UPPokeEntry->L5->Caption = "Sekundarni tip:";
	UPPokeEntry->L6->Caption = "HP:";
	UPPokeEntry->L7->Caption = "ATK:";
	UPPokeEntry->L8->Caption = "DEF:";
	UPPokeEntry->L9->Caption = "SP. ATK:";
	UPPokeEntry->L10->Caption = "SP. DEF:";
	UPPokeEntry->L11->Caption = "SPD:";
	UPPokeEntry->UpdatePokePicButton->Caption = "Ažuriraj sliku";
    UPPokeEntry->UpdatePLearnset->Caption = "Ažuriraj learnset";
	UPPokeEntry->FinishUpdate->Caption = "Ažuriraj info pokemona";

	//OptionsS translate to HR
    OptionsS->ComboBox1->ItemIndex = 1;
	OptionsS->Caption = "Opcije";
	OptionsS->L1->Caption = "Jezik:";
	OptionsS->L2->Caption = "Pozadinska boja:";
	OptionsS->L3->Caption = "Font:";
	OptionsS->Button1->Caption = "Primjeni";
	OptionsS->Button2->Caption = "Odustani";
	OptionsS->Button3->Caption = "Odaberi boju";

	//Chat translate to HR
    Chat->IPEdit->TextHint = "Javna IP adresa";
	Chat->L2->Caption = "Korisnièko ime:";
	Chat->B1->Caption = "Spoji se";
	Chat->B2->Caption = "Odspoji se";
	Chat->Message->TextHint = "Ovdje poènite pisati poruku";

	//DownDB translate to HR
	DownDB->L1->Caption = "Preuzmi Pokemon DB";
	DownDB->BDownload->Caption = "Preuzmi";
    DownDB->BCancel->Caption = "Prekini";
}
//---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//Search the DB
void __fastcall TMain::SearchPokeClick(TObject *Sender){
	int f=0;
	ListOfPoke->Filtered = FALSE;

	if(SearchPokeName->Text != ""){
		ListOfPoke->Filter = "Name = '" + SearchPokeName->Text + "'";
		f++;
	}else{
		ListOfPoke->Filter = "";
	}
	if(GenSelect->Text != "All"){
		if(f == 0){
			f++;
		}else{
			ListOfPoke->Filter += " AND ";
		}
        ListOfPoke->Filter += "Gen = '" + GenSelect->Text + "'";
	}
	if(PrimaryT->Text != "Any"){
		if(f == 0){
			f++;
		}else{
			ListOfPoke->Filter += " AND ";
		}
		ListOfPoke->Filter += "PrimaryType = '" + PrimaryT->Text + "'";
	}
	if(SecondaryT->Text != "Any"){
		if(f == 0){
			f++;
		}else{
			ListOfPoke->Filter += " AND ";
		}
		ListOfPoke->Filter += "SecondaryType = '" + SecondaryT->Text + "'";
	}
	ListOfPoke->Filtered = TRUE;
}
//---------------------------------------------------------------------------

//Call AddNewPokeScreen.cpp for adding pokemon
void __fastcall TMain::AddNewPokeClick(TObject *Sender){
	AddPokeForm->ShowModal();
}
//---------------------------------------------------------------------------

//Call UpdatePokeRecordScreen.cpp for updating pokemon data
void __fastcall TMain::UpdatePokeEntryClick(TObject *Sender){
	UPPokeEntry->ShowModal();
}
//---------------------------------------------------------------------------

//Delete a DB pokemon record
void __fastcall TMain::DeletePokeEntryClick(TObject *Sender){
	if(PokeL->FieldByName("Learnset")->AsString != ""){
		PokeL->Delete();
	}
	ListOfPoke->Delete();
	ListOfPoke->First();
}
//---------------------------------------------------------------------------

//Show PDF report
void __fastcall TMain::ExportAsPDF(TObject *Sender){
	PokeReportFile->ShowReport();
}
//---------------------------------------------------------------------------

//Export DB pokemon data as RTF
void __fastcall TMain::ExportAsRTF(TObject *Sender){
	PokeReportFile->Export(ExpAsRTF);
}
//---------------------------------------------------------------------------

//Export DB pokemon data as PNG
void __fastcall TMain::ExportAsPNG(TObject *Sender){
	PokeReportFile->Export(ExpAsPNG);
}
//---------------------------------------------------------------------------

//Call OptionsScreen.cpp to adjust settings
void __fastcall TMain::N2Click(TObject *Sender){
    OptionsS->ShowModal();
}
//---------------------------------------------------------------------------

//Read posSettings.ini to see what the last position of the project was
void __fastcall TMain::FormClose(TObject *Sender, TCloseAction &Action){
	TIniFile *Ini = new TIniFile(GetCurrentDir() + "\\posSettings.ini");
	Ini->WriteInteger("Main Screen", "Top", Top);
	Ini->WriteInteger("Main Screen", "Left", Left);
	delete Ini;
}
//---------------------------------------------------------------------------

//Loading pokemon learnsets after each scroll through the grid
void __fastcall TMain::ListOfPokeAfterScroll(TDataSet *DataSet){
	if(e == 0){
		if(Main->PokeL->FieldByName("Learnset")->AsString != ""){
			UnicodeString link = Main->PokeL->FieldByName("Learnset")->AsString;
			Learnset->Picture->LoadFromFile(link);
		}else{
			HINSTANCE DLLResource;
			if((DLLResource = LoadLibrary(L"DLLResource.dll")) == NULL){
				ShowMessage("Unable to load DLLResource.dll!");
				return;
			}
			TResourceStream *dllRS = new TResourceStream((int)DLLResource, "NA_learnset_PNG", RT_RCDATA);
			Learnset->Picture->LoadFromStream(dllRS);

			delete dllRS;
            FreeLibrary(DLLResource);

			//Learnset->Picture->LoadFromFile("PokemonMoves\\NA.png");
		}
	}
}
//Bug: pri uèitavanju programa, ne uèita se i slika sa learnsetom pokemona

//---------------------------------------------------------------------------

//Call EncryptedTCPChatBox.cpp for the chatbox feature
void __fastcall TMain::Chat1Click(TObject *Sender){
	Chat->Show();
}
//---------------------------------------------------------------------------

//Call DownloadScreen.cpp to download complete DB
void __fastcall TMain::DownloadDBClick(TObject *Sender){
    DownDB->ShowModal();
}
//---------------------------------------------------------------------------

//Code for calculating calc field Overall
void __fastcall TMain::ListOfPokeCalcFields(TDataSet *DataSet){
	int hp = ListOfPoke->FieldByName("HP")->AsInteger;
	int atk = ListOfPoke->FieldByName("ATK")->AsInteger;
	int def = ListOfPoke->FieldByName("DEF")->AsInteger;
	int spatk = ListOfPoke->FieldByName("SPATK")->AsInteger;
	int spdef = ListOfPoke->FieldByName("SPDEF")->AsInteger;
	int spd = ListOfPoke->FieldByName("SPD")->AsInteger;
   	DataSet->FieldByName("Overall")->AsInteger = hp + atk + def + spatk + spdef + spd;
}
//---------------------------------------------------------------------------

//Loading program config from generalSettings.ini file
void __fastcall TMain::FormShow(TObject *Sender){
    TIniFile *Ini1 = new TIniFile(GetCurrentDir() + "\\posSettings.ini");
	if(y==0){
		Top = Ini1->ReadInteger("Main Screen", "Top", 0);
		Left = Ini1->ReadInteger("Main Screen", "Left", 0);
		y++;
	}
	delete Ini1;

	TIniFile *Ini = new TIniFile(GetCurrentDir() + "\\generalSettings.ini");
	if(Ini->ReadString("Options", "Language", "") == "ENG"){
		TranslateToENG();
	}
	if(Ini->ReadString("Options", "Language", "") == "HR"){
		TranslateToHR();
	}

	Main->Color = StringToColor(Ini->ReadString("Options", "Color", ""));
	Main->Font->Name = Ini->ReadString("Options", "Font", OptionsS->ComboBox2->Text);

	delete Ini;
}
//---------------------------------------------------------------------------

