#include <stdio.h>
#include <stdlib.h>		//exit, fopen, malloc, etc
#include <errno.h>		//zmienna errno
#include "loadfile.h"

#define X game->xx 		//LICZBA kolumn - wymiar tablicy zgodny z osia X
#define Y game->yy		//LICZBA rzedow - wymiar tablicy zgodny z osia Y

id loadfile ( char* fn ){
	FILE *in = fopen( fn, "r" );
	if( in == NULL ){
		perror("Nie ma takiego pliku");	
		exit(EXIT_FAILURE);
	}

	id game = malloc ( sizeof (inputData_t) );
	int n;			//liczba punktow
	int a, b, c;	//zmienne pomocnicze przechowywujace czytane wartosci

	//pierwsze cztery dane niezbedne
	if ( fscanf( in, "%d%d%d%d", &a, &b, &c, &n ) == 4 ){

		if ( a < 0 || b < 0 || c < 0 ) {
			errno = 5;
			perror("Bledne wartosci w pliku"); 
			exit ( EXIT_FAILURE );
		}

		game->g = a;
		game->xx = b; //X
		game->yy = c; //Y
		
		//alokowanie pamieci obu tablic
		//game->t (lub d) to wskaznik na tablice wskaznikow wierszy
		int i;
		game->t = malloc( X * sizeof(int*) );
		if (game->t == NULL){
			perror("Zabraklo pamieci"); 	//errno automatycznie przyjmuje odpowiednia wartosc
			exit ( EXIT_FAILURE );
		}
		game->d = malloc( X * sizeof(int*) );
		if (game->d == NULL){
			perror("Zabraklo pamieci"); 
			exit ( EXIT_FAILURE );
		}

   		for( i = 0; i < X; i++){
        	game->t[i] = malloc( Y * sizeof(int) );
			if (game->t[i] == NULL){
				perror("Zabraklo pamieci"); 
				exit ( EXIT_FAILURE );
			}

			game->d[i] = malloc( Y * sizeof(int) );
			if (game->d == NULL){
				perror("Zabraklo pamieci"); 
				exit ( EXIT_FAILURE );
			}

    		}
		
		//zerowanie zawartosci obu tablic
		int j;
		for ( j = 0; j < Y; j++ ){
	            for (i = 0; i < X; i++ ){
        	        game->t[i][j] = 0;
				game->d[i][j] = 0;
            		}
        	}
	
		//czytanie n par wspolrzednych punktow
		while (n--){
			if ( fscanf( in, "%d%d", &a, &b) == 2 ){
				if ( a <= X && b <= Y && a >= 0 && b >= 0)
					game->t[a][b] = 1;
				else {
					errno = 5;
					perror("Bledne wartosci w pliku"); 
					exit ( EXIT_FAILURE );
				}
			}
			else {
				errno = 5;
				perror("Zbyt malo danych"); 
				exit ( EXIT_FAILURE );
			}
		}

	}
	else {
		errno = 5;
		perror("Bledna liczba danych"); 
		exit ( EXIT_FAILURE );
	}

	fclose( in );
	return game;
}

void createoutputfile ( id game ){
	FILE *out = fopen( "wynik.txt", "w" );
	if( out == NULL ){
		perror("Nie udalo sie otworzyc pliku wynik.txt");	
		abort();		//nie exit, poniewaz nie jest to kluczowy modul
	}
	
	fprintf( out, "%d\n%d %d\n", game->g, game->xx, game->yy );

	//zmienne pomocnicze do zliczenia zywych komorek oraz iterowania po tablicy dwuwymiarowej
	int alive_counter = 0, i, j;

	for ( j = 0; j < Y; j++ ){
    	for ( i = 0; i < X; i++ ){
        	if ( game->d[i][j] == 1 )
				alive_counter++;
        }
    }

	fprintf( out, "%d", alive_counter );
	
	int alive = 0;
	for ( j = 0; j < Y; j++ ){
    	for ( i = 0; i < X; i++ ){
        	if ( game->d[i][j] == 1 )
				fprintf( out, "\n%d %d", i, j );
        }
    }

	fclose( out );
}

void releasememory ( id game ){
	int i;
	for ( i = 0; i < X; i++ ){
        free( game->t[i] );
		free( game->d[i] );
    }
    free( game->t );
	free( game->d );
    free( game );
}

