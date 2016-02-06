#include "PlainArray.hpp"
#include <iostream>

using namespace RandomMapEngine;

int main(int argc,  char ** argv){
  int s[] = {4, 3};
  int d = 2;
  PlainArray p(s, d);
  
  int a[] = {0, 2};
  p.set_cell(a, 30.4);
  int b[] = {2, 0};
  p.set_cell(b, -30.4);
  std::cout << "value {0, 2} " << p.get_cell(a) << "\nvalue {2, 0} " << p.get_cell(b) << std::endl;
  p.display();
  std::cout << "====GET_COORDINATES====" << std::endl;
  
  int *c = p.get_coordinates(11);
  std::cout << "value " << c[0] << " " << c[1] << " " << c[2]  << std::endl;

  return 0;
}
