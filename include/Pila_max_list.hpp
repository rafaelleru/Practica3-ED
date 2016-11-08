#ifndef PILA_MAX_LIST
#define PILA_MAX_LIS
#include "./Lista_enlazada.hpp"

using namespace std;

template <class T>

/**
 * @brief Representacion del T.D.A PilaMax usando para su 
 * almacenamiento una lista enlazada.
 */

class PilaMax{
 private:
  T maximo;
 
  Lista_enlazada<T> list;
 public:

  /**
   * @brief constructor por defecto. Crea una pila max vacia.
   */
  PilaMax();

  /**
   * @brief crea una pila max con un elemento dentro.
   * @param e el elemento que se insertara como primero de la lista.
   */
  PilaMax(T e);

  /**
   * @brief crea una nueva pila a partir de otra pila.
   * @param p referencia a la pila que sera copiada.
   */
  PilaMax(PilaMax<T>& p);

  /**
   * @brief Destructor. Libera la memoria ocupada por la pila.
   */
  ~PilaMax();

  /**
   * @brief añade un nuevo elemento al tope de la pila y actualiza el maximo.
   * @param e el elemento que se coloca como tope.
   */
  void push(T e);

  /**
   * @brief devuelve el elemento tope de la pila y actualiza el maximo.
   * @return el valor del elemento tope de la pila.
   */
  T pop();

  /**
   * @brief devuelve el numero de elementos almacenados en la pila.
   * @return el tamaño de la  pila.
   */
  int size();

  /**
   * @brief devuelve el valor del maximo elemento de la pila, pero no lo elimina 
   * ya que podria ser el tope y esto entraria en conflicto con la politica de gestión de la pila.
   * @return el valor del elemento  maximo de la pila.
   */
  T getMax();

  //operadores

  /**
   * @brief operador de asignacion. Pone en this el contenido de p.
   * @param p la pila_max que se va a copiar en this.
   * @return this, referencia a la pila en la que se han asignado los contenidos
   * de p.
   */
  PilaMax<T>& operator=(PilaMax<T>& p);
  bool operator==(PilaMax<T>& p);
  bool operator!=(PilaMax<T>& p);
 };

#endif


template <class T>
PilaMax<T>::PilaMax(T e){
  this->list(e);
  this->maximo = e;
}


template <class T>
PilaMax<T>::PilaMax(PilaMax<T>& p){
  this->list = p.list;
  this->maximo = p.maximo;
}

template <class T>
PilaMax<T>::~PilaMax(){
  //this->~list();
}

template <class T>
void PilaMax<T>::push(T e){
  this->list.add(e);
  if(e>this->maximo){
    this->maximo = e;
  }
}

template <class T>
T PilaMax<T>::pop(){
  if (this->list.getLast() == maximo){
    this->maximo = 0;
    for(int i = 0; i < this->list.size(); i++){
      if(this->list.at(i) > maximo){
	maximo = this->list.at(i);
      }
    }
  }

  T to_ret = this->list.getLast();
  this->list.remove(this->size());
  return to_ret;
}


template <class T>
int PilaMax<T>::size(){
  return this->list.size();
}

template <class T>
T PilaMax<T>::getMax(){
  return this->maximo;
}

template <class T>
PilaMax<T>& PilaMax<T>::operator=(PilaMax<T>& p){
  if( this!= p){
    this->list = p.list;
    this->maximo = p.maximo;
  }

  return this;
}

template <class T>
bool PilaMax<T>::operator==(PilaMax<T>& p){
  if(this->maximo == p.maximo){
    bool equal = true;
    for(int i = 0; i < this->list.size() && true; ++i){
      if(this->list.at(i) != p.list.at(i)){
	equal = false;
      }
    }

    return equal;
  }else return false;
}

template <class T>
bool PilaMax<T>::operator!=(PilaMax<T>& p){
  return !(this == p);
}
