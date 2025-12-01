#include <stdlib.h>
#include <time.h>
#include "rnd.h"

void inicializar_aleatorio(void) {
    srand((unsigned int)time(NULL));
}

int sorteio_intervalo(int limite) {
    return rand() % limite;
}
