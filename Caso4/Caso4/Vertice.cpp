#include "Vertice.h"

Vertice::Vertice(std::wstring pPalabra) // F(n) = O(c) 
{
	this->palabra = pPalabra;
}

Arista* Vertice::buscarArista(std::wstring pPalabra) // F(n) = O(c)
{
	mapAristasType::iterator arista = mapaAristasExistentes.find(pPalabra);
	if (arista != mapaAristasExistentes.end())
	{
		return arista->second;
	}
	return nullptr;
}

void Vertice::nuevaArista(Vertice* nodoLlegada) // F(n) = O(c)
{
	mapAristasType::iterator aristaPair = mapaAristasExistentes.find(nodoLlegada->palabra);
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

int Vertice::getPoder() // F(n) = O(c)
{
	return poder;
}

void Vertice::ordenarAristas() // F(n) = O(nlogn)
{
	std::sort(aristas.begin(), aristas.end(), [](const Arista* lhs, const Arista* rhs)
		{
			return lhs->peso > rhs->peso;
		});
	this->nextToVisit = aristas.begin();
}

void Vertice::imprimirAristas() // F(n) = O(n)
{
	for (auto it : aristas)
	{
		Arista* aristaDeVuelta = it->verticeLlegada->buscarArista(this->palabra);
		int pesoIda = it->peso;
		int pesoDeVuelta = (aristaDeVuelta != nullptr) ? aristaDeVuelta->peso : 0;
		std::wstring textoRelaciones = it->verticeLlegada->palabra;
		if (pesoIda > 1)
		{
			textoRelaciones.append(L" --- Peso ida: " + std::to_wstring(pesoIda));
		}
		if (pesoDeVuelta > 1)
		{
			textoRelaciones.append(L" --- Peso de vuelta: " + std::to_wstring(pesoDeVuelta));
		}
		if (pesoIda > 1 || pesoDeVuelta > 1) std::wcout << textoRelaciones << std::endl;
	}
}

void Vertice::asignarNextToVist() // F(n) = O(c)
{
	this->nextToVisit = aristas.begin();
}

void Vertice::palabrasMenosPoderosas() //F(n) = O(n) con n siendo la cantidad de aristas del vertice por evalua (el P)
{
	for (auto thisArista : aristas) 
	{
		if (thisArista->peso > 1)
		{
			Arista* aristaDeRegreso = thisArista->verticeLlegada->buscarArista(this->palabra);
			if (aristaDeRegreso != nullptr && aristaDeRegreso->peso > 1)
			{
				if (thisArista->peso > aristaDeRegreso->peso)
				{
					std::wcout << L"Palabra: " + thisArista->verticeLlegada->palabra + L" --- Peso de ida: " + std::to_wstring(thisArista->peso) + L" --- Peso de vuelta: " + std::to_wstring(aristaDeRegreso->peso) + L"\n";
				}
			}
			else
			{
				std::wcout << L"Palabra: " + thisArista->verticeLlegada->palabra + L" --- Peso de ida: " + std::to_wstring(thisArista->peso) + L" --- Gano por default\n";
			}
		}
		else
			break;
	}
}
