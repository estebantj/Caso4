#include "Vertice.h"

Vertice::Vertice(std::wstring pPalabra)
{
	this->palabra = pPalabra;
}

Arista* Vertice::buscarArista(std::wstring pPalabra)
{
	mapType::iterator arista = mapaAristasExistentes.find(pPalabra);
	if (arista != mapaAristasExistentes.end())
	{
		return arista->second;
	}
	return nullptr;
}

void Vertice::nuevaArista(Vertice* nodoLlegada)
{
	auto aristaPair = mapaAristasExistentes.find(nodoLlegada->palabra);
	if (aristaPair == mapaAristasExistentes.end())
	{
		Arista* arista;
		arista->verticeLlegada = nodoLlegada;
		arista->peso = 0;
		aristas.push_back(arista);
		mapaAristasExistentes.insert({ nodoLlegada->palabra, arista });
	}
	else
	{
		Arista* arist = aristaPair->second;
		arist->peso = arist->peso + 1;
	}
}

void Vertice::imprimirAristas()
{
	for (auto it : aristas) 
	{
		int pesoIda = it->second;
		if (pesoIda >= 1)
		{
			std::wcout << " --- Peso hacia: " << pesoIda;
		}
	}
}


/*
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
*/