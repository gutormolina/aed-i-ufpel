#include <stdio.h>
#include <string.h>

int firstUniqChar(char * s)
{
    int aux[strlen(s)];
    
    for (int i = 0; i < strlen(s); i++)
    {
        aux[i] = 0;

        for (int j = 0; j < strlen(s); j++)
        {
            if (s[j] == s[i])
            {
                aux[i]++;
            }
            
        }
        
    }

    int firstIndex = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (aux[i] < aux[firstIndex])
        {
            firstIndex = i;
        }
    }
    
    if (aux[firstIndex] > 1)
    {
        return -1;
    }

    return firstIndex;
}

int main()
{
    char *string = {"leetcode"};
    printf("%d", firstUniqChar(string));
}
