#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < width ;r++)
    {
        for (int c = 0; c < height ;c++)
        {
            if (image[c][r].rgbtBlue == 0 && image[c][r].rgbtRed == 0 && image[c][r].rgbtGreen == 0)
            {
                image[c][r].rgbtRed = 255;
                image[c][r].rgbtBlue = 75;
                image[c][r].rgbtGreen = 213;
            }
        }
    }
}
