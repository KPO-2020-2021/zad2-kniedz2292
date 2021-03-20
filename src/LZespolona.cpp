#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
 
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  
  if( abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
  
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;
if(Skl2==0)
     {
       cerr<<"blad0"<<endl;
       exit(-1);
     }
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
LZespolona  operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re*Skl2.re -Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im+Skl1.im*Skl2.re;
  return Wynik;
}

LZespolona sprzezenie(LZespolona Skl1)
{
  LZespolona Wynik;
  
  Wynik.re = Skl1.re;
  Wynik.im = Skl1.im*-1;
  return Wynik;
}
double mod2(LZespolona Skl1)
{
  double Wynik;
  Wynik = (Skl1.im*Skl1.im+Skl1.re*Skl1.re);
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
    LZespolona Wynik;
  
  Wynik=Skl1*sprzezenie(Skl2)/mod2(Skl2);

  return Wynik;
}

void Wyswietl(LZespolona Skl1)
{
  cout<<"("<<Skl1.re<<showpos<<Skl1.im<<noshowpos<<"i)";
}

ostream & operator <<(ostream & wyj, LZespolona Skl)
{
  wyj<<"("<<Skl.re<<showpos<<Skl.im<<noshowpos<<"i)";
  return wyj;
}
istream & operator >>(istream & wej, LZespolona &Skl)
{
  char zm;
wej>>zm;
if(zm!='(')
{
wej.setstate(ios::failbit);
}
wej>>Skl.re;
wej>>Skl.im;
wej>>zm;
if(zm!='i')
{
wej.setstate(ios::failbit);
}
wej>>zm;
if(zm!=')')
{
wej.setstate(ios::failbit);
}
return wej;
}