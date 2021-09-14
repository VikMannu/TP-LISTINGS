//Listing 4.14 (condvar.c) Control a Thread Using a Condition Variable

#include <pthread.h>
#include <stdio.h>

int thread_flag;
pthread_cond_t thread_flag_cv;
pthread_mutex_t thread_flag_mutex;

void do_work();

void initialize_flag()
{
	/* Initialize the mutex and condition variable. */
	/* Inicializa el mutex y la variable de condición. */
	pthread_mutex_init(&thread_flag_mutex, NULL);
	pthread_cond_init(&thread_flag_cv, NULL);
	/* Initialize the flag value. */
	/* Inicializa el valor de la bandera. */
	thread_flag = 0;
}

/* Calls do_work repeatedly while the thread flag is set; blocks if
the flag is clear. */
/* Llama a do_work repetidamente mientras la bandera del hilo está activada; 
bloques si la bandera está limpia. */
void *thread_function(void *thread_arg)
{
	/* Loop infinitely. */
	/* Bucle infinito. */
	while (1)
	{
		/* Lock the mutex before accessing the flag value. */
		/* Bloquea el mutex antes de acceder al valor de la bandera. */
		pthread_mutex_lock(&thread_flag_mutex);
		while (!thread_flag)
			/* The flag is clear. Wait for a signal on the condition
			variable, indicating that the flag value has changed. When the
			signal arrives and this thread unblocks, loop and check the
			flag again. */
			/* La bandera está clara. Espere una señal en la variable de condición, 
			lo que indica que el valor de la bandera ha cambiado. 
			Cuando llega la señal y este hilo se desbloquea, 
			haz un bucle y vuelve a comprobar la bandera. */
			pthread_cond_wait(&thread_flag_cv, &thread_flag_mutex);

		/* When we’ve gotten here, we know the flag must be set. 
		Unlock the mutex. */
		/* Cuando llegamos aquí, sabemos que la bandera debe estar puesta. 
		Desbloquea el mutex. */
		pthread_mutex_unlock(&thread_flag_mutex);
		/* Do some work. */
		/* Haz algo de trabajo. */
		do_work();
	}
	return NULL;
}

/* Sets the value of the thread flag to FLAG_VALUE. */
/* Establece el valor de la bandera del hilo en FLAG_VALUE. */
void set_thread_flag(int flag_value)
{
	/* Lock the mutex before accessing the flag value. */
	/* Bloquea el mutex antes de acceder al valor de la bandera. */
	pthread_mutex_lock(&thread_flag_mutex);
	/* Set the flag value, and then signal in case thread_function is
	blocked, waiting for the flag to become set. However,
	thread_function can’t actually check the flag until the mutex is
	unlocked. */
	/* Establecer el valor de la bandera, y luego señalizar en caso
	de que thread_function esté bloqueado, esperando que la bandera
	se establezca. Sin embargo, thread_function en realidad no puede
	verificar el indicador hasta que se desbloquea el mutex. */
	thread_flag = flag_value;
	pthread_cond_signal(&thread_flag_cv);
	/* Unlock the mutex. */
	/* Desbloquea el mutex. */
	pthread_mutex_unlock(&thread_flag_mutex);
}

void do_work(){ }

int main()
{
	pthread_t thread;
	pthread_create(&thread, NULL, &thread_function, NULL);
	printf("\nHa finalizado la ejecución.\n");
	return 0;
}