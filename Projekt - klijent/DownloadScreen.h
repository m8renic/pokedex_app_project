//---------------------------------------------------------------------------

#ifndef DownloadScreenH
#define DownloadScreenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IdBaseComponent.hpp"
#include "IdComponent.hpp"
#include "IdHTTP.hpp"
#include "IdTCPClient.hpp"
#include "IdTCPConnection.hpp"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <IdIntercept.hpp>
#include <IdInterceptThrottler.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Net.HttpClient.hpp>
#include <System.Net.HttpClientComponent.hpp>
#include <System.Net.URLClient.hpp>
//---------------------------------------------------------------------------
class TDownDB : public TForm
{
__published:	// IDE-managed Components
	TProgressBar *Progress;
	TComboBox *CLimits;
	TButton *BDownload;
	TIdInterceptThrottler *IdInterceptThrottler1;
	TShape *Shape1;
	TLabel *L1;
	TButton *BCancel;
	TIdHTTP *HTTP;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	TEdit *E;
	void __fastcall CLimitsChange(TObject *Sender);
	void __fastcall BDownloadClick(TObject *Sender);
	void __fastcall BCancelClick(TObject *Sender);
	void __fastcall HTTPWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall HTTPWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall HTTPWorkEnd(TObject *ASender, TWorkMode AWorkMode);
	void __fastcall FormShow(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TDownDB(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDownDB *DownDB;
//---------------------------------------------------------------------------
#endif
