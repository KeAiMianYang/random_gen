#include <stdio.h>
#include "generator.h"

int main(){
	
	//~ int i=0;
	//~ int j=0;
	//~ int number;
	//~ double pNum;
	//~ int ** tab = (int**) malloc(sizeof(int) * MAX_HEIGHT * MAX_LENGTH);
	int tab[MAX_HEIGHT][MAX_LENGTH];
	if(tab == NULL){
		printf("HODOR");
	}
	
	//~ for(i=0 ; i<MAX_LENGTH ; ++i){
		//~ for(j=0 ; j<MAX_HEIGHT ; ++j){
			//~ number = generate_level(perlin_noise_2d(i, j), 4, 1);
			//~ printf("%d ", number);
		//~ }
		//~ printf("\n");
	//~ }
	generate_array(tab);
	
	return 0;
}