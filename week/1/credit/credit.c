#include <stdio.h>
#include <cs50.h>
#include <math.h>


// American Express uses 15-digit numbers | American Express numbers start with 34 or 37
// MasterCard uses 16-digit numbers | MasterCard numbers start with 51, 52, 53, 54, or 55
// Visa uses 13- and 16-digit numbers | Visa numbers start with 4


int get_length(long number);    // Function to get card length
int get_initial_digits(long number, int length)    // Function to get card's initial digits


int main(void)
{
    // Prompt user for card number
    long card_number = get_long("Number: ");

}


int get_length(long number)
{
    int count = 0;
    while(number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}


int get_initial_digits(long number, int length)
{
    return number / (pow(length - 2));
}
