#include <iostream>
#include "../include/VectorDinamico.hpp"

using namespace std;

int main(){
  Vector_Dinamico<int> vd;

  vd.poner(1);
  vd.poner(2);
  vd.poner(3);
  vd.poner(4);

  cout << "tam vector = " << vd.size() << endl;
  
  for(int i=0; i < vd.size(); i++){
    cout << vd.at(i) << endl;
  }

  cout << "elimino elemento" << endl;
  vd.quitar();

  for(int i=0; i < vd.size(); i++){
    cout << vd.at(i) << endl;
  }

  cout << "redimensiono el vector a 2" << endl;
  vd.resize(2);
  
  cout << "tras el resize" << endl;
  for(int i=0; i < vd.size(); i++)
    cout << vd.at(i) << endl;

 
  bool vacia = vd.vacia();
  if(vacia){
    cout << "el vector esta vacio" << endl;
  }else{
    cout << "el vector tiene cosas" << endl;
  }

  int tope;
  tope = vd.tope();
  cout << tope << endl;

}
