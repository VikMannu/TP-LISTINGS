//Listing 5.8 (dup2.c) Redirect Output from a Pipe with dup2

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int fds[2];
    pid_t pid;
    /* Create a pipe. File descriptors for the two ends of the pipe are
    placed in fds. */
    /* Crea una tubería. Los descriptores de archivo para los dos extremos de la tubería se colocan en fds. */
    pipe(fds);
    /* Fork a child process. */
    /* Bifurcar un proceso hijo. */
    pid = fork();
    if (pid == (pid_t)0)
    {
        /* This is the child process. Close our copy of the write end of
        the file descriptor. */
        /* Este es el proceso hijo. Cierre nuestra copia del final de escritura del descriptor de archivo. */
        close(fds[1]);
        /* Connect the read end of the pipe to standard input. */
        /* Conecte el extremo de lectura de la tubería a la entrada estándar. */
        dup2(fds[0], STDIN_FILENO);
        /* Replace the child process with the “sort” program. */
        /* Reemplazar el proceso hijo con el programa "sort". */
        execlp("sort", "sort", 0);
    }
    else
    {
        /* This is the parent process. */
        /* Este es el proceso padre. */
        FILE *stream;
        /* Close our copy of the read end of the file descriptor. */
        /* Cierre nuestra copia del final de lectura del descriptor de archivo. */
        close(fds[0]);
        /* Convert the write file descriptor to a FILE object, and write
        to it. */
        /* Convierta el descriptor del archivo de escritura en 
        un objeto FILE y escriba en él. */
        stream = fdopen(fds[1], "w");
        fprintf(stream, "This is a test.\n");
        fprintf(stream, "Hello, world.\n");
        fprintf(stream, "My dog has fleas.\n");
        fprintf(stream, "This program is great.\n");
        fprintf(stream, "One fish, two fish.\n");
        fflush(stream);
        close(fds[1]);
        /* Wait for the child process to finish. */
        /* Espere a que finalice el proceso hijo. */
        waitpid(pid, NULL, 0);
    }
    return 0;
}