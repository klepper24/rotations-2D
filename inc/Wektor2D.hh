#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>


class Wektor2D {


	double x;
	double y;
	
  public:

 
	Wektor2D() {}
	~Wektor2D() {}
	   
};



std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);


std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
