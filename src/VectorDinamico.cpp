//----------------------------------------------------------------------
//                         Vector Dinámico
//----------------------------------------------------------------------

#include "../include/VectorDinamico.h"

using namespace std;

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(){
  datos = new T[reservados];
  
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico& vd){
  this->reservados=vd.reservados;
  datos = new T[reservados];
  this->datos = vd.datos;
}

template <class T>
Vector_Dinamico<T>::~Vector_Dinamico(){
  delete[] datos;
}

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator=(const Vector_Dinamico& vd){
  if(this != &vd){
    ~Vector_Dinamico();
    if(vd.datos)
      Vector_Dinamico(vd);
    else
      datos = 0;
  }
  return *this;
}

template <class T>
void Vector_Dinamico<T>::resize(int n){
  T *aux = new T[n];
  aux = this->datos;
  this->reservados = n;
  this->datos = aux;
  
}

template <class T>
void Vector_Dinamico<T>:: poner(T c){
  if(utilizados == reservados){
    resize(2*reservados);
    datos[utilizados] = c;
    utilizados++;
  }
}

template <class T>
void Vector_Dinamico<T>::quitar(){
  if(utilizados > 0){
    utilizados--;
    if(utilizados < reservados/4)
      resize(reservados/2);
  }
}

template <class T>
T Vector_Dinamico<T>::tope() const{
  if(utilizados > 0){
    return datos[utilizados-1];
  }
}
