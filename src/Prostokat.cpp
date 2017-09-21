#include "Prostokat.hh"


std::ostream& operator << (std::ostream &Strm, const Prostokat &Pr)
{
		
	Strm << Pr.pro[0][0] << " " << Pr.pro[0][1] << std::endl
			<< Pr.pro[1][0] << " " << Pr.pro[1][1] << std::endl;

	return Strm;
}
