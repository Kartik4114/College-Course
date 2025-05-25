#include <stdio.h>

void selection_sort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j] <= arr[i])
            {
                int current = arr[i];
                arr[i] = arr[j];
                arr[j] = current;
            }
        }
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    // clock_t start,end;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // start=clock();
    selection_sort(arr, n);
    // end=clock();

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}