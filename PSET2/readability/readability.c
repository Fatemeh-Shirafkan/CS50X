#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    // Get the text

    string text = get_string("Text: ");

    float letters = 0;
    float words = 1;
    float sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        // Calculate the number of letters
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            letters++;
        };

        // Calculate the number of words
        if (text[i] == 32)
        {
            words++;
        };

        // Calculate the number of sentences
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        };
    };

    float L = 100 * (letters / words);
    float S = 100 * (sentences / words);

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Check the result

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    };
}