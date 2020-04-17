#include "Nodo.h"

Nodo::Nodo(std::wstring pPalabra)
{
	this->palabra = pPalabra;
}

aristaDataType* Nodo::searchArista(std::wstring pPalabra)
{
	for (aristaDataType aristaActual : aristas)
	{
		if (aristaActual.first->palabra == pPalabra)
		{
			return &aristaActual;
		}
	}
	return nullptr;
}

void Nodo::nuevaArista(Nodo* nodoLlegada)
{
	aristaDataType* arista = searchArista(nodoLlegada->palabra);
	if (arista == nullptr)
	{
		aristaDataType nuevaArista = std::make_pair( nodoLlegada, 1 );
		aristas.push_back(nuevaArista);
	}
	else 
	{
		arista->second = arista->second + 1;
	}
}