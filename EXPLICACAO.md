# Explicacao do codigo `batalha_naval.c`

Este arquivo explica, de forma simples e direta, o que cada linha ou bloco pequeno do programa faz.

## Bibliotecas e constantes

| Linha(s) | Explicacao |
|---|---|
| 1 | Inclui a biblioteca de entrada e saida, usada por `printf`, `scanf` e arquivos. |
| 2 | Inclui funcoes gerais, como `malloc`, `free`, `rand`, `srand` e `exit`. |
| 3 | Inclui funcoes de tempo, usadas para iniciar o sorteio aleatorio. |
| 5 | Comentario dizendo que os proximos valores sao usados nas matrizes do jogo. |
| 6 | Define `AGUA` como valor `0`. |
| 7 | Define `NAVIO_ACERTADO` como valor `2`. |
| 8 | Define `MARCA_AGUA` como valor `3`, usado quando o jogador erra um tiro. |
| 9 | Define `MARCA_IMPACTO` como valor `4`, usado quando acerta parte de um navio. |
| 10 | Define `MARCA_AFUNDOU` como valor `5`, usado quando um navio inteiro afunda. |
| 11 | Define `DESCONHECIDO` como valor `7`, usado em posicoes ainda nao atacadas. |
| 12 | Define `NAVIO_BASE` como valor `10`, para identificar navios internamente. |
| 14 | Comentario indicando as regras minimas do trabalho. |
| 15 | Define o menor tamanho permitido para o tabuleiro. |
| 16 | Define a menor quantidade permitida de navios. |
| 17 | Define o nome do arquivo binario usado para salvar dados. |

## Registros do jogo

| Linha(s) | Explicacao |
|---|---|
| 19 | Comentario sobre o registro de configuracao. |
| 20-24 | Cria o tipo `Configuracao`, que guarda tamanho do campo e quantidade de navios. |
| 26 | Comentario sobre o registro de navio. |
| 27-34 | Cria o tipo `Navio`, que guarda as duas posicoes do navio e seus acertos. |
| 36 | Comentario sobre o registro do jogador. |
| 37-44 | Cria o tipo `Jogador`, com campo, visao do adversario, navios e contadores. |
| 46 | Comentario sobre o registro da partida completa. |
| 47-54 | Cria o tipo `Jogo`, juntando configuracao, jogadores, turno e estado da partida. |

## Prototipos

| Linha(s) | Explicacao |
|---|---|
| 56 | Comentario indicando que vem a lista de prototipos das funcoes. |
| 57 | Declara a funcao que cria uma matriz. |
| 58 | Declara a funcao que libera uma matriz da memoria. |
| 59 | Declara a funcao que preenche uma matriz com um valor. |
| 60 | Declara a funcao que imprime o campo do proprio jogador. |
| 61 | Declara a funcao que imprime o campo conhecido do adversario. |
| 62 | Declara a funcao que define a configuracao padrao. |
| 63 | Declara a funcao que salva a configuracao. |
| 64 | Declara a funcao que carrega a configuracao. |
| 65 | Declara a funcao que salva uma partida. |
| 66 | Declara a funcao que carrega uma partida. |
| 67 | Declara a funcao que inicia uma partida. |
| 68 | Declara a funcao que libera a memoria da partida. |
| 69 | Declara a funcao que executa a partida. |
| 70 | Declara a funcao que altera as configuracoes. |
| 71 | Declara a funcao recursiva que conta navios restantes. |

## Entrada do usuario

| Linha(s) | Explicacao |
|---|---|
| 73 | Comentario dizendo que a funcao limpa entradas invalidas. |
| 74 | Inicio da funcao `limparEntrada`. |
| 76 | Cria a variavel que recebe cada caractere digitado. |
| 78-81 | Le caracteres ate chegar no fim da linha ou no fim do arquivo. |
| 82 | Fecha a funcao. |
| 84 | Comentario dizendo que a funcao le um numero inteiro. |
| 85 | Inicio da funcao `lerInteiro`, recebendo uma mensagem para mostrar ao usuario. |
| 87 | Cria a variavel onde o numero sera guardado. |
| 89 | Mostra a mensagem na tela. |
| 90 | Tenta ler um inteiro; se nao conseguir, entra no laco. |
| 92 | Limpa o que foi digitado errado. |
| 93 | Pede novamente um numero inteiro. |
| 94 | Fecha o laco de validacao. |
| 96 | Limpa o restante da linha depois da leitura correta. |
| 97 | Devolve o numero lido. |
| 98 | Fecha a funcao. |
| 100 | Comentario dizendo que a funcao pausa a tela. |
| 101 | Inicio da funcao `aguardarEnter`. |
| 103 | Mostra a mensagem pedindo ENTER. |
| 104 | Espera o usuario apertar ENTER. |
| 105 | Fecha a funcao. |

