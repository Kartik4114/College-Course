#include <stdio.h>

void insertion_sort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (current < arr[j])
            {
                arr[j + 1] = arr[j];
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
    insertion_sort(arr, n);
    // end=clock();

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}