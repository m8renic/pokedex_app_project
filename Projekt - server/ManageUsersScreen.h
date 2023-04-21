//---------------------------------------------------------------------------

#ifndef ManageUsersScreenH
#define ManageUsersScreenH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"
//---------------------------------------------------------------------------
class TManageUsers : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDataSource *UserSource;
	TLabel *AddU;
	TLabel *AddP;
	TGroupBox *GroupBox1;
	TEdit *AddUEdit;
	TEdit *AddPEdit;
	TGroupBox *UpdateUser;
	TLabel *UpU;
	TLabel *UpP;
	TGroupBox *DeleteUser;
	TDBEdit *DBUserEdit;
	TDBEdit *DBUserDeleteEdit;
	TLabel *DelU;
	TLabel *DelP;
	TButton *DeleteUserButton;
	TButton *AddUserB;
	TButton *UpdateUserB;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	THash *MHash;
	TCryptographicLibrary *CryptographicLibrary1;
	void __fastcall AddUserBClick(TObject *Sender);
	void __fastcall UpdateUserBClick(TObject *Sender);
	void __fastcall DeleteUserButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TManageUsers(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TManageUsers *ManageUsers;
//---------------------------------------------------------------------------
#endif
