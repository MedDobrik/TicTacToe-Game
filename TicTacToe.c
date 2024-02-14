#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int EmptySlots(char tableau[3][3])
{
    int emptySlots = 0;
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3; j++)
        {
            if (tableau[i][j] == ' ')
            {
               emptySlots = emptySlots + 1;
            }
        }
    }

    return emptySlots;
}

void boardPrint(char tableau[3][3])
{
        printf(" %c\t | %c\t | %c ", tableau[0][0], tableau[0][1], tableau[0][2]);
        printf("\n");
        printf("---------------------------");
        printf("\n");
        printf(" %c\t | %c\t | %c ", tableau[1][0], tableau[1][1], tableau[1][2]);
        printf("\n");
        printf("---------------------------");
        printf("\n");
        printf(" %c\t | %c\t | %c ", tableau[2][0], tableau[2][1], tableau[2][2]);
        printf("\n");
}

void checkWinner(char tableau[3][3] , int *emptySlots)
{

    if (tableau[0][0] == tableau[0][1] && tableau[0][0] == tableau[0][2] && tableau[0][0] == 'X')
    {
        printf("You Won");
        *emptySlots = 0;
    }
    else if (tableau[1][0] == tableau[1][1] && tableau[1][0] == tableau[1][2] && tableau[1][0] == 'X')
    {
        printf("You Won");
        *emptySlots = 0;
    }
    else if (tableau[2][0] == tableau[2][1] && tableau[2][0] == tableau[2][2] && tableau[2][0] == 'X')
    {
        printf("You Won");
        *emptySlots = 0;
    }
    else if (tableau[0][0] == tableau[1][0] && tableau[0][0] == tableau[2][0] && tableau[0][0] == 'X')
    {
        printf("You Won");
        *emptySlots = 0;
    }
    else if (tableau[0][1] == tableau[1][1] && tableau[0][1] == tableau[2][1] && tableau[0][1] == 'X')
    {
        printf("You Won");
        *emptySlots = 0;
    }
    else if (tableau[0][2] == tableau[1][2] && tableau[0][2] == tableau[2][2] && tableau[0][2] == 'X')
    {
        printf("You Won");
        *emptySlots = 0;
    }
    else if (tableau[0][0] == tableau[1][1] && tableau[0][0] == tableau[2][2] && tableau[0][0] == 'X')
    {
        printf("You Won");
        *emptySlots = 0;
    }
    else if (tableau[0][2] == tableau[1][1] && tableau[0][2] == tableau[2][0] && tableau[0][2] == 'X')
    {
        printf("You Won");
        *emptySlots = 0;
    }
    

    else if (tableau[0][0] == tableau[0][1] && tableau[0][0] == tableau[0][2] && tableau[0][0] == 'O')
    {
        printf("You Lost");
        *emptySlots = 0;
    }
    else if (tableau[1][0] == tableau[1][1] && tableau[1][0] == tableau[1][2] && tableau[1][0] == 'O')
    {
        printf("You Lost");
        *emptySlots = 0;
    }
    else if (tableau[2][0] == tableau[2][1] && tableau[2][0] == tableau[2][2] && tableau[2][0] == 'O')
    {
        printf("You Lost");
        *emptySlots = 0;
    }
    else if (tableau[0][0] == tableau[1][0] && tableau[0][0] == tableau[2][0] && tableau[0][0] == 'O')
    {
        printf("You Lost");
        *emptySlots = 0;
    }
    else if (tableau[0][1] == tableau[1][1] && tableau[0][1] == tableau[2][1] && tableau[0][1] == 'O')
    {
        printf("You Lost");
        *emptySlots = 0;
    }
    else if (tableau[0][2] == tableau[1][2] && tableau[0][2] == tableau[2][2] && tableau[0][2] == 'O')
    {
        printf("You Lost");
        *emptySlots = 0;
    }
    else if (tableau[0][0] == tableau[1][1] && tableau[0][0] == tableau[2][2] && tableau[0][0] == 'O')
    {
        printf("You Lost");
        *emptySlots = 0;
    }
    else if (tableau[0][2] == tableau[1][1] && tableau[0][2] == tableau[2][0] && tableau[0][2] == 'O')
    {
        printf("You Lost");
        *emptySlots = 0;
    }
    else 
    {
        int slots = EmptySlots(tableau);

        if (slots == 0)
        {
            printf("Tie");
            *emptySlots = 0;
        } 
        
    }
}

int main()
{
    int row,column;
    int scanfResultRow, scanfResultColumn;
    int emptySlots = 9;
    char tableau[3][3];
    
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            
            tableau[i][j] = ' ';
        }
    }

    while (emptySlots >= 1)
    {

        boardPrint(tableau);
        
        // PLayer Move : 

        printf("\nNumber Of Empty Slots : %d\n", emptySlots);

        int playerMove = 0;

        while (playerMove == 0)
        {
            if (emptySlots == 0)
            {
                break;
            }

            do {
                printf("\nChoose a row number between 1 and 3: ");
                scanfResultRow = scanf("%d", &row);

                // Clear the input buffer in case of non-numeric input
                while (getchar() != '\n');

                printf("Choose a column number between 1 and 3: ");
                scanfResultColumn = scanf("%d", &column);

                // Clear the input buffer in case of non-numeric input
                while (getchar() != '\n');

                if ((scanfResultRow != 1) || (scanfResultColumn != 1) || 
                    (row < 1 || row > 3 || column < 1 || column > 3)) {
                    printf("Invalid input! Row and column must be numeric and between 1 and 3.\n");
                }
            } 
            while ((scanfResultRow != 1) || (scanfResultColumn != 1) ||
                    (row < 1 || row > 3 || column < 1 || column > 3));

            if (tableau[row-1][column-1] != ' ')
            {
                printf("\nThis Spot Is Full\n");
            }
            else 
            {
                tableau[row-1][column-1] = 'X';
                playerMove = 1;
            }    
        }
        
        emptySlots = EmptySlots(tableau);

        //BOT move :

        int botMove = 0;

        while (botMove == 0)
        {
            if (emptySlots == 0)
            {
                break;
            }
            srand(time(NULL));
            int botMove_row = rand() % 3 + 1;
            int botMove_column = rand() % 3 + 1;

            if (tableau[botMove_row-1][botMove_column-1] == ' ')
            {
                tableau[botMove_row-1][botMove_column-1] = 'O';
                botMove = 1;
            }
        }
        checkWinner(tableau, &emptySlots);
        
    }
    printf("\n\n");
    system("pause");
    return 0;
}