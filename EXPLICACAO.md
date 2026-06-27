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
| 20 | `typedef struct` | Comeca a declaracao de um registro. |
| 21 | `{` | Abre um bloco de codigo. |
| 22 | `    int tamanho;` | Declara uma variavel inteira. |
| 23 | `    int quantidadeNavios;` | Cria o tipo `Configuracao`, que guarda tamanho do campo e quantidade de navios. |
| 24 | `} Configuracao;` | Cria o tipo `Configuracao`, que guarda tamanho do campo e quantidade de navios. |
| 25 | &nbsp; | Linha em branco para separar partes do codigo. |
| 26 | `/* Registro que guarda as duas partes de um navio. */` | Comentario sobre o registro de navio. |
| 27 | `typedef struct` | Comeca a declaracao de um registro. |
| 28 | `{` | Abre um bloco de codigo. |
| 29 | `    int linha1;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 30 | `    int coluna1;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 31 | `    int linha2;` | Declara uma variavel inteira. |
| 32 | `    int coluna2;` | Declara uma variavel inteira. |
| 33 | `    int acertos;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 34 | `} Navio;` | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 35 | &nbsp; | Linha em branco para separar partes do codigo. |
| 36 | `/* Registro que guarda tudo que pertence a um jogador. */` | Comentario sobre o registro do jogador. |
| 37 | `typedef struct` | Comeca a declaracao de um registro. |
| 38 | `{` | Abre um bloco de codigo. |
| 39 | `    int **campo;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 40 | `    int **visaoAdversario;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 41 | `    Navio *navios;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 42 | `    int totalNavios;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 43 | `    int naviosAfundados;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 44 | `} Jogador;` | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 45 | &nbsp; | Linha em branco para separar partes do codigo. |
| 46 | `/* Registro que guarda uma partida inteira. */` | Comentario sobre o registro da partida completa. |
| 47 | `typedef struct` | Comeca a declaracao de um registro. |
| 48 | `{` | Abre um bloco de codigo. |
| 49 | `    Configuracao config;` | Guarda a configuracao usada nesta partida. |
| 50 | `    Jogador humano;` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 51 | `    Jogador computador;` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 52 | `    int turno;                  /* 0 = humano, 1 = computador */` | Guarda de quem e o turno atual: humano ou computador. |
| 53 | `    int emAndamento;            /* 1 = jogo ativo, 0 = jogo parado */` | Indica se a partida ainda esta ativa. |
| 54 | `    int bombardeiosHumanoFeitos; /* disparos ja feitos no turno atual */` | Guarda quantos bombardeios o humano ja fez no turno atual, para o save nao devolver tres disparos extras. |
| 55 | `} Jogo;` | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |
| 56 | &nbsp; | Linha em branco para separar partes do codigo. |
| 57 | `/* Prototipos das funcoes. */` | Comentario indicando que vem a lista de prototipos das funcoes. |
| 58 | `int **criarMatriz(int tamanho);` | Declara a funcao que cria uma matriz. |
| 59 | `void liberarMatriz(int **matriz, int tamanho);` | Declara a funcao que libera uma matriz da memoria. |
| 60 | `void preencherMatriz(int **matriz, int tamanho, int valor);` | Declara a funcao que preenche uma matriz com um valor. |
| 61 | `void imprimirCampoProprio(int **campo, int tamanho);` | Declara a funcao que imprime o campo do proprio jogador. |
| 62 | `void imprimirCampoAdversario(int **campo, int tamanho);` | Declara a funcao que imprime o campo conhecido do adversario. |
| 63 | `void configuracaoPadrao(Configuracao *config);` | Declara a funcao que define a configuracao padrao. |
| 64 | `int salvarConfiguracao(Configuracao *config);` | Declara a funcao que salva a configuracao. |
| 65 | `int carregarConfiguracao(Configuracao *config);` | Declara a funcao que carrega a configuracao. |
| 66 | `int salvarJogo(Jogo *jogo);` | Declara a funcao que salva uma partida. |
| 67 | `int carregarJogo(Jogo *jogo);` | Declara a funcao que carrega uma partida. |
| 68 | `void inicializarJogo(Jogo *jogo, Configuracao config);` | Declara a funcao que inicia uma partida. |
| 69 | `void liberarJogo(Jogo *jogo);` | Declara a funcao que libera a memoria da partida. |
| 70 | `void executarPartida(Jogo *jogo);` | Declara a funcao que executa a partida. |
| 71 | `void configurarJogo(Configuracao *config);` | Declara a funcao que altera as configuracoes. |
| 72 | `int contarNaviosRestantes(Navio *navios, int total, int indice);` | Declara a funcao recursiva que conta navios restantes. |
| 73 | `int contarBombardeiosRealizados(int **visaoAdversario, int tamanho);` | Declara a funcao que conta quantas posicoes ja foram bombardeadas para recuperar o progresso do turno ao carregar. |
| 74 | &nbsp; | Linha em branco para separar partes do codigo. |
| 75 | `/* Limpa o restante da linha quando o usuario digita algo invalido. */` | Comentario dizendo que a funcao limpa entradas invalidas. |
| 76 | `void limparEntrada(void)` | Inicio da funcao `limparEntrada`. |
| 77 | `{` | Abre um bloco de codigo. |
| 78 | `    int c;` | Cria a variavel que recebe cada caractere digitado. |
| 79 | &nbsp; | Linha em branco para separar partes do codigo. |
| 80 | `    do` | Executa uma instrucao do programa. |
| 81 | `    {` | Abre ou fecha um bloco de codigo. |
| 82 | `        c = getchar();` | Le caracteres ate chegar no fim da linha ou no fim do arquivo. |
| 83 | `    } while (c != '\n' &amp;&amp; c != EOF);` | Le caracteres ate chegar no fim da linha ou no fim do arquivo. |
| 84 | `}` | Fecha um bloco de codigo. |
| 85 | &nbsp; | Linha em branco para separar partes do codigo. |
| 86 | `/* Le um numero inteiro do teclado. */` | Comentario dizendo que a funcao le um numero inteiro. |
| 87 | `int lerInteiro(char mensagem[])` | Inicio da funcao `lerInteiro`, recebendo uma mensagem para mostrar ao usuario. |
| 88 | `{` | Abre um bloco de codigo. |
| 89 | `    int valor;` | Declara uma variavel inteira. |
| 90 | &nbsp; | Linha em branco para separar partes do codigo. |
| 91 | `    printf("%s", mensagem);` | Mostra a mensagem na tela. |
| 92 | `    while (scanf("%d", &amp;valor) != 1)` | Tenta ler um inteiro; se nao conseguir, entra no laco. |
| 93 | `    {` | Abre ou fecha um bloco de codigo. |
| 94 | `        limparEntrada();` | Limpa o que foi digitado errado. |
| 95 | `        printf("Digite um numero inteiro: ");` | Pede novamente um numero inteiro. |
| 96 | `    }` | Fecha um bloco de codigo. |
| 97 | &nbsp; | Linha em branco para separar partes do codigo. |
| 98 | `    limparEntrada();` | Limpa o restante da linha depois da leitura correta. |
| 99 | `    return valor;` | Retorna um valor ou encerra a funcao. |
| 100 | `}` | Fecha um bloco de codigo. |
| 101 | &nbsp; | Linha em branco para separar partes do codigo. |
| 102 | `/* Pausa a tela ate o usuario confirmar que leu as mensagens. */` | Comentario dizendo que a funcao pausa a tela. |
| 103 | `void aguardarEnter(void)` | Inicio da funcao `aguardarEnter`. |
| 104 | `{` | Abre um bloco de codigo. |
| 105 | `    printf("Pressione ENTER para continuar...");` | Mostra a mensagem pedindo ENTER. |
| 106 | `    getchar();` | Espera o usuario apertar ENTER. |
| 107 | `}` | Fecha um bloco de codigo. |
| 108 | &nbsp; | Linha em branco para separar partes do codigo. |
| 109 | `/* Aloca uma matriz quadrada de inteiros usando ponteiros. */` | Comentario sobre alocar uma matriz quadrada. |
| 110 | `int **criarMatriz(int tamanho)` | Inicio da funcao `criarMatriz`. |
| 111 | `{` | Abre um bloco de codigo. |
| 112 | `    int i;` | Cria um contador para laco. |
| 113 | `    int **matriz = (int **)malloc(tamanho * sizeof(int *));` | Aloca o vetor de ponteiros, um para cada linha da matriz. |
| 114 | &nbsp; | Linha em branco para separar partes do codigo. |
| 115 | `    if (matriz == NULL)` | Verifica uma condicao para decidir o que fazer. |
| 116 | `    {` | Abre ou fecha um bloco de codigo. |
| 117 | `        return NULL;` | Se a alocacao falhar, retorna `NULL`. |
| 118 | `    }` | Fecha um bloco de codigo. |
| 119 | &nbsp; | Linha em branco para separar partes do codigo. |
| 120 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 121 | `    {` | Abre ou fecha um bloco de codigo. |
| 122 | `        matriz[i] = (int *)malloc(tamanho * sizeof(int));` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 123 | &nbsp; | Linha em branco para separar partes do codigo. |
| 124 | `        if (matriz[i] == NULL)` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 125 | `        {` | Abre ou fecha um bloco de codigo. |
| 126 | `            liberarMatriz(matriz, i);` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 127 | `            return NULL;` | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 128 | `        }` | Fecha um bloco de codigo. |
| 129 | `    }` | Fecha um bloco de codigo. |
| 130 | &nbsp; | Linha em branco para separar partes do codigo. |
| 131 | `    return matriz;` | Retorna a matriz criada. |
| 132 | `}` | Fecha um bloco de codigo. |
| 133 | &nbsp; | Linha em branco para separar partes do codigo. |
| 134 | `/* Libera a memoria da matriz linha por linha. */` | Comentario sobre liberar uma matriz. |
| 135 | `void liberarMatriz(int **matriz, int tamanho)` | Inicio da funcao `liberarMatriz`. |
| 136 | `{` | Abre um bloco de codigo. |
| 137 | `    int i;` | Cria um contador para laco. |
| 138 | &nbsp; | Linha em branco para separar partes do codigo. |
| 139 | `    if (matriz == NULL)` | Verifica uma condicao para decidir o que fazer. |
| 140 | `    {` | Abre ou fecha um bloco de codigo. |
| 141 | `        return;` | Retorna um valor ou encerra a funcao. |
| 142 | `    }` | Fecha um bloco de codigo. |
| 143 | &nbsp; | Linha em branco para separar partes do codigo. |
| 144 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 145 | `    {` | Abre ou fecha um bloco de codigo. |
| 146 | `        free(matriz[i]);` | Libera cada linha da matriz. |
| 147 | `    }` | Fecha um bloco de codigo. |
| 148 | &nbsp; | Linha em branco para separar partes do codigo. |
| 149 | `    free(matriz);` | Libera o vetor principal da matriz. |
| 150 | `}` | Fecha um bloco de codigo. |
| 151 | &nbsp; | Linha em branco para separar partes do codigo. |
| 152 | `/* Preenche todas as posicoes de uma matriz com o mesmo valor. */` | Comentario sobre preencher uma matriz. |
| 153 | `void preencherMatriz(int **matriz, int tamanho, int valor)` | Inicio da funcao `preencherMatriz`. |
| 154 | `{` | Abre um bloco de codigo. |
| 155 | `    int i;` | Cria um contador para laco. |
| 156 | `    int j;` | Cria um contador para laco. |
| 157 | &nbsp; | Linha em branco para separar partes do codigo. |
| 158 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 159 | `    {` | Abre ou fecha um bloco de codigo. |
| 160 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre todas as colunas da linha atual. |
| 161 | `        {` | Abre ou fecha um bloco de codigo. |
| 162 | `            matriz[i][j] = valor;` | Percorre todas as posicoes e coloca o valor informado. |
| 163 | `        }` | Fecha um bloco de codigo. |
| 164 | `    }` | Fecha um bloco de codigo. |
| 165 | `}` | Fecha um bloco de codigo. |
| 166 | &nbsp; | Linha em branco para separar partes do codigo. |
| 167 | `/* Imprime os indices das colunas e as linhas separadoras. */` | Comentario sobre imprimir cabecalho. |
| 168 | `void imprimirCabecalho(int tamanho)` | Inicio da funcao `imprimirCabecalho`. |
| 169 | `{` | Abre um bloco de codigo. |
| 170 | `    int j;` | Cria um contador para laco. |
| 171 | &nbsp; | Linha em branco para separar partes do codigo. |
| 172 | `    printf("     ");` | Mostra uma mensagem na tela. |
| 173 | `    for (j = 0; j &lt; tamanho; j++)` | Comeca um laco de repeticao. |
| 174 | `    {` | Abre ou fecha um bloco de codigo. |
| 175 | `        printf("%3d", j + 1);` | Mostra uma mensagem na tela. |
| 176 | `    }` | Fecha um bloco de codigo. |
| 177 | `    printf("\n");` | Mostra uma mensagem na tela. |
| 178 | &nbsp; | Linha em branco para separar partes do codigo. |
| 179 | `    printf("    +");` | Mostra uma mensagem na tela. |
| 180 | `    for (j = 0; j &lt; tamanho; j++)` | Comeca um laco de repeticao. |
| 181 | `    {` | Abre ou fecha um bloco de codigo. |
| 182 | `        printf("---");` | Mostra uma mensagem na tela. |
| 183 | `    }` | Fecha um bloco de codigo. |
| 184 | `    printf("\n");` | Mostra uma mensagem na tela. |
| 185 | `}` | Fecha um bloco de codigo. |
| 186 | &nbsp; | Linha em branco para separar partes do codigo. |
| 187 | `/* Imprime o campo do jogador humano, mostrando os seus navios. */` | Comentario sobre imprimir o campo do jogador. |
| 188 | `void imprimirCampoProprio(int **campo, int tamanho)` | Inicio da funcao `imprimirCampoProprio`. |
| 189 | `{` | Abre um bloco de codigo. |
| 190 | `    int i;` | Cria um contador para laco. |
| 191 | `    int j;` | Cria um contador para laco. |
| 192 | `    int valor;` | Declara uma variavel inteira. |
| 193 | &nbsp; | Linha em branco para separar partes do codigo. |
| 194 | `    imprimirCabecalho(tamanho);` | Executa uma instrucao do programa. |
| 195 | &nbsp; | Linha em branco para separar partes do codigo. |
| 196 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 197 | `    {` | Abre ou fecha um bloco de codigo. |
| 198 | `        printf("%3d &#124;", i + 1);` | Mostra uma mensagem na tela. |
| 199 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre todas as colunas da linha atual. |
| 200 | `        {` | Abre ou fecha um bloco de codigo. |
| 201 | `            valor = campo[i][j];` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 202 | &nbsp; | Linha em branco para separar partes do codigo. |
| 203 | `            if (valor == AGUA)` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 204 | `            {` | Abre ou fecha um bloco de codigo. |
| 205 | `                printf("%3d", AGUA);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 206 | `            }` | Fecha um bloco de codigo. |
| 207 | `            else if (valor == NAVIO_ACERTADO)` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 208 | `            {` | Abre ou fecha um bloco de codigo. |
| 209 | `                printf("%3d", NAVIO_ACERTADO);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 210 | `            }` | Fecha um bloco de codigo. |
| 211 | `            else if (valor &gt;= NAVIO_BASE)` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 212 | `            {` | Abre ou fecha um bloco de codigo. |
| 213 | `                printf("%3d", 1);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 214 | `            }` | Fecha um bloco de codigo. |
| 215 | `            else` | Caso contrario, executa o outro bloco. |
| 216 | `            {` | Abre ou fecha um bloco de codigo. |
| 217 | `                printf("%3d", valor);` | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 218 | `            }` | Fecha um bloco de codigo. |
| 219 | `        }` | Fecha um bloco de codigo. |
| 220 | `        printf("\n");` | Mostra uma mensagem na tela. |
| 221 | `    }` | Fecha um bloco de codigo. |
| 222 | `}` | Fecha um bloco de codigo. |
| 223 | &nbsp; | Linha em branco para separar partes do codigo. |
| 224 | `/* Imprime o que o jogador humano conhece do campo adversario. */` | Comentario sobre imprimir o campo adversario conhecido. |
| 225 | `void imprimirCampoAdversario(int **campo, int tamanho)` | Inicio da funcao `imprimirCampoAdversario`. |
| 226 | `{` | Abre um bloco de codigo. |
| 227 | `    int i;` | Cria um contador para laco. |
| 228 | `    int j;` | Cria um contador para laco. |
| 229 | &nbsp; | Linha em branco para separar partes do codigo. |
| 230 | `    imprimirCabecalho(tamanho);` | Executa uma instrucao do programa. |
| 231 | &nbsp; | Linha em branco para separar partes do codigo. |
| 232 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 233 | `    {` | Abre ou fecha um bloco de codigo. |
| 234 | `        printf("%3d &#124;", i + 1);` | Mostra uma mensagem na tela. |
| 235 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre todas as colunas da linha atual. |
| 236 | `        {` | Abre ou fecha um bloco de codigo. |
| 237 | `            printf("%3d", campo[i][j]);` | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 238 | `        }` | Fecha um bloco de codigo. |
| 239 | `        printf("\n");` | Mostra uma mensagem na tela. |
| 240 | `    }` | Fecha um bloco de codigo. |
| 241 | `}` | Fecha um bloco de codigo. |
| 242 | &nbsp; | Linha em branco para separar partes do codigo. |
| 243 | `/* Converte o valor interno do campo proprio para o numero que aparece na tela. */` | Comentario sobre converter valor interno em valor visivel. |
| 244 | `int valorVisivelCampoProprio(int valor)` | Inicio da funcao `valorVisivelCampoProprio`. |
| 245 | `{` | Abre um bloco de codigo. |
| 246 | `    if (valor == AGUA)` | Verifica uma condicao para decidir o que fazer. |
| 247 | `    {` | Abre ou fecha um bloco de codigo. |
| 248 | `        return AGUA;` | Se for agua, retorna `0`. |
| 249 | `    }` | Fecha um bloco de codigo. |
| 250 | &nbsp; | Linha em branco para separar partes do codigo. |
| 251 | `    if (valor == NAVIO_ACERTADO)` | Se for navio acertado, retorna `2`. |
| 252 | `    {` | Abre ou fecha um bloco de codigo. |
| 253 | `        return NAVIO_ACERTADO;` | Se for navio acertado, retorna `2`. |
| 254 | `    }` | Fecha um bloco de codigo. |
| 255 | &nbsp; | Linha em branco para separar partes do codigo. |
| 256 | `    if (valor &gt;= NAVIO_BASE)` | Verifica uma condicao para decidir o que fazer. |
| 257 | `    {` | Abre ou fecha um bloco de codigo. |
| 258 | `        return 1;` | Se for parte de navio ainda inteiro, mostra como `1`. |
| 259 | `    }` | Fecha um bloco de codigo. |
| 260 | &nbsp; | Linha em branco para separar partes do codigo. |
| 261 | `    return valor;` | Retorna um valor ou encerra a funcao. |
| 262 | `}` | Fecha um bloco de codigo. |
| 263 | &nbsp; | Linha em branco para separar partes do codigo. |
| 264 | `/* Imprime uma linha com os indices das colunas para dois campos juntos. */` | Comentario sobre cabecalho duplo. |
| 265 | `void imprimirCabecalhoDuplo(int tamanho)` | Inicio da funcao `imprimirCabecalhoDuplo`. |
| 266 | `{` | Abre um bloco de codigo. |
| 267 | `    int j;` | Cria um contador para laco. |
| 268 | &nbsp; | Linha em branco para separar partes do codigo. |
| 269 | `    printf("     ");` | Mostra uma mensagem na tela. |
| 270 | `    for (j = 0; j &lt; tamanho; j++)` | Comeca um laco de repeticao. |
| 271 | `    {` | Abre ou fecha um bloco de codigo. |
| 272 | `        printf("%3d", j + 1);` | Mostra uma mensagem na tela. |
| 273 | `    }` | Fecha um bloco de codigo. |
| 274 | &nbsp; | Linha em branco para separar partes do codigo. |
| 275 | `    printf(" &#124; ");` | Mostra uma mensagem na tela. |
| 276 | &nbsp; | Linha em branco para separar partes do codigo. |
| 277 | `    printf("     ");` | Mostra uma mensagem na tela. |
| 278 | `    for (j = 0; j &lt; tamanho; j++)` | Comeca um laco de repeticao. |
| 279 | `    {` | Abre ou fecha um bloco de codigo. |
| 280 | `        printf("%3d", j + 1);` | Mostra uma mensagem na tela. |
| 281 | `    }` | Fecha um bloco de codigo. |
| 282 | `    printf("\n");` | Mostra uma mensagem na tela. |
| 283 | &nbsp; | Linha em branco para separar partes do codigo. |
| 284 | `    printf("    +");` | Mostra uma mensagem na tela. |
| 285 | `    for (j = 0; j &lt; tamanho; j++)` | Comeca um laco de repeticao. |
| 286 | `    {` | Abre ou fecha um bloco de codigo. |
| 287 | `        printf("---");` | Mostra uma mensagem na tela. |
| 288 | `    }` | Fecha um bloco de codigo. |
| 289 | &nbsp; | Linha em branco para separar partes do codigo. |
| 290 | `    printf(" &#124; ");` | Mostra uma mensagem na tela. |
| 291 | &nbsp; | Linha em branco para separar partes do codigo. |
| 292 | `    printf("    +");` | Mostra uma mensagem na tela. |
| 293 | `    for (j = 0; j &lt; tamanho; j++)` | Comeca um laco de repeticao. |
| 294 | `    {` | Abre ou fecha um bloco de codigo. |
| 295 | `        printf("---");` | Mostra uma mensagem na tela. |
| 296 | `    }` | Fecha um bloco de codigo. |
| 297 | `    printf("\n");` | Mostra uma mensagem na tela. |
| 298 | `}` | Fecha um bloco de codigo. |
| 299 | &nbsp; | Linha em branco para separar partes do codigo. |
| 300 | `/* Imprime o campo do jogador e o campo conhecido do computador juntos. */` | Comentario sobre imprimir dois campos lado a lado. |
| 301 | `void imprimirCamposLadoALado(int **campoHumano, int **campoComputador, int tamanho)` | Inicio da funcao `imprimirCamposLadoALado`. |
| 302 | `{` | Abre um bloco de codigo. |
| 303 | `    int i;` | Cria um contador para laco. |
| 304 | `    int j;` | Cria um contador para laco. |
| 305 | `    int valor;` | Declara uma variavel inteira. |
| 306 | &nbsp; | Linha em branco para separar partes do codigo. |
| 307 | `    imprimirCabecalhoDuplo(tamanho);` | Imprime o cabecalho duplo. |
| 308 | &nbsp; | Linha em branco para separar partes do codigo. |
| 309 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 310 | `    {` | Abre ou fecha um bloco de codigo. |
| 311 | `        printf("%3d &#124;", i + 1);` | Mostra uma mensagem na tela. |
| 312 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre todas as colunas da linha atual. |
| 313 | `        {` | Abre ou fecha um bloco de codigo. |
| 314 | `            valor = valorVisivelCampoProprio(campoHumano[i][j]);` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 315 | `            printf("%3d", valor);` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 316 | `        }` | Fecha um bloco de codigo. |
| 317 | &nbsp; | Linha em branco para separar partes do codigo. |
| 318 | `        printf(" &#124; ");` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 319 | &nbsp; | Linha em branco para separar partes do codigo. |
| 320 | `        printf("%3d &#124;", i + 1);` | Mostra uma mensagem na tela. |
| 321 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre todas as colunas da linha atual. |
| 322 | `        {` | Abre ou fecha um bloco de codigo. |
| 323 | `            printf("%3d", campoComputador[i][j]);` | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 324 | `        }` | Fecha um bloco de codigo. |
| 325 | &nbsp; | Linha em branco para separar partes do codigo. |
| 326 | `        printf("\n");` | Mostra uma mensagem na tela. |
| 327 | `    }` | Fecha um bloco de codigo. |
| 328 | `}` | Fecha um bloco de codigo. |
| 329 | &nbsp; | Linha em branco para separar partes do codigo. |
| 330 | `/* Define a configuracao minima caso nao exista arquivo salvo. */` | Comentario sobre configuracao padrao. |
| 331 | `void configuracaoPadrao(Configuracao *config)` | Inicio da funcao `configuracaoPadrao`. |
| 332 | `{` | Abre um bloco de codigo. |
| 333 | `    config-&gt;tamanho = TAMANHO_MINIMO;` | Define o tamanho minimo do campo. |
| 334 | `    config-&gt;quantidadeNavios = NAVIOS_MINIMOS;` | Define a quantidade minima de navios. |
| 335 | `}` | Fecha um bloco de codigo. |
| 336 | &nbsp; | Linha em branco para separar partes do codigo. |
| 337 | `/* Salva somente a configuracao em arquivo binario. */` | Comentario sobre salvar configuracao. |
| 338 | `int salvarConfiguracao(Configuracao *config)` | Inicio da funcao `salvarConfiguracao`. |
| 339 | `{` | Abre um bloco de codigo. |
| 340 | `    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");` | Declara ou inicia uma funcao ou variavel usada no programa. |
| 341 | `    int temJogo = 0;` | Define que nao existe partida salva, apenas configuracao. |
| 342 | &nbsp; | Linha em branco para separar partes do codigo. |
| 343 | `    if (arquivo == NULL)` | Verifica uma condicao para decidir o que fazer. |
| 344 | `    {` | Abre ou fecha um bloco de codigo. |
| 345 | `        return 0;` | Retorna um valor ou encerra a funcao. |
| 346 | `    }` | Fecha um bloco de codigo. |
| 347 | &nbsp; | Linha em branco para separar partes do codigo. |
| 348 | `    fwrite(config, sizeof(Configuracao), 1, arquivo);` | Grava a configuracao no arquivo. |
| 349 | `    fwrite(&amp;temJogo, sizeof(int), 1, arquivo);` | Grava dados no arquivo binario. |
| 350 | &nbsp; | Linha em branco para separar partes do codigo. |
| 351 | `    fclose(arquivo);` | Executa uma instrucao do programa. |
| 352 | `    return 1;` | Retorna um valor ou encerra a funcao. |
| 353 | `}` | Fecha um bloco de codigo. |
| 354 | &nbsp; | Linha em branco para separar partes do codigo. |
| 355 | `/* Carrega a configuracao do arquivo binario. */` | Comentario sobre carregar configuracao. |
| 356 | `int carregarConfiguracao(Configuracao *config)` | Inicio da funcao `carregarConfiguracao`. |
| 357 | `{` | Abre um bloco de codigo. |
| 358 | `    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");` | Declara ou inicia uma funcao ou variavel usada no programa. |
| 359 | &nbsp; | Linha em branco para separar partes do codigo. |
| 360 | `    if (arquivo == NULL)` | Verifica uma condicao para decidir o que fazer. |
| 361 | `    {` | Abre ou fecha um bloco de codigo. |
| 362 | `        configuracaoPadrao(config);` | Se o arquivo nao existir, usa a configuracao padrao e retorna erro. |
| 363 | `        return 0;` | Retorna um valor ou encerra a funcao. |
| 364 | `    }` | Fecha um bloco de codigo. |
| 365 | &nbsp; | Linha em branco para separar partes do codigo. |
| 366 | `    fread(config, sizeof(Configuracao), 1, arquivo);` | Le a configuracao do arquivo. |
| 367 | `    fclose(arquivo);` | Executa uma instrucao do programa. |
| 368 | `    return 1;` | Retorna um valor ou encerra a funcao. |
| 369 | `}` | Fecha um bloco de codigo. |
| 370 | &nbsp; | Linha em branco para separar partes do codigo. |
| 371 | `/* Escreve uma matriz no arquivo binario, linha por linha. */` | Comentario sobre escrever matriz no arquivo. |
| 372 | `void escreverMatriz(FILE *arquivo, int **matriz, int tamanho)` | Inicio da funcao `escreverMatriz`. |
| 373 | `{` | Abre um bloco de codigo. |
| 374 | `    int i;` | Cria um contador para laco. |
| 375 | &nbsp; | Linha em branco para separar partes do codigo. |
| 376 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 377 | `    {` | Abre ou fecha um bloco de codigo. |
| 378 | `        fwrite(matriz[i], sizeof(int), tamanho, arquivo);` | Grava cada linha da matriz no arquivo. |
| 379 | `    }` | Fecha um bloco de codigo. |
| 380 | `}` | Fecha um bloco de codigo. |
| 381 | &nbsp; | Linha em branco para separar partes do codigo. |
| 382 | `/* Le uma matriz do arquivo binario, linha por linha. */` | Comentario sobre ler matriz do arquivo. |
| 383 | `void lerMatriz(FILE *arquivo, int **matriz, int tamanho)` | Inicio da funcao `lerMatriz`. |
| 384 | `{` | Abre um bloco de codigo. |
| 385 | `    int i;` | Cria um contador para laco. |
| 386 | &nbsp; | Linha em branco para separar partes do codigo. |
| 387 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 388 | `    {` | Abre ou fecha um bloco de codigo. |
| 389 | `        fread(matriz[i], sizeof(int), tamanho, arquivo);` | Le cada linha da matriz do arquivo. |
| 390 | `    }` | Fecha um bloco de codigo. |
| 391 | `}` | Fecha um bloco de codigo. |
| 392 | &nbsp; | Linha em branco para separar partes do codigo. |
| 393 | `/* Salva uma partida completa em arquivo binario. */` | Comentario sobre salvar partida completa. |
| 394 | `int salvarJogo(Jogo *jogo)` | Inicio da funcao `salvarJogo`. |
| 395 | `{` | Abre um bloco de codigo. |
| 396 | `    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");` | Declara ou inicia uma funcao ou variavel usada no programa. |
| 397 | `    int temJogo = 1;` | Marca que existe jogo salvo. |
| 398 | `    int tamanho = jogo-&gt;config.tamanho;` | Declara uma variavel inteira. |
| 399 | &nbsp; | Linha em branco para separar partes do codigo. |
| 400 | `    if (arquivo == NULL)` | Verifica uma condicao para decidir o que fazer. |
| 401 | `    {` | Abre ou fecha um bloco de codigo. |
| 402 | `        return 0;` | Retorna um valor ou encerra a funcao. |
| 403 | `    }` | Fecha um bloco de codigo. |
| 404 | &nbsp; | Linha em branco para separar partes do codigo. |
| 405 | `    fwrite(&amp;jogo-&gt;config, sizeof(Configuracao), 1, arquivo);` | Salva configuracao, existencia do jogo, turno e estado da partida. |
| 406 | `    fwrite(&amp;temJogo, sizeof(int), 1, arquivo);` | Grava dados no arquivo binario. |
| 407 | `    fwrite(&amp;jogo-&gt;turno, sizeof(int), 1, arquivo);` | Salva configuracao, existencia do jogo, turno e estado da partida. |
| 408 | `    fwrite(&amp;jogo-&gt;emAndamento, sizeof(int), 1, arquivo);` | Salva configuracao, existencia do jogo, turno e estado da partida. |
| 409 | &nbsp; | Linha em branco para separar partes do codigo. |
| 410 | `    fwrite(&amp;jogo-&gt;humano.totalNavios, sizeof(int), 1, arquivo);` | Salva dados, navios e matrizes do jogador humano. |
| 411 | `    fwrite(&amp;jogo-&gt;humano.naviosAfundados, sizeof(int), 1, arquivo);` | Salva dados, navios e matrizes do jogador humano. |
| 412 | `    fwrite(jogo-&gt;humano.navios, sizeof(Navio), jogo-&gt;humano.totalNavios, arquivo);` | Salva dados, navios e matrizes do jogador humano. |
| 413 | `    escreverMatriz(arquivo, jogo-&gt;humano.campo, tamanho);` | Salva dados, navios e matrizes do jogador humano. |
| 414 | `    escreverMatriz(arquivo, jogo-&gt;humano.visaoAdversario, tamanho);` | Salva dados, navios e matrizes do jogador humano. |
| 415 | &nbsp; | Linha em branco para separar partes do codigo. |
| 416 | `    fwrite(&amp;jogo-&gt;computador.totalNavios, sizeof(int), 1, arquivo);` | Salva dados, navios e matrizes do computador. |
| 417 | `    fwrite(&amp;jogo-&gt;computador.naviosAfundados, sizeof(int), 1, arquivo);` | Salva dados, navios e matrizes do computador. |
| 418 | `    fwrite(jogo-&gt;computador.navios, sizeof(Navio), jogo-&gt;computador.totalNavios, arquivo);` | Salva dados, navios e matrizes do computador. |
| 419 | `    escreverMatriz(arquivo, jogo-&gt;computador.campo, tamanho);` | Salva dados, navios e matrizes do computador. |
| 420 | `    escreverMatriz(arquivo, jogo-&gt;computador.visaoAdversario, tamanho);` | Salva dados, navios e matrizes do computador. |
| 421 | &nbsp; | Linha em branco para separar partes do codigo. |
| 422 | `    fclose(arquivo);` | Executa uma instrucao do programa. |
| 423 | `    return 1;` | Retorna um valor ou encerra a funcao. |
| 424 | `}` | Fecha um bloco de codigo. |
| 425 | &nbsp; | Linha em branco para separar partes do codigo. |
| 426 | `/* Carrega uma partida completa do arquivo binario. */` | Comentario sobre carregar partida completa. |
| 427 | `int carregarJogo(Jogo *jogo)` | Inicio da funcao `carregarJogo`. |
| 428 | `{` | Abre um bloco de codigo. |
| 429 | `    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");` | Declara ou inicia uma funcao ou variavel usada no programa. |
| 430 | `    int temJogo;` | Cria variavel que indica se existe jogo salvo. |
| 431 | `    int tamanho;` | Declara uma variavel inteira. |
| 432 | &nbsp; | Linha em branco para separar partes do codigo. |
| 433 | `    if (arquivo == NULL)` | Verifica uma condicao para decidir o que fazer. |
| 434 | `    {` | Abre ou fecha um bloco de codigo. |
| 435 | `        return 0;` | Retorna um valor ou encerra a funcao. |
| 436 | `    }` | Fecha um bloco de codigo. |
| 437 | &nbsp; | Linha em branco para separar partes do codigo. |
| 438 | `    fread(&amp;jogo-&gt;config, sizeof(Configuracao), 1, arquivo);` | Le configuracao e indicador de jogo salvo. |
| 439 | `    fread(&amp;temJogo, sizeof(int), 1, arquivo);` | Le configuracao e indicador de jogo salvo. |
| 440 | &nbsp; | Linha em branco para separar partes do codigo. |
| 441 | `    if (temJogo == 0)` | Se nao houver jogo salvo, fecha o arquivo e retorna erro. |
| 442 | `    {` | Abre ou fecha um bloco de codigo. |
| 443 | `        fclose(arquivo);` | Se nao houver jogo salvo, fecha o arquivo e retorna erro. |
| 444 | `        return 0;` | Retorna um valor ou encerra a funcao. |
| 445 | `    }` | Fecha um bloco de codigo. |
| 446 | &nbsp; | Linha em branco para separar partes do codigo. |
| 447 | `    tamanho = jogo-&gt;config.tamanho;` | Copia o tamanho da configuracao. |
| 448 | &nbsp; | Linha em branco para separar partes do codigo. |
| 449 | `    fread(&amp;jogo-&gt;turno, sizeof(int), 1, arquivo);` | Le turno e estado da partida. |
| 450 | `    fread(&amp;jogo-&gt;emAndamento, sizeof(int), 1, arquivo);` | Le turno e estado da partida. |
| 451 | &nbsp; | Linha em branco para separar partes do codigo. |
| 452 | `    fread(&amp;jogo-&gt;humano.totalNavios, sizeof(int), 1, arquivo);` | Le dados do jogador humano e recria suas matrizes. |
| 453 | `    fread(&amp;jogo-&gt;humano.naviosAfundados, sizeof(int), 1, arquivo);` | Le dados do jogador humano e recria suas matrizes. |
| 454 | `    jogo-&gt;humano.navios = (Navio *)malloc(jogo-&gt;humano.totalNavios * sizeof(Navio));` | Le dados do jogador humano e recria suas matrizes. |
| 455 | `    jogo-&gt;humano.campo = criarMatriz(tamanho);` | Le dados do jogador humano e recria suas matrizes. |
| 456 | `    jogo-&gt;humano.visaoAdversario = criarMatriz(tamanho);` | Le dados do jogador humano e recria suas matrizes. |
| 457 | `    fread(jogo-&gt;humano.navios, sizeof(Navio), jogo-&gt;humano.totalNavios, arquivo);` | Le dados do jogador humano e recria suas matrizes. |
| 458 | `    lerMatriz(arquivo, jogo-&gt;humano.campo, tamanho);` | Le dados do jogador humano e recria suas matrizes. |
| 459 | `    lerMatriz(arquivo, jogo-&gt;humano.visaoAdversario, tamanho);` | Le dados do jogador humano e recria suas matrizes. |
| 460 | &nbsp; | Linha em branco para separar partes do codigo. |
| 461 | `    fread(&amp;jogo-&gt;computador.totalNavios, sizeof(int), 1, arquivo);` | Le dados do computador e recria suas matrizes. |
| 462 | `    fread(&amp;jogo-&gt;computador.naviosAfundados, sizeof(int), 1, arquivo);` | Le dados do computador e recria suas matrizes. |
| 463 | `    jogo-&gt;computador.navios = (Navio *)malloc(jogo-&gt;computador.totalNavios * sizeof(Navio));` | Le dados do computador e recria suas matrizes. |
| 464 | `    jogo-&gt;computador.campo = criarMatriz(tamanho);` | Le dados do computador e recria suas matrizes. |
| 465 | `    jogo-&gt;computador.visaoAdversario = criarMatriz(tamanho);` | Le dados do computador e recria suas matrizes. |
| 466 | `    fread(jogo-&gt;computador.navios, sizeof(Navio), jogo-&gt;computador.totalNavios, arquivo);` | Le dados do computador e recria suas matrizes. |
| 467 | `    lerMatriz(arquivo, jogo-&gt;computador.campo, tamanho);` | Le dados do computador e recria suas matrizes. |
| 468 | `    lerMatriz(arquivo, jogo-&gt;computador.visaoAdversario, tamanho);` | Le dados do computador e recria suas matrizes. |
| 469 | &nbsp; | Linha em branco para separar partes do codigo. |
| 470 | `    if (jogo-&gt;turno == 0)` | Verifica se o jogo salvo estava no turno do humano. |
| 471 | `    {` | Abre ou fecha um bloco de codigo. |
| 472 | `        jogo-&gt;bombardeiosHumanoFeitos = contarBombardeiosRealizados(jogo-&gt;humano.visaoAdversario, tamanho) % 3;` | Ao carregar no turno humano, recupera quantos disparos desse turno ja foram feitos. |
| 473 | `    }` | Fecha um bloco de codigo. |
| 474 | `    else` | Caso contrario, executa o outro bloco. |
| 475 | `    {` | Abre ou fecha um bloco de codigo. |
| 476 | `        jogo-&gt;bombardeiosHumanoFeitos = 0;` | Zera o contador de bombardeios do turno humano. |
| 477 | `    }` | Fecha um bloco de codigo. |
| 478 | &nbsp; | Linha em branco para separar partes do codigo. |
| 479 | `    fclose(arquivo);` | Executa uma instrucao do programa. |
| 480 | `    return 1;` | Retorna um valor ou encerra a funcao. |
| 481 | `}` | Fecha um bloco de codigo. |
| 482 | &nbsp; | Linha em branco para separar partes do codigo. |
| 483 | `/* Verifica se duas posicoes estao livres para colocar um navio. */` | Comentario sobre verificar posicoes livres. |
| 484 | `int posicaoLivre(int **campo, int linha1, int coluna1, int linha2, int coluna2)` | Inicio da funcao `posicaoLivre`. |
| 485 | `{` | Abre um bloco de codigo. |
| 486 | `    return campo[linha1][coluna1] == AGUA &amp;&amp; campo[linha2][coluna2] == AGUA;` | Retorna verdadeiro se as duas posicoes estiverem com agua. |
| 487 | `}` | Fecha um bloco de codigo. |
| 488 | &nbsp; | Linha em branco para separar partes do codigo. |
| 489 | `/* Sorteia todos os navios de um jogador sem deixar sobrepor. */` | Comentario sobre sortear navios. |
| 490 | `void posicionarNavios(Jogador *jogador, int tamanho)` | Inicio da funcao `posicionarNavios`. |
| 491 | `{` | Abre um bloco de codigo. |
| 492 | `    int i;` | Cria um contador para laco. |
| 493 | `    int linha;` | Cria variavel para guardar uma linha do campo. |
| 494 | `    int coluna;` | Cria variavel para guardar uma coluna do campo. |
| 495 | `    int direcao;` | Cria variaveis usadas para sortear posicoes e direcao. |
| 496 | `    int linha2;` | Declara uma variavel inteira. |
| 497 | `    int coluna2;` | Declara uma variavel inteira. |
| 498 | &nbsp; | Linha em branco para separar partes do codigo. |
| 499 | `    for (i = 0; i &lt; jogador-&gt;totalNavios; i++)` | Comeca um laco para posicionar todos os navios. |
| 500 | `    {` | Abre ou fecha um bloco de codigo. |
| 501 | `        do` | Executa uma instrucao do programa. |
| 502 | `        {` | Abre ou fecha um bloco de codigo. |
| 503 | `            linha = rand() % tamanho;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 504 | `            coluna = rand() % tamanho;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 505 | `            direcao = rand() % 2;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 506 | `            linha2 = linha;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 507 | `            coluna2 = coluna;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 508 | &nbsp; | Linha em branco para separar partes do codigo. |
| 509 | `            if (direcao == 0)` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 510 | `            {` | Abre ou fecha um bloco de codigo. |
| 511 | `                coluna2 = coluna + 1;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 512 | `            }` | Fecha um bloco de codigo. |
| 513 | `            else` | Caso contrario, executa o outro bloco. |
| 514 | `            {` | Abre ou fecha um bloco de codigo. |
| 515 | `                linha2 = linha + 1;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 516 | `            }` | Fecha um bloco de codigo. |
| 517 | `        } while (linha2 &gt;= tamanho &#124;&#124; coluna2 &gt;= tamanho &#124;&#124;` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 518 | `                 !posicaoLivre(jogador-&gt;campo, linha, coluna, linha2, coluna2));` | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 519 | &nbsp; | Linha em branco para separar partes do codigo. |
| 520 | `        jogador-&gt;navios[i].linha1 = linha;` | Guarda as coordenadas e zera os acertos do navio. |
| 521 | `        jogador-&gt;navios[i].coluna1 = coluna;` | Guarda as coordenadas e zera os acertos do navio. |
| 522 | `        jogador-&gt;navios[i].linha2 = linha2;` | Guarda as coordenadas e zera os acertos do navio. |
| 523 | `        jogador-&gt;navios[i].coluna2 = coluna2;` | Guarda as coordenadas e zera os acertos do navio. |
| 524 | `        jogador-&gt;navios[i].acertos = 0;` | Guarda as coordenadas e zera os acertos do navio. |
| 525 | &nbsp; | Linha em branco para separar partes do codigo. |
| 526 | `        jogador-&gt;campo[linha][coluna] = NAVIO_BASE + i;` | Marca as duas partes do navio no campo. |
| 527 | `        jogador-&gt;campo[linha2][coluna2] = NAVIO_BASE + i;` | Marca as duas partes do navio no campo. |
| 528 | `    }` | Fecha um bloco de codigo. |
| 529 | `}` | Fecha um bloco de codigo. |
| 530 | &nbsp; | Linha em branco para separar partes do codigo. |
| 531 | `/* Aloca e prepara as estruturas de um jogador. */` | Comentario sobre inicializar jogador. |
| 532 | `void inicializarJogador(Jogador *jogador, int tamanho, int totalNavios)` | Inicio da funcao `inicializarJogador`. |
| 533 | `{` | Abre um bloco de codigo. |
| 534 | `    jogador-&gt;campo = criarMatriz(tamanho);` | Cria a matriz do campo do jogador. |
| 535 | `    jogador-&gt;visaoAdversario = criarMatriz(tamanho);` | Cria a matriz da visao do adversario. |
| 536 | `    jogador-&gt;navios = (Navio *)malloc(totalNavios * sizeof(Navio));` | Aloca o vetor de navios. |
| 537 | `    jogador-&gt;totalNavios = totalNavios;` | Guarda a quantidade total de navios. |
| 538 | `    jogador-&gt;naviosAfundados = 0;` | Zera a quantidade de navios afundados. |
| 539 | &nbsp; | Linha em branco para separar partes do codigo. |
| 540 | `    preencherMatriz(jogador-&gt;campo, tamanho, AGUA);` | Preenche o campo com agua. |
| 541 | `    preencherMatriz(jogador-&gt;visaoAdversario, tamanho, DESCONHECIDO);` | Preenche a visao do adversario com posicoes desconhecidas. |
| 542 | `    posicionarNavios(jogador, tamanho);` | Sorteia e posiciona os navios. |
| 543 | `}` | Fecha um bloco de codigo. |
| 544 | &nbsp; | Linha em branco para separar partes do codigo. |
| 545 | `/* Libera a memoria usada por um jogador. */` | Comentario sobre liberar memoria do jogador. |
| 546 | `void liberarJogador(Jogador *jogador, int tamanho)` | Inicio da funcao `liberarJogador`. |
| 547 | `{` | Abre um bloco de codigo. |
| 548 | `    liberarMatriz(jogador-&gt;campo, tamanho);` | Libera a matriz do campo. |
| 549 | `    liberarMatriz(jogador-&gt;visaoAdversario, tamanho);` | Libera a matriz da visao do adversario. |
| 550 | `    free(jogador-&gt;navios);` | Libera o vetor de navios. |
| 551 | &nbsp; | Linha em branco para separar partes do codigo. |
| 552 | `    jogador-&gt;campo = NULL;` | Coloca os ponteiros como `NULL` para evitar uso indevido. |
| 553 | `    jogador-&gt;visaoAdversario = NULL;` | Coloca os ponteiros como `NULL` para evitar uso indevido. |
| 554 | `    jogador-&gt;navios = NULL;` | Coloca os ponteiros como `NULL` para evitar uso indevido. |
| 555 | `}` | Fecha um bloco de codigo. |
| 556 | &nbsp; | Linha em branco para separar partes do codigo. |
| 557 | `/* Cria uma nova partida. */` | Comentario sobre criar nova partida. |
| 558 | `void inicializarJogo(Jogo *jogo, Configuracao config)` | Inicio da funcao `inicializarJogo`. |
| 559 | `{` | Abre um bloco de codigo. |
| 560 | `    jogo-&gt;config = config;` | Copia a configuracao para o jogo. |
| 561 | `    jogo-&gt;turno = 0;` | Atualiza ou calcula um valor usado pelo programa. |
| 562 | `    jogo-&gt;emAndamento = 1;` | Marca o jogo como em andamento. |
| 563 | `    jogo-&gt;bombardeiosHumanoFeitos = 0;` | Zera o contador de bombardeios do turno humano. |
| 564 | &nbsp; | Linha em branco para separar partes do codigo. |
| 565 | `    inicializarJogador(&amp;jogo-&gt;humano, config.tamanho, config.quantidadeNavios);` | Inicializa o jogador humano. |
| 566 | `    inicializarJogador(&amp;jogo-&gt;computador, config.tamanho, config.quantidadeNavios);` | Inicializa o computador. |
| 567 | `}` | Fecha um bloco de codigo. |
| 568 | &nbsp; | Linha em branco para separar partes do codigo. |
| 569 | `/* Libera a memoria usada pela partida. */` | Comentario sobre liberar memoria do jogo. |
| 570 | `void liberarJogo(Jogo *jogo)` | Inicio da funcao `liberarJogo`. |
| 571 | `{` | Abre um bloco de codigo. |
| 572 | `    int tamanho = jogo-&gt;config.tamanho;` | Declara uma variavel inteira. |
| 573 | &nbsp; | Linha em branco para separar partes do codigo. |
| 574 | `    liberarJogador(&amp;jogo-&gt;humano, tamanho);` | Libera os dados do humano. |
| 575 | `    liberarJogador(&amp;jogo-&gt;computador, tamanho);` | Libera os dados do computador. |
| 576 | `}` | Fecha um bloco de codigo. |
| 577 | &nbsp; | Linha em branco para separar partes do codigo. |
| 578 | `/* Funcao recursiva: conta navios que ainda nao foram afundados. */` | Comentario indicando que a funcao usa recursao. |
| 579 | `int contarNaviosRestantes(Navio *navios, int total, int indice)` | Inicio da funcao `contarNaviosRestantes`. |
| 580 | `{` | Abre um bloco de codigo. |
| 581 | `    if (indice == total)` | Caso base: se chegou ao final do vetor, retorna zero. |
| 582 | `    {` | Abre ou fecha um bloco de codigo. |
| 583 | `        return 0;` | Retorna um valor ou encerra a funcao. |
| 584 | `    }` | Fecha um bloco de codigo. |
| 585 | &nbsp; | Linha em branco para separar partes do codigo. |
| 586 | `    if (navios[indice].acertos &lt; 2)` | Se o navio atual ainda nao afundou, conta ele e chama a funcao de novo. |
| 587 | `    {` | Abre ou fecha um bloco de codigo. |
| 588 | `        return 1 + contarNaviosRestantes(navios, total, indice + 1);` | Se o navio atual ainda nao afundou, conta ele e chama a funcao de novo. |
| 589 | `    }` | Fecha um bloco de codigo. |
| 590 | &nbsp; | Linha em branco para separar partes do codigo. |
| 591 | `    return contarNaviosRestantes(navios, total, indice + 1);` | Se o navio ja afundou, apenas continua a contagem. |
| 592 | `}` | Fecha um bloco de codigo. |
| 593 | &nbsp; | Linha em branco para separar partes do codigo. |
| 594 | `/* Conta quantas posicoes o jogador ja bombardeou no campo adversario. */` | Comentario sobre contar bombardeios ja realizados. |
| 595 | `int contarBombardeiosRealizados(int **visaoAdversario, int tamanho)` | Inicio da funcao `contarBombardeiosRealizados`. |
| 596 | `{` | Abre um bloco de codigo. |
| 597 | `    int i;` | Cria um contador para laco. |
| 598 | `    int j;` | Cria um contador para laco. |
| 599 | `    int total = 0;` | Cria o contador total e comeca em zero. |
| 600 | &nbsp; | Linha em branco para separar partes do codigo. |
| 601 | `    for (i = 0; i &lt; tamanho; i++)` | Percorre todas as linhas do campo. |
| 602 | `    {` | Abre ou fecha um bloco de codigo. |
| 603 | `        for (j = 0; j &lt; tamanho; j++)` | Percorre todas as colunas da linha atual. |
| 604 | `        {` | Abre ou fecha um bloco de codigo. |
| 605 | `            if (visaoAdversario[i][j] != DESCONHECIDO)` | Verifica se aquela posicao ja deixou de ser desconhecida. |
| 606 | `            {` | Abre ou fecha um bloco de codigo. |
| 607 | `                total++;` | Soma uma posicao ja bombardeada. |
| 608 | `            }` | Fecha um bloco de codigo. |
| 609 | `        }` | Fecha um bloco de codigo. |
| 610 | `    }` | Fecha um bloco de codigo. |
| 611 | &nbsp; | Linha em branco para separar partes do codigo. |
| 612 | `    return total;` | Retorna o total encontrado. |
| 613 | `}` | Fecha um bloco de codigo. |
| 614 | &nbsp; | Linha em branco para separar partes do codigo. |
| 615 | `/* Mostra o significado dos numeros do tabuleiro. */` | Comentario sobre mostrar legenda. |
| 616 | `void mostrarLegenda(void)` | Inicio da funcao `mostrarLegenda`. |
| 617 | `{` | Abre um bloco de codigo. |
| 618 | `    printf("\n===== LEGENDA =====\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 619 | `    printf("0 = Agua no seu campo\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 620 | `    printf("1 = Seu navio\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 621 | `    printf("2 = Parte do seu navio acertada\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 622 | `    printf("3 = Agua encontrada no campo adversario\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 623 | `    printf("4 = Impacto em navio adversario\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 624 | `    printf("5 = Navio adversario afundado\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 625 | `    printf("7 = Posicao desconhecida no campo adversario\n");` | Imprime o significado de cada numero usado no tabuleiro. |
| 626 | `}` | Fecha um bloco de codigo. |
| 627 | &nbsp; | Linha em branco para separar partes do codigo. |
| 628 | `/* Limpa a tela usando sequencia ANSI, sem depender do comando clear/cls. */` | Comentario sobre limpar a tela. |
| 629 | `void limparTela(void)` | Inicio da funcao `limparTela`. |
| 630 | `{` | Abre um bloco de codigo. |
| 631 | `    printf("\033[2J\033[H");` | Imprime codigos ANSI para limpar a tela e voltar ao topo. |
| 632 | `    fflush(stdout);` | Forca a saida aparecer imediatamente. |
| 633 | `}` | Fecha um bloco de codigo. |
| 634 | &nbsp; | Linha em branco para separar partes do codigo. |
| 635 | `/* Mostra o campo do jogador e o campo conhecido do computador. */` | Comentario sobre mostrar os campos. |
| 636 | `void mostrarCampos(Jogo *jogo)` | Inicio da funcao `mostrarCampos`. |
| 637 | `{` | Abre um bloco de codigo. |
| 638 | `    int restantesHumano;` | Cria variaveis para contadores, largura e textos. |
| 639 | `    int restantesComputador;` | Cria variaveis para contadores, largura e textos. |
| 640 | `    int larguraCampo = 5 + jogo-&gt;config.tamanho * 3;` | Cria variaveis para contadores, largura e textos. |
| 641 | `    char textoHumano[80];` | Cria variaveis para contadores, largura e textos. |
| 642 | `    char textoComputador[80];` | Cria variaveis para contadores, largura e textos. |
| 643 | &nbsp; | Linha em branco para separar partes do codigo. |
| 644 | `    restantesHumano = contarNaviosRestantes(jogo-&gt;humano.navios, jogo-&gt;humano.totalNavios, 0);` | Conta os navios restantes do humano. |
| 645 | `    restantesComputador = contarNaviosRestantes(jogo-&gt;computador.navios, jogo-&gt;computador.totalNavios, 0);` | Conta os navios restantes do computador. |
| 646 | `    sprintf(textoHumano, "Seus navios restantes: %d", restantesHumano);` | Monta o texto de navios restantes do humano. |
| 647 | `    sprintf(textoComputador, "Navios restantes do computador: %d", restantesComputador);` | Monta o texto de navios restantes do computador. |
| 648 | &nbsp; | Linha em branco para separar partes do codigo. |
| 649 | `    printf("\n%-*s &#124; %s\n", larguraCampo, "===== SEU CAMPO =====",` | Imprime os titulos dos dois campos. |
| 650 | `           "===== CAMPO DO COMPUTADOR CONHECIDO =====");` | Imprime os titulos dos dois campos. |
| 651 | `    printf("%-*s &#124; %s\n", larguraCampo, textoHumano, textoComputador);` | Imprime os titulos dos dois campos. |
| 652 | &nbsp; | Linha em branco para separar partes do codigo. |
| 653 | `    imprimirCamposLadoALado(jogo-&gt;humano.campo,` | Imprime os campos lado a lado. |
| 654 | `                            jogo-&gt;humano.visaoAdversario,` | Imprime os campos lado a lado. |
| 655 | `                            jogo-&gt;config.tamanho);` | Imprime os campos lado a lado. |
| 656 | &nbsp; | Linha em branco para separar partes do codigo. |
| 657 | `    mostrarLegenda();` | Mostra a legenda. |
| 658 | `    printf("\n");` | Mostra uma mensagem na tela. |
| 659 | `}` | Fecha um bloco de codigo. |
| 660 | &nbsp; | Linha em branco para separar partes do codigo. |
| 661 | `/* Procura o indice do navio que esta em uma posicao. */` | Comentario sobre procurar navio por posicao. |
| 662 | `int indiceNavioPorPosicao(Navio *navios, int total, int linha, int coluna)` | Inicio da funcao `indiceNavioPorPosicao`. |
| 663 | `{` | Abre um bloco de codigo. |
| 664 | `    int i;` | Cria um contador para laco. |
| 665 | &nbsp; | Linha em branco para separar partes do codigo. |
| 666 | `    for (i = 0; i &lt; total; i++)` | Procura qual navio ocupa a linha e coluna informadas. |
| 667 | `    {` | Abre ou fecha um bloco de codigo. |
| 668 | `        if ((navios[i].linha1 == linha &amp;&amp; navios[i].coluna1 == coluna) &#124;&#124;` | Procura qual navio ocupa a linha e coluna informadas. |
| 669 | `            (navios[i].linha2 == linha &amp;&amp; navios[i].coluna2 == coluna))` | Procura qual navio ocupa a linha e coluna informadas. |
| 670 | `        {` | Abre ou fecha um bloco de codigo. |
| 671 | `            return i;` | Procura qual navio ocupa a linha e coluna informadas. |
| 672 | `        }` | Fecha um bloco de codigo. |
| 673 | `    }` | Fecha um bloco de codigo. |
| 674 | &nbsp; | Linha em branco para separar partes do codigo. |
| 675 | `    return -1;` | Retorna `-1` se nenhum navio for encontrado. |
| 676 | `}` | Fecha um bloco de codigo. |
| 677 | &nbsp; | Linha em branco para separar partes do codigo. |
| 678 | `/* Marca as duas partes de um navio afundado. */` | Comentario sobre marcar navio afundado. |
| 679 | `void marcarNavioAfundado(int **visao, Navio navio)` | Inicio da funcao `marcarNavioAfundado`. |
| 680 | `{` | Abre um bloco de codigo. |
| 681 | `    visao[navio.linha1][navio.coluna1] = MARCA_AFUNDOU;` | Marca a primeira parte do navio como afundada. |
| 682 | `    visao[navio.linha2][navio.coluna2] = MARCA_AFUNDOU;` | Marca a segunda parte do navio como afundada. |
| 683 | `}` | Fecha um bloco de codigo. |
| 684 | &nbsp; | Linha em branco para separar partes do codigo. |
| 685 | `/* Faz um bombardeio e devolve Agua, Impacto ou Afundou. */` | Comentario sobre executar um bombardeio. |
| 686 | `int bombardear(Jogador *atacante, Jogador *defensor, int linha, int coluna)` | Inicio da funcao `bombardear`. |
| 687 | `{` | Abre um bloco de codigo. |
| 688 | `    int indice;` | Cria variavel para guardar o indice do navio atingido. |
| 689 | `    int valor = defensor-&gt;campo[linha][coluna];` | Pega o valor da posicao atacada no campo do defensor. |
| 690 | &nbsp; | Linha em branco para separar partes do codigo. |
| 691 | `    if (valor == AGUA)` | Verifica uma condicao para decidir o que fazer. |
| 692 | `    {` | Abre ou fecha um bloco de codigo. |
| 693 | `        atacante-&gt;visaoAdversario[linha][coluna] = MARCA_AGUA;` | Se acertou agua, marca agua na visao do atacante e retorna esse resultado. |
| 694 | `        return MARCA_AGUA;` | Se acertou agua, marca agua na visao do atacante e retorna esse resultado. |
| 695 | `    }` | Fecha um bloco de codigo. |
| 696 | &nbsp; | Linha em branco para separar partes do codigo. |
| 697 | `    if (valor &gt;= NAVIO_BASE)` | Verifica uma condicao para decidir o que fazer. |
| 698 | `    {` | Abre ou fecha um bloco de codigo. |
| 699 | `        indice = indiceNavioPorPosicao(defensor-&gt;navios, defensor-&gt;totalNavios, linha, coluna);` | Descobre qual navio foi atingido. |
| 700 | `        defensor-&gt;campo[linha][coluna] = NAVIO_ACERTADO;` | Marca a posicao como parte de navio acertada. |
| 701 | `        defensor-&gt;navios[indice].acertos++;` | Soma um acerto ao navio atingido. |
| 702 | &nbsp; | Linha em branco para separar partes do codigo. |
| 703 | `        if (defensor-&gt;navios[indice].acertos == 2)` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 704 | `        {` | Abre ou fecha um bloco de codigo. |
| 705 | `            defensor-&gt;naviosAfundados++;` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 706 | `            marcarNavioAfundado(atacante-&gt;visaoAdversario, defensor-&gt;navios[indice]);` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 707 | `            return MARCA_AFUNDOU;` | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 708 | `        }` | Fecha um bloco de codigo. |
| 709 | `        else` | Caso contrario, executa o outro bloco. |
| 710 | `        {` | Abre ou fecha um bloco de codigo. |
| 711 | `            atacante-&gt;visaoAdversario[linha][coluna] = MARCA_IMPACTO;` | Se ainda nao afundou, marca impacto e retorna `4`. |
| 712 | `            return MARCA_IMPACTO;` | Se ainda nao afundou, marca impacto e retorna `4`. |
| 713 | `        }` | Fecha um bloco de codigo. |
| 714 | `    }` | Fecha um bloco de codigo. |
| 715 | &nbsp; | Linha em branco para separar partes do codigo. |
| 716 | `    return MARCA_AGUA;` | Retorna agua para qualquer outro caso. |
| 717 | `}` | Fecha um bloco de codigo. |
| 718 | &nbsp; | Linha em branco para separar partes do codigo. |
| 719 | `/* Mostra o texto do resultado de um bombardeio. */` | Comentario sobre mostrar resultado do bombardeio. |
| 720 | `void mostrarResultadoBombardeio(int resultado)` | Inicio da funcao `mostrarResultadoBombardeio`. |
| 721 | `{` | Abre um bloco de codigo. |
| 722 | `    if (resultado == MARCA_AGUA)` | Se o resultado foi agua, imprime `Agua!`. |
| 723 | `    {` | Abre ou fecha um bloco de codigo. |
| 724 | `        printf("Agua!\n");` | Se o resultado foi agua, imprime `Agua!`. |
| 725 | `    }` | Fecha um bloco de codigo. |
| 726 | `    else if (resultado == MARCA_IMPACTO)` | Se foi impacto, imprime `Impacto!`. |
| 727 | `    {` | Abre ou fecha um bloco de codigo. |
| 728 | `        printf("Impacto!\n");` | Se foi impacto, imprime `Impacto!`. |
| 729 | `    }` | Fecha um bloco de codigo. |
| 730 | `    else` | Caso contrario, executa o outro bloco. |
| 731 | `    {` | Abre ou fecha um bloco de codigo. |
| 732 | `        printf("Afundou!\n");` | Caso contrario, imprime `Afundou!`. |
| 733 | `    }` | Fecha um bloco de codigo. |
| 734 | `}` | Fecha um bloco de codigo. |
| 735 | &nbsp; | Linha em branco para separar partes do codigo. |
| 736 | `/* Verifica se o jogador ja bombardeou uma posicao. */` | Comentario sobre verificar posicao ja bombardeada. |
| 737 | `int posicaoJaBombardeada(Jogador *atacante, int linha, int coluna)` | Inicio da funcao `posicaoJaBombardeada`. |
| 738 | `{` | Abre um bloco de codigo. |
| 739 | `    return atacante-&gt;visaoAdversario[linha][coluna] != DESCONHECIDO;` | Retorna verdadeiro se a posicao nao esta mais desconhecida. |
| 740 | `}` | Fecha um bloco de codigo. |
| 741 | &nbsp; | Linha em branco para separar partes do codigo. |
| 742 | `/* Executa os tres bombardeios do jogador humano. */` | Comentario sobre os tres bombardeios do humano. |
| 743 | `int turnoHumano(Jogo *jogo)` | Inicio da funcao `turnoHumano`. |
| 744 | `{` | Abre um bloco de codigo. |
| 745 | `    int i;` | Cria um contador para laco. |
| 746 | `    int linha;` | Cria variavel para guardar uma linha do campo. |
| 747 | `    int coluna;` | Cria variavel para guardar uma coluna do campo. |
| 748 | `    int linhaEscolhida;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 749 | `    int colunaEscolhida;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 750 | `    int tamanho = jogo-&gt;config.tamanho;` | Guarda o tamanho do campo em uma variavel. |
| 751 | `    int entradaValida;` | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 752 | &nbsp; | Linha em branco para separar partes do codigo. |
| 753 | `    for (i = jogo-&gt;bombardeiosHumanoFeitos; i &lt; 3; i++)` | Continua o turno humano a partir do bombardeio que ainda falta fazer. |
| 754 | `    {` | Abre ou fecha um bloco de codigo. |
| 755 | `        mostrarCampos(jogo);` | Mostra os campos antes de pedir o proximo bombardeio. |
| 756 | `        printf("Bombardeio %d de 3\n", i + 1);` | Mostra qual bombardeio esta sendo feito. |
| 757 | `        printf("Digite 0 na linha para voltar ao menu sem salvar.\n");` | Explica que linha `0` volta ao menu sem salvar. |
| 758 | `        printf("Digite -1 na linha para salvar e voltar ao menu.\n");` | Explica que linha `-1` salva e volta ao menu. |
| 759 | &nbsp; | Linha em branco para separar partes do codigo. |
| 760 | `        do` | Comeca a repeticao da leitura ate a entrada ser valida. |
| 761 | `        {` | Abre ou fecha um bloco de codigo. |
| 762 | `            entradaValida = 1;` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 763 | `            linhaEscolhida = lerInteiro("Escolha a linha do campo adversario: ");` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 764 | &nbsp; | Linha em branco para separar partes do codigo. |
| 765 | `            if (linhaEscolhida == 0)` | Se a linha for `0`, encerra a partida atual e volta ao menu. |
| 766 | `            {` | Abre ou fecha um bloco de codigo. |
| 767 | `                jogo-&gt;emAndamento = 0;` | Se a linha for `0`, encerra a partida atual e volta ao menu. |
| 768 | `                return 0;` | Volta ao menu sem continuar a partida. |
| 769 | `            }` | Fecha um bloco de codigo. |
| 770 | &nbsp; | Linha em branco para separar partes do codigo. |
| 771 | `            if (linhaEscolhida == -1)` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 772 | `            {` | Abre ou fecha um bloco de codigo. |
| 773 | `                salvarJogo(jogo);` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 774 | `                printf("Jogo salvo.\n");` | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 775 | `                return 0;` | Volta ao menu depois de salvar a partida. |
| 776 | `            }` | Fecha um bloco de codigo. |
| 777 | &nbsp; | Linha em branco para separar partes do codigo. |
| 778 | `            if (linhaEscolhida &lt; 1 &#124;&#124; linhaEscolhida &gt; tamanho)` | Valida se a linha esta dentro do campo. |
| 779 | `            {` | Abre ou fecha um bloco de codigo. |
| 780 | `                printf("Linha invalida. Use valores de 1 ate %d.\n", tamanho);` | Valida se a linha esta dentro do campo. |
| 781 | `                entradaValida = 0;` | Valida se a linha esta dentro do campo. |
| 782 | `            }` | Fecha um bloco de codigo. |
| 783 | `            else` | Caso contrario, executa o outro bloco. |
| 784 | `            {` | Abre ou fecha um bloco de codigo. |
| 785 | `                colunaEscolhida = lerInteiro("Escolha a coluna do campo adversario: ");` | Le a coluna escolhida. |
| 786 | &nbsp; | Linha em branco para separar partes do codigo. |
| 787 | `                if (colunaEscolhida &lt; 1 &#124;&#124; colunaEscolhida &gt; tamanho)` | Valida se a coluna esta dentro do campo. |
| 788 | `                {` | Abre ou fecha um bloco de codigo. |
| 789 | `                    printf("Coluna invalida. Use valores de 1 ate %d.\n", tamanho);` | Valida se a coluna esta dentro do campo. |
| 790 | `                    entradaValida = 0;` | Marca a entrada como invalida para pedir novamente. |
| 791 | `                }` | Fecha um bloco de codigo. |
| 792 | `                else` | Caso contrario, executa o outro bloco. |
| 793 | `                {` | Abre ou fecha um bloco de codigo. |
| 794 | `                    linha = linhaEscolhida - 1;` | Converte linha e coluna de 1..N para 0..N-1. |
| 795 | `                    coluna = colunaEscolhida - 1;` | Converte linha e coluna de 1..N para 0..N-1. |
| 796 | `                }` | Fecha um bloco de codigo. |
| 797 | &nbsp; | Linha em branco para separar partes do codigo. |
| 798 | `                if (entradaValida &amp;&amp; posicaoJaBombardeada(&amp;jogo-&gt;humano, linha, coluna))` | Impede bombardear a mesma posicao duas vezes. |
| 799 | `                {` | Abre ou fecha um bloco de codigo. |
| 800 | `                    printf("Essa posicao ja foi bombardeada.\n");` | Impede bombardear a mesma posicao duas vezes. |
| 801 | `                    entradaValida = 0;` | Marca a entrada como invalida para impedir repetir bombardeio. |
| 802 | `                }` | Fecha um bloco de codigo. |
| 803 | `            }` | Fecha um bloco de codigo. |
| 804 | `        } while (!entradaValida);` | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 805 | &nbsp; | Linha em branco para separar partes do codigo. |
| 806 | `        printf("\nResultado do bombardeio: ");` | Executa o bombardeio e mostra o resultado. |
| 807 | `        mostrarResultadoBombardeio(bombardear(&amp;jogo-&gt;humano, &amp;jogo-&gt;computador, linha, coluna));` | Executa o bombardeio e mostra o resultado. |
| 808 | `        jogo-&gt;bombardeiosHumanoFeitos = i + 1;` | Atualiza quantos bombardeios o humano ja fez antes de permitir salvar. |
| 809 | &nbsp; | Linha em branco para separar partes do codigo. |
| 810 | `        if (jogo-&gt;computador.naviosAfundados == jogo-&gt;computador.totalNavios)` | Verifica se todos os navios do computador foram afundados. |
| 811 | `        {` | Abre ou fecha um bloco de codigo. |
| 812 | `            return 1;` | Encerra a funcao informando sucesso ou que a partida continua. |
| 813 | `        }` | Fecha um bloco de codigo. |
| 814 | `    }` | Fecha um bloco de codigo. |
| 815 | &nbsp; | Linha em branco para separar partes do codigo. |
| 816 | `    jogo-&gt;bombardeiosHumanoFeitos = 0;` | Zera o contador de bombardeios do turno humano. |
| 817 | `    jogo-&gt;turno = 1;` | Passa o turno para o computador. |
| 818 | `    printf("\nFim do seu turno. Agora e a vez da maquina bombardear.\n");` | Mostra mensagem de fim do turno humano. |
| 819 | `    return 1;` | Retorna que a partida deve continuar. |
| 820 | `}` | Fecha um bloco de codigo. |
| 821 | &nbsp; | Linha em branco para separar partes do codigo. |
| 822 | `/* Converte uma posicao sorteada em linha e coluna. */` | Comentario sobre converter posicao em coordenada. |
| 823 | `void posicaoParaCoordenada(int posicao, int tamanho, int *linha, int *coluna)` | Inicio da funcao `posicaoParaCoordenada`. |
| 824 | `{` | Abre um bloco de codigo. |
| 825 | `    posicao--;` | Ajusta a posicao para comecar em zero. |
| 826 | `    *linha = posicao / tamanho;` | Calcula a linha. |
| 827 | `    *coluna = posicao % tamanho;` | Calcula a coluna. |
| 828 | `}` | Fecha um bloco de codigo. |
| 829 | &nbsp; | Linha em branco para separar partes do codigo. |
| 830 | `/* Sorteia uma posicao valida para o computador. */` | Comentario sobre sortear posicao do computador. |
| 831 | `void sortearPosicaoComputador(Jogo *jogo, int *linha, int *coluna)` | Inicio da funcao `sortearPosicaoComputador`. |
| 832 | `{` | Abre um bloco de codigo. |
| 833 | `    int posicao;` | Cria variavel para a posicao sorteada. |
| 834 | `    int limite = jogo-&gt;config.tamanho * jogo-&gt;config.tamanho;` | Calcula o total de casas do campo. |
| 835 | &nbsp; | Linha em branco para separar partes do codigo. |
| 836 | `    do` | Executa uma instrucao do programa. |
| 837 | `    {` | Abre ou fecha um bloco de codigo. |
| 838 | `        posicao = (rand() % limite) + 1;` | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 839 | `        posicaoParaCoordenada(posicao, jogo-&gt;config.tamanho, linha, coluna);` | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 840 | `    } while (posicaoJaBombardeada(&amp;jogo-&gt;computador, *linha, *coluna));` | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 841 | `}` | Fecha um bloco de codigo. |
| 842 | &nbsp; | Linha em branco para separar partes do codigo. |
| 843 | `/* Executa os tres bombardeios do computador. */` | Comentario sobre os tres bombardeios do computador. |
| 844 | `void turnoComputador(Jogo *jogo)` | Inicio da funcao `turnoComputador`. |
| 845 | `{` | Abre um bloco de codigo. |
| 846 | `    int i;` | Cria um contador para laco. |
| 847 | `    int j;` | Cria um contador para laco. |
| 848 | `    int linha;` | Cria variavel para guardar uma linha do campo. |
| 849 | `    int coluna;` | Cria variavel para guardar uma coluna do campo. |
| 850 | `    int totalBombardeios = 0;` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 851 | `    int linhas[3];` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 852 | `    int colunas[3];` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 853 | `    int resultados[3];` | Cria variaveis, vetores de linhas, colunas e resultados. |
| 854 | &nbsp; | Linha em branco para separar partes do codigo. |
| 855 | `    for (i = 0; i &lt; 3; i++)` | Comeca o laco dos tres bombardeios. |
| 856 | `    {` | Abre ou fecha um bloco de codigo. |
| 857 | `        sortearPosicaoComputador(jogo, &amp;linha, &amp;coluna);` | Sorteia uma posicao valida. |
| 858 | `        linhas[i] = linha + 1;` | Guarda a linha e a coluna sorteadas, usando numeros que comecam em 1. |
| 859 | `        colunas[i] = coluna + 1;` | Guarda a linha e a coluna sorteadas, usando numeros que comecam em 1. |
| 860 | `        resultados[i] = bombardear(&amp;jogo-&gt;computador, &amp;jogo-&gt;humano, linha, coluna);` | Executa o bombardeio contra o humano. |
| 861 | `        totalBombardeios++;` | Aumenta o total de bombardeios feitos. |
| 862 | &nbsp; | Linha em branco para separar partes do codigo. |
| 863 | `        limparTela();` | Limpa a tela. |
| 864 | `        mostrarCampos(jogo);` | Executa uma instrucao do programa. |
| 865 | `        printf("===== BOMBARDEIOS DA MAQUINA =====\n");` | Imprime o titulo dos bombardeios da maquina. |
| 866 | &nbsp; | Linha em branco para separar partes do codigo. |
| 867 | `        for (j = 0; j &lt; totalBombardeios; j++)` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 868 | `        {` | Abre ou fecha um bloco de codigo. |
| 869 | `            printf("Bombardeio %d de 3\n", j + 1);` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 870 | `            printf("A maquina bombardeou a linha %d e coluna %d.\n", linhas[j], colunas[j]);` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 871 | `            printf("\nResultado do bombardeio: ");` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 872 | `            mostrarResultadoBombardeio(resultados[j]);` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 873 | `            printf("\n");` | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 874 | `        }` | Fecha um bloco de codigo. |
| 875 | &nbsp; | Linha em branco para separar partes do codigo. |
| 876 | `        if (jogo-&gt;humano.naviosAfundados == jogo-&gt;humano.totalNavios)` | Para o turno se todos os navios humanos afundaram. |
| 877 | `        {` | Abre ou fecha um bloco de codigo. |
| 878 | `            break;` | Para o turno se todos os navios humanos afundaram. |
| 879 | `        }` | Fecha um bloco de codigo. |
| 880 | `    }` | Fecha um bloco de codigo. |
| 881 | &nbsp; | Linha em branco para separar partes do codigo. |
| 882 | `    if (jogo-&gt;humano.naviosAfundados == jogo-&gt;humano.totalNavios)` | Se o humano perdeu, sai da funcao. |
| 883 | `    {` | Abre ou fecha um bloco de codigo. |
| 884 | `        return;` | Retorna um valor ou encerra a funcao. |
| 885 | `    }` | Fecha um bloco de codigo. |
| 886 | &nbsp; | Linha em branco para separar partes do codigo. |
| 887 | `    aguardarEnter();` | Espera o usuario apertar ENTER. |
| 888 | `    jogo-&gt;bombardeiosHumanoFeitos = 0;` | Zera o contador de bombardeios do turno humano. |
| 889 | `    jogo-&gt;turno = 0;` | Devolve o turno para o humano depois da maquina jogar. |
| 890 | `}` | Fecha um bloco de codigo. |
| 891 | &nbsp; | Linha em branco para separar partes do codigo. |
| 892 | `/* Menu que aparece depois de vitoria ou derrota. */` | Comentario sobre menu de fim de jogo. |
| 893 | `int menuFimDeJogo(void)` | Inicio da funcao `menuFimDeJogo`. |
| 894 | `{` | Abre um bloco de codigo. |
| 895 | `    printf("\n1 - Jogar novamente\n");` | Mostra as opcoes depois de uma vitoria ou derrota. |
| 896 | `    printf("2 - Voltar ao menu principal\n");` | Mostra as opcoes depois de uma vitoria ou derrota. |
| 897 | `    printf("3 - Sair\n");` | Mostra as opcoes depois de uma vitoria ou derrota. |
| 898 | `    return lerInteiro("Escolha: ");` | Retorna um valor ou encerra a funcao. |
| 899 | `}` | Fecha um bloco de codigo. |
| 900 | &nbsp; | Linha em branco para separar partes do codigo. |
| 901 | `/* Controla a partida ate alguem vencer ou o jogador voltar ao menu. */` | Comentario sobre controlar a partida. |
| 902 | `void executarPartida(Jogo *jogo)` | Inicio da funcao `executarPartida`. |
| 903 | `{` | Abre um bloco de codigo. |
| 904 | `    int opcao;` | Declara uma variavel inteira. |
| 905 | `    int terminou = 0;` | Cria variavel para indicar se a partida terminou. |
| 906 | &nbsp; | Linha em branco para separar partes do codigo. |
| 907 | `    while (jogo-&gt;emAndamento &amp;&amp; !terminou)` | Mantem a partida rodando enquanto estiver em andamento e nao tiver vencedor. |
| 908 | `    {` | Abre ou fecha um bloco de codigo. |
| 909 | `        if (jogo-&gt;turno == 0)` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 910 | `        {` | Abre ou fecha um bloco de codigo. |
| 911 | `            if (!turnoHumano(jogo))` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 912 | `            {` | Abre ou fecha um bloco de codigo. |
| 913 | `                return;` | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 914 | `            }` | Fecha um bloco de codigo. |
| 915 | `        }` | Fecha um bloco de codigo. |
| 916 | `        else` | Caso contrario, executa o outro bloco. |
| 917 | `        {` | Abre ou fecha um bloco de codigo. |
| 918 | `            turnoComputador(jogo);` | Se for turno do computador, executa o turno do computador. |
| 919 | `        }` | Fecha um bloco de codigo. |
| 920 | &nbsp; | Linha em branco para separar partes do codigo. |
| 921 | `        if (jogo-&gt;computador.naviosAfundados == jogo-&gt;computador.totalNavios)` | Verifica uma condicao para decidir o que fazer. |
| 922 | `        {` | Abre ou fecha um bloco de codigo. |
| 923 | `            printf("\nVoce venceu!\n");` | Se todos os navios do computador afundaram, mostra vitoria. |
| 924 | `            terminou = 1;` | Atualiza ou calcula um valor usado pelo programa. |
| 925 | `        }` | Fecha um bloco de codigo. |
| 926 | `        else if (jogo-&gt;humano.naviosAfundados == jogo-&gt;humano.totalNavios)` | Se todos os navios do humano afundaram, mostra derrota. |
| 927 | `        {` | Abre ou fecha um bloco de codigo. |
| 928 | `            printf("\nVoce perdeu!\n");` | Se todos os navios do humano afundaram, mostra derrota. |
| 929 | `            terminou = 1;` | Atualiza ou calcula um valor usado pelo programa. |
| 930 | `        }` | Fecha um bloco de codigo. |
| 931 | `    }` | Fecha um bloco de codigo. |
| 932 | &nbsp; | Linha em branco para separar partes do codigo. |
| 933 | `    while (terminou)` | Enquanto a partida terminou, mostra o menu final. |
| 934 | `    {` | Abre ou fecha um bloco de codigo. |
| 935 | `        opcao = menuFimDeJogo();` | Le a opcao do menu final. |
| 936 | &nbsp; | Linha em branco para separar partes do codigo. |
| 937 | `        if (opcao == 1)` | Verifica uma condicao para decidir o que fazer. |
| 938 | `        {` | Abre ou fecha um bloco de codigo. |
| 939 | `            liberarJogo(jogo);` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 940 | `            inicializarJogo(jogo, jogo-&gt;config);` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 941 | `            executarPartida(jogo);` | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 942 | `            terminou = 0;` | Atualiza ou calcula um valor usado pelo programa. |
| 943 | `        }` | Fecha um bloco de codigo. |
| 944 | `        else if (opcao == 2)` | Atualiza ou calcula um valor usado pelo programa. |
| 945 | `        {` | Abre ou fecha um bloco de codigo. |
| 946 | `            terminou = 0;` | Atualiza ou calcula um valor usado pelo programa. |
| 947 | `        }` | Fecha um bloco de codigo. |
| 948 | `        else if (opcao == 3)` | Atualiza ou calcula um valor usado pelo programa. |
| 949 | `        {` | Abre ou fecha um bloco de codigo. |
| 950 | `            jogo-&gt;emAndamento = 0;` | Opcao 3: encerra o programa. |
| 951 | `            terminou = 0;` | Atualiza ou calcula um valor usado pelo programa. |
| 952 | `            exit(0);` | Opcao 3: encerra o programa. |
| 953 | `        }` | Fecha um bloco de codigo. |
| 954 | `        else` | Caso contrario, executa o outro bloco. |
| 955 | `        {` | Abre ou fecha um bloco de codigo. |
| 956 | `            printf("Opcao invalida.\n");` | Mostra uma mensagem na tela. |
| 957 | `        }` | Fecha um bloco de codigo. |
| 958 | `    }` | Fecha um bloco de codigo. |
| 959 | `}` | Fecha um bloco de codigo. |
| 960 | &nbsp; | Linha em branco para separar partes do codigo. |
| 961 | `/* Permite mudar tamanho do campo e quantidade de navios. */` | Comentario sobre mudar configuracoes. |
| 962 | `void configurarJogo(Configuracao *config)` | Inicio da funcao `configurarJogo`. |
| 963 | `{` | Abre um bloco de codigo. |
| 964 | `    int tamanho;` | Declara uma variavel inteira. |
| 965 | `    int navios;` | Cria variaveis para tamanho, navios e maximo permitido. |
| 966 | `    int maximoNavios;` | Cria variaveis para tamanho, navios e maximo permitido. |
| 967 | &nbsp; | Linha em branco para separar partes do codigo. |
| 968 | `    tamanho = lerInteiro("Tamanho do campo quadrado (minimo 8): ");` | Le o tamanho do campo. |
| 969 | `    if (tamanho &lt; TAMANHO_MINIMO)` | Se o tamanho for menor que o minimo, usa o minimo. |
| 970 | `    {` | Abre ou fecha um bloco de codigo. |
| 971 | `        tamanho = TAMANHO_MINIMO;` | Se o tamanho for menor que o minimo, usa o minimo. |
| 972 | `    }` | Fecha um bloco de codigo. |
| 973 | &nbsp; | Linha em branco para separar partes do codigo. |
| 974 | `    maximoNavios = (tamanho * tamanho) / 2;` | Calcula o maximo de navios possivel. |
| 975 | `    navios = lerInteiro("Quantidade de navios de duas celulas (minimo 4): ");` | Le a quantidade de navios. |
| 976 | `    if (navios &lt; NAVIOS_MINIMOS)` | Se a quantidade for menor que o minimo, usa o minimo. |
| 977 | `    {` | Abre ou fecha um bloco de codigo. |
| 978 | `        navios = NAVIOS_MINIMOS;` | Se a quantidade for menor que o minimo, usa o minimo. |
| 979 | `    }` | Fecha um bloco de codigo. |
| 980 | `    if (navios &gt; maximoNavios)` | Se a quantidade passar do maximo, limita ao maximo. |
| 981 | `    {` | Abre ou fecha um bloco de codigo. |
| 982 | `        navios = maximoNavios;` | Se a quantidade passar do maximo, limita ao maximo. |
| 983 | `    }` | Fecha um bloco de codigo. |
| 984 | &nbsp; | Linha em branco para separar partes do codigo. |
| 985 | `    config-&gt;tamanho = tamanho;` | Salva o tamanho na configuracao. |
| 986 | `    config-&gt;quantidadeNavios = navios;` | Salva a quantidade de navios na configuracao. |
| 987 | &nbsp; | Linha em branco para separar partes do codigo. |
| 988 | `    if (salvarConfiguracao(config))` | Tenta salvar e mostra mensagem de sucesso. |
| 989 | `    {` | Abre ou fecha um bloco de codigo. |
| 990 | `        printf("Configuracao salva.\n");` | Tenta salvar e mostra mensagem de sucesso. |
| 991 | `    }` | Fecha um bloco de codigo. |
| 992 | `    else` | Caso contrario, executa o outro bloco. |
| 993 | `    {` | Abre ou fecha um bloco de codigo. |
| 994 | `        printf("Nao foi possivel salvar a configuracao.\n");` | Se nao conseguir salvar, mostra mensagem de erro. |
| 995 | `    }` | Fecha um bloco de codigo. |
| 996 | `}` | Fecha um bloco de codigo. |
| 997 | &nbsp; | Linha em branco para separar partes do codigo. |
| 998 | `/* Le a opcao escolhida no menu principal. */` | Comentario sobre ler opcao do menu. |
| 999 | `int lerOpcaoMenu(void)` | Inicio da funcao `lerOpcaoMenu`. |
| 1000 | `{` | Abre um bloco de codigo. |
| 1001 | `    return lerInteiro("Escolha: ");` | Retorna um valor ou encerra a funcao. |
| 1002 | `}` | Fecha um bloco de codigo. |
| 1003 | &nbsp; | Linha em branco para separar partes do codigo. |
| 1004 | `/* Mostra o menu principal do jogo. */` | Comentario sobre mostrar menu principal. |
| 1005 | `void mostrarMenu(Configuracao config)` | Inicio da funcao `mostrarMenu`. |
| 1006 | `{` | Abre um bloco de codigo. |
| 1007 | `    printf("\n===== BATALHA NAVAL =====\n");` | Imprime o titulo do jogo. |
| 1008 | `    printf("Configuracao atual: campo %dx%d, %d navios\n",` | Mostra a configuracao atual. |
| 1009 | `           config.tamanho, config.tamanho, config.quantidadeNavios);` | Mostra a configuracao atual. |
| 1010 | `    printf("1 - Novo Jogo\n");` | Mostra opcao de novo jogo. |
| 1011 | `    printf("2 - Configurar\n");` | Mostra opcao de configurar. |
| 1012 | `    printf("3 - Carregar\n");` | Mostra opcao de carregar jogo salvo. |
| 1013 | `    printf("4 - Sair\n");` | Mostra opcao de sair. |
| 1014 | `}` | Fecha um bloco de codigo. |
| 1015 | &nbsp; | Linha em branco para separar partes do codigo. |
| 1016 | `/* Funcao principal: o programa sempre comeca por aqui. */` | Comentario dizendo que o programa comeca na funcao principal. |
| 1017 | `int main(void)` | Inicio da funcao `main`. |
| 1018 | `{` | Abre um bloco de codigo. |
| 1019 | `    Configuracao config;` | Executa uma instrucao do programa. |
| 1020 | `    Jogo jogo;` | Cria a variavel que guarda a partida. |
| 1021 | `    int opcao;` | Declara uma variavel inteira. |
| 1022 | `    int executando = 1;` | Cria variavel que mantem o menu rodando. |
| 1023 | &nbsp; | Linha em branco para separar partes do codigo. |
| 1024 | `    srand((unsigned int)time(NULL));` | Inicializa o sorteio aleatorio usando o horario atual. |
| 1025 | `    carregarConfiguracao(&amp;config);` | Carrega configuracao salva ou usa a padrao. |
| 1026 | &nbsp; | Linha em branco para separar partes do codigo. |
| 1027 | `    while (executando)` | Comeca o laco principal do programa. |
| 1028 | `    {` | Abre ou fecha um bloco de codigo. |
| 1029 | `        mostrarMenu(config);` | Mostra o menu principal. |
| 1030 | `        opcao = lerOpcaoMenu();` | Le a opcao escolhida. |
| 1031 | &nbsp; | Linha em branco para separar partes do codigo. |
| 1032 | `        if (opcao == 1)` | Verifica uma condicao para decidir o que fazer. |
| 1033 | `        {` | Abre ou fecha um bloco de codigo. |
| 1034 | `            inicializarJogo(&amp;jogo, config);` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 1035 | `            executarPartida(&amp;jogo);` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 1036 | `            liberarJogo(&amp;jogo);` | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 1037 | `        }` | Fecha um bloco de codigo. |
| 1038 | `        else if (opcao == 2)` | Atualiza ou calcula um valor usado pelo programa. |
| 1039 | `        {` | Abre ou fecha um bloco de codigo. |
| 1040 | `            configurarJogo(&amp;config);` | Opcao 2: abre a configuracao do jogo. |
| 1041 | `        }` | Fecha um bloco de codigo. |
| 1042 | `        else if (opcao == 3)` | Atualiza ou calcula um valor usado pelo programa. |
| 1043 | `        {` | Abre ou fecha um bloco de codigo. |
| 1044 | `            if (carregarJogo(&amp;jogo))` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1045 | `            {` | Abre ou fecha um bloco de codigo. |
| 1046 | `                executarPartida(&amp;jogo);` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1047 | `                liberarJogo(&amp;jogo);` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1048 | `                carregarConfiguracao(&amp;config);` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1049 | `            }` | Fecha um bloco de codigo. |
| 1050 | `            else` | Caso contrario, executa o outro bloco. |
| 1051 | `            {` | Abre ou fecha um bloco de codigo. |
| 1052 | `                printf("Nenhum jogo salvo encontrado.\n");` | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1053 | `            }` | Fecha um bloco de codigo. |
| 1054 | `        }` | Fecha um bloco de codigo. |
| 1055 | `        else if (opcao == 4)` | Opcao 4: encerra o laco principal. |
| 1056 | `        {` | Abre ou fecha um bloco de codigo. |
| 1057 | `            executando = 0;` | Opcao 4: encerra o laco principal. |
| 1058 | `        }` | Fecha um bloco de codigo. |
| 1059 | `        else` | Caso contrario, executa o outro bloco. |
| 1060 | `        {` | Abre ou fecha um bloco de codigo. |
| 1061 | `            printf("Opcao invalida.\n");` | Mostra uma mensagem na tela. |
| 1062 | `        }` | Fecha um bloco de codigo. |
| 1063 | `    }` | Fecha um bloco de codigo. |
| 1064 | &nbsp; | Linha em branco para separar partes do codigo. |
| 1065 | `    printf("Programa encerrado.\n");` | Mostra mensagem de encerramento. |
| 1066 | `    return 0;` | Retorna zero, indicando que o programa terminou corretamente. |
| 1067 | `}` | Fecha um bloco de codigo. |
