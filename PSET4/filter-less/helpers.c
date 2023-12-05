#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int mainRed;
    int mainBlue;
    int mainGreen;
    float grayOut;

    for (int i = 0; i < height ;i++)
    {
        for(int j = 0; j < width ;j++)
        {
            mainRed = image[i][j].rgbtRed;
            mainBlue = image[i][j].rgbtBlue;
            mainGreen = image[i][j].rgbtGreen;

            grayOut = round((mainBlue + mainGreen + mainRed) / 3.0);

            image[i][j].rgbtRed = grayOut;
            image[i][j].rgbtBlue = grayOut;
            image[i][j].rgbtGreen = grayOut;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int orgRed;
    int orgBlue;
    int orgGreen;

    float sepiaRed;
    float sepiaBlue;
    float sepiaGreen;

    for (int i = 0; i < height ;i++)
    {
        for (int j = 0; j < width ;j++)
        {
            orgRed = image[i][j].rgbtRed;
            orgBlue = image[i][j].rgbtBlue;
            orgGreen = image[i][j].rgbtGreen;

            sepiaRed = .393 * orgRed + .769 * orgGreen + .189 * orgBlue;
            if (sepiaRed > 255)
            {
                 sepiaRed = 255;
            }
            sepiaGreen = .349 * orgRed + .686 * orgGreen + .168 * orgBlue;
            if (sepiaGreen > 255)
            {
                 sepiaGreen = 255;
            }
            sepiaBlue = .272 * orgRed + .534 * orgGreen + .131 * orgBlue;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE rowplace[width];

    for (int i = 0; i < height ;i++)
    {
        for(int j = 0; j < width ;j++)
        {
            rowplace[j] = image[i][j];
        }
        for(int l = 0; l < width ;l++)
        {
            image[i][l].rgbtRed = rowplace[width - l - 1].rgbtRed;
            image[i][l].rgbtBlue = rowplace[width - l - 1].rgbtBlue;
            image[i][l].rgbtGreen = rowplace[width - l - 1].rgbtGreen;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height ;i++)
    {
        for (int j = 0; j < width ;j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height ;i++)
    {
        for (int j = 0; j < width ;j++)
        {
            int count = 0;
            float redSum = 0;
            float blueSum = 0;
            float greenSum = 0;

            for (int l = -1; l < 2; l++)
            {
                for (int t = -1; t < 2; t++)
                {
                    if ((i+l < 0 || i+l >= height || j+t < 0 || j+t >= width))
                    {
                        redSum += copy[i + l][j + t].rgbtRed;
                        blueSum += copy[i + l][j + t].rgbtBlue;
                        greenSum += copy[i + l][j + t].rgbtGreen;
                        count++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            image[i][j].rgbtRed = (int)round(redSum / count);
            image[i][j].rgbtBlue = (int)round(blueSum / count);
            image[i][j].rgbtGreen = (int)round(greenSum / count);
        }
    }
}
