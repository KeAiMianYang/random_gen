#ifndef GENERATOR_HPP
#define GENERATOR_HPP

class Strategy;

#include "PlainArray.hpp"
#include "Strategy.hpp"

class PerlinNoise{
public: // TODO: set as protected
  PlainArray _tab;
  Strategy* _strategy;
 public:
  PerlinNoise(int* sizes, int dimension);
  double blank_noise(int* values);
  void set_strategy(Strategy& strategy);
  Strategy& get_strategy();
  void display();
  void execute();
  //execute, for strategy
 protected:
  static double random(int seed);
  double perlin(int octaves, double frequency, double persistence, double x); //octaves: number of times the generation is made for a point
  //frequency: the basic frequency for a point
  //persistence: factor to multiply x by
  //x: the point to mesure for the generation
  void generate(); // TO TEST
  //TO IMPROVE, useless memory allocation
};

#endif
