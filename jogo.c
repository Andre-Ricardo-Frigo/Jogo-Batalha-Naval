#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "batalha.h"

/* Limpa caracteres restantes quando a leitura com scanf falha. */
void limparEntrada(void) {
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/* Le um numero inteiro do teclado. */
int lerInteiro(const char *mensagem) {
    int valor;

    printf("%s", mensagem);
    while (scanf("%d", &valor) != 1) {
        limparEntrada();
        printf("Digite um numero inteiro: ");
    }

    return valor;
}

/* Pausa a tela para o jogador conseguir ler a mensagem exibida. */
void pausarTela(void) {
    limparEntrada();
    printf("Pressione ENTER para continuar...");
    getchar();
}

/* Converte uma posicao de 1 ate tamanho*tamanho em linha e coluna. */
void posicaoParaCoordenada(int posicao, int tamanho, int *linha, int *coluna) {
    posicao--;
    *linha = posicao / tamanho;
    *coluna = posicao % tamanho;
}

/* Procura qual navio ocupa uma posicao do campo. */
int indiceNavioPorPosicao(Navio *navios, int total, int linha, int coluna) {
    int i;

    for (i = 0; i < total; i++) {
        if ((navios[i].linha1 == linha && navios[i].coluna1 == coluna) ||
            (navios[i].linha2 == linha && navios[i].coluna2 == coluna)) {
            return i;
        }
    }

    return -1;
}

/* Marca as duas partes de um navio afundado na visao do adversario. */
void marcarNavioAfundado(int **visao, Navio navio) {
    visao[navio.linha1][navio.coluna1] = MARCA_AFUNDOU;
    visao[navio.linha2][navio.coluna2] = MARCA_AFUNDOU;
}

/* Verifica se ainda existem celulas livres para colocar o navio. */
int posicaoLivre(int **campo, int linha1, int coluna1, int linha2, int coluna2) {
    return campo[linha1][coluna1] == AGUA && campo[linha2][coluna2] == AGUA;
}

/* Sorteia navios de duas celulas, sem permitir sobreposicao. */
void posicionarNavios(Jogador *jogador, int tamanho) {
    int i;
    int linha;
    int coluna;
    int direcao;
    int linha2;
    int coluna2;

    for (i = 0; i < jogador->totalNavios; i++) {
        do {
            linha = rand() % tamanho;
            coluna = rand() % tamanho;
            direcao = rand() % 2; /* 0 = horizontal, 1 = vertical */
            linha2 = linha;
            coluna2 = coluna;

            if (direcao == 0) {
                coluna2 = coluna + 1;
            } else {
                linha2 = linha + 1;
            }
        } while (linha2 >= tamanho || coluna2 >= tamanho ||
                 !posicaoLivre(jogador->campo, linha, coluna, linha2, coluna2));

        jogador->navios[i].linha1 = linha;
        jogador->navios[i].coluna1 = coluna;
        jogador->navios[i].linha2 = linha2;
        jogador->navios[i].coluna2 = coluna2;
        jogador->navios[i].acertos = 0;

        jogador->campo[linha][coluna] = NAVIO_BASE + i;
        jogador->campo[linha2][coluna2] = NAVIO_BASE + i;
    }
}

/* Inicializa as estruturas de um jogador. */
void inicializarJogador(Jogador *jogador, int tamanho, int totalNavios) {
    jogador->campo = criarMatriz(tamanho);
    jogador->visaoAdversario = criarMatriz(tamanho);
    jogador->navios = (Navio *) malloc(totalNavios * sizeof(Navio));
    jogador->totalNavios = totalNavios;
    jogador->naviosAfundados = 0;

    preencherMatriz(jogador->campo, tamanho, AGUA);
    preencherMatriz(jogador->visaoAdversario, tamanho, DESCONHECIDO);
    posicionarNavios(jogador, tamanho);
}

/* Libera as estruturas de um jogador. */
void liberarJogador(Jogador *jogador, int tamanho) {
    liberarMatriz(jogador->campo, tamanho);
    liberarMatriz(jogador->visaoAdversario, tamanho);
    free(jogador->navios);

    jogador->campo = NULL;
    jogador->visaoAdversario = NULL;
    jogador->navios = NULL;
}

/* Cria uma nova partida com as configuracoes recebidas. */
void inicializarJogo(Jogo *jogo, Configuracao config) {
    jogo->config = config;
    jogo->turno = 0;
    jogo->emAndamento = 1;

    inicializarJogador(&jogo->humano, config.tamanho, config.quantidadeNavios);
    inicializarJogador(&jogo->computador, config.tamanho, config.quantidadeNavios);
}

/* Libera toda a memoria alocada para a partida. */
void liberarJogo(Jogo *jogo) {
    int tamanho = jogo->config.tamanho;

    liberarJogador(&jogo->humano, tamanho);
    liberarJogador(&jogo->computador, tamanho);
}

/* Funcao recursiva exigida no trabalho: conta navios ainda nao afundados. */
int contarNaviosRestantes(Navio *navios, int total, int indice) {
    if (indice == total) {
        return 0;
    }

    if (navios[indice].acertos < 2) {
        return 1 + contarNaviosRestantes(navios, total, indice + 1);
    }

    return contarNaviosRestantes(navios, total, indice + 1);
}

/* Mostra o significado dos numeros usados nos tabuleiros. */
void mostrarLegenda(void) {
    printf("\n===== LEGENDA =====\n");
    printf("0 = Agua no seu campo\n");
    printf("1 = Seu navio\n");
    printf("2 = Parte do seu navio acertada\n");
    printf("3 = Agua encontrada no campo adversario\n");
    printf("4 = Impacto em navio adversario\n");
    printf("5 = Navio adversario afundado\n");
    printf("7 = Posicao desconhecida no campo adversario\n");
}

/* Mostra os dois campos relevantes para o jogador humano. */
void mostrarCampos(Jogo *jogo) {
    int restantesHumano;
    int restantesComputador;

    restantesHumano = contarNaviosRestantes(jogo->humano.navios, jogo->humano.totalNavios, 0);
    restantesComputador = contarNaviosRestantes(jogo->computador.navios, jogo->computador.totalNavios, 0);

    printf("\n===== SEU CAMPO =====\n");
    printf("Seus navios restantes: %d\n", restantesHumano);
    imprimirCampoProprio(jogo->humano.campo, jogo->config.tamanho);

    printf("\n===== CAMPO DO COMPUTADOR CONHECIDO =====\n");
    printf("Navios restantes do computador: %d\n", restantesComputador);
    imprimirCampoAdversario(jogo->humano.visaoAdversario, jogo->config.tamanho);
    mostrarLegenda();
    printf("\n");
}

/* Processa um bombardeio e altera as matrizes conforme o resultado. */
int bombardear(Jogador *atacante, Jogador *defensor, int linha, int coluna) {
    int indice;
    int valor = defensor->campo[linha][coluna];

    if (valor == AGUA) {
        atacante->visaoAdversario[linha][coluna] = MARCA_AGUA;
        printf("Agua!\n");
        return 1;
    }

    if (valor >= NAVIO_BASE) {
        indice = indiceNavioPorPosicao(defensor->navios, defensor->totalNavios, linha, coluna);
        defensor->campo[linha][coluna] = NAVIO_ACERTADO;
        defensor->navios[indice].acertos++;

        if (defensor->navios[indice].acertos == 2) {
            defensor->naviosAfundados++;
            marcarNavioAfundado(atacante->visaoAdversario, defensor->navios[indice]);
            printf("Afundou!\n");
        } else {
            atacante->visaoAdversario[linha][coluna] = MARCA_IMPACTO;
            printf("Impacto!\n");
        }

        return 1;
    }

    return 0;
}

/* Verifica se uma posicao ja foi bombardeada pelo jogador atacante. */
int posicaoJaBombardeada(Jogador *atacante, int linha, int coluna) {
    return atacante->visaoAdversario[linha][coluna] != DESCONHECIDO;
}

/* Executa os tres bombardeios do jogador humano. */
int turnoHumano(Jogo *jogo) {
    int i;
    int linha;
    int coluna;
    int linhaEscolhida;
    int colunaEscolhida;
    int tamanho = jogo->config.tamanho;
    int entradaValida;

    for (i = 0; i < 3; i++) {
        mostrarCampos(jogo);
        printf("Bombardeio %d de 3\n", i + 1);
        printf("Digite 0 na linha para voltar ao menu sem salvar.\n");
        printf("Digite -1 na linha para salvar e voltar ao menu.\n");

        do {
            entradaValida = 1;
            linhaEscolhida = lerInteiro("Escolha a linha do campo adversario: ");

            if (linhaEscolhida == 0) {
                jogo->emAndamento = 0;
                return 0;
            }

            if (linhaEscolhida == -1) {
                salvarJogo(jogo);
                printf("Jogo salvo.\n");
                return 0;
            }

            if (linhaEscolhida < 1 || linhaEscolhida > tamanho) {
                printf("Linha invalida. Use valores de 1 ate %d.\n", tamanho);
                entradaValida = 0;
            } else {
                colunaEscolhida = lerInteiro("Escolha a coluna do campo adversario: ");

                if (colunaEscolhida < 1 || colunaEscolhida > tamanho) {
                    printf("Coluna invalida. Use valores de 1 ate %d.\n", tamanho);
                    entradaValida = 0;
                } else {
                    linha = linhaEscolhida - 1;
                    coluna = colunaEscolhida - 1;
                }

                if (entradaValida && posicaoJaBombardeada(&jogo->humano, linha, coluna)) {
                    printf("Essa posicao ja foi bombardeada.\n");
                    entradaValida = 0;
                }
            }
        } while (!entradaValida);

        printf("\nResultado do bombardeio: ");
        bombardear(&jogo->humano, &jogo->computador, linha, coluna);
        pausarTela();

        if (jogo->computador.naviosAfundados == jogo->computador.totalNavios) {
            return 1;
        }
    }

    jogo->turno = 1;
    return 1;
}

/* Sorteia uma posicao valida para o computador bombardear. */
void sortearPosicaoComputador(Jogo *jogo, int *linha, int *coluna) {
    int posicao;
    int limite = jogo->config.tamanho * jogo->config.tamanho;

    do {
        posicao = (rand() % limite) + 1;
        posicaoParaCoordenada(posicao, jogo->config.tamanho, linha, coluna);
    } while (posicaoJaBombardeada(&jogo->computador, *linha, *coluna));
}

/* Executa os tres bombardeios do computador. */
void turnoComputador(Jogo *jogo) {
    int i;
    int linha;
    int coluna;
    int posicao;

    printf("\nTurno do computador.\n");

    for (i = 0; i < 3; i++) {
        sortearPosicaoComputador(jogo, &linha, &coluna);
        posicao = linha * jogo->config.tamanho + coluna + 1;
        printf("Computador bombardeou a posicao %d: ", posicao);
        bombardear(&jogo->computador, &jogo->humano, linha, coluna);
        pausarTela();

        if (jogo->humano.naviosAfundados == jogo->humano.totalNavios) {
            return;
        }
    }

    jogo->turno = 0;
}

/* Menu exibido ao final da partida. */
int menuFimDeJogo(void) {
    printf("\n1 - Jogar novamente\n");
    printf("2 - Voltar ao menu principal\n");
    printf("3 - Sair\n");
    return lerInteiro("Escolha: ");
}

/* Executa a partida ate vitoria, derrota ou encerramento pelo usuario. */
void executarPartida(Jogo *jogo) {
    int opcao;
    int terminou = 0;

    while (jogo->emAndamento && !terminou) {
        if (jogo->turno == 0) {
            if (!turnoHumano(jogo)) {
                return;
            }
        } else {
            turnoComputador(jogo);
        }

        if (jogo->computador.naviosAfundados == jogo->computador.totalNavios) {
            printf("\nVoce venceu!\n");
            terminou = 1;
        } else if (jogo->humano.naviosAfundados == jogo->humano.totalNavios) {
            printf("\nVoce perdeu!\n");
            terminou = 1;
        }
    }

    while (terminou) {
        opcao = menuFimDeJogo();

        if (opcao == 1) {
            liberarJogo(jogo);
            inicializarJogo(jogo, jogo->config);
            executarPartida(jogo);
            terminou = 0;
        } else if (opcao == 2) {
            terminou = 0;
        } else if (opcao == 3) {
            jogo->emAndamento = 0;
            terminou = 0;
            exit(0);
        } else {
            printf("Opcao invalida.\n");
        }
    }
}

/* Permite alterar tamanho do campo e quantidade de navios. */
void configurarJogo(Configuracao *config) {
    int tamanho;
    int navios;
    int maximoNavios;

    tamanho = lerInteiro("Tamanho do campo quadrado (minimo 8): ");
    if (tamanho < TAMANHO_MINIMO) {
        tamanho = TAMANHO_MINIMO;
    }

    maximoNavios = (tamanho * tamanho) / 2;
    navios = lerInteiro("Quantidade de navios de duas celulas (minimo 4): ");
    if (navios < NAVIOS_MINIMOS) {
        navios = NAVIOS_MINIMOS;
    }
    if (navios > maximoNavios) {
        navios = maximoNavios;
    }

    config->tamanho = tamanho;
    config->quantidadeNavios = navios;

    if (salvarConfiguracao(config)) {
        printf("Configuracao salva.\n");
    } else {
        printf("Nao foi possivel salvar a configuracao.\n");
    }
}
