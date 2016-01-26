#include "Strategy.h"
#include "Generator.h"
#include <cmath>

/*
AffineStrategy
*/

/*
double linear_interpolate(double a, double b, double t){
	return (1. - t)*a + t*b;
}
*/

//TODO: find a way to use PerlinNoise & co in Strategy & co
//SOLUTION1: using namespaces, with two headers, one "hidden" containing _tab and _size, they will be publics but hidden from the public
//SOLUTION2: using pointers in methods:
// http://stackoverflow.com/questions/13844129/friend-class-with-inheritance
//SOLUTION3: redo everything: _tab is a double*, size is an int*, friends will work on a virtual method and inheritance
void AffineStrategy1D::execute(double* tab, int size, double factor){
  for(int i=0 ; i<size-1 ; ++i){
    tab[i] = (1. - factor)*tab[i] + tab[i+1];
  }
}
