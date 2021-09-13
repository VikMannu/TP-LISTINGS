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
PROG-5.2 = bin/capitulo_5/5.2/sem_all_deall
OBJ-5.2 = obj/capitulo_5/5.2/sem_all_deall.o
SRC-5.2 = src/capitulo_5/5.2/sem_all_deall.c
#Capitulo 5.3
PROG-5.3 = bin/capitulo_5/5.3/sem_init
OBJ-5.3 = obj/capitulo_5/5.3/sem_init.o
SRC-5.3 = src/capitulo_5/5.3/sem_init.c
#Capitulo 5.4
PROG-5.4 = bin/capitulo_5/5.4/sem_pv
OBJ-5.4 = obj/capitulo_5/5.4/sem_pv.o
SRC-5.4 = src/capitulo_5/5.4/sem_pv.c
#Capitulo 5.5
PROG-5.5 = bin/capitulo_5/5.5/mmap-write
OBJ-5.5 = obj/capitulo_5/5.5/mmap-write.o
SRC-5.5 = src/capitulo_5/5.5/mmap-write.c
#Capitulo 5.6
PROG-5.6 = bin/capitulo_5/5.6/mmap-read
OBJ-5.6 = obj/capitulo_5/5.6/mmap-read.o
SRC-5.6 = src/capitulo_5/5.6/mmap-read.c
#Capitulo 5.7
PROG-5.7 = bin/capitulo_5/5.7/pipe
OBJ-5.7 = obj/capitulo_5/5.7/pipe.o
SRC-5.7 = src/capitulo_5/5.7/pipe.c
#Capitulo 5.8
PROG-5.8 = bin/capitulo_5/5.8/dup2
OBJ-5.8 = obj/capitulo_5/5.8/dup2.o
SRC-5.8 = src/capitulo_5/5.8/dup2.c
#Capitulo 5.9
PROG-5.9 = bin/capitulo_5/5.9/popen
OBJ-5.9 = obj/capitulo_5/5.9/popen.o
SRC-5.9 = src/capitulo_5/5.9/popen.c
#Capitulo 5.10
PROG-5.10 = bin/capitulo_5/5.10/socket-server
OBJ-5.10 = obj/capitulo_5/5.10/socket-server.o
SRC-5.10 = src/capitulo_5/5.10/socket-server.c
#Capitulo 5.11
PROG-5.11 = bin/capitulo_5/5.11/socket-client
OBJ-5.11 = obj/capitulo_5/5.11/socket-client.o
SRC-5.11 = src/capitulo_5/5.11/socket-client.c
#Capitulo 5.12
PROG-5.12 = bin/capitulo_5/5.12/socket-inet
OBJ-5.12 = obj/capitulo_5/5.12/socket-inet.o
SRC-5.12 = src/capitulo_5/5.12/socket-inet.c


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
listing-5.2: $(SRC-5.2)
	g++ -c $(SRC-5.2) -o $(OBJ-5.2)

#5.3
exec-5.3:
	./$(PROG-5.3) $(CFLAGS)
$(PROG-5.3): $(OBJ-5.3)
	g++ -o $(PROG-5.3) $(OBJ-5.3)
$(OBJ-5.3): $(SRC-5.3)
	g++ -c $(SRC-5.3) -o $(OBJ-5.3)
listing-5.3: $(SRC-5.3)
	g++ -c $(SRC-5.3) -o $(OBJ-5.3)

#5.4
exec-5.4:
	./$(PROG-5.4) $(CFLAGS)
$(PROG-5.4): $(OBJ-5.4)
	g++ -o $(PROG-5.4) $(OBJ-5.4)
$(OBJ-5.4): $(SRC-5.4)
	g++ -c $(SRC-5.4) -o $(OBJ-5.4)
listing-5.4: $(SRC-5.4)
	g++ -c $(SRC-5.4) -o $(OBJ-5.4)

#5.5
exec-5.5:
	./$(PROG-5.5) $(CFLAGS)
$(PROG-5.5): $(OBJ-5.5)
	g++ -o $(PROG-5.5) $(OBJ-5.5)
$(OBJ-5.5): $(SRC-5.5)
	g++ -c $(SRC-5.5) -o $(OBJ-5.5)
listing-5.5: $(SRC-5.5)
	g++ -c $(SRC-5.5) -o $(OBJ-5.5)

#5.6
exec-5.6:
	./$(PROG-5.6) $(CFLAGS)
