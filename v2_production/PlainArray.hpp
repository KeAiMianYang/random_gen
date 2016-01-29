#ifndef PLAINARRAY_HPP
#define PLAINARRAY_HPP

/*
#include <iterator>

PlainArray(..){
_tab = (double*) malloc(sizeof(double)*dimension);
std::copy(std::begin(sizes), std::end(sizes), std::begin(_tab);
}
*/
/*!
  \file PlainArray.hpp
  \brief A class representing an array the same way no matter it's dimension
 */

class PlainArray{
 protected:
  double* _tab; // the array
  int* _sizes; // TO IMPROVE make a safe copy of the sizes
  int _dimension; // the number of dimensions
  int _totalSize; // the total size of the array
 public:
  //! Creates a new Array
  /*!
    \param sizes an array of int of the size of dimension. Represent the structure of the array -- for an array of [2][3], sizes will have the value [2, 3]
    \param dimension the dimension of the array -- for an array [2][3], dimension will have the value 2
   */
  PlainArray(int* sizes, int dimension);
  //! returns the value of the cell at the coordinates coordinates -- for an array [2][3], coordinates will have the value [x, y]
  double get_cell(int*  coordinates);
  //! returns the value of the cell at the number cellNumber -- for an array [2][3], cellNumber will have the value u
  double get_cell(int cellNumber);
  //! set the value of the cell at the coordinates coordinates -- for an array [2][3], coordinates will have the value [x, y]
  void set_cell(int* coordinates, double value);
  //! returns the value of the cell at the number cellNumber -- for an array [2][3], cellNumber will have the value u
  void set_cell(int cellNumber, double value);
  //! returns the number of dimensions -- for an array [2][3], will return 2
  int get_dimension();
  //! returns the size depending of a dimension -- for an array [2][3], will return 2 if dimNum equals 0, and 3 if dimNum equals 1
  int get_size(int dimNum);
  //! returns the total size of the array -- for an array [2][3], will return 6
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
