#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//projeto_jogoDaVelha.c
void loadScreen () {
    system("cls");
        printf("CarregandoJogo\n");
        printf("o------");
        Sleep(125);

        system("cls");
        printf("CarregandoJogo\n");
        printf("-o-----");
        Sleep(125);

        system("cls");
        printf("CarregandoJogo\n");
        printf("--o----");
        Sleep(125);

        system("cls");
        printf("CarregandoJogo\n");
        printf("---o---");
        Sleep(125);

        system("cls");
        printf("CarregandoJogo\n");
        printf("----o--");
        Sleep(125);
        
        system("cls");
        printf("CarregandoJogo\n");
        printf("-----o-");
        Sleep(125);
        
        system("cls");
        printf("CarregandoJogo\n");
        printf("------o");
        Sleep(125);
}

void setingGameMatriz (int size, char game[][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            game[i][j] = ' ';
        }
    }
}

void enteringGameMode (int *player) {
    printf("Modos de jogo:\n");
    printf("    1. Jogador x Jogador\n    0. Jogador x Maquina\n\n");
    printf("Digite o modo de jogo: ");
    scanf("%d", player);
}

void enteringNicks (char nickPlayer[], int player) {
    printf("\nDigite o nick do jogador %d:", player);
    scanf("%s", nickPlayer);
}

void printGame (int size, char game[][size]) {
    printf("...............\n");
    printf("   1   2   3   \n");
    printf("1  %c | %c | %c\n", game[0][0], game[0][1], game[0][2]);
    printf("  ...|...|...  \n");
    printf("2  %c | %c | %c\n", game[1][0], game[1][1], game[1][2]);
    printf("  ...|...|...  \n");
    printf("3  %c | %c | %c\n", game[2][0], game[2][1], game[2][2]);
    printf("...............\n");
}

void printTurn (char nick[]) {
    printf("\nEh a vez de %s\n", nick);
}

int validPosition (int size, char game[][size], int line, int column) {
    if (line < 0 || column < 0) {
        system("cls");
        printGame(size, game);
        printf("\nEsta posicao eh invalida");
        printf("\nEscolha uma nova posicao");
        return 1;
    } else if (game[line][column] != ' ') {
        system("cls");
        printGame(size, game);
        printf("\nEsta posicao ja foi marcada");
        printf("\nEscolha uma nova posicao");
        return 1;
    } 
    return 0;
}

void selectPositionToPlay (int size, char game[][size], int *line, int *column, char symbol) {
    printf("Digite uma linha e uma coluna do jogo para marcar um %c:", symbol);
    do {
        printf("\nLinha: ");
        scanf("%d", line);
        printf("Coluna: ");
        scanf("%d", column);
        
        if (*column > size || *column < 1) *column = 0;
        if (*line > size || *line < 1) *line = 0;
    
    } while (validPosition(size, game, *line - 1, *column - 1));
}

void putSymbol (int size, char game[][size], char symbol, int line, int column) {
    game[line][column] = symbol;
}

int sum (char nick[], int i, int s) {
    if (i > -1) return sum(nick, i - 1, s + nick[i]);
}

