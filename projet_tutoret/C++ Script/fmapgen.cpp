//Version c++ 11

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mapgen.h"
#define SIZE 20

using namespace std;

int main(int argc, char** argv){
	srand(time(NULL));
	int i = 0 ;
	while(i < 5){
		print_map(i, mapgen());
		i++;
	}

	cout << endl;
	i = 0;
	srand(time(NULL));
	while(i < 5){
		print_map(i, mapgenlimit());
		i++;
	}
}

//Créer des maps linéaire où des objectifs sont placés au hasard et sont représenté par des 'X'
int * mapgen(){
	

	int * map = (int*) malloc(sizeof(int) * SIZE);

	int pos = rand() % SIZE - 1, i;

	for(i = 0 ; i < SIZE ; i++)	map[i] = 0;
		map[pos] = 1;

	return map;
}

//Préférence de placement des objetctifs sur la gauche
int * mapgenleftpref(void){
	int * map = (int*) malloc(sizeof(int) *SIZE);
	int pos = (rand() % 19) / 2;
	int i ;
	for(i = 0 ; i < SIZE ; i++)	map[i] = 0;
	map[pos] = 1;

	return map;
}

//Préférence de placement des objectifs sur la droite
int * mapgenrightpref(void){
	int * map = (int*) malloc(sizeof(int) *SIZE);
	int pos = ((rand() % 19) / 2) + SIZE/2;
	int i ;
	for(i = 0 ; i < SIZE ; i++)	map[i] = 0;
	map[pos + (SIZE/2)] = 1;

	return map;
}

int * mapgenoftenleft(void){
	int * map = (int *) malloc(sizeof(int) * SIZE);
	int pos = (rand() % 19), i;
	pos = (int)pos * pos /19 ;
	for(i = 0 ; i < SIZE ; i++)	map[i] = 0;
	map[pos] = 1;
	return map;
}

int * mapgenlimit(void){
	int * map = (int *) malloc(sizeof(int) * SIZE);
	int limit = rand() % (SIZE - 1), i;
	int pos = rand() % limit;
	for(i = 0 ; i < SIZE ; i++)	map[i] = 0;
	map[pos] = 1;
	return map;
}

//Permet d'afficher une map
void print_map(int line, int * map){
	int i ;
	cout << line;
	for(i = 0; i < SIZE ; i++){
		string s = map[i] == 0 ? "_" : "X";
		cout << s ;
	}
	cout << endl;
	free(map);
}

