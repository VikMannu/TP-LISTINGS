#VARIABLES
#CAPITULO 1
BIN-1.1 = bin/capitulo_1/main

OBJ-1.1 = obj/capitulo_1/main.o
OBJ-1.2 = obj/capitulo_1/reciprocal.o
OBJS1 = $(OBJ-1.1) $(OBJ-1.2)

SRC-1.1 = src/capitulo_1/main.c
SRC-1.2 = src/capitulo_1/reciprocal.cpp
SRC-1.3 = src/capitulo_1/reciprocal.hpp

#CAPITULO 2
#2.1
BIN-2.1 = bin/capitulo_2/2.1/arglist
OBJ-2.1 = obj/capitulo_2/2.1/arglist.o
SRC-2.1 = src/capitulo_2/2.1/arglist.c

#2.2
BIN-2.2 = bin/capitulo_2/2.2/getopt_long
OBJ-2.2 = obj/capitulo_2/2.2/getopt_long.o
SRC-2.2 = src/capitulo_2/2.2/getopt_long.c

#2.3
BIN-2.3 = bin/capitulo_2/2.3/print-env
OBJ-2.3 = obj/capitulo_2/2.3/print-env.o
SRC-2.3 = src/capitulo_2/2.3/print-env.c

#2.4
BIN-2.4 = bin/capitulo_2/2.4/client
OBJ-2.4 = obj/capitulo_2/2.4/client.o
SRC-2.4 = src/capitulo_2/2.4/client.c

#2.5
BIN-2.5 = bin/capitulo_2/2.5/temp_file
OBJ-2.5 = obj/capitulo_2/2.5/temp_file.o
SRC2-5 = src/capitulo_2/2.5/temp_file.c

#2.6
PROG-2.6 = bin/capitulo_2/2.6/readfile
OBJ-2.6 = obj/capitulo_2/2.6/readfile.o
SRC-2.6 = src/capitulo_2/2.6/readfile.c

#2.7&2.8
BIN-2.8 = bin/capitulo_2/2.7_2.8/app

OBJ-2.7 = obj/capitulo_2/2.7_2.8/test.o
OBJ-2.8 = obj/capitulo_2/2.7_2.8/app.o

SRC-2.7 = src/capitulo_2/2.7_2.8/test.c
SRC-2.8 = src/capitulo_2/2.7_2.8/app.c

LIBTEST = obj/capitulo_2/2.7_2.8/libtest.a
LIBURL = obj/capitulo_2/2.7_2.8

#2.9
BIN-2.9 = bin/capitulo_2/2.9/tifftest
OBJ-2.9 = obj/capitulo_2/2.9/tifftest.o
SRC-2.9 = src/capitulo_2/2.9/tifftest.c

#CAPITULO 5
#Capitulo 5.1
PROG-5.1 = bin/capitulo_5/5.1/shm
OBJ-5.1 = obj/capitulo_5/5.1/shm.o
SRC-5.1 = src/capitulo_5/5.1/shm.c

#Capitulo 5.2
PROG-5.2 = bin/capitulo_5/5.2/shm
OBJ-5.2 = obj/capitulo_5/5.2/shm.o
SRC-5.2 = src/capitulo_5/5.2/shm.c

#COMPILACIONES
#make all
all: all-1 all-2 all-5

#CAPITULO 1
all-1: $(BIN-1.1)

exec-1.1:
	./$(BIN-1.1) $(CFLAGS)
exec-1.2:
	@echo "No posee bin"
exec-1.3:
	@echo "No posee bin"

$(BIN-1.1): $(OBJS1)
	g++ -o $(BIN-1.1) $(OBJS1)
$(OBJ-1.1): $(SRC-1.1) $(SRC-1.3)
	g++ -c $(SRC-1.1) -o $(OBJ-1.1)
$(OBJ-1.2): $(SRC-1.2) $(SRC-1.3)
	g++ -c $(SRC-1.2) -o $(OBJ-1.2)
listing-1.1: $(SRC-1.1) $(SRC-1.3)
	g++ -c $(SRC-1.1) -o $(OBJ-1.1)
listing-1.2: $(SRC-1.2) $(SRC-1.3)
	g++ -c $(SRC-1.2) -o $(OBJ-1.2)
listing-1.3: 
	@echo "El listing-1.3 es un encabezado"

#CAPITULO 2
all-2: $(BIN-2.1) $(BIN-2.2) $(BIN-2.3) $(BIN-2.4) $(BIN-2.5) $(PROG-2.6) $(BIN-2.8) $(BIN-2.9)
#2.1
exec2.1:
	./$(BIN-2.1) $(CFLAGS)
$(BIN-2.1): $(OBJ-2.1)
	g++ -o $(BIN-2.1) $(OBJ-2.1)
$(OBJ-2.1): $(SRC-2.1)
	g++ -c $(SRC-2.1) -o $(OBJ-2.1)
listing-2.1: $(SRC-2.1)
	g++ -c $(SRC-2.1) -o $(OBJ-2.1)

#2.2
exec-2.2:
	./$(BIN-2.2) $(CFLAGS)
$(BIN-2.2): $(OBJ-2.2)
	g++ -o $(BIN-2.2) $(OBJ-2.2)
$(OBJ-2.2): $(SRC-2.2)
	g++ -c $(SRC-2.2) -o $(OBJ-2.2)
listing-2.2: $(SRC-2.2)
	g++ -c $(SRC-2.2) -o $(OBJ-2.2)

#2.3
exec-2.3:
	./$(BIN-2.3) $(CFLAGS)
