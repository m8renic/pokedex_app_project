//---------------------------------------------------------------------------

#ifndef EncryptedTCPChatBoxH
#define EncryptedTCPChatBoxH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Dialogs.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
#include <IdUDPClient.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Codec.hpp"
#include <System.SysUtils.hpp>
#include "uTPLb_Signatory.hpp"
#include "uTPLb_Hash.hpp"
#include <IdIOHandler.hpp>
#include <IdIOHandlerStream.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTP.hpp>
//---------------------------------------------------------------------------
class TChat : public TForm{
__published:	// IDE-managed Components
	TListBox *Messages;
	TListBox *Users;
	TEdit *Message;
	TShape *Shape1;
	TLabel *L1;
	TEdit *IPEdit;
	TLabel *L2;
	TEdit *User;
	TButton *B1;
	TShape *Status;
	TButton *B2;
	TImage *SendImg;
	TIdTCPClient *TCPClient;
	TIdUDPServer *UDPServer;
	TCryptographicLibrary *CryptographicLibrary;
	TCodec *Assymetric;
	TSignatory *Signatory;
	TLabel *L3;
	TEdit *Pass;
	THash *Hashing;
	TIdTCPServer *TCPServer;
	TCodec *Symetric;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall B1Click(TObject *Sender);
	void __fastcall B2Click(TObject *Sender);
	void __fastcall SendImgClick(TObject *Sender);
	void __fastcall MessageKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall UDPServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding);
	void __fastcall TCPServerExecute(TIdContext *AContext);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TChat(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChat *Chat;
//---------------------------------------------------------------------------
#endif
