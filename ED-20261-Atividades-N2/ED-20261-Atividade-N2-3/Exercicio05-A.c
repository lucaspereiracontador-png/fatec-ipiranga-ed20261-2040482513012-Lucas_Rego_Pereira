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

// Altura de um nó (altura da subárvore)
int alturaNo(No *no) {
    if (no == NULL) return -1;
    int altEsq = alturaNo(no->esq);
    int altDir = alturaNo(no->dir);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

// Profundidade de um nó (distância da raiz até ele)
int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado)
        return profundidadeNo(raiz->esq, valor, prof + 1);
    else
        return profundidadeNo(raiz->dir, valor, prof + 1);
}

// Grau de um nó (quantos filhos ele tem)
int grauNo(No *no) {
    if (no == NULL) return 0;
    int grau = 0;
    if (no->esq != NULL) grau++;
    if (no->dir != NULL) grau++;
    return grau;
}

// Percurso em-ordem para imprimir graus
void imprimirGraus(No *raiz) {
    if (raiz != NULL) {
        imprimirGraus(raiz->esq);
        printf("No %d -> grau %d\n", raiz->dado, grauNo(raiz));
        imprimirGraus(raiz->dir);
    }
}

// Liberar memória
void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int n = sizeof(valores)/sizeof(valores[0]);

    No *raiz = NULL;
    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }
    return 0;
}