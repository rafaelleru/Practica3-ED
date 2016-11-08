#ifndef __VECTOR_DINAMICO__
#define __VECTOR_DINAMICO__

using namespace std;

template <class T>

class Vector_Dinamico{
 private:
  T *datos;
  int reservados;
  int utilizados;
 public:
  Vector_Dinamico();
  Vector_Dinamico(const Vector_Dinamica& vd);
  ~Vector_Dinamico();
  Vector_Dinamico& operator= (const Vector_Dinamico& vd);

  void resize(int n);
  bool vacia() const{ return utilizados == 0;}
  void poner(T c);
  void quitar();
  T tope() const;
  
};

#endif
