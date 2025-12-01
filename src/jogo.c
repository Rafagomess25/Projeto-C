#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "jogo.h"
#include "screen.h"
#include "keyboard.h"

#define MAX_JOGADORES 10
Jogador ranking[MAX_JOGADORES];
int numJogadores = 0;

int ehPrimo(int n) {
    if (n <= 1) return 0;   
    for (int i = 2; i * i <= n; i++)   
        if (n % i == 0)  
            return 0;   
    return 1;   
}

int gerarNumero(int limite) {
    return rand() % (limite + 1);
}

int mostrarDicas(int fase, int numero) {
    int linhas = 1;
    setTextoBranco();
    printf("🧠 Charadas do Enigma:\n");
  
    switch(fase) {
        case 1:
            if (numero % 2 == 0) {
                setTextoBranco();
                printf("- \"Sou par, mas não parente. Se me dividir, não fico descontente. Quem sou eu?\"\n");
                linhas++;
            } else {
                setTextoBranco();
                printf("- \"Não sou par, não sou quadrado. Quando me contam, fico isolado. Quem sou eu?\"\n");
                linhas++;
            }
            if (numero > 5) {
                setTextoBranco();
                printf("- \"Se cinco é metade do meu caminho, que estrada longa estou eu seguindo?\"\n");
                linhas++;
            } else {
                setTextoBranco();
                printf("- \"Me abaixo ao cinco e sigo com orgulho. Estou antes da metade, sou filho do barulho.\"\n");
                linhas++;
            }
            if (numero == 0) {
                setTextoBranco();
                printf("- \"Sou o início de tudo e de tudo o fim. Não tenho valor, mas sou o maior no fim. Quem sou eu?\"\n");
                linhas++;
            }
            if (numero % 3 == 0) {
                setTextoBranco();
                printf("- \"Três é minha dança, e múltiplos são meu par. Se me dividir por ele, vai se espantar.\"\n");
                linhas++;
            }
            if (numero == 7) {
                setTextoBranco();
                printf("- \"Dizem que sou da sorte, mas vivo escondido. Me ache entre o dez e o perdido.\"\n");
                linhas++;
            }
            if (numero == 9) {
                setTextoBranco();
                printf("- \"Quase o fim, quase o dez, mas não o suficiente para ser vez.\"\n");
                linhas++;
            }
            break;

        case 2:
            if (numero % 2 == 0) {
                setTextoBranco();
                printf("- \"Sou par como dois irmãos em harmonia. Me dividem e ainda sou simetria.\"\n");
                linhas++;
            } else {
                setTextoBranco();
                printf("- \"Sou ímpar, caminho só. Nunca ando em dupla, sou um nó.\"\n");
                linhas++;
            }
            if (numero < 10) {
                setTextoBranco();
                printf("- \"Sou pequeno, mas não despreze. Entre gigantes, ainda me ergue.\"\n");
                linhas++;
            } else if (numero < 25) {
                setTextoBranco();
                printf("- \"Estou na juventude dos números, nem velho nem novo. Quem olha, vê um ovo.\"\n");
                linhas++;
            } else if (numero < 40) {
                setTextoBranco();
                printf("- \"Já passei da metade da estrada, mas o fim ainda me escapa.\"\n");
                linhas++;
            } else {
                setTextoBranco();
                printf("- \"Sou veterano entre os 50. Estou no topo, olhando os fracos do alto.\"\n");
                linhas++;
            }
            if (numero % 5 == 0) {
                setTextoBranco();
                printf("- \"O cinco é meu mestre, sigo seus passos. Divida-me por ele e verá meus traços.\"\n");
                linhas++;
            }
            if (numero % 10 == 0) {
                setTextoBranco();
                printf("- \"Redondo como a lua cheia, sou filho da perfeição decimal.\"\n");
                linhas++;
            }
            if (numero == 0) {
                setTextoBranco();
                printf("- \"Do nada eu vim, ao nada eu vou. Não valho nada, mas abro o show.\"\n");
                linhas++;
            }
            if (numero == 25) {
                setTextoBranco();
                printf("- \"Sou o meio do caminho, o centro do destino. Nem menos nem mais, sou o vizinho.\"\n");
                linhas++;
            }
            if (numero == 49) {
                setTextoBranco();
                printf("- \"Sou quase o rei dos cinquenta, mas parei um passo antes da coroa.\"\n");
                linhas++;
            }
            if (numero % 7 == 0) {
                setTextoBranco();
                printf("- \"O sete é mágico, dizem por aí. Multiplique e logo vai me descobrir.\"\n");
                linhas++;
            }
            break;
   
        case 3:
             if (numero % 2 == 0) {
                setTextoBranco();
                printf("- \"Sou par, ando com par, somos dois em toda parte. Me divida, e não vou reclamar.\"\n");
            } else {
                setTextoBranco();
                printf("- \"Sou ímpar e solitário, não me encaixo nem no par mais solidário.\"\n");
            }

  
            if (numero < 25) {
                setTextoBranco();
                printf("- \"Ainda sou jovem, mal saí do berço. Mas cuidado, pequenos também têm peso.\"\n");
                linhas++;
            } else if (numero < 50) {
                setTextoBranco();
                printf("- \"Estou na subida, quase metade. Mas não cheguei no cume da verdade.\"\n");
                linhas++;
            } else if (numero == 50) {
                setTextoBranco();
                printf("- \"Sou o meio exato da centena. Nem rico, nem pobre. Apenas equilibrado.\"\n");
                linhas++;
            } else if (numero < 75) {
                setTextoBranco();
                printf("- \"Já passei da metade, olho para trás. Mas o fim ainda está por um triz.\"\n");
                linhas++;
            } else {
                setTextoBranco();
                printf("- \"Sou veterano entre os números. Me aproximo do fim com passos firmes.\"\n");
                linhas++;
            }

     
            if (numero % 3 == 0) {
                setTextoBranco();
                printf("- \"Três é meu guia, minha divisão. Se tentar me cortar, faça essa equação.\"\n");
                linhas++;
            }

            if (numero % 5 == 0) {
                setTextoBranco();
                printf("- \"Cinco me comanda como um rei. Se me dividir por ele, diga ‘amém’.\"\n");
                linhas++;
            }

            if (numero % 10 == 0) {
                setTextoBranco();
                printf("- \"Sou redondo como a roda, e minha conta fecha sem sobra.\"\n");
                linhas++;
            }

            if (numero % 7 == 0) {
                setTextoBranco();
                printf("- \"Sete é místico, e eu também. Tente me encontrar se puder, meu bem.\"\n");
                linhas++;
            }

            if (numero % 11 == 0) {
                setTextoBranco();
                printf("- \"Dobro de mim é sempre par. Sou reflexo, espelho, singular.\"\n");
                linhas++;
            }

            if (numero == 0) {
                setTextoBranco();
                printf("- \"Sou o silêncio da matemática. O nada que tudo começa. Quem sou eu?\"\n");
                linhas++;
            }

            if (numero == 1) {
                setTextoBranco();
                printf("- \"Não sou par nem múltiplo. Apenas o primeiro a pisar nesse solo.\"\n");
                linhas++;
            }

            if (numero == 100) {
                setTextoBranco();
                printf("- \"Sou o ápice da escala, o fim da linha. Quem me alcança, já domina.\"\n");
                linhas++;
            }

            if (numero == 42) {
                setTextoBranco();
                printf("- \"Dizem que sou a resposta para tudo, mas ninguém entende a pergunta.\"\n");
                linhas++;
            }

            break;
           
        case 4:
           
            if (numero % 2 == 0) {
                setTextoBranco();
                printf("- \"Tenho par no nome, par no andar. Me divida sem medo, não vou reclamar.\"\n");
                linhas++;
            } else {
                setTextoBranco();
                printf("- \"Sigo só, passo ímpar. Nunca me encaixo, sou singular.\"\n");
                linhas++;
            }

            
            if (numero < 30) {
                setTextoBranco();
                printf("- \"Sou da primeira infância numérica. Mal comecei, já querem me adivinhar.\"\n");
                linhas++;
            } else if (numero < 60) {
                setTextoBranco();
                printf("- \"Avancei um terço da corrida, mas ainda não vejo a linha de chegada.\"\n");
                linhas++;
            } else if (numero < 90) {
                setTextoBranco();
                printf("- \"Sou maduro, sou firme. Já vivi mais da metade da jornada.\"\n");
                linhas++;
            } else if (numero < 120) {
                setTextoBranco();
                printf("- \"Os ventos do fim começam a soprar. Já vejo os três dígitos no ar.\"\n");
                linhas++;
            } else {
                setTextoBranco();
                printf("- \"Estou entre os gigantes. Poucos chegam tão alto quanto eu.\"\n");
                linhas++;
            }

         
            if (numero % 3 == 0) {
                setTextoBranco();
                printf("- \"O três me guia, me divide com arte. Descubra meu segredo, seja parte.\"\n");
                linhas++;
            }

            if (numero % 5 == 0) {
                setTextoBranco();
                printf("- \"Cinco é minha base, sou redondo em sua dança. Se me seguir, terá esperança.\"\n");
                linhas++;
            }

            if (numero % 10 == 0) {
                setTextoBranco();
                printf("- \"Fecho bem a conta, com final tranquilo. Sou múltiplo de dez, bem estilo.\"\n");
                linhas++;
            }

            if (numero % 6 == 0) {
                setTextoBranco();
                printf("- \"Sou amigo do par e do três também. Se me dividir por seis, tudo vai bem.\"\n");
                linhas++;
            }

            if (numero % 7 == 0) {
                setTextoBranco();
                printf("- \"Sou sete vezes mistério. Se me achares, és digno de império.\"\n");
                linhas++;
            }

            if (numero % 9 == 0) {
                setTextoBranco();
                printf("- \"Multiplicado por nove, danço redondo. Mas divida com calma, senão afundo.\"\n");
                linhas++;
            }

            if (numero % 13 == 0) {
                setTextoBranco();
                printf("- \"Azar ou sorte? Você decide. Sou filho do treze, e isso me divide.\"\n");
                linhas++;
            }

            
            if (numero == 0) {
                setTextoBranco();
                printf("- \"Sou o ponto de partida. Não peso nada, mas inicio tudo. Quem sou eu?\"\n");
                linhas++;
            }

            if (numero == 1) {
                setTextoBranco();
                printf("- \"Sou o primeiro, o original. Sem mim, nenhum outro faz sentido.\"\n");
                linhas++;
            }

            if (numero == 50) {
                setTextoBranco();
                printf("- \"Sou metade de cem, mas estou num jogo maior. Me veja como referência, não como o fim.\"\n");
                linhas++;
            }

            if (numero == 75) {
                setTextoBranco();
                printf("- \"Três quartos do centenário. Estou quase lá, mas não cheguei.\"\n");
                linhas++;
            }

            if (numero == 100) {
                setTextoBranco();
                printf("- \"O clássico centenário. Todos me respeitam, mesmo quem é mais alto.\"\n");
                linhas++;
            }

            if (numero == 150) {
                setTextoBranco();
                printf("- \"Sou o fim da linha. O topo da escada. Se me acertar, não há mais nada.\"\n");
                linhas++;
            }

            if (numero == 42) {
                setTextoBranco();
                printf("- \"Sou a resposta para tudo, ou pelo menos assim dizem. A pergunta? Mistério.\"\n");
                linhas++;
            }

            break;

        case 5:
            if (numero % 2 == 0) {
                printf("- \"Sou par, sou calmo, sigo com razão. Me divida por dois, sem hesitação.\"\n");
                linhas++;
            } else {
                printf("- \"Ímpar sou, e sempre serei. Nunca me dobro, nunca vacilei.\"\n");
                linhas++;
            }
            if (numero < 50) {
                printf("- \"Sou criança numérica, mal comecei. Mas até os pequenos já desafiei.\"\n");
                linhas++;
            } else if (numero < 100) {
                printf("- \"Estou no primeiro terço, firme como um rochedo. Já sei quem sou, sem medo.\"\n");
                linhas++;
            } else if (numero < 150) {
                printf("- \"Me escondo no meio do caminho. Ainda há muito chão, mas já vejo vizinho.\"\n");
                linhas++;
            } else if (numero < 200) {
                printf("- \"Já passei da metade, e isso é fato. Mas o fim ainda é um boato.\"\n");
                linhas++;
            } else if (numero < 250) {
                printf("- \"Sou veterano da contagem. Meus dias jovens? Apenas lembragem.\"\n");
                linhas++;
            } else {
                printf("- \"Cheguei no cume da colina. Agora é só descer... se encontrar a mina.\"\n");
                linhas++;
            }
            if (numero % 3 == 0) {
                printf("- \"Sou da escola dos triplos, meu passo é curto, mas certo. Me ache com lógica e afeto.\"\n");
                linhas++;
            }
            if (numero % 4 == 0) {
                setTextoBranco();
                printf("- \"Me dividem em quatro partes iguais. E ainda assim, continuo demais.\"\n");
                linhas++;
            }
            if (numero % 5 == 0) {
                setTextoBranco();
                printf("- \"O cinco me molda como um molde. Redondo fico, como ouro nobre.\"\n");
                linhas++;
            }
            if (numero % 6 == 0) {
                setTextoBranco();
                printf("- \"Sou par com um toque de três. Um casamento que ninguém desfez.\"\n");
                linhas++;
            }
            if (numero % 7 == 0) {
                setTextoBranco();
                printf("- \"Sete é o mágico divisor. Se me encontrar com ele, me verá com fervor.\"\n");
                linhas++;
            }
            if (numero % 9 == 0) {
                setTextoBranco();
                printf("- \"O nove me conhece bem. Multiplica e me mantém.\"\n");
                linhas++;
            }
            if (numero % 10 == 0) {
                setTextoBranco();
                printf("- \"Fecho contas com perfeição. Dez é meu irmão.\"\n");
                linhas++;
            }
            if (numero % 12 == 0) {
                setTextoBranco();
                printf("- \"Sou doze vezes melhor. Ou apenas dividido com ardor.\"\n");
                linhas++;
            }
            if (numero % 15 == 0) {
                setTextoBranco();
                printf("- \"Me acha nos quartos de quinze. Mas cuidado: quem erra, se extingue.\"\n");
                linhas++;
            }
            if (numero % 25 == 0) {
                setTextoBranco();
                printf("- \"Meus múltiplos são moedas. Cada vinte e cinco vale ideias.\"\n");
                linhas++;
            }
            if (numero == 0) {
                setTextoBranco();
                printf("- \"Sou o vazio e o começo. Nada sou, mas tudo apreço.\"\n");
                linhas++;
            }
            if (numero == 1) {
                setTextoBranco();
                printf("- \"O início, o singular, o primeiro passo pra tudo formar.\"\n");
                linhas++;
            }
            if (numero == 50) {
                setTextoBranco();
                printf("- \"Meio de cem, mas longe do fim. Ainda ando, mesmo sem jardim.\"\n");
                linhas++;
            }
            if (numero == 100) {
                setTextoBranco();
                printf("- \"Aclamado por todos, centenário sou. Se me errar, o jogo voou.\"\n");
                linhas++;
            }
            if (numero == 150) {
                setTextoBranco();
                printf("- \"Sou o ponto médio da sua nova missão. Nem baixo, nem alto — só precisão.\"\n");
                linhas++;
            }
            if (numero == 200) {
                setTextoBranco();
                printf("- \"Dois cem em um. Tão longe do começo, tão perto do bum.\"\n");
                linhas++;
            }
            if (numero == 250) {
                setTextoBranco();
                printf("- \"Um quarto pra acabar. Já ouvi dizerem que é o lugar pra parar.\"\n");
                linhas++;
            }
            if (numero == 300) {
                setTextoBranco();
                printf("- \"Sou o limite final. O Charada espera... com seu sorriso fatal.\"\n");
                linhas++;
            }
            if (numero == 42) {
                setTextoBranco();
                printf("- \"Sou a resposta de tudo no universo. Mas ninguém entende meu verso.\"\n");
                linhas++;
            }
            break;
    }
    return linhas;
}

