#include <stdio.h>
#include "loadfile.h"
#include "generacje.h"

//domyślnie wykorzystuje plik glider_test.txt
int main( int argc, char** argv ){

    char *filename = argc > 1 ? argv[1] : "glider_test.txt";
    id gra = loadfile( filename );

	generacje( gra );

	releasememory( gra );
    return 0;
}
