//Listing 5.12 (socket-inet.c) Read from a WWW Server

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

/* Print the contents of the home page for the server’s socket.
Return an indication of success. */
/* Imprime el contenido de la página de inicio para el socket 
del servidor. Devuelve una indicación de éxito. */
void get_home_page(int socket_fd)
{
    char buffer[10000];
    ssize_t number_characters_read;
    /* Send the HTTP GET command for the home page. */
    /* Envíe el comando HTTP GET para la página de inicio. */
    sprintf(buffer, "GET /\n");
    write(socket_fd, buffer, strlen(buffer));
    /* Read from the socket. The call to read may not
    return all the data at one time, so keep
    trying until we run out. */
    /* Leer desde el zócalo. Es posible que la llamada 
    a leer no devuelva todos los datos a la vez, 
    así que sigue intentándolo hasta que se acabe. */
    while (1)
    {
        number_characters_read = read(socket_fd, buffer, 10000);
        if (number_characters_read == 0)
            return;
        /* Write the data to standard output. */
        /* Escribe los datos en la salida estándar. */
        fwrite(buffer, sizeof(char), number_characters_read, stdout);
    }
}

int main(int argc, char *const argv[])
{
    int socket_fd;
    struct sockaddr_in name;
    struct hostent *hostinfo;
    /* Create the socket. */
    socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    /* Store the server’s name in the socket address. */
    /* Almacena el nombre del servidor en la dirección del socket. */
    name.sin_family = AF_INET;
    /* Convert from strings to numbers. */
    /* Convertir de cadenas a números. */
    hostinfo = gethostbyname(argv[1]);
    if (hostinfo == NULL)
        return 1;
    else
        name.sin_addr = *((struct in_addr *)hostinfo->h_addr);
    /* Web servers use port 80. */
    /* Los servidores web utilizan el puerto 80. */
    name.sin_port = htons(80);
    /* Connect to the Web server */
    /* Conectarse al servidor web */
    if (connect(socket_fd, &name, sizeof(struct sockaddr_in)) == -1)
    {
        perror("connect");
        return 1;
    }
    /* Retrieve the server’s home page. */
    /* Recupera la página de inicio del servidor. */
    get_home_page(socket_fd);
    return 0;
}