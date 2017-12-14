#include "grafos.h"
int main()
{
	Grafo a;
	Nodo* temp;
	for (int i = 0; i < 10; ++i)
	{
		temp = a.BFS(a.root, i - 1);
		a.AddNodo(&temp, i, 0);
	}

	Graph_SearchDjikstra busqueda(a,0,4);
    return 0;
}

