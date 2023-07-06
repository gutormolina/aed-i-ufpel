#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize);

int main()
{
    int tam = 10;
    int* vetor = (int *)malloc(tam * sizeof(int));
    vetor[0] = 1;
    for (int i = 1; i < tam; i++)
    {
        vetor[i] = vetor[i - 1] + 1;
    }
    int* retorno = (int *)malloc(sizeof(int));
    vetor = runningSum(vetor, tam, retorno);
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }
    free(vetor);
    free(retorno);
}

int* runningSum(int* nums, int numsSize, int* returnSize){
    int result = 0;
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) 
    {
        result += nums[i];
        nums[i] = result;
    }
    return nums;
}