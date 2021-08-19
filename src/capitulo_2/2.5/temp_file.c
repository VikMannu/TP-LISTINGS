//Listing 2.5 (temp_file.c) Using mkstemp

#include <stdlib.h>
#include <unistd.h>

/* A handle for a temporary file created with write_temp_file. In
this implementation, it’s just a file descriptor. */
/* Un identificador para un archivo temporal creado con write_temp_file. 
En esta implementación, es solo un descriptor de archivo. */
typedef int temp_file_handle;

/* Writes LENGTH bytes from BUFFER into a temporary file. The
temporary file is immediately unlinked. Returns a handle to the
temporary file. */
/* Escribe LENGTH bytes desde BUFFER en un archivo temporal. 
El archivo temporal se desvincula inmediatamente. 
Devuelve un identificador al archivo temporal. */
temp_file_handle write_temp_file(char *buffer, size_t length)
{
    /* Create the filename and file. The XXXXXX will be replaced with
    characters that make the filename unique. */
    /* Crea el nombre del archivo y el archivo. 
    El XXXXXX será reemplazado por caracteres 
    que hacen que el nombre de archivo sea único. */
    char temp_filename[] = "/tmp/temp_file.XXXXXX";
    int fd = mkstemp(temp_filename);

    /* Unlink the file immediately, so that it will be removed when the
    file descriptor is closed. */
    /* Desvincula el archivo inmediatamente, para que se elimine 
    cuando se cierre el descriptor del archivo. */
    unlink(temp_filename);

    /* Write the number of bytes to the file first. */
    /* Escriba primero el número de bytes en el archivo. */
    write(fd, &length, sizeof(length));

    /* Now write the data itself. */
    /* Ahora escribe los datos en sí. */
    write(fd, buffer, length);

    /* Use the file descriptor as the handle for the temporary file. */
    /* Utilice el descriptor de archivo como identificador del archivo temporal. */
    return fd;
}

/* Reads the contents of a temporary file TEMP_FILE created with
write_temp_file. The return value is a newly allocated buffer of
those contents, which the caller must deallocate with free.
*LENGTH is set to the size of the contents, in bytes. The
temporary file is removed. */
/* Lee el contenido de un archivo temporal TEMP_FILE 
creado con write_temp_file. El valor de retorno es un 
búfer recién asignado de esos contenidos, 
que la persona que llama debe desasignar de forma gratuita. 
* LENGTH se establece en el tamaño del contenido, en bytes. 
El archivo temporal se elimina. */
char *read_temp_file(temp_file_handle temp_file, size_t *length)
{
    char *buffer;

    /* The TEMP_FILE handle is a file descriptor to the temporary file. */
    /* El identificador TEMP_FILE es un descriptor de archivo para el archivo temporal. */
    int fd = temp_file;

    /* Rewind to the beginning of the file. */
    /* Rebobinar hasta el principio del archivo. */
    lseek(fd, 0, SEEK_SET);

    /* Read the size of the data in the temporary file. */
    /* Leer el tamaño de los datos en el archivo temporal. */
    read(fd, length, sizeof(*length));

    /* Allocate a buffer and read the data. */
    /* Asignar un búfer y leer los datos. */
    buffer = (char *)malloc(*length);
    read(fd, buffer, *length);

    /* Close the file descriptor, which will cause the temporary file to
    go away. */
    /* Cierre el descriptor del archivo, lo que hará que el 
    archivo temporal desaparezca. */
    close(fd);

    return buffer;
}