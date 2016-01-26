#include <iostream>
#include "generator.h"
#include "interpolate.h"

using namespace std;

PerlinNoise::PerlinNoise(int i_maxHeight, int i_maxLength, bool i_isUnsigned, int i_maxLevel, int i_dimension):
a_maxHeight(i_maxHeight), a_maxLength(i_maxLength), a_isUnsigned(i_isUnsigned), a_maxLevel(i_maxLevel), a_dimension(i_dimension){
    /* correspond to
     * a_maxHeight = i_maxHeight;
     * a_maxLength = i_maxLength;
     * a_isUnsigned = i_isUnsigned;
     * a_maxLevel = i_maxLevel;
     * a_dimension = i_dimension;
     */
     
}// PerlinNoise::PerlinNoise(int i_maxHeight, int i_maxLength, bool i_isUnsigned, int i_maxLevel, int i_dimension)

PerlinNoise::~PerlinNoise(){
    
}// PerlinNoise::~PerlinNoise()

int PerlinNoise::get_max_length(){
    return  a_maxLength;
}// int PerlinNoise::get_max_length()

int PerlinNoise::get_max_height(){
    return a_maxHeight;
}// int PerlinNoise::get_max_height()

int PerlinNoise::get_max_level(){
    return a_maxLevel;
}// int PerlinNoise::get_max_level()

bool PerlinNoise::get_is_unsigned(){
    return a_isUnsigned;
}// bool PerlinNoise::get_is_unsigned()

int PerlinNoise::get_dimension(){
    return a_dimension;
}// int PerlinNoise::get_dimension()

double PerlinNoise::rand_noise(int io_seed){
    io_seed = (io_seed<<13) ^ io_seed;
    io_seed = (io_seed * (io_seed * io_seed * 15731 + 789221) + 1376312589);
    return 1.0 - (io_seed & 0x7fffffff) / 1073741824.0;
}// double PerlinNoise::rand_noise(int io_seed)

double PerlinNoise::perlin_noise(int* i_parameters){
    double tmp = 0.;
    for(int i=0 ; i<a_dimension ; ++i){
        tmp = rand_noise(i_parameters[i] + (int)(tmp * NUMBER));
    }
    return tmp;
}// double PerlinNoise::perlin_noise(int* i_parameters)

int PerlinNoise::generate_level(double i_number){
    if(a_isUnsigned && i_number < 0){
        i_number *= -1;
    }
    double tmp = i_number*NUMBER;
    int tmp2 = (int) tmp;
    
    return tmp2 % a_maxLevel;
}// int PerlinNoise::generate_level(double i_number)

int PerlinNoise::generate_level_directly(int* i_parameters){
    return generate_level(perlin_noise(i_parameters));
}// int PerlinNoise::generate_level_directly(int* i_parameters)


/* ============= */
/* PerlinNoise2D */
PerlinNoise2D::PerlinNoise2D(int i_maxHeight, int i_maxLength, bool i_isUnsigned, int i_maxLevel):
PerlinNoise(i_maxHeight, i_maxLength, i_isUnsigned, i_maxLevel, 2){
    
        //dynamic generation of the array
    int* tmp = (int*) malloc(sizeof(int)*a_maxHeight*a_maxLength);
    if((tmp) == NULL){
        cerr << "ERROR: couldn't allocate an array of" << a_maxHeight << "x" << a_maxLength << endl;
        exit(-1);
    }
    if(!(ap_tab = (int**) malloc(sizeof(int*)*a_maxHeight))){
        cerr << "ERROR: couldn't allocate an array of" << a_maxHeight << endl;
        exit(-1);
    }
    for(int i=0 ; i<a_maxHeight ; ++i){
        ap_tab[i] = tmp+i*a_maxLength;
    }
}// PerlinNoise2D::PerlinNoise2D(int i_maxHeight, int i_maxLength, bool i_isUnsigned, int i_maxLevel, int i_dimension)

PerlinNoise2D::~PerlinNoise2D(){
    for(int i=0 ; i<a_maxHeight ; ++i){
        free(ap_tab[i]);
        free(ap_tab);
    }
}// PerlinNoise2D::~PerlinNoise2D()

