//Listing 5.10 (socket-server.c) Local Namespace Socket Server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

/* Read text from the socket and print it out. Continue until the
socket closes. Return nonzero if the client sent a “quit”
message, zero otherwise. */
/* Leer texto del conector e imprimirlo. Continúe hasta que 
se cierre el enchufe. Devuelve un valor distinto de cero si el 
cliente envió un mensaje de "salir", cero en caso contrario. */
int server(int client_socket)
{
    while (1)
    {
        int length;
        char *text;
        /* First, read the length of the text message from the socket. If
        read returns zero, the client closed the connection. */
        /* Primero, lea la longitud del mensaje de texto del conector. 
        Si read devuelve cero, el cliente cerró la conexión. */
        if (read(client_socket, &length, sizeof(length)) == 0)
            return 0;
        /* Allocate a buffer to hold the text. */
        /* Asignar un búfer para contener el texto. */
        text = (char *)malloc(length);
        /* Read the text itself, and print it. */
        /* Leer el texto en sí e imprimirlo. */
        read(client_socket, text, length);
        printf("%s\n", text);
        /* Free the buffer. */
        /* Liberar el búfer. */
        free(text);
        /* If the client sent the message “quit,” we’re all done. */
        /* Si el cliente envió el mensaje "salir", hemos terminado. */
        if (!strcmp(text, "quit"))
            return 1;
    }
}

int main(int argc, char *const argv[])
{
    const char *const socket_name = argv[1];
    int socket_fd;
    struct sockaddr_un name;
    int client_sent_quit_message;
    /* Create the socket. */
    /* Crea el socket. */
    socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
    /* Indicate that this is a server. */
    /* Indica que este es un servidor. */
    name.sun_family = AF_LOCAL;
    strcpy(name.sun_path, socket_name);
    bind(socket_fd, &name, SUN_LEN(&name));
    /* Listen for connections. */
    /* Escuche las conexiones. */
    listen(socket_fd, 5);
    /* Repeatedly accept connections, spinning off one server() to deal
    with each client. Continue until a client sends a “quit” message. */
    /* Acepta conexiones repetidamente, haciendo girar un servidor () para 
    tratar con cada cliente. Continúe hasta que un cliente 
    envíe un mensaje de "dejar de fumar". */
    do
    {
        struct sockaddr_un client_name;
        socklen_t client_name_len;
        int client_socket_fd;
        /* Accept a connection. */
        /* Aceptar una conexión. */
        client_socket_fd = accept(socket_fd, &client_name, &client_name_len);
        /* Handle the connection. */
        /* Manejar la conexión. */
        client_sent_quit_message = server(client_socket_fd);
        /* Close our end of the connection. */
        /* Cierre nuestro extremo de la conexión. */
        close(client_socket_fd);
    } while (!client_sent_quit_message);
    /* Remove the socket file. */
    /* Elimina el archivo de socket. */
    close(socket_fd);
    unlink(socket_name);
    return 0;
}