void cpuTurn (int size, char game[][size], int turn) {
    int verify = 0;
    do {
        for (int i = 0; i < size; i++) { // horizonal
            if (game[i][0] == 'O' && game[i][1] == 'O' && game[i][2] == ' ') {
                game[i][2] = 'O';
                verify = 1;
            } else if (game[i][0] == 'O' && game[i][1] == ' ' && game[i][2] == 'O') {
                game[i][1] = 'O';
                verify = 1;
            } else if (game[i][0] == ' ' && game[i][1] == 'O' && game[i][2] == 'O') {
                game[i][0] = 'O';
                verify = 1;
            }
            if (verify) break;
        }
    
        if (verify) break;

        for (int i = 0; i < size; i++) { // vertical
            if (game[0][i] == 'O' && game[1][i] == 'O' && game[2][i] == ' ') {
                game[2][i] = 'O';
                verify = 1;
            } else if (game[0][i] == 'O' && game[1][i] == ' ' && game[2][i] == 'O') {
                game[1][i] = 'O';
                verify = 1;
            } else if (game[0][i] == ' ' && game[1][i] == 'O' && game[2][i] == 'O') {
                game[0][i] = 'O';
                verify = 1;
            }
            if (verify) break;
        }
    
        if (verify) break;

        // diagonal
        if (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == ' ') {
            game[2][2] = 'O';
            verify = 1;
        } else if (game[0][0] == 'O' && game[1][1] == ' ' && game[2][2] == 'O') {
            game[1][1] = 'O';
            verify = 1;
        } else if (game[0][0] == ' ' && game[1][1] == 'O' && game[2][2] == 'O') {
            game[0][0] = 'O';
            verify = 1;
        }
    
        if (verify) break;

        if (game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == ' ') {
            game[2][0] = 'O';
            verify = 1;
        } else if (game[0][2] == 'O' && game[1][1] == ' ' && game[2][0] == 'O') {
            game[1][1] = 'O';
            verify = 1;
        } else if (game[0][2] == ' ' && game[1][1] == 'O' && game[2][0] == 'O') {
            game[0][2] = 'O';
            verify = 1;
        }
    
        if (verify) break;
        /////////////////////////////// negar vitoria vvvvvvvv
        for (int i = 0; i < size; i++) { // horizonal
            if (game[i][0] == 'X' && game[i][1] == 'X' && game[i][2] == ' ') {
                game[i][2] = 'O';
                verify = 1;
            } else if (game[i][0] == 'X' && game[i][1] == ' ' && game[i][2] == 'X') {
                game[i][1] = 'O';
                verify = 1;
            } else if (game[i][0] == ' ' && game[i][1] == 'X' && game[i][2] == 'X') {
                game[i][0] = 'O';
                verify = 1;
            }
            if (verify) break;
        }
    
        if (verify) break;

        for (int i = 0; i < size; i++) { // vertical
            if (game[0][i] == 'X' && game[1][i] == 'X' && game[2][i] == ' ') {
                game[2][i] = 'O';
                verify = 1;
            } else if (game[0][i] == 'X' && game[1][i] == ' ' && game[2][i] == 'X') {
                game[1][i] = 'O';
                verify = 1;
            } else if (game[0][i] == ' ' && game[1][i] == 'X' && game[2][i] == 'X') {
                game[0][i] = 'O';
                verify = 1;
            }
            if (verify) break;
        }
    
        if (verify) break;

        // diagonal
        if (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == ' ') {
            game[2][2] = 'O';
            verify = 1;
        } else if (game[0][0] == 'X' && game[1][1] == ' ' && game[2][2] == 'X') {
            game[1][1] = 'O';
            verify = 1;
        } else if (game[0][0] == ' ' && game[1][1] == 'X' && game[2][2] == 'X') {
            game[0][0] = 'O';
            verify = 1;
        }
    
        if (verify) break;

        if (game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == ' ') {
            game[2][0] = 'O';
            verify = 1;
        } else if (game[0][2] == 'X' && game[1][1] == ' ' && game[2][0] == 'X') {
            game[1][1] = 'O';
            verify = 1;
        } else if (game[0][2] == ' ' && game[1][1] == 'X' && game[2][0] == 'X') {
            game[0][2] = 'O';
            verify = 1;
        }
    
        if (verify) break;
        /////////////////////////////// negar vitoria ^^^^^^^^

        int arrayI[9], arrayJ[9], i, j;
        srand(time(NULL));
        for (i = 0; i < 10; i++) {
            arrayI[i] = rand() % 3;
        } 
        for (j = 0; j < 10; j++) {
            arrayJ[j] = rand() % 3;
        }

        i = arrayI[turn], j = arrayJ[turn];

        if (game[i][j] == ' ') {
            game[i][j] = 'O';
            verify = 1;
        }
        else if (game[j][i] == ' ') {
            game[j][i] = 'O';
            verify = 1;
        }
        else {
            for (i = 0; i < size; i++) {
                for (j = 0; j < size; j++) {
                    if (game[i][j] == ' ' || game[j][i] == ' ') {
                        if (game[i][j] == ' ') {
                            game[i][j] = 'O';
                            verify = 1;
                        } else if (game[j][i] == 'O'){
                            game[j][i] = 'O';
                            verify = 1;
                        } 
                        if (verify) break;
                    }   
                }
                if (verify) break;
            }
        }
    } while (!verify);
}


