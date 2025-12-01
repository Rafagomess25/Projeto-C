#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fleet.h"

void init_fleet(Frota *frota) {
    frota->quantidade = 6;
    frota->navios = (Navio *)malloc(frota->quantidade * sizeof(Navio));
    if (frota->navios == NULL) {
        printf("\nErro de memoria ao criar frota\n");
        exit(1);
    }

    // Porta-avioes
    strcpy(frota->navios[0].nome, "Porta-Avioes");
    frota->navios[0].tamanho       = 5;
    frota->navios[0].dano_sofrido  = 0;
    frota->navios[0].ativo         = 0;

    // Encouracado
    strcpy(frota->navios[1].nome, "Encouracado");
    frota->navios[1].tamanho       = 4;
    frota->navios[1].dano_sofrido  = 0;
    frota->navios[1].ativo         = 0;

    // Cruzadores
    strcpy(frota->navios[2].nome, "Cruzador");
    frota->navios[2].tamanho       = 3;
    frota->navios[2].dano_sofrido  = 0;
    frota->navios[2].ativo         = 0;

    strcpy(frota->navios[3].nome, "Cruzador");
    frota->navios[3].tamanho       = 3;
    frota->navios[3].dano_sofrido  = 0;
    frota->navios[3].ativo         = 0;

    // Destroyers
    strcpy(frota->navios[4].nome, "Destroyer");
    frota->navios[4].tamanho       = 2;
    frota->navios[4].dano_sofrido  = 0;
    frota->navios[4].ativo         = 0;

    strcpy(frota->navios[5].nome, "Destroyer");
    frota->navios[5].tamanho       = 2;
    frota->navios[5].dano_sofrido  = 0;
    frota->navios[5].ativo         = 0;
}

void free_fleet(Frota *frota) {
    if (frota->navios != NULL) {
        free(frota->navios);
        frota->navios = NULL;
    }
}
