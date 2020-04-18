#include "Vertice.h"

Vertice::Vertice(std::wstring pPalabra)
{
	this->palabra = pPalabra;
}

void Vertice::nuevaArista(Vertice* nodoLlegada)
{
	//aristaDataType* arista = searchArista(nodoLlegada->palabra);
	NodoArista* arista = aristas.buscarNodo(nodoLlegada->palabra);
	if (arista == nullptr)
	{
		aristas.insertarNodo(nodoLlegada);
	}
	else 
	{
		arista->peso = arista->peso + 1;
		arista->moverNodo();
	}	
}