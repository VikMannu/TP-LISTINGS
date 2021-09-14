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
SRC-2.5 = src/capitulo_2/2.5/temp_file.c
#2.6
BIN-2.6 = bin/capitulo_2/2.6/readfile
OBJ-2.6 = obj/capitulo_2/2.6/readfile.o
SRC-2.6 = src/capitulo_2/2.6/readfile.c
#2.7&2.8
#No utilice las variables porque por alguna razón daba un error
BIN-2.8 = bin/capitulo_2/2.7_2.8/app
OBJ-2.7 = obj/capitulo_2/2.7_2.8/test.o
OBJ-2.8 = obj/capitulo_2/2.7_2.8/app.o
SRC-2.7 = src/capitulo_2/2.7_2.8/test.c
SRC-2.8 = src/capitulo_2/2.7_2.8/app.c
LIBTEST = obj/capitulo_2/2.7_2.8/libtest.a
LIBURL = obj/capitulo_2/2.7_2.8
#2.9
#No utilice las variables porque por alguna razón daba un error
BIN-2.9 = bin/capitulo_2/2.9/tifftest
OBJ-2.9 = obj/capitulo_2/2.9/tifftest.o
SRC-2.9 = src/capitulo_2/2.9/tifftest.c

#CAPITULO 3
#3.1
BIN-3.1 = bin/capitulo_3/3.1/print-pid
OBJ-3.1 = obj/capitulo_3/3.1/print-pid.o
SRC-3.1 = src/capitulo_3/3.1/print-pid.c
#3.2
BIN-3.2 = bin/capitulo_3/3.2/system
OBJ-3.2 = obj/capitulo_3/3.2/system.o
SRC-3.2 = src/capitulo_3/3.2/system.c
#3.3
BIN-3.3 = bin/capitulo_3/3.3/fork
OBJ-3.3 = obj/capitulo_3/3.3/fork.o
SRC-3.3 = src/capitulo_3/3.3/fork.c
#3.4
BIN-3.4 = bin/capitulo_3/3.4/fork-exec
OBJ-3.4 = obj/capitulo_3/3.4/fork-exec.o
SRC-3.4 = src/capitulo_3/3.4/fork-exec.c
#3.5
BIN-3.5 = bin/capitulo_3/3.5/sigusr1
OBJ-3.5 = obj/capitulo_3/3.5/sigusr1.o
SRC-3.5 = src/capitulo_3/3.5/sigusr1.c
#3.6
BIN-3.6 = bin/capitulo_3/3.6/zombie
OBJ-3.6 = obj/capitulo_3/3.6/zombie.o
SRC-3.6 = src/capitulo_3/3.6/zombie.c
#3.7
BIN-3.7 = bin/capitulo_3/3.7/sigchld
OBJ-3.7 = obj/capitulo_3/3.7/sigchld.o
SRC-3.7 = src/capitulo_3/3.7/sigchld.c

