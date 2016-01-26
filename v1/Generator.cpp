#include <iostream>
#include "Generator.h"


/*
 * PerlinNoise
 */

PerlinNoise::PerlinNoise(int dimension):
  _dimension(dimension){
}// PerlinNoise::PerlinNoise(int dimension, Strategie strategie)

double PerlinNoise::random(int seed){
    seed = (seed<<13) ^ seed;
    seed = (seed * (seed * seed * 15731 + 789221) + 1376312589);
    return 1.0 - (seed & 0x7fffffff) / 1073741824.0;
}// double PerlinNoise::random(int seed)

double PerlinNoise::blank_noise(int* values){
  double output = 0;
  for(int i=0 ; i<_dimension ; ++i){
    output += PerlinNoise::random(values[i]);
  }
  return output;
}// double PerlinNoise::blank_noise(int* values)

void PerlinNoise::set_strategy(Strategy& strategy){
  _strategy = strategy;
}// void set_strategy(Strategy& strategy)

Strategy& PerlinNoise::get_strategy(){
  return _strategy;
}

/*
 * PerlinNoise1D
 */

PerlinNoise1D::PerlinNoise1D(int size)
  :PerlinNoise(1){
  _size = size;
  this->generate();
}// PerlinNoise1D::PerlinNoise1D(Strategie strategie)

void PerlinNoise1D::generate(){
  for(int i=0 ; i<_size ; ++i){
    this->blank_noise(&i);
  }
}

void PerlinNoise1D::display(){
  for(int i=0 ; i<_size ; ++i){
    std::cout << "[" << _tab[i] << "]";
  }
  std::cout << std::endl;
}

void PerlinNoise1D::execute(double factor){
  _strategy.execute(tab, size, factor);
}
