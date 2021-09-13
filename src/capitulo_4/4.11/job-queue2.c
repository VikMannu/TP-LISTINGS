//Listing 4.11 (job-queue2.c) Job Queue Thread Function, Protected by a Mutex

#include <malloc.h>
#include <pthread.h>

struct job
{
    /* Link field for linked list. */
    /* Campo de enlace para lista enlazada. */
    struct job *next;
    /* Other fields describing work to be done... */
    /* Otros campos que describen el trabajo a realizar ... */
};

/* A linked list of pending jobs. */
/* Una lista vinculada de trabajos pendientes. */
struct job *job_queue;
/* A mutex protecting job_queue. */
/* Un mutex que protege job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Process queued jobs until the queue is empty. */
/* Procesar trabajos en cola hasta que la cola esté vacía. */
void *thread_function(void *arg)
{
    while (1)
    {
        struct job *next_job;
        /* Lock the mutex on the job queue. */
        /* Bloquea el mutex en la cola de trabajos. */
        pthread_mutex_lock(&job_queue_mutex);
        /* Now it’s safe to check if the queue is empty. */
        /* Ahora es seguro comprobar si la cola está vacía. */
        if (job_queue == NULL)
            next_job = NULL;
        else
        {
            /* Get the next available job. */
            /* Obtén el siguiente trabajo disponible. */
            next_job = job_queue;
            /* Remove this job from the list. */
            /* Eliminar este trabajo de la lista. */
            job_queue = job_queue->next;
        }
        /* Unlock the mutex on the job queue because we’re done with the
        queue for now. */
        /* Desbloquea el mutex en la cola de trabajos porque hemos terminado con la cola por ahora. */
        pthread_mutex_unlock(&job_queue_mutex);
        /* Was the queue empty? If so, end the thread. */
        /* ¿Estaba la cola vacía? Si es así, termine el hilo. */
        if (next_job == NULL)
            break;
        /* Carry out the work. */
        /* Realizar el trabajo. */
        process_job(next_job);
        /* Clean up. */
        /* Limpiar. */
        free(next_job);
    }
    return NULL;
}