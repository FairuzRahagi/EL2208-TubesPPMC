#ifndef _FILES_H_
#define _FILES_H_

void readMaze(char* filename, int*** pMaze, int* pRow, int* pCol, int** pStart, int** pDest);
void dijkstra(maze, row, col, start, dest);
void printMatrix(maze, row, col, start, dest);

#endif
