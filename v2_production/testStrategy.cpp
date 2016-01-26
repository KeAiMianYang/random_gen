#include "PlainArray.hpp"
#include "Generator.hpp"
#include "Strategy.hpp"

#include <iostream>

int main(int argc, char** argv){
  int sizes[] = {6};
  PerlinNoise perlin(sizes, 1);
  PerlinNoise perlin2(sizes, 1);
  perlin.display();
  StrategyCosine* c = new StrategyCosine;
  perlin.set_strategy(*(c)); // has to "cast" pointer into reference
  perlin.execute();
  std::cout << "StrategyCosine" << std::endl;
  perlin.display();
  
  PerlinNoise perlin3(sizes, 1);
  StrategyLinear* d = new StrategyLinear;
  perlin3.set_strategy(*(d));
  perlin3.execute();
  std::cout << "StrategyLinear" << std::endl;
  perlin3.display();

  return 0;
}
