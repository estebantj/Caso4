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
#include "Estructura.h"

using namespace std;

static Estructura estructura;

void leerArchivo()
{
	wifstream archivo("Texto.txt");
	if (archivo.is_open()) {

		// Dar formato utf-8
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>); 
		(void)archivo.imbue(utf8_locale);

		//Variables de vertices y cont de parrafo
		wchar_t caracter;
		int numeroDeParrafo = 1;
		wstring word, lastWord;

		while (archivo.get(caracter))
		{
			if (iswalpha(caracter) || caracter == ' ' || caracter == '\n')
			{
				caracter = tolower(caracter); // para evitar aumento de comparaciones en el diccionario
				if (iswalpha(caracter)) word.push_back(caracter);

				else // else if (caracter == " " || caracter == "\n")
				{
					if (caracter == '\n') lastWord.clear();

					if (!word.empty())
					{
						size_t wordSize = word.length();
						// Terminaciones
						wstring subString1 = wordSize > 1 ? word.substr(wordSize - 2, wordSize - 1) : L"";
						wstring subString2 = wordSize > 2 ? word.substr(wordSize - 3, wordSize - 1) : L"";
						wstring subString3 = wordSize > 3 ? word.substr(wordSize - 4, wordSize - 1) : L"";
						wstring subString4 = wordSize > 4 ? word.substr(wordSize - 5, wordSize - 1) : L"";

						if ((filtro.find(word) == filtro.end()) &&
							filtroTerminaciones.find(subString1) == filtroTerminaciones.end() &&
							filtroTerminaciones.find(subString2) == filtroTerminaciones.end() &&
							filtroTerminaciones.find(subString3) == filtroTerminaciones.end() &&
							filtroTerminaciones.find(subString4) == filtroTerminaciones.end())
						{
							//wcout << word << "\n";  
							if (!lastWord.empty())
							{
								estructura.nuevaRelacion(lastWord, word);
								lastWord = word;
							}
							else
							{
								lastWord = word;
							}
						}
						word.clear();
					}
				}
			}
		}
	}
	else
	{
		wcout << "Error al abrir archivo\n";   //Debe ser wcout porque la consola esta en ese modo
	}
}

int main()
{
	int m = _setmode(_fileno(stdout), _O_U16TEXT); // Se cambia la consola a utf-16 se le asigna a "m" para eliminar el warning 
	leerArchivo();
	estructura.imprimirRelaciones();
	return 20;
}