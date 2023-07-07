#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int romanToInt(char * s)
{
    int sum = 0;
    for (unsigned int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'I' && s[i + 1] == 'V')
        {
            sum = sum + 4;
            i++;
        } else if (s[i] == 'I' && s[i + 1] == 'X')
        {
            sum = sum + 9;
            i++;
        } else if (s[i] == 'X' && s[i + 1] == 'L')
        {
            sum = sum + 40;
            i++;
        } else if (s[i] == 'X' && s[i + 1] == 'C')
        {
            sum = sum + 90;
            i++;
        } else if (s[i] == 'C' && s[i + 1] == 'D')
        {
            sum = sum + 400;
            i++;
        } else if (s[i] == 'C' && s[i + 1] == 'M')
        {
            sum = sum + 900;
            i++;
        } else
        {
            switch (s[i])
            {
            case 'I':
                sum += 1;
                break;
            
            case 'V':
                sum += 5;
                break;
            
            case 'X':
                sum += 10;
                break;

            case 'L':
                sum += 50;
                break;

            case 'C':
                sum += 100;
                break;

            case 'D':
                sum += 500;
                break;

            case 'M':
                sum += 1000;
                break;

            default:
                break;
            }
        }
    }
    
    return sum; 
}

int main()
{
    char *string = (char *)malloc(7 * sizeof(char));
    string = "MCMXCIV";
    printf("%d", romanToInt(string));
}