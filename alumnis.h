#ifndef ALUMNIS_H
#define ALUMNIS_H

typedef struct Data_de_Nascimento {
    int dia;
    int mes;
    int ano;
} Data_de_Nascimento;

typedef struct Aluno {
    char nome [100];
    int numero_matricula;
    char curso [50];
    Data_de_Nascimento aniversario;
} Aluno;

#include "list.h"

void adicionar_aluno (Deque *Alunos);

void buscar_aluno (Deque *Alunos);

void listar_alunos (Deque *Alunos);

void exibir_aluno (Aluno *aluno);

void editar_aluno (Deque *Alunos);

void menu_de_edicao (Aluno *aluno);

void excluir_aluno (Deque *Alunos);


#endif