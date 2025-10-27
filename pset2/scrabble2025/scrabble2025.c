#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculateScore(string word);

int main (void){
    // prompt players
    string POneWrd = get_string("Player 1, please type your word: ");
    string PTwoWrd = get_string("Player 2, please type your word: ");

    int POneScore = calculateScore(POneWrd);
    int PTwoScore = calculateScore(PTwoWrd);

    if (POneScore > PTwoScore){
        printf("Player one wins! \n");
    }
    else if (POneScore < PTwoScore){
        printf("Player two wins! \n");
    }
    else {
        printf("It's a tie! \n");
    }
}


int calculateScore(string word){
    int wordSum = 0;
    for (int i = 0, len = strlen(word); i < len; i++){
        if (isupper(word[i]))
        {
            wordSum += values[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            wordSum += values[word[i] -'a'];
        }
    }
     return wordSum;
}
