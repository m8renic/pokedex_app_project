//---------------------------------------------------------------------------

#ifndef ServerInterfaceH
#define ServerInterfaceH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdIntercept.hpp>
#include <IdLogBase.hpp>
#include <IdLogFile.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <IdUDPServer.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Signatory.hpp"
#include <System.SysUtils.hpp>
#include <IdCmdTCPServer.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTPServer.hpp>
#include <IdTrivialFTPServer.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "uTPLb_Hash.hpp"
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <Vcl.Menus.hpp>
#include <IdUserAccounts.hpp>
//---------------------------------------------------------------------------
class TServer : public TForm
{
__published:	// IDE-managed Components
	TRESTRequest *RESTRequest1;
	TShape *Shape1;
	TLabel *Label1;
	TEdit *IPRO;
	TRESTResponse *RESTResponse1;
	TBindingsList *BindingsList1;
	TLinkControlToField *LinkControlToField1;
	TButton *GetIP;
	TButton *Button1;
	TButton *Button2;
	TShape *Status;
	TIdTCPServer *ChatServer;
	TListBox *Messages;
	TListBox *Users;
	TIdUDPClient *UDPClient;
	TADOConnection *UsersConnection;
	TADOTable *UsersTable;
	THash *Hash;
	TCryptographicLibrary *CryptographicLibrary1;
	TMainMenu *MainMenu1;
	TMenuItem *Manageusers1;
	TWideStringField *UsersTableUsername;
	TIdTCPClient *TCPForward;
	TWideStringField *UsersTablePassword;
	TRESTClient *IPRESTClient;
	TCodec *Symetric;
	void __fastcall GetIPClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ChatServerExecute(TIdContext *AContext);
	void __fastcall ChatServerConnect(TIdContext *AContext);
	void __fastcall ChatServerDisconnect(TIdContext *AContext);
	void __fastcall Manageusers1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TServer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TServer *Server;
//---------------------------------------------------------------------------
#endif
