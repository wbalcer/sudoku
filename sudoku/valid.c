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



bool findfree(int grid[9][9],int *row,int *col)
{
    for (*row=0;*row<9;(*row)++)
        for (*col=0;*col<9;(*col)++)
            if (grid[*row][*col]==0)
                return true;
    return false;
}

bool canPlace2(int grid[9][9],int row,int col,int num)
{
    for (int i = 0; i < 9; i++)
        if (grid[row][i] == num)
            return false;

    for (int i = 0; i < 9; i++)
        if (grid[i][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++)
        for (int j = startCol; j < startCol + 3; j++)
            if (grid[i][j] == num)
                return false;
    return true;
}

bool validmove(int grid[9][9])
{
    int row,col;
    if (!findfree(grid,&row,&col))
        return true;
    for (int num=1;num<=9;num++)
        if (canPlace2(grid, row, col, num))
        {
            grid[row][col]=num;
            if (validmove(grid))
                return true;
            grid[row][col]=0;
        }
    return false;
}
