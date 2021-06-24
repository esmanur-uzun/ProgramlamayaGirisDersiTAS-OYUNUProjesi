//proje 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int gamer1[2][20], gamer2[2][20];
int hamle = 0, isGameOver = 0;
int gameControl(int, int, int);
int gameOver(int, int, int);

void mainBoard()
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 20; j++)
        {
            gamer1[i][j] = 1;
            gamer2[i][j] = 1;
        }
    }
    printf("\n Baslangicta\n\n");
    return;
}

void printBoard()
{
    int i, j;
    printf("----first player----\n");
    printf("|--------------------------------------------------------------------|");
    printf("\n|        |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11|12|13|14|15|16|17|18|19|20|\n");
    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            printf("|Mavi    |");
        }
        else
        {
            printf("|kirmizi |");
        }
        for (j = 0; j < 20; j++)
        {
            printf("%d |", gamer1[i][j]);
        }
        printf("\n");
    }
    printf("|--------------------------------------------------------------------|");
    printf("\n\n");
    printf("----second player----\n");
    printf("|--------------------------------------------------------------------|");
    printf("\n|        |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11|12|13|14|15|16|17|18|19|20|\n");
    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            printf("|Mavi    |");
        }
        else
        {
            printf("|kirmizi |");
        }
        for (j = 0; j < 20; j++)
        {
            printf("%d |", gamer2[i][j]);
        }
        printf("\n");
    }
    printf("|--------------------------------------------------------------------|");
    return;
}

int game(int chosenPlayer, int color, int man)
{
    if (isGameOver == 0)
    {
        hamle++;
        printf("\n\n%d.hamle\n", hamle);
        printf("secilen oyuncu=%d.oyuncu\n", chosenPlayer);

        if (color == 0)
        {
            printf("rastgele secilen tas : Mavi %d\n", man + 1);
        }
        else
        {
            printf("rastgele secilen tas : Kirmizi %d\n", man + 1);
        }
        printf("\n");
        int i, j;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 20; j++)
            {
                if (chosenPlayer == 1 && color == i && man == j)
                {
                    gamer1[i][j]--;
                    gamer2[i][j]++;
                }
                else if (chosenPlayer == 2 && color == i && man == j)
                {
                    gamer1[i][j]++;
                    gamer2[i][j]--;
                }
            }
        }
        printBoard();
        gameControl(chosenPlayer, color, man);
    }
    return 0;
}

int nextPlayer, nextColor, nextMan;

