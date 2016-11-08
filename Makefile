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

$(BIN)/pilamax: $(OBJ)/pilamax.o
	$(CXX) -o $(BIN)/pilamax $(OBJ)/pilamax.o
$(OBJ)/pilamax.o: $(SRC)/usopilas_max.cpp $(INC)/Pila_max.h $(OBJ)/pilaMax.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pilamax.o $(SRC)/usopilas_max.cpp $(OBJ)/pilaMax.o -I$(INC)
$(OBJ)/pilaMax.o: $(INC)/Pila_max_list.h  $(INC)/Lista_enlazada.h $(INC)/Pila_max.h
	$(CXX)  $(CPPFLAGS) -o $(OBJ)/pilaMax.o $(Pila_max.h) $(SRC)/Pila_max_list.cpp -I$(INC) 

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
