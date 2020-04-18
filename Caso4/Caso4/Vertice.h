#pragma once
#include <string>
#include <vector>
#include <utility>
#include "DoubleCircularList.h"

class Vertice
{
public:
	Vertice(std::wstring pPalabra);
	
	void nuevaArista(Vertice* nodoLlegada);

private:

	aristaDataType* searchArista(std::wstring pPalabra);

	std::wstring palabra;
	int peso;
	//std::vector< aristaDataType > aristas; // Linked list
	DoubleCircularList aristas;

	friend class DoubleCircularList;
};

