#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digit(string key);
void caesar(string plaintext, int k);

int main(int argc, string argv[])
{
//check argc
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

//check key = int or not?
    if(!only_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

//input plaintext
    string input_text = get_string("plaintext:  ");

//encryption
    int k = atoi(argv[1]);
    caesar(input_text, k);
}

bool only_digit(string key)
{
    for(int i = 0, l = strlen(key); i < l; i++)
    {
        if(key[i] < 48 || key[i] > 57)
        {
            return false;
        }
    }
    return true;
}

void caesar(string plaintext, int k)
{
    for(int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if(plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = (plaintext[i] - 'A' + k) % 26 + 'A';
        }
        else if(plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] = (plaintext[i] - 'a' + k) % 26 + 'a';
        }
    }
    printf("ciphertext: %s\n",plaintext);
}

