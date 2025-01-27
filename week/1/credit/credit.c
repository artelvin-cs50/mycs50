#include <stdio.h>
#include <cs50.h>
#include <math.h>


// American Express uses 15-digit numbers | American Express numbers start with 34 or 37
// MasterCard uses 16-digit numbers | MasterCard numbers start with 51, 52, 53, 54, or 55
// Visa uses 13- and 16-digit numbers | Visa numbers start with 4


char get_card_type(long number);    // Function to identify card type using length and initial digits
bool luhn_valid(long number);    // Function to validate card using Luhn's algorithm


int main(void)
{
    // Prompt user for card number
    long cardNumber = get_long("Number: ");

    char cardType = get_card_type(cardNumber);

    if(luhn_valid(cardNumber))
    {
        if(cardType == 'A')
        {
            printf("AMEX\n");
        }
        else if(cardType == 'M')
        {
            printf("MASTERCARD\n");
        }
        else if(cardType == 'V')
        {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }

}


char get_card_type(long number)
{
    int length = 0;
    long numberTemp = number;
    while(numberTemp > 0)
    {
        numberTemp /= 10;
        length++;
    }

    int digits = number / pow(10, (long)length - 2);


    if(length == 15 && (digits == 34 || digits == 37))
    {
        return 'A';
    }
    else if(length == 16 && (digits >= 51 && digits <= 55))
    {
        return 'M';
    }
    else if((length == 13 || length == 16) && (digits >= 40 && digits <= 49))
    {
        return 'V';
    }
    else
        return 'I';
}


bool luhn_valid(long number)
{
    int sum = 0;
    while(number > 0)
    {
        sum += number % 10;     // Start by adding the last digit (which belongs to the digits that aren't multiplied by 2) to the total sum

        number /= 10;       // Go to next digit

        if(((number % 10) * 2) >= 10)       // Check if the product of the multiplied digit has two digits
        {
            int product = (number % 10) * 2;
            sum += (product % 10);
            sum += (product / 10);
        } else {
            sum += (number % 10) * 2;
        }

        number /= 10;
    }

    if(sum % 10 == 0)
        return true;
    else
        return false;
}
