#include "interpolate.h"
#include <math.h>

double linear_interpolate(double a, double b, double t){
	return (1. - t)*a + t*b;
}
double cosine_interpolate(double a, double b, double t){
	double c = (1 - cos(t*3.1415927))*.5;
	return (1. -c)*a + c*b;
}