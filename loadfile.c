#include <stdio.h>
#include <stdlib.h>		//exit, fopen, malloc, etc
#include <errno.h>		//zmienna errno
#include "loadfile.h"


id loadfile ( char* fn ){
	FILE *in = fopen( fn, "r" );
	if( in == NULL ){
		perror( "Nie ma takiego pliku" );	
		exit( EXIT_FAILURE );
	}

	id game = malloc ( sizeof (inputData_t) );
	int n;			//liczba punktow
	int a, b, c;		//zmienne pomocnicze przechowywujace czytane wartosci

	//pierwsze cztery dane niezbedne
	if ( fscanf( in, "%d%d%d%d", &a, &b, &c, &n ) == 4 ){
		game->g = a;
		game->xx = b;
		game->yy = c;
		
		//alokowanie pamieci obu tablic
		//game->t (lub d) to wskaznik na tablice wskaznikow wierszy
		int i;
		game->t = malloc( (game->xx) * sizeof(int*) );
		game->d = malloc( (game->xx) * sizeof(int*) );
   		for( i = 0; i < game->xx; i++){
        		game->t[i] = malloc( game->yy * sizeof(int) );
			game->d[i] = malloc( game->yy * sizeof(int) );
    		}
		
		//zerowanie zawartosci obu tablic
		int j;
		for ( j = 0; j < game->yy; j++ ){
            		for (i = 0; i < game->xx; i++ ){
                		game->t[i][j] = 0;
				game->d[i][j] = 0;
            		}
       		}
	
		//czytanie n par wspolrzednych punktow
		while (n--){
			if ( fscanf( in, "%d%d", &a, &b) == 2 ){
				if ( a <= game->xx && b <= game->yy )
					game->t[a][b] = 1;
				else {
					errno = 5;
					perror( "Bledne wartosci w pliku" ); 
					exit ( EXIT_FAILURE );
				}
			}
			else {
				errno = 5;
				perror( "Zbyt malo danych" ); 
				exit ( EXIT_FAILURE );
			}
		}

	}
	else {
		errno = 5;
		perror( "Bledna liczba danych" ); 
		exit ( EXIT_FAILURE );
	}

	fclose( in );
	return game;
}


void releasememory ( id game ){
	int i;
	for ( i = 0; i < game->xx; i++ ){
        free( game->t[i] );
		free( game->d[i] );
    }
    free( game->t );
	free( game->d );
    free( game );
}

