#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

int tam = 3;
char tabuleiro[3][3];

void SleepSO(int tempoMS)
{
#ifdef __linux__
    usleep(tempoMS * 1000);
#elif __WIN32
    Sleep(tempoMS);
#else


#endif        
}

void loadScreen () 
{
    for(int i = 0; i < 2; i++)
    {
        system("cls");
        printf("CarregandoJogo\n");
        printf("o------");
        SleepSO(125);

        system("cls");
        printf("CarregandoJogo\n");
        printf("-o-----");
        SleepSO(125);

        system("cls");
        printf("CarregandoJogo\n");
        printf("--o----");
        SleepSO(125);

        system("cls");
        printf("CarregandoJogo\n");
        printf("---o---");
        SleepSO(125);

        system("cls");
        printf("CarregandoJogo\n");
        printf("----o--");
        SleepSO(125);
        
        system("cls");
        printf("CarregandoJogo\n");
        printf("-----o-");
        SleepSO(125);
        
        system("cls");
        printf("CarregandoJogo\n");
        printf("------o");
        SleepSO(125);
    }
}

void ComputingScore()
{
    printf("Calculando os pontos feitos. . .\n");
    printf("...............\n");
    SleepSO(2000);
}

void rules()
{
    system("clear || cls");
    printf("\tREGRAS DO JOGO DA VELHA!\t\n\n");
    printf("Descri%c%co de cada op%c%o do jogo:\n\n",135, 198, 135, 198);

    printf("(1) - Jogador contra CPU\n");
    printf("Esta op%c%co lhe d%c o direito de jogar contra a IA da CPU, onde voc%e joga com X e a CPU com O\n", 135, 198, 160, 136);
    printf("Obs: A IA da CPU joga usando o Algoritmo Minimax, portanto, ser%c um pouco complicado vencer rs.\n\n",160);

    printf("(2) - Jogador contra Jogador\n");
    printf("Esta op%c%co lhe d%c o direito de jogar contra outro jogador, inserindo o nome de cada um.\n\n",135, 198, 160);

    printf("(3) - Regras do jogo\n");
    printf("Esta op%c%co lhe mostra as regras do jogo, %c onde voc%c est%c agora!\n\n",135, 198, 130, 136, 160);

    printf("(4) - Sair do jogo\n");
    printf("Esta op%c%co encerra o programa!\n\n",135, 198);

    system("pause");
}

void printGame (int tam, char tabuleiro[][tam])
 {
    system("clear || cls");
    printf("...............\n");
    printf("   1   2   3   \n");
    printf("1  %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("  ...|...|...  \n");
    printf("2  %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("  ...|...|...  \n");
    printf("3  %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("...............\n");
}

void turnPlayer( char player[], int i)
{
    if(i)
    {
        printf("%c a vez de %s jogar!\n", 144, player);
        printf("...............\n");
    }
    if(!i)
    {
        printf("%c a vez da %s jogar!\n", 144, player);
        printf("...............\n");
        SleepSO(2000);
    }
}

void read_nickname_char(char nickname[], int i) 
{
    char c = getchar();
    if(c == '\n') nickname[i] = '\0';
    else 
    {
        nickname[i] = c;
        read_nickname_char(nickname, i + 1);
    }   
}

void inserNickname( char nickOne[], char nickTwo[], int i)
{
   if(i)
   {
    system("clear || cls");
    printf("Digite o nome do primeiro jogador: ");
    getchar();
    read_nickname_char(nickOne,0);

    system("clear || cls");
    printf("Digite o nome do segundo jogador jogador: ");
    read_nickname_char(nickTwo,0);
   }
   if(!i)
   {
    system("clear || cls");
    printf("Digite o nome do jogador: ");
    getchar();
    read_nickname_char(nickOne,0);

    strcpy(nickTwo, "CPU");
    system("clear || cls");
    
   }
}

int CheckWinner (int tam, char tabuleiro[][tam], int *playerOne, int *playerTwo)
{
    char winner;

    for (int i = 0; i < tam; i++) 
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]) 
        {
            if (tabuleiro[i][0] != ' ') winner = tabuleiro[i][0];
        }
    }

    for (int i = 0; i < tam; i++) 
    { 
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
        {
            if (tabuleiro[0][i] != ' ') winner = tabuleiro[0][i];
        }
    }

    if (tabuleiro [0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]) 
    {
        if(tabuleiro[1][1] != ' ') 
        {
        winner = tabuleiro[1][1];
        }
    }
    if (tabuleiro [0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0]) 
    {
        if(tabuleiro[1][1] != ' ') 
        {
        winner = tabuleiro[1][1];
        }
    }
    if (winner == 'X')
    {
        *playerOne += 1;
        return 1;
    }
    else if (winner == 'O')
    {
        *playerTwo += 1;
        return 2;
    }
    else
    {
        return 0;
    }
}

