//---------------------------------------------------------------------------

#ifndef OptionsScreenH
#define OptionsScreenH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TOptionsS : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TComboBox *ComboBox1;
	TLabel *L1;
	TColorDialog *ColorPicking;
	TLabel *L2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TLabel *L3;
	TComboBox *ComboBox2;
	void __fastcall ColorPickClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall ApplySettingsClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TOptionsS(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionsS *OptionsS;
//---------------------------------------------------------------------------
#endif
