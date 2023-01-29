#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "print.h"
#include "game.h"
#include "menu.h"
#include "valid.h"
#include "highscores.h"
        

void display(int** board)
{
    system("clear");
    char letter = 'a';
    printf("    ");
    for (int k = 0; k < 9; ++k)
    {
        printf("%d  ", k + 1);
        if((k+1)%3==0)
            printf("  ");
    }
    printf("\n  ---------------------------------\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%c | ", letter);
        letter++;
        for (int j = 0; j < 9; j++) 
        {
            if (board[i][j] == 0)
            {
                printf("   ");
            }
            else
            {
                printf("%d  ", board[i][j]);
            }
            if ((j + 1) % 3 == 0 && j < 9 - 1)
                printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < 9 - 1)
            printf("  ---------------------------------\n");
    }
}
