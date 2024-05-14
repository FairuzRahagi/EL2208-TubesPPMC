#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void readMaze(char* filename, int*** pMaze, int* pRow, int* pCol, int** pStart, int** pDest) {
  FILE* fp = fopen(filename, "r");
  char buf[1024];
  
  if (fp == NULL) {
    printf("File tidak ditemukan.\n");
    exit(0);
  }
  
  if (fgets(buf, 1024, fp) != NULL) {
    buf[strcspn(buf, "\n")] = 0;
    *pRow = 1;
    *pCol = strlen(buf);
    while (fgets(buf, 1024, fp) != NULL) {
      buf[strcspn(buf, "\n")] = 0;
      int col = strlen(buf);
      if (*pCol != col) {
        printf("Bentuk maze bukan persegi atau persegi panjang!\n");
        exit(0);
      }
      (*pRow)++;
    }
  } else {
    printf("File kosong!\n");
    exit(0);
  }

  *pStart = calloc(2, sizeof(int));
  *pDest = calloc(2, sizeof(int));
  (*pMaze) = malloc((*pRow) * sizeof(int*));
  (*pMaze)[0] = malloc((*pCol) * sizeof(int));

  rewind(fp);
  int ch, i = 0, j = 0;
  while ((ch = getc(fp)) != EOF) {
    if (ch == '\n') {
      i++;
      (*pMaze)[i] = malloc((*pRow) * sizeof(int));
      j = -1;
    } else if (ch == 'S') {
      (*pStart)[0] = i;
      (*pStart)[1] = j;
      (*pMaze)[i][j] = 1;
    } else if (ch == 'E') {
      (*pDest)[0] = i;
      (*pDest)[1] = j;
      (*pMaze)[i][j] = 1;
    } else if (ch == '.') (*pMaze)[i][j] = 1;
    else if (ch == '#') (*pMaze)[i][j] = 0;
    else {
      printf("Terdapat karakter tidak valid!\n");
      exit(0);
    }
    j++;
  }

  fclose(fp);
  return;
}

void printMatrix(int rows, int cols, int** matrix) { // debug -> (char (*(*)[N]))maze / (int(**) [12])maze, 11
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
