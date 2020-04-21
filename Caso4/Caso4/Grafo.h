#pragma once
#include <unordered_map>
#include <string>
#include <algorithm>    
#include "Vertice.h"

class Grafo
{
public:
	
	void listarPoder();
	void ordenarAristas();
	void ordenarVertices();
	void imprimirRelaciones();
	void nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada);

	std::unordered_map<std::wstring, Vertice*> vertices;

};

