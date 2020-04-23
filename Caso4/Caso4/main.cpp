#pragma warning(disable : 4996)

#include <string>
#include <fstream>
#include <iostream>
#include <locale>
#include <codecvt>	
#include <clocale>
#include <map>
#include <cstdio>  // for _fileno
#include <io.h>    // for _setmode
#include <fcntl.h> // for _O_U16TEXT
#include "Variables.h"
#include "Grafo.h"
#include <Windows.h>

static Grafo estructura;

void leerArchivo()
{
	std::wifstream archivo("Texto.txt");
	if (archivo.is_open()) {

		// Dar formato utf-8
		std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>);
		(void)archivo.imbue(utf8_locale);

		//Variables de vertices 
		wchar_t caracter;
		std::wstring word;
		std::wstring lastWords[10];
		int arraySize = std::size(lastWords);
		while (archivo.get(caracter))
		{
			if (iswalpha(caracter) || caracter == ' ' || caracter == '\n')
			{
				caracter = tolower(caracter); // para evitar aumento de comparaciones en el diccionario
				if (iswalpha(caracter)) word.push_back(caracter);

				else // else if (caracter == " " || caracter == "\n")
				{
					if (caracter == '\n') 
					{
						//TODO: Needs to be checked
						for (int i = 0; i < arraySize - 1; i++)
						{
							lastWords[i].clear();
						}
					}
					if (!word.empty())
					{
						size_t wordSize = word.length();
						// Terminaciones
						std::wstring subString1 = wordSize > 1 ? word.substr(wordSize - 2, wordSize - 1) : L"";
						std::wstring subString2 = wordSize > 2 ? word.substr(wordSize - 3, wordSize - 1) : L"";
						std::wstring subString3 = wordSize > 3 ? word.substr(wordSize - 4, wordSize - 1) : L"";
						std::wstring subString4 = wordSize > 4 ? word.substr(wordSize - 5, wordSize - 1) : L"";

						if ((filtro.find(word) == filtro.end()) &&
							filtroTerminaciones.find(subString1) == filtroTerminaciones.end() &&
							filtroTerminaciones.find(subString2) == filtroTerminaciones.end() &&
							filtroTerminaciones.find(subString3) == filtroTerminaciones.end() &&
							filtroTerminaciones.find(subString4) == filtroTerminaciones.end())
						{
							//wcout << word << "\n";							
							for (int i=0; i < arraySize-1; i++ )
							{
								if (!lastWords[i].empty()) estructura.nuevaRelacion(lastWords[i], word);
								lastWords[i] = lastWords[i+1];
							}
							if (!lastWords[arraySize - 1].empty()) estructura.nuevaRelacion(lastWords[arraySize - 1], word);
							lastWords[arraySize - 1] = word;
						}
						word.clear();
					}
				}
			}
		}
	}
	else
	{
		std::wcout << "Error al abrir archivo\n";   //Debe ser wcout porque la consola esta en ese modo
	}
	estructura.ordenarAristas();
	estructura.ordenarVertices();
}

void loopPreguntas() {
	int entrada = 0;
	std::wstring  textoIntro = L"Presione \n1: Resolver el problema a)\n2: Resolver el problema b)\n3: Resolver el problema c)\n4: Imprimir todas las relaciones\n5: Salir\n";;
	std::wstring palabra;
	int cantidadMasPoderosas = 0;
	while (entrada != 5) {
		std::wcout << textoIntro;
		std::cin >> entrada;
		if (entrada > 0 && entrada < 5) {
			switch (entrada)
				{
				case 1:
					std::wcout << L"Digite la cantidad de palabras: ";
					std::cin >> cantidadMasPoderosas;
					estructura.palabrasMasPoderosas(cantidadMasPoderosas);
					std::wcout << std::endl;
					break;
				case 2:
					std::wcout << L"Digite la palabra: ";
					std::wcin >> palabra;
					estructura.palabrasMenosPoderosas(palabra);
					std::wcout << std::endl;
					palabra.clear();
					break;
				case 3:
					std::wcout << L"Digite la palabra: ";
					std::wcin >> palabra;
					estructura.gruposDePoder(palabra);
					break;
				case 4:
					std::wcout << L"Digite la palabra o  digite '.' para mostrar todo: ";
					//std::wcin >> palabra;
					std::cin.ignore();
					std::getline(std::wcin, palabra);
					if (palabra == L".") palabra.clear();
					estructura.imprimirRelaciones(palabra);
					palabra.clear();
					break;
				default:
					break;
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
}

int wmain()
{
	// Se cambia la consola a utf-16 se le asigna a "m" para eliminar el warning 
	int m = _setmode(_fileno(stdout), _O_U16TEXT);
	//setlocale(LC_ALL, "");

	leerArchivo();
	loopPreguntas();
	return 20;
}