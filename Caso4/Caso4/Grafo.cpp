#include "Grafo.h"
#include "Variables.h"
//#include <bits/stdc++.h> 
#include <functional>
//#include <wctype.h>
//#include <stdio.h>

void Grafo::nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada)
{
	if (pPalabraSalida == pPalabraLlegada) return;

	mapVerticesType::iterator primeraPalabra = vertices.find(pPalabraSalida);
	Vertice* nodoPrimeraPalabra = nullptr;
	Vertice* nodoSegundaPalabra = nullptr;
	mapVerticesType::iterator segundaPalabra = vertices.find(pPalabraLlegada);
	
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

void Grafo::asignarNextToVist()
{
	for (auto& it : vertices)
	{
		it.second->asignarNextToVist();
	}
}

//Resuelve pregunta A)
void Grafo::palabrasMasPoderosas(int cantidad) //F(n) = O(n) siendo el n la cantidad de elementos solicitados
{

	if (verticesOrdenados.size() < cantidad) { //2 tiempos
		std::wcout << L"\nNo existen tantos vertices en la estructura"; //1 tiempo
		return; //1 tiempo
	}
	std::wcout << L"\nLas " + std::to_wstring(cantidad) + L" palabras con mayor poder son las siguientes: \n"; //3 tiempos
	
	for (int i = 0; i < cantidad; i++) std::wcout << verticesOrdenados.at(i)->palabra + L": con un poder de " + std::to_wstring(verticesOrdenados.at(i)->poder) + L"\n";
	//for tiene tiempo n donde la n es cantidad

}

void Grafo::palabrasMenosPoderosas(std::wstring pPalabra) { //F(n) = O(c)
	mapVerticesType::iterator it = vertices.find(pPalabra);
	if (it == vertices.end()) {
		std::wcout << L"\nLa palabra no existe en el Grafo";
		return;
	}
	it->second->palabrasMenosPoderosas();
}

void Grafo::gruposDePoder(std::wstring pPalabra, int pK)
{
	mapVerticesType::iterator verticeInicial = vertices.find(pPalabra);
	if (verticeInicial == vertices.end()) {
		std::wcout << L"\nLa palabra no existe en el Grafo";
		return;
	}

	std::wcout << "\n\nGrupos de poder relacionados con la palabra: " << verticeInicial->second->palabra << "\n";
	float groupSize;
	bool huboResiduo = false;
	float cantidadDeVertices = (float)this->verticesOrdenados.size();
	if (pK <= cantidadDeVertices)
	{
		groupSize =  cantidadDeVertices / (float) pK;
		if (groupSize != (int)groupSize) huboResiduo = true;
	}
	else
	{
		std::wcout << "El k es mayor a la cantidad de vertices, cantidad de vertices: " << cantidadDeVertices;
		return;
	}

	int contador = 1;
	groupSize++;
	this->verticeInicial = verticeInicial->second;
	for (auto thisArista : verticeInicial->second->aristas) // F(n) = O(n) con n = k
	{
		if (contador > pK) break;
		if (contador == pK && huboResiduo) groupSize--;
		std::wcout << "--- Grupo #" << contador << " ---\n";
		Vertice* nextVertice = thisArista->verticeLlegada;
		std::wstring camino = buscarCaminoMasPoderoso(nextVertice, (int)groupSize);
		std::wcout << camino << "\n\n";
		contador++;
	}
	std::wcout << "\n";
}

/*	Nota	
	El nextToVisit permite que se vuelva a aun vertice porque las relaciones son con direccion.
	Y al utilizar esta direccion el nextToVisit se actualiza para apuntar a otra relacion.
*/
std::wstring Grafo::buscarCaminoMasPoderoso(Vertice* pVerticeSalida, int pGroupSize)
{
	std::wstring camino;
	Vertice* verticeActual = pVerticeSalida;
	int actualGroupSize = 0;
	
	while (actualGroupSize < pGroupSize) {
		camino += verticeActual->palabra + L" -> ";

		std::vector<Arista*>::iterator* nextToVisit = &verticeActual->nextToVisit;
		if (*nextToVisit == verticeActual->aristas.end()) break;

		verticeActual = (*(*nextToVisit))->verticeLlegada;
		if (verticeActual == this->verticeInicial) break;
		++(*nextToVisit);
		actualGroupSize++;
	}

	return camino;
}