## Matrizes e impressao dos campos

| Linha(s) | Explicacao |
|---|---|
| 107 | Comentario sobre alocar uma matriz quadrada. |
| 108 | Inicio da funcao `criarMatriz`. |
| 110 | Cria o contador do laco. |
| 111 | Aloca o vetor de ponteiros, um para cada linha da matriz. |
| 113-116 | Se a alocacao falhar, retorna `NULL`. |
| 118-127 | Aloca cada linha da matriz; se falhar, libera o que ja foi alocado. |
| 129 | Retorna a matriz criada. |
| 130 | Fecha a funcao. |
| 132 | Comentario sobre liberar uma matriz. |
| 133 | Inicio da funcao `liberarMatriz`. |
| 135 | Cria o contador do laco. |
| 137-140 | Se a matriz for nula, sai da funcao. |
| 142-145 | Libera cada linha da matriz. |
| 147 | Libera o vetor principal da matriz. |
| 148 | Fecha a funcao. |
| 150 | Comentario sobre preencher uma matriz. |
| 151 | Inicio da funcao `preencherMatriz`. |
| 153-154 | Cria os contadores de linha e coluna. |
| 156-162 | Percorre todas as posicoes e coloca o valor informado. |
| 163 | Fecha a funcao. |
| 165 | Comentario sobre imprimir cabecalho. |
| 166 | Inicio da funcao `imprimirCabecalho`. |
| 168 | Cria o contador de colunas. |
| 170 | Imprime espacos antes dos numeros das colunas. |
| 171-174 | Imprime os numeros das colunas. |
| 175 | Pula linha. |
| 177 | Imprime o inicio da linha separadora. |
| 178-181 | Imprime tracos da largura do campo. |
| 182 | Pula linha. |
| 183 | Fecha a funcao. |
| 185 | Comentario sobre imprimir o campo do jogador. |
| 186 | Inicio da funcao `imprimirCampoProprio`. |
| 188-190 | Cria contadores e a variavel que guarda o valor da posicao. |
| 192 | Imprime o cabecalho do campo. |
| 194-219 | Percorre o campo e imprime agua, acerto, navio visivel como `1` ou outro valor. |
| 220 | Fecha a funcao. |
| 222 | Comentario sobre imprimir o campo adversario conhecido. |
| 223 | Inicio da funcao `imprimirCampoAdversario`. |
| 225-226 | Cria contadores de linha e coluna. |
| 228 | Imprime o cabecalho. |
| 230-238 | Percorre e imprime todos os valores conhecidos do campo adversario. |
| 239 | Fecha a funcao. |
| 241 | Comentario sobre converter valor interno em valor visivel. |
| 242 | Inicio da funcao `valorVisivelCampoProprio`. |
| 244-247 | Se for agua, retorna `0`. |
| 249-252 | Se for navio acertado, retorna `2`. |
| 254-257 | Se for parte de navio ainda inteiro, mostra como `1`. |
| 259 | Retorna outros valores sem alterar. |
| 260 | Fecha a funcao. |
| 262 | Comentario sobre cabecalho duplo. |
| 263 | Inicio da funcao `imprimirCabecalhoDuplo`. |
| 265 | Cria o contador de colunas. |
| 267-280 | Imprime os numeros das colunas dos dois campos lado a lado. |
| 282-295 | Imprime as linhas separadoras dos dois campos lado a lado. |
| 296 | Fecha a funcao. |
| 298 | Comentario sobre imprimir dois campos lado a lado. |
| 299 | Inicio da funcao `imprimirCamposLadoALado`. |
| 301-303 | Cria contadores e a variavel de valor. |
| 305 | Imprime o cabecalho duplo. |
| 307-325 | Percorre as linhas e imprime o campo humano e a visao do computador na mesma linha. |
| 326 | Fecha a funcao. |

## Configuracao e arquivo binario

