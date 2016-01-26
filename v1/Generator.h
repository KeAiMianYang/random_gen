#ifndef GENERATOR_H
#define GENERATOR_H


#include "Strategy.h"
class PerlinNoise {
  // friend class Strategy;
 protected:
  int _dimension;
  Strategy& _strategy;
  
 public:
  PerlinNoise(int dimension);
  double blank_noise(int* values);
  void set_strategy(Strategy& strategy);
  Strategy& get_strategy();
  virtual void display() = 0;
  virtual void execute(double factor) = 0;
 protected:
  static double random(int seed);
  virtual void generate() = 0;
};

class PerlinNoise1D: public PerlinNoise {
  // friend class Strategy;
protected:
  double* _tab;
  int _size;
public:
  PerlinNoise1D(int size);
  virtual void display();
  virtual void execute(double factor);
protected:
  virtual void generate();
};


#endif
