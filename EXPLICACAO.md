# Explicacao linha por linha de `batalha_naval.c`

A tabela abaixo mostra cada linha do codigo e uma explicacao simples ao lado.

| Linha | Codigo | Explicacao |
|---:|---|---|
| 1 | `#include &lt;stdio.h&gt;` | Inclui a biblioteca de entrada e saida, usada por `printf`, `scanf` e arquivos. |
| 2 | `#include &lt;stdlib.h&gt;` | Inclui funcoes gerais, como `malloc`, `free`, `rand`, `srand` e `exit`. |
| 3 | `#include &lt;time.h&gt;` | Inclui funcoes de tempo, usadas para iniciar o sorteio aleatorio. |
| 4 | &nbsp; | Linha em branco para separar partes do codigo. |
| 5 | `/* Valores usados dentro das matrizes do jogo. */` | Comentario dizendo que os proximos valores sao usados nas matrizes do jogo. |
| 6 | `#define AGUA 0` | Define `AGUA` como valor `0`. |
| 7 | `#define NAVIO_ACERTADO 2` | Define `NAVIO_ACERTADO` como valor `2`. |
| 8 | `#define MARCA_AGUA 3` | Define `MARCA_AGUA` como valor `3`, usado quando o jogador erra um tiro. |
| 9 | `#define MARCA_IMPACTO 4` | Define `MARCA_IMPACTO` como valor `4`, usado quando acerta parte de um navio. |
| 10 | `#define MARCA_AFUNDOU 5` | Define `MARCA_AFUNDOU` como valor `5`, usado quando um navio inteiro afunda. |
| 11 | `#define DESCONHECIDO 7` | Define `DESCONHECIDO` como valor `7`, usado em posicoes ainda nao atacadas. |
| 12 | `#define NAVIO_BASE 10` | Define `NAVIO_BASE` como valor `10`, para identificar navios internamente. |
| 13 | &nbsp; | Linha em branco para separar partes do codigo. |
| 14 | `/* Regras minimas do trabalho. */` | Comentario indicando as regras minimas do trabalho. |
| 15 | `#define TAMANHO_MINIMO 8` | Define o menor tamanho permitido para o tabuleiro. |
| 16 | `#define NAVIOS_MINIMOS 4` | Define a menor quantidade permitida de navios. |
| 17 | `#define ARQUIVO_DADOS "batalha_naval.bin"` | Define o nome do arquivo binario usado para salvar dados. |
| 18 | &nbsp; | Linha em branco para separar partes do codigo. |
| 19 | `/* Registro que guarda as configuracoes do jogo. */` | Comentario sobre o registro de configuracao. |
| 20 | `typedef struct` | Cria o tipo `Configuracao`, que guarda tamanho do campo e quantidade de navios. |
| 21 | `{` | Cria o tipo `Configuracao`, que guarda tamanho do campo e quantidade de navios. |
| 22 | `    int tamanho;` | Cria o tipo `Configuracao`, que guarda tamanho do campo e quantidade de navios. |
| 23 | `    int quantidadeNavios;` | Cria o tipo `Configuracao`, que guarda tamanho do campo e quantidade de navios. |
| 24 | `} Configuracao;` | Cria o tipo `Configuracao`, que guarda tamanho do campo e quantidade de navios. |
| 25 | &nbsp; | Linha em branco para separar partes do codigo. |
| 26 | `/* Registro que guarda as duas partes de um navio. */` | Comentario sobre o registro de navio. |
| 27 | `typedef struct` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 28 | `{` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 29 | `    int linha1;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 30 | `    int coluna1;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 31 | `    int linha2;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 32 | `    int coluna2;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 33 | `    int acertos;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 34 | `} Navio;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 35 | &nbsp; | Linha em branco para separar partes do codigo. |
| 36 | `/* Registro que guarda tudo que pertence a um jogador. */` | Comentario sobre o registro do jogador. |
| 37 | `typedef struct` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 38 | `{` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 39 | `    int **campo;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 40 | `    int **visaoAdversario;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 41 | `    Navio *navios;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 42 | `    int totalNavios;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 43 | `    int naviosAfundados;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 44 | `} Jogador;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 45 | &nbsp; | Linha em branco para separar partes do codigo. |
| 46 | `/* Registro que guarda uma partida inteira. */` | Comentario sobre o registro da partida completa. |
| 47 | `typedef struct` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 48 | `{` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 49 | `    Configuracao config;` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 50 | `    Jogador humano;` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 51 | `    Jogador computador;` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 52 | `    int turno;       /* 0 = humano, 1 = computador */` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 53 | `    int emAndamento; /* 1 = jogo ativo, 0 = jogo parado */` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 54 | `} Jogo;` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 55 | &nbsp; | Linha em branco para separar partes do codigo. |
| 56 | `/* Prototipos das funcoes. */` | Comentario indicando que vem a lista de prototipos das funcoes. |
| 57 | `int **criarMatriz(int tamanho);` | Declara a funcao que cria uma matriz. |
| 58 | `void liberarMatriz(int **matriz, int tamanho);` | Declara a funcao que libera uma matriz da memoria. |
| 59 | `void preencherMatriz(int **matriz, int tamanho, int valor);` | Declara a funcao que preenche uma matriz com um valor. |
| 60 | `void imprimirCampoProprio(int **campo, int tamanho);` | Declara a funcao que imprime o campo do proprio jogador. |
| 61 | `void imprimirCampoAdversario(int **campo, int tamanho);` | Declara a funcao que imprime o campo conhecido do adversario. |
| 62 | `void configuracaoPadrao(Configuracao *config);` | Declara a funcao que define a configuracao padrao. |
| 63 | `int salvarConfiguracao(Configuracao *config);` | Declara a funcao que salva a configuracao. |
| 64 | `int carregarConfiguracao(Configuracao *config);` | Declara a funcao que carrega a configuracao. |
| 65 | `int salvarJogo(Jogo *jogo);` | Declara a funcao que salva uma partida. |
| 66 | `int carregarJogo(Jogo *jogo);` | Declara a funcao que carrega uma partida. |
| 67 | `void inicializarJogo(Jogo *jogo, Configuracao config);` | Declara a funcao que inicia uma partida. |
| 68 | `void liberarJogo(Jogo *jogo);` | Declara a funcao que libera a memoria da partida. |
| 69 | `void executarPartida(Jogo *jogo);` | Declara a funcao que executa a partida. |
| 70 | `void configurarJogo(Configuracao *config);` | Declara a funcao que altera as configuracoes. |
| 71 | `int contarNaviosRestantes(Navio *navios, int total, int indice);` | Declara a funcao recursiva que conta navios restantes. |
| 72 | &nbsp; | Linha em branco para separar partes do codigo. |
| 73 | `/* Limpa o restante da linha quando o usuario digita algo invalido. */` | Comentario dizendo que a funcao limpa entradas invalidas. |
| 74 | `void limparEntrada(void)` | Inicio da funcao `limparEntrada`. |
| 75 | `{` | Abre ou fecha um bloco de codigo. |
| 76 | `    int c;` | Cria a variavel que recebe cada caractere digitado. |
| 77 | &nbsp; | Linha em branco para separar partes do codigo. |
| 78 | `    do` | Le caracteres ate chegar no fim da linha ou no fim do arquivo. |
| 79 | `    {` | Le caracteres ate chegar no fim da linha ou no fim do arquivo. |
| 80 | `        c = getchar();` | Le caracteres ate chegar no fim da linha ou no fim do arquivo. |
| 81 | `    } while (c != '\n' &amp;&amp; c != EOF);` | Le caracteres ate chegar no fim da linha ou no fim do arquivo. |
| 82 | `}` | Fecha a funcao. |
| 83 | &nbsp; | Linha em branco para separar partes do codigo. |
| 84 | `/* Le um numero inteiro do teclado. */` | Comentario dizendo que a funcao le um numero inteiro. |
| 85 | `int lerInteiro(char mensagem[])` | Inicio da funcao `lerInteiro`, recebendo uma mensagem para mostrar ao usuario. |
| 86 | `{` | Abre ou fecha um bloco de codigo. |
| 87 | `    int valor;` | Cria a variavel onde o numero sera guardado. |
| 88 | &nbsp; | Linha em branco para separar partes do codigo. |
| 89 | `    printf("%s", mensagem);` | Mostra a mensagem na tela. |
| 90 | `    while (scanf("%d", &amp;valor) != 1)` | Tenta ler um inteiro; se nao conseguir, entra no laco. |
| 91 | `    {` | Abre ou fecha um bloco de codigo. |
| 92 | `        limparEntrada();` | Limpa o que foi digitado errado. |
| 93 | `        printf("Digite um numero inteiro: ");` | Pede novamente um numero inteiro. |
| 94 | `    }` | Fecha o laco de validacao. |
| 95 | &nbsp; | Linha em branco para separar partes do codigo. |
| 96 | `    limparEntrada();` | Limpa o restante da linha depois da leitura correta. |
| 97 | `    return valor;` | Devolve o numero lido. |
| 98 | `}` | Fecha a funcao. |
| 99 | &nbsp; | Linha em branco para separar partes do codigo. |
| 100 | `/* Pausa a tela ate o usuario confirmar que leu as mensagens. */` | Comentario dizendo que a funcao pausa a tela. |
| 101 | `void aguardarEnter(void)` | Inicio da funcao `aguardarEnter`. |
| 102 | `{` | Abre ou fecha um bloco de codigo. |
| 103 | `    printf("Pressione ENTER para continuar...");` | Mostra a mensagem pedindo ENTER. |
| 104 | `    getchar();` | Espera o usuario apertar ENTER. |
| 105 | `}` | Fecha a funcao. |
| 106 | &nbsp; | Linha em branco para separar partes do codigo. |
| 107 | `/* Aloca uma matriz quadrada de inteiros usando ponteiros. */` | Comentario sobre alocar uma matriz quadrada. |
| 108 | `int **criarMatriz(int tamanho)` | Inicio da funcao `criarMatriz`. |
| 109 | `{` | Abre ou fecha um bloco de codigo. |
| 110 | `    int i;` | Cria o contador do laco. |
| 111 | `    int **matriz = (int **)malloc(tamanho * sizeof(int *));` | Aloca o vetor de ponteiros, um para cada linha da matriz. |
| 112 | &nbsp; | Linha em branco para separar partes do codigo. |
| 113 | `    if (matriz == NULL)` | Se a alocacao falhar, retorna `NULL`. |
| 114 | `    {` | Se a alocacao falhar, retorna `NULL`. |
| 115 | `        return NULL;` | Se a alocacao falhar, retorna `NULL`. |
| 116 | `    }` | Se a alocacao falhar, retorna `NULL`. |
| 117 | &nbsp; | Linha em branco para separar partes do codigo. |
| 118 | `    for (i = 0; i &lt; tamanho; i++)` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 119 | `    {` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 120 | `        matriz[i] = (int *)malloc(tamanho * sizeof(int));` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 121 | &nbsp; | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 122 | `        if (matriz[i] == NULL)` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 123 | `        {` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 124 | `            liberarMatriz(matriz, i);` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 125 | `            return NULL;` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 126 | `        }` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 127 | `    }` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 128 | &nbsp; | Linha em branco para separar partes do codigo. |
| 129 | `    return matriz;` | Retorna a matriz criada. |
| 130 | `}` | Fecha a funcao. |
| 131 | &nbsp; | Linha em branco para separar partes do codigo. |
| 132 | `/* Libera a memoria da matriz linha por linha. */` | Comentario sobre liberar uma matriz. |
| 133 | `void liberarMatriz(int **matriz, int tamanho)` | Inicio da funcao `liberarMatriz`. |
| 134 | `{` | Abre ou fecha um bloco de codigo. |
| 135 | `    int i;` | Cria o contador do laco. |
| 136 | &nbsp; | Linha em branco para separar partes do codigo. |
| 137 | `    if (matriz == NULL)` | Se a matriz for nula, sai da funcao. |
| 138 | `    {` | Se a matriz for nula, sai da funcao. |
| 139 | `        return;` | Se a matriz for nula, sai da funcao. |
| 140 | `    }` | Se a matriz for nula, sai da funcao. |
| 141 | &nbsp; | Linha em branco para separar partes do codigo. |
| 142 | `    for (i = 0; i &lt; tamanho; i++)` | Libera cada linha da matriz. |
| 143 | `    {` | Libera cada linha da matriz. |
| 144 | `        free(matriz[i]);` | Libera cada linha da matriz. |
| 145 | `    }` | Libera cada linha da matriz. |
| 146 | &nbsp; | Linha em branco para separar partes do codigo. |
| 147 | `    free(matriz);` | Libera o vetor principal da matriz. |
| 148 | `}` | Fecha a funcao. |
| 149 | &nbsp; | Linha em branco para separar partes do codigo. |
| 150 | `/* Preenche todas as posicoes de uma matriz com o mesmo valor. */` | Comentario sobre preencher uma matriz. |
| 151 | `void preencherMatriz(int **matriz, int tamanho, int valor)` | Inicio da funcao `preencherMatriz`. |
| 152 | `{` | Abre ou fecha um bloco de codigo. |
| 153 | `    int i;` | Cria os contadores de linha e coluna. |
| 154 | `    int j;` | Cria os contadores de linha e coluna. |
| 155 | &nbsp; | Linha em branco para separar partes do codigo. |
| 156 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as posicoes e coloca o valor informado. |
| 157 | `    {` | Percorre todas as posicoes e coloca o valor informado. |
| 158 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre todas as posicoes e coloca o valor informado. |
| 159 | `        {` | Percorre todas as posicoes e coloca o valor informado. |
| 160 | `            matriz[i][j] = valor;` | Percorre todas as posicoes e coloca o valor informado. |
| 161 | `        }` | Percorre todas as posicoes e coloca o valor informado. |
| 162 | `    }` | Percorre todas as posicoes e coloca o valor informado. |
| 163 | `}` | Fecha a funcao. |
| 164 | &nbsp; | Linha em branco para separar partes do codigo. |
| 165 | `/* Imprime os indices das colunas e as linhas separadoras. */` | Comentario sobre imprimir cabecalho. |
| 166 | `void imprimirCabecalho(int tamanho)` | Inicio da funcao `imprimirCabecalho`. |
| 167 | `{` | Abre ou fecha um bloco de codigo. |
| 168 | `    int j;` | Cria o contador de colunas. |
| 169 | &nbsp; | Linha em branco para separar partes do codigo. |
| 170 | `    printf("     ");` | Imprime espacos antes dos numeros das colunas. |
| 171 | `    for (j = 0; j &lt; tamanho; j++)` | Imprime os numeros das colunas. |
| 172 | `    {` | Imprime os numeros das colunas. |
| 173 | `        printf("%3d", j + 1);` | Imprime os numeros das colunas. |
| 174 | `    }` | Imprime os numeros das colunas. |
| 175 | `    printf("\n");` | Pula linha. |
| 176 | &nbsp; | Linha em branco para separar partes do codigo. |
| 177 | `    printf("    +");` | Imprime o inicio da linha separadora. |
| 178 | `    for (j = 0; j &lt; tamanho; j++)` | Imprime tracos da largura do campo. |
| 179 | `    {` | Imprime tracos da largura do campo. |
| 180 | `        printf("---");` | Imprime tracos da largura do campo. |
| 181 | `    }` | Imprime tracos da largura do campo. |
| 182 | `    printf("\n");` | Pula linha. |
| 183 | `}` | Fecha a funcao. |
| 184 | &nbsp; | Linha em branco para separar partes do codigo. |
| 185 | `/* Imprime o campo do jogador humano, mostrando os seus navios. */` | Comentario sobre imprimir o campo do jogador. |
| 186 | `void imprimirCampoProprio(int **campo, int tamanho)` | Inicio da funcao `imprimirCampoProprio`. |
| 187 | `{` | Abre ou fecha um bloco de codigo. |
| 188 | `    int i;` | Cria contadores e a variavel que guarda o valor da posicao. |
| 189 | `    int j;` | Cria contadores e a variavel que guarda o valor da posicao. |
| 190 | `    int valor;` | Cria contadores e a variavel que guarda o valor da posicao. |
| 191 | &nbsp; | Linha em branco para separar partes do codigo. |
| 192 | `    imprimirCabecalho(tamanho);` | Imprime o cabecalho do campo. |
| 193 | &nbsp; | Linha em branco para separar partes do codigo. |
| 194 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 195 | `    {` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 196 | `        printf("%3d &#124;", i + 1);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 197 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 198 | `        {` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 199 | `            valor = campo[i][j];` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 200 | &nbsp; | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 201 | `            if (valor == AGUA)` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 202 | `            {` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 203 | `                printf("%3d", AGUA);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 204 | `            }` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 205 | `            else if (valor == NAVIO_ACERTADO)` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 206 | `            {` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 207 | `                printf("%3d", NAVIO_ACERTADO);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 208 | `            }` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 209 | `            else if (valor &gt;= NAVIO_BASE)` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 210 | `            {` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 211 | `                printf("%3d", 1);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 212 | `            }` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 213 | `            else` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 214 | `            {` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 215 | `                printf("%3d", valor);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 216 | `            }` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 217 | `        }` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 218 | `        printf("\n");` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 219 | `    }` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 220 | `}` | Fecha a funcao. |
| 221 | &nbsp; | Linha em branco para separar partes do codigo. |
| 222 | `/* Imprime o que o jogador humano conhece do campo adversario. */` | Comentario sobre imprimir o campo adversario conhecido. |
| 223 | `void imprimirCampoAdversario(int **campo, int tamanho)` | Inicio da funcao `imprimirCampoAdversario`. |
| 224 | `{` | Abre ou fecha um bloco de codigo. |
| 225 | `    int i;` | Cria contadores de linha e coluna. |
| 226 | `    int j;` | Cria contadores de linha e coluna. |
| 227 | &nbsp; | Linha em branco para separar partes do codigo. |
| 228 | `    imprimirCabecalho(tamanho);` | Imprime o cabecalho. |
| 229 | &nbsp; | Linha em branco para separar partes do codigo. |
| 230 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 231 | `    {` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 232 | `        printf("%3d &#124;", i + 1);` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 233 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 234 | `        {` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 235 | `            printf("%3d", campo[i][j]);` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 236 | `        }` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 237 | `        printf("\n");` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 238 | `    }` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 239 | `}` | Fecha a funcao. |
| 240 | &nbsp; | Linha em branco para separar partes do codigo. |
| 241 | `/* Converte o valor interno do campo proprio para o numero que aparece na tela. */` | Comentario sobre converter valor interno em valor visivel. |
| 242 | `int valorVisivelCampoProprio(int valor)` | Inicio da funcao `valorVisivelCampoProprio`. |
| 243 | `{` | Abre ou fecha um bloco de codigo. |
| 244 | `    if (valor == AGUA)` | Se for agua, retorna `0`. |
| 245 | `    {` | Se for agua, retorna `0`. |
| 246 | `        return AGUA;` | Se for agua, retorna `0`. |
| 247 | `    }` | Se for agua, retorna `0`. |
| 248 | &nbsp; | Linha em branco para separar partes do codigo. |
| 249 | `    if (valor == NAVIO_ACERTADO)` | Se for navio acertado, retorna `2`. |
| 250 | `    {` | Se for navio acertado, retorna `2`. |
| 251 | `        return NAVIO_ACERTADO;` | Se for navio acertado, retorna `2`. |
| 252 | `    }` | Se for navio acertado, retorna `2`. |
| 253 | &nbsp; | Linha em branco para separar partes do codigo. |
| 254 | `    if (valor &gt;= NAVIO_BASE)` | Se for parte de navio ainda inteiro, mostra como `1`. |
| 255 | `    {` | Se for parte de navio ainda inteiro, mostra como `1`. |
| 256 | `        return 1;` | Se for parte de navio ainda inteiro, mostra como `1`. |
| 257 | `    }` | Se for parte de navio ainda inteiro, mostra como `1`. |
| 258 | &nbsp; | Linha em branco para separar partes do codigo. |
| 259 | `    return valor;` | Retorna outros valores sem alterar. |
| 260 | `}` | Fecha a funcao. |
| 261 | &nbsp; | Linha em branco para separar partes do codigo. |
| 262 | `/* Imprime uma linha com os indices das colunas para dois campos juntos. */` | Comentario sobre cabecalho duplo. |
| 263 | `void imprimirCabecalhoDuplo(int tamanho)` | Inicio da funcao `imprimirCabecalhoDuplo`. |
| 264 | `{` | Abre ou fecha um bloco de codigo. |
| 265 | `    int j;` | Cria o contador de colunas. |
| 266 | &nbsp; | Linha em branco para separar partes do codigo. |
| 267 | `    printf("     ");` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 268 | `    for (j = 0; j &lt; tamanho; j++)` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 269 | `    {` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 270 | `        printf("%3d", j + 1);` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 271 | `    }` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 272 | &nbsp; | Imprime os numeros das colunas dos dois campos lado a lado. |
| 273 | `    printf(" &#124; ");` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 274 | &nbsp; | Imprime os numeros das colunas dos dois campos lado a lado. |
| 275 | `    printf("     ");` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 276 | `    for (j = 0; j &lt; tamanho; j++)` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 277 | `    {` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 278 | `        printf("%3d", j + 1);` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 279 | `    }` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 280 | `    printf("\n");` | Imprime os numeros das colunas dos dois campos lado a lado. |
| 281 | &nbsp; | Linha em branco para separar partes do codigo. |
| 282 | `    printf("    +");` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 283 | `    for (j = 0; j &lt; tamanho; j++)` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 284 | `    {` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 285 | `        printf("---");` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 286 | `    }` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 287 | &nbsp; | Imprime as linhas separadoras dos dois campos lado a lado. |
| 288 | `    printf(" &#124; ");` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 289 | &nbsp; | Imprime as linhas separadoras dos dois campos lado a lado. |
| 290 | `    printf("    +");` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 291 | `    for (j = 0; j &lt; tamanho; j++)` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 292 | `    {` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 293 | `        printf("---");` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 294 | `    }` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 295 | `    printf("\n");` | Imprime as linhas separadoras dos dois campos lado a lado. |
| 296 | `}` | Fecha a funcao. |
| 297 | &nbsp; | Linha em branco para separar partes do codigo. |
| 298 | `/* Imprime o campo do jogador e o campo conhecido do computador juntos. */` | Comentario sobre imprimir dois campos lado a lado. |
| 299 | `void imprimirCamposLadoALado(int **campoHumano, int **campoComputador, int tamanho)` | Inicio da funcao `imprimirCamposLadoALado`. |
| 300 | `{` | Abre ou fecha um bloco de codigo. |
| 301 | `    int i;` | Cria contadores e a variavel de valor. |
| 302 | `    int j;` | Cria contadores e a variavel de valor. |
| 303 | `    int valor;` | Cria contadores e a variavel de valor. |
| 304 | &nbsp; | Linha em branco para separar partes do codigo. |
| 305 | `    imprimirCabecalhoDuplo(tamanho);` | Imprime o cabecalho duplo. |
| 306 | &nbsp; | Linha em branco para separar partes do codigo. |
| 307 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 308 | `    {` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 309 | `        printf("%3d &#124;", i + 1);` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 310 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 311 | `        {` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 312 | `            valor = valorVisivelCampoProprio(campoHumano[i][j]);` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 313 | `            printf("%3d", valor);` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 314 | `        }` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 315 | &nbsp; | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 316 | `        printf(" &#124; ");` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 317 | &nbsp; | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 318 | `        printf("%3d &#124;", i + 1);` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 319 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 320 | `        {` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 321 | `            printf("%3d", campoComputador[i][j]);` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 322 | `        }` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 323 | &nbsp; | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 324 | `        printf("\n");` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 325 | `    }` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 326 | `}` | Fecha a funcao. |
| 327 | &nbsp; | Linha em branco para separar partes do codigo. |
| 328 | `/* Define a configuracao minima caso nao exista arquivo salvo. */` | Comentario sobre configuracao padrao. |
| 329 | `void configuracaoPadrao(Configuracao *config)` | Inicio da funcao `configuracaoPadrao`. |
| 330 | `{` | Abre ou fecha um bloco de codigo. |
| 331 | `    config-&gt;tamanho = TAMANHO_MINIMO;` | Define o tamanho minimo do campo. |
| 332 | `    config-&gt;quantidadeNavios = NAVIOS_MINIMOS;` | Define a quantidade minima de navios. |
| 333 | `}` | Fecha a funcao. |
| 334 | &nbsp; | Linha em branco para separar partes do codigo. |
| 335 | `/* Salva somente a configuracao em arquivo binario. */` | Comentario sobre salvar configuracao. |
| 336 | `int salvarConfiguracao(Configuracao *config)` | Inicio da funcao `salvarConfiguracao`. |
| 337 | `{` | Abre ou fecha um bloco de codigo. |
| 338 | `    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");` | Abre o arquivo binario para escrita. |
| 339 | `    int temJogo = 0;` | Define que nao existe partida salva, apenas configuracao. |
| 340 | &nbsp; | Linha em branco para separar partes do codigo. |
| 341 | `    if (arquivo == NULL)` | Se o arquivo nao abrir, retorna erro. |
| 342 | `    {` | Se o arquivo nao abrir, retorna erro. |
| 343 | `        return 0;` | Se o arquivo nao abrir, retorna erro. |
| 344 | `    }` | Se o arquivo nao abrir, retorna erro. |
| 345 | &nbsp; | Linha em branco para separar partes do codigo. |
| 346 | `    fwrite(config, sizeof(Configuracao), 1, arquivo);` | Grava a configuracao no arquivo. |
| 347 | `    fwrite(&amp;temJogo, sizeof(int), 1, arquivo);` | Grava a informacao de que nao ha jogo salvo. |
| 348 | &nbsp; | Linha em branco para separar partes do codigo. |
| 349 | `    fclose(arquivo);` | Fecha o arquivo. |
| 350 | `    return 1;` | Retorna sucesso. |
| 351 | `}` | Fecha a funcao. |
| 352 | &nbsp; | Linha em branco para separar partes do codigo. |
| 353 | `/* Carrega a configuracao do arquivo binario. */` | Comentario sobre carregar configuracao. |
| 354 | `int carregarConfiguracao(Configuracao *config)` | Inicio da funcao `carregarConfiguracao`. |
| 355 | `{` | Abre ou fecha um bloco de codigo. |
| 356 | `    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");` | Abre o arquivo binario para leitura. |
| 357 | &nbsp; | Linha em branco para separar partes do codigo. |
| 358 | `    if (arquivo == NULL)` | Se o arquivo nao existir, usa a configuracao padrao e retorna erro. |
| 359 | `    {` | Se o arquivo nao existir, usa a configuracao padrao e retorna erro. |
| 360 | `        configuracaoPadrao(config);` | Se o arquivo nao existir, usa a configuracao padrao e retorna erro. |
| 361 | `        return 0;` | Se o arquivo nao existir, usa a configuracao padrao e retorna erro. |
| 362 | `    }` | Se o arquivo nao existir, usa a configuracao padrao e retorna erro. |
| 363 | &nbsp; | Linha em branco para separar partes do codigo. |
| 364 | `    fread(config, sizeof(Configuracao), 1, arquivo);` | Le a configuracao do arquivo. |
| 365 | `    fclose(arquivo);` | Fecha o arquivo. |
| 366 | `    return 1;` | Retorna sucesso. |
| 367 | `}` | Fecha a funcao. |
| 368 | &nbsp; | Linha em branco para separar partes do codigo. |
| 369 | `/* Escreve uma matriz no arquivo binario, linha por linha. */` | Comentario sobre escrever matriz no arquivo. |
| 370 | `void escreverMatriz(FILE *arquivo, int **matriz, int tamanho)` | Inicio da funcao `escreverMatriz`. |
| 371 | `{` | Abre ou fecha um bloco de codigo. |
| 372 | `    int i;` | Cria o contador de linhas. |
| 373 | &nbsp; | Linha em branco para separar partes do codigo. |
| 374 | `    for (i = 0; i &lt; tamanho; i++)` | Grava cada linha da matriz no arquivo. |
| 375 | `    {` | Grava cada linha da matriz no arquivo. |
| 376 | `        fwrite(matriz[i], sizeof(int), tamanho, arquivo);` | Grava cada linha da matriz no arquivo. |
| 377 | `    }` | Grava cada linha da matriz no arquivo. |
| 378 | `}` | Fecha a funcao. |
| 379 | &nbsp; | Linha em branco para separar partes do codigo. |
| 380 | `/* Le uma matriz do arquivo binario, linha por linha. */` | Comentario sobre ler matriz do arquivo. |
| 381 | `void lerMatriz(FILE *arquivo, int **matriz, int tamanho)` | Inicio da funcao `lerMatriz`. |
| 382 | `{` | Abre ou fecha um bloco de codigo. |
| 383 | `    int i;` | Cria o contador de linhas. |
| 384 | &nbsp; | Linha em branco para separar partes do codigo. |
| 385 | `    for (i = 0; i &lt; tamanho; i++)` | Le cada linha da matriz do arquivo. |
| 386 | `    {` | Le cada linha da matriz do arquivo. |
| 387 | `        fread(matriz[i], sizeof(int), tamanho, arquivo);` | Le cada linha da matriz do arquivo. |
| 388 | `    }` | Le cada linha da matriz do arquivo. |
| 389 | `}` | Fecha a funcao. |
| 390 | &nbsp; | Linha em branco para separar partes do codigo. |
| 391 | `/* Salva uma partida completa em arquivo binario. */` | Comentario sobre salvar partida completa. |
| 392 | `int salvarJogo(Jogo *jogo)` | Inicio da funcao `salvarJogo`. |
| 393 | `{` | Abre ou fecha um bloco de codigo. |
| 394 | `    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");` | Abre o arquivo binario para escrita. |
| 395 | `    int temJogo = 1;` | Marca que existe jogo salvo. |
| 396 | `    int tamanho = jogo-&gt;config.tamanho;` | Guarda o tamanho do campo em uma variavel. |
| 397 | &nbsp; | Linha em branco para separar partes do codigo. |
| 398 | `    if (arquivo == NULL)` | Se o arquivo nao abrir, retorna erro. |
| 399 | `    {` | Se o arquivo nao abrir, retorna erro. |
| 400 | `        return 0;` | Se o arquivo nao abrir, retorna erro. |
| 401 | `    }` | Se o arquivo nao abrir, retorna erro. |
| 402 | &nbsp; | Linha em branco para separar partes do codigo. |
| 403 | `    fwrite(&amp;jogo-&gt;config, sizeof(Configuracao), 1, arquivo);` | Salva configuracao, existencia do jogo, turno e estado da partida. |
| 404 | `    fwrite(&amp;temJogo, sizeof(int), 1, arquivo);` | Salva configuracao, existencia do jogo, turno e estado da partida. |
| 405 | `    fwrite(&amp;jogo-&gt;turno, sizeof(int), 1, arquivo);` | Salva configuracao, existencia do jogo, turno e estado da partida. |
| 406 | `    fwrite(&amp;jogo-&gt;emAndamento, sizeof(int), 1, arquivo);` | Salva configuracao, existencia do jogo, turno e estado da partida. |
| 407 | &nbsp; | Linha em branco para separar partes do codigo. |
| 408 | `    fwrite(&amp;jogo-&gt;humano.totalNavios, sizeof(int), 1, arquivo);` | Salva dados, navios e matrizes do jogador humano. |
| 409 | `    fwrite(&amp;jogo-&gt;humano.naviosAfundados, sizeof(int), 1, arquivo);` | Salva dados, navios e matrizes do jogador humano. |
| 410 | `    fwrite(jogo-&gt;humano.navios, sizeof(Navio), jogo-&gt;humano.totalNavios, arquivo);` | Salva dados, navios e matrizes do jogador humano. |
| 411 | `    escreverMatriz(arquivo, jogo-&gt;humano.campo, tamanho);` | Salva dados, navios e matrizes do jogador humano. |
| 412 | `    escreverMatriz(arquivo, jogo-&gt;humano.visaoAdversario, tamanho);` | Salva dados, navios e matrizes do jogador humano. |
| 413 | &nbsp; | Linha em branco para separar partes do codigo. |
| 414 | `    fwrite(&amp;jogo-&gt;computador.totalNavios, sizeof(int), 1, arquivo);` | Salva dados, navios e matrizes do computador. |
| 415 | `    fwrite(&amp;jogo-&gt;computador.naviosAfundados, sizeof(int), 1, arquivo);` | Salva dados, navios e matrizes do computador. |
| 416 | `    fwrite(jogo-&gt;computador.navios, sizeof(Navio), jogo-&gt;computador.totalNavios, arquivo);` | Salva dados, navios e matrizes do computador. |
| 417 | `    escreverMatriz(arquivo, jogo-&gt;computador.campo, tamanho);` | Salva dados, navios e matrizes do computador. |
| 418 | `    escreverMatriz(arquivo, jogo-&gt;computador.visaoAdversario, tamanho);` | Salva dados, navios e matrizes do computador. |
| 419 | &nbsp; | Linha em branco para separar partes do codigo. |
| 420 | `    fclose(arquivo);` | Fecha o arquivo. |
| 421 | `    return 1;` | Retorna sucesso. |
| 422 | `}` | Fecha a funcao. |
| 423 | &nbsp; | Linha em branco para separar partes do codigo. |
| 424 | `/* Carrega uma partida completa do arquivo binario. */` | Comentario sobre carregar partida completa. |
| 425 | `int carregarJogo(Jogo *jogo)` | Inicio da funcao `carregarJogo`. |
| 426 | `{` | Abre ou fecha um bloco de codigo. |
| 427 | `    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");` | Abre o arquivo binario para leitura. |
| 428 | `    int temJogo;` | Cria variavel que indica se existe jogo salvo. |
| 429 | `    int tamanho;` | Cria variavel para o tamanho do campo. |
| 430 | &nbsp; | Linha em branco para separar partes do codigo. |
| 431 | `    if (arquivo == NULL)` | Se o arquivo nao abrir, retorna erro. |
| 432 | `    {` | Se o arquivo nao abrir, retorna erro. |
| 433 | `        return 0;` | Se o arquivo nao abrir, retorna erro. |
| 434 | `    }` | Se o arquivo nao abrir, retorna erro. |
| 435 | &nbsp; | Linha em branco para separar partes do codigo. |
| 436 | `    fread(&amp;jogo-&gt;config, sizeof(Configuracao), 1, arquivo);` | Le configuracao e indicador de jogo salvo. |
| 437 | `    fread(&amp;temJogo, sizeof(int), 1, arquivo);` | Le configuracao e indicador de jogo salvo. |
| 438 | &nbsp; | Linha em branco para separar partes do codigo. |
| 439 | `    if (temJogo == 0)` | Se nao houver jogo salvo, fecha o arquivo e retorna erro. |
| 440 | `    {` | Se nao houver jogo salvo, fecha o arquivo e retorna erro. |
| 441 | `        fclose(arquivo);` | Se nao houver jogo salvo, fecha o arquivo e retorna erro. |
| 442 | `        return 0;` | Se nao houver jogo salvo, fecha o arquivo e retorna erro. |
| 443 | `    }` | Se nao houver jogo salvo, fecha o arquivo e retorna erro. |
| 444 | &nbsp; | Linha em branco para separar partes do codigo. |
| 445 | `    tamanho = jogo-&gt;config.tamanho;` | Copia o tamanho da configuracao. |
| 446 | &nbsp; | Linha em branco para separar partes do codigo. |
| 447 | `    fread(&amp;jogo-&gt;turno, sizeof(int), 1, arquivo);` | Le turno e estado da partida. |
| 448 | `    fread(&amp;jogo-&gt;emAndamento, sizeof(int), 1, arquivo);` | Le turno e estado da partida. |
| 449 | &nbsp; | Linha em branco para separar partes do codigo. |
| 450 | `    fread(&amp;jogo-&gt;humano.totalNavios, sizeof(int), 1, arquivo);` | Le dados do jogador humano e recria suas matrizes. |
| 451 | `    fread(&amp;jogo-&gt;humano.naviosAfundados, sizeof(int), 1, arquivo);` | Le dados do jogador humano e recria suas matrizes. |
| 452 | `    jogo-&gt;humano.navios = (Navio *)malloc(jogo-&gt;humano.totalNavios * sizeof(Navio));` | Le dados do jogador humano e recria suas matrizes. |
| 453 | `    jogo-&gt;humano.campo = criarMatriz(tamanho);` | Le dados do jogador humano e recria suas matrizes. |
| 454 | `    jogo-&gt;humano.visaoAdversario = criarMatriz(tamanho);` | Le dados do jogador humano e recria suas matrizes. |
| 455 | `    fread(jogo-&gt;humano.navios, sizeof(Navio), jogo-&gt;humano.totalNavios, arquivo);` | Le dados do jogador humano e recria suas matrizes. |
| 456 | `    lerMatriz(arquivo, jogo-&gt;humano.campo, tamanho);` | Le dados do jogador humano e recria suas matrizes. |
| 457 | `    lerMatriz(arquivo, jogo-&gt;humano.visaoAdversario, tamanho);` | Le dados do jogador humano e recria suas matrizes. |
| 458 | &nbsp; | Linha em branco para separar partes do codigo. |
| 459 | `    fread(&amp;jogo-&gt;computador.totalNavios, sizeof(int), 1, arquivo);` | Le dados do computador e recria suas matrizes. |
| 460 | `    fread(&amp;jogo-&gt;computador.naviosAfundados, sizeof(int), 1, arquivo);` | Le dados do computador e recria suas matrizes. |
| 461 | `    jogo-&gt;computador.navios = (Navio *)malloc(jogo-&gt;computador.totalNavios * sizeof(Navio));` | Le dados do computador e recria suas matrizes. |
| 462 | `    jogo-&gt;computador.campo = criarMatriz(tamanho);` | Le dados do computador e recria suas matrizes. |
| 463 | `    jogo-&gt;computador.visaoAdversario = criarMatriz(tamanho);` | Le dados do computador e recria suas matrizes. |
| 464 | `    fread(jogo-&gt;computador.navios, sizeof(Navio), jogo-&gt;computador.totalNavios, arquivo);` | Le dados do computador e recria suas matrizes. |
| 465 | `    lerMatriz(arquivo, jogo-&gt;computador.campo, tamanho);` | Le dados do computador e recria suas matrizes. |
| 466 | `    lerMatriz(arquivo, jogo-&gt;computador.visaoAdversario, tamanho);` | Le dados do computador e recria suas matrizes. |
| 467 | &nbsp; | Linha em branco para separar partes do codigo. |
| 468 | `    fclose(arquivo);` | Fecha o arquivo. |
| 469 | `    return 1;` | Retorna sucesso. |
| 470 | `}` | Fecha a funcao. |
| 471 | &nbsp; | Linha em branco para separar partes do codigo. |
| 472 | `/* Verifica se duas posicoes estao livres para colocar um navio. */` | Comentario sobre verificar posicoes livres. |
| 473 | `int posicaoLivre(int **campo, int linha1, int coluna1, int linha2, int coluna2)` | Inicio da funcao `posicaoLivre`. |
| 474 | `{` | Abre ou fecha um bloco de codigo. |
| 475 | `    return campo[linha1][coluna1] == AGUA &amp;&amp; campo[linha2][coluna2] == AGUA;` | Retorna verdadeiro se as duas posicoes estiverem com agua. |
| 476 | `}` | Fecha a funcao. |
| 477 | &nbsp; | Linha em branco para separar partes do codigo. |
| 478 | `/* Sorteia todos os navios de um jogador sem deixar sobrepor. */` | Comentario sobre sortear navios. |
| 479 | `void posicionarNavios(Jogador *jogador, int tamanho)` | Inicio da funcao `posicionarNavios`. |
| 480 | `{` | Abre ou fecha um bloco de codigo. |
| 481 | `    int i;` | Cria variaveis usadas para sortear posicoes e direcao. |
| 482 | `    int linha;` | Cria variaveis usadas para sortear posicoes e direcao. |
| 483 | `    int coluna;` | Cria variaveis usadas para sortear posicoes e direcao. |
| 484 | `    int direcao;` | Cria variaveis usadas para sortear posicoes e direcao. |
| 485 | `    int linha2;` | Cria variaveis usadas para sortear posicoes e direcao. |
| 486 | `    int coluna2;` | Cria variaveis usadas para sortear posicoes e direcao. |
| 487 | &nbsp; | Linha em branco para separar partes do codigo. |
| 488 | `    for (i = 0; i &lt; jogador-&gt;totalNavios; i++)` | Comeca um laco para posicionar todos os navios. |
| 489 | `    {` | Abre ou fecha um bloco de codigo. |
| 490 | `        do` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 491 | `        {` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 492 | `            linha = rand() % tamanho;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 493 | `            coluna = rand() % tamanho;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 494 | `            direcao = rand() % 2;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 495 | `            linha2 = linha;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 496 | `            coluna2 = coluna;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 497 | &nbsp; | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 498 | `            if (direcao == 0)` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 499 | `            {` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 500 | `                coluna2 = coluna + 1;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 501 | `            }` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 502 | `            else` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 503 | `            {` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 504 | `                linha2 = linha + 1;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 505 | `            }` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 506 | `        } while (linha2 &gt;= tamanho &#124;&#124; coluna2 &gt;= tamanho &#124;&#124;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 507 | `                 !posicaoLivre(jogador-&gt;campo, linha, coluna, linha2, coluna2));` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 508 | &nbsp; | Linha em branco para separar partes do codigo. |
| 509 | `        jogador-&gt;navios[i].linha1 = linha;` | Guarda as coordenadas e zera os acertos do navio. |
| 510 | `        jogador-&gt;navios[i].coluna1 = coluna;` | Guarda as coordenadas e zera os acertos do navio. |
| 511 | `        jogador-&gt;navios[i].linha2 = linha2;` | Guarda as coordenadas e zera os acertos do navio. |
| 512 | `        jogador-&gt;navios[i].coluna2 = coluna2;` | Guarda as coordenadas e zera os acertos do navio. |
| 513 | `        jogador-&gt;navios[i].acertos = 0;` | Guarda as coordenadas e zera os acertos do navio. |
| 514 | &nbsp; | Linha em branco para separar partes do codigo. |
| 515 | `        jogador-&gt;campo[linha][coluna] = NAVIO_BASE + i;` | Marca as duas partes do navio no campo. |
| 516 | `        jogador-&gt;campo[linha2][coluna2] = NAVIO_BASE + i;` | Marca as duas partes do navio no campo. |
| 517 | `    }` | Fecha o laco dos navios. |
| 518 | `}` | Fecha a funcao. |
| 519 | &nbsp; | Linha em branco para separar partes do codigo. |
| 520 | `/* Aloca e prepara as estruturas de um jogador. */` | Comentario sobre inicializar jogador. |
| 521 | `void inicializarJogador(Jogador *jogador, int tamanho, int totalNavios)` | Inicio da funcao `inicializarJogador`. |
| 522 | `{` | Abre ou fecha um bloco de codigo. |
| 523 | `    jogador-&gt;campo = criarMatriz(tamanho);` | Cria a matriz do campo do jogador. |
| 524 | `    jogador-&gt;visaoAdversario = criarMatriz(tamanho);` | Cria a matriz da visao do adversario. |
| 525 | `    jogador-&gt;navios = (Navio *)malloc(totalNavios * sizeof(Navio));` | Aloca o vetor de navios. |
| 526 | `    jogador-&gt;totalNavios = totalNavios;` | Guarda a quantidade total de navios. |
| 527 | `    jogador-&gt;naviosAfundados = 0;` | Zera a quantidade de navios afundados. |
| 528 | &nbsp; | Linha em branco para separar partes do codigo. |
| 529 | `    preencherMatriz(jogador-&gt;campo, tamanho, AGUA);` | Preenche o campo com agua. |
| 530 | `    preencherMatriz(jogador-&gt;visaoAdversario, tamanho, DESCONHECIDO);` | Preenche a visao do adversario com posicoes desconhecidas. |
| 531 | `    posicionarNavios(jogador, tamanho);` | Sorteia e posiciona os navios. |
| 532 | `}` | Fecha a funcao. |
| 533 | &nbsp; | Linha em branco para separar partes do codigo. |
| 534 | `/* Libera a memoria usada por um jogador. */` | Comentario sobre liberar memoria do jogador. |
| 535 | `void liberarJogador(Jogador *jogador, int tamanho)` | Inicio da funcao `liberarJogador`. |
| 536 | `{` | Abre ou fecha um bloco de codigo. |
| 537 | `    liberarMatriz(jogador-&gt;campo, tamanho);` | Libera a matriz do campo. |
| 538 | `    liberarMatriz(jogador-&gt;visaoAdversario, tamanho);` | Libera a matriz da visao do adversario. |
| 539 | `    free(jogador-&gt;navios);` | Libera o vetor de navios. |
| 540 | &nbsp; | Linha em branco para separar partes do codigo. |
| 541 | `    jogador-&gt;campo = NULL;` | Coloca os ponteiros como `NULL` para evitar uso indevido. |
| 542 | `    jogador-&gt;visaoAdversario = NULL;` | Coloca os ponteiros como `NULL` para evitar uso indevido. |
| 543 | `    jogador-&gt;navios = NULL;` | Coloca os ponteiros como `NULL` para evitar uso indevido. |
| 544 | `}` | Fecha a funcao. |
| 545 | &nbsp; | Linha em branco para separar partes do codigo. |
| 546 | `/* Cria uma nova partida. */` | Comentario sobre criar nova partida. |
| 547 | `void inicializarJogo(Jogo *jogo, Configuracao config)` | Inicio da funcao `inicializarJogo`. |
| 548 | `{` | Abre ou fecha um bloco de codigo. |
| 549 | `    jogo-&gt;config = config;` | Copia a configuracao para o jogo. |
| 550 | `    jogo-&gt;turno = 0;` | Define que o humano comeca. |
| 551 | `    jogo-&gt;emAndamento = 1;` | Marca o jogo como em andamento. |
| 552 | &nbsp; | Linha em branco para separar partes do codigo. |
| 553 | `    inicializarJogador(&amp;jogo-&gt;humano, config.tamanho, config.quantidadeNavios);` | Inicializa o jogador humano. |
| 554 | `    inicializarJogador(&amp;jogo-&gt;computador, config.tamanho, config.quantidadeNavios);` | Inicializa o computador. |
| 555 | `}` | Fecha a funcao. |
| 556 | &nbsp; | Linha em branco para separar partes do codigo. |
| 557 | `/* Libera a memoria usada pela partida. */` | Comentario sobre liberar memoria do jogo. |
| 558 | `void liberarJogo(Jogo *jogo)` | Inicio da funcao `liberarJogo`. |
| 559 | `{` | Abre ou fecha um bloco de codigo. |
| 560 | `    int tamanho = jogo-&gt;config.tamanho;` | Guarda o tamanho do campo. |
| 561 | &nbsp; | Linha em branco para separar partes do codigo. |
| 562 | `    liberarJogador(&amp;jogo-&gt;humano, tamanho);` | Libera os dados do humano. |
| 563 | `    liberarJogador(&amp;jogo-&gt;computador, tamanho);` | Libera os dados do computador. |
| 564 | `}` | Fecha a funcao. |
| 565 | &nbsp; | Linha em branco para separar partes do codigo. |
| 566 | `/* Funcao recursiva: conta navios que ainda nao foram afundados. */` | Comentario indicando que a funcao usa recursao. |
| 567 | `int contarNaviosRestantes(Navio *navios, int total, int indice)` | Inicio da funcao `contarNaviosRestantes`. |
| 568 | `{` | Abre ou fecha um bloco de codigo. |
| 569 | `    if (indice == total)` | Caso base: se chegou ao final do vetor, retorna zero. |
| 570 | `    {` | Caso base: se chegou ao final do vetor, retorna zero. |
| 571 | `        return 0;` | Caso base: se chegou ao final do vetor, retorna zero. |
| 572 | `    }` | Caso base: se chegou ao final do vetor, retorna zero. |
| 573 | &nbsp; | Linha em branco para separar partes do codigo. |
| 574 | `    if (navios[indice].acertos &lt; 2)` | Se o navio atual ainda nao afundou, conta ele e chama a funcao de novo. |
| 575 | `    {` | Se o navio atual ainda nao afundou, conta ele e chama a funcao de novo. |
| 576 | `        return 1 + contarNaviosRestantes(navios, total, indice + 1);` | Se o navio atual ainda nao afundou, conta ele e chama a funcao de novo. |
| 577 | `    }` | Se o navio atual ainda nao afundou, conta ele e chama a funcao de novo. |
| 578 | &nbsp; | Linha em branco para separar partes do codigo. |
| 579 | `    return contarNaviosRestantes(navios, total, indice + 1);` | Se o navio ja afundou, apenas continua a contagem. |
| 580 | `}` | Fecha a funcao. |
| 581 | &nbsp; | Linha em branco para separar partes do codigo. |
| 582 | `/* Mostra o significado dos numeros do tabuleiro. */` | Comentario sobre mostrar legenda. |
| 583 | `void mostrarLegenda(void)` | Inicio da funcao `mostrarLegenda`. |
| 584 | `{` | Abre ou fecha um bloco de codigo. |
| 585 | `    printf("\n===== LEGENDA =====\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 586 | `    printf("0 = Agua no seu campo\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 587 | `    printf("1 = Seu navio\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 588 | `    printf("2 = Parte do seu navio acertada\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 589 | `    printf("3 = Agua encontrada no campo adversario\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 590 | `    printf("4 = Impacto em navio adversario\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 591 | `    printf("5 = Navio adversario afundado\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 592 | `    printf("7 = Posicao desconhecida no campo adversario\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 593 | `}` | Fecha a funcao. |
| 594 | &nbsp; | Linha em branco para separar partes do codigo. |
| 595 | `/* Limpa a tela usando sequencia ANSI, sem depender do comando clear/cls. */` | Comentario sobre limpar a tela. |
| 596 | `void limparTela(void)` | Inicio da funcao `limparTela`. |
| 597 | `{` | Abre ou fecha um bloco de codigo. |
| 598 | `    printf("\033[2J\033[H");` | Imprime codigos ANSI para limpar a tela e voltar ao topo. |
| 599 | `    fflush(stdout);` | Forca a saida aparecer imediatamente. |
| 600 | `}` | Fecha a funcao. |
| 601 | &nbsp; | Linha em branco para separar partes do codigo. |
| 602 | `/* Mostra o campo do jogador e o campo conhecido do computador. */` | Comentario sobre mostrar os campos. |
| 603 | `void mostrarCampos(Jogo *jogo)` | Inicio da funcao `mostrarCampos`. |
| 604 | `{` | Abre ou fecha um bloco de codigo. |
| 605 | `    int restantesHumano;` | Cria variaveis para contadores, largura e textos. |
| 606 | `    int restantesComputador;` | Cria variaveis para contadores, largura e textos. |
| 607 | `    int larguraCampo = 5 + jogo-&gt;config.tamanho * 3;` | Cria variaveis para contadores, largura e textos. |
| 608 | `    char textoHumano[80];` | Cria variaveis para contadores, largura e textos. |
| 609 | `    char textoComputador[80];` | Cria variaveis para contadores, largura e textos. |
| 610 | &nbsp; | Linha em branco para separar partes do codigo. |
| 611 | `    restantesHumano = contarNaviosRestantes(jogo-&gt;humano.navios, jogo-&gt;humano.totalNavios, 0);` | Conta os navios restantes do humano. |
| 612 | `    restantesComputador = contarNaviosRestantes(jogo-&gt;computador.navios, jogo-&gt;computador.totalNavios, 0);` | Conta os navios restantes do computador. |
| 613 | `    sprintf(textoHumano, "Seus navios restantes: %d", restantesHumano);` | Monta o texto de navios restantes do humano. |
| 614 | `    sprintf(textoComputador, "Navios restantes do computador: %d", restantesComputador);` | Monta o texto de navios restantes do computador. |
| 615 | &nbsp; | Linha em branco para separar partes do codigo. |
| 616 | `    printf("\n%-*s &#124; %s\n", larguraCampo, "===== SEU CAMPO =====",` | Imprime os titulos dos dois campos. |
| 617 | `           "===== CAMPO DO COMPUTADOR CONHECIDO =====");` | Imprime os titulos dos dois campos. |
| 618 | `    printf("%-*s &#124; %s\n", larguraCampo, textoHumano, textoComputador);` | Imprime os titulos dos dois campos. |
| 619 | &nbsp; | Linha em branco para separar partes do codigo. |
| 620 | `    imprimirCamposLadoALado(jogo-&gt;humano.campo,` | Imprime os campos lado a lado. |
| 621 | `                            jogo-&gt;humano.visaoAdversario,` | Imprime os campos lado a lado. |
| 622 | `                            jogo-&gt;config.tamanho);` | Imprime os campos lado a lado. |
| 623 | &nbsp; | Linha em branco para separar partes do codigo. |
| 624 | `    mostrarLegenda();` | Mostra a legenda. |
| 625 | `    printf("\n");` | Pula uma linha. |
| 626 | `}` | Fecha a funcao. |
| 627 | &nbsp; | Linha em branco para separar partes do codigo. |
| 628 | `/* Procura o indice do navio que esta em uma posicao. */` | Comentario sobre procurar navio por posicao. |
| 629 | `int indiceNavioPorPosicao(Navio *navios, int total, int linha, int coluna)` | Inicio da funcao `indiceNavioPorPosicao`. |
| 630 | `{` | Abre ou fecha um bloco de codigo. |
| 631 | `    int i;` | Cria o contador do laco. |
| 632 | &nbsp; | Linha em branco para separar partes do codigo. |
| 633 | `    for (i = 0; i &lt; total; i++)` | Procura qual navio ocupa a linha e coluna informadas. |
| 634 | `    {` | Procura qual navio ocupa a linha e coluna informadas. |
| 635 | `        if ((navios[i].linha1 == linha &amp;&amp; navios[i].coluna1 == coluna) &#124;&#124;` | Procura qual navio ocupa a linha e coluna informadas. |
| 636 | `            (navios[i].linha2 == linha &amp;&amp; navios[i].coluna2 == coluna))` | Procura qual navio ocupa a linha e coluna informadas. |
| 637 | `        {` | Procura qual navio ocupa a linha e coluna informadas. |
| 638 | `            return i;` | Procura qual navio ocupa a linha e coluna informadas. |
| 639 | `        }` | Procura qual navio ocupa a linha e coluna informadas. |
| 640 | `    }` | Procura qual navio ocupa a linha e coluna informadas. |
| 641 | &nbsp; | Linha em branco para separar partes do codigo. |
| 642 | `    return -1;` | Retorna `-1` se nenhum navio for encontrado. |
| 643 | `}` | Fecha a funcao. |
| 644 | &nbsp; | Linha em branco para separar partes do codigo. |
| 645 | `/* Marca as duas partes de um navio afundado. */` | Comentario sobre marcar navio afundado. |
| 646 | `void marcarNavioAfundado(int **visao, Navio navio)` | Inicio da funcao `marcarNavioAfundado`. |
| 647 | `{` | Abre ou fecha um bloco de codigo. |
| 648 | `    visao[navio.linha1][navio.coluna1] = MARCA_AFUNDOU;` | Marca a primeira parte do navio como afundada. |
| 649 | `    visao[navio.linha2][navio.coluna2] = MARCA_AFUNDOU;` | Marca a segunda parte do navio como afundada. |
| 650 | `}` | Fecha a funcao. |
| 651 | &nbsp; | Linha em branco para separar partes do codigo. |
| 652 | `/* Faz um bombardeio e devolve Agua, Impacto ou Afundou. */` | Comentario sobre executar um bombardeio. |
| 653 | `int bombardear(Jogador *atacante, Jogador *defensor, int linha, int coluna)` | Inicio da funcao `bombardear`. |
| 654 | `{` | Abre ou fecha um bloco de codigo. |
| 655 | `    int indice;` | Cria variavel para guardar o indice do navio atingido. |
| 656 | `    int valor = defensor-&gt;campo[linha][coluna];` | Pega o valor da posicao atacada no campo do defensor. |
| 657 | &nbsp; | Linha em branco para separar partes do codigo. |
| 658 | `    if (valor == AGUA)` | Se acertou agua, marca agua na visao do atacante e retorna esse resultado. |
| 659 | `    {` | Se acertou agua, marca agua na visao do atacante e retorna esse resultado. |
| 660 | `        atacante-&gt;visaoAdversario[linha][coluna] = MARCA_AGUA;` | Se acertou agua, marca agua na visao do atacante e retorna esse resultado. |
| 661 | `        return MARCA_AGUA;` | Se acertou agua, marca agua na visao do atacante e retorna esse resultado. |
| 662 | `    }` | Se acertou agua, marca agua na visao do atacante e retorna esse resultado. |
| 663 | &nbsp; | Linha em branco para separar partes do codigo. |
| 664 | `    if (valor &gt;= NAVIO_BASE)` | Verifica se a posicao contem navio. |
| 665 | `    {` | Abre ou fecha um bloco de codigo. |
| 666 | `        indice = indiceNavioPorPosicao(defensor-&gt;navios, defensor-&gt;totalNavios, linha, coluna);` | Descobre qual navio foi atingido. |
| 667 | `        defensor-&gt;campo[linha][coluna] = NAVIO_ACERTADO;` | Marca a posicao como parte de navio acertada. |
| 668 | `        defensor-&gt;navios[indice].acertos++;` | Soma um acerto ao navio atingido. |
| 669 | &nbsp; | Linha em branco para separar partes do codigo. |
| 670 | `        if (defensor-&gt;navios[indice].acertos == 2)` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 671 | `        {` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 672 | `            defensor-&gt;naviosAfundados++;` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 673 | `            marcarNavioAfundado(atacante-&gt;visaoAdversario, defensor-&gt;navios[indice]);` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 674 | `            return MARCA_AFUNDOU;` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 675 | `        }` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 676 | `        else` | Se ainda nao afundou, marca impacto e retorna `4`. |
| 677 | `        {` | Se ainda nao afundou, marca impacto e retorna `4`. |
| 678 | `            atacante-&gt;visaoAdversario[linha][coluna] = MARCA_IMPACTO;` | Se ainda nao afundou, marca impacto e retorna `4`. |
| 679 | `            return MARCA_IMPACTO;` | Se ainda nao afundou, marca impacto e retorna `4`. |
| 680 | `        }` | Se ainda nao afundou, marca impacto e retorna `4`. |
| 681 | `    }` | Abre ou fecha um bloco de codigo. |
| 682 | &nbsp; | Linha em branco para separar partes do codigo. |
| 683 | `    return MARCA_AGUA;` | Retorna agua para qualquer outro caso. |
| 684 | `}` | Fecha a funcao. |
| 685 | &nbsp; | Linha em branco para separar partes do codigo. |
| 686 | `/* Mostra o texto do resultado de um bombardeio. */` | Comentario sobre mostrar resultado do bombardeio. |
| 687 | `void mostrarResultadoBombardeio(int resultado)` | Inicio da funcao `mostrarResultadoBombardeio`. |
| 688 | `{` | Abre ou fecha um bloco de codigo. |
| 689 | `    if (resultado == MARCA_AGUA)` | Se o resultado foi agua, imprime `Agua!`. |
| 690 | `    {` | Se o resultado foi agua, imprime `Agua!`. |
| 691 | `        printf("Agua!\n");` | Se o resultado foi agua, imprime `Agua!`. |
| 692 | `    }` | Se o resultado foi agua, imprime `Agua!`. |
| 693 | `    else if (resultado == MARCA_IMPACTO)` | Se foi impacto, imprime `Impacto!`. |
| 694 | `    {` | Se foi impacto, imprime `Impacto!`. |
| 695 | `        printf("Impacto!\n");` | Se foi impacto, imprime `Impacto!`. |
| 696 | `    }` | Se foi impacto, imprime `Impacto!`. |
| 697 | `    else` | Caso contrario, imprime `Afundou!`. |
| 698 | `    {` | Caso contrario, imprime `Afundou!`. |
| 699 | `        printf("Afundou!\n");` | Caso contrario, imprime `Afundou!`. |
| 700 | `    }` | Caso contrario, imprime `Afundou!`. |
| 701 | `}` | Fecha a funcao. |
| 702 | &nbsp; | Linha em branco para separar partes do codigo. |
| 703 | `/* Verifica se o jogador ja bombardeou uma posicao. */` | Comentario sobre verificar posicao ja bombardeada. |
| 704 | `int posicaoJaBombardeada(Jogador *atacante, int linha, int coluna)` | Inicio da funcao `posicaoJaBombardeada`. |
| 705 | `{` | Abre ou fecha um bloco de codigo. |
| 706 | `    return atacante-&gt;visaoAdversario[linha][coluna] != DESCONHECIDO;` | Retorna verdadeiro se a posicao nao esta mais desconhecida. |
| 707 | `}` | Fecha a funcao. |
| 708 | &nbsp; | Linha em branco para separar partes do codigo. |
| 709 | `/* Executa os tres bombardeios do jogador humano. */` | Comentario sobre os tres bombardeios do humano. |
| 710 | `int turnoHumano(Jogo *jogo)` | Inicio da funcao `turnoHumano`. |
| 711 | `{` | Abre ou fecha um bloco de codigo. |
| 712 | `    int i;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 713 | `    int linha;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 714 | `    int coluna;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 715 | `    int linhaEscolhida;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 716 | `    int colunaEscolhida;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 717 | `    int tamanho = jogo-&gt;config.tamanho;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 718 | `    int entradaValida;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 719 | &nbsp; | Linha em branco para separar partes do codigo. |
| 720 | `    for (i = 0; i &lt; 3; i++)` | Comeca o laco dos tres bombardeios. |
| 721 | `    {` | Abre ou fecha um bloco de codigo. |
| 722 | `        mostrarCampos(jogo);` | Mostra os campos. |
| 723 | `        printf("Bombardeio %d de 3\n", i + 1);` | Mostra qual bombardeio esta sendo feito. |
| 724 | `        printf("Digite 0 na linha para voltar ao menu sem salvar.\n");` | Explica que linha `0` volta ao menu sem salvar. |
| 725 | `        printf("Digite -1 na linha para salvar e voltar ao menu.\n");` | Explica que linha `-1` salva e volta ao menu. |
| 726 | &nbsp; | Linha em branco para separar partes do codigo. |
| 727 | `        do` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 728 | `        {` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 729 | `            entradaValida = 1;` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 730 | `            linhaEscolhida = lerInteiro("Escolha a linha do campo adversario: ");` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 731 | &nbsp; | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 732 | `            if (linhaEscolhida == 0)` | Se a linha for `0`, encerra a partida atual e volta ao menu. |
| 733 | `            {` | Se a linha for `0`, encerra a partida atual e volta ao menu. |
| 734 | `                jogo-&gt;emAndamento = 0;` | Se a linha for `0`, encerra a partida atual e volta ao menu. |
| 735 | `                return 0;` | Se a linha for `0`, encerra a partida atual e volta ao menu. |
| 736 | `            }` | Se a linha for `0`, encerra a partida atual e volta ao menu. |
| 737 | &nbsp; | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 738 | `            if (linhaEscolhida == -1)` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 739 | `            {` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 740 | `                salvarJogo(jogo);` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 741 | `                printf("Jogo salvo.\n");` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 742 | `                return 0;` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 743 | `            }` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 744 | &nbsp; | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 745 | `            if (linhaEscolhida &lt; 1 &#124;&#124; linhaEscolhida &gt; tamanho)` | Valida se a linha esta dentro do campo. |
| 746 | `            {` | Valida se a linha esta dentro do campo. |
| 747 | `                printf("Linha invalida. Use valores de 1 ate %d.\n", tamanho);` | Valida se a linha esta dentro do campo. |
| 748 | `                entradaValida = 0;` | Valida se a linha esta dentro do campo. |
| 749 | `            }` | Valida se a linha esta dentro do campo. |
| 750 | `            else` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 751 | `            {` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 752 | `                colunaEscolhida = lerInteiro("Escolha a coluna do campo adversario: ");` | Le a coluna escolhida. |
| 753 | &nbsp; | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 754 | `                if (colunaEscolhida &lt; 1 &#124;&#124; colunaEscolhida &gt; tamanho)` | Valida se a coluna esta dentro do campo. |
| 755 | `                {` | Valida se a coluna esta dentro do campo. |
| 756 | `                    printf("Coluna invalida. Use valores de 1 ate %d.\n", tamanho);` | Valida se a coluna esta dentro do campo. |
| 757 | `                    entradaValida = 0;` | Valida se a coluna esta dentro do campo. |
| 758 | `                }` | Valida se a coluna esta dentro do campo. |
| 759 | `                else` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 760 | `                {` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 761 | `                    linha = linhaEscolhida - 1;` | Converte linha e coluna de 1..N para 0..N-1. |
| 762 | `                    coluna = colunaEscolhida - 1;` | Converte linha e coluna de 1..N para 0..N-1. |
| 763 | `                }` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 764 | &nbsp; | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 765 | `                if (entradaValida &amp;&amp; posicaoJaBombardeada(&amp;jogo-&gt;humano, linha, coluna))` | Impede bombardear a mesma posicao duas vezes. |
| 766 | `                {` | Impede bombardear a mesma posicao duas vezes. |
| 767 | `                    printf("Essa posicao ja foi bombardeada.\n");` | Impede bombardear a mesma posicao duas vezes. |
| 768 | `                    entradaValida = 0;` | Impede bombardear a mesma posicao duas vezes. |
| 769 | `                }` | Impede bombardear a mesma posicao duas vezes. |
| 770 | `            }` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 771 | `        } while (!entradaValida);` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 772 | &nbsp; | Linha em branco para separar partes do codigo. |
| 773 | `        printf("\nResultado do bombardeio: ");` | Executa o bombardeio e mostra o resultado. |
| 774 | `        mostrarResultadoBombardeio(bombardear(&amp;jogo-&gt;humano, &amp;jogo-&gt;computador, linha, coluna));` | Executa o bombardeio e mostra o resultado. |
| 775 | &nbsp; | Linha em branco para separar partes do codigo. |
| 776 | `        if (jogo-&gt;computador.naviosAfundados == jogo-&gt;computador.totalNavios)` | Se todos os navios do computador afundaram, indica fim do jogo. |
| 777 | `        {` | Se todos os navios do computador afundaram, indica fim do jogo. |
| 778 | `            return 1;` | Se todos os navios do computador afundaram, indica fim do jogo. |
| 779 | `        }` | Se todos os navios do computador afundaram, indica fim do jogo. |
| 780 | `    }` | Abre ou fecha um bloco de codigo. |
| 781 | &nbsp; | Linha em branco para separar partes do codigo. |
| 782 | `    jogo-&gt;turno = 1;` | Passa o turno para o computador. |
| 783 | `    printf("\nFim do seu turno. Agora e a vez da maquina bombardear.\n");` | Mostra mensagem de fim do turno humano. |
| 784 | `    return 1;` | Retorna que a partida deve continuar. |
| 785 | `}` | Fecha a funcao. |
| 786 | &nbsp; | Linha em branco para separar partes do codigo. |
| 787 | `/* Converte uma posicao sorteada em linha e coluna. */` | Comentario sobre converter posicao em coordenada. |
| 788 | `void posicaoParaCoordenada(int posicao, int tamanho, int *linha, int *coluna)` | Inicio da funcao `posicaoParaCoordenada`. |
| 789 | `{` | Abre ou fecha um bloco de codigo. |
| 790 | `    posicao--;` | Ajusta a posicao para comecar em zero. |
| 791 | `    *linha = posicao / tamanho;` | Calcula a linha. |
| 792 | `    *coluna = posicao % tamanho;` | Calcula a coluna. |
| 793 | `}` | Fecha a funcao. |
| 794 | &nbsp; | Linha em branco para separar partes do codigo. |
| 795 | `/* Sorteia uma posicao valida para o computador. */` | Comentario sobre sortear posicao do computador. |
| 796 | `void sortearPosicaoComputador(Jogo *jogo, int *linha, int *coluna)` | Inicio da funcao `sortearPosicaoComputador`. |
| 797 | `{` | Abre ou fecha um bloco de codigo. |
| 798 | `    int posicao;` | Cria variavel para a posicao sorteada. |
| 799 | `    int limite = jogo-&gt;config.tamanho * jogo-&gt;config.tamanho;` | Calcula o total de casas do campo. |
| 800 | &nbsp; | Linha em branco para separar partes do codigo. |
| 801 | `    do` | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 802 | `    {` | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 803 | `        posicao = (rand() % limite) + 1;` | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 804 | `        posicaoParaCoordenada(posicao, jogo-&gt;config.tamanho, linha, coluna);` | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 805 | `    } while (posicaoJaBombardeada(&amp;jogo-&gt;computador, *linha, *coluna));` | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 806 | `}` | Fecha a funcao. |
| 807 | &nbsp; | Linha em branco para separar partes do codigo. |
| 808 | `/* Executa os tres bombardeios do computador. */` | Comentario sobre os tres bombardeios do computador. |
| 809 | `void turnoComputador(Jogo *jogo)` | Inicio da funcao `turnoComputador`. |
| 810 | `{` | Abre ou fecha um bloco de codigo. |
| 811 | `    int i;` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 812 | `    int j;` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 813 | `    int linha;` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 814 | `    int coluna;` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 815 | `    int totalBombardeios = 0;` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 816 | `    int linhas[3];` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 817 | `    int colunas[3];` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 818 | `    int resultados[3];` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 819 | &nbsp; | Linha em branco para separar partes do codigo. |
| 820 | `    for (i = 0; i &lt; 3; i++)` | Comeca o laco dos tres bombardeios. |
| 821 | `    {` | Abre ou fecha um bloco de codigo. |
| 822 | `        sortearPosicaoComputador(jogo, &amp;linha, &amp;coluna);` | Sorteia uma posicao valida. |
| 823 | `        linhas[i] = linha + 1;` | Guarda a linha e a coluna sorteadas, usando numeros que comecam em 1. |
| 824 | `        colunas[i] = coluna + 1;` | Guarda a linha e a coluna sorteadas, usando numeros que comecam em 1. |
| 825 | `        resultados[i] = bombardear(&amp;jogo-&gt;computador, &amp;jogo-&gt;humano, linha, coluna);` | Executa o bombardeio contra o humano. |
| 826 | `        totalBombardeios++;` | Aumenta o total de bombardeios feitos. |
| 827 | &nbsp; | Linha em branco para separar partes do codigo. |
| 828 | `        limparTela();` | Limpa a tela. |
| 829 | `        mostrarCampos(jogo);` | Mostra os campos atualizados. |
| 830 | `        printf("===== BOMBARDEIOS DA MAQUINA =====\n");` | Imprime o titulo dos bombardeios da maquina. |
| 831 | &nbsp; | Linha em branco para separar partes do codigo. |
| 832 | `        for (j = 0; j &lt; totalBombardeios; j++)` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 833 | `        {` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 834 | `            printf("Bombardeio %d de 3\n", j + 1);` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 835 | `            printf("A maquina bombardeou a linha %d e coluna %d.\n", linhas[j], colunas[j]);` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 836 | `            printf("\nResultado do bombardeio: ");` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 837 | `            mostrarResultadoBombardeio(resultados[j]);` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 838 | `            printf("\n");` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 839 | `        }` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 840 | &nbsp; | Linha em branco para separar partes do codigo. |
| 841 | `        if (jogo-&gt;humano.naviosAfundados == jogo-&gt;humano.totalNavios)` | Para o turno se todos os navios humanos afundaram. |
| 842 | `        {` | Para o turno se todos os navios humanos afundaram. |
| 843 | `            break;` | Para o turno se todos os navios humanos afundaram. |
| 844 | `        }` | Para o turno se todos os navios humanos afundaram. |
| 845 | `    }` | Abre ou fecha um bloco de codigo. |
| 846 | &nbsp; | Linha em branco para separar partes do codigo. |
| 847 | `    if (jogo-&gt;humano.naviosAfundados == jogo-&gt;humano.totalNavios)` | Se o humano perdeu, sai da funcao. |
| 848 | `    {` | Se o humano perdeu, sai da funcao. |
| 849 | `        return;` | Se o humano perdeu, sai da funcao. |
| 850 | `    }` | Se o humano perdeu, sai da funcao. |
| 851 | &nbsp; | Linha em branco para separar partes do codigo. |
| 852 | `    aguardarEnter();` | Espera o usuario apertar ENTER. |
| 853 | `    jogo-&gt;turno = 0;` | Devolve o turno para o humano. |
| 854 | `}` | Fecha a funcao. |
| 855 | &nbsp; | Linha em branco para separar partes do codigo. |
| 856 | `/* Menu que aparece depois de vitoria ou derrota. */` | Comentario sobre menu de fim de jogo. |
| 857 | `int menuFimDeJogo(void)` | Inicio da funcao `menuFimDeJogo`. |
| 858 | `{` | Abre ou fecha um bloco de codigo. |
| 859 | `    printf("\n1 - Jogar novamente\n");` | Mostra as opcoes depois de uma vitoria ou derrota. |
| 860 | `    printf("2 - Voltar ao menu principal\n");` | Mostra as opcoes depois de uma vitoria ou derrota. |
| 861 | `    printf("3 - Sair\n");` | Mostra as opcoes depois de uma vitoria ou derrota. |
| 862 | `    return lerInteiro("Escolha: ");` | Le e retorna a opcao escolhida. |
| 863 | `}` | Fecha a funcao. |
| 864 | &nbsp; | Linha em branco para separar partes do codigo. |
| 865 | `/* Controla a partida ate alguem vencer ou o jogador voltar ao menu. */` | Comentario sobre controlar a partida. |
| 866 | `void executarPartida(Jogo *jogo)` | Inicio da funcao `executarPartida`. |
| 867 | `{` | Abre ou fecha um bloco de codigo. |
| 868 | `    int opcao;` | Cria variavel para opcao do menu final. |
| 869 | `    int terminou = 0;` | Cria variavel para indicar se a partida terminou. |
| 870 | &nbsp; | Linha em branco para separar partes do codigo. |
| 871 | `    while (jogo-&gt;emAndamento &amp;&amp; !terminou)` | Mantem a partida rodando enquanto estiver em andamento e nao tiver vencedor. |
| 872 | `    {` | Abre ou fecha um bloco de codigo. |
| 873 | `        if (jogo-&gt;turno == 0)` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 874 | `        {` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 875 | `            if (!turnoHumano(jogo))` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 876 | `            {` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 877 | `                return;` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 878 | `            }` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 879 | `        }` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 880 | `        else` | Se for turno do computador, executa o turno do computador. |
| 881 | `        {` | Se for turno do computador, executa o turno do computador. |
| 882 | `            turnoComputador(jogo);` | Se for turno do computador, executa o turno do computador. |
| 883 | `        }` | Se for turno do computador, executa o turno do computador. |
| 884 | &nbsp; | Linha em branco para separar partes do codigo. |
| 885 | `        if (jogo-&gt;computador.naviosAfundados == jogo-&gt;computador.totalNavios)` | Se todos os navios do computador afundaram, mostra vitoria. |
| 886 | `        {` | Se todos os navios do computador afundaram, mostra vitoria. |
| 887 | `            printf("\nVoce venceu!\n");` | Se todos os navios do computador afundaram, mostra vitoria. |
| 888 | `            terminou = 1;` | Se todos os navios do computador afundaram, mostra vitoria. |
| 889 | `        }` | Se todos os navios do computador afundaram, mostra vitoria. |
| 890 | `        else if (jogo-&gt;humano.naviosAfundados == jogo-&gt;humano.totalNavios)` | Se todos os navios do humano afundaram, mostra derrota. |
| 891 | `        {` | Se todos os navios do humano afundaram, mostra derrota. |
| 892 | `            printf("\nVoce perdeu!\n");` | Se todos os navios do humano afundaram, mostra derrota. |
| 893 | `            terminou = 1;` | Se todos os navios do humano afundaram, mostra derrota. |
| 894 | `        }` | Se todos os navios do humano afundaram, mostra derrota. |
| 895 | `    }` | Abre ou fecha um bloco de codigo. |
| 896 | &nbsp; | Linha em branco para separar partes do codigo. |
| 897 | `    while (terminou)` | Enquanto a partida terminou, mostra o menu final. |
| 898 | `    {` | Abre ou fecha um bloco de codigo. |
| 899 | `        opcao = menuFimDeJogo();` | Le a opcao do menu final. |
| 900 | &nbsp; | Linha em branco para separar partes do codigo. |
| 901 | `        if (opcao == 1)` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 902 | `        {` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 903 | `            liberarJogo(jogo);` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 904 | `            inicializarJogo(jogo, jogo-&gt;config);` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 905 | `            executarPartida(jogo);` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 906 | `            terminou = 0;` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 907 | `        }` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 908 | `        else if (opcao == 2)` | Opcao 2: volta ao menu principal. |
| 909 | `        {` | Opcao 2: volta ao menu principal. |
| 910 | `            terminou = 0;` | Opcao 2: volta ao menu principal. |
| 911 | `        }` | Opcao 2: volta ao menu principal. |
| 912 | `        else if (opcao == 3)` | Opcao 3: encerra o programa. |
| 913 | `        {` | Opcao 3: encerra o programa. |
| 914 | `            jogo-&gt;emAndamento = 0;` | Opcao 3: encerra o programa. |
| 915 | `            terminou = 0;` | Opcao 3: encerra o programa. |
| 916 | `            exit(0);` | Opcao 3: encerra o programa. |
| 917 | `        }` | Opcao 3: encerra o programa. |
| 918 | `        else` | Qualquer outra opcao mostra erro. |
| 919 | `        {` | Qualquer outra opcao mostra erro. |
| 920 | `            printf("Opcao invalida.\n");` | Qualquer outra opcao mostra erro. |
| 921 | `        }` | Qualquer outra opcao mostra erro. |
| 922 | `    }` | Abre ou fecha um bloco de codigo. |
| 923 | `}` | Fecha a funcao. |
| 924 | &nbsp; | Linha em branco para separar partes do codigo. |
| 925 | `/* Permite mudar tamanho do campo e quantidade de navios. */` | Comentario sobre mudar configuracoes. |
| 926 | `void configurarJogo(Configuracao *config)` | Inicio da funcao `configurarJogo`. |
| 927 | `{` | Abre ou fecha um bloco de codigo. |
| 928 | `    int tamanho;` | Cria variaveis para tamanho, navios e maximo permitido. |
| 929 | `    int navios;` | Cria variaveis para tamanho, navios e maximo permitido. |
| 930 | `    int maximoNavios;` | Cria variaveis para tamanho, navios e maximo permitido. |
| 931 | &nbsp; | Linha em branco para separar partes do codigo. |
| 932 | `    tamanho = lerInteiro("Tamanho do campo quadrado (minimo 8): ");` | Le o tamanho do campo. |
| 933 | `    if (tamanho &lt; TAMANHO_MINIMO)` | Se o tamanho for menor que o minimo, usa o minimo. |
| 934 | `    {` | Se o tamanho for menor que o minimo, usa o minimo. |
| 935 | `        tamanho = TAMANHO_MINIMO;` | Se o tamanho for menor que o minimo, usa o minimo. |
| 936 | `    }` | Se o tamanho for menor que o minimo, usa o minimo. |
| 937 | &nbsp; | Linha em branco para separar partes do codigo. |
| 938 | `    maximoNavios = (tamanho * tamanho) / 2;` | Calcula o maximo de navios possivel. |
| 939 | `    navios = lerInteiro("Quantidade de navios de duas celulas (minimo 4): ");` | Le a quantidade de navios. |
| 940 | `    if (navios &lt; NAVIOS_MINIMOS)` | Se a quantidade for menor que o minimo, usa o minimo. |
| 941 | `    {` | Se a quantidade for menor que o minimo, usa o minimo. |
| 942 | `        navios = NAVIOS_MINIMOS;` | Se a quantidade for menor que o minimo, usa o minimo. |
| 943 | `    }` | Se a quantidade for menor que o minimo, usa o minimo. |
| 944 | `    if (navios &gt; maximoNavios)` | Se a quantidade passar do maximo, limita ao maximo. |
| 945 | `    {` | Se a quantidade passar do maximo, limita ao maximo. |
| 946 | `        navios = maximoNavios;` | Se a quantidade passar do maximo, limita ao maximo. |
| 947 | `    }` | Se a quantidade passar do maximo, limita ao maximo. |
| 948 | &nbsp; | Linha em branco para separar partes do codigo. |
| 949 | `    config-&gt;tamanho = tamanho;` | Salva o tamanho na configuracao. |
| 950 | `    config-&gt;quantidadeNavios = navios;` | Salva a quantidade de navios na configuracao. |
| 951 | &nbsp; | Linha em branco para separar partes do codigo. |
| 952 | `    if (salvarConfiguracao(config))` | Tenta salvar e mostra mensagem de sucesso. |
| 953 | `    {` | Tenta salvar e mostra mensagem de sucesso. |
| 954 | `        printf("Configuracao salva.\n");` | Tenta salvar e mostra mensagem de sucesso. |
| 955 | `    }` | Tenta salvar e mostra mensagem de sucesso. |
| 956 | `    else` | Se nao conseguir salvar, mostra mensagem de erro. |
| 957 | `    {` | Se nao conseguir salvar, mostra mensagem de erro. |
| 958 | `        printf("Nao foi possivel salvar a configuracao.\n");` | Se nao conseguir salvar, mostra mensagem de erro. |
| 959 | `    }` | Se nao conseguir salvar, mostra mensagem de erro. |
| 960 | `}` | Fecha a funcao. |
| 961 | &nbsp; | Linha em branco para separar partes do codigo. |
| 962 | `/* Le a opcao escolhida no menu principal. */` | Comentario sobre ler opcao do menu. |
| 963 | `int lerOpcaoMenu(void)` | Inicio da funcao `lerOpcaoMenu`. |
| 964 | `{` | Abre ou fecha um bloco de codigo. |
| 965 | `    return lerInteiro("Escolha: ");` | Le e retorna a opcao escolhida. |
| 966 | `}` | Fecha a funcao. |
| 967 | &nbsp; | Linha em branco para separar partes do codigo. |
| 968 | `/* Mostra o menu principal do jogo. */` | Comentario sobre mostrar menu principal. |
| 969 | `void mostrarMenu(Configuracao config)` | Inicio da funcao `mostrarMenu`. |
| 970 | `{` | Abre ou fecha um bloco de codigo. |
| 971 | `    printf("\n===== BATALHA NAVAL =====\n");` | Imprime o titulo do jogo. |
| 972 | `    printf("Configuracao atual: campo %dx%d, %d navios\n",` | Mostra a configuracao atual. |
| 973 | `           config.tamanho, config.tamanho, config.quantidadeNavios);` | Mostra a configuracao atual. |
| 974 | `    printf("1 - Novo Jogo\n");` | Mostra opcao de novo jogo. |
| 975 | `    printf("2 - Configurar\n");` | Mostra opcao de configurar. |
| 976 | `    printf("3 - Carregar\n");` | Mostra opcao de carregar jogo salvo. |
| 977 | `    printf("4 - Sair\n");` | Mostra opcao de sair. |
| 978 | `}` | Fecha a funcao. |
| 979 | &nbsp; | Linha em branco para separar partes do codigo. |
| 980 | `/* Funcao principal: o programa sempre comeca por aqui. */` | Comentario dizendo que o programa comeca na funcao principal. |
| 981 | `int main(void)` | Inicio da funcao `main`. |
| 982 | `{` | Abre ou fecha um bloco de codigo. |
| 983 | `    Configuracao config;` | Cria a variavel de configuracao. |
| 984 | `    Jogo jogo;` | Cria a variavel que guarda a partida. |
| 985 | `    int opcao;` | Cria a variavel da opcao escolhida. |
| 986 | `    int executando = 1;` | Cria variavel que mantem o menu rodando. |
| 987 | &nbsp; | Linha em branco para separar partes do codigo. |
| 988 | `    srand((unsigned int)time(NULL));` | Inicializa o sorteio aleatorio usando o horario atual. |
| 989 | `    carregarConfiguracao(&amp;config);` | Carrega configuracao salva ou usa a padrao. |
| 990 | &nbsp; | Linha em branco para separar partes do codigo. |
| 991 | `    while (executando)` | Comeca o laco principal do programa. |
| 992 | `    {` | Abre ou fecha um bloco de codigo. |
| 993 | `        mostrarMenu(config);` | Mostra o menu principal. |
| 994 | `        opcao = lerOpcaoMenu();` | Le a opcao escolhida. |
| 995 | &nbsp; | Linha em branco para separar partes do codigo. |
| 996 | `        if (opcao == 1)` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 997 | `        {` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 998 | `            inicializarJogo(&amp;jogo, config);` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 999 | `            executarPartida(&amp;jogo);` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 1000 | `            liberarJogo(&amp;jogo);` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 1001 | `        }` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 1002 | `        else if (opcao == 2)` | Opcao 2: abre a configuracao do jogo. |
| 1003 | `        {` | Opcao 2: abre a configuracao do jogo. |
| 1004 | `            configurarJogo(&amp;config);` | Opcao 2: abre a configuracao do jogo. |
| 1005 | `        }` | Opcao 2: abre a configuracao do jogo. |
| 1006 | `        else if (opcao == 3)` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1007 | `        {` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1008 | `            if (carregarJogo(&amp;jogo))` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1009 | `            {` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1010 | `                executarPartida(&amp;jogo);` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1011 | `                liberarJogo(&amp;jogo);` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1012 | `                carregarConfiguracao(&amp;config);` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1013 | `            }` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1014 | `            else` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1015 | `            {` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1016 | `                printf("Nenhum jogo salvo encontrado.\n");` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1017 | `            }` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1018 | `        }` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1019 | `        else if (opcao == 4)` | Opcao 4: encerra o laco principal. |
| 1020 | `        {` | Opcao 4: encerra o laco principal. |
| 1021 | `            executando = 0;` | Opcao 4: encerra o laco principal. |
| 1022 | `        }` | Opcao 4: encerra o laco principal. |
| 1023 | `        else` | Qualquer outra opcao mostra erro. |
| 1024 | `        {` | Qualquer outra opcao mostra erro. |
| 1025 | `            printf("Opcao invalida.\n");` | Qualquer outra opcao mostra erro. |
| 1026 | `        }` | Qualquer outra opcao mostra erro. |
| 1027 | `    }` | Fecha o laco principal. |
| 1028 | &nbsp; | Linha em branco para separar partes do codigo. |
| 1029 | `    printf("Programa encerrado.\n");` | Mostra mensagem de encerramento. |
| 1030 | `    return 0;` | Retorna zero, indicando que o programa terminou corretamente. |
| 1031 | `}` | Fecha a funcao `main`. |
