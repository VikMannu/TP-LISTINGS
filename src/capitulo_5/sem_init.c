//Listing 5.3 (sem_init.c) Initializing a Binary Semaphore

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

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