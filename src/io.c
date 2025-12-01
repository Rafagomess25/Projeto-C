#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "game.h"
#include "io.h"

void exibir_tabuleiro(Board *tabuleiro, int revelar_navios) {
    printf("  ");
    for (int coluna = 0; coluna < tabuleiro->colunas; coluna++) {
        printf(" %c", 'A' + coluna);
    }
    printf("\n");

    for (int linha = 0; linha < tabuleiro->linhas; linha++) {
        printf("%2d ", linha + 1);

        for (int coluna = 0; coluna < tabuleiro->colunas; coluna++) {
            Tile *casa = get_cell(tabuleiro, linha, coluna);
            char simbolo = '~';

            switch (casa->status) {
                case CELL_AGUA:
                    simbolo = '~';
                    break;
                case CELL_ACERTO:
                    simbolo = 'X';
                    break;
                case CELL_ERRO:
                    simbolo = '.';
                    break;
                case CELL_NAVIO:
                    simbolo = (revelar_navios ? 'S' : '~');
                    break;
            }

            printf(" %c", simbolo);
        }
        printf("\n");
    }
}

void ler_coordenada(int *linha, int *coluna) {
    char entrada[10];

    printf("Digite coordenada (ex.: A5): ");
    scanf("%9s", entrada);

    char letra_coluna = toupper(entrada[0]);
    *coluna = letra_coluna - 'A';

    int numero_linha = atoi(&entrada[1]);
    *linha = numero_linha - 1;
}

int ler_orientacao() {
    char entrada[10];

    while (1) {
        printf("Orientacao (H = Horizontal, V = Vertical): ");
        scanf("%9s", entrada);

        char c = toupper(entrada[0]);
        if (c == 'H') return ORIENT_H;
        if (c == 'V') return ORIENT_V;

        printf("Opcao invalida! Tente H ou V.\n");
    }
}
