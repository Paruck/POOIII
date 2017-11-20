#include <iostream>
#include "Personaje.h"

int main(int argv, char** argc) {
	Personaje Loco;

	Loco.setPosition(5, 0);

	while (true)
	{
		if (Loco.Mapa[Loco.getY()][Loco.getX()] == Camino)
		{
			if (Loco.Arriba(Loco.getY(), Loco.getX()))
			{
				Loco.visitados.push(vect2(Loco.getX(), Loco.getY()));
				Loco.mapaVisitado[Loco.getY()][Loco.getX()] = 3;
				Loco.setPosition(Loco.getY() - 1, Loco.getX());
				std::cout << "Se movio hacia arriba!\n";
			}
			else if (Loco.Derecha(Loco.getY(), Loco.getX()))
			{
				Loco.visitados.push(vect2(Loco.getX(), Loco.getY()));
				Loco.mapaVisitado[Loco.getY()][Loco.getX()] = 3;
				Loco.setPosition(Loco.getY(), Loco.getX() + 1);
				std::cout << "Se movio hacia la derecha!\n";
			}
			else if (Loco.Abajo(Loco.getY(), Loco.getX()))
			{
				Loco.visitados.push(vect2(Loco.getX(), Loco.getY()));
				Loco.mapaVisitado[Loco.getY()][Loco.getX()] = 3;
				Loco.setPosition(Loco.getY() + 1, Loco.getX());
				std::cout << "Se movio hacia abajo!\n";
			}
			else if (Loco.Izquierda(Loco.getY(), Loco.getX()))
			{
				Loco.visitados.push(vect2(Loco.getX(), Loco.getY()));
				Loco.mapaVisitado[Loco.getY()][Loco.getX()] = 3;
				Loco.setPosition(Loco.getY(), Loco.getX() - 1);
				std::cout << "Se movio hacia la izquierda!\n";
			}
			else if (Loco.Final(Loco.getY(), Loco.getX()))
			{
				std::cout << "Ha llegado a la salida.!!!!!! \n";
				break;
			}
			else
			{
				Loco.setPosition(Loco.visitados.top().y, Loco.visitados.top().x);
				Loco.visitados.pop();
			}
		}
	}
	system("Pause");
	return 0;

}