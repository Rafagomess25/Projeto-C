#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "board.h"
#include "fleet.h"
#include "rnd.h"
#include "io.h"

int pode_alocar_navio(Board *grade, int comprimento, int linha, int coluna, int orientacao) {
    if (orientacao == ORIENT_H) {
        if (coluna + comprimento > grade->colunas) return 0;
    } else {
        if (linha + comprimento > grade->linhas) return 0;
    }

    for (int desloc = 0; desloc < comprimento; desloc++) {
        int linha_atual  = linha  + (orientacao == ORIENT_V ? desloc : 0);
        int coluna_atual = coluna + (orientacao == ORIENT_H ? desloc : 0);

        Tile *casa = get_cell(grade, linha_atual, coluna_atual);
        if (casa->status != CELL_AGUA) {
            return 0;
        }
    }

    return 1;
}

void posicionar_navios_auto(Board *grade, Frota *esquadra) {
    for (int i = 0; i < esquadra->quantidade; i++) {
        Navio *navio = &esquadra->navios[i];
        int alocado = 0;

        while (!alocado) {
            int linha_sorteada  = sorteio_intervalo(grade->linhas);
            int coluna_sorteada = sorteio_intervalo(grade->colunas);
            int orientacao      = sorteio_intervalo(2); /* 0 = H, 1 = V */

            if (pode_alocar_navio(grade, navio->tamanho,
                                  linha_sorteada, coluna_sorteada,
                                  orientacao)) {

                for (int k = 0; k < navio->tamanho; k++) {
                    int linha_navio  = linha_sorteada  + (orientacao == ORIENT_V ? k : 0);
                    int coluna_navio = coluna_sorteada + (orientacao == ORIENT_H ? k : 0);

                    Tile *casa = get_cell(grade, linha_navio, coluna_navio);
                    casa->status  = CELL_NAVIO;
                    casa->id_navio = i;
                }

                navio->linha_inicial  = linha_sorteada;
                navio->coluna_inicial = coluna_sorteada;
                navio->orientacao     = orientacao;
                navio->ativo          = 1;
                alocado = 1;
            }
        }
    }
}

void posicionar_navios_manual(Board *grade, Frota *esquadra) {
    printf("\n--- MODO DE POSICIONAMENTO MANUAL ---\n");

    for (int i = 0; i < esquadra->quantidade; i++) {
        Navio *navio = &esquadra->navios[i];
        int alocado = 0;

        while (!alocado) {
            printf("\nPosicionando: %s (Tamanho: %d)\n", navio->nome, navio->tamanho);
            exibir_tabuleiro(grade, 1);

            int linha, coluna;
            ler_coordenada(&linha, &coluna);
            int orientacao = ler_orientacao();

            if (pode_alocar_navio(grade, navio->tamanho, linha, coluna, orientacao)) {
                for (int k = 0; k < navio->tamanho; k++) {
                    int linha_navio  = linha  + (orientacao == ORIENT_V ? k : 0);
                    int coluna_navio = coluna + (orientacao == ORIENT_H ? k : 0);

                    Tile *casa = get_cell(grade, linha_navio, coluna_navio);
                    casa->status  = CELL_NAVIO;
                    casa->id_navio = i;
                }

                navio->linha_inicial  = linha;
                navio->coluna_inicial = coluna;
                navio->orientacao     = orientacao;
                navio->ativo          = 1;
                alocado = 1;

                printf("Navio posicionado!\n");
            } else {
                printf(">>> ERRO: Posicao invalida ou ocupada! Tente novamente.\n");
            }
        }
    }
}

int disparar_tiro(Board *grade, Frota *esquadra, int linha, int coluna) {
    if (linha  < 0 || linha  >= grade->linhas ||
        coluna < 0 || coluna >= grade->colunas) {
        return -1;
    }

    Tile *alvo = get_cell(grade, linha, coluna);

    if (alvo->status == CELL_ACERTO || alvo->status == CELL_ERRO) {
        return -1;
    }

    if (alvo->status == CELL_AGUA) {
        alvo->status = CELL_ERRO;
        return 0;
    }

    if (alvo->status == CELL_NAVIO) {
        alvo->status = CELL_ACERTO;
        int id = alvo->id_navio;
        if (id >= 0) {
            esquadra->navios[id].dano_sofrido++;
        }
        return 1;
    }

    return 0;
}

int verificar_derrota(Frota *esquadra) {
    for (int i = 0; i < esquadra->quantidade; i++) {
        if (esquadra->navios[i].dano_sofrido < esquadra->navios[i].tamanho) {
            return 0;
        }
    }
    return 1;
}

void jogada_cpu(Board *tabuleiro_alvo, Frota *esquadra_alvo) {
    int jogada_valida = 0;

    printf("\n[Computador esta pensando...]\n");

    while (!jogada_valida) {
        int linha_tiro  = sorteio_intervalo(tabuleiro_alvo->linhas);
        int coluna_tiro = sorteio_intervalo(tabuleiro_alvo->colunas);

        int resultado = disparar_tiro(tabuleiro_alvo, esquadra_alvo,
                                      linha_tiro, coluna_tiro);

        if (resultado != -1) {
            jogada_valida = 1;

            printf(">>> Computador atirou em %c%d: ",
                   'A' + coluna_tiro, linha_tiro + 1);

            if (resultado == 1) {
                printf("ACERTOU O TEU NAVIO! <<<\n");
            } else {
                printf("AGUA. <<<\n");
            }
        }
    }
}
