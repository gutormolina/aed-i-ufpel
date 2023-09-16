#include <stdio.h>
#include <stdlib.h>

int partition(int **intervals, int low, int high)
{
    int *pivot = intervals[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (intervals[j][0] <= pivot[0])
        {
            i++;
            int *temp = intervals[i];
            intervals[i] = intervals[j];
            intervals[j] = temp;
        }
    }

    int *temp = intervals[i + 1];
    intervals[i + 1] = intervals[high];
    intervals[high] = temp;

    return i + 1;
}

void quickSort(int **intervals, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(intervals, low, high);

        quickSort(intervals, low, pivotIndex - 1);  // ordena esquerda
        quickSort(intervals, pivotIndex + 1, high); // ordena direita
    }
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, 
            int *returnSize, int **returnColumnSizes)
{
    if (intervalsSize <= 0)
    {
        *returnSize = 0;

        return NULL;
    }

    quickSort(intervals, 0, intervalsSize - 1); // ordena a lista

    int **returnIntervals = (int **)malloc(sizeof(int *) * intervalsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * intervalsSize);

    int auxIndex = 0;
    returnIntervals[0] = (int *)malloc(sizeof(int) * 2);
    returnIntervals[0][0] = intervals[0][0];
    returnIntervals[0][1] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) // percorre as linhas
    {
        int start1 = returnIntervals[auxIndex][0];
        int end1 = returnIntervals[auxIndex][1];
        int start2 = intervals[i][0];
        int end2 = intervals[i][1];

        if (end1 >= start2) // verifica o overlap
        {
            returnIntervals[auxIndex][0] = start1; // merge
            if (end2 > end1) // checa qual é o maior end
            { 
                returnIntervals[auxIndex][1] = end2;
            }
            else
            {
                returnIntervals[auxIndex][1] = end1;
            }
        }
        else // sem overlap
        {
            auxIndex++;
            returnIntervals[auxIndex] = (int *)malloc(sizeof(int) * 2);
            returnIntervals[auxIndex][0] = start2; // insere no novo array
            returnIntervals[auxIndex][1] = end2;
        }
    }

    *returnSize = auxIndex + 1;
    for (int i = 0; i < *returnSize; i++) // percorre as linhas contando
    {
        (*returnColumnSizes)[i] = 2; // atribui valor de cols para cada linha
    }

    return returnIntervals;
}

int main()
{
    int intervalsSize = 2;
    int intervalsColSize = 2;
    int returnSize;
    int *returnColumnSizes;

    int **intervals = (int **)malloc(intervalsSize * sizeof(int *));
    for (int i = 0; i < intervalsSize; i++)
    {
        intervals[i] = (int *)malloc(intervalsColSize * sizeof(int));
    }

    intervals[0][0] = 1;
    intervals[0][1] = 4;
    intervals[1][0] = 0;
    intervals[1][1] = 4;

    printf("Input: ");
    for (int i = 0; i < intervalsSize; i++)
    {
        printf("[%d, %d] ", intervals[i][0], intervals[i][1]);
    }

    printf("\n\n");
    
    int **returnIntervals = merge(intervals, intervalsSize, &intervalsColSize,
                                  &returnSize, &returnColumnSizes);

    printf("Output: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[%d, %d] ", returnIntervals[i][0], returnIntervals[i][1]);
    }

    printf("\n\n");

    for (int i = 0; i < intervalsSize; i++)
    {
        free(intervals[i]);
    }

    free(intervals);

    for (int i = 0; i < returnSize; i++)
    {
        free(returnIntervals[i]);
    }

    free(returnIntervals);
    free(returnColumnSizes);

    return 0;
}
