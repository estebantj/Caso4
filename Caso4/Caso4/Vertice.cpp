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
	mapType::iterator aristaPair = mapaAristasExistentes.find(nodoLlegada->palabra);
	if (aristaPair == mapaAristasExistentes.end())
	{
		Arista* arista = new Arista(nodoLlegada);
		aristas.push_back(arista);
		mapaAristasExistentes.insert({ nodoLlegada->palabra, arista });
	}
	else
	{
		Arista* arista = aristaPair->second;
		arista->peso = arista->peso + 1;
		this->poder = this->poder + 1;
	}
}

void Vertice::ordenarAristas()
{
	std::sort(aristas.begin(), aristas.end(), [](const Arista* lhs, const Arista* rhs)
		{
			return lhs->peso < rhs->peso;
		});
}

void Vertice::imprimirAristas()
{
	for (auto it : aristas) 
	{
		
		Arista* aristaDeVuelta = it->verticeLlegada->buscarArista(this->palabra);
		int pesoIda = it->peso;
		int pesoDeVuelta = (aristaDeVuelta != nullptr) ? aristaDeVuelta->peso : 0;
		
		if (pesoIda > 1)
		{
			std::wcout << it->verticeLlegada->palabra << " --- Peso ida: " << pesoIda << "\n";
		}

		/*
		if (pesoDeVuelta > 1)
		{
			std::wcout << " --- Peso de vuelta: " << pesoDeVuelta;
		}
		*/
	}
	std::wcout << std::endl;
}
