#pragma once
#include <unordered_map>
#include <string>
#include "Vertice.h"

class Estructura
{
public:
	void nuevaRelacion(std::wstring pPalabraSalida, std::wstring pPalabraLlegada);

	std::unordered_map<std::wstring, Vertice*> vertices;

};

