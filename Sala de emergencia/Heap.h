#pragma once
#include <iostream>
#include <string>
#include <utility>

//heap de strings
class Heap
{
private:
	//arreglo de strings
	std::pair<std::string,int> * datos;

	void walkUp(size_t index);
	void walkDown(size_t index);

	size_t size;
	size_t count;

public:
	//numero de elementos que contendra el heap];
	Heap(size_t _size);
	~Heap();
	void Queue(std::string dato, int llave);
	std::string Dequeue();

	//temporal, para mostrar el contenido
	void print();

};
