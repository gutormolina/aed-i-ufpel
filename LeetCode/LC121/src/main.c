#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
    int maxProfit = 0;
    int minPrice = prices[0];
    
    for (int i = 1; i < pricesSize; i++)
    {
        int currentProfit = prices[i] - minPrice;
        if (currentProfit > maxProfit)
            maxProfit = currentProfit;

        if (prices[i] < minPrice)
            minPrice = prices[i];
    }

    return maxProfit;
	
}

int main()
{
    int size = 6;
    int a[6] = {7,1,5,3,6,4};
	int(*array)[6] = &a;
    printf("%d", maxProfit(*array, size));
}