#include "Generator.hpp"
#include "Strategy.hpp"
#include <iostream>


Generator::Generator(int* sizes, int dimension):
  _tab(sizes, dimension), _strategy(new Strategy), _min(-1), _max(1){
  
  generate(); 
}

double Generator::blank_noise(int* values){
  double output = 0;
  for(int i=0 ; i<_tab.get_dimension() ; ++i){
    output += Generator::random(values[i] + (int)(output*850000));
  }
  return output;
}// double Generator::blank_noise(int* values)

void Generator::set_strategy(Strategy& strategy){
  
  _strategy = &strategy;
}

Strategy Generator::get_strategy(){
  return *_strategy;
}

PlainArray* Generator::get_array(){
  return &_tab;
}

void Generator::display(){
  _tab.display();
}

void Generator::set_range(int min, int max){
  /*
  // assert max > min
  double newRange = (max - min)/2;
  std::cout << newRange << std::endl;
  double newMiddle = min + _range;
  std::cout << newMiddle << std::endl;
  for(int i=0 ; i<_tab.get_total_size() ; ++i){
    std::cout << "i=" << i << ": " << _range/newRange << std::endl;
    _tab.set_cell(i, (_tab.get_cell(i)/(_range/newRange))+(_middle-newMiddle));
  }
  _range = newRange;
  _middle = newMiddle;  
*/
  double diff = (max - min) / (_max - _min);
  for(int i=0 ; i<_tab.get_total_size() ; ++i){
    _tab.set_cell(i, (_tab.get_cell(i) - -min) * diff + min);
  }
}

double Generator::random(int seed){
    seed = (seed<<13) ^ seed;
    seed = (seed * (seed * seed * 15731 + 789221) + 1376312589);
    return 1.0 - (seed & 0x7fffffff) / 1073741824.0;
}// static double PerlinNoise::random(int seed)

void Generator::generate(){
  int* coordinates;
  double value = 0;
  for(int i=0 ; i<_tab.get_total_size() ; ++i){
    coordinates = _tab.get_coordinates(i);
    value = blank_noise(coordinates);
    //    std::cout << "value(" << i <<") = " << value << std::endl;
    //    std::cout << "0: " << coordinates[0] << ", 1: " << coordinates[1] << ", 2: " << coordinates[2] << std::endl;
    _tab.set_cell(coordinates, value);
  }
}

void Generator::execute(){
  //  std::cout << "in PerlinNoise::execute()" << std::endl;
  _strategy->execute(_tab);
  //  std::cout << "out of PerlinNoise::execute()" << std::endl;
}
