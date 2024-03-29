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
	$(CXX) -o $(BIN)/pilamax $(OBJ)/usopilamax.o
$(OBJ)/usopilamax.o: $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/usopilamax.o $(SRC)/usopilas_max.cpp

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
