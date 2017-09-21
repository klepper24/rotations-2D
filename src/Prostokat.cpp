#include "Prostokat.hh"


void Prostokat::obroc(Macierz2x2 macierz)
{
	p1 = macierz * p1;    //petle!!
	p2 = macierz * p2;
	p3 = macierz * p3;
	p4 = macierz * p4;
}

void Prostokat::przesun(Wektor2D wektor)
{
	p1 = p1 + wektor;
	p2 = p2 + wektor;
	p3 = p3 + wektor;
	p4 = p4 + wektor;
}

void Prostokat::sprawdzDlugoscPrzeciwleglychBokow()
{	
		
	if((p2 - p1) == (p3 - p4))
		cout << "Dluzsze przeciwlegle boki sa sobie rowne!" << endl;
	else
		cout << "Ups! Dluzsze przeciwlegle boki NIE sa sobie rowne! Uwaga na niedokladnosci!" << endl;

	if((p3 - p2) == (p4 - p1))
		cout << "Krotsze przeciwlegle boki sa sobie rowne!" << endl;
	else
		cout << "Ups! Krotsze przeciwlegle boki NIE sa sobie rowne! Uwaga na niedokladnosci!" << endl;
}

std::ostream& operator << (std::ostream &Strm, const Prostokat &Pr)
{

  Strm << setw(16) << fixed << setprecision(10) << Pr.p1
       << setw(16) << fixed << setprecision(10) << Pr.p2
  	   << setw(16) << fixed << setprecision(10) << Pr.p3 
       << setw(16) << fixed << setprecision(10) << Pr.p4 << endl;		
	
	return Strm;
}

