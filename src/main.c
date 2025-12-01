#include <stdlib.h>
#include <stdio.h>    
#include <time.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "jogo.h"

int main() {

    screenInit(1);
    keyboardInit();
    
    int ch;
    while(1) {
        printf("\033[32m");
        screenClear();
        screenGotoxy(1, 1);
        printf("=== CODE RIDDLER ===");
        screenGotoxy(1, 3);
        setTextoBranco();
        printf("1. Iniciar Jogo");
        screenGotoxy(1, 4);
        setTextoBranco();
        printf("2. Ver Ranking");
        screenGotoxy(1, 5);
        setTextoBranco();
        printf("3. Sair");
        screenGotoxy(1, 7);
        setTextoVerde();
        printf("Escolha uma opção: ");
        fflush(stdout);

        while(!keyhit());
        ch = readch();
        
        
        switch(ch) {
            case '1':
                executarJogo();
                break;
            case '2':
                mostrarRanking();
                break;
            case '3':
                keyboardDestroy();
                screenDestroy();
                return 0;
        }
    }
}