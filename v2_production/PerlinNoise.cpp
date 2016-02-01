#include "PerlinNoise.hpp"

#include "PlainArray.hpp"
#include "Generator.hpp"
#include "Strategy.hpp"

PlainArray* PerlinNoise::generate_perlinNoise(Strategy strategy, int min, int max, int dimension, int* sizes){ // needs to include a library
  PlainArray* p = new PlainArray(sizes, dimension);
  return p;
}

int* PerlinNoise::generate_perlinNoise_1D(Strategy strategy, int min, int max, int size){
  PlainArray* p = PerlinNoise::generate_perlinNoise(strategy, min, max, 1, &size);
}
int** PerlinNoise::generate_perlinNoise_2D(Strategy strategy, int min, int max, int sizeX, int sizeY){
  int sizes[] = {sizeX, sizeY};
  PlainArray* p = PerlinNoise::generate_perlinNoise(strategy, min, max, 2, sizes);
}
int*** PerlinNoise::generate_perlinNoise_3D(Strategy strategy, int min, int max, int sizeX, int sizeY, int sizeZ){
  int sizes[] = {sizeX, sizeY, sizeZ};
  PlainArray* p = PerlinNoise::generate_perlinNoise(strategy, min, max, 3, sizes);
}

int* PerlinNoise::convert_one_dim(PlainArray plainArray){
  int* p;
  return p;
}
int** PerlinNoise::convert_two_dim(PlainArray plainArray){
  int** p;
  return p;
}
int*** PerlinNoise::convert_three_dim(PlainArray plainArray){
  int*** p;
  return p;
}
