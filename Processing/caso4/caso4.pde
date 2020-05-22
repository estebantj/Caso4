double angle = -7;

float x1 = 0;
float y1 = -10;

float x2 = 0;
float y2 = 10;

float screenCenterX = 0;
float screenCenterY = 0;

int cantidadDeCirculos = 50;
int radioInicial = 50;

ArrayList<float[]> posiciones;

void interpolacion()
{
  int cantPosiciones = 180/(int)abs((float)angle);
  posiciones.add(new float[]{x1, y1});

  for (int i = 0; i < cantPosiciones*2; ++i) {
    float point[] = posiciones.get(i);

    double angleRadians = (angle ) * (Math.PI/180); // Convert to radians
    double rotatedXIzquierda = Math.cos(angleRadians) * (point[0] - screenCenterX) - Math.sin(angleRadians) * (point[1] - screenCenterY) + screenCenterX;
    double rotatedYIzquierda = Math.sin(angleRadians) * (point[0] - screenCenterX) + Math.cos(angleRadians) * (point[1] - screenCenterY) + screenCenterY;
    
    posiciones.add(new float[]{(float)rotatedXIzquierda, (float)rotatedYIzquierda});

    if (i == cantPosiciones) angle = -1*angle;
  }
}

void setup()
{
  posiciones = new ArrayList<float[]>();
  interpolacion();
  size(1366,768);
  println("posIzquierdas.size(): "+posiciones.size()); //<>//
}

int posActual = 0;

void draw() 
{
  if (posActual == posiciones.size()) posActual=0;
  background(0);
  translate(width/2, height/2);
  
  line(0,-1000,0,1000);
  noFill();

  float point[] = posiciones.get(posActual); //<>//
  int multiplicador = 1;
  float puntoX = point[0];
  float puntoY = point[1];
  
  for (int i = 0; i < cantidadDeCirculos; i++) {
    stroke(255,0,0);
    strokeWeight(2);
    circle(puntoX, puntoY, radioInicial*multiplicador);

    stroke(0,255,0);
    strokeWeight(2);
    circle(puntoX*-1, puntoY*-1, radioInicial*multiplicador);
    
    multiplicador+=2;  
  }

  posActual++;
}
