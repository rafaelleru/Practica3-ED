#ifndef PILA_MAX_LIST
#define PILA_MAX_LIS

template <class T>

/**
 * @brief Representacion del T.D.A PilaMax usando para su almacenamiento una lista enlazada.
 */

class PilaMax{
    /**
     * @brief Un elemento de la lista enlazada.
     * representa un valor y almacena la posicion del siguiente elemento en la lista.
     */

  struct Elemento{
    T valor;
    Elemento* sig;
  };

  class Lista_enlazada{
    /**
     * @brief TDA lista enlazada
     */
  private:
    int n;
    Elemento* first;
    Elemento* last;
  public:
    Lista_enlazada();
    Lista_enlazada(T e);
    ~Lista_enlazada();
    void add(T e);
    T at(int index);
    //void delete(int index);
    int size();
  };
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
