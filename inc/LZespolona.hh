#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona operator +=(LZespolona Skl1);
  LZespolona operator /=(LZespolona Skl1);
 double arg();
  const bool  operator == ( LZespolona  Skl2) const;

LZespolona  operator + ( LZespolona  Skl2);

LZespolona  operator - ( LZespolona  Skl2);
LZespolona  operator * ( LZespolona Skl2);
LZespolona operator / ( LZespolona Skl2);
LZespolona operator / ( double Skl2);
LZespolona sprzezenie();
double mod2();
void Wyswietl();

};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


ostream & operator <<(ostream & wyj, LZespolona Skl);
istream & operator >>(istream & wej, LZespolona &Skl);
#endif
