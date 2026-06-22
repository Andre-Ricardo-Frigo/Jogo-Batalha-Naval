# Batalha Naval em C

Trabalho academico desenvolvido apenas com conteudos de Algoritmos 2:

- funcoes e procedimentos;
- registros (`struct`);
- ponteiros;
- matriz dinamica;
- arquivo binario;
- uma funcao recursiva para contar navios restantes.

## Compilar

```sh
make
```

## Executar

```sh
./batalha
```

## Valores usados nos campos

- `0`: agua no campo proprio;
- `1`: navio no campo proprio;
- `2`: parte de navio atingida no campo proprio;
- `3`: agua encontrada no campo adversario;
- `4`: impacto no campo adversario;
- `5`: navio afundado no campo adversario;
- `7`: agua desconhecida no campo adversario.

Durante o turno humano, digite primeiro a linha e depois a coluna do bombardeio.
Tambem e possivel digitar `-1` na linha para salvar e voltar ao menu ou `0` na linha para voltar ao menu sem salvar.
