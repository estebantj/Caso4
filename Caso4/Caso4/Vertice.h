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


	std::wstring palabra;
	int peso;
	DoubleCircularList aristas;

	friend class DoubleCircularList;
};

