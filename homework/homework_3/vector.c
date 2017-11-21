#include "vector.h"

#define MEMORY_ERR 1

//enum {
	//MEMORY 0,
//	FILE,
//}

void vector_init(vector *v) {
  v->size = 0;
  v->allocated = 1;
  if(!(v->data = realloc(v->data, (v->allocated)*sizeof(v->data[0])))){
		printf("Error: can't reallocate memory"); // stderr
		//exit(1);
	};
}
// Vector* vector, VECTOR* vector
void vector_push(vector *v, int d){
	if(v->size == v->allocated){
	if(!(v->data = realloc(v->data, (v->allocated * 2)*sizeof(v->data[0])))){
		printf("Error: can't reallocate memory");
		exit(2);
	};
	v->allocated *= 2;
	}
	v->data[v->size] = d;
	v->size++;
}

vector* read_vector_from_file(FILE *file)
{
	static vector v;
	vector_init(&v);
// if v == NULL rerun NULL	
while (!feof (file))  // gets(), strtok()
    {  
      int d;
      fscanf (file, "%d", &d); // if 
	  vector_push(&v, d);     
    }
	return &v;
}

void write_vector_to_file(vector *v, FILE *file)
{
	fprintf(file, "[");
	for(int i = 0; i < v->size-1; i++)
	{
    	fprintf(file, "%d, ", v->data[i]);
	}
	fprintf(file, "%d", v->data[v->size-1]);
	fprintf(file, "]\n");
}

void qsort_vector(vector *v)
{
	int compare (const void * a, const void * b)
	{
  		return ( *(int*)a - *(int*)b );
	}
	qsort(v->data, v->size, sizeof(int), compare); // что внутри?
}

int vector_size(const vector *v)
{
    return v->size;
}

int vector_allocated(const vector *v)
{
    return v->allocated;
}

void print_vector(const vector *v)
{	
	printf("[");
	for(int i = 0; i < v->size-1; i++)
	{
    	printf("%d, ", v->data[i]);
	}
	printf("%d", v->data[v->size-1]);
	printf("]\n");
}

void vector_set(vector *v, int index, int d)
{
    if (index >= 0 && index < v->size)
        v->data[index] = d;
}

int* vector_get(const vector *v, int index)
{
    if (index >= 0 && index < v->size)
        return &v->data[index];
    return NULL;
}

void vector_free(vector *v)
{
    free(v->data);
}
