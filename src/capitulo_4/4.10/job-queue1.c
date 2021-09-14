//Listing 4.10 (job-queue1.c) Thread Function to Process Jobs from the Queue

#include <pthread.h>
#include <malloc.h>

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
void process_job(struct job* job_x);

/* A linked list of pending jobs. */
/* Una lista vinculada de trabajos pendientes. */
struct job *job_queue;

/* Process queued jobs until the queue is empty. */
/* Procesar trabajos en cola hasta que la cola esté vacía. */
void *thread_function(void *arg)
{
	while (job_queue != NULL)
	{
		/* Get the next available job. */
		/* Obtén el siguiente trabajo disponible. */
		struct job *next_job = job_queue;
		/* Remove this job from the list. */
		/* Eliminar este trabajo de la lista. */
		job_queue = job_queue->next;
		/* Carry out the work. */
		/* Realizar el trabajo. */
		process_job(next_job);
		/* Clean up. */
		/* Limpiar. */
		free(next_job);
	}
	printf("\nSe han terminado todos los trabajos.\n");
	return NULL;
}


void process_job(struct job* job_x){
	job_x->estado = 0;
}

int main()
{
	job_queue = (struct job*)malloc(sizeof(struct job*));
	job_queue->estado=1;
	job_queue->next=NULL;
	pthread_t thread;
	pthread_create(&thread, NULL, &thread_function, NULL);
	pthread_join(thread, NULL);
	return 0;
}