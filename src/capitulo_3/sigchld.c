// Listing 3.7 (sigchld.c) Cleaning Up Children by Handling SIGCHLD

#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int signal_number)
{
    /* Clean up the child process. */
    /* Limpiar el proceso hijo. */
    int status;
    wait(&status);
    /* Store its exit status in a global variable. */
    /* Almacena su estado de salida en una variable global. */
    child_exit_status = status;
}

int main()
{
    /* Handle SIGCHLD by calling clean_up_child_process. */
    /* Maneja SIGCHLD llamando a clean_up_child_process. */
    struct sigaction sigchld_action;
    memset(&sigchld_action, 0, sizeof(sigchld_action));
    sigchld_action.sa_handler = &clean_up_child_process;
    sigaction(SIGCHLD, &sigchld_action, NULL);
    /* Now do things, including forking a child process. */
    /* Ahora haga cosas, incluso bifurcar un proceso hijo. */
    /* ... */
    return 0;
}