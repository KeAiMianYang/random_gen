#ifndef MAPGEN
#define MAPGEN



int* mapgen(void);
int* mapgenleftpref(void);
int* mapgenrightpref(void);
int* mapgenoftenleft(void);
int* mapgenlimit(void);
void print_map(int , int* );
void print_intmap(int, int *);
int* noisemapgenvalleys(void);
int* noisemapgen(void);
void chargTexture(void);



#endif