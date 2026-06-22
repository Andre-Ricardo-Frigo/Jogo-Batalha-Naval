#ifndef BATALHA_H
#define BATALHA_H

/* Valores usados nas matrizes do jogo. */
#define AGUA 0
#define NAVIO_ACERTADO 2
#define MARCA_AGUA 3
#define MARCA_IMPACTO 4
#define MARCA_AFUNDOU 5
#define DESCONHECIDO 7
#define NAVIO_BASE 10

#define TAMANHO_MINIMO 8
#define NAVIOS_MINIMOS 4
#define ARQUIVO_DADOS "batalha_naval.bin"

/* Guarda as configuracoes escolhidas pelo usuario. */
typedef struct {
    int tamanho;
    int quantidadeNavios;
} Configuracao;

/* Guarda as duas posicoes ocupadas por um navio e seus acertos. */
typedef struct {
    int linha1;
    int coluna1;
    int linha2;
    int coluna2;
    int acertos;
} Navio;

/* Guarda os dados de um jogador. */
typedef struct {
    int **campo;
    int **visaoAdversario;
    Navio *navios;
    int totalNavios;
    int naviosAfundados;
} Jogador;

/* Guarda todo o estado necessario para salvar e carregar uma partida. */
typedef struct {
    Configuracao config;
    Jogador humano;
    Jogador computador;
    int turno; /* 0 = humano, 1 = computador */
    int emAndamento;
} Jogo;

/* matriz.c */
int **criarMatriz(int tamanho);
void liberarMatriz(int **matriz, int tamanho);
void preencherMatriz(int **matriz, int tamanho, int valor);
void imprimirCampoProprio(int **campo, int tamanho);
void imprimirCampoAdversario(int **campo, int tamanho);
void copiarMatriz(int **origem, int **destino, int tamanho);

/* arquivo.c */
void configuracaoPadrao(Configuracao *config);
int salvarConfiguracao(Configuracao *config);
int carregarConfiguracao(Configuracao *config);
int salvarJogo(Jogo *jogo);
int carregarJogo(Jogo *jogo);

/* jogo.c */
void inicializarJogo(Jogo *jogo, Configuracao config);
void liberarJogo(Jogo *jogo);
void executarPartida(Jogo *jogo);
void configurarJogo(Configuracao *config);
int contarNaviosRestantes(Navio *navios, int total, int indice);

#endif
