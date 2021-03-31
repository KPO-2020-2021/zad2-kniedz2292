Przy dwóch Pańskich testach wyskakuje mi blad z zaaokragleniem. Nie chciałem nic w nich zmieniać, ponieważ nie wiem czy możemy.
///////////////////////////////////////////
TEST CASE:  LZespolona - wyswietlanie zaokragl

./tests/test2.cpp:82: ERROR: CHECK( "(0.33+0.33i)" == out.str() ) is NOT correct!
  values: CHECK( (0.33+0.33i) == (0.333333+0.333333i) )
  ///////////////////////////////////////////////////////////
  ./tests/test2.cpp:84:
TEST CASE:  LZespolona - wczytywanie stand

./tests/test2.cpp:96: ERROR: CHECK( "(10.00+10.10i)" == out.str() ) is NOT correct!
  values: CHECK( (10.00+10.10i) == (10+10.1i) )
  ///////////////////////////////////////////////////
  Na początku miałem też problemy z wykonaniem dzielenia przez 0 LZespolonej, ponieważ wyswietlal mi sie bladmake przez funkcje w test2.cpp, która wyszukiwała błedu i go wypisywała. Zmieniłem to i użyłem throwa i juz wszystko pięknie działało.