#pragma once
#include "vect2.h"
#include <stack>
enum espacioEnLaMatriz
{
	Pared = 0,
	Camino = 1,
	Salida = 2,
	Visitado = 3,
};


class Personaje
{
private: 
	int						x,
							y;
public:
	std::stack<vect2>		visitados;
	inline void setPosition(int posy, int posx) {
		x = posx;
		y = posy;
	}
	inline int getX() {
		return x;
	}
	int getY() {
		return y;
	}

	bool Arriba(int y, int x);
	bool Abajo(int y, int x);
	bool Derecha(int y, int x);
	bool Izquierda(int y, int x);
	bool Final(int y, int x);


	int Mapa[10][10]
	{
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,2,
		0,0,0,0,1,1,1,1,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		1,1,1,1,1,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
	};
	int mapaVisitado[10][10]
	{
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,2,
		0,0,0,0,1,1,1,1,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		1,1,1,1,1,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
	};


	Personaje();
	~Personaje();
};

