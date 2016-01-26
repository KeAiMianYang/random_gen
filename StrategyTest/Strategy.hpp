#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy{
public:
  virtual double execute(double x, double y)=0;
};

class StrategySum : public Strategy{
public:
  virtual double execute(double x, double y);
};

class StrategyMultiply : public Strategy{
public:
  virtual double execute(double x, double y);
};


#endif
