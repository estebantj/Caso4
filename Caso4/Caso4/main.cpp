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


using namespace std;

string fileName = "Texto.txt";


void leerArchivo()
{
	wifstream archivo("Texto.txt");
	
	if (archivo.is_open()){

		// Dar formato utf-8
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>); //TODO da error
		(void)archivo.imbue(utf8_locale);

		wstring word, parrafo;
		int numeroDeParrafo = 1;
		wchar_t caracter, bom = L'\0';
		//Diccionario de palabras por revisar

		map<wstring,char> mapaPalabrasFiltro;
		wstring palabrasFiltro[20];
		for (int i = 0;i < 30;i++) {

		}
		
		archivo.get(bom);

		while (archivo.get(caracter))
		{	
			if (iswalpha(caracter) || caracter == ' ' || caracter == '\n')
			{
				if (iswalpha(caracter)) word.push_back(caracter);

				else if (caracter == ' ')
				{
					if (!word.empty())
					{
						int wordSize = word.size();
						if ( !(mapaPalabrasFiltro.count(word)) ||  //Lee que count es lo mas elegante para maps
 
								(wordSize >1 &&
									( (word[wordSize-2]==L'a' && word[wordSize - 2] == L'a') ||
									((word[wordSize - 2] == L'a' && word[wordSize - 2] == L'a'))
									) 
							    ) 
						) {

							wcout << word << "\n";  //Realmente acá iría el insertar en grafo usar numeroParrafo  
						}

						word.clear();
					}
					// Se verifica si word es un sustantivo
				}
				else if (caracter == '\n')
				{
					if (!word.empty())
					{
						//wcout << word << "\n";
						word.clear();
					}
					//Nueva linea equivale a nuevo parrafo en la mayoria de los casos
					//wcout << "Parrafo #" << numeroDeParrafo << "\n";
					numeroDeParrafo++;
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