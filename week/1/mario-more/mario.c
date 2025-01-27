#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt for user input and handle invalid ones
    int height = 0;
    do {
        height = get_int("Height: ");
    } while(height < 1);


    // Build pyramid
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < (height - 1) - i; j++) // Print `(height - 1) - i` blankspaces
        {
            printf(" ");
        }

        for(int k = 0; k <= i; k++) // Print `i + 1` hashes (left side of pyramid)
        {
            printf("#");
        }

        printf("  "); // Add center gap

        for(int u = 0; u <= i; u++) // Print `i + 1` hashes (right side of pyramid)
        {
            printf("#");
        }

        printf("\n"); // Go to next row
    }
}
