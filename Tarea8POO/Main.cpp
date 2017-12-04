#include <iostream>
#include <string>
#include <fstream>
class Node
{
public:
	std::string		dato;
	Node*			father = nullptr;
	Node*			left = nullptr;
	Node*			right = nullptr;

	inline Node(): father(nullptr), left(nullptr), right(nullptr) {}
	inline Node(Node* const& copy){ this->dato = copy->dato; }
	inline Node(const std::string& val):dato(val) {}
	inline Node(const std::string& val, Node* const& padre) :Node(val) { this->father = padre; }
	inline friend std::ostream& operator << (std::ostream& lhs, const Node& rhs) { return lhs << rhs.dato; }
	inline friend std::istream& operator >> (std::istream & lhs, Node& rhs){ return lhs >> rhs.dato; }
			
};

class Arbol {
public:
	Node *root = nullptr;
	void Insert(const std::string &v, Node * & root, Node* parent = nullptr);
	void Print(Node* root);
	void serchString(Node* root, const std::string &v);
	inline bool Vacio(Node* actual) { return actual == nullptr ? true : false; }
	inline Arbol():root(nullptr){}

};

void Arbol::Insert(const std::string &v, Node *& root, Node * parent)
{
	if (root == nullptr) {
		root = new Node(v, parent);
		return;
	}

	else if (v < root->dato) Insert(v, (root->left), root);

	else if (v > root->dato) Insert(v, (root->right), root);


}

void Arbol::Print(Node * root)
{
	if (root != nullptr) {
		Print(root->left);
		std::cout << *root << "\n";
		Print(root->right);
	}

	
}

void Arbol::serchString(Node * root, const std::string & v)
{
		Node* actual = root;

		while (!Vacio(actual)) {
			if (v == actual->dato) {
				std::cout << "Dato: " << v << " fue encontrado en el arbol.\n";
				return;
			}
			else if (v < actual->dato) {
				actual = actual->left;
			}
			else if (v > actual->dato) {
				actual = actual->right;
			}
		}
		std::cout << "Dato: " << v << " no fue encontrado en el arbol.\n"; 
}


int main(int argc, char** argv) {

	std::ifstream archivoEntrada;
	Arbol l;



	//l.Insert("Arbol", root);
	//l.Insert("Beso", root);
	//l.Insert("Cama", root);
	//l.Insert("Dedo", root);
	//l.Insert("Emilo", root);
	//l.Insert("Fe", root);
	Node* nuevo = nullptr;

	archivoEntrada.open("Arbol.txt", std::ios::in);

	if (archivoEntrada.is_open()) {
		while (!archivoEntrada.eof()) {
			std::string Dato;
			std::getline(archivoEntrada, Dato);
			l.Insert(Dato, nuevo);
			std::cout << Dato << "\n";
		}
	}
	else
	{
		return -1;
	}
	archivoEntrada.close();
	l.Print(nuevo);
	l.serchString(nuevo, "Arbol");
	l.serchString(nuevo, "Perro");
	l.serchString(nuevo, "Emilio");

	system("PAUSE");
	return 0;
}

