#include "Macierz2x2.hh"


Macierz2x2::Macierz2x2(double arg)
{
	mac[0][0] = cos(arg);
	mac[0][1] = -sin(arg);
	mac[1][0] = sin(arg);
	mac[1][1] = cos(arg);
}


std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Macierz)
{
		Strm << Macierz.mac[0][0] << " " << Macierz.mac[0][1] << std::endl
				<< Macierz.mac[1][0] << " " << Macierz.mac[1][1] << std::endl;

	return Strm;
}



