#include <stdio.h>
#include <locale.h>
#include "screen.h"
#include "keyboard.h"
#include <string.h>

void preencherFundoEntreBordasComTitle(void);


void screenClear() {
    printf("%s%s", ESC, CLEARSCREEN);
    fflush(stdout);
}




void screenDrawBorders(void) {
    setlocale(LC_ALL, "");
    screenClear();
    screenBoxEnable();           

    screenGotoxy(MINX, MINY);
    putchar(BOX_UPLEFT);

    for (int x = MINX + 1; x < MAXX; x++) {
        screenGotoxy(x, MINY);
        putchar(BOX_HLINE);
    }
    screenGotoxy(MAXX, MINY);
    putchar(BOX_UPRIGHT);

    for (int y = MINY + 1; y < MAXY; y++) {
        screenGotoxy(MINX, y);
        putchar(BOX_VLINE);
        screenGotoxy(MAXX, y);
        putchar(BOX_VLINE);
    }

    screenGotoxy(MINX, MAXY);
    putchar(BOX_DWNLEFT);
    for (int x = MINX + 1; x < MAXX; x++) {
        screenGotoxy(x, MAXY);
        putchar(BOX_HLINE);
    }
    screenGotoxy(MAXX, MAXY);
    putchar(BOX_DWNRIGHT);

    screenBoxDisable();    
    preencherFundoEntreBordasComTitle();
}

void screenInit(int drawBorders) {
    screenClear();
    if (drawBorders) screenDrawBorders();
    screenHomeCursor();
    screenHideCursor();
}

void screenDestroy(void) {
    printf(ESC NORMALTEXT);      
    screenClear();
    screenHomeCursor();
    screenShowCursor();
}

void screenGotoxy(int x, int y) {
    printf("%s[%d;%dH", ESC, y, x);
    fflush(stdout);
}
void screenSetColor(screenColor fg, screenColor bg) {
    char seq[20];
    int bright = 0;
    if (fg > LIGHTGRAY) { bright = 1; fg -= 8; }
    snprintf(seq, sizeof(seq), ESC "[%d;%d;%dm", bright, fg + 30, bg + 40);
    printf("%s", seq);
}

