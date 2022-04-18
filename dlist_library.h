#ifndef DOUBLY_LINKED_LIST_DLIST_LIBRARY_H
#define DOUBLY_LINKED_LIST_DLIST_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} dnode_t;

typedef struct dList {
    dnode_t *first;
    dnode_t *last;
} dlist_t;

void print_list(dlist_t *list);
void add_first(dlist_t *list, int new_data);
void add_last(dlist_t *list, int new_data);
void add_before(dlist_t *list, int key, int new_data);
void add_after(dlist_t *list, int key, int new_data);
dnode_t *search_list(dlist_t *list, int key);
dlist_t *init_empty();
void del_first(dlist_t *list);
void del_last(dlist_t *list);
void del_before(dlist_t *list, int key);
void del_after(dlist_t *list, int key);

#endif //DOUBLY_LINKED_LIST_DLIST_LIBRARY_H