char CheckWinner_CPU(char tabbleCPU[]) 
{
	int i;
	for (i = 0; i < 9; i += 3) {
		if (tabbleCPU[i] == tabbleCPU[i + 1] && tabbleCPU[i + 1] == tabbleCPU[i + 2]) {
			if (tabbleCPU[i] != ' ') {
				return tabbleCPU[i];
			}
		}
	}
	for (i = 0; i < 4; i++) {
		if (tabbleCPU[i] == tabbleCPU[i + 3] && tabbleCPU[i + 3] == tabbleCPU[i + 6]) {
			if (tabbleCPU[i] != ' ') {
				return tabbleCPU[i];
			}
		}
	}
	if (tabbleCPU[0] == tabbleCPU[4] && tabbleCPU[4] == tabbleCPU[8]) {
		if (tabbleCPU[0] != ' ') {
			return tabbleCPU[i];
		}
	}
	if (tabbleCPU[2] == tabbleCPU[4] && tabbleCPU[4] == tabbleCPU[6]) {
		if (tabbleCPU[2] != ' ') {
			return tabbleCPU[i];
		}
	}
	return ' ';
}
bool draw(char tab[3][3])
{
    for(int i=0; i < 9; i++)
    {
        if(tab[i / 3][i % 3] == ' ') return false;
    }
    return true;
}

bool validPosition (int size, char game[][size], int line, int column) {
    if (line < 0 || column < 0) 
    {
        printGame(size, game);
        printf("Esta posi%c%co %c inv%clida!\n",135, 198,130, 160);
        printf("...............\n");
        printf("\nEscolha uma nova posi%c%co!", 135, 198);
        return true;
    } 
    else if (game[line][column] != ' ') 
    {   
        printGame(3, tabuleiro);
        printf("Esta posi%c%co j%c foi marcada!\n", 135, 198, 160);
        printf("...............\n");
        printf("\nEscolha uma nova posi%c%co!", 135, 198);
        return true;
    } 
    return false;
}


void addSpaceInTabble (int i, int linha, int coluna, char matrix[][coluna])
{
	if (i < linha * coluna)
	{
		matrix[i / coluna][i % coluna] =  ' ';
		addSpaceInTabble(i + 1, linha, coluna, matrix);
	}
	return;
}

void symbol (int tam, char matrix[][tam], char symbol, int line, int column) 
{
    matrix[line][column] = symbol;
}


void Score(int playerOne, int PLayerTwo, char nicknameOne[], char nicknameTwo[])
{
    

    if(playerOne != PLayerTwo)
    {
        printf("%s venceu o duelo!\n", (playerOne > PLayerTwo) ? nicknameOne : nicknameTwo);
        printf("...............\n");
    }

    else
    {
        
        printf("%s e %s empataram esse duelo!\n", nicknameOne, nicknameTwo);
        printf("...............\n");
    }

    printf("\nPlacar final:\n\n");

    printf("%s venceu %d %s!\n", nicknameOne, playerOne, playerOne == 1 ? "vez" : "vezes");
    printf("%s venceu %d %s!\n\n",nicknameTwo, PLayerTwo, PLayerTwo == 1 ? "vez" : "vezes");

}


