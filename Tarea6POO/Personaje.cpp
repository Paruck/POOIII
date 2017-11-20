#include "Personaje.h"


bool Personaje::Arriba(int y, int x)
{
	if (Mapa[y - 1][x] == Camino && mapaVisitado[y - 1][x] != Visitado)
		return true;

	else
		return false;
}

bool Personaje::Abajo(int y, int x)
{
	if (Mapa[y + 1][x] == Camino && mapaVisitado[y + 1][x] != Visitado)
		return true;

	else
		return false;
}

bool Personaje::Derecha(int y, int x)
{
	if (Mapa[y][x + 1] == Camino && mapaVisitado[y][x + 1] != Visitado)
		return true;

	else
		return false;
}

bool Personaje::Izquierda(int y, int x)
{
	if (Mapa[y][x - 1] == Camino && mapaVisitado[y][x - 1] != Visitado)
		return true;

	else
		return false;
}

bool Personaje::Final(int y, int x)
{
	if (Mapa[y][x + 1] == Salida || Mapa[y][x - 1] == Salida ||
		Mapa[y+1][x] == Salida || Mapa[y-1][x] == Salida)
		return true;

	else
		return false;
}

Personaje::Personaje()
{
}


Personaje::~Personaje()
{
}
