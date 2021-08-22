//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "pomocna.h"
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *Slika;
	TRadioButton *RadioButtonDodajDuzi;
	TButton *ButtonPresjekDuzi;
	TLabel *LabelKoordinate;
	TEdit *EditKoordinate;
	void __fastcall SlikaMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall PresjekDuziClick(TObject *Sender);
private:	// User declarations

	vector<Tacka> tackePresjeka;
	vector<Duz> duzi;
	Tacka *tackaPocetakDuzi;
	void dodajTacku(Tacka);
	void presjekDuzi(vector<Duz> &vDuzi);
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
