#ifndef PILA_MAX_LIST
#define PILA_MAX_LIS
#include "./Lista_enlazada.h"

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
