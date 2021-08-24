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
#2.1
PROG2-1 = bin/capitulo_2/2.1/arglist
OBJ2-1 = obj/capitulo_2/2.1/arglist.o
SRC2-1 = src/capitulo_2/2.1/arglist.c

#2.2
PROG2-2 = bin/capitulo_2/2.2/getopt_long
OBJ2-2 = obj/capitulo_2/2.2/getopt_long.o
SRC2-2 = src/capitulo_2/2.2/getopt_long.c

#2.3
PROG2-3 = bin/capitulo_2/2.3/print-env
OBJ2-3 = obj/capitulo_2/2.3/print-env.o
SRC2-3 = src/capitulo_2/2.3/print-env.c

#2.4
PROG2-4 = bin/capitulo_2/2.4/client
OBJ2-4 = obj/capitulo_2/2.4/client.o
SRC2-4 = src/capitulo_2/2.4/client.c

#2.5
PROG2-5 = bin/capitulo_2/2.5/temp_file
OBJ2-5 = obj/capitulo_2/2.5/temp_file.o
SRC2-5 = src/capitulo_2/2.5/temp_file.c

#2.6
PROG2-6 = bin/capitulo_2/2.6/readfile
OBJ2-6 = obj/capitulo_2/2.6/readfile.o
SRC2-6 = src/capitulo_2/2.6/readfile.c

#2.7&2.8
PROGAPP = bin/capitulo_2/2.7_2.8/app

OBJAPP = obj/capitulo_2/2.7_2.8/app.o
OBJTEST = obj/capitulo_2/2.7_2.8/test.o
OBJTEST2 = obj/capitulo_2/2.7_2.8/test2.o

SRCAPP = src/capitulo_2/2.7_2.8/app.c
SRCTEST = src/capitulo_2/2.7_2.8/test.c
SRCTEST2 = src/capitulo_2/2.7_2.8/test.c

LIBTEST = obj/capitulo_2/2.7_2.8/libtest.a

#2.9
PROG2-9 = bin/capitulo_2/2.9/tifftest
OBJ2-9 = obj/capitulo_2/2.9/tifftest.o
SRC2-9 = src/capitulo_2/2.9/tifftest.c


#COMPILACIONES
#make all
all: all-1 all-2

#CAPITULO 1
all-1: $(PROG1)

exec1:
	./$(PROG1) $(CFLAGS)
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
all-2: $(PROG2-1) $(PROG2-2) $(PROG2-3) $(PROG2-4) $(PROG2-5) $(PROG2-6) $(PROAPP) $(PROG2-9)

#2.1
exec2.1:
	./$(PROG2-1) $(CFLAGS)
$(PROG2-1): $(OBJ2-1)
	g++ -o $(PROG2-1) $(OBJ2-1)
$(OBJ2-1): $(SRC2-1)
	g++ -c $(SRC2-1) -o $(OBJ2-1)
listing-2.1: $(SRC2-1)
	g++ -c $(SRC2-1) -o $(OBJ2-1)

#2.2
exec2.2:
	./$(PROG2-2) $(CFLAGS)
$(PROG2-2): $(OBJ2-2)
	g++ -o $(PROG2-2) $(OBJ2-2)
$(OBJ2-2): $(SRC2-2)
	g++ -c $(SRC2-2) -o $(OBJ2-2)
listing-2.2: $(SRC2-2)
	g++ -c $(SRC2-2) -o $(OBJ2-2)

#2.3
exec2.3:
	./$(PROG2-3) $(CFLAGS)
$(PROG2-3): $(OBJ2-3)
	g++ -o $(PROG2-3) $(OBJ2-3)
$(OBJ2-3): $(SRC2-3)
	g++ -c $(SRC2-3) -o $(OBJ2-3)
listing-2.3: $(SRC2-3)
	g++ -c $(SRC2-3) -o $(OBJ2-3)

