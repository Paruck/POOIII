#include <iostream>
#include <fstream>

char numberArray[4096];
std::ofstream archivoEntrada;

void pushNumbers() {

	archivoEntrada.open("Scores.txt", std::ios::out);
	//Descomentar para escribir el archivo con los datos anteriores
	//archivoEntrada.open("Scores.txt", std::ios::app);
	while (true)
	{
		int indexArray, numero;
		std::cout << "Introduce el espacio de memoria en el que quieres meter el dato: \n";
		std::cin >> indexArray;
		if (indexArray < 0)
			break;
		std::cout << "Introduce los numeros que quieras meter al Array,\n cuando quieras terminar, mete un numero negativo. \n";
		std::cin >> numero;
		if (numero < 0)
			break;
		else
			numero -= 1;

		archivoEntrada <<"Indice de array: " << indexArray  << "\nElemento: "<< numero << "\n";
		numero = numero % 8;
		numberArray[indexArray] = numberArray[indexArray] | (1 << (numero));
	}
		archivoEntrada.close();
}

void searchNumbers() {
	while (true)
	{
		int indexArray, numero;
		std::cout << "Introduce el indice del arreglo en el que quieres buscar: \n";
		std::cin >> indexArray;
		if (indexArray < 0)
			break;
		std::cout << "Introduce el numero que quieres buscar dentro del Array,\n cuando decidas terminar, introduce un numero negativo. \n";
		std::cin >> numero;
		if (numero < 0)
			break;
		else
			numero -= 1;

		numero = numero % 8;
		if ((numberArray[indexArray] & (1 << (numero))))
			std::cout << "El numero si esta dentro del Array.\n";
		else
			std::cout << "El numero no esta dentro del Array.\n";
	}
}

int main(int argv, char** argc) {

	pushNumbers();
	searchNumbers();

	system("Pause");
	return 0;
}