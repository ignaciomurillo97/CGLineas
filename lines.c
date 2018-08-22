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
#include "time.h"
#include "sys/time.h"
#include "unistd.h"

// Debug
#include <math.h>

void draw_scene ();

void render();
void mark();
void plot(int x, int y);
void noplot(int x, int y);

int H_SIZE, V_SIZE, LINE_COUNT, REPETITION;
int **lineVector;

int main(int argc, char** argv) {
  if (argc != 4){
    printf("lines <resolucion> <# de lineas> <# numero de veces>");
    exit(1);
  }
  H_SIZE = atoi(argv[1]);
  V_SIZE = atoi(argv[1]);
  LINE_COUNT = atoi(argv[2]);
  REPETITION = atoi(argv[3]);

  srand(time(NULL));
  lineVector = (int**)malloc(sizeof(int*) * LINE_COUNT);
  for (int i = 0; i < LINE_COUNT; i++) {
    lineVector[i] = (int*)malloc(sizeof(int*) * 4);
    lineVector[i][0] = rand() % H_SIZE;
    lineVector[i][1] = rand() % V_SIZE;
    lineVector[i][2] = rand() % H_SIZE;
    lineVector[i][3] = rand() % V_SIZE;
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

void showLines (void(*lineArg)(int, int, int, int, void(*plotFunc)(int, int)), void(*plotFunc)(int, int)) {
  for (int i = 0; i < LINE_COUNT; i++) {
    int* curr = lineVector[i];
    lineArg(curr[0], curr[1], curr[2], curr[3], plotFunc);
  }
}

void timeAlgorithms () {
  struct timeval stop, start;
  setColor(1, 0, 0);
  gettimeofday(&start, NULL);
  for (int i = 0; i < REPETITION; i++) {
    showLines(line1, mark);
  }
  gettimeofday(&stop, NULL);
  printf("time line1: %i milliseconds\n", stop.tv_usec - start.tv_usec);
  glFlush();

  sleep(1);
  setColor(0, 1, 0);
  gettimeofday(&start, NULL);
  for (int i = 0; i < REPETITION; i++) {
    showLines(line2, mark);
  }
  gettimeofday(&stop, NULL);
  printf("time line2: %i milliseconds\n", stop.tv_usec - start.tv_usec);
  glFlush();

  sleep(1);
  setColor(0, 0, 1);
  gettimeofday(&start, NULL);
  for (int i = 0; i < REPETITION; i++) {
    showLines(line3, mark);
  }
  gettimeofday(&stop, NULL);
  printf("time line3: %i milliseconds\n", stop.tv_usec - start.tv_usec);
  glFlush();

  sleep(1);
  setColor(1, 1, 0);
  gettimeofday(&start, NULL);
  for (int i = 0; i < REPETITION; i++) {
    showLines(line4, mark);
  }
  gettimeofday(&stop, NULL);
  printf("time line4: %i milliseconds\n", stop.tv_usec - start.tv_usec);
  glFlush();

  // etero
  setColor(1, 0, 1);
  gettimeofday(&start, NULL);
  for (int i = 0; i < REPETITION; i++) {
    showLines(line1, noplot);
  }
  setColor(0, 1, 1);
  gettimeofday(&stop, NULL);
  printf("time line1 w/ null plot: %i milliseconds\n", stop.tv_usec - start.tv_usec);

  gettimeofday(&start, NULL);
  for (int i = 0; i < REPETITION; i++) {
    showLines(line2, noplot);
  }
  gettimeofday(&stop, NULL);
  printf("time line2 w/ null plot: %i milliseconds\n", stop.tv_usec - start.tv_usec);

  setColor(1, 1, 1);
  gettimeofday(&start, NULL);
  for (int i = 0; i < REPETITION; i++) {
    showLines(line3, noplot);
  }
  gettimeofday(&stop, NULL);
  printf("time line3 w/ null plot: %i milliseconds\n", stop.tv_usec - start.tv_usec);

  setColor(0.5, 0.5, 0.5);
  gettimeofday(&start, NULL);
  for (int i = 0; i < REPETITION; i++) {
    showLines(line4, noplot);
  }
  gettimeofday(&stop, NULL);
  printf("time line4 w/ null plot: %i milliseconds\n", stop.tv_usec - start.tv_usec);
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

  timeAlgorithms();
  glFlush();
}

void mark(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void plot(int x, int y) {
  mark(x, y);
  glFlush();
}

void noplot(int x, int y) {
  return;
}

void setColor(float r, float g, float b){
  glColor3f(r, g, b);
}
