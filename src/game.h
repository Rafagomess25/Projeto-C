#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "fleet.h"

int pode_alocar_navio(Board *grade, int comprimento, int linha, int coluna, int orientacao);
void posicionar_navios_auto(Board *grade, Frota *esquadra);
void posicionar_navios_manual(Board *grade, Frota *esquadra);

int disparar_tiro(Board *grade, Frota *esquadra, int linha, int coluna);
int verificar_derrota(Frota *esquadra);

void jogada_cpu(Board *tabuleiro_alvo, Frota *esquadra_alvo);

#endif
