# include <cs50.h>
# include <stdio.h>

int coins = 0;
void module(int x);

int main(void)
{
    // get cash > 0
    int cash;
    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash < 0);

    module(cash);
    printf("%i\n", coins);
}

void module(int x)
{
    if ( x % 25 == 0 )
    {
        coins = x / 25;
    }
    else
    {
        int y = x % 25;
        coins = ( x - y ) / 25;
        if ( y % 10 == 0 )
        {
            coins = coins + y/10;
        }
        else
        {
            int z = y % 10;
            coins = coins + ( y - z ) / 10;
            if ( z > 4 )
            {
            coins = coins + 1 + z - 5; // Example: z == 7 -> add coin 5 and (z-5) coins 1
            }
            else
            {
                coins = coins + z;
            }
        }
    }
}
