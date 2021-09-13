//Listing 4.8(cleanup.c)Program Fragment Demonstrating a Thread Cleanup Handler

#include <malloc.h>
#include <pthread.h>

/* Allocate a temporary buffer. */
/* Asignar un búfer temporal. */
void *allocate_buffer(size_t size)
{
    	return malloc(size);
}

/* Deallocate a temporary buffer. */
/* Desasignar un búfer temporal. */
void deallocate_buffer(void *buffer)
{
    	free(buffer);
}

void do_some_work()
{
	/* Allocate a temporary buffer. */
	/* Asignar un búfer temporal. */
	void *temp_buffer = allocate_buffer(1024);

	/* Register a cleanup handler for this buffer, to deallocate it in
	case the thread exits or is cancelled. */
	/* Registra un controlador de limpieza para este búfer, 
	para desasignarlo en caso de que el hilo salga o se cancele. */
	pthread_cleanup_push(deallocate_buffer, temp_buffer);

	/* Do some work here that might call pthread_exit or might be
	cancelled... */

	/* Haga un trabajo aquí que podría llamar a pthread_exit o podría cancelarse ... */
	/* Unregister the cleanup handler. Because we pass a nonzero value,
	this actually performs the cleanup by calling
	deallocate_buffer. */
	/* Anular el registro del controlador de limpieza. Debido a que pasamos 
	un valor distinto de cero, esto en realidad realiza la limpieza llamando a deallocate_buffer. */
	pthread_cleanup_pop(1);
}

int main()
{
	do_some_work();
	printf("\nLa ejecución ha finalizado correctamente.\n");
	return 0;
}