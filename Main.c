#include "Djikstra.c"
#include "files.c"
#include "files.h"
#include <stdio.h>

int main() {
  char filename[20];
  printf("Masukkan nama file input: ");
  scanf("%s", filename);

  int** maze;
  int row, col;
  int* start;
  int* dest;

  readMaze(filename, &maze, &row, &col, &start, &dest);

  djikstra()

  printMatrix(row, col, maze);
  return 0;
}
