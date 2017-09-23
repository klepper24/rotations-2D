#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"


void zapisWspolrzednychDoStrumienia(std::ostream& StrmWy, Prostokat &Pr)
{

	StrmWy << Pr;
	StrmWy << Pr.punkty[0] << std::endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool zapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostokat &Pr)
{
  std::ofstream StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  zapisWspolrzednychDoStrumienia(StrmPlikowy, Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

void obracanieProstokata(Prostokat& pro)
{
	std::cout << "Podaj wartosc kata obrotu w stopniach: " << std::endl;
	float kat;	
	std::cin >> kat;
	Macierz2x2 mac1(kat);

	std::cout << "Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
	unsigned int ile = 0;
	std::cin >> ile;
	for(unsigned int i = 0; i < ile; ++i)
		pro.obroc(mac1);
		
}

void przesuwanieProstokata(Prostokat& pro)
{
	std::cout << "Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb, tzn. wspolrzednej x oraz wspolrzednej y: " << std::endl;

	Wektor2D wek;
	std::cin >> wek;
	
	pro.przesun(wek);
}

void wyswietlanieWspolrzednych(Prostokat& pro)
{
	std::cout << pro;
}

void sprawdzenieBokow(Prostokat& pro)
{
	pro.sprawdzDlugoscPrzeciwleglychBokow();
}

void wyswietlMenu()
{
		std::cout << std::endl
			 << "o - obrot prostokata o zadany kat" << std::endl
			 << "p - przesuniecie prostokota o zadany wektor" << std::endl
			 << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl
			 << "s - sprawdzenie dlugosci przeciwleglych bokow" << std::endl
			 << "m - wyswietl menu" << std::endl
			 << "k - koniec dzialania programu" << std::endl;
}

int main()
{
	//getopt do robienia menu - poczytać!!!
	Prostokat pro1{Wektor2D(30,40),Wektor2D(30,100),Wektor2D(100,100),Wektor2D(100, 40)};

	PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);

	wyswietlMenu();
	char wybor = 'a';
	while(wybor != 'k')
	{

		std::cout << "Twoj wybor?\t";
		std::cin >> wybor;

		switch(wybor)
		{
			case 'o': 	obracanieProstokata(pro1);
						zapisWspolrzednychDoStrumienia(std::cout,pro1);
  						if (!zapisWspolrzednychDoPliku("prostokat.dat",pro1)) return 1;
  						Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
						break;

			case 'p':   przesuwanieProstokata(pro1);
						zapisWspolrzednychDoStrumienia(std::cout,pro1);
  						if (!zapisWspolrzednychDoPliku("prostokat.dat",pro1)) return 1;
  						Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
						break;

			case 'w': 	wyswietlanieWspolrzednych(pro1);
						break;

			case 's':   sprawdzenieBokow(pro1);
						break;

			case 'm':   wyswietlMenu();
						break;

			case 'k': 
						break;

			default:  std::cout << std::endl << "Bledny znak! Sprobuj jeszcze raz!" << std::endl;
						break;
		}
				
	}


	/*Prostokat pro1{{3,4},{10,4},{10,10},{3, 10}};
	Wektor2D wek1(3,4), wek2(-4,5);
	Macierz2x2 mac1(90);
	pro1.obroc(mac1);
	cout << pro1 << endl;
	cout << wek1 << endl; */
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


