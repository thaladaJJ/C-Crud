#include <stdlib.h>
#include <stdio.h>
#include "list.h"

Deque* initializeList () {

    Deque *deque = (Deque*) malloc (sizeof (Deque));
    
    if (deque == NULL) {
        printf ("Falha ao alocar memória para a lista.\n");
        exit (EXIT_FAILURE);
    }

    deque->first = NULL;
    deque->last = NULL;
    deque->quantity = 0;

    return deque;
}

void destroyList (Deque *d) {

    while (d->first != NULL) {
        Node *temp = d->first;
        d->first = d->first->next;
        free (temp);
    }

    d->first = NULL;
    d->last = NULL;
    d->quantity = 0;
}

int emptyList (Deque *d) {
    
    return d->first == NULL;
}

int sizeOfList (Deque *d) {
    
    return d->quantity;
}

void insertAtBeginning (Deque *d, Aluno *data) {

    Node *n = (Node*) malloc (sizeof (Node));

    if (n == NULL) {
        printf ("Falha ao inserir na lista. Memória insuficiente!");
        return;
    }

    n->data = data;
    n->prev = NULL;

    if (d->first == NULL) {
        d->first = n;
        d->last = n;
    }

    else {
        n->next = d->first;
        d->first->prev = n;
        d->first = n;
    }

    d->quantity++;
}

void insertAtEnd (Deque *d, Aluno *data) {

    Node *n = (Node*) malloc (sizeof (Node));

    if (n == NULL) {
        printf ("Falha ao inserir na lista. Memória insuficiente!\n");
        return;
    }
    
    n->data = data;
    n->next = NULL;

    if (d->last == NULL) {
        d->first = n;
        d->last = n;
    }

    else {
        n->prev = d->last;
        d->last->next = n;
        d->last = n;
    }

    d->quantity++;
}

void remove_beginning (Deque *d) {

    if (emptyList(d)) {
        printf ("Lista vazia, não foi possível remover.\n");
        return;
    }

    Node *temp = d->first;
    d->first = temp->next;

    if (d->first == NULL)
        d->last = NULL;
    
    else
        d->first->prev = NULL;
    
    d->quantity--;
}

void remove_end (Deque *d) {

    if (emptyList(d)) {
        printf ("Lista vazia, não foi possível remover.\n");
        return;
    }

    Node *temp = d->last;
    d->last = temp->prev;

    if (d->last == NULL)
        d->first = NULL;
    
    else
        d->last->next = NULL;
        
    d->quantity--;
}

void remove_target (Deque *d, Aluno *data) {

    Node *temp = d->first;

    while (temp != NULL) {

        Aluno *aluno = temp->data;

        if (aluno == data) {

            if (temp == d->first)
                remove_end (d);
            
            else if (temp == d->last)
                remove_beginning (d);
            
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free (temp);
                d->quantity--;
            }

            return;
        }

        temp = temp->next;
    }

}

void remove_target_by_matricula(Deque *d, int matricula) {
    
    Node *temp = d->first;

    while (temp != NULL) {
        Aluno *aluno = temp->data;

        if (aluno->numero_matricula == matricula) {

            if (temp == d->first)
                remove_beginning(d);
            
            else if (temp == d->last)
                remove_end(d);
            
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                d->quantity--;
            }

            return;
        }

        temp = temp->next;
    }

    printf("Aluno com a matrícula %d não encontrado na lista.\n", matricula);
}