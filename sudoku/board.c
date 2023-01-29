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

int board[9][9];


bool canPlace(int** board,int row,int col,int num)
{
    for (int i=0;i<9;i++)
        if (board[row][i]==num)
            return false;

    for (int i=0;i<9;i++)
        if (board[i][col]==num)
            return false;

    int startRow=row-row%3;
    int startCol=col-col%3;
    for (int i=startRow;i<startRow+3;i++)
        for (int j=startCol;j<startCol+3;j++)
            if (board[i][j]==num)
                return false;
    return true;
}


bool generateSudoku(int** board,int row,int col)
{
    if (row==9)
        return true;
    if (col==9)
        return generateSudoku(board,row + 1,0);
    if (board[row][col]!=0)
        return generateSudoku(board,row,col+1);
    int nums[9] = {1,2,3,4,5,6,7,8,9};
    for (int i=0;i<9;i++) 
    {
        int j=rand()%9;
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }

    for (int i=0;i<9;i++) 
    {
        int num=nums[i];
        if (canPlace(board,row,col,num)) 
        {
            board[row][col]=num;
            if (generateSudoku(board,row,col+1))
            {
                return true;
            }
            board[row][col]=0;
        }
    }

    return false;
}


int** boardgenerator(int difficulty)
{
    int** board=(int**)malloc(9*sizeof(int*));
    for (int i=0;i<9;i++)
        board[i]=(int*)malloc(9*sizeof(int));

    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++)
            board[i][j]=0;

    if (generateSudoku(board,0,0)) 
    {
        int level[6]={0,18,26,33,40,50};
        for (int i=0;i<level[difficulty];i++)
        {
            int row=rand()%9;
            int col=rand()%9;
            board[row][col]=0;
        }
    }
    return board;
}
