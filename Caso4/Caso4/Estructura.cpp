#include "Estructura.h"
#include "Variables.h"
//#include <bits/stdc++.h> 
#include <functional>


typedef std::unordered_map<std::wstring, Vertice*> MAP;

void Estructura::nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada)
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
	nodoPrimeraPalabra->poder++;
}

void Estructura::imprimirRelaciones()
{
	for (auto& it : vertices) {
		wcout << L"########### Relaciones de " << it.second->palabra << " ######################\n";
		it.second->imprimirAristas();
	}
}

void Estructura::listarPoder() {
	std::wcout << "\n\n\n\n\n";
	//std::getchar;
	std::vector<int> poderes;
	for (auto& it : vertices)                   poderes.push_back(it.second->poder);
	std::sort(poderes.begin(), poderes.end(), std::greater<int>());
	for (int i = 0;i < poderes.size();i++)      std::wcout << poderes[i]<<"\n";
}

