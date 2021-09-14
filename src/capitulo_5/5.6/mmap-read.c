//Listing 5.6 (mmap-read.c) Read an Integer from a Memory-Mapped File, and Double It

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define FILE_LENGTH 0x100

int main(int argc, char *const argv[])
{
    int fd;
    void* file_memory;
    int integer;
    /* Open the file. */
    /* Abre el archivo. */
    fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR);
    /* Create the memory mapping. */
    /* Crea el mapeo de memoria. */
    file_memory = mmap(0, FILE_LENGTH, PROT_READ | PROT_WRITE,
                       MAP_SHARED, fd, 0);
    close(fd);
    /* Read the integer, print it out, and double it. */
    /* Leer el entero, imprimirlo y duplicarlo. */
    sscanf((char *)file_memory, "%d", &integer);
    printf("value: %d\n", integer);
    sprintf((char *)file_memory, "%d\n", 2 * integer);
    /* Release the memory (unnecessary because the program exits). */
    /* Liberar la memoria (innecesario porque el programa sale). */
    munmap(file_memory, FILE_LENGTH);
    return 0;
}