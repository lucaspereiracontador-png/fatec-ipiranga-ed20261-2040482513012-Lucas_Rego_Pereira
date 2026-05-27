//RA: 2040482513012 - Lucas Rego Pereira

#include <stdio.h>

int chamadasPotRapida = 0;
int chamadasPotIngenua = 0;

// Caso base: exp == 0 → retorna 1
// Caso recursivo: divide exp pela metade se par, ou reduz 1 se ímpar
long long potenciaRapida(long long base, int exp) {
    chamadasPotRapida++;
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long meio = potenciaRapida(base, exp / 2);
        return meio * meio;
    } else {
        return base * potenciaRapida(base, exp - 1);
    }
}

// Implementação ingênua: apenas multiplica base * potencia(base, exp-1)
long long potenciaIngenua(long long base, int exp) {
    chamadasPotIngenua++;
    if (exp == 0) return 1;
    return base * potenciaIngenua(base, exp - 1);
}

int main() {
    int testesBase[] = {2, 3, 5, 7};
    int testesExp[]  = {10, 7, 0, 12};

    for (int i = 0; i < 4; i++) {
        chamadasPotRapida = 0;
        chamadasPotIngenua = 0;

        long long resultadoRapida = potenciaRapida(testesBase[i], testesExp[i]);
        long long resultadoIngenua = potenciaIngenua(testesBase[i], testesExp[i]);

        printf("\nTeste: %d^%d\n", testesBase[i], testesExp[i]);
        printf("Potenciação rápida: %lld (chamadas: %d)\n", resultadoRapida, chamadasPotRapida);
        printf("Potenciação ingênua: %lld (chamadas: %d)\n", resultadoIngenua, chamadasPotIngenua);
    }

    return 0;
}
