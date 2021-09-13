//Listing 4.4 (primes.c) Compute Prime Numbers in a Thread

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

/* Compute successive prime numbers (very inefficiently). Return the
Nth prime number, where N is the value pointed to by *ARG. */
/* Calcular números primos sucesivos (de manera muy ineficiente). 
Devuelve el número primo N, donde N es el valor al que apunta * ARG. */
void *compute_prime(void *arg)
{
	intptr_t candidate = 2;
	int n = *((int *)arg);
	while (1)
	{
		int factor;
		int is_prime = 1;
		/* Test primality by successive division. */
		/* Prueba de primalidad por división sucesiva. */
		for (factor = 2; factor < candidate; ++factor)
			if (candidate % factor == 0)
			{
				is_prime = 0;
				break;
			}
		/* Is this the prime number we’re looking for? */
		/* ¿Es este el número primo que estamos buscando? */
		if (is_prime)
		{
			if (--n == 0)
				/* Return the desired prime number as the thread return value. */
				/* Devuelve el número primo deseado como valor de retorno del hilo. */
				return (void*) candidate;
		}
		++candidate;
	}
	return NULL;
}

int main()
{
	pthread_t thread;
	int which_prime = 5000;
	int prime;

	/* Start the computing thread, up to the 5,000th prime number. */
	/* Inicie el subproceso de cálculo, hasta el número 5.000 primo. */
	pthread_create(&thread, NULL, &compute_prime, &which_prime);

	/* Do some other work here... */
	/* Wait for the prime number thread to complete, and get the result. */
	/* Haz algún otro trabajo aquí ... */
	/* Espere a que se complete el hilo de números primos y obtenga el resultado. */
	pthread_join(thread, (void*) &prime);

	/* Print the largest prime it computed. */
	/* Imprime el primo más grande que calculó. */
	printf("The %dth prime number is % d.\n", which_prime, prime);
	return 0;
}