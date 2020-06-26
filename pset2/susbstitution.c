#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>


int main(int argc, string argv[])
{
    // checks for only two arguments to be passed
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // checks to see argv[1] is equal to 26 characters
    int length = strlen(argv[1]);
    if (length != 26)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // iterates thru the entire key to check that are all letters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // if any character is not alpha prints error below
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution KEY");
            return 1;
        }
    }

    // check for repeated characters
    // two counters for each for loop needs a counter to further compare both
    int main_counter = 0;
    int second_counter = 0;
    for (int x = 0; x < length; x++)
    {
        for (int z = 0; argv[1][z] != '\0'; z++)
        {
            second_counter++;
            if (argv[1][z] == argv[1][x])
            {
                main_counter++;
            }
        }
    }

    // if the counter is not equal to length variable then an error occurs cuz length is supposed to be 26
    if (length != main_counter)
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }

    //prompts user input
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //conversion of text into ciphertext
    int input = strlen(plaintext);
    for (int z = 0; z < input; z++)
    {
        for (int l = 0; l < 26; l++)
        {
            if (plaintext[z] == 'a' + l)
            {
                if (argv[1][l] >= 'a' && argv[1][l] <= 'z')
                    //check if the capital is lowercase
                {
                    printf("%c", argv[1][l]);
                }
                else
                {
                    char let = argv[1][l] + 32;
                    printf("%c", let);
                }
            }

            else if (plaintext[z] == 'A' + l)
            {
                if (argv[1][l] >= 'a' && argv[1][l] <= 'z')
                    // check if letter is uppercase
                {
                    char let1 = argv[1][l] - 32;
                    printf("%c", let1);
                }
                else
                {
                    printf("%c", argv[1][l]);
                }
            }
        }

        if (!isalpha(plaintext[z]))
        {
            printf("%c", plaintext[z]);
        }

    }

    printf("\n");
}
// note to self. always make sure to check exactly what is wrong, dont be afraid to dive into those red lines
