#include <stdio.h>

//  Atualiza o sinal que indica quantos índices são == 0;
int updateFlag(int *amount, int amountSize)
{
    int flag = 0;
    for (int i = 0; i < amountSize; i++)
    {
        if (amount[i] == 0)
        {
            flag++;
        }
    }
    
    return flag;
}

int fillCups(int* amount, int amountSize)
{
    int flag = 0;
    flag = updateFlag(amount, amountSize);

    int served = 0;
    int seconds = 0;
    
    //  Enche dois copos
    while (flag < 2)
    {
        flag = 0;
        flag = updateFlag(amount, amountSize);
        int firstCup = 0;
        //  Encontra o maior índice
        for (int i = 0; i < amountSize; i++)
        {   
            if (amount[i] > amount[firstCup])
            {
                firstCup = i;
            }
        } 
        
        //  Inicializa o segundo copo;
        int secondCup = -1;
        
        //  Encontra o segundo maior índice
        for (int i = 0; i < amountSize; i++)
        {   
            if (i != firstCup && amount[i] >= amount[secondCup])
            {
                secondCup = i;
            }
        }
        
        amount[firstCup]--;
        amount[secondCup]--;
        flag = updateFlag(amount, amountSize);
        seconds ++;
    }

    //  Termina de encher o tipo restante
    while (flag < 3)
    {
        flag = 0;
        flag = updateFlag(amount, amountSize);
        int cup = 0;
        for (int i = 0; i < amountSize; i++)
        {
            if (amount[i] > amount[cup])
            {
                cup = i;
            }
        }

        amount[cup]--;
        flag = updateFlag(amount, amountSize);
        seconds ++;
    }

    return seconds;
}

int main()
{
    int size = 3;
    int amount[] = {3, 1, 0};
    printf("%d", fillCups(amount, size));
}