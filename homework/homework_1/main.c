#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "htable.h"


char* getWord(FILE *fp);

void read_to_htable(FILE *fp, struct htable* hash_table);

int main(int argc, char **argv){
	int value;
	struct htable* hash_table[argc];
	FILE* pFile;
	hash_table[0] = htable_new();
	for(int i = 1;i<argc;++i){
		pFile = fopen(argv[i], "r");
		if(pFile==NULL)
			{
				printf("ERROR: File not opened.\n");
				return 1;
			}
		read_to_htable(pFile, hash_table[0]);
		fclose(pFile);
	}

	for(int i = 1;i<argc;++i){
		pFile = fopen(argv[i], "r");
		hash_table[i] = htable_new();
		if(pFile==NULL)
			{
				printf("ERROR: File not opened.\n");
				return 1;
			}
		read_to_htable(pFile, hash_table[i]);
		fclose(pFile);
	}

	for(size_t item_idx = 0; item_idx < hash_table[0]->size; item_idx++) {
		struct htable_item* curr_item = hash_table[0]->items_table[item_idx];
		while(curr_item) {
		  struct htable_item* next_item = curr_item->next;
		  int value[argc], count = 0;
		  for(int i = 0;i<argc;++i){
				value[i] = htable_get(hash_table[i], curr_item->key, strlen(curr_item->key)*sizeof(char));
				if(value[i]!=0)
					++count;
			}
		  if(count > 4){
				printf("For key %s we have %d congruences.:\n", curr_item->key, value[0]);
				for(int i =1;i<argc;i++){
					if(value[i] != 0)
						printf("\tIn %s we have %d congruences.\n", argv[i], value[i]);
				}
			}
		  //printf("%s : %d\n", curr_item->key, curr_item->value);
		  curr_item = next_item;
		}
  }
	
	for(;argc--;){
		htable_free(hash_table[argc]);
	}
};


char *getWord(FILE *fp)
{
    char word[100];
    int ch; 
    size_t idx ;

    for (idx=0; idx < sizeof(word) -1; ) {
        ch = fgetc(fp);
        if (ch == EOF) break;
        if (!isalpha(ch)) {
           if (!idx) continue; // Nothing read yet; skip this character
           else break; // we are beyond the current word
           }
        word[idx++] = tolower(ch);
        }
    if (!idx) return NULL; // No characters were successfully read
    word[idx] = '\0';
    return strdup(word);
};

void read_to_htable(FILE *fp, struct htable* hash_table){
    char *word;
	int value;
    while(word=getWord(fp)){
	 value = htable_get(hash_table, word, strlen(word)*sizeof(char));
	 if(value != 0){
		//printf("THERE is value %d for key %s\n", value, word);
	 }
	 value++;
     htable_set(hash_table, word, strlen(word)*sizeof(char), value);
	 free(word);
	}
};
