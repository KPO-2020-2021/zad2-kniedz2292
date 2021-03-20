#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
ostream & operator <<(ostream & wyj,WyrazenieZesp WyrZ))
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
}
LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZesplona wynik;
    switch(WyrZ.Op)
    {
        case Op_Dodaj:
        wynik= WyrZ.Arg1+WyrZ.Arg2;
        break;
                case Op_Odejmij:
        wynik= WyrZ.Arg1-WyrZ.Arg2;
        break;
                case Op_Mnoz:
        wynik= WyrZ.Arg1*WyrZ.Arg2;
        break;
                case Op_Dziel:
       wynik= WyrZ.Arg1/WyrZ.Arg2;
        break;
    }
    return wynik;
}