#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
// Vector
typedef struct vector {
	int *data;
	int size;
	int allocated;
} vector;

void vector_init(vector *v);
int vector_size(const vector *v); // const position?
int vector_allocated(const vector *v);
void print_vector(const vector *v);
void vector_push(vector *v, int d);
void vector_set(vector *v, int index, int d);
int* vector_get(const vector *v, int index);
void vector_free(vector *v);
vector* read_vector_from_file(FILE *file);
void write_vector_to_file(vector *v, FILE *file);
void qsort_vector(vector *v);

#endif
