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
  Lista_enlazada();
  Lista_enlazada(T e);
  Lista_enlazada(Elemento e);
  ~Lista_enlazada();
  void add(T e);
  T at(int index);
  void remove(int index);
  int size();
  T getLast();
};

#endif