void InsertPosition (int size, char game[][size], int *line, int *column, char symbol) 
{
    printf("\nDigite uma linha e uma coluna do jogo para marcar um %c:", symbol);
    do {
        printf("\nLinha: ");
        scanf("%d", line);
        printf("Coluna: ");
        scanf("%d", column);
        
        if (*column > size || *column < 1) *column = 0;
        if (*line > size || *line < 1) *line = 0;
    
    } while (validPosition(size, game, *line - 1, *column - 1));
}

//Algoritmo Minimax para CPU jogar

bool MovesLeft_CPU(char tabbleCPU[]) 
{
	for (int i = 0; i < 9; i++) 
    {
		if (tabbleCPU[i] == ' ') 
        {
			return true;
		}
	}
	return false;
}

int minimax_CPU(char tabble[3][3], char tabbleCPU[], int depth, int max_turn, int Min, int Max) {
	char winning = CheckWinner_CPU(tabbleCPU);
	int CPU_move, mm;
	if (winning == 'O') return 10;
	if (winning == 'X') return -10;
	if (!MovesLeft_CPU(tabbleCPU))  return 0;
	if (max_turn) 
    {
		CPU_move = -1000;
		for (int i = 0; i < 9; i++) 
        {
			if (tabbleCPU[i] == ' ') 
            {
				tabbleCPU[i] = 'O';
				mm = minimax_CPU(tabble, tabbleCPU, depth + 1, 0, Min, Max);
				if (mm > CPU_move) CPU_move = mm - depth;
				if (CPU_move > Min) Min = CPU_move;
				tabbleCPU[i] = ' ';
				if (Max <= Min) break;
			}
		}
		return CPU_move;
	}

     else 
     {
		CPU_move = 1000;
		for (int i = 0; i < 9; i++) 
        {
			if (tabbleCPU[i] == ' ') 
            {
				tabbleCPU[i] = 'X';
				mm = minimax_CPU(tabble, tabbleCPU, depth + 1, 1, Min, Max);
				if (mm < CPU_move) CPU_move = mm + depth;
				if (CPU_move < Max) Max = CPU_move;
				tabbleCPU[i] = ' ';
				if (Max <= Min) break;
			}
		}
		return CPU_move;
	}
}

int best_CPU_move(char tabble[3][3], char tabbleCPU[]) {
	int best = -1000;
	int move = -1;
	int mm;
	for (int i = 0; i < 9; i++) 
    {
		if (tabbleCPU[i] == ' ') 
        {
			tabbleCPU[i] = 'O';
			mm = minimax_CPU(tabble, tabbleCPU, 0, 0, -1000, 1000);

			if (mm > best) 
            {
				best = mm;
				move = i;
			}
			tabbleCPU[i] = ' ';
		}
	}
	return move;
}

void InsertPositionCPU (int size, char game[][size],char tabbleCPU[], int *line, int *column, int linePlayer, int columnPlayer) 
{

    int player_move;
    if(linePlayer == 0 && columnPlayer == 0 ) player_move = 0;
    if(linePlayer == 0 && columnPlayer == 1 ) player_move = 1;
    if(linePlayer == 0 && columnPlayer == 2 ) player_move = 2;
    if(linePlayer == 1 && columnPlayer == 0 ) player_move = 3;
    if(linePlayer == 1 && columnPlayer == 1 ) player_move = 4;
    if(linePlayer == 1 && columnPlayer == 2 ) player_move = 5;
    if(linePlayer == 2 && columnPlayer == 0 ) player_move = 6;
    if(linePlayer == 2 && columnPlayer == 1 ) player_move = 7;
    if(linePlayer == 2 && columnPlayer == 2 ) player_move = 8;

    tabbleCPU[player_move] = 'X';

    int CPU_move = best_CPU_move(game, tabbleCPU);

    tabbleCPU[CPU_move] = 'O';

    if(CPU_move == 0)
    {
        *line = 1;
        *column = 1;
    }

    if(CPU_move == 1)
    {
        *line = 1;
        *column = 2;
    }

    if(CPU_move == 2)
    {
        *line = 1;
        *column = 3;
    }

    if(CPU_move == 3)
    {
        *line = 2;
        *column = 1;
    }

    if(CPU_move == 4)
    {
        *line = 2;
        *column = 2;
    }

    if(CPU_move == 5)
    {
        *line = 2;
        *column = 3;
    }

    if(CPU_move == 6)
    {
        *line = 3;
        *column = 1;
    }

    if(CPU_move == 7)
    {
        *line = 3;
        *column = 2;
    }

    if(CPU_move == 8)
    {
        *line = 3;
        *column = 3;
    }
}

