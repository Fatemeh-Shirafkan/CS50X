#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Get the message

    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text); i++)
    {
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};

        int character = text[i];

        int m = 0;
        while (character > 0)
        {
            binary[m] = character % 2;
            character = character / 2;

            m++;
        };

        // Reverce

        for (int n = BITS_IN_BYTE - 1; n >= 0; n--)
        {
            print_bulb(binary[n]);
        };
        printf("\n");
    };
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
