#pragma once
#include <string>
#include <vector>

class Nodo
{
private:
	std::string palabra;
	int peso;
	std::vector< std::pair<Nodo*, int> > aristas;
	
};

