#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "list.h"
#include "alumnis.h"

void Menu (Deque *lista) {  

    printf ("Bem vindo ao menu de Alunos. Escolha uma opção:\n");
    int option = 0;
    
       while (option != 6) {
        
        printf ("1. Adicionar novo aluno\n2. Buscar aluno por nome\n3. Excluir aluno\n4. Listar todos os alunos\n5. Editar dados de um aluno\n6. Sair\n");
        
        scanf ("%d", &option);

        switch (option) {
            case 1:
                system ("clear");
                adicionar_aluno (lista);
                break;
            
            case 2:
                system ("clear");
                buscar_aluno (lista);
                break;
            
            case 3:
                excluir_aluno (lista);
                break;
            
            case 4:
                listar_alunos (lista);
                break;
            
            case 5:
                system("clear");
                editar_aluno (lista);
                break;
            
            case 6:
                printf ("Encerrando o programa!\n");
                break;

            default:
                system ("clear");
                printf ("Opção inválida.\n");
                break;
        }
    }

}

int main () {

    setlocale (LC_ALL, "Portuguese_Brazil");

    Deque *lista_alunos = initializeList ();
    
    Menu (lista_alunos);

    destroyList (lista_alunos);

    return 0;
}