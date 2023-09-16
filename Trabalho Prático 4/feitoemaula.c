#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 /**
    ------  Ideia:  -----------------------------------------
 
    1. Percorrer todas as linhas do array intervals,
    comparando intervals[i] com intervals[i + 1] (próxima).

    2. A cada iteração, guardar os valores de cada intervalo
    podendo comparar os inícios e fins.

    3. Caso o intervalo i termine depois de o começo do
    intervalo i + 1, estes intervalos devem sofrer o merge.
    Senão devem ser gravados normalmente.

    4. A gravação ocorre em um novo array de retorno.

    5. Para definir o returnSize, é necessário iterar pelas
    linhas do novo array até encontrar seu final (null);

    6. O returnColumnSizes deve ser 1 (talvez 2), pois cada
    intervalos contém dois valores em sua posição.

    ---------------------------------------------------------
 */

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int start1, start2, end1, end2;
    int **returnIntervals = (int **)malloc(sizeof(int *));
    for (int i = 0; i < intervalsSize - 1; i++) // percorre as linhas
    {
        start1 = intervals[i][0];
        end1 = intervals[i][1];
        start2 = intervals[i + 1][0];
        end2 = intervals[i + 1][1];

        //returnIntervals[i] = (int *)malloc(sizeof(int) * 2);
        if (end1 >= start2) // verifica o overlap
        {
            //returnIntervals[i][0] = (int *)malloc(sizeof(int *));
            returnIntervals[i][0] = start1; // merge
            //returnIntervals[i][1] = (int )malloc(sizeof(int ));
            returnIntervals[i][1] = end2;
            i++;
        } 
        else // sem overlap
        {
            returnIntervals[i][0] = start1; // insere no novo array
            returnIntervals[i][1] = end1;
        }

    }

    returnSize = (int *)malloc(sizeof(int *));
    returnSize = 0;
    returnColumnSizes = (int *)malloc(sizeof(int *));
    returnColumnSizes = 1;

    for (int i = 0; returnIntervals[i][0] != NULL; i++) // percorre as linhas contando
    {
        returnSize++;
    }

    return returnIntervals;
}

int main()
{
    int **intervals = [[1,3],[2,6],[8,10],[15,18]];
    int intervalsSize = 4;
    int *intervalsColSize = 1;
    int *returnSize;
    int **returnColumnSize;
    intervals = merge(intervals, intervalsSize, intervalsColSize, returnSize, returnColumnSize);
}
