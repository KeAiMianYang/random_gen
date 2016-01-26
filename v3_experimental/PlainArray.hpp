#ifndef PLAINARRAY_HPP
#define PLAINARRAY_HPP

/*
#include <iterator>

PlainArray(..){
_tab = (double*) malloc(sizeof(double)*dimension);
std::copy(std::begin(sizes), std::end(sizes), std::begin(_tab);
}
*/

class PlainArray{
 protected:
  double* _tab;
  int* _sizes; // TO IMPROVE make a safe copy of the sizes
  int _dimension;
  int _totalSize;
 public:
  PlainArray(int* sizes, int dimension);
  double get_cell(int*  coordinates);
  double get_cell(int cellNumber);
  void set_cell(int* coordinates, double value);
  int get_dimension();
  int get_size(int dimNum);
  int get_total_size();
  void display();
  // TO IMPROVE WITH get_coordinates()
  int* get_coordinates(int cellNumber);
  // TO IMPROVE WITH io parameter
 protected:
  int get_cell_number(int* coordinates);
};

/*
TESTED FOR 1D, 2D, 3D
*/

#endif
