//Listing 4.1 (thread-create.c) Create a Thread

#include <pthread.h>
#include <stdio.h>
/* Prints x’s to stderr. The parameter is unused. Does not return. */
/* Imprime las x en stderr. El parámetro no se utiliza. No vuelve. */
void *print_xs(void *unused)
{
    while (1)
        fputc('x', stderr);
    return NULL;
}

/* The main program. */
int main()
{
    pthread_t thread_id;
    /* Create a new thread. The new thread will run the print_xs
    function. */
    /* Crea un hilo nuevo. El nuevo hilo ejecutará la función print_xs. */
    pthread_create(&thread_id, NULL, &print_xs, NULL);

    /* Print o’s continuously to stderr. */
    /* Imprime o's continuamente a stderr. */
    while (1)
        fputc('o', stderr);
    return 0;
}