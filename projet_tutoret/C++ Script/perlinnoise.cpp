#define SDL_MAIN_HANDLED
#define HEIGHT 640
#define LONG 480
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;


void definirPixel(SDL_Surface* , int , int , Uint32);
void affiche_perlin(int** , SDL_Surface* );

int main(int argc, char** argv)
{ 
    cout << "bonjour" << endl;
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        cout << stdout << endl << "Échec de l'initialisation de la SDL " << SDL_GetError() << endl;
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Perlin",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  640,
                                                                  480,
                                                                  SDL_WINDOW_SHOWN);

        
        if( pWindow )
        {
            SDL_Surface* pSurface = SDL_GetWindowSurface(pWindow);
            SDL_LockSurface(pSurface);
            for(int y = 0 ; y < pSurface->h ;y++)
                {
                    for(int x = 0 ; x < pSurface->w ; x++){
                        definirPixel(pSurface, x, y, (Uint32) 0x88410000);
                    }
                }
            SDL_UnlockSurface(pSurface);
            SDL_UpdateWindowSurface(pWindow);
            SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */
            SDL_DestroyWindow(pWindow);
        }
        else
        {
            cout << stdout << endl << "Échec de l'initialisation de la SDL " << SDL_GetError() << endl;
        }
    }

    SDL_Quit();

    return 0;
}




void affiche_perlin(int** perlin, SDL_Surface* pSurface){
    void* pixels = pSurface->pixels;
    for(int y = 0 ; y < pSurface->h ;y++)
        {
        for(int x = 0 ; x < pSurface->w ; x++){
            switch(perlin[x][y]){
                case 0 : 
                    definirPixel(pSurface,x, y, (Uint32)0x6699ff00);
                    break;

                case 1 : 
                    definirPixel(pSurface,x, y, (Uint32)0x66996600);
                    break;

                case 2 : 
                    definirPixel(pSurface,x, y, (Uint32)0x66660000);
                    break;

                case 3 : 
                    definirPixel(pSurface,x, y, (Uint32)0x58290000);
                    break;
            }

            
        }
    }
}


void definirPixel(SDL_Surface* surface, int x, int y, Uint32 pixel)
{
    int nbOctetsParPixel = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8*) surface->pixels + y * surface->pitch + x * nbOctetsParPixel;
    switch(nbOctetsParPixel)
    {
        case 1:
            *p = pixel;
            break;

        case 2:
            *(Uint16 *)p = pixel;
            break;

        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            }
            else
            {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4:
            *(Uint32 *)p = pixel;
            break;
    }
}