int chekWinnerInRound (int size, char game[][size]) {
    char winner;

    for (int i = 0; i < size; i++) { // vitoria horizontal
        if (game[i][0] == game[i][1] && game[i][0] == game[i][2]) {
            if (game[i][0] != ' ') winner = game[i][0];
        }
    }

    for (int i = 0; i < size; i++) { // vitoria vertical
        if (game[0][i] == game[1][i] && game[0][i] == game[2][i]) {
            if (game[0][i] != ' ') winner = game[0][i];
        }
    }
        // vitoria diagonal
    if (game [0][0] == game[1][1] && game[0][0] == game[2][2]) {
        if(game[1][1] != ' ') winner = game[1][1];
    }
    if (game [0][2] == game[1][1] && game[0][2] == game[2][0]) {
        if(game[1][1] != ' ') winner = game[1][1];
    }
    
    if (winner == 'X') return 1;
    else if (winner == 'O') return 2;
    else return 0;
}

void printWinner (char nickPlayer1[], char nickPlayer2[], int winner) {
    if (winner == 1) printf("\nO Vencedor foi: %s\n", nickPlayer1);
    if (winner == 2) printf("\nO Vencedor foi: %s\n", nickPlayer2);
}

void restartGame (int *restart) {
    printf("\nVoce deseja jogar novamente?\n");
    printf("    1. Sim\n    0. Nao\n\n");
    printf("Digite sua escolha: ");
    scanf("%d", restart);
    getchar();
    system("cls");
}

void switchGameMode (int *switchGameMode) {
    printf("\nDeseja alterar o modo de jogo?\n");
    printf("    1. Sim\n    0. Nao\n\n");
    printf("Digite sua escolha: ");
    scanf("%d", switchGameMode);
    system("cls");
}

void scoreboard (int count1, int count2, int countCPU, char nickPlayer1[], char nickPlayer2[], int player2) {
    printf("\nO placar do jogo foi:\n");
    printf("    %s: %d\n", nickPlayer1, count1);
    if (player2) printf("    %s: %d\n", nickPlayer2, count2);   
    printf("    %s: %d\n", "CPU", countCPU);
    printf("\nObrigado por jogar!\n");
    getchar();
}

int main () {
    int size = 3, player2, restart, switchMode = 1;
    int winCount1 = 0, winCount2 = 0, countCPU = 0, roundCount = 1, winner = 0, line, column;
    char game[size][size];
    char nickPlayer1[21], nickPlayer2[21] = "CPU";

    do {
        setingGameMatriz(size, game);

        if (switchMode) {
            enteringGameMode(&player2);

            enteringNicks(nickPlayer1, 1);
            if (player2) enteringNicks(nickPlayer2, 2);
        }

        roundCount = 1;
        winner = 0;
        
        loadScreen();

        do {
            system("cls");
            if (roundCount % 2) {
                printTurn(nickPlayer1);
                printGame(size, game);
                selectPositionToPlay(size, game, &line, &column, 'X');
                putSymbol(size, game, 'X', line - 1, column - 1);
            } else {
                printTurn(nickPlayer2);
                printGame(size, game);
                if (player2) {
                    selectPositionToPlay(size, game, &line, &column, 'O'); 
                    putSymbol(size, game, 'O', line - 1, column - 1);
                } else {
                    cpuTurn(size, game, roundCount);
                    printf("A CPU esta jogando...");
                    Sleep(2000);
                }
            }

            if (roundCount > 4) {
                winner = chekWinnerInRound(size, game);
            }
            if (winner) {
                system("cls");
                printGame(size, game);
                printWinner(nickPlayer1, nickPlayer2, winner);
                if (winner == 1) winCount1++;
                else {
                    if (player2) winCount2++;
                    else countCPU++;
                }
                break;
            }

            if (!winner) {
                system("cls");
                printGame(size, game);
                printf("Esta rodada terminou em empate");
            }

            roundCount += 1;
        } while (roundCount < 10);

        restartGame(&restart);
        if (restart) switchGameMode(&switchMode);
    } while (restart);

    scoreboard(winCount1, winCount2, countCPU, nickPlayer1, nickPlayer2, player2);
    
    return 0;
}