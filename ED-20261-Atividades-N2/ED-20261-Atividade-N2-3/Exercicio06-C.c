//RA: 2040482513012 - Lucas Rego Pereira

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

// Inserção na ABB
No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->dado = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->dado)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->dado)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Altura de um nó
int alturaNo(No *no) {
    if (no == NULL) return -1;
    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

// Profundidade de um nó
int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado)
        return profundidadeNo(raiz->esq, valor, prof + 1);
    else
        return profundidadeNo(raiz->dir, valor, prof + 1);
}

// Grau de um nó
int grauNo(No *no) {
    if (no == NULL) return 0;
    int grau = 0;
    if (no->esq != NULL) grau++;
    if (no->dir != NULL) grau++;
    return grau;
}

// Imprimir ancestrais (recursivo)
int imprimirAncestralAux(No *raiz, int valor) {
    if (raiz == NULL) return 0;
    if (raiz->dado == valor) return 1;
    if (imprimirAncestralAux(raiz->esq, valor) || imprimirAncestralAux(raiz->dir, valor)) {
        printf("%d ", raiz->dado);
        return 1;
    }
    return 0;
}
void imprimirAncestral(No *raiz, int valor) {
    if (!imprimirAncestralAux(raiz, valor))
        printf("Valor %d não encontrado.\n", valor);
}

// Imprimir descendentes (em-ordem)
void imprimirDescendentesAux(No *no) {
    if (no != NULL) {
        imprimirDescendentesAux(no->esq);
        printf("%d ", no->dado);
        imprimirDescendentesAux(no->dir);
    }
}
void imprimirDescendentes(No *raiz, int valor) {
    if (raiz == NULL) return;
    if (raiz->dado == valor) {
        if (raiz->esq) imprimirDescendentesAux(raiz->esq);
        if (raiz->dir) imprimirDescendentesAux(raiz->dir);
        return;
    }
    if (valor < raiz->dado) imprimirDescendentes(raiz->esq, valor);
    else imprimirDescendentes(raiz->dir, valor);
}

// Contar descendentes
int contarDescendentes(No *no) {
    if (no == NULL) return 0;
    int qtd = 0;
    if (no->esq) qtd += 1 + contarDescendentes(no->esq);
    if (no->dir) qtd += 1 + contarDescendentes(no->dir);
    return qtd;
}

void relatorioNo(No *raiz, int valor) {
    if (raiz == NULL) {
        printf("Árvore vazia.\n");
        return;
    }

    // Encontrar o nó
    No *atual = raiz;
    while (atual != NULL && atual->dado != valor) {
        if (valor < atual->dado) atual = atual->esq;
        else atual = atual->dir;
    }
    if (atual == NULL) {
        printf("Valor %d não encontrado na árvore.\n", valor);
        return;
    }

    printf("+----------------------------------+\n");
    printf("| RELATORIO DO NO: %d              |\n", valor);
    printf("+----------------------------------+\n");
    printf("| Profundidade : %d                |\n", profundidadeNo(raiz, valor, 0));
    printf("| Altura : %d                      |\n", alturaNo(atual));
    printf("| Grau : %d                        |\n", grauNo(atual));
    printf("| Ancestrais : ");
    imprimirAncestral(raiz, valor);
    printf("|\n| Descendentes : ");
    imprimirDescendentes(raiz, valor);
    printf("|\n| Qtd Descend. : %d                |\n", contarDescendentes(atual));
    printf("+----------------------------------+\n");
}

int main() {
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int n = sizeof(valores)/sizeof(valores[0]);

    No *raiz = NULL;
    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    relatorioNo(raiz, 50); // raiz
    relatorioNo(raiz, 30); // intermediário
    relatorioNo(raiz, 10); // folha
    relatorioNo(raiz, 70); // intermediário

    return 0;
}

