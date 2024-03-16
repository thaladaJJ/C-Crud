#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "list.h"
#include "alumnis.h"

void adicionar_aluno (Deque *Alunos) {

    setlocale (LC_ALL, "Portuguese_Brazil");

    Aluno *novoAluno = (Aluno*) malloc (sizeof(Aluno));

        if (novoAluno == NULL) {
            printf ("Falha na alocação de memória.\n");
            return;
        }

    printf ("Insira os dados do aluno:\n");

    printf ("Nome: ");
    scanf (" %[^\n]", novoAluno->nome);

    printf ("Matrícula: ");
    scanf ("%d", &novoAluno->numero_matricula);

    printf ("Curso: ");
    scanf (" %[^\n]", novoAluno->curso);

    printf ("Dia, mês e ano de nascimento no formato (dd/mm/yyyy): ");
    scanf ("%02d/%02d/%04d", &novoAluno->aniversario.dia, &novoAluno->aniversario.mes, &novoAluno->aniversario.ano);

    insertAtBeginning (Alunos, novoAluno);
    system ("cls");
    printf ("Aluno %d adicionado com sucesso!\n", novoAluno->numero_matricula);
}

void excluir_aluno (Deque *Alunos) {

    printf ("Digite o número da matrícula do aluno que quer remover: ");

    int num_matricula;
    scanf ("%d", &num_matricula);

    Node *temp = Alunos->first;
    
    while (temp != NULL) {

        Aluno *aluno = temp->data;
        if (aluno->numero_matricula = num_matricula) {
            
        }

    }
}

void listar_alunos (Deque *Alunos) {

    if (emptyList(Alunos)){
        system("cls");
        return;
    }

    Node *temp = Alunos->first;

    system ("cls");

    while (temp != NULL) {

        Aluno *aluno = temp->data;

        printf ("Nome: %s\nMatrícula: %d\nCurso: %s\nData de nascimento: %02d/%02d/%04d\n\n", 
        aluno->nome, aluno->numero_matricula, aluno->curso, 
        aluno->aniversario.dia, aluno->aniversario.mes, aluno->aniversario.ano);
        
        temp=temp->next;
    }


}

void editar_aluno (Deque *Alunos);

void buscar_aluno (Deque *Alunos) {

    if (emptyList(Alunos)){
        system("cls");
        printf ("Nenhum aluno registrado!\n");
        return;
    }

    char nome [50];

    printf ("Insira o nome completo do aluno desejado: ");
    scanf (" %[^\n]", nome);

    printf ("\n");

    Node *temp = Alunos->first;

    while (temp != NULL) {

        Aluno *aluno = temp->data;

        if (strcmp (aluno->nome, nome) == 0) {
            
            printf ("Nome: %s\nMatrícula: %d\nCurso: %s\nData de nascimento: %02d/%02d/%04d\n\n", 
            aluno->nome, aluno->numero_matricula, aluno->curso, 
            aluno->aniversario.dia, aluno->aniversario.mes, aluno->aniversario.ano);
            return;
        }

        temp=temp->next;
    }

    system ("cls");
    printf ("Aluno não encontrado!\n");
} 