#include <string>
#include <fstream>
#include <iostream>
#include <locale>
#include <codecvt>
#include <clocale>

#include <cstdio>  // for _fileno
#include <io.h>    // for _setmode
#include <fcntl.h> // for _O_U16TEXT


using namespace std;

string fileName = "Texto.txt";

void leerArchivo()
{
	wifstream archivo("Texto.txt");
	

	if (archivo.is_open())
	{
		// Dar formatio utf-8
		locale utf8_locale(locale(), new codecvt_utf8<wchar_t>); //TODO da error
		archivo.imbue(utf8_locale);

		wstring word, parrafo;
		wchar_t caracter;
		int numeroDeParrafo = 1;
		cout << "Archivo abierto\n";

		wchar_t bom = L'\0';
		archivo.get(bom);

		while (archivo.get(caracter))
		{	
			if (iswalpha(caracter) || caracter == ' ' || caracter == '\n')
			{
				word.push_back(caracter);
				if (caracter == ' ')
				{
					if (!word.empty())
					{
						wcout << word << "\n";
						word.clear();
					}
					// Se verifica si word es un sustantivo
				}
				else if (caracter == '\n')
				{
					if (!word.empty())
					{
						wcout << word << "\n";
						word.clear();
					}
					//Nueva linea equivale a nuevo parrafo en la mayoria de los casos
					wcout << "Parrafo #" << numeroDeParrafo << "\n";
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
	_setmode(_fileno(stdout), _O_U16TEXT); // Se cambia la consola a utf-16
	
	leerArchivo();
	//system("PAUSE");
	return 1;
}