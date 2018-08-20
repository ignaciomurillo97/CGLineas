#include "incremental1.h"
#include <math.h>
#include <stdio.h>

void incrementalLine(int xStart, int yStart, int xEnd, int yEnd) {
  if (xStart != xEnd) {
    long double m, y;
    int i;

    m = (yStart - yEnd) / (xStart - xEnd);
    y = yStart;
    for (i = 0; i < xEnd; i ++) {
      plot(i, round(y));
      y += m;
    }
  } else {
    fprintf(stderr, "No se puede calcular una pendiente vertical");
  }
}
