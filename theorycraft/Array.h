#ifndef ARRAY_H
#define ARRAY_H

template<typename E>
class Array{
 protected:
  E*  _tab;
  int* _sizes;
  int _dimension;
 public:
  Array(int* sizes, int dimension);
  E get_cell(int*  coordinates);
  void set_cell(int* coordinates, E value);
 protected:
  int get_cell_number(int* coordinates);
};

/*
NOT TESTED:
  PlainArray(int* sizes, int dimension);
  int get_cell(int*  coordinates);
  void set_cell(int* coordinates, int value);
TESTED FOR 1D
*/

#endif
