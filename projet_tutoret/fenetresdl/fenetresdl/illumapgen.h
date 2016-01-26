#ifndef ILLUMAPGEN
#define ILLUMAPGEN

struct Textures{
	SDL_Renderer* renderer;
	SDL_Texture* ground1;
	SDL_Texture* ground2;
	SDL_Texture* ground3;
	SDL_Texture* ground4;
	SDL_Texture* ground5;
	SDL_Texture* grass1;
	SDL_Texture* grass2;
	SDL_Texture* grass3;
	SDL_Texture* grass4;
	SDL_Texture* grass5;

	int initialiseTextures(SDL_Window*);
	int deleteTextures(void);

};

class Map{
	protected :
		int* currentMap;
		const int MAPSIZE;

	public : 
		Map(const int);
		~Map();
		void deleteMap();
		int getCase(int);
		void initMap(const int);
		void noiseMapGeneration();

	
};

class Fenetre{
	protected :

		
		Textures* textures;
		Map* map;
		const int LENGTH;
		const int HEIGHT;

	public :
		SDL_Window* fenetre;

		Fenetre(const int, const int);
		~Fenetre();
		int initWindow();
		int affiWindow();
		void prepareFen();
		int getCase(int);
};

#endif