#ifndef USER_HPP
#define USER_HPP

class Strategy;

class User{
protected:
  Strategy* _strategy;
  //Strategy& _strategy;
public:
  User(Strategy& strategy);
  double execute(double x, double y);
  void set_strategy(Strategy& strategy);
};

#endif
