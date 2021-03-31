#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona odp;
  Statystyki st{0,0,0,0,0};
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " wyrazenie: "<<WyrZ_PytanieTestowe<<endl;
    int i=0;
while(i++<3)
{
  cin>>odp;
  if(cin.good())
  {
    break;
  }
  cin.clear();
  cin.ignore(9999,'\n');
}
st.wszystkie++;
if(odp==WyrZ_PytanieTestowe.Oblicz())
{
  cout<<"poprawne"<<endl;
st.poprawne++;
}
else
{
  cout<<"bledne"<<WyrZ_PytanieTestowe.Oblicz()<<endl;
st.bledne++;
}
  }
  st.licz();
  st.Wyswietl();

LZespolona a{4,3};
cout<<a.arg()<<endl; //36.87

LZespolona a{1,1};
cout<<a.arg()<<endl; //45

LZespolona a{2,2}
cout<<a.arg()<<endl; //45

LZespolona a{3,7};
cout<<a.arg()<<endl; //66.8
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
