#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include <cmath>

//template <int n, int m>
class Macierz2x2 {


	double mac[2][2];

  public:

	//Macierz2x2() {}
	~Macierz2x2() {}
	Macierz2x2(double arg);
	/*
	double& operator () (int a, int b)
	{
		return sth;	
	}
	*/	

	friend std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Macierz);

	double get_mac (int a, int b)
	{
		return mac[a][b];	
	}
};



#endif
