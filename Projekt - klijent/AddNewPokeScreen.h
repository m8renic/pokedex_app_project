//---------------------------------------------------------------------------

#ifndef AddNewPokeScreenH
#define AddNewPokeScreenH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TAddPokeForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *L2;
	TLabel *L3;
	TLabel *L4;
	TLabel *L5;
	TLabel *L6;
	TLabel *L7;
	TLabel *L8;
	TLabel *L9;
	TLabel *L10;
	TLabel *L11;
	TLabel *L1;
	TButton *FinishAdd;
	TShape *Shape1;
	TEdit *DBEditDexEntry;
	TEdit *DBEditName;
	TEdit *DBEditGen;
	TEdit *DBEditPT;
	TEdit *DBEditST;
	TEdit *DBEditHP;
	TEdit *DBEditATK;
	TEdit *DBEditDEF;
	TEdit *DBEditSPATK;
	TEdit *DBEditSPDEF;
	TEdit *DBEditSPD;
	TOpenPictureDialog *OpenPokePic;
	TButton *AddImgBtn;
	TButton *AddPokeLearnset;
	TOpenPictureDialog *OpenLearnset;
	void __fastcall FinishAddClick(TObject *Sender);
	void __fastcall AddImgBtnClick(TObject *Sender);
	void __fastcall AddPokeLearnsetClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddPokeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddPokeForm *AddPokeForm;
//---------------------------------------------------------------------------
#endif
