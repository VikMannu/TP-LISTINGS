//Listing 5.3 (sem_init.c) Initializing a Binary Semaphore

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <sys/stat.h>

#define KEY 0x1111

/* We must define union semun ourselves. */
/* Debemos definir union semun nosotros mismos. */
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

/* Initialize a binary semaphore with a value of 1. */
/* Inicializar un semáforo binario con un valor de 1. */
int binary_semaphore_initialize(int semid)
{
    union semun argument;
    unsigned short values[1];
    values[0] = 1;
    argument.array = values;
    return semctl(semid, 0, SETALL, argument);
}

int main (int argc, char* argv[])
{
	// Primero debemos alojar espacio para el semaforo 
	int id_semaforo = semget(KEY, 1, IPC_CREAT | S_IWUSR | S_IRUSR);
	
	printf("Valor del id del semaforo: %d\n", id_semaforo);
	
	int valor_semaforo = binary_semaphore_initialize(id_semaforo);
	
	printf("Valor retornado por la funcion semctl: %d\n", valor_semaforo);
	printf("Este valor significa que se inicializo exitosamente el semaforo\n");
	
	int estado = binary_semaphore_deallocate(id_semaforo);
	
	printf("Semaforo binario desalojado\n");
	
	return 0;
}