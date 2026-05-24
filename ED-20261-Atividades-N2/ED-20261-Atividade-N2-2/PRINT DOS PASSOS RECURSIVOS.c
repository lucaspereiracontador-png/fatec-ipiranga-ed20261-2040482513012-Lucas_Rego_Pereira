#include <stdio.h>

struct No {
    int valor; 
    int altura; 
    struct No *esq; 
    struct No *dir;
};

int calcularAltura(struct No* n){
    if(n == NULL){
    printf("Nó NULL -> altura = -1\n");
    return -1;
    }
    
    int h_esq = calcularAltura(n->esq);
    int h_dir = calcularAltura(n->dir);
    int altura = 1 + (h_esq > h_dir ? h_esq : h_dir);
    printf("Nó %d -> altura = 1 + max(%d, %d) = %d\n", n->valor, h_esq, h_dir, altura);
    
    return altura;
}

int obterFB(struct No* n){
    if (n == NULL) return 0;
    
    int h_esq = calcularAltura(n->esq);
    int h_dir = calcularAltura(n->dir);
    int fb = h_esq - h_dir;
    
    printf("Nó %d -> FB = %d - %d = %d\n", n->valor, h_esq, h_dir, fb);
    return fb;
}

int main() {
    struct No n2 = {2, 0, NULL, NULL};
    struct No n5 = {5, 0, &n2, NULL};
    struct No n10 = {10, 0, &n5, NULL};
    struct No n20 = {20, 0, &n10, NULL};

    printf("Altura da raiz: %d\n", calcularAltura(&n20));
    printf("Fator de Balanceamento da raiz: %d\n", obterFB(&n20));
   
    return 0;
}