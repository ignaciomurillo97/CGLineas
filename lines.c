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
#include "color.h"
#include "incremental1.h"

void draw_scene ();

COLOR **buffer;
COLOR *currColor;


void render();

int main(int argc, char** argv) {
  int i, j;
  currColor = (COLOR*)malloc(sizeof(COLOR));

  buffer = (COLOR **)malloc(H_SIZE * sizeof(COLOR*));
  for (i = 0; i < H_SIZE; i++) 
  {
    buffer[i] = (COLOR *)malloc(V_SIZE * sizeof(COLOR));
    for (j = 0; j < V_SIZE; j++) 
    {
      buffer[i][j].r = 0;
      buffer[i][j].g = 0;
      buffer[i][j].b = 0;
    }
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(H_SIZE, V_SIZE);
  glutCreateWindow("Simple GLUT Application");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
  glutDisplayFunc(render);
  glutMainLoop();
}

void render() {
  int x, y;

  setColor(1, 1, 1);
  incrementalLine(10, 10, 9, 100);

  for (x = 0; x < H_SIZE; x++) {
    for (y = 0; y < V_SIZE; y++) {
      COLOR currentColor = buffer[x][y];
      glColor3f(currentColor.r, currentColor.g, currentColor.b);
      glBegin(GL_POINTS);
      glVertex2i(x, y);
      glEnd();
    }
  }
  glFlush();
}

void plot(int x, int y) {
  buffer[x][y] = *currColor;
}

void setColor(float r, float g, float b){
  currColor->r = r;
  currColor->g = g;
  currColor->b = b;
}
