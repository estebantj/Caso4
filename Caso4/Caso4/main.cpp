#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string fileName = "Texto.txt";

void leerArchivo()
{
	ifstream archivo("Texto.txt");
	if (archivo.is_open())
	{
		string word, parrafo;
		char caracter;
		int numeroDeParrafo = 1;
		cout << "Archivo abierto\n";
		while (archivo.get(caracter))
		{
			if ()
			word.push_back(caracter);
			if (caracter == ' ')
			{
				// Se verifica si word es un sustantivo
			}
			if (caracter == '\n')
			{
				//Nueva linea equivale a nuevo parrafo en la mayoria de los casos
				cout << "Parrafo #" << numeroDeParrafo << "\n";
				numeroDeParrafo++;
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
	leerArchivo();
	//system("PAUSE");
	return 1;
}