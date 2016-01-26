#ifndef PLAINARRAY_H
#define PLAINARRAY_H

class PlainArray{
 protected:
  double* _tab;
  int* _sizes;
  int _dimension;
 public:
  PlainArray(int* sizes, int dimension);
  double get_cell(int*  coordinates);
  void set_cell(int* coordinates, double value);
 protected:
  int get_cell_number(int* coordinates);
};

/*
TESTED FOR 1D
*/

#endif
