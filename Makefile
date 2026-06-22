CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o jogo.o matriz.o arquivo.o

all: batalha

batalha: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o batalha

main.o: main.c batalha.h
	$(CC) $(CFLAGS) -c main.c

jogo.o: jogo.c batalha.h
	$(CC) $(CFLAGS) -c jogo.c

matriz.o: matriz.c batalha.h
	$(CC) $(CFLAGS) -c matriz.c

arquivo.o: arquivo.c batalha.h
	$(CC) $(CFLAGS) -c arquivo.c

clean:
	rm -f $(OBJ) batalha batalha_naval.bin
