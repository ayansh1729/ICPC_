//Implementation of stack using array!!

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int* arr;
};

int is_empty(struct stack* s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct stack* s){
    if(s->top==(s->size)-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* s,int num){
    if(is_full(s)){
        printf("\nStack Overflow!!\n");
    }
    else{
        s->top++;
        s->arr[s->top]=num;
    }
}

void pop(struct stack* s){
    if(is_empty(s)){
        printf("\nStack Underflow\n");
    }
    else{
        s->top--;
    }
}

void display(struct stack* s){
    if(is_empty(s)){
        printf("\nThe stack is empty:\n");
    }
    else{
        for(int i=0;i<=s->top;i++){
            printf("%d ",s->arr[i]);
        }
        printf("\n");
    }
}
 
int main(){
    struct stack s;
    s.top=-1;
    printf("Enter the size of stack you want: ");
    scanf("%d",&(s.size));
    s.arr=(int*)malloc(s.size*sizeof(int));
    char operation[10];
    while(1){
        printf("Enter the operation you want to perform of\n 1. push 2. pop 3. display 4. exit \n");
        scanf("%s",operation);
        if(strcmp(operation,"push")==0){        
            int num;
            printf("Enter the number you want to push: ");
            scanf("%d",&num);
            push(&s,num);
        }
        else if(strcmp(operation,"pop")==0){
            pop(&s);
        }
        else if(strcmp(operation,"display")==0){
            display(&s);
        }
        else if(strcmp(operation,"exit")==0){
            break;
        }
    }
    return 0;
}