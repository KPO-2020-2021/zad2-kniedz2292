#ifndef STATYTSYKA_HH
#define STATYTSYKA_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

struct Statystyki
{
    int poprawne;
    int bledne;
    int wszystkie;
    double procent_poprawnie;
    double procent_blednie;
    void licz()
    {
        procent_poprawnie=poprawne*100.0/wszystkie;
        procent_blednie=bledne*100.0/wszystkie;
    }
   void Wyswietl()
    {
        cout<<"ilosc poprawnychy odpowiedzi "<<poprawne<<endl;
        cout<<"ilosc blednych odpowiedzi "<<bledne<<endl;
        cout<<"ilosc pprocentowa poprawnych odpowiedzi "<< procent_poprawnie <<"%"<<endl;
    }
};



#endif
