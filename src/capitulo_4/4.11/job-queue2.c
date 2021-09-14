//Listing 4.11 (job-queue2.c) Job Queue Thread Function, Protected by a Mutex


//En este ejercicio restamos sucesivamente la variable global
//este trabajo se encola 100000 veces
//y creamos 3 hilos para disminuir la variable
//protegemos la cola y la variable global con mutexs

#include <malloc.h>
#include <pthread.h>
//disminuiremos sucesivamente esta variable, y veremos si al final es 0
int cant = 10000;
struct job
{
    /* Link field for linked list. */
    /* Campo de enlace para lista enlazada. */
    struct job *next;
    /* Other fields describing work to be done... */
    /* Otros campos que describen el trabajo a realizar ... */
    void (*disminuir_nro) (struct job*);
};

/* A linked list of pending jobs. */
/* Una lista vinculada de trabajos pendientes. */
struct job *job_queue;
/* A mutex protecting job_queue. */
/* Un mutex que protege job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

//procesar trabajo
void process_job(struct job * trabajo  ){
    trabajo->disminuir_nro(trabajo);
}

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

//creamos el nodo
struct job * crearNodo(void *trabajo){
    struct job *nuevo=(struct job*)malloc(sizeof(struct job));
    nuevo->disminuir_nro=trabajo;
    nuevo->next=NULL;
    return nuevo;
}

//funcion para agregar trabajos a la lista enlazada
void add_job(struct job **cola,void *trabajo){
    struct job *actual=*cola;
    struct job *nuevo=crearNodo(trabajo);
    while(actual->next != NULL){
        actual=actual->next;
    }
    actual->next=nuevo;
}

//disminuimos la variable global
void disminuir(){
    pthread_mutex_lock (&job_queue_mutex);
    cant--;
    printf("%d\n",cant);
    pthread_mutex_unlock (&job_queue_mutex);
}

//funcion main
int main(){
	pthread_t hilo[3];
    int i=0;
    job_queue=NULL;
    job_queue = crearNodo(disminuir);
    //creamos 10000 trabajos
    for (int i = 0; i < 10000-1; i++)
    {
        add_job(&job_queue,disminuir);
    }    
    //creamos 3 hilos que agarren los trabajos
    for ( i = 0; i < 3; i++)
    {
        pthread_create(&hilo[i], NULL, &thread_function, NULL);
    }
    //hacemos el join
    for ( i = 0; i < 3; i++)
    {
        pthread_join(hilo[i], NULL);
    }
	printf("Cantidad despues de disminuirla 10000 veces: %d", cant);
	return 0;
}



