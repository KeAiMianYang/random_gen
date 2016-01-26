#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "illumapgen.h"


using namespace std;

int main(int argc, char** argv)
{ 
    Fenetre launcher(640,480);
    //launcher.affiWindow();
    return 0;

}


Fenetre::Fenetre (const int LENGTH,const int HEIGHT) : LENGTH(LENGTH), HEIGHT(HEIGHT){
    if(this->initWindow() == -1) system ("exit");
    
}
Fenetre::~Fenetre(){
    textures->deleteTextures();
    delete(map);
}

int Fenetre::initWindow(){
    
        if(SDL_Init(SDL_INIT_VIDEO) != 0){
            cout << stdout << "Échec de l'initialisation de la SDL \n" << SDL_GetError();
            return -1; 
        }
        else{

            //cette fenetre ne peut être utilisé et nous sommes toujours en train de rechercher pour l'utilisation de se pointeur donne une segmentation fault.
         //cela doit provenir du fonctionnement de la SDL et sa gestion des droits d'accès.
            fenetre = SDL_CreateWindow("Affichage map générée", SDL_WINDOWPOS_UNDEFINED,
                                                                SDL_WINDOWPOS_UNDEFINED,
                                                                LENGTH,
                                                                HEIGHT,
                                                                SDL_WINDOW_SHOWN);

            
        if(fenetre){
        //SDL_RenderPresent(textures->renderer);
        //SDL_Delay(3000);
            if(textures->initialiseTextures(fenetre) == -1) system("exit");
    
            map = new Map(LENGTH / 20);
            map->noiseMapGeneration();
            SDL_DestroyWindow(fenetre);
        }
        else
        {
                cout << stderr <<"Erreur de création de la fenêtre: "<< SDL_GetError();
                return -1;
        }
    

        SDL_Quit();
        return 0;
    }
}

int Fenetre::affiWindow(){
    return 0;
    
}

void Fenetre::prepareFen(){
    int mapcase = 0;
    for(int i = 0 ; i < LENGTH ; i+=20){
        for(int j = HEIGHT - 200; j < HEIGHT ; j+=20){
            int groundvalue = (rand()% 5) + 1;
            SDL_Rect dest = {i, j, 20, 20};
            switch(groundvalue){
            case 1:
                SDL_RenderCopy(textures->renderer, textures->ground1, NULL, &dest);
            break;
            case 2:
                SDL_RenderCopy(textures->renderer, textures->ground2, NULL, &dest);
            break;
            case 3:
                SDL_RenderCopy(textures->renderer, textures->ground3, NULL, &dest);
            break;
            case 4:
                SDL_RenderCopy(textures->renderer, textures->ground4, NULL, &dest);
            break;
            case 5:
                SDL_RenderCopy(textures->renderer, textures->ground5, NULL, &dest);
            break;
            }
        }

        SDL_Rect dest = {i, HEIGHT -220, 20, 20};
        SDL_RenderCopy(textures->renderer, textures->grass3, NULL, &dest);
        
        switch(map->getCase(mapcase)){
            case 1 :
                dest.y -= 20;
                SDL_RenderCopy(textures->renderer, textures->grass3, NULL, &dest);
                break;
            case 2 :
                for(int k = 0 ; k < 3 ; k++){
                    dest.y-=20;
                    SDL_RenderCopy(textures->renderer, textures->grass3, NULL, &dest);
                }
                break;
            case 3:
                for(int k = 0 ; k < 5 ; k++){
                    dest.y-=20;
                    SDL_RenderCopy(textures->renderer, textures->grass3, NULL, &dest);
                }
                break;
        }
        mapcase++;
    }
}

Map::Map(const int MAPSIZE) : MAPSIZE(MAPSIZE){
    //Première initialisation du tableau représentant la map
    initMap(MAPSIZE);
}

Map::~Map(){
    if(currentMap != NULL)  free(currentMap);
}

void Map::deleteMap(){
    free(currentMap);
}

int Map::getCase(int index){
    return currentMap[index];
}

