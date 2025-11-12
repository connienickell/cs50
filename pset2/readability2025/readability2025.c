#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void) {
    // get text
    string userText;
    do {
        userText = get_string("Text:");
    }
    while (strlen(userText) < 1);

    int letterCount = 0;
    int wordCount = 1;
    int sentenceCount = 0;
    // calculate letters, words, sentences
    for (int i = 0, q = strlen(userText); i < q; i ++)
    {
        if ((userText[i] > 64 && userText[i] < 91) || (userText[i] > 96 && userText[i] < 123))
        {
            letterCount++;
        }
        else if (userText[i] == 32)
        {
            wordCount++;
        }
        else if (userText[i] == 46 || userText[i] == 33 || userText[i] == 63)
        {
            sentenceCount++;
        }
    }
    printf("%i \n", letterCount);
    printf("%i \n", wordCount);
    printf("%i \n", sentenceCount);

    // L is the average number of letters per 100 words in the text
    float L = ((float)letterCount/wordCount) * 100;

    // S is the average number of sentences per 100 words in the text
    float S = ((float)sentenceCount/wordCount)* 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int gradeLevel = round(index);

    // find grade level:
    if (gradeLevel < 1)
    {
        printf("Before Grade 1 \n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+ \n");
    } else
    {
        printf("Grade %i \n", gradeLevel);
    }
    return 0;
}

/* index = 0.0588 * L - 0.296 * S - 15.8

input of text
calculate L
calculate S
find Grade level of index
print Grade level
*/
