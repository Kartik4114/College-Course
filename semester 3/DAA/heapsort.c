#include<stdio.h>
void heapSort(int pq[], int n) {
    // Write your code
     // build heap sort first
    // here we will start adding elements from 1st index as we are taking 0th element is
    // already in heap.

    for (int i = 1; i < n; i++)
    {
        int childindex = i;

        while (childindex > 0)
        {
        int parentindex = (childindex - 1) / 2; // as parent first child will be present at 2i-1;
            if (pq[childindex] < pq[parentindex])
            {
                // swapping the values of child and parent index.
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break; // as if we element don't reach at root.
            }
            childindex = parentindex;
        }
    }

    // remove elements
    // remember here we are not deleting the elements we are just not taking last element.
    int size = n;
    while (size > 1)
    {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size--;
        // down heapify.
        int parentindex = 0;
        int leftchildindex = 2 * parentindex + 1;
        int rightchildindex = 2 * parentindex + 2;

        while (leftchildindex < size)
        {
            int minindex = parentindex;
            if (pq[minindex] > pq[leftchildindex])
            {
                minindex = leftchildindex;
            }
            if (rightchildindex < size && pq[minindex] > pq[rightchildindex])
            {
                minindex = rightchildindex;
            }
            if (minindex == parentindex)
            {
                break;
            }
            int temp = pq[minindex];
            pq[minindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = minindex;
            leftchildindex = 2 * parentindex + 1;
            rightchildindex = 2 * parentindex + 2;
        }
    }
}
 int main(){

    int n;
    scanf("%d", &n);
    // clock_t start,end;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // start=clock();
        heapSort(arr, n);
    // end=clock();

    for (int i = n-1; i >=0; i--)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}