//Listing 5.2 (sem_all_deall.c) Allocating and Deallocating a Binary Semaphore
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

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

int main (int argc, char *argv[]) {
    printf("\n Obtener un ID de semáforo binario, asignando si es necesario.");
    int sem_id = binary_semaphore_allocation(KEY, IPC_CREAT);
	
	printf("\n Valor de semid:%d", sem_id);
	
    printf("\n Desasignar un semáforo binario."
           "\n Todos los usuarios deben haber terminado su uso. Devuelve -1 en caso de fallo.");
	binary_semaphore_deallocate(sem_id);
	
	printf("\n Semaforo binario desalojado\n");
	
	return 0;
}