#2.4
exec2.4:
	./$(PROG2-4) $(CFLAGS)
$(PROG2-4): $(OBJ2-4)
	g++ -o $(PROG2-4) $(OBJ2-4)
$(OBJ2-4): $(SRC2-4)
	g++ -c $(SRC2-4) -o $(OBJ2-4)
listing-2.4: $(SRC2-4)
	g++ -c $(SRC2-4) -o $(OBJ2-4)

#2.5
exec2.5:
	./$(PROG2-5) $(CFLAGS)
$(PROG2-5): $(OBJ2-5)
	g++ -o $(PROG2-5) $(OBJ2-5)
$(OBJ2-5): $(SRC2-5)
	g++ -c $(SRC2-5) -o $(OBJ2-5)
listing-2.5: $(SRC2-5)
	g++ -c $(SRC2-5) -o $(OBJ2-5)

#2.6
exec2.6:
	./$(PROG2-6) $(CFLAGS)
$(PROG2-6): $(OBJ2-6)
	g++ -o $(PROG2-6) $(OBJ2-6)
$(OBJ2-6): $(SRC2-6)
	g++ -c $(SRC2-6) -o $(OBJ2-6)
listing-2.6: $(SRC2-6)
	g++ -c $(SRC2-6) -o $(OBJ2-6)

#2.7&2.8
execapp:
	./$(PROAPP) $(CFLAGS)
$(PROGAPP): $(OBJAPP) $(LIBTEST)
	g++ -o $(PROAPP) $(OBJAPP) -L. -ltest -WL,-rpath,/home/victor/Documents/TP-LISTINGS/obj/capitulo_2/2.7_2.8/
$(LIBTEST): $(OBJTEST) $(OBJTEST2)
	ar cr $(LIBTEST) -o $(OBJTEST) $(OBJTEST)
$(OBJAPP): $(SRCAPP)
	g++ -c $(SRCAPP) -o $(OBJAPP)
$(OBJTEST): $(SRCTEST)
	g++ -c $(SRCTEST) -o $(OBJTEST)
$(OBJTEST2): $(SRCTEST2)
	g++ -c $(SRCTEST2) -o $(OBJTEST2)	
listing-2.7: $(SRCAPP)
	g++ -c $(SRCAPP) -o $(OBJAPP)
listing-2.8: $(SRCTEST)
	g++ -c $(SRCTEST) -o $(OBJTEST)

#2.9
exec2.9:
	./$(PROG2-9) $(CFLAGS)
$(PROG2-9): $(OBJ2-9)
	g++ -o $(PROG2-9) $(OBJ2-9) –ltiff
$(OBJ2-9): $(SRC2-9)
	g++ -c $(SRC2-9) -o $(OBJ2-9)
listing-2.9: $(SRC2-9)
	g++ -c $(SRC2-9) -o $(OBJ2-9)


#CLEAN
clean: clean-1 clean-2

#clean-capitulo_1
clean-1:
	rm -f $(PROG1) $(OBJS1)

#clean-capitulo_2
clean-2: clean-2.1 clean-2.2 clean-2.3 clean-2.4 clean-2.5 clean-2.6 clean-2.7_2.8 clean-2.9

clean-2.1:
	rm -f $(PROG2-1) $(OBJ2-1)

clean-2.2:
	rm -f $(PROG2-2) $(OBJ2-2)

clean-2.3:
	rm -f $(PROG2-3) $(OBJ2-3)

clean-2.4:
	rm -f $(PROG2-4) $(OBJ2-4)

clean-2.5:
	rm -f $(PROG2-5) $(OBJ2-5)

clean-2.6:
	rm -f $(PROG2-6) $(OBJ2-6)

clean-2.7_2.8:
	rm -f $(LIBTEST) $(OBJTEST) $(OBJTEST2)

clean-2.9:
	rm -f $(PROG2-6) $(OBJ2-6)