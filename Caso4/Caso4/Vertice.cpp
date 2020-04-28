#include "Vertice.h"

Vertice::Vertice(std::wstring pPalabra)
{
	this->palabra = pPalabra;
}

Arista* Vertice::buscarArista(std::wstring pPalabra)
{
	mapAristasType::iterator arista = mapaAristasExistentes.find(pPalabra);
	if (arista != mapaAristasExistentes.end())
	{
		return arista->second;
	}
	return nullptr;
}

void Vertice::nuevaArista(Vertice* nodoLlegada)
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

int Vertice::getPoder()
{
	return poder;
}

void Vertice::ordenarAristas()
{
	std::sort(aristas.begin(), aristas.end(), [](const Arista* lhs, const Arista* rhs)
		{
			return lhs->peso > rhs->peso;
		});
	this->nextToVisit = aristas.begin();
}

void Vertice::imprimirAristas()
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

void Vertice::asignarNextToVist()
{
	this->nextToVisit = aristas.begin();
}

void Vertice::palabrasMenosPoderosas()
{
	for (auto thisArista : aristas) //F(n) = O(n) con n siendo la cantidad de aristas del vertice por evalua (el P)
	{
		if (thisArista->peso > 1) //2 tiempos
		{
			Arista* aristaDeRegreso = thisArista->verticeLlegada->buscarArista(this->palabra); //6 tiempos
			if (aristaDeRegreso != nullptr && aristaDeRegreso->peso > 1) //4 tiempos
			{
				if (thisArista->peso > aristaDeRegreso->peso) //3 tiempos
				{
					std::wcout << L"Palabra: " + thisArista->verticeLlegada->palabra + L" --- Peso de ida: " + std::to_wstring(thisArista->peso) + L" --- Peso de vuelta: " + std::to_wstring(aristaDeRegreso->peso) + L"\n";
					//11 tiempos
				}
			}
			else // Gana por default (no hay arista de regreso o tiene peso 1)
			{
				std::wcout << L"Palabra: " + thisArista->verticeLlegada->palabra + L" --- Peso de ida: " + std::to_wstring(thisArista->peso) + L" --- Gano por default\n";
				//11tiempos
			}
		}
		else
			break;
	}
}
