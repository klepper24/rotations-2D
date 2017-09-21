#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include "Macierz2x2.hh"


class Wektor2D {


	double wek[2]; // why does it work? = {0,1};
	
	
  public:

 
	Wektor2D(double a = 0, double b = 0) 
	{
		wek[0] = a;
		wek[1] = b;
	}
	~Wektor2D() {}
	double& operator [] (int index)
	{
		return wek[index];
	}
	friend Wektor2D operator * (Macierz2x2 macierz, Wektor2D wektor);
	friend std::istream& operator >> (std::istream &Strm, Wektor2D &Wektor);
	friend std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wektor);


};



#endif
