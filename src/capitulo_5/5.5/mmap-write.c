//Listing 5.5 (mmap-write.c) Write a Random Number to a Memory-Mapped File

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define FILE_LENGTH 0x100

/* Return a uniformly random number in the range [low,high]. */
/* Devuelve un número uniformemente aleatorio en el rango [bajo, alto]. */
int random_range(unsigned const low, unsigned const high)
{
    unsigned const range = high - low + 1;
    return low + (int)(((double)range) * rand() / (RAND_MAX + 1.0));
}

int main(int argc, char *const argv[])
{
    int fd;
    void *file_memory;
    /* Seed the random number generator. */
    /* Sembrar el generador de números aleatorios. */
    srand(time(NULL));
    /* Prepare a file large enough to hold an unsigned integer. */
    /* Prepara un archivo lo suficientemente grande para contener un entero sin signo. */
        
    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    lseek(fd, FILE_LENGTH + 1, SEEK_SET);
    write(fd, "", 1);
    lseek(fd, 0, SEEK_SET);
    /* Create the memory mapping. */
    /* Crea el mapeo de memoria. */
    file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    /* Write a random integer to memory-mapped area. */
    /* Escribe un número entero aleatorio en el área asignada a la memoria. */
    int random_value = random_range(-100, 100);
    sprintf((char *)file_memory, "%d\n", random_value);
    /* Release the memory (unnecessary because the program exits). */
    /* Liberar la memoria (innecesario porque el programa sale). */
    printf("El número que se escribió es: %d\n", random_value);
    munmap(file_memory, FILE_LENGTH);
    return 0;
}