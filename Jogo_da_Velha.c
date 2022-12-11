#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

int tam = 3;
char tabuleiro[3][3];


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

void read_nickname(char nickname[], int i) 
{
    char c = getchar();
    if(c == '\n') nickname[i] = '\0';
    else 
    {
        nickname[i] = c;
        read_nickname(nickname, i + 1);
    }   
}

void inserNicknameVsPlayer( char nickOne[], char nickTwo[])
{
   
    system("clear || cls");
    printf("Digite o nome do primeiro jogador: ");
    getchar();
    read_nickname(nickOne,0);

    system("clear || cls");
    printf("Digite o nome do segundo jogador jogador: ");
    read_nickname(nickTwo,0);
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

bool draw(char tab[3][3])
{
    for(int i=0; i < 9; i++)
    {
        if(tab[i / 3][i % 3] == ' ') return false;
    }
    return true;
}

bool valid_move (int tam, char tabuleiro[][tam], int line, int column) {

    if (tabuleiro[line][column] != ' ') {

        printf("\nEscolha uma outra posicao");
        return true;
    } 
    return false;
}

bool validPosition (int size, char game[][size], int line, int column) {
    if (line < 0 || column < 0) 
    {
        printGame(size, game);
        printf("\nEsta posicao eh invalida");
        printf("\nEscolha uma nova posicao");
        return true;
    } 
    else if (game[line][column] != ' ') 
    {   
        printGame(3, tabuleiro);
        printf("\nEsta posicao ja foi marcada");
        printf("\nEscolha uma nova posicao");
        return true;
    } 
    return false;
}

void add_0_tabble (int i, int linha, int coluna, char matrix[][coluna])
{
	if (i < linha * coluna)
	{
		matrix[i / coluna][i % coluna] =  ' ';
		add_0_tabble(i + 1, linha, coluna, matrix);
	}
	return;
}

void symbol (int tam, char matrix[][tam], char symbol, int line, int column) 
{
    matrix[line][column] = symbol;
}


void Score(int playerOne, int PLayerTwo, char nicknameOne[], char nicknameTwo[])
{
    

    printf("Placar final:\n\n");

    printf("%s: %d\n", nicknameOne, playerOne);
    printf("%s: %d\n\n",nicknameTwo, PLayerTwo);

    printf("%s venceu o duelo!\n\n", (playerOne > PLayerTwo) ? nicknameOne : nicknameTwo);
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

void VersusPlayer(int *JogadorX, int *jogadorBola, int tam, char tabuleiro[][tam])
{   
    int playerOne = 0, playerTwo = 0;
    add_0_tabble(0, tam, tam, tabuleiro);

    for(int i = 0; ; i++)
        {            
            int line1, column1, line2, column2;

          
            printGame(3, tabuleiro);

            selectPositionToPlay(tam, tabuleiro, &line1, &column1, 'X');
            symbol(3,tabuleiro,'X',line1-1, column1-1);
            printGame(3, tabuleiro);

            if(CheckWinner(3,tabuleiro, &playerOne, &playerTwo) == 1) break;
            if(draw(tabuleiro)) break;
            

            selectPositionToPlay(tam, tabuleiro, &line2, &column2, 'O');
            symbol(3,tabuleiro,'O',line2-1, column2-1);
            printGame(3, tabuleiro);

            if(CheckWinner(3,tabuleiro, &playerOne, &playerTwo) == 2) break;
            if(draw(tabuleiro)) break;
            
        }
        

    *JogadorX = *JogadorX + playerOne;
    *jogadorBola = *jogadorBola + playerTwo;


}

void ReplayGamePlayer( int *op, int *scoreOne, int *scoreTwo)
{
    do
    {   


        int playerOne = 0, playerTwo = 0;
        VersusPlayer(&playerOne, &playerTwo, tam, tabuleiro);

        *scoreOne += playerOne;
        *scoreTwo += playerTwo;

        printGame(3, tabuleiro);
        printf("Você pretende continuar?\n");
        printf("(1) - Sim\n(2) - N%co\n", 198);
        
        printf("Digite um n%cmero: ", 163);        
        scanf("%d", op);
        
        if(*op != 1 && *op != 2)
        {
            printf("Op%c%co inválida!\n", 135, 198);
        } 
    } while (*op != 2 );
    
}

void inicial_menu()
{
    while(1)
    {
        system("clear || cls");
        printf("\tJOGO DA VELHA!\t\n");
        printf("Op%c%ces:\n", 135,228);

        printf("(1) - Jogador contra CPU\n");
        printf("(2) - Jogador contra Jogador\n");
        printf("(3) - Regras do jogo\n");
        printf("(4) - Sair do jogo\n");

        printf("Digite um n%cmero: ", 163);
        int opc;
        scanf("%d", &opc);

        if(opc == 1)
        {
            system("clear || cls");

        }

        else if(opc == 2)
        {
            system("clear || cls");
            int playerOne = 0, playerTwo = 0;
            int op;
            char nicknameOne[50], nicknameTwo[50];
            inserNicknameVsPlayer(nicknameOne, nicknameTwo);

            do{
                ReplayGamePlayer(&op, &playerOne, &playerTwo);
            }while(op != 2); 
            
            Sleep(125);
            printGame(3, tabuleiro);
            Score(playerOne, playerTwo, nicknameOne, nicknameTwo);
            system("pause");
        }
        else if(opc == 3)
        {
        
        }
        else if(opc == 4)
        {
            exit(0);
        }
        else
        {
            system("clear || cls");
        }
    }
}

int main()
{
 
    inicial_menu();
    return 0;
}
