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
  PilaMax(Lista_enlazada<T> l);
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