int lerNumero() {
    int numero = 0;
    char ch;

    while (1) {
        ch = readch();

        if (ch == '\n') break;
        if (isdigit(ch)) {
            numero = numero * 10 + (ch - '0');
            printf("%c", ch);
        }
    }
    return numero;
}

int fazerPerguntaLogica() {
    int resposta;
    char ch;  
    
    screenClear();
    screenGotoxy(20, 5);
    setTextoBranco();
    printf("=== PERGUNTA DE LÓGICA ===");
    
    screenGotoxy(10, 7);
    setTextoBranco();
    printf("Considere a seguinte charada:");
    screenGotoxy(10, 8);
    setTextoBranco();
    printf("\"Se o Cavaleiro das Trevas decifrar minha pista enigmática,");
    screenGotoxy(10, 9);
    setTextoBranco();
    printf("então o jogo termina com a minha captura.\"");
    screenGotoxy(10, 11);
    setTextoBranco();
    printf("Qual é o valor lógico desta proposição?");
    screenGotoxy(10, 12);
    setTextoBranco();
    printf("1. Verdadeiro");
    screenGotoxy(10, 13);
    setTextoBranco();
    printf("2. Falso");
    screenGotoxy(10, 14);
    setTextoBranco();
    printf("3. Indeterminado");
    
    screenGotoxy(10, 15);
    setTextoBranco();
    printf("Sua resposta (1-3): ");
    
    while (1) {
        ch = readch();
        if (ch >= '1' && ch <= '3') {
            resposta = ch - '0';
            printf("%c", ch);
            break;
        }
    }
    
    return (resposta == 1); 
}

