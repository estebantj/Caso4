#pragma once
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>

class Vertice;
class Arista;

typedef std::unordered_map<std::wstring, Arista*> mapType;

struct Arista
{
	Vertice* verticeLlegada;
	int peso;
};

class Vertice
{
public:
	Vertice(std::wstring pPalabra);
	Arista* buscarArista(std::wstring pPalabra);
	void nuevaArista(Vertice* nodoLlegada);
	void imprimirAristas();

private:

	int poder;
	std::wstring palabra;
	std::vector<Arista*> aristas;
	std::unordered_map<std::wstring, Arista*> mapaAristasExistentes;

	friend class DoubleCircularList;
	friend class Estructura;
};

