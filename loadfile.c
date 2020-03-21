#include<stdio.h>
#include<stdlib.h>
#include"loadfile.h"

id loadfile ( char* fn ){
	FILE *in = fopen( fn, "r" );
	if( in == NULL )
		exit (EXIT_FAILURE);	//error brak sciezki pliku

	id game = malloc (sizeof (inputData_t));
	int n;			//liczba punktow
	int a, b, c;	//zmienne pomocnicze przechowywujace czytane wartosci

	//pierwsze cztery dane niezbedne
	if ( fscanf( in, "%d%d%d%d", &a, &b, &c, &n ) == 4 ){
		game->g = a;
		game->xx = b;
		game->yy = c;
		
		//alokowanie pamieci core dumped so sad
		//game->t = malloc ( sizeof(int) * game->xx * game->yy );
		//game->d = malloc ( sizeof(int) * game->xx * game->yy );

		//zerowanie zawartosci obu tablic
		int i, j;
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
				else 
					exit (EXIT_FAILURE); //error bledne wartosci
			}
			else 
				exit (EXIT_FAILURE); //error bledna liczba danych
		}
	}
	else 
		exit (EXIT_FAILURE); //error bledna liczba danych

	fclose( in );
	return game;
}
