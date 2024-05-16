#include "Dijkstra2.c"
#include "files.c"
#include <stdio.h>
#include <time.h>

int main() {
  char filename[20];
  printf("Masukkan nama file input: ");
  scanf("%s", filename);

  int** maze;
  int row, col;
  int* start;
  int* dest;

  readMaze(filename, &maze, &row, &col, &start, &dest);
  clock_t start_time = clock();
  dijkstra(maze, row, col, start, dest);
  printMatrix(row, col, maze);
  clock_t end_time = clock();

  double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000.0;

  printf("Elapsed time: %.2f milliseconds\n", elapsed_time);
  return 0;
}

