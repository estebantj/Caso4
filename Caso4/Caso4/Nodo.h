#pragma once
#include <string>
#include <vector>

class Nodo
{
public:
	Nodo(std::wstring pPalabra)
	{
		this->palabra = pPalabra;
	}
	

	void nuevaArista(Nodo* nodoLlegada)
	{

	}

private:
	std::wstring palabra;
	int peso;
	std::vector< std::pair<Nodo*, int> > aristas;
	
};

