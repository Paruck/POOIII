#pragma once

#include "ofMain.h"
#include "ofPath.h"
#include <vector>
#include <iostream>
#include <string>

class Nodo;

class Arista {
public:
	std::vector<Nodo*> vecinos;
	std::vector<int> costos;
};

class Nodo {
public:
	Nodo() {}
	Nodo(const int& v) :val(v) {
		figura.circle(posx = rand() % 200, posy = rand() % 200, 10);
	}
	int val, posx, posy;
	ofPath figura;
	Arista Aristas;
};

class Grafo {
public:
	Grafo() {}
	Nodo* root = nullptr;
	Nodo* BFS(Nodo* const& r, const int& key)
	{
		if (r == nullptr)
			return nullptr;
		if (r->val == key)
			return r;
		Nodo* val = nullptr;
		for (auto& i : r->Aristas.vecinos)
			if (i->val == key)
				return i;
		for (auto& i : r->Aristas.vecinos)
		{
			val = BFS(i, key);
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
		for (auto& i : r->Aristas.vecinos)
		{
			val = BFS(i, key);
			if (val == nullptr)
				continue;
			if (val->val == key)
				return val;
		}
		return nullptr;
	}
	void AddNodo(Nodo** nodo, const int& key, const int& costo)
	{
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
		(*nodo)->Aristas.vecinos.push_back(new Nodo(key));
		(*nodo)->Aristas.costos.push_back(costo);
	}

	void drawGrafo(Nodo* nodo)
	{
		nodo->figura.draw();
		for (auto i : nodo->Aristas.vecinos)
		{
			ofDrawLine(nodo->posx, nodo->posy, i->posx, i->posy);
			drawGrafo(i);
		}
	}
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		Grafo a;
};