#CAPITULO 5
#5.1
BIN-5.1 = bin/capitulo_5/5.1/shm
OBJ-5.1 = obj/capitulo_5/5.1/shm.o
SRC-5.1 = src/capitulo_5/5.1/shm.c
#5.2
BIN-5.2 = bin/capitulo_5/5.2/sem_all_deall
OBJ-5.2 = obj/capitulo_5/5.2/sem_all_deall.o
SRC-5.2 = src/capitulo_5/5.2/sem_all_deall.c
#5.3
BIN-5.3 = bin/capitulo_5/5.3/sem_init
OBJ-5.3 = obj/capitulo_5/5.3/sem_init.o
SRC-5.3 = src/capitulo_5/5.3/sem_init.c
#5.4
BIN-5.4 = bin/capitulo_5/5.4/sem_pv
OBJ-5.4 = obj/capitulo_5/5.4/sem_pv.o
SRC-5.4 = src/capitulo_5/5.4/sem_pv.c
#5.5
BIN-5.5 = bin/capitulo_5/5.5/mmap-write
OBJ-5.5 = obj/capitulo_5/5.5/mmap-write.o
SRC-5.5 = src/capitulo_5/5.5/mmap-write.c
#5.6
BIN-5.6 = bin/capitulo_5/5.6/mmap-read
OBJ-5.6 = obj/capitulo_5/5.6/mmap-read.o
SRC-5.6 = src/capitulo_5/5.6/mmap-read.c
#5.7
BIN-5.7 = bin/capitulo_5/5.7/pipe
OBJ-5.7 = obj/capitulo_5/5.7/pipe.o
SRC-5.7 = src/capitulo_5/5.7/pipe.c
#5.8
BIN-5.8 = bin/capitulo_5/5.8/dup2
OBJ-5.8 = obj/capitulo_5/5.8/dup2.o
SRC-5.8 = src/capitulo_5/5.8/dup2.c
#5.9
BIN-5.9 = bin/capitulo_5/5.9/popen
OBJ-5.9 = obj/capitulo_5/5.9/popen.o
SRC-5.9 = src/capitulo_5/5.9/popen.c
#5.10
BIN-5.10 = bin/capitulo_5/5.10/socket-server
OBJ-5.10 = obj/capitulo_5/5.10/socket-server.o
SRC-5.10 = src/capitulo_5/5.10/socket-server.c
#5.11
BIN-5.11 = bin/capitulo_5/5.11/socket-client
OBJ-5.11 = obj/capitulo_5/5.11/socket-client.o
SRC-5.11 = src/capitulo_5/5.11/socket-client.c
#5.12
BIN-5.12 = bin/capitulo_5/5.12/socket-inet
OBJ-5.12 = obj/capitulo_5/5.12/socket-inet.o
SRC-5.12 = src/capitulo_5/5.12/socket-inet.c


#COMPILACIONES
#make all
all: all-1 all-2 all-3 all-5

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
all-2: $(BIN-2.1) $(BIN-2.2) $(BIN-2.3) $(BIN-2.4) $(BIN-2.5) $(BIN-2.6) $(BIN-2.8) $(BIN-2.9)
#2.1
exec-2.1:
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
$(OBJ-2.5): $(SRC-2.5)
	g++ -c $(SRC-2.5) -o $(OBJ-2.5)
listing-2.5: $(SRC-2.5)
	g++ -c $(SRC-2.5) -o $(OBJ-2.5)
#2.6
exec-2.6:
	./$(BIN-2.6) $(CFLAGS)
$(BIN-2.6): $(OBJ-2.6)
	g++ -o $(BIN-2.6) $(OBJ-2.6)
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
	@echo "g++ -o bin/capitulo_2/2.7_2.8/app src/capitulo_2/2.7_2.8/app.c -L./obj/capitulo_2/2.7_2.8 -ltest"
$(LIBTEST): $(OBJ-2.7)
	ar cr $(LIBTEST) $(OBJ-2.7)
	@echo "Se creó la libreria libtest.a"
$(OBJ-2.7): $(SRC-2.7)
	g++ -c $(SRC-2.7) -o $(OBJ-2.7)
listing-2.7:
	g++ -c $(SRC-2.7) -o $(OBJ-2.7)
	ar cr $(LIBTEST) $(OBJ-2.7)
	@echo "Se creó la libreria libtest.a"
listing-2.8: $(LIBTEST)
#	g++ -o $(BIN-2.8) $(SRC-2.8) -L./$(LIBURL) -ltest
#	mv tifftest.o obj/capitulo_2/2.9/
# solo con @echo me funcionó cuando probé en mi computadora
	@echo "g++ -o bin/capitulo_2/2.7_2.8/app src/capitulo_2/2.7_2.8/app.c -L./obj/capitulo_2/2.7_2.8 -ltest"

#2.9
exec-2.9:
	./$(BIN-2.9) $(CFLAGS)
$(BIN-2.9):
	g++ -o bin/capitulo_2/2.9/tifftest src/capitulo_2/2.9/tifftest.c -ltiff
listing-2.9:
	g++ -o bin/capitulo_2/2.9/tifftest src/capitulo_2/2.9/tifftest.c -ltiff

	
