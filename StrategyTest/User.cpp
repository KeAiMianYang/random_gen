#include "User.hpp"
#include "Strategy.hpp"


User::User(Strategy& strategy):_strategy(&strategy)
			       //_strategy(strategy)
{}

double User::execute(double x, double y){
  return _strategy->execute(x, y);
  //  return _strategy.execute(x, y);
}

void User::set_strategy(Strategy& strategy){
  //  _strategy = strategy;
  _strategy = &strategy;
}
