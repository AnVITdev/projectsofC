#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int check(string x);

int main(void)
{
    string player1 = get_string("Player 1 : ");
    string player2 = get_string("Player 2 : ");
    int score1 = check(player1);
    int score2 = check(player2);
    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int check(string x)
{
    int sum = 0;
    for (int i = 0, j = strlen(x); i < j; i++)
    {
        if (isupper(x[i]))
        {
            sum = sum + points[x[i] - 'A'];
        }
        else if (islower(x[i]))
        {
            sum = sum + points[x[i] - 'a'];
        }
    }
    return sum;
}
