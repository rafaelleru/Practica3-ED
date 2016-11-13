#define CUAL_COMPILA 1
#if CUAL_COMPILA==1
#include <./Pila_max_VD.hpp>
#elif CUAL_COMPILA==2
#include <./Pila_max_list.hpp>
#else
#include <./Pila_max_cola.hpp>
#endif
