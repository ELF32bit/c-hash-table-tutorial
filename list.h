#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef int bool;

typedef struct ListNode {
	void* data;
	size_t data_size;
	struct ListNode* next;
} ListNode;

typedef struct List {
	ListNode* head;
} List;

List* list_new();
void list_push(List* list, void* data, size_t data_size);
bool list_find(const List* list, const void* data, size_t data_size);
void list_free(List* list);

#endif
