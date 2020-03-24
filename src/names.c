#include "names.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#define STR_LEN 40

char * generate_name(int i){
	char *name = (char*)malloc(sizeof(char)*STR_LEN); //ilosc znakow z malym zapasem
	if(name == NULL){
		perror("Zabraklo pamieci");
		exit( EXIT_FAILURE );
	}
		
	//otrzymanie czasu lokalnego w postaci napisu	
	time_t now = time(0);
	struct tm *myTime = localtime(&now); 
	char date[STR_LEN];
	strncpy(date, asctime(myTime), sizeof(asctime(myTime))-1);        

	char number[2];
	sprintf(number, "%d", i);
	
	strcpy(name, "../dane/");
	strcat(name, date);
	strcat(name, "__");
	strcat(name, number);
	strcat(name, ".png");
	
	char *cleanName = (char*)malloc(sizeof(char)*STR_LEN + 1);
	if(cleanName == NULL){
		perror("Zabraklo pamieci");
		exit( 	EXIT_FAILURE );
	}

	int j = 0;
	for (int n = 0; name[n]!='\0'; n++) {
  		if ((name[n] != ' ') && (name[n] != '\n')) {
    			cleanName[j] = name[n];
    			j++;
  		}
	}
	cleanName[j] = '\0';
	
	free(name);
	
	return cleanName;
			
}
