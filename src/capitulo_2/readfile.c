//Listing 2.6 (readfile.c) Freeing Resources During Abnormal Conditions

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *read_from_file(const char *filename, size_t length)
{
    char *buffer;
    int fd;
    ssize_t bytes_read;
    
    /* Allocate the buffer. */
    /* Asignar el búfer. */
    buffer = (char *)malloc(length);

    if (buffer == NULL)
        return NULL;
    /* Open the file. */
    /* Abre el archivo. */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        /* open failed. Deallocate buffer before returning. */
        /* apertura fallida. Desasigne el búfer antes de regresar. */
        free(buffer);
        return NULL;
    }
    
    /* Read the data. */
    /* Leer los datos. */
    bytes_read = read(fd, buffer, length);
    if (bytes_read != length)
    {
        /* read failed. Deallocate buffer and close fd before returning. */
        /* lectura fallida. Desasigne el búfer y cierre fd antes de regresar. */
        free(buffer);
        close(fd);
        return NULL;
    }
    
    /* Everything’s fine. Close the file and return the buffer. */
    /* Todo está bien. Cierre el archivo y devuelva el búfer. */
    close(fd);
    
    return buffer;
}