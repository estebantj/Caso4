#pragma once
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>

class Vertice;


class NodoArista
{
public:
	NodoArista(Vertice* llegada);

	NodoArista* siguiente;
	NodoArista* anterior;

	Vertice* arista;
	int peso;

};

class DoubleCircularList
{
public:
	void moverNodo(NodoArista* pNodo);
	void insertarNodo(Vertice* nodoLlegada);
	void imprimirNodos(std::wstring pPalabra);
	NodoArista* buscarNodo(std::wstring pPalabra);

private:
	NodoArista* primero;
	std::unordered_map<std::wstring, NodoArista*> mapaAristasExistentes;
};


class Vertice
{
public:
	Vertice(std::wstring pPalabra);
	void nuevaArista(Vertice* nodoLlegada);

private:

	int poder;
	std::wstring palabra;
	DoubleCircularList aristas;

	friend class DoubleCircularList;
	friend class Estructura;
};

