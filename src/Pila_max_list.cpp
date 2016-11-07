#include "../include/Pila_max_list.h"
#include "../include/Lista_enlazada.h"

//----------------------------------------------------------------------
//                        PILA MAX
//----------------------------------------------------------------------

template <class T>
PilaMax<T>::PilaMax(){
  list();
}

template <class T>
PilaMax<T>::PilaMax(T e){
  list(e);
  maximo = e;
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
  maximo = list.at(0);
  T to_ret = list.getLast();
  T max;
  if(to_ret = maximo){
    for(int i=0; i < list.size(); ++i){
      max = list.at(i);
      if(max > maximo){
	maximo = max;
      }
    }
  }

  return to_ret;
}

template <class T>
PilaMax<T>& PilaMax<T>::operator=(PilaMax<T> p){
  if(this != p){
    this->list = p.list;
    this->maximo = p.maximo;
  }
  
  return this;
}

template <class T>
bool PilaMax<T>::operator==(PilaMax<T> &p){
  return this->list == p.list && this->maximo == p.maximo;
}

template <class T>
bool PilaMax<T>::operator!=(PilaMax<T> &p){
  return this != p;
}
