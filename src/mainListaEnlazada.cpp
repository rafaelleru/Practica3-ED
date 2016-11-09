#include <iostream>
#include "../include/Lista_enlazada.hpp"

using namespace std;

int main(){
  Lista_enlazada<int> l;
  cout << "He creado un obj" << endl;
  l.add(8);
  cout << "He añadido el primero"  << l.at(0) <<endl;
  l.add(2);
  cout <<"Añadido segundo num "<<l.at(1)<<endl;
  
  l.add(2);
  l.add(3);
  l.add(4);
  cout << "añadido todos" << endl;
  cout << "el tamaño de la lista es: " << l.size()<<endl;
  
  for(int i = 0; i < l.size(); i++){
    cout << l.at(i) << endl;
  }
  
  l.remove(3);

  cout << "tras eliminar el 3er elemento" << endl;
  for(int i = 0; i < l.size(); i++){
    cout <<"iteraccion: "<< i <<" valor: "<< l.at(i) << endl;
  }

  int ultimo = l.getLast();
  cout << "\nEl ultimo elemento es: " << ultimo << endl;

  Lista_enlazada<int>copia(l);
  for(int i = 0; i < copia.size(); i++){
    cout <<"iteraccion: "<< i <<" valor: "<< copia.at(i) << endl;
  }
}
