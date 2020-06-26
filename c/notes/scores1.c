// Averages three numbers using an array

#include <cs50.h>
#include <stdio.h>

const int n = 3
int main(void)
{
    // Scores
    int scores[n];
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;

    // Print average
    printf("Average: %i\n", (scores[0] + scores[1] + scores[2]) / n);
}
