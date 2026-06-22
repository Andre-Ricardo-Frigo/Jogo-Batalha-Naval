#include <stdio.h>
#include <stdlib.h>
#include "batalha.h"

/* Aloca dinamicamente uma matriz quadrada de inteiros. */
int **criarMatriz(int tamanho) {
    int i;
    int **matriz = (int **) malloc(tamanho * sizeof(int *));

    if (matriz == NULL) {
        return NULL;
    }

    for (i = 0; i < tamanho; i++) {
        matriz[i] = (int *) malloc(tamanho * sizeof(int));

        if (matriz[i] == NULL) {
            liberarMatriz(matriz, i);
            return NULL;
        }
    }

    return matriz;
}

/* Libera cada linha da matriz e depois o vetor de ponteiros. */
void liberarMatriz(int **matriz, int tamanho) {
    int i;

    if (matriz == NULL) {
        return;
    }

    for (i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

/* Coloca o mesmo valor em todas as posicoes da matriz. */
void preencherMatriz(int **matriz, int tamanho, int valor) {
    int i;
    int j;

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            matriz[i][j] = valor;
        }
    }
}

/* Copia os valores de uma matriz para outra matriz ja alocada. */
void copiarMatriz(int **origem, int **destino, int tamanho) {
    int i;
    int j;

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}

/* Mostra o campo do jogador humano, revelando seus proprios navios. */
void imprimirCampoProprio(int **campo, int tamanho) {
    int i;
    int j;
    int valor;

    printf("    ");
    for (j = 0; j < tamanho; j++) {
        printf("%3d", j + 1);
    }
    printf("\n");

    for (i = 0; i < tamanho; i++) {
        printf("%3d ", i + 1);
        for (j = 0; j < tamanho; j++) {
            valor = campo[i][j];

            if (valor == AGUA) {
                printf("%3d", AGUA);
            } else if (valor == NAVIO_ACERTADO) {
                printf("%3d", NAVIO_ACERTADO);
            } else if (valor >= NAVIO_BASE) {
                printf("%3d", 1);
            } else {
                printf("%3d", valor);
            }
        }
        printf("\n");
    }
}

/* Mostra a visao conhecida do campo adversario. */
void imprimirCampoAdversario(int **campo, int tamanho) {
    int i;
    int j;

    printf("    ");
    for (j = 0; j < tamanho; j++) {
        printf("%3d", j + 1);
    }
    printf("\n");

    for (i = 0; i < tamanho; i++) {
        printf("%3d ", i + 1);
        for (j = 0; j < tamanho; j++) {
            printf("%3d", campo[i][j]);
        }
        printf("\n");
    }
}
