#ifndef FLEET_H
#define FLEET_H

typedef enum {
    ORIENT_H,
    ORIENT_V
} Orientation;

typedef struct {
    char nome[20];
    int tamanho;
    int dano_sofrido;
    int ativo;
    int linha_inicial;
    int coluna_inicial;
    Orientation orientacao;
} Navio;

typedef struct {
    Navio *navios;
    int quantidade;
} Frota;

void init_fleet(Frota *frota);
void free_fleet(Frota *frota);

#endif
