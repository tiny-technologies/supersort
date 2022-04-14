#include "utils.h"

void insertion_sort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = array[i];
        int j = i;
        while ((x < array[j - 1]) && (j > 0))
        {
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = x;
    }
}

void selection_sort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        swap(array, i, argmin(array, i, n));
    }
}

void bubble_sort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        int j = i + 1;
        while (array[k] > array[j] && j > 0)
        {
            swap(array, k, j);
            k--;
            j--;
        }
    }
}