void VersusCPU(int *JogadorX, int *jogadorBola, int tam, char tabuleiro[][tam], char tabbleCPU[], char nickOne[], char nickTwo[])
{   
    int playerOne = 0, playerTwo = 0;
    addSpaceInTabble(0, tam, tam, tabuleiro);

    for(int i = 0; ; i++)
        {            
            int line1, column1, lineCPU, columnCPU;

          
            printGame(3, tabuleiro);

            turnPlayer(nickOne,1);
            InsertPosition(tam, tabuleiro, &line1, &column1, 'X');
            symbol(3,tabuleiro,'X',line1-1, column1-1);
            printGame(3, tabuleiro);

            if(CheckWinner(3,tabuleiro, &playerOne, &playerTwo) == 1) break;
            if(draw(tabuleiro)) break;
            
            turnPlayer(nickTwo,0);
            InsertPositionCPU(tam, tabuleiro, tabbleCPU, &lineCPU, &columnCPU, line1-1, column1-1);
            symbol(3,tabuleiro,'O',lineCPU-1, columnCPU-1);
            
            printGame(3, tabuleiro);

            if(CheckWinner(3,tabuleiro, &playerOne, &playerTwo) == 2) break;
            if(draw(tabuleiro)) break;
            
        }

    *JogadorX = *JogadorX + playerOne;
    *jogadorBola = *jogadorBola + playerTwo;

}

void InitCPUGame(int *op, char *tabbleCPU, int *scoreOne, int *scoreCPU, char nicknameOne[], char nicknameCPU[])
{

     do
    {   
        int playerOne = 0, playerCPU = 0;
        VersusCPU(&playerOne, &playerCPU, tam, tabuleiro, tabbleCPU, nicknameOne, nicknameCPU);

        *scoreOne += playerOne;
        *scoreCPU += playerCPU;

        printGame(3, tabuleiro);

        printf("\a%s prevaleceu nesta rodada!\n",(playerOne == playerCPU) ? "Empate" : (playerOne > playerCPU) ? nicknameOne  : nicknameCPU );
        printf("...............\n\n");
        printf("Voc%c pretende continuar?\n", 136);
        printf("(1) - Sim\n(2) - N%co\n\n", 198);
        
        printf("Digite um n%cmero: ", 163);        
        scanf("%d", op);
        
        if(*op != 1 && *op != 2) printf("Op%c%co inválida!\n", 135, 198);
        
    } while (*op != 2 );
    
}

