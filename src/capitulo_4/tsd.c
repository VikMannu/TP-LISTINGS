//Listing 4.7 (tsd.c) Per-Thread Log Files Implemented with Thread-Specific Data

#include <malloc.h>
#include <pthread.h>
#include <stdio.h>

/* The key used to associate a log file pointer with each thread. */
/* La clave utilizada para asociar un puntero de archivo de registro con cada hilo. */
static pthread_key_t thread_log_key;

/* Write MESSAGE to the log file for the current thread. */
/* Escribe MESSAgE en el archivo de registro del hilo actual. */
void write_to_thread_log(const char *message)
{
    FILE *thread_log = (FILE *)pthread_getspecific(thread_log_key);
    fprintf(thread_log, "%s\n", message);
}

/* Close the log file pointer THREAD_LOG. */
/* Cierre el puntero del archivo de registro THREAD_LOG. */
void close_thread_log(void *thread_log)
{
    fclose((FILE *)thread_log);
}
void *thread_function(void *args)
{
    char thread_log_filename[20];
    FILE *thread_log;
    /* Generate the filename for this thread’s log file. */
    /* Genera el nombre de archivo para el archivo de registro de este hilo. */
    sprintf(thread_log_filename, "thread %d.log", (int)pthread_self());
    /* Open the log file. */
    /* Abre el archivo de registro. */
    thread_log = fopen(thread_log_filename, "w");
    /* Store the file pointer in thread-specific data under thread_log_key. */
    /* Almacena el puntero del archivo en datos específicos de subproceso en thread_log_key. */
    pthread_setspecific(thread_log_key, thread_log);
    write_to_thread_log("Thread starting.");
    /* Do work here... */
    return NULL;
}

int main()
{
    int i;
    pthread_t threads[5];
    /* Create a key to associate thread log file pointers in
    thread-specific data. Use close_thread_log to clean up the file
    pointers. */
    /* Crea una clave para asociar punteros al archivo de registro de 
    subprocesos en datos específicos de subprocesos. 
    Utilice close_thread_log para limpiar los punteros del archivo. */
    pthread_key_create(&thread_log_key, close_thread_log);
    /* Create threads to do the work. */
    /* Crea hilos para hacer el trabajo. */
    for (i = 0; i < 5; ++i)
        pthread_create(&(threads[i]), NULL, thread_function, NULL);
    /* Wait for all threads to finish. */
    /* Espere a que finalicen todos los hilos. */
    for (i = 0; i < 5; ++i)
        pthread_join(threads[i], NULL);
    return 0;
}