//Implementation of Queue using circular array!!

#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,size;

struct queue{                                   //Initializing a queue
    int* arr;
};


int is_empty(int front,int rear){               
    if(front==rear && front ==-1){             //Queue is empty if front=rear and front=-1......notice it's "and" not or...think why??
        return 1;
    }
    else{
        return 0;
    }
}
int is_full(int front,int rear){                //if rear+1=front then queue is full....then why (rear+1)%size ??
    if((rear+1)%size==front){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* q,int num){
    if(is_full(front,rear)){                //If queue is already full we can't insert!
        printf("Overflow\n");
    }
    else if(front==-1 && rear==-1){         //For the very first case...when front is -1
        front=rear=0;   
        q->arr[rear]=num;
    }
    else{
        rear=(rear+1)%size;                 
        q->arr[rear]=num;                   //insert the element at rear
    }
}

void dequeue(struct queue *q){      //Why the argument is *q....why not just q
    if(is_empty(front,rear)){
        printf("Underflow\n");        // If queue is empty you can't delete so underflow
    }
    else{
        if(front==rear){                //reason for this statement??
            front=-1;
            rear=-1;
            return;
        }
        front=(front+1)%size;             //We can't delete an element in array?? so how is this statement it's solution
    }
}

void display(struct queue *q){
    printf("%d %d\n",front,rear);
    if(is_empty(front,rear)){               //If the queue is empty simply print it's empty
        printf("The queue is empty\n");
    }
    else{
        if(front==rear){                       
            printf("%d ",q->arr[front]);
        }
        else{
            int i=front;            //declearing a counter
            while(i!=rear){
                printf("%d ",q->arr[i]);
                i=(i+1)%size;         //circular increment of counter
            }
            printf("%d ",q->arr[i]);
        }
    }
    printf("\n");
}


int main(){
    struct queue q;
    printf("Enter the size of queue you want: ");
    scanf("%d",&size);
    q.arr=(int*)malloc(size*sizeof(int));
    while(1){
        int op;
        display(&q);
        printf("Enter the operation you want to perform: 1.enqueue 2.dequeue 3.display 4.exit\n ");
        scanf("%d",&(op));
        if(op==1){
            int num;
            printf("Enter the element you want to insert: ");    // Insert either 1 or 2 or 3 or 4!
            scanf("%d",&num);
            enqueue(&q,num);
        }
        else if(op==2){
            dequeue(&q);
        }
        else if(op==3){
            display(&q);
        }
        else{
            break;
        }
    }
    return 0;
}
