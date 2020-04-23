#include "Grafo.h"
#include "Variables.h"
//#include <bits/stdc++.h> 
#include <functional>
//#include <wctype.h>
//#include <stdio.h>



void Grafo::nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada)
{
	// TODO
	mapVerticesType::iterator primeraPalabra = vertices.find(pPalabraSalida);
	mapVerticesType::iterator segundaPalabra = vertices.find(pPalabraLlegada);
	Vertice* nodoPrimeraPalabra = nullptr;
	Vertice* nodoSegundaPalabra = nullptr;
	if (primeraPalabra == vertices.end())
	{
		nodoPrimeraPalabra = new Vertice(pPalabraSalida);
		primeraPalabra = (vertices.insert({ pPalabraSalida, nodoPrimeraPalabra })).first;

	}
	else
		nodoPrimeraPalabra = primeraPalabra->second;

	if (segundaPalabra == vertices.end())
	{
		nodoSegundaPalabra = new Vertice(pPalabraLlegada);
		segundaPalabra = (vertices.insert({ pPalabraLlegada, nodoSegundaPalabra })).first;
	}
	else
		nodoSegundaPalabra = segundaPalabra->second;

	nodoPrimeraPalabra->nuevaArista(nodoSegundaPalabra);
}

void Grafo::imprimirRelaciones(std::wstring pPalabra)
{
	if (pPalabra.empty())
	{
		for (auto& it : vertices)
		{
			std::wcout << L"########### Relaciones de " << it.second->palabra << " ######################\n";
			it.second->imprimirAristas();
		}
	}
	else
	{
		mapVerticesType::iterator vertice = vertices.find(pPalabra);
		if (vertice != vertices.end())
		{
			std::wcout << L"########### Relaciones de " << vertice->second->palabra << " ######################\n";
			vertice->second->imprimirAristas();
		}
		else
			std::wcout << L"Palabra no encontrada\n";
	}
}


void Grafo::ordenarAristas()
{
	for (auto& it : vertices)
	{
		it.second->ordenarAristas();
	}
}


void Grafo::ordenarVertices()
{
	for (auto x : vertices) verticesOrdenados.push_back(x.second);

	std::sort(verticesOrdenados.begin(), verticesOrdenados.end(), [](Vertice* verticeAux1, Vertice* verticeAux2)
		{
			return verticeAux1->getPoder() > verticeAux2->getPoder();
		}
	);
}

//Resuelve pregunta A)
void Grafo::palabrasMasPoderosas(int cantidad)
{
	std::wcout << L"\nLas " + std::to_wstring(cantidad) + L" palabras con mayor poder son las siguientes: \n";

	for (int i = 0; i < cantidad; i++) std::wcout << verticesOrdenados.at(i)->palabra + L": con un poder de " + std::to_wstring(verticesOrdenados.at(i)->poder) + L"\n";
}

void Grafo::palabrasMenosPoderosas(std::wstring pPalabra) {
	mapVerticesType::iterator it = vertices.find(pPalabra);
	if (it == vertices.end()) {
		std::wcout << L"La palabra no existe en el Grafo";
		return;
	}
	it->second->palabrasMenosPoderosas();
}

void Grafo::gruposDePoder(std::wstring pPalabra)
{
	mapVerticesType::iterator it = vertices.find(pPalabra);
	if (it == vertices.end()) {
		std::wcout << L"La palabra no existe en el Grafo";
		return;
	}
	it->second->gruposDePoder();
}