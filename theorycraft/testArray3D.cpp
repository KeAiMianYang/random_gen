#include <iostream>
#include "PlainArray.h"

int main(int argc, char** argv){
  int dim = 3;
  int sizes[] = {2, 3, 4};

  PlainArray p3(sizes, dim);

  int coord[] = {1, 2, 3};
  p3.set_cell(coord, 8.);
  std::cout << p3.get_cell(coord) << std::endl;
}
