#include "Macierz2x2.hh"


Macierz2x2::Macierz2x2(double arg)
{
	arr[0][0] = cos(arg);
	arr[0][1] = -sin(arg);
	arr[1][0] = sin(arg);
	arr[1][1] = cos(arg);
}



std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac)
{
		Strm << Mac.arr[0][0] << " " << Mac.arr[0][1] << endl
				<< Mac.arr[1][0] << " " << Mac.arr[1][1] << endl;

	return Strm;
}

