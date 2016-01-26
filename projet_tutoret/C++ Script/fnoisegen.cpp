#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "mapgen.h"
#define MAPSIZE 40

using namespace std;





int main(int argv, char ** argc){
	int i;

	srand(time(NULL));
	for(i = 1 ; i <= 5 ; i++){
		print_intmap(i , noisemapgen());
		
	}
	cout << endl << endl;
	for(i = 1 ; i <= 5 ; i++){
		print_intmap(i , noisemapgenvalleys());
		
	}

}

int* noisemapgen(void){
	int * map = (int*) calloc(MAPSIZE, sizeof(int));
	
	for(int i = 0 ; i < MAPSIZE ; i++){
		map[i] = (rand() % 3) + 1;
	}
	return map;
}

int* noisemapgenvalleys(void){
	int* map = (int *) calloc(MAPSIZE, sizeof(int));
	for(int i = 0 ; i < MAPSIZE ; i++){
		int random = (rand() % 3) + 1;
		map[i] = rand() % random ;
	}
	return map;
}

void print_intmap(int line, int* map){
	for(int i = 0; i < MAPSIZE ; i++){
		cout << map[i] ;
	}
	cout << endl;
	free(map);
}