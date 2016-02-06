#include "PlainArray.hpp"

using namespace RandomMapEngine;

int main(){
  int s[] = {3, 4};
  Generator p(s, 2);
  int** a = p.convert_two_dim();
}
