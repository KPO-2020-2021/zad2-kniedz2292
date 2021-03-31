#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "Statystyki.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Suma"){
   LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;

    CHECK(x+y == z);

}
TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 0.000007;
    x.im = 0.000007;

    y.re = 0.000003;
    y.im = 0.000003;

    z.re = 0;
    z.im = 0;

    CHECK(x+y == z);

}
TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00000001;
    y.im = 0.00000001;

    z.re = 1;
    z.im = 1;

    CHECK(x+y == z);
}
TEST_CASE("test LZespolona Odejmowanie"){
    LZespolona x, y, z;

    x.re = 0.999999;
    x.im = 0.999999;

    y.re = 0.000001;
    y.im = 0.000001;

    z.re = 1;
    z.im = 1;

    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Odejmowanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00000001;
    y.im = 0.00000001;

    z.re = 1;
    z.im = 1;

    CHECK(x-y == z);
}
TEST_CASE("test LZespolona Odejmowanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;

    CHECK(x-y == z);

}
TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00000001;
    y.im = 0.00000001;

    z.re = 0;
    z.im = 0;

    CHECK(x*y == z);
}
TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;

    CHECK(x*y == z);
}
TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 1;
    z.im = 1;

    CHECK(x*y == z);
}
TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;

    z.re = 0;
    z.im = 2;

    CHECK(x*y == z);
}
TEST_CASE("test LZespolona mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 1;

    z.re = -1;
    z.im = 1;

    CHECK(x*y == z);
}
TEST_CASE("test LZespolona modul"){
    LZespolona x;
    double s=2;
    x.re=1;
    x.im=1;

    CHECK(x.mod2()== s);
}
TEST_CASE("test LZespolona sprzezenie"){
    LZespolona x,y;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -1;

    CHECK(x.sprzezenie()== y);
}
TEST_CASE("test LZespolona Suma,rown"){
   LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
x+=y;
    CHECK( x== z);

}

TEST_CASE("test Lstatystyki"){
   Statystyki st={1,1,2,0,0};
st.licz();

    CHECK( st.procent_poprawnie== 50);

}