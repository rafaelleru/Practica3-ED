#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
#include "./Pila_max_vd.h"
#elif CUAL_COMPILA==2
#include "./Pila_max_list.h"
#else
#include "./pila_max_cola.h"
#endif
