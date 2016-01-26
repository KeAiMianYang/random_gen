#include "Strategy.hpp"

double StrategySum::execute(double x, double y){
  return x+y;
}

double StrategyMultiply::execute(double x, double y){
  return x*y;
}
