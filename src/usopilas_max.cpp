#include <iostream>
#include "../include/Pila_max.h"
//#include "./Pila_max_list.hpp"
//#include "./Lista_enlazada.cpp"

using namespace std;

int main(){

  PilaMax<int> p;
  int x;
  int i;

  for ( i=10; i>=0 ; i--) 
    p.push(i);
  
  while (p.size() != 0){
    x = p.get();
    p.pop();
    cout << x <<endl;
    cout << "maximo: " << p.getMaximo();
  }     

  return 0;
}
