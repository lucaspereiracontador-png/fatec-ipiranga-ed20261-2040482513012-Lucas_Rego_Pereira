//RA: 2040482513012 - Lucas Rego Pereira

#include <stdio.h>

int chamadasBusca = 0; // contador global de chamadas

// Caso base: intervalo vazio (inicio > fim) → retorna -1
// Caso recursivo: divide o vetor ao meio e busca na metade correta
int buscaBinaria(int *vet, int inicio, int fim, int alvo) {
    chamadasBusca++;
    if (inicio > fim) return -1;

    int meio = (inicio + fim) / 2;

    if (vet[meio] == alvo) return meio;
    else if (vet[meio] > alvo) return buscaBinaria(vet, inicio, meio - 1, alvo);
    else return buscaBinaria(vet, meio + 1, fim, alvo);
}

int main() {
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    int tamanho = sizeof(dados) / sizeof(dados[0]);

    int testes[] = {23, 7, 2}; // presente, ausente, primeiro elemento
    for (int i = 0; i < 3; i++) {
        chamadasBusca = 0;
        int alvo = testes[i];
        int resultado = buscaBinaria(dados, 0, tamanho - 1, alvo);
        if (resultado != -1)
            printf("Elemento %d encontrado no índice %d (chamadas: %d)\n", alvo, resultado, chamadasBusca);
        else
            printf("Elemento %d não encontrado (chamadas: %d)\n", alvo, chamadasBusca);
    }

    return 0;
}
