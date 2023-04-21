//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerInterface.h"
#include "ManageUsersScreen.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Hash"
#pragma resource "*.dfm"
TManageUsers *ManageUsers;
//---------------------------------------------------------------------------
__fastcall TManageUsers::TManageUsers(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TManageUsers::AddUserBClick(TObject *Sender){
	MHash->HashString(AddPEdit->Text, TEncoding::UTF8);
	UnicodeString hashOfPass = Stream_To_Hex(MHash->HashOutputValue);
	MHash->HashString(hashOfPass + AddPEdit->Text, TEncoding::UTF8);
	UnicodeString finalHash = Stream_To_Hex(MHash->HashOutputValue);

	Server->UsersTable->Append();

	Server->UsersTable->FieldByName("Username")->AsString = AddUEdit->Text;
	Server->UsersTable->FieldByName("Password")->AsString = finalHash;

	Server->UsersTable->Post();

	AddUEdit->Text = "";
    AddPEdit->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TManageUsers::UpdateUserBClick(TObject *Sender){
	MHash->HashString(AddPEdit->Text, TEncoding::UTF8);
	UnicodeString hashOfPass = Stream_To_Hex(MHash->HashOutputValue);
	MHash->HashString(hashOfPass + AddPEdit->Text, TEncoding::UTF8);
	UnicodeString finalHash = Stream_To_Hex(MHash->HashOutputValue);

	Server->UsersTable->Edit();

    Server->UsersTable->FieldByName("Username")->AsString = AddUEdit->Text;
	Server->UsersTable->FieldByName("Password")->AsString = finalHash;

	Server->UsersTable->Post();
}
//---------------------------------------------------------------------------

void __fastcall TManageUsers::DeleteUserButtonClick(TObject *Sender){
	Server->UsersTable->Delete();
	Server->UsersTable->First();
}
//---------------------------------------------------------------------------

