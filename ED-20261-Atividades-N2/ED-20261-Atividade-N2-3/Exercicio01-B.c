//RA: 2040482513012 - Lucas Rego Pereira

#include <stdio.h>

// ==========================================
// FUNÇÃO PARA EXIBIR ELEMENTOS E SOMAR
// ==========================================
void exibirESomar(int *v, int tamanho) {

    int *p = v;
    int soma = 0;

    printf("\nELEMENTOS DO VETOR:\n");

    // Percorre o vetor usando apenas ponteiros
    for (; p < v + tamanho; p++) {

        // *p acessa o valor armazenado no endereço apontado por p
        printf("Valor: %d | Endereco: %p\n", *p, (void*)p);

        // Soma o valor apontado por p
        soma += *p;
    }

    printf("\nSoma total: %d\n", soma);
}

// ==========================================
// FUNÇÃO PARA INVERTER O VETOR
// ==========================================
void inverterVetor(int *v, int tamanho) {

    // inicio aponta para o primeiro elemento
    int *inicio = v;

    // fim aponta para o último elemento
    int *fim = v + (tamanho - 1);

    while (inicio < fim) {

        // Variável auxiliar para troca
        int temp = *inicio; // pega o valor do início

        // copia o valor do final para o início
        *inicio = *fim;

        // coloca o valor antigo do início no final
        *fim = temp;

        // avança para o próximo elemento
        inicio++;

        // recua para o elemento anterior
        fim--;
    }
}

// ==========================================
// FUNÇÃO MAIN
// ==========================================
int main() {

    int v[] = {10, 20, 30, 40, 50};

    printf("VETOR ORIGINAL:\n");

    // Chama a função que exibe e soma
    exibirESomar(v, 5);

    // Chama a função que inverte o vetor
    inverterVetor(v, 5);

    printf("\nVETOR INVERTIDO:\n");

    // Exibe novamente após inverter
    exibirESomar(v, 5);
    
    return 0;
}