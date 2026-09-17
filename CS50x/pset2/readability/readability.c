#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_words(string t);
int count_letters(string t);
int count_sentences(string t);

int main(void)
{
    string text = get_string("Text: ");
    int x = count_words(text);
    float L = count_letters(text) * 100.0 / x;
    float S = count_sentences(text) * 100.0 / x;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_words(string t)
{
    int words = 1;
    int length_text = strlen(t);
    for (int i = 0; i < length_text; i++)
    {
        if (t[i] == ' ')
        {
            words ++;
        }
    }
    return words;
}

int count_letters(string t)
{
    int letters = 0;
    int length_text = strlen(t);
    for (int i = 0; i < length_text; i++)
    {
        if (isupper(t[i]))
        {
            letters ++;
        }
        if (islower(t[i]))
        {
            letters ++;
        }
    }
    return letters;
}

int count_sentences(string t)
{
    int sentences = 0;
    int length_text = strlen(t);
    for (int i = 0; i < length_text; i++)
    {
        if (t[i] == '.' || t[i] == '?' || t[i] == '!')
        {
            sentences ++;
        }
    }
    return sentences;
}
