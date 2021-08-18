#Variables
#Capitulo 1
PROG1 = bin/capitulo_1/programa

OBJ1MAIN = obj/capitulo_1/main.o
OBJ1RECIPROCAL = obj/capitulo_1/reciprocal.o
OBJS1 = $(OBJ1MAIN) $(OBJ1RECIPROCAL)

SRC1MAIN = src/capitulo_1/main.c
SRC1RECIPROCAL = src/capitulo_1/reciprocal.cpp
SRC1CABECERA = src/capitulo_1/reciprocal.hpp



#make all
all: $(PROG1)

#Capitulo 1
$(PROG1): $(OBJS1)
	g++ -o $(PROG1) $(OBJS1)

$(OBJ1MAIN): $(SRC1MAIN) $(SRC1CABECERA)
	g++ -c $(SRC1MAIN) -o $(OBJ1MAIN)

$(OBJ1RECIPROCAL): $(SRC1RECIPROCAL) $(SRC1CABECERA)
	g++ -c $(SRC1RECIPROCAL) -o $(OBJ1RECIPROCAL)


#Capitulo 2



#clean
clean:
	rm -f $(PROG1) $(OBJS1)




