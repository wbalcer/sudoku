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

void menu()
{
    system("clear");
    printf("---------------------------SUDOKU---------------------------\n\n\n\n\n\nNacisnij numer, aby wybrac\n");
    printf("1.Graj\n2.Pokaż rekordy\n\n\n\n\n");
    printf("----------Aby wyjsc z gry wcisnij dowolny przycisk----------\n");
    int choice=0;
    int difficulty=0;
    scanf("%d",&choice);
    if (choice==1)
    {
        system("clear");
        printf("------------------Wybierz poziom trudności------------------\n\n\n\n\n\n\n\n\n");
        printf("1.Bardzo latwy\n2.Latwy\n3.Sredni\n4.Trudny\n5.Bardzo trudny\nAby wrocic, wcisnij dowolny przycisk\n");
        int difficulty=0;
        scanf("%d",&difficulty);
        system("clear");
        if (difficulty>=1 && difficulty<=5)    
            game(difficulty);
    }
    if (choice==2)
    {
        highscores();
    }
}