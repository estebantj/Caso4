#include "parte2.h"

//Definicion de variables
double angle = -7;

float x = 0, y = -100;
float x2 = 0, y2 = 100;
float screenCenterX = 0, screenCenterY = 0;

int cantidadDeCirculos = 5, radioInicial = 50;

vector<pair<float, float>> posIzquierdas;
vector<pair<float, float>> posDerechas;

void interpolacion()
{
    // Posiciones para los circulso de la izquierda
    // Primeros 180 grados
    int cantPosiciones = 180 / (int)abs((float)angle);
    posIzquierdas.push_back(make_pair(x, y));
    posDerechas.push_back(make_pair(x2, y2));

    auto iteradorIzq = posIzquierdas.begin();
    auto iteradorDer = posDerechas.begin();

    for (int i = 0; i <= cantPosiciones; i++) {

        pair<float, float> point = posIzquierdas.back();

        double angleRadians = (angle) * (M_PI / 180); // Convert to radians
        double rotatedXIzquierda = cos(angleRadians) * ((double)point.first - screenCenterX) - sin(angleRadians) * ((double)point.second - screenCenterY) + screenCenterX;
        double rotatedYIzquierda = sin(angleRadians) * ((double)point.first - screenCenterX) + cos(angleRadians) * ((double)point.second - screenCenterY) + screenCenterY;

        posIzquierdas.push_back(pair<float, float>((float)rotatedXIzquierda, (float)rotatedYIzquierda));

        point = posDerechas.back();

        double rotatedXDerecha = cos(angleRadians) * ((double)point.first - screenCenterX) - sin(angleRadians) * ((double)point.second - screenCenterY) + screenCenterX;
        double rotatedYDerecha = sin(angleRadians) * ((double)point.first - screenCenterX) + cos(angleRadians) * ((double)point.second - screenCenterY) + screenCenterY;

        posDerechas.push_back(pair<float, float>((float)rotatedXDerecha, (float)rotatedYDerecha));

        if (i == cantPosiciones / 2) angle = -1 * angle;
    }
}

void draw() {
    int posActual = 0;
    vector<pair<float, float>>::iterator iteradorDer = posDerechas.begin();
    vector<pair<float, float>>::iterator iteradorIzq = posIzquierdas.begin();

    while (true) {

        if (posActual == posIzquierdas.size() - 1) {
            posActual = 0;
            vector<pair<float, float>>::iterator iteradorDer = posDerechas.begin();
            vector<pair<float, float>>::iterator iteradorIzq = posIzquierdas.begin();
        }

        pair<float, float> point = (*iteradorIzq);
        pair<float, float> point2 = (*iteradorDer);;
        int multiplicador = 1, radioTotal;
        for (int i = 0; i < cantidadDeCirculos; i++) {

            radioTotal = radioInicial * multiplicador;

            //Pasar los datos al GUI para que dibuje
            cout << point.first;
            cout << point.second;
            cout << radioTotal << endl;
            cout << point2.first;
            cout << point2.second;
            cout << radioTotal << endl;

            multiplicador += 2;
        }
        posActual++;
        iteradorDer++;
        iteradorIzq++;
    }
}
void generarPuntos() {
    interpolacion();

    wcout << "Posiciones del circulo izquierdo:\n";
    for (pair<float, float> posicion : posIzquierdas)
    {
        wcout << posicion.first << "," << posicion.second;
        wcout << " -> ";
    }
    wcout << "\n" << endl;

    wcout << "Posiciones del circulo derecho:\n";
    for (pair<float, float> posicion : posDerechas)
    {
        wcout << posicion.first << "," << posicion.second;
        wcout << " -> ";
    }

    wcout << "\n" << endl;
    //draw();
}