void desenharCharadaAscii() {
    screenClear();

    screenGotoxy(15, 2);
    setTextoVerde();
    printf("⠀               ⢀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 3);
    setTextoVerde();
    printf("⠀⠀⠀⠀  ⠀   ⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣀⠀⠀⠀⠀  ⠀ \n");
    screenGotoxy(15, 4);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀  ⠀⢀⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 5);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀  ⠀⣷⣶⣤⣄⣈⣉⣉⣉⣉⣉⣉⣉⣁⣤⡄⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 6);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 7);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀  ⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 8);
    setTextoVerde();
    printf("⠀⠀⠀⠀  ⠀⠀⢀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 9);
    setTextoVerde();
    printf("⠀⠀   ⢀⣠⣶⣾⡏⢀⡈⠛⠻⠿⢿⣿⣿⣿⣿⣿⠿⠿⠟⠛⢀⠀⢶⣤⣀⠀⠀⠀\n");
    screenGotoxy(15, 10);
    setTextoVerde();
    printf("   ⠀⢠⣿⣿⣿⣿⡇⠸⣿⣿⣶⣶⣤⣤⣤⣤⣤⣤⣤⣶⣶⣿⡿⠂⣸⣿⣿⣷⡄⠀\n");
    screenGotoxy(15, 11);
    setTextoVerde();
    printf("  ⠀ ⢸⣿⣿⣿⣿⣿⣦⣄⡉⠛⠛⠛⠿⠿⠿⠿⠛⠛⠛⢉⣁⣤⣾⣿⣿⣿⣿⡷⠀\n");
    screenGotoxy(15, 12);
    setTextoVerde();
    printf("⠀⠀  ⠙⢿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀\n");
    screenGotoxy(15, 13);
    setTextoVerde();
    printf("⠀⠀⠀  ⠀⠈⠙⠛⠿⠿⢿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠛⠛⠉⠁⠀⠀⠀⠀\n");
    screenGotoxy(15, 14);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣷⡍⠻⢷⠿⢿⠿⢧⣶⣿⣿⣿⣿⣿⣿⣿⣿⣶⣆⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 15);
    setTextoVerde();
    printf("⠀⠀⠀⣀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣆⣰⣶⣆⣀⣾⣿⣿⣿⣿⣿⣿⣿⡿⠿⣥⣾⣿⡀⠀⠀⠀⠀\n");
    screenGotoxy(15, 16);
    setTextoVerde();
    printf("⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠘⠻⣿⣿⣿⣦⡀⠀⠀\n");
    screenGotoxy(15, 17);
    setTextoVerde();
    printf("⠀⠿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠛⠻⣿⣿⣿⣿⣿⣿⣿⣏⣡⣼⣿⣦⣄⠘⢿⣿⣿⣿⣿⡄⠀\n");
    screenGotoxy(15, 18);
    setTextoVerde();
    printf("⠀⣬⣿⣃⢨⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠉⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣼⣿⣿⣿⣿⡷⠀\n");
    screenGotoxy(15, 19);
    setTextoVerde();
    printf("⠀⠹⣿⣽⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿⡿⠛⠉⠉⠙⢿⣿⣿⣿⠁⠀\n");
    screenGotoxy(15, 20);
    setTextoVerde();
    printf("⠀⠀⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣽⣿⣿⣿⣇⠀⠀⠀⠀⢸⣿⣿⣿⠂⠀\n");
    screenGotoxy(15, 21);
    setTextoVerde();
    printf("⠀⠀⢹⣿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢲⣿⣿⣿⣿⣿⣿⣿⣶⠦⠀⣼⣿⣿⣿⣀⡀\n");
    screenGotoxy(15, 22);
    setTextoVerde();
    printf("⠀⢰⣧⣼⣿⣿⣿⠃⠀⢀⣠⡀⠀⠀⠀⠀⠀⠀⣆⢸⣿⣿⣿⣿⣿⠿⣷⣶⣶⡄⠈⣿⣿⣿⣸⣿\n");
    screenGotoxy(15, 23);
    setTextoVerde();
    printf("⠀⠘⣿⣿⡞⣿⡏⠀⠚⠛⠉⠙⣧⡀⠀⠀⠈⣦⣻⣾⣿⣿⣻⣿⢏⡴⠋⠁⠀⠀⠀⣿⣿⣿⣿⡿\n");
    screenGotoxy(15, 24);
    setTextoVerde();
    printf("⠀⠀⠙⢠⣷⢿⣧⠀⠀⢲⣿⣶⣿⣿⣦⡀⢀⣾⣿⣿⣿⣯⣟⣷⣯⣷⣶⣶⣾⣿⣦⣿⡏⣿⡔⠁\n");
    screenGotoxy(15, 25);
    setTextoVerde();
    printf("⠀⠀⢠⡼⣧⠘⡏⠀⠀⠀⠁⢹⣂⣤⣼⡿⢻⡟⠻⣿⣿⣿⣿⣹⠯⠖⣁⣿⣿⣿⠛⢻⢃⣿⠷⠀\n");
    screenGotoxy(15, 26);
    setTextoVerde();
    printf("⠀⠀⠀⢣⡨⠿⠉⠀⠀⠀⠀⣀⣈⠉⠁⠀⠀⠀⠀⢿⡃⢸⣿⣿⣿⣿⣿⣿⠋⠉⠀⠈⠾⠁⠀⠀\n");
    screenGotoxy(15, 27);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⡿⠷⠖⠀⠀⠀⠀⢻⣿⣿⣿⣭⣿⣻⣿⣿⣶⡤⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 28);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣯⣇⠀⠀⠀⠀⣀⠀⠀⢸⣿⠇⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 29);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⢀⠀⠈⠘⣿⣿⣶⣦⣄⣉⠳⠤⣿⣾⣿⣿⣿⠿⣿⡿⢫⡆⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 30);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠸⣿⡄⠈⠙⠛⠟⢿⠿⠏⠛⠉⠀⢠⣿⠁⡾⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 31);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠸⣄⠀⠀⠹⣿⡓⠲⠤⠀⠀⢀⡤⠴⠞⣻⣿⠃⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 32);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠢⠀⠀⠹⣷⣄⡀⡀⣀⢠⢠⣶⣷⡿⠃⠀⢀⢰⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 33);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆⠈⢆⠀⠈⢿⣿⣶⣾⣿⣿⣿⡿⠀⠀⢀⡏⢸⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 34);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣧⠀⠘⣆⠀⢀⡈⣻⣿⣿⣿⣷⣦⡀⠀⣾⠇⣼⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 35);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣆⠀⠘⣆⠀⠙⠛⠛⣻⠿⣿⣿⠇⣼⡟⣲⠋⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 36);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣄⠘⢦⣀⣀⣴⣧⣴⣿⣟⣼⣿⡷⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 37);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⢦⣈⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 38);
    setTextoVerde();
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣟⡛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

    screenGotoxy(15, 39);
    setTextoVerde();
    printf("HAHAHA! RESOLVA MEUS ENIGMAS!");
    screenGotoxy(15, 40);
    setTextoVerde();
    printf("Pressione ENTER para continuar...");
    
    while (readch() != '\n'); 
}

