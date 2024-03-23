# C-Crud

> Nesse repositório está uma implementação simples de uma CRUD em C feita para uso simples por inserção de dados no terminal pelo teclado.

### Especificações

> O programa manipula uma estrutura de dados para armazenar informações de um aluno, que é determinado pelo nome, número de matrícula, curso e data de nascimento.
```C

#ifndef ALUMNIS_H
#define ALUMNIS_H

#include "list.h"

typedef struct Data_de_Nascimento {
    short int dia;
    short int mes;
    short int ano;
} Data_de_Nascimento;

typedef struct Aluno {
    char nome [100];
    int numero_matricula;
    char curso [50];
    Data_de_Nascimento aniversario;
} Aluno;

```

> A estrutura de dados utilizada é do tipo deque (fila duplamente terminada), caracterizada pelos seus ponteiros
> para o início e fim da lista. Sua implementação é determinada em list.c.

```C

typedef struct Node {
    void *data;
    struct Node *next, *prev;
} Node;

typedef struct {
    Node *first, *last;
    int quantity;
} Deque;

```
> Essas duas estruturas determinam a composição da deque, possuindo um encadeamento duplo, com ponteiros para o elemento anterior e o próximo
> que tem seu valor nulo na inicialização da lista

` Deque* initializeList (); `
> Retorna uma estrutura Deque através da alocação dinâmica de memória. Necessária sua utilização antes que o usuário use
> os métodos e funções do tipo Deque.

```C
void destroyList (Deque *d);

int emptyList (Deque *d);

int sizeOfList (Deque *d);

void insertAtBeginning (Deque *d, Aluno *data);

void insertAtEnd (Deque *d, Aluno *data);

void remove_beginning (Deque *d);

void remove_end (Deque *d);

void remove_target (Deque *d, Aluno *data);

void remove_target_by_matricula(Deque *d, int matricula);
```

### Alumnis

> Conforme visto anteriormente, é implementado um tipo aluno com seu nome, matrícula, curso e data de nascimento, que também é um tipo
> composto especificado por uma estrutura. Os métodos em alumnis sempre imprimem informações para o usuário inserir corretamente os dados
> necessários à função.

`void adicionar_aluno (Deque *Alunos);`

> Aloca dinamicamente uma estrutura de um aluno na memória e solicita seus dados em seguida. Utiliza um método da deque para inserir no começo
> da lista que recebeu como parâmetro.

`int emptyList (Deque *d);` 
`int sizeOfList (Deque *d);`

> Retornam respectivamente: "verdadeiro" para se a lista está vazia e "falso" para lista cheia; a quantidade atual de elementos na lista.

`void editar_aluno (Deque *Alunos);`

`void menu_de_edicao (Deque *Alunos, Aluno *aluno);`

> O método editar_aluno é quem chama o menu_de_edicao no programa, assim, eles funcionam em conjunto, sendo separados por questão de legibilidade de código.
> Esses métodos fornecem uma interface para a edição de qualquer dado de um aluno escolhido, procurando-o na lista pelo número de matrícula que é fornecido
> pelo usuário, retornando ao menu principal se não encontrar o aluno com o número inserido.

```C

void buscar_aluno (Deque *Alunos);

void listar_alunos (Deque *Alunos);

void exibir_aluno (Deque *Alunos, Aluno *aluno);

void excluir_aluno (Deque *Alunos);

```
