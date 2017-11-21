#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

typedef struct matrix_element {
	int index_row;
	int index_col;
	double value;
} matrix_element;

matrix_element* create_matrix(int row, int col);
matrix_element* create_matrix_from_file(FILE* file);
void pretty_print(matrix_element* Matrix);
void free_matrix(matrix_element* Matrix);
double get_elem(matrix_element* Matrix, int row, int col);
void set_elem(matrix_element* Matrix, int row, int col, double val);
int get_rows(matrix_element* Matrix);
int get_cols(matrix_element* Matrix);
matrix_element* matrix_multiplication(matrix_element* Matrix_1, matrix_element* Matrix_2);

#endif //_MATRIX_H_