const char *title[] = {
    "      0      0      0      0      0      0      0      0      0      0      0      0      ",
    "      1      1      1      1      0      1      1      1      1      1      1      1      ",
    "      0      1      1      1      1      0      0      1      1      1      1      1      ",
    "      0      0      0      0      0      1      0      0      0      0      0      0      ",
    "      0      1      0      1      0      0      1      1      0      0      1      1      ",
    "      0      1      0      1      0      0      1      1      0      0      1      1      ",
    "      1      1      0      1      0      1      1      0      1      1      0      1      ",
    "      1      1      0      1      0      1      1      0      1      1      0      1      ",
    "      0      0      1      0      0      0      1      0      0      0      1      0      ",
    "      1      0      1      0      1      0      1      0      1      0      1      0      ",
    "      1      0      1      0      1      0      1      0      1      0      1      0      ",
    "      1      1      0      0      1      1      0      0      1      1      0      0      ",
    "      1      1      0      0      1      1      0      0      1      1      0      0      ",
    "      1      1      1      1      1      1      1      1      1      1      1      1      ",
    "      0      0      0      0      0      0      0      0      0      0      0      0      ",
};

void preencherFundoEntreBordasComTitle() {
    setTextoVerde();
    int num_lines = sizeof(title) / sizeof(title[0]);
    int y_idx = 0;
    for (int y = MINY + 1; y < MAXY; y++) {
        const char *linha = title[y_idx % num_lines];
        int len = strlen(linha);
        int x_idx = 0;
        for (int x = MINX + 1; x < MAXX; x++) {
            screenGotoxy(x, y);
            char ch = linha[x_idx % len];
            putchar(ch);
            x_idx++;
        }
        y_idx++;
    }
}



void screenUpdate(void)    { fflush(stdout); }
void screenSetNormal(void) { printf(ESC NORMALTEXT); }
void screenSetBold(void)   { printf(ESC BOLDTEXT); }
void screenSetBlink(void)  { printf(ESC BLINKTEXT); }
void screenSetReverse(void){ printf(ESC REVERSETEXT); }
void screenBoxEnable(void) { printf(ESC BOX_ENABLE); }
void screenBoxDisable(void){ printf(ESC BOX_DISABLE); }
void screenHomeCursor(void){ printf(ESC HOMECURSOR); }
void screenHideCursor(void){ printf(ESC HIDECURSOR); }
void screenShowCursor(void){ printf(ESC SHOWCURSOR); }

void setTextoBranco() {
    printf("\033[1;97m");
}

void setTextoVerde(){
    printf("\033[32m");
}


