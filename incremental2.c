#include "incremental2.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void swap1(int *x1,int *y1, int *x2, int *y2);

void line3(int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int)) {
  long double x, y, paso_x, paso_y;
  int i, ancho, deltaX, deltaY;

  deltaX = (xEnd - xStart);
  deltaY = (yEnd - yStart);
  ancho = fmax(abs(deltaX), abs(deltaY));
  paso_x = deltaX/(float)ancho;
  paso_y = deltaY/(float)ancho;
  x = xStart; y = yStart;
  
  for (i = 0; i <= ancho; i++) {
    plot(round(x), round(y));
    x += paso_x;
    y += paso_y;
  }
}

void swap1(int *x1,int *y1, int *x2, int *y2){
  *x1 += *x2;
  *y1 += *y2;
  *x2 = *x1 - *x2;
  *y2 = *y1 - *y2;
  *x1 -= *x2;
  *y1 -= *y2;
}
