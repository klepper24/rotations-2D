#include "Wektor2D.hh"

Wektor2D Wektor2D::operator + (const Wektor2D& wektor) const
{
	Wektor2D temp;
	for(unsigned int i = 0; i < rozmiar; ++i)
	{
		temp.wek[i] = wek[i] + wektor.wek[i];
	}

	
	return temp;
}


Wektor2D Wektor2D::operator - (const Wektor2D& wektor) const
{
	Wektor2D temp;  
	for(unsigned int i = 0; i < rozmiar; ++i)
	{
		temp.wek[i] = wek[i] - wektor.wek[i];
	}
	
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
	Wektor2D prim;

	for(unsigned int i = 0; i < wektor.rozmiar; ++i)
		for(unsigned int j = 0; j < wektor.rozmiar; ++j)
				prim.wek[i] += macierz(i,j) * wektor[j];
	
	
	return prim;
}


std::istream& operator >> (std::istream &Strm, Wektor2D &wektor)
{
	for(unsigned int i = 0; i < wektor.rozmiar; ++i)	
		Strm >> wektor.wek[i];

	return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor2D &wektor)
{

	  Strm << setw(16) << fixed << setprecision(10) << wektor.wek[0] 
       << setw(16) << fixed << setprecision(10) << wektor.wek[1] << endl;

	return Strm;
} 



