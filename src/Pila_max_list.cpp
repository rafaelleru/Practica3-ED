#include "../include/Pila_max_list.h"

//----------------------------------------------------------------------
//                        PILA MAX
//----------------------------------------------------------------------

template <class T>
PilaMax<T>::PilaMax(){
  list = new Lista_enlazada();
}

template <class T>
PilaMax<T>::~PilaMax(){}

template <class T>
void PilaMax<T>::push(T e){
  this->list.push(e);
  if(e > maximo)
    maximo = e;
}

template <class T>
T PilaMax<T>::pop(){
  return list.getLast();
}


