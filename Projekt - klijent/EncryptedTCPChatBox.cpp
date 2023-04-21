#include <vcl.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#pragma hdrstop

#include "MainScreen.h"
#include "AddNewPokeScreen.h"
#include "UpdatePokeRecordScreen.h"
#include "OptionsScreen.h"
#include "EncryptedTCPChatBox.h"
#include <pngimage.hpp>
#include <jpeg.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"
#include "uTPLb_Signatory.hpp"
#include <iostream>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_Signatory"
#pragma link "uTPLb_Hash"
#pragma resource "*.dfm"
TChat *Chat;
std::wofstream fs;
int connectionEstablish = 0;
UnicodeString filename;
UnicodeString userF;
UnicodeString secretEncKey = "LawfulChaotic!!#$%&/";
//---------------------------------------------------------------------------
__fastcall TChat::TChat(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//When creating the form, indicate to the user he is not connected to the server
void __fastcall TChat::FormCreate(TObject *Sender){
	Status->Brush->Color = clRed;
	fs.open ("log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
}
//---------------------------------------------------------------------------

//Connecting to server
void __fastcall TChat::B1Click(TObject *Sender){
	TCPClient->Host = IPEdit->Text;

	try{
		TCPClient->Connect();
		TCPClient->Socket->Binding->SetKeepAliveValues(TRUE, 1000, 1000);
		TCPServer->Active = TRUE;
		connectionEstablish = 1;
		Status->Brush->Color = clLime;
		fs << "Connected to server on IP: " << IPEdit->Text << "\n";
	}
	catch(...){
		ShowMessage("Unable to connect, try again!");
	}

	//Prvi hash za dobivanje razlièitog salta za svaki password
	UnicodeString salt1;
	Hashing->HashString(Pass->Text, TEncoding::UTF8);
	salt1 = Stream_To_Hex(Hashing->HashOutputValue);

	//Generiranje salt2
	UnicodeString salt2;
	srand((unsigned)time(NULL));
	int z = 0;
	for(int i = 0; i < 10; i++){
		z = (rand() % (3 - 1 + 1)) + 1;
		if (z == 1){	//Generira broj ako z == 1
			salt2 += char((rand() % (57 - 48 + 1)) + 48);
		}
		if (z == 2){	//Generira veliko slovo ako z == 2
			salt2 += char((rand() % (90 - 65 + 1)) + 65);
		}
		if (z == 3){	//Generira malo slovo ako z == 3
			salt2 += char((rand() % (122 - 97 + 1)) + 97);
		}
	}

	//Hash sa salt1 i password
	Hashing->HashString(salt1 + Pass->Text, TEncoding::UTF8);
	UnicodeString passHash = Stream_To_Hex(Hashing->HashOutputValue);
    fs << "\n\n" << passHash << "\n\n";

	//Hash sa (hash od salt1 i password) te salt2
	Hashing->HashString(passHash + salt2, TEncoding::UTF8);
	UnicodeString passHashWSalt2 = Stream_To_Hex(Hashing->HashOutputValue);

	UnicodeString login = ":" + User->Text + "!" + passHashWSalt2 + "$" + salt2;

	UnicodeString encLogin;
	Symetric->Password = secretEncKey;
	Symetric->EncryptString(login, encLogin, TEncoding::UTF8);

	TCPClient->Socket->WriteLn(encLogin);
	connectionEstablish = 1;

	UnicodeString res = TCPClient->Socket->ReadLn();

	if(res == "Entered wrong username or password! Try again!" && connectionEstablish == 1){
		connectionEstablish = 0;
		ShowMessage("Entered wrong username or password! Try again!");
		TCPClient->Disconnect();
        TCPServer->Active = FALSE;
		fs << "Disconnected from server!\n";
		fs.close();
		Status->Brush->Color = clRed;
	}else if(res == "Success!" && connectionEstablish == 1){
		connectionEstablish = 2;
		ShowMessage("Login successful!");
	}
}
//---------------------------------------------------------------------------

//Disconnect from server
void __fastcall TChat::B2Click(TObject *Sender){
	TCPClient->Disconnect();
	TCPServer->Active = FALSE;
	fs << "Disconnected from server!\n";
    fs.close();
    Status->Brush->Color = clRed;
}
//---------------------------------------------------------------------------

//Send text message over TCP with 1. RSA encryption and then 2. AES encryption
void __fastcall TChat::SendImgClick(TObject *Sender){
	UnicodeString msg = "<" + User->Text + "> " + Message->Text;
	TThread::Synchronize(TThread::CurrentThread,
	[&](){
		UnicodeString encMsg;
		std::unique_ptr<TMemoryStream> PubK (new TMemoryStream);
		PubK->LoadFromFile("PubK.bin");
		Signatory->LoadKeysFromStream(PubK.get(), TKeyStoragePartSet() << partPublic);
		Assymetric->EncryptString(msg, encMsg, TEncoding::UTF8);

		UnicodeString encAESmsg;
		Symetric->Password = secretEncKey;
		Symetric->EncryptString(encMsg, encAESmsg, TEncoding::UTF8);

		TCPClient->Socket->WriteLn(encAESmsg);
	});
	fs << "Sent " << "<" << User->Text << "> " << Message->Text << " to server.\n";
	Message->Text = "";
}
//---------------------------------------------------------------------------

//Send text message over TCP with 1. RSA encryption and then 2. AES encryption, but when the ENTER key is pressed
void __fastcall TChat::MessageKeyPress(TObject *Sender, System::WideChar &Key){
	if(GetKeyState(VK_RETURN) & 0x8000){
    	UnicodeString msg = "<" + User->Text + "> " + Message->Text;
		TThread::Synchronize(TThread::CurrentThread,
		[&](){
			UnicodeString encMsg;
			std::unique_ptr<TMemoryStream> PubK (new TMemoryStream);
			PubK->LoadFromFile("PubK.bin");
			Signatory->LoadKeysFromStream(PubK.get(), TKeyStoragePartSet() << partPublic);
			Assymetric->EncryptString(msg, encMsg, TEncoding::UTF8);

            UnicodeString encAESmsg;
			Symetric->Password = secretEncKey;
			Symetric->EncryptString(encMsg, encAESmsg, TEncoding::UTF8);

			TCPClient->Socket->WriteLn(encAESmsg);
		});
		fs << "Sent " << "<" << User->Text << "> " << Message->Text << " to server.\n";
		Message->Text = "";
	}
}
//---------------------------------------------------------------------------

//UDP receive list of users
void __fastcall TChat::UDPServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding){
    TThread::Synchronize(TThread::CurrentThread,
	[&](){
		UnicodeString msg = BytesToString(AData);
        fs << "Message: " << msg << "\n";

		if(msg.IsDelimiter("!", 1)){
			UnicodeString addUser = msg.SubString(msg.Pos("!")+1, msg.Pos("-")-2);
			fs << "Added user " << addUser << " to list of users!\n";
			Chat->Users->Items->Add(addUser);
		}else if(msg.IsDelimiter("/", 1)){
			UnicodeString removeUser = msg.SubString(msg.Pos("/")+1, msg.Pos("-")-2);
			Chat->Users->Items->Delete(Chat->Users->Items->IndexOf(removeUser));
		}else if(msg == "ClientIPChange"){
			int x = Users->Items->Count;
			for(int i = 0; i < x; i++){
				Users->Items->Delete(i);
			}
		}
    });
}
//---------------------------------------------------------------------------

//TCP receive encrypted messages
void __fastcall TChat::TCPServerExecute(TIdContext *AContext){
	UnicodeString msg = AContext->Connection->Socket->ReadLn();

	UnicodeString decMsg;
	std::unique_ptr<TMemoryStream> PrivK (new TMemoryStream);
	PrivK->LoadFromFile("PrivK.bin");
	Signatory->LoadKeysFromStream(PrivK.get(), TKeyStoragePartSet() << partPrivate);

	Assymetric->DecryptString(decMsg, msg, TEncoding::UTF8);

	TThread::Synchronize(TThread::CurrentThread,
	[&](){
		Chat->Messages->Items->Add(decMsg);
	});
}
//---------------------------------------------------------------------------

//When closing down the EncryptedTCPChatBox.cpp form, disconnect from server
void __fastcall TChat::FormCloseQuery(TObject *Sender, bool &CanClose){
	TCPClient->Disconnect();
    TCPServer->Active = FALSE;
	Status->Brush->Color = clRed;
}
//---------------------------------------------------------------------------

//Loading program config from generalSettings.ini file
void __fastcall TChat::FormShow(TObject *Sender){
    TIniFile *Ini = new TIniFile(GetCurrentDir() + "\\generalSettings.ini");
	if(Ini->ReadString("Options", "Language", "") == "ENG"){
		TranslateToENG();
	}
	if(Ini->ReadString("Options", "Language", "") == "HR"){
		TranslateToHR();
	}

	Chat->Color = StringToColor(Ini->ReadString("Options", "Color", ""));
	Chat->Font->Name = Ini->ReadString("Options", "Font", OptionsS->ComboBox2->Text);

	delete Ini;
}
//---------------------------------------------------------------------------

