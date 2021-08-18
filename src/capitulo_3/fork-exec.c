//Listing 3.4 (fork-exec.c) Using fork and exec Together

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* Spawn a child process running a new program. PROGRAM is the name
of the program to run; the path will be searched for this program.
ARG_LIST is a NULL-terminated list of character strings to be
passed as the program’s argument list. Returns the process ID of
the spawned process. */
/* Genera un proceso hijo que ejecuta un programa nuevo. 
PROGRAMA es el nombre del programa que se ejecutará; 
se buscará la ruta para este programa. 
ARG_LIST es una lista terminada en NULL de cadenas 
de caracteres que se pasarán como lista de argumentos del programa. 
Devuelve el ID de proceso del proceso generado. */
int spawn(char *program, char **arg_list)
{
    pid_t child_pid;
    /* Duplicate this process. */
    /* Duplica este proceso. */
    child_pid = fork();
    if (child_pid != 0)
        /* This is the parent process. */
        /* Este es el proceso principal. */
        return child_pid;
    else
    {
        /* Now execute PROGRAM, searching for it in the path. */
        /* Ahora ejecuta PROGRAM, buscándolo en la ruta. */
        execvp(program, arg_list);

        /* The execvp function returns only if an error occurs. */
        /* La función execvp regresa solo si ocurre un error. */
        fprintf(stderr, "an error occurred in execvp\n");
        abort();
    }
}

int main()
{
    /* The argument list to pass to the “ls” command. */
    /* La lista de argumentos para pasar al comando "ls". */
    char *arg_list[] = {
        "ls", /* argv[0], the name of the program. */ 
        "- l",  
        "/",
        NULL /* The argument list must end with a NULL. */
            /* La lista de argumentos debe terminar con NULL */
    };

    /* Spawn a child process running the “ls” command. Ignore the
    returned child process ID. */
    /* Genera un proceso hijo ejecutando el comando "ls". 
    Ignore el ID de proceso secundario devuelto. */
    spawn("ls", arg_list);
    printf("done with main program\n");

    return 0;
}