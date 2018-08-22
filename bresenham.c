#include "bresenham.h"
#include <stdlib.h>
#include <stdio.h>

void bresenhamOctante1(int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int));
void bresenhamOctante2(int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int));
void bresenhamOctante3(int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int));
void bresenhamOctante4(int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int));

int deltaX, deltaY;

void line4(int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int)){
  deltaX = (xEnd - xStart);
  deltaY = (yEnd - yStart);

  if (yStart < yEnd) { // mitad superior
    if (xStart < xEnd){ // cuadrante derecho
      if (abs(deltaX) > abs(deltaY)){ // Octante 1
        bresenhamOctante1(xStart, yStart, xEnd, yEnd, plot);
      } else { // Octante 2
        bresenhamOctante2(xStart, yStart, xEnd, yEnd, plot);
      }
    }
    else{ // cuadrante izquierdo
      if (abs(deltaX) < abs(deltaY)){ // Octante 3
        bresenhamOctante3(xStart, yStart, xEnd, yEnd, plot);
      } else { // Octante 4
        bresenhamOctante4(xStart, yStart, xEnd, yEnd, plot);
      }
    }
  } else { // mitad inferior
    if (xStart < xEnd){ // cuadrante derecho
      if (abs(deltaX) > abs(deltaY)){ // Octante 8
        bresenhamOctante4(xEnd, yEnd, xStart, yStart, plot);
      } else { // Octante 7
        bresenhamOctante3(xEnd, yEnd, xStart, yStart, plot);
      }
    }
    else{ // cuadrante izquierdo
      if (abs(deltaX) < abs(deltaY)){ // Octante 6
        bresenhamOctante2(xEnd, yEnd, xStart, yStart, plot);
      } else { // Octante 5
        bresenhamOctante1(xEnd, yEnd, xStart, yStart, plot);
      }
    }  
  }
} 

void bresenhamOctante1 (int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int)) {
  int DeltaE, DeltaNE, d, Xp, Yp;

  deltaX = xEnd - xStart;
  deltaY = yEnd - yStart;
  DeltaE = 2* deltaY;
  DeltaNE = 2* (deltaY - deltaX);
  Xp = xStart; Yp = yStart;
  plot(Xp, Yp);

  d = 2 * (deltaY - deltaX);
  while (Xp < xEnd) {
    if (d < 0){
      Xp ++;
      d = d + DeltaE;
    } else {
      Xp ++; Yp ++;
      d = d + DeltaNE;
    }
    plot(Xp, Yp);
  }
}

void bresenhamOctante2 (int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int)) {
  int DeltaN, DeltaNE, d, Xp, Yp, deltaX, deltaY;

  deltaX = xEnd - xStart;
  deltaY = yEnd - yStart;

  // Octante 2
  DeltaN = 2* deltaX;
  DeltaNE = 2* (deltaX - deltaY);
  Xp = xStart; Yp = yStart;
  plot(Xp, Yp);

  d = 2 * (deltaX - deltaY);
  while (Xp < xEnd) {
    if (d < 0){
      Yp ++;
      d = d + DeltaN;
    } else {
      Xp ++; Yp ++;
      d = d + DeltaNE;
    }
    plot(Xp, Yp);
  }
}

void bresenhamOctante3 (int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int)) {
  int DeltaN, DeltaNO, d, Xp, Yp, deltaX, deltaY;

  deltaX = xEnd - xStart;
  deltaY = yEnd - yStart;

  // Octante 3
  DeltaN = -2* deltaX;
  DeltaNO = 2* (-deltaY - deltaX);
  Xp = xStart; Yp = yStart;
  plot(Xp, Yp);

  d = 2 * (-deltaX - deltaY);
  while (Xp > xEnd) {
    if (d < 0){
      Yp ++;
      d = d + DeltaN;
    } else {
      Xp --; Yp ++;
      d = d + DeltaNO;
    }
    plot(Xp, Yp);
  }
}

void bresenhamOctante4 (int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int)) {
  int DeltaO, DeltaNO, d, Xp, Yp, deltaX, deltaY;

  deltaX = xEnd - xStart;
  deltaY = yEnd - yStart;

  // Octante 4
  DeltaO = 2* deltaY;
  DeltaNO = 2* (deltaY + deltaX);
  Xp = xStart; Yp = yStart;
  plot(Xp, Yp);

  d = 2 * (deltaY - deltaX);
  while (Xp > xEnd) {
    if (d < 0){
      Xp --;
      d = d + DeltaO;
    } else {
      Xp --; Yp ++;
      d = d + DeltaNO;
    }
    plot(Xp, Yp);
  }
}