void VersusPlayer(int *JogadorX, int *jogadorBola, int tam, char tabuleiro[][tam], char nickOne[], char nickTwo[])
{   
    int playerOne = 0, playerTwo = 0;
    addSpaceInTabble(0, tam, tam, tabuleiro);

    for(int i = 0; ; i++)
        {            
            int line1, column1, line2, column2;

          
            printGame(3, tabuleiro);

            turnPlayer(nickOne,1);
            InsertPosition(tam, tabuleiro, &line1, &column1, 'X');
            symbol(3,tabuleiro,'X',line1-1, column1-1);
            printGame(3, tabuleiro);

            if(CheckWinner(3,tabuleiro, &playerOne, &playerTwo) == 1) break;
            if(draw(tabuleiro)) break;
            
            turnPlayer(nickTwo,1);
            InsertPosition(tam, tabuleiro, &line2, &column2, 'O');
            symbol(3,tabuleiro,'O',line2-1, column2-1);
            printGame(3, tabuleiro);

            if(CheckWinner(3,tabuleiro, &playerOne, &playerTwo) == 2) break;
            if(draw(tabuleiro)) break;
            
        }
        

    *JogadorX = *JogadorX + playerOne;
    *jogadorBola = *jogadorBola + playerTwo;


}


void InitPlayerGame( int *op, int *scoreOne, int *scoreTwo, char nicknameOne[], char nicknameTwo[])
{
    do
    {   

        int playerOne = 0, playerTwo = 0;
        VersusPlayer(&playerOne, &playerTwo, tam, tabuleiro, nicknameOne, nicknameTwo);

        *scoreOne += playerOne;
        *scoreTwo += playerTwo;

        printGame(3, tabuleiro);

        printf("\a%s prevaleceu nesta rodada!\n",(playerOne == playerTwo) ? "Empate" : (playerOne > playerTwo) ? nicknameOne  : nicknameTwo );
        printf("...............\n\n");
        printf("Voc%c pretende continuar?\n", 136);
        printf("(1) - Sim\n(2) - N%co\n\n", 198);
        
        printf("Digite um n%cmero: ", 163);        
        scanf("%d", op);
        
        if(*op != 1 && *op != 2) printf("Op%c%co inválida!\n", 135, 198);
        
    } while (*op != 2 );
    
}

void inicial_menu()
{
    while(1)
    {
        system("clear || cls");
        printf("\tJOGO DA VELHA!\t\n\n");
        printf("Op%c%ces:\n\n", 135,228);

        printf("(1) - Jogador contra CPU\n\n");
        printf("(2) - Jogador contra Jogador\n\n");
        printf("(3) - Regras do jogo\n\n");
        printf("(4) - Sair do jogo\n\n");

        printf("Digite um n%cmero: ", 163);
        int opc;
        scanf("%d", &opc);

        
        if(opc == 1)
        {
            system("clear || cls");
            int playerOne = 0, playerTwo = 0;
            int op;
            system("clear || cls");
            
            char nicknameOne[50], nicknameTwo[50];
            inserNickname(nicknameOne, nicknameTwo, 0);

            system("clear || cls");

            char tabbleCPU[] = {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '};

            do{
                InitCPUGame(&op, tabbleCPU, &playerOne, &playerTwo, nicknameOne, nicknameTwo);
            }while(op != 2); 
            
            Sleep(125);
            printGame(3, tabuleiro);
            ComputingScore();

            printGame(3, tabuleiro);
            Score(playerOne, playerTwo, nicknameOne, nicknameTwo);
            system("pause");

        }

        else if(opc == 2)
        {
            system("clear || cls");
            int playerOne = 0, playerTwo = 0;
            int op;
            system("clear || cls");
            
            char nicknameOne[50], nicknameTwo[50];
            inserNickname(nicknameOne, nicknameTwo, 1);

            do{
                InitPlayerGame(&op, &playerOne, &playerTwo, nicknameOne, nicknameTwo);
            }while(op != 2); 
            
            Sleep(125);
            printGame(3, tabuleiro);
            ComputingScore();

            printGame(3, tabuleiro);
            Score(playerOne, playerTwo, nicknameOne, nicknameTwo);
            system("pause");
        }
        else if(opc == 3)
        {
            rules();
        }
        else if(opc == 4)
        {
            exit(0);
        }
        else
        {
            system("clear || cls");
            printf("Escolha uma opcao valida!");
            getchar();
        }
    }
}

int main()
{
    loadScreen();
    inicial_menu();
    return 0;
}
