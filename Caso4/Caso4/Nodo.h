#pragma once
#include <string>
#include <vector>
#include <utility>

class Nodo;

typedef std::pair<Nodo*, int> aristaDataType;

class Nodo
{
public:
	Nodo(std::wstring pPalabra);
	
	void nuevaArista(Nodo* nodoLlegada);

private:

	aristaDataType* searchArista(std::wstring pPalabra);

	std::wstring palabra;
	int peso;
	std::vector< aristaDataType > aristas;
};

