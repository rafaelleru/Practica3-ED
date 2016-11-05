#ifndef PILA_MAX_LIST
#define PILA_MAX_LIS

template <class T>

/**
 * @brief Representacion del T.D.A PilaMax usando para su almacenamiento una lista enlazada.
 */

class PilaMax{
 private:
  T maximo;
 
  Lista_enlazada list;
 public:
  PilaMax();
  ~PilaMax();
  void push(T e);
  T pop();
};
#endif
