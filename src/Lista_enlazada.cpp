//----------------------------------------------------------------------
//                     Lista Enlazada
//----------------------------------------------------------------------

#include "../include/Lista_enlazada.h"

using namespace std;

template <class T>
Lista_enlazada<T>::Lista_enlazada(){
  first = new Elemento;
}

template <class T>
Lista_enlazada<T>::Lista_enlazada(T e){
  first = new Elemento;
  first->valor = e;
  n++;
}

template <class T>
Lista_enlazada<T>::~Lista_enlazada(){
  Elemento aux = first;
  while(aux->sig != 0){
    Elemento to_del = aux;
    aux = aux->sig;
    delete to_del;
  }
}

template<class T>
Lista_enlazada<T>::Lista_enlazada(Elemento e){
  Elemento* aux = e.sig;
  Elemento* aux2;
  first = e;
  last = first;
  aux2 = first->sig;

  while(aux->sig != 0){
    aux2->valor = aux->valor;
    last = aux2;
    n++;
    aux2->sig = new Elemento;
    aux2 = aux->sig;
    aux = aux->sig;
  }
}
    
    

template <class T>
void Lista_enlazada<T>::add(T e){
  last->sig = new Elemento;
  Elemento aux = last->sig;
  aux->sig = new Elemento*;
  aux->valor = e;
  last->siguiente = aux;
  n++;
}

template <class T>
void Lista_enlazada<T>::remove(int index){
  Elemento* aux;
  Elemento* aux2;
  Elemento* aux3;
  int i = 0;
  aux = first;
  while(i < index-1 && aux->sig !=0){
    aux = aux->sig;
  }

  aux2 = aux->sig->sig;
  delete aux->sig;
  aux->sig = aux2;

  n--;
}
  
template <class T>
T Lista_enlazada<T>::at(int index){
  int cont = 0;
  Elemento e = first;
  for(cont; cont < index; ++cont){
    e = e->sig;
  }

  return e->valor;
}

template <class T>
int Lista_enlazada<T>::size(){
  return n;
}
