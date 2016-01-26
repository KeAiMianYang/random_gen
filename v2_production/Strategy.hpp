#ifndef STRATEGY_HPP
#define STRATEGY_HPP
#include "PlainArray.hpp"

class Strategy{
 public:
  virtual bool execute(PlainArray& tab);
};

class Strategy1D : public Strategy{
 public:
  virtual bool execute(PlainArray& tab);
  //not tested
 protected:
  double smooth_noise(double x);
  virtual double interpolate(double a, double b, double factor)=0;
};

class StrategyLinear : public Strategy1D{
 protected:
  virtual double interpolate(double a, double b, double factor);
  //not tested
};

class StrategyCosine : public Strategy1D{
 protected:
  virtual double interpolate(double a, double b, double factor);
  //not tested
};

#endif