int** PerlinNoise2D::get_tab(){
    return ap_tab;
}// int** PerlinNoise2D::get_tab()

void PerlinNoise2D::generate_array(){
    int* param = (int*) malloc(sizeof(int)*2);
    for(int i=0 ; i<a_maxHeight ; ++i){
        param[0] = i;
        for(int j=0 ; j<a_maxLength ; ++j){
            param[1] = j;
            int tmp = generate_level_directly(param);
            ap_tab[i][j] = tmp;
        }
    }
    cout << "fin de generate_array" << endl;
}// void PerlinNoise2D::generate_array()

/* ============= */
/* PerlinNoise1D */
PerlinNoise1D::PerlinNoise1D(int i_maxLength, bool i_isUnsigned, int i_maxLevel):
PerlinNoise(0, i_maxLength, i_isUnsigned, i_maxLevel, 1){
    if(!(ap_tab = (int*) malloc(sizeof(int)*a_maxLength))){
        cerr << "ERROR: couldn't allocate an array of" << a_maxLength << endl;
        exit(-1);
    }
}// PerlinNoise1D::PerlinNoise1D(int i_maxLength, bool i_isUnsigned, int i_maxLevel)

PerlinNoise1D::~PerlinNoise1D(){
    free(ap_tab);
}// PerlinNoise1D::~PerlinNoise1D()

int* PerlinNoise1D::get_tab(){
    return ap_tab;
}// int* PerlinNoise1D::get_tab()

void PerlinNoise1D::generate_array(){
    int* param = (int*) malloc(sizeof(int)*1);
    for(int i=0 ; i<a_maxLength ; ++i){
        param[0] = i;
        int tmp = generate_level_directly(param);
        ap_tab[i] = tmp;
    }
    cout << "fin de generate_array" << endl;
    
}// void PerlinNoise1D::generate_array()

void PerlinNoise1D::linear(int t){
    for(int i=0 ; i<a_maxLength-1 ; ++i){
        ap_tab[i] = linear_interpolate(ap_tab[i], ap_tab[i+1], t);
    }
}

void PerlinNoise1D::cosine(int t){
    for(int i=0 ; i<a_maxLength-1 ; ++i){
        ap_tab[i] = cosine_interpolate(ap_tab[i], ap_tab[i+1], t);
    }
}

void PerlinNoise1D::generate_linear(int t){
    for(int i=0 ; i<a_maxLength ; ++i){
        int tmp = generate_level_linear(i, t);
        ap_tab[i] = tmp;
    }
    cout << "fin de generate_array" << endl;
    
}

int PerlinNoise1D::generate_level_linear(int x, int t){
    int param[1] = {x};
    double number = perlin_noise(param);
    if(a_isUnsigned && number < 0){
    number *= -1;
    }
    param[0] = x+1;
    double tmp1 = number*NUMBER;
    number = perlin_noise(param);
    if(a_isUnsigned && number < 0){
    number *= -1;
    }
    double tmp2 = number*NUMBER;
    double tmp3 = linear_interpolate(tmp1, tmp2, t);
    
    int output = (int) tmp3;
    return output % a_maxLevel;
}

/* ================ */
/* PerlinNoiseFixed */
PerlinNoiseFixed::PerlinNoiseFixed(bool i_isUnsigned, int i_maxLevel):
PerlinNoise(MAX_HEIGHT, MAX_LENGTH, i_isUnsigned, i_maxLevel, 2){
    
}// PerlinNoiseFixed::PerlinNoiseFixed(int i_maxLength, bool i_isUnsigned, int i_maxLevel)

PerlinNoiseFixed::~PerlinNoiseFixed(){
    
}// PerlinNoiseFixed::~PerlinNoiseFixed()

void PerlinNoiseFixed::generate_array(){
    int* param = (int*) malloc(sizeof(int)*2);
    for(int i=0 ; i<a_maxHeight ; ++i){
        param[0] = i;
        for(int j=0 ; j<a_maxLength ; ++j){
            param[1] = j;
            int tmp = generate_level_directly(param);
            ap_tab[i][j] = tmp;
        }
    }
    cout << "fin de generate_array" << endl;
    
}// void PerlinNoiseFixed::generate_array()
