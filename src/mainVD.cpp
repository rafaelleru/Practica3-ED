#include <iostream>
#include "../include/VectorDinamico.h"

using namespace std;

int main(){
  Vector_Dinamico<int> vd;
  
  vd.poner(1);
  vd.poner(6);
  vd.poner(0);
  vd.poner(7);
  vd.poner(9);
  vd.poner(6);

  for(int i=0; i < vd.utilizados; i++)
    cout << vd.datos[i];

  vd.quitar();

  for(int i=0; i < vd.utilizados; i++)
    cout << vd.datos[i];

  vd.resize(2);
  for(int i=0; i < vd.utilizados; i++)
    cout << vd.datos[i];

}
