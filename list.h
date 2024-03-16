#ifndef LIST_H
#define LIST_H

typedef struct Node {
    void *data;
    struct Node *next, *prev;
} Node;

typedef struct {
    Node *first, *last;
    int quantity;
} Deque;

#include "alumnis.h"

Deque* initializeList ();

void destroyList (Deque *d);

int emptyList (Deque *d);

int sizeOfList (Deque *d);

void insertAtBeginning (Deque *d, Aluno *data);

void insertAtEnd (Deque *d, Aluno *data);

void remove_beginning (Deque *d);

void remove_end (Deque *d);

void remove_target (Deque *d, Aluno *data);

void remove_target_by_matricula(Deque *d, int matricula);


#endif