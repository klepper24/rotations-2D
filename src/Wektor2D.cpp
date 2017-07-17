#include "Wektor2D.hh"



std::istream& Wektor2D::operator >> (std::istream &Strm, Wektor2D &Wek)
{
	Strm << "Enter 'x' coordinate: " << std::endl;	
	Strm >> Wek.x;
	Strm << "Enter 'y' coordinate: " << std::endl;	
	Strm >> Wek.y;

	return Strm;
}


std::ostream& Wektor2D::operator << (std::ostream &Strm, const Wektor2D &Wek)
{

	Strm << "[" << Wek.x << "," << Wek.y << "]" << endl;

	return Strm;
}
