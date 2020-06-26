#include <cs50.h>
#include <stdio.h>
#include <math.h> // new mathemathics library for the round function

int main(void)
{
    float cents;
    int coins = 0;

    do
    {
        cents = get_float("How much are you owed?\n");  //ask user how much change he needs
    }
    while (cents < 0 );

    int change_total = round(cents * 100); // new variable to store how much is owed in integer form instead of float form

    while (change_total >= 25) // if change is 25, add one coin (quarter) and substract the amount to the change_total variable
    {
        coins++;
        change_total -= 25;
    }

    while (change_total >= 10) // same as above but with dimes
    {
        coins++;
        change_total -= 10;
    }

    while (change_total >= 5) // nickes
    {
        coins++;
        change_total -= 5;
    }

    while (change_total >= 1) //pennies
    {
        coins++;
        change_total -= 1;
    }
    printf("the minimum amount of coins is: %i\n", coins);
}
