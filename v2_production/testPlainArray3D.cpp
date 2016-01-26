#include "PlainArray.hpp"
#include <iostream>

int main(int argc,  char ** argv){
  int s[] = {2, 4, 3};
  int d = 3;
  PlainArray p(s, d);
  
  int a[] = {1, 0, 0};
  p.set_cell(a, 30.4);
  int b[] = {0, 0, 1};
  p.set_cell(b, -30.4);
  std::cout << "value {1, 0, 0} " << p.get_cell(a) << "\nvalue {0, 0, 1} " << p.get_cell(b) << std::endl;
  p.display();
  std::cout << "GET_COORDINATES():" << std::endl;
  int *c = p.get_coordinates(6);
  std::cout << "value " << c[0] << " " << c[1] << " " << c[2]  << std::endl;

  return 0;
}
