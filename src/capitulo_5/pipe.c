//Listing 5.7 (pipe.c) Using a Pipe to Communicate with a Child Process

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Write COUNT copies of MESSAGE to STREAM, pausing for a second
between each. */
/* Escribe COUNT copias de MESSAGE en STREAM, haciendo una 
pausa de un segundo entre cada una. */
void writer(const char *message, int count, FILE *stream)
{
    for (; count > 0; --count)
    {
        /* Write the message to the stream, and send it off immediately. */
        /* Escribe el mensaje en la transmisión y envíalo de inmediato. */
        fprintf(stream, "%s\n", message);
        fflush(stream);
        /* Snooze a while. */
        /* Posponer un rato. */
        sleep(1);
    }
}

/* Read random strings from the stream as long as possible. */
/* Leer cadenas aleatorias de la secuencia el mayor tiempo posible. */
void reader(FILE *stream)
{
    char buffer[1024];
    /* Read until we hit the end of the stream. fgets reads until
    either a newline or the end-of-file. */
    /* Leer hasta que lleguemos al final de la transmisión. 
    fgets lee hasta una nueva línea o el final del archivo. */
    while (!feof(stream) && !ferror(stream) && fgets(buffer, sizeof(buffer), stream) != NULL)
        fputs(buffer, stdout);
}
int main()
{
    int fds[2];
    pid_t pid;
    /* Create a pipe. File descriptors for the two ends of the pipe are
    placed in fds. */
    /* Crea una tubería. Los descriptores de archivo para los dos 
    extremos de la tubería se colocan en fds. */
    pipe(fds);
    /* Fork a child process. */
    /* Bifurcar un proceso hijo. */
    pid = fork();
    if (pid == (pid_t)0)
    {
        FILE *stream;
        /* This is the child process. Close our copy of the write end of
        the file descriptor. */
        /* Este es el proceso hijo. Cierre nuestra copia del final de 
        escritura del descriptor de archivo. */
        close(fds[1]);
        /* Convert the read file descriptor to a FILE object, and read
        from it. */
        /* Convierte el descriptor de archivo leído en un 
        objeto FILE y lee de él. */
        stream = fdopen(fds[0], "r");
        reader(stream);
        close(fds[0]);
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
        writer("Hello, world.", 5, stream);
        close(fds[1]);
    }
    return 0;
}