#include "Heap.h"


Heap::Heap(size_t _size)
{
	datos = new std::pair<std::string,int>[_size];
	size = _size;
	count = 0;
}

void Heap::Queue(std::string dato, int llave)
{
	if (count == size)
	{
		std::cout << "Peligro. Heap lleno" << std::endl;
		return;
	}
	//el dato se va directo al sig espacio disponible
	datos[count] = std::pair<std::string,int>(dato,llave);
	//checar si se debe intercambiar con su padre
	walkUp(count);
	count++;
}

std::string Heap::Dequeue()
{
	//tomar el nodo raiz;
	std::string ret = datos[0].first;
	//el ultimo valor es promovido a la raiz
	datos[0] = datos[count - 1];
	//decremententar count
	count--;
	//comprobar que sus hijos no sean menores
	walkDown(0);
	return ret;
}

void Heap::walkUp(size_t idx)
{
	//ya esta en el nodo raiz
	if (idx == 0) return;

	//calcular el padre
	size_t idxpadre = (idx - 1) / 2;

	if (datos[idxpadre].second < datos[idx].second)
	{
		std::pair<std::string, int> temp = datos[idxpadre];
		datos[idxpadre] = datos[idx];
		datos[idx] = temp;
		//revisar que el nodo movido no sea mayor a su padre
		walkUp(idxpadre);
	}
}

void Heap::walkDown(size_t idx)
{
	//calcular los indices de lso hijos
	size_t idxizq = 2 * idx + 1;
	size_t idxder = 2 * idx + 2;

	//si no tiene hijos, terminar
	if (idxizq > count && idxder > count) return;


	size_t idxhijo;
	//ambos existen
	if (idxizq <= count && idxder <= count)
	{
		//determinar el hijo precedente
		if (datos[idxizq].second > datos[idxder].second)
		{
			idxhijo = idxizq;
		}
		else
		{
			idxhijo = idxder;
		}
	}
	else if (idxizq <= count)
	{
		idxhijo = idxizq;
	}
	else if (idxder <= count)
	{
		idxhijo = idxder;
	}

	//comparar con este hijo
	if (datos[idxhijo].second > datos[idx].second)
	{
		std::pair<std::string, int> temp = datos[idxhijo];
		datos[idxhijo] = datos[idx];
		datos[idx] = temp;
		walkDown(idxhijo);
	}

}

void Heap::print()
{
	std::cout << "Contenido del heap:" << std::endl;
	for (size_t i = 0; i < count; i++)
	{
		std::cout << datos[i].first << " " << datos[i].second << std::endl;
	}
}

Heap::~Heap()
{
}