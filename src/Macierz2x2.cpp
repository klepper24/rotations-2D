#include "Macierz2x2.hh"


Macierz2x2::Macierz2x2(double arg)
{
	mac[0][0] = cos(arg * PI / 180.0);
	mac[0][1] = -sin(arg * PI / 180.0);
	mac[1][0] = sin(arg * PI / 180.0);
	mac[1][1] = cos(arg * PI / 180.0);
}


std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Macierz)
{
		

  Strm << setw(16) << fixed << setprecision(10) << Macierz.mac[0][0]
       << setw(16) << fixed << setprecision(10) << Macierz.mac[0][1]
  	   << setw(16) << fixed << setprecision(10) << Macierz.mac[1][0] 
       << setw(16) << fixed << setprecision(10) << Macierz.mac[1][1] << endl;


	return Strm;
}



