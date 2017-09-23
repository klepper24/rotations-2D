#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Wektor2D.hh"


class Prostokat {

public:
	
	//konstruktor do podejscia pierwszego
	//Prostokat(Wektor2D punkt1, Wektor2D punkt2, Wektor2D punkt3, Wektor2D punkt4): p1(punkt1), p2(punkt2), p3(punkt3), p4(punkt4) {};
	
	Prostokat(std::initializer_list<Wektor2D> l) : punkty(l) {} //konstruktor dla vectora z std na bazie initializer_list
	~Prostokat() = default;
    void obroc(Macierz2x2 macierz);
	void przesun(Wektor2D wektor);
	void sprawdzDlugoscPrzeciwleglychBokow();
	friend void zapisWspolrzednychDoStrumienia(std::ostream& StrmWy, Prostokat& Pr);
    friend std::ostream& operator << ( std::ostream& Strm, const Prostokat& Pr);

private:
	
	//podejscie pierwsze:  Wektor2D p1, p2, p3, p4;       
	std::vector<Wektor2D> punkty;
																											
};






#endif
