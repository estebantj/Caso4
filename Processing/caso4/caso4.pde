double angle = -7;

float x1 = 0;
float y1 = -10;

float x2 = 0;
float y2 = 10;

float screenCenterX = 0;
float screenCenterY = 0;

int cantidadDeCirculos = 5;
int radioInicial = 50;

ArrayList<float[]> posIzquierdas;
ArrayList<float[]> posDerechas;

void interpolacion()
{
  int cantPosiciones = 180/(int)abs((float)angle);
  posIzquierdas.add(new float[]{x1, y1});
  posDerechas.add(new float[]{x2, y2});

  for (int i = 0; i < cantPosiciones*2; ++i) {
    float point[] = posIzquierdas.get(i);

    double angleRadians = (angle ) * (Math.PI/180); // Convert to radians
    double rotatedXIzquierda = Math.cos(angleRadians) * (point[0] - screenCenterX) - Math.sin(angleRadians) * (point[1] - screenCenterY) + screenCenterX;
    double rotatedYIzquierda = Math.sin(angleRadians) * (point[0] - screenCenterX) + Math.cos(angleRadians) * (point[1] - screenCenterY) + screenCenterY;
    
    posIzquierdas.add(new float[]{(float)rotatedXIzquierda, (float)rotatedYIzquierda});

    point = posDerechas.get(i);
    double rotatedXDerecha = Math.cos(angleRadians) * (point[0] - screenCenterX) - Math.sin(angleRadians) * (point[1] - screenCenterY) + screenCenterX;
    double rotatedYDerecha = Math.sin(angleRadians) * (point[0] - screenCenterX) + Math.cos(angleRadians) * (point[1] - screenCenterY) + screenCenterY;
    
    posDerechas.add(new float[]{(float)rotatedXDerecha, (float)rotatedYDerecha});
    
    if (i == cantPosiciones) angle = -1*angle;
  }
}

void setup()
{
  posIzquierdas = new ArrayList<float[]>();
  posDerechas = new ArrayList<float[]>();
  interpolacion();
  size(1366,768);
  println("posIzquierdas.size(): "+posIzquierdas.size()); //<>//
  println("posDerechas.size(): "+posDerechas.size());
}

int posActual = 0;

void draw() 
{
  if (posActual == posIzquierdas.size()) posActual = 0;
  background(0);
  translate(width/2, height/2);
  
  line(0,-1000,0,1000);
  noFill();

  float point[] = posIzquierdas.get(posActual);
  float point2[] = posDerechas.get(posActual); //<>//
  int multiplicador = 1;

  for (int i = 0; i < cantidadDeCirculos; i++) {
    stroke(255,0,0);
    strokeWeight(2);
    circle(point[0], point[1], radioInicial*multiplicador);

    stroke(0,255,0);
    strokeWeight(2);
    circle(point2[0], point2[1], radioInicial*multiplicador);
    multiplicador+=2;  
  }

  posActual++;
}
