#include <stdio.h>
#include <stdlib.h>
#include "batalha.h"

/* Define valores minimos quando nao existe arquivo salvo. */
void configuracaoPadrao(Configuracao *config) {
    config->tamanho = TAMANHO_MINIMO;
    config->quantidadeNavios = NAVIOS_MINIMOS;
}

/* Grava a configuracao e informa que nao ha partida salva. */
int salvarConfiguracao(Configuracao *config) {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");
    int temJogo = 0;

    if (arquivo == NULL) {
        return 0;
    }

    fwrite(config, sizeof(Configuracao), 1, arquivo);
    fwrite(&temJogo, sizeof(int), 1, arquivo);

    fclose(arquivo);
    return 1;
}

/* Le a configuracao do arquivo binario, se ele existir. */
int carregarConfiguracao(Configuracao *config) {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");

    if (arquivo == NULL) {
        configuracaoPadrao(config);
        return 0;
    }

    fread(config, sizeof(Configuracao), 1, arquivo);
    fclose(arquivo);
    return 1;
}

/* Escreve uma matriz no arquivo, linha por linha. */
void escreverMatriz(FILE *arquivo, int **matriz, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        fwrite(matriz[i], sizeof(int), tamanho, arquivo);
    }
}

/* Le uma matriz do arquivo, linha por linha. */
void lerMatriz(FILE *arquivo, int **matriz, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        fread(matriz[i], sizeof(int), tamanho, arquivo);
    }
}

/* Salva configuracao e partida no mesmo arquivo binario. */
int salvarJogo(Jogo *jogo) {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");
    int temJogo = 1;
    int tamanho = jogo->config.tamanho;

    if (arquivo == NULL) {
        return 0;
    }

    fwrite(&jogo->config, sizeof(Configuracao), 1, arquivo);
    fwrite(&temJogo, sizeof(int), 1, arquivo);
    fwrite(&jogo->turno, sizeof(int), 1, arquivo);
    fwrite(&jogo->emAndamento, sizeof(int), 1, arquivo);

    fwrite(&jogo->humano.totalNavios, sizeof(int), 1, arquivo);
    fwrite(&jogo->humano.naviosAfundados, sizeof(int), 1, arquivo);
    fwrite(jogo->humano.navios, sizeof(Navio), jogo->humano.totalNavios, arquivo);
    escreverMatriz(arquivo, jogo->humano.campo, tamanho);
    escreverMatriz(arquivo, jogo->humano.visaoAdversario, tamanho);

    fwrite(&jogo->computador.totalNavios, sizeof(int), 1, arquivo);
    fwrite(&jogo->computador.naviosAfundados, sizeof(int), 1, arquivo);
    fwrite(jogo->computador.navios, sizeof(Navio), jogo->computador.totalNavios, arquivo);
    escreverMatriz(arquivo, jogo->computador.campo, tamanho);
    escreverMatriz(arquivo, jogo->computador.visaoAdversario, tamanho);

    fclose(arquivo);
    return 1;
}

/* Carrega uma partida completa do arquivo binario. */
int carregarJogo(Jogo *jogo) {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");
    int temJogo;
    int tamanho;

    if (arquivo == NULL) {
        return 0;
    }

    fread(&jogo->config, sizeof(Configuracao), 1, arquivo);
    fread(&temJogo, sizeof(int), 1, arquivo);

    if (temJogo == 0) {
        fclose(arquivo);
        return 0;
    }

    tamanho = jogo->config.tamanho;

    fread(&jogo->turno, sizeof(int), 1, arquivo);
    fread(&jogo->emAndamento, sizeof(int), 1, arquivo);

    fread(&jogo->humano.totalNavios, sizeof(int), 1, arquivo);
    fread(&jogo->humano.naviosAfundados, sizeof(int), 1, arquivo);
    jogo->humano.navios = (Navio *) malloc(jogo->humano.totalNavios * sizeof(Navio));
    jogo->humano.campo = criarMatriz(tamanho);
    jogo->humano.visaoAdversario = criarMatriz(tamanho);
    fread(jogo->humano.navios, sizeof(Navio), jogo->humano.totalNavios, arquivo);
    lerMatriz(arquivo, jogo->humano.campo, tamanho);
    lerMatriz(arquivo, jogo->humano.visaoAdversario, tamanho);

    fread(&jogo->computador.totalNavios, sizeof(int), 1, arquivo);
    fread(&jogo->computador.naviosAfundados, sizeof(int), 1, arquivo);
    jogo->computador.navios = (Navio *) malloc(jogo->computador.totalNavios * sizeof(Navio));
    jogo->computador.campo = criarMatriz(tamanho);
    jogo->computador.visaoAdversario = criarMatriz(tamanho);
    fread(jogo->computador.navios, sizeof(Navio), jogo->computador.totalNavios, arquivo);
    lerMatriz(arquivo, jogo->computador.campo, tamanho);
    lerMatriz(arquivo, jogo->computador.visaoAdversario, tamanho);

    fclose(arquivo);
    return 1;
}
