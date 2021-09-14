//Listing 4.13 (spin-condvar.c) A Simple Condition Variable Implementation

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int thread_flag;
pthread_mutex_t thread_flag_mutex;
void initialize_flag()
{
    pthread_mutex_init(&thread_flag_mutex, NULL);
    thread_flag = 0;
}

//funcion para trabaje
void do_work(int nro){
    printf("%d\n", nro);
}

struct params
{
    int number;
}typedef params;



/* Calls do_work repeatedly while the thread flag is set; otherwise
spins. */
/* Llama a do_work repetidamente mientras la bandera del hilo está activada; 
de lo contrario gira. */
void *thread_function(void *thread_arg)
{
    params *p=(params*) thread_arg;
    
    while (1)
    {
        int flag_is_set;
        /* Protect the flag with a mutex lock. */
        /* Protege la bandera con un bloqueo mutex. */
        pthread_mutex_lock(&thread_flag_mutex);
        flag_is_set = thread_flag;
        pthread_mutex_unlock(&thread_flag_mutex);
        if (flag_is_set) {
            printf("Thread ID: %lx\n", pthread_self());
            do_work(p->number);
            thread_flag = 0;
        } else {
            do_work(2*p->number);
            printf("La bandera se asigna a 1...\n");
            thread_flag = 1;
        }
        /* Else don’t do anything. Just loop again. */
        /* De lo contrario, no hagas nada. Simplemente repita el bucle. */
    }
    return NULL;
}

/* Sets the value of the thread flag to FLAG_VALUE. */
/* Establece el valor de la bandera del hilo en FLAG_VALUE. */
void set_thread_flag(int flag_value)
{
    /* Protect the flag with a mutex lock. */
    /* Protege la bandera con un bloqueo mutex. */
    pthread_mutex_lock(&thread_flag_mutex);
    thread_flag = flag_value;
    pthread_mutex_unlock(&thread_flag_mutex);
}

//a traves de la condicion de variable logramos hacer que la variable bandera 
//se modifica a lo largo de la ejecucion
//mostrando asi que dos hilos pudieron ejecutar los trabajos y a la vez poder 
//entrar en la condicon if else.

//Debe notarse que esta implementacion es ineficiente, porque
//cuando no se este realizando el ciclo de cada hilo, de todas formas se 
//esta verificando la condicion del flag una y otra vez, sin entrar al bucle.

int main(int argc, char const *argv[])
{
    pthread_t thread1, thread2;
    initialize_flag();
    //enviamos como parametros los nros a imprimir
    params philo1;
    params philo2;
    philo1.number=5;
    philo2.number=7;
    pthread_create(&thread1, NULL, &thread_function, &philo1);
    printf("Thread1 ID (main): %lx\n", thread1);
   
    pthread_create(&thread2, NULL, &thread_function, &philo2);
    printf("Thread2 ID (main): %lx\n", thread2);
    //el main espera a los hilos
    sleep(2);
    //cancelamos la ejecucion despues de 2 segundos
    pthread_cancel(thread1);
    pthread_cancel(thread2);

    return 0;
}
