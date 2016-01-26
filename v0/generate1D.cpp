#include <iostream>
#include "generator.h"
#include "interpolate.h"

using namespace std;

int main(int argc, char** argv){
	PerlinNoise1D* perlin = new PerlinNoise1D(10, 1, 500);
	perlin->generate_array();
	int* tab = perlin->get_tab();
	
	for(int i=0 ; i<perlin->get_max_length() ; ++i){
		cout << "[" << tab[i] << "]";
	}
	cout << endl;
	delete(perlin);
	
	perlin = new PerlinNoise1D(10, 1, 500);
	perlin->generate_linear(0.);
	for(int i=0 ; i<perlin->get_max_length() ; ++i){
		cout << "[" << tab[i] << "]";
	}
	cout << endl;
	
	return 0;
}