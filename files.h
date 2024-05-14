#ifndef _FILES_H_
#define _FILES_H_

char** readMaze(char* filename, int*** pMaze, int* pRow, int* pCol, int** pStart, int** pDest);
void printMatrix(int rows, int cols, int** matrix);

#endif
