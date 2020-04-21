#pragma once
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>
#include <algorithm>

class Vertice;
class Arista;

typedef std::unordered_map<std::wstring, Arista*> mapType;

class Arista
{
public:
	Arista(Vertice* pLlegada)
	{
		this->peso = 1;
		this->verticeLlegada = pLlegada;
	}
	int peso;
	Vertice* verticeLlegada;
};

class Vertice
{
public:
	Vertice(std::wstring pPalabra);

	void ordenarAristas();
	void imprimirAristas();
	void nuevaArista(Vertice* nodoLlegada);
	Arista* buscarArista(std::wstring pPalabra);

private:
	int poder;
	std::wstring palabra;
	std::vector<Arista*> aristas;
	std::unordered_map<std::wstring, Arista*> mapaAristasExistentes;

	friend class Grafo;
};

