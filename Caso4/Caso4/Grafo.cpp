#include "Grafo.h"
#include "Variables.h"
//#include <bits/stdc++.h> 
#include <functional>
#include <set>

typedef std::unordered_map<std::wstring, Vertice*> MAP;

void Grafo::nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada)
{
	MAP::iterator primeraPalabra = vertices.find(pPalabraSalida);
	MAP::iterator segundaPalabra = vertices.find(pPalabraLlegada);
	Vertice* nodoPrimeraPalabra = nullptr;
	Vertice* nodoSegundaPalabra = nullptr;
	if (primeraPalabra == vertices.end())
	{
		//pair<MAP::iterator, bool> ret = vertices.insert({ pPalabraSalida, new Nodo(pPalabraSalida) });
		nodoPrimeraPalabra = new Vertice(pPalabraSalida);
		primeraPalabra = (vertices.insert({ pPalabraSalida, nodoPrimeraPalabra })).first;

	}
	else 
		nodoPrimeraPalabra = primeraPalabra->second;

	if (segundaPalabra == vertices.end())
	{
		//pair<MAP::iterator, bool> ret = vertices.insert({ pPalabraLlegada, new Nodo(pPalabraLlegada) });
		nodoSegundaPalabra = new Vertice(pPalabraLlegada);
		segundaPalabra = (vertices.insert({ pPalabraLlegada, nodoSegundaPalabra })).first;
	}
	else 
		nodoSegundaPalabra = segundaPalabra->second;
	
	// Se añade la arista
	nodoPrimeraPalabra->nuevaArista(nodoSegundaPalabra);
}

void Grafo::imprimirRelaciones()
{
	for (auto& it : vertices) 
	{
		std::wcout << L"########### Relaciones de " << it.second->palabra << " ######################\n";
		it.second->imprimirAristas();
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

	std::vector<std::pair<int,Vertice*>> verticesAux;
	for (auto x : vertices) {
		auto m = std::make_pair(x.second->poder, x.second);
		verticesAux.push_back(m);	
		vertices.erase(x.first);
	}
	// FIX CUSTOM MADE COMPARISON std::sort(verticesAux.begin(), verticesAux.end(), std::greater<int>());

	for (auto x : verticesAux) {
		vertices.insert(std::make_pair(x.second->palabra,x.second));
	}


}

void Grafo::listarPoder() {
	std::wcout << "\n\n\n\n\n";
	//std::getchar;
	}

