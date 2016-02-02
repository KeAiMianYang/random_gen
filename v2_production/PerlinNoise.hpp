#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP



class Strategy;
class PlainArray;

class PerlinNoise{
public:
static PlainArray* generate_perlinNoise(Strategy strategy, int min, int max, int dimension, int* sizes);
static int* generate_perlinNoise_1D(Strategy strategy, int min, int max, int size);
static int** generate_perlinNoise_2D(Strategy strategy, int min, int max, int sizeX, int sizeY);
static int*** generate_perlinNoise_3D(Strategy strategy, int min, int max, int sizeX, int sizeY, int sizeZ);
private:
static int* convert_one_dim(PlainArray* plainArray);
static int** convert_two_dim(PlainArray* plainArray);
static int*** convert_three_dim(PlainArray* plainArray);
};

class Aaaa{

};

#endif
