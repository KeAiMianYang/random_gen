#include "PlainArray.hpp"
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
  _totalSize= sizeArray;
  _tab = (double*)malloc(sizeof(double) * sizeArray);
}// PlainArray::PlayArray(int* tab, int* sizes, int dimension)

double PlainArray::get_cell(int* coordinates){
  return _tab[get_cell_number(coordinates)];
  // return _tab+numCell WRONG SYNTAX
}

double PlainArray::get_cell(int cellNumber){
  return _tab[cellNumber];
}

void PlainArray::set_cell(int* coordinates, double value){
  _tab[get_cell_number(coordinates)] = value;
}

void PlainArray::set_cell(int cellNumber, double value){
  _tab[cellNumber] = value;
}

int PlainArray::get_cell_number(int* coordinates){
  int numCell = 0;
  //  int sizeDim = 1;
  int sizeDim = _totalSize;
  for(int i=0 ; i<_dimension ; ++i){
    sizeDim /= _sizes[i];
    numCell += coordinates[i] * sizeDim;
    //    sizeDim *= _sizes[i];
  }
  return numCell;
}

int PlainArray::get_dimension(){
  return _dimension;
}

int PlainArray::get_size(int dimNum){
  return _sizes[dimNum];
}

int PlainArray::get_total_size(){
  return _totalSize;
}

void PlainArray::display(){
  std::cout << "Array of " << _dimension << "dimensions" << std::endl;
  for(int i=0 ; i<_totalSize ; ++i){
    std::cout << "[" << _tab[i] << "]";
  }
  std::cout << std::endl;
}

int* PlainArray::get_coordinates(int cellNumber){
  //  std::cout << "in get_coordinates()" << std::endl;
  int* coordinates = (int*) malloc(sizeof(int)*_dimension);
  int size = _totalSize;
  //  std::cout << "totalSize " << _totalSize << std::endl;
  for(int i=0 ; i<_dimension ; ++i){
    size /= _sizes[i];
    coordinates[i] = cellNumber / size;
    cellNumber %= size;
    //    std::cout << "i=" << i << " cellNumber " << cellNumber << ", size " << size << ", cellNumber/size " << cellNumber/size << std::endl;
  }
  //  std::cout << "out of get_coordinates()" << std::endl;
  return coordinates;
}
