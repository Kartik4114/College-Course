#include <stdio.h>
#include <time.h>

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{

    int n;
    scanf("%d", &n);
    clock_t start,end;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    start=clock();
    bubble_sort(arr, n);
    end=clock();

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    double time=(double)(end-start)/(double)CLOCKS_PER_SEC;

    size_t s=sizeof(arr);

    printf("Time is %.5lf",time);
    printf("Size is %zu",s);

    return 0;

}