#include "Prostokat.hh"


std::ostream& operator << (std::ostream &Strm, const Prostokat &Pr)
{
		
	Strm << Pr.arr[0][0] << " " << Pr.arr[0][1] << endl
			<< Pr.arr[1][0] << " " << Pr.arr[1][1] << endl;

	return Strm;
}
