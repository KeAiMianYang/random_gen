#ifndef INTERPOLATE_H
#define INTERPOLATE_H

class Interpolate{
	public:
	virtual double interpolate(double a, double b, double t) = 0;
};

// TODO: linear_interpolate, cosine_interpolate, cubic_interpolate, smooth_noise
//la variable t est controlée
double linear_interpolate(double a, double b, double t);
double cosine_interpolate(double a, double b, double t);
#endif