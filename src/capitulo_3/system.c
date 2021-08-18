//Listing 3.2 (system.c) Using the system Call

#include <stdlib.h>

int main()
{
    int return_value;
    return_value = system("ls - l /");
    return return_value;
}