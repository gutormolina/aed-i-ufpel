#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[30];
    int idade;
} Pessoa;

typedef struct Nodo
{
    Pessoa info;
    struct Nodo *prox;
} Nodo;

typedef struct
{
    Nodo *topo;
} Pilha;

Pilha* reset()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha *pilha, Pessoa pessoa)
{
    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));
    novoNodo->info = pessoa;
    novoNodo->prox = pilha->topo;
    pilha->topo = novoNodo;
}

Pessoa pop(Pilha *pilha)
{
    if (pilha->topo == NULL)
    {
        Pessoa pessoaVazia;
        strcpy(pessoaVazia.nome, "");
        pessoaVazia.idade = 0;
        return pessoaVazia;
    }

    Nodo *remover = pilha->topo;
    pilha->topo = remover->prox;
    Pessoa pessoaRemovida = remover->info;

    free(remover);
    return pessoaRemovida;
}

void clear(Pilha *pilha)
{
    while (pilha->topo != NULL) {
        pop(pilha);
    }
    free(pilha);
}

int main()
{
    Pessoa p1, p2, p3, p4;
    strcpy(p1.nome, "Juliano");
    p1.idade = 23;
    strcpy(p2.nome, "Augusto");
    p2.idade = 20;
    strcpy(p3.nome, "Luiz");
    p3.idade = 20;
    strcpy(p4.nome, "Bruna");
    p4.idade = 19;

    Pilha *pilha = reset();

    push(pilha, p1);
    push(pilha, p2);
    push(pilha, p3);

    Pessoa pessoaRemovida = pop(pilha);
    printf("Removido: %s\n", pessoaRemovida.nome);

    pessoaRemovida = pop(pilha);
    printf("Removido: %s\n", pessoaRemovida.nome);

    push(pilha, p4);

    pessoaRemovida = pop(pilha);
    printf("Removido: %s\n", pessoaRemovida.nome);

    clear(pilha);
    
    return 0;
}