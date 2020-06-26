#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string text = get_string("Text: "); // prompts user for a text
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        else if (text[i] == ' ') // every space equals a new word
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float grade_level = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentences / (float) words) - 15.8;
    //float variable used to define the coleman-liau index
    if (grade_level >= 1 && grade_level < 16)
    {
        printf("Grade %i\n", (int) round(grade_level)); //round the grade level to compare it with a US grade level.
    }
    else if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level > 16)
    {
        printf("Grade 16+\n");
    }
}


//Note to self: This was a pretty good exercise, pretty witty and actually helpful and applicable in the real world, unfortunately I didnt manage to use the isalpha() method. need to practice the methods implementation on C!!
