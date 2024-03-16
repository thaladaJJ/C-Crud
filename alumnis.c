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
    printf ("Aluno %d adicionado com sucesso!\n\n", novoAluno->numero_matricula);
}

void excluir_aluno (Deque *Alunos) {

    if (emptyList(Alunos)) {
        system ("cls");
        printf ("Nenhum aluno registrado!\n\n");
        return;
    }

    printf ("Digite o número da matrícula do aluno que quer remover: ");

    int num_matricula;
    scanf ("%d", &num_matricula);

   system ("cls");
   remove_target_by_matricula (Alunos, num_matricula);
}

void listar_alunos (Deque *Alunos) {

    if (emptyList(Alunos)) {
        system("cls");
        printf ("Nenhum aluno registrado!\n\n");
        return;
    }

    Node *temp = Alunos->first;

    system ("cls");

    while (temp != NULL) {

        Aluno *aluno = temp->data;

        exibir_aluno (Alunos, aluno);
        
        temp=temp->next;
    }


}

void editar_aluno (Deque *Alunos) {

    setlocale (LC_ALL, "Portuguese_Brazil");

    if (emptyList(Alunos)){
        system("cls");
        printf ("Nenhum aluno registrado!\n\n");
        return;
    }

    listar_alunos (Alunos);
    printf ("\n");

    int matricula_alvo;

    printf ("Digite a matrícula do aluno que quer editar: ");
    scanf ("%d", &matricula_alvo);
    printf ("\n");

    Node *temp = Alunos->first;

    while (temp != NULL) {

        Aluno *aluno = temp->data;

        if (aluno->numero_matricula == matricula_alvo) {
            
            menu_de_edicao (Alunos, aluno);
            system ("cls");
            printf ("Aluno %d atualizado com sucesso!\n\n", aluno->numero_matricula);
            
            return;
        }

        temp=temp->next;
    }

    printf ("Aluno não encontrado na lista.\n\n");
}

void menu_de_edicao (Deque *Alunos, Aluno *aluno) {

    setlocale (LC_ALL, "Portuguese_Brazil");

    system ("cls");
    exibir_aluno (Alunos, aluno);

    printf ("Escolha um campo para editar:\n");

    int option = 0;
    
       while (option != 5) {
        
        printf ("1. Nome\n2. Matrícula\n3. Curso\n4. Data de Nascimento\n5. Sair\n");
        
        scanf ("%d", &option);

        switch (option) {

            case 1:
                printf ("Nome: ");
                scanf (" %[^\n]", aluno->nome);

                system ("cls");
                printf ("Nome atualizado!\n\n");
                break;
            
            case 2:
                printf ("Matrícula: ");
                scanf ("%d", &aluno->numero_matricula);
                
                system ("cls");
                printf ("Matrícula atualizada!\n\n");
                break;
            
            case 3:
                printf ("Curso: ");
                scanf (" %[^\n]", aluno->curso);

                system ("cls");
                printf ("Curso atualizado!\n\n");
                break;
            
            case 4:
                printf ("Dia, mês e ano de nascimento no formato (dd/mm/yyyy): ");
                scanf ("%02d/%02d/%04d", &aluno->aniversario.dia, &aluno->aniversario.mes, &aluno->aniversario.ano);
                
                system ("cls");
                printf ("Data de nascimento atualizada!\n\n");
                break;
            
            case 5:
                break;
            
            default:
                system ("cls");
                printf ("Opção inválida.\n\n");
                break;
        }

        exibir_aluno (Alunos, aluno);
    }

}

void buscar_aluno (Deque *Alunos) {

    if (emptyList(Alunos)){
        system("cls");
        printf ("Nenhum aluno registrado!\n\n");
        return;
    }

    char nome [100];

    printf ("Insira o nome completo do aluno desejado: ");
    scanf (" %[^\n]", nome);

    printf ("\n");

    Node *temp = Alunos->first;

    while (temp != NULL) {

        Aluno *aluno = temp->data;

        if (strcmp (aluno->nome, nome) == 0) {
            
            exibir_aluno (Alunos, aluno);
            return;
        }

        temp=temp->next;
    }

    system ("cls");
    printf ("Aluno não encontrado!\n\n");
}

void exibir_aluno (Deque *Alunos, Aluno *aluno) {

    printf ("Nome: %s\nMatrícula: %d\nCurso: %s\nData de nascimento: %02d/%02d/%04d\n\n", 
    aluno->nome, aluno->numero_matricula, aluno->curso, 
    aluno->aniversario.dia, aluno->aniversario.mes, aluno->aniversario.ano);
}