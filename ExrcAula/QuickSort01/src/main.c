#include <stdio.h>

void swap(int* array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quickSort(int array[], int left, int right)
{
    int mid, i, j;
    i = left;
    j = right;
    mid = array[(left + right) / 2];
    
    do
    {
        while (array[i] < mid)
        {
            i++;
        }

        while (mid < array[j])
        {
            j--;
        }

        if (i <= j)
        {
            swap(&array, i, j);
            i++;
            j--;
        }
    } while ( i <= j);

    if (left < j)
    {
        quickSort(array, left, j);
    }

    if (i < right)
    {
        quickSort(array, i, right);
    }
}

int main()
{
    int array[] = {1,6,4,37,8,3,5,7,8,1,2,4,6,8,2,3,4,6,8,9};
    int left = 0, right = sizeof(array) - 1;
    printf("Original Array: ");
    for (int i = 0; i < right; i++)
    {
        printf("%d ", array[i]);
    }

    quickSort(array, left, right);

    printf("QuickSort Array: ");
    for (int i = 0; i < right; i++)
    {
        printf("%d ", sortedArray[i]);
    }
    
    
}