#ifndef ALUMNIS_H
#define ALUMNIS_H

#include "list.h"

typedef struct Data_de_Nascimento {
    short int dia;
    short int mes;
    short int ano;
} Data_de_Nascimento;

typedef struct Aluno {
    char nome [50];
    int numero_matricula;
    char curso [30];
    Data_de_Nascimento aniversario;
} Aluno;

void adicionar_aluno (Deque *Alunos);

void excluir_aluno (Deque *Alunos);

void listar_alunos (Deque *Alunos);

void editar_aluno (Deque *Alunos);

void buscar_aluno (Deque *Alunos);


#endif