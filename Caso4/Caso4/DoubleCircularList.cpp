#include "Vertice.h"

NodoArista::NodoArista(Vertice* llegada)
{
	this->arista = llegada;
	this->anterior = nullptr;
	this->siguiente = nullptr;
	this->peso = 1;
}

void NodoArista::moverNodo()
{

}

void DoubleCircularList::insertarNodo(Vertice* nodoLlegada)
{
	NodoArista* nuevoNodo = new NodoArista(nodoLlegada);
	if (primero != nullptr) 
	{
		NodoArista* last = primero->anterior;
		nuevoNodo->siguiente = primero;
		nuevoNodo->anterior = last;
		last->siguiente = primero->anterior = nuevoNodo;
		primero = nuevoNodo;
	}
	else
	{
		primero = nuevoNodo;
		primero->anterior = primero->siguiente = primero;
	}
	mapaAristasExistentes.insert({ nodoLlegada->palabra, nuevoNodo });
}

NodoArista* DoubleCircularList::buscarNodo(std::wstring pPalabra)
{
	auto nodoBuscado = mapaAristasExistentes.find(pPalabra);
	if (nodoBuscado != mapaAristasExistentes.end()) 
	{
		return nodoBuscado->second;
	}
	return nullptr;
}

