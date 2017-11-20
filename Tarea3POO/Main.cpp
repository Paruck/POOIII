#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
#include <algorithm>

std::ofstream archivoEntrada;

std::vector <std::vector <int>> vect;


//Convierte enteros en bits y los guarda en un archivo binario.
std::vector< int > get_bits(unsigned long x) {
	archivoEntrada.open("VectorDeBits.bin", std::ios::binary);  
	std::string chars(std::bitset< sizeof(long) * CHAR_BIT >(x).to_string(char(0), char(1)));
	for (int i = 0; i < chars.size(); ++i) {
		archivoEntrada << chars.at(i);
	}
	return std::vector< int >(chars.begin(), chars.end());
}


//Agrega vectores de bits a un vector de vectores.
void agregarElementos(unsigned long x) {
	vect.push_back(get_bits(x));
}

//Imprime el todos los elementos del indice del vector seleccionados.
void buscarElementos(int index) {
	for (int i = 0; i < vect.at(index).size(); i++) {
		std::cout << vect.at(index).at(i);
	}
	std::cout << "\n";
}

//Re asigna el vector seleccionado con otro valor.
void reAsignar(int index, unsigned long x) {
	vect.at(index) = get_bits(x);
}


int main(int argv, char** argc) {

	agregarElementos(1);
	agregarElementos(2);
	agregarElementos(3);
	buscarElementos(0);
	buscarElementos(2);
	buscarElementos(1);
	system("Pause");
	return 0;
}