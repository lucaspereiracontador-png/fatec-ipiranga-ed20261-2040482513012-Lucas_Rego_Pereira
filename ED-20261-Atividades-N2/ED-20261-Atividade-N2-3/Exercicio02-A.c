//RA: 2040482513012 - Lucas Rego Pereira

#include <stdio.h>

// ==========================================
// Calcula e retorna a média aritmética
// ==========================================
float calcularMedia(float *vet, int n) {

    float soma = 0.0f;

    float *ptr = vet;

    // Percorre o vetor usando ponteiro
    for (; ptr < vet + n; ptr++) {

        // *ptr acessa o valor armazenado
        soma += *ptr;
    }

    return soma / n;
}

// ==========================================
// Encontra maior e menor valor
// ==========================================
void encontrarExtremos(float *vet, int n,
                       float *maior, float *menor) {

    float *ptr = vet;

    // Inicializa maior e menor com o primeiro elemento
    *maior = *vet;
    *menor = *vet;

    // Percorre o vetor usando ponteiro
    for (; ptr < vet + n; ptr++) {

        // Verifica maior valor
        if (*ptr > *maior) {

            // Escreve diretamente no endereço apontado por maior
            *maior = *ptr;
        }

        // Verifica menor valor
        if (*ptr < *menor) {

            // Escreve diretamente no endereço apontado por menor
            *menor = *ptr;
        }
    }
}

// ==========================================
// Normaliza o vetor
// Cada elemento é dividido pelo maior valor
// ==========================================
void normalizar(float *vet, int n) {

    float maior;
    float menor;

    // Descobre o maior valor do vetor
    encontrarExtremos(vet, n, &maior, &menor);

    float *ptr = vet;

    // Percorre o vetor usando ponteiros
    for (; ptr < vet + n; ptr++) {

        // Modifica diretamente o conteúdo do vetor original
        *ptr = *ptr / maior;
    }
}

// ==========================================
// Imprime o vetor formatado
// ==========================================
void imprimirVetor(float *vet, int n, const char *titulo) {

    printf("\n%s\n", titulo);

    float *ptr = vet;

    // Percorre usando apenas ponteiros
    for (; ptr < vet + n; ptr++) {

        // Exibe o valor atual
        printf("%.2f ", *ptr);
    }

    printf("\n");
}

// ==========================================
// FUNÇÃO MAIN
// ==========================================
int main(void) {

    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};

    float media;
    float maior;
    float menor;

    // Vetor antes da normalização
    imprimirVetor(notas, 6, "VETOR ORIGINAL:");

    // Calcula média
    media = calcularMedia(notas, 6);

    // Encontra maior e menor
    encontrarExtremos(notas, 6, &maior, &menor);

    // Exibe resultados
    printf("\nMedia: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);

    // Normaliza o vetor
    normalizar(notas, 6);

    // Vetor após normalização
    imprimirVetor(notas, 6, "VETOR NORMALIZADO:");

    /*
       A função normalizar altera o vetor original porque
       o vetor é passado por ponteiro.

       Assim, a função recebe o endereço de memória do primeiro
       elemento do vetor e modifica diretamente os valores
       armazenados nesses endereços.

       Não é criada uma cópia do vetor.
    */

    return 0;
}