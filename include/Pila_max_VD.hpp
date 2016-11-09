#ifndef __PILA_MAX_VD__
#defind __PILA_MAX_VD__

#include "./VectorDinamico.hpp"
#include "./Lista_enlazada.hpp"

using namespace std;

template <class T>
class PilaMax{
private:
  Vector_Dinamico<T> vector;
  T maximo;
public:
  PilaMax();
  PilaMax(T e);
  PilaMax(Lista_enlazada<T>& l);
  PilaMax(PilaMax<T>& p);
  ~PilaMax();
  void push(T e);
  T pop();
  T getMaximo();
  int size();

  //Operadores
  PilaMax& operator=(PilaMax<T>& p);
  bool operator==(PilaMax<T>& p);
  bool operator!=(PilaMax<T>& p);
};

#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                                   IMPLEMENTACION
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template<class T>
PilaMax<T>::PilaMax(){
  this->vector();
}

template <class T>
PilaMax<T>::PilaMax(T e){
  this->vector();
  this->vector.poner(e);
  this->maximo = e;
}

template <class T>
PilaMax<T>::PilaMax(Lista_enlazada<T> &l){
  this->vector();
  for(int i=0; i < l.size(); ++i){
    this->vector.poner(l.at(i));
    if(l.at(i) > maximo)
      maximo = l.at(i);
  }
}

template <class T>
PilaMax<T>::PilaMax(PilaMax<T>& p){
  this->vector = p.vector;
  this->maximo = p.maximo;
}

template <class T>
PilaMax<T>::~PilaMax(){}

template <class T>
void PilaMax<T>::push(T e){
  this->vector.poner(e);
  if(e > this->maximo){
    maximo = e;
  }
}

template <class T>
T PilaMax<T>::pop(){
  T to_ret = vector.at(vector.size()); //Si hay core mirar aqui.
  vector.remove(vector.size());
  if (to_ret == maximo){
    maximo = 0;
    for(int i=0; i < vector.size(); ++i){
      if(vector.at(i) > maximo)
	maximo = vector.at(i);
    }
  }
  return to_ret;
}

template <class T>
T PilaMax<T>::getMaximo(){
  return this->maximo;
}

template <class T>
int PilaMax<T>::size(){
  return this->vector.size();
}

