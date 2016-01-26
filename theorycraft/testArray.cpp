#include "PlainArray.h"
#include <iostream>

void disp(PlainArray& p);

int main(int argc, char** argv){
  int sizes[] = {3};
  // int* sizes = &3;
  PlainArray p(sizes, 1);
  disp(p);

  std::cout << "TEST GETTER SETTER" << std::endl;
  int coo = 2;
  std::cout << "setter" << std::endl;
  p.set_cell(&coo, 59);
  std::cout << p._tab[2] << std::endl;
  disp(p);
  std::cout << "getter: " << p.get_cell(&coo) << std::endl;
}

void disp(PlainArray& p){
  std:: cout << "disp" << std::endl;
  for(int i=0 ; i<3 ; ++i){
    std::cout << p._tab[i] << "|";
  }
  std::cout << std::endl;
}