#CAPITULO 3
all-3: $(BIN-3.1) $(BIN-3.2) $(BIN-3.3) $(BIN-3.4) $(BIN-3.5) $(BIN-3.6) $(BIN-3.7)
#3.1
exec-3.1:
	./$(BIN-3.1) $(CFLAGS)
$(BIN-3.1): $(OBJ-3.1)
	g++ -o $(BIN-3.1) $(OBJ-3.1)
$(OBJ-3.1): $(SRC-3.1)
	g++ -c $(SRC-3.1) -o $(OBJ-3.1)
listin-3.1: $(SRC-3.1)
	g++ -c $(SRC-3.1) -o $(OBJ-3.1)
#3.2
exec-3.2:
	./$(BIN-3.2) $(CFLAGS)
$(BIN-3.2): $(OBJ-3.2)
	g++ -o $(BIN-3.2) $(OBJ-3.2)
$(OBJ-3.2): $(SRC-3.2)
	g++ -c $(SRC-3.2) -o $(OBJ-3.2)
listin-3.2: $(SRC-3.2)
	g++ -c $(SRC-3.2) -o $(OBJ-3.2)
#3.3
exec-3.3:
	./$(BIN-3.3) $(CFLAGS)
$(BIN-3.3): $(OBJ-3.3)
	g++ -o $(BIN-3.3) $(OBJ-3.3)
$(OBJ-3.3): $(SRC-3.3)
	g++ -c $(SRC-3.3) -o $(OBJ-3.3)
listin-3.3: $(SRC-3.3)
	g++ -c $(SRC-3.3) -o $(OBJ-3.3)
#3.4
exec-3.4:
	./$(BIN-3.4) $(CFLAGS)
$(BIN-3.4): $(OBJ-3.4)
	g++ -o $(BIN-3.4) $(OBJ-3.4)
$(OBJ-3.4): $(SRC-3.4)
	g++ -c $(SRC-3.4) -o $(OBJ-3.4)
listin-3.4: $(SRC-3.4)
	g++ -c $(SRC-3.4) -o $(OBJ-3.4)
#3.5
exec-3.5:
	./$(BIN-3.5) $(CFLAGS)
$(BIN-3.5): $(OBJ-3.5)
	g++ -o $(BIN-3.5) $(OBJ-3.5)
$(OBJ-3.5): $(SRC-3.5)
	g++ -c $(SRC-3.5) -o $(OBJ-3.5)
listin-3.5: $(SRC-3.5)
	g++ -c $(SRC-3.5) -o $(OBJ-3.5)
#3.6
exec-3.6:
	./$(BIN-3.6) $(CFLAGS)
$(BIN-3.6): $(OBJ-3.6)
	g++ -o $(BIN-3.6) $(OBJ-3.6)
$(OBJ-3.6): $(SRC-3.6)
	g++ -c $(SRC-3.6) -o $(OBJ-3.6)
listin-3.6: $(SRC-3.6)
	g++ -c $(SRC-3.6) -o $(OBJ-3.6)
#3.7
exec-3.7:
	./$(BIN-3.7) $(CFLAGS)
$(BIN-3.7): $(OBJ-3.7)
	g++ -o $(BIN-3.7) $(OBJ-3.7)
$(OBJ-3.7): $(SRC-3.7)
	g++ -c $(SRC-3.7) -o $(OBJ-3.7)
listin-3.7: $(SRC-3.7)
	g++ -c $(SRC-3.7) -o $(OBJ-3.7)

#CAPITULO 4
all-4:


#CAPITULO 5
all-5: $(BIN-5.1) $(BIN-5.2) $(BIN-5.3) $(BIN-5.4) $(BIN-5.5) $(BIN-5.6) $(BIN-5.7) $(BIN-5.8) \
		$(BIN-5.9) $(BIN-5.10) $(BIN-5.11) $(BIN-5.12)

#5.1
exec-5.1:
	./$(BIN-5.1) $(CFLAGS)
