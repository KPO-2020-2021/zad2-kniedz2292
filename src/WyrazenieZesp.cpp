#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
ostream & operator <<(ostream & wyj,WyrazenieZesp WyrZ)
{
    wyj<<WyrZ.Arg1;
    switch(WyrZ.Op)
    {
        case Op_Dodaj:
        wyj<<"+";
        break;
                case Op_Odejmij:
        wyj<<"-";
        break;
                case Op_Mnoz:
        wyj<<"*";
        break;
                case Op_Dziel:
        wyj<<"/";
        break;
    }
 wyj<<WyrZ.Arg1;
 return wyj;
}
LZespolona WyrazenieZesp::Oblicz()
{
    LZespolona wynik;
    switch( Op)
    {
        case Op_Dodaj:
        wynik=  Arg1+ Arg2;
        break;
                case Op_Odejmij:
        wynik=  Arg1- Arg2;
        break;
                case Op_Mnoz:
        wynik=  Arg1* Arg2;
        break;
                case Op_Dziel:
       wynik=  Arg1/ Arg2;
        break;
    }
    return wynik;
}