#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(char *s);
char rotate(char plainTextChar, char *s);

int main(int argc, char *argv[])
{
    //check argcount
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) == 1)
    {
        return 1;
    }

    // get string from user
    string userText = get_string("plaintext: ");

    // store length of user string
    int textLen = strlen(userText);

    printf("ciphertext: ");

    // loop through and modify each char
    for (int i = 0; i < textLen; i++)
    {
        userText[i] = rotate(userText[i], argv[1]);
        printf("%c", userText[i]);
    }
    printf("\n");
    return 0;
}


//ensure arg contains only digits
int only_digits(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if(!isdigit(s[i])){
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}


//modify each character
char rotate(char plainTextChar, char *s)
{
    int mod = atoi(s) % 26;
    char cipheredChar;
    
    if (!isalpha(plainTextChar))
    {
        return plainTextChar;
    }

    if (isupper(plainTextChar))
    {
        cipheredChar = plainTextChar + mod;
        if (cipheredChar > 'Z')
        {
            int remainder = cipheredChar - ('Z' + 1);
            cipheredChar = 'A' + remainder;
        }
    }
    else if (islower(plainTextChar))
    {
        cipheredChar = plainTextChar + mod;
        if (cipheredChar > 'z')
        {
            int remainder = cipheredChar - ('z' + 1);
            cipheredChar = 'a' + remainder;
        }
    }
    return cipheredChar;
}
