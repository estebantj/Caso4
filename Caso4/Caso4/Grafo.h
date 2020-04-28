#pragma once
#include <unordered_map>
#include <string>
#include <algorithm>    
#include "Vertice.h"

typedef std::unordered_map<std::wstring, Vertice*> mapVerticesType;

class Grafo
{
public:

	void ordenarAristas();
	void ordenarVertices();
	void asignarNextToVist();
	void palabrasMasPoderosas(int cantidad);
	void imprimirRelaciones(std::wstring pPalabra);
	void gruposDePoder(std::wstring pPalabra, int pK);
	void palabrasMenosPoderosas(std::wstring pPalabra);
	void nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada);
	std::wstring buscarCaminoMasPoderoso(Vertice* pVerticeSalida, int pGroupSize);

	Vertice* verticeInicial;
	std::vector<Vertice*> verticesOrdenados;
	std::unordered_map<std::wstring, Vertice*> vertices;
};


