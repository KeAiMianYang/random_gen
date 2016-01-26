#include "Strategy.hpp"
#include "PlainArray.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

bool Strategy::execute(PlainArray& tab){
  std::cout << "ERROR: I AM EXECUTED" << std::endl;
}

/*
bool Strategy1D::execute(PlainArray& tab, int factor){
  std::cout << "in Strategy1D::execute()" << std::endl;
  if(tab.get_dimension() != 1){
    return false;
  }
  int* coo = (int*) malloc(sizeof(int));
  for(int i=0 ; i<tab.get_total_size()-1 ;  ++i){
    *coo = i;
    tab.set_cell(coo, interpolate(tab.get_cell(i), tab.get_cell(i+1), factor));
  }
  std::cout << "out of Strategy1D::execute()" << std::endl;
  return true;
}
*/
bool Strategy1D::execute(PlainArray& tab){
  //  std::cout << "in Strategy1D::execute()" << std::endl;
  if(tab.get_dimension() != 1){
    return false;
  }
  int* coo = (int*) malloc(sizeof(int));
  for(int i=0 ; i<tab.get_total_size()-1 ;  ++i){
    *coo = i;
    tab.set_cell(coo, smooth_noise(tab.get_cell(i)));
  }
  //  std::cout << "out of Strategy1D::execute()" << std::endl;
  return true;
}

double Strategy1D::smooth_noise(double x){
  //Integer part : E(x)
  int int_x = (int) x;
  //Floating part : x - E(x)
  double float_x = x - int_x;
  
  return interpolate(int_x, int_x+1, float_x);
}

double StrategyLinear::interpolate(double a, double b, double factor){
  return (1. - factor)*a + factor*b;
}


double StrategyCosine::interpolate(double a, double b, double factor){
  double c = (1 - cos(factor*M_PI))*.5;
  //  std::cout << "a = " << a << ", c = " << c << std::endl;
  return (1. - c)*a + c*b;
}
