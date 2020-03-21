#ifndef LOADFILE_H
#define LOADFILE_H

typedef struct {
	int g;				//liczba generacji
	int xx, yy; 		//wymiary planszy
	int t[100][100];	//plansza
	int d[100][100];	//duplikat planszy - zapisywanie nastepnej generacji
} inputData_t, *id;

id loadfile ( char* fn );
//przypisuje zmiennym odpowiednie wartosci 

#endif
