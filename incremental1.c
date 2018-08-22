#include "incremental1.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *x1,int *y1, int *x2, int *y2);

void line2(int xStart, int yStart, int xEnd, int yEnd, void (*plot)(int, int)) {
  int i;
  if (abs(xEnd - xStart) > abs(yEnd - yStart)){
    if (xEnd < xStart) {
      swap(&xStart, &yStart, &xEnd, &yEnd);
    }
    long double m, y;
    m = (yStart - yEnd) / (long double)(xStart - xEnd);
    y = yStart;
    for (i = xStart; i < xEnd; i ++) {
      plot(i, floor(y));
      y += m;
    }
  } else {
    if (yEnd < yStart) {
      swap(&xStart, &yStart, &xEnd, &yEnd);
    }
    long double m, x;
    m = (xStart - xEnd) / (long double)(yStart - yEnd);
    x = xStart;
    for (i = yStart; i < yEnd; i ++) {
      plot(floor(x), i);
      x += m;
    }
  }
}

void swap(int *x1,int *y1, int *x2, int *y2){
  *x1 += *x2;
  *y1 += *y2;
  *x2 = *x1 - *x2;
  *y2 = *y1 - *y2;
  *x1 -= *x2;
  *y1 -= *y2;
}
