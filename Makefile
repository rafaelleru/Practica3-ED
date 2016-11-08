SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usocolas


$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o 
$(OBJ)/usocolas.o: $(INC)/cola.h $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o -I$(INC)



# ********** Uso pilaMax ********************

pila: $(BIN)/pilamax

$(BIN)/pilamax: $(OBJ)/usopilamax.o
	$(CXX) -o $(BIN)/pilamax $(OBJ)/usopilamax.o $(OBJ)/pilamaxlist.o
$(OBJ)/usopilamax.o: $(SRC)/usopilas_max.cpp $(OBJ)/pilamaxlist.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/usopilamax.o $(SRC)/usopilas_max.cpp $(OBJ)/pilamaxlist.o -I$(INC)

$(OBJ)/pilamaxlist.o: $(SRC)/Pila_max_list.cpp $(OBJ)/Lista_enlazada.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pilamaxlist.o $(INC)/Pila_max_list.hpp $(OBJ)/Lista_enlazada.o -I$(INC)

$(OBJ)/Lista_enlazada.o: $(SRC)/Lista_enlazada.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Lista_enlazada.o $(INC)/Lista_enlazada.hpp -I$(INC)

vector: $(BIN)/pruebaVD

$(BIN)/pruebaVD: $(OBJ)/mainVD.o
	$(CXX) -o $(BIN)/pruebaVD $(OBJ)/mainVD.o
$(OBJ)/mainVD.o: $(OBJ)/VectorDinamico.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/mainVD.o $(SRC)/mainVD.cpp -I$(INC)
$(OBJ)/VectorDinamico.o: $(INC)/VectorDinamico.hpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/VectorDinamico.o $(INC)/VectorDinamico.hpp
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
