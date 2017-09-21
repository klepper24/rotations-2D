#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor2D.hh"


class Prostokat {

	Wektor2D pro[2][2];
	
  public:

   friend std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr);

};






#endif
