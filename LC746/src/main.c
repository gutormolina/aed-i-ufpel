/* You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.*/

#include <stdio.h>

int main(int argc, char const *argv[])
{   
    int *array = (int *)malloc(10 * sizeof(int));
    array;
    int tam = 10;
    printf("%d", minCostClimbingStairs(array, tam));
    return 0;
}

int minCostClimbingStairs(int *cost, int costSize)
{
    int minimumCost = 0, i = 0;

    for (int i = 0; i < costSize-2; i++)
    {
        if (cost[i] > cost[i + 1])
        {
            i = i + 1;
        }
        
        minimumCost += cost[i];
    }
    
    return minimumCost;
}