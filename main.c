#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "batalha.h"

/* Le um inteiro simples usado no menu principal. */
static int lerOpcaoMenu(void) {
    int opcao;
    int c;

    printf("Escolha: ");
    while (scanf("%d", &opcao) != 1) {
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
        printf("Digite um numero inteiro: ");
    }

    return opcao;
}

/* Mostra as opcoes principais do programa. */
static void mostrarMenu(Configuracao config) {
    printf("\n===== BATALHA NAVAL =====\n");
    printf("Configuracao atual: campo %dx%d, %d navios\n",
           config.tamanho, config.tamanho, config.quantidadeNavios);
    printf("1 - Novo Jogo\n");
    printf("2 - Configurar\n");
    printf("3 - Carregar\n");
    printf("4 - Sair\n");
}

/* Funcao principal: controla o menu e chama os modulos do jogo. */
int main(void) {
    Configuracao config;
    Jogo jogo;
    int opcao;
    int executando = 1;

    srand((unsigned int) time(NULL));
    carregarConfiguracao(&config);

    while (executando) {
        mostrarMenu(config);
        opcao = lerOpcaoMenu();

        if (opcao == 1) {
            inicializarJogo(&jogo, config);
            executarPartida(&jogo);
            liberarJogo(&jogo);
        } else if (opcao == 2) {
            configurarJogo(&config);
        } else if (opcao == 3) {
            if (carregarJogo(&jogo)) {
                executarPartida(&jogo);
                liberarJogo(&jogo);
                carregarConfiguracao(&config);
            } else {
                printf("Nenhum jogo salvo encontrado.\n");
            }
        } else if (opcao == 4) {
            executando = 0;
        } else {
            printf("Opcao invalida.\n");
        }
    }

    printf("Programa encerrado.\n");
    return 0;
}
