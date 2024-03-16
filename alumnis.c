#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "list.h"
#include "alumnis.h"

void adicionar_aluno (Deque *Alunos) {

    setlocale (LC_ALL, "Portuguese_Brazil");

    Aluno *novoAluno = (Aluno*) malloc (sizeof(Aluno));

        if (novoAluno == NULL) {
            printf ("Falha na aloca��o de mem�ria.\n");
            return;
        }

    printf ("Insira os dados do aluno:\n");

    printf ("Nome: ");
    scanf (" %[^\n]", novoAluno->nome);

    printf ("Matr�cula: ");
    scanf ("%d", &novoAluno->numero_matricula);

    printf ("Curso: ");
    scanf (" %[^\n]", novoAluno->curso);

    printf ("Dia, m�s e ano de nascimento no formato (dd/mm/yyyy): ");
    scanf ("%02d/%02d/%04d", &novoAluno->aniversario.dia, &novoAluno->aniversario.mes, &novoAluno->aniversario.ano);

    insertAtBeginning (Alunos, novoAluno);
    system ("cls");
    printf ("Aluno %d adicionado com sucesso!\n", novoAluno->numero_matricula);
}

void excluir_aluno (Deque *Alunos) {

    

}

void listar_alunos (Deque *Alunos) {

    if (emptyList(Alunos))
        return;
    
    Node *temp = Alunos->first;

    system ("cls");

    while (temp != NULL) {

        Aluno *aluno = temp->data;

        printf ("Nome: %s\nMatr�cula: %d\nCurso: %s\nData de nascimento: %02d/%02d/%04d\n\n", 
        aluno->nome, aluno->numero_matricula, aluno->curso, 
        aluno->aniversario.dia, aluno->aniversario.mes, aluno->aniversario.ano);
        
        temp=temp->next;
    }


}

void editar_aluno (Deque *Alunos);

Aluno buscar_aluno (Deque *Alunos) {



}