#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.666;
    y.im = 0.666;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez lzespolona") {
    LZespolona x, y,z;
    
    
    x.re = 2;
    x.im = 2;

    y.re =1;
    y.im =0;
   
     z.re = 2;
    z.im = 2;
    CHECK(x/y == z);
}

TEST_CASE("Test LZespolona dzielenie przez lzespolona") {
    LZespolona x, y,z;
    
    
    x.re = 2;
    x.im = 2;

    y.re =1;
    y.im =0;
   
     z.re = 2;
    z.im = 2;
    x/=y;
    CHECK( x== z);
}


TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("LZespolona - wyswietlanie zaokragl"){
    LZespolona x;

    x.re = 1.0/3.0;
    x.im = 1.0/3.0;

    std::ostringstream out;

    out << x;
    CHECK( "(0.33+0.33i)" == out.str());
}
TEST_CASE("LZespolona - wczytywanie stand"){
    LZespolona x;

    

    std::istringstream in("(10+10.10i)");
    in >> x;
    std::ostringstream out;

    out << x;


    CHECK( "(10.00+10.10i)" == out.str());
}
TEST_CASE("Test LZespolona dodawanie, znany"){
    WyrazenieZesp x{{1,1},Op_Dodaj,{1,1}};
    LZespolona t={2,2};

    CHECK(x.Oblicz()== t);

}
TEST_CASE("Test LZespolona odejmowanie, znany"){
    WyrazenieZesp x{{1,1},Op_Dodaj,{1,1}};
    LZespolona t={2,2};

    CHECK(x.Oblicz()== t);

}
TEST_CASE("Test LZespolona mnozenie, znany"){
    WyrazenieZesp x{{1,1},Op_Mnoz,{1,1}};
    LZespolona t={0,2};

    CHECK(x.Oblicz()== t);

}
TEST_CASE("Test LZespolona dzielenie, znany"){
    WyrazenieZesp x{{1,1},Op_Dziel,{1,1}};
    LZespolona t={01,0};

    CHECK(x.Oblicz()== t);

}