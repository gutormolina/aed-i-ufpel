#include <stdio.h>

int* divide(int* nums, int left, int right)
{
    
}

int* quickSort(int* nums, int left, int right) 
{
    if (left < right)
    {
        int pivot = divide(nums, left, right);
        quickSort(nums, right, pivot - 1);
        quickSort(nums, pivot + 1, left);
    }
}

int main()
{

}