#include <stdio.h>
#include <stdlib.h>

int minCostClimbingStairs(int *cost, int costSize)
{
    int i = 2;

    for (i; i < costSize; i++) // soma os custos até a última posição
    {
        if (cost[i - 1] > cost[i - 2])
        {
            cost[i] += cost[i - 2];
        } else {
            cost[i] += cost[i - 1];
        }
    }

    if (cost[i - 1] > cost[i - 2]) // retorna o menor
    {
        return cost[i - 2];
    } else {
        return cost[i - 1];
    }
}

int main()
{
    int x[10] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int(*a)[10] = &x;
    int size = 10;
    printf("%d", minCostClimbingStairs(*a, size));
}