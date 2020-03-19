#include<stdio.h>

//tyle wyswietlam (robocze)
#define X 7
#define Y 7

//caly obraz
#define XX 255
#define YY 255

//punkty glidera
#define N 5

//ile chwil
#define T 4

int abs (int x){
    if (x < 0)
        return -x;
    else return x;
}


int main (){

    int tab[XX][YY];
    int dup[XX][YY];
    int x, y;

    int i=0;
    for ( ; i < N; i++ ){
        scanf("%d%d", &x, &y);
        tab[x][y] = 1;
        dup[x][y] = 1;
    }

    for (y = 0; y < X; y++){
        for (x = 0; x < Y; x++){
            printf("%d", dup[x][y]);
        }
        printf("\n");
    }
    printf("\n");



    i = T;
    while (i--){
        for (y = 1; y < Y; y++){
            for (x = 1; x < X; x++){

                int diff = 0, change = 0;

                if (tab[x][y] == 0){
                    if (x < X && abs(tab[x][y]-tab[x+1][y]) == 1)
                        diff += 1;
                    if (y < Y && abs(tab[x][y]-tab[x][y+1]) == 1)
                        diff += 1;
                    if (x > 0 && abs(tab[x][y]-tab[x-1][y]) == 1)
                        diff += 1;
                    if (y > 0 && abs(tab[x][y]-tab[x][y-1]) == 1)
                        diff += 1;
                    if (x < X && y < Y && abs(tab[x][y]-tab[x+1][y+1]) == 1)
                        diff += 1;
                    if (x > 0 && y < Y && abs(tab[x][y]-tab[x-1][y+1]) == 1)
                        diff += 1;
                    if (x < X && y > 0 && abs(tab[x][y]-tab[x+1][y-1]) == 1)
                        diff += 1;
                    if (x > 0 && y > 0 && abs(tab[x][y]-tab[x-1][y-1]) == 1)
                        diff += 1;

                    if (diff == 3)
                        change = 1;
                }
                else {
                    if (x < X && abs(tab[x][y]-tab[x+1][y]) == 1)
                        diff += 1;
                    if (y < Y && abs(tab[x][y]-tab[x][y+1]) == 1)
                        diff += 1;
                    if (x > 0 && abs(tab[x][y]-tab[x-1][y]) == 1)
                        diff += 1;
                    if (y > 0 && abs(tab[x][y]-tab[x][y-1]) == 1)
                        diff += 1;
                    if (x < X && y < Y && abs(tab[x][y]-tab[x+1][y+1]) == 1)
                        diff += 1;
                    if (x > 0 && y < Y && abs(tab[x][y]-tab[x-1][y+1]) == 1)
                        diff += 1;
                    if (x < X && y > 0 && abs(tab[x][y]-tab[x+1][y-1]) == 1)
                        diff += 1;
                    if (x > 0 && y > 0 && abs(tab[x][y]-tab[x-1][y-1]) == 1)
                        diff += 1;

                    if (8-diff == 2 || 8-diff == 3) change = 0;
                    else change = 1;
                }

                if (change){
                    if (tab[x][y] == 0){
                        dup[x][y] = 1;
                    }

                    if (tab[x][y] == 1) {
                        dup[x][y] = 0;
                    }
                }
            }
        }

        //TU MOZNA GENEROWAC PNG////////
        for (y = 0; y < X; y++){
            for (x = 0; x < Y; x++){
                printf("%d", dup[x][y]);
            }
            printf("\n");
        }
        printf("\n");
        ////////////////////////////////

        for (y = 0; y < X; y++){
            for (x = 0; x < Y; x++){
                tab[x][y] = dup[x][y];
            }
        }


    }
    return 0;
}