$(PROG-5.6): $(OBJ-5.6)
	g++ -o $(PROG-5.6) $(OBJ-5.6)
$(OBJ-5.6): $(SRC-5.6)
	g++ -c $(SRC-5.6) -o $(OBJ-5.6)
listing-5.6: $(SRC-5.6)
	g++ -c $(SRC-5.6) -o $(OBJ-5.6)

#5.7
exec-5.7:
	./$(PROG-5.7) $(CFLAGS)
$(PROG-5.7): $(OBJ-5.7)
	g++ -o $(PROG-5.7) $(OBJ-5.7)
$(OBJ-5.7): $(SRC-5.7)
	g++ -c $(SRC-5.7) -o $(OBJ-5.7)
listing-5.7: $(SRC-5.7)
	g++ -c $(SRC-5.7) -o $(OBJ-5.7)

#5.8
exec-5.8:
	./$(PROG-5.8) $(CFLAGS)
$(PROG-5.8): $(OBJ-5.8)
	g++ -o $(PROG-5.8) $(OBJ-5.8)
$(OBJ-5.8): $(SRC-5.8)
	g++ -c $(SRC-5.8) -o $(OBJ-5.8)
listing-5.8: $(SRC-5.8)
	g++ -c $(SRC-5.8) -o $(OBJ-5.8)

#5.9
exec-5.9:
	./$(PROG-5.9) $(CFLAGS)
$(PROG-5.9): $(OBJ-5.9)
	g++ -o $(PROG-5.9) $(OBJ-5.9)
$(OBJ-5.9): $(SRC-5.9)
	g++ -c $(SRC-5.9) -o $(OBJ-5.9)
listing-5.9: $(SRC-5.9)
	g++ -c $(SRC-5.9) -o $(OBJ-5.9)

#5.10
exec-5.10:
	./$(PROG-5.10) $(CFLAGS)
$(PROG-5.10): $(OBJ-5.10)
	g++ -o $(PROG-5.10) $(OBJ-5.10)
$(OBJ-5.10): $(SRC-5.10)
	g++ -c $(SRC-5.10) -o $(OBJ-5.10)
listing-5.10: $(SRC-5.10)
	g++ -c $(SRC-5.10) -o $(OBJ-5.10)

#5.11
exec-5.11:
	./$(PROG-5.11) $(CFLAGS)
$(PROG-5.11): $(OBJ-5.11)
	g++ -o $(PROG-5.11) $(OBJ-5.11)
$(OBJ-5.11): $(SRC-5.11)
	g++ -c $(SRC-5.11) -o $(OBJ-5.11)
listing-5.11: $(SRC-5.11)
	g++ -c $(SRC-5.11) -o $(OBJ-5.11)

#5.12
exec-5.12:
	./$(PROG-5.12) $(CFLAGS)
$(PROG-5.12): $(OBJ-5.12)
	g++ -o $(PROG-5.12) $(OBJ-5.12)
$(OBJ-5.12): $(SRC-5.12)
	g++ -c $(SRC-5.12) -o $(OBJ-5.12)
listing-5.12: $(SRC-5.12)
	g++ -c $(SRC-5.12) -o $(OBJ-5.12)


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
clean-5: clean-5.1 clean-5.2 clean-5.3 clean-5.4 clean-5.5 clean-5.6 clean-5.7 clean-5.8 clean-5.9 clean-5.10 clean-5.11 clean-5.12

clean-5.1:
	rm -f $(PROG-5.1) $(OBJ-5.1)
clean-5.2:
	rm -f $(PROG-5.2) $(OBJ-5.2)
clean-5.3:
	rm -f $(PROG-5.3) $(OBJ-5.3)
clean-5.4:
	rm -f $(PROG-5.4) $(OBJ-5.4)
clean-5.5:
	rm -f $(PROG-5.5) $(OBJ-5.5)
clean-5.6:
	rm -f $(PROG-5.6) $(OBJ-5.6)
clean-5.7:
	rm -f $(PROG-5.7) $(OBJ-5.7)
clean-5.8:
	rm -f $(PROG-5.8) $(OBJ-5.8)
clean-5.9:
	rm -f $(PROG-5.9) $(OBJ-5.9)
clean-5.10:
	rm -f $(PROG-5.10) $(OBJ-5.10)
clean-5.11:
	rm -f $(PROG-5.11) $(OBJ-5.11)
clean-5.12:
	rm -f $(PROG-5.12) $(OBJ-5.12)