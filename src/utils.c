#include "utils.h"

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int argmin(int array[], int i, int j)
{
    int s = i;
    for (int k = i + 1; k < j; k++)
    {
        if (array[k] < array[s])
        {
            s = k;
        }
    }

    return s;
}

int is_sorted(int array[], int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        if (array[k] > array[k + 1])
        {
            return 0;
        }
    }

    return 1;
}
