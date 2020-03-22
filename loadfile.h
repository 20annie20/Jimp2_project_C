#ifndef LOADFILE_H
#define LOADFILE_H

typedef struct {
	int g;				//liczba generacji
	int xx;				//wymiary planszy
	int yy; 		
	int **t;			//plansza
	int **d;			//duplikat planszy - zapisywanie nastepnej generacji
} inputData_t, *id;

id loadfile ( char* fn );
//przypisuje zmiennym odpowiednie wartosci 

void releasememory ( id game );
//custom zwolnienie pamieci dynamicznej tablicy dwuwymiarowej w strukturze

#endif
