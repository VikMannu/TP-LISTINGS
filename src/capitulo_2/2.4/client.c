//Listing 2.4 (client.c) Part of a Network Client Program

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *server_name = getenv("SERVER_NAME");

    if (server_name == NULL)
        /* The SERVER_NAME environment variable was not set. Use the   default. */
       /* No se estableció la variable de entorno SERVER_NAME. Utilice el predeterminado. */
        server_name = "server.my - company.com";
    printf("accessing server %s\n", server_name);
    /* Access the server here... */
    /* Accede al servidor aquí ... */

    return 0;
}