#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize)
{
    int *wealth = (int *)malloc(accountsSize * sizeof(int));

    for (int i = 0; i < accountsSize; i++)
    {
        wealth[i] = 0;
        
        for (int j = 0; j < *accountsColSize; j++)
        {
            wealth[i] += accounts[i][j];
        }
    }
    
    int richestWealth = 0;
    for (int i = 0; i < accountsSize; i++)
    {
        if (wealth[i] > richestWealth)
        {
            richestWealth = wealth[i];
        }
    }
    
    return richestWealth;
}

int main()
{
    int tamContas = 2;
    int **contas = (int **)malloc(tamContas * sizeof(int));
    int *colContas = (int *)malloc(sizeof(int));
    colContas = 3;
    int con[3][2] = {{1,5},{7,3},{3,5}};
    contas = &con;
    printf("%d", maximumWealth(**contas, tamContas, *colContas));
    free(contas);
    free(colContas);
}
