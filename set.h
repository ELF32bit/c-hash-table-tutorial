#ifndef SET_H
#define SET_H

#include "list.h"
#include <stdio.h>

typedef struct Set {
	List** hash_table;
	size_t hash_table_size;
} Set;

Set* set_new(size_t hash_table_size);
void set_add(Set* set, const char* string);
bool set_find(const Set* set, const char* string);
void set_print(const Set* set);
void set_free(Set* set);

#endif
