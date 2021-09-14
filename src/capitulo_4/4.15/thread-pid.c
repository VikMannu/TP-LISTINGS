//Listing 4.15 (thread-pid.c) Print Process IDs for Threads

//A traves de este codigo es posible ver pdi del proceso de los hilos
//este coincide porque comparten los mismos recursos y misma direccion de memoria
//que el hilo principal. 

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
//funcion de hilo
void *thread_function(void *arg)
{
    fprintf(stderr, "child thread pid is % d\n", (int)getpid());
    /* Spin forever. */
    while (1)
        ;
    return NULL;
}


int main()
{
    pthread_t thread;
    fprintf(stderr, "main thread pid is % d\n", (int)getpid());
    pthread_create(&thread, NULL, &thread_function, NULL);
    /* Spin forever. */
    while (1)
        ;
    return 0;
}