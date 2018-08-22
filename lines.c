/*
 * Instituto Tecnologico de Costa Rica
 * Escuela de Ingenieria en Computacion
 * Computer Graphics
 *
 * Programa: lineas
 * Archivo:  lineas.c
 */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "lines.h"
#include "malloc.h"
#include "fuerzaBruta.h"
#include "incremental1.h"
#include "incremental2.h"
#include "bresenham.h"

// Debug
#include <math.h>

void draw_scene ();

void render();
void mark();
int xStart, yStart, xEnd, yEnd;

int main(int argc, char** argv) {
  if (argc != 5){
    exit(1);
  }
  xStart = atoi(argv[1]);
  yStart = atoi(argv[2]);
  xEnd = atoi(argv[3]);
  yEnd = atoi(argv[4]);


  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(H_SIZE, V_SIZE);
  glutCreateWindow("Simple GLUT Application");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);

  glutDisplayFunc(render);
  glutMainLoop();
}

void elCicloDeLaMalaria () {
  int x, y;
  int radio = 100;
  int centro = 200;
  float rad;
  for (int i = 0; i < 360; i++) {
    rad = i * 3.1415 / 180;
    x = (radio * cos(rad)) + centro;
    y = (radio * sin(rad)) + centro;
    setColor(sin(rad), cos(rad), 1);
    line4(centro, centro, x, y, plot);
  }
}

void render() {
  int i, j;

  setColor(0, 0, 0);
  for (i = 0; i < H_SIZE; i++) 
  {
    for (j = 0; j < V_SIZE; j++) 
    {
      mark(i, j);
    }
  }

  elCicloDeLaMalaria();
  glFlush();
}

void mark(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void plot(int x, int y) {
  mark(x, y);
}

void noplot(int x, int y) {
  return;
}

void setColor(float r, float g, float b){
  glColor3f(r, g, b);
}
