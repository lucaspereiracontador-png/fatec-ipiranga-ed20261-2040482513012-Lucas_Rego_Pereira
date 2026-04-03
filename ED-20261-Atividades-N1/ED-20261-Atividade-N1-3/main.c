/*--------------------------------------------------*/
/* FATEC-Ipiranga                                    */
/* ADS - Estrutura de Dados                          */
/* Atividade N1-3: Simulação HP12c com Pilha RPN     */
/* Autor: Lucas Rego Pereira                         */
/* RA: 2040482513012                                 */
/* Data: 25/03/2026                                  */
/*--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Registradores da HP12c (pilha de 4 níveis)
double X = 0, Y = 0, Z = 0, T = 0;

/*--------------------------------------------------
 Função: push
 Objetivo: Inserir um valor na pilha (X, Y, Z, T)
--------------------------------------------------*/
void push(double valor) {
    T = Z;
    Z = Y;
    Y = X;
    X = valor;
}

/*--------------------------------------------------
 Função: pop
 Objetivo: Remover o valor do topo da pilha (X)
--------------------------------------------------*/
double pop() {
    double topo = X;
    X = Y;
    Y = Z;
    Z = T;
    return topo;
}

/*--------------------------------------------------
 Função: mostrarPilha
 Objetivo: Exibir o estado atual dos registradores
--------------------------------------------------*/
void mostrarPilha() {
    printf("T: %.2f | Z: %.2f | Y: %.2f | X: %.2f\n", T, Z, Y, X);
}

/*--------------------------------------------------
 Função: processarRPN
 Objetivo: Processar expressão em Notação Polonesa Reversa
--------------------------------------------------*/
void processarRPN(char *expr) {
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (strchr("+-*/", token[0]) && strlen(token) == 1) {
            // Operador
            double a = pop();
            double b = pop();
            double resultado;

            switch (token[0]) {
                case '+': resultado = b + a; break;
                case '-': resultado = b - a; break;
                case '*': resultado = b * a; break;
                case '/': resultado = b / a; break;
            }
            push(resultado);
        } else {
            // Operando
            push(atof(token));
        }
        mostrarPilha(); // mostra estado após cada passo
        token = strtok(NULL, " ");
    }
}

/*--------------------------------------------------
 Função principal
--------------------------------------------------*/
int main() {
    char expr[MAX] = "5 1 2 + 4 * + 3 -";
    printf("Expressão RPN: %s\n", expr);
    processarRPN(expr);
    printf("\nResultado final: %.2f\n", X);
    return 0;
}
