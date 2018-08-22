#include "incremental2.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void line1(int xStart, int yStart, int xEnd, int yEnd, void (*plotf)(int, int)) {
  long double m, b, x, y;
  int deltaX, deltaY, last, i;

  deltaX = (xEnd - xStart);
  deltaY = (yEnd - yStart);

  if (abs(deltaX) > abs(deltaY)) {
    m = deltaY / (float)deltaX;
    b = yStart - m * xStart;
    last = fmax(xStart, xEnd);
    for ( i = fmin(xStart, xEnd); i < last; i++  ){
      y = i * m + b;
      plotf(i, round(y));
    }
  } else {
    m = deltaX / (float)deltaY;
    b = xStart - m * yStart;
    last = fmax(yStart, yEnd);
    for ( i =  fmin(yStart, yEnd); i < last; i++  ){
      x = i * m + b;
      plotf(round(x), i);
    }
  }
}
