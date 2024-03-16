#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next, *prev;
} Node;

typedef struct {
    Node *first, *last;
    int quantity;
} Deque;

void initializeList ();

void destroyList (Deque *d);

int emptyList (Deque *d);

int sizeOfList (Deque *d);

void insertAtBeginning (Deque *d, void *data);

void insertAtEnd (Deque *d, void *data);

void remove_beginning (Deque *d);

void remove_end (Deque *d);


#endif