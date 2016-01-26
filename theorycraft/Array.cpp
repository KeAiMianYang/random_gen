#include "Array.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

/*
    { U1 = SIZE*x1
    { Un+1 = Un + SIZE * (xn!).size * xn+1
*/
template<typename E>
Array<E>::Array(int* sizes, int dimension): _sizes(sizes), _dimension(dimension){
  int sizeArray = 1;
  for(int i=0 ; i<dimension ; ++i){
    sizeArray *= sizes[i];
  }
  _tab = (E*)malloc(sizeof(E) * sizeArray);
}// Array::Array(int* sizes, int dimension)

template<typename E>
E Array<E>::get_cell(int* coordinates){
  return _tab[get_cell_number(coordinates)];
  // return _tab+numCell WRONG SYNTAX
}// typename E Array::get_cell(int* coordinates)

template<typename E>
void Array<E>::set_cell(int* coordinates, E value){
  _tab[get_cell_number(coordinates)] = value;
}// void Array::set_cell(int* coordinates, typename E value)

template<typename E>
int Array<E>::get_cell_number(int* coordinates){
  int numCell = 0;
  int sizeDim = 1;
  for(int i=0 ; i<_dimension ; ++i){
    //numCell += sizeof(int) * coordinates[i] * sizeDim;
    numCell += coordinates[i] * sizeDim;
    sizeDim *= _sizes[i];
  }
  return numCell;
}// int Array::get_cell_number(int* coordinates)
