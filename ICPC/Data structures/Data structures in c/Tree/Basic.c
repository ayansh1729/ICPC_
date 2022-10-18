#include<stdio.h>
#include<stdlib.h>
// #include "stack.h"

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

struct stack{
    int top;
    int size;
    int* arr;
};


node* new_node(int data){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->data=data;
    return new_node;
}

void preOrder(node* root){
    node* ptr=root;
    if(ptr==NULL){
        return;
    }
    printf("%d ",ptr->data);
    preOrder(ptr->left);
    preOrder(ptr->right);

}
void postOrder(node* root){
    node* ptr=root;
    if(ptr==NULL){
        return;
    }
    postOrder(ptr->left);
    postOrder(ptr->right);
    printf("%d ",ptr->data);

}
void inOrder(node* root){
    node* ptr=root;
    if(ptr==NULL){
        return;
    }
    inOrder(ptr->left);
    printf("%d ",ptr->data);
    inOrder(ptr->right);
}
int main(){
    node* root=new_node(1);
    node* ptr=root;
    ptr->left=new_node(3);      //vvi--- ptr->left has address of a new_node which has value 3
    // ptr->right=new_node(5);    
    ptr->left->left=new_node(7);
    ptr->left->right=new_node(9);
    ptr->right=new_node(2);
    ptr->right->left=new_node(4);
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);
    return 0;
}