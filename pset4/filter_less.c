#include <math.h>
#include "helpers.h"


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbtGray;

    for (int i = 0; i < width; i++)
    {
        for (int n = 0; n < height; n++)
        {
            rgbtGray = round((image[n][i].rgbtRed + image[n][i].rgbtGreen + image[n][i].rgbtBlue) / 3.000);
            // averages the sum of the RBG

            image[n][i].rgbtRed = rgbtGray;
            image[n][i].rgbtGreen = rgbtGray;
            image[n][i].rgbtBlue = rgbtGray;
            // equales each rbg into the rgbtGray average
        }
    }
    return;
}

int rgb_limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    for (int i = 0; i < width; i++)
    {
        for (int n = 0; n < height; n++)
        {
            sepiaRed = rgb_limit(round(0.393 * image[n][i].rgbtRed + 0.769 * image[n][i].rgbtGreen + 0.189 * image[n][i].rgbtBlue));
            sepiaGreen = rgb_limit(round(0.349 * image[n][i].rgbtRed + 0.686 * image[n][i].rgbtGreen + 0.168 * image[n][i].rgbtBlue));
            sepiaBlue = rgb_limit(round(0.272 * image[n][i].rgbtRed + 0.534 * image[n][i].rgbtGreen + 0.131 * image[n][i].rgbtBlue));
            // adding the sepia value to the rbg

            image[n][i].rgbtRed = sepiaRed;
            image[n][i].rgbtGreen = sepiaGreen;
            image[n][i].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int row = 0; row < width / 2; row++)
    {
        for (int j = 0; j < height; j++)
        {
            int temporal[3] = {image[j][row].rgbtRed, image[j][row].rgbtGreen, image[j][row].rgbtBlue};
            // swaps the pixels
            image[j][row].rgbtRed = image[j][width - row - 1].rgbtRed;
            image[j][row].rgbtGreen = image[j][width - row - 1].rgbtGreen;
            image[j][row].rgbtBlue = image[j][width - row - 1].rgbtBlue;

            image[j][width - row - 1].rgbtRed = temporal[0];
            image[j][width - row - 1].rgbtGreen = temporal[1];
            image[j][width - row - 1].rgbtBlue = temporal[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blurRed;
    int blurGreen;
    int blurBlue;
    float counter;

    // creates a temporary color table to not alter the calc
    RGBTRIPLE temporal[width][height];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            blurRed = 0;
            blurGreen = 0;
            blurBlue = 0;
            counter = 0.00;

            // iterates thru 8 neighbour pixels and sums them
            for (int x = -1; x < 2; x++)
            {
                // goes untile the edge
                if (j + x < 0 || j + x > width - 1)
                {
                    continue;
                }

                // goes until the edge of the picture
                for (int y = -1; y < 2; y++)
                {
                    if (i + y < 0 || i + y > width - 1)
                    {
                        continue;
                    }

                    blurRed += image[j + x][i + y].rgbtRed;
                    blurGreen += image[j + x][i + y].rgbtGreen;
                    blurBlue += image[j + x][i + y].rgbtBlue;
                    counter++;
                }
            }
            // averages the color to make it look blury(to the nearest integer)
            temporal[j][i].rgbtRed = round(blurRed / counter);
            temporal[j][i].rgbtGreen = round(blurGreen / counter);
            temporal[j][i].rgbtBlue = round(blurBlue / counter);
        }
    }

    for (int i = 0; i  < width; i++)
    {
        for (int x = 0; x < height; x++)
        {
            image[x][i].rgbtRed = temporal[x][i].rgbtRed;
            image[x][i].rgbtGreen = temporal[x][i].rgbtGreen;
            image[x][i].rgbtBlue = temporal[x][i].rgbtBlue;
        }
    }
    return;
}
