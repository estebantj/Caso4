#include "Vertice.h"

Vertice::Vertice(std::wstring pPalabra)
{
	this->palabra = pPalabra;
}

void Vertice::nuevaArista(Vertice* nodoLlegada)
{
	NodoArista* arista = aristas.buscarNodo(nodoLlegada->palabra);
	if (arista == nullptr)
	{
		aristas.insertarNodo(nodoLlegada);
	}
	else 
	{
		arista->peso = arista->peso + 1;
		aristas.moverNodo(arista);
	}	
}

NodoArista::NodoArista(Vertice* llegada)
{
	this->arista = llegada;
	this->anterior = nullptr;
	this->siguiente = nullptr;
	this->peso = 1;
}

void DoubleCircularList::moverNodo(NodoArista* pNodo)
{
	/*
	while (pNodo->peso > pNodo->siguiente->peso && pNodo->siguiente != primero);
	{
		NodoArista* anterior = pNodo->anterior;
		NodoArista* siguiente = pNodo->siguiente;

		anterior->siguiente = siguiente;
		siguiente->anterior = anterior;
		pNodo->anterior = siguiente;
		pNodo->siguiente = siguiente->siguiente;
		siguiente->siguiente->anterior = pNodo;
		
		if (primero == pNodo) {
			primero = pNodo->anterior;
		}
	}
	*/
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

// El parametro es la palabra del nodo al que se le van a imprimir sus relaciones
void DoubleCircularList::imprimirNodos(std::wstring pPalabra)
{
	if (primero != nullptr)
	{
		NodoArista* aux = primero;
		do {
			Vertice* verticeLlegada = aux->arista; // Vertice del nodo de llegada
			NodoArista* nodoAristaActual = verticeLlegada->aristas.buscarNodo(pPalabra); // Se busca si existe una relacion de vuelta
			int pesoIda = aux->peso;
			int pesoDeVuelta = (nodoAristaActual != nullptr ? nodoAristaActual->peso : 0);
			std::wcout << verticeLlegada->palabra;
			if (pesoIda > 1)
			{
				std::wcout << " --- Peso hacia: " << pesoIda;
			}
			if (pesoDeVuelta > 1)
			{
				std::wcout << " --- Peso de vuelta: " << pesoDeVuelta;
			}
			std::wcout << "\n";
			aux = aux->siguiente;
		} while (aux != primero);
	}
}
