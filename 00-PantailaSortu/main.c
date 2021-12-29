#include<stdio.h>
#include<SDL.h>
#include <stdlib.h>
#include<SDL_image.h>
#define WINDOW_WIDTH     500
#define WINDOW_HEIGHT    500


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* lehioa = NULL;
	SDL_Renderer* renderer = NULL;
	int zikloa = 0;
	SDL_Event event;//eventoen estruktura


	//LEHIO BAT SORTZEN DA, TITULO BATEKIN,TAMAINA BATEKIN ETA GERO FLAGS=ZE EZAUGARRIEKIN
	lehioa = SDL_CreateWindow("hola Aritz", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

	//POR LO QUE HE ENTENDIDO RENDER DA PARA MODIFICAR ALGO ORIGINAL, BERAZ HEMEN AURRETIK SORTUTAKO LEHIOARI ONDORENGO PROPIETATEAK APLIKATZEKO ESATEN DA	
	renderer = SDL_CreateRenderer(lehioa, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);

	//HIRU HAUEK BATEA DIJOZTE, PANTALLAN KOLOREA ALDATZEKO= EZDAKIT ZEBA	
	SDL_SetRenderDrawColor(renderer, 0x3b, 0x3b, 0x3b, 0x00);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	//PANTALLA IXTEKO,MINIMIZATZEKO EDO MUGITZEKO
	while (!zikloa)
	{
		//PANTALLA BARRUAN EBENTORENBAT GERTATZEN DEN BITARTEAN
		while (SDL_PollEvent(&event) != 0)//EVENT INIZIATZEKO DERRIGORREZKOA OMEN DA HAU ITEA
		{
			if (event.type == SDL_QUIT)zikloa = 1;
			else if (event.key.keysym.sym == SDLK_ESCAPE)zikloa = 1;// hau dao estruktura baten anidatuaren, anidatuaren..anidatuan.
		}
	}
	SDL_DestroyWindow(lehioa);
	SDL_Quit();

	return 0;
}