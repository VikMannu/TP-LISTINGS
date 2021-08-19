//Listing 2.2 (getopt_long.c) Using getopt_long

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* The name of this program. */
/* El nombre de este programa. */
const char *program_name;

/* Prints usage information for this program to STREAM (typically
stdout or stderr), and exit the program with EXIT_CODE. Does not
return. */
/* Imprime la información de uso de este programa 
en STREAM (normalmente stdout o stderr) y sale 
del programa con EXIT_CODE. No vuelve. */

void print_usage(FILE *stream, int exit_code)
{
    fprintf(stream, "Usage: %s options[inputfile...]\n", program_name);
    fprintf(stream,
        " -h --help Display this usage information.\n"
        " -o --output filename Write output to file.\n"
        " -v --verbose Print verbose messages.\n");
    exit(exit_code);
}

/* Main program entry point. ARGC contains number of argument list
elements; ARGV is an array of pointers to them. */
/* Punto de entrada del programa principal. 
ARGC contiene varios elementos de la lista de argumentos; 
ARGV es una serie de indicadores para ellos. */

int main(int argc, char *argv[])
{
    int next_option;

    /* A string listing valid short options letters. */
    /* Una cadena que enumera letras de opciones cortas válidas. */
    const char *const short_options = "ho : v";

    /* An array describing valid long options. */
    /* Una matriz que describe opciones largas válidas. */
    const struct option long_options[] = {
        { "help", 0, NULL, 'h' },
        { "output", 1, NULL, 'o' },
        { "verbose", 0, NULL, 'v' },
        {NULL, 0, NULL, 0} /* Required at end of array. */
                           /* Requerido al final de la matriz. */
    };

    /* The name of the file to receive program output, or NULL for
    standard output. */
    /* El nombre del archivo para recibir la salida del programa 
    o NULL para la salida estándar. */
    const char *output_filename = NULL;

    /* Whether to display verbose messages. */
    /* Si mostrar mensajes detallados. */
    int verbose = 0;

    /* Remember the name of the program, to incorporate in messages.
    The name is stored in argv[0]. */
    /* Recuerda el nombre del programa, para incorporar en los mensajes. 
    El nombre se almacena en argv [0]. */
    program_name = argv[0];

    do
    {
        next_option = getopt_long(argc, argv, short_options,
                                  long_options, NULL);
        switch (next_option)
        {
        case 'h': /* -h or --help */
            /* User has requested usage information. 
                Print it to standard output, and exit 
                with exit code zero (normal termination). */
            /* El usuario ha solicitado información de uso. 
                Imprima en salida estándar y salga con el 
                código de salida cero (terminación normal). */
            print_usage(stdout, 0);

        case 'o': /* -o or --output */
            /* This option takes an argument, 
                the name of the output file. */
            /* Esta opción toma un argumento, 
                el nombre del archivo de salida. */
            output_filename = optarg;
            break;

        case 'v': /* -v or --verbose */
            verbose = 1;
            break;

        case '?': /* The user specified an invalid option. */
                  /* El usuario especificó una opción no válida. */
            /* Print usage information to standard error, 
                and exit with exit code one 
                (indicating abnormal termination). */
            /* Imprime la información de uso en el error estándar 
                y sale con el código de salida uno 
                (que indica una terminación anormal). */
            print_usage(stderr, 1);

        case -1: /* Done with options. */
            /* Hecho con opciones. */
            break;

        default: /* Something else: unexpected. */
            /* Algo más: inesperado. */
            abort();
        }
    } while (next_option != -1);

    /* Done with options. OPTIND points to first nonoption argument.
    For demonstration purposes, print them if the verbose option was
    specified. */
    /* Hecho con opciones. OPTIND apunta al primer argumento sin opción. 
    Para fines de demostración, imprímalos si se especificó 
    la opción detallada. */
    if (verbose)
    {
        int i;
        for (i = optind; i < argc; ++i)
            printf("Argument: %s\n", argv[i]);
    }

    /* The main program goes here. */
    /* El programa principal va aquí. */
    return 0;
}