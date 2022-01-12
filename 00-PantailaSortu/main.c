#include"Juego.h"

int main(int argc, char* argv[])
{
	char* link[20][20] = {
							{"img/GRASS.png","img/WATER.png","img/MOUNTAIN.png","\0"},
							{"img/PERTSONA3.png","img/PERTSONA2.png","img/PERTSONA.png","img/PERTSONA4.png"},
							{"img/ORCO3.png","img/ORCO1.png","img/ORCO2.png","img/ORCO4.png"},
							{"img/ISOTILE_NEO.png","img/ISOTILE1.png","img/RANGO.png","\0"}
						};
	mapPos.x = 500;
	mapPos.y = 1000;
	persona.x = 0;
	persona.y = 0;
	soldado.orientazioa = 0;
	orco.orientazioa = 0;
	init("tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1300, 800, false);

	irudiakKargatu(terreno.irudiak, link[0]);
	irudiakKargatu(soldado.irudiak, link[1]);
	
	irudiakKargatu(orco.irudiak, link[2]);
	irudiakKargatu(cubo.irudiak, link[3]);
	while (isRunning)
	{
		handleEvents();
		update();
		render();
	}
	clean();
	return 0;
}
void irudiakKargatu(SDL_Texture*gotorlekua[] ,char** link) {
	for (int i = 0; i < 4; i++)gotorlekua[i] = loadImage(link[i], renderer);
}
