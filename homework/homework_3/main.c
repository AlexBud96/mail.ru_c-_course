#include "vector.h"


int main(int argc, char* argv[])
{
	if(argc != 3){
fputs("Invalid number of arguments.", stdout);
}
	FILE *file_1 = fopen(argv[1], "r");
	if (file_1==NULL) {fputs ("Can`t open file 1\n",stdout); exit (EXIT_FAILURE);}
	FILE *file_2 = fopen(argv[2], "w");
	if (file_2==NULL) {fputs ("Can`t open file 2\n",stdout); exit (EXIT_FAILURE);}

	vector* v = read_vector_from_file(file_1);
	fclose(file_1);
	qsort_vector(v);
	write_vector_to_file(v, file_2);
	fclose(file_2);
	vector_free(v);
	return 0;
}
