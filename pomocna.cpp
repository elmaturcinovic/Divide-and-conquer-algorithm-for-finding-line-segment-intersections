//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include "pomocna.h"


void Tacka::Crtaj(TImage *image) const {
    image->Canvas->Ellipse(x-4,y-4,x+4,y+4);
}

bool operator<(Tacka A, Tacka B) {
	if(A.x < B.x)
	  return true;
	if(A.x == B.x)
	  return A.y < B.y;
	return false;
}

bool operator==(Tacka A, Tacka B) {
  return A.x == B.x && A.y == B.y;
}

bool operator!=(Tacka A, Tacka B) {
    return !(A==B);
}


int Orijentacija(Tacka A, Tacka B, Tacka C) {

	int P = A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y);
	if(P > 0)
	  return -1;
	if(P < 0)
	  return 1;
	return 0;

}

void Duz::Crtaj(TImage *slika) const {
	pocetak.Crtaj(slika);
	kraj.Crtaj(slika);
	slika->Canvas->MoveTo(pocetak.x,pocetak.y);
	slika->Canvas->LineTo(kraj.x,kraj.y);
}

//1 za presjek
//0 ako nema presjeka
int PresjekDuzi(Duz p, Duz q) {
   int or1 = Orijentacija(p.pocetak,p.kraj,q.pocetak);
   int or2 = Orijentacija(p.pocetak,p.kraj,q.kraj);
   int or3 = Orijentacija(q.pocetak,q.kraj,p.pocetak);
   int or4 = Orijentacija(q.pocetak,q.kraj,p.kraj);


   if( or1 * or2 < 0 && or3 * or4 < 0)
	 return 1;
   return 0;
}

bool daLiJeTackaUnutarTrougla(Tacka P, Trougao t) {
	if(Orijentacija(t.A,t.B,P) == Orijentacija(t.B,t.C,P) &&
	   Orijentacija(t.B,t.C,P) == Orijentacija(t.C,t.A,P))
		 return true;
	return false;
}

void Trougao::Crtaj(TImage *image) const {
	image->Canvas->MoveTo(A.x,A.y);
	image->Canvas->LineTo(B.x,B.y);
	image->Canvas->LineTo(C.x,C.y);
	image->Canvas->LineTo(A.x,A.y);
}

Tacka TackaPresjekaPravih(Duz p, Duz q) {
	double a1 = p.kraj.y - p.pocetak.y;
	double b1 = p.pocetak.x - p.kraj.x;
	double c1 = a1*(p.pocetak.x) + b1*(p.pocetak.y);



	double a2 = q.kraj.y - q.pocetak.y;
	double b2 = q.pocetak.x - q.kraj.x;
	double c2 = a2*(q.pocetak.x) + b2*(q.pocetak.y);



	double determinant = a1*b2 - a2*b1;



    if (determinant == 0)
    {
        return Tacka(INT_MAX, INT_MAX);
    }
    else
    {
		double x = (b2*c1 - b1*c2)/determinant;
		double y = (a1*c2 - a2*c1)/determinant;
		return Tacka(round(x), round(y));
    }
}

double Udaljenost(Tacka A, Tacka B) {
  return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}



//---------------------------------------------------------------------------
#pragma package(smart_init)


