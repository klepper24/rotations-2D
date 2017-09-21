#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;

int main()
{
	Wektor2D wek1(3,4), wek2;
	Macierz2x2 mac1(30);

	wek2 = mac1 * wek1;
	wek2 = mac1 * wek2;
	wek2 = mac1 * wek2;

	cout << mac1;
	cout << wek2;

	return 0;
}


/*
EXAMPLE OF TEMPLATE CLASS FOR MATRIX OF DIFFERENT DIMENSIONS

template<int N, int M>
class Matrix
{
	double arr[N][M];
public:
	Matrix() = default;
	Matrix(std::initializer_list<double> lista)
	{
		if (lista.size() > N * M)		
			throw std::runtime_error("to ja");

		unsigned int licznik = 0u;
		for(auto it : lista)
		{
			arr[licznik / M][licznik % M] = it;
			++licznik;
		}
	}
};

int main()
{
	Macierz2x2 mac1;
	Matrix<2, 3> mac2({3.5, 2.5, 4.5});

}*/


