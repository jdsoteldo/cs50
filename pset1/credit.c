#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card_num = 0LL;

    while (card_num < 1LL || card_num > 9999999999999999LL)
    {
        card_num = get_long("Please give me your credit card number: ");
    }

    // Make a copy of the card number to be used and modified throughout the process.

    long card_num_copy = card_num;

    // Isolate every digit from the credit card number using a loop and the variable 'digit'.
    // Keep track of the amount and position of each digit using variable 'count'.

    int card_num_count = 0;

    while (card_num_copy > 0LL)
    {
        card_num_copy = card_num_copy / 10LL;
        card_num_count++;
    }

    // If the number entered doesn't have the right amount of digits according
    // to variable 'count', declare the number as invalid.

    if (card_num_count != 13 && card_num_count != 15 && card_num_count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Reset value of variable 'card_num_copy' and apply calculations that will isolate the first two digits.
    // Store the results in a variable 'company_id'.

    card_num_copy = card_num;

    while (card_num_copy > 100LL)
    {
        card_num_copy = card_num_copy / 10LL;
    }

    int company_id = card_num_copy;

    // Print the type of credit card depending on the company ID and amount of digits.

    if (company_id > 50 && company_id < 56 && card_num_count == 16)
    {
        printf("MASTERCARD\n") ;
    }
    else if ((company_id == 34 || company_id == 37) && (card_num_count == 15))
    {
        printf("AMEX\n") ;
    }
    else if ((company_id / 10 == 4) && (card_num_count == 13 || card_num_count == 16))
    {
        printf("VISA\n") ;
    }
    else
    {
        printf("INVALID\n");
    }

    // Luhn's algorithm.

    int sum = 0;

    card_num_copy = card_num;

    for (int i = 1; i <= card_num_count; i++)
    {
        int digit = card_num_copy % 10LL;

        if (i % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;

        card_num_copy /= 10LL;
    }

    // Checking the validity of the number according to Luhn's algorithm

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    return 0;
}
