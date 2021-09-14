//Listing 5.4 (sem_pv.c) Wait and Post Operations for a Binary Semaphore

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <stdio.h>

#define KEY 0x1111

// Usamos parte del listing 5.3 para este codigo
union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *__buf;
};

// Usamos parte del listing 5.3 para este codigo
int binary_semaphore_initialize (int semid)
{
    union semun argument;
	unsigned short values[1];
	values[0] = 1;
	argument.array = values;
	return semctl (semid, 0, SETALL, argument);
}

/* Wait on a binary semaphore. Block until the semaphore value is positive, then 
decrement it by 1. */
/* Espera un semáforo binario. Bloquear hasta que el valor del semáforo 
sea positivo, luego disminuirlo en 1. */
int binary_semaphore_wait(int semid)
{
    struct sembuf operations[1];
    /* Use the first (and only) semaphore. */
    /* Usa el primer (y único) semáforo. */
    operations[0].sem_num = 0;
    /* Decrement by 1. */
    /* Disminución en 1. */
    operations[0].sem_op = -1;
    /* Permit undo'ing. */
    /* Permitir deshacer. */
    operations[0].sem_flg = SEM_UNDO;
    return semop(semid, operations, 1);
}

/* Post to a binary semaphore: increment its value by 1. 
This returns immediately. */
/* Publicar en un semáforo binario: incrementa su valor en 1. 
Esto regresa inmediatamente. */
int binary_semaphore_post(int semid)
{
    struct sembuf operations[1];
    /* Use the first (and only) semaphore. */
    /* Usa el primer (y único) semáforo. */
    operations[0].sem_num = 0;
    /* Increment by 1. */
    /* Incremento en 1. */
    operations[0].sem_op = 1;
    /* Permit undo'ing. */
    /* Permitir deshacer. */
    operations[0].sem_flg = SEM_UNDO;
    return semop(semid, operations, 1);
}

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

int main(int argc, char*argv[])
{
    int sem_id = binary_semaphore_allocation(KEY, IPC_CREAT);
    printf("\n Se alojo un semáforo y su sem_id es: %d", sem_id);
	
	int valor_semaforo = binary_semaphore_initialize(sem_id);
	
	int valor_retorno = binary_semaphore_post(sem_id);
	
	printf("\n Valor del semaforo: %d\n", valor_semaforo);

    int estado = binary_semaphore_deallocate(sem_id);
	printf("\n Semaforo binario desalojado y su estado es: \n", estado);
	
	return 0;
}