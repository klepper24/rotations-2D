#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Wektor2D.hh"


class Prostokat {

	Wektor2D p1, p2, p3, p4;  //std::vector        
	 
  public:
	
	Prostokat(Wektor2D punkt1, Wektor2D punkt2, Wektor2D punkt3, Wektor2D punkt4): p1(punkt1), p2(punkt2), p3(punkt3), p4(punkt4) {};
	//konstruktor dla vecotra z std na bazie initializer_list
	~Prostokat() = default;
    void obroc(Macierz2x2 macierz);
	void przesun(Wektor2D wektor);
	void sprawdzDlugoscPrzeciwleglychBokow();
	friend void zapisWspolrzednychDoStrumienia(std::ostream& StrmWy, Prostokat &Pr, double Przesuniecie);
    friend std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr);

};






#endif
