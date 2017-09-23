#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include "Macierz2x2.hh"


class Wektor2D 
{
	
public:

 	Wektor2D() 
	{ 
		for(unsigned int i = 0; i < rozmiar; i++)
			wek[i] = 0.0; //bo double 
	}

	Wektor2D(double a, double b) 
	{
		wek[0] = a;
		wek[1] = b;
	}
	~Wektor2D() = default;                      //obczaic default
	double& operator [] (unsigned int index)    //przeciazenie operatorow w momencie const!!! najpierw kompilator szuka operatorow const
	{
		return wek[index];
	}

	double operator [] (unsigned int index) const   //nie mozna zwrocic referencji, bo metoda jest const, czyli zapewnia, ze pole klasy nie
	{												//											zostanie zmienione
		return wek[index];
	}

	Wektor2D operator + (const Wektor2D& wektor) const;
	Wektor2D operator - (const Wektor2D& wektor) const;
	bool operator == (const Wektor2D& wektor) const;
	friend Wektor2D operator * (const Macierz2x2& macierz, const Wektor2D& wektor);	
	friend std::istream& operator >> (std::istream &Strm, Wektor2D &wektor);
	friend std::ostream& operator << (std::ostream &Strm, const Wektor2D &wektor);


private:
	
	//static const unsigned int rozmiar = 2; //zeby tylko byla jedna zmienna dla ilus tam obiektow
	//constexpr vs const
	static constexpr unsigned int rozmiar = 2;						
	double wek[rozmiar]; // why does it work? = {0,1}, bo C++11;

};

/* przyklad 
double tab[2] = {1, 2};
vector<double> vec(std::begin(tab), std::end(tab));
*/


#endif