$(BIN-2.3): $(OBJ-2.3)
	g++ -o $(BIN-2.3) $(OBJ-2.3)
$(OBJ-2.3): $(SRC-2.3)
	g++ -c $(SRC-2.3) -o $(OBJ-2.3)
listing-2.3: $(SRC-2.3)
	g++ -c $(SRC-2.3) -o $(OBJ-2.3)

#2.4
exec-2.4:
	./$(BIN-2.4) $(CFLAGS)
$(BIN-2.4): $(OBJ-2.4)
	g++ -o $(BIN-2.4) $(OBJ-2.4)
$(OBJ-2.4): $(SRC-2.4)
	g++ -c $(SRC-2.4) -o $(OBJ-2.4)
listing-2.4: $(SRC-2.4)
	g++ -c $(SRC-2.4) -o $(OBJ-2.4)

#2.5
exec-2.5:
	./$(BIN-2.5) $(CFLAGS)
$(BIN-2.5): $(OBJ-2.5)
	g++ -o $(BIN-2.5) $(OBJ-2.5)
$(OBJ-2.5): $(SRC2-5)
	g++ -c $(SRC2-5) -o $(OBJ-2.5)
listing-2.5: $(SRC2-5)
	g++ -c $(SRC2-5) -o $(OBJ-2.5)

#2.6
exec-2.6:
	./$(PROG-2.6) $(CFLAGS)
$(PROG-2.6): $(OBJ-2.6)
	g++ -o $(PROG-2.6) $(OBJ-2.6)
$(OBJ-2.6): $(SRC-2.6)
	g++ -c $(SRC-2.6) -o $(OBJ-2.6)
listing-2.6: $(SRC-2.6)
	g++ -c $(SRC-2.6) -o $(OBJ-2.6)

#2.7&2.8
exec-2.7:
	@echo "No posee bin"
exec-2.8:
	./$(BIN-2.8) $(CFLAGS)
$(BIN-2.8): $(LIBTEST)
	g++ -o $(BIN-2.8) $(SRC-2.8) -L./$(LIBURL) -ltest
	mv tifftest.o obj/capitulo_2/2.9/
$(LIBTEST): $(OBJ-2.7)
	ar cr $(LIBTEST) $(OBJ-2.7)
	@echo "Se creó la libreria libtest.a"
$(OBJ-2.7): $(SRC-2.7)
	g++ -c $(SRC-2.7) -o $(OBJ-2.7)
listing-2.7:
	g++ -c $(SRC-2.7) -o $(OBJ-2.7)
	ar cr $(LIBTEST) $(OBJ-2.7)
	@echo "Se creó la libreria libtest.a"
listing-2.8: listing-2.7
	g++ -o $(BIN-2.8) $(SRC-2.8) -L./$(LIBURL) -ltest
	mv tifftest.o obj/capitulo_2/2.9/

#2.9
exec-2.9:
	./$(BIN-2.9) $(CFLAGS)
$(BIN-2.9): $(OBJ-2.9)
	g++ -o $(BIN-2.9) $(SRC-2.9) –ltiff
listing-2.9:
	g++ -o $(BIN-2.9) $(SRC-2.9) –ltiff

	
#CAPITULO 3
all-3:

#CAPITULO 4
all-4:


#CAPITULO 5
all-5: $(PROG-5.1) $(PROG-5.2)

#5.1
exec-5.1:
	./$(PROG-5.1) $(CFLAGS)
$(PROG-5.1): $(OBJ-5.1)
	g++ -o $(PROG-5.1) $(OBJ-5.1)
$(OBJ-5.1): $(SRC-5.1)
	g++ -c $(SRC-5.1) -o $(OBJ-5.1)
listing-5.1: $(SRC-5.1)
	g++ -c $(SRC-5.1) -o $(OBJ-5.1)

#5.2
exec-5.2:
	./$(PROG-5.2) $(CFLAGS)
$(PROG-5.2): $(OBJ-5.2)
	g++ -o $(PROG-5.2) $(OBJ-5.2)
$(OBJ-5.2): $(SRC-5.2)
	g++ -c $(SRC-5.2) -o $(OBJ-5.2)
listing-5.1: $(SRC-5.2)
	g++ -c $(SRC-5.2) -o $(OBJ-5.2)



#clean
clean: clean-1 clean-2 clean-5

#clean-capitulo_1
clean-1:
	rm -f $(BIN-1.1) $(OBJS1)

#clean-capitulo_2
clean-2: clean-2.1 clean-2.2 clean-2.3 clean-2.4 clean-2.5 clean-2.6 clean-2.7_2.8 clean-2.9

clean-2.1:
	rm -f $(BIN-2.1) $(OBJ-2.1)
clean-2.2:
	rm -f $(BIN-2.2) $(OBJ-2.2)
clean-2.3:
	rm -f $(BIN-2.3) $(OBJ-2.3)
clean-2.4:
	rm -f $(BIN-2.4) $(OBJ-2.4)
clean-2.5:
	rm -f $(BIN-2.5) $(OBJ-2.5)
clean-2.6:
	rm -f $(PROG-2.6) $(OBJ-2.6)
clean-2.7_2.8:
	rm -f $(BIN-2.8) $(LIBTEST) $(OBJ-2.7)
clean-2.9:
	rm -f $(BIN-2.9) $(OBJ-2.9)

#clean-capitulo_5
clean-5: clean-5.1

clean-5.1:
	rm -f $(PROG-5.1) $(OBJ-5.1)
clean-5.2:
	rm -f $(PROG-5.2) $(OBJ-5.2)