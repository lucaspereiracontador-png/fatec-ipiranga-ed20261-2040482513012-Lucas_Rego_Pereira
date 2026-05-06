//  ALUNO: LUCAS REGO PEREIRA
//    RA: 2040482513012


#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *esq;
    struct reg *dir;
} noh;

//Criação do nó
noh* createnoh(int conteudo) {
    noh *novonoh = (noh*)malloc(sizeof(noh));
    novonoh->conteudo = conteudo;
    novonoh->esq = NULL;
    novonoh->dir = NULL;
    return novonoh;
}

//Identificação do nó principal

noh* insert(noh* raiz, int conteudo) {
    if(raiz == NULL) return createnoh(conteudo);
    if(conteudo < raiz->conteudo)
        raiz->esq = insert(raiz->esq, conteudo);
    else
        raiz->dir = insert(raiz->dir, conteudo);
    return raiz;
}

//Impressão da raiz

void imprimeRaiz(noh* raiz) {
    if(raiz) printf("Raiz (root): %d\n", raiz->conteudo);
}

//Impressão dos nós internos

void imprimeNohInternos(noh* raiz) {
    if(raiz == NULL) return;
    if(raiz->esq != NULL || raiz->dir != NULL)
    printf("%d ", raiz->conteudo);
    imprimeNohInternos(raiz->esq);
    imprimeNohInternos(raiz->dir);
}

//Impressão de folhas

void imprimeFolhas(noh* raiz) {
    if(raiz == NULL) return;
    if(raiz->esq == NULL && raiz->dir == NULL)
    printf("%d ", raiz->conteudo);
    imprimeFolhas(raiz->esq);
    imprimeFolhas(raiz->dir);
}

//Impressão por nível

void imprimeNivel(noh* raiz, int nivel) {
    if(raiz == NULL) return;
    if(nivel == 1) {
        printf("%d ", raiz->conteudo);
    } else {
        imprimeNivel(raiz->esq, nivel - 1);
        imprimeNivel(raiz->dir, nivel - 1);
    }
}

//Altura do nó

int altura(noh* raiz) {
    if (raiz == NULL) return -1;
    int alturaesq = altura(raiz->esq);
    int alturadir = altura(raiz->dir);
    return (alturaesq > alturadir ? alturaesq : alturadir) + 1;
}

//Grau de um nó

int grau(noh* noh) {
    int g = 0;
    if(noh->esq) g++;
    if(noh->dir) g++;
    return g;
}

// Função para imprimir o grau de cada nó
void imprimeGraus(noh* raiz) {
    if (raiz == NULL) return;
    printf("Nó %d -> Grau: %d\n", raiz->conteudo, grau(raiz));
    imprimeGraus(raiz->esq);
    imprimeGraus(raiz->dir);
}

//Ancestrais

int imprimeAncestrais(noh* raiz, int alvo) {
    if(raiz == NULL) return 0;
    if(raiz->conteudo == alvo) return 1;
    if(imprimeAncestrais(raiz->esq, alvo) || imprimeAncestrais(raiz->dir, alvo)) {
        printf("%d ", raiz->conteudo);
        return 1;
    }
    return 0;
}

//Descendentes

void imprimeDescendentes(noh* raiz) {
    if(raiz == NULL) return;
    if(raiz->esq) {
        printf("%d ", raiz->esq->conteudo);
        imprimeDescendentes(raiz->esq);
    }
    if(raiz->dir) {
        printf("%d ", raiz->dir->conteudo);
        imprimeDescendentes(raiz->dir);
    }
}

//Profundidade de um nó

int prof(noh* raiz, int alvo, int nivel) {
    if(raiz == NULL) return -1;
    if(raiz->conteudo == alvo) return nivel;
    int esq = prof(raiz->esq, alvo, nivel + 1);
    if(esq != -1) return esq;
    return prof(raiz->dir, alvo, nivel +1);
}

// Função encontraNoh
noh* encontraNoh(noh* raiz, int alvo) {
    if (raiz == NULL) return NULL;
    if (raiz->conteudo == alvo) return raiz;
    if (alvo < raiz->conteudo) return encontraNoh(raiz->esq, alvo);
    else return encontraNoh(raiz->dir, alvo);
}

//Sub-Árvore

void imprimeSubArvore(noh* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->conteudo);
    imprimeSubArvore(raiz->esq);
    imprimeSubArvore(raiz->dir);
}

    int main() {
    noh* raiz = NULL;

    // Inserindo valores para gerar profundidade de 7 níveis
    // Exemplo: inserir valores sequenciais para garantir BST profunda
    int conteudo[] = {50, 30, 70, 20, 40, 60, 80, 10, 65, 5, 2};
    int n = sizeof(conteudo)/sizeof(conteudo[0]);
    for (int i = 0; i < n; i++) {
        raiz = insert(raiz, conteudo[i]);
    }

    imprimeRaiz(raiz);

    printf("Nós Internos: ");
    imprimeNohInternos(raiz);
    printf("\n");

    printf("Nós Externos (Folhas): ");
    imprimeFolhas(raiz);
    printf("\n");

    printf("Níveis:\n");
    int h = altura(raiz);
    for (int i = 1; i <= h + 1; i++) {
        printf("Nível %d: ", i);
        imprimeNivel(raiz, i);
        printf("\n");
    }
    
    printf("Graus individualizados de cada nó:\n");
    imprimeGraus(raiz);

    printf("Ancestrais do nó 40: ");
    imprimeAncestrais(raiz, 40);
    printf("\n");

    printf("Descendentes do nó 30: ");
    noh* noh30 = encontraNoh(raiz, 30);
    imprimeDescendentes(noh30);
    printf("\n");

    printf("Altura do nó 30: %d\n", altura(noh30));
    printf("Profundidade do nó 40: %d\n", prof(raiz, 40, 0));

    printf("Subárvore a partir do nó 30:\n");
    imprimeSubArvore(noh30);
    printf("\n");
    
    return 0;
}

