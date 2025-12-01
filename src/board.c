#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void init_board(Board *tabuleiro, int linhas, int colunas) {
    tabuleiro->linhas  = linhas;
    tabuleiro->colunas = colunas;

    int total_casas = linhas * colunas;

    tabuleiro->grade = (Tile *)malloc(total_casas * sizeof(Tile));
    if (tabuleiro->grade == NULL) {
        printf("\nErro de memoria ao criar tabuleiro\n");
        exit(1);
    }

    for (int i = 0; i < total_casas; i++) {
        tabuleiro->grade[i].status  = CELL_AGUA;
        tabuleiro->grade[i].id_navio = -1;
    }
}

void free_board(Board *tabuleiro) {
    if (tabuleiro->grade != NULL) {
        free(tabuleiro->grade);
        tabuleiro->grade = NULL;
    }
}

Tile *get_cell(Board *tabuleiro, int linha, int coluna) {
    if (linha  < 0 || linha  >= tabuleiro->linhas ||
        coluna < 0 || coluna >= tabuleiro->colunas) {
        return NULL;
        }

    int indice = (linha * tabuleiro->colunas) + coluna;
    return &tabuleiro->grade[indice];
}
