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


void highscores()
{
    char nazwa[20];
    int czas;
    system("clear");
    printf("------------REKORDY------------\n\n\n");
    printf("BARDZO LATWY\n");
    FILE *f=fopen("bl.txt","rt");
    if (f == NULL)
    {
        printf("blad otwarcia pliku \n");
    }
    for (int i=0;i<5;i++)
    {
        fscanf(f,"%19s %d",nazwa,&czas);
        printf("%d.%19s %d:%d\n",i+1,nazwa,czas/60,czas%60);
    }
    fclose(f);
    printf("\n\n");
    printf("LATWY\n");
    f=fopen("l.txt","rt");
    if (f == NULL)
    {
        printf("blad otwarcia pliku \n");
    }
    for (int i=0;i<5;i++)
    {
        fscanf(f,"%19s %d",nazwa,&czas);
        printf("%d.%19s %d:%d\n",i+1,nazwa,czas/60,czas%60);
    }
    fclose(f);
    printf("\n\n");
    printf("SREDNI\n");
    f=fopen("s.txt","rt");
    if (f == NULL)
    {
        printf("blad otwarcia pliku \n");
    }
    for (int i=0;i<5;i++)
    {
        fscanf(f,"%19s %d",nazwa,&czas);
        printf("%d.%19s %d:%d\n",i+1,nazwa,czas/60,czas%60);
    }
    fclose(f);
    printf("\n\n");
    printf("TRUDNY\n");
    f=fopen("t.txt","rt");
    if (f == NULL)
    {
        printf("blad otwarcia pliku \n");
    }
    for (int i=0;i<5;i++)
    {
        fscanf(f,"%19s %d",nazwa,&czas);
        printf("%d.%19s %d:%d\n",i+1,nazwa,czas/60,czas%60);
    }
    fclose(f);
    printf("\n\n");
    printf("BARDZO TRUDNY\n");
    f=fopen("bt.txt","rt");
    if (f == NULL)
    {
        printf("blad otwarcia pliku \n");
    }
    for (int i=0;i<5;i++)
    {
        fscanf(f,"%19s %d",nazwa,&czas);
        printf("%d.%19s %d:%d\n",i+1,nazwa,czas/60,czas%60);
    }
    fclose(f);
    printf("\n\n");
    int wait;
    printf("-NACISNIJ DOWOLNY PRZYCISK ABY WROCIC DO MENU-\n");
    scanf("%d",&wait);
    menu();
}