//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <fstream>
#include <string.h>
#pragma hdrstop

#include "ServerInterface.h"
#include "ManageUsersScreen.h"
#include <pngimage.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Signatory"
#pragma link "uTPLb_Hash"
#pragma resource "*.dfm"
TServer *Server;
std::wofstream fs;
UnicodeString userF;
UnicodeString secretEncKey = "LawfulChaotic!!#$%&/";
//---------------------------------------------------------------------------
__fastcall TServer::TServer(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TServer::FormCreate(TObject *Sender){
	Status->Brush->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TServer::GetIPClick(TObject *Sender){
	RESTRequest1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TServer::Button1Click(TObject *Sender){
	Status->Brush->Color = clLime;
	ChatServer->Active = TRUE;
	fs.open ("log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	fs << "Starting server!\n";
}
//---------------------------------------------------------------------------

void __fastcall TServer::Button2Click(TObject *Sender){

	Status->Brush->Color = clRed;
	ChatServer->Active = FALSE;
	fs << "Stopping server!\n";
	fs.close();
}
//---------------------------------------------------------------------------

void __fastcall TServer::ChatServerExecute(TIdContext *AContext){
	UnicodeString encMsg = AContext->Connection->Socket->ReadLn();
    fs << encMsg << "\n";

    UnicodeString msg;
    Symetric->Password = secretEncKey;
	Symetric->DecryptString(msg, encMsg, TEncoding::UTF8);

    fs << msg << "\n";

	if(msg != "ACK" && !msg.IsDelimiter(":", 1)){
		TList *list = ChatServer->Contexts->LockList();
		for (int i = 0; i < list->Count; i++) {
			TIdServerContext *peer = (TIdServerContext*)list->Items[i];
			TCPForward->Host = peer->Connection->Socket->Binding->PeerIP;
			try{
				TCPForward->Connect();
			}
			catch(...){
				continue;
			}
			TCPForward->Socket->WriteLn(msg);
			TCPForward->Disconnect();
		}
		ChatServer->Contexts->UnlockList();
		TThread::Synchronize(TThread::CurrentThread,
		[&](){
			fs << msg << "\n";
			Messages->Items->Add(msg);
			Messages->ItemIndex = Messages->Count - 1;
		});
	}else if(msg.IsDelimiter(":", 1)){
		UnicodeString user, pass, salt;
		user = msg.SubString(2, msg.Pos("!")-2);
		pass = msg.SubString(msg.Pos("!")+1, msg.Pos("$")-user.Length()-3);
		salt = msg.SubString(msg.Pos("$")+1, msg.Pos(msg.LastChar()));

		UsersTable->Filtered = FALSE;
		UsersTable->Filter = "Username = '" + user + "'";
		UsersTable->Filtered = TRUE;

		if(UsersTable->FieldByName("Username")->AsString != ""){
			UnicodeString HpassDB = UsersTable->FieldByName("Password")->AsString;
			Hash->HashString(HpassDB + salt, TEncoding::UTF8);
			UnicodeString passHashWSalt = Stream_To_Hex(Hash->HashOutputValue);
			fs << "\nServer pass hash: " + passHashWSalt;
			if(passHashWSalt != pass){
				AContext->Connection->Socket->WriteLn("Entered wrong username or password! Try again!");
				fs << "Something Wrong!\n";
			}else{
				AContext->Connection->Socket->WriteLn("Success!");
				UsersTable->Filtered = FALSE;
				UsersTable->Filter = "";
				UsersTable->Filtered = TRUE;
			}
		}
		fs << "\n" << user << "\n" << pass << "\n" << salt << "\n";
	}else{
		fs << "Message was successfully received by client!\n";
	}
}
//---------------------------------------------------------------------------

void __fastcall TServer::ChatServerConnect(TIdContext *AContext){
	Users->Items->Add(AContext->Connection->Socket->Binding->PeerIP);
	int x = Users->Items->Count;
	UDPClient->Broadcast("ClientIPChange", 25567);
	for(int i = 0; i < x; i++){
		UDPClient->Broadcast("!" + Users->Items->Strings[i] + "-", 25567);
	}
	fs << "Client connected to server from IP: " << AContext->Connection->Socket->Binding->PeerIP << "\n";
}
//---------------------------------------------------------------------------

void __fastcall TServer::ChatServerDisconnect(TIdContext *AContext){
	Users->Items->Delete(Users->Items->IndexOf(AContext->Connection->Socket->Binding->PeerIP));
	UDPClient->Broadcast("/" + AContext->Connection->Socket->Binding->PeerIP + "-", 25567);
	fs << "Client disconnected from server with IP: " << AContext->Connection->Socket->Binding->PeerIP << "\n";
}
//---------------------------------------------------------------------------

void __fastcall TServer::Manageusers1Click(TObject *Sender)
{
	if(ChatServer->Active != TRUE){
		ManageUsers->ShowModal();
	}else{
        ShowMessage("Shut down the server and try again!");
	}
}
//---------------------------------------------------------------------------

