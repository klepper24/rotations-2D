#include "Wektor2D.hh"



std::istream& operator >> (std::istream &Strm, Wektor2D &Wektor)
{
	Strm >> Wektor.wek[0];	
	Strm >> Wektor.wek[1];

	return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wektor)
{

	Strm << "[" << Wektor.wek[0] << "," << Wektor.wek[1] << "]" << std::endl;

	return Strm;
} 


Wektor2D operator * (Macierz2x2 macierz, Wektor2D wektor)
{
	Wektor2D prim;		
	prim.wek[0] = macierz.get_mac(0,0) * wektor[0] + macierz.get_mac(0,1) * wektor[1];
	prim.wek[1] = macierz.get_mac(1,0) * wektor[0] + macierz.get_mac(1,1) * wektor[1];
	
	return prim;
}