void jogarFase(Jogo *jogo) {
    int chute;
    jogo->tentativasUsadas = 0;
    jogo->acertou = 0;

    screenClear();
    screenInit(1);

    screenGotoxy(28, 2);
    setTextoBranco();
    switch (jogo->fase) {
        
        case 1: printf("=== Fase 1 (0-10) ==="); break;
        case 2: printf("=== Fase 2 (0-50) ==="); break;
        case 3: printf("=== Fase 3 (0-100) ==="); break;
        case 4: printf("=== Fase 4 (0-150) ==="); break;
        case 5: printf("=== Fase 5 (0-300) ==="); break;
        default: printf("=== Fase %d ===", jogo->fase);
    }

    screenGotoxy(10, 4);
    int linhasDicas = mostrarDicas(jogo->fase, jogo->numeroSecreto);

    
    int linhaTentativa = 4 + linhasDicas + 2;

    for (int i = 1; i <= jogo->tentativas; i++) {
        screenGotoxy(20, linhaTentativa + (i - 1) * 4);
        setTextoBranco();
        printf("Tentativa %d de %d: ", i, jogo->tentativas);

        chute = lerNumero();
        jogo->tentativasUsadas++;

        if (chute == jogo->numeroSecreto) {
            screenGotoxy(20, linhaTentativa + 5 + (i - 1) * 4);
            setTextoBranco();
            printf("!! Parabéns! Você acertou o número %d !!", jogo->numeroSecreto);
            jogo->acertou = 1;
            return;
        }

        screenGotoxy(20, linhaTentativa + 1 + (i - 1) * 4);
        setTextoBranco();
        printf("Tente outra vez!");
        screenGotoxy(20, linhaTentativa + 2 + (i - 1) * 4);
        setTextoBranco();
        if (chute < jogo->numeroSecreto) {
            setTextoBranco();
            printf("O número secreto é maior!");
        } else {
            setTextoBranco();
            printf("O número secreto é menor!");
        }
    }
}

