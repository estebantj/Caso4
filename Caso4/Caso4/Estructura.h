#pragma once
#include <unordered_map>
#include <string>
#include <algorithm>    
#include "Vertice.h"

class Estructura
{
public:
	
	void listarPoder();
	void imprimirRelaciones();
	void ordernarAristas();
	void nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada);

	std::unordered_map<std::wstring, Vertice*> vertices;

};

