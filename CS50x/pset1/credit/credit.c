#include <stdio.h>
#include <cs50.h>
#include <math.h>

long credit;
int sum, len;

int count(long x);
int luhn(long number);
void check();

int main(void)
{
    credit = get_long("Number: ");
    len = count(credit);
    luhn(credit);
    check();
}











int count(long x)
{
    int l = 0;
    do
    {
        l++;
        x /= 10;
    }
    while (x > 0);
    return l;
}







int luhn(long number)
{
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 1; i < len; i += 2)
    {
        int digit = (number / (long)pow(10, i)) % 10;

        digit *= 2;

        if (digit > 9)
        {
            digit = digit / 10 + digit % 10;
        }

        sum1 += digit;
    }

    for (int j = 0; j < len; j += 2)
    {
        sum2 += (number / (long long)pow(10, j)) % 10;
    }

    sum = sum1 + sum2;
    return sum;
}



void check()
{
    if(sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (len == 15 && (credit / 10000000000000 == 34 || credit / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if (len == 16 && (credit / 100000000000000 >= 51 && credit / 100000000000000 <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((len == 13 && credit / 1000000000000 == 4) || (len == 16 && credit / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
