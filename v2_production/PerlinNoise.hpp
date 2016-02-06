#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP

namespace RadomMapEngine {

class Strategy;
class PlainArray;

class PerlinNoise{
public:
static PlainArray* generate_perlinNoise(Strategy* strategy, int min, int max, int dimension, int* sizes);
static float* generate_perlinNoise_1D(Strategy* strategy, int min, int max, int size);
static float** generate_perlinNoise_2D(Strategy* strategy, int min, int max, int sizeX, int sizeY);
static float*** generate_perlinNoise_3D(Strategy* strategy, int min, int max, int sizeX, int sizeY, int sizeZ);
private:
static float* convert_one_dim(PlainArray* plainArray);
static float** convert_two_dim(PlainArray* plainArray);
static float*** convert_three_dim(PlainArray* plainArray);
};

}
#endif
