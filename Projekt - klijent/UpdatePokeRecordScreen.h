//---------------------------------------------------------------------------

#ifndef UpdatePokeRecordScreenH
#define UpdatePokeRecordScreenH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TUPPokeEntry : public TForm
{
__published:	// IDE-managed Components
	TLabel *L2;
	TLabel *L3;
	TLabel *L4;
	TLabel *L5;
	TLabel *L1;
	TButton *FinishUpdate;
	TShape *Shape1;
	TLabel *L8;
	TLabel *L7;
	TLabel *L6;
	TLabel *L11;
	TLabel *L10;
	TLabel *L9;
	TDBEdit *DBEditHPUP;
	TDBEdit *DBEditATKUP;
	TDBEdit *DBEditDEFUP;
	TDBEdit *DBEditSPDEFUP;
	TDBEdit *DBEditSPATKUP;
	TDBEdit *DBEditSPDUP;
	TDBEdit *DBEditNAME;
	TDBEdit *DBEditDEXUP;
	TDBEdit *DBEditGENUP;
	TDBEdit *DBEditPTUP;
	TDBEdit *DBEditSTUP;
	TButton *UpdatePokePicButton;
	TOpenPictureDialog *UpdatePokePic;
	TButton *UpdatePLearnset;
	TOpenPictureDialog *UpdateLearnset;
	void __fastcall FinishUpdateClick(TObject *Sender);
	void __fastcall UpdatePokePicButtonClick(TObject *Sender);
	void __fastcall UpdatePLearnsetClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TUPPokeEntry(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TUPPokeEntry *UPPokeEntry;
//---------------------------------------------------------------------------
#endif
