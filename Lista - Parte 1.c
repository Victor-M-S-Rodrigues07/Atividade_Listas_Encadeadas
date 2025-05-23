// Lista de Execícios: Listas Encadeadas, Filas e Pilhas

// 1) Inserção Básica

#include <stdio.h>
#include <stdlib.h>

typedef struct no {

    int dado;
    struct no* proximo;
} no;

void inserir_inicio (no **lista, int valor) {

    no* novo = (no*) malloc (sizeof (no));

    if (novo == NULL) {

        printf ("Erro ao tentar alocar memoria\n");
        return;
    }

    novo -> dado = valor;
    novo -> proximo = *lista;
    *lista = novo;
}

void inserir_fim (no** lista, int valor) {

    no* novo = (no*) malloc (sizeof (no));

    if (novo == NULL) {

        printf ("Erro ao tentar alocar memoria\n");
        return;
    }

    novo -> dado = valor;
    novo -> proximo = NULL;

    if (*lista == NULL) {

        *lista = novo;
    }

    else {

        no* atual = *lista;

        while (atual -> proximo != NULL) {

            atual = atual -> proximo;
        }

        atual -> proximo = novo;
    }
}

void liberar_memoria (no* lista) {

    no* temp;

    while (lista != NULL) {

        temp = lista;
        lista = lista -> proximo;
        free (temp);
    }
}

// 2) Contagem de Nós

int contar_nos (no* lista) {

    int quantidade = 0;

    while (lista != NULL) {

        quantidade++;

        lista = lista -> proximo;
    }

    return quantidade;
}

// 3) Busca de Elemento

int buscar_elemento (no* lista, int elementoProcurado) {

    while (lista != NULL) {

        if (lista -> dado == elementoProcurado) {

            return 1;
        }

        lista = lista -> proximo;
    }

    return 0;
}

int main () {

    no* lista = NULL;

    inserir_fim (&lista, 10);
    inserir_fim (&lista, 20);
    inserir_inicio (&lista, 40);
    inserir_inicio (&lista, 60);

    printf ("A quantidade de nos: %d\n", contar_nos (lista));

    int elementoProcurado = 30;

    if (buscar_elemento (lista, elementoProcurado) == 1) {

        printf ("O elemento %d esta na lista!\n", elementoProcurado);
    }

    else {

        printf ("O elemento %d nao esta na lista!\n", elementoProcurado);
    }

    liberar_memoria (lista);
}