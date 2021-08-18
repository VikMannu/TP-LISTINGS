//Listing 3.6 (zombie.c) Making a Zombie Process

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;
    /* Create a child process. */
    /* Crea un proceso hijo. */
    child_pid = fork();
    if (child_pid > 0)
    {
        /* This is the parent process. Sleep for a minute. */
        /* Este es el proceso principal. Duerme un minuto. */
        sleep(60);
    }
    else
    {
        /* This is the child process. Exit immediately. */
        /* Este es el proceso hijo. Sal de inmediato. */
        exit(0);
    }
    return 0;
}