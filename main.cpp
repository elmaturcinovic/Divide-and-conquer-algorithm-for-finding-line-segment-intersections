//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Slika->Canvas->FillRect(Rect(0,0,Slika->Width,Slika->Height));
	tackaPocetakDuzi = nullptr;
}
//---------------------------------------------------------------------------
void TForm2::dodajTacku(Tacka nova) {
	nova.Crtaj(Slika);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SlikaMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
    EditKoordinate->Text = "( " + IntToStr(X) + " , " + IntToStr(Y) + " )";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SlikaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if(RadioButtonDodajDuzi->Checked) {
		if(!tackaPocetakDuzi) {
			tackaPocetakDuzi = new Tacka(X,Y);
			tackaPocetakDuzi->Crtaj(Slika);
		}
		else {
			Duz nova(*tackaPocetakDuzi, Tacka(X,Y));
			duzi.push_back(nova);
			nova.Crtaj(Slika);
			tackaPocetakDuzi = nullptr;
		}
	}
}
//---------------------------------------------------------------------------
 void TForm2::presjekDuzi(vector<Duz> &v) {

	//Ukoliko imamo prazan vektor duzi ili imamo u njemu samo jednu duz,
	//tada ne mozemo imati presjeke, pa tu zavrsavamo funkciju
	if (v.size()<=1) return;

	//Ukoliko je broj duži jednak 2, provjeravamo da li se te dvije duži sijeku
	if (v.size()==2) {
		if (PresjekDuzi(v[0],v[1])==1) {
			Tacka presjek = TackaPresjekaPravih(v[0],v[1]);
			presjek.Crtaj(Slika);
			tackePresjeka.push_back(presjek);
		}
		return;
	}

	//Ukoliko imamo niz duži dužine veće od 2
	//Uzimamo random duž iz niza duži
	 int random = rand() % v.size();
	 Duz randomDuz = v[random];

	 //Duži dijelimo na dvije skupine, u odnosu na to s koje strane prave koju
	 //određuje odabrana duž
	 //poluravan1 ima orijentaciju -1, poluravan2 ima orijentaciju 1
	 vector<Duz> poluravan1, poluravan2;
	 for (int i = 0; i < v.size(); i++) {
		  if (i== random) continue;
		  int orijentacija1 = Orijentacija(randomDuz.pocetak,randomDuz.kraj,v[i].pocetak);
		  int orijentacija2 = Orijentacija(randomDuz.pocetak,randomDuz.kraj,v[i].kraj);
		  if (orijentacija1 == orijentacija2 && orijentacija1 == -1) {
			poluravan1.push_back(v[i]);
			continue;
		  }
		  else if (orijentacija1 == orijentacija2 && orijentacija1 == 1) {
					poluravan2.push_back(v[i]);
					continue;
		  }
		  else {
			Tacka presjek = TackaPresjekaPravih(v[i],randomDuz);

			if (orijentacija1 == -1) {
				   poluravan1.push_back(Duz(v[i].pocetak,presjek));
				   poluravan2.push_back(Duz(v[i].kraj,presjek));
			}
			else {
				poluravan2.push_back(Duz(v[i].pocetak,presjek));
				poluravan1.push_back(Duz(v[i].kraj,presjek));
			}

			if ((Udaljenost(randomDuz.pocetak,presjek)<Udaljenost(randomDuz.pocetak,randomDuz.kraj))&&
				(Udaljenost(randomDuz.kraj,presjek)<Udaljenost(randomDuz.pocetak,randomDuz.kraj))) {
					presjek.Crtaj(Slika);
					tackePresjeka.push_back(presjek);
			}
		  }
	 }
	 presjekDuzi(poluravan1);
	 presjekDuzi(poluravan2);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::PresjekDuziClick(TObject *Sender)
{
	Slika->Canvas->Brush->Color = clRed;
	presjekDuzi(duzi);
}
//---------------------------------------------------------------------------
