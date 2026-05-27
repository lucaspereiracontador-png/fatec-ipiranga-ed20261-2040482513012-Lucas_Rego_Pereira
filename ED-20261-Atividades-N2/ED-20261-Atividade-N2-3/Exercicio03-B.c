//RA: 2040482513012 - Lucas Rego Pereira

#include <stdio.h>

int contador = 0; // contador global

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco de %c para %c\n", origem, destino);
        contador++;
    } else {
        hanoi(n - 1, origem, auxiliar, destino);
        printf("Mover disco de %c para %c\n", origem, destino);
        contador++;
        hanoi(n - 1, auxiliar, destino, origem);
    }
}

int main() {
    for (int n = 1; n <= 6; n++) {
        contador = 0;
        printf("\n--- Teste com n = %d ---\n", n);
        hanoi(n, 'A', 'C', 'B');
        printf("Movimentos realizados: %d\n", contador);
        printf("Esperado (2^n - 1): %d\n", (1 << n) - 1);
    }
    return 0;
}

/*
Tabela de comparação:

n   Movimentos (contado)   2^n - 1 (esperado)
1   1                      1
2   3                      3
3   7                      7
4   15                     15
5   31                     31
6   63                     63
*/