void jogarFaseComPergunta(Jogo *jogo) {
    jogarFase(jogo);
    
    if (!jogo->acertou) {
        screenGotoxy(20, 15 + jogo->tentativas * 4);
        setTextoBranco();
        printf("Suas tentativas acabaram! Mas há uma chance...");
        
        if (fazerPerguntaLogica()) {
            screenGotoxy(20, 17 + jogo->tentativas * 4);
            setTextoBranco();
            printf("Resposta correta! Você ganhou mais 3 tentativas!");
            
            jogo->tentativas += 3;
            jogarFase(jogo);
        } else {
            screenGotoxy(20, 17 + jogo->tentativas * 4);
            setTextoBranco();
            printf("Resposta errada! Fim de jogo.");
        }
    }
}

void adicionarAoRanking(char *nome, int tentativas) {
    if (numJogadores < MAX_JOGADORES) {
        strcpy(ranking[numJogadores].nome, nome);
        ranking[numJogadores].tentativasTotais = tentativas;
        numJogadores++;
        
      
        for (int i = 0; i < numJogadores - 1; i++) {
            for (int j = 0; j < numJogadores - i - 1; j++) {
                if (ranking[j].tentativasTotais > ranking[j+1].tentativasTotais) {
                    Jogador temp = ranking[j];
                    ranking[j] = ranking[j+1];
                    ranking[j+1] = temp;
                }
            }
        }
    }
}