$(BIN-5.1): $(OBJ-5.1)
	g++ -o $(BIN-5.1) $(OBJ-5.1)
$(OBJ-5.1): $(SRC-5.1)
	g++ -c $(SRC-5.1) -o $(OBJ-5.1)
listing-5.1: $(SRC-5.1)
	g++ -c $(SRC-5.1) -o $(OBJ-5.1)

#5.2
exec-5.2:
	./$(BIN-5.2) $(CFLAGS)
$(BIN-5.2): $(OBJ-5.2)
	g++ -o $(BIN-5.2) $(OBJ-5.2)
$(OBJ-5.2): $(SRC-5.2)
	g++ -c $(SRC-5.2) -o $(OBJ-5.2)
listing-5.2: $(SRC-5.2)
	g++ -c $(SRC-5.2) -o $(OBJ-5.2)

#5.3
exec-5.3:
	./$(BIN-5.3) $(CFLAGS)
$(BIN-5.3): $(OBJ-5.3)
	g++ -o $(BIN-5.3) $(OBJ-5.3)
$(OBJ-5.3): $(SRC-5.3)
	g++ -c $(SRC-5.3) -o $(OBJ-5.3)
listing-5.3: $(SRC-5.3)
	g++ -c $(SRC-5.3) -o $(OBJ-5.3)

#5.4
exec-5.4:
	./$(BIN-5.4) $(CFLAGS)
$(BIN-5.4): $(OBJ-5.4)
	g++ -o $(BIN-5.4) $(OBJ-5.4)
$(OBJ-5.4): $(SRC-5.4)
	g++ -c $(SRC-5.4) -o $(OBJ-5.4)
listing-5.4: $(SRC-5.4)
	g++ -c $(SRC-5.4) -o $(OBJ-5.4)

#5.5
exec-5.5:
	./$(BIN-5.5) prueba
$(BIN-5.5): $(OBJ-5.5)
	g++ -o $(BIN-5.5) $(OBJ-5.5)
$(OBJ-5.5): $(SRC-5.5)
	g++ -c $(SRC-5.5) -o $(OBJ-5.5)
listing-5.5: $(SRC-5.5)
	g++ -c $(SRC-5.5) -o $(OBJ-5.5)

#5.6
exec-5.6:
	./$(BIN-5.6) prueba
	rm -f prueba
$(BIN-5.6): $(OBJ-5.6)
	g++ -o $(BIN-5.6) $(OBJ-5.6)
$(OBJ-5.6): $(SRC-5.6)
	g++ -c $(SRC-5.6) -o $(OBJ-5.6)
listing-5.6: $(SRC-5.6)
	g++ -c $(SRC-5.6) -o $(OBJ-5.6)

#5.7
exec-5.7:
	./$(BIN-5.7) $(CFLAGS)
$(BIN-5.7): $(OBJ-5.7)
	g++ -o $(BIN-5.7) $(OBJ-5.7)
$(OBJ-5.7): $(SRC-5.7)
	g++ -c $(SRC-5.7) -o $(OBJ-5.7)
listing-5.7: $(SRC-5.7)
	g++ -c $(SRC-5.7) -o $(OBJ-5.7)

#5.8
exec-5.8:
	./$(BIN-5.8) $(CFLAGS)
$(BIN-5.8): $(OBJ-5.8)
	g++ -o $(BIN-5.8) $(OBJ-5.8)
$(OBJ-5.8): $(SRC-5.8)
	g++ -c $(SRC-5.8) -o $(OBJ-5.8)
listing-5.8: $(SRC-5.8)
	g++ -c $(SRC-5.8) -o $(OBJ-5.8)

#5.9
exec-5.9:
	./$(BIN-5.9) $(CFLAGS)
$(BIN-5.9): $(OBJ-5.9)
	g++ -o $(BIN-5.9) $(OBJ-5.9)
$(OBJ-5.9): $(SRC-5.9)
	g++ -c $(SRC-5.9) -o $(OBJ-5.9)
listing-5.9: $(SRC-5.9)
	g++ -c $(SRC-5.9) -o $(OBJ-5.9)

