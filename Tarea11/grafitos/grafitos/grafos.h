#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <queue>
class Nodo;

class Arista {
public:
	Nodo* vecinos;
	int costos;
	Arista(Nodo*& nodo, int cost) {
		vecinos = nodo;
		costos = cost;
	}
};

class Nodo {
public:
	Nodo() {}
	Nodo(const int& v) :val(v) {
	}
	int val;
	std::vector<Arista> Aristas;
};

class Grafo {
int nodeCount = 0;
public:
	Grafo() {}
	Nodo* root = nullptr;
	int nodecount() { return nodeCount; }
	Nodo* BFS(Nodo* const& r, const int& key)
	{
		if (r == nullptr)
			return nullptr;
		if (r->val == key)
			return r;
		Nodo* val = nullptr;
		for (auto& i : r->Aristas)
			if (i.vecinos->val == key)
				return i.vecinos;
		for (auto& i : r->Aristas)
		{
			val = BFS(i.vecinos, key);
			if (val == nullptr)
				continue;
			if (val->val == key)
				return val;
		}
		return nullptr;
	}
	Nodo* DFS(Nodo* const& r, const int& key)
	{
		if (r == nullptr)
			return nullptr;
		if (r->val == key)
			return r;
		Nodo* val = nullptr;
		for (auto& i : r->Aristas)
		{
			val = BFS(i.vecinos, key);
			if (val == nullptr)
				continue;
			if (val->val == key)
				return val;
		}
		return nullptr;
	}
	void AddNodo(Nodo** nodo, const int& key, const int& costo)
	{
		nodeCount++;
		if (root == nullptr)
		{
			root = new Nodo(key);
			*nodo = root;
			return;
		}
		if (*nodo == nullptr)
		{
			*nodo = new Nodo(key);
			return;
		}
		(*nodo)->Aristas.push_back(Arista(*nodo, key));
	}

};

class Graph_SearchDjikstra
{
public:
	typedef Arista Edge;
	typedef Nodo Node;
	typedef Grafo graphtype;
	//referencia al grafo que se le va a buscar una ruta
	graphtype *graph;

	//vector que contiene las rutas mas cortas encontradas al momento,
	//es decir, el arbold erutas mas cortas (shortest path tree SPT)
	std::vector< const Edge*> shortestPathTree;

	//mejor costo encontrado hasta el momento para cada nodo
	//el tamano es igual al numero de nodos
	std::vector<float> costToNode;

	//vector de nodos padre que apuntan a un nodo pero no has sido
	//agregados aun al SPT
	std::vector< const Edge*> searchFrontier;

	//nodos destino y origen
	int source;
	int target;

	//constructor
	Graph_SearchDjikstra(graphtype& _graph,
		int _source,
		int _target
		) : 
		shortestPathTree(graph->nodecount()),
		searchFrontier(graph->nodecount()),
		costToNode(graph->nodecount()),
		source(_source),
		target(_target)
	{
		graph = &_graph;
		search();
	}

	Graph_SearchDjikstra() = delete;

	//retorna una lista ligada con la ruta encontrada 
	std::list<int> GetPathToTarget();


	//busqueda de ruta 
	void search()
	{
		//crear una cola de prioridad con tamano maximo del num de nodos 
		std::priority_queue < float > pq;
		
		//agregar el origen a la cola
		pq.push(source);

		//mientras la cola no este vacia
		while (!pq.empty())
		{
			//jalar el costo mas bajo de la cola, en este caso, el nodo al que apunta
			//el arista con el costo mas bajo
			int nextClosestNode = pq.top();
			pq.pop();

			//mover el arista de la frontera al SPT
			shortestPathTree[nextClosestNode] = searchFrontier[nextClosestNode];
			//si el nodo es el destino, terminar
			if (nextClosestNode == target) return;

			//determinar si la ruta al nodo es mejor que la que ya se tenia
			//para cada arista conectado al nodo
			for (int i = nextClosestNode; i < graph->root->Aristas.size(); ++i)
			{
				//acumular el costo
				float newCost = costToNode[nextClosestNode] + graph->root->Aristas.at(i).costos; //

																		//si esta arista nunca habia estado en la frontera, anotar
																		//el costo de alcanzar el nodo alq ue apunta, despues agregar el
																		//arista a la frontera y el nodo destino a la cola de prioridad
				if (searchFrontier[pE->to] == 0)
				{
					costToNode[pE->to] = newCost;
					pq.push(pE->to);
					searchFrontier[pE->to] = pE;
				}
				//probar si el costo de alcanzar el destino a traves de este nodo es mas 
				//barato que la ruta mas barata encontrada hasta el momento.
				else if (newCost < costToNode[pE->to] && shortestPathTree[pe->to] == 0)
				{
					costToNode[pE->to] newCost;
					searchFrontier[pE->to] = pE;
					//ajustar la prioridad
					pq.chagePriority(pE->to);
				}
			}
		}


	}
};