#include <stdio.h>
#include <cs50.h>

// quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main(void)
{
    // Prompt and handle user input
    int change_owed = 0;
    do
    {
        change_owed = get_int("Change owed: ");
    } while (change_owed < 1);


    // Calculate optimal number of coins
    int coint_count = 0;
    while(change_owed > 0)
    {
        if(change_owed >= QUARTER)
        {
            change_owed -= QUARTER;
            coint_count++;
        }

        else if(change_owed >= DIME)
        {
            change_owed -= DIME;
            coint_count++;
        }

        else if(change_owed >= NICKEL)
        {
            change_owed -= NICKEL;
            coint_count++;
        }

        else
        {
            change_owed -= PENNY;
            coint_count++;
        }
    }

    printf("%d\n", coint_count);
}
