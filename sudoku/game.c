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

#define MAX_HIGH_SCORES 5

typedef struct 
{
    char* name;
    int time;
} HighScore;


void addhighscore(HighScore newscore, int difficulty)
{
    HighScore high_scores[MAX_HIGH_SCORES];
    char* filename;
    switch (difficulty)
    {
        case 1:
            filename = "bl.txt";
            break;
        case 2:
            filename = "l.txt";
            break;
        case 3:
            filename = "s.txt";
            break;
        case 4:
            filename = "t.txt";
            break;
        case 5:
            filename = "bt.txt";
            break;
        default:
            break;
    }

    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < MAX_HIGH_SCORES; i++)
    {
        high_scores[i].name = malloc(20 * sizeof(char));
        fscanf(f, "%19s %d", high_scores[i].name, &high_scores[i].time);
    }
    fclose(f);

    high_scores[MAX_HIGH_SCORES - 1] = newscore;

    for (int i = 0; i < MAX_HIGH_SCORES - 1; i++)
        for (int j = i + 1; j < MAX_HIGH_SCORES; j++)
            if (high_scores[i].time > high_scores[j].time)
            {
                HighScore temp = high_scores[i];
                high_scores[i] = high_scores[j];
                high_scores[j] = temp;
            }

    f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < MAX_HIGH_SCORES; i++)
        fprintf(f, "%s %d\n", high_scores[i].name, high_scores[i].time);

    fclose(f);
}



bool isempty(int col,int row,int** board)
{
    if (board[row][col]==0)
        return true;
    return false;
}

int move(int** board)
{    
    int grid[9][9];
    int col;
    int row;
    char letter;
    int num;
    int change[3];
    printf("Napisz kolumne: ");
    scanf("%d",&col);
    col--;
    printf("Napisz rzad: ");
    scanf(" %c",&letter);
    row=letter-'a';
    printf("Napisz liczbe: ");
    scanf("%d",&num);
    if (col>8||col<0||row>8||row<0||num<1||num>9||!isempty(col,row,board))
    {
        printf("Niepoprawny ruch! Spróbuj ponownie.\n");
        return move(board);
    }
    board[row][col]=num;
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++)
            grid[i][j]=board[i][j];
    if (validmove(grid))
    {  
        display(board);
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                if((board[i][j])==0)
                    return 0;
        return 1;
    }
    return 2;    
}

void game(int difficulty)
{
    int** board = boardgenerator(difficulty);
    int decision=0;
    char nazwa[20];
    display(board);
    int gamestatus=0;
    time_t start_time, end_time;
    start_time = time(NULL);
    while (gamestatus<1)
        gamestatus=move(board);
    end_time=clock();
    if (gamestatus==1)
    {
        system("clear");
        end_time = time(NULL);
        int elapsed = difftime(end_time, start_time);
        printf("--------------------------Wygrywasz-------------------------\n\n\n\n\n");
        printf("Twoj czas to %d:%d\n",elapsed/60,elapsed%60);
        printf("Podaj nazwe: ");
        scanf("%19s",nazwa);
        HighScore newscore = {.name = nazwa, .time = elapsed};
        addhighscore(newscore, difficulty);
    }
    else
    {
        printf("--------------------------Przegrywasz-------------------------\n\n\n\n\n");
    }
    printf("\n--------Aby wrocic do menu wcisnij dowolny przycisk---------\n");
    scanf("%d",&decision);
    menu();    
}
