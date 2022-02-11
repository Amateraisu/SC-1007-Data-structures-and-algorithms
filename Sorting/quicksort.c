#include <stdio.h>

void quicksort(int *arr, int left, int right)
{

    int p; // this is the pivot position
    if (left >= right)
    {
        return;
    }
    p = partition(arr, left, p - 1);
    p = partition(arr, p + 1, right);
}

int partition(int *arr, int left, int right)
{
    int i = left - 1;
    int pivot = arr[right];
    int j = left;
    int temp;

    for (j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    return (i + 1);
}

int main()
{

    int arr = {1, 4, 3, 0};

    quicksort(arr, 0, 3);

    for (int i = 0; i <= 4; i++)
    {
        printf(arr[i]);
    }

    return 0;
}