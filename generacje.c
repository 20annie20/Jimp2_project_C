#include <stdio.h>
#include "loadfile.h" //for id datatype, zawiera w sobie errno
#include "generacje.h"

//rozmiary obrazu
#define X g->xx
#define Y g->yy

//->pomocniczo o jeden mniejsza ramka, by nie wychodzic poza swoja pamiec
#define XX g->xx-1
#define YY g->yy-1

//ile generacji
#define T g->g

//tablice obecna i duplikat, do przechowywania stanu poprzedniego podczas tworzenia nowego
#define tab g->t
#define dup g->d


//dostaje strukture g z wczytanym prawidlowo plikiem
void generacje ( id g ){

    int x, y, i;

    for ( y = 0; y < Y; y++ ){
     	for ( x = 0; x < X; x++ ){
			dup[x][y] = tab[x][y];
            printf( "%d", dup[x][y] );
        }
		printf("\n");
    }
	printf("\n");


    i = T;
    while ( i-- ){
        for ( y = 0; y < Y; y++ ){
            for ( x = 0; x < X; x++ ){
				
                int alive = 0;

                //zliczanie zywych sasiadow
                if ( x < XX ) 
                    alive += tab[x+1][y];
                if ( y < YY ) 
                    alive += tab[x][y+1];
                if ( x > 0 ) 
                    alive += tab[x-1][y];
                if ( y > 0 ) 
                    alive += tab[x][y-1];                        
                if ( x < XX && y < YY ) 
                    alive += tab[x+1][y+1];                        
                if ( x > 0 && y < YY ) 
                    alive += tab[x-1][y+1];
                if ( x < XX && y > 0 )
                    alive += tab[x+1][y-1];
                if ( x > 0 && y > 0 ) 
                    alive += tab[x-1][y-1];

				//ewentualna zmiana stanu obecnej komorki
                if ( tab[x][y] == 0 && alive == 3)
                    dup[x][y] = 1;
                if ( tab[x][y] == 1 && !(alive == 2 || alive == 3) )
                        dup[x][y] = 0;										
						
            }
        }

        //TU MOZNA GENEROWAC PNG na podstawie duplikatu/////////
        for ( y = 0; y < Y; y++ ){
            for ( x = 0; x < X; x++ ){
                printf( "%d", dup[x][y] );
            }
            printf( "\n" );
        }
        printf( "\n" );
        ////////////////////////////////////////////////////////

        for ( y = 0; y < Y; y++ ){
            for ( x = 0; x < X; x++ ){
                tab[x][y] = dup[x][y];
            }
        }
		
    }
}
