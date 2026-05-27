//RA: 2040482513012 - Lucas Rego Pereira

#include <stdio.h>

// Função que troca os valores de duas variáveis
void trocar(int *a, int *b) {

    // *a acessa o valor armazenado no endereço apontado por a
    // *b acessa o valor armazenado no endereço apontado por b
    *a = *a + *b;

    // *b recebe o valor original de *a
    // porque agora *a contém a soma dos dois valores
    *b = *a - *b;

    // *a recebe o valor original de *b
    *a = *a - *b;
}

int main() {

    // =========================
    // PARTE A — TROCA COM PONTEIROS
    // =========================

    int x = 10;
    int y = 20;

    printf("ANTES DA TROCA:\n");

    // &x retorna o endereço de memória da variável x
    printf("Endereco de x: %p\n", (void*)&x);

    // &y retorna o endereço de memória da variável y
    printf("Endereco de y: %p\n", (void*)&y);

    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);

    // &x envia o endereço de x para a função
    // &y envia o endereço de y para a função
    trocar(&x, &y);

    printf("\nDEPOIS DA TROCA:\n");

    // &x retorna novamente o endereço de x
    printf("Endereco de x: %p\n", (void*)&x);

    // &y retorna novamente o endereço de y
    printf("Endereco de y: %p\n", (void*)&y);

    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);
    
return 0;
}