#include <stdio.h>
#include "loadfile.h"

int main(int argc, char** argv){

    char *filename = argc > 1 ? argv[1] : "glider_test.txt";
    if (filename == NULL)
		return -2;
	
    id gra = loadfile( filename );

	int i, j;
		for ( j = 0; j < gra->yy; j++ ){
            for (i = 0; i < gra->xx; i++ ){
                printf("%d", gra->t[i][j]);
            }
			printf("\n");
        }

            	

    return 0;
}
