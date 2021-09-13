#VARIABLES
#CAPITULO 1
PROG1 = bin/capitulo_1/main

OBJ1MAIN = obj/capitulo_1/main.o
OBJ1RECIPROCAL = obj/capitulo_1/reciprocal.o
OBJS1 = $(OBJ1MAIN) $(OBJ1RECIPROCAL)

SRC1MAIN = src/capitulo_1/main.c
SRC1RECIPROCAL = src/capitulo_1/reciprocal.cpp
SRC1CABECERA = src/capitulo_1/reciprocal.hpp

#CAPITULO 2
#Capitulo 2.1
PROG2-1 = bin/capitulo_2/2.1/arglist
OBJ2-1 = obj/capitulo_2/2.1/arglist.o
SRC2-1 = src/capitulo_2/2.1/arglist.c

#Capitulo 2.1
PROG2-2 = bin/capitulo_2/2.2/getopt_long
OBJ2-2 = obj/capitulo_2/2.2/getopt_long.o
SRC2-2 = src/capitulo_2/2.2/getopt_long.c


#CAPITULO 5
#Capitulo 5.1
PROG5-1 = bin/capitulo_5/5.1/shm
OBJ5-1 = obj/capitulo_5/5.1/shm.o
SRC5-1 = src/capitulo_5/5.1/shm.c


#COMPILACIONES
#make all
all: all-1 all-2 all-3 all-4 all-5

#CAPITULO 1
all-1: $(PROG1)
$(PROG1): $(OBJS1)
	g++ -o $(PROG1) $(OBJS1)

$(OBJ1MAIN): $(SRC1MAIN) $(SRC1CABECERA)
	g++ -c $(SRC1MAIN) -o $(OBJ1MAIN)

$(OBJ1RECIPROCAL): $(SRC1RECIPROCAL) $(SRC1CABECERA)
	g++ -c $(SRC1RECIPROCAL) -o $(OBJ1RECIPROCAL)

listing-1.1: $(SRC1MAIN) $(SRC1CABECERA)
	g++ -c $(SRC1MAIN) -o $(OBJ1MAIN)

listing-1.2: $(SRC1RECIPROCAL) $(SRC1CABECERA)
	g++ -c $(SRC1RECIPROCAL) -o $(OBJ1RECIPROCAL)

#CAPITULO 2
all-2: $(PROG2-1) $(PROG2-2)
#2.1
$(PROG2-1): $(OBJ2-1)
	g++ -o $(PROG2-1) $(OBJ2-1)

$(OBJ2-1): $(SRC2-1)
	g++ -c $(SRC2-1) -o $(OBJ2-1)

listing-2.1: $(SRC2-1)
	g++ -c $(SRC2-1) -o $(OBJ2-1)

#2.2
$(PROG2-2): $(OBJ2-2)
	g++ -o $(PROG2-2) $(OBJ2-2)

$(OBJ2-2): $(SRC2-2)
	g++ -c $(SRC2-2) -o $(OBJ2-2)

listing-2.2: $(SRC2-2)
	g++ -c $(SRC2-2) -o $(OBJ2-2)

#CAPITULO 3
all-3:

#CAPITULO 4
all-4:


#CAPITULO 5
all-5: $(PROG5-1)
#5.1
$(PROG5-1): $(OBJ5-1)
	g++ -o $(PROG5-1) $(OBJ5-1)

$(OBJ5-1): $(SRC5-1)
	g++ -c $(SRC5-1) -o $(OBJ5-1)

listing-5.1: $(SRC5-1)
	g++ -c $(SRC5-1) -o $(OBJ5-1)


#clean
clean: clean-1 clean-2 clean-3 clean-4 clean-5

clean-1:
	rm -f $(PROG1) $(OBJS1)

clean-2:
	rm -f $(PROG2-1) $(OBJ2-1) $(PROG2-2) $(OBJ2-2)

clean-3:
	

clean-4:


clean-5:
	rm -f $(PROG5-1)