| Linha(s) | Explicacao |
|---|---|
| 328 | Comentario sobre configuracao padrao. |
| 329 | Inicio da funcao `configuracaoPadrao`. |
| 331 | Define o tamanho minimo do campo. |
| 332 | Define a quantidade minima de navios. |
| 333 | Fecha a funcao. |
| 335 | Comentario sobre salvar configuracao. |
| 336 | Inicio da funcao `salvarConfiguracao`. |
| 338 | Abre o arquivo binario para escrita. |
| 339 | Define que nao existe partida salva, apenas configuracao. |
| 341-344 | Se o arquivo nao abrir, retorna erro. |
| 346 | Grava a configuracao no arquivo. |
| 347 | Grava a informacao de que nao ha jogo salvo. |
| 349 | Fecha o arquivo. |
| 350 | Retorna sucesso. |
| 351 | Fecha a funcao. |
| 353 | Comentario sobre carregar configuracao. |
| 354 | Inicio da funcao `carregarConfiguracao`. |
| 356 | Abre o arquivo binario para leitura. |
| 358-362 | Se o arquivo nao existir, usa a configuracao padrao e retorna erro. |
| 364 | Le a configuracao do arquivo. |
| 365 | Fecha o arquivo. |
| 366 | Retorna sucesso. |
| 367 | Fecha a funcao. |
| 369 | Comentario sobre escrever matriz no arquivo. |
| 370 | Inicio da funcao `escreverMatriz`. |
| 372 | Cria o contador de linhas. |
| 374-377 | Grava cada linha da matriz no arquivo. |
| 378 | Fecha a funcao. |
| 380 | Comentario sobre ler matriz do arquivo. |
| 381 | Inicio da funcao `lerMatriz`. |
| 383 | Cria o contador de linhas. |
| 385-388 | Le cada linha da matriz do arquivo. |
| 389 | Fecha a funcao. |
| 391 | Comentario sobre salvar partida completa. |
| 392 | Inicio da funcao `salvarJogo`. |
| 394 | Abre o arquivo binario para escrita. |
| 395 | Marca que existe jogo salvo. |
| 396 | Guarda o tamanho do campo em uma variavel. |
| 398-401 | Se o arquivo nao abrir, retorna erro. |
| 403-406 | Salva configuracao, existencia do jogo, turno e estado da partida. |
| 408-412 | Salva dados, navios e matrizes do jogador humano. |
| 414-418 | Salva dados, navios e matrizes do computador. |
| 420 | Fecha o arquivo. |
| 421 | Retorna sucesso. |
| 422 | Fecha a funcao. |
| 424 | Comentario sobre carregar partida completa. |
| 425 | Inicio da funcao `carregarJogo`. |
| 427 | Abre o arquivo binario para leitura. |
| 428 | Cria variavel que indica se existe jogo salvo. |
| 429 | Cria variavel para o tamanho do campo. |
| 431-434 | Se o arquivo nao abrir, retorna erro. |
| 436-437 | Le configuracao e indicador de jogo salvo. |
| 439-443 | Se nao houver jogo salvo, fecha o arquivo e retorna erro. |
| 445 | Copia o tamanho da configuracao. |
| 447-448 | Le turno e estado da partida. |
| 450-457 | Le dados do jogador humano e recria suas matrizes. |
| 459-466 | Le dados do computador e recria suas matrizes. |
| 468 | Fecha o arquivo. |
| 469 | Retorna sucesso. |
| 470 | Fecha a funcao. |

## Posicionamento e inicializacao

