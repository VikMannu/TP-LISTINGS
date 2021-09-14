//Listing 4.12 (job-queue3.c) Job Queue Controlled by a Semaphore

#include <malloc.h>
#include <pthread.h>
#include <semaphore.h>

struct job
{
	/* Link field for linked list. */
	/* Campo de enlace para lista enlazada. */
	struct job *next;
	/* Other fields describing work to be done... */
	/* Otros campos que describen el trabajo a realizar ... */
	int estado;
};

void process_job(struct job* job_x);

/* A linked list of pending jobs. */
/* Una lista vinculada de trabajos pendientes. */
struct job *job_queue;

/* A mutex protecting job_queue. */
/* Un mutex que protege job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

/* A semaphore counting the number of jobs in the queue. */
/* Un semáforo que cuenta el número de trabajos en la cola. */
sem_t job_queue_count;

/* Perform one-time initialization of the job queue. */
/* Realiza una inicialización única de la cola de trabajos. */
void initialize_job_queue()
{
	/* The queue is initially empty. */
	/* La cola está inicialmente vacía. */
	job_queue = NULL;
	/* Initialize the semaphore which counts jobs in the queue. Its
	initial value should be zero. */
	/* Inicializa el semáforo que cuenta los trabajos en la cola.
	Su valor inicial debe ser cero. */
	sem_init(&job_queue_count, 0, 0);
}

/* Process queued jobs until the queue is empty. */
/* Procesar trabajos en cola hasta que la cola esté vacía. */
void *thread_function(void *arg)
{
	while (1)
	{
		struct job *next_job;
		/* Wait on the job queue semaphore. If its value is positive,
		indicating that the queue is not empty, decrement the count by
		1. If the queue is empty, block until a new job is enqueued. */
		/* Espera en el semáforo de la cola de trabajos. Si su valor es positivo,
		lo que indica que la cola no está vacía, disminuya el recuento en 1.
		Si la cola está vacía, bloquee hasta que se coloque un nuevo trabajo en la cola. */
		sem_wait(&job_queue_count);

		/* Lock the mutex on the job queue. */
		/* Bloquea el mutex en la cola de trabajos. */
		pthread_mutex_lock(&job_queue_mutex);

		/* Because of the semaphore, we know the queue is not empty. Get
		the next available job. */
		/* Debido al semáforo, sabemos que la cola no está vacía.
		Consiga el próximo trabajo disponible. */
		next_job = job_queue;

		/* Remove this job from the list. */
		/* Eliminar este trabajo de la lista. */
		job_queue = job_queue->next;

		/* Unlock the mutex on the job queue because we’re done with the
		queue for now. */
		/* Desbloquea el mutex en la cola de trabajos porque hemos
		terminado con la cola por ahora. */
		pthread_mutex_unlock(&job_queue_mutex);

		/* Carry out the work. */
		/* Realizar el trabajo. */
		process_job(next_job);
		/* Clean up. */
		free(next_job);
	}
	return NULL;
}

/* Add a new job to the front of the job queue. */
/* Agregar un nuevo trabajo al principio de la cola de trabajos. */
void enqueue_job(/* Pass job-specific data here... */) /* Pasar datos específicos del trabajo aquí ... */
{
	struct job *new_job;
	/* Allocate a new job object. */
	/* Asignar un nuevo objeto de trabajo. */
	new_job = (struct job *)malloc(sizeof(struct job));
	/* Set the other fields of the job struct here... */
	/* Lock the mutex on the job queue before accessing it. */
	/* Establezca los otros campos de la estructura del trabajo aquí ... */
	/* Bloquear el mutex en la cola de trabajos antes de acceder a él. */
	pthread_mutex_lock(&job_queue_mutex);
	/* Place the new job at the head of the queue. */
	/* Coloca el nuevo trabajo al principio de la cola. */
	new_job->next = job_queue;
	job_queue = new_job;
	/* Post to the semaphore to indicate that another job is available. If
	threads are blocked, waiting on the semaphore, one will become
	unblocked so it can process the job. */
	/* Publicar en el semáforo para indicar que hay otro trabajo disponible.
	Si los hilos están bloqueados, esperando en el semáforo,
	uno se desbloqueará para que pueda procesar el trabajo. */
	sem_post(&job_queue_count);
	/* Unlock the job queue mutex. */
	/* Desbloquea el mutex de la cola de trabajos. */
	pthread_mutex_unlock(&job_queue_mutex);
}

void process_job(struct job* job_x){
	job_x->estado = 0;
}

int main()
{
	job_queue = (struct job*)malloc(sizeof(struct job*));
	job_queue->estado = 1;
	job_queue->next=NULL;
	pthread_t thread;
	pthread_create(&thread, NULL, &thread_function, NULL);
	printf("\nSe han terminado todos los trabajos.\n");
	return 0;
}