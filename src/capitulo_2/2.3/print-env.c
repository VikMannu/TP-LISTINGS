//Listing 2.3 ( print-env.c) Printing the Execution Environment

#include <stdio.h>

/* The ENVIRON variable contains the environment. */
/* La variable ENVIRON contiene el entorno. */
extern char **environ;

int main()
{
    char **var;
    for (var = environ; *var != NULL; ++var)
        printf("%s\n", *var);
    return 0;
}