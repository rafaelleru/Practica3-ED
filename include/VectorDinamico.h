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
  Vector_Dinamico(const Vector_Dinamica& vd);

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
