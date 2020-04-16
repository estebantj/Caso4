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
	wifstream archivo("Texto.txt");

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
						if (wordSize > 1)
						{
							wstring subWord = word.substr(wordSize - 2, wordSize - 1);
						}
						if ((filtro.find(word) == filtro.end()) &&
							(wordSize > 1 ) && (word.substr(wordSize - 2, wordSize - 1) != L"ar") &&
							(word.substr(wordSize - 2, wordSize - 1) != L"ir") &&
							(word.substr(wordSize - 2, wordSize - 1) != L"er") &&
							(word.substr(wordSize - 2, wordSize - 1) != L"so") &&
							(word.substr(wordSize - 2, wordSize - 1) != L"to") &&
							(wordSize > 3) && (word.substr(wordSize - 3, wordSize - 1) != L"cho") &&
							(wordSize > 4) && (word.substr(wordSize - 4, wordSize - 1) != L"ando") &&
							(wordSize > 5) && (word.substr(wordSize - 5, wordSize - 1) != L"iendo") )
						{
							wcout << word << "\n";  //Realmente acá iría el insertar en grafo usar numeroParrafo  
						}
						/*
						
							*/
						word.clear();
					}
				}
			}
		}

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