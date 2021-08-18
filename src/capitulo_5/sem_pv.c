//Listing 5.4 (sem_pv.c) Wait and Post Operations for a Binary Semaphore

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

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