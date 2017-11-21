#include "matrix.h"

int main(int argc, char* argv[])
{
	FILE *file_1 = fopen(argv[1], "r");
	FILE *file_2 = fopen(argv[2], "r");
	if (file_1==NULL) {fputs ("Can`t open file 1",stderr); exit (EXIT_FAILURE);}
	if (file_2==NULL) {fputs ("Can`t open file 2",stderr); exit (EXIT_FAILURE);}
	matrix_element* Matrix_1 = create_matrix_from_file(file_1);
	fclose(file_1);
	matrix_element* Matrix_2 = create_matrix_from_file(file_2);
	fclose(file_2);
	matrix_element* Rezult_Matrix = matrix_multiplication(Matrix_1, Matrix_2);
	pretty_print(Rezult_Matrix);
	printf("%d\n", get_rows(Rezult_Matrix));
	printf("%d\n", get_cols(Rezult_Matrix));
	free_matrix(Matrix_1);
	free_matrix(Matrix_2);
	free_matrix(Rezult_Matrix);
	return 0;
}
