#include "dlist_library.h"


void print_list(dlist_t *list)
{
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }

    dnode_t *current = list->first;

    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void add_first(dlist_t *list, int new_data)
{
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }

    dnode_t *new = (dnode_t *)malloc(sizeof(dnode_t));

    new->data = new_data;

    new->next = list->first;
    new->prev = NULL;

    if(list->first != NULL) {
        list->first->prev = new;
    }
    if(list->last == NULL) {
        list->last = new;
    }

    list->first = new;
}

void add_last(dlist_t *list, int new_data)
{
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }

    dnode_t *new = (dnode_t *)malloc(sizeof(dnode_t));

    new->data = new_data;
    new->next = NULL;
    new->prev = list->last;

    if(list->first == NULL) {
        list->first = new;
    }

    if(list->last != NULL) {
        list->last->next = new;
    }
    list->last = new;
}

dnode_t *search_list(dlist_t *list, int key)
{
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return NULL;
    }

    dnode_t *it = list->first;
    while(it != NULL && it->data != key) {
        it = it->next;
    }

    return it;
}

void add_before(dlist_t *list, int key, int new_data) {
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }
    dnode_t *it = search_list(list, key);

    if(it == list->first) {
        add_first(list, new_data);
        return;
    }

    if(!it) {
        return;
    }

    dnode_t *new = (dnode_t *)malloc(sizeof(dnode_t));

    new->data = new_data;

    new->next = it;
    new->prev = it->prev;
    it->prev = new;
    new->prev->next = new;

}
void add_after(dlist_t *list, int key, int new_data) {
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }

    dnode_t *it = search_list(list, key);

    if(it == list->last) {
        add_last(list, new_data);
        return;
    }

    if(!it) {
        return;
    }

    dnode_t *new = (dnode_t *)malloc(sizeof(dnode_t));

    new->data = new_data;

    new->prev = it;
    new->next = it->next;
    it->next = new;
    new->next->prev = new;

}

void del_first(dlist_t *list)
{
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }
    if(list->first == NULL) {
        return;
    }

    dnode_t *tmp = list->first;
    list->first = list->first->next;
    if(tmp) {
        free(tmp);
    }

    list->first->prev = NULL;
}

void del_last(dlist_t *list) {
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }

    if(list->last != NULL) {
        dnode_t *tmp = list->last;
        list->last = list->last->prev;
        free(tmp);
        list->last->next = NULL;
    }
}

void del_before(dlist_t *list, int key)
{
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }

    if(list->first == NULL) {
        return;
    }

    dnode_t *it = search_list(list, key);

    if(it != list->first && it) {
        dnode_t *tmp = it->prev;
        it->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        free(tmp);
    }
}

void del_after(dlist_t *list, int key)
{
    if(list == NULL) {
        fprintf(stderr, "List is empty\n");
        fflush(stderr);
        return;
    }

    if(list->first == NULL) {
        return;
    }

    dnode_t *it = search_list(list, key);

    if(it != list->last && it) {
        dnode_t *tmp = it->next;
        it->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
    }
}

dlist_t *init_empty()
{
    dlist_t *list = (dlist_t *)malloc(sizeof(dlist_t));

    list->first = NULL;
    list->last = NULL;

    return list;
}