void mostrarRanking() {
    screenClear();
    screenInit(1);
    screenGotoxy(28, 2);
    setTextoBranco();
    printf("=== RANKING DOS JOGADORES ===");
    
    for (int i = 0; i < numJogadores; i++) {
        screenGotoxy(20, 5 + i);
        printf("%d. %s - %d tentativas", i+1, ranking[i].nome, ranking[i].tentativasTotais);
    }
    
    screenGotoxy(20, 7 + numJogadores);
    setTextoBranco();
    printf("Pressione ENTER para continuar...");
    while (readch() != '\n');
}

void feedbackCharadaFase(int fase) {
    screenClear();
    screenInit(1);
    screenGotoxy(15, 10);
    printf("\033[32m");
    setTextoBranco();
    printf("HAHAHA! VOCÊ PASSOU DA FASE %d!", fase);
    screenGotoxy(15, 12);
    setTextoBranco();
    printf("Mas não pense que será tão fácil nas próximas...");
    screenGotoxy(15, 14);
    setTextoBranco();
    printf("Pressione ENTER para continuar...");
    while (readch() != '\n');
}

void executarJogo() {
    desenharCharadaAscii();


    srand(time(NULL));
    char nome[50];
    int tentativasTotais = 0;
    
    screenClear();
    screenInit(1);
    screenGotoxy(25, 5);
    setTextoBranco();
    printf("Digite seu nome: ");
    
    
    int i = 0;
    char ch;
    while ((ch = readch()) != '\n' && i < 49) {
        nome[i++] = ch;
        printf("%c", ch);
    }
    nome[i] = '\0';
    

    Jogo fase1 = {1, gerarNumero(10), 5, 0, 0};
    jogarFase(&fase1);
    tentativasTotais += fase1.tentativasUsadas;

    if (!fase1.acertou) {
        screenGotoxy(20, 20);
        setTextoBranco();
        printf("Fim de jogo! Você não completou a fase 1.");
        return;
    }
    feedbackCharadaFase(1);

  
    Jogo fase2 = {2, gerarNumero(50), 5, 0, 0};
    jogarFase(&fase2);
    tentativasTotais += fase2.tentativasUsadas;

    if (!fase2.acertou) {
        screenGotoxy(20, 20);
        setTextoBranco();
        printf("Fim de jogo! Você não completou a fase 2.");
        return;
    }
    feedbackCharadaFase(2);

  
    Jogo fase3 = {3, gerarNumero(100), 5, 0, 0};
    jogarFaseComPergunta(&fase3);
    tentativasTotais += fase3.tentativasUsadas;

    if (!fase3.acertou) {
        screenGotoxy(20, 20);
        setTextoBranco();
        printf("Fim de jogo! Você não completou a fase 3.");
        return;
    }
    feedbackCharadaFase(3);


    Jogo fase4 = {4, gerarNumero(150), 5, 0, 0};
    jogarFaseComPergunta(&fase4);
    tentativasTotais += fase4.tentativasUsadas;

    if (!fase4.acertou) {
        screenGotoxy(20, 20);
        setTextoBranco();
        printf("Fim de jogo! Você não completou a fase 4.");
        return;
    }
    feedbackCharadaFase(4);

    
    Jogo fase5 = {5, gerarNumero(300), 5, 0, 0};
    jogarFaseComPergunta(&fase5);
    tentativasTotais += fase5.tentativasUsadas;

    if (fase5.acertou) {
        screenGotoxy(20, 20);
        setTextoBranco();
        printf("PARABÉNS! Você completou todas as 5 fases em %d tentativas!", tentativasTotais);
        adicionarAoRanking(nome, tentativasTotais);
        mostrarRanking();
    } else {
        screenGotoxy(20, 20);
        setTextoBranco();
        printf("Fim de jogo! Você não completou a fase 5.");
    }
}