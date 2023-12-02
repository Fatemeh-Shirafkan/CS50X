#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size

    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // Prompt for end size

    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // Calculate number of years until we reach threshold

    int years = 0;
    int x = 0;
    int y = 0;

    while (start < end)
    {

        x = (start / 3);
        y = (start / 4);

        start = start + x - y;
        years++;
    }

    // Print number of years

    printf("Years: %i\n", years);
}
