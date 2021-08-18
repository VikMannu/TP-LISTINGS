//Listing 5.11 (socket-client.c) Local Namespace Socket Client

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

/* Write TEXT to the socket given by file descriptor SOCKET_FD. */
/* Escribe TEXT en el conector proporcionado por el descriptor de archivo SOCKET_FD. */
void write_text(int socket_fd, const char *text)
{
    /* Write the number of bytes in the string, including
    NUL-termination. */
    /* Escribe el número de bytes en la cadena, 
    incluida la terminación NULL. */
    int length = strlen(text) + 1;
    write(socket_fd, &length, sizeof(length));
    /* Write the string. */
    /* Escribe la cadena. */
    write(socket_fd, text, length);
}

int main(int argc, char *const argv[])
{
    const char *const socket_name = argv[1];
    const char *const message = argv[2];
    int socket_fd;
    struct sockaddr_un name;
    /* Create the socket. */
    socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
    /* Store the server’s name in the socket address. */
    /* Almacena el nombre del servidor en la dirección del socket. */
    name.sun_family = AF_LOCAL;
    strcpy(name.sun_path, socket_name);
    /* Connect the socket. */
    connect(socket_fd, &name, SUN_LEN(&name));
    /* Write the text on the command line to the socket. */
    /* Escribe el texto de la línea de comando en el conector. */
    write_text(socket_fd, message);
    close(socket_fd);
    return 0;
}