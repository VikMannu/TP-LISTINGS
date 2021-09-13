//Listing 4.2 (thread-create2.c) Create Two Threads

#include <pthread.h>
#include <stdio.h>

/* Parameters to print_function. */
/* Parámetros para print_function. */
struct char_print_parms
{
    /* The character to print. */
    /* El carácter a imprimir. */
    char character;

    /* The number of times to print it. */
    /* El número de veces que se imprime. */
    int count;
};

/* Prints a number of characters to stderr, as given by PARAMETERS,
which is a pointer to a struct char_print_parms. */
/* Imprime una serie de caracteres en stderr, tal como lo indica PARAMETERS, 
que es un puntero a una estructura char_print_parms. */
void *char_print(void *parameters)
{
    /* Cast the cookie pointer to the right type. */
    /* Lanza el puntero de la cookie al tipo correcto. */
    struct char_print_parms *p = (struct char_print_parms *)parameters;
    int i;
    for (i = 0; i < p->count; ++i)
        fputc(p->character, stderr);
    return NULL;
}

/* The main program. */
int main()
{
    pthread_t thread1_id;
    pthread_t thread2_id;
    struct char_print_parms thread1_args;
    struct char_print_parms thread2_args;

    /* Create a new thread to print 30,000 'x's. */
    /* Crea un nuevo hilo para imprimir 30,000 'x's. */
    thread1_args.character = 'x';
    thread1_args.count = 30000;
    pthread_create(&thread1_id, NULL, &char_print, &thread1_args);

    /* Create a new thread to print 20,000 o's. */
    /* Crea un nuevo hilo para imprimir 20.000 o's. */
    thread2_args.character = 'o';
    thread2_args.count = 20000;
    pthread_create(&thread2_id, NULL, &char_print, &thread2_args);
    printf("\n\n Al agregar este print, probablemente alguno de los hilos imprima algo.\n");
    return 0;
}