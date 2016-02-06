#include <iostream>

#include "Generator.hpp"
#include "Strategy.hpp"
#include "PlainArray.hpp"

using namespace RandomMapEngine;

int main(int argc, char ** argv){
  int s[] = {3, 2};
  Generator p(s, 2);

  std::cout << p._tab.get_cell(3) << ", " << p._tab.get_cell(4) << ", " << p._tab.get_cell(5) << std::endl;
  p.set_range(3, 9);
  std::cout << p._tab.get_cell(3) << ", " << p._tab.get_cell(4) << ", " << p._tab.get_cell(5) << std::endl;
}
