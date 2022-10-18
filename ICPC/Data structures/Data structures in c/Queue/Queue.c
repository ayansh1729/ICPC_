#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//<------------priority Queue------------------>//

typedef struct p_node
{ // Priority queue node---->
    int data;
    int priority;
} p_node;

typedef struct p_queue
{
    p_node array[1000];
    // p_node* array -----       and the memory can be allocated later
    // p_node* head  -----         We can use a linked list to store that only thing is
    //  in the p_node a next should be added
} p_queue;

int size = -1; // pointing to last element

void enqueue(int data, int priority, p_queue *p_q)
{
    size++; // Incrementing the index

    p_q->array[size].data = data; // putting the data and priority at each node
    p_q->array[size].priority = priority;
}

int peek(p_queue *p_q)
{
    int highest_priority = INT_MIN; // INT_MIN denotes the minimum possible value of int(ds)
    int index = -1;

    for (int i = 0; i <= size; i++)
    { // Note that size is a global variable

        // We have to write the condition only when  our priority is either greater or equal
        //  if we encounter a priority of equal then we choose whicher is highest value

        //<----------this is your choice not a property of queue--------->//
        // you can choose with other properties e.g lower value one

        // The index should be greater than -1....that condition is because there is nothing to compare at -1
        // The index of array starts from 0

        if ((highest_priority == p_q->array[i].priority) && (index > -1) && (p_q->array[index].data < p_q->array[i].data))
        {
            highest_priority = p_q->array[i].priority;
            index = i;
        }
        else if (highest_priority < p_q->array[i].priority)
        {
            highest_priority = p_q->array[i].priority;
            index = i;
        }
    }

    return index;
}

void dequeue(p_queue *p_q)
{
    int index = peek(p_q); // search element with highest priority

    for (int i = index; i < size; i++)
    {
        p_q->array[i] = p_q->array[i + 1]; // shift all the elements to left
    }

    size--;
}

int main()
{
    // This is creation of a priority queue
    p_queue *p_q = (p_queue *)malloc(sizeof(p_queue));

    enqueue(10, 2, p_q);
    enqueue(14, 4, p_q);
    enqueue(16, 4, p_q);
    enqueue(12, 3, p_q);

    int index = peek(p_q);

    printf("The top value is: %d \n", p_q->array[index].data);

    dequeue(p_q);

    // After dequeue-------

    index = peek(p_q);

    printf("After deque The top value is: %d ", p_q->array[index].data);

    return 0;
}