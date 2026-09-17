#include <cs50.h>
#include <stdio.h>

int main(void)
{
// loops until true height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);
// draw
    for (int line = 1; line <= height; line ++)
    {
    // draw left
        // draw space
        for (int space = 0; space < height - line; space++)
        {
            printf(" ");
        }

        // draw #
        for (int hash = 0; hash < line; hash++)
        {
            printf("#");
        }

    // draw mid
        printf("  ");

    // draw right
        // draw #
        for (int hash = 0; hash < line; hash++)
        {
            printf("#");
        }
    // jump to next line
        printf("\n");
    }

}
