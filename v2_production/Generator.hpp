#ifndef GENERATOR_HPP
#define GENERATOR_HPP

class Strategy;

#include "PlainArray.hpp"
#include "Strategy.hpp"

class PerlinNoise{
public: // TODO: set as protected
  PlainArray _tab;
  Strategy* _strategy;
  double _middle;
  double _range;
 public:
  PerlinNoise(int* sizes, int dimension);
  double blank_noise(int* values);
  void set_strategy(Strategy& strategy);
  Strategy get_strategy();
  void display();
  void execute();
  void set_range(int min, int max); // TO TEST
  //execute, for strategy
 protected:
  static double random(int seed);
  void generate(); // TO TEST
  //TO IMPROVE, useless memory allocation
};

#endif
