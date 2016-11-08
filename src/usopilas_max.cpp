#include <iostream>
#include "../include/Pila_max.h"

using namespace std;

int main(){

  PilaMax<int> p;
  int i;

  for ( i=10; i>=0 ; i--) 
    p.push(i);
  
  while (!p.size() == 0){
    int x = p.pop();
    cout << x<<endl;
  }     
  
  return 0;
}
