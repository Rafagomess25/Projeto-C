#ifndef BOARD_H
#define BOARD_H

typedef enum {
    CELL_AGUA,
    CELL_NAVIO,
    CELL_ACERTO,
    CELL_ERRO
} CellState;

typedef struct {
    CellState status;
    int id_navio;
} Tile;

typedef struct {
    int linhas;
    int colunas;
    Tile *grade;
} Board;

void init_board(Board *tabuleiro, int linhas, int colunas);

void free_board(Board *tabuleiro);

Tile *get_cell(Board *tabuleiro, int linha, int coluna);

#endif
