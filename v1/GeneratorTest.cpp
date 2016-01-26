#include "Generator.h"
#include "Strategy.h"

using namespace std;

int main(int argc, char** argv){
  PerlinNoise1D p1D(4);
  PerlinNoise* p1D2 = new PerlinNoise1D(4);
  p1D.display();

  return 0;
}
