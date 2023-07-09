#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize)
{
    char letters[strlen(licensePlate)];
    for (size_t i = 0; i < strlen(licensePlate); i++)
    {
        if (isalpha(licensePlate[i]) != 0) 
        {
            letters[i] = tolower(licensePlate[i]);
        }
    }

    int aux = 0;
    char shortest[wordsSize];
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; j < strlen(letters); j++)
        {
            for (int h = 0; h < strlen(words[i]); h++)
            {
                if(words[i][h] == letters[j])
                {
                    aux++;
                }
                if (aux == strlen(letters))
                {
                    shortest[j] = words[i][h];
                }                
            }
        }
    }
    return shortest;
}

int main()
{
    char * defWord = (char *)malloc(7 * sizeof(char));
    char a[7] = {"1s3 PSt"};
    defWord = &a;
    char ** wordArr = (char **)malloc(4 * sizeof(char*));
    char w[4][8] = {{"step"},{"steps"},{"stripe"},{"stepple"}};
    wordArr = &w;
    int size = 4;
    printf("%s", shortestCompletingWord(defWord, wordArr, size));
}
