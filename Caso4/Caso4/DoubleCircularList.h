#pragma once
#include "Vertice.h"
#include <unordered_map>

class NodoArista
{
public:
	NodoArista(Vertice* llegada);

	void moverNodo();

	NodoArista* siguiente;
	NodoArista* anterior;
	
	Vertice* arista;
	int peso;

};

class DoubleCircularList
{
public:
	void insertarNodo(Vertice* nodoLlegada);

	NodoArista* buscarNodo(std::wstring pPalabra);

private:
	NodoArista* primero;
	std::unordered_map<std::wstring, NodoArista*> mapaAristasExistentes;
};

