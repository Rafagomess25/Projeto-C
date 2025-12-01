#ifndef IO_H
#define IO_H

#include "board.h"

void exibir_tabuleiro(Board *tabuleiro, int revelar_navios);
void ler_coordenada(int *linha, int *coluna);
int ler_orientacao();

#endif
