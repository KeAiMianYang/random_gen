#ifndef STRATEGY_H
#define STRATEGY_H


class Strategy{
 public:
  virtual void execute(double* tab, int size, double factor) = 0;
};

#include "Generator.h"

class Strategy1D : public Strategy {
public:
  virtual void execute(double* tab, int size, double factor) = 0;
};

class AffineStrategy1D : public Strategy1D{
public:
  virtual void execute(double* tab, int size, double factor);
};

#endif
