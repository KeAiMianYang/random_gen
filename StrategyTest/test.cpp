#include "User.hpp"
#include "Strategy.hpp"
#include <iostream>

int main(int argc, char** argv){

  User u(*(new StrategySum));

  std::cout << "Sum : " << u.execute(3, 4) << std::endl;

  User v(*(new StrategyMultiply));
  std::cout << "Multiply : " << v.execute(3, 4) << std::endl;

  u.set_strategy(*(new StrategyMultiply));
  std::cout << u.execute(3, 4) << std::endl;

  return 0;
}
