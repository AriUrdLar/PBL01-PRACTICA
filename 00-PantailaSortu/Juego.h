#ifndef JUEGO_H
#define JUEGO_H
#include<stdio.h>
#include<SDL.h>
#include <stdlib.h>
#include<SDL_image.h>
#include <stdbool.h>
#include<string.h>

#pragma region DEFINES
#define WINDOW_WIDTH     1200
#define WINDOW_HEIGHT    800
#define TALE_X 30
#define TALE_Y 30
#define GORA 0
#define BEHERA 1
#define ESKUBI 2
#define EZKERRA 3
#pragma endregion

SDL_Window* window;
SDL_Renderer* renderer;
bool isRunning;
SDL_Texture* irudiak[20];

#pragma region ENUM
typedef enum ORIENTAZIOAK { aurrera, atzera, eskubi, ezker }ORIENTAZIOAK;
typedef enum TERRENOAK { belarzaria, ura, mendia }TERRENOAK;
#pragma endregion
ORIENTAZIOAK orientazioak;
TERRENOAK terrenoak;

#pragma region STRUCT
typedef struct XY
{
	int x, y;
} BI_D_KOORDENADAK;
typedef struct IRUDIAK {
	SDL_Texture* irudiak[4];
	int orientazioa;
	int terrenoMota;

} ORIENTAZIOA;
#pragma endregion
BI_D_KOORDENADAK mapPos, mousePos, infoPos, isometric, cart, persona;
ORIENTAZIOA soldado, orco, terreno, cubo;

#pragma region FUNCTIONS
void init(char* titulo, int xpos, int ypos, int width, int height, bool fullscreen);
void handleEvents();
void update();
void render();
void clean();
void laukia(int x0, int y0, int w, int h, SDL_Rect* laukia);
void Mapa();
void MousePos();
void iso(int x0, int y0);
void cartesian(int isoY, int isoX);
void erakutsiTale(int xmouse, int ymouse);
void irudiakKargatu(SDL_Texture* gotorlekua[], char** link);
void Desplazatu(int x, int y, int orientazioa);
bool running();
SDL_Texture* loadImage(char* file, SDL_Renderer* renderer);
void RangoaIpini(int rango);
void RangoaEzabatu();
#pragma endregion

#endif // !JUEGO_H
