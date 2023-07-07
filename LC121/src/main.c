#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
    int max = 0, bestBuy = prices[0], bestBuyIndex, bestSell = 0, bestSellIndex;
    for (int i = 0; i < pricesSize; i++)
    {
		if (bestBuy > prices[i])
		{
			bestBuy = prices[i];
			bestBuyIndex = i;
		}
    }
    
	for (int i = bestBuyIndex + 1; i < pricesSize; i++)
	{
		if (bestSell < prices[i])
		{
			bestSell = prices[i];
			bestSellIndex = i;
		}
	}

	return max = prices[bestSellIndex] - prices[bestBuyIndex];
}

int main()
{
    int size = 6;
    int a[6] = {7,1,5,3,6,4};
	int(*array)[6] = &a;
    printf("%d", maxProfit(*array, size));
}