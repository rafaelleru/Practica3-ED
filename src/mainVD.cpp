#include <iostream>
#include "../include/VectorDinamico.hpp"

using namespace std;

int main(){
  Vector_Dinamico<int> vd;
  
  vd.poner(1);
  vd.poner(6);
  vd.poner(0);
  vd.poner(7);
  vd.poner(9);
  vd.poner(6);

  for(int i=0; i < vd.size(); i++)
    cout << vd.at(i);

  vd.quitar();

  for(int i=0; i < vd.size(); i++)
    cout << vd.at(i);

  vd.resize(2);
  
  for(int i=0; i < vd.size(); i++)
    cout << vd.at(i);

  bool vacia = true;
  vacia = vd.vacia();
  cout << vacia << endl;

  int tope;
  tope = vd.tope();
  cout << tope << endl;

}
