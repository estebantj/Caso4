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

using namespace std;


void leerArchivo()
{
	wifstream archivo("el_quijote.txt");
	int cantidad = 0;
	if (archivo.is_open()) {

		// Dar formato utf-8
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>); //TODO da error
		(void)archivo.imbue(utf8_locale);

		wstring word, parrafo;
		int numeroDeParrafo = 1;
		wchar_t caracter, bom = L'\0';

		archivo.get(bom);

		while (archivo.get(caracter))
		{
			if (iswalpha(caracter) || caracter == ' ' || caracter == '\n')
			{
				caracter = tolower(caracter); // para evitar aumento de comparaciones en el diccionario
				if (iswalpha(caracter)) word.push_back(caracter);

				else // else if (caracter == " " || caracter == "\n")
				{
					if (caracter == '\n') numeroDeParrafo++;

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
							//wcout << word << "\n";  //Realmente acá iría el insertar en grafo usar numeroParrafo 
							cantidad++;
						}
						word.clear();
					}
				}
			}
		}
		wcout << L"cantidad: " << to_wstring(cantidad) << endl;

	}
	else
	{
		cout << "Error al abrir archivo\n";
	}
}

int main()
{
	int m = _setmode(_fileno(stdout), _O_U16TEXT); // Se cambia la consola a utf-16

	leerArchivo();
	//system("PAUSE");
	return 1;
}