int gameControl(int controlPlayer, int controlColor, int controlMan)
{
    int firstCondition = (controlMan + 1) * 2 - 1;
    int secondCondition = controlMan - 4;
    if (controlPlayer == 1)
    {
        nextPlayer = 2;
    }
    else
    {
        nextPlayer = 1;
    }
    if ((firstCondition >= 0 && firstCondition < 20) && (secondCondition >= 0 && secondCondition < 20))
    {
        if (nextPlayer == 1)
        {
            if ((gamer1[controlColor][firstCondition] == 1 || gamer1[controlColor][firstCondition] == 2) &&
                (gamer1[!controlColor][secondCondition] == 1 || gamer1[!controlColor][secondCondition] == 2))
            {
                int randomSelectionMan = rand() % 2;
                if (randomSelectionMan == 0)
                {
                    nextColor = controlColor;
                    nextMan = firstCondition;
                }
                else
                {
                    if (controlColor == 0)
                        nextColor = 1;
                    else
                        nextColor = 0;
                    nextMan = secondCondition;
                }
            }
            else if (gamer1[controlColor][firstCondition] == 1 || gamer1[controlColor][firstCondition] == 2)
            {
                nextColor = controlColor;
                nextMan = firstCondition;
            }
            else if (gamer1[!controlColor][secondCondition] == 1 || gamer1[!controlColor][secondCondition] == 2)
            {
                if (controlColor == 0)
                    nextColor = 1;
                else
                    nextColor = 0;
                nextMan = secondCondition;
            }
            else
            {
                isGameOver = 1;
                gameOver(nextPlayer, firstCondition, secondCondition);
            }
        }
        else
        {
            if ((gamer2[controlColor][firstCondition] == 1 || gamer2[controlColor][firstCondition] == 2) &&
                (gamer2[!controlColor][secondCondition] == 1 || gamer2[!controlColor][secondCondition] == 2))
            {
                int randomSelectionMan = rand() % 2;
                if (randomSelectionMan == 0)
                {
                    nextColor = controlColor;
                    nextMan = firstCondition;
                }
                else
                {
                    if (controlColor == 0)
                        nextColor = 1;
                    else
                        nextColor = 0;
                    nextMan = secondCondition;
                }
            }
            else if (gamer2[controlColor][firstCondition] == 1 || gamer2[controlColor][firstCondition] == 2)
            {
                nextColor = controlColor;
                nextMan = firstCondition;
            }
            else if (gamer2[!controlColor][secondCondition] == 1 || gamer2[!controlColor][secondCondition] == 2)
            {
                if (controlColor == 0)
                    nextColor = 1;
                else
                    nextColor = 0;
                nextMan = secondCondition;
            }
            else
            {
                isGameOver = 1;
                gameOver(nextPlayer, firstCondition, secondCondition);
            }
        }
    }
    else if (firstCondition >= 0 && firstCondition < 20)
    {
        if (nextPlayer == 1)
        {
            if (gamer1[controlColor][firstCondition] == 1 || gamer1[controlColor][firstCondition] == 2)
            {
                nextColor = controlColor;
                nextMan = firstCondition;
            }
            else
            {
                isGameOver = 1;
                gameOver(nextPlayer, firstCondition, secondCondition);
            }
        }
        else
        {
            if (gamer2[controlColor][firstCondition] == 1 || gamer2[controlColor][firstCondition] == 2)
            {
                nextColor = controlColor;
                nextMan = firstCondition;
            }
            else
            {
                isGameOver = 1;
                gameOver(nextPlayer, firstCondition, secondCondition);
            }
        }
    }
    else
    {

        if (nextPlayer == 1)
        {
            if (gamer1[!controlColor][secondCondition] == 1 || gamer1[!controlColor][secondCondition] == 2)
            {
                if (controlColor == 0)
                    nextColor = 1;
                else
                    nextColor = 0;
                nextMan = secondCondition;
            }
            else
            {
                isGameOver = 1;
                gameOver(nextPlayer, firstCondition, secondCondition);
            }
        }
        else
        {
            if (gamer2[!controlColor][secondCondition] == 1 || gamer2[!controlColor][secondCondition] == 2)
            {
                if (controlColor == 0)
                    nextColor = 1;
                else
                    nextColor = 0;
                nextMan = secondCondition;
            }
            else
            {
                isGameOver = 1;
                gameOver(nextPlayer, firstCondition, secondCondition);
            }
        }
    }
    game(nextPlayer, nextColor, nextMan);
    return 0;
}
void randomSelect()
{

    int chosenPlayer = (rand() % 2) + 1;
    int color = rand() % 2;
    int man = rand() % 10;
    game(chosenPlayer, color, man);
    return;
}

int gameOver(int losingPlayer, int firstCondition, int secondCondition)
{
    printf("\n\n\t\t<--- Oyun Bitti --->\n");
    printf("\n Toplam hamle: %d\n", hamle);
    printf(" %d. oyuncu kaybetti\n", losingPlayer);

    if ((firstCondition >= 0 && firstCondition < 20) && (secondCondition >= 0 && secondCondition < 20))
    {
        printf(" Elinde ayni renk, %d numarali tas veya farkli renk, %d numarali tas olmadigi icin kaybetti.\n", firstCondition + 1, secondCondition + 1);
    }
    else if (firstCondition >= 0 && firstCondition < 20)
    {
        printf(" Elinde ayni renk, %d numarali tas olmadigi icin kaybetti.\n", firstCondition + 1);
    }
    else
    {
        printf(" Kaybetme nedeni: Elinde farkli renk, %d numarali tas olmadigi icin kaybetti.\n", secondCondition + 1);
    }
    return 0;
}

int main()
{
    srand(time(0));
    printf("\n\t\t<--- Tas Oyunu --->\n");
    mainBoard();
    printBoard();
    randomSelect();
    getch();
    
    return 0;
}
