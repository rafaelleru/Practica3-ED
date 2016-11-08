#ifndef __VECTOR_DINAMICO__
#define __VECTOR_DINAMICO__

using namespace std;

template <class T>
/**
 * @brief TDA Vector dinámico
 */
class Vector_Dinamico{
 private:
  T *datos;
  int reservados;
  int utilizados;
 public:

  /**
   * @brief Construye un vector dinamico vacio 
   */
  Vector_Dinamico();

  /**
   * @brief Construye un vector igual a vd
   * @param vd Vector dinamico que queremos copiar
   */
  Vector_Dinamico(const Vector_Dinamico& vd);

  /**
   * @brief Libera la memoria reservada
   */
  ~Vector_Dinamico();

  /**
   * @brief Iguala un vector a otro ya creado
   * @param vd Vector que queremos igualar
   */
  Vector_Dinamico& operator= (const Vector_Dinamico& vd);

  /**
   * @brief Cambia el tamaño de un vector creado a n
   * @param n Entero que sera el nuevo tamaño del vector
   */
  void resize(int n);

  /**
   * @brief Devuelve true si el vector tiene 0 elementos
   */
  bool vacia() const{ return utilizados == 0;}

  /**
   * @brief añade c al final del vector, aumentando su tamaño
   * @param c valor que se añade
   */ 
  void poner(T c);

  /**
   * @brief se elimina el ultimo elemento del vector
   */
  void quitar();

  /**
   * @brief devuelve el ultimo elemento del vector
   **/
  T tope() const;
  
};

#endif



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