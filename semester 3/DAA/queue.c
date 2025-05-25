// here is the c program to stimulate the working of ordinary queue using array.
// here we are performing operations like QINSERT(inserting the queue),QDELETE(deleting the queue),
//  QDISPLAY(displaying the queue), checking size,cheking whelther queue is empty or not.

#include <stdio.h>
#include <stdbool.h> //library to check true or false.
#include <stdlib.h>  // library for doing dynamic memory allocation.

// defining the structure of queue using array.
typedef struct queue_using_array
{

    int *data;      // it is array in which data will be stored.
    int nextindex;  // for tracking nextindex.
    int firstindex; // for tracking firstindex used in displaying.
    int size;       // for checking size of queue.
    int capacity;   // for capacity of queue.
} q1;

// initializing the queue.
void initialize_queue(q1 *queue, int s)
{
    queue->nextindex = 0;
    queue->firstindex = -1;
    queue->size = 0;
    queue->capacity = s;
    queue->data = (int *)malloc(s * sizeof(int));
}

// function to get size of the queue.
int getsize(q1 *queue)
{
    return queue->size;
}

// it is a boolean function to check whether function is empty or not.
bool isempty(q1 *queue)
{
    return queue->size == 0;
}

// it is function to push elements in the queue.
void QINSERT(q1 *queue, int element)
{
    if (queue->size == queue->capacity)
    {
        printf("queue is full !");
        return;
    }
    queue->data[queue->nextindex] = element;
    queue->nextindex++;
    if (queue->firstindex == -1)
    {
        queue->firstindex = 0;
    }
    queue->size++;
}

// function to display the front element in the queue.
int QDISPLAY(q1 *queue)
{
    if (isempty(queue))
    {
        printf("queue is empty !");
    }

    return queue->data[queue->firstindex];
}

// function to pop the elements in the queue.
int QDELETE(q1 *queue)
{
    if (isempty(queue))
    {
        printf("queue is empty !");
    }
    int ans = queue->data[queue->firstindex];
    queue->firstindex++;
    queue->size--;
    return ans;
}

int main()
{

    int capacity;
    printf("enter the capacity of the queue : \n");
    scanf("%d", &capacity);

   int arr[capacity];
    q1 queue;
    initialize_queue(&queue, capacity);// function calling for inittializing.

    // here taking input the elements for the  queue.
    printf("enter the elements for queue :\n");
    for(int i=0;i<capacity;i++){
       scanf("%d",&arr[i]);
    }
// loop for inserting elements in the queue.
    for(int i=0;i<capacity;i++){
       (QINSERT(&queue,arr[i]));
    }

    printf("\nelements in the queue are :\n");
// loop for displaying elements and deleting the elements.
    for(int i=0;i<capacity;i++){
       printf("%d ",(QDISPLAY(&queue)));
       (QDELETE(&queue));
    }
    printf("\n");
    
    printf("After deleting the elements in the queue are :\n");

 // checking queue is empty or not.
    if (isempty(&queue))
    {
        printf("queue is empty !");
    }
    else
    {
        printf("queue is full !");
    }

    free(queue.data);// for freeing the queue.

    return 0;
}

