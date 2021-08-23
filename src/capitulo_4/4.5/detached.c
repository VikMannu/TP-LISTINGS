//Listing 4.5 (detached.c) Skeleton Program That Creates a Detached Thread
//En este programa se muestra la ejecución de hilos separados
//sin necesidad del join
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *thread_function(void *thread_arg)
{
    int n=10,i=0;
    for (i = 0; i < n; i++)
    {
        printf("%d",i);
    }
    printf("\nFinaliza el hilo...\n");
    return NULL;
}
//Funcion fibonacci para el main
int fibonacci(int n){
    if(n==1){
        return 1;
    }else if(n==0){
        return 0;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main()
{
    pthread_attr_t attr;
    pthread_t thread;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread, &attr, &thread_function, NULL);
    /* Do work here... */
    //Realizando el trabajo del main
    int v= fibonacci(30);
    /* No need to join the second thread. */
    //no se necesita unir con el segundo hilo
    printf("El fibonacci de 30 es: %d\n...Finaliza el main\n", v);
    pthread_attr_destroy(&attr);
    return 0;
}
 
