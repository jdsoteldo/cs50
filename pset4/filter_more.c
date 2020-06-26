#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            gray = round((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.000);
            // averages the sum of the of the RGB

            image[h][w].rgbtRed = gray;
            image[h][w].rgbtGreen = gray;
            image[h][w].rgbtBlue = gray;
            // equals the red green and blue into the gray shade
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            int temporal[3] = { image[h][w].rgbtRed, image[h][w].rgbtGreen, image[h][w].rgbtBlue };

            image[h][w].rgbtRed =  image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w -  1].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;

            image[h][width - w - 1].rgbtRed = temporal[0];
            image[h][width - w - 1].rgbtGreen = temporal[1];
            image[h][width - w - 1].rgbtBlue = temporal[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blurRed;
    int blurGreen;
    int blurBlue;
    float counter;
    RGBTRIPLE temporal[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            blurRed = 0;
            blurGreen = 0;
            blurBlue = 0;
            counter = 0.00;

            // loops thru the neighbour pixels
            for (int n = -1; n < 2; n++)
            {
                if (h + n < 0 || h + n > width - 1)
                {
                    continue;
                }

                for (int x = -1; x < 2; x++)
                {
                    if (w + x < 0 || w + x > width - 1)
                    {
                        continue;
                    }

                    blurRed += image[h + n][w + x].rgbtRed;
                    blurGreen += image[h + n][w + x].rgbtGreen;
                    blurBlue += image[h + n][w + x].rgbtBlue;
                    counter++;
                }
            }

            temporal[h][w].rgbtRed = round(blurRed / counter);
            temporal[h][w].rgbtGreen = round(blurGreen / counter);
            temporal[h][w].rgbtBlue = round(blurBlue / counter);
        }
    }

    for (int w = 0; w < width; w++)
    {
        for (int h = 0; h < height; h++)
        {
            image[h][w].rgbtRed = temporal[h][w].rgbtRed;
            image[h][w].rgbtGreen = temporal[h][w].rgbtGreen;
            image[h][w].rgbtBlue = temporal[h][w].rgbtBlue;
        }
    }
    return;
}

int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])

{
    //create temporary values to store the calculations
    float sumBlueY;
    float sumGreenY;
    float sumRedY;
    float sumBlueX;
    float sumGreenX;
    float sumRedX;
    float modifierX;
    float modifierY;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temporal[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //Resets values for every pixel
            sumBlueY = 0.0;
            sumGreenY = 0.0;
            sumRedY = 0.0;
            sumBlueX = 0.0;
            sumGreenX = 0.0;
            sumRedX = 0.0;

            // sums values of the pixel and 8 neighboring ones after applying a modifier, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    // calculates modifiers for vertical and horizantal borders
                    modifierX = (k + 1 * k - k * abs(h));
                    modifierY = (h + 1 * h - h * abs(k));

                    sumBlueX += image[j + k][i + h].rgbtBlue * modifierX;
                    sumGreenX += image[j + k][i + h].rgbtGreen * modifierX;
                    sumRedX += image[j + k][i + h].rgbtRed * modifierX;

                    sumBlueY += image[j + k][i + h].rgbtBlue * modifierY;
                    sumGreenY += image[j + k][i + h].rgbtGreen * modifierY;
                    sumRedY += image[j + k][i + h].rgbtRed * modifierY;
                }
            }

            // obtains the final values of the pixels combining X and Y calculations
            temporal[j][i].rgbtBlue = limit(round(sqrt(sumBlueX * sumBlueX + sumBlueY * sumBlueY)));
            temporal[j][i].rgbtGreen = limit(round(sqrt(sumGreenX * sumGreenX + sumGreenY * sumGreenY)));
            temporal[j][i].rgbtRed = limit(round(sqrt(sumRedX * sumRedX + sumRedY * sumRedY)));
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temporal[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temporal[j][i].rgbtGreen;
            image[j][i].rgbtRed = temporal[j][i].rgbtRed;
        }
    }
    return;

}
// abs( ) function in C returns the absolute value of an integer. The absolute value of a number is always positive. Only integer values are supported in C.
// “stdlib.h” header file supports abs( ) function in C language. Syntax for abs( ) function in C is given below.
// int abs ( int n );
