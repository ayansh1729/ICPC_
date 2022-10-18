// #ifndef stack
// #include<stdio.h>

// struct stack{
//     int top;
//     int size;
//     int* arr;
// };

// int is_empty(struct stack* s){
//     if(s->top==-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int is_full(struct stack* s){
//     if(s->top==(s->size)-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// void push(struct stack* s,int num){
//     if(is_full(s)){
//         printf("\nStack Overflow!!\n");
//     }
//     else{
//         s->top++;
//         s->arr[s->top]=num;
//     }
// }

// void pop(struct stack* s){
//     if(is_empty(s)){
//         printf("\nStack Underflow\n");
//     }
//     else{
//         s->top--;
//     }
// }

// void display(struct stack* s){
//     if(is_empty(s)){
//         printf("\nThe stack is empty:\n");
//     }
//     else{
//         for(int i=0;i<=s->top;i++){
//             printf("%d ",s->arr[i]);
//         }
//         printf("\n");
//     }
// }
// #define stack
// #endif