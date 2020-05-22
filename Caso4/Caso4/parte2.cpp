#include "parte2.h"

//Definicion de variables
double angle = -7;

float x = 0, y = -100;
float x2 = 0, y2 = 100;
float screenCenterX = 0, screenCenterY = 0;
int cantidadDeCirculos = 5, radioInicial = 50;

vector<pair<float, float>> posiciones;

void interpolacion()
{
    // Posiciones para los circulso de la izquierda
    // Primeros 180 grados
    int cantPosiciones = 180 / (int)abs((float)angle);
    posiciones.push_back(make_pair(x, y));

    auto iteradorIzq = posiciones.begin();
    double angleRadians = (angle) * (M_PI / 180); // Convert to radians
    double calculatedCos = cos(angleRadians);
    double calculatedSin = sin(angleRadians);

    for (int i = 0; i <= cantPosiciones*2; i++) {

        pair<float, float> point = posiciones.back();
        double pointX = (double)point.first - screenCenterX;
        double pointY = (double)point.second - screenCenterY;
        double rotatedXIzquierda = calculatedCos * (pointX) - calculatedSin * (pointY) + screenCenterX;
        double rotatedYIzquierda = calculatedSin * (pointX) + calculatedCos * (pointY) + screenCenterY;

        posiciones.push_back(pair<float, float>((float)rotatedXIzquierda, (float)rotatedYIzquierda));

        if (i == cantPosiciones) angle = -1 * angle;
    }
}

void draw() {
    int posActual = 0;
    vector<pair<float, float>>::iterator iteradorIzq = posiciones.begin();

    while (true) {

        if (posActual == posiciones.size() - 1) {
            posActual = 0;
            vector<pair<float, float>>::iterator iteradorIzq = posiciones.begin();
        }

        pair<float, float> point = (*iteradorIzq);
        int multiplicador = 1, radioTotal;

        for (int i = 0; i < cantidadDeCirculos; i++) {

            radioTotal = radioInicial * multiplicador;

            //Pasar los datos al GUI para que dibuje
            cout << point.first;
            cout << point.second;
            cout << radioTotal << endl;
            cout << point.first*-1;
            cout << point.second*-1;
            cout << radioTotal << endl;

            multiplicador += 2;
        }
        posActual++;
        iteradorIzq++;
    }
}

void generarPuntos() {
    
    interpolacion();

    wcout << "Posiciones del circulo izquierdo:\n";
    for (pair<float, float> posicion : posiciones)
    {
        wcout << posicion.first << "," << posicion.second;
        wcout << " -> ";
    }
    wcout << "\n" << endl;

    wcout << "Posiciones del circulo derecho:\n";
    for (pair<float, float> posicion : posiciones)
    {
        wcout << posicion.first*-1 << "," << posicion.second*-1;
        wcout << " -> ";
    }

    wcout << "\n" << endl;
    //draw();
}


