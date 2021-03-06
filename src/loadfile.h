#ifndef LOADFILE_H
#define LOADFILE_H

typedef struct {
	int g;				//liczba generacji
	int xx;				//rozmiar planszy wzgledem osi ox 
	int yy; 			//rozmiar planszy wzgledem osi oy
	int **t;			//plansza
	int **d;			//duplikat planszy - zapisywanie nastepnej generacji
} inputData_t, *id;

id loadfile ( char* fn );
//przypisuje zmiennym odpowiednie wartosci 

void createoutputfile ( id game );
//tworzy plik analogiczny do pliku wejsciowego, zawierajacy wspolrzedne zywych komorek po minieciu g generacji

void releasememory ( id game );
//zwolnienie pamieci dynamicznej tablicy dwuwymiarowej w strukturze

#endif
