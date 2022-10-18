#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front;
    int rear;
    int* arr;
    int size;
};   


void enqueue(struct queue* q,int num){
      if(q->front==-1 && q->rear==-1)   // condition to check queue is empty  
    {  
        q->front=0;  
        q->rear=0;  
        q->arr[q->rear]=num;  
    }  
    else if((q->rear+1)%(q->size)==q->front)  // condition to check queue is full  
    {  
        printf("Queue is overflow..");  
    }  
    else  
    {  
        q->rear=(q->rear+1)%(q->size);       // rear is incremented  
        q->arr[q->rear]=num;     // assigning a value to the queue at the rear position.  
    }  
}
void dequeue(struct queue* q){
       if((q->front==-1) && (q->rear==-1))  // condition to check queue is empty  
    {  
        printf("\nQueue is underflow..");  
    }  
    else if(q->front==q->rear)  
    {  
    printf("\nThe dequeued element is %d", q->arr[q->front]);  
        q->front=-1;  
        q->rear=-1;  
    }   
    else  
    {  
        printf("\nThe dequeued element is %d", q->arr[q->front]);  
        q->front=(q->front+1)%(q->size);  
    } 
}
void display(struct queue* q){

    printf("%d %d\n",q->front,q->rear);
    int i=q->front;  
    if(q->front==-1 && q->rear==-1)  
    {  
        printf("\n Queue is empty..");  
    }  
    else  
    {  
        printf("\nElements in a Queue are :");  
        while(i<=q->rear)  
        {  
            printf("%d,", q->arr[i]);  
            i=(i+1)%(q->size);  
        }  
    }  
    printf("\n");
}
int main(){
    struct queue q;
    q.front=-1;
    q.rear=-1;
    printf("Enter the size of queue you want: ");
    scanf("%d",&(q.size));
    q.arr=(int*)malloc(q.size*sizeof(int));
    while(1){
        int op;
        display(&q);
        printf("Enter the operation you want to perform: 1.enqueue 2.dequeue 3.display 4.exit\n ");
        scanf("%d",&(op));
        if(op==1){
            int num;
            printf("Enter the element you want to insert: ");
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