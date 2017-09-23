#include "Macierz2x2.hh"


Macierz2x2::Macierz2x2(double degree)
{
	mac[0][0] = mac[1][1] = cos(degree * PI / 180.0);
	mac[0][1] = -sin(degree * PI / 180.0);
	mac[1][0] = sin(degree * PI / 180.0);
	
}


std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &macierz)
{
		
	for(unsigned int i = 0; i < macierz.rozmiar; ++i)
		for(unsigned int j = 0; j < macierz.rozmiar; ++j)
  			Strm << std::setw(16) << std::fixed << std::setprecision(10) << macierz.mac[i][j];

	return Strm << std::endl;
}



