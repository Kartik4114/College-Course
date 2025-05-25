// here is the c program to stimulate the working of circular queue using array.
// here we are performing operations like QINSERT(inserting the queue),QDELETE(deleting the queue),
//  QDISPLAY(displaying the queue), checking size,cheking whelther queue is empty or not.
// in circular queue , after reaching at last next element gets prints at 0th index. 

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

    queue->nextindex=(queue->nextindex+1)%queue->capacity;
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
        return 0;
    }
    int ans = queue->data[queue->firstindex];
    if(queue->size==0){
      queue->firstindex=-1;
      queue->nextindex=0;

    }
    queue->firstindex=(queue->firstindex+1)% queue->capacity;
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


        // pushing the elements in queue.
        QINSERT(&queue,10);
        QINSERT(&queue,20);
        QINSERT(&queue,30);
        QINSERT(&queue,40);
        QINSERT(&queue,50);

        printf("%d ",QDISPLAY(&queue));
        QDELETE(&queue);
        printf("%d ",QDISPLAY(&queue));
        QDELETE(&queue);
        printf("%d ",QDISPLAY(&queue));
        QDELETE(&queue);

       // inserting again for seeing whether the circular linked list work or not. 
        QINSERT(&queue,60);// pushing one element again.
        printf("%d ",QDISPLAY(&queue));
        QDELETE(&queue);
        printf("%d ",QDISPLAY(&queue));

        QDELETE(&queue);
        printf("%d ",QDISPLAY(&queue));

 // checking queue is empty or not.
    printf("%d",isempty(&queue));
    if(isempty(&queue)==0){
        printf("queue is not empty.\n");
        printf("as queue is not empty this clearly shows that cirular list has been implemented.\n");
    }
    
    free(queue.data);// for freeing the queue.

    return 0;
}
