#ifndef PILA_MAX_LIST
#define PILA_MAX_LIS

using namespace std;

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
  PilaMax(T e);
  ~PilaMax();
  void push(T e);
  T pop();

  //operadores
  PilaMax<T>& operator=(PilaMax<T>& p);
  bool operator==(PilaMax<T>& p);
  bool operator!=(PilaMax<T>& p);
};
#endif
