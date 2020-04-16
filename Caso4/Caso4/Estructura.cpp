#include "Estructura.h"
#include "Variables.h"

using namespace std;

typedef std::unordered_map<std::wstring, Nodo*>MAP;

void Estructura::nuevaRelacion(wstring pPalabraSalida, wstring pPalabraLlegada)
{
	MAP::iterator primeraPalabra = vertices.find(pPalabraSalida);
	MAP::iterator segundaPalabra = vertices.find(pPalabraLlegada);
	Nodo* nodoPrimeraPalabra = nullptr;
	Nodo* nodoSegundaPalabra = nullptr;
	if (primeraPalabra == vertices.end())
	{
		nodoPrimeraPalabra = new Nodo(pPalabraSalida);
		pair<MAP::iterator, bool> ret = vertices.insert({ pPalabraSalida, nodoPrimeraPalabra });
		primeraPalabra = ret.first;
	}
	else 
		nodoPrimeraPalabra = primeraPalabra->second;
	if (segundaPalabra == vertices.end())
	{
		nodoSegundaPalabra = new Nodo(pPalabraLlegada);
		pair<MAP::iterator, bool> ret = vertices.insert({ pPalabraLlegada, nodoSegundaPalabra });
		segundaPalabra = ret.first;
	}
	else 
		nodoSegundaPalabra = segundaPalabra->second;


}