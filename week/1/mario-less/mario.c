#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for height and handle invalid ones
    int height = 0;
    do {
        height = get_int("Height: ");
    } while(height < 1);


    // Build pyramid
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < (height - i) - 1; j++) // Print `(height - 1) - i` blankspaces
        {
            printf(" ");
        }

        for(int k = 0; k <= i; k++) // Print `i + 1` hashes
        {
            printf("#");
        }

        printf("\n"); // Go to next row
    }
}
