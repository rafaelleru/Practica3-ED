#ifndef __LISTA_ENLAZADA__
#define __LISTA_ENLAZADA__

using namespace std;

template <class T>

class Lista_enlazada{
    /**
     * @brief TDA lista enlazada
     */
 private:
  struct Elemento{
    T valor;
    Elemento* sig;
  };
  int n;
  Elemento* first;
  Elemento* last;
 public:
  /**
   * @brief crea una lista enlazada vacia
   */
  Lista_enlazada();

  /**
   * @brief Crrea una lista enlazada cuyo primer elemento tiene valor e.
   * @param e el valor del primer elemento de la lista.
   */
  Lista_enlazada(T e);

  /**
   * @brief Operador de copia. Crea una nueva lista enlazada a partir de
   * e. Al ser e un struct de tipo elemento la lista contendra todos los 
   * elementos apuntados por e.
   * @param e el primer elemento que contiene la lista enlazada a copiar.
   */
  Lista_enlazada(Elemento e);

  /**
   * @brief libera la memoria ocupada por una lista enlazada.
   */
  ~Lista_enlazada();

  /**
   * @brief operador de copia. Asigna el contenido de la lista e en this.
   * @param l la lista que se le pasa.
   */
  Lista_enlazada(Lista_enlazada<T>& l);

  /**
   * @brief añade un nuevo elemento e a la lista enlazada, lo hace al final de esta.
   * @param e el elemento que se desea añadir.
   */
  void add(T e);

  /**
   * @brief accede al elemento numero "index" de la lista enlazada si este existe.
   * @param index el número del elemento que se desea acceder.
   * @return el valor del elemento "index" de la lista.
   */
  T at(int index);

  /**
   * @brief elimina el elemento i-esimo de la lista enlazada.
   * @param index el numero del elemento que se desea eliminar.
   */
  void remove(int index);

  /**
   * @brief devuelve el tamaño de la lista enlazada.
   */
  int size();

  /**
   * @brief devuelve el ultimo elemento de la lista enlazada.
   */
  T getLast();
};

//#include "../src/Lista_enlazada.cpp"
#endif

//----------------------------------------------------------------------
//                     Lista Enlazada
//----------------------------------------------------------------------
#include <iostream>

template <class T>
Lista_enlazada<T>::Lista_enlazada(){
  n = 0;
  first = new Elemento;
  last = first;
}

template <class T>
Lista_enlazada<T>::Lista_enlazada(T e){
  first = new Elemento;
  first->valor = e;
  n++;
}

template <class T>
Lista_enlazada<T>::~Lista_enlazada(){
  Elemento *aux = first;
  while(aux->sig != 0){
    Elemento *to_del = aux;
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
Lista_enlazada<T>::Lista_enlazada(Lista_enlazada<T>& l){
  this->first = l.first;
  this->last = l.last;
  this->n = l.n;
}

template <class T>
void Lista_enlazada<T>::add(T e){
  Elemento *aux = last;
  aux->sig = new Elemento;
  aux = aux->sig;
  aux->valor = e;
  last = aux;
  n++;
}

template <class T>
void Lista_enlazada<T>::remove(int index){
  Elemento* aux;
  Elemento* aux2;
  int i = 0;
  aux = first;
  while(i < index-1 && aux->sig !=0){
    aux = aux->sig;
    i++;
  }

  aux2 = aux->sig->sig;
  delete aux->sig;
  aux->sig = aux2;

  n--;
}


template <class T>
T Lista_enlazada<T>::at(int index){
  Elemento *e = first;
  for(int i=0; i <= index; ++i){
    e = e->sig;
  }
  return e->valor;
}

template <class T>
int Lista_enlazada<T>::size(){
  return n;
}

template <class T>
T Lista_enlazada<T>::getLast(){
  return last->valor;
}



