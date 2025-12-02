# Projeto C — Game
📋 Descrição

[Descrição breve do jogo e objetivo do jogador. Ex: "Um jogo de dungeon crawler onde o jogador enfrenta inimigos, coleta itens e tenta chegar ao fim da masmorra."]
🎮 Como Jogar

    Compile o projeto (ver seção Build)

    Execute: ./game (Linux/macOS) ou game.exe (Windows)

    Siga as instruções no menu

Controles: [Explique como o jogador interage, ex: "Digite números para escolher ações do menu"]
🔨 Build
Pré-requisitos

    Compilador GCC ou Clang

    Make (opcional, mas recomendado)

    Sistema operacional: Linux, macOS ou Windows (com MinGW/WSL)

Compilação com Makefile

bash
make          # Compila o projeto
make run      # Compila e executa
make clean    # Remove arquivos compilados

Compilação Manual

bash
gcc -o game src/*.c -Iinclude
./game

📂 Estrutura do Projeto

Projeto-C/<br>
├── src/ <br>
│   ├── main.c          # Ponto de entrada <br>
│   ├── game.c          # Lógica do jogo<br>
│   ├── player.c        # Funções do jogador<br>
│   └── [outros_modulos].c<br>
├── include/<br>
│   ├── game.h<br>
│   ├── player.h<br>
│   └── [outros_headers].h<br>
├── README.md<br>
└── [Relatório_Técnico].pdf<br>
