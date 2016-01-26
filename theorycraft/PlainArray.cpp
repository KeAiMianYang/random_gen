#include "PlainArray.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

/*
    { U1 = SIZE*x1
    { Un+1 = Un + SIZE * (xn!).size * xn+1
*/

PlainArray::PlainArray(int* sizes, int dimension): _sizes(sizes), _dimension(dimension){
  int sizeArray = 1;
  for(int i=0 ; i<dimension ; ++i){
    sizeArray *= sizes[i];
  }
  _tab = (double*)malloc(sizeof(double) * sizeArray);
}// PlainArray::PlayArray(int* tab, int* sizes, int dimension)

double PlainArray::get_cell(int* coordinates){
  return _tab[get_cell_number(coordinates)];
  // return _tab+numCell WRONG SYNTAX
}

void PlainArray::set_cell(int* coordinates, double value){
  _tab[get_cell_number(coordinates)] = value;
}

int PlainArray::get_cell_number(int* coordinates){
  int numCell = 0;
  int sizeDim = 1;
  for(int i=0 ; i<_dimension ; ++i){
    //numCell += sizeof(int) * coordinates[i] * sizeDim;
    numCell += coordinates[i] * sizeDim;
    sizeDim *= _sizes[i];
  }
  return numCell;
}
