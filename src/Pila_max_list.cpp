#include "../include/Pila_max_list.h"

//----------------------------------------------------------------------
//                     Lista Enlazada
//----------------------------------------------------------------------

template <class T>
PilaMax<T>::Lista_enlazada::Lista_enlazada(){
  first = new Elemento;
  last = first;
}

template <class T>
PilaMax<T>::Lista_enlazada::Lista_enlazada(T e){
  first = new Elemento;
  first->valor = e;
  last = first;
  n++;
}

template <class T>
PilaMax<T>::Lista_enlazada::~Lista_enlazada(){
  Elemento aux = first;
  while(aux->sig != 0){
    Elemento to_del = aux;
    aux = aux->sig;
    delete to_del;
  }
}

template <class T>
void PilaMax<T>::Lista_enlazada::add(T e){
  last->sig = new Elemento;
  Elemento aux = last->sig;
  aux->sig = new Elemento*;
  aux->valor = e;
  last->siguiente = aux;
  n++;
}
  
template <class T>
T PilaMax<T>::Lista_enlazada::at(int index){
  int cont = 0;
  Elemento e = first;
  for(cont; cont < index; ++cont){
    e = e->sig;
  }

  return e->valor;
}

template <class T>
int PilaMax<T>::Lista_enlazada::size(){
  return n;
}

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

  
