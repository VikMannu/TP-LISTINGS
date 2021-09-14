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

/* Obtain a binary semaphore’s ID, allocating if necessary. */
/* Obtener un ID de semáforo binario, asignando si es necesario. */
int binary_semaphore_allocation(key_t key, int sem_flags)
{
    return semget(key, 1, sem_flags);
}

/* Deallocate a binary semaphore. All users must have finished their
use. Returns -1 on failure. */
/* Desasignar un semáforo binario. Todos los usuarios deben haber 
terminado su uso. Devuelve -1 en caso de fallo. */
int binary_semaphore_deallocate(int semid)
{
    union semun ignored_argument;
    return semctl(semid, 1, IPC_RMID, ignored_argument);
}


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
	int sem_id = semget(KEY, 1, IPC_CREAT | S_IWUSR | S_IRUSR);
	
	printf(" Valor del id del semaforo: %d\n", sem_id);
	
	int value_sem = binary_semaphore_initialize(sem_id);
	
	printf(" Valor retornado por la funcion semctl: %d\n", value_sem);
	printf(" Este valor significa que se inicializo exitosamente el semaforo\n");
	
	int estado = binary_semaphore_deallocate(sem_id);
	printf(" Semaforo binario desalojado\n");
	
	return 0;
}