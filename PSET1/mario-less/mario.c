#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for the height of pyramid

    int pyramidHeight;
    do
    {
        pyramidHeight = get_int("Enter the height of the pyramid: ");
    }
    while (pyramidHeight < 1 || pyramidHeight > 8);

    // Counting lines based on user input

    for (int i = 0 ; i < pyramidHeight ; i++)
    {
        // Space to reverse the pyramid

        for (int j = 0 ; j < pyramidHeight - (i + 1) ; j++)
        {
            printf(" ");
        };

        // Print how many squares in each line

        for (int l = 0; l <= i ; l++)
        {
            printf("#");
        };

        printf("\n");
    };

}