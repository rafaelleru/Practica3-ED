#ifndef __PILA_MAX_VD__
#define __PILA_MAX_VD__

#include "./VectorDinamico.hpp"
#include "./Lista_enlazada.hpp"

using namespace std;

template <class T>

/**
 * @brief Clase PilaMax que utiliza la clase VectorDinamico
 */
class PilaMax{
private:
  Vector_Dinamico<T> vector;
  T maximo;
public:
  /**
   * @brief Crea un vector vacio
   */
  PilaMax();

  /**
   * @brief Crea un vector con un solo elemento e
   * @param e Variable de tipo T que sera el maximo del vector
   */
  PilaMax(T e);

  /**
   * @brief Construye un objeto con igual vector y maximo que p
   * @param p Objeto de la clase PilaMax que se desea copiar
   */
  PilaMax(PilaMax<T>& p);

  /**
   * @brief Libera la memoria reservada para el vector
   */
  ~PilaMax();

  /**
   * @brief Añade en la ultima posicion e
   * @param e Variable de tipo T que queremos añadir al vector
   */
  void push(T e);

  /**
   * @brief Elimina el ultimo elemento del vector
   */
  void pop();

  /**
   * @brief devuelve el tope de la cola
   * @return el tope de la pila
   */

  T get();
  /**
   * @brief Devuelve el mayor valor del vector
   */
  T getMaximo();

  /**
   * @brief Devuelve el tamaño del vector
   */
  int size();

  //Operadores

  /**
   * @brief Operador de asignacion
   * @param p Objeto de Pilamax que asignamos a otro objeto
   */
  PilaMax& operator=(PilaMax<T>& p);

  /**
   * @brief operador que comprueba si son iguales dos objetos
   * @param p Objeto de PilaMax que queremos comparar con otro objeto 
   */
  bool operator==(PilaMax<T>& p);

  /**
   * @brief operador que comprueba si son distintos dos objetos
   * @param p Objeto de PilaMax que queremos comparar con otro objeto 
   */
  bool operator!=(PilaMax<T>& p);
};

#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                                   IMPLEMENTACION
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

template <class T>
PilaMax<T>::PilaMax(){
  T maximo = 0;
}

template <class T>
PilaMax<T>::PilaMax(T e){
  this->vector.poner(e);
  this->maximo = e;
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
void PilaMax<T>::pop(){
  this->vector.quitar();
}

template <class T>
T PilaMax<T>::get(){
  return this->vector.tope();
}

template <class T>
T PilaMax<T>::getMaximo(){
  return this->maximo;
}

template <class T>
int PilaMax<T>::size(){
  return this->vector.size();
}

template <class T>
PilaMax<T>& PilaMax<T>::operator=(PilaMax<T>& p){
  this->vector = p.vector;
  this->maximo = p.maximo;
}

template <class T>
bool PilaMax<T>::operator==(PilaMax<T>& p){
  bool igual = false;
  if(this->vector.size() == p.vector.size()){
    igual = true;
    for(int i=0; i<this->vector.size() && igual; ++i){
      if(this->vector.datos[i] != p.datos[i])
	igual = false;
    }
  }
  return igual;
}

template <class T>
bool PilaMax<T>::operator!=(PilaMax<T>& p){
  return !(*this == p);
}