#5.10
exec-5.10:
	./$(BIN-5.10) $(CFLAGS)
$(BIN-5.10): $(OBJ-5.10)
	g++ -o $(BIN-5.10) $(OBJ-5.10)
$(OBJ-5.10): $(SRC-5.10)
	g++ -c $(SRC-5.10) -o $(OBJ-5.10)
listing-5.10: $(SRC-5.10)
	g++ -c $(SRC-5.10) -o $(OBJ-5.10)

#5.11
exec-5.11:
	./$(BIN-5.11) $(CFLAGS)
$(BIN-5.11): $(OBJ-5.11)
	g++ -o $(BIN-5.11) $(OBJ-5.11)
$(OBJ-5.11): $(SRC-5.11)
	g++ -c $(SRC-5.11) -o $(OBJ-5.11)
listing-5.11: $(SRC-5.11)
	g++ -c $(SRC-5.11) -o $(OBJ-5.11)

#5.12
exec-5.12:
	./$(BIN-5.12) $(CFLAGS)
$(BIN-5.12): $(OBJ-5.12)
	g++ -o $(BIN-5.12) $(OBJ-5.12)
$(OBJ-5.12): $(SRC-5.12)
	g++ -c $(SRC-5.12) -o $(OBJ-5.12)
listing-5.12: $(SRC-5.12)
	g++ -c $(SRC-5.12) -o $(OBJ-5.12)


#clean
clean: clean-1 clean-2 clean-3 clean-5

#clean-capitulo_1
clean-1:
	rm -f $(BIN-1.1) $(OBJS1) $(OBJ-1.1) $(OBJ-1.2)

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
	rm -f $(BIN-2.6) $(OBJ-2.6)
clean-2.7_2.8:
	rm -f $(BIN-2.8) $(LIBTEST) $(OBJ-2.7)
clean-2.9:
	rm -f $(BIN-2.9) $(OBJ-2.9)

#clean-capitulo_3
clean-3: clean-3.1 clean-3.2 clean-3.3 clean-3.4 clean-3.5 clean-3.6 clean-3.7

clean-3.1:
	rm -f $(BIN-3.1) $(OBJ-3.1) 
clean-3.2:
	rm -f $(BIN-3.2) $(OBJ-3.2)
clean-3.3:
	rm -f $(BIN-3.3) $(OBJ-3.3)
clean-3.4:
	rm -f $(BIN-3.4) $(OBJ-3.4)
clean-3.5:
	rm -f $(BIN-3.5) $(OBJ-3.5)
clean-3.6:
	rm -f $(BIN-3.6) $(OBJ-3.6)
clean-3.7:
	rm -f $(BIN-3.7) $(OBJ-3.7)

#clean-capitulo_5
clean-5: clean-5.1 clean-5.2 clean-5.3 clean-5.4 clean-5.5 clean-5.6 clean-5.7 clean-5.8 clean-5.9 clean-5.10 clean-5.11 clean-5.12

clean-5.1:
	rm -f $(BIN-5.1) $(OBJ-5.1)
clean-5.2:
	rm -f $(BIN-5.2) $(OBJ-5.2)
clean-5.3:
	rm -f $(BIN-5.3) $(OBJ-5.3)
clean-5.4:
	rm -f $(BIN-5.4) $(OBJ-5.4)
clean-5.5:
	rm -f $(BIN-5.5) $(OBJ-5.5)
clean-5.6:
	rm -f $(BIN-5.6) $(OBJ-5.6)
clean-5.7:
	rm -f $(BIN-5.7) $(OBJ-5.7)
clean-5.8:
	rm -f $(BIN-5.8) $(OBJ-5.8)
clean-5.9:
	rm -f $(BIN-5.9) $(OBJ-5.9)
clean-5.10:
	rm -f $(BIN-5.10) $(OBJ-5.10)
clean-5.11:
	rm -f $(BIN-5.11) $(OBJ-5.11)
clean-5.12:
	rm -f $(BIN-5.12) $(OBJ-5.12)