| Linha(s) | Explicacao |
|---|---|
| 472 | Comentario sobre verificar posicoes livres. |
| 473 | Inicio da funcao `posicaoLivre`. |
| 475 | Retorna verdadeiro se as duas posicoes estiverem com agua. |
| 476 | Fecha a funcao. |
| 478 | Comentario sobre sortear navios. |
| 479 | Inicio da funcao `posicionarNavios`. |
| 481-486 | Cria variaveis usadas para sortear posicoes e direcao. |
| 488 | Comeca um laco para posicionar todos os navios. |
| 490-507 | Sorteia uma posicao horizontal ou vertical ate achar espaco valido. |
| 509-513 | Guarda as coordenadas e zera os acertos do navio. |
| 515-516 | Marca as duas partes do navio no campo. |
| 517 | Fecha o laco dos navios. |
| 518 | Fecha a funcao. |
| 520 | Comentario sobre inicializar jogador. |
| 521 | Inicio da funcao `inicializarJogador`. |
| 523 | Cria a matriz do campo do jogador. |
| 524 | Cria a matriz da visao do adversario. |
| 525 | Aloca o vetor de navios. |
| 526 | Guarda a quantidade total de navios. |
| 527 | Zera a quantidade de navios afundados. |
| 529 | Preenche o campo com agua. |
| 530 | Preenche a visao do adversario com posicoes desconhecidas. |
| 531 | Sorteia e posiciona os navios. |
| 532 | Fecha a funcao. |
| 534 | Comentario sobre liberar memoria do jogador. |
| 535 | Inicio da funcao `liberarJogador`. |
| 537 | Libera a matriz do campo. |
| 538 | Libera a matriz da visao do adversario. |
| 539 | Libera o vetor de navios. |
| 541-543 | Coloca os ponteiros como `NULL` para evitar uso indevido. |
| 544 | Fecha a funcao. |
| 546 | Comentario sobre criar nova partida. |
| 547 | Inicio da funcao `inicializarJogo`. |
| 549 | Copia a configuracao para o jogo. |
| 550 | Define que o humano comeca. |
| 551 | Marca o jogo como em andamento. |
| 553 | Inicializa o jogador humano. |
| 554 | Inicializa o computador. |
| 555 | Fecha a funcao. |
| 557 | Comentario sobre liberar memoria do jogo. |
| 558 | Inicio da funcao `liberarJogo`. |
| 560 | Guarda o tamanho do campo. |
| 562 | Libera os dados do humano. |
| 563 | Libera os dados do computador. |
| 564 | Fecha a funcao. |

## Legenda e exibicao da partida

| Linha(s) | Explicacao |
|---|---|
| 566 | Comentario indicando que a funcao usa recursao. |
| 567 | Inicio da funcao `contarNaviosRestantes`. |
| 569-572 | Caso base: se chegou ao final do vetor, retorna zero. |
| 574-577 | Se o navio atual ainda nao afundou, conta ele e chama a funcao de novo. |
| 579 | Se o navio ja afundou, apenas continua a contagem. |
| 580 | Fecha a funcao. |
| 582 | Comentario sobre mostrar legenda. |
| 583 | Inicio da funcao `mostrarLegenda`. |
| 585-592 | Imprime o significado de cada numero usado no tabuleiro. |
| 593 | Fecha a funcao. |
| 595 | Comentario sobre limpar a tela. |
| 596 | Inicio da funcao `limparTela`. |
| 598 | Imprime codigos ANSI para limpar a tela e voltar ao topo. |
| 599 | Forca a saida aparecer imediatamente. |
| 600 | Fecha a funcao. |
| 602 | Comentario sobre mostrar os campos. |
| 603 | Inicio da funcao `mostrarCampos`. |
| 605-609 | Cria variaveis para contadores, largura e textos. |
| 611 | Conta os navios restantes do humano. |
| 612 | Conta os navios restantes do computador. |
| 613 | Monta o texto de navios restantes do humano. |
| 614 | Monta o texto de navios restantes do computador. |
| 616-618 | Imprime os titulos dos dois campos. |
| 620-622 | Imprime os campos lado a lado. |
| 624 | Mostra a legenda. |
| 625 | Pula uma linha. |
| 626 | Fecha a funcao. |

## Bombardeios

| Linha(s) | Explicacao |
|---|---|
| 628 | Comentario sobre procurar navio por posicao. |
| 629 | Inicio da funcao `indiceNavioPorPosicao`. |
| 631 | Cria o contador do laco. |
| 633-640 | Procura qual navio ocupa a linha e coluna informadas. |
| 642 | Retorna `-1` se nenhum navio for encontrado. |
| 643 | Fecha a funcao. |
| 645 | Comentario sobre marcar navio afundado. |
| 646 | Inicio da funcao `marcarNavioAfundado`. |
| 648 | Marca a primeira parte do navio como afundada. |
| 649 | Marca a segunda parte do navio como afundada. |
| 650 | Fecha a funcao. |
| 652 | Comentario sobre executar um bombardeio. |
| 653 | Inicio da funcao `bombardear`. |
| 655 | Cria variavel para guardar o indice do navio atingido. |
| 656 | Pega o valor da posicao atacada no campo do defensor. |
| 658-662 | Se acertou agua, marca agua na visao do atacante e retorna esse resultado. |
| 664 | Verifica se a posicao contem navio. |
| 666 | Descobre qual navio foi atingido. |
| 667 | Marca a posicao como parte de navio acertada. |
| 668 | Soma um acerto ao navio atingido. |
| 670-675 | Se o navio recebeu dois acertos, marca como afundado e retorna `5`. |
| 676-680 | Se ainda nao afundou, marca impacto e retorna `4`. |
| 683 | Retorna agua para qualquer outro caso. |
| 684 | Fecha a funcao. |
| 686 | Comentario sobre mostrar resultado do bombardeio. |
| 687 | Inicio da funcao `mostrarResultadoBombardeio`. |
| 689-692 | Se o resultado foi agua, imprime `Agua!`. |
| 693-696 | Se foi impacto, imprime `Impacto!`. |
| 697-700 | Caso contrario, imprime `Afundou!`. |
| 701 | Fecha a funcao. |
| 703 | Comentario sobre verificar posicao ja bombardeada. |
| 704 | Inicio da funcao `posicaoJaBombardeada`. |
| 706 | Retorna verdadeiro se a posicao nao esta mais desconhecida. |
| 707 | Fecha a funcao. |

## Turno do humano

| Linha(s) | Explicacao |
|---|---|
| 709 | Comentario sobre os tres bombardeios do humano. |
| 710 | Inicio da funcao `turnoHumano`. |
| 712-718 | Cria variaveis para laco, coordenadas, tamanho e validacao. |
| 720 | Comeca o laco dos tres bombardeios. |
| 722 | Mostra os campos. |
| 723 | Mostra qual bombardeio esta sendo feito. |
| 724 | Explica que linha `0` volta ao menu sem salvar. |
| 725 | Explica que linha `-1` salva e volta ao menu. |
| 727-771 | Repete a leitura ate o usuario informar uma posicao valida e ainda nao atacada. |
| 732-736 | Se a linha for `0`, encerra a partida atual e volta ao menu. |
| 738-743 | Se a linha for `-1`, salva o jogo e volta ao menu. |
| 745-749 | Valida se a linha esta dentro do campo. |
| 752 | Le a coluna escolhida. |
| 754-758 | Valida se a coluna esta dentro do campo. |
| 761-762 | Converte linha e coluna de 1..N para 0..N-1. |
| 765-769 | Impede bombardear a mesma posicao duas vezes. |
| 773-774 | Executa o bombardeio e mostra o resultado. |
| 776-779 | Se todos os navios do computador afundaram, indica fim do jogo. |
| 782 | Passa o turno para o computador. |
| 783 | Mostra mensagem de fim do turno humano. |
| 784 | Retorna que a partida deve continuar. |
| 785 | Fecha a funcao. |

## Turno do computador

| Linha(s) | Explicacao |
|---|---|
| 787 | Comentario sobre converter posicao em coordenada. |
| 788 | Inicio da funcao `posicaoParaCoordenada`. |
| 790 | Ajusta a posicao para comecar em zero. |
| 791 | Calcula a linha. |
| 792 | Calcula a coluna. |
| 793 | Fecha a funcao. |
| 795 | Comentario sobre sortear posicao do computador. |
| 796 | Inicio da funcao `sortearPosicaoComputador`. |
| 798 | Cria variavel para a posicao sorteada. |
| 799 | Calcula o total de casas do campo. |
| 801-805 | Sorteia uma posicao ate encontrar uma que ainda nao foi bombardeada. |
| 806 | Fecha a funcao. |
| 808 | Comentario sobre os tres bombardeios do computador. |
| 809 | Inicio da funcao `turnoComputador`. |
| 811-818 | Cria variaveis, vetores de posicoes e resultados. |
| 820 | Comeca o laco dos tres bombardeios. |
| 822 | Sorteia uma posicao valida. |
| 823 | Converte linha e coluna em numero de posicao. |
| 824 | Guarda a posicao sorteada. |
| 825 | Executa o bombardeio contra o humano. |
| 826 | Aumenta o total de bombardeios feitos. |
| 828 | Limpa a tela. |
| 829 | Mostra os campos atualizados. |
| 830 | Imprime o titulo dos bombardeios da maquina. |
| 832-839 | Mostra todos os bombardeios da maquina feitos neste turno ate agora. |
| 841-844 | Para o turno se todos os navios humanos afundaram. |
| 847-850 | Se o humano perdeu, sai da funcao. |
| 852 | Espera o usuario apertar ENTER. |
| 853 | Devolve o turno para o humano. |
| 854 | Fecha a funcao. |

## Fim de jogo e partida

| Linha(s) | Explicacao |
|---|---|
| 856 | Comentario sobre menu de fim de jogo. |
| 857 | Inicio da funcao `menuFimDeJogo`. |
| 859-861 | Mostra as opcoes depois de uma vitoria ou derrota. |
| 862 | Le e retorna a opcao escolhida. |
| 863 | Fecha a funcao. |
| 865 | Comentario sobre controlar a partida. |
| 866 | Inicio da funcao `executarPartida`. |
| 868 | Cria variavel para opcao do menu final. |
| 869 | Cria variavel para indicar se a partida terminou. |
| 871 | Mantem a partida rodando enquanto estiver em andamento e nao tiver vencedor. |
| 873-879 | Se for turno humano, executa o turno humano e pode voltar ao menu. |
| 880-883 | Se for turno do computador, executa o turno do computador. |
| 885-889 | Se todos os navios do computador afundaram, mostra vitoria. |
| 890-894 | Se todos os navios do humano afundaram, mostra derrota. |
| 897 | Enquanto a partida terminou, mostra o menu final. |
| 899 | Le a opcao do menu final. |
| 901-907 | Opcao 1: libera a partida antiga, cria outra e joga de novo. |
| 908-911 | Opcao 2: volta ao menu principal. |
| 912-917 | Opcao 3: encerra o programa. |
| 918-921 | Qualquer outra opcao mostra erro. |
| 923 | Fecha a funcao. |

## Configuracao e menu principal

| Linha(s) | Explicacao |
|---|---|
| 925 | Comentario sobre mudar configuracoes. |
| 926 | Inicio da funcao `configurarJogo`. |
| 928-930 | Cria variaveis para tamanho, navios e maximo permitido. |
| 932 | Le o tamanho do campo. |
| 933-936 | Se o tamanho for menor que o minimo, usa o minimo. |
| 938 | Calcula o maximo de navios possivel. |
| 939 | Le a quantidade de navios. |
| 940-943 | Se a quantidade for menor que o minimo, usa o minimo. |
| 944-947 | Se a quantidade passar do maximo, limita ao maximo. |
| 949 | Salva o tamanho na configuracao. |
| 950 | Salva a quantidade de navios na configuracao. |
| 952-955 | Tenta salvar e mostra mensagem de sucesso. |
| 956-959 | Se nao conseguir salvar, mostra mensagem de erro. |
| 960 | Fecha a funcao. |
| 962 | Comentario sobre ler opcao do menu. |
| 963 | Inicio da funcao `lerOpcaoMenu`. |
| 965 | Le e retorna a opcao escolhida. |
| 966 | Fecha a funcao. |
| 968 | Comentario sobre mostrar menu principal. |
| 969 | Inicio da funcao `mostrarMenu`. |
| 971 | Imprime o titulo do jogo. |
| 972-973 | Mostra a configuracao atual. |
| 974 | Mostra opcao de novo jogo. |
| 975 | Mostra opcao de configurar. |
| 976 | Mostra opcao de carregar jogo salvo. |
| 977 | Mostra opcao de sair. |
| 978 | Fecha a funcao. |

## Funcao principal

| Linha(s) | Explicacao |
|---|---|
| 980 | Comentario dizendo que o programa comeca na funcao principal. |
| 981 | Inicio da funcao `main`. |
| 983 | Cria a variavel de configuracao. |
| 984 | Cria a variavel que guarda a partida. |
| 985 | Cria a variavel da opcao escolhida. |
| 986 | Cria variavel que mantem o menu rodando. |
| 988 | Inicializa o sorteio aleatorio usando o horario atual. |
| 989 | Carrega configuracao salva ou usa a padrao. |
| 991 | Comeca o laco principal do programa. |
| 993 | Mostra o menu principal. |
| 994 | Le a opcao escolhida. |
| 996-1001 | Opcao 1: cria novo jogo, executa a partida e libera memoria. |
| 1002-1005 | Opcao 2: abre a configuracao do jogo. |
| 1006-1018 | Opcao 3: tenta carregar jogo salvo; se nao houver, mostra aviso. |
| 1019-1022 | Opcao 4: encerra o laco principal. |
| 1023-1026 | Qualquer outra opcao mostra erro. |
| 1027 | Fecha o laco principal. |
| 1029 | Mostra mensagem de encerramento. |
| 1030 | Retorna zero, indicando que o programa terminou corretamente. |
| 1031 | Fecha a funcao `main`. |

