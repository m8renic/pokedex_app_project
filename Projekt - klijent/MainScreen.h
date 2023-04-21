//---------------------------------------------------------------------------

#ifndef MainScreenH
#define MainScreenH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportImage.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Menus.hpp>
#include <IdBaseComponent.hpp>
#include <IdIntercept.hpp>
#include <IdLogBase.hpp>
#include <IdLogFile.hpp>
//---------------------------------------------------------------------------
class TMain : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TShape *Shape2;
	TLabel *L2;
	TLabel *L3;
	TLabel *L1;
	TShape *Shape3;
	TLabel *L4;
	TComboBox *GenSelect;
	TComboBox *PrimaryT;
	TComboBox *SecondaryT;
	TEdit *SearchPokeName;
	TButton *SearchPoke;
	TButton *AddNewPoke;
	TButton *UpdatePokeEntry;
	TButton *DeletePokeEntry;
	TDBGrid *DBGrid1;
	TScrollBox *ScrollBox1;
	TLabel *L5;
	TLabel *L6;
	TLabel *L7;
	TLabel *L8;
	TLabel *L9;
	TLabel *L10;
	TLabel *L11;
	TLabel *L12;
	TLabel *L13;
	TLabel *L14;
	TLabel *L15;
	TLabel *L16;
	TImage *Learnset;
	TDBEdit *DBEditDEXENTRY;
	TDBEdit *DBEditNAME;
	TDBEdit *DBEdit3;
	TDBEdit *DBEditPTUP;
	TDBEdit *DBEdit5;
	TDBEdit *DBEdit6;
	TDBEdit *DBEdit7;
	TDBEdit *DBEdit8;
	TDBEdit *DBEdit9;
	TDBEdit *DBEdit10;
	TDBEdit *DBEdit11;
	TDBImage *DBImage1;
	TADOConnection *PokeDBConnection;
	TADOTable *ListOfPoke;
	TIntegerField *ListOfPokeID;
	TWideStringField *ListOfPokeDexEntry;
	TIntegerField *ListOfPokeGen;
	TWideStringField *ListOfPokeName;
	TWideStringField *ListOfPokePrimaryType;
	TWideStringField *ListOfPokeSecondaryType;
	TBlobField *ListOfPokePokeIcon;
	TDataSource *PokeDataSource;
	TMainMenu *ExportPopUp;
	TMenuItem *N1;
	TMenuItem *S1;
	TMenuItem *S2;
	TMenuItem *S3;
	TMenuItem *N2;
	TMenuItem *Chat1;
	TMenuItem *DownloadDB;
	TfrxReport *PokeReportFile;
	TfrxDBDataset *PokeReportDB1;
	TfrxPNGExport *ExpAsPNG;
	TfrxPDFExport *ExpAsPDF;
	TfrxRTFExport *ExpAsRTF;
	TADOTable *PokeL;
	TIntegerField *PokeLID;
	TDataSource *PLC;
	TfrxDBDataset *PokeReportDB2;
	TIntegerField *ListOfPokeHP;
	TIntegerField *ListOfPokeATK;
	TIntegerField *ListOfPokeDEF;
	TIntegerField *ListOfPokeSPATK;
	TIntegerField *ListOfPokeSPDEF;
	TIntegerField *ListOfPokeSPD;
	TLabel *Label2;
	TWideMemoField *PokeLLearnset;
	TIntegerField *ListOfPokeOverall;
	TLabel *OVL;
	TDBEdit *OVEdit;
    void __fastcall SearchPokeClick(TObject *Sender);
	void __fastcall AddNewPokeClick(TObject *Sender);
	void __fastcall DeletePokeEntryClick(TObject *Sender);
	void __fastcall UpdatePokeEntryClick(TObject *Sender);
	void __fastcall ExportAsPDF(TObject *Sender);
	void __fastcall ExportAsRTF(TObject *Sender);
	void __fastcall ExportAsPNG(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ListOfPokeAfterScroll(TDataSet *DataSet);
	void __fastcall Chat1Click(TObject *Sender);
	void __fastcall DownloadDBClick(TObject *Sender);
	void __fastcall ListOfPokeCalcFields(TDataSet *DataSet);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain *Main;
void TranslateToENG();
void TranslateToHR();
//---------------------------------------------------------------------------
#endif
