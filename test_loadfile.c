#include <stdio.h>
#include "loadfile.h"

//wypisuje cala zawartosc tablicy na podstawie pliku	
int main( int argc, char** argv ){

    char *filename = argc > 1 ? argv[1] : "glider_test.txt";
    id gra = loadfile( filename );

	int i, j;
	for ( j = 0; j < gra->yy; j++ ){
        for ( i = 0; i < gra->xx; i++ ){
            printf( "%d", gra->t[i][j] );
        }
		printf("\n");
	}

	releasememory( gra );
    return 0;
}
