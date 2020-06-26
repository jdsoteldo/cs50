#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int width;
    do
    {
        width = get_int("Width: "); // asks user for the desired width
    }
    while (width < 1 || width > 8); // verifies the user input is a number between 1-8

    for (int x = 0; x < width; x++)
    {
        for (int dot = x; dot < width - 1 ; dot++)
        {
            printf(" "); //this space fixes the element to the right
        }
        for (int hash = 0; hash < x + 1; hash++) // a hash will be printed as many times as user set the width of the stairs
        {
            printf("#");
        }
        printf("\n"); //prints new line each time the set of hashes is printed.
    }
}