void Map::initMap(int length){
    currentMap = NULL;
    currentMap = static_cast<int*>(calloc(length, sizeof(int)));
}

void Map::noiseMapGeneration(){
    srand(time(NULL));
    for(int i = 0 ; i < MAPSIZE ; i++){
        int random = (rand() % 3) + 1;
        currentMap[i] = (rand() % random ) + 1;
    }    
}

int Textures::initialiseTextures(SDL_Window* pWindow){
    
    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

    if(renderer != NULL){
        //Chargement sprite ground1 en mémoire vidéo
        SDL_Surface* pSprite = SDL_LoadBMP("/../Texture/ground1.bmp");
        ground1 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement ground1
        if(ground1 == NULL){
            cout<<"Erreur dans le chargement du sprite ground1 :\n" << SDL_GetError();
            return -1;
        } 
      
        //Chargement sprite ground2 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/ground2.bmp");
        ground2 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement ground2
        if(ground2 == NULL){
            cout<<"Erreur dans le chargement du sprite ground2 :\n" << SDL_GetError();
            return -1;
        }

        //Chargement sprite ground3 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/ground3.bmp");
        ground3 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement ground3
        if(ground3 == NULL){
            cout<<"Erreur dans le chargement du sprite ground3 :\n" << SDL_GetError();
            return -1;
        }

        //Chargement sprite ground4 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/ground4.bmp");
        ground4 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement ground4
        if(ground4 == NULL){
            cout<<"Erreur dans le chargement du sprite ground4 :\n" << SDL_GetError();
            return -1;
        }

        //Chargement sprite ground5 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/ground5.bmp");
        ground5 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement ground5
        if(ground5 == NULL){
            cout<<"Erreur dans le chargement du sprite ground5 :\n" << SDL_GetError();
            return -1;
        }

        //Chargement sprite grass1 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/grass1.bmp");
        grass1 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement grass1
        if(grass1 == NULL){
            cout<<"Erreur dans le chargement du sprite grass1 :\n" << SDL_GetError();
            return -1;
        }

        //Chargement sprite grass2 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/grass2.bmp");
        grass2 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement grass2
        if(grass2 == NULL){
            cout<<"Erreur dans le chargement du sprite grass2 :\n" << SDL_GetError();
            return -1;
        }

        //Chargement sprite grass3 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/grass3.bmp");
        grass3 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement grass3
        if(grass3 == NULL){
            cout<<"Erreur dans le chargement du sprite grass3 :\n" << SDL_GetError();
            return -1;
        }


        //Chargement sprite grass4 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/grass4.bmp");
        grass4 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement grass4
        if(grass4 == NULL){
            cout<<"Erreur dans le chargement du sprite grass4 :\n" << SDL_GetError();
            return -1;
        }

        //Chargement sprite grass5 en mémoire vidéo
        pSprite = SDL_LoadBMP("/../Texture/grass5.bmp");
        grass5 = SDL_CreateTextureFromSurface(renderer, pSprite);
        SDL_FreeSurface(pSprite);
        //Vérification du chargement grass5
        if(grass5 == NULL){
            cout<<"Erreur dans le chargement du sprite grass5 :\n" << SDL_GetError();
            return -1;
    }
    else return -1;
    }
    return 0;
}

int Textures::deleteTextures(){
    if(renderer != NULL && ground1 != NULL && ground2 != NULL && ground3 != NULL && ground4 != NULL && ground5 != NULL &&
        grass1 != NULL && grass2 != NULL && grass3 != NULL && grass4 != NULL && grass5 != NULL)
    {
        SDL_DestroyTexture(ground1);
        SDL_DestroyTexture(ground2);
        SDL_DestroyTexture(ground3);
        SDL_DestroyTexture(ground4);
        SDL_DestroyTexture(ground5);

        SDL_DestroyTexture(grass1);
        SDL_DestroyTexture(grass2);
        SDL_DestroyTexture(grass3);
        SDL_DestroyTexture(grass4);
        SDL_DestroyTexture(grass5);

        SDL_DestroyRenderer(renderer);

        return 0;
    }
    else return -1;
}
