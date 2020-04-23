#include "Grafo.h"
#include "Variables.h"
//#include <bits/stdc++.h> 
#include <functional>
//#include <wctype.h>
//#include <stdio.h>



typedef std::unordered_map<std::wstring, Vertice*> MAP;

void Grafo::nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada)
{
	pPalabraSalida[0] = towupper(pPalabraSalida[0]);
	pPalabraLlegada[0] = towupper(pPalabraLlegada[0]);
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

	for (auto x : vertices) verticesOrdenados.push_back(x.second);

	std::sort(verticesOrdenados.begin(), verticesOrdenados.end(), [](Vertice* verticeAux1, Vertice* verticeAux2)
		{
			return verticeAux1->getPoder() > verticeAux2->getPoder();
		}
	);

	//Solo para mostrar las palabras (eliminar luego de crear el método correcto para la A)
	for (auto x : verticesOrdenados) std::wcout << std::to_wstring(x->poder) + L"   " + x->palabra + L"\n";
}

//Resuelve pregunta A)
void Grafo::palabrasMasPoderosas(int cantidad)
{
	std::wcout<< L"\nLas "+std::to_wstring(cantidad)+L" palabras con mayor poder son las siguientes: \n";

	for (int i = 0; i < cantidad;i++) std::wcout << verticesOrdenados.at(i)->palabra +L": con un poder de " + std::to_wstring(verticesOrdenados.at(i)->poder) + L"\n";
}

void Grafo::palabrasMenosPoderosas(std::wstring pPalabra) {
	std::unordered_map<std::wstring,Vertice*>::iterator it = vertices.find(pPalabra);
	if (it == vertices.end()) {
		std::wcout << L"La palabra no existe en el Grafo";
		return;
	}
		
	for (int repe = 0;repe < it->second->cantMenorPoder;repe++) {
			//Tener un numero de posicion de la lista de aristas donde solo tenemos
			//que movernos esas veces porque el resto son mayores tons al ordenarla 
			//
	}
}