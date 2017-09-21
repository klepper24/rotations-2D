#include "Wektor2D.hh"

Wektor2D Wektor2D::operator + (const Wektor2D& wektor) const
{
	Wektor2D temp;//zrobic petle
	temp.wek[0] = wek[0] + wektor.wek[0];
	temp.wek[1] = wek[1] + wektor.wek[1];
	
	return temp;
}


Wektor2D Wektor2D::operator - (const Wektor2D& wektor) const
{
	Wektor2D temp;  ///zrobic petle!!
	temp.wek[0] = wek[0] - wektor.wek[0];
	temp.wek[1] = wek[1] - wektor.wek[1];
	
	return temp;
}

bool Wektor2D::operator == (const Wektor2D& wektor) const
{
	for(unsigned int i = 0; i < rozmiar; ++i)
	{		
		if(wek[i] != wektor.wek[i])
			return false;
	}
	return true;
}

Wektor2D operator * (const Macierz2x2& macierz, const Wektor2D& wektor)
{
	Wektor2D prim; //petla w petli
	prim.wek[0] = macierz(0,0) * wektor[0] + macierz.operator() (0,1) * wektor[1];
	prim.wek[1] = macierz(1,0) * wektor[0] + macierz(1,1) * wektor[1];
	
	return prim;
}


std::istream& operator >> (std::istream &Strm, Wektor2D &Wektor)
{
	Strm >> Wektor.wek[0] >> Wektor.wek[1];

	return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wektor)
{

	  Strm << setw(16) << fixed << setprecision(10) << Wektor.wek[0] 
       << setw(16) << fixed << setprecision(10) << Wektor.wek[1] << endl;
	//Strm << "[" << Wektor.wek[0] << "," << Wektor.wek[1] << "]" << std::endl;

	return Strm;
} 



