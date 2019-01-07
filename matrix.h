#include <stdio.h>  	/* scanf, printf, NULL */  
#include <stdlib.h> 	/* malloc, atoi, free */
#include <math.h>	/* fabs */


void print(double **inputArray, double *b, int size);

void ScaleRow(double **inputArray, double *b,  int size, int Row, double k);

void AddRow(double **inputArray, double *b, int size, int fromRow, int toRow);

void swapRow(double **inputArray, double *b, int size, int Row1, int Row2);

double max(double *inputRow, int size);

int matchIndex(double *inputRow, double entry);

void ZeroTemp(double *inputTemp, int size);

double getDouble();

void flush(); 


