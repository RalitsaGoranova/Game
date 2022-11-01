#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>

//global variables for player location
int coordX = 0;
int coordY = 0;

// this function outputs the MazeMap
void OutMaze(char mazeMap[20][20])
{

     for(int i = coordX -1; i < coordX + 2; i ++)
    {
        for(int j = coordY - 1; j < coordY + 2; j ++)
        {

            printf("%c", mazeMap[i][j]);
            printf(" ");


        }
        printf("\n");
    }

}
// this function puts Player character on a random path
void PlayerLocation(char mazeMap[20][20])
{

    srand((unsigned) time(0));
    while(mazeMap[coordX][coordY] != 'o')
    {
        coordX = rand() % 19;
        coordY = rand() % 19;

    }
    mazeMap[coordX][coordY] = 'P';

}

char KeyPressed()
{

    return getchar();

}
void PlayerMovement(char mazeMap[20][20],char keyDown)
{

    switch(keyDown)
    {
    case 'A':
        {
            mazeMap[coordX][coordY] = 'o';
            coordY--;
            if(mazeMap[coordX][coordY] == "S")
            {
                coordY++;
                mazeMap[coordX][coordY] = 'P';
                printf("\n");
                system("cls");
                OutMaze(mazeMap);
                break;
            }
            if(mazeMap[coordX][coordY] == 'W')
            {
               system("cls");
               printf("You Won!");
               break;
            }
            mazeMap[coordX][coordY] = 'P';
            printf("\n");
            system("cls");
            OutMaze(mazeMap);
            break;
        }
        case 'D':
        {

            mazeMap[coordX][coordY] = 'o';
            coordY++;
            if(mazeMap[coordX][coordY] == "S")
            {
                coordY--;
                mazeMap[coordX][coordY] = 'P';
                printf("\n");
                system("cls");
                OutMaze(mazeMap);
                break;
            }
            if(mazeMap[coordX][coordY] == 'W')
            {
               system("cls");
               printf("You Won!");
               break;
            }
            mazeMap[coordX][coordY] = 'P';
            printf("\n");
            system("cls");
            OutMaze(mazeMap);
            break;
        }
        case 'W':
        {
             mazeMap[coordX][coordY] = 'o';
            coordX--;
            if(mazeMap[coordX][coordY] == "S")
            {
                coordX++;
                mazeMap[coordX][coordY] = 'P';
                printf("\n");
                system("cls");
                OutMaze(mazeMap);
                break;
            }
            if(mazeMap[coordX][coordY] == 'W')
            {
               system("cls");
               printf("You Won!");
               break;
            }
             mazeMap[coordX][coordY] = 'P';
            printf("\n");
            system("cls");
            OutMaze(mazeMap);
            break;
        }
        case 'S':
        {

            mazeMap[coordX][coordY] = 'o';
            coordX++;
            if(mazeMap[coordX][coordY] == "S")
            {
                coordX--;
                mazeMap[coordX][coordY] = 'P';
                printf("\n");
                system("cls");
                OutMaze(mazeMap);
                break;
            }
            if(mazeMap[coordX][coordY] == 'W')
            {
               system("cls");
               printf("You Won!");
               break;
            }
            mazeMap[coordX][coordY] = 'P';
            printf("\n");
            system("cls");
            OutMaze(mazeMap);
            break;
        }
    }

}
int main()
{
    int length = 20;
    char mazeMap[20][20] =
    {
                {'S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S'},
                {'S','o','o','o','o','o','o','S','o','o','o','o','o','o','o','o','o','o','o','S'},
                {'S','S','S','S','S','S','o','S','S','o','S','S','S','S','o','S','S','S','o','S'},
                {'S','o','o','o','o','o','o','o','S','o','o','o','o','o','o','o','S','o','o','S'},
                {'S','o','S','S','S','S','S','o','S','S','S','S','S','S','S','o','S','o','S','S'},
                {'S','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','S','o','S','S'},
                {'S','S','o','S','S','S','S','S','S','S','S','S','S','S','S','S','S','o','S','S'},
                {'S','S','o','o','o','o','o','S','o','o','o','o','o','o','o','o','o','o','S','S'},
                {'S','S','S','S','S','S','o','S','o','S','S','S','S','S','S','S','S','S','S','S'},
                {'S','S','o','o','o','S','o','S','o','S','S','S','S','S','S','S','S','S','S','S'},
                {'S','S','o','S','o','S','o','S','o','o','o','o','o','o','o','o','o','S','S','S'},
                {'S','S','o','S','o','S','o','S','o','S','S','S','S','S','S','S','o','S','S','S'},
                {'S','S','o','S','o','o','o','S','o','S','o','S','o','o','o','o','o','S','S','S'},
                {'S','S','o','o','S','o','S','S','o','S','o','o','o','S','S','S','S','S','S','S'},
                {'S','S','S','o','S','o','S','S','S','S','S','o','S','S','S','S','S','S','S','S'},
                {'S','S','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','S','S'},
                {'S','o','o','S','S','S','S','S','S','S','o','S','S','S','S','S','S','o','S','S'},
                {'S','o','S','S','o','o','S','o','o','o','o','o','o','o','o','o','o','o','S','S'},
                {'S','o','o','o','o','S','W','o','S','S','S','S','S','S','S','S','S','o','S','S'},
                {'S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S'},
    };
    PlayerLocation(mazeMap);
    OutMaze(mazeMap);
    printf("--------------------------\n");
    printf("Press SPACE to Exit");
    printf("\n");
    printf("Play with: W, A, S, D:\n");
    printf("Press ENTER to input move;");
    printf("\n--------------------------\n");

    char keyDown = KeyPressed();
    while(keyDown != ' ')
    {

       keyDown = KeyPressed();
       PlayerMovement(mazeMap, keyDown);

    }


    return 0;
}
