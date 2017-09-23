
#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double PI = atan2(0,-1);       //zamiast #define PI 3.14159265 

//template <int n, int m>
class Macierz2x2 {
	
public:

	//Macierz2x2() {}
	~Macierz2x2() {}
	Macierz2x2(double arg);
	//operator () do odczytywania wartosci z macierzy, do zapisywania nalezaloby zrobic kolejny operator, patrz: 
	double operator () (unsigned int a, unsigned int b) const
	{
		return mac[a][b];	
	}

	friend std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &macierz);
	//funkcja niepotrzebna ze wzgledu na przeciazony operator funkcyjny ()
	/*
	double get_mac(int a, int b) const
	{
		return mac[a][b];	
	}*/

private:

	static constexpr unsigned int rozmiar = 2;  
	double mac[rozmiar][rozmiar];

};



#endif
