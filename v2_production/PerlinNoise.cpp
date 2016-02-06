#include "PerlinNoise.hpp"

#include "PlainArray.hpp"
#include "Generator.hpp"
#include "Strategy.hpp"

#include <cstdlib>

PlainArray* PerlinNoise::generate_perlinNoise(Strategy* strategy, int min, int max, int dimension, int* sizes){ // needs to include a library
  Generator g(sizes, dimension);
  g.set_range(min, max);
  g.set_strategy(*strategy);
  g.execute();
  return g.get_array();
}

float* PerlinNoise::generate_perlinNoise_1D(Strategy* strategy, int min, int max, int size){
  PlainArray* p = PerlinNoise::generate_perlinNoise(strategy, min, max, 1, &size);
  return PerlinNoise::convert_one_dim(p);
}
float** PerlinNoise::generate_perlinNoise_2D(Strategy* strategy, int min, int max, int sizeX, int sizeY){
  int sizes[] = {sizeX, sizeY};
  PlainArray* p = PerlinNoise::generate_perlinNoise(strategy, min, max, 2, sizes);
  return PerlinNoise::convert_two_dim(p);
}
float*** PerlinNoise::generate_perlinNoise_3D(Strategy* strategy, int min, int max, int sizeX, int sizeY, int sizeZ){
  int sizes[] = {sizeX, sizeY, sizeZ};
  PlainArray* p = PerlinNoise::generate_perlinNoise(strategy, min, max, 3, sizes);
  return PerlinNoise::convert_three_dim(p);
}

float* PerlinNoise::convert_one_dim(PlainArray* plainArray){
  float* output = (float*) malloc(sizeof(float)*plainArray->get_size(0));
  for(int i=0 ; i<plainArray->get_size(0) ; ++i){
    output[i] = (int) plainArray->get_cell(i);
  }
  return output;
}
float** PerlinNoise::convert_two_dim(PlainArray* plainArray){
  float** output = (float**) malloc(sizeof(float*)*plainArray->get_size(0));
  float* tmp = (float*) malloc(sizeof(float)*plainArray->get_size(1));
  int* dim = (int*) malloc(sizeof(int)*plainArray->get_dimension());
  for(int i=0 ; i<plainArray->get_size(0) ; ++i){
    dim[0] = i;
    for(int j=0 ; j<plainArray->get_size(1) ; ++j){
      dim[1] = j;
      tmp[j] = plainArray->get_cell(dim);
    }
    output[i] = tmp;
  }
  return output;
}
float*** PerlinNoise::convert_three_dim(PlainArray* plainArray){
  float*** output = (float***) malloc(sizeof(float**)*plainArray->get_size(0));
  float** tmp = (float**) malloc(sizeof(float*)*plainArray->get_size(1));
  float* tmp2 = (float*) malloc(sizeof(float)*plainArray->get_size(2));
  int* dim = (int*) malloc(sizeof(int)*plainArray->get_dimension());
  for(int i=0 ; i<plainArray->get_size(0) ; ++i){
    dim[0] = i;
    for(int j=0 ; j<plainArray->get_size(1) ; ++j){
      dim[1] = j;
      for(int k=0 ; k<plainArray->get_size(2) ; ++k){
	dim[2] = k;
	tmp2[k] = plainArray->get_cell(dim);
      }
      tmp[j] = tmp2;
    }
    output[i] = tmp;
  }
  return output;
}
