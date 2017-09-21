#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void zapisWspolrzednychDoStrumienia(std::ostream& StrmWy, Prostokat &Pr, double Przesuniecie = 0.0)
{


  StrmWy << setw(16) << fixed << setprecision(10) << Pr.p1[0] + Przesuniecie
         << setw(16) << fixed << setprecision(10) << Pr.p1[1] + Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << Pr.p2[0] + Przesuniecie 
         << setw(16) << fixed << setprecision(10) << Pr.p2[1] + Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << Pr.p3[0] + Przesuniecie 
         << setw(16) << fixed << setprecision(10) << Pr.p3[1] + Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << Pr.p4[0] + Przesuniecie 
         << setw(16) << fixed << setprecision(10) << Pr.p4[1] + Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << Pr.p1[0] + Przesuniecie
         << setw(16) << fixed << setprecision(10) << Pr.p1[1] + Przesuniecie << endl; 
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
bool zapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostokat &Pr, double Przesuniecie = 0.0)
{
  ofstream StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  zapisWspolrzednychDoStrumienia(StrmPlikowy, Pr, Przesuniecie);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


void obracanieProstokata(Prostokat& pro)
{
	cout << "Podaj wartosc kata obrotu w stopniach: " << endl;
	float kat;	
	cin >> kat;
	Macierz2x2 mac1(kat);

	cout << "Ile razy operacja obrotu ma byc powtorzona?" << endl;
	unsigned int ile = 0;
	cin >> ile;
	for(unsigned int i = 0; i < ile; ++i)
		pro.obroc(mac1);
		
}


void przesuwanieProstokata(Prostokat& pro)
{
	cout << "Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb, tzn. wspolrzednej x oraz wspolrzednej y: " << endl;

	Wektor2D wek;
	cin >> wek;
	
	pro.przesun(wek);
}


void wyswietlanieWspolrzednych(Prostokat& pro)
{
	cout << pro;
}


void sprawdzenieBokow(Prostokat& pro)
{
	pro.sprawdzDlugoscPrzeciwleglychBokow();
}

void wyswietlMenu()
{
		cout << endl
			 << "o - obrot prostokata o zadany kat" << endl
			 << "p - przesuniecie prostokota o zadany wektor" << endl
			 << "w - wyswietlenie wspolrzednych wierzcholkow" << endl
			 << "s - sprawdzenie dlugosci przeciwleglych bokow" << endl
			 << "m - wyswietl menu" << endl
			 << "k - koniec dzialania programu" << endl;
}


int main()
{
	//getopt do robienia menu - poczytać!!!
	Prostokat pro1{{30,40},{100,40},{100,100},{30, 100}};
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

		cout << "Twoj wybor?\t";
		cin >> wybor;

		switch(wybor)
		{
			case 'o': 	obracanieProstokata(pro1);
						zapisWspolrzednychDoStrumienia(cout,pro1);
  						if (!zapisWspolrzednychDoPliku("prostokat.dat",pro1)) return 1;
  						Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
						break;

			case 'p':   przesuwanieProstokata(pro1);
						zapisWspolrzednychDoStrumienia(cout,pro1);
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

			default:  cout << endl << "Bledny znak! Sprobuj jeszcze raz!" << endl;
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


