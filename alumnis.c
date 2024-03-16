#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "alumnis.h"

void adicionar_aluno (Deque *Alunos) {

    Aluno novoAluno;

    printf ("Insira os dados do aluno:\n");

    printf ("Nome: ");
    scanf ("%s", novoAluno.nome);
    printf ("Matrícula: ");
    scanf ("%d", &novoAluno.numero_matricula);
    printf ("Curso: ");
    scanf ("%s", novoAluno.curso);

    printf ("Dia, mês e ano de nascimento no formato (dd/mm/yyyy):");
    scanf ("%02d/%02d/%02d", novoAluno.aniversario.dia, novoAluno.aniversario.mes, novoAluno.aniversario.ano);

    insertAtBeginning (Alunos, &novoAluno);
}

void excluir_aluno ();

void listar_alunos ();

void editar_aluno ();

Aluno buscar_aluno ();