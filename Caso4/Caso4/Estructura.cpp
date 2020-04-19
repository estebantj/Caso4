#include "Estructura.h"
#include "Variables.h"

using namespace std;

typedef std::unordered_map<std::wstring, Vertice*> MAP;

void Estructura::nuevaRelacion(wstring pPalabraSalida, wstring pPalabraLlegada)
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