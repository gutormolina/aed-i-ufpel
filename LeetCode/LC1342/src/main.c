#include <stdio.h>

int numberOfSteps(int num)
{
    int i = 0;
    for (i; num != 0; i++)
    {
        if (num % 2 == 0)
        {
            num = num / 2;
        } else {
            num = num - 1;
        }
    }
    return i;
}

int main()
{
    int n = 14;
    printf("%d", numberOfSteps(n));
}