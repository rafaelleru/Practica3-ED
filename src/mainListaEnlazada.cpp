#include <iostream>
#include "../include/Lista_enlazada.h"

using namespace std;

int main(){
  Lista_enlazada<int> l;

  l.add(8);
  l.add(1);
  l.add(2);
  l.add(3);
  l.add(4);

  for(int i = 0; i < l.size(); i++){
    cout << l.at(i) << endl;
  }

  l.remove(3);

  for(int i = 0; i < l.size(); i++){
    cout << l.at(i) << endl;
  }
}
