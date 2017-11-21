#include "matrix.h"

matrix_element* create_matrix(int row, int col)
{
	matrix_element* Matrix = NULL;
	Matrix = (matrix_element*)malloc(sizeof(matrix_element)*row*col);
	for(int i=0, k=0;i<row;i++){
		for(int j=0;j<col;j++){
				Matrix[k].index_row = i;
				Matrix[k].index_col = j;
				k++;
			}		
		}
	Matrix[row*col].index_row = -1;
	return Matrix;
};

matrix_element* create_matrix_from_file(FILE* file)
{
	int row = 0;
	int col = 0;
	int ElementCounter = 0;
	matrix_element* Matrix = NULL;
	double element;
	char c;
	char* ElementInString;
	int SizeOfString = 0;
	fpos_t begin;
	fpos_t end;
	
	fgetpos(file,&begin);
	do {
      c = fgetc (file);
      if (!isspace(c))
			{
				SizeOfString++;
			}
	  else
			{
				if(SizeOfString == 0){continue;}
				fgetpos(file,&end);
				ElementInString = (char*)malloc(sizeof(char)*SizeOfString);
				fsetpos(file,&begin);
				for(int i=0;i<=SizeOfString;i++){ElementInString[i] = fgetc(file);}
				element = atof(ElementInString);
				free(ElementInString);
				begin = end;
				fsetpos(file,&begin);
				SizeOfString = 0;
				if(ElementCounter == 0)
						{row = element;}
				if(ElementCounter == 1)
					{
						col = element;
						Matrix = create_matrix(row, col);
					}
				if(ElementCounter > 1 && ElementCounter < (row*col+2))
					{Matrix[ElementCounter-2].value = element;}
				ElementCounter++;
			}
    } while (c != EOF);
	return Matrix;
};

void pretty_print(matrix_element* Matrix)
{
	int row = get_rows(Matrix);
	int col = get_cols(Matrix);
	for(int i=0;i<row*col;i++)
		{
			printf("Matrix[%d]:\n", i);
			printf("\tindex_row = %d\n", Matrix[i].index_row);
			printf("\tindex_col = %d\n", Matrix[i].index_col);
			printf("\tvalue = %f\n", Matrix[i].value);
		}
};

void free_matrix(matrix_element* Matrix)
{
	free(Matrix);
};

double get_elem(matrix_element* Matrix, int row, int col)
{
	int row_size = get_rows(Matrix);
	int col_size = get_cols(Matrix);
	if((!(0<=row)||!(row<row_size))||(!(0<=col)||!(col<col_size)))
		{printf("Can`t get element! Wrong index."); return 0;}
	return Matrix[row*col_size + col].value;
}

void set_elem(matrix_element* Matrix, int row, int col, double val)
{
	int row_size = get_rows(Matrix);
	int col_size = get_cols(Matrix);
	if((!(0<=row)||!(row<row_size))||(!(0<=col)||!(col<col_size)))
		{printf("Can`t get element! Wrong index.");}
	//printf("Row size is = %d\n", row_size);
	//printf("Col size is = %d\n", col_size);
	Matrix[row*col_size + col].value = val;
}

int get_rows(matrix_element* Matrix)
{
	int i = 0;
	while(Matrix[i].index_row != -1){i++;}
	int row_size = Matrix[i-1].index_row + 1;
	return row_size;
}

int get_cols(matrix_element* Matrix)
{
	int i = 0;
	while(Matrix[i].index_row != -1){i++;}
	int col_size = Matrix[i-1].index_col + 1;
	return col_size;
}

matrix_element* matrix_multiplication(matrix_element* Matrix_1, matrix_element* Matrix_2)
{
	if(get_cols(Matrix_1) != get_rows(Matrix_2))
		{printf("Number of columns in Matrix_1 is not equal to the number of rows in Matrix_2"); return NULL;}
	matrix_element* Rezult_Matrix = create_matrix(get_rows(Matrix_1), get_cols(Matrix_2));
	for(int i=0;i<get_rows(Rezult_Matrix);i++){
		for(int j=0;j<get_cols(Rezult_Matrix);j++){
				double value = 0;
				for(int k=0;k<get_cols(Matrix_1);k++)
					{
						value += get_elem(Matrix_1, i, k)*get_elem(Matrix_2, k, j);
					}
				set_elem(Rezult_Matrix, i, j, value);
				}
		}		
	return Rezult_Matrix;
}
