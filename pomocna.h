//---------------------------------------------------------------------------
#ifndef pomocnaH
#define pomocnaH
#include <vector>
using namespace std;

struct Tacka {
	int x;
	int y;
	Tacka():x(0),y(0) {}
	Tacka(int X, int Y):x(X),y(Y) {}
    void Crtaj(TImage*) const;
};

bool operator==(Tacka,Tacka);
bool operator!=(Tacka,Tacka);
bool operator<(Tacka,Tacka);

struct Duz {
	Tacka pocetak;
	Tacka kraj;
	bool otkrivena;
	Duz(Tacka A,Tacka B):pocetak(A),kraj(B),otkrivena(false) {
		if(kraj < pocetak)
			swap(pocetak,kraj);
	}
	void Crtaj(TImage*) const;
};

struct Trougao {
	Tacka A;
	Tacka B;
	Tacka C;
	Trougao(Tacka A, Tacka B, Tacka C):A(A),B(B),C(C) {}
	void Crtaj(TImage*) const;
};



void iscrtajPoligon(vector<Tacka> &poligon, TImage *image);
int Orijentacija(Tacka,Tacka,Tacka);
int PresjekDuzi(Duz, Duz);
bool daLiJeTackaUnutarTrougla(Tacka,Trougao);
Tacka TackaPresjekaPravih(Duz, Duz);
double Udaljenost(Tacka A, Tacka B);



//---------------------------------------------------------------------------
#endif
