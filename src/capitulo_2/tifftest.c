//Listing 2.9 (tifftest.c) Using libtiff

#include <stdio.h>
#include <tiffio.h>

int main(int argc, char **argv)
{
    TIFF *tiff;
    tiff = TIFFOpen(argv[1], “r”);
    TIFFClose(tiff);
    return 0;
}