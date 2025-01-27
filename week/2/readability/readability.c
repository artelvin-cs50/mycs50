#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// index = 0.0588 * L - 0.296 * S - 15.8
// L is the average number of letters per 100 words in the text | L = (letters / words) * 100
// S is the average number of sentences per 100 words in the text | S = (sentences / words) * 100


int get_index(int letters, int words, int sentences);        // Function to calculate Coleman-Liau index
int count_letters(string text);     // Function to count letters,
int count_words(string text);       // words, and
int count_sentences(string text);   // sentences in a text


int main(void)
{
    // Prompt user for text input
    string text = get_string("Text: ");

    // Store word, letter, and sentence count
    int letterCount = count_letters(text),
        wordCount = count_words(text),
        sentenceCount = count_sentences(text);

    // Calculate Coleman-Liau index
    int index = get_index(letterCount, wordCount, sentenceCount);

    // Print grade level
    if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

}


int count_letters(string text)
{
    int count = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}


int count_words(string text)
{
    int count = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == ' ')
        {
            count++;
        }
    }
    count++;        // Account for the last word in the text which ends with not a space but a period/./
    return count;
}


int count_sentences(string text)
{
    int count = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text [i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}


// index = 0.0588 * L - 0.296 * S - 15.8
// L is the average number of letters per 100 words in the text | L = (letters / words) * 100
// S is the average number of sentences per 100 words in the text | S = (sentences / words) * 100
int get_index(int letters, int words, int sentences)
{
    float L = ((float)letters / words) * 100.0;
    float S = ((float)sentences / words) * 100.0;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);        // Return rounded off index
}
