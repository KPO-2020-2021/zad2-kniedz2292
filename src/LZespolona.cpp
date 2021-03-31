#include "LZespolona.hh"
#define _USE_MATH_DEFINES
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
 LZespolona LZespolona::operator +=(LZespolona Skl1)
 {
   *this=*this+Skl1;
   return *this;
 }
 LZespolona LZespolona::operator /= (LZespolona Skl1)
 {
   *this=*this/Skl1;
   return *this;
 }
 double LZespolona::arg()
 {
   double wynik;
   if(re>0)
   {
     wynik=atan2(im,re) * 180 / M_PI;
   }
   else if(re<0)
   {
     wynik=atan2(im,re) + M_PI * 180 / M_PI;
   }
   else
   {
       throw "argument a jest zerem wyjatek";
   }
   return wynik;
   
 }

const bool  LZespolona::operator == (   LZespolona  Skl2)const{
 
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  
  if( abs( re - Skl2.re) <= MIN_DIFF && abs( im - Skl2.im) <= MIN_DIFF)
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
LZespolona  LZespolona::operator + (   LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re =  re + Skl2.re;
  Wynik.im =  im + Skl2.im;
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
LZespolona  LZespolona::operator / (   double  Skl2){
  LZespolona  Wynik;
if(Skl2==0)
     {
       throw "dzielisz przez zero a nie wolno :P";
     }
  Wynik.re =  re / Skl2;
  Wynik.im =  im / Skl2;
  return Wynik;
}
LZespolona  LZespolona::operator - (   LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re =  re - Skl2.re;
  Wynik.im =  im - Skl2.im;
  return Wynik;
}
LZespolona  LZespolona::operator * (  LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re =  re*Skl2.re - im*Skl2.im;
  Wynik.im =  re*Skl2.im+ im*Skl2.re;
  return Wynik;
}

LZespolona LZespolona::sprzezenie( )
{
  LZespolona Wynik;
  
  Wynik.re =  re;
  Wynik.im =  im*-1;
  return Wynik;
}
double LZespolona::mod2( )
{
  double Wynik;
  Wynik = ( im* im+ re* re);
  return Wynik;
}

LZespolona LZespolona::operator / (  LZespolona Skl2)
{
    LZespolona Wynik;
  
  Wynik=*this*Skl2.sprzezenie()/Skl2.mod2();

  return Wynik;
}

void LZespolona::Wyswietl( )
{
  cout<<"("<< re<<showpos<< im<<noshowpos<<"i)";
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