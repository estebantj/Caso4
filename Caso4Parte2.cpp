# define M_PI     3.14159265358979323
#include <iostream>
#include <fstream>
#include <math.h>
#include <unordered_set>
using namespace std;


//Definicion de variables
double angle = -7;

float x1 = 0, y1 = -10;
float x2 = 0, y2 = 10;
float screenCenterX = 0, screenCenterY = 0;

int cantidadDeCirculos = 5, radioInicial = 50;

unordered_set<pair<float,float>> posIzquierdas;
unordered_set<pair<float,float>> posDerechas;
void interpolacion()
{
    // Posiciones para los circulso de la izquierda
    // Primeros 180 grados
    int cantPosiciones = 200/(int)abs((float)angle);
    posIzquierdas.insert(make_pair(x1,y1));
    posDerechas.insert(make_pair(x2,y2));

    auto     iteradorIzq = posIzquierdas.begin();
    auto iteradorDer = posDerechas.begin();

    for (int i = 0; i < cantPosiciones*2; ++i) {

        pair<float,float> point ;
        point.first = (*iteradorIzq).first;
        point.second = (*iteradorIzq).second;

        double angleRadians = (angle) * (M_PI/180); // Convert to radians
        double rotatedXIzquierda = cos(angleRadians) * (point.first - screenCenterX) -  sin(angleRadians) * (point.second - screenCenterY) + screenCenterX;
        double rotatedYIzquierda = sin(angleRadians) * (point.first - screenCenterX) +  cos(angleRadians) * (point.second- screenCenterY) + screenCenterY;

        posIzquierdas.insert(make_pair((float)rotatedXIzquierda, (float)rotatedYIzquierda));

        point.first = (*iteradorIzq).first;
        point.second = (*iteradorDer).second;

        double rotatedXDerecha = cos(angleRadians) * (point.first- screenCenterX) -  sin(angleRadians) * (point.second - screenCenterY) + screenCenterX;
        double rotatedYDerecha = sin(angleRadians) * (point.first - screenCenterX) +  cos(angleRadians) * (point.second - screenCenterY) + screenCenterY;

        posDerechas.insert(make_pair((float)rotatedXDerecha, (float)rotatedYDerecha));

        iteradorIzq++;
        iteradorDer++;
        if (i == cantPosiciones) angle = -1*angle;
    }
}

void draw(){
    int posActual = 0;
    unordered_set<pair<float,float>>::iterator iteradorDer = posDerechas.begin();
    unordered_set<pair<float,float>>::iterator iteradorIzq = posIzquierdas.begin();

    while(true){

        if(posActual == posIzquierdas.size()) {
            posActual = 0;
            unordered_set<pair<float,float>>::iterator iteradorDer = posDerechas.begin();
            unordered_set<pair<float,float>>::iterator iteradorIzq = posIzquierdas.begin();
        }

        pair<float,float> point;
        pair<float,float> point2;
        int multiplicador = 1, radioTotal;
        for(int i = 0; i < cantidadDeCirculos; i++){

            radioTotal = radioInicial*multiplicador;

            //Pasar los datos al GUI para que dibuje
            cout<< point.first;
            cout<< point.second;
            cout<< radioTotal<<endl;
            cout<< point2.first;
            cout<< point2.second;
            cout<< radioTotal<<endl;

            multiplicador +=2;
        }
        posActual++;
        iteradorDer++;
        iteradorIzq++;
    }
}
int main () {
    interpolacion();
    draw();
}

