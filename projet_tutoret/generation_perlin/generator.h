#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_HEIGHT 480
#define MAX_LENGTH 640
// les lines than collumns
#define NUMBER 850000

/**
 * Represente un bruit de perlin, crée une carte remplie de façon pseudo aléatoire
 */
class PerlinNoise{
    protected:
        int a_maxHeight;
        int a_maxLength;
        bool a_isUnsigned;
        int a_maxLevel;
        int a_dimension;
    public:
        PerlinNoise(int i_maxHeight, int i_maxLength, bool i_isUnsigned, int i_maxLevel, int i_dimension);
        ~PerlinNoise();
        int get_max_length();
        int get_max_height();
        int get_max_level();
        bool get_is_unsigned();
        int get_dimension();
        //allow to generate a level using perlin noise directly, with any dimension needed
        int generate_level_directly(int* i_parameters);
    protected:
        //Fournit une valeur double aléatoire entre -1 et 1
        double rand_noise(int io_seed);
        double perlin_noise(int* i_parameters);
        int generate_level(double i_number);
};

/**
 * la classe PerlinNoise utilisée pour une carte en deux dimensions
 */
class PerlinNoise2D: public PerlinNoise{
    protected:
        int** ap_tab;
    public:
        PerlinNoise2D(int i_maxHeight, int i_maxLength, bool i_isUnsigned, int i_maxLevel);
        ~PerlinNoise2D();
        int** get_tab();
        //generate an array using perlin noise, but for a two dimensionnal perlin noise
        void generate_array();
};

/**
 * la classe PerlinNoise utilisée pour une carte en une dimensions
 */
class PerlinNoise1D: public PerlinNoise{
    protected:
        int* ap_tab;
    public:
        PerlinNoise1D(int i_maxLength, bool i_isUnsigned, int i_maxLevel);
        ~PerlinNoise1D();
        int* get_tab();
        //generate an array using perlin noise, but for a two dimensionnal perlin noise
        void generate_array();
        void linear(int t);
        void cosine(int t);
        void generate_linear(int t);
    protected:
        int generate_level_linear(int x, int t);
};

/**
 * la classe PerlinNoise utilisée pour une carte en deux dimensions, dont les caleurs sont fixes
 */
class PerlinNoiseFixed: public PerlinNoise{
    public:
        int ap_tab[MAX_HEIGHT][MAX_LENGTH];
    public:
        PerlinNoiseFixed(bool i_isUnsigned, int i_maxLevel);
        ~PerlinNoiseFixed();
        
        //generate an array using perlin noise, but for a two dimensionnal perlin noise
        void generate_array();
};

#endif