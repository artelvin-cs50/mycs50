#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,        // Store points in an array
                      1, 1, 3, 10, 1, 1,1, 1, 4, 4, 8, 4, 10};


int calculate_points(string word);


int main(void)
{
    string playerOneWord = get_string("Player 1: ");
    string playerTwoWord = get_string("Player 2: ");

    int playerOneScore = calculate_points(playerOneWord), playerTwoScore = calculate_points(playerTwoWord);

    if(playerOneScore > playerTwoScore)
    {
        printf("Player 1 wins!\n");
    }
    else if(playerTwoScore > playerOneScore)
    {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}


int calculate_points(string word)
{
    int points = 0;

    for(int i = 0, n = strlen(word); i < n; i++)
    {
        if(isalpha(word[i]))
        {
            points += POINTS[(tolower(word[i])) - 'a'];     // Subtract the character 'a' which has the 97 ASCII Code to the ith character of the word
                                                            // Use the difference as the index for POINTS[]
        }                                                   // For example, 'b' is 98 in ASCII Code; 'b' - 'a' is the same as 98 - 97 which equals to 1
    }
    return points;
}
