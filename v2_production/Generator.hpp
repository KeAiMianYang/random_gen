#ifndef GENERATOR_HPP
#define GENERATOR_HPP

/*!
  \file Generator.hpp
  \brief Generator of a Perlin Noise
 */
class Strategy;

#include "PlainArray.hpp"
#include "Strategy.hpp"

class Generator{
public: // TODO: set as protected
  PlainArray _tab;
  Strategy* _strategy;
  double _min;
  double _max;
 public:
  Generator(int* sizes, int dimension); //!< Create an array according to the sizes given, then generate the numbers
  double blank_noise(int* values);
  void set_strategy(Strategy& strategy);
  Strategy get_strategy();
  void display();
  void execute();
  void set_range(int min, int max); // TO TEST
  PlainArray* get_array();
  //execute, for strategy
 protected:
  static double random(int seed);
  void generate(); // TO TEST
  //TO IMPROVE, useless memory allocation
};

#endif
