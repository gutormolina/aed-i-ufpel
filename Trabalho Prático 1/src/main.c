#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *shortestCompletingWord(char *licensePlate, char **words, int wordsSize)
{
    char letters[strlen(licensePlate) + 1];
    int letCount = 0;
    for (unsigned int i = 0; i < strlen(licensePlate); i++)
    {
        if (isalpha(licensePlate[i]) != 0) // Checa se o caractere em licensePlate é uma letra.
        {
            letters[letCount] = tolower(licensePlate[i]); // Grava a letra em sua forma minúscula no array letters.
            letCount++;
        }
    }
    letters[letCount] = '\0';

    int acceptableWords[wordsSize];
    for (int i = 0; i < wordsSize; i++)
    {
        acceptableWords[i] = 0; // Zera o array acceptableWords.
    }
    
    int aux = 0;
    for (int i = 0; i < wordsSize; i++) // Percorre o "eixo y" (palavras) da matriz words.
    {
        char reading[strlen(words[i]) + 1];
        strcpy(reading, words[i]); // Copia a palavra a ser verificada para um array auxiliar.

        unsigned int count = 0;
        for (unsigned int j = 0; j < strlen(letters); j++) // Percorre o array letters.
        {
            for (unsigned int k = 0; k < strlen(reading); k++) // Percorre o "eixo x" (letras) da matriz words.
            {
                if (reading[k] == letters[j]) // Checa se a letra está no array letters.
                {
                    reading[k] = ' '; // Apaga a letra do array auxiliar.
                    count++;
                    break;
                }
            }
            if (count == strlen(letters)) // Checa se todas as letras foram encontradas.
            {
                acceptableWords[aux] = i; // Armazena o índice da palavra correspondida.
                aux++;
            }
        }
    }

    int shortest = acceptableWords[0];
    for (int i = 0; i < aux; i++) // Descobre a menor palavra correspondente.
    {
        if (strlen(words[acceptableWords[i]]) < strlen(words[shortest]))
        {
            shortest = acceptableWords[i]; // Grava o índice da menor palavra correspondente.
        }
    }

    return words[shortest];
}

int main()
{
    char defWord[] = "1s3 PSt";
    char *wordArr[4] = {"step","steps","stripe","stepple"};
    int size = 4;
    printf("%s", shortestCompletingWord(defWord, wordArr